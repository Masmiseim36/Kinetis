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

unsigned char write_block[8];
unsigned char *write_block_address=INVALID_ADDRESS;
unsigned write_block_size;

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
#ifdef HASFlexNVM
  if (address >= 0x10000000)
    {
      address -= 0x10000000;
      address += 0x800000;
    }
#endif
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
#ifdef HASFlexNVM
      if (h->start == 0x10000000)
        return res;
#endif
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
      int j = h->geometry[0].count;
      int blocksize = h->geometry[0].size;
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
  0,
  0,
  0
};

#include <libmem_loader.h>

extern unsigned char __RAM_segment_end__[];
extern unsigned char __RAM_segment_used_end__[];

libmem_geometry_t geometry[2];
#ifdef HASFlexNVM
libmem_geometry_t geometry2[2];
#endif

int
main(int param0)
{ 
  int res;
  libmem_driver_handle_t h, h1;    
  unsigned sectorSize;
#define FMC_PFB0CR (*(volatile unsigned *)0x4001F004)
  // turn off and invalidate any caching
  FMC_PFB0CR = (0xf<<20) | (0x1<<19);

  // workout flash size, sector size and write block size
  unsigned FLASH_SIZE = ((SIM_FCFG2>>24) & 0x7f)<<13;  
  if (SIM_FCFG2 & (1<<23)) // N
    FLASH_SIZE += ((SIM_FCFG2>>16) & 0x7f)<<13;
  unsigned FLASH_START = 0;

  write_block_size = 4;
#if defined(LOADER3)
  sectorSize = 4 * 1024;
#elif defined(LOADERV5)
  sectorSize = 8 * 1024;
  write_block_size = 8;
  FLASH_START = 0x10000000;
#else  
  if (param0)
    {
      sectorSize = (param0 & 0xf) * 1024;
      if (sectorSize == 4 * 1024)
        {
          FLASH_SIZE *= 2;
          write_block_size = 8;
        }
    }
  else
    switch ((SIM_SDID >> 7) & 0x7)
      {
        case 0x0:
          sectorSize = 1 * 1024;
          break;
        case 0x1:
        case 0x2:
          sectorSize = 2 * 1024;
          break;
        case 0x3:
          sectorSize = 4 * 1024;
          FLASH_SIZE *= 2;
          write_block_size = 8;
          break;
        default:
          libmem_rpc_loader_exit(LIBMEM_STATUS_ERROR, "Unsupported device");
          return 0;
      }
#endif
  geometry[0].count = FLASH_SIZE/sectorSize;
  geometry[0].size = sectorSize;
  libmem_register_driver(&h, (uint8_t *)FLASH_START, FLASH_SIZE, geometry, 0, &driver_functions, &ext_driver_functions);

#ifdef HASFlexNVM
  sectorSize = ((param0 >> 4) & 0xf) * 1024;
  unsigned NVM_FLASH_SIZE = ((SIM_FCFG2>>16) & 0x3f)<<13;
  if (sectorSize == 4 * 1024)
    NVM_FLASH_SIZE *= 2;
  geometry2[0].count = NVM_FLASH_SIZE/sectorSize;
  geometry2[0].size = sectorSize;
  libmem_register_driver(&h1, (uint8_t *)0x10000000, NVM_FLASH_SIZE, geometry2, 0, &driver_functions, &ext_driver_functions);
#endif  

#if 0
  uint8_t *erase_start;
  size_t erase_size;  
  //res = libmem_erase((uint8_t *)0x0, 0x24, &erase_start, &erase_size); 
  //res = libmem_erase((uint8_t *)0x10000000, 0x24, &erase_start, &erase_size);
  res = libmem_erase_all();
  static const unsigned char buffer1[24] = { 0x38, 0xAA, 0xFF, 0x1F,  0x45, 0x06, 0x00, 0x00,  0x65, 0x05, 0x00, 0x00,  0x67, 0x05, 0x00, 0x00 };  
  static const unsigned char buffer2[24] = { 0xB0, 0xB5, 0x96, 0xB0,  0x00, 0xAF, 0x4F, 0xF0,  0x30, 0x00, 0x00, 0xF0,  0x41, 0xF0, 0x02, 0x42 }; 
  res = libmem_write(0x00000000, buffer1, sizeof(buffer1)); 
  res = libmem_write(0x10000000, buffer2, sizeof(buffer2)); 
  res = libmem_flush();
#endif
   
  res = libmem_rpc_loader_start(__RAM_segment_used_end__, __RAM_segment_end__ - 1); 
  libmem_rpc_loader_exit(res, 0);
  return 0;
}
