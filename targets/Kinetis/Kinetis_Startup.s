/*****************************************************************************
 * Copyright (c) 2010, 2011, 2012 Rowley Associates Limited.                 *
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

  .syntax unified
  .global reset_handler

  .section .vectors, "ax"
  .code 16
  .global _vectors

.macro DEFAULT_ISR_HANDLER name=
  .thumb_func
  .weak \name
\name:
1: b 1b /* endless loop */
.endm

_vectors:
  .word __stack_end__
#ifdef STARTUP_FROM_RESET
  .word reset_handler
#else
  .word reset_wait
#endif /* STARTUP_FROM_RESET */
  .word NMI_Handler
  .word HardFault_Handler
  .word MemManage_Handler
  .word BusFault_Handler
  .word UsageFault_Handler
  .word 0 // Reserved
  .word 0 // Reserved
  .word 0 // Reserved
  .word 0 // Reserved
  .word SVC_Handler
  .word DebugMon_Handler
  .word 0 // Reserved
  .word PendSV_Handler
  .word SysTick_Handler
  // External interrupts start her 
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
#else
  #error no vectors
#endif
_vectors_end:

  // align to 0x400 for the flash configuration field
  .balign 0x400, 0xff
BackDoorKey:
  .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
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

  .section .init, "ax"  
  .thumb_func
  reset_handler:
#ifndef __NO_SYSTEM_INIT
  ldr sp, =__SRAM_segment_end__
  bl SystemInit
#endif

#ifdef __HAS_FPU
#ifndef __NO_FPU
#ifdef CTL_TASKING
  // Clear ASPEN and LSPEN bits with FPCCR &= ~(C00000000)
  movw r0, 0xEF34
  movt r0, 0xE000
  ldr r1, [r0]
  bics r1, r1, #(0xC0000000)
  str r1, [r0]
#endif
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
#endif
#endif
#endif

#ifdef VECTORS_IN_RAM
  ldr r0, =__vectors_load_start__
  ldr r1, =__vectors_load_end__
  ldr r2, =__VECTOR_RAM
l0:
  cmp r0, r1
  beq l1
  ldr r3, [r0], #4
  str r3, [r2], #4
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

DEFAULT_ISR_HANDLER NMI_Handler
DEFAULT_ISR_HANDLER HardFault_Handler
DEFAULT_ISR_HANDLER MemManage_Handler
DEFAULT_ISR_HANDLER BusFault_Handler
DEFAULT_ISR_HANDLER UsageFault_Handler
DEFAULT_ISR_HANDLER SVC_Handler
DEFAULT_ISR_HANDLER DebugMon_Handler
DEFAULT_ISR_HANDLER PendSV_Handler
DEFAULT_ISR_HANDLER SysTick_Handler

#if defined(MK10D5)
  #include "MK10D5.vecdef"
#elif defined(MK10D7)
  #include "MK10D7.vecdef"
#elif defined(MK10D10)
  #include "MK10D10.vecdef"  
#elif defined(MK10DZ10)
  #include "MK10DZ10.vecdef"
#elif defined(MK10F12)
  #include "MK10F12.vecdef"
#elif defined(MK20D5)
  #include "MK20D5.vecdef"
#elif defined(MK20D7)
  #include "MK20D7.vecdef"
#elif defined(MK20D10)
  #include "MK20D10.vecdef"  
#elif defined(MK20DZ10)
  #include "MK20DZ10.vecdef"
#elif defined(MK20F12)
  #include "MK20F12.vecdef"
#elif defined(MK30D7)
  #include "MK30D7.vecdef"
#elif defined(MK30D10)
  #include "MK30D10.vecdef"
#elif defined(MK30DZ10)
  #include "MK30DZ10.vecdef"
#elif defined(MK40D7)
  #include "MK40D7.vecdef"
#elif defined(MK40D10)
  #include "MK40D10.vecdef"
#elif defined(MK40DZ10)
  #include "MK40DZ10.vecdef"
#elif defined(MK50D7)
  #include "MK50D7.vecdef"
#elif defined(MK50D10)
  #include "MK50D10.vecdef"
#elif defined(MK50DZ10)
  #include "MK50DZ10.vecdef"
#elif defined(MK51D7)
  #include "MK51D7.vecdef"
#elif defined(MK51D10)
  #include "MK51D10.vecdef"
#elif defined(MK51DZ10)
  #include "MK51DZ10.vecdef"
#elif defined(MK52D10)
  #include "MK52D10.vecdef"
#elif defined(MK52DZ10)
  #include "MK52DZ10.vecdef"
#elif defined(MK53D10)
  #include "MK53D10.vecdef"
#elif defined(MK53DZ10)
  #include "MK52DZ10.vecdef"
#elif defined(MK60D10)
  #include "MK60D10.vecdef"
#elif defined(MK60DZ10)
  #include "MK60DZ10.vecdef"
#elif defined(MK60F12)
  #include "MK60F12.vecdef"
#elif defined(MK60F15)
  #include "MK60F15.vecdef"
#elif defined(MK61F12)
  #include "MK61F12.vecdef"
#elif defined(MK61F15)
  #include "MK61F15.vecdef"
#elif defined(MK70F12)
  #include "MK70F12.vecdef"
#elif defined(MK70F15)
  #include "MK70F15.vecdef"
#else
  #error no vectors
#endif

#ifndef __NO_SYSTEM_INIT
  .thumb_func
  .weak SystemInit
SystemInit:
#endif  
disableWatchDog: 
  movw r0, #0x2000
  movt r0, #0x4005
  movw r1, #0xC520
  strh r1, [r0, #14]
  movw r1, #0xD928
  strh r1, [r0, #14] 
  movw r1, #0x1D2
  strh r1, [r0]
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
