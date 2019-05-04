// Copyright (c) 2012 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <ctl_api.h>
#include <Kinetis.h>
#include "CMSIS/system_MKL46Z4.c"

#define RED_LED 29
#define SW1_BUTTON 3

void
delay(int count)
{
  volatile int i=0;
  while (i++<count);
}

void
ctl_board_init(void)
{
  SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTE_MASK;
  // LED AF 1 GPIO, OUTPUT
  PORTE->PCR[RED_LED] = PORT_PCR_MUX(1);
  PTE->PDOR = 1<<RED_LED;
  PTE->PDDR = 1<<RED_LED;
  // BUTTON AF1 GPIO, interrupt on falling edge, enable pull-up
  PORTC->PCR[SW1_BUTTON] = PORT_PCR_MUX(1)|PORT_PCR_IRQC(0xA)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
}

void 
ctl_board_set_leds(unsigned on)
{
  if (on)
    PTE->PSOR = 1<<RED_LED;
  else
    PTE->PCOR = 1<<RED_LED;
}

static CTL_ISR_FN_t userButtonISR;

void
PORTC_PORTD_IRQHandler(void)
{
  ctl_enter_isr();
  if (PORTC->ISFR & (1<<SW1_BUTTON))
    {
      userButtonISR();
      PORTC->ISFR = (1<<SW1_BUTTON);
    }
  ctl_exit_isr();
}

void 
ctl_board_on_button_pressed(CTL_ISR_FN_t isr)
{
  userButtonISR = isr;
  ctl_set_priority(PORTC_PORTD_IRQn, 1);
  ctl_unmask_isr(PORTC_PORTD_IRQn);
}
