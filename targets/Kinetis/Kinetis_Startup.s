/*****************************************************************************
 * Copyright (c) 2010, 2011, 2012, 2013 Rowley Associates Limited.           *
 *                                                                           *
 * This file may be distributed under the terms of the License Agreement     *
 * provided with this software.                                              *
 *                                                                           *
 * THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE   *
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. *
 *****************************************************************************/

 /*****************************************************************************
 *                           Preprocessor Definitions
 *                           ------------------------
 *
 * STARTUP_FROM_RESET
 *
 *   If defined, the program will startup from power-on/reset. If not defined
 *   the program will just loop endlessly from power-on/reset.
 *
 *   This definition is not defined by default on this target because the
 *   debugger is unable to reset this target and maintain control of it over the
 *   JTAG interface. The advantage of doing this is that it allows the debugger
 *   to reset the CPU and run programs from a known reset CPU state on each run.
 *   It also acts as a safety net if you accidently download a program in FLASH
 *   that crashes and prevents the debugger from taking control over JTAG
 *   rendering the target unusable over JTAG. The obvious disadvantage of doing
 *   this is that your application will not startup without the debugger.
 *
 *   We advise that on this target you keep STARTUP_FROM_RESET undefined whilst
 *   you are developing and only define STARTUP_FROM_RESET when development is
 *   complete.
 *
 * __NO_SYSTEM_INIT
 *
 *   If defined, the SystemInit() function will NOT be called. By default SystemInit()
 *   is called after reset to enable the clocks and memories to be initialised 
 *   prior to any C startup initialisation.
 *
 * VECTORS_IN_RAM
 *
 *   If defined then the exception vectors are copied from Flash to RAM
 *
 * __FPU_PRESENT
 *
 *   If defined then access is enabled to the FPU
 */

.macro ISR_HANDLER name=
  .section .vectors, "ax"
  .word \name
  .section .init, "ax"
  .thumb_func
  .weak \name
\name:
1: b 1b /* endless loop */
.endm

.macro ISR_RESERVED
  .section .vectors, "ax"
  .word 0
.endm

  .syntax unified
  .global reset_handler

  .section .vectors, "ax"
  .code 16
  .global _vectors

_vectors:
  .word __stack_end__
#ifdef STARTUP_FROM_RESET
  .word reset_handler
#else
  .word reset_wait
#endif /* STARTUP_FROM_RESET */
ISR_HANDLER NMI_Handler
ISR_HANDLER HardFault_Handler
ISR_HANDLER MemManage_Handler 
ISR_HANDLER BusFault_Handler
ISR_HANDLER UsageFault_Handler
ISR_RESERVED
ISR_RESERVED
ISR_RESERVED
ISR_RESERVED
ISR_HANDLER SVC_Handler
ISR_HANDLER DebugMon_Handler
ISR_RESERVED
ISR_HANDLER PendSV_Handler
ISR_HANDLER SysTick_Handler 
#if defined(MK10D5)
  #include "MK10D5.vec"
#elif defined(MK10D7)
  #include "MK10D7.vec"
#elif defined(MK10D10)
  #include "MK10D10.vec"  
#elif defined(MK10DZ10)
  #include "MK10DZ10.vec"
#elif defined(MK10F12)
  #include "MK10F12.vec"
#elif defined(MK11D5)
  #include "MK11D5.vec"
#elif defined(MK12D5)
  #include "MK12D5.vec"
#elif defined(MK20D5)
  #include "MK20D5.vec"
#elif defined(MK20D7)
  #include "MK20D7.vec"
#elif defined(MK20D10)
  #include "MK20D10.vec"  
#elif defined(MK20DZ10)
  #include "MK20DZ10.vec"
#elif defined(MK20F12)
  #include "MK20F12.vec"
#elif defined(MK21D5)
  #include "MK21D5.vec"
#elif defined(MK22D5)
  #include "MK22D5.vec"
#elif defined(MK30D7)
  #include "MK30D7.vec"
#elif defined(MK30D10)
  #include "MK30D10.vec"
#elif defined(MK30DZ10)
  #include "MK30DZ10.vec"
#elif defined(MK40D7)
  #include "MK40D7.vec"
#elif defined(MK40D10)
  #include "MK40D10.vec"
#elif defined(MK40DZ10)
  #include "MK40DZ10.vec"
#elif defined(MK50D7)
  #include "MK50D7.vec"
#elif defined(MK50D10)
  #include "MK50D10.vec"
#elif defined(MK50DZ10)
  #include "MK50DZ10.vec"
#elif defined(MK51D7)
  #include "MK51D7.vec"
#elif defined(MK51D10)
  #include "MK51D10.vec"
#elif defined(MK51DZ10)
  #include "MK51DZ10.vec"
#elif defined(MK52D10)
  #include "MK52D10.vec"
#elif defined(MK52DZ10)
  #include "MK52DZ10.vec"
#elif defined(MK53D10)
  #include "MK53D10.vec"
#elif defined(MK53DZ10)
  #include "MK52DZ10.vec"
#elif defined(MK60D10)
  #include "MK60D10.vec"
#elif defined(MK60DZ10)
  #include "MK60DZ10.vec"
#elif defined(MK60F12)
  #include "MK60F12.vec"
#elif defined(MK60F15)
  #include "MK60F15.vec"
#elif defined(MK61F12)
  #include "MK61F12.vec"
#elif defined(MK61F15)
  #include "MK61F15.vec"
#elif defined(MK70F12)
  #include "MK70F12.vec"
#elif defined(MK70F15)
  #include "MK70F15.vec"
#elif defined(MKE02Z2)
  #include "MKE02z2.vec"
#elif defined(MKE04Z4)
  #include "MKE04z4.vec"
#elif defined(MKL02Z4)
  #include "MKL02Z4.vec"
#elif defined(MKL04Z4)
  #include "MKL04Z4.vec"
#elif defined(MKL05Z4)
  #include "MKL05Z4.vec"
#elif defined(MKL14Z4)
  #include "MKL14Z4.vec"
#elif defined(MKL15Z4)
  #include "MKL15Z4.vec"
#elif defined(MKL16Z4)
  #include "MKL16Z4.vec"
#elif defined(MKL24Z4)
  #include "MKL24Z4.vec"
#elif defined(MKL25Z4)
  #include "MKL25Z4.vec"
#elif defined(MKL26Z4)
  #include "MKL26Z4.vec"
#elif defined(MKL34Z4)
  #include "MKL34Z4.vec"
#elif defined(MKL36Z4)
  #include "MKL36Z4.vec"
#elif defined(MKL46Z4)
  #include "MKL46Z4.vec"
#else
  #error no vectors
#endif
  .section .vectors, "ax"
_vectors_end:
  
  .section .vectors, "ax"
  // fill to 0x400 for the flash configuration field
  .fill 0x400-(_vectors_end-_vectors), 1, 0xff
BackDoorKey:
  .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
#if defined(MKE02Z2) || defined(MKE04Z4)
RESERVED:
  .byte 0xff, 0xff, 0xff, 0xff
EEPROT:
  .byte 0xff
FPROT:
  .byte 0xff
FSEC:
  .byte 0xfe
FOPT:
  .byte 0xff
#else
FPROT:
  .byte 0xff, 0xff, 0xff, 0xff
FSEC:
  .byte 0xfe
FOPT:
  .byte 0xff
FEPROT:
  .byte 0xff
FDPROT:
  .byte 0xff
#endif

  .section .init, "ax"  
  .thumb_func
  reset_handler:
#ifndef __NO_SYSTEM_INIT
#ifdef __ARM_ARCH_6M__
  ldr r0, =__SRAM_segment_end__
  mov sp, r0
#else
  ldr sp, =__SRAM_segment_end__
#endif
  bl SystemInit
#endif

#ifdef __HAS_FPU
#ifndef __NO_FPU
  // Enable CP11 and CP10 with CPACR |= (0xf<<20)
  movw r0, 0xED88
  movt r0, 0xE000
  ldr r1, [r0]
  orrs r1, r1, #(0xf << 20)
  str r1, [r0]
#ifndef __NO_RUNFAST_MODE
  nop
  nop
  nop  
  vmrs r0, fpscr
  orrs r0, r0, #(0x3 << 24) // FZ and DN
  vmsr fpscr, r0
  // clear the CONTROL.FPCA bit
  mov r0, #0
  msr control, r0 
  // FPDSCR similarly
  movw r1, 0xEF3C
  movt r1, 0xE000
  ldr r0, [r1]
  orrs r0, r0, #(0x3 << 24) // FZ and DN
  str r0, [r1]
#endif
#endif
#endif

#ifdef VECTORS_IN_RAM
  ldr r0, =_vectors
  ldr r1, =_vectors_end
  ldr r2, =__VECTOR_RAM
l0:
  cmp r0, r1
  beq l1
  ldr r3, [r0]
  str r3, [r2]
  adds r0, r0, #4
  adds r2, r2, #4
  b l0
l1:
#endif

  /* Configure vector table offset register */
  ldr r0, =0xE000ED08
#ifdef VECTORS_IN_RAM
  ldr r1, =__vectors_ram_start__
#else
  ldr r1, =_vectors
#endif
  str r1, [r0]

  b _start

#ifndef __NO_SYSTEM_INIT
  .thumb_func
  .weak SystemInit
SystemInit:
#endif  
disableWatchDog: 
#if defined(MKL02Z4) || defined(MKL04Z4) || defined(MKL05Z4) || defined(MKL14Z4) || defined(MKL15Z4) || defined(MKL24Z4) || defined(MKL25Z4) || defined(MKL26Z4) || defined(MKL34Z4) || defined(MKL36Z4) || defined(MKL46Z4)
  ldr r0, =0x40048100
  ldr r1, =#0
  str r1, [r0]
#elif defined(MKE02Z2) || defined(MKE04Z4)
  ldr r0, =0x40052000
  ldr r1, =0x0
  strb r1, [r0, #1] // WDOG->CS2 = 0;
  ldr r1, =#0x20c5
  strh r1, [r0, #2] // WDOG->CNT = 0x20C5;
  ldr r1, =#0x28D9
  strh r1, [r0, #2] // WDOG->CNT = 0x28D9;
  ldr r1, =#0xFFFF
  strh r1, [r0, #4] // WDOG->TOVAL = 0xFFFF;
  ldr r1, =#0x20
  strb r1, [r0, #0] // WDOG->CS1 = 0x20;
#else
  movw r0, #0x2000
  movt r0, #0x4005
  movw r1, #0xC520
  strh r1, [r0, #14]
  movw r1, #0xD928
  strh r1, [r0, #14] 
  movw r1, #0x1D2
  strh r1, [r0]
#endif
  bx lr

#ifndef STARTUP_FROM_RESET
  .thumb_func
reset_wait:
  bl disableWatchDog;
1: b 1b /* endless loop */
#endif /* STARTUP_FROM_RESET */

#ifdef VECTORS_IN_RAM
  .section .vectors_ram, "ax"
  .global __VECTOR_RAM
__VECTOR_RAM:
  .space _vectors_end-_vectors, 0
#endif
