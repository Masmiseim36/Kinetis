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

#define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#define   __O     volatile             /*!< Defines 'write only' permissions                */
#define   __IO    volatile             /*!< Defines 'read / write' permissions              */

/** FTMRH - Register Layout Typedef */
typedef struct {
  __IO uint8_t FCLKDIV;                            /**< Flash Clock Divider Register, offset: 0x0 */
  __I  uint8_t FSEC;                               /**< Flash Security Register, offset: 0x1 */
  __IO uint8_t FCCOBIX;                            /**< Flash CCOB Index Register, offset: 0x2 */
       uint8_t RESERVED_0[1];
  __IO uint8_t FCNFG;                              /**< Flash Configuration Register, offset: 0x4 */
  __IO uint8_t FERCNFG;                            /**< Flash Error Configuration Register, offset: 0x5 */
  __IO uint8_t FSTAT;                              /**< Flash Status Register, offset: 0x6 */
  __IO uint8_t FERSTAT;                            /**< Flash Error Status Register, offset: 0x7 */
  __IO uint8_t FPROT;                              /**< Flash Protection Register, offset: 0x8 */
  __IO uint8_t EEPROT;                             /**< EEPROM Protection Register, offset: 0x9 */
  __IO uint8_t FCCOBHI;                            /**< Flash Common Command Object Register:High, offset: 0xA */
  __IO uint8_t FCCOBLO;                            /**< Flash Common Command Object Register: Low, offset: 0xB */
  __I  uint8_t FOPT;                               /**< Flash Option Register, offset: 0xC */
} FTMRH_Type;

/*!
 * @}
 */ /* end of group FTMRH_Register_Masks */


/* FTMRH - Peripheral instance base addresses */
/** Peripheral FTMRH base address */
#define FTMRH_BASE                               (0x40020000u)
/** Peripheral FTMRH base pointer */
#define FTMRH                                    ((FTMRH_Type *)FTMRH_BASE)

#define FTFL_FSTAT_MGSTAT0  (1<<0)
#define FTFL_FSTAT_FPVIOL   (1<<4)
#define FTFL_FSTAT_ACCERR   (1<<5)
#define FTFL_FSTAT_RDCOLERR (1<<6)
#define FTFL_FSTAT_CCIF     (1<<7)

#define FLASH_CMD_PROGRAM 0x06
#define FLASH_CMD_ERASE_ALL 0x08
#define FLASH_CMD_ERASE_SECTOR 0x0A

#define INVALID_ADDRESS (unsigned char *)1

#define write_block_size 4
unsigned char write_block[write_block_size];
unsigned char *write_block_address=INVALID_ADDRESS;
unsigned char FCF[4] = { 0xff, 0xff, 0xfe, 0xff };
#define FLASH_START (uint8_t *)0
#define FLASH_SIZE (FLASH_PAGE_COUNT*FLASH_PAGE_SIZE)
#define FLASH_PAGE_COUNT 128
#define FLASH_PAGE_SIZE 512

static int
doFlashCmd()
{
  FTMRH->FSTAT = FTFL_FSTAT_ACCERR | FTFL_FSTAT_FPVIOL; // Write to clear
  FTMRH->FSTAT = FTFL_FSTAT_CCIF; // Go?
  while(!(FTMRH->FSTAT & FTFL_FSTAT_CCIF));  // Wait
  if (FTMRH->FSTAT & (FTFL_FSTAT_ACCERR | FTFL_FSTAT_FPVIOL | FTFL_FSTAT_MGSTAT0)) 
    return LIBMEM_STATUS_ERROR;
  else
    return LIBMEM_STATUS_SUCCESS;
}

static void
setFlashCmdAndAddress(unsigned char cmd, unsigned address)
{
  FTMRH->FCCOBIX = 0x0;
  FTMRH->FCCOBHI = cmd; 
  FTMRH->FCCOBLO = address>>16;
  FTMRH->FCCOBIX = 0x1;
  FTMRH->FCCOBHI = address>>8;
  FTMRH->FCCOBLO = address;
}

static int
flashCmdProgram(unsigned address, unsigned char value[4])
{
  setFlashCmdAndAddress(FLASH_CMD_PROGRAM, address);
  FTMRH->FCCOBIX = 0x2;
  FTMRH->FCCOBHI = value[1];
  FTMRH->FCCOBLO = value[0];
  FTMRH->FCCOBIX = 0x3;
  FTMRH->FCCOBHI = value[3];
  FTMRH->FCCOBLO = value[2];
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
libmem_erase_all(void)
{  
  FTMRH->FCCOBIX = 0x0;
  FTMRH->FCCOBHI = FLASH_CMD_ERASE_ALL; 
  doFlashCmd();    
  flashCmdProgram(0x40C, FCF);
  return LIBMEM_STATUS_SUCCESS;
}

int
libmem_erase(uint8_t *start, size_t size, uint8_t **erased_start, size_t *erased_size)
{
  int res = LIBMEM_STATUS_SUCCESS;   
  int found = 0;
  int j = FLASH_PAGE_COUNT;//geometry[0].count;
  int blocksize = FLASH_PAGE_SIZE;//geometry[0].size;
  uint8_t *end = start + size - 1;
  uint8_t *flashstart = FLASH_START;//h->start;      
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
              setFlashCmdAndAddress(FLASH_CMD_ERASE_SECTOR, (unsigned)flashstart);
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
  if ((FTMRH->FCLKDIV & 0x80)==0)
    FTMRH->FCLKDIV = 0x13;
  // turn off and invalidate any caching
  #define MCM_PLACR (*(volatile unsigned *)0xF000300C)
  MCM_PLACR = 0x1BC00;
  int res = libmem_rpc_loader_start(__RAM_segment_used_end__, __RAM_segment_end__ - 1); 
  MCM_PLACR = 0x0;
  libmem_rpc_loader_exit(res, 0);
  return 0;
}
