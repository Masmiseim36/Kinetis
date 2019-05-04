// Copyright (c) 2013 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <ctl_api.h>
#include <Kinetis.h>
//#include "CMSIS/system_MKM34Z5.c"

#define DISABLE_WDOG    1
#define DEFAULT_SYSTEM_CLOCK           48000000 /* Default System clock value */

#define WAIT_FOR_STATUS_FLAG(reg,name1,name2)                                 \
{                                                                             \
  while (((MCG->S&MCG_S_##name2##_MASK)>>MCG_S_##name2##_SHIFT)!=              \
    ((MCG->reg &MCG_##reg##_##name1##_MASK)>>MCG_##reg##_##name1##_SHIFT));                 \
}

uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;


void SystemInit (void) {
#if (DISABLE_WDOG)
  /* Disable the WDOG module */
  /* WDOG_UNLOCK: WDOGUNLOCK=0xC520 */
  WDOG->UNLOCK = (uint16_t)0xC520u;     /* Key 1 */
  /* WDOG_UNLOCK : WDOGUNLOCK=0xD928 */
  WDOG->UNLOCK  = (uint16_t)0xD928u;    /* Key 2 */
  /* WDOG_STCTRLH: ??=0,DISTESTWDOG=0,BYTESEL=0,TESTSEL=0,TESTWDOG=0,??=0,STNDBYEN=1,WAITEN=1,STOPEN=1,DBGEN=0,ALLOWUPDATE=1,WINEN=0,IRQRSTEN=0,CLKSRC=1,WDOGEN=0 */
  WDOG->STCTRLH = (uint16_t)0x01D2u;
#endif /* (DISABLE_WDOG) */
  MCG->SC = 0x00; 
  MCG->C8 = 0x80;
  /* Select MCG PLL 32Khz Reference Clock Select and MCG OSC Clock Select     */
  MCG->C7 = 0x01;     
  /* External Reference clock setup                                           */
  MCG->C2 = 0x88;
  if (MCG->C2 & MCG_C2_EREFS0_MASK) { WAIT_FOR_STATUS_FLAG (C2, EREFS0, OSCINIT0); }      
  /* Setup C1 register keeping MCGOUTCLK clocked from internal reference clock*/
  MCG->C1 = (0x00 & ~MCG_C1_CLKS_MASK) | MCG_C1_CLKS(1); 
 // if (MCG_C1 &   MCG_C1_IREFS_MASK) { WAIT_FOR_STATUS_FLAG (MCG_C1, IREFS, IREFST); } 
  MCG->C4 = (MCG->C4 & (MCG_C4_FCTRIM_MASK|MCG_C4_SCFTRIM_MASK)) | 0xA0;
  while ((MCG->C4 & MCG_C4_DRST_DRS_MASK) != (0xA0 & MCG_C4_DRST_DRS_MASK)); 
  MCG->C6 = 0x00;  
  /* Switch MCGOUTCLK clock source                                            */
  MCG->C1 = 0x00;   
  WAIT_FOR_STATUS_FLAG (C1, CLKS, CLKST);  
  if (MCG->C1 & MCG_C1_IRCLKEN_MASK) { WAIT_FOR_STATUS_FLAG (C2, IRCS, IRCST); }   
}

#define RED_LED 1
#define SW1_BUTTON 0

void
delay(int count)
{
  volatile int i=0;
  while (i++<count);
}

void
ctl_board_init(void)
{
  SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTF_MASK; // Enable PORTD
  // LED AF 1 GPIO, OUTPUT
  PORTF->PCR[RED_LED] = PORT_PCR_MUX(1);
  GPIOF->PDOR = 1<<RED_LED;
  GPIOF->PDDR = 1<<RED_LED;
  // BUTTON AF1 GPIO, interrupt on falling edge, enable pull-up
  PORTD->PCR[SW1_BUTTON] = PORT_PCR_MUX(1)|PORT_PCR_IRQC(0xA)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
}

void 
ctl_board_set_leds(unsigned on)
{
  if (on)
    GPIOF->PDOR |= 1<<RED_LED;
  else
    GPIOF->PDOR &= ~(1<<RED_LED);
}

static CTL_ISR_FN_t userButtonISR;

void
PTx_IRQHandler(void)
{
  ctl_enter_isr();
  if (PORTD->ISFR & (1<<SW1_BUTTON))
    {
      userButtonISR();
      PORTD->ISFR = (1<<SW1_BUTTON);
    }
  ctl_exit_isr();
}

void 
ctl_board_on_button_pressed(CTL_ISR_FN_t isr)
{
  userButtonISR = isr;
  ctl_set_priority(PTx_IRQn, 1);
  ctl_unmask_isr(PTx_IRQn);
}
