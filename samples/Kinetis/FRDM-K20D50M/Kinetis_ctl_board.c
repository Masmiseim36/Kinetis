// Copyright (c) 2013 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <ctl_api.h>
#include <Kinetis.h>
#include "CMSIS/system_MK20D5.c"

#define RED_LED 3

void
delay(int count)
{
  volatile int i=0;
  while (i++<count);
}

void
ctl_board_init(void)
{
  SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK; // Enable PORTC
  // LED AF 1 GPIO, OUTPUT
  PORTC->PCR[RED_LED] = PORT_PCR_MUX(1);
  PTC->PDOR = 1<<RED_LED;
  PTC->PDDR = 1<<RED_LED;
}

void 
ctl_board_set_leds(unsigned on)
{
  if (on)
    PTC->PSOR = 1<<RED_LED;
  else
    PTC->PCOR = 1<<RED_LED;
}

static CTL_ISR_FN_t userButtonISR;

void 
ctl_board_on_button_pressed(CTL_ISR_FN_t isr)
{
  userButtonISR = isr;  
}
