/*
** ###################################################################
**     Processors:          MK60DN512ZVLL10
**                          MK60DX256ZVLL10
**                          MK60DN256ZVLL10
**                          MK60DN512ZVLQ10
**                          MK60DN256ZVLQ10
**                          MK60DX256ZVLQ10
**                          MK60DN512ZVMC10
**                          MK60DN256ZVMC10
**                          MK60DX256ZVMC10
**                          MK60DN512ZVMD10
**                          MK60DX256ZVMD10
**                          MK60DN256ZVMD10
**
**     Compilers:           ARM Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    K60P144M100SF2RM, Rev. 5, 8 May 2011
**     Version:             rev. 1.5, 2013-04-05
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright: 2013 Freescale, Inc. All Rights Reserved.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2011-06-10)
**         Initial version.
**         Changes with respect to the previous MK60NxxxMD100 header file:
**         RTC  - CCR register removed. Replaced by IER register.
**         CRC  - added CTRLHU register for 8-bit access to the CTRL register.
**         FB   - bit FB_CSCR_EXALE renamed to FB_CSCR_EXTS.
**         SIM  - bit group FSIZE in SIM_FCFG1 split into groups PFSIZE and NVMSIZE.
**         I2S  - bit SSIEN in I2S_CR register renamed to I2SEN.
**         SDHC - bit VOLTSEL in SDHC_VENDOR register removed.
**     - rev. 1.1 (2011-06-29)
**         Order of declarations changed.
**     - rev. 1.2 (2011-09-08)
**         Cortex_Core_Configuration extended with additional parameters.
**         Gap between end of interrupt vector table and flash configuration field filled by default ISR.
**     - rev. 1.3 (2012-01-10)
**         Registers updated according to the new reference manual revision - Rev. 6, 6 Nov 2011
**         ADC - PGALPb bit group added.
**         PDB - Register PO)EN renamed to POEN
**         SDHC - WRBRSTLEN bit group added
**         SIM - Bit DSPI0 in SCGC6 register renamed to SPI0.
**     - rev. 1.4 (2012-04-13)
**         Added new #define symbol MCU_MEM_MAP_VERSION_MINOR.
**         Added new #define symbols <peripheralType>_BASE_PTRS.
**     - rev. 1.5 (2013-04-05)
**         Changed start of doxygen comment.
**
** ###################################################################
*/

/*!
 * @file MK60DZ10
 * @version 1.5
 * @date 2013-04-05
 * @brief Device specific configuration file for MK60DZ10 (implementation file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#include <stdint.h>
#include "MK60DZ10.h"

#define DISABLE_WDOG    1

#ifndef CLOCK_SETUP
#define CLOCK_SETUP     0
#endif
/* Predefined clock setups
   0 ... Multipurpose Clock Generator (MCG) in FLL Engaged Internal (FEI) mode
         Reference clock source for MCG module is the slow internal clock source 32.768kHz
         Core clock = 41.94MHz, BusClock = 41.94MHz
   1 ... Multipurpose Clock Generator (MCG) in PLL Engaged External (PEE) mode
         Reference clock source for MCG module is an external crystal 8MHz
         Core clock = 48MHz, BusClock = 48MHz
   2 ... Multipurpose Clock Generator (MCG) in Bypassed Low Power External (BLPE) mode
         Core clock/Bus clock derived directly from an external crystal 8MHz with no multiplication
         Core clock = 8MHz, BusClock = 8MHz
   3 ... Multipurpose Clock Generator (MCG) in PLL Engaged External (PEE) mode
         Reference clock source for MCG module is an external clock source 50MHz
         Core clock = 100MHz, BusClock = 50MHz
   4 ... Multipurpose Clock Generator (MCG) in Bypassed Low Power External (BLPE) mode
         Core clock/Bus clock derived directly from an external clock source 50MHz with no multiplication
         Core clock = 50MHz, BusClock = 50MHz
*/

/*----------------------------------------------------------------------------
  Define clock source values
 *----------------------------------------------------------------------------*/
#if (CLOCK_SETUP == 0)
    #define CPU_XTAL_CLK_HZ                 4000000U /* Value of the external crystal or oscillator clock frequency in Hz */
    #define CPU_XTAL32k_CLK_HZ              32768U   /* Value of the external 32k crystal or oscillator clock frequency in Hz */
    #define CPU_INT_SLOW_CLK_HZ             32768U   /* Value of the slow internal oscillator clock frequency in Hz  */
    #define CPU_INT_FAST_CLK_HZ             4000000U /* Value of the fast internal oscillator clock frequency in Hz  */
    #define DEFAULT_SYSTEM_CLOCK            41943040U /* Default System clock value */
#elif (CLOCK_SETUP == 1)
    #define CPU_XTAL_CLK_HZ                 8000000U /* Value of the external crystal or oscillator clock frequency in Hz */
    #define CPU_XTAL32k_CLK_HZ              32768U   /* Value of the external 32k crystal or oscillator clock frequency in Hz */
    #define CPU_INT_SLOW_CLK_HZ             32768U   /* Value of the slow internal oscillator clock frequency in Hz  */
    #define CPU_INT_FAST_CLK_HZ             4000000U /* Value of the fast internal oscillator clock frequency in Hz  */
    #define DEFAULT_SYSTEM_CLOCK            48000000U /* Default System clock value */
#elif (CLOCK_SETUP == 2)
    #define CPU_XTAL_CLK_HZ                 8000000U /* Value of the external crystal or oscillator clock frequency in Hz */
    #define CPU_XTAL32k_CLK_HZ              32768U   /* Value of the external 32k crystal or oscillator clock frequency in Hz */
    #define CPU_INT_SLOW_CLK_HZ             32768U   /* Value of the slow internal oscillator clock frequency in Hz  */
    #define CPU_INT_FAST_CLK_HZ             4000000U /* Value of the fast internal oscillator clock frequency in Hz  */
    #define DEFAULT_SYSTEM_CLOCK            8000000U /* Default System clock value */
#elif (CLOCK_SETUP == 3)
    #define CPU_XTAL_CLK_HZ                 50000000U /* Value of the external crystal or oscillator clock frequency in Hz */
    #define CPU_XTAL32k_CLK_HZ              32768U   /* Value of the external 32k crystal or oscillator clock frequency in Hz */
    #define CPU_INT_SLOW_CLK_HZ             32768U   /* Value of the slow internal oscillator clock frequency in Hz  */
    #define CPU_INT_FAST_CLK_HZ             4000000U /* Value of the fast internal oscillator clock frequency in Hz  */
    #define DEFAULT_SYSTEM_CLOCK            100000000U /* Default System clock value */
#elif (CLOCK_SETUP == 4)
    #define CPU_XTAL_CLK_HZ                 50000000U /* Value of the external crystal or oscillator clock frequency in Hz */
    #define CPU_XTAL32k_CLK_HZ              32768U   /* Value of the external 32k crystal or oscillator clock frequency in Hz */
    #define CPU_INT_SLOW_CLK_HZ             32768U   /* Value of the slow internal oscillator clock frequency in Hz  */
    #define CPU_INT_FAST_CLK_HZ             4000000U /* Value of the fast internal oscillator clock frequency in Hz  */
    #define DEFAULT_SYSTEM_CLOCK            50000000U /* Default System clock value */
#endif /* (CLOCK_SETUP == 4) */


/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */

uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/* ----------------------------------------------------------------------------
   -- SystemInit()
   ---------------------------------------------------------------------------- */

void SystemInit (void) {
#if (DISABLE_WDOG)
  /* Disable the WDOG module */
  /* WDOG_UNLOCK: WDOGUNLOCK=0xC520 */
  WDOG->UNLOCK = (uint16_t)0xC520U;     /* Key 1 */
  /* WDOG_UNLOCK : WDOGUNLOCK=0xD928 */
  WDOG->UNLOCK  = (uint16_t)0xD928U;    /* Key 2 */
  /* WDOG_STCTRLH: ??=0,DISTESTWDOG=0,BYTESEL=0,TESTSEL=0,TESTWDOG=0,??=0,STNDBYEN=1,WAITEN=1,STOPEN=1,DBGEN=0,ALLOWUPDATE=1,WINEN=0,IRQRSTEN=0,CLKSRC=1,WDOGEN=0 */
  WDOG->STCTRLH = (uint16_t)0x01D2U;
#endif /* (DISABLE_WDOG) */

  /* System clock initialization */
#if (CLOCK_SETUP == 0)
  /* SIM->CLKDIV1: OUTDIV1=0,OUTDIV2=0,OUTDIV3=1,OUTDIV4=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM->CLKDIV1 = (uint32_t)0x00110000U; /* Update system prescalers */
  /* Switch to FEI Mode */
  /* MCG->C1: CLKS=0,FRDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  MCG->C1 = (uint8_t)0x06U;
  /* MCG->C2: ??=0,??=0,RANGE=0,HGO=0,EREFS=0,LP=0,IRCS=0 */
  MCG->C2 = (uint8_t)0x00U;
  /* MCG_C4: DMX32=0,DRST_DRS=1 */
  MCG->C4 = (uint8_t)((MCG->C4 & (uint8_t)~(uint8_t)0xC0U) | (uint8_t)0x20U);
  /* MCG->C5: ??=0,PLLCLKEN=0,PLLSTEN=0,PRDIV=0 */
  MCG->C5 = (uint8_t)0x00U;
  /* MCG->C6: LOLIE=0,PLLS=0,CME=0,VDIV=0 */
  MCG->C6 = (uint8_t)0x00U;
  while((MCG->S & MCG_S_IREFST_MASK) == 0U) { /* Check that the source of the FLL reference clock is the internal reference clock. */
  }
  while((MCG->S & 0x0Cu) != 0x00U) {    /* Wait until output of the FLL is selected */
  }
#elif (CLOCK_SETUP == 1)
  /* SIM->CLKDIV1: OUTDIV1=0,OUTDIV2=0,OUTDIV3=1,OUTDIV4=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM->CLKDIV1 = (uint32_t)0x00110000U; /* Update system prescalers */
  /* Switch to FBE Mode */
  /* OSC->CR: ERCLKEN=0,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  OSC->CR = (uint8_t)0x00U;
  /* SIM->SOPT2: MCGCLKSEL=0 */
  SIM->SOPT2 &= (uint8_t)~(uint8_t)0x01U;
  /* MCG->C2: ??=0,??=0,RANGE=2,HGO=0,EREFS=1,LP=0,IRCS=0 */
  MCG->C2 = (uint8_t)0x24U;
  /* MCG->C1: CLKS=2,FRDIV=3,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  MCG->C1 = (uint8_t)0x9AU;
  /* MCG->C4: DMX32=0,DRST_DRS=0 */
  MCG->C4 &= (uint8_t)~(uint8_t)0xE0U;
  /* MCG->C5: ??=0,PLLCLKEN=0,PLLSTEN=0,PRDIV=3 */
  MCG->C5 = (uint8_t)0x03U;
  /* MCG->C6: LOLIE=0,PLLS=0,CME=0,VDIV=0 */
  MCG->C6 = (uint8_t)0x00U;
  while((MCG->S & MCG_S_OSCINIT_MASK) == 0U) { /* Check that the oscillator is running */
  }
  while((MCG->S & MCG_S_IREFST_MASK) != 0U) { /* Check that the source of the FLL reference clock is the external reference clock. */
  }
  while((MCG->S & 0x0CU) != 0x08U) {    /* Wait until external reference clock is selected as MCG output */
  }
  /* Switch to PBE Mode */
  /* MCG_C5: ??=0,PLLCLKEN=0,PLLSTEN=0,PRDIV=3 */
  MCG->C5 = (uint8_t)0x03U;
  /* MCG->C6: LOLIE=0,PLLS=1,CME=0,VDIV=0 */
  MCG->C6 = (uint8_t)0x40U;
  while((MCG->S & MCG_S_PLLST_MASK) == 0U) { /* Wait until the source of the PLLS clock has switched to the PLL */
  }
  while((MCG->S & MCG_S_LOCK_MASK) == 0U) { /* Wait until locked */
  }
  /* Switch to PEE Mode */
  /* MCG->C1: CLKS=0,FRDIV=3,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  MCG->C1 = (uint8_t)0x1AU;
  while((MCG->S & 0x0CU) != 0x0CU) {    /* Wait until output of the PLL is selected */
  }
  while((MCG->S & MCG_S_LOCK_MASK) == 0U) { /* Wait until locked */
  }
#elif (CLOCK_SETUP == 2)
  /* SIM_CLKDIV1: OUTDIV1=0,OUTDIV2=0,OUTDIV3=1,OUTDIV4=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM->CLKDIV1 = (uint32_t)0x00110000U; /* Update system prescalers */
  /* Switch to FBE Mode */
  /* OSC->CR: ERCLKEN=0,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  OSC->CR = (uint8_t)0x00U;
  /* SIM->SOPT2: MCGCLKSEL=0 */
  SIM->SOPT2 &= (uint8_t)~(uint8_t)0x01U;
  /* MCG->C2: ??=0,??=0,RANGE=2,HGO=0,EREFS=1,LP=0,IRCS=0 */
  MCG->C2 = (uint8_t)0x24U;
  /* MCG->C1: CLKS=2,FRDIV=3,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  MCG->C1 = (uint8_t)0x9AU;
  /* MCG->C4: DMX32=0,DRST_DRS=0 */
  MCG->C4 &= (uint8_t)~(uint8_t)0xE0U;
  /* MCG->C5: ??=0,PLLCLKEN=0,PLLSTEN=0,PRDIV=0 */
  MCG->C5 = (uint8_t)0x00U;
  /* MCG->C6: LOLIE=0,PLLS=0,CME=0,VDIV=0 */
  MCG->C6 = (uint8_t)0x00U;
  while((MCG->S & MCG_S_OSCINIT_MASK) == 0U) { /* Check that the oscillator is running */
  }
  while((MCG->S & MCG_S_IREFST_MASK) != 0U) { /* Check that the source of the FLL reference clock is the external reference clock. */
  }
  while((MCG->S & 0x0CU) != 0x08U) {    /* Wait until external reference clock is selected as MCG output */
  }
  /* Switch to BLPE Mode */
  /* MCG->C2: ??=0,??=0,RANGE=2,HGO=0,EREFS=1,LP=0,IRCS=0 */
  MCG->C2 = (uint8_t)0x24U;
#elif (CLOCK_SETUP == 3)
  /* SIM->CLKDIV1: OUTDIV1=0,OUTDIV2=0,OUTDIV3=1,OUTDIV4=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM->CLKDIV1 = (uint32_t)0x01330000U; /* Update system prescalers */
  /* Switch to FBE Mode */
  /* OSC->CR: ERCLKEN=1,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  OSC->CR = (uint8_t)0x80U;
  /* SIM->SOPT2: MCGCLKSEL=0 */
  SIM->SOPT2 &= (uint8_t)~(uint8_t)0x01u;
  /* MCG->C2: ??=0,??=0,RANGE=2,HGO=0,EREFS=0,LP=0,IRCS=0 */
  MCG->C2 = (uint8_t)0x20U;
  /* MCG->C1: CLKS=2,FRDIV=5,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  MCG->C1 = (uint8_t)0xAAu;
  /* MCG->C4: DMX32=0,DRST_DRS=0 */
  MCG->C4 &= (uint8_t)~(uint8_t)0xE0U;
  /* MCG->C5: ??=0,PLLCLKEN=0,PLLSTEN=0,PRDIV=0x0F */
  MCG->C5 = (uint8_t)0x0Fu;
  /* MCG->C6: LOLIE=0,PLLS=0,CME=0,VDIV=0 */
  MCG->C6 = (uint8_t)0x00U;
  while((MCG->S & MCG_S_OSCINIT_MASK) == 0U) { /* Check that the oscillator is running */
  }
  while((MCG->S & MCG_S_IREFST_MASK) != 0U) { /* Check that the source of the FLL reference clock is the external reference clock. */
  }
  while((MCG->S & 0x0CU) != 0x08U) {    /* Wait until external reference clock is selected as MCG output */
  }
  /* Switch to PBE Mode */
  /* MCG->C1: CLKS=2,FRDIV=5,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  MCG->C1 = (uint8_t)0xAAU;
  /* MCG->C6: LOLIE=0,PLLS=1,CME=0,VDIV=8 */
  MCG->C6 = (uint8_t)0x48u;
  while((MCG->S & MCG_S_PLLST_MASK) == 0U) { /* Wait until the source of the PLLS clock has switched to the PLL */
  }
  while((MCG->S & MCG_S_LOCK_MASK) == 0U) { /* Wait until locked */
  }
  /* Switch to PEE Mode */
  /* MCG_C1: CLKS=0,FRDIV=5,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  MCG->C1 = (uint8_t)0x2AU;
  while((MCG->S & 0x0CU) != 0x0CU) {    /* Wait until output of the PLL is selected */
  }
  while((MCG->S & MCG_S_LOCK_MASK) == 0U) { /* Wait until locked */
  }
#elif (CLOCK_SETUP == 4)
  /* SIM_CLKDIV1: OUTDIV1=0,OUTDIV2=0,OUTDIV3=1,OUTDIV4=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM->CLKDIV1 = (uint32_t)0x00110000U; /* Update system prescalers */
  /* Switch to FBE Mode */
  /* OSC->CR: ERCLKEN=0,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  OSC->CR = (uint8_t)0x00U;
  /* SIM->SOPT2: MCGCLKSEL=0 */
  SIM->SOPT2 &= (uint8_t)~(uint8_t)0x01U;
  /* MCG->C2: ??=0,??=0,RANGE=2,HGO=0,EREFS=0,LP=0,IRCS=0 */
  MCG->C2 = (uint8_t)0x20U;
  /* MCG->C1: CLKS=2,FRDIV=5,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  MCG->C1 = (uint8_t)0xAAU;
  /* MCG->C4: DMX32=0,DRST_DRS=0 */
  MCG->C4 &= (uint8_t)~(uint8_t)0xE0U;
  /* MCG->C5: ??=0,PLLCLKEN=0,PLLSTEN=0,PRDIV=0 */
  MCG->C5 = (uint8_t)0x00U;
  /* MCG->C6: LOLIE=0,PLLS=0,CME=0,VDIV=0 */
  MCG->C6 = (uint8_t)0x00U;
  while((MCG->S & MCG_S_IREFST_MASK) != 0U) { /* Check that the source of the FLL reference clock is the external reference clock. */
  }
  while((MCG->S & 0x0CU) != 0x08U) {    /* Wait until external reference clock is selected as MCG output */
  }
  /* Switch to BLPE Mode */
  /* MCG->C2: ??=0,??=0,RANGE=2,HGO=0,EREFS=0,LP=0,IRCS=0 */
  MCG->C2 = (uint8_t)0x22U;
#endif /* (CLOCK_SETUP == 4) */
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */

void SystemCoreClockUpdate (void) {
  uint32_t MCGOUTClock;                                                        /* Variable to store output clock frequency of the MCG module */
  uint8_t Divider;

  if ((MCG->C1 & MCG_C1_CLKS_MASK) == 0x00U) {
    /* Output of FLL or PLL is selected */
    if ((MCG->C6 & MCG_C6_PLLS_MASK) == 0x00U) {
      /* FLL is selected */
      if ((MCG->C1 & MCG_C1_IREFS_MASK) == 0x00U) {
        /* External reference clock is selected */
        if ((SIM->SOPT2 & SIM_SOPT2_MCGCLKSEL_MASK) == 0x00U) {
          MCGOUTClock = CPU_XTAL_CLK_HZ;                                       /* System oscillator drives MCG clock */
        } else { /* (!((SIM->SOPT2 & SIM_SOPT2_MCGCLKSEL_MASK) == 0x0U)) */
          MCGOUTClock = CPU_XTAL32k_CLK_HZ;                                    /* RTC 32 kHz oscillator drives MCG clock */
        } /* (!((SIM->SOPT2 & SIM_SOPT2_MCGCLKSEL_MASK) == 0x0U)) */
        Divider = (uint8_t)(1u << ((MCG->C1 & MCG_C1_FRDIV_MASK) >> MCG_C1_FRDIV_SHIFT));
        MCGOUTClock = (MCGOUTClock / Divider);  /* Calculate the divided FLL reference clock */
        if ((MCG->C2 & MCG_C2_RANGE_MASK) != 0x0U) {
          MCGOUTClock /= 32U;                                                  /* If high range is enabled, additional 32 divider is active */
        } /* ((MCG->C2 & MCG_C2_RANGE_MASK) != 0x0U) */
      } else { /* (!((MCG->C1 & MCG_C1_IREFS_MASK) == 0x0U)) */
        MCGOUTClock = CPU_INT_SLOW_CLK_HZ;                                     /* The slow internal reference clock is selected */
      } /* (!((MCG->C1 & MCG_C1_IREFS_MASK) == 0x0U)) */
      /* Select correct multiplier to calculate the MCG output clock  */
      switch (MCG->C4 & (MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS_MASK)) {
        case 0x0U:
          MCGOUTClock *= 640U;
          break;
        case 0x20U:
          MCGOUTClock *= 1280U;
          break;
        case 0x40U:
          MCGOUTClock *= 1920U;
          break;
        case 0x60U:
          MCGOUTClock *= 2560U;
          break;
        case 0x80U:
          MCGOUTClock *= 732U;
          break;
        case 0xA0U:
          MCGOUTClock *= 1464U;
          break;
        case 0xC0U:
          MCGOUTClock *= 2197U;
          break;
        case 0xE0U:
          MCGOUTClock *= 2929U;
          break;
        default:
          break;
      }
    } else { /* (!((MCG->C6 & MCG_C6_PLLS_MASK) == 0x00U)) */
      /* PLL is selected */
      Divider = (1U + (MCG->C5 & MCG_C5_PRDIV_MASK));
      MCGOUTClock = (uint32_t)(CPU_XTAL_CLK_HZ / Divider);    /* Calculate the PLL reference clock */
      Divider = ((MCG->C6 & MCG_C6_VDIV_MASK) + 24U);
      MCGOUTClock *= Divider;                       /* Calculate the MCG output clock */
    } /* (!((MCG->C6 & MCG_C6_PLLS_MASK) == 0x0U)) */
  } else if ((MCG->C1 & MCG_C1_CLKS_MASK) == 0x40U) {
    /* Internal reference clock is selected */
    if ((MCG->C2 & MCG_C2_IRCS_MASK) == 0x00U) {
      MCGOUTClock = CPU_INT_SLOW_CLK_HZ;                                       /* Slow internal reference clock selected */
    } else { /* (!((MCG->C2 & MCG_C2_IRCS_MASK) == 0x0U)) */
      MCGOUTClock = CPU_INT_FAST_CLK_HZ / 2;                                   /* Fast internal reference clock selected */
    } /* (!((MCG->C2 & MCG_C2_IRCS_MASK) == 0x0U)) */
  } else if ((MCG->C1 & MCG_C1_CLKS_MASK) == 0x80U) {
    /* External reference clock is selected */
    if ((SIM->SOPT2 & SIM_SOPT2_MCGCLKSEL_MASK) == 0x0U) {
      MCGOUTClock = CPU_XTAL_CLK_HZ;                                           /* System oscillator drives MCG clock */
    } else { /* (!((SIM->SOPT2 & SIM_SOPT2_MCGCLKSEL_MASK) == 0x0U)) */
      MCGOUTClock = CPU_XTAL32k_CLK_HZ;                                        /* RTC 32 kHz oscillator drives MCG clock */
    } /* (!((SIM->SOPT2 & SIM_SOPT2_MCGCLKSEL_MASK) == 0x0U)) */
  } else { /* (!((MCG->C1 & MCG_C1_CLKS_MASK) == 0x80U)) */
    /* Reserved value */
    return;
  } /* (!((MCG->C1 & MCG_C1_CLKS_MASK) == 0x80U)) */
  SystemCoreClock = (MCGOUTClock / (0x01U + ((SIM->CLKDIV1 & SIM_CLKDIV1_OUTDIV1_MASK) >> SIM_CLKDIV1_OUTDIV1_SHIFT)));
}
