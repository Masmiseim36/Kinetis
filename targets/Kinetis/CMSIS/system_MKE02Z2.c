/*
** ###################################################################
**     Compilers:           ARM Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    MKE02Z64M20SF0RM, Rev.2.1, Apr-23 2013
**     Version:             rev. 1.2, 2013-05-07
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
**     - rev. 1.0 (2013-02-06)
**         Initial version.
**     - rev. 1.1 (2013-04-05)
**         Changed start of doxygen comment.
**     - rev. 1.2 (2013-05-07)
**         Update according to reference manual rev. 2.1.
**
** ###################################################################
*/

/*!
 * @file MKE02Z2
 * @version 1.2
 * @date 2013-05-07
 * @brief Device specific configuration file for MKE02Z2 (implementation file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#include <stdint.h>
#include "MKE02Z2.h"

  #define DEFAULT_SYSTEM_CLOCK            20971520u /* Default System clock value */


/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */

uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/* ----------------------------------------------------------------------------
   -- SystemInit()
   ---------------------------------------------------------------------------- */

void SystemInit (void) {
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */

void SystemCoreClockUpdate (void) {
}
