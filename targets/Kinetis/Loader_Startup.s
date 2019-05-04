/*****************************************************************************
  Generic ARM loader startup code.

  Copyright (c) 2007 Rowley Associates Limited.

  This file may be distributed under the terms of the License Agreement
  provided with this software.

  THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *****************************************************************************/

  .text
  .syntax unified
  .thumb
  .align 2
  .thumb_func
  
  .global _start
  .extern main

/*****************************************************************************
 * Function    : _start                                                      *
 *                                                                           *
 * Description : Minimal C startup code for loader.                          *
 *                                                                           *
 * Input       : R0 - Number of loader parameters                            *
 *             : R1 - Loader parameter 0                                     *
 *****************************************************************************/
_start:
  // Disable watchdog
#if defined(L_SERIES)
  ldr r2, =0x40048100
  ldr r3, =#0
  str r3, [r2]
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
  movw r2, #0x2000
  movt r2, #0x4005
  movw r3, #0xC520
  strh r3, [r2, #14]
  movw r3, #0xD928
  strh r3, [r2, #14] 
  movw r3, #0x1D2
  strh r3, [r2]
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
  ldr r2, =0x40052000
  ldr r3, =0x0
  strb r3, [r2, #1]
  ldr r3, =#0x20c5
  strh r3, [r2, #2]
  ldr r3, =#0x28D9
  strh r3, [r2, #2]
  ldr r3, =#0xFFFF
  strh r3, [r2, #4]
  ldr r3, =#0x20
  strb r3, [r2, #0]
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

  // Copy loader parameter if supplied
  cmp r0, #0
  beq 1f
  mov r0, r1
1:
  
  // Set stackpointer
  ldr r2, =__stack_end__
  mov sp, r2

  // Clear BSS
  ldr r2, =__bss_start__
  ldr r3, =__bss_end__
  movs r4, #0
zero_bss_loop:
  cmp r2, r3
  beq zero_bss_end
  strb r4, [r2]
  adds r2, r2, #1
  b zero_bss_loop
zero_bss_end:

  bl main

  b .
