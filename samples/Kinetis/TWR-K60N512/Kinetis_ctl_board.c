// Copyright (c) 2010, 2011 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <ctl_api.h>
#include <Kinetis.h>

#ifndef __NO_PLL
#define _100Mhz

void set_sys_dividers(unsigned outdiv1, unsigned outdiv2, unsigned outdiv3, unsigned outdiv4)__attribute__((__long_call__,section(".fast")));

void sysinit (void)__attribute__((constructor));
void sysinit (void)
{
  // PLL setup Code derived from Freescale KINETIS512_SC package for a board with a 50Mhz external clock
  
  // First move to FBE mode
  MCG->C2 = 0;

  // after initialization of oscillator release latched state of oscillator and GPIO
  SIM->SCGC4 |= SIM_SCGC4_LLWU_MASK;
  LLWU->CS |= LLWU_CS_ACKISO_MASK;
  
  // Select external oscillator and Reference Divider and clear IREFS to start ext osc
  // CLKS=2, FRDIV=3, IREFS=0, IRCLKEN=0, IREFSTEN=0
  MCG->C1 = MCG_C1_CLKS(2) | MCG_C1_FRDIV(3);

  while (MCG->S & MCG_S_IREFST_MASK){}; // wait for Reference clock Status bit to clear

  while (((MCG->S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) != 0x2){}; // Wait for clock status bits to show clock source is ext ref clk

  // Now in FBE

  MCG->C5 = MCG_C5_PRDIV(0x18);

  // Ensure MCG_C6 is at the reset default of 0. LOLIE disabled, PLL disabled, clk monitor disabled, PLL VCO divider is clear
  MCG->C6 = 0x0;

  // Set system options dividers
#if defined(_50Mhz)
  //MCG=PLL, core = MCG, bus = MCG, FlexBus = MCG, Flash clock= MCG/2
  set_sys_dividers(0,0,0,1);
  // Set the VCO divider and enable the PLL for 50MHz, LOLIE=0, PLLS=1, CME=0, VDIV=1
  MCG->C6 = MCG_C6_PLLS_MASK | MCG_C6_VDIV(1); //VDIV = 1 (x25)
  SystemCoreClock = 50 * 1000000;
#elif defined(_100Mhz)
  //MCG=PLL, core = MCG, bus = MCG/2, FlexBus = MCG/2, Flash clock= MCG/4
  set_sys_dividers(0,1,1,3);
  // Set the VCO divider and enable the PLL for 100MHz, LOLIE=0, PLLS=1, CME=0, VDIV=26
  MCG->C6 = MCG_C6_PLLS_MASK | MCG_C6_VDIV(26); //VDIV = 26 (x50)
  SystemCoreClock = 100 * 1000000;
#elif defined(_96Mhz)
  //MCG=PLL, core = MCG, bus = MCG/2, FlexBus = MCG/2, Flash clock= MCG/4
  set_sys_dividers(0,1,1,3);
  // Set the VCO divider and enable the PLL for 96MHz, LOLIE=0, PLLS=1, CME=0, VDIV=24
  MCG->C6 = MCG_C6_PLLS_MASK | MCG_C6_VDIV(24); //VDIV = 24 (x48)
  SystemCoreClock = 96 * 1000000;
#elif defined(_48Mhz)
  //MCG=PLL, core = MCG, bus = MCG, FlexBus = MCG, Flash clock= MCG/2
  set_sys_dividers(0,0,0,1);
  // Set the VCO divider and enable the PLL for 48MHz, LOLIE=0, PLLS=1, CME=0, VDIV=0
  MCG->C6 = MCG_C6_PLLS_MASK; //VDIV = 0 (x24)
  SystemCoreClock = 48 * 1000000;
#endif

  while (!(MCG->S & MCG_S_PLLST_MASK)){}; // wait for PLL status bit to set

  while (!(MCG->S & MCG_S_LOCK_MASK)){}; // Wait for LOCK bit to set

  // Now running PBE Mode

  // Transition into PEE by setting CLKS to 0
  // CLKS=0, FRDIV=3, IREFS=0, IRCLKEN=0, IREFSTEN=0
  MCG->C1 &= ~MCG_C1_CLKS_MASK;

  // Wait for clock status bits to update
  while (((MCG->S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) != 0x3){};

  // Now running PEE Mode
}

#else

void sysinit (void)__attribute__((constructor));
void sysinit (void)
{
  SystemCoreClockUpdate();
}

#endif

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
