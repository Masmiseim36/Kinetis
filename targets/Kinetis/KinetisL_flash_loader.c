/*****************************************************************************
 *                                                                           *
 * Copyright (c) 2013 Rowley Associates Limited.                             *
 *                                                                           *
 * This file may be distributed under the terms of the License Agreement     *
 * provided with this software.                                              *
 *                                                                           *
 * THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE   *
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. *
 *****************************************************************************/

#include <libmem.h>

#define FTFL_FSTAT (*(volatile unsigned char *)0x40020000)
#define FTFL_FCNFG (*(volatile unsigned char *)0x40020001)
#define FTFL_FSEC (*(const volatile unsigned char *)0x40020002)
#define FTFL_FOPT (*(const volatile unsigned char *)0x40020003)
#define FTFL_FCCOB3 (*(volatile unsigned char *)0x40020004)
#define FTFL_FCCOB2 (*(volatile unsigned char *)0x40020005)
#define FTFL_FCCOB1 (*(volatile unsigned char *)0x40020006)
#define FTFL_FCCOB0 (*(volatile unsigned char *)0x40020007)
#define FTFL_FCCOB7 (*(volatile unsigned char *)0x40020008)
#define FTFL_FCCOB6 (*(volatile unsigned char *)0x40020009)
#define FTFL_FCCOB5 (*(volatile unsigned char *)0x4002000A)
#define FTFL_FCCOB4 (*(volatile unsigned char *)0x4002000B)
#define FTFL_FCCOBB (*(volatile unsigned char *)0x4002000C)
#define FTFL_FCCOBA (*(volatile unsigned char *)0x4002000D)
#define FTFL_FCCOB9 (*(volatile unsigned char *)0x4002000E)
#define FTFL_FCCOB8 (*(volatile unsigned char *)0x4002000F)

#define FTFL_FSTAT_MGSTAT0  (1<<0)
#define FTFL_FSTAT_FPVIOL   (1<<4)
#define FTFL_FSTAT_ACCERR   (1<<5)
#define FTFL_FSTAT_RDCOLERR (1<<6)
#define FTFL_FSTAT_CCIF     (1<<7)

#define FCMD_RD1BLK 0x00
#define FCMD_RD1SEC 0x01
#define FCMD_PGMCHK 0x02
#define FCMD_RDRSRC 0x03
#define FCMD_PGM4 0x06
#define FCMD_PGM8 0x07
#define FCMD_ERSBLK 0x08
#define FCMD_ERSSCR 0x09
#define FCMD_PGMSEC 0x0b
#define FCMD_RD1ALL 0x40
#define FCMD_RDONCE 0x41
#define FCMD_PGMONCE 0x43
#define FCMD_ERSALL 0x44
#define FCMD_VFYKEY 0x45
#define FCMD_PGMPART 0x80
#define FCMD_SETRAM 0x81

#define SIM_SDID  (*(volatile unsigned *)0x40048024)
#define SIM_FCFG1 (*(volatile unsigned *)0x4004804C)
#define SIM_FCFG2 (*(volatile unsigned *)0x40048050)

#define INVALID_ADDRESS (unsigned char *)1

#define write_block_size 4
unsigned char write_block[write_block_size];
unsigned char *write_block_address=INVALID_ADDRESS;
unsigned char FCF[4] = { 0xfe, 0xff, 0xff, 0xff };
#define FLASH_START (uint8_t *)0
unsigned FLASH_SIZE;
unsigned FLASH_PAGE_COUNT;
#define FLASH_PAGE_SIZE 1024

static int
doFlashCmd()
{
  FTFL_FSTAT = FTFL_FSTAT_ACCERR | FTFL_FSTAT_FPVIOL; // Write to clear
  FTFL_FSTAT = FTFL_FSTAT_CCIF; // Go?
  while(!(FTFL_FSTAT & FTFL_FSTAT_CCIF));  // Wait
  if (FTFL_FSTAT & (FTFL_FSTAT_ACCERR | FTFL_FSTAT_FPVIOL | FTFL_FSTAT_MGSTAT0)) 
    return LIBMEM_STATUS_ERROR;
  else
    return LIBMEM_STATUS_SUCCESS;
}

static void
setFlashCmdAndAddress(unsigned char cmd, unsigned address)
{
  FTFL_FCCOB0 = cmd; 
  FTFL_FCCOB1 = address>>16;
  FTFL_FCCOB2 = address>>8;
  FTFL_FCCOB3 = address;
}

static int
flashCmdProgram(unsigned address, unsigned char value[4])
{
  setFlashCmdAndAddress(FCMD_PGM4, address);
  FTFL_FCCOB7 = value[0];
  FTFL_FCCOB6 = value[1];
  FTFL_FCCOB5 = value[2];
  FTFL_FCCOB4 = value[3];
  return doFlashCmd();
}

static int
write_current_block()
{  
  if (write_block_address == INVALID_ADDRESS)
    return LIBMEM_STATUS_SUCCESS;
#ifndef ALLOW_FCF_WRITE
  if (LIBMEM_ADDRESS_IN_RANGE(write_block_address, (uint8_t*)0x400, (uint8_t*)(0x410-1)))
    {
      write_block_address = INVALID_ADDRESS;
      return LIBMEM_STATUS_SUCCESS;
    }
#endif
  int res = flashCmdProgram((unsigned)write_block_address, write_block);
  *(unsigned *)write_block = 0xffffffff;
  write_block_address = INVALID_ADDRESS;  
  return res;
}

int
libmem_write(uint8_t *dest, const uint8_t *src, size_t size)
{  
  while (1)
    {
      uint8_t *block = (uint8_t *)(((uint32_t)dest) & ~(write_block_size-1));
      uint32_t offset = dest - block;
      uint32_t frag = write_block_size - offset;
      if (frag > size)
        frag = size;

       /* Purge the buffer if the next write is in a different block */
      if (block != write_block_address)
        {         
          int res = write_current_block();
          if (res != LIBMEM_STATUS_SUCCESS)
            return res;
          if (frag != write_block_size)
            {             
              for (unsigned i=0;i<4;i++)
                write_block[i] = block[i];              
            }
        }
      /* Copy data into buffer */      
      for (unsigned i=0;i<frag;i++)
        write_block[i+offset] = src[i];
      write_block_address = block;
      size -= frag;
      if (!size)
        break;
      dest += frag;
      src += frag;
   }
  return LIBMEM_STATUS_SUCCESS;
}

int
libmem_erase(uint8_t *start, size_t size, uint8_t **erased_start, size_t *erased_size)
{
  int res = LIBMEM_STATUS_SUCCESS;
#ifndef NO_ERASE_ALL
  if (LIBMEM_RANGE_WITHIN_RANGE(FLASH_START, FLASH_START + FLASH_SIZE - 1, start, start + size - 1))
    {
      if (erased_start)
        *erased_start = FLASH_START;
      if (erased_size)
        *erased_size = FLASH_SIZE;
      // Erase All     
      FTFL_FCCOB0 = FCMD_ERSALL;
      doFlashCmd();    
      flashCmdProgram(0x40C, FCF);
    }
  else
#endif
    {      
      int found = 0;
      int j = FLASH_PAGE_COUNT;
      int blocksize = FLASH_PAGE_SIZE;
      uint8_t *end = start + size - 1;
      uint8_t *flashstart = FLASH_START;
      if (erased_size)
        *erased_size = 0;
      while (j--)
        {
          if (LIBMEM_RANGE_OCCLUDES_RANGE(start, end, flashstart, flashstart + blocksize - 1))
            {
              if (!found)
                {
                  if (erased_start)
                    *erased_start = flashstart;
                  found = 1;
                }
              if (res == LIBMEM_STATUS_SUCCESS)
                {                  
                  setFlashCmdAndAddress(FCMD_ERSSCR, (unsigned)flashstart);
                  doFlashCmd();
#ifndef ALLOW_FCF_WRITE                
                  if (LIBMEM_ADDRESS_IN_RANGE((uint8_t*)0x40C, flashstart, flashstart + blocksize - 1))
                    {
                      flashCmdProgram(0x40C, FCF);
                    }
#endif                                      
                }
              if (erased_size)
                *erased_size += blocksize;
            }
          else
            {
              if (found)
                return res;
            }
          flashstart += blocksize;         
        }            
    }
  return res;
}

int
libmem_flush()
{  
  return write_current_block();
}

uint32_t
libmem_crc32(const uint8_t *start, size_t size, uint32_t crc)
{
  return libmem_crc32_direct(start, size, crc);
}

size_t
libmem_get_driver_sector_size(const uint8_t *p)
{
  return FLASH_PAGE_SIZE;
}

#include <libmem_loader.h>

extern unsigned char __RAM_segment_end__[];
extern unsigned char __RAM_segment_used_end__[];

int
main(int param0)
{  
#define MCM_PLACR (*(volatile unsigned *)0xF000300C)
  // turn off and invalidate any caching
  MCM_PLACR = (1<<15) | (1<<13) | (1<<12) | (1<<11) | (1<<10);
  FLASH_SIZE = ((SIM_FCFG2>>24) & 0x3f)<<13;
  FLASH_SIZE += ((SIM_FCFG2>>16) & 0x3f)<<13;
  FLASH_PAGE_COUNT = FLASH_SIZE/FLASH_PAGE_SIZE;
  int res = libmem_rpc_loader_start(__RAM_segment_used_end__, __RAM_segment_end__ - 1); 
  MCM_PLACR = 0;
  libmem_rpc_loader_exit(res, 0);
  return 0;
}
