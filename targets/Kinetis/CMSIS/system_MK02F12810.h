/*
** ###################################################################
**     Processors:          MK02FN128VFM10
**                          MK02FN64VFM10
**                          MK02FN128VLF10
**                          MK02FN64VLF10
**                          MK02FN128VLH10
**                          MK02FN64VLH10
**
**     Compilers:           ARM Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          GNU C Compiler - CodeSourcery Sourcery G++
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    K02P64M100SFARM, Rev. 0, February 14, 2014
**     Version:             rev. 0.1, 2014-02-24
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright: 2014 Freescale, Inc. All Rights Reserved.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 0.1 (2014-02-24)
**         Initial version
**
** ###################################################################
*/

/*!
 * @file MK02F12810
 * @version 0.1
 * @date 2014-02-24
 * @brief Device specific configuration file for MK02F12810 (header file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#ifndef SYSTEM_MK02F12810_H_
#define SYSTEM_MK02F12810_H_                     /**< Symbol preventing repeated inclusion */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


#define DISABLE_WDOG    1

#ifndef CLOCK_SETUP
  #define CLOCK_SETUP     0
#endif

/* Predefined clock setups
   0 ... Default  part configuration
         Multipurpose Clock Generator (MCG) in FEI mode.
         Reference clock source for MCG module: Slow internal reference clock
         Core clock = 20.97152MHz
         Bus clock  = 20.97152MHz
   1 ... Maximum achievable clock frequency configuration
         Multipurpose Clock Generator (MCG) in FEE mode.
         Reference clock source for MCG module: System oscillator 0 reference clock
         Core clock = 80MHz
         Bus clock  = 40MHz
   2 ... Internally clocked, ready for Very Low Power Run mode.
         Multipurpose Clock Generator (MCG) in BLPI mode.
         Reference clock source for MCG module: Fast internal reference clock
         Core clock = 4MHz
         Bus clock  = 4MHz
   3 ... Externally clocked, ready for Very Low Power Run mode.
         Multipurpose Clock Generator (MCG) in BLPE mode.
         Reference clock source for MCG module: System oscillator 0 reference clock
         Core clock = 4MHz
         Bus clock  = 4MHz
 */

/* Define clock source values */

#define CPU_XTAL_CLK_HZ                 8000000u   /* Value of the external crystal or oscillator clock frequency in Hz */
#define CPU_INT_SLOW_CLK_HZ             32768u   /* Value of the slow internal oscillator clock frequency in Hz  */
#define CPU_INT_FAST_CLK_HZ             4000000u /* Value of the fast internal oscillator clock frequency in Hz  */
#define CPU_INT_IRC_CLK_HZ              48000000u /* Value of the 48M internal oscillator clock frequency in Hz  */

#if (CLOCK_SETUP == 0)
    #define DEFAULT_SYSTEM_CLOCK            20971520u /* Default System clock value */
#elif (CLOCK_SETUP == 1)
  #define DEFAULT_SYSTEM_CLOCK            80000000u /* Default System clock value */
#elif (CLOCK_SETUP == 2)
    #define DEFAULT_SYSTEM_CLOCK            4000000u /* Default System clock value */
#elif (CLOCK_SETUP == 3)
  #define DEFAULT_SYSTEM_CLOCK            4000000u /* Default System clock value */
#endif

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

#endif  /* #if !defined(SYSTEM_MK02F12810_H_) */
