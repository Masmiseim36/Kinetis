/*****************************************************************************
 * Copyright (c) 2010, 2011 Rowley Associates Limited.                       *
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
  .word DMA0_IRQHandler  /* DMA Channel 0 Transfer Complete */
  .word DMA1_IRQHandler  /* DMA Channel 1 Transfer Complete */
  .word DMA2_IRQHandler  /* DMA Channel 2 Transfer Complete */
  .word DMA3_IRQHandler  /* DMA Channel 3 Transfer Complete */
  .word DMA4_IRQHandler  /* DMA Channel 4 Transfer Complete */
  .word DMA5_IRQHandler  /* DMA Channel 5 Transfer Complete */
  .word DMA6_IRQHandler  /* DMA Channel 6 Transfer Complete */
  .word DMA7_IRQHandler  /* DMA Channel 7 Transfer Complete */
  .word DMA8_IRQHandler  /* DMA Channel 8 Transfer Complete */
  .word DMA9_IRQHandler  /* DMA Channel 9 Transfer Complete */
  .word DMA10_IRQHandler  /* DMA Channel 10 Transfer Complete */
  .word DMA11_IRQHandler  /* DMA Channel 11 Transfer Complete */
  .word DMA12_IRQHandler  /* DMA Channel 12 Transfer Complete */
  .word DMA13_IRQHandler  /* DMA Channel 13 Transfer Complete */
  .word DMA14_IRQHandler  /* DMA Channel 14 Transfer Complete */
  .word DMA15_IRQHandler  /* DMA Channel 15 Transfer Complete */
  .word DMA_Error_IRQHandler  /* DMA Error Interrupt */
  .word MCM_IRQHandler  /* Normal Interrupt */
  .word FTFL_IRQHandler  /* FTFL Interrupt */
  .word Read_Collision_IRQHandler  /* Read Collision Interrupt */
  .word LVD_LVW_IRQHandler  /* Low Voltage Detect, Low Voltage Warning */
  .word LLW_IRQHandler  /* Low Leakage Wakeup */
  .word Watchdog_IRQHandler  /* WDOG Interrupt */
  .word RNG_IRQHandler  /* RNGB Interrupt */
  .word I2C0_IRQHandler  /* I2C0 interrupt */
  .word I2C1_IRQHandler  /* I2C1 interrupt */
  .word SPI0_IRQHandler  /* SPI0 Interrupt */
  .word SPI1_IRQHandler  /* SPI1 Interrupt */
  .word SPI2_IRQHandler  /* SPI2 Interrupt */
  .word CAN0_ORed_Message_buffer_IRQHandler  /* CAN0 OR'd Message Buffers Interrupt */
  .word CAN0_Bus_Off_IRQHandler  /* CAN0 Bus Off Interrupt */
  .word CAN0_Error_IRQHandler  /* CAN0 Error Interrupt */
  .word CAN0_Tx_Warning_IRQHandler  /* CAN0 Tx Warning Interrupt */
  .word CAN0_Rx_Warning_IRQHandler  /* CAN0 Rx Warning Interrupt */
  .word CAN0_Wake_Up_IRQHandler  /* CAN0 Wake Up Interrupt */
  .word Reserved51_IRQHandler  /* Reserved interrupt 51 */
  .word Reserved52_IRQHandler  /* Reserved interrupt 52 */
  .word CAN1_ORed_Message_buffer_IRQHandler  /* CAN1 OR'd Message Buffers Interrupt */
  .word CAN1_Bus_Off_IRQHandler  /* CAN1 Bus Off Interrupt */
  .word CAN1_Error_IRQHandler  /* CAN1 Error Interrupt */
  .word CAN1_Tx_Warning_IRQHandler  /* CAN1 Tx Warning Interrupt */
  .word CAN1_Rx_Warning_IRQHandler  /* CAN1 Rx Warning Interrupt */
  .word CAN1_Wake_Up_IRQHandler  /* CAN1 Wake Up Interrupt */
  .word Reserved59_IRQHandler  /* Reserved interrupt 59 */
  .word Reserved60_IRQHandler  /* Reserved interrupt 60 */
  .word UART0_RX_TX_IRQHandler  /* UART0 Receive/Transmit interrupt */
  .word UART0_ERR_IRQHandler  /* UART0 Error interrupt */
  .word UART1_RX_TX_IRQHandler  /* UART1 Receive/Transmit interrupt */
  .word UART1_ERR_IRQHandler  /* UART1 Error interrupt */
  .word UART2_RX_TX_IRQHandler  /* UART2 Receive/Transmit interrupt */
  .word UART2_ERR_IRQHandler  /* UART2 Error interrupt */
  .word UART3_RX_TX_IRQHandler  /* UART3 Receive/Transmit interrupt */
  .word UART3_ERR_IRQHandler  /* UART3 Error interrupt */
  .word UART4_RX_TX_IRQHandler  /* UART4 Receive/Transmit interrupt */
  .word UART4_ERR_IRQHandler  /* UART4 Error interrupt */
  .word UART5_RX_TX_IRQHandler  /* UART5 Receive/Transmit interrupt */
  .word UART5_ERR_IRQHandler  /* UART5 Error interrupt */
  .word ADC0_IRQHandler  /* ADC0 interrupt */
  .word ADC1_IRQHandler  /* ADC1 interrupt */
  .word CMP0_IRQHandler  /* CMP0 interrupt */
  .word CMP1_IRQHandler  /* CMP1 interrupt */
  .word CMP2_IRQHandler  /* CMP2 interrupt */
  .word FTM0_IRQHandler  /* FTM0 fault, overflow and channels interrupt */
  .word FTM1_IRQHandler  /* FTM1 fault, overflow and channels interrupt */
  .word FTM2_IRQHandler  /* FTM2 fault, overflow and channels interrupt */
  .word CMT_IRQHandler  /* CMT interrupt */
  .word RTC_IRQHandler  /* RTC interrupt */
  .word Reserved83_IRQHandler  /* Reserved interrupt 83 */
  .word PIT0_IRQHandler  /* PIT timer channel 0 interrupt */
  .word PIT1_IRQHandler  /* PIT timer channel 1 interrupt */
  .word PIT2_IRQHandler  /* PIT timer channel 2 interrupt */
  .word PIT3_IRQHandler  /* PIT timer channel 3 interrupt */
  .word PDB0_IRQHandler  /* PDB0 Interrupt */
  .word USB0_IRQHandler  /* USB0 interrupt */
  .word USBDCD_IRQHandler  /* USBDCD Interrupt */
  .word ENET_1588_Timer_IRQHandler  /* Ethernet MAC IEEE 1588 Timer Interrupt */
  .word ENET_Transmit_IRQHandler  /* Ethernet MAC Transmit Interrupt */
  .word ENET_Receive_IRQHandler  /* Ethernet MAC Receive Interrupt */
  .word ENET_Error_IRQHandler  /* Ethernet MAC Error and miscelaneous Interrupt */
  .word I2S0_IRQHandler  /* I2S0 Interrupt */
  .word SDHC_IRQHandler  /* SDHC Interrupt */
  .word DAC0_IRQHandler  /* DAC0 interrupt */
  .word DAC1_IRQHandler  /* DAC1 interrupt */
  .word TSI0_IRQHandler  /* TSI0 Interrupt */
  .word MCG_IRQHandler  /* MCG Interrupt */
  .word LPTimer_IRQHandler  /* LPTimer interrupt */
  .word Reserved102_IRQHandler  /* Reserved interrupt 102 */
  .word PORTA_IRQHandler  /* Port A interrupt */
  .word PORTB_IRQHandler  /* Port B interrupt */
  .word PORTC_IRQHandler  /* Port C interrupt */
  .word PORTD_IRQHandler  /* Port D interrupt */
  .word PORTE_IRQHandler  /* Port E interrupt */
  .word Reserved108_IRQHandler  /* Reserved interrupt 108 */
  .word Reserved109_IRQHandler  /* Reserved interrupt 109 */
  .word Reserved110_IRQHandler  /* Reserved interrupt 110 */
  .word Reserved111_IRQHandler  /* Reserved interrupt 111 */
  .word Reserved112_IRQHandler  /* Reserved interrupt 112 */
  .word Reserved113_IRQHandler  /* Reserved interrupt 113 */
  .word Reserved114_IRQHandler  /* Reserved interrupt 114 */
  .word Reserved115_IRQHandler  /* Reserved interrupt 115 */
  .word Reserved116_IRQHandler  /* Reserved interrupt 116 */
  .word Reserved117_IRQHandler  /* Reserved interrupt 117 */
  .word Reserved118_IRQHandler  /* Reserved interrupt 118 */
  .word Reserved119_IRQHandler  /* Reserved interrupt 119 */
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

#ifdef __FPU_PRESENT
  // SCB->CPACR |= (0xF << 20);               /* cp10 and cp11 set in CPACR    */
  movw r0, 0xED88
  movt r0, 0xE000
  ldr r1, [r0]
  orrs r1, r1, #(0xf << 20)
  str r1, [r0]
#endif

#ifdef VECTORS_IN_RAM
  ldr r0, =__vectors_load_start__
  ldr r1, =__vectors_load_end__
  ldr r2, =__vectors_ram_start__
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

DEFAULT_ISR_HANDLER DMA0_IRQHandler  /* DMA Channel 0 Transfer Complete */
DEFAULT_ISR_HANDLER DMA1_IRQHandler  /* DMA Channel 1 Transfer Complete */
DEFAULT_ISR_HANDLER DMA2_IRQHandler  /* DMA Channel 2 Transfer Complete */
DEFAULT_ISR_HANDLER DMA3_IRQHandler  /* DMA Channel 3 Transfer Complete */
DEFAULT_ISR_HANDLER DMA4_IRQHandler  /* DMA Channel 4 Transfer Complete */
DEFAULT_ISR_HANDLER DMA5_IRQHandler  /* DMA Channel 5 Transfer Complete */
DEFAULT_ISR_HANDLER DMA6_IRQHandler  /* DMA Channel 6 Transfer Complete */
DEFAULT_ISR_HANDLER DMA7_IRQHandler  /* DMA Channel 7 Transfer Complete */
DEFAULT_ISR_HANDLER DMA8_IRQHandler  /* DMA Channel 8 Transfer Complete */
DEFAULT_ISR_HANDLER DMA9_IRQHandler  /* DMA Channel 9 Transfer Complete */
DEFAULT_ISR_HANDLER DMA10_IRQHandler  /* DMA Channel 10 Transfer Complete */
DEFAULT_ISR_HANDLER DMA11_IRQHandler  /* DMA Channel 11 Transfer Complete */
DEFAULT_ISR_HANDLER DMA12_IRQHandler  /* DMA Channel 12 Transfer Complete */
DEFAULT_ISR_HANDLER DMA13_IRQHandler  /* DMA Channel 13 Transfer Complete */
DEFAULT_ISR_HANDLER DMA14_IRQHandler  /* DMA Channel 14 Transfer Complete */
DEFAULT_ISR_HANDLER DMA15_IRQHandler  /* DMA Channel 15 Transfer Complete */
DEFAULT_ISR_HANDLER DMA_Error_IRQHandler  /* DMA Error Interrupt */
DEFAULT_ISR_HANDLER MCM_IRQHandler  /* Normal Interrupt */
DEFAULT_ISR_HANDLER FTFL_IRQHandler  /* FTFL Interrupt */
DEFAULT_ISR_HANDLER Read_Collision_IRQHandler  /* Read Collision Interrupt */
DEFAULT_ISR_HANDLER LVD_LVW_IRQHandler  /* Low Voltage Detect, Low Voltage Warning */
DEFAULT_ISR_HANDLER LLW_IRQHandler  /* Low Leakage Wakeup */
DEFAULT_ISR_HANDLER Watchdog_IRQHandler  /* WDOG Interrupt */
DEFAULT_ISR_HANDLER RNG_IRQHandler  /* RNGB Interrupt */
DEFAULT_ISR_HANDLER I2C0_IRQHandler  /* I2C0 interrupt */
DEFAULT_ISR_HANDLER I2C1_IRQHandler  /* I2C1 interrupt */
DEFAULT_ISR_HANDLER SPI0_IRQHandler  /* SPI0 Interrupt */
DEFAULT_ISR_HANDLER SPI1_IRQHandler  /* SPI1 Interrupt */
DEFAULT_ISR_HANDLER SPI2_IRQHandler  /* SPI2 Interrupt */
DEFAULT_ISR_HANDLER CAN0_ORed_Message_buffer_IRQHandler  /* CAN0 OR'd Message Buffers Interrupt */
DEFAULT_ISR_HANDLER CAN0_Bus_Off_IRQHandler  /* CAN0 Bus Off Interrupt */
DEFAULT_ISR_HANDLER CAN0_Error_IRQHandler  /* CAN0 Error Interrupt */
DEFAULT_ISR_HANDLER CAN0_Tx_Warning_IRQHandler  /* CAN0 Tx Warning Interrupt */
DEFAULT_ISR_HANDLER CAN0_Rx_Warning_IRQHandler  /* CAN0 Rx Warning Interrupt */
DEFAULT_ISR_HANDLER CAN0_Wake_Up_IRQHandler  /* CAN0 Wake Up Interrupt */
DEFAULT_ISR_HANDLER Reserved51_IRQHandler  /* Reserved interrupt 51 */
DEFAULT_ISR_HANDLER Reserved52_IRQHandler  /* Reserved interrupt 52 */
DEFAULT_ISR_HANDLER CAN1_ORed_Message_buffer_IRQHandler  /* CAN1 OR'd Message Buffers Interrupt */
DEFAULT_ISR_HANDLER CAN1_Bus_Off_IRQHandler  /* CAN1 Bus Off Interrupt */
DEFAULT_ISR_HANDLER CAN1_Error_IRQHandler  /* CAN1 Error Interrupt */
DEFAULT_ISR_HANDLER CAN1_Tx_Warning_IRQHandler  /* CAN1 Tx Warning Interrupt */
DEFAULT_ISR_HANDLER CAN1_Rx_Warning_IRQHandler  /* CAN1 Rx Warning Interrupt */
DEFAULT_ISR_HANDLER CAN1_Wake_Up_IRQHandler  /* CAN1 Wake Up Interrupt */
DEFAULT_ISR_HANDLER Reserved59_IRQHandler  /* Reserved interrupt 59 */
DEFAULT_ISR_HANDLER Reserved60_IRQHandler  /* Reserved interrupt 60 */
DEFAULT_ISR_HANDLER UART0_RX_TX_IRQHandler  /* UART0 Receive/Transmit interrupt */
DEFAULT_ISR_HANDLER UART0_ERR_IRQHandler  /* UART0 Error interrupt */
DEFAULT_ISR_HANDLER UART1_RX_TX_IRQHandler  /* UART1 Receive/Transmit interrupt */
DEFAULT_ISR_HANDLER UART1_ERR_IRQHandler  /* UART1 Error interrupt */
DEFAULT_ISR_HANDLER UART2_RX_TX_IRQHandler  /* UART2 Receive/Transmit interrupt */
DEFAULT_ISR_HANDLER UART2_ERR_IRQHandler  /* UART2 Error interrupt */
DEFAULT_ISR_HANDLER UART3_RX_TX_IRQHandler  /* UART3 Receive/Transmit interrupt */
DEFAULT_ISR_HANDLER UART3_ERR_IRQHandler  /* UART3 Error interrupt */
DEFAULT_ISR_HANDLER UART4_RX_TX_IRQHandler  /* UART4 Receive/Transmit interrupt */
DEFAULT_ISR_HANDLER UART4_ERR_IRQHandler  /* UART4 Error interrupt */
DEFAULT_ISR_HANDLER UART5_RX_TX_IRQHandler  /* UART5 Receive/Transmit interrupt */
DEFAULT_ISR_HANDLER UART5_ERR_IRQHandler  /* UART5 Error interrupt */
DEFAULT_ISR_HANDLER ADC0_IRQHandler  /* ADC0 interrupt */
DEFAULT_ISR_HANDLER ADC1_IRQHandler  /* ADC1 interrupt */
DEFAULT_ISR_HANDLER CMP0_IRQHandler  /* CMP0 interrupt */
DEFAULT_ISR_HANDLER CMP1_IRQHandler  /* CMP1 interrupt */
DEFAULT_ISR_HANDLER CMP2_IRQHandler  /* CMP2 interrupt */
DEFAULT_ISR_HANDLER FTM0_IRQHandler  /* FTM0 fault, overflow and channels interrupt */
DEFAULT_ISR_HANDLER FTM1_IRQHandler  /* FTM1 fault, overflow and channels interrupt */
DEFAULT_ISR_HANDLER FTM2_IRQHandler  /* FTM2 fault, overflow and channels interrupt */
DEFAULT_ISR_HANDLER CMT_IRQHandler  /* CMT interrupt */
DEFAULT_ISR_HANDLER RTC_IRQHandler  /* RTC interrupt */
DEFAULT_ISR_HANDLER Reserved83_IRQHandler  /* Reserved interrupt 83 */
DEFAULT_ISR_HANDLER PIT0_IRQHandler  /* PIT timer channel 0 interrupt */
DEFAULT_ISR_HANDLER PIT1_IRQHandler  /* PIT timer channel 1 interrupt */
DEFAULT_ISR_HANDLER PIT2_IRQHandler  /* PIT timer channel 2 interrupt */
DEFAULT_ISR_HANDLER PIT3_IRQHandler  /* PIT timer channel 3 interrupt */
DEFAULT_ISR_HANDLER PDB0_IRQHandler  /* PDB0 Interrupt */
DEFAULT_ISR_HANDLER USB0_IRQHandler  /* USB0 interrupt */
DEFAULT_ISR_HANDLER USBDCD_IRQHandler  /* USBDCD Interrupt */
DEFAULT_ISR_HANDLER ENET_1588_Timer_IRQHandler  /* Ethernet MAC IEEE 1588 Timer Interrupt */
DEFAULT_ISR_HANDLER ENET_Transmit_IRQHandler  /* Ethernet MAC Transmit Interrupt */
DEFAULT_ISR_HANDLER ENET_Receive_IRQHandler  /* Ethernet MAC Receive Interrupt */
DEFAULT_ISR_HANDLER ENET_Error_IRQHandler  /* Ethernet MAC Error and miscelaneous Interrupt */
DEFAULT_ISR_HANDLER I2S0_IRQHandler  /* I2S0 Interrupt */
DEFAULT_ISR_HANDLER SDHC_IRQHandler  /* SDHC Interrupt */
DEFAULT_ISR_HANDLER DAC0_IRQHandler  /* DAC0 interrupt */
DEFAULT_ISR_HANDLER DAC1_IRQHandler  /* DAC1 interrupt */
DEFAULT_ISR_HANDLER TSI0_IRQHandler  /* TSI0 Interrupt */
DEFAULT_ISR_HANDLER MCG_IRQHandler  /* MCG Interrupt */
DEFAULT_ISR_HANDLER LPTimer_IRQHandler  /* LPTimer interrupt */
DEFAULT_ISR_HANDLER Reserved102_IRQHandler  /* Reserved interrupt 102 */
DEFAULT_ISR_HANDLER PORTA_IRQHandler  /* Port A interrupt */
DEFAULT_ISR_HANDLER PORTB_IRQHandler  /* Port B interrupt */
DEFAULT_ISR_HANDLER PORTC_IRQHandler  /* Port C interrupt */
DEFAULT_ISR_HANDLER PORTD_IRQHandler  /* Port D interrupt */
DEFAULT_ISR_HANDLER PORTE_IRQHandler  /* Port E interrupt */
DEFAULT_ISR_HANDLER Reserved108_IRQHandler  /* Reserved interrupt 108 */
DEFAULT_ISR_HANDLER Reserved109_IRQHandler  /* Reserved interrupt 109 */
DEFAULT_ISR_HANDLER Reserved110_IRQHandler  /* Reserved interrupt 110 */
DEFAULT_ISR_HANDLER Reserved111_IRQHandler  /* Reserved interrupt 111 */
DEFAULT_ISR_HANDLER Reserved112_IRQHandler  /* Reserved interrupt 112 */
DEFAULT_ISR_HANDLER Reserved113_IRQHandler  /* Reserved interrupt 113 */
DEFAULT_ISR_HANDLER Reserved114_IRQHandler  /* Reserved interrupt 114 */
DEFAULT_ISR_HANDLER Reserved115_IRQHandler  /* Reserved interrupt 115 */
DEFAULT_ISR_HANDLER Reserved116_IRQHandler  /* Reserved interrupt 116 */
DEFAULT_ISR_HANDLER Reserved117_IRQHandler  /* Reserved interrupt 117 */
DEFAULT_ISR_HANDLER Reserved118_IRQHandler  /* Reserved interrupt 118 */
DEFAULT_ISR_HANDLER Reserved119_IRQHandler  /* Reserved interrupt 119 */

#ifndef STARTUP_FROM_RESET
  .thumb_func
reset_wait:
  // disable the watchdog
  movw r0, #0x2000
  movt r0, #0x4005
  movw r1, #0xC520
  strh r1, [r0, #14]
  movw r1, #0xD928
  strh r1, [r0, #14] 
  movw r1, #0x1D2
  strh r1, [r0]
1: b 1b /* endless loop */
#endif /* STARTUP_FROM_RESET */

#ifdef VECTORS_IN_RAM
  .section .vectors_ram, "ax"
_vectors_ram:
  .space _vectors_end-_vectors, 0
#endif
