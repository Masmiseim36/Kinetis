/*****************************************************************************
 *                                                                           *
 * Copyright (c) 2010, 2011, 2012 Rowley Associates Limited.                 *
 *                                                                           *
 * This file may be distributed under the terms of the License Agreement     *
 * provided with this software.                                              *
 *                                                                           *
 * THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE   *
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. *
 *****************************************************************************/

#include <libmem.h>
#include <string.h>

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

unsigned FLASH_SIZE;
unsigned char write_block[8];
unsigned char *write_block_address=INVALID_ADDRESS;
unsigned write_block_size;

libmem_geometry_t geometry[2];

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
  if (write_block_size == 8)
    {
      setFlashCmdAndAddress(FCMD_PGM8, (unsigned)write_block_address);          
      FTFL_FCCOB7 = write_block[0];
      FTFL_FCCOB6 = write_block[1];
      FTFL_FCCOB5 = write_block[2];
      FTFL_FCCOB4 = write_block[3];
      FTFL_FCCOBB = write_block[4];
      FTFL_FCCOBA = write_block[5];
      FTFL_FCCOB9 = write_block[6];
      FTFL_FCCOB8 = write_block[7];
    }
  else
    {
      setFlashCmdAndAddress(FCMD_PGM4, (unsigned)write_block_address);
      FTFL_FCCOB7 = write_block[0];
      FTFL_FCCOB6 = write_block[1];
      FTFL_FCCOB5 = write_block[2];
      FTFL_FCCOB4 = write_block[3];      
    }  
  int res = doFlashCmd();
  memset(write_block, 0xff, write_block_size);
  write_block_address = INVALID_ADDRESS;  
  return res;
}

static int
libmem_write_impl(libmem_driver_handle_t *h, uint8_t *dest, const uint8_t *src, size_t size)
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
            memcpy(write_block, block, write_block_size);
        }
      /* Copy data into buffer */
      memcpy(write_block + offset, src, frag);
      write_block_address = block;
      size -= frag;
      if (!size)
        break;
      dest += frag;
      src += frag;
   }
  return LIBMEM_STATUS_SUCCESS;
}

static int
libmem_erase_impl(libmem_driver_handle_t *h, uint8_t *start, size_t size, uint8_t **erased_start, size_t *erased_size)
{
  int res = LIBMEM_STATUS_SUCCESS;
  if (LIBMEM_RANGE_WITHIN_RANGE(h->start, h->start + h->size - 1, start, start + size - 1))
    {
      if (erased_start)
        *erased_start = h->start;
      if (erased_size)
        *erased_size = h->size;
      // Erase All
      FTFL_FCCOB0 = FCMD_ERSALL;
      doFlashCmd();           
      if (write_block_size == 8)
        {
          setFlashCmdAndAddress(FCMD_PGM8, 0x408);
          FTFL_FCCOB7 = 0xff;
          FTFL_FCCOB6 = 0xff;
          FTFL_FCCOB5 = 0xff;
          FTFL_FCCOB4 = 0xff;
          FTFL_FCCOBB = 0xfe;
          FTFL_FCCOBA = 0xff;
          FTFL_FCCOB9 = 0xff;
          FTFL_FCCOB8 = 0xff;                                                                              
        }
      else
        {
          setFlashCmdAndAddress(FCMD_PGM4, 0x40C);
          FTFL_FCCOB7 = 0xfe;
          FTFL_FCCOB6 = 0xff;
          FTFL_FCCOB5 = 0xff;
          FTFL_FCCOB4 = 0xff;                                                                              
        }
      doFlashCmd();
    }
  else
    {      
      int found = 0;
      int j = geometry[0].count;
      int blocksize = geometry[0].size;
      uint8_t *end = start + size - 1;
      uint8_t *flashstart = h->start;      
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
                  // Ensure that FTFL_FSEC(0x40C) = 0xfe                  
                  if (LIBMEM_ADDRESS_IN_RANGE((uint8_t*)0x40C, flashstart, flashstart + blocksize - 1))
                    {
                      if (write_block_size == 8)
                        {
                          setFlashCmdAndAddress(FCMD_PGM8, 0x408);
                          FTFL_FCCOB7 = 0xff;
                          FTFL_FCCOB6 = 0xff;
                          FTFL_FCCOB5 = 0xff;
                          FTFL_FCCOB4 = 0xff;
                          FTFL_FCCOBB = 0xfe;
                          FTFL_FCCOBA = 0xff;
                          FTFL_FCCOB9 = 0xff;
                          FTFL_FCCOB8 = 0xff;                                                                              
                        }
                      else
                        {
                          setFlashCmdAndAddress(FCMD_PGM4, 0x40C);
                          FTFL_FCCOB7 = 0xfe;
                          FTFL_FCCOB6 = 0xff;
                          FTFL_FCCOB5 = 0xff;
                          FTFL_FCCOB4 = 0xff;                                                                              
                        }
                      doFlashCmd();
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

static int
libmem_flush_impl()
{  
  return write_current_block();
}

static int
libmem_inrange_impl(libmem_driver_handle_t *h, const uint8_t *dest)
{
  return LIBMEM_ADDRESS_IN_RANGE(dest, (uint8_t *)0, (uint8_t *)(FLASH_SIZE - 1));
}

static const libmem_driver_functions_t driver_functions =
{       
  libmem_write_impl,
  0,
  libmem_erase_impl, 
  0,
  0,
  libmem_flush_impl
};

static const libmem_ext_driver_functions_t ext_driver_functions =
{
  libmem_inrange_impl,
  0,
  0
};

int
kinetis_register_libmem_driver(libmem_driver_handle_t *h)
{        
  unsigned sectorSize;
#define FMC_PFB0CR (*(volatile unsigned *)0x4001F004)
  // turn off and invalidate any caching
  FMC_PFB0CR = (0xf<<20) | (0x1<<19);

  // workout flash size, sector size and write block size
  FLASH_SIZE = ((SIM_FCFG2>>24) & 0x3f)<<13;  
  if (SIM_FCFG2 & (1<<23)) // N
    FLASH_SIZE += ((SIM_FCFG2>>16) & 0x3f)<<13;

  write_block_size = 4;
  
  switch ((SIM_SDID >> 7) & 0x7)
    {
      case 0x0:
        sectorSize = 1*1024;
        break;
      case 0x1:
      case 0x2:
        sectorSize = 2*1024;
        break;
      case 0x3:
        sectorSize = 4*1024;
        FLASH_SIZE *= 2;
        write_block_size = 8;
        break;
      default:
        return LIBMEM_STATUS_ERROR;
    }
  geometry[0].count = FLASH_SIZE/sectorSize;
  geometry[0].size = sectorSize;
  libmem_register_driver(h, (uint8_t *)0, FLASH_SIZE, geometry, 0, &driver_functions, &ext_driver_functions);
  return LIBMEM_STATUS_SUCCESS;
}

#include <libmem_loader.h>

extern unsigned char __RAM_segment_end__[];
extern unsigned char __RAM_segment_used_end__[];

int
main(int param0)
{ 
  libmem_driver_handle_t h;    
  int res = kinetis_register_libmem_driver(&h);
  if (res != LIBMEM_STATUS_SUCCESS)
    libmem_rpc_loader_exit(LIBMEM_STATUS_ERROR, "Unsupported device");   
#if 0
  uint8_t *erase_start;
  size_t erase_size;  
  res = libmem_erase((uint8_t *)0x0, 0x81a, &erase_start, &erase_size); 

  static const unsigned char buffer[24] = { 0x1, 0x2, 0x3, 0x4,  0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf };    
  res = libmem_write(0x0, buffer, 0x24); 
  res = libmem_flush();
#endif
   
  res = libmem_rpc_loader_start(__RAM_segment_used_end__, __RAM_segment_end__ - 1); 
  libmem_rpc_loader_exit(res, 0);
  return 0;
}
