/*****************************************************************************
 * Copyright (c) 2010-2014 Rowley Associates Limited.                        *
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
#include __VECTORS
  .section .vectors, "ax"
_vectors_end:
    
  // flash configuration  
  .org 0x400, 0xff
  .long 0xffffffff
  .long 0xffffffff
  .long 0xffffffff
#if defined(MK80F25615)
  .long 0xffff3dfe
#elif defined(MK82F25615)
  .long 0xffff3dfe
#elif defined(MKE02Z4)
  .long 0xfffeff87
#elif defined(MKE04Z4)
  .long 0xfffeffff
#elif defined(MKE04Z1284)
  .long 0xfffeffff
#elif defined(MKE06Z4)
  .long 0xfffeffff
#elif defined(MKE14Z7)
  .long 0xffff7dfe
#elif defined(MKE15Z7)
  .long 0xffff7dfe
#elif defined(MKE14F16)
  .long 0xffff7dfe
#elif defined(MKE16F16)
  .long 0xffff7dfe
#elif defined(MKE18F16)
  .long 0xffff7dfe
#elif defined(SKEAZN642)
  .long 0xfffeff87
#elif defined(SKEAZN84)
  .long 0xfffeffff
#elif defined(SKEAZ1284)
  .long 0xfffeffff
#elif defined(MKL03Z4)
  .long 0xffff3ffe
#elif defined(MKL13Z644)
  .long 0xffff3dfe
#elif defined(MKL17Z644)
  .long 0xffff3dfe
#elif defined(MKL17Z4)
  .long 0xffff3ffe
#elif defined(MKL27Z644)
  .long 0xffff3dfe
#elif defined(MKL27Z4)
  .long 0xffff3ffe
#elif defined(MKL28Z7)
  .long 0xffff3dfe
#elif defined(MKL33Z644)
  .long 0xffff3dfe
#elif defined(MKL33Z4)
  .long 0xffff3ffe
#elif defined(MKL43Z4)
  .long 0xffff3ffe
#elif defined(MKL82Z7)
  .long 0xffff3dfe
#elif defined(MKM34Z7)
  .long 0xffff3ffe
#elif defined(MWPR1516)
  .long 0xfffeffff
#else
  .long 0xfffffffe
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

#if defined(__FPU_PRESENT) && !defined(__SOFTFP__)
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

  bl _start

#ifndef __NO_SYSTEM_INIT
  .thumb_func
  .weak SystemInit
SystemInit:
#endif  
disableWatchDog: 
#if defined(L_SERIES)
  ldr r0, =0x40048100
  ldr r1, =0x0
  str r1, [r0]
#elif defined(L28_SERIES)
  ldr r0, =0x40076000
  ldr r1, =0xD928C520
  str r1, [r0, #4]
  ldr r1, =0xffff
  str r1, [r0, #8]
  ldr r1, [r0]
  ldr r2, =(1<<7)
  bics r1, r2
  ldr r2, =(1<<5)
  orrs r1, r2
  str r1, [r0]
#elif defined(K_SERIES)
  movw r0, #0x2000
  movt r0, #0x4005
  movw r1, #0xC520
  strh r1, [r0, #14]
  movw r1, #0xD928
  strh r1, [r0, #14] 
  movw r1, #0x1D2
  strh r1, [r0]
#elif defined(M_SERIES)
  ldr r2, =0x40053000
  ldr r3, =0xC520
  strh r3, [r2, #14]
  ldr r3, =0xD928
  strh r3, [r2, #14] 
  ldr r3, =0x1D2
  strh r3, [r2]
#elif defined(V_SERIES)
  ldr r2, =0x40052000
  ldr r3, =0xC520
  strh r3, [r2, #14]
  ldr r3, =0xD928
  strh r3, [r2, #14] 
  ldr r3, =0x1D2
  strh r3, [r2]
#elif defined(E_SERIES)
  ldr r0, =0x40052000
  ldr r1, =0x0
  strb r1, [r0, #1]
  ldr r1, =0x20c5
  strh r1, [r0, #2]
  ldr r1, =0x28D9
  strh r1, [r0, #2]
  ldr r1, =0xFFFF
  strh r1, [r0, #4]
  ldr r1, =0x20
  strb r1, [r0, #0]
#elif defined(E1_SERIES) || defined(E2_SERIES)
  ldr r0, =0x40052000
  ldr r1, =0xD928C520
  str r1, [r0, #4]
  ldr r1, =0xffff
  str r1, [r0, #8]
  ldr r1, [r0]
  ldr r2, =(1<<7)
  bics r1, r2
  ldr r2, =(1<<5)
  orrs r1, r2
  str r1, [r0]
#elif defined(W35_SERIES)
#else
#error L_SERIES, L28_SERIES, K_SERIES, M_SERIES, V_SERIES, E_SERIES, E1_SERIES or E2_SERIES should be defined
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
