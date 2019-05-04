// Copyright (c) 2013 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <ctl_api.h>
#include <Kinetis.h>
#if 0
#include "CMSIS/system_MKE04Z4.c"
#else
#include "CMSIS/MKE04Z4.h"
void SystemInit (void) __attribute__ ((section (".init")));
extern uint32_t SystemCoreClock  __attribute__ ((section(".non_init")));

uint32_t SystemCoreClock;

#define WDOG_CNT          *((volatile unsigned short*)0x40052002)
#define WDOG_TOVAL        *((volatile unsigned short*)0x40052004)
#define WDOG_WIN          *((volatile unsigned short*)0x40052006)

void SystemInit()
{
  WDOG->CS2 = 0;
  WDOG_CNT = 0x20C5;
  WDOG_CNT = 0x28D9;
  WDOG_TOVAL = 0xFFFF;
  WDOG->CS1 = 0x20;

  OSC->CR = OSC_CR_OSCEN_MASK | OSC_CR_OSCSTEN_MASK | OSC_CR_RANGE_MASK | OSC_CR_OSCOS_MASK;
  __asm("nop");
  __asm("nop");
  while(!(OSC->CR & OSC_CR_OSCINIT_MASK));

  ICS->C1 = (ICS->C1 & ~(ICS_C1_RDIV_MASK)) | ICS_C1_RDIV(3);
  ICS->C1 = ICS->C1 & ~ICS_C1_IREFS_MASK;
  __asm("nop");
  __asm("nop");

  while(ICS->S & ICS_S_IREFST_MASK);
  while(!(ICS->S & ICS_S_LOCK_MASK));

  ICS->C2 = 0;

  SystemCoreClock = 10000000/256*1024/1;
}
#endif

#define RED_LED 21

void
delay(int count)
{
  volatile int i=0;
  while (i++<count);
}

void
ctl_board_init(void)
{
  FPTA->PDDR = 1<<RED_LED;
}

void 
ctl_board_set_leds(unsigned on)
{
  if (on)
    FPTA->PSOR = 1<<RED_LED;
  else
    FPTA->PCOR = 1<<RED_LED;
}

static CTL_ISR_FN_t userButtonISR;

void 
ctl_board_on_button_pressed(CTL_ISR_FN_t isr)
{
  userButtonISR = isr;  
}
