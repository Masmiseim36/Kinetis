// Copyright (c) 2012 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <ctl_api.h>
#include <Kinetis.h>

#ifdef WITH_DDR

void SystemInit (void) __attribute__ ((section (".init")));
extern uint32_t SystemCoreClock  __attribute__ ((section(".non_init")));

uint32_t SystemCoreClock;

void SystemInit()
{
  WDOG->UNLOCK = (uint16_t)0xC520u;   
  WDOG->UNLOCK  = (uint16_t)0xD928u;
  WDOG->STCTRLH = (uint16_t)0x01D2u;
 
//---------------------------------------------------------------
//__message "-- Setting PLL0 and PLL1 \n";  
// Clock
  SIM->SCGC5 = 0x00047F82; //__writeMemory32(0x00047F82, 0x40048038, "Memory");	// SIM_SCGC5
  SIM->CLKDIV1 = 0x01150000;// __writeMemory32(0x01150000, 0x40048044, "Memory");	// SIM_CLKDIV1
// PLL 1
  //__message " -- Setup PLL 1\n";
  MCG->C2 = 0x10;//__writeMemory8(0x10, 0x40064001, "Memory");     // MCG_C2 tower can osc
//    __writeMemory8(0x14, 0x40064001, "Memory");	      // MCG_C2 firebird crystal
  MCG->C1 = 0xA8;//__writeMemory8(0xA8, 0x40064000, "Memory");	      // MCG_C1            
  MCG->C5 = 0x04;//__writeMemory8(0x04, 0x40064004, "Memory");     // MCG_C5 tower /5
//    __writeMemory8(0x00, 0x40064004, "Memory");	      // MCG_C5 firebird /1
//    __writeMemory8(0x44, 0x40064005, "Memory");	      // MCG_C6 firebird
  MCG->C6 = 0x68;//__writeMemory8(0x68, 0x40064005, "Memory");     // MCG_C6 tower
  unsigned reg  = MCG->C5;//__readMemory8(0x40064004, "Memory");       // MCG_C5
  reg |= 0x40u;                                 // MCG_C5 PLL0 enable
  MCG->C5 = reg;//__writeMemory8(reg, 0x40064004, "Memory");	      // MCG_C5 
  reg = MCG->C1;//__readMemory8(0x40064000, "Memory");       // MCG_C1
  reg &= ~0xC0u;                                // MCG_C1 CLKS = 00
  MCG->C1 = reg;//__writeMemory8(reg, 0x40064000, "Memory");	      // MCG_C1
    
  //---------------------------------------------------------------
  //     PLL 2
  //    __message " -- Setup PLL 2\n";
  MCG->C10 = 0x14;//__writeMemory8(0x14, 0x4006400F, "Memory");     // MCG_C10  Tower osc
  //    __writeMemory8(0x14, 0x4006400F, "Memory");       // MCG_C10  Firebird osc
  MCG->C12 = 0x0E;//__writeMemory8(0x0E, 0x40064011, "Memory");     // MCG_C12  Tower x30
  //    __writeMemory8(0x09, 0x40064011, "Memory");	      // MCG_C12  Firebird x25
  MCG->C11 = 0x44;//__writeMemory8(0x44, 0x40064010, "Memory");     // MCG_C11  Tower /5
  //    __writeMemory8(0x40, 0x40064010, "Memory");	      // MCG_C11  Firebird /1

  //__message " -- Enable Trace clock\n";
  //__writeMemory32(0x44001004, 0x40048004, "Memory");
  //__writeMemory32(0x600, 0x4004E05C, "Memory"); //PORTF_PCR23

  /* Enable DDR controller clock */
  //SIM_SCGC3 |= SIM_SCGC3_DDR_MASK;
  reg  = SIM->SCGC3;//__readMemory32(0x40048030u,"Memory");
  reg |= 0x4000u;
  SIM->SCGC3 = reg;//__writeMemory32(reg, 0x40048030u, "Memory"); //System clock gating Register (SIM_SCGC3)

  /* Enable DDR pads and set slew rate */
  //SIM_MCR |= 0xC4;   // bits were left out of the manual so there isn't a macro right now
  SIM->MCR = 0xC4; //__writeMemory32(0xC4, 0x4004806Cu, "Memory"); //RCR Control Register (DDR_RCR)

  /*I/O Pad Control (PAD_CTRL) register.*/
  //  * (vuint32 *)(0x400AE1AC) = 0x01030203;
  //__writeMemory16(0x01030203u, 0x400Ae1acu, "Memory"); 
  DDR->PAD_CTRL = 0x01030203;

  DDR->CR00 = 0x00000400;//__writeMemory32(0x00000400, 0x400AE000u, "Memory"); //DDR Control Register 0 (DDR_CR00)
  //DDR->CR01 = 0x01000000;__writeMemory32(0x01000000, 0x400AE004u, "Memory"); //DDR Control Register 1 (DDR_CR01)
  DDR->CR02 = 0x02000031;//__writeMemory32(0x02000031, 0x400AE008u, "Memory"); //DDR Control Register 2 (DDR_CR02)
  DDR->CR03 = 0x02020506;//__writeMemory32(0x02020506, 0x400AE00Cu, "Memory"); //DDR Control Register 3 (DDR_CR03)
  DDR->CR04 = 0x06090202;//__writeMemory32(0x06090202, 0x400AE010u, "Memory"); //DDR Control Register 4 (DDR_CR04)
  DDR->CR05 = 0x02020302;//__writeMemory32(0x02020302, 0x400AE014u, "Memory"); //DDR Control Register 5 (DDR_CR05)
  DDR->CR06 = 0x02904002;//__writeMemory32(0x02904002, 0x400AE018u, "Memory"); //DDR Control Register 6 (DDR_CR06)
  DDR->CR07 = 0x01000303;//__writeMemory32(0x01000303, 0x400AE01Cu, "Memory"); //DDR Control Register 7 (DDR_CR07)
  DDR->CR08 = 0x05030201;//__writeMemory32(0x05030201, 0x400AE020u, "Memory"); //DDR Control Register 8 (DDR_CR08)
  DDR->CR09 = 0x020000c8;//__writeMemory32(0x020000c8, 0x400AE024u, "Memory"); //DDR Control Register 9 (DDR_CR09)
  DDR->CR10 = 0x03003207;//__writeMemory32(0x03003207, 0x400AE028u, "Memory"); //DDR Control Register 10 (DDR_CR10)
  DDR->CR11 = 0x01000000;//__writeMemory32(0x01000000, 0x400AE02Cu, "Memory"); //DDR Control Register 11 (DDR_CR11)
  DDR->CR12 = 0x04920031;//__writeMemory32(0x04920031, 0x400AE030u, "Memory"); //DDR Control Register 12 (DDR_CR12)
  DDR->CR13 = 0x00000005;//__writeMemory32(0x00000005, 0x400AE034u, "Memory"); //DDR Control Register 13 (DDR_CR13)
  DDR->CR14 = 0x00C80002;//__writeMemory32(0x00C80002, 0x400AE038u, "Memory"); //DDR Control Register 14 (DDR_CR14)
  DDR->CR15 = 0x00000032;//__writeMemory32(0x00000032, 0x400AE03Cu, "Memory"); //DDR Control Register 15 (DDR_CR15)
  DDR->CR16 = 0x00000001;//__writeMemory32(0x00000001, 0x400AE040u, "Memory"); //DDR Control Register 16 (DDR_CR16)
  //DDR->CR17 = //__writeMemory32( , 0x400AE044u, "Memory"); //DDR Control Register 17 (DDR_CR17)
  //DDR->CR18 = //__writeMemory32( , 0x400AE048u, "Memory"); //DDR Control Register 18 (DDR_CR18)
  //DDR->CR19 = //__writeMemory32( , 0x400AE04Cu, "Memory"); //DDR Control Register 19 (DDR_CR19)
  DDR->CR20 = 0x00030300;//__writeMemory32(0x00030300, 0x400AE050u, "Memory"); //DDR Control Register 20 (DDR_CR20)
  DDR->CR21 = 0x00040232;//__writeMemory32(0x00040232, 0x400AE054u, "Memory"); //DDR Control Register 21 (DDR_CR21)
  DDR->CR22 = 0x00000000;//__writeMemory32(0x00000000, 0x400AE058u, "Memory"); //DDR Control Register 22 (DDR_CR22)
  //DDR->CR23 = 0x00040302;__writeMemory32(0x00040302, 0x400AE05Cu, "Memory"); //DDR Control Register 23 (DDR_CR23)
  //DDR->CR24 = //__writeMemory32( , 0x400AE060u, "Memory"); //DDR Control Register 24 (DDR_CR24)
  DDR->CR25 = 0x0A010201;//__writeMemory32(0x0A010201, 0x400AE064u, "Memory"); //DDR Control Register 25 (DDR_CR25)
  DDR->CR26 = 0x0101FFFF;//__writeMemory32(0x0101FFFF, 0x400AE068u, "Memory"); //DDR Control Register 26 (DDR_CR26)
  DDR->CR27 = 0x01010101;//__writeMemory32(0x01010101, 0x400AE06Cu, "Memory"); //DDR Control Register 27 (DDR_CR27)
  DDR->CR28 = 0x00000003;//__writeMemory32(0x00000003, 0x400AE070u, "Memory"); //DDR Control Register 28 (DDR_CR28)
  DDR->CR29 = 0x00000000;//__writeMemory32(0x00000000, 0x400AE074u, "Memory"); //DDR Control Register 29 (DDR_CR29)
  DDR->CR30 = 0x00000001;//__writeMemory32(0x00000001 , 0x400AE078u, "Memory"); //DDR Control Register 30 (DDR_CR30)
  //DDR->CR31 =//__writeMemory32( , 0x400AE07Cu, "Memory"); //DDR Control Register 31 (DDR_CR31)
  //DDR->CR32 =//__writeMemory32( , 0x400AE080u, "Memory"); //DDR Control Register 32 (DDR_CR32)
  //DDR->CR33 =//__writeMemory32( , 0x400AE084u, "Memory"); //DDR Control Register 33 (DDR_CR33)
  DDR->CR34 = 0x02020101;//__writeMemory32(0x02020101, 0x400AE088u, "Memory"); //DDR Control Register 34 (DDR_CR34)
  //DDR->CR35 = //__writeMemory32( , 0x400AE08Cu, "Memory"); //DDR Control Register 35 (DDR_CR35)
  //DDR->CR36 = 0x01010201;//__writeMemory32(0x01010201, 0x400AE090u, "Memory"); //DDR Control Register 36 (DDR_CR36)
  DDR->CR37 = 0x00000200;//__writeMemory32(0x00000200, 0x400AE094u, "Memory"); //DDR Control Register 37 (DDR_CR37)
  DDR->CR38 = 0x00200000;//__writeMemory32(0x00200000, 0x400AE098u, "Memory"); //DDR Control Register 38 (DDR_CR38)
  DDR->CR39 = 0x01010020;//__writeMemory32(0x01010020, 0x400AE09Cu, "Memory"); //DDR Control Register 39 (DDR_CR39)
  DDR->CR40 = 0x00002000;//__writeMemory32(0x00002000, 0x400AE0A0u, "Memory"); //DDR Control Register 40 (DDR_CR40)
  DDR->CR41 = 0x01010020;//__writeMemory32(0x01010020, 0x400AE0A4u, "Memory"); //DDR Control Register 41 (DDR_CR41)
  DDR->CR42 = 0x00002000;//__writeMemory32(0x00002000, 0x400AE0A8u, "Memory"); //DDR Control Register 42 (DDR_CR42)
  DDR->CR43 = 0x01010020;//__writeMemory32(0x01010020, 0x400AE0ACu, "Memory"); //DDR Control Register 43 (DDR_CR43)
  DDR->CR44 = 0x00000000;//__writeMemory32(0x00000000, 0x400AE0B0u, "Memory"); //DDR Control Register 44 (DDR_CR44)
  DDR->CR45 = 0x03030303;//__writeMemory32(0x03030303, 0x400AE0B4u, "Memory"); //DDR Control Register 45 (DDR_CR45)
  DDR->CR46 = 0x02006401;//__writeMemory32(0x02006401, 0x400AE0B8u, "Memory"); //DDR Control Register 46 (DDR_CR46)
  DDR->CR47 = 0x01020202;//__writeMemory32(0x01020202, 0x400AE0BCu, "Memory"); //DDR Control Register 47 (DDR_CR47)
  DDR->CR48 = 0x01010064;//__writeMemory32(0x01010064, 0x400AE0C0u, "Memory"); //DDR Control Register 48 (DDR_CR48)
  DDR->CR49 = 0x00020101;//__writeMemory32(0x00020101, 0x400AE0c4u, "Memory"); //DDR Control Register 49 (DDR_CR49)
  DDR->CR50 = 0x00000064;//__writeMemory32(0x00000064, 0x400AE0C8u, "Memory"); //DDR Control Register 50 (DDR_CR50)
  //DDR->CR51 = //__writeMemory32( , 0x400AE0CCu, "Memory"); //DDR Control Register 51 (DDR_CR51)
  DDR->CR52 = 0x02000602;//__writeMemory32(0x02000602, 0x400AE0D0u, "Memory"); //DDR Control Register 52 (DDR_CR52)
  DDR->CR53 = 0x03c80000;//__writeMemory32(0x03c80000, 0x400AE0D4u, "Memory"); //DDR Control Register 53 (DDR_CR53)
  DDR->CR54 = 0x03c803c8;//__writeMemory32(0x03c803c8, 0x400AE0D8u, "Memory"); //DDR Control Register 54 (DDR_CR54)
  DDR->CR55 = 0x03c803c8;//__writeMemory32(0x03c803c8, 0x400AE0DCu, "Memory"); //DDR Control Register 55 (DDR_CR55)
  DDR->CR56 = 0x020303c8;//__writeMemory32(0x020303c8, 0x400AE0E0u, "Memory"); //DDR Control Register 56 (DDR_CR56)
  DDR->CR57 = 0x01010002;//__writeMemory32(0x01010002, 0x400AE0E4u, "Memory"); //DDR Control Register 57 (DDR_CR57)
  //DDR->CR58 = //__writeMemory32( , 0x400AE0E8u, "Memory"); //DDR Control Register 58 (DDR_CR58)
  //DDR->CR59 = //__writeMemory32( , 0x400AE0ECu, "Memory"); //DDR Control Register 59 (DDR_CR59)
  //DDR->CR60 = //__writeMemory32( , 0x400AE0F0u, "Memory"); //DDR Control Register 60 (DDR_CR60)
  //DDR->CR61 = //__writeMemory32( , 0x400AE0F4u, "Memory"); //DDR Control Register 61 (DDR_CR61)
  //DDR->CR62 = //__writeMemory32( , 0x400AE0F8u, "Memory"); //DDR Control Register 62 (DDR_CR62)
  //DDR->CR63 = //__writeMemory32( , 0x400AE0FCu, "Memory"); //DDR Control Register 63 (DDR_CR63)
  DDR->CR00 = 0x00000401;//__writeMemory32(0x00000401, 0x400AE000, "Memory");	// DDR_CR00	start
  MCM->CR = 0x00100000;//__writeMemory32(0x00100000, 0xE008000C, "Memory");	// MCM_CR	128MB
    
  // Enable caches
  LMEM->PCCCR = 0x85000001;
  LMEM->PSCCR = 0x85000003; 
  SystemCoreClock = 120000000;
}
#else
#define CLOCK_SETUP 1
#include "CMSIS/system_MK70F12.c"
#endif

#define E1_LED 11
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
  SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK| SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTF_MASK; // Enable PORTA | PORTD
  // LED AF1 GPIO, OUTPUT
  PORTA->PCR[E1_LED] = PORT_PCR_MUX(1); 
  PTA->PDOR = 1<<E1_LED;
  PTA->PDDR = 1<<E1_LED;
  // BUTTON AF1 GPIO, interrupt on falling edge, enable pull-up
  PORTD->PCR[SW1_BUTTON] = PORT_PCR_MUX(1)|PORT_PCR_IRQC(0xA)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
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
PORTD_IRQHandler(void)
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
  ctl_set_priority(PORTD_IRQn, 1);
  ctl_unmask_isr(PORTD_IRQn);
}
