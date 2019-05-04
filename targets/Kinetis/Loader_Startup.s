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

  // disable the watchdog
  movw r2, #0x2000
  movt r2, #0x4005
  movw r3, #0xC520
  strh r3, [r2, #14]
  movw r3, #0xD928
  strh r3, [r2, #14] 
  movw r3, #0x1D2
  strh r3, [r2]
  /***************************************************************************
   * Copy loader parameter to R0 if a parameter has been supplied.           *
   ***************************************************************************/
  cmp r0, #0
  it ne
  movne r0, r1

  /***************************************************************************
   * TODO: Carry out memory configration here if required.                   *
   ***************************************************************************/

  /***************************************************************************
   * Setup stack                                                             *
   ***************************************************************************/
  ldr sp, =__stack_end__

  /***************************************************************************
   * Zero the BSS section.                                                   *
   ***************************************************************************/
  ldr r2, =__bss_start__
  ldr r3, =__bss_end__
  mov r4, #0
zero_bss_loop:
  cmp r2, r3
  beq zero_bss_end
  strb r4, [r2], #+1
  b zero_bss_loop
zero_bss_end:

  /***************************************************************************
   * Jump to loader main and pass R0 as parameter                            *
   ***************************************************************************/
  bl main
  
  /***************************************************************************
   * Return from main, endless loop.                                         *
   ***************************************************************************/
  b .
