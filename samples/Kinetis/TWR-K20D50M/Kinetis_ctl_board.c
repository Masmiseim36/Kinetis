// Copyright (c) 2010, 2011 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <ctl_api.h>
#include <Kinetis.h>
#include "CMSIS/system_MK20D5.c"

#define E1_LED 10
#define SW3_BUTTON 2

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
  PORTC->PCR[E1_LED] = PORT_PCR_MUX(1);
  PTC->PDOR = 1<<E1_LED;
  PTC->PDDR = 1<<E1_LED;
  // BUTTON AF1 GPIO, interrupt on falling edge, enable pull-up
  PORTC->PCR[SW3_BUTTON] = PORT_PCR_MUX(1)|PORT_PCR_IRQC(0xA)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
}

void 
ctl_board_set_leds(unsigned on)
{
  if (on)
    PTC->PSOR = 1<<E1_LED;
  else
    PTC->PCOR = 1<<E1_LED;
}

static CTL_ISR_FN_t userButtonISR;

void
PORTC_IRQHandler(void)
{
  ctl_enter_isr();
  if (PORTC->ISFR & (1<<SW3_BUTTON))
    {
      userButtonISR();
      PORTC->ISFR = (1<<SW3_BUTTON);
    }
  ctl_exit_isr();
}

void 
ctl_board_on_button_pressed(CTL_ISR_FN_t isr)
{
  userButtonISR = isr;
  ctl_set_priority(PORTC_IRQn, 1);
  ctl_unmask_isr(PORTC_IRQn);
}