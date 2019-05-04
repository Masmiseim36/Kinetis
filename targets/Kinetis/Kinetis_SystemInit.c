/*****************************************************************************
 * Copyright (c) 2010, 2011 Rowley Associates Limited.                       *
 *                                                                           *
 * This file may be distributed under the terms of the License Agreement     *
 * provided with this software.                                              *
 *                                                                           *
 * THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE   *
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. *
 *****************************************************************************/
#include "Kinetis.h"

#if __TARGET_PROCESSOR==MK10N512VMD100
#include "CMSIS/system_MK10N512MD100.c"
#elif __TARGET_PROCESSOR==MK10X256VMD100
#include "CMSIS/system_MK10X256MD100.c"
#elif __TARGET_PROCESSOR==MK20N512VMD100
#include "CMSIS/system_MK20N512MD100.c"
#elif __TARGET_PROCESSOR==MK20X256VMD100
#include "CMSIS/system_MK20X256MD100.c"
#elif __TARGET_PROCESSOR==MK30N512VMD100
#include "CMSIS/system_MK30N512MD100.c"
#elif __TARGET_PROCESSOR==MK30X256VMD100
#include "CMSIS/system_MK30X256MD100.c"
#elif __TARGET_PROCESSOR==MK40N512VMD100
#include "CMSIS/system_MK40N512MD100.c"
#elif __TARGET_PROCESSOR==MK40X256VMD100
#include "CMSIS/system_MK40X256MD100.c"
#elif __TARGET_PROCESSOR==MK60N512VMD100
#include "CMSIS/system_MK60N512MD100.c"
#elif __TARGET_PROCESSOR==MK60X256VMD100
#include "CMSIS/system_MK60X256MD100.c"
#else
#error __TARGET_PROCESSOR
#endif

void set_sys_dividers(unsigned outdiv1, unsigned outdiv2, unsigned outdiv3, unsigned outdiv4)__attribute__((section(".fast")));

void set_sys_dividers(unsigned outdiv1, unsigned outdiv2, unsigned outdiv3, unsigned outdiv4)
{
 /*
  * This routine must be placed in RAM. It is a workaround for errata e2448.
  * Flash prefetch must be disabled when the flash clock divider is changed.
  * This cannot be performed while executing out of flash.
  * There must be a short delay after the clock dividers are changed before prefetch
  * can be re-enabled.
  */
  unsigned temp_reg;
  unsigned i;
  
  temp_reg = FMC->PFAPR; // store present value of FMC_PFAPR
  
  // set M0PFD through M7PFD to 1 to disable prefetch
  FMC->PFAPR |= FMC_PFAPR_M7PFD_MASK | FMC_PFAPR_M6PFD_MASK | FMC_PFAPR_M5PFD_MASK
             | FMC_PFAPR_M4PFD_MASK | FMC_PFAPR_M3PFD_MASK | FMC_PFAPR_M2PFD_MASK
             | FMC_PFAPR_M1PFD_MASK | FMC_PFAPR_M0PFD_MASK;
  
  // set clock dividers to desired value  
  SIM->CLKDIV1 = SIM_CLKDIV1_OUTDIV1(outdiv1) | SIM_CLKDIV1_OUTDIV2(outdiv2) 
              | SIM_CLKDIV1_OUTDIV3(outdiv3) | SIM_CLKDIV1_OUTDIV4(outdiv4);

  // wait for dividers to change
  for (i = 0 ; i < outdiv4 ; i++)
  {}
  
  FMC->PFAPR = temp_reg; // re-store original value of FMC_PFAPR
  
  return;
} // set_sys_dividers
