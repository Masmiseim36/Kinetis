// Copyright (c) 2012,2013 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <ctl_api.h>
#include <Kinetis.h>
#include "CMSIS/system_MKL05Z4.c"

#define RED_LED 8

void
delay(int count)
{
  volatile int i=0;
  while (i++<count);
}

void
ctl_board_init(void)
{
  SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK; // Enable PORTB
  // LED AF 1 GPIO, OUTPUT
  PORTB->PCR[RED_LED] = PORT_PCR_MUX(1);
  PTB->PDOR = 1<<RED_LED;
  PTB->PDDR = 1<<RED_LED;
}

void 
ctl_board_set_leds(unsigned on)
{
  if (on)
    PTB->PSOR = 1<<RED_LED;
  else
    PTB->PCOR = 1<<RED_LED;
}

static CTL_ISR_FN_t userButtonISR;

void 
ctl_board_on_button_pressed(CTL_ISR_FN_t isr)
{
  userButtonISR = isr;  
}
