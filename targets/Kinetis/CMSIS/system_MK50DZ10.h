/*
** ###################################################################
**     Processors:          MK50DN512ZCLL10
**                          MK50DX256ZCLL10
**                          MK50DN512ZCLQ10
**                          MK50DN512ZCMC10
**                          MK50DX256ZCMC10
**                          MK50DN512ZCMD10
**                          MK50DX256ZCLK10
**                          MK50DX256ZCMB10
**
**     Compilers:           ARM Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    K50P144M100SF2RM Rev. 5, 8 May 2011
**     Version:             rev. 1.2, 2011-09-08
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright: 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2011-06-10)
**         Initial version
**     - rev. 1.1 (2011-06-29)
**         Order of declarations changed.
**     - rev. 1.2 (2011-09-08)
**         Cortex_Core_Configuration extended with additional parameters.
**         Gap between end of interrupt vector table and flash configuration field filled by default ISR.
**
** ###################################################################
*/

/**
 * @file MK50DZ10
 * @version 1.2
 * @date 2011-09-08
 * @brief Device specific configuration file for MK50DZ10 (header file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#ifndef SYSTEM_MK50DZ10_H_
#define SYSTEM_MK50DZ10_H_                       /**< Symbol preventing repeated inclusion */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

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

#endif  /* #if !defined(SYSTEM_MK50DZ10_H_) */
