/*
** ###################################################################
**     Processors:          MWPR1516CAL
**                          MWPR1516CFM
**
**     Compilers:           Keil ARM C/C++ Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          GNU C Compiler - CodeSourcery Sourcery G++
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    MWPR1516RM, Rev. 2 Draft A, Sep 2014
**     Version:             rev. 1.5, 2014-12-12
**     Build:               b141212
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright (c) 2014 Freescale Semiconductor, Inc.
**     All rights reserved.
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2014-04-23)
**         Initial version.
**     - rev. 1.1 (2014-07-07)
**         ADC - Bitfield AUT_RSTA has been added into register CTL1.
**         CNC - Register ANACFG has been renamed to ANACFG1.
**         FSKDT - Register OTRGTH has been renamed to OPCTH.
**         FSKDT - Bitfield OTRGIE in register CR has been renamed to OPIE.
**         FSKDT - Bitfield OTRGF in register SR has been renamed to OPF.
**         FTM - Register EXTTRIG has been added.
**         LDO - Bitfield INCLPE in register CR has been renamed to BASHDN.
**     - rev. 1.2 (2014-08-01)
**         PMC - Added peripheral.
**     - rev. 1.3 (2014-08-08)
**         PMC - BITFIELD 5VT has been renamed to T5V.
**     - rev. 1.4 (2014-10-01)
**         FTM1 - Base address has been changed from 0x4003A000 to 0x40039000.
**         Other peripheries - little changes like after reset values and so on.
**     - rev. 1.5 (2014-12-12)
**         LDO - LDO_CTRM[15:9] has been changed to reserved.
**         WDOG - Interrupt name has been synchronized.
**
** ###################################################################
*/

/*!
 * @file MWPR1516
 * @version 1.5
 * @date 2014-12-12
 * @brief Device specific configuration file for MWPR1516 (header file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#ifndef SYSTEM_MWPR1516_H_
#define SYSTEM_MWPR1516_H_                       /**< Symbol preventing repeated inclusion */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


#define DISABLE_WDOG    1

#ifndef CLOCK_SETUP
#define CLOCK_SETUP     0
#endif
/* Predefined clock setups
   0 ... Internal Clock Source (ICS) in FLL Engaged Internal (FEI) mode
         Default  part configuration.
         Reference clock source for ICS module is the slow internal clock source 32.768kHz
         Core clock = 20.97MHz, BusClock = 20.97MHz
   1 ... Internal Clock Source (ICS) in FLL Engaged External (FEE) mode
         Maximum achievable clock frequency configuration.
         Reference clock source for ICS module is an external 8MHz crystal
         Core clock = 20MHz, BusClock = 20MHz
   2 ... Internal Clock Source (ICS) in Bypassed Low Power Internal (FBILP) mode
         Core clock/Bus clock derived directly from an  internal clock 32.769kHz with no multiplication
         The clock settings is ready for Very Low Power Run mode.
         Core clock = 32.769kHz, BusClock = 32.769kHz
   3 ... Internal Clock Source (ICS) in Bypassed Low Power External (BLPE) mode
         Core clock/Bus clock derived directly from the external 8MHz crystal
         The clock settings is ready for Very Low Power Run mode.
         Core clock = 8MHz, BusClock = 8MHz
*/

/*----------------------------------------------------------------------------
  Define clock source values
 *----------------------------------------------------------------------------*/
#if (CLOCK_SETUP == 0)
    #define CPU_XTAL_CLK_HZ                 8000000u /* Value of the external crystal or oscillator clock frequency in Hz */
    #define CPU_INT_CLK_HZ                  32768u   /* Value of the internal oscillator clock frequency in Hz  */
    #define DEFAULT_SYSTEM_CLOCK            20971520u /* Default System clock value */
#elif (CLOCK_SETUP == 1)
    #define CPU_XTAL_CLK_HZ                 8000000u /* Value of the external crystal or oscillator clock frequency in Hz */
    #define CPU_INT_CLK_HZ                  32768u   /* Value of the internal oscillator clock frequency in Hz  */
    #define DEFAULT_SYSTEM_CLOCK            20000000u /* Default System clock value */
#elif (CLOCK_SETUP == 2)
    #define CPU_XTAL_CLK_HZ                 8000000u /* Value of the external crystal or oscillator clock frequency in Hz */
    #define CPU_INT_CLK_HZ                  32768u   /* Value of the internal oscillator clock frequency in Hz  */
    #define DEFAULT_SYSTEM_CLOCK            32768u   /* Default System clock value */
#elif (CLOCK_SETUP == 3)
    #define CPU_XTAL_CLK_HZ                 8000000u /* Value of the external crystal or oscillator clock frequency in Hz */
    #define CPU_INT_CLK_HZ                  32768u   /* Value of the internal oscillator clock frequency in Hz  */
    #define DEFAULT_SYSTEM_CLOCK            8000000u /* Default System clock value */
#else
  #error The selected clock setup is not supported.
#endif /* (CLOCK_SETUP == 3) */


/**
 * @brief System clock frequency (core clock)
 *
 * The system clock frequency supplied to the SysTick timer and the processor
 * core clock. This variable can be used by the user application to setup the
 * SysTick timer or configure other parameters. It may also be used by debugger to
 * query the frequency of the debug timer or configure the trace clock speed
 * SystemCoreClock is initialized with a correct predefined value.
 */
extern uint32_t SystemCoreClock;

/**
 * @brief Setup the microcontroller system.
 *
 * Typically this function configures the oscillator (PLL) that is part of the
 * microcontroller device. For systems with variable clock speed it also updates
 * the variable SystemCoreClock. SystemInit is called from startup_device file.
 */
void SystemInit (void);

/**
 * @brief Updates the SystemCoreClock variable.
 *
 * It must be called whenever the core clock is changed during program
 * execution. SystemCoreClockUpdate() evaluates the clock register settings and calculates
 * the current core clock.
 */
void SystemCoreClockUpdate (void);

#ifdef __cplusplus
}
#endif

#endif  /* #if !defined(SYSTEM_MWPR1516_H_) */
