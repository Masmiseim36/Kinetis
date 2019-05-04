// Copyright (c) 2012 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <ctl_api.h>
#include <Kinetis.h>
#include "CMSIS/system_MKL25Z4.c"

#define RED_LED 8
#define SW3_BUTTON 4

void
delay(int count)
{
  volatile int i=0;
  while (i++<count);
}

void
ctl_board_init(void)
{
  SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK; // Enable PORTA and PORTB
  // LED AF 1 GPIO, OUTPUT
  PORTB->PCR[RED_LED] = PORT_PCR_MUX(1);
  PTB->PDOR = 1<<RED_LED;
  PTB->PDDR = 1<<RED_LED;
  // BUTTON AF1 GPIO, interrupt on falling edge, enable pull-up
  PORTA->PCR[SW3_BUTTON] = PORT_PCR_MUX(1)|PORT_PCR_IRQC(0xA)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
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
PORTA_IRQHandler(void)
{
  ctl_enter_isr();
  if (PORTA->ISFR & (1<<SW3_BUTTON))
    {
      userButtonISR();
      PORTA->ISFR = (1<<SW3_BUTTON);
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
