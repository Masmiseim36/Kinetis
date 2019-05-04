// Copyright (c) 2012 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <ctl_api.h>
#include <Kinetis.h>

#define CLOCK_SETUP 1
#include "CMSIS/system_MK60F12.c"

#define E1_LED 11
#define SW1_BUTTON 19

void
delay(int count)
{
  volatile int i=0;
  while (i++<count);
}

void
ctl_board_init(void)
{
  SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK; // Enable PORTA
  // LED AF1 GPIO, OUTPUT
  PORTA->PCR[E1_LED] = PORT_PCR_MUX(1); 
  PTA->PDOR = 1<<E1_LED;
  PTA->PDDR = 1<<E1_LED;
  // BUTTON AF1 GPIO, interrupt on falling edge, enable pull-up
  PORTA->PCR[SW1_BUTTON] = PORT_PCR_MUX(1)|PORT_PCR_IRQC(0xA)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
}

void 
ctl_board_set_leds(unsigned on)
{
  if (on)
    PTA->PSOR = 1<<E1_LED;
  else
    PTA->PCOR = 1<<E1_LED;
}

static CTL_ISR_FN_t userButtonISR;

void
PORTA_IRQHandler(void)
{
  ctl_enter_isr();
  if (PORTA->ISFR & (1<<SW1_BUTTON))
    {
      userButtonISR();
      PORTA->ISFR = (1<<SW1_BUTTON);
    }
  ctl_exit_isr();
}

void 
ctl_board_on_button_pressed(CTL_ISR_FN_t isr)
{
  userButtonISR = isr;
  ctl_set_priority(PORTA_IRQn, 1);
  ctl_unmask_isr(PORTA_IRQn);
}
