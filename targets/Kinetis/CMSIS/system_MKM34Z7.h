/*
** ###################################################################
**     Processors:          MKM34Z256VLL7
**                          MKM34Z256VLQ7
**
**     Compilers:           Keil ARM C/C++ Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          MCUXpresso Compiler
**
**     Reference manual:    KM34P144M75SF0RM, Rev.1, Jan 2015
**     Version:             rev. 1.2, 2015-03-06
**     Build:               b170112
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright (c) 2016 Freescale Semiconductor, Inc.
**     Copyright 2016 - 2017 NXP
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
**     o Neither the name of the copyright holder nor the names of its
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
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2014-10-17)
**         Initial version.
**     - rev. 1.1 (2015-01-27)
**         Update according to reference manual rev. 1, RC.
**     - rev. 1.2 (2015-03-06)
**         Update according to reference manual rev. 1.
**
** ###################################################################
*/

/*!
 * @file MKM34Z7
 * @version 1.2
 * @date 2015-03-06
 * @brief Device specific configuration file for MKM34Z7 (header file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#ifndef _SYSTEM_MKM34Z7_H_
#define _SYSTEM_MKM34Z7_H_                       /**< Symbol preventing repeated inclusion */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


#ifndef DISABLE_WDOG
  #define DISABLE_WDOG                 1
#endif

/* Define clock source values */

#define CPU_XTAL_CLK_HZ                8000000u            /* Value of the external crystal or oscillator clock frequency in Hz */
#define CPU_XTAL32k_CLK_HZ             32768u              /* Value of the external 32k crystal or oscillator clock frequency in Hz */
#define CPU_INT_SLOW_CLK_HZ            32768u              /* Value of the slow internal oscillator clock frequency in Hz  */
#define CPU_INT_FAST_CLK_HZ            4000000u            /* Value of the fast internal oscillator clock frequency in Hz  */

/* Low power mode enable */
/* SMC_PMPROT: AVLP=1,AVLLS=1 */
#define SYSTEM_SMC_PMPROT_VALUE        0x22U               /* SMC_PMPROT */

#define DEFAULT_SYSTEM_CLOCK           2000000u            /* Default System clock value */


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

#endif  /* _SYSTEM_MKM34Z7_H_ */
