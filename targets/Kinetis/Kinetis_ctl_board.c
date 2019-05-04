// Copyright (c) 2013-2014 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <ctl_api.h>
#include <Kinetis.h>

#if defined(MK10D5)
  #include "CMSIS/system_MK10D5.c"
#elif defined(MK10D7)
  #include "CMSIS/system_MK10D7.c"
#elif defined(MK10D10)
  #include "CMSIS/system_MK10D10.c"  
#elif defined(MK10DZ10)
  #include "CMSIS/system_MK10DZ10.c"
#elif defined(MK10F12)
  #include "CMSIS/system_MK10F12.c"
#elif defined(MK11D5)
  #include "CMSIS/system_MK11D5.c"
#elif defined(MK12D5)
  #include "CMSIS/system_MK12D5.c"
#elif defined(MK20D5)
  #include "CMSIS/system_MK20D5.c"
#elif defined(MK20D7)
  #include "CMSIS/system_MK20D7.c"
#elif defined(MK20D10)
  #include "CMSIS/system_MK20D10.c"  
#elif defined(MK20DZ10)
  #include "CMSIS/system_MK20DZ10.c"
#elif defined(MK20F12)
  #include "CMSIS/system_MK20F12.c"
#elif defined(MK21D5)
  #include "CMSIS/system_MK21D5.c"
#elif defined(MK21F12)
  #include "CMSIS/system_MK21F12.c"
#elif defined(MK22D5)
  #include "CMSIS/system_MK22D5.c"
#elif defined(MK22F12)
  #include "CMSIS/system_MK22F12.c"
#elif defined(MK24F12)
  #include "CMSIS/system_MK24F12.c"
#elif defined(MK30D7)
  #include "CMSIS/system_MK30D7.c"
#elif defined(MK30D10)
  #include "CMSIS/system_MK30D10.c"
#elif defined(MK30DZ10)
  #include "CMSIS/system_MK30DZ10.c"
#elif defined(MK40D7)
  #include "CMSIS/system_MK40D7.c"
#elif defined(MK40D10)
  #include "CMSIS/system_MK40D10.c"
#elif defined(MK40DZ10)
  #include "CMSIS/system_MK40DZ10.c"
#elif defined(MK50D7)
  #include "CMSIS/system_MK50D7.c"
#elif defined(MK50D10)
  #include "CMSIS/system_MK50D10.c"
#elif defined(MK50DZ10)
  #include "CMSIS/system_MK50DZ10.c"
#elif defined(MK51D7)
  #include "CMSIS/system_MK51D7.c"
#elif defined(MK51D10)
  #include "CMSIS/system_MK51D10.c"
#elif defined(MK51DZ10)
  #include "CMSIS/system_MK51DZ10.c"
#elif defined(MK52D10)
  #include "CMSIS/system_MK52D10.c"
#elif defined(MK52DZ10)
  #include "CMSIS/system_MK52DZ10.c"
#elif defined(MK53D10)
  #include "CMSIS/system_MK53D10.c"
#elif defined(MK53DZ10)
  #include "CMSIS/system_MK53DZ10.c"
#elif defined(MK60D10)
  #include "CMSIS/system_MK60D10.c"
#elif defined(MK60DZ10)
  #include "CMSIS/system_MK60DZ10.c"
#elif defined(MK60F12)
  #include "CMSIS/system_MK60F12.c"
#elif defined(MK60F15)
  #include "CMSIS/system_MK60F15.c"
#elif defined(MK61F12)
  #include "CMSIS/system_MK61F12.c"
#elif defined(MK61F15)
  #include "CMSIS/system_MK61F15.c"
#elif defined(MK63F12)
  #include "CMSIS/system_MK63F12.c"
#elif defined(MK64F12)
  #include "CMSIS/system_MK64F12.c"
#elif defined(MK70F12)
  #include "CMSIS/system_MK70F12.c"
#elif defined(MK70F15)
  #include "CMSIS/system_MK70F15.c"
#elif defined(MKE02Z2)
  #include "CMSIS/system_MKE02Z2.c"
#elif defined(MKL02Z4)
  #include "CMSIS/system_MKL02Z4.c"
#elif defined(MKL04Z4)
  #include "CMSIS/system_MKL04Z4.c"
#elif defined(MKL05Z4)
  #include "CMSIS/system_MKL05Z4.c"
#elif defined(MKL14Z4)
  #include "CMSIS/system_MKL14Z4.c"
#elif defined(MKL15Z4)
  #include "CMSIS/system_MKL15Z4.c"
#elif defined(MKL16Z4)
  #include "CMSIS/system_MKL16Z4.c"
#elif defined(MKL24Z4)
  #include "CMSIS/system_MKL24Z4.c"
#elif defined(MKL25Z4)
  #include "CMSIS/system_MKL25Z4.c"
#elif defined(MKL26Z4)
  #include "CMSIS/system_MKL26Z4.c"
#elif defined(MKL34Z4)
  #include "CMSIS/system_MKL34Z4.c"
#elif defined(MKL36Z4)
  #include "CMSIS/system_MKL36Z4.c"
#elif defined(MKL46Z4)
  #include "CMSIS/system_MKL46Z4.c"
#elif defined(MKM13Z5)
  #include "CMSIS/system_MKM13Z5.c"
#elif defined(MKM14Z5)
  #include "CMSIS/system_MKM14Z5.c"
#elif defined(MKM32Z5)
  #include "CMSIS/system_MKM32Z5.c"
#elif defined(MKM33Z5)
  #include "CMSIS/system_MKM33Z5.c"
#elif defined(MKM34Z5)
  #include "CMSIS/system_MKM34Z5.c"
#elif defined(MKM38Z5)
  #include "CMSIS/system_MKM38Z5.c"
#elif defined(MKV10Z7)
  #include "CMSIS/system_MKV10Z7.c"
#elif defined(MKW21D5)
  #include "CMSIS/system_MKW21D5.c"
#elif defined(MKW21D5)
  #include "CMSIS/system_MKW21D5.c"
#elif defined(MKW22D5)
  #include "CMSIS/system_MKW22D5.c"
#elif defined(MKW24D5)
  #include "CMSIS/system_MKW24D5.c"
#else
  #error no SystemInit
#endif

void
delay(int count)
{
  volatile int i=0;
  while (i++<count);
}

void
ctl_board_init(void)
{ 
}

void 
ctl_board_set_leds(unsigned on)
{ 
}

static CTL_ISR_FN_t userButtonISR;

void 
ctl_board_on_button_pressed(CTL_ISR_FN_t isr)
{
  userButtonISR = isr;  
}
