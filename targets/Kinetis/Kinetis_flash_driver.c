/*****************************************************************************
 *                                                                           *
 * Copyright (c) 2010, 2011 Rowley Associates Limited.                       *
 *                                                                           *
 * This file may be distributed under the terms of the License Agreement     *
 * provided with this software.                                              *
 *                                                                           *
 * THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE   *
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. *
 *****************************************************************************/

#include <libmem.h>

#define FMC_PFAPR (*(volatile unsigned *)0x4001F000)
#define FMC_PFB0CR (*(volatile unsigned *)0x4001F004)
#define FMC_PFB1CR (*(volatile unsigned *)0x4001F008) 

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

#define SECTOR_SIZE 0x800

#define SIM_FCFG1 (*(volatile unsigned *)0x4004804C)
#define SIM_FCFG2 (*(volatile unsigned *)0x40048050)

unsigned FLASH_SIZE;

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
libmem_write_impl(libmem_driver_handle_t *h, uint8_t *dest, const uint8_t *src, size_t size)
{
  unsigned sdest = (unsigned)dest & ~3;  
  while (size>=4)
    {
      if (sdest >= 0x400 && sdest < 0x410) // ignore writes to the flash configuration field
        {
          src += 4;
          size -= 4;         
          sdest += 4;
        }
      else
        {
          setFlashCmdAndAddress(FCMD_PGM4, sdest);          
          FTFL_FCCOB7 = *src++;
          FTFL_FCCOB6 = *src++;
          FTFL_FCCOB5 = *src++;
          FTFL_FCCOB4 = *src++;
          size -= 4;
          sdest += 4;
          doFlashCmd();
        }
    }
  if (size)
    {
      setFlashCmdAndAddress(FCMD_PGM4, sdest);
      FTFL_FCCOB7 = *src++; size--;
      FTFL_FCCOB6 = 0xff;
      FTFL_FCCOB5 = 0xff;
      FTFL_FCCOB4 = 0xff;      
      if (size)
        {
          FTFL_FCCOB6 = *src++; size--;
          if (size)
            FTFL_FCCOB5 = *src++; size--;
        }
      doFlashCmd();
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
                  // Ensure that FTFL_FSEC = 0xfe
                  if (flashstart == 0)
                    {
                      setFlashCmdAndAddress(FCMD_PGM4, 0x40C);                      
                      FTFL_FCCOB4 = 0xff;
                      FTFL_FCCOB5 = 0xff;
                      FTFL_FCCOB6 = 0xff;
                      FTFL_FCCOB7 = 0xfe;
                      doFlashCmd();
                    }                  
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
  return LIBMEM_STATUS_SUCCESS;
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
  // turn off and invalidate any caching
  FMC_PFB0CR = (0xf<<20) | (0x1<<19);

  FLASH_SIZE = ((SIM_FCFG2>>24) & 0x3f)<<13;  
  if (SIM_FCFG2 & (1<<23)) // N
    FLASH_SIZE += ((SIM_FCFG2>>16) & 0x3f)<<13;
     
  geometry[0].count = FLASH_SIZE/SECTOR_SIZE;
  geometry[0].size = SECTOR_SIZE;
  libmem_register_driver(h, (uint8_t *)0, FLASH_SIZE, geometry, 0, &driver_functions, &ext_driver_functions);
  return LIBMEM_STATUS_SUCCESS;
}
