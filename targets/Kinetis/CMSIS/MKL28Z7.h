/*
** ###################################################################
**     Processors:          MKL28Z512VDC7
**                          MKL28Z512VLH7
**                          MKL28Z512VLL7
**                          MKL28Z512VMP7
**
**     Compilers:           Keil ARM C/C++ Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          GNU C Compiler - CodeSourcery Sourcery G++
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    KL28SINGLERM, Rev. 0, June 1, 2015
**     Version:             rev. 1.12, 2015-06-03
**     Build:               b150603
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MKL28Z7
**
**     Copyright (c) 1997 - 2015 Freescale Semiconductor, Inc.
**     All rights reserved.
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2014-12-29)
**         Initial version.
**     - rev. 1.1 (2015-03-19)
**         Make array for registers in XRDC, PCC and TRGMUX
**     - rev. 1.2 (2015-03-20)
**         Add vector table for intmux0
**         Add IRQS for SCG, RCM, DAC, TSI
**     - rev. 1.3 (2015-03-26)
**         Update FGPIO and GPIO
**         Update IRQ for LPIT
**     - rev. 1.4 (2015-04-08)
**         Group channel registers for LPIT
**     - rev. 1.5 (2015-04-15)
**         Group channel registers for INTMUX
**     - rev. 1.6 (2015-05-06)
**         Correct FOPT reset value
**         Correct vector table size
**         Remove parts with 256K flash size
**     - rev. 1.7 (2015-05-08)
**         Reduce register for XRDC
**     - rev. 1.8 (2015-05-12)
**         Add CMP
**         DMAMUX channel count to 8
**         Add PIDR for GPIO/FGPIO
**         Rename PIT to LPIT in PCC
**         SCG, USB register update
**         SIM, TRGMUX1, TRNG, TSTMR0/1 base address update
**         Add KEY related macros for WDOG
**     - rev. 1.9 (2015-05-16)
**         Add IRQS
**     - rev. 1.10 (2015-05-30)
**         Remove MTB1, MCM1 and MMDVSQ1
**     - rev. 1.11 (2015-06-01)
**         Remove registers for modules which are not available on single in PCC and TRGMUX
**     - rev. 1.12 (2015-06-03)
**         Bit 31 of TRGMUX changed to RW from RO
**
** ###################################################################
*/

/*!
 * @file MKL28Z7.h
 * @version 1.12
 * @date 2015-06-03
 * @brief CMSIS Peripheral Access Layer for MKL28Z7
 *
 * CMSIS Peripheral Access Layer for MKL28Z7
 */


/* ----------------------------------------------------------------------------
   -- MCU activation
   ---------------------------------------------------------------------------- */

/* Prevention from multiple including the same memory map */
#if !defined(MKL28Z7_H_)  /* Check if memory map has not been already included */
#define MKL28Z7_H_
#define MCU_MKL28Z7

/* Check if another memory map has not been also included */
#if (defined(MCU_ACTIVE))
  #error MKL28Z7 memory map: There is already included another memory map. Only one memory map can be included.
#endif /* (defined(MCU_ACTIVE)) */
#define MCU_ACTIVE

#include <stdint.h>

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100u
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x000Cu


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 80                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M0 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M0 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M0 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M0 System Tick Interrupt */

  /* Device specific interrupts */
  DMA0_04_IRQn                 = 0,                /**< DMA0 channel 0/4 transfer complete */
  DMA0_15_IRQn                 = 1,                /**< DMA0 channel 1/5 transfer complete */
  DMA0_26_IRQn                 = 2,                /**< DMA0 channel 2/6 transfer complete */
  DMA0_37_IRQn                 = 3,                /**< DMA0 channel 3/7 transfer complete */
  CTI0_DMA0_Error_IRQn         = 4,                /**< CTI0 or DMA0 error */
  FLEXIO0_IRQn                 = 5,                /**< FLEXIO0 */
  TPM0_IRQn                    = 6,                /**< TPM0 single interrupt vector for all sources */
  TPM1_IRQn                    = 7,                /**< TPM1 single interrupt vector for all sources */
  TPM2_IRQn                    = 8,                /**< TPM2 single interrupt vector for all sources */
  LPIT0_IRQn                   = 9,                /**< LPIT0 interrupt */
  LPSPI0_IRQn                  = 10,               /**< LPSPI0 single interrupt vector for all sources */
  LPSPI1_IRQn                  = 11,               /**< LPSPI1 single interrupt vector for all sources */
  LPUART0_IRQn                 = 12,               /**< LPUART0 status and error */
  LPUART1_IRQn                 = 13,               /**< LPUART1 status and error */
  LPI2C0_IRQn                  = 14,               /**< LPI2C0 interrupt */
  LPI2C1_IRQn                  = 15,               /**< LPI2C1 interrupt */
  Reserved32_IRQn              = 16,               /**< Reserved interrupt */
  PORTA_IRQn                   = 17,               /**< PORTA Pin detect */
  PORTB_IRQn                   = 18,               /**< PORTB Pin detect */
  PORTC_IRQn                   = 19,               /**< PORTC Pin detect */
  PORTD_IRQn                   = 20,               /**< PORTD Pin detect */
  PORTE_IRQn                   = 21,               /**< PORTE Pin detect */
  LLWU0_IRQn                   = 22,               /**< Low leakage wakeup 0 */
  I2S0_IRQn                    = 23,               /**< I2S0 interrupt */
  USB0_IRQn                    = 24,               /**< USB0 interrupt */
  ADC0_IRQn                    = 25,               /**< ADC0 interrupt */
  LPTMR0_IRQn                  = 26,               /**< LPTMR0 interrupt */
  RTC_Seconds_IRQn             = 27,               /**< RTC seconds */
  INTMUX0_0_IRQn               = 28,               /**< INTMUX0 channel 0 interrupt */
  INTMUX0_1_IRQn               = 29,               /**< INTMUX0 channel 1 interrupt */
  INTMUX0_2_IRQn               = 30,               /**< INTMUX0 channel 2 interrupt */
  INTMUX0_3_IRQn               = 31,               /**< INTMUX0 channel 3 interrupt */
  LPTMR1_IRQn                  = 32,               /**< LPTMR1 interrupt  (INTMUX source IRQ0) */
  Reserved49_IRQn              = 33,               /**< Reserved interrupt */
  Reserved50_IRQn              = 34,               /**< Reserved interrupt */
  Reserved51_IRQn              = 35,               /**< Reserved interrupt */
  LPSPI2_IRQn                  = 36,               /**< LPSPI2 single interrupt vector for all sources (INTMUX source IRQ4) */
  LPUART2_IRQn                 = 37,               /**< LPUART2 status and error (INTMUX source IRQ5) */
  EMVSIM0_IRQn                 = 38,               /**< EMVSIM0 interrupt (INTMUX source IRQ6) */
  LPI2C2_IRQn                  = 39,               /**< LPI2C2 interrupt (INTMUX source IRQ7) */
  TSI0_IRQn                    = 40,               /**< TSI0 interrupt (INTMUX source IRQ8) */
  PMC_IRQn                     = 41,               /**< PMC interrupt (INTMUX source IRQ9) */
  FTFA_IRQn                    = 42,               /**< FTFA interrupt (INTMUX source IRQ10) */
  SCG_IRQn                     = 43,               /**< SCG interrupt (INTMUX source IRQ11) */
  WDOG0_IRQn                   = 44,               /**< WDOG0 interrupt (INTMUX source IRQ12) */
  DAC0_IRQn                    = 45,               /**< DAC0 interrupt (INTMUX source IRQ13) */
  TRNG_IRQn                    = 46,               /**< TRNG interrupt (INTMUX source IRQ14) */
  RCM_IRQn                     = 47,               /**< RCM interrupt (INTMUX source IRQ15) */
  CMP0_IRQn                    = 48,               /**< CMP0 interrupt (INTMUX source IRQ16) */
  CMP1_IRQn                    = 49,               /**< CMP1 interrupt (INTMUX source IRQ17) */
  RTC_Alarm_IRQn               = 50,               /**< RTC Alarm interrupt (INTMUX source IRQ18) */
  Reserved67_IRQn              = 51,               /**< Reserved interrupt */
  Reserved68_IRQn              = 52,               /**< Reserved interrupt */
  Reserved69_IRQn              = 53,               /**< Reserved interrupt */
  Reserved70_IRQn              = 54,               /**< Reserved interrupt */
  Reserved71_IRQn              = 55,               /**< Reserved interrupt */
  Reserved72_IRQn              = 56,               /**< Reserved interrupt */
  Reserved73_IRQn              = 57,               /**< Reserved interrupt */
  Reserved74_IRQn              = 58,               /**< Reserved interrupt */
  Reserved75_IRQn              = 59,               /**< Reserved interrupt */
  Reserved76_IRQn              = 60,               /**< Reserved interrupt */
  Reserved77_IRQn              = 61,               /**< Reserved interrupt */
  Reserved78_IRQn              = 62,               /**< Reserved interrupt */
  Reserved79_IRQn              = 63                /**< Reserved interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M0 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M0 Core Configuration
 * @{
 */

#define __CM0PLUS_REV                  0x0000    /**< Core revision r0p0 */
#define __MPU_PRESENT                  0         /**< Defines if an MPU is present or not */
#define __VTOR_PRESENT                 1         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               2         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */

#include "core_cm0plus.h"              /* Core Peripheral Access Layer */
#include "system_MKL28Z7.h"            /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #pragma push
  #pragma anon_unions
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC1[2];                            /**< ADC Status and Control Registers 1, array offset: 0x0, array step: 0x4 */
  __IO uint32_t CFG1;                              /**< ADC Configuration Register 1, offset: 0x8 */
  __IO uint32_t CFG2;                              /**< ADC Configuration Register 2, offset: 0xC */
  __I  uint32_t R[2];                              /**< ADC Data Result Register, array offset: 0x10, array step: 0x4 */
  __IO uint32_t CV1;                               /**< Compare Value Registers, offset: 0x18 */
  __IO uint32_t CV2;                               /**< Compare Value Registers, offset: 0x1C */
  __IO uint32_t SC2;                               /**< Status and Control Register 2, offset: 0x20 */
  __IO uint32_t SC3;                               /**< Status and Control Register 3, offset: 0x24 */
  __IO uint32_t OFS;                               /**< ADC Offset Correction Register, offset: 0x28 */
  __IO uint32_t PG;                                /**< ADC Plus-Side Gain Register, offset: 0x2C */
  __IO uint32_t MG;                                /**< ADC Minus-Side Gain Register, offset: 0x30 */
  __IO uint32_t CLPD;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x34 */
  __IO uint32_t CLPS;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x38 */
  __IO uint32_t CLP4;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x3C */
  __IO uint32_t CLP3;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x40 */
  __IO uint32_t CLP2;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x44 */
  __IO uint32_t CLP1;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x48 */
  __IO uint32_t CLP0;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x4C */
       uint8_t RESERVED_0[4];
  __IO uint32_t CLMD;                              /**< ADC Minus-Side General Calibration Value Register, offset: 0x54 */
  __IO uint32_t CLMS;                              /**< ADC Minus-Side General Calibration Value Register, offset: 0x58 */
  __IO uint32_t CLM4;                              /**< ADC Minus-Side General Calibration Value Register, offset: 0x5C */
  __IO uint32_t CLM3;                              /**< ADC Minus-Side General Calibration Value Register, offset: 0x60 */
  __IO uint32_t CLM2;                              /**< ADC Minus-Side General Calibration Value Register, offset: 0x64 */
  __IO uint32_t CLM1;                              /**< ADC Minus-Side General Calibration Value Register, offset: 0x68 */
  __IO uint32_t CLM0;                              /**< ADC Minus-Side General Calibration Value Register, offset: 0x6C */
} ADC_Type, *ADC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros
 * @{
 */


/* ADC - Register accessors */
#define ADC_SC1_REG(base,index)                  ((base)->SC1[index])
#define ADC_SC1_COUNT                            2
#define ADC_CFG1_REG(base)                       ((base)->CFG1)
#define ADC_CFG2_REG(base)                       ((base)->CFG2)
#define ADC_R_REG(base,index)                    ((base)->R[index])
#define ADC_R_COUNT                              2
#define ADC_CV1_REG(base)                        ((base)->CV1)
#define ADC_CV2_REG(base)                        ((base)->CV2)
#define ADC_SC2_REG(base)                        ((base)->SC2)
#define ADC_SC3_REG(base)                        ((base)->SC3)
#define ADC_OFS_REG(base)                        ((base)->OFS)
#define ADC_PG_REG(base)                         ((base)->PG)
#define ADC_MG_REG(base)                         ((base)->MG)
#define ADC_CLPD_REG(base)                       ((base)->CLPD)
#define ADC_CLPS_REG(base)                       ((base)->CLPS)
#define ADC_CLP4_REG(base)                       ((base)->CLP4)
#define ADC_CLP3_REG(base)                       ((base)->CLP3)
#define ADC_CLP2_REG(base)                       ((base)->CLP2)
#define ADC_CLP1_REG(base)                       ((base)->CLP1)
#define ADC_CLP0_REG(base)                       ((base)->CLP0)
#define ADC_CLMD_REG(base)                       ((base)->CLMD)
#define ADC_CLMS_REG(base)                       ((base)->CLMS)
#define ADC_CLM4_REG(base)                       ((base)->CLM4)
#define ADC_CLM3_REG(base)                       ((base)->CLM3)
#define ADC_CLM2_REG(base)                       ((base)->CLM2)
#define ADC_CLM1_REG(base)                       ((base)->CLM1)
#define ADC_CLM0_REG(base)                       ((base)->CLM0)

/*!
 * @}
 */ /* end of group ADC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/* SC1 Bit Fields */
#define ADC_SC1_ADCH_MASK                        0x1Fu
#define ADC_SC1_ADCH_SHIFT                       0
#define ADC_SC1_ADCH_WIDTH                       5
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_ADCH_SHIFT))&ADC_SC1_ADCH_MASK)
#define ADC_SC1_DIFF_MASK                        0x20u
#define ADC_SC1_DIFF_SHIFT                       5
#define ADC_SC1_DIFF_WIDTH                       1
#define ADC_SC1_DIFF(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_DIFF_SHIFT))&ADC_SC1_DIFF_MASK)
#define ADC_SC1_AIEN_MASK                        0x40u
#define ADC_SC1_AIEN_SHIFT                       6
#define ADC_SC1_AIEN_WIDTH                       1
#define ADC_SC1_AIEN(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_AIEN_SHIFT))&ADC_SC1_AIEN_MASK)
#define ADC_SC1_COCO_MASK                        0x80u
#define ADC_SC1_COCO_SHIFT                       7
#define ADC_SC1_COCO_WIDTH                       1
#define ADC_SC1_COCO(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_COCO_SHIFT))&ADC_SC1_COCO_MASK)
/* CFG1 Bit Fields */
#define ADC_CFG1_ADICLK_MASK                     0x3u
#define ADC_CFG1_ADICLK_SHIFT                    0
#define ADC_CFG1_ADICLK_WIDTH                    2
#define ADC_CFG1_ADICLK(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADICLK_SHIFT))&ADC_CFG1_ADICLK_MASK)
#define ADC_CFG1_MODE_MASK                       0xCu
#define ADC_CFG1_MODE_SHIFT                      2
#define ADC_CFG1_MODE_WIDTH                      2
#define ADC_CFG1_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_MODE_SHIFT))&ADC_CFG1_MODE_MASK)
#define ADC_CFG1_ADLSMP_MASK                     0x10u
#define ADC_CFG1_ADLSMP_SHIFT                    4
#define ADC_CFG1_ADLSMP_WIDTH                    1
#define ADC_CFG1_ADLSMP(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADLSMP_SHIFT))&ADC_CFG1_ADLSMP_MASK)
#define ADC_CFG1_ADIV_MASK                       0x60u
#define ADC_CFG1_ADIV_SHIFT                      5
#define ADC_CFG1_ADIV_WIDTH                      2
#define ADC_CFG1_ADIV(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADIV_SHIFT))&ADC_CFG1_ADIV_MASK)
#define ADC_CFG1_ADLPC_MASK                      0x80u
#define ADC_CFG1_ADLPC_SHIFT                     7
#define ADC_CFG1_ADLPC_WIDTH                     1
#define ADC_CFG1_ADLPC(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADLPC_SHIFT))&ADC_CFG1_ADLPC_MASK)
/* CFG2 Bit Fields */
#define ADC_CFG2_ADLSTS_MASK                     0x3u
#define ADC_CFG2_ADLSTS_SHIFT                    0
#define ADC_CFG2_ADLSTS_WIDTH                    2
#define ADC_CFG2_ADLSTS(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADLSTS_SHIFT))&ADC_CFG2_ADLSTS_MASK)
#define ADC_CFG2_ADHSC_MASK                      0x4u
#define ADC_CFG2_ADHSC_SHIFT                     2
#define ADC_CFG2_ADHSC_WIDTH                     1
#define ADC_CFG2_ADHSC(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADHSC_SHIFT))&ADC_CFG2_ADHSC_MASK)
#define ADC_CFG2_ADACKEN_MASK                    0x8u
#define ADC_CFG2_ADACKEN_SHIFT                   3
#define ADC_CFG2_ADACKEN_WIDTH                   1
#define ADC_CFG2_ADACKEN(x)                      (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADACKEN_SHIFT))&ADC_CFG2_ADACKEN_MASK)
#define ADC_CFG2_MUXSEL_MASK                     0x10u
#define ADC_CFG2_MUXSEL_SHIFT                    4
#define ADC_CFG2_MUXSEL_WIDTH                    1
#define ADC_CFG2_MUXSEL(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_MUXSEL_SHIFT))&ADC_CFG2_MUXSEL_MASK)
/* R Bit Fields */
#define ADC_R_D_MASK                             0xFFFFu
#define ADC_R_D_SHIFT                            0
#define ADC_R_D_WIDTH                            16
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x))<<ADC_R_D_SHIFT))&ADC_R_D_MASK)
/* CV1 Bit Fields */
#define ADC_CV1_CV_MASK                          0xFFFFu
#define ADC_CV1_CV_SHIFT                         0
#define ADC_CV1_CV_WIDTH                         16
#define ADC_CV1_CV(x)                            (((uint32_t)(((uint32_t)(x))<<ADC_CV1_CV_SHIFT))&ADC_CV1_CV_MASK)
/* CV2 Bit Fields */
#define ADC_CV2_CV_MASK                          0xFFFFu
#define ADC_CV2_CV_SHIFT                         0
#define ADC_CV2_CV_WIDTH                         16
#define ADC_CV2_CV(x)                            (((uint32_t)(((uint32_t)(x))<<ADC_CV2_CV_SHIFT))&ADC_CV2_CV_MASK)
/* SC2 Bit Fields */
#define ADC_SC2_REFSEL_MASK                      0x3u
#define ADC_SC2_REFSEL_SHIFT                     0
#define ADC_SC2_REFSEL_WIDTH                     2
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC2_REFSEL_SHIFT))&ADC_SC2_REFSEL_MASK)
#define ADC_SC2_DMAEN_MASK                       0x4u
#define ADC_SC2_DMAEN_SHIFT                      2
#define ADC_SC2_DMAEN_WIDTH                      1
#define ADC_SC2_DMAEN(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_DMAEN_SHIFT))&ADC_SC2_DMAEN_MASK)
#define ADC_SC2_ACREN_MASK                       0x8u
#define ADC_SC2_ACREN_SHIFT                      3
#define ADC_SC2_ACREN_WIDTH                      1
#define ADC_SC2_ACREN(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACREN_SHIFT))&ADC_SC2_ACREN_MASK)
#define ADC_SC2_ACFGT_MASK                       0x10u
#define ADC_SC2_ACFGT_SHIFT                      4
#define ADC_SC2_ACFGT_WIDTH                      1
#define ADC_SC2_ACFGT(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACFGT_SHIFT))&ADC_SC2_ACFGT_MASK)
#define ADC_SC2_ACFE_MASK                        0x20u
#define ADC_SC2_ACFE_SHIFT                       5
#define ADC_SC2_ACFE_WIDTH                       1
#define ADC_SC2_ACFE(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACFE_SHIFT))&ADC_SC2_ACFE_MASK)
#define ADC_SC2_ADTRG_MASK                       0x40u
#define ADC_SC2_ADTRG_SHIFT                      6
#define ADC_SC2_ADTRG_WIDTH                      1
#define ADC_SC2_ADTRG(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ADTRG_SHIFT))&ADC_SC2_ADTRG_MASK)
#define ADC_SC2_ADACT_MASK                       0x80u
#define ADC_SC2_ADACT_SHIFT                      7
#define ADC_SC2_ADACT_WIDTH                      1
#define ADC_SC2_ADACT(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ADACT_SHIFT))&ADC_SC2_ADACT_MASK)
/* SC3 Bit Fields */
#define ADC_SC3_AVGS_MASK                        0x3u
#define ADC_SC3_AVGS_SHIFT                       0
#define ADC_SC3_AVGS_WIDTH                       2
#define ADC_SC3_AVGS(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGS_SHIFT))&ADC_SC3_AVGS_MASK)
#define ADC_SC3_AVGE_MASK                        0x4u
#define ADC_SC3_AVGE_SHIFT                       2
#define ADC_SC3_AVGE_WIDTH                       1
#define ADC_SC3_AVGE(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGE_SHIFT))&ADC_SC3_AVGE_MASK)
#define ADC_SC3_ADCO_MASK                        0x8u
#define ADC_SC3_ADCO_SHIFT                       3
#define ADC_SC3_ADCO_WIDTH                       1
#define ADC_SC3_ADCO(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_ADCO_SHIFT))&ADC_SC3_ADCO_MASK)
#define ADC_SC3_CALF_MASK                        0x40u
#define ADC_SC3_CALF_SHIFT                       6
#define ADC_SC3_CALF_WIDTH                       1
#define ADC_SC3_CALF(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_CALF_SHIFT))&ADC_SC3_CALF_MASK)
#define ADC_SC3_CAL_MASK                         0x80u
#define ADC_SC3_CAL_SHIFT                        7
#define ADC_SC3_CAL_WIDTH                        1
#define ADC_SC3_CAL(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_SC3_CAL_SHIFT))&ADC_SC3_CAL_MASK)
/* OFS Bit Fields */
#define ADC_OFS_OFS_MASK                         0xFFFFu
#define ADC_OFS_OFS_SHIFT                        0
#define ADC_OFS_OFS_WIDTH                        16
#define ADC_OFS_OFS(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_OFS_OFS_SHIFT))&ADC_OFS_OFS_MASK)
/* PG Bit Fields */
#define ADC_PG_PG_MASK                           0xFFFFu
#define ADC_PG_PG_SHIFT                          0
#define ADC_PG_PG_WIDTH                          16
#define ADC_PG_PG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_PG_PG_SHIFT))&ADC_PG_PG_MASK)
/* MG Bit Fields */
#define ADC_MG_MG_MASK                           0xFFFFu
#define ADC_MG_MG_SHIFT                          0
#define ADC_MG_MG_WIDTH                          16
#define ADC_MG_MG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_MG_MG_SHIFT))&ADC_MG_MG_MASK)
/* CLPD Bit Fields */
#define ADC_CLPD_CLPD_MASK                       0x3Fu
#define ADC_CLPD_CLPD_SHIFT                      0
#define ADC_CLPD_CLPD_WIDTH                      6
#define ADC_CLPD_CLPD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPD_CLPD_SHIFT))&ADC_CLPD_CLPD_MASK)
/* CLPS Bit Fields */
#define ADC_CLPS_CLPS_MASK                       0x3Fu
#define ADC_CLPS_CLPS_SHIFT                      0
#define ADC_CLPS_CLPS_WIDTH                      6
#define ADC_CLPS_CLPS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPS_CLPS_SHIFT))&ADC_CLPS_CLPS_MASK)
/* CLP4 Bit Fields */
#define ADC_CLP4_CLP4_MASK                       0x3FFu
#define ADC_CLP4_CLP4_SHIFT                      0
#define ADC_CLP4_CLP4_WIDTH                      10
#define ADC_CLP4_CLP4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP4_CLP4_SHIFT))&ADC_CLP4_CLP4_MASK)
/* CLP3 Bit Fields */
#define ADC_CLP3_CLP3_MASK                       0x1FFu
#define ADC_CLP3_CLP3_SHIFT                      0
#define ADC_CLP3_CLP3_WIDTH                      9
#define ADC_CLP3_CLP3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP3_CLP3_SHIFT))&ADC_CLP3_CLP3_MASK)
/* CLP2 Bit Fields */
#define ADC_CLP2_CLP2_MASK                       0xFFu
#define ADC_CLP2_CLP2_SHIFT                      0
#define ADC_CLP2_CLP2_WIDTH                      8
#define ADC_CLP2_CLP2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP2_CLP2_SHIFT))&ADC_CLP2_CLP2_MASK)
/* CLP1 Bit Fields */
#define ADC_CLP1_CLP1_MASK                       0x7Fu
#define ADC_CLP1_CLP1_SHIFT                      0
#define ADC_CLP1_CLP1_WIDTH                      7
#define ADC_CLP1_CLP1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP1_CLP1_SHIFT))&ADC_CLP1_CLP1_MASK)
/* CLP0 Bit Fields */
#define ADC_CLP0_CLP0_MASK                       0x3Fu
#define ADC_CLP0_CLP0_SHIFT                      0
#define ADC_CLP0_CLP0_WIDTH                      6
#define ADC_CLP0_CLP0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP0_CLP0_SHIFT))&ADC_CLP0_CLP0_MASK)
/* CLMD Bit Fields */
#define ADC_CLMD_CLMD_MASK                       0x3Fu
#define ADC_CLMD_CLMD_SHIFT                      0
#define ADC_CLMD_CLMD_WIDTH                      6
#define ADC_CLMD_CLMD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLMD_CLMD_SHIFT))&ADC_CLMD_CLMD_MASK)
/* CLMS Bit Fields */
#define ADC_CLMS_CLMS_MASK                       0x3Fu
#define ADC_CLMS_CLMS_SHIFT                      0
#define ADC_CLMS_CLMS_WIDTH                      6
#define ADC_CLMS_CLMS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLMS_CLMS_SHIFT))&ADC_CLMS_CLMS_MASK)
/* CLM4 Bit Fields */
#define ADC_CLM4_CLM4_MASK                       0x3FFu
#define ADC_CLM4_CLM4_SHIFT                      0
#define ADC_CLM4_CLM4_WIDTH                      10
#define ADC_CLM4_CLM4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM4_CLM4_SHIFT))&ADC_CLM4_CLM4_MASK)
/* CLM3 Bit Fields */
#define ADC_CLM3_CLM3_MASK                       0x1FFu
#define ADC_CLM3_CLM3_SHIFT                      0
#define ADC_CLM3_CLM3_WIDTH                      9
#define ADC_CLM3_CLM3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM3_CLM3_SHIFT))&ADC_CLM3_CLM3_MASK)
/* CLM2 Bit Fields */
#define ADC_CLM2_CLM2_MASK                       0xFFu
#define ADC_CLM2_CLM2_SHIFT                      0
#define ADC_CLM2_CLM2_WIDTH                      8
#define ADC_CLM2_CLM2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM2_CLM2_SHIFT))&ADC_CLM2_CLM2_MASK)
/* CLM1 Bit Fields */
#define ADC_CLM1_CLM1_MASK                       0x7Fu
#define ADC_CLM1_CLM1_SHIFT                      0
#define ADC_CLM1_CLM1_WIDTH                      7
#define ADC_CLM1_CLM1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM1_CLM1_SHIFT))&ADC_CLM1_CLM1_MASK)
/* CLM0 Bit Fields */
#define ADC_CLM0_CLM0_MASK                       0x3Fu
#define ADC_CLM0_CLM0_SHIFT                      0
#define ADC_CLM0_CLM0_WIDTH                      6
#define ADC_CLM0_CLM0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM0_CLM0_SHIFT))&ADC_CLM0_CLM0_MASK)

/*!
 * @}
 */ /* end of group ADC_Register_Masks */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x40066000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
#define ADC0_BASE_PTR                            (ADC0)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC0_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0 }

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros
 * @{
 */


/* ADC - Register instance definitions */
/* ADC0 */
#define ADC0_SC1A                                ADC_SC1_REG(ADC0,0)
#define ADC0_SC1B                                ADC_SC1_REG(ADC0,1)
#define ADC0_CFG1                                ADC_CFG1_REG(ADC0)
#define ADC0_CFG2                                ADC_CFG2_REG(ADC0)
#define ADC0_RA                                  ADC_R_REG(ADC0,0)
#define ADC0_RB                                  ADC_R_REG(ADC0,1)
#define ADC0_CV1                                 ADC_CV1_REG(ADC0)
#define ADC0_CV2                                 ADC_CV2_REG(ADC0)
#define ADC0_SC2                                 ADC_SC2_REG(ADC0)
#define ADC0_SC3                                 ADC_SC3_REG(ADC0)
#define ADC0_OFS                                 ADC_OFS_REG(ADC0)
#define ADC0_PG                                  ADC_PG_REG(ADC0)
#define ADC0_MG                                  ADC_MG_REG(ADC0)
#define ADC0_CLPD                                ADC_CLPD_REG(ADC0)
#define ADC0_CLPS                                ADC_CLPS_REG(ADC0)
#define ADC0_CLP4                                ADC_CLP4_REG(ADC0)
#define ADC0_CLP3                                ADC_CLP3_REG(ADC0)
#define ADC0_CLP2                                ADC_CLP2_REG(ADC0)
#define ADC0_CLP1                                ADC_CLP1_REG(ADC0)
#define ADC0_CLP0                                ADC_CLP0_REG(ADC0)
#define ADC0_CLMD                                ADC_CLMD_REG(ADC0)
#define ADC0_CLMS                                ADC_CLMS_REG(ADC0)
#define ADC0_CLM4                                ADC_CLM4_REG(ADC0)
#define ADC0_CLM3                                ADC_CLM3_REG(ADC0)
#define ADC0_CLM2                                ADC_CLM2_REG(ADC0)
#define ADC0_CLM1                                ADC_CLM1_REG(ADC0)
#define ADC0_CLM0                                ADC_CLM0_REG(ADC0)

/* ADC - Register array accessors */
#define ADC0_SC1(index)                          ADC_SC1_REG(ADC0,index)
#define ADC0_R(index)                            ADC_R_REG(ADC0,index)

/*!
 * @}
 */ /* end of group ADC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CAU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAU_Peripheral_Access_Layer CAU Peripheral Access Layer
 * @{
 */

/** CAU - Register Layout Typedef */
typedef struct {
  __O  uint32_t DIRECT[16];                        /**< Direct access register 0..Direct access register 15, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[2048];
  __O  uint32_t LDR_CASR;                          /**< Status register - Load Register command, offset: 0x840 */
  __O  uint32_t LDR_CAA;                           /**< Accumulator register - Load Register command, offset: 0x844 */
  __O  uint32_t LDR_CA[9];                         /**< General Purpose Register 0 - Load Register command..General Purpose Register 8 - Load Register command, array offset: 0x848, array step: 0x4 */
       uint8_t RESERVED_1[20];
  __I  uint32_t STR_CASR;                          /**< Status register - Store Register command, offset: 0x880 */
  __I  uint32_t STR_CAA;                           /**< Accumulator register - Store Register command, offset: 0x884 */
  __I  uint32_t STR_CA[9];                         /**< General Purpose Register 0 - Store Register command..General Purpose Register 8 - Store Register command, array offset: 0x888, array step: 0x4 */
       uint8_t RESERVED_2[20];
  __O  uint32_t ADR_CASR;                          /**< Status register - Add Register command, offset: 0x8C0 */
  __O  uint32_t ADR_CAA;                           /**< Accumulator register - Add to register command, offset: 0x8C4 */
  __O  uint32_t ADR_CA[9];                         /**< General Purpose Register 0 - Add to register command..General Purpose Register 8 - Add to register command, array offset: 0x8C8, array step: 0x4 */
       uint8_t RESERVED_3[20];
  __O  uint32_t RADR_CASR;                         /**< Status register - Reverse and Add to Register command, offset: 0x900 */
  __O  uint32_t RADR_CAA;                          /**< Accumulator register - Reverse and Add to Register command, offset: 0x904 */
  __O  uint32_t RADR_CA[9];                        /**< General Purpose Register 0 - Reverse and Add to Register command..General Purpose Register 8 - Reverse and Add to Register command, array offset: 0x908, array step: 0x4 */
       uint8_t RESERVED_4[84];
  __O  uint32_t XOR_CASR;                          /**< Status register - Exclusive Or command, offset: 0x980 */
  __O  uint32_t XOR_CAA;                           /**< Accumulator register - Exclusive Or command, offset: 0x984 */
  __O  uint32_t XOR_CA[9];                         /**< General Purpose Register 0 - Exclusive Or command..General Purpose Register 8 - Exclusive Or command, array offset: 0x988, array step: 0x4 */
       uint8_t RESERVED_5[20];
  __O  uint32_t ROTL_CASR;                         /**< Status register - Rotate Left command, offset: 0x9C0 */
  __O  uint32_t ROTL_CAA;                          /**< Accumulator register - Rotate Left command, offset: 0x9C4 */
  __O  uint32_t ROTL_CA[9];                        /**< General Purpose Register 0 - Rotate Left command..General Purpose Register 8 - Rotate Left command, array offset: 0x9C8, array step: 0x4 */
       uint8_t RESERVED_6[276];
  __O  uint32_t AESC_CASR;                         /**< Status register - AES Column Operation command, offset: 0xB00 */
  __O  uint32_t AESC_CAA;                          /**< Accumulator register - AES Column Operation command, offset: 0xB04 */
  __O  uint32_t AESC_CA[9];                        /**< General Purpose Register 0 - AES Column Operation command..General Purpose Register 8 - AES Column Operation command, array offset: 0xB08, array step: 0x4 */
       uint8_t RESERVED_7[20];
  __O  uint32_t AESIC_CASR;                        /**< Status register - AES Inverse Column Operation command, offset: 0xB40 */
  __O  uint32_t AESIC_CAA;                         /**< Accumulator register - AES Inverse Column Operation command, offset: 0xB44 */
  __O  uint32_t AESIC_CA[9];                       /**< General Purpose Register 0 - AES Inverse Column Operation command..General Purpose Register 8 - AES Inverse Column Operation command, array offset: 0xB48, array step: 0x4 */
} CAU_Type, *CAU_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CAU - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAU_Register_Accessor_Macros CAU - Register accessor macros
 * @{
 */


/* CAU - Register accessors */
#define CAU_DIRECT_REG(base,index)               ((base)->DIRECT[index])
#define CAU_DIRECT_COUNT                         16
#define CAU_LDR_CASR_REG(base)                   ((base)->LDR_CASR)
#define CAU_LDR_CAA_REG(base)                    ((base)->LDR_CAA)
#define CAU_LDR_CA_REG(base,index)               ((base)->LDR_CA[index])
#define CAU_LDR_CA_COUNT                         9
#define CAU_STR_CASR_REG(base)                   ((base)->STR_CASR)
#define CAU_STR_CAA_REG(base)                    ((base)->STR_CAA)
#define CAU_STR_CA_REG(base,index)               ((base)->STR_CA[index])
#define CAU_STR_CA_COUNT                         9
#define CAU_ADR_CASR_REG(base)                   ((base)->ADR_CASR)
#define CAU_ADR_CAA_REG(base)                    ((base)->ADR_CAA)
#define CAU_ADR_CA_REG(base,index)               ((base)->ADR_CA[index])
#define CAU_ADR_CA_COUNT                         9
#define CAU_RADR_CASR_REG(base)                  ((base)->RADR_CASR)
#define CAU_RADR_CAA_REG(base)                   ((base)->RADR_CAA)
#define CAU_RADR_CA_REG(base,index)              ((base)->RADR_CA[index])
#define CAU_RADR_CA_COUNT                        9
#define CAU_XOR_CASR_REG(base)                   ((base)->XOR_CASR)
#define CAU_XOR_CAA_REG(base)                    ((base)->XOR_CAA)
#define CAU_XOR_CA_REG(base,index)               ((base)->XOR_CA[index])
#define CAU_XOR_CA_COUNT                         9
#define CAU_ROTL_CASR_REG(base)                  ((base)->ROTL_CASR)
#define CAU_ROTL_CAA_REG(base)                   ((base)->ROTL_CAA)
#define CAU_ROTL_CA_REG(base,index)              ((base)->ROTL_CA[index])
#define CAU_ROTL_CA_COUNT                        9
#define CAU_AESC_CASR_REG(base)                  ((base)->AESC_CASR)
#define CAU_AESC_CAA_REG(base)                   ((base)->AESC_CAA)
#define CAU_AESC_CA_REG(base,index)              ((base)->AESC_CA[index])
#define CAU_AESC_CA_COUNT                        9
#define CAU_AESIC_CASR_REG(base)                 ((base)->AESIC_CASR)
#define CAU_AESIC_CAA_REG(base)                  ((base)->AESIC_CAA)
#define CAU_AESIC_CA_REG(base,index)             ((base)->AESIC_CA[index])
#define CAU_AESIC_CA_COUNT                       9

/*!
 * @}
 */ /* end of group CAU_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CAU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAU_Register_Masks CAU Register Masks
 * @{
 */

/* DIRECT Bit Fields */
#define CAU_DIRECT_CAU_DIRECT0_MASK              0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT0_SHIFT             0
#define CAU_DIRECT_CAU_DIRECT0_WIDTH             32
#define CAU_DIRECT_CAU_DIRECT0(x)                (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT0_SHIFT))&CAU_DIRECT_CAU_DIRECT0_MASK)
#define CAU_DIRECT_CAU_DIRECT1_MASK              0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT1_SHIFT             0
#define CAU_DIRECT_CAU_DIRECT1_WIDTH             32
#define CAU_DIRECT_CAU_DIRECT1(x)                (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT1_SHIFT))&CAU_DIRECT_CAU_DIRECT1_MASK)
#define CAU_DIRECT_CAU_DIRECT2_MASK              0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT2_SHIFT             0
#define CAU_DIRECT_CAU_DIRECT2_WIDTH             32
#define CAU_DIRECT_CAU_DIRECT2(x)                (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT2_SHIFT))&CAU_DIRECT_CAU_DIRECT2_MASK)
#define CAU_DIRECT_CAU_DIRECT3_MASK              0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT3_SHIFT             0
#define CAU_DIRECT_CAU_DIRECT3_WIDTH             32
#define CAU_DIRECT_CAU_DIRECT3(x)                (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT3_SHIFT))&CAU_DIRECT_CAU_DIRECT3_MASK)
#define CAU_DIRECT_CAU_DIRECT4_MASK              0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT4_SHIFT             0
#define CAU_DIRECT_CAU_DIRECT4_WIDTH             32
#define CAU_DIRECT_CAU_DIRECT4(x)                (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT4_SHIFT))&CAU_DIRECT_CAU_DIRECT4_MASK)
#define CAU_DIRECT_CAU_DIRECT5_MASK              0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT5_SHIFT             0
#define CAU_DIRECT_CAU_DIRECT5_WIDTH             32
#define CAU_DIRECT_CAU_DIRECT5(x)                (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT5_SHIFT))&CAU_DIRECT_CAU_DIRECT5_MASK)
#define CAU_DIRECT_CAU_DIRECT6_MASK              0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT6_SHIFT             0
#define CAU_DIRECT_CAU_DIRECT6_WIDTH             32
#define CAU_DIRECT_CAU_DIRECT6(x)                (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT6_SHIFT))&CAU_DIRECT_CAU_DIRECT6_MASK)
#define CAU_DIRECT_CAU_DIRECT7_MASK              0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT7_SHIFT             0
#define CAU_DIRECT_CAU_DIRECT7_WIDTH             32
#define CAU_DIRECT_CAU_DIRECT7(x)                (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT7_SHIFT))&CAU_DIRECT_CAU_DIRECT7_MASK)
#define CAU_DIRECT_CAU_DIRECT8_MASK              0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT8_SHIFT             0
#define CAU_DIRECT_CAU_DIRECT8_WIDTH             32
#define CAU_DIRECT_CAU_DIRECT8(x)                (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT8_SHIFT))&CAU_DIRECT_CAU_DIRECT8_MASK)
#define CAU_DIRECT_CAU_DIRECT9_MASK              0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT9_SHIFT             0
#define CAU_DIRECT_CAU_DIRECT9_WIDTH             32
#define CAU_DIRECT_CAU_DIRECT9(x)                (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT9_SHIFT))&CAU_DIRECT_CAU_DIRECT9_MASK)
#define CAU_DIRECT_CAU_DIRECT10_MASK             0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT10_SHIFT            0
#define CAU_DIRECT_CAU_DIRECT10_WIDTH            32
#define CAU_DIRECT_CAU_DIRECT10(x)               (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT10_SHIFT))&CAU_DIRECT_CAU_DIRECT10_MASK)
#define CAU_DIRECT_CAU_DIRECT11_MASK             0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT11_SHIFT            0
#define CAU_DIRECT_CAU_DIRECT11_WIDTH            32
#define CAU_DIRECT_CAU_DIRECT11(x)               (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT11_SHIFT))&CAU_DIRECT_CAU_DIRECT11_MASK)
#define CAU_DIRECT_CAU_DIRECT12_MASK             0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT12_SHIFT            0
#define CAU_DIRECT_CAU_DIRECT12_WIDTH            32
#define CAU_DIRECT_CAU_DIRECT12(x)               (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT12_SHIFT))&CAU_DIRECT_CAU_DIRECT12_MASK)
#define CAU_DIRECT_CAU_DIRECT13_MASK             0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT13_SHIFT            0
#define CAU_DIRECT_CAU_DIRECT13_WIDTH            32
#define CAU_DIRECT_CAU_DIRECT13(x)               (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT13_SHIFT))&CAU_DIRECT_CAU_DIRECT13_MASK)
#define CAU_DIRECT_CAU_DIRECT14_MASK             0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT14_SHIFT            0
#define CAU_DIRECT_CAU_DIRECT14_WIDTH            32
#define CAU_DIRECT_CAU_DIRECT14(x)               (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT14_SHIFT))&CAU_DIRECT_CAU_DIRECT14_MASK)
#define CAU_DIRECT_CAU_DIRECT15_MASK             0xFFFFFFFFu
#define CAU_DIRECT_CAU_DIRECT15_SHIFT            0
#define CAU_DIRECT_CAU_DIRECT15_WIDTH            32
#define CAU_DIRECT_CAU_DIRECT15(x)               (((uint32_t)(((uint32_t)(x))<<CAU_DIRECT_CAU_DIRECT15_SHIFT))&CAU_DIRECT_CAU_DIRECT15_MASK)
/* LDR_CASR Bit Fields */
#define CAU_LDR_CASR_IC_MASK                     0x1u
#define CAU_LDR_CASR_IC_SHIFT                    0
#define CAU_LDR_CASR_IC_WIDTH                    1
#define CAU_LDR_CASR_IC(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CASR_IC_SHIFT))&CAU_LDR_CASR_IC_MASK)
#define CAU_LDR_CASR_DPE_MASK                    0x2u
#define CAU_LDR_CASR_DPE_SHIFT                   1
#define CAU_LDR_CASR_DPE_WIDTH                   1
#define CAU_LDR_CASR_DPE(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CASR_DPE_SHIFT))&CAU_LDR_CASR_DPE_MASK)
#define CAU_LDR_CASR_VER_MASK                    0xF0000000u
#define CAU_LDR_CASR_VER_SHIFT                   28
#define CAU_LDR_CASR_VER_WIDTH                   4
#define CAU_LDR_CASR_VER(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CASR_VER_SHIFT))&CAU_LDR_CASR_VER_MASK)
/* LDR_CAA Bit Fields */
#define CAU_LDR_CAA_ACC_MASK                     0xFFFFFFFFu
#define CAU_LDR_CAA_ACC_SHIFT                    0
#define CAU_LDR_CAA_ACC_WIDTH                    32
#define CAU_LDR_CAA_ACC(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CAA_ACC_SHIFT))&CAU_LDR_CAA_ACC_MASK)
/* LDR_CA Bit Fields */
#define CAU_LDR_CA_CA0_MASK                      0xFFFFFFFFu
#define CAU_LDR_CA_CA0_SHIFT                     0
#define CAU_LDR_CA_CA0_WIDTH                     32
#define CAU_LDR_CA_CA0(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CA_CA0_SHIFT))&CAU_LDR_CA_CA0_MASK)
#define CAU_LDR_CA_CA1_MASK                      0xFFFFFFFFu
#define CAU_LDR_CA_CA1_SHIFT                     0
#define CAU_LDR_CA_CA1_WIDTH                     32
#define CAU_LDR_CA_CA1(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CA_CA1_SHIFT))&CAU_LDR_CA_CA1_MASK)
#define CAU_LDR_CA_CA2_MASK                      0xFFFFFFFFu
#define CAU_LDR_CA_CA2_SHIFT                     0
#define CAU_LDR_CA_CA2_WIDTH                     32
#define CAU_LDR_CA_CA2(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CA_CA2_SHIFT))&CAU_LDR_CA_CA2_MASK)
#define CAU_LDR_CA_CA3_MASK                      0xFFFFFFFFu
#define CAU_LDR_CA_CA3_SHIFT                     0
#define CAU_LDR_CA_CA3_WIDTH                     32
#define CAU_LDR_CA_CA3(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CA_CA3_SHIFT))&CAU_LDR_CA_CA3_MASK)
#define CAU_LDR_CA_CA4_MASK                      0xFFFFFFFFu
#define CAU_LDR_CA_CA4_SHIFT                     0
#define CAU_LDR_CA_CA4_WIDTH                     32
#define CAU_LDR_CA_CA4(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CA_CA4_SHIFT))&CAU_LDR_CA_CA4_MASK)
#define CAU_LDR_CA_CA5_MASK                      0xFFFFFFFFu
#define CAU_LDR_CA_CA5_SHIFT                     0
#define CAU_LDR_CA_CA5_WIDTH                     32
#define CAU_LDR_CA_CA5(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CA_CA5_SHIFT))&CAU_LDR_CA_CA5_MASK)
#define CAU_LDR_CA_CA6_MASK                      0xFFFFFFFFu
#define CAU_LDR_CA_CA6_SHIFT                     0
#define CAU_LDR_CA_CA6_WIDTH                     32
#define CAU_LDR_CA_CA6(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CA_CA6_SHIFT))&CAU_LDR_CA_CA6_MASK)
#define CAU_LDR_CA_CA7_MASK                      0xFFFFFFFFu
#define CAU_LDR_CA_CA7_SHIFT                     0
#define CAU_LDR_CA_CA7_WIDTH                     32
#define CAU_LDR_CA_CA7(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CA_CA7_SHIFT))&CAU_LDR_CA_CA7_MASK)
#define CAU_LDR_CA_CA8_MASK                      0xFFFFFFFFu
#define CAU_LDR_CA_CA8_SHIFT                     0
#define CAU_LDR_CA_CA8_WIDTH                     32
#define CAU_LDR_CA_CA8(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CA_CA8_SHIFT))&CAU_LDR_CA_CA8_MASK)
/* STR_CASR Bit Fields */
#define CAU_STR_CASR_IC_MASK                     0x1u
#define CAU_STR_CASR_IC_SHIFT                    0
#define CAU_STR_CASR_IC_WIDTH                    1
#define CAU_STR_CASR_IC(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_STR_CASR_IC_SHIFT))&CAU_STR_CASR_IC_MASK)
#define CAU_STR_CASR_DPE_MASK                    0x2u
#define CAU_STR_CASR_DPE_SHIFT                   1
#define CAU_STR_CASR_DPE_WIDTH                   1
#define CAU_STR_CASR_DPE(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_STR_CASR_DPE_SHIFT))&CAU_STR_CASR_DPE_MASK)
#define CAU_STR_CASR_VER_MASK                    0xF0000000u
#define CAU_STR_CASR_VER_SHIFT                   28
#define CAU_STR_CASR_VER_WIDTH                   4
#define CAU_STR_CASR_VER(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_STR_CASR_VER_SHIFT))&CAU_STR_CASR_VER_MASK)
/* STR_CAA Bit Fields */
#define CAU_STR_CAA_ACC_MASK                     0xFFFFFFFFu
#define CAU_STR_CAA_ACC_SHIFT                    0
#define CAU_STR_CAA_ACC_WIDTH                    32
#define CAU_STR_CAA_ACC(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_STR_CAA_ACC_SHIFT))&CAU_STR_CAA_ACC_MASK)
/* STR_CA Bit Fields */
#define CAU_STR_CA_CA0_MASK                      0xFFFFFFFFu
#define CAU_STR_CA_CA0_SHIFT                     0
#define CAU_STR_CA_CA0_WIDTH                     32
#define CAU_STR_CA_CA0(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_STR_CA_CA0_SHIFT))&CAU_STR_CA_CA0_MASK)
#define CAU_STR_CA_CA1_MASK                      0xFFFFFFFFu
#define CAU_STR_CA_CA1_SHIFT                     0
#define CAU_STR_CA_CA1_WIDTH                     32
#define CAU_STR_CA_CA1(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_STR_CA_CA1_SHIFT))&CAU_STR_CA_CA1_MASK)
#define CAU_STR_CA_CA2_MASK                      0xFFFFFFFFu
#define CAU_STR_CA_CA2_SHIFT                     0
#define CAU_STR_CA_CA2_WIDTH                     32
#define CAU_STR_CA_CA2(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_STR_CA_CA2_SHIFT))&CAU_STR_CA_CA2_MASK)
#define CAU_STR_CA_CA3_MASK                      0xFFFFFFFFu
#define CAU_STR_CA_CA3_SHIFT                     0
#define CAU_STR_CA_CA3_WIDTH                     32
#define CAU_STR_CA_CA3(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_STR_CA_CA3_SHIFT))&CAU_STR_CA_CA3_MASK)
#define CAU_STR_CA_CA4_MASK                      0xFFFFFFFFu
#define CAU_STR_CA_CA4_SHIFT                     0
#define CAU_STR_CA_CA4_WIDTH                     32
#define CAU_STR_CA_CA4(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_STR_CA_CA4_SHIFT))&CAU_STR_CA_CA4_MASK)
#define CAU_STR_CA_CA5_MASK                      0xFFFFFFFFu
#define CAU_STR_CA_CA5_SHIFT                     0
#define CAU_STR_CA_CA5_WIDTH                     32
#define CAU_STR_CA_CA5(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_STR_CA_CA5_SHIFT))&CAU_STR_CA_CA5_MASK)
#define CAU_STR_CA_CA6_MASK                      0xFFFFFFFFu
#define CAU_STR_CA_CA6_SHIFT                     0
#define CAU_STR_CA_CA6_WIDTH                     32
#define CAU_STR_CA_CA6(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_STR_CA_CA6_SHIFT))&CAU_STR_CA_CA6_MASK)
#define CAU_STR_CA_CA7_MASK                      0xFFFFFFFFu
#define CAU_STR_CA_CA7_SHIFT                     0
#define CAU_STR_CA_CA7_WIDTH                     32
#define CAU_STR_CA_CA7(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_STR_CA_CA7_SHIFT))&CAU_STR_CA_CA7_MASK)
#define CAU_STR_CA_CA8_MASK                      0xFFFFFFFFu
#define CAU_STR_CA_CA8_SHIFT                     0
#define CAU_STR_CA_CA8_WIDTH                     32
#define CAU_STR_CA_CA8(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_STR_CA_CA8_SHIFT))&CAU_STR_CA_CA8_MASK)
/* ADR_CASR Bit Fields */
#define CAU_ADR_CASR_IC_MASK                     0x1u
#define CAU_ADR_CASR_IC_SHIFT                    0
#define CAU_ADR_CASR_IC_WIDTH                    1
#define CAU_ADR_CASR_IC(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CASR_IC_SHIFT))&CAU_ADR_CASR_IC_MASK)
#define CAU_ADR_CASR_DPE_MASK                    0x2u
#define CAU_ADR_CASR_DPE_SHIFT                   1
#define CAU_ADR_CASR_DPE_WIDTH                   1
#define CAU_ADR_CASR_DPE(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CASR_DPE_SHIFT))&CAU_ADR_CASR_DPE_MASK)
#define CAU_ADR_CASR_VER_MASK                    0xF0000000u
#define CAU_ADR_CASR_VER_SHIFT                   28
#define CAU_ADR_CASR_VER_WIDTH                   4
#define CAU_ADR_CASR_VER(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CASR_VER_SHIFT))&CAU_ADR_CASR_VER_MASK)
/* ADR_CAA Bit Fields */
#define CAU_ADR_CAA_ACC_MASK                     0xFFFFFFFFu
#define CAU_ADR_CAA_ACC_SHIFT                    0
#define CAU_ADR_CAA_ACC_WIDTH                    32
#define CAU_ADR_CAA_ACC(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CAA_ACC_SHIFT))&CAU_ADR_CAA_ACC_MASK)
/* ADR_CA Bit Fields */
#define CAU_ADR_CA_CA0_MASK                      0xFFFFFFFFu
#define CAU_ADR_CA_CA0_SHIFT                     0
#define CAU_ADR_CA_CA0_WIDTH                     32
#define CAU_ADR_CA_CA0(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CA_CA0_SHIFT))&CAU_ADR_CA_CA0_MASK)
#define CAU_ADR_CA_CA1_MASK                      0xFFFFFFFFu
#define CAU_ADR_CA_CA1_SHIFT                     0
#define CAU_ADR_CA_CA1_WIDTH                     32
#define CAU_ADR_CA_CA1(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CA_CA1_SHIFT))&CAU_ADR_CA_CA1_MASK)
#define CAU_ADR_CA_CA2_MASK                      0xFFFFFFFFu
#define CAU_ADR_CA_CA2_SHIFT                     0
#define CAU_ADR_CA_CA2_WIDTH                     32
#define CAU_ADR_CA_CA2(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CA_CA2_SHIFT))&CAU_ADR_CA_CA2_MASK)
#define CAU_ADR_CA_CA3_MASK                      0xFFFFFFFFu
#define CAU_ADR_CA_CA3_SHIFT                     0
#define CAU_ADR_CA_CA3_WIDTH                     32
#define CAU_ADR_CA_CA3(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CA_CA3_SHIFT))&CAU_ADR_CA_CA3_MASK)
#define CAU_ADR_CA_CA4_MASK                      0xFFFFFFFFu
#define CAU_ADR_CA_CA4_SHIFT                     0
#define CAU_ADR_CA_CA4_WIDTH                     32
#define CAU_ADR_CA_CA4(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CA_CA4_SHIFT))&CAU_ADR_CA_CA4_MASK)
#define CAU_ADR_CA_CA5_MASK                      0xFFFFFFFFu
#define CAU_ADR_CA_CA5_SHIFT                     0
#define CAU_ADR_CA_CA5_WIDTH                     32
#define CAU_ADR_CA_CA5(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CA_CA5_SHIFT))&CAU_ADR_CA_CA5_MASK)
#define CAU_ADR_CA_CA6_MASK                      0xFFFFFFFFu
#define CAU_ADR_CA_CA6_SHIFT                     0
#define CAU_ADR_CA_CA6_WIDTH                     32
#define CAU_ADR_CA_CA6(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CA_CA6_SHIFT))&CAU_ADR_CA_CA6_MASK)
#define CAU_ADR_CA_CA7_MASK                      0xFFFFFFFFu
#define CAU_ADR_CA_CA7_SHIFT                     0
#define CAU_ADR_CA_CA7_WIDTH                     32
#define CAU_ADR_CA_CA7(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CA_CA7_SHIFT))&CAU_ADR_CA_CA7_MASK)
#define CAU_ADR_CA_CA8_MASK                      0xFFFFFFFFu
#define CAU_ADR_CA_CA8_SHIFT                     0
#define CAU_ADR_CA_CA8_WIDTH                     32
#define CAU_ADR_CA_CA8(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CA_CA8_SHIFT))&CAU_ADR_CA_CA8_MASK)
/* RADR_CASR Bit Fields */
#define CAU_RADR_CASR_IC_MASK                    0x1u
#define CAU_RADR_CASR_IC_SHIFT                   0
#define CAU_RADR_CASR_IC_WIDTH                   1
#define CAU_RADR_CASR_IC(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CASR_IC_SHIFT))&CAU_RADR_CASR_IC_MASK)
#define CAU_RADR_CASR_DPE_MASK                   0x2u
#define CAU_RADR_CASR_DPE_SHIFT                  1
#define CAU_RADR_CASR_DPE_WIDTH                  1
#define CAU_RADR_CASR_DPE(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CASR_DPE_SHIFT))&CAU_RADR_CASR_DPE_MASK)
#define CAU_RADR_CASR_VER_MASK                   0xF0000000u
#define CAU_RADR_CASR_VER_SHIFT                  28
#define CAU_RADR_CASR_VER_WIDTH                  4
#define CAU_RADR_CASR_VER(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CASR_VER_SHIFT))&CAU_RADR_CASR_VER_MASK)
/* RADR_CAA Bit Fields */
#define CAU_RADR_CAA_ACC_MASK                    0xFFFFFFFFu
#define CAU_RADR_CAA_ACC_SHIFT                   0
#define CAU_RADR_CAA_ACC_WIDTH                   32
#define CAU_RADR_CAA_ACC(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CAA_ACC_SHIFT))&CAU_RADR_CAA_ACC_MASK)
/* RADR_CA Bit Fields */
#define CAU_RADR_CA_CA0_MASK                     0xFFFFFFFFu
#define CAU_RADR_CA_CA0_SHIFT                    0
#define CAU_RADR_CA_CA0_WIDTH                    32
#define CAU_RADR_CA_CA0(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CA_CA0_SHIFT))&CAU_RADR_CA_CA0_MASK)
#define CAU_RADR_CA_CA1_MASK                     0xFFFFFFFFu
#define CAU_RADR_CA_CA1_SHIFT                    0
#define CAU_RADR_CA_CA1_WIDTH                    32
#define CAU_RADR_CA_CA1(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CA_CA1_SHIFT))&CAU_RADR_CA_CA1_MASK)
#define CAU_RADR_CA_CA2_MASK                     0xFFFFFFFFu
#define CAU_RADR_CA_CA2_SHIFT                    0
#define CAU_RADR_CA_CA2_WIDTH                    32
#define CAU_RADR_CA_CA2(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CA_CA2_SHIFT))&CAU_RADR_CA_CA2_MASK)
#define CAU_RADR_CA_CA3_MASK                     0xFFFFFFFFu
#define CAU_RADR_CA_CA3_SHIFT                    0
#define CAU_RADR_CA_CA3_WIDTH                    32
#define CAU_RADR_CA_CA3(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CA_CA3_SHIFT))&CAU_RADR_CA_CA3_MASK)
#define CAU_RADR_CA_CA4_MASK                     0xFFFFFFFFu
#define CAU_RADR_CA_CA4_SHIFT                    0
#define CAU_RADR_CA_CA4_WIDTH                    32
#define CAU_RADR_CA_CA4(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CA_CA4_SHIFT))&CAU_RADR_CA_CA4_MASK)
#define CAU_RADR_CA_CA5_MASK                     0xFFFFFFFFu
#define CAU_RADR_CA_CA5_SHIFT                    0
#define CAU_RADR_CA_CA5_WIDTH                    32
#define CAU_RADR_CA_CA5(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CA_CA5_SHIFT))&CAU_RADR_CA_CA5_MASK)
#define CAU_RADR_CA_CA6_MASK                     0xFFFFFFFFu
#define CAU_RADR_CA_CA6_SHIFT                    0
#define CAU_RADR_CA_CA6_WIDTH                    32
#define CAU_RADR_CA_CA6(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CA_CA6_SHIFT))&CAU_RADR_CA_CA6_MASK)
#define CAU_RADR_CA_CA7_MASK                     0xFFFFFFFFu
#define CAU_RADR_CA_CA7_SHIFT                    0
#define CAU_RADR_CA_CA7_WIDTH                    32
#define CAU_RADR_CA_CA7(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CA_CA7_SHIFT))&CAU_RADR_CA_CA7_MASK)
#define CAU_RADR_CA_CA8_MASK                     0xFFFFFFFFu
#define CAU_RADR_CA_CA8_SHIFT                    0
#define CAU_RADR_CA_CA8_WIDTH                    32
#define CAU_RADR_CA_CA8(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CA_CA8_SHIFT))&CAU_RADR_CA_CA8_MASK)
/* XOR_CASR Bit Fields */
#define CAU_XOR_CASR_IC_MASK                     0x1u
#define CAU_XOR_CASR_IC_SHIFT                    0
#define CAU_XOR_CASR_IC_WIDTH                    1
#define CAU_XOR_CASR_IC(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CASR_IC_SHIFT))&CAU_XOR_CASR_IC_MASK)
#define CAU_XOR_CASR_DPE_MASK                    0x2u
#define CAU_XOR_CASR_DPE_SHIFT                   1
#define CAU_XOR_CASR_DPE_WIDTH                   1
#define CAU_XOR_CASR_DPE(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CASR_DPE_SHIFT))&CAU_XOR_CASR_DPE_MASK)
#define CAU_XOR_CASR_VER_MASK                    0xF0000000u
#define CAU_XOR_CASR_VER_SHIFT                   28
#define CAU_XOR_CASR_VER_WIDTH                   4
#define CAU_XOR_CASR_VER(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CASR_VER_SHIFT))&CAU_XOR_CASR_VER_MASK)
/* XOR_CAA Bit Fields */
#define CAU_XOR_CAA_ACC_MASK                     0xFFFFFFFFu
#define CAU_XOR_CAA_ACC_SHIFT                    0
#define CAU_XOR_CAA_ACC_WIDTH                    32
#define CAU_XOR_CAA_ACC(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CAA_ACC_SHIFT))&CAU_XOR_CAA_ACC_MASK)
/* XOR_CA Bit Fields */
#define CAU_XOR_CA_CA0_MASK                      0xFFFFFFFFu
#define CAU_XOR_CA_CA0_SHIFT                     0
#define CAU_XOR_CA_CA0_WIDTH                     32
#define CAU_XOR_CA_CA0(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CA_CA0_SHIFT))&CAU_XOR_CA_CA0_MASK)
#define CAU_XOR_CA_CA1_MASK                      0xFFFFFFFFu
#define CAU_XOR_CA_CA1_SHIFT                     0
#define CAU_XOR_CA_CA1_WIDTH                     32
#define CAU_XOR_CA_CA1(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CA_CA1_SHIFT))&CAU_XOR_CA_CA1_MASK)
#define CAU_XOR_CA_CA2_MASK                      0xFFFFFFFFu
#define CAU_XOR_CA_CA2_SHIFT                     0
#define CAU_XOR_CA_CA2_WIDTH                     32
#define CAU_XOR_CA_CA2(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CA_CA2_SHIFT))&CAU_XOR_CA_CA2_MASK)
#define CAU_XOR_CA_CA3_MASK                      0xFFFFFFFFu
#define CAU_XOR_CA_CA3_SHIFT                     0
#define CAU_XOR_CA_CA3_WIDTH                     32
#define CAU_XOR_CA_CA3(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CA_CA3_SHIFT))&CAU_XOR_CA_CA3_MASK)
#define CAU_XOR_CA_CA4_MASK                      0xFFFFFFFFu
#define CAU_XOR_CA_CA4_SHIFT                     0
#define CAU_XOR_CA_CA4_WIDTH                     32
#define CAU_XOR_CA_CA4(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CA_CA4_SHIFT))&CAU_XOR_CA_CA4_MASK)
#define CAU_XOR_CA_CA5_MASK                      0xFFFFFFFFu
#define CAU_XOR_CA_CA5_SHIFT                     0
#define CAU_XOR_CA_CA5_WIDTH                     32
#define CAU_XOR_CA_CA5(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CA_CA5_SHIFT))&CAU_XOR_CA_CA5_MASK)
#define CAU_XOR_CA_CA6_MASK                      0xFFFFFFFFu
#define CAU_XOR_CA_CA6_SHIFT                     0
#define CAU_XOR_CA_CA6_WIDTH                     32
#define CAU_XOR_CA_CA6(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CA_CA6_SHIFT))&CAU_XOR_CA_CA6_MASK)
#define CAU_XOR_CA_CA7_MASK                      0xFFFFFFFFu
#define CAU_XOR_CA_CA7_SHIFT                     0
#define CAU_XOR_CA_CA7_WIDTH                     32
#define CAU_XOR_CA_CA7(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CA_CA7_SHIFT))&CAU_XOR_CA_CA7_MASK)
#define CAU_XOR_CA_CA8_MASK                      0xFFFFFFFFu
#define CAU_XOR_CA_CA8_SHIFT                     0
#define CAU_XOR_CA_CA8_WIDTH                     32
#define CAU_XOR_CA_CA8(x)                        (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CA_CA8_SHIFT))&CAU_XOR_CA_CA8_MASK)
/* ROTL_CASR Bit Fields */
#define CAU_ROTL_CASR_IC_MASK                    0x1u
#define CAU_ROTL_CASR_IC_SHIFT                   0
#define CAU_ROTL_CASR_IC_WIDTH                   1
#define CAU_ROTL_CASR_IC(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CASR_IC_SHIFT))&CAU_ROTL_CASR_IC_MASK)
#define CAU_ROTL_CASR_DPE_MASK                   0x2u
#define CAU_ROTL_CASR_DPE_SHIFT                  1
#define CAU_ROTL_CASR_DPE_WIDTH                  1
#define CAU_ROTL_CASR_DPE(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CASR_DPE_SHIFT))&CAU_ROTL_CASR_DPE_MASK)
#define CAU_ROTL_CASR_VER_MASK                   0xF0000000u
#define CAU_ROTL_CASR_VER_SHIFT                  28
#define CAU_ROTL_CASR_VER_WIDTH                  4
#define CAU_ROTL_CASR_VER(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CASR_VER_SHIFT))&CAU_ROTL_CASR_VER_MASK)
/* ROTL_CAA Bit Fields */
#define CAU_ROTL_CAA_ACC_MASK                    0xFFFFFFFFu
#define CAU_ROTL_CAA_ACC_SHIFT                   0
#define CAU_ROTL_CAA_ACC_WIDTH                   32
#define CAU_ROTL_CAA_ACC(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CAA_ACC_SHIFT))&CAU_ROTL_CAA_ACC_MASK)
/* ROTL_CA Bit Fields */
#define CAU_ROTL_CA_CA0_MASK                     0xFFFFFFFFu
#define CAU_ROTL_CA_CA0_SHIFT                    0
#define CAU_ROTL_CA_CA0_WIDTH                    32
#define CAU_ROTL_CA_CA0(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CA_CA0_SHIFT))&CAU_ROTL_CA_CA0_MASK)
#define CAU_ROTL_CA_CA1_MASK                     0xFFFFFFFFu
#define CAU_ROTL_CA_CA1_SHIFT                    0
#define CAU_ROTL_CA_CA1_WIDTH                    32
#define CAU_ROTL_CA_CA1(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CA_CA1_SHIFT))&CAU_ROTL_CA_CA1_MASK)
#define CAU_ROTL_CA_CA2_MASK                     0xFFFFFFFFu
#define CAU_ROTL_CA_CA2_SHIFT                    0
#define CAU_ROTL_CA_CA2_WIDTH                    32
#define CAU_ROTL_CA_CA2(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CA_CA2_SHIFT))&CAU_ROTL_CA_CA2_MASK)
#define CAU_ROTL_CA_CA3_MASK                     0xFFFFFFFFu
#define CAU_ROTL_CA_CA3_SHIFT                    0
#define CAU_ROTL_CA_CA3_WIDTH                    32
#define CAU_ROTL_CA_CA3(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CA_CA3_SHIFT))&CAU_ROTL_CA_CA3_MASK)
#define CAU_ROTL_CA_CA4_MASK                     0xFFFFFFFFu
#define CAU_ROTL_CA_CA4_SHIFT                    0
#define CAU_ROTL_CA_CA4_WIDTH                    32
#define CAU_ROTL_CA_CA4(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CA_CA4_SHIFT))&CAU_ROTL_CA_CA4_MASK)
#define CAU_ROTL_CA_CA5_MASK                     0xFFFFFFFFu
#define CAU_ROTL_CA_CA5_SHIFT                    0
#define CAU_ROTL_CA_CA5_WIDTH                    32
#define CAU_ROTL_CA_CA5(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CA_CA5_SHIFT))&CAU_ROTL_CA_CA5_MASK)
#define CAU_ROTL_CA_CA6_MASK                     0xFFFFFFFFu
#define CAU_ROTL_CA_CA6_SHIFT                    0
#define CAU_ROTL_CA_CA6_WIDTH                    32
#define CAU_ROTL_CA_CA6(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CA_CA6_SHIFT))&CAU_ROTL_CA_CA6_MASK)
#define CAU_ROTL_CA_CA7_MASK                     0xFFFFFFFFu
#define CAU_ROTL_CA_CA7_SHIFT                    0
#define CAU_ROTL_CA_CA7_WIDTH                    32
#define CAU_ROTL_CA_CA7(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CA_CA7_SHIFT))&CAU_ROTL_CA_CA7_MASK)
#define CAU_ROTL_CA_CA8_MASK                     0xFFFFFFFFu
#define CAU_ROTL_CA_CA8_SHIFT                    0
#define CAU_ROTL_CA_CA8_WIDTH                    32
#define CAU_ROTL_CA_CA8(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CA_CA8_SHIFT))&CAU_ROTL_CA_CA8_MASK)
/* AESC_CASR Bit Fields */
#define CAU_AESC_CASR_IC_MASK                    0x1u
#define CAU_AESC_CASR_IC_SHIFT                   0
#define CAU_AESC_CASR_IC_WIDTH                   1
#define CAU_AESC_CASR_IC(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CASR_IC_SHIFT))&CAU_AESC_CASR_IC_MASK)
#define CAU_AESC_CASR_DPE_MASK                   0x2u
#define CAU_AESC_CASR_DPE_SHIFT                  1
#define CAU_AESC_CASR_DPE_WIDTH                  1
#define CAU_AESC_CASR_DPE(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CASR_DPE_SHIFT))&CAU_AESC_CASR_DPE_MASK)
#define CAU_AESC_CASR_VER_MASK                   0xF0000000u
#define CAU_AESC_CASR_VER_SHIFT                  28
#define CAU_AESC_CASR_VER_WIDTH                  4
#define CAU_AESC_CASR_VER(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CASR_VER_SHIFT))&CAU_AESC_CASR_VER_MASK)
/* AESC_CAA Bit Fields */
#define CAU_AESC_CAA_ACC_MASK                    0xFFFFFFFFu
#define CAU_AESC_CAA_ACC_SHIFT                   0
#define CAU_AESC_CAA_ACC_WIDTH                   32
#define CAU_AESC_CAA_ACC(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CAA_ACC_SHIFT))&CAU_AESC_CAA_ACC_MASK)
/* AESC_CA Bit Fields */
#define CAU_AESC_CA_CA0_MASK                     0xFFFFFFFFu
#define CAU_AESC_CA_CA0_SHIFT                    0
#define CAU_AESC_CA_CA0_WIDTH                    32
#define CAU_AESC_CA_CA0(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CA_CA0_SHIFT))&CAU_AESC_CA_CA0_MASK)
#define CAU_AESC_CA_CA1_MASK                     0xFFFFFFFFu
#define CAU_AESC_CA_CA1_SHIFT                    0
#define CAU_AESC_CA_CA1_WIDTH                    32
#define CAU_AESC_CA_CA1(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CA_CA1_SHIFT))&CAU_AESC_CA_CA1_MASK)
#define CAU_AESC_CA_CA2_MASK                     0xFFFFFFFFu
#define CAU_AESC_CA_CA2_SHIFT                    0
#define CAU_AESC_CA_CA2_WIDTH                    32
#define CAU_AESC_CA_CA2(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CA_CA2_SHIFT))&CAU_AESC_CA_CA2_MASK)
#define CAU_AESC_CA_CA3_MASK                     0xFFFFFFFFu
#define CAU_AESC_CA_CA3_SHIFT                    0
#define CAU_AESC_CA_CA3_WIDTH                    32
#define CAU_AESC_CA_CA3(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CA_CA3_SHIFT))&CAU_AESC_CA_CA3_MASK)
#define CAU_AESC_CA_CA4_MASK                     0xFFFFFFFFu
#define CAU_AESC_CA_CA4_SHIFT                    0
#define CAU_AESC_CA_CA4_WIDTH                    32
#define CAU_AESC_CA_CA4(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CA_CA4_SHIFT))&CAU_AESC_CA_CA4_MASK)
#define CAU_AESC_CA_CA5_MASK                     0xFFFFFFFFu
#define CAU_AESC_CA_CA5_SHIFT                    0
#define CAU_AESC_CA_CA5_WIDTH                    32
#define CAU_AESC_CA_CA5(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CA_CA5_SHIFT))&CAU_AESC_CA_CA5_MASK)
#define CAU_AESC_CA_CA6_MASK                     0xFFFFFFFFu
#define CAU_AESC_CA_CA6_SHIFT                    0
#define CAU_AESC_CA_CA6_WIDTH                    32
#define CAU_AESC_CA_CA6(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CA_CA6_SHIFT))&CAU_AESC_CA_CA6_MASK)
#define CAU_AESC_CA_CA7_MASK                     0xFFFFFFFFu
#define CAU_AESC_CA_CA7_SHIFT                    0
#define CAU_AESC_CA_CA7_WIDTH                    32
#define CAU_AESC_CA_CA7(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CA_CA7_SHIFT))&CAU_AESC_CA_CA7_MASK)
#define CAU_AESC_CA_CA8_MASK                     0xFFFFFFFFu
#define CAU_AESC_CA_CA8_SHIFT                    0
#define CAU_AESC_CA_CA8_WIDTH                    32
#define CAU_AESC_CA_CA8(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CA_CA8_SHIFT))&CAU_AESC_CA_CA8_MASK)
/* AESIC_CASR Bit Fields */
#define CAU_AESIC_CASR_IC_MASK                   0x1u
#define CAU_AESIC_CASR_IC_SHIFT                  0
#define CAU_AESIC_CASR_IC_WIDTH                  1
#define CAU_AESIC_CASR_IC(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CASR_IC_SHIFT))&CAU_AESIC_CASR_IC_MASK)
#define CAU_AESIC_CASR_DPE_MASK                  0x2u
#define CAU_AESIC_CASR_DPE_SHIFT                 1
#define CAU_AESIC_CASR_DPE_WIDTH                 1
#define CAU_AESIC_CASR_DPE(x)                    (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CASR_DPE_SHIFT))&CAU_AESIC_CASR_DPE_MASK)
#define CAU_AESIC_CASR_VER_MASK                  0xF0000000u
#define CAU_AESIC_CASR_VER_SHIFT                 28
#define CAU_AESIC_CASR_VER_WIDTH                 4
#define CAU_AESIC_CASR_VER(x)                    (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CASR_VER_SHIFT))&CAU_AESIC_CASR_VER_MASK)
/* AESIC_CAA Bit Fields */
#define CAU_AESIC_CAA_ACC_MASK                   0xFFFFFFFFu
#define CAU_AESIC_CAA_ACC_SHIFT                  0
#define CAU_AESIC_CAA_ACC_WIDTH                  32
#define CAU_AESIC_CAA_ACC(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CAA_ACC_SHIFT))&CAU_AESIC_CAA_ACC_MASK)
/* AESIC_CA Bit Fields */
#define CAU_AESIC_CA_CA0_MASK                    0xFFFFFFFFu
#define CAU_AESIC_CA_CA0_SHIFT                   0
#define CAU_AESIC_CA_CA0_WIDTH                   32
#define CAU_AESIC_CA_CA0(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CA_CA0_SHIFT))&CAU_AESIC_CA_CA0_MASK)
#define CAU_AESIC_CA_CA1_MASK                    0xFFFFFFFFu
#define CAU_AESIC_CA_CA1_SHIFT                   0
#define CAU_AESIC_CA_CA1_WIDTH                   32
#define CAU_AESIC_CA_CA1(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CA_CA1_SHIFT))&CAU_AESIC_CA_CA1_MASK)
#define CAU_AESIC_CA_CA2_MASK                    0xFFFFFFFFu
#define CAU_AESIC_CA_CA2_SHIFT                   0
#define CAU_AESIC_CA_CA2_WIDTH                   32
#define CAU_AESIC_CA_CA2(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CA_CA2_SHIFT))&CAU_AESIC_CA_CA2_MASK)
#define CAU_AESIC_CA_CA3_MASK                    0xFFFFFFFFu
#define CAU_AESIC_CA_CA3_SHIFT                   0
#define CAU_AESIC_CA_CA3_WIDTH                   32
#define CAU_AESIC_CA_CA3(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CA_CA3_SHIFT))&CAU_AESIC_CA_CA3_MASK)
#define CAU_AESIC_CA_CA4_MASK                    0xFFFFFFFFu
#define CAU_AESIC_CA_CA4_SHIFT                   0
#define CAU_AESIC_CA_CA4_WIDTH                   32
#define CAU_AESIC_CA_CA4(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CA_CA4_SHIFT))&CAU_AESIC_CA_CA4_MASK)
#define CAU_AESIC_CA_CA5_MASK                    0xFFFFFFFFu
#define CAU_AESIC_CA_CA5_SHIFT                   0
#define CAU_AESIC_CA_CA5_WIDTH                   32
#define CAU_AESIC_CA_CA5(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CA_CA5_SHIFT))&CAU_AESIC_CA_CA5_MASK)
#define CAU_AESIC_CA_CA6_MASK                    0xFFFFFFFFu
#define CAU_AESIC_CA_CA6_SHIFT                   0
#define CAU_AESIC_CA_CA6_WIDTH                   32
#define CAU_AESIC_CA_CA6(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CA_CA6_SHIFT))&CAU_AESIC_CA_CA6_MASK)
#define CAU_AESIC_CA_CA7_MASK                    0xFFFFFFFFu
#define CAU_AESIC_CA_CA7_SHIFT                   0
#define CAU_AESIC_CA_CA7_WIDTH                   32
#define CAU_AESIC_CA_CA7(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CA_CA7_SHIFT))&CAU_AESIC_CA_CA7_MASK)
#define CAU_AESIC_CA_CA8_MASK                    0xFFFFFFFFu
#define CAU_AESIC_CA_CA8_SHIFT                   0
#define CAU_AESIC_CA_CA8_WIDTH                   32
#define CAU_AESIC_CA_CA8(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CA_CA8_SHIFT))&CAU_AESIC_CA_CA8_MASK)

/*!
 * @}
 */ /* end of group CAU_Register_Masks */


/* CAU - Peripheral instance base addresses */
/** Peripheral CAU0 base address */
#define CAU0_BASE                                (0xF0005000u)
/** Peripheral CAU0 base pointer */
#define CAU0                                     ((CAU_Type *)CAU0_BASE)
#define CAU0_BASE_PTR                            (CAU0)
/** Array initializer of CAU peripheral base addresses */
#define CAU_BASE_ADDRS                           { CAU0_BASE }
/** Array initializer of CAU peripheral base pointers */
#define CAU_BASE_PTRS                            { CAU0 }

/* ----------------------------------------------------------------------------
   -- CAU - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAU_Register_Accessor_Macros CAU - Register accessor macros
 * @{
 */


/* CAU - Register instance definitions */
/* CAU0 */
#define CAU_DIRECT0                              CAU_DIRECT_REG(CAU0,0)
#define CAU_DIRECT1                              CAU_DIRECT_REG(CAU0,1)
#define CAU_DIRECT2                              CAU_DIRECT_REG(CAU0,2)
#define CAU_DIRECT3                              CAU_DIRECT_REG(CAU0,3)
#define CAU_DIRECT4                              CAU_DIRECT_REG(CAU0,4)
#define CAU_DIRECT5                              CAU_DIRECT_REG(CAU0,5)
#define CAU_DIRECT6                              CAU_DIRECT_REG(CAU0,6)
#define CAU_DIRECT7                              CAU_DIRECT_REG(CAU0,7)
#define CAU_DIRECT8                              CAU_DIRECT_REG(CAU0,8)
#define CAU_DIRECT9                              CAU_DIRECT_REG(CAU0,9)
#define CAU_DIRECT10                             CAU_DIRECT_REG(CAU0,10)
#define CAU_DIRECT11                             CAU_DIRECT_REG(CAU0,11)
#define CAU_DIRECT12                             CAU_DIRECT_REG(CAU0,12)
#define CAU_DIRECT13                             CAU_DIRECT_REG(CAU0,13)
#define CAU_DIRECT14                             CAU_DIRECT_REG(CAU0,14)
#define CAU_DIRECT15                             CAU_DIRECT_REG(CAU0,15)
#define CAU_LDR_CASR                             CAU_LDR_CASR_REG(CAU0)
#define CAU_LDR_CAA                              CAU_LDR_CAA_REG(CAU0)
#define CAU_LDR_CA0                              CAU_LDR_CA_REG(CAU0,0)
#define CAU_LDR_CA1                              CAU_LDR_CA_REG(CAU0,1)
#define CAU_LDR_CA2                              CAU_LDR_CA_REG(CAU0,2)
#define CAU_LDR_CA3                              CAU_LDR_CA_REG(CAU0,3)
#define CAU_LDR_CA4                              CAU_LDR_CA_REG(CAU0,4)
#define CAU_LDR_CA5                              CAU_LDR_CA_REG(CAU0,5)
#define CAU_LDR_CA6                              CAU_LDR_CA_REG(CAU0,6)
#define CAU_LDR_CA7                              CAU_LDR_CA_REG(CAU0,7)
#define CAU_LDR_CA8                              CAU_LDR_CA_REG(CAU0,8)
#define CAU_STR_CASR                             CAU_STR_CASR_REG(CAU0)
#define CAU_STR_CAA                              CAU_STR_CAA_REG(CAU0)
#define CAU_STR_CA0                              CAU_STR_CA_REG(CAU0,0)
#define CAU_STR_CA1                              CAU_STR_CA_REG(CAU0,1)
#define CAU_STR_CA2                              CAU_STR_CA_REG(CAU0,2)
#define CAU_STR_CA3                              CAU_STR_CA_REG(CAU0,3)
#define CAU_STR_CA4                              CAU_STR_CA_REG(CAU0,4)
#define CAU_STR_CA5                              CAU_STR_CA_REG(CAU0,5)
#define CAU_STR_CA6                              CAU_STR_CA_REG(CAU0,6)
#define CAU_STR_CA7                              CAU_STR_CA_REG(CAU0,7)
#define CAU_STR_CA8                              CAU_STR_CA_REG(CAU0,8)
#define CAU_ADR_CASR                             CAU_ADR_CASR_REG(CAU0)
#define CAU_ADR_CAA                              CAU_ADR_CAA_REG(CAU0)
#define CAU_ADR_CA0                              CAU_ADR_CA_REG(CAU0,0)
#define CAU_ADR_CA1                              CAU_ADR_CA_REG(CAU0,1)
#define CAU_ADR_CA2                              CAU_ADR_CA_REG(CAU0,2)
#define CAU_ADR_CA3                              CAU_ADR_CA_REG(CAU0,3)
#define CAU_ADR_CA4                              CAU_ADR_CA_REG(CAU0,4)
#define CAU_ADR_CA5                              CAU_ADR_CA_REG(CAU0,5)
#define CAU_ADR_CA6                              CAU_ADR_CA_REG(CAU0,6)
#define CAU_ADR_CA7                              CAU_ADR_CA_REG(CAU0,7)
#define CAU_ADR_CA8                              CAU_ADR_CA_REG(CAU0,8)
#define CAU_RADR_CASR                            CAU_RADR_CASR_REG(CAU0)
#define CAU_RADR_CAA                             CAU_RADR_CAA_REG(CAU0)
#define CAU_RADR_CA0                             CAU_RADR_CA_REG(CAU0,0)
#define CAU_RADR_CA1                             CAU_RADR_CA_REG(CAU0,1)
#define CAU_RADR_CA2                             CAU_RADR_CA_REG(CAU0,2)
#define CAU_RADR_CA3                             CAU_RADR_CA_REG(CAU0,3)
#define CAU_RADR_CA4                             CAU_RADR_CA_REG(CAU0,4)
#define CAU_RADR_CA5                             CAU_RADR_CA_REG(CAU0,5)
#define CAU_RADR_CA6                             CAU_RADR_CA_REG(CAU0,6)
#define CAU_RADR_CA7                             CAU_RADR_CA_REG(CAU0,7)
#define CAU_RADR_CA8                             CAU_RADR_CA_REG(CAU0,8)
#define CAU_XOR_CASR                             CAU_XOR_CASR_REG(CAU0)
#define CAU_XOR_CAA                              CAU_XOR_CAA_REG(CAU0)
#define CAU_XOR_CA0                              CAU_XOR_CA_REG(CAU0,0)
#define CAU_XOR_CA1                              CAU_XOR_CA_REG(CAU0,1)
#define CAU_XOR_CA2                              CAU_XOR_CA_REG(CAU0,2)
#define CAU_XOR_CA3                              CAU_XOR_CA_REG(CAU0,3)
#define CAU_XOR_CA4                              CAU_XOR_CA_REG(CAU0,4)
#define CAU_XOR_CA5                              CAU_XOR_CA_REG(CAU0,5)
#define CAU_XOR_CA6                              CAU_XOR_CA_REG(CAU0,6)
#define CAU_XOR_CA7                              CAU_XOR_CA_REG(CAU0,7)
#define CAU_XOR_CA8                              CAU_XOR_CA_REG(CAU0,8)
#define CAU_ROTL_CASR                            CAU_ROTL_CASR_REG(CAU0)
#define CAU_ROTL_CAA                             CAU_ROTL_CAA_REG(CAU0)
#define CAU_ROTL_CA0                             CAU_ROTL_CA_REG(CAU0,0)
#define CAU_ROTL_CA1                             CAU_ROTL_CA_REG(CAU0,1)
#define CAU_ROTL_CA2                             CAU_ROTL_CA_REG(CAU0,2)
#define CAU_ROTL_CA3                             CAU_ROTL_CA_REG(CAU0,3)
#define CAU_ROTL_CA4                             CAU_ROTL_CA_REG(CAU0,4)
#define CAU_ROTL_CA5                             CAU_ROTL_CA_REG(CAU0,5)
#define CAU_ROTL_CA6                             CAU_ROTL_CA_REG(CAU0,6)
#define CAU_ROTL_CA7                             CAU_ROTL_CA_REG(CAU0,7)
#define CAU_ROTL_CA8                             CAU_ROTL_CA_REG(CAU0,8)
#define CAU_AESC_CASR                            CAU_AESC_CASR_REG(CAU0)
#define CAU_AESC_CAA                             CAU_AESC_CAA_REG(CAU0)
#define CAU_AESC_CA0                             CAU_AESC_CA_REG(CAU0,0)
#define CAU_AESC_CA1                             CAU_AESC_CA_REG(CAU0,1)
#define CAU_AESC_CA2                             CAU_AESC_CA_REG(CAU0,2)
#define CAU_AESC_CA3                             CAU_AESC_CA_REG(CAU0,3)
#define CAU_AESC_CA4                             CAU_AESC_CA_REG(CAU0,4)
#define CAU_AESC_CA5                             CAU_AESC_CA_REG(CAU0,5)
#define CAU_AESC_CA6                             CAU_AESC_CA_REG(CAU0,6)
#define CAU_AESC_CA7                             CAU_AESC_CA_REG(CAU0,7)
#define CAU_AESC_CA8                             CAU_AESC_CA_REG(CAU0,8)
#define CAU_AESIC_CASR                           CAU_AESIC_CASR_REG(CAU0)
#define CAU_AESIC_CAA                            CAU_AESIC_CAA_REG(CAU0)
#define CAU_AESIC_CA0                            CAU_AESIC_CA_REG(CAU0,0)
#define CAU_AESIC_CA1                            CAU_AESIC_CA_REG(CAU0,1)
#define CAU_AESIC_CA2                            CAU_AESIC_CA_REG(CAU0,2)
#define CAU_AESIC_CA3                            CAU_AESIC_CA_REG(CAU0,3)
#define CAU_AESIC_CA4                            CAU_AESIC_CA_REG(CAU0,4)
#define CAU_AESIC_CA5                            CAU_AESIC_CA_REG(CAU0,5)
#define CAU_AESIC_CA6                            CAU_AESIC_CA_REG(CAU0,6)
#define CAU_AESIC_CA7                            CAU_AESIC_CA_REG(CAU0,7)
#define CAU_AESIC_CA8                            CAU_AESIC_CA_REG(CAU0,8)

/* CAU - Register array accessors */
#define CAU0_DIRECT(index)                       CAU_DIRECT_REG(CAU0,index)
#define CAU0_LDR_CA(index)                       CAU_LDR_CA_REG(CAU0,index)
#define CAU0_STR_CA(index)                       CAU_STR_CA_REG(CAU0,index)
#define CAU0_ADR_CA(index)                       CAU_ADR_CA_REG(CAU0,index)
#define CAU0_RADR_CA(index)                      CAU_RADR_CA_REG(CAU0,index)
#define CAU0_XOR_CA(index)                       CAU_XOR_CA_REG(CAU0,index)
#define CAU0_ROTL_CA(index)                      CAU_ROTL_CA_REG(CAU0,index)
#define CAU0_AESC_CA(index)                      CAU_AESC_CA_REG(CAU0,index)
#define CAU0_AESIC_CA(index)                     CAU_AESIC_CA_REG(CAU0,index)

/*!
 * @}
 */ /* end of group CAU_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group CAU_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Peripheral_Access_Layer CMP Peripheral Access Layer
 * @{
 */

/** CMP - Register Layout Typedef */
typedef struct {
  __IO uint8_t CR0;                                /**< CMP Control Register 0, offset: 0x0 */
  __IO uint8_t CR1;                                /**< CMP Control Register 1, offset: 0x1 */
  __IO uint8_t FPR;                                /**< CMP Filter Period Register, offset: 0x2 */
  __IO uint8_t SCR;                                /**< CMP Status and Control Register, offset: 0x3 */
  __IO uint8_t DACCR;                              /**< DAC Control Register, offset: 0x4 */
  __IO uint8_t MUXCR;                              /**< MUX Control Register, offset: 0x5 */
} CMP_Type, *CMP_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Register_Accessor_Macros CMP - Register accessor macros
 * @{
 */


/* CMP - Register accessors */
#define CMP_CR0_REG(base)                        ((base)->CR0)
#define CMP_CR1_REG(base)                        ((base)->CR1)
#define CMP_FPR_REG(base)                        ((base)->FPR)
#define CMP_SCR_REG(base)                        ((base)->SCR)
#define CMP_DACCR_REG(base)                      ((base)->DACCR)
#define CMP_MUXCR_REG(base)                      ((base)->MUXCR)

/*!
 * @}
 */ /* end of group CMP_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Register_Masks CMP Register Masks
 * @{
 */

/* CR0 Bit Fields */
#define CMP_CR0_HYSTCTR_MASK                     0x3u
#define CMP_CR0_HYSTCTR_SHIFT                    0
#define CMP_CR0_HYSTCTR_WIDTH                    2
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_CR0_HYSTCTR_SHIFT))&CMP_CR0_HYSTCTR_MASK)
#define CMP_CR0_FILTER_CNT_MASK                  0x70u
#define CMP_CR0_FILTER_CNT_SHIFT                 4
#define CMP_CR0_FILTER_CNT_WIDTH                 3
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x))<<CMP_CR0_FILTER_CNT_SHIFT))&CMP_CR0_FILTER_CNT_MASK)
/* CR1 Bit Fields */
#define CMP_CR1_EN_MASK                          0x1u
#define CMP_CR1_EN_SHIFT                         0
#define CMP_CR1_EN_WIDTH                         1
#define CMP_CR1_EN(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_EN_SHIFT))&CMP_CR1_EN_MASK)
#define CMP_CR1_OPE_MASK                         0x2u
#define CMP_CR1_OPE_SHIFT                        1
#define CMP_CR1_OPE_WIDTH                        1
#define CMP_CR1_OPE(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_OPE_SHIFT))&CMP_CR1_OPE_MASK)
#define CMP_CR1_COS_MASK                         0x4u
#define CMP_CR1_COS_SHIFT                        2
#define CMP_CR1_COS_WIDTH                        1
#define CMP_CR1_COS(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_COS_SHIFT))&CMP_CR1_COS_MASK)
#define CMP_CR1_INV_MASK                         0x8u
#define CMP_CR1_INV_SHIFT                        3
#define CMP_CR1_INV_WIDTH                        1
#define CMP_CR1_INV(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_INV_SHIFT))&CMP_CR1_INV_MASK)
#define CMP_CR1_PMODE_MASK                       0x10u
#define CMP_CR1_PMODE_SHIFT                      4
#define CMP_CR1_PMODE_WIDTH                      1
#define CMP_CR1_PMODE(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_CR1_PMODE_SHIFT))&CMP_CR1_PMODE_MASK)
#define CMP_CR1_TRIGM_MASK                       0x20u
#define CMP_CR1_TRIGM_SHIFT                      5
#define CMP_CR1_TRIGM_WIDTH                      1
#define CMP_CR1_TRIGM(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_CR1_TRIGM_SHIFT))&CMP_CR1_TRIGM_MASK)
#define CMP_CR1_WE_MASK                          0x40u
#define CMP_CR1_WE_SHIFT                         6
#define CMP_CR1_WE_WIDTH                         1
#define CMP_CR1_WE(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_WE_SHIFT))&CMP_CR1_WE_MASK)
#define CMP_CR1_SE_MASK                          0x80u
#define CMP_CR1_SE_SHIFT                         7
#define CMP_CR1_SE_WIDTH                         1
#define CMP_CR1_SE(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_SE_SHIFT))&CMP_CR1_SE_MASK)
/* FPR Bit Fields */
#define CMP_FPR_FILT_PER_MASK                    0xFFu
#define CMP_FPR_FILT_PER_SHIFT                   0
#define CMP_FPR_FILT_PER_WIDTH                   8
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x))<<CMP_FPR_FILT_PER_SHIFT))&CMP_FPR_FILT_PER_MASK)
/* SCR Bit Fields */
#define CMP_SCR_COUT_MASK                        0x1u
#define CMP_SCR_COUT_SHIFT                       0
#define CMP_SCR_COUT_WIDTH                       1
#define CMP_SCR_COUT(x)                          (((uint8_t)(((uint8_t)(x))<<CMP_SCR_COUT_SHIFT))&CMP_SCR_COUT_MASK)
#define CMP_SCR_CFF_MASK                         0x2u
#define CMP_SCR_CFF_SHIFT                        1
#define CMP_SCR_CFF_WIDTH                        1
#define CMP_SCR_CFF(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_CFF_SHIFT))&CMP_SCR_CFF_MASK)
#define CMP_SCR_CFR_MASK                         0x4u
#define CMP_SCR_CFR_SHIFT                        2
#define CMP_SCR_CFR_WIDTH                        1
#define CMP_SCR_CFR(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_CFR_SHIFT))&CMP_SCR_CFR_MASK)
#define CMP_SCR_IEF_MASK                         0x8u
#define CMP_SCR_IEF_SHIFT                        3
#define CMP_SCR_IEF_WIDTH                        1
#define CMP_SCR_IEF(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_IEF_SHIFT))&CMP_SCR_IEF_MASK)
#define CMP_SCR_IER_MASK                         0x10u
#define CMP_SCR_IER_SHIFT                        4
#define CMP_SCR_IER_WIDTH                        1
#define CMP_SCR_IER(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_IER_SHIFT))&CMP_SCR_IER_MASK)
#define CMP_SCR_DMAEN_MASK                       0x40u
#define CMP_SCR_DMAEN_SHIFT                      6
#define CMP_SCR_DMAEN_WIDTH                      1
#define CMP_SCR_DMAEN(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_SCR_DMAEN_SHIFT))&CMP_SCR_DMAEN_MASK)
/* DACCR Bit Fields */
#define CMP_DACCR_VOSEL_MASK                     0x3Fu
#define CMP_DACCR_VOSEL_SHIFT                    0
#define CMP_DACCR_VOSEL_WIDTH                    6
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VOSEL_SHIFT))&CMP_DACCR_VOSEL_MASK)
#define CMP_DACCR_VRSEL_MASK                     0x40u
#define CMP_DACCR_VRSEL_SHIFT                    6
#define CMP_DACCR_VRSEL_WIDTH                    1
#define CMP_DACCR_VRSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VRSEL_SHIFT))&CMP_DACCR_VRSEL_MASK)
#define CMP_DACCR_DACEN_MASK                     0x80u
#define CMP_DACCR_DACEN_SHIFT                    7
#define CMP_DACCR_DACEN_WIDTH                    1
#define CMP_DACCR_DACEN(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_DACEN_SHIFT))&CMP_DACCR_DACEN_MASK)
/* MUXCR Bit Fields */
#define CMP_MUXCR_MSEL_MASK                      0x7u
#define CMP_MUXCR_MSEL_SHIFT                     0
#define CMP_MUXCR_MSEL_WIDTH                     3
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_MSEL_SHIFT))&CMP_MUXCR_MSEL_MASK)
#define CMP_MUXCR_PSEL_MASK                      0x38u
#define CMP_MUXCR_PSEL_SHIFT                     3
#define CMP_MUXCR_PSEL_WIDTH                     3
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSEL_SHIFT))&CMP_MUXCR_PSEL_MASK)
#define CMP_MUXCR_PSTM_MASK                      0x80u
#define CMP_MUXCR_PSTM_SHIFT                     7
#define CMP_MUXCR_PSTM_WIDTH                     1
#define CMP_MUXCR_PSTM(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSTM_SHIFT))&CMP_MUXCR_PSTM_MASK)

/*!
 * @}
 */ /* end of group CMP_Register_Masks */


/* CMP - Peripheral instance base addresses */
/** Peripheral CMP0 base address */
#define CMP0_BASE                                (0x4006E000u)
/** Peripheral CMP0 base pointer */
#define CMP0                                     ((CMP_Type *)CMP0_BASE)
#define CMP0_BASE_PTR                            (CMP0)
/** Peripheral CMP1 base address */
#define CMP1_BASE                                (0x400EF000u)
/** Peripheral CMP1 base pointer */
#define CMP1                                     ((CMP_Type *)CMP1_BASE)
#define CMP1_BASE_PTR                            (CMP1)
/** Array initializer of CMP peripheral base addresses */
#define CMP_BASE_ADDRS                           { CMP0_BASE, CMP1_BASE }
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            { CMP0, CMP1 }

/* ----------------------------------------------------------------------------
   -- CMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Register_Accessor_Macros CMP - Register accessor macros
 * @{
 */


/* CMP - Register instance definitions */
/* CMP0 */
#define CMP0_CR0                                 CMP_CR0_REG(CMP0)
#define CMP0_CR1                                 CMP_CR1_REG(CMP0)
#define CMP0_FPR                                 CMP_FPR_REG(CMP0)
#define CMP0_SCR                                 CMP_SCR_REG(CMP0)
#define CMP0_DACCR                               CMP_DACCR_REG(CMP0)
#define CMP0_MUXCR                               CMP_MUXCR_REG(CMP0)
/* CMP1 */
#define CMP1_CR0                                 CMP_CR0_REG(CMP1)
#define CMP1_CR1                                 CMP_CR1_REG(CMP1)
#define CMP1_FPR                                 CMP_FPR_REG(CMP1)
#define CMP1_SCR                                 CMP_SCR_REG(CMP1)
#define CMP1_DACCR                               CMP_DACCR_REG(CMP1)
#define CMP1_MUXCR                               CMP_MUXCR_REG(CMP1)

/*!
 * @}
 */ /* end of group CMP_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group CMP_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Peripheral_Access_Layer CRC Peripheral Access Layer
 * @{
 */

/** CRC - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      __IO uint16_t DATAL;                             /**< CRC_DATAL register., offset: 0x0 */
      __IO uint16_t DATAH;                             /**< CRC_DATAH register., offset: 0x2 */
    } ACCESS16BIT;
    __IO uint32_t DATA;                              /**< CRC Data register, offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      __IO uint8_t DATALL;                             /**< CRC_DATALL register., offset: 0x0 */
      __IO uint8_t DATALU;                             /**< CRC_DATALU register., offset: 0x1 */
      __IO uint8_t DATAHL;                             /**< CRC_DATAHL register., offset: 0x2 */
      __IO uint8_t DATAHU;                             /**< CRC_DATAHU register., offset: 0x3 */
    } ACCESS8BIT;
  };
  union {                                          /* offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      __IO uint16_t GPOLYL;                            /**< CRC_GPOLYL register., offset: 0x4 */
      __IO uint16_t GPOLYH;                            /**< CRC_GPOLYH register., offset: 0x6 */
    } GPOLY_ACCESS16BIT;
    __IO uint32_t GPOLY;                             /**< CRC Polynomial register, offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      __IO uint8_t GPOLYLL;                            /**< CRC_GPOLYLL register., offset: 0x4 */
      __IO uint8_t GPOLYLU;                            /**< CRC_GPOLYLU register., offset: 0x5 */
      __IO uint8_t GPOLYHL;                            /**< CRC_GPOLYHL register., offset: 0x6 */
      __IO uint8_t GPOLYHU;                            /**< CRC_GPOLYHU register., offset: 0x7 */
    } GPOLY_ACCESS8BIT;
  };
  union {                                          /* offset: 0x8 */
    __IO uint32_t CTRL;                              /**< CRC Control register, offset: 0x8 */
    struct {                                         /* offset: 0x8 */
           uint8_t RESERVED_0[3];
      __IO uint8_t CTRLHU;                             /**< CRC_CTRLHU register., offset: 0xB */
    } CTRL_ACCESS8BIT;
  };
} CRC_Type, *CRC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CRC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Accessor_Macros CRC - Register accessor macros
 * @{
 */


/* CRC - Register accessors */
#define CRC_DATAL_REG(base)                      ((base)->ACCESS16BIT.DATAL)
#define CRC_DATAH_REG(base)                      ((base)->ACCESS16BIT.DATAH)
#define CRC_DATA_REG(base)                       ((base)->DATA)
#define CRC_DATALL_REG(base)                     ((base)->ACCESS8BIT.DATALL)
#define CRC_DATALU_REG(base)                     ((base)->ACCESS8BIT.DATALU)
#define CRC_DATAHL_REG(base)                     ((base)->ACCESS8BIT.DATAHL)
#define CRC_DATAHU_REG(base)                     ((base)->ACCESS8BIT.DATAHU)
#define CRC_GPOLYL_REG(base)                     ((base)->GPOLY_ACCESS16BIT.GPOLYL)
#define CRC_GPOLYH_REG(base)                     ((base)->GPOLY_ACCESS16BIT.GPOLYH)
#define CRC_GPOLY_REG(base)                      ((base)->GPOLY)
#define CRC_GPOLYLL_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYLL)
#define CRC_GPOLYLU_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYLU)
#define CRC_GPOLYHL_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYHL)
#define CRC_GPOLYHU_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYHU)
#define CRC_CTRL_REG(base)                       ((base)->CTRL)
#define CRC_CTRLHU_REG(base)                     ((base)->CTRL_ACCESS8BIT.CTRLHU)

/*!
 * @}
 */ /* end of group CRC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Masks CRC Register Masks
 * @{
 */

/* DATAL Bit Fields */
#define CRC_DATAL_DATAL_MASK                     0xFFFFu
#define CRC_DATAL_DATAL_SHIFT                    0
#define CRC_DATAL_DATAL_WIDTH                    16
#define CRC_DATAL_DATAL(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAL_DATAL_SHIFT))&CRC_DATAL_DATAL_MASK)
/* DATAH Bit Fields */
#define CRC_DATAH_DATAH_MASK                     0xFFFFu
#define CRC_DATAH_DATAH_SHIFT                    0
#define CRC_DATAH_DATAH_WIDTH                    16
#define CRC_DATAH_DATAH(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAH_DATAH_SHIFT))&CRC_DATAH_DATAH_MASK)
/* DATA Bit Fields */
#define CRC_DATA_LL_MASK                         0xFFu
#define CRC_DATA_LL_SHIFT                        0
#define CRC_DATA_LL_WIDTH                        8
#define CRC_DATA_LL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LL_SHIFT))&CRC_DATA_LL_MASK)
#define CRC_DATA_LU_MASK                         0xFF00u
#define CRC_DATA_LU_SHIFT                        8
#define CRC_DATA_LU_WIDTH                        8
#define CRC_DATA_LU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LU_SHIFT))&CRC_DATA_LU_MASK)
#define CRC_DATA_HL_MASK                         0xFF0000u
#define CRC_DATA_HL_SHIFT                        16
#define CRC_DATA_HL_WIDTH                        8
#define CRC_DATA_HL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HL_SHIFT))&CRC_DATA_HL_MASK)
#define CRC_DATA_HU_MASK                         0xFF000000u
#define CRC_DATA_HU_SHIFT                        24
#define CRC_DATA_HU_WIDTH                        8
#define CRC_DATA_HU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HU_SHIFT))&CRC_DATA_HU_MASK)
/* DATALL Bit Fields */
#define CRC_DATALL_DATALL_MASK                   0xFFu
#define CRC_DATALL_DATALL_SHIFT                  0
#define CRC_DATALL_DATALL_WIDTH                  8
#define CRC_DATALL_DATALL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALL_DATALL_SHIFT))&CRC_DATALL_DATALL_MASK)
/* DATALU Bit Fields */
#define CRC_DATALU_DATALU_MASK                   0xFFu
#define CRC_DATALU_DATALU_SHIFT                  0
#define CRC_DATALU_DATALU_WIDTH                  8
#define CRC_DATALU_DATALU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALU_DATALU_SHIFT))&CRC_DATALU_DATALU_MASK)
/* DATAHL Bit Fields */
#define CRC_DATAHL_DATAHL_MASK                   0xFFu
#define CRC_DATAHL_DATAHL_SHIFT                  0
#define CRC_DATAHL_DATAHL_WIDTH                  8
#define CRC_DATAHL_DATAHL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHL_DATAHL_SHIFT))&CRC_DATAHL_DATAHL_MASK)
/* DATAHU Bit Fields */
#define CRC_DATAHU_DATAHU_MASK                   0xFFu
#define CRC_DATAHU_DATAHU_SHIFT                  0
#define CRC_DATAHU_DATAHU_WIDTH                  8
#define CRC_DATAHU_DATAHU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHU_DATAHU_SHIFT))&CRC_DATAHU_DATAHU_MASK)
/* GPOLYL Bit Fields */
#define CRC_GPOLYL_GPOLYL_MASK                   0xFFFFu
#define CRC_GPOLYL_GPOLYL_SHIFT                  0
#define CRC_GPOLYL_GPOLYL_WIDTH                  16
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYL_GPOLYL_SHIFT))&CRC_GPOLYL_GPOLYL_MASK)
/* GPOLYH Bit Fields */
#define CRC_GPOLYH_GPOLYH_MASK                   0xFFFFu
#define CRC_GPOLYH_GPOLYH_SHIFT                  0
#define CRC_GPOLYH_GPOLYH_WIDTH                  16
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYH_GPOLYH_SHIFT))&CRC_GPOLYH_GPOLYH_MASK)
/* GPOLY Bit Fields */
#define CRC_GPOLY_LOW_MASK                       0xFFFFu
#define CRC_GPOLY_LOW_SHIFT                      0
#define CRC_GPOLY_LOW_WIDTH                      16
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_LOW_SHIFT))&CRC_GPOLY_LOW_MASK)
#define CRC_GPOLY_HIGH_MASK                      0xFFFF0000u
#define CRC_GPOLY_HIGH_SHIFT                     16
#define CRC_GPOLY_HIGH_WIDTH                     16
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_HIGH_SHIFT))&CRC_GPOLY_HIGH_MASK)
/* GPOLYLL Bit Fields */
#define CRC_GPOLYLL_GPOLYLL_MASK                 0xFFu
#define CRC_GPOLYLL_GPOLYLL_SHIFT                0
#define CRC_GPOLYLL_GPOLYLL_WIDTH                8
#define CRC_GPOLYLL_GPOLYLL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLL_GPOLYLL_SHIFT))&CRC_GPOLYLL_GPOLYLL_MASK)
/* GPOLYLU Bit Fields */
#define CRC_GPOLYLU_GPOLYLU_MASK                 0xFFu
#define CRC_GPOLYLU_GPOLYLU_SHIFT                0
#define CRC_GPOLYLU_GPOLYLU_WIDTH                8
#define CRC_GPOLYLU_GPOLYLU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLU_GPOLYLU_SHIFT))&CRC_GPOLYLU_GPOLYLU_MASK)
/* GPOLYHL Bit Fields */
#define CRC_GPOLYHL_GPOLYHL_MASK                 0xFFu
#define CRC_GPOLYHL_GPOLYHL_SHIFT                0
#define CRC_GPOLYHL_GPOLYHL_WIDTH                8
#define CRC_GPOLYHL_GPOLYHL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHL_GPOLYHL_SHIFT))&CRC_GPOLYHL_GPOLYHL_MASK)
/* GPOLYHU Bit Fields */
#define CRC_GPOLYHU_GPOLYHU_MASK                 0xFFu
#define CRC_GPOLYHU_GPOLYHU_SHIFT                0
#define CRC_GPOLYHU_GPOLYHU_WIDTH                8
#define CRC_GPOLYHU_GPOLYHU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHU_GPOLYHU_SHIFT))&CRC_GPOLYHU_GPOLYHU_MASK)
/* CTRL Bit Fields */
#define CRC_CTRL_TCRC_MASK                       0x1000000u
#define CRC_CTRL_TCRC_SHIFT                      24
#define CRC_CTRL_TCRC_WIDTH                      1
#define CRC_CTRL_TCRC(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TCRC_SHIFT))&CRC_CTRL_TCRC_MASK)
#define CRC_CTRL_WAS_MASK                        0x2000000u
#define CRC_CTRL_WAS_SHIFT                       25
#define CRC_CTRL_WAS_WIDTH                       1
#define CRC_CTRL_WAS(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_WAS_SHIFT))&CRC_CTRL_WAS_MASK)
#define CRC_CTRL_FXOR_MASK                       0x4000000u
#define CRC_CTRL_FXOR_SHIFT                      26
#define CRC_CTRL_FXOR_WIDTH                      1
#define CRC_CTRL_FXOR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_FXOR_SHIFT))&CRC_CTRL_FXOR_MASK)
#define CRC_CTRL_TOTR_MASK                       0x30000000u
#define CRC_CTRL_TOTR_SHIFT                      28
#define CRC_CTRL_TOTR_WIDTH                      2
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOTR_SHIFT))&CRC_CTRL_TOTR_MASK)
#define CRC_CTRL_TOT_MASK                        0xC0000000u
#define CRC_CTRL_TOT_SHIFT                       30
#define CRC_CTRL_TOT_WIDTH                       2
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOT_SHIFT))&CRC_CTRL_TOT_MASK)
/* CTRLHU Bit Fields */
#define CRC_CTRLHU_TCRC_MASK                     0x1u
#define CRC_CTRLHU_TCRC_SHIFT                    0
#define CRC_CTRLHU_TCRC_WIDTH                    1
#define CRC_CTRLHU_TCRC(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TCRC_SHIFT))&CRC_CTRLHU_TCRC_MASK)
#define CRC_CTRLHU_WAS_MASK                      0x2u
#define CRC_CTRLHU_WAS_SHIFT                     1
#define CRC_CTRLHU_WAS_WIDTH                     1
#define CRC_CTRLHU_WAS(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_WAS_SHIFT))&CRC_CTRLHU_WAS_MASK)
#define CRC_CTRLHU_FXOR_MASK                     0x4u
#define CRC_CTRLHU_FXOR_SHIFT                    2
#define CRC_CTRLHU_FXOR_WIDTH                    1
#define CRC_CTRLHU_FXOR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_FXOR_SHIFT))&CRC_CTRLHU_FXOR_MASK)
#define CRC_CTRLHU_TOTR_MASK                     0x30u
#define CRC_CTRLHU_TOTR_SHIFT                    4
#define CRC_CTRLHU_TOTR_WIDTH                    2
#define CRC_CTRLHU_TOTR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOTR_SHIFT))&CRC_CTRLHU_TOTR_MASK)
#define CRC_CTRLHU_TOT_MASK                      0xC0u
#define CRC_CTRLHU_TOT_SHIFT                     6
#define CRC_CTRLHU_TOT_WIDTH                     2
#define CRC_CTRLHU_TOT(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOT_SHIFT))&CRC_CTRLHU_TOT_MASK)

/*!
 * @}
 */ /* end of group CRC_Register_Masks */


/* CRC - Peripheral instance base addresses */
/** Peripheral CRC base address */
#define CRC_BASE                                 (0x40078000u)
/** Peripheral CRC base pointer */
#define CRC0                                     ((CRC_Type *)CRC_BASE)
#define CRC_BASE_PTR                             (CRC0)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC0 }

/* ----------------------------------------------------------------------------
   -- CRC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Accessor_Macros CRC - Register accessor macros
 * @{
 */


/* CRC - Register instance definitions */
/* CRC */
#define CRC_DATA                                 CRC_DATA_REG(CRC0)
#define CRC_DATAL                                CRC_DATAL_REG(CRC0)
#define CRC_DATALL                               CRC_DATALL_REG(CRC0)
#define CRC_DATALU                               CRC_DATALU_REG(CRC0)
#define CRC_DATAH                                CRC_DATAH_REG(CRC0)
#define CRC_DATAHL                               CRC_DATAHL_REG(CRC0)
#define CRC_DATAHU                               CRC_DATAHU_REG(CRC0)
#define CRC_GPOLY                                CRC_GPOLY_REG(CRC0)
#define CRC_GPOLYL                               CRC_GPOLYL_REG(CRC0)
#define CRC_GPOLYLL                              CRC_GPOLYLL_REG(CRC0)
#define CRC_GPOLYLU                              CRC_GPOLYLU_REG(CRC0)
#define CRC_GPOLYH                               CRC_GPOLYH_REG(CRC0)
#define CRC_GPOLYHL                              CRC_GPOLYHL_REG(CRC0)
#define CRC_GPOLYHU                              CRC_GPOLYHU_REG(CRC0)
#define CRC_CTRL                                 CRC_CTRL_REG(CRC0)
#define CRC_CTRLHU                               CRC_CTRLHU_REG(CRC0)

/*!
 * @}
 */ /* end of group CRC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group CRC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DAC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Peripheral_Access_Layer DAC Peripheral Access Layer
 * @{
 */

/** DAC - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x2 */
    __IO uint8_t DATL;                               /**< DAC Data Low Register, array offset: 0x0, array step: 0x2 */
    __IO uint8_t DATH;                               /**< DAC Data High Register, array offset: 0x1, array step: 0x2 */
  } DAT[16];
  __IO uint8_t SR;                                 /**< DAC Status Register, offset: 0x20 */
  __IO uint8_t C0;                                 /**< DAC Control Register, offset: 0x21 */
  __IO uint8_t C1;                                 /**< DAC Control Register 1, offset: 0x22 */
  __IO uint8_t C2;                                 /**< DAC Control Register 2, offset: 0x23 */
} DAC_Type, *DAC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DAC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Register_Accessor_Macros DAC - Register accessor macros
 * @{
 */


/* DAC - Register accessors */
#define DAC_DATL_REG(base,index)                 ((base)->DAT[index].DATL)
#define DAC_DATL_COUNT                           16
#define DAC_DATH_REG(base,index)                 ((base)->DAT[index].DATH)
#define DAC_DATH_COUNT                           16
#define DAC_SR_REG(base)                         ((base)->SR)
#define DAC_C0_REG(base)                         ((base)->C0)
#define DAC_C1_REG(base)                         ((base)->C1)
#define DAC_C2_REG(base)                         ((base)->C2)

/*!
 * @}
 */ /* end of group DAC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Register_Masks DAC Register Masks
 * @{
 */

/* DATL Bit Fields */
#define DAC_DATL_DATA0_MASK                      0xFFu
#define DAC_DATL_DATA0_SHIFT                     0
#define DAC_DATL_DATA0_WIDTH                     8
#define DAC_DATL_DATA0(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_DATL_DATA0_SHIFT))&DAC_DATL_DATA0_MASK)
/* DATH Bit Fields */
#define DAC_DATH_DATA1_MASK                      0xFu
#define DAC_DATH_DATA1_SHIFT                     0
#define DAC_DATH_DATA1_WIDTH                     4
#define DAC_DATH_DATA1(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_DATH_DATA1_SHIFT))&DAC_DATH_DATA1_MASK)
/* SR Bit Fields */
#define DAC_SR_DACBFRPBF_MASK                    0x1u
#define DAC_SR_DACBFRPBF_SHIFT                   0
#define DAC_SR_DACBFRPBF_WIDTH                   1
#define DAC_SR_DACBFRPBF(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_SR_DACBFRPBF_SHIFT))&DAC_SR_DACBFRPBF_MASK)
#define DAC_SR_DACBFRPTF_MASK                    0x2u
#define DAC_SR_DACBFRPTF_SHIFT                   1
#define DAC_SR_DACBFRPTF_WIDTH                   1
#define DAC_SR_DACBFRPTF(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_SR_DACBFRPTF_SHIFT))&DAC_SR_DACBFRPTF_MASK)
#define DAC_SR_DACBFWMF_MASK                     0x4u
#define DAC_SR_DACBFWMF_SHIFT                    2
#define DAC_SR_DACBFWMF_WIDTH                    1
#define DAC_SR_DACBFWMF(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_SR_DACBFWMF_SHIFT))&DAC_SR_DACBFWMF_MASK)
/* C0 Bit Fields */
#define DAC_C0_DACBBIEN_MASK                     0x1u
#define DAC_C0_DACBBIEN_SHIFT                    0
#define DAC_C0_DACBBIEN_WIDTH                    1
#define DAC_C0_DACBBIEN(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACBBIEN_SHIFT))&DAC_C0_DACBBIEN_MASK)
#define DAC_C0_DACBTIEN_MASK                     0x2u
#define DAC_C0_DACBTIEN_SHIFT                    1
#define DAC_C0_DACBTIEN_WIDTH                    1
#define DAC_C0_DACBTIEN(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACBTIEN_SHIFT))&DAC_C0_DACBTIEN_MASK)
#define DAC_C0_DACBWIEN_MASK                     0x4u
#define DAC_C0_DACBWIEN_SHIFT                    2
#define DAC_C0_DACBWIEN_WIDTH                    1
#define DAC_C0_DACBWIEN(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACBWIEN_SHIFT))&DAC_C0_DACBWIEN_MASK)
#define DAC_C0_LPEN_MASK                         0x8u
#define DAC_C0_LPEN_SHIFT                        3
#define DAC_C0_LPEN_WIDTH                        1
#define DAC_C0_LPEN(x)                           (((uint8_t)(((uint8_t)(x))<<DAC_C0_LPEN_SHIFT))&DAC_C0_LPEN_MASK)
#define DAC_C0_DACSWTRG_MASK                     0x10u
#define DAC_C0_DACSWTRG_SHIFT                    4
#define DAC_C0_DACSWTRG_WIDTH                    1
#define DAC_C0_DACSWTRG(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACSWTRG_SHIFT))&DAC_C0_DACSWTRG_MASK)
#define DAC_C0_DACTRGSEL_MASK                    0x20u
#define DAC_C0_DACTRGSEL_SHIFT                   5
#define DAC_C0_DACTRGSEL_WIDTH                   1
#define DAC_C0_DACTRGSEL(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACTRGSEL_SHIFT))&DAC_C0_DACTRGSEL_MASK)
#define DAC_C0_DACRFS_MASK                       0x40u
#define DAC_C0_DACRFS_SHIFT                      6
#define DAC_C0_DACRFS_WIDTH                      1
#define DAC_C0_DACRFS(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACRFS_SHIFT))&DAC_C0_DACRFS_MASK)
#define DAC_C0_DACEN_MASK                        0x80u
#define DAC_C0_DACEN_SHIFT                       7
#define DAC_C0_DACEN_WIDTH                       1
#define DAC_C0_DACEN(x)                          (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACEN_SHIFT))&DAC_C0_DACEN_MASK)
/* C1 Bit Fields */
#define DAC_C1_DACBFEN_MASK                      0x1u
#define DAC_C1_DACBFEN_SHIFT                     0
#define DAC_C1_DACBFEN_WIDTH                     1
#define DAC_C1_DACBFEN(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFEN_SHIFT))&DAC_C1_DACBFEN_MASK)
#define DAC_C1_DACBFMD_MASK                      0x6u
#define DAC_C1_DACBFMD_SHIFT                     1
#define DAC_C1_DACBFMD_WIDTH                     2
#define DAC_C1_DACBFMD(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFMD_SHIFT))&DAC_C1_DACBFMD_MASK)
#define DAC_C1_DACBFWM_MASK                      0x18u
#define DAC_C1_DACBFWM_SHIFT                     3
#define DAC_C1_DACBFWM_WIDTH                     2
#define DAC_C1_DACBFWM(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFWM_SHIFT))&DAC_C1_DACBFWM_MASK)
#define DAC_C1_DMAEN_MASK                        0x80u
#define DAC_C1_DMAEN_SHIFT                       7
#define DAC_C1_DMAEN_WIDTH                       1
#define DAC_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x))<<DAC_C1_DMAEN_SHIFT))&DAC_C1_DMAEN_MASK)
/* C2 Bit Fields */
#define DAC_C2_DACBFUP_MASK                      0xFu
#define DAC_C2_DACBFUP_SHIFT                     0
#define DAC_C2_DACBFUP_WIDTH                     4
#define DAC_C2_DACBFUP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFUP_SHIFT))&DAC_C2_DACBFUP_MASK)
#define DAC_C2_DACBFRP_MASK                      0xF0u
#define DAC_C2_DACBFRP_SHIFT                     4
#define DAC_C2_DACBFRP_WIDTH                     4
#define DAC_C2_DACBFRP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFRP_SHIFT))&DAC_C2_DACBFRP_MASK)

/*!
 * @}
 */ /* end of group DAC_Register_Masks */


/* DAC - Peripheral instance base addresses */
/** Peripheral DAC0 base address */
#define DAC0_BASE                                (0x4006A000u)
/** Peripheral DAC0 base pointer */
#define DAC0                                     ((DAC_Type *)DAC0_BASE)
#define DAC0_BASE_PTR                            (DAC0)
/** Array initializer of DAC peripheral base addresses */
#define DAC_BASE_ADDRS                           { DAC0_BASE }
/** Array initializer of DAC peripheral base pointers */
#define DAC_BASE_PTRS                            { DAC0 }

/* ----------------------------------------------------------------------------
   -- DAC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Register_Accessor_Macros DAC - Register accessor macros
 * @{
 */


/* DAC - Register instance definitions */
/* DAC0 */
#define DAC0_DAT0L                               DAC_DATL_REG(DAC0,0)
#define DAC0_DAT0H                               DAC_DATH_REG(DAC0,0)
#define DAC0_DAT1L                               DAC_DATL_REG(DAC0,1)
#define DAC0_DAT1H                               DAC_DATH_REG(DAC0,1)
#define DAC0_DAT2L                               DAC_DATL_REG(DAC0,2)
#define DAC0_DAT2H                               DAC_DATH_REG(DAC0,2)
#define DAC0_DAT3L                               DAC_DATL_REG(DAC0,3)
#define DAC0_DAT3H                               DAC_DATH_REG(DAC0,3)
#define DAC0_DAT4L                               DAC_DATL_REG(DAC0,4)
#define DAC0_DAT4H                               DAC_DATH_REG(DAC0,4)
#define DAC0_DAT5L                               DAC_DATL_REG(DAC0,5)
#define DAC0_DAT5H                               DAC_DATH_REG(DAC0,5)
#define DAC0_DAT6L                               DAC_DATL_REG(DAC0,6)
#define DAC0_DAT6H                               DAC_DATH_REG(DAC0,6)
#define DAC0_DAT7L                               DAC_DATL_REG(DAC0,7)
#define DAC0_DAT7H                               DAC_DATH_REG(DAC0,7)
#define DAC0_DAT8L                               DAC_DATL_REG(DAC0,8)
#define DAC0_DAT8H                               DAC_DATH_REG(DAC0,8)
#define DAC0_DAT9L                               DAC_DATL_REG(DAC0,9)
#define DAC0_DAT9H                               DAC_DATH_REG(DAC0,9)
#define DAC0_DAT10L                              DAC_DATL_REG(DAC0,10)
#define DAC0_DAT10H                              DAC_DATH_REG(DAC0,10)
#define DAC0_DAT11L                              DAC_DATL_REG(DAC0,11)
#define DAC0_DAT11H                              DAC_DATH_REG(DAC0,11)
#define DAC0_DAT12L                              DAC_DATL_REG(DAC0,12)
#define DAC0_DAT12H                              DAC_DATH_REG(DAC0,12)
#define DAC0_DAT13L                              DAC_DATL_REG(DAC0,13)
#define DAC0_DAT13H                              DAC_DATH_REG(DAC0,13)
#define DAC0_DAT14L                              DAC_DATL_REG(DAC0,14)
#define DAC0_DAT14H                              DAC_DATH_REG(DAC0,14)
#define DAC0_DAT15L                              DAC_DATL_REG(DAC0,15)
#define DAC0_DAT15H                              DAC_DATH_REG(DAC0,15)
#define DAC0_SR                                  DAC_SR_REG(DAC0)
#define DAC0_C0                                  DAC_C0_REG(DAC0)
#define DAC0_C1                                  DAC_C1_REG(DAC0)
#define DAC0_C2                                  DAC_C2_REG(DAC0)

/* DAC - Register array accessors */
#define DAC0_DATL(index)                         DAC_DATL_REG(DAC0,index)
#define DAC0_DATH(index)                         DAC_DATH_REG(DAC0,index)

/*!
 * @}
 */ /* end of group DAC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group DAC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control Register, offset: 0x0 */
  __I  uint32_t ES;                                /**< Error Status Register, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t ERQ;                               /**< Enable Request Register, offset: 0xC */
       uint8_t RESERVED_1[4];
  __IO uint32_t EEI;                               /**< Enable Error Interrupt Register, offset: 0x14 */
  __O  uint8_t CEEI;                               /**< Clear Enable Error Interrupt Register, offset: 0x18 */
  __O  uint8_t SEEI;                               /**< Set Enable Error Interrupt Register, offset: 0x19 */
  __O  uint8_t CERQ;                               /**< Clear Enable Request Register, offset: 0x1A */
  __O  uint8_t SERQ;                               /**< Set Enable Request Register, offset: 0x1B */
  __O  uint8_t CDNE;                               /**< Clear DONE Status Bit Register, offset: 0x1C */
  __O  uint8_t SSRT;                               /**< Set START Bit Register, offset: 0x1D */
  __O  uint8_t CERR;                               /**< Clear Error Register, offset: 0x1E */
  __O  uint8_t CINT;                               /**< Clear Interrupt Request Register, offset: 0x1F */
       uint8_t RESERVED_2[4];
  __IO uint32_t INT;                               /**< Interrupt Request Register, offset: 0x24 */
       uint8_t RESERVED_3[4];
  __IO uint32_t ERR;                               /**< Error Register, offset: 0x2C */
       uint8_t RESERVED_4[4];
  __I  uint32_t HRS;                               /**< Hardware Request Status Register, offset: 0x34 */
       uint8_t RESERVED_5[12];
  __IO uint32_t EARS;                              /**< Enable Asynchronous Request in Stop Register, offset: 0x44 */
       uint8_t RESERVED_6[184];
  __IO uint8_t DCHPRI3;                            /**< Channel n Priority Register, offset: 0x100 */
  __IO uint8_t DCHPRI2;                            /**< Channel n Priority Register, offset: 0x101 */
  __IO uint8_t DCHPRI1;                            /**< Channel n Priority Register, offset: 0x102 */
  __IO uint8_t DCHPRI0;                            /**< Channel n Priority Register, offset: 0x103 */
  __IO uint8_t DCHPRI7;                            /**< Channel n Priority Register, offset: 0x104 */
  __IO uint8_t DCHPRI6;                            /**< Channel n Priority Register, offset: 0x105 */
  __IO uint8_t DCHPRI5;                            /**< Channel n Priority Register, offset: 0x106 */
  __IO uint8_t DCHPRI4;                            /**< Channel n Priority Register, offset: 0x107 */
       uint8_t RESERVED_7[3832];
  struct {                                         /* offset: 0x1000, array step: 0x20 */
    __IO uint32_t SADDR;                             /**< TCD Source Address, array offset: 0x1000, array step: 0x20 */
    __IO uint16_t SOFF;                              /**< TCD Signed Source Address Offset, array offset: 0x1004, array step: 0x20 */
    __IO uint16_t ATTR;                              /**< TCD Transfer Attributes, array offset: 0x1006, array step: 0x20 */
    union {                                          /* offset: 0x1008, array step: 0x20 */
      __IO uint32_t NBYTES_MLNO;                       /**< TCD Minor Byte Count (Minor Loop Mapping Disabled), array offset: 0x1008, array step: 0x20 */
      __IO uint32_t NBYTES_MLOFFNO;                    /**< TCD Signed Minor Loop Offset (Minor Loop Mapping Enabled and Offset Disabled), array offset: 0x1008, array step: 0x20 */
      __IO uint32_t NBYTES_MLOFFYES;                   /**< TCD Signed Minor Loop Offset (Minor Loop Mapping and Offset Enabled), array offset: 0x1008, array step: 0x20 */
    };
    __IO uint32_t SLAST;                             /**< TCD Last Source Address Adjustment, array offset: 0x100C, array step: 0x20 */
    __IO uint32_t DADDR;                             /**< TCD Destination Address, array offset: 0x1010, array step: 0x20 */
    __IO uint16_t DOFF;                              /**< TCD Signed Destination Address Offset, array offset: 0x1014, array step: 0x20 */
    union {                                          /* offset: 0x1016, array step: 0x20 */
      __IO uint16_t CITER_ELINKNO;                     /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x1016, array step: 0x20 */
      __IO uint16_t CITER_ELINKYES;                    /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x1016, array step: 0x20 */
    };
    __IO uint32_t DLAST_SGA;                         /**< TCD Last Destination Address Adjustment/Scatter Gather Address, array offset: 0x1018, array step: 0x20 */
    __IO uint16_t CSR;                               /**< TCD Control and Status, array offset: 0x101C, array step: 0x20 */
    union {                                          /* offset: 0x101E, array step: 0x20 */
      __IO uint16_t BITER_ELINKNO;                     /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x101E, array step: 0x20 */
      __IO uint16_t BITER_ELINKYES;                    /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x101E, array step: 0x20 */
    };
  } TCD[8];
} DMA_Type, *DMA_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DMA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Accessor_Macros DMA - Register accessor macros
 * @{
 */


/* DMA - Register accessors */
#define DMA_CR_REG(base)                         ((base)->CR)
#define DMA_ES_REG(base)                         ((base)->ES)
#define DMA_ERQ_REG(base)                        ((base)->ERQ)
#define DMA_EEI_REG(base)                        ((base)->EEI)
#define DMA_CEEI_REG(base)                       ((base)->CEEI)
#define DMA_SEEI_REG(base)                       ((base)->SEEI)
#define DMA_CERQ_REG(base)                       ((base)->CERQ)
#define DMA_SERQ_REG(base)                       ((base)->SERQ)
#define DMA_CDNE_REG(base)                       ((base)->CDNE)
#define DMA_SSRT_REG(base)                       ((base)->SSRT)
#define DMA_CERR_REG(base)                       ((base)->CERR)
#define DMA_CINT_REG(base)                       ((base)->CINT)
#define DMA_INT_REG(base)                        ((base)->INT)
#define DMA_ERR_REG(base)                        ((base)->ERR)
#define DMA_HRS_REG(base)                        ((base)->HRS)
#define DMA_EARS_REG(base)                       ((base)->EARS)
#define DMA_DCHPRI3_REG(base)                    ((base)->DCHPRI3)
#define DMA_DCHPRI2_REG(base)                    ((base)->DCHPRI2)
#define DMA_DCHPRI1_REG(base)                    ((base)->DCHPRI1)
#define DMA_DCHPRI0_REG(base)                    ((base)->DCHPRI0)
#define DMA_DCHPRI7_REG(base)                    ((base)->DCHPRI7)
#define DMA_DCHPRI6_REG(base)                    ((base)->DCHPRI6)
#define DMA_DCHPRI5_REG(base)                    ((base)->DCHPRI5)
#define DMA_DCHPRI4_REG(base)                    ((base)->DCHPRI4)
#define DMA_SADDR_REG(base,index)                ((base)->TCD[index].SADDR)
#define DMA_SADDR_COUNT                          8
#define DMA_SOFF_REG(base,index)                 ((base)->TCD[index].SOFF)
#define DMA_SOFF_COUNT                           8
#define DMA_ATTR_REG(base,index)                 ((base)->TCD[index].ATTR)
#define DMA_ATTR_COUNT                           8
#define DMA_NBYTES_MLNO_REG(base,index)          ((base)->TCD[index].NBYTES_MLNO)
#define DMA_NBYTES_MLNO_COUNT                    8
#define DMA_NBYTES_MLOFFNO_REG(base,index)       ((base)->TCD[index].NBYTES_MLOFFNO)
#define DMA_NBYTES_MLOFFNO_COUNT                 8
#define DMA_NBYTES_MLOFFYES_REG(base,index)      ((base)->TCD[index].NBYTES_MLOFFYES)
#define DMA_NBYTES_MLOFFYES_COUNT                8
#define DMA_SLAST_REG(base,index)                ((base)->TCD[index].SLAST)
#define DMA_SLAST_COUNT                          8
#define DMA_DADDR_REG(base,index)                ((base)->TCD[index].DADDR)
#define DMA_DADDR_COUNT                          8
#define DMA_DOFF_REG(base,index)                 ((base)->TCD[index].DOFF)
#define DMA_DOFF_COUNT                           8
#define DMA_CITER_ELINKNO_REG(base,index)        ((base)->TCD[index].CITER_ELINKNO)
#define DMA_CITER_ELINKNO_COUNT                  8
#define DMA_CITER_ELINKYES_REG(base,index)       ((base)->TCD[index].CITER_ELINKYES)
#define DMA_CITER_ELINKYES_COUNT                 8
#define DMA_DLAST_SGA_REG(base,index)            ((base)->TCD[index].DLAST_SGA)
#define DMA_DLAST_SGA_COUNT                      8
#define DMA_CSR_REG(base,index)                  ((base)->TCD[index].CSR)
#define DMA_CSR_COUNT                            8
#define DMA_BITER_ELINKNO_REG(base,index)        ((base)->TCD[index].BITER_ELINKNO)
#define DMA_BITER_ELINKNO_COUNT                  8
#define DMA_BITER_ELINKYES_REG(base,index)       ((base)->TCD[index].BITER_ELINKYES)
#define DMA_BITER_ELINKYES_COUNT                 8

/*!
 * @}
 */ /* end of group DMA_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/* CR Bit Fields */
#define DMA_CR_EDBG_MASK                         0x2u
#define DMA_CR_EDBG_SHIFT                        1
#define DMA_CR_EDBG_WIDTH                        1
#define DMA_CR_EDBG(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_EDBG_SHIFT))&DMA_CR_EDBG_MASK)
#define DMA_CR_ERCA_MASK                         0x4u
#define DMA_CR_ERCA_SHIFT                        2
#define DMA_CR_ERCA_WIDTH                        1
#define DMA_CR_ERCA(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_ERCA_SHIFT))&DMA_CR_ERCA_MASK)
#define DMA_CR_HOE_MASK                          0x10u
#define DMA_CR_HOE_SHIFT                         4
#define DMA_CR_HOE_WIDTH                         1
#define DMA_CR_HOE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_CR_HOE_SHIFT))&DMA_CR_HOE_MASK)
#define DMA_CR_HALT_MASK                         0x20u
#define DMA_CR_HALT_SHIFT                        5
#define DMA_CR_HALT_WIDTH                        1
#define DMA_CR_HALT(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_HALT_SHIFT))&DMA_CR_HALT_MASK)
#define DMA_CR_CLM_MASK                          0x40u
#define DMA_CR_CLM_SHIFT                         6
#define DMA_CR_CLM_WIDTH                         1
#define DMA_CR_CLM(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_CR_CLM_SHIFT))&DMA_CR_CLM_MASK)
#define DMA_CR_EMLM_MASK                         0x80u
#define DMA_CR_EMLM_SHIFT                        7
#define DMA_CR_EMLM_WIDTH                        1
#define DMA_CR_EMLM(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_EMLM_SHIFT))&DMA_CR_EMLM_MASK)
#define DMA_CR_ECX_MASK                          0x10000u
#define DMA_CR_ECX_SHIFT                         16
#define DMA_CR_ECX_WIDTH                         1
#define DMA_CR_ECX(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_CR_ECX_SHIFT))&DMA_CR_ECX_MASK)
#define DMA_CR_CX_MASK                           0x20000u
#define DMA_CR_CX_SHIFT                          17
#define DMA_CR_CX_WIDTH                          1
#define DMA_CR_CX(x)                             (((uint32_t)(((uint32_t)(x))<<DMA_CR_CX_SHIFT))&DMA_CR_CX_MASK)
#define DMA_CR_ACTIVE_MASK                       0x80000000u
#define DMA_CR_ACTIVE_SHIFT                      31
#define DMA_CR_ACTIVE_WIDTH                      1
#define DMA_CR_ACTIVE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CR_ACTIVE_SHIFT))&DMA_CR_ACTIVE_MASK)
/* ES Bit Fields */
#define DMA_ES_DBE_MASK                          0x1u
#define DMA_ES_DBE_SHIFT                         0
#define DMA_ES_DBE_WIDTH                         1
#define DMA_ES_DBE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_DBE_SHIFT))&DMA_ES_DBE_MASK)
#define DMA_ES_SBE_MASK                          0x2u
#define DMA_ES_SBE_SHIFT                         1
#define DMA_ES_SBE_WIDTH                         1
#define DMA_ES_SBE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SBE_SHIFT))&DMA_ES_SBE_MASK)
#define DMA_ES_SGE_MASK                          0x4u
#define DMA_ES_SGE_SHIFT                         2
#define DMA_ES_SGE_WIDTH                         1
#define DMA_ES_SGE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SGE_SHIFT))&DMA_ES_SGE_MASK)
#define DMA_ES_NCE_MASK                          0x8u
#define DMA_ES_NCE_SHIFT                         3
#define DMA_ES_NCE_WIDTH                         1
#define DMA_ES_NCE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_NCE_SHIFT))&DMA_ES_NCE_MASK)
#define DMA_ES_DOE_MASK                          0x10u
#define DMA_ES_DOE_SHIFT                         4
#define DMA_ES_DOE_WIDTH                         1
#define DMA_ES_DOE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_DOE_SHIFT))&DMA_ES_DOE_MASK)
#define DMA_ES_DAE_MASK                          0x20u
#define DMA_ES_DAE_SHIFT                         5
#define DMA_ES_DAE_WIDTH                         1
#define DMA_ES_DAE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_DAE_SHIFT))&DMA_ES_DAE_MASK)
#define DMA_ES_SOE_MASK                          0x40u
#define DMA_ES_SOE_SHIFT                         6
#define DMA_ES_SOE_WIDTH                         1
#define DMA_ES_SOE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SOE_SHIFT))&DMA_ES_SOE_MASK)
#define DMA_ES_SAE_MASK                          0x80u
#define DMA_ES_SAE_SHIFT                         7
#define DMA_ES_SAE_WIDTH                         1
#define DMA_ES_SAE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SAE_SHIFT))&DMA_ES_SAE_MASK)
#define DMA_ES_ERRCHN_MASK                       0x700u
#define DMA_ES_ERRCHN_SHIFT                      8
#define DMA_ES_ERRCHN_WIDTH                      3
#define DMA_ES_ERRCHN(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ES_ERRCHN_SHIFT))&DMA_ES_ERRCHN_MASK)
#define DMA_ES_CPE_MASK                          0x4000u
#define DMA_ES_CPE_SHIFT                         14
#define DMA_ES_CPE_WIDTH                         1
#define DMA_ES_CPE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_CPE_SHIFT))&DMA_ES_CPE_MASK)
#define DMA_ES_ECX_MASK                          0x10000u
#define DMA_ES_ECX_SHIFT                         16
#define DMA_ES_ECX_WIDTH                         1
#define DMA_ES_ECX(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_ECX_SHIFT))&DMA_ES_ECX_MASK)
#define DMA_ES_VLD_MASK                          0x80000000u
#define DMA_ES_VLD_SHIFT                         31
#define DMA_ES_VLD_WIDTH                         1
#define DMA_ES_VLD(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_VLD_SHIFT))&DMA_ES_VLD_MASK)
/* ERQ Bit Fields */
#define DMA_ERQ_ERQ0_MASK                        0x1u
#define DMA_ERQ_ERQ0_SHIFT                       0
#define DMA_ERQ_ERQ0_WIDTH                       1
#define DMA_ERQ_ERQ0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ0_SHIFT))&DMA_ERQ_ERQ0_MASK)
#define DMA_ERQ_ERQ1_MASK                        0x2u
#define DMA_ERQ_ERQ1_SHIFT                       1
#define DMA_ERQ_ERQ1_WIDTH                       1
#define DMA_ERQ_ERQ1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ1_SHIFT))&DMA_ERQ_ERQ1_MASK)
#define DMA_ERQ_ERQ2_MASK                        0x4u
#define DMA_ERQ_ERQ2_SHIFT                       2
#define DMA_ERQ_ERQ2_WIDTH                       1
#define DMA_ERQ_ERQ2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ2_SHIFT))&DMA_ERQ_ERQ2_MASK)
#define DMA_ERQ_ERQ3_MASK                        0x8u
#define DMA_ERQ_ERQ3_SHIFT                       3
#define DMA_ERQ_ERQ3_WIDTH                       1
#define DMA_ERQ_ERQ3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ3_SHIFT))&DMA_ERQ_ERQ3_MASK)
#define DMA_ERQ_ERQ4_MASK                        0x10u
#define DMA_ERQ_ERQ4_SHIFT                       4
#define DMA_ERQ_ERQ4_WIDTH                       1
#define DMA_ERQ_ERQ4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ4_SHIFT))&DMA_ERQ_ERQ4_MASK)
#define DMA_ERQ_ERQ5_MASK                        0x20u
#define DMA_ERQ_ERQ5_SHIFT                       5
#define DMA_ERQ_ERQ5_WIDTH                       1
#define DMA_ERQ_ERQ5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ5_SHIFT))&DMA_ERQ_ERQ5_MASK)
#define DMA_ERQ_ERQ6_MASK                        0x40u
#define DMA_ERQ_ERQ6_SHIFT                       6
#define DMA_ERQ_ERQ6_WIDTH                       1
#define DMA_ERQ_ERQ6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ6_SHIFT))&DMA_ERQ_ERQ6_MASK)
#define DMA_ERQ_ERQ7_MASK                        0x80u
#define DMA_ERQ_ERQ7_SHIFT                       7
#define DMA_ERQ_ERQ7_WIDTH                       1
#define DMA_ERQ_ERQ7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ7_SHIFT))&DMA_ERQ_ERQ7_MASK)
/* EEI Bit Fields */
#define DMA_EEI_EEI0_MASK                        0x1u
#define DMA_EEI_EEI0_SHIFT                       0
#define DMA_EEI_EEI0_WIDTH                       1
#define DMA_EEI_EEI0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI0_SHIFT))&DMA_EEI_EEI0_MASK)
#define DMA_EEI_EEI1_MASK                        0x2u
#define DMA_EEI_EEI1_SHIFT                       1
#define DMA_EEI_EEI1_WIDTH                       1
#define DMA_EEI_EEI1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI1_SHIFT))&DMA_EEI_EEI1_MASK)
#define DMA_EEI_EEI2_MASK                        0x4u
#define DMA_EEI_EEI2_SHIFT                       2
#define DMA_EEI_EEI2_WIDTH                       1
#define DMA_EEI_EEI2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI2_SHIFT))&DMA_EEI_EEI2_MASK)
#define DMA_EEI_EEI3_MASK                        0x8u
#define DMA_EEI_EEI3_SHIFT                       3
#define DMA_EEI_EEI3_WIDTH                       1
#define DMA_EEI_EEI3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI3_SHIFT))&DMA_EEI_EEI3_MASK)
#define DMA_EEI_EEI4_MASK                        0x10u
#define DMA_EEI_EEI4_SHIFT                       4
#define DMA_EEI_EEI4_WIDTH                       1
#define DMA_EEI_EEI4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI4_SHIFT))&DMA_EEI_EEI4_MASK)
#define DMA_EEI_EEI5_MASK                        0x20u
#define DMA_EEI_EEI5_SHIFT                       5
#define DMA_EEI_EEI5_WIDTH                       1
#define DMA_EEI_EEI5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI5_SHIFT))&DMA_EEI_EEI5_MASK)
#define DMA_EEI_EEI6_MASK                        0x40u
#define DMA_EEI_EEI6_SHIFT                       6
#define DMA_EEI_EEI6_WIDTH                       1
#define DMA_EEI_EEI6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI6_SHIFT))&DMA_EEI_EEI6_MASK)
#define DMA_EEI_EEI7_MASK                        0x80u
#define DMA_EEI_EEI7_SHIFT                       7
#define DMA_EEI_EEI7_WIDTH                       1
#define DMA_EEI_EEI7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI7_SHIFT))&DMA_EEI_EEI7_MASK)
/* CEEI Bit Fields */
#define DMA_CEEI_CEEI_MASK                       0x7u
#define DMA_CEEI_CEEI_SHIFT                      0
#define DMA_CEEI_CEEI_WIDTH                      3
#define DMA_CEEI_CEEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_CEEI_SHIFT))&DMA_CEEI_CEEI_MASK)
#define DMA_CEEI_CAEE_MASK                       0x40u
#define DMA_CEEI_CAEE_SHIFT                      6
#define DMA_CEEI_CAEE_WIDTH                      1
#define DMA_CEEI_CAEE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_CAEE_SHIFT))&DMA_CEEI_CAEE_MASK)
#define DMA_CEEI_NOP_MASK                        0x80u
#define DMA_CEEI_NOP_SHIFT                       7
#define DMA_CEEI_NOP_WIDTH                       1
#define DMA_CEEI_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_NOP_SHIFT))&DMA_CEEI_NOP_MASK)
/* SEEI Bit Fields */
#define DMA_SEEI_SEEI_MASK                       0x7u
#define DMA_SEEI_SEEI_SHIFT                      0
#define DMA_SEEI_SEEI_WIDTH                      3
#define DMA_SEEI_SEEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_SEEI_SHIFT))&DMA_SEEI_SEEI_MASK)
#define DMA_SEEI_SAEE_MASK                       0x40u
#define DMA_SEEI_SAEE_SHIFT                      6
#define DMA_SEEI_SAEE_WIDTH                      1
#define DMA_SEEI_SAEE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_SAEE_SHIFT))&DMA_SEEI_SAEE_MASK)
#define DMA_SEEI_NOP_MASK                        0x80u
#define DMA_SEEI_NOP_SHIFT                       7
#define DMA_SEEI_NOP_WIDTH                       1
#define DMA_SEEI_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_NOP_SHIFT))&DMA_SEEI_NOP_MASK)
/* CERQ Bit Fields */
#define DMA_CERQ_CERQ_MASK                       0x7u
#define DMA_CERQ_CERQ_SHIFT                      0
#define DMA_CERQ_CERQ_WIDTH                      3
#define DMA_CERQ_CERQ(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_CERQ_SHIFT))&DMA_CERQ_CERQ_MASK)
#define DMA_CERQ_CAER_MASK                       0x40u
#define DMA_CERQ_CAER_SHIFT                      6
#define DMA_CERQ_CAER_WIDTH                      1
#define DMA_CERQ_CAER(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_CAER_SHIFT))&DMA_CERQ_CAER_MASK)
#define DMA_CERQ_NOP_MASK                        0x80u
#define DMA_CERQ_NOP_SHIFT                       7
#define DMA_CERQ_NOP_WIDTH                       1
#define DMA_CERQ_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_NOP_SHIFT))&DMA_CERQ_NOP_MASK)
/* SERQ Bit Fields */
#define DMA_SERQ_SERQ_MASK                       0x7u
#define DMA_SERQ_SERQ_SHIFT                      0
#define DMA_SERQ_SERQ_WIDTH                      3
#define DMA_SERQ_SERQ(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_SERQ_SHIFT))&DMA_SERQ_SERQ_MASK)
#define DMA_SERQ_SAER_MASK                       0x40u
#define DMA_SERQ_SAER_SHIFT                      6
#define DMA_SERQ_SAER_WIDTH                      1
#define DMA_SERQ_SAER(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_SAER_SHIFT))&DMA_SERQ_SAER_MASK)
#define DMA_SERQ_NOP_MASK                        0x80u
#define DMA_SERQ_NOP_SHIFT                       7
#define DMA_SERQ_NOP_WIDTH                       1
#define DMA_SERQ_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_NOP_SHIFT))&DMA_SERQ_NOP_MASK)
/* CDNE Bit Fields */
#define DMA_CDNE_CDNE_MASK                       0x7u
#define DMA_CDNE_CDNE_SHIFT                      0
#define DMA_CDNE_CDNE_WIDTH                      3
#define DMA_CDNE_CDNE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_CDNE_SHIFT))&DMA_CDNE_CDNE_MASK)
#define DMA_CDNE_CADN_MASK                       0x40u
#define DMA_CDNE_CADN_SHIFT                      6
#define DMA_CDNE_CADN_WIDTH                      1
#define DMA_CDNE_CADN(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_CADN_SHIFT))&DMA_CDNE_CADN_MASK)
#define DMA_CDNE_NOP_MASK                        0x80u
#define DMA_CDNE_NOP_SHIFT                       7
#define DMA_CDNE_NOP_WIDTH                       1
#define DMA_CDNE_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_NOP_SHIFT))&DMA_CDNE_NOP_MASK)
/* SSRT Bit Fields */
#define DMA_SSRT_SSRT_MASK                       0x7u
#define DMA_SSRT_SSRT_SHIFT                      0
#define DMA_SSRT_SSRT_WIDTH                      3
#define DMA_SSRT_SSRT(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_SSRT_SHIFT))&DMA_SSRT_SSRT_MASK)
#define DMA_SSRT_SAST_MASK                       0x40u
#define DMA_SSRT_SAST_SHIFT                      6
#define DMA_SSRT_SAST_WIDTH                      1
#define DMA_SSRT_SAST(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_SAST_SHIFT))&DMA_SSRT_SAST_MASK)
#define DMA_SSRT_NOP_MASK                        0x80u
#define DMA_SSRT_NOP_SHIFT                       7
#define DMA_SSRT_NOP_WIDTH                       1
#define DMA_SSRT_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_NOP_SHIFT))&DMA_SSRT_NOP_MASK)
/* CERR Bit Fields */
#define DMA_CERR_CERR_MASK                       0x7u
#define DMA_CERR_CERR_SHIFT                      0
#define DMA_CERR_CERR_WIDTH                      3
#define DMA_CERR_CERR(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERR_CERR_SHIFT))&DMA_CERR_CERR_MASK)
#define DMA_CERR_CAEI_MASK                       0x40u
#define DMA_CERR_CAEI_SHIFT                      6
#define DMA_CERR_CAEI_WIDTH                      1
#define DMA_CERR_CAEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERR_CAEI_SHIFT))&DMA_CERR_CAEI_MASK)
#define DMA_CERR_NOP_MASK                        0x80u
#define DMA_CERR_NOP_SHIFT                       7
#define DMA_CERR_NOP_WIDTH                       1
#define DMA_CERR_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CERR_NOP_SHIFT))&DMA_CERR_NOP_MASK)
/* CINT Bit Fields */
#define DMA_CINT_CINT_MASK                       0x7u
#define DMA_CINT_CINT_SHIFT                      0
#define DMA_CINT_CINT_WIDTH                      3
#define DMA_CINT_CINT(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CINT_CINT_SHIFT))&DMA_CINT_CINT_MASK)
#define DMA_CINT_CAIR_MASK                       0x40u
#define DMA_CINT_CAIR_SHIFT                      6
#define DMA_CINT_CAIR_WIDTH                      1
#define DMA_CINT_CAIR(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CINT_CAIR_SHIFT))&DMA_CINT_CAIR_MASK)
#define DMA_CINT_NOP_MASK                        0x80u
#define DMA_CINT_NOP_SHIFT                       7
#define DMA_CINT_NOP_WIDTH                       1
#define DMA_CINT_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CINT_NOP_SHIFT))&DMA_CINT_NOP_MASK)
/* INT Bit Fields */
#define DMA_INT_INT0_MASK                        0x1u
#define DMA_INT_INT0_SHIFT                       0
#define DMA_INT_INT0_WIDTH                       1
#define DMA_INT_INT0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT0_SHIFT))&DMA_INT_INT0_MASK)
#define DMA_INT_INT1_MASK                        0x2u
#define DMA_INT_INT1_SHIFT                       1
#define DMA_INT_INT1_WIDTH                       1
#define DMA_INT_INT1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT1_SHIFT))&DMA_INT_INT1_MASK)
#define DMA_INT_INT2_MASK                        0x4u
#define DMA_INT_INT2_SHIFT                       2
#define DMA_INT_INT2_WIDTH                       1
#define DMA_INT_INT2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT2_SHIFT))&DMA_INT_INT2_MASK)
#define DMA_INT_INT3_MASK                        0x8u
#define DMA_INT_INT3_SHIFT                       3
#define DMA_INT_INT3_WIDTH                       1
#define DMA_INT_INT3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT3_SHIFT))&DMA_INT_INT3_MASK)
#define DMA_INT_INT4_MASK                        0x10u
#define DMA_INT_INT4_SHIFT                       4
#define DMA_INT_INT4_WIDTH                       1
#define DMA_INT_INT4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT4_SHIFT))&DMA_INT_INT4_MASK)
#define DMA_INT_INT5_MASK                        0x20u
#define DMA_INT_INT5_SHIFT                       5
#define DMA_INT_INT5_WIDTH                       1
#define DMA_INT_INT5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT5_SHIFT))&DMA_INT_INT5_MASK)
#define DMA_INT_INT6_MASK                        0x40u
#define DMA_INT_INT6_SHIFT                       6
#define DMA_INT_INT6_WIDTH                       1
#define DMA_INT_INT6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT6_SHIFT))&DMA_INT_INT6_MASK)
#define DMA_INT_INT7_MASK                        0x80u
#define DMA_INT_INT7_SHIFT                       7
#define DMA_INT_INT7_WIDTH                       1
#define DMA_INT_INT7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT7_SHIFT))&DMA_INT_INT7_MASK)
/* ERR Bit Fields */
#define DMA_ERR_ERR0_MASK                        0x1u
#define DMA_ERR_ERR0_SHIFT                       0
#define DMA_ERR_ERR0_WIDTH                       1
#define DMA_ERR_ERR0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR0_SHIFT))&DMA_ERR_ERR0_MASK)
#define DMA_ERR_ERR1_MASK                        0x2u
#define DMA_ERR_ERR1_SHIFT                       1
#define DMA_ERR_ERR1_WIDTH                       1
#define DMA_ERR_ERR1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR1_SHIFT))&DMA_ERR_ERR1_MASK)
#define DMA_ERR_ERR2_MASK                        0x4u
#define DMA_ERR_ERR2_SHIFT                       2
#define DMA_ERR_ERR2_WIDTH                       1
#define DMA_ERR_ERR2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR2_SHIFT))&DMA_ERR_ERR2_MASK)
#define DMA_ERR_ERR3_MASK                        0x8u
#define DMA_ERR_ERR3_SHIFT                       3
#define DMA_ERR_ERR3_WIDTH                       1
#define DMA_ERR_ERR3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR3_SHIFT))&DMA_ERR_ERR3_MASK)
#define DMA_ERR_ERR4_MASK                        0x10u
#define DMA_ERR_ERR4_SHIFT                       4
#define DMA_ERR_ERR4_WIDTH                       1
#define DMA_ERR_ERR4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR4_SHIFT))&DMA_ERR_ERR4_MASK)
#define DMA_ERR_ERR5_MASK                        0x20u
#define DMA_ERR_ERR5_SHIFT                       5
#define DMA_ERR_ERR5_WIDTH                       1
#define DMA_ERR_ERR5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR5_SHIFT))&DMA_ERR_ERR5_MASK)
#define DMA_ERR_ERR6_MASK                        0x40u
#define DMA_ERR_ERR6_SHIFT                       6
#define DMA_ERR_ERR6_WIDTH                       1
#define DMA_ERR_ERR6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR6_SHIFT))&DMA_ERR_ERR6_MASK)
#define DMA_ERR_ERR7_MASK                        0x80u
#define DMA_ERR_ERR7_SHIFT                       7
#define DMA_ERR_ERR7_WIDTH                       1
#define DMA_ERR_ERR7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR7_SHIFT))&DMA_ERR_ERR7_MASK)
/* HRS Bit Fields */
#define DMA_HRS_HRS0_MASK                        0x1u
#define DMA_HRS_HRS0_SHIFT                       0
#define DMA_HRS_HRS0_WIDTH                       1
#define DMA_HRS_HRS0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS0_SHIFT))&DMA_HRS_HRS0_MASK)
#define DMA_HRS_HRS1_MASK                        0x2u
#define DMA_HRS_HRS1_SHIFT                       1
#define DMA_HRS_HRS1_WIDTH                       1
#define DMA_HRS_HRS1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS1_SHIFT))&DMA_HRS_HRS1_MASK)
#define DMA_HRS_HRS2_MASK                        0x4u
#define DMA_HRS_HRS2_SHIFT                       2
#define DMA_HRS_HRS2_WIDTH                       1
#define DMA_HRS_HRS2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS2_SHIFT))&DMA_HRS_HRS2_MASK)
#define DMA_HRS_HRS3_MASK                        0x8u
#define DMA_HRS_HRS3_SHIFT                       3
#define DMA_HRS_HRS3_WIDTH                       1
#define DMA_HRS_HRS3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS3_SHIFT))&DMA_HRS_HRS3_MASK)
#define DMA_HRS_HRS4_MASK                        0x10u
#define DMA_HRS_HRS4_SHIFT                       4
#define DMA_HRS_HRS4_WIDTH                       1
#define DMA_HRS_HRS4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS4_SHIFT))&DMA_HRS_HRS4_MASK)
#define DMA_HRS_HRS5_MASK                        0x20u
#define DMA_HRS_HRS5_SHIFT                       5
#define DMA_HRS_HRS5_WIDTH                       1
#define DMA_HRS_HRS5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS5_SHIFT))&DMA_HRS_HRS5_MASK)
#define DMA_HRS_HRS6_MASK                        0x40u
#define DMA_HRS_HRS6_SHIFT                       6
#define DMA_HRS_HRS6_WIDTH                       1
#define DMA_HRS_HRS6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS6_SHIFT))&DMA_HRS_HRS6_MASK)
#define DMA_HRS_HRS7_MASK                        0x80u
#define DMA_HRS_HRS7_SHIFT                       7
#define DMA_HRS_HRS7_WIDTH                       1
#define DMA_HRS_HRS7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS7_SHIFT))&DMA_HRS_HRS7_MASK)
/* EARS Bit Fields */
#define DMA_EARS_EDREQ_0_MASK                    0x1u
#define DMA_EARS_EDREQ_0_SHIFT                   0
#define DMA_EARS_EDREQ_0_WIDTH                   1
#define DMA_EARS_EDREQ_0(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_EARS_EDREQ_0_SHIFT))&DMA_EARS_EDREQ_0_MASK)
#define DMA_EARS_EDREQ_1_MASK                    0x2u
#define DMA_EARS_EDREQ_1_SHIFT                   1
#define DMA_EARS_EDREQ_1_WIDTH                   1
#define DMA_EARS_EDREQ_1(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_EARS_EDREQ_1_SHIFT))&DMA_EARS_EDREQ_1_MASK)
#define DMA_EARS_EDREQ_2_MASK                    0x4u
#define DMA_EARS_EDREQ_2_SHIFT                   2
#define DMA_EARS_EDREQ_2_WIDTH                   1
#define DMA_EARS_EDREQ_2(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_EARS_EDREQ_2_SHIFT))&DMA_EARS_EDREQ_2_MASK)
#define DMA_EARS_EDREQ_3_MASK                    0x8u
#define DMA_EARS_EDREQ_3_SHIFT                   3
#define DMA_EARS_EDREQ_3_WIDTH                   1
#define DMA_EARS_EDREQ_3(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_EARS_EDREQ_3_SHIFT))&DMA_EARS_EDREQ_3_MASK)
#define DMA_EARS_EDREQ_4_MASK                    0x10u
#define DMA_EARS_EDREQ_4_SHIFT                   4
#define DMA_EARS_EDREQ_4_WIDTH                   1
#define DMA_EARS_EDREQ_4(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_EARS_EDREQ_4_SHIFT))&DMA_EARS_EDREQ_4_MASK)
#define DMA_EARS_EDREQ_5_MASK                    0x20u
#define DMA_EARS_EDREQ_5_SHIFT                   5
#define DMA_EARS_EDREQ_5_WIDTH                   1
#define DMA_EARS_EDREQ_5(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_EARS_EDREQ_5_SHIFT))&DMA_EARS_EDREQ_5_MASK)
#define DMA_EARS_EDREQ_6_MASK                    0x40u
#define DMA_EARS_EDREQ_6_SHIFT                   6
#define DMA_EARS_EDREQ_6_WIDTH                   1
#define DMA_EARS_EDREQ_6(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_EARS_EDREQ_6_SHIFT))&DMA_EARS_EDREQ_6_MASK)
#define DMA_EARS_EDREQ_7_MASK                    0x80u
#define DMA_EARS_EDREQ_7_SHIFT                   7
#define DMA_EARS_EDREQ_7_WIDTH                   1
#define DMA_EARS_EDREQ_7(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_EARS_EDREQ_7_SHIFT))&DMA_EARS_EDREQ_7_MASK)
/* DCHPRI3 Bit Fields */
#define DMA_DCHPRI3_CHPRI_MASK                   0x7u
#define DMA_DCHPRI3_CHPRI_SHIFT                  0
#define DMA_DCHPRI3_CHPRI_WIDTH                  3
#define DMA_DCHPRI3_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI3_CHPRI_SHIFT))&DMA_DCHPRI3_CHPRI_MASK)
#define DMA_DCHPRI3_DPA_MASK                     0x40u
#define DMA_DCHPRI3_DPA_SHIFT                    6
#define DMA_DCHPRI3_DPA_WIDTH                    1
#define DMA_DCHPRI3_DPA(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI3_DPA_SHIFT))&DMA_DCHPRI3_DPA_MASK)
#define DMA_DCHPRI3_ECP_MASK                     0x80u
#define DMA_DCHPRI3_ECP_SHIFT                    7
#define DMA_DCHPRI3_ECP_WIDTH                    1
#define DMA_DCHPRI3_ECP(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI3_ECP_SHIFT))&DMA_DCHPRI3_ECP_MASK)
/* DCHPRI2 Bit Fields */
#define DMA_DCHPRI2_CHPRI_MASK                   0x7u
#define DMA_DCHPRI2_CHPRI_SHIFT                  0
#define DMA_DCHPRI2_CHPRI_WIDTH                  3
#define DMA_DCHPRI2_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI2_CHPRI_SHIFT))&DMA_DCHPRI2_CHPRI_MASK)
#define DMA_DCHPRI2_DPA_MASK                     0x40u
#define DMA_DCHPRI2_DPA_SHIFT                    6
#define DMA_DCHPRI2_DPA_WIDTH                    1
#define DMA_DCHPRI2_DPA(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI2_DPA_SHIFT))&DMA_DCHPRI2_DPA_MASK)
#define DMA_DCHPRI2_ECP_MASK                     0x80u
#define DMA_DCHPRI2_ECP_SHIFT                    7
#define DMA_DCHPRI2_ECP_WIDTH                    1
#define DMA_DCHPRI2_ECP(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI2_ECP_SHIFT))&DMA_DCHPRI2_ECP_MASK)
/* DCHPRI1 Bit Fields */
#define DMA_DCHPRI1_CHPRI_MASK                   0x7u
#define DMA_DCHPRI1_CHPRI_SHIFT                  0
#define DMA_DCHPRI1_CHPRI_WIDTH                  3
#define DMA_DCHPRI1_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI1_CHPRI_SHIFT))&DMA_DCHPRI1_CHPRI_MASK)
#define DMA_DCHPRI1_DPA_MASK                     0x40u
#define DMA_DCHPRI1_DPA_SHIFT                    6
#define DMA_DCHPRI1_DPA_WIDTH                    1
#define DMA_DCHPRI1_DPA(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI1_DPA_SHIFT))&DMA_DCHPRI1_DPA_MASK)
#define DMA_DCHPRI1_ECP_MASK                     0x80u
#define DMA_DCHPRI1_ECP_SHIFT                    7
#define DMA_DCHPRI1_ECP_WIDTH                    1
#define DMA_DCHPRI1_ECP(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI1_ECP_SHIFT))&DMA_DCHPRI1_ECP_MASK)
/* DCHPRI0 Bit Fields */
#define DMA_DCHPRI0_CHPRI_MASK                   0x7u
#define DMA_DCHPRI0_CHPRI_SHIFT                  0
#define DMA_DCHPRI0_CHPRI_WIDTH                  3
#define DMA_DCHPRI0_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI0_CHPRI_SHIFT))&DMA_DCHPRI0_CHPRI_MASK)
#define DMA_DCHPRI0_DPA_MASK                     0x40u
#define DMA_DCHPRI0_DPA_SHIFT                    6
#define DMA_DCHPRI0_DPA_WIDTH                    1
#define DMA_DCHPRI0_DPA(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI0_DPA_SHIFT))&DMA_DCHPRI0_DPA_MASK)
#define DMA_DCHPRI0_ECP_MASK                     0x80u
#define DMA_DCHPRI0_ECP_SHIFT                    7
#define DMA_DCHPRI0_ECP_WIDTH                    1
#define DMA_DCHPRI0_ECP(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI0_ECP_SHIFT))&DMA_DCHPRI0_ECP_MASK)
/* DCHPRI7 Bit Fields */
#define DMA_DCHPRI7_CHPRI_MASK                   0x7u
#define DMA_DCHPRI7_CHPRI_SHIFT                  0
#define DMA_DCHPRI7_CHPRI_WIDTH                  3
#define DMA_DCHPRI7_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI7_CHPRI_SHIFT))&DMA_DCHPRI7_CHPRI_MASK)
#define DMA_DCHPRI7_DPA_MASK                     0x40u
#define DMA_DCHPRI7_DPA_SHIFT                    6
#define DMA_DCHPRI7_DPA_WIDTH                    1
#define DMA_DCHPRI7_DPA(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI7_DPA_SHIFT))&DMA_DCHPRI7_DPA_MASK)
#define DMA_DCHPRI7_ECP_MASK                     0x80u
#define DMA_DCHPRI7_ECP_SHIFT                    7
#define DMA_DCHPRI7_ECP_WIDTH                    1
#define DMA_DCHPRI7_ECP(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI7_ECP_SHIFT))&DMA_DCHPRI7_ECP_MASK)
/* DCHPRI6 Bit Fields */
#define DMA_DCHPRI6_CHPRI_MASK                   0x7u
#define DMA_DCHPRI6_CHPRI_SHIFT                  0
#define DMA_DCHPRI6_CHPRI_WIDTH                  3
#define DMA_DCHPRI6_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI6_CHPRI_SHIFT))&DMA_DCHPRI6_CHPRI_MASK)
#define DMA_DCHPRI6_DPA_MASK                     0x40u
#define DMA_DCHPRI6_DPA_SHIFT                    6
#define DMA_DCHPRI6_DPA_WIDTH                    1
#define DMA_DCHPRI6_DPA(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI6_DPA_SHIFT))&DMA_DCHPRI6_DPA_MASK)
#define DMA_DCHPRI6_ECP_MASK                     0x80u
#define DMA_DCHPRI6_ECP_SHIFT                    7
#define DMA_DCHPRI6_ECP_WIDTH                    1
#define DMA_DCHPRI6_ECP(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI6_ECP_SHIFT))&DMA_DCHPRI6_ECP_MASK)
/* DCHPRI5 Bit Fields */
#define DMA_DCHPRI5_CHPRI_MASK                   0x7u
#define DMA_DCHPRI5_CHPRI_SHIFT                  0
#define DMA_DCHPRI5_CHPRI_WIDTH                  3
#define DMA_DCHPRI5_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI5_CHPRI_SHIFT))&DMA_DCHPRI5_CHPRI_MASK)
#define DMA_DCHPRI5_DPA_MASK                     0x40u
#define DMA_DCHPRI5_DPA_SHIFT                    6
#define DMA_DCHPRI5_DPA_WIDTH                    1
#define DMA_DCHPRI5_DPA(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI5_DPA_SHIFT))&DMA_DCHPRI5_DPA_MASK)
#define DMA_DCHPRI5_ECP_MASK                     0x80u
#define DMA_DCHPRI5_ECP_SHIFT                    7
#define DMA_DCHPRI5_ECP_WIDTH                    1
#define DMA_DCHPRI5_ECP(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI5_ECP_SHIFT))&DMA_DCHPRI5_ECP_MASK)
/* DCHPRI4 Bit Fields */
#define DMA_DCHPRI4_CHPRI_MASK                   0x7u
#define DMA_DCHPRI4_CHPRI_SHIFT                  0
#define DMA_DCHPRI4_CHPRI_WIDTH                  3
#define DMA_DCHPRI4_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI4_CHPRI_SHIFT))&DMA_DCHPRI4_CHPRI_MASK)
#define DMA_DCHPRI4_DPA_MASK                     0x40u
#define DMA_DCHPRI4_DPA_SHIFT                    6
#define DMA_DCHPRI4_DPA_WIDTH                    1
#define DMA_DCHPRI4_DPA(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI4_DPA_SHIFT))&DMA_DCHPRI4_DPA_MASK)
#define DMA_DCHPRI4_ECP_MASK                     0x80u
#define DMA_DCHPRI4_ECP_SHIFT                    7
#define DMA_DCHPRI4_ECP_WIDTH                    1
#define DMA_DCHPRI4_ECP(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI4_ECP_SHIFT))&DMA_DCHPRI4_ECP_MASK)
/* SADDR Bit Fields */
#define DMA_SADDR_SADDR_MASK                     0xFFFFFFFFu
#define DMA_SADDR_SADDR_SHIFT                    0
#define DMA_SADDR_SADDR_WIDTH                    32
#define DMA_SADDR_SADDR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_SADDR_SADDR_SHIFT))&DMA_SADDR_SADDR_MASK)
/* SOFF Bit Fields */
#define DMA_SOFF_SOFF_MASK                       0xFFFFu
#define DMA_SOFF_SOFF_SHIFT                      0
#define DMA_SOFF_SOFF_WIDTH                      16
#define DMA_SOFF_SOFF(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_SOFF_SOFF_SHIFT))&DMA_SOFF_SOFF_MASK)
/* ATTR Bit Fields */
#define DMA_ATTR_DSIZE_MASK                      0x7u
#define DMA_ATTR_DSIZE_SHIFT                     0
#define DMA_ATTR_DSIZE_WIDTH                     3
#define DMA_ATTR_DSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_DSIZE_SHIFT))&DMA_ATTR_DSIZE_MASK)
#define DMA_ATTR_DMOD_MASK                       0xF8u
#define DMA_ATTR_DMOD_SHIFT                      3
#define DMA_ATTR_DMOD_WIDTH                      5
#define DMA_ATTR_DMOD(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_DMOD_SHIFT))&DMA_ATTR_DMOD_MASK)
#define DMA_ATTR_SSIZE_MASK                      0x700u
#define DMA_ATTR_SSIZE_SHIFT                     8
#define DMA_ATTR_SSIZE_WIDTH                     3
#define DMA_ATTR_SSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_SSIZE_SHIFT))&DMA_ATTR_SSIZE_MASK)
#define DMA_ATTR_SMOD_MASK                       0xF800u
#define DMA_ATTR_SMOD_SHIFT                      11
#define DMA_ATTR_SMOD_WIDTH                      5
#define DMA_ATTR_SMOD(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_SMOD_SHIFT))&DMA_ATTR_SMOD_MASK)
/* NBYTES_MLNO Bit Fields */
#define DMA_NBYTES_MLNO_NBYTES_MASK              0xFFFFFFFFu
#define DMA_NBYTES_MLNO_NBYTES_SHIFT             0
#define DMA_NBYTES_MLNO_NBYTES_WIDTH             32
#define DMA_NBYTES_MLNO_NBYTES(x)                (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLNO_NBYTES_SHIFT))&DMA_NBYTES_MLNO_NBYTES_MASK)
/* NBYTES_MLOFFNO Bit Fields */
#define DMA_NBYTES_MLOFFNO_NBYTES_MASK           0x3FFFFFFFu
#define DMA_NBYTES_MLOFFNO_NBYTES_SHIFT          0
#define DMA_NBYTES_MLOFFNO_NBYTES_WIDTH          30
#define DMA_NBYTES_MLOFFNO_NBYTES(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_NBYTES_SHIFT))&DMA_NBYTES_MLOFFNO_NBYTES_MASK)
#define DMA_NBYTES_MLOFFNO_DMLOE_MASK            0x40000000u
#define DMA_NBYTES_MLOFFNO_DMLOE_SHIFT           30
#define DMA_NBYTES_MLOFFNO_DMLOE_WIDTH           1
#define DMA_NBYTES_MLOFFNO_DMLOE(x)              (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_DMLOE_SHIFT))&DMA_NBYTES_MLOFFNO_DMLOE_MASK)
#define DMA_NBYTES_MLOFFNO_SMLOE_MASK            0x80000000u
#define DMA_NBYTES_MLOFFNO_SMLOE_SHIFT           31
#define DMA_NBYTES_MLOFFNO_SMLOE_WIDTH           1
#define DMA_NBYTES_MLOFFNO_SMLOE(x)              (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_SMLOE_SHIFT))&DMA_NBYTES_MLOFFNO_SMLOE_MASK)
/* NBYTES_MLOFFYES Bit Fields */
#define DMA_NBYTES_MLOFFYES_NBYTES_MASK          0x3FFu
#define DMA_NBYTES_MLOFFYES_NBYTES_SHIFT         0
#define DMA_NBYTES_MLOFFYES_NBYTES_WIDTH         10
#define DMA_NBYTES_MLOFFYES_NBYTES(x)            (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_NBYTES_SHIFT))&DMA_NBYTES_MLOFFYES_NBYTES_MASK)
#define DMA_NBYTES_MLOFFYES_MLOFF_MASK           0x3FFFFC00u
#define DMA_NBYTES_MLOFFYES_MLOFF_SHIFT          10
#define DMA_NBYTES_MLOFFYES_MLOFF_WIDTH          20
#define DMA_NBYTES_MLOFFYES_MLOFF(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_MLOFF_SHIFT))&DMA_NBYTES_MLOFFYES_MLOFF_MASK)
#define DMA_NBYTES_MLOFFYES_DMLOE_MASK           0x40000000u
#define DMA_NBYTES_MLOFFYES_DMLOE_SHIFT          30
#define DMA_NBYTES_MLOFFYES_DMLOE_WIDTH          1
#define DMA_NBYTES_MLOFFYES_DMLOE(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_DMLOE_SHIFT))&DMA_NBYTES_MLOFFYES_DMLOE_MASK)
#define DMA_NBYTES_MLOFFYES_SMLOE_MASK           0x80000000u
#define DMA_NBYTES_MLOFFYES_SMLOE_SHIFT          31
#define DMA_NBYTES_MLOFFYES_SMLOE_WIDTH          1
#define DMA_NBYTES_MLOFFYES_SMLOE(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_SMLOE_SHIFT))&DMA_NBYTES_MLOFFYES_SMLOE_MASK)
/* SLAST Bit Fields */
#define DMA_SLAST_SLAST_MASK                     0xFFFFFFFFu
#define DMA_SLAST_SLAST_SHIFT                    0
#define DMA_SLAST_SLAST_WIDTH                    32
#define DMA_SLAST_SLAST(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_SLAST_SLAST_SHIFT))&DMA_SLAST_SLAST_MASK)
/* DADDR Bit Fields */
#define DMA_DADDR_DADDR_MASK                     0xFFFFFFFFu
#define DMA_DADDR_DADDR_SHIFT                    0
#define DMA_DADDR_DADDR_WIDTH                    32
#define DMA_DADDR_DADDR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DADDR_DADDR_SHIFT))&DMA_DADDR_DADDR_MASK)
/* DOFF Bit Fields */
#define DMA_DOFF_DOFF_MASK                       0xFFFFu
#define DMA_DOFF_DOFF_SHIFT                      0
#define DMA_DOFF_DOFF_WIDTH                      16
#define DMA_DOFF_DOFF(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_DOFF_DOFF_SHIFT))&DMA_DOFF_DOFF_MASK)
/* CITER_ELINKNO Bit Fields */
#define DMA_CITER_ELINKNO_CITER_MASK             0x7FFFu
#define DMA_CITER_ELINKNO_CITER_SHIFT            0
#define DMA_CITER_ELINKNO_CITER_WIDTH            15
#define DMA_CITER_ELINKNO_CITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKNO_CITER_SHIFT))&DMA_CITER_ELINKNO_CITER_MASK)
#define DMA_CITER_ELINKNO_ELINK_MASK             0x8000u
#define DMA_CITER_ELINKNO_ELINK_SHIFT            15
#define DMA_CITER_ELINKNO_ELINK_WIDTH            1
#define DMA_CITER_ELINKNO_ELINK(x)               (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKNO_ELINK_SHIFT))&DMA_CITER_ELINKNO_ELINK_MASK)
/* CITER_ELINKYES Bit Fields */
#define DMA_CITER_ELINKYES_CITER_MASK            0x1FFu
#define DMA_CITER_ELINKYES_CITER_SHIFT           0
#define DMA_CITER_ELINKYES_CITER_WIDTH           9
#define DMA_CITER_ELINKYES_CITER(x)              (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_CITER_SHIFT))&DMA_CITER_ELINKYES_CITER_MASK)
#define DMA_CITER_ELINKYES_LINKCH_MASK           0xE00u
#define DMA_CITER_ELINKYES_LINKCH_SHIFT          9
#define DMA_CITER_ELINKYES_LINKCH_WIDTH          3
#define DMA_CITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_LINKCH_SHIFT))&DMA_CITER_ELINKYES_LINKCH_MASK)
#define DMA_CITER_ELINKYES_ELINK_MASK            0x8000u
#define DMA_CITER_ELINKYES_ELINK_SHIFT           15
#define DMA_CITER_ELINKYES_ELINK_WIDTH           1
#define DMA_CITER_ELINKYES_ELINK(x)              (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_ELINK_SHIFT))&DMA_CITER_ELINKYES_ELINK_MASK)
/* DLAST_SGA Bit Fields */
#define DMA_DLAST_SGA_DLASTSGA_MASK              0xFFFFFFFFu
#define DMA_DLAST_SGA_DLASTSGA_SHIFT             0
#define DMA_DLAST_SGA_DLASTSGA_WIDTH             32
#define DMA_DLAST_SGA_DLASTSGA(x)                (((uint32_t)(((uint32_t)(x))<<DMA_DLAST_SGA_DLASTSGA_SHIFT))&DMA_DLAST_SGA_DLASTSGA_MASK)
/* CSR Bit Fields */
#define DMA_CSR_START_MASK                       0x1u
#define DMA_CSR_START_SHIFT                      0
#define DMA_CSR_START_WIDTH                      1
#define DMA_CSR_START(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_CSR_START_SHIFT))&DMA_CSR_START_MASK)
#define DMA_CSR_INTMAJOR_MASK                    0x2u
#define DMA_CSR_INTMAJOR_SHIFT                   1
#define DMA_CSR_INTMAJOR_WIDTH                   1
#define DMA_CSR_INTMAJOR(x)                      (((uint16_t)(((uint16_t)(x))<<DMA_CSR_INTMAJOR_SHIFT))&DMA_CSR_INTMAJOR_MASK)
#define DMA_CSR_INTHALF_MASK                     0x4u
#define DMA_CSR_INTHALF_SHIFT                    2
#define DMA_CSR_INTHALF_WIDTH                    1
#define DMA_CSR_INTHALF(x)                       (((uint16_t)(((uint16_t)(x))<<DMA_CSR_INTHALF_SHIFT))&DMA_CSR_INTHALF_MASK)
#define DMA_CSR_DREQ_MASK                        0x8u
#define DMA_CSR_DREQ_SHIFT                       3
#define DMA_CSR_DREQ_WIDTH                       1
#define DMA_CSR_DREQ(x)                          (((uint16_t)(((uint16_t)(x))<<DMA_CSR_DREQ_SHIFT))&DMA_CSR_DREQ_MASK)
#define DMA_CSR_ESG_MASK                         0x10u
#define DMA_CSR_ESG_SHIFT                        4
#define DMA_CSR_ESG_WIDTH                        1
#define DMA_CSR_ESG(x)                           (((uint16_t)(((uint16_t)(x))<<DMA_CSR_ESG_SHIFT))&DMA_CSR_ESG_MASK)
#define DMA_CSR_MAJORELINK_MASK                  0x20u
#define DMA_CSR_MAJORELINK_SHIFT                 5
#define DMA_CSR_MAJORELINK_WIDTH                 1
#define DMA_CSR_MAJORELINK(x)                    (((uint16_t)(((uint16_t)(x))<<DMA_CSR_MAJORELINK_SHIFT))&DMA_CSR_MAJORELINK_MASK)
#define DMA_CSR_ACTIVE_MASK                      0x40u
#define DMA_CSR_ACTIVE_SHIFT                     6
#define DMA_CSR_ACTIVE_WIDTH                     1
#define DMA_CSR_ACTIVE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_CSR_ACTIVE_SHIFT))&DMA_CSR_ACTIVE_MASK)
#define DMA_CSR_DONE_MASK                        0x80u
#define DMA_CSR_DONE_SHIFT                       7
#define DMA_CSR_DONE_WIDTH                       1
#define DMA_CSR_DONE(x)                          (((uint16_t)(((uint16_t)(x))<<DMA_CSR_DONE_SHIFT))&DMA_CSR_DONE_MASK)
#define DMA_CSR_MAJORLINKCH_MASK                 0x700u
#define DMA_CSR_MAJORLINKCH_SHIFT                8
#define DMA_CSR_MAJORLINKCH_WIDTH                3
#define DMA_CSR_MAJORLINKCH(x)                   (((uint16_t)(((uint16_t)(x))<<DMA_CSR_MAJORLINKCH_SHIFT))&DMA_CSR_MAJORLINKCH_MASK)
#define DMA_CSR_BWC_MASK                         0xC000u
#define DMA_CSR_BWC_SHIFT                        14
#define DMA_CSR_BWC_WIDTH                        2
#define DMA_CSR_BWC(x)                           (((uint16_t)(((uint16_t)(x))<<DMA_CSR_BWC_SHIFT))&DMA_CSR_BWC_MASK)
/* BITER_ELINKNO Bit Fields */
#define DMA_BITER_ELINKNO_BITER_MASK             0x7FFFu
#define DMA_BITER_ELINKNO_BITER_SHIFT            0
#define DMA_BITER_ELINKNO_BITER_WIDTH            15
#define DMA_BITER_ELINKNO_BITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKNO_BITER_SHIFT))&DMA_BITER_ELINKNO_BITER_MASK)
#define DMA_BITER_ELINKNO_ELINK_MASK             0x8000u
#define DMA_BITER_ELINKNO_ELINK_SHIFT            15
#define DMA_BITER_ELINKNO_ELINK_WIDTH            1
#define DMA_BITER_ELINKNO_ELINK(x)               (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKNO_ELINK_SHIFT))&DMA_BITER_ELINKNO_ELINK_MASK)
/* BITER_ELINKYES Bit Fields */
#define DMA_BITER_ELINKYES_BITER_MASK            0x1FFu
#define DMA_BITER_ELINKYES_BITER_SHIFT           0
#define DMA_BITER_ELINKYES_BITER_WIDTH           9
#define DMA_BITER_ELINKYES_BITER(x)              (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_BITER_SHIFT))&DMA_BITER_ELINKYES_BITER_MASK)
#define DMA_BITER_ELINKYES_LINKCH_MASK           0xE00u
#define DMA_BITER_ELINKYES_LINKCH_SHIFT          9
#define DMA_BITER_ELINKYES_LINKCH_WIDTH          3
#define DMA_BITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_LINKCH_SHIFT))&DMA_BITER_ELINKYES_LINKCH_MASK)
#define DMA_BITER_ELINKYES_ELINK_MASK            0x8000u
#define DMA_BITER_ELINKYES_ELINK_SHIFT           15
#define DMA_BITER_ELINKYES_ELINK_WIDTH           1
#define DMA_BITER_ELINKYES_ELINK(x)              (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_ELINK_SHIFT))&DMA_BITER_ELINKYES_ELINK_MASK)

/*!
 * @}
 */ /* end of group DMA_Register_Masks */


/* DMA - Peripheral instance base addresses */
/** Peripheral DMA0 base address */
#define DMA0_BASE                                (0x40008000u)
/** Peripheral DMA0 base pointer */
#define DMA0                                     ((DMA_Type *)DMA0_BASE)
#define DMA0_BASE_PTR                            (DMA0)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA0_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA0 }

/* ----------------------------------------------------------------------------
   -- DMA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Accessor_Macros DMA - Register accessor macros
 * @{
 */


/* DMA - Register instance definitions */
/* DMA0 */
#define DMA0_CR                                  DMA_CR_REG(DMA0)
#define DMA0_ES                                  DMA_ES_REG(DMA0)
#define DMA0_ERQ                                 DMA_ERQ_REG(DMA0)
#define DMA0_EEI                                 DMA_EEI_REG(DMA0)
#define DMA0_CEEI                                DMA_CEEI_REG(DMA0)
#define DMA0_SEEI                                DMA_SEEI_REG(DMA0)
#define DMA0_CERQ                                DMA_CERQ_REG(DMA0)
#define DMA0_SERQ                                DMA_SERQ_REG(DMA0)
#define DMA0_CDNE                                DMA_CDNE_REG(DMA0)
#define DMA0_SSRT                                DMA_SSRT_REG(DMA0)
#define DMA0_CERR                                DMA_CERR_REG(DMA0)
#define DMA0_CINT                                DMA_CINT_REG(DMA0)
#define DMA0_INT                                 DMA_INT_REG(DMA0)
#define DMA0_ERR                                 DMA_ERR_REG(DMA0)
#define DMA0_HRS                                 DMA_HRS_REG(DMA0)
#define DMA0_EARS                                DMA_EARS_REG(DMA0)
#define DMA0_DCHPRI3                             DMA_DCHPRI3_REG(DMA0)
#define DMA0_DCHPRI2                             DMA_DCHPRI2_REG(DMA0)
#define DMA0_DCHPRI1                             DMA_DCHPRI1_REG(DMA0)
#define DMA0_DCHPRI0                             DMA_DCHPRI0_REG(DMA0)
#define DMA0_DCHPRI7                             DMA_DCHPRI7_REG(DMA0)
#define DMA0_DCHPRI6                             DMA_DCHPRI6_REG(DMA0)
#define DMA0_DCHPRI5                             DMA_DCHPRI5_REG(DMA0)
#define DMA0_DCHPRI4                             DMA_DCHPRI4_REG(DMA0)
#define DMA0_TCD0_SADDR                          DMA_SADDR_REG(DMA0,0)
#define DMA0_TCD0_SOFF                           DMA_SOFF_REG(DMA0,0)
#define DMA0_TCD0_ATTR                           DMA_ATTR_REG(DMA0,0)
#define DMA0_TCD0_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA0,0)
#define DMA0_TCD0_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA0,0)
#define DMA0_TCD0_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA0,0)
#define DMA0_TCD0_SLAST                          DMA_SLAST_REG(DMA0,0)
#define DMA0_TCD0_DADDR                          DMA_DADDR_REG(DMA0,0)
#define DMA0_TCD0_DOFF                           DMA_DOFF_REG(DMA0,0)
#define DMA0_TCD0_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA0,0)
#define DMA0_TCD0_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA0,0)
#define DMA0_TCD0_DLASTSGA                       DMA_DLAST_SGA_REG(DMA0,0)
#define DMA0_TCD0_CSR                            DMA_CSR_REG(DMA0,0)
#define DMA0_TCD0_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA0,0)
#define DMA0_TCD0_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA0,0)
#define DMA0_TCD1_SADDR                          DMA_SADDR_REG(DMA0,1)
#define DMA0_TCD1_SOFF                           DMA_SOFF_REG(DMA0,1)
#define DMA0_TCD1_ATTR                           DMA_ATTR_REG(DMA0,1)
#define DMA0_TCD1_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA0,1)
#define DMA0_TCD1_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA0,1)
#define DMA0_TCD1_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA0,1)
#define DMA0_TCD1_SLAST                          DMA_SLAST_REG(DMA0,1)
#define DMA0_TCD1_DADDR                          DMA_DADDR_REG(DMA0,1)
#define DMA0_TCD1_DOFF                           DMA_DOFF_REG(DMA0,1)
#define DMA0_TCD1_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA0,1)
#define DMA0_TCD1_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA0,1)
#define DMA0_TCD1_DLASTSGA                       DMA_DLAST_SGA_REG(DMA0,1)
#define DMA0_TCD1_CSR                            DMA_CSR_REG(DMA0,1)
#define DMA0_TCD1_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA0,1)
#define DMA0_TCD1_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA0,1)
#define DMA0_TCD2_SADDR                          DMA_SADDR_REG(DMA0,2)
#define DMA0_TCD2_SOFF                           DMA_SOFF_REG(DMA0,2)
#define DMA0_TCD2_ATTR                           DMA_ATTR_REG(DMA0,2)
#define DMA0_TCD2_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA0,2)
#define DMA0_TCD2_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA0,2)
#define DMA0_TCD2_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA0,2)
#define DMA0_TCD2_SLAST                          DMA_SLAST_REG(DMA0,2)
#define DMA0_TCD2_DADDR                          DMA_DADDR_REG(DMA0,2)
#define DMA0_TCD2_DOFF                           DMA_DOFF_REG(DMA0,2)
#define DMA0_TCD2_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA0,2)
#define DMA0_TCD2_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA0,2)
#define DMA0_TCD2_DLASTSGA                       DMA_DLAST_SGA_REG(DMA0,2)
#define DMA0_TCD2_CSR                            DMA_CSR_REG(DMA0,2)
#define DMA0_TCD2_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA0,2)
#define DMA0_TCD2_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA0,2)
#define DMA0_TCD3_SADDR                          DMA_SADDR_REG(DMA0,3)
#define DMA0_TCD3_SOFF                           DMA_SOFF_REG(DMA0,3)
#define DMA0_TCD3_ATTR                           DMA_ATTR_REG(DMA0,3)
#define DMA0_TCD3_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA0,3)
#define DMA0_TCD3_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA0,3)
#define DMA0_TCD3_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA0,3)
#define DMA0_TCD3_SLAST                          DMA_SLAST_REG(DMA0,3)
#define DMA0_TCD3_DADDR                          DMA_DADDR_REG(DMA0,3)
#define DMA0_TCD3_DOFF                           DMA_DOFF_REG(DMA0,3)
#define DMA0_TCD3_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA0,3)
#define DMA0_TCD3_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA0,3)
#define DMA0_TCD3_DLASTSGA                       DMA_DLAST_SGA_REG(DMA0,3)
#define DMA0_TCD3_CSR                            DMA_CSR_REG(DMA0,3)
#define DMA0_TCD3_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA0,3)
#define DMA0_TCD3_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA0,3)
#define DMA0_TCD4_SADDR                          DMA_SADDR_REG(DMA0,4)
#define DMA0_TCD4_SOFF                           DMA_SOFF_REG(DMA0,4)
#define DMA0_TCD4_ATTR                           DMA_ATTR_REG(DMA0,4)
#define DMA0_TCD4_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA0,4)
#define DMA0_TCD4_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA0,4)
#define DMA0_TCD4_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA0,4)
#define DMA0_TCD4_SLAST                          DMA_SLAST_REG(DMA0,4)
#define DMA0_TCD4_DADDR                          DMA_DADDR_REG(DMA0,4)
#define DMA0_TCD4_DOFF                           DMA_DOFF_REG(DMA0,4)
#define DMA0_TCD4_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA0,4)
#define DMA0_TCD4_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA0,4)
#define DMA0_TCD4_DLASTSGA                       DMA_DLAST_SGA_REG(DMA0,4)
#define DMA0_TCD4_CSR                            DMA_CSR_REG(DMA0,4)
#define DMA0_TCD4_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA0,4)
#define DMA0_TCD4_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA0,4)
#define DMA0_TCD5_SADDR                          DMA_SADDR_REG(DMA0,5)
#define DMA0_TCD5_SOFF                           DMA_SOFF_REG(DMA0,5)
#define DMA0_TCD5_ATTR                           DMA_ATTR_REG(DMA0,5)
#define DMA0_TCD5_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA0,5)
#define DMA0_TCD5_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA0,5)
#define DMA0_TCD5_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA0,5)
#define DMA0_TCD5_SLAST                          DMA_SLAST_REG(DMA0,5)
#define DMA0_TCD5_DADDR                          DMA_DADDR_REG(DMA0,5)
#define DMA0_TCD5_DOFF                           DMA_DOFF_REG(DMA0,5)
#define DMA0_TCD5_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA0,5)
#define DMA0_TCD5_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA0,5)
#define DMA0_TCD5_DLASTSGA                       DMA_DLAST_SGA_REG(DMA0,5)
#define DMA0_TCD5_CSR                            DMA_CSR_REG(DMA0,5)
#define DMA0_TCD5_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA0,5)
#define DMA0_TCD5_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA0,5)
#define DMA0_TCD6_SADDR                          DMA_SADDR_REG(DMA0,6)
#define DMA0_TCD6_SOFF                           DMA_SOFF_REG(DMA0,6)
#define DMA0_TCD6_ATTR                           DMA_ATTR_REG(DMA0,6)
#define DMA0_TCD6_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA0,6)
#define DMA0_TCD6_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA0,6)
#define DMA0_TCD6_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA0,6)
#define DMA0_TCD6_SLAST                          DMA_SLAST_REG(DMA0,6)
#define DMA0_TCD6_DADDR                          DMA_DADDR_REG(DMA0,6)
#define DMA0_TCD6_DOFF                           DMA_DOFF_REG(DMA0,6)
#define DMA0_TCD6_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA0,6)
#define DMA0_TCD6_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA0,6)
#define DMA0_TCD6_DLASTSGA                       DMA_DLAST_SGA_REG(DMA0,6)
#define DMA0_TCD6_CSR                            DMA_CSR_REG(DMA0,6)
#define DMA0_TCD6_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA0,6)
#define DMA0_TCD6_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA0,6)
#define DMA0_TCD7_SADDR                          DMA_SADDR_REG(DMA0,7)
#define DMA0_TCD7_SOFF                           DMA_SOFF_REG(DMA0,7)
#define DMA0_TCD7_ATTR                           DMA_ATTR_REG(DMA0,7)
#define DMA0_TCD7_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA0,7)
#define DMA0_TCD7_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA0,7)
#define DMA0_TCD7_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA0,7)
#define DMA0_TCD7_SLAST                          DMA_SLAST_REG(DMA0,7)
#define DMA0_TCD7_DADDR                          DMA_DADDR_REG(DMA0,7)
#define DMA0_TCD7_DOFF                           DMA_DOFF_REG(DMA0,7)
#define DMA0_TCD7_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA0,7)
#define DMA0_TCD7_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA0,7)
#define DMA0_TCD7_DLASTSGA                       DMA_DLAST_SGA_REG(DMA0,7)
#define DMA0_TCD7_CSR                            DMA_CSR_REG(DMA0,7)
#define DMA0_TCD7_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA0,7)
#define DMA0_TCD7_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA0,7)

/* DMA - Register array accessors */
#define DMA0_SADDR(index)                        DMA_SADDR_REG(DMA0,index)
#define DMA0_SOFF(index)                         DMA_SOFF_REG(DMA0,index)
#define DMA0_ATTR(index)                         DMA_ATTR_REG(DMA0,index)
#define DMA0_NBYTES_MLNO(index)                  DMA_NBYTES_MLNO_REG(DMA0,index)
#define DMA0_NBYTES_MLOFFNO(index)               DMA_NBYTES_MLOFFNO_REG(DMA0,index)
#define DMA0_NBYTES_MLOFFYES(index)              DMA_NBYTES_MLOFFYES_REG(DMA0,index)
#define DMA0_SLAST(index)                        DMA_SLAST_REG(DMA0,index)
#define DMA0_DADDR(index)                        DMA_DADDR_REG(DMA0,index)
#define DMA0_DOFF(index)                         DMA_DOFF_REG(DMA0,index)
#define DMA0_CITER_ELINKNO(index)                DMA_CITER_ELINKNO_REG(DMA0,index)
#define DMA0_CITER_ELINKYES(index)               DMA_CITER_ELINKYES_REG(DMA0,index)
#define DMA0_DLAST_SGA(index)                    DMA_DLAST_SGA_REG(DMA0,index)
#define DMA0_CSR(index)                          DMA_CSR_REG(DMA0,index)
#define DMA0_BITER_ELINKNO(index)                DMA_BITER_ELINKNO_REG(DMA0,index)
#define DMA0_BITER_ELINKYES(index)               DMA_BITER_ELINKYES_REG(DMA0,index)

/*!
 * @}
 */ /* end of group DMA_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group DMA_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DMAMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Peripheral_Access_Layer DMAMUX Peripheral Access Layer
 * @{
 */

/** DMAMUX - Register Layout Typedef */
typedef struct {
  __IO uint8_t CHCFG[8];                           /**< Channel Configuration register, array offset: 0x0, array step: 0x1 */
} DMAMUX_Type, *DMAMUX_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DMAMUX - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Accessor_Macros DMAMUX - Register accessor macros
 * @{
 */


/* DMAMUX - Register accessors */
#define DMAMUX_CHCFG_REG(base,index)             ((base)->CHCFG[index])
#define DMAMUX_CHCFG_COUNT                       8

/*!
 * @}
 */ /* end of group DMAMUX_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Masks DMAMUX Register Masks
 * @{
 */

/* CHCFG Bit Fields */
#define DMAMUX_CHCFG_SOURCE_MASK                 0x3Fu
#define DMAMUX_CHCFG_SOURCE_SHIFT                0
#define DMAMUX_CHCFG_SOURCE_WIDTH                6
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_SOURCE_SHIFT))&DMAMUX_CHCFG_SOURCE_MASK)
#define DMAMUX_CHCFG_TRIG_MASK                   0x40u
#define DMAMUX_CHCFG_TRIG_SHIFT                  6
#define DMAMUX_CHCFG_TRIG_WIDTH                  1
#define DMAMUX_CHCFG_TRIG(x)                     (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_TRIG_SHIFT))&DMAMUX_CHCFG_TRIG_MASK)
#define DMAMUX_CHCFG_ENBL_MASK                   0x80u
#define DMAMUX_CHCFG_ENBL_SHIFT                  7
#define DMAMUX_CHCFG_ENBL_WIDTH                  1
#define DMAMUX_CHCFG_ENBL(x)                     (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_ENBL_SHIFT))&DMAMUX_CHCFG_ENBL_MASK)

/*!
 * @}
 */ /* end of group DMAMUX_Register_Masks */


/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX0 base address */
#define DMAMUX0_BASE                             (0x40021000u)
/** Peripheral DMAMUX0 base pointer */
#define DMAMUX0                                  ((DMAMUX_Type *)DMAMUX0_BASE)
#define DMAMUX0_BASE_PTR                         (DMAMUX0)
/** Array initializer of DMAMUX peripheral base addresses */
#define DMAMUX_BASE_ADDRS                        { DMAMUX0_BASE }
/** Array initializer of DMAMUX peripheral base pointers */
#define DMAMUX_BASE_PTRS                         { DMAMUX0 }

/* ----------------------------------------------------------------------------
   -- DMAMUX - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Accessor_Macros DMAMUX - Register accessor macros
 * @{
 */


/* DMAMUX - Register instance definitions */
/* DMAMUX0 */
#define DMAMUX0_CHCFG0                           DMAMUX_CHCFG_REG(DMAMUX0,0)
#define DMAMUX0_CHCFG1                           DMAMUX_CHCFG_REG(DMAMUX0,1)
#define DMAMUX0_CHCFG2                           DMAMUX_CHCFG_REG(DMAMUX0,2)
#define DMAMUX0_CHCFG3                           DMAMUX_CHCFG_REG(DMAMUX0,3)
#define DMAMUX0_CHCFG4                           DMAMUX_CHCFG_REG(DMAMUX0,4)
#define DMAMUX0_CHCFG5                           DMAMUX_CHCFG_REG(DMAMUX0,5)
#define DMAMUX0_CHCFG6                           DMAMUX_CHCFG_REG(DMAMUX0,6)
#define DMAMUX0_CHCFG7                           DMAMUX_CHCFG_REG(DMAMUX0,7)

/* DMAMUX - Register array accessors */
#define DMAMUX0_CHCFG(index)                     DMAMUX_CHCFG_REG(DMAMUX0,index)

/*!
 * @}
 */ /* end of group DMAMUX_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group DMAMUX_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- EMVSIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EMVSIM_Peripheral_Access_Layer EMVSIM Peripheral Access Layer
 * @{
 */

/** EMVSIM - Register Layout Typedef */
typedef struct {
  __I  uint32_t VER_ID;                            /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t CLKCFG;                            /**< Clock Configuration Register, offset: 0x8 */
  __IO uint32_t DIVISOR;                           /**< Baud Rate Divisor Register, offset: 0xC */
  __IO uint32_t CTRL;                              /**< Control Register, offset: 0x10 */
  __IO uint32_t INT_MASK;                          /**< Interrupt Mask Register, offset: 0x14 */
  __IO uint32_t RX_THD;                            /**< Receiver Threshold Register, offset: 0x18 */
  __IO uint32_t TX_THD;                            /**< Transmitter Threshold Register, offset: 0x1C */
  __IO uint32_t RX_STATUS;                         /**< Receive Status Register, offset: 0x20 */
  __IO uint32_t TX_STATUS;                         /**< Transmitter Status Register, offset: 0x24 */
  __IO uint32_t PCSR;                              /**< Port Control and Status Register, offset: 0x28 */
  __I  uint32_t RX_BUF;                            /**< Receive Data Read Buffer, offset: 0x2C */
  __IO uint32_t TX_BUF;                            /**< Transmit Data Buffer, offset: 0x30 */
  __IO uint32_t TX_GETU;                           /**< Transmitter Guard ETU Value Register, offset: 0x34 */
  __IO uint32_t CWT_VAL;                           /**< Character Wait Time Value Register, offset: 0x38 */
  __IO uint32_t BWT_VAL;                           /**< Block Wait Time Value Register, offset: 0x3C */
  __IO uint32_t BGT_VAL;                           /**< Block Guard Time Value Register, offset: 0x40 */
  __IO uint32_t GPCNT0_VAL;                        /**< General Purpose Counter 0 Timeout Value Register, offset: 0x44 */
  __IO uint32_t GPCNT1_VAL;                        /**< General Purpose Counter 1 Timeout Value, offset: 0x48 */
} EMVSIM_Type, *EMVSIM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- EMVSIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EMVSIM_Register_Accessor_Macros EMVSIM - Register accessor macros
 * @{
 */


/* EMVSIM - Register accessors */
#define EMVSIM_VER_ID_REG(base)                  ((base)->VER_ID)
#define EMVSIM_PARAM_REG(base)                   ((base)->PARAM)
#define EMVSIM_CLKCFG_REG(base)                  ((base)->CLKCFG)
#define EMVSIM_DIVISOR_REG(base)                 ((base)->DIVISOR)
#define EMVSIM_CTRL_REG(base)                    ((base)->CTRL)
#define EMVSIM_INT_MASK_REG(base)                ((base)->INT_MASK)
#define EMVSIM_RX_THD_REG(base)                  ((base)->RX_THD)
#define EMVSIM_TX_THD_REG(base)                  ((base)->TX_THD)
#define EMVSIM_RX_STATUS_REG(base)               ((base)->RX_STATUS)
#define EMVSIM_TX_STATUS_REG(base)               ((base)->TX_STATUS)
#define EMVSIM_PCSR_REG(base)                    ((base)->PCSR)
#define EMVSIM_RX_BUF_REG(base)                  ((base)->RX_BUF)
#define EMVSIM_TX_BUF_REG(base)                  ((base)->TX_BUF)
#define EMVSIM_TX_GETU_REG(base)                 ((base)->TX_GETU)
#define EMVSIM_CWT_VAL_REG(base)                 ((base)->CWT_VAL)
#define EMVSIM_BWT_VAL_REG(base)                 ((base)->BWT_VAL)
#define EMVSIM_BGT_VAL_REG(base)                 ((base)->BGT_VAL)
#define EMVSIM_GPCNT0_VAL_REG(base)              ((base)->GPCNT0_VAL)
#define EMVSIM_GPCNT1_VAL_REG(base)              ((base)->GPCNT1_VAL)

/*!
 * @}
 */ /* end of group EMVSIM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- EMVSIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EMVSIM_Register_Masks EMVSIM Register Masks
 * @{
 */

/* VER_ID Bit Fields */
#define EMVSIM_VER_ID_VER_MASK                   0xFFFFFFFFu
#define EMVSIM_VER_ID_VER_SHIFT                  0
#define EMVSIM_VER_ID_VER_WIDTH                  32
#define EMVSIM_VER_ID_VER(x)                     (((uint32_t)(((uint32_t)(x))<<EMVSIM_VER_ID_VER_SHIFT))&EMVSIM_VER_ID_VER_MASK)
/* PARAM Bit Fields */
#define EMVSIM_PARAM_RX_FIFO_DEPTH_MASK          0xFFu
#define EMVSIM_PARAM_RX_FIFO_DEPTH_SHIFT         0
#define EMVSIM_PARAM_RX_FIFO_DEPTH_WIDTH         8
#define EMVSIM_PARAM_RX_FIFO_DEPTH(x)            (((uint32_t)(((uint32_t)(x))<<EMVSIM_PARAM_RX_FIFO_DEPTH_SHIFT))&EMVSIM_PARAM_RX_FIFO_DEPTH_MASK)
#define EMVSIM_PARAM_TX_FIFO_DEPTH_MASK          0xFF00u
#define EMVSIM_PARAM_TX_FIFO_DEPTH_SHIFT         8
#define EMVSIM_PARAM_TX_FIFO_DEPTH_WIDTH         8
#define EMVSIM_PARAM_TX_FIFO_DEPTH(x)            (((uint32_t)(((uint32_t)(x))<<EMVSIM_PARAM_TX_FIFO_DEPTH_SHIFT))&EMVSIM_PARAM_TX_FIFO_DEPTH_MASK)
/* CLKCFG Bit Fields */
#define EMVSIM_CLKCFG_CLK_PRSC_MASK              0xFFu
#define EMVSIM_CLKCFG_CLK_PRSC_SHIFT             0
#define EMVSIM_CLKCFG_CLK_PRSC_WIDTH             8
#define EMVSIM_CLKCFG_CLK_PRSC(x)                (((uint32_t)(((uint32_t)(x))<<EMVSIM_CLKCFG_CLK_PRSC_SHIFT))&EMVSIM_CLKCFG_CLK_PRSC_MASK)
#define EMVSIM_CLKCFG_GPCNT1_CLK_SEL_MASK        0x300u
#define EMVSIM_CLKCFG_GPCNT1_CLK_SEL_SHIFT       8
#define EMVSIM_CLKCFG_GPCNT1_CLK_SEL_WIDTH       2
#define EMVSIM_CLKCFG_GPCNT1_CLK_SEL(x)          (((uint32_t)(((uint32_t)(x))<<EMVSIM_CLKCFG_GPCNT1_CLK_SEL_SHIFT))&EMVSIM_CLKCFG_GPCNT1_CLK_SEL_MASK)
#define EMVSIM_CLKCFG_GPCNT0_CLK_SEL_MASK        0xC00u
#define EMVSIM_CLKCFG_GPCNT0_CLK_SEL_SHIFT       10
#define EMVSIM_CLKCFG_GPCNT0_CLK_SEL_WIDTH       2
#define EMVSIM_CLKCFG_GPCNT0_CLK_SEL(x)          (((uint32_t)(((uint32_t)(x))<<EMVSIM_CLKCFG_GPCNT0_CLK_SEL_SHIFT))&EMVSIM_CLKCFG_GPCNT0_CLK_SEL_MASK)
/* DIVISOR Bit Fields */
#define EMVSIM_DIVISOR_DIVISOR_VALUE_MASK        0x1FFu
#define EMVSIM_DIVISOR_DIVISOR_VALUE_SHIFT       0
#define EMVSIM_DIVISOR_DIVISOR_VALUE_WIDTH       9
#define EMVSIM_DIVISOR_DIVISOR_VALUE(x)          (((uint32_t)(((uint32_t)(x))<<EMVSIM_DIVISOR_DIVISOR_VALUE_SHIFT))&EMVSIM_DIVISOR_DIVISOR_VALUE_MASK)
/* CTRL Bit Fields */
#define EMVSIM_CTRL_IC_MASK                      0x1u
#define EMVSIM_CTRL_IC_SHIFT                     0
#define EMVSIM_CTRL_IC_WIDTH                     1
#define EMVSIM_CTRL_IC(x)                        (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_IC_SHIFT))&EMVSIM_CTRL_IC_MASK)
#define EMVSIM_CTRL_ICM_MASK                     0x2u
#define EMVSIM_CTRL_ICM_SHIFT                    1
#define EMVSIM_CTRL_ICM_WIDTH                    1
#define EMVSIM_CTRL_ICM(x)                       (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_ICM_SHIFT))&EMVSIM_CTRL_ICM_MASK)
#define EMVSIM_CTRL_ANACK_MASK                   0x4u
#define EMVSIM_CTRL_ANACK_SHIFT                  2
#define EMVSIM_CTRL_ANACK_WIDTH                  1
#define EMVSIM_CTRL_ANACK(x)                     (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_ANACK_SHIFT))&EMVSIM_CTRL_ANACK_MASK)
#define EMVSIM_CTRL_ONACK_MASK                   0x8u
#define EMVSIM_CTRL_ONACK_SHIFT                  3
#define EMVSIM_CTRL_ONACK_WIDTH                  1
#define EMVSIM_CTRL_ONACK(x)                     (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_ONACK_SHIFT))&EMVSIM_CTRL_ONACK_MASK)
#define EMVSIM_CTRL_FLSH_RX_MASK                 0x100u
#define EMVSIM_CTRL_FLSH_RX_SHIFT                8
#define EMVSIM_CTRL_FLSH_RX_WIDTH                1
#define EMVSIM_CTRL_FLSH_RX(x)                   (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_FLSH_RX_SHIFT))&EMVSIM_CTRL_FLSH_RX_MASK)
#define EMVSIM_CTRL_FLSH_TX_MASK                 0x200u
#define EMVSIM_CTRL_FLSH_TX_SHIFT                9
#define EMVSIM_CTRL_FLSH_TX_WIDTH                1
#define EMVSIM_CTRL_FLSH_TX(x)                   (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_FLSH_TX_SHIFT))&EMVSIM_CTRL_FLSH_TX_MASK)
#define EMVSIM_CTRL_SW_RST_MASK                  0x400u
#define EMVSIM_CTRL_SW_RST_SHIFT                 10
#define EMVSIM_CTRL_SW_RST_WIDTH                 1
#define EMVSIM_CTRL_SW_RST(x)                    (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_SW_RST_SHIFT))&EMVSIM_CTRL_SW_RST_MASK)
#define EMVSIM_CTRL_KILL_CLOCKS_MASK             0x800u
#define EMVSIM_CTRL_KILL_CLOCKS_SHIFT            11
#define EMVSIM_CTRL_KILL_CLOCKS_WIDTH            1
#define EMVSIM_CTRL_KILL_CLOCKS(x)               (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_KILL_CLOCKS_SHIFT))&EMVSIM_CTRL_KILL_CLOCKS_MASK)
#define EMVSIM_CTRL_DOZE_EN_MASK                 0x1000u
#define EMVSIM_CTRL_DOZE_EN_SHIFT                12
#define EMVSIM_CTRL_DOZE_EN_WIDTH                1
#define EMVSIM_CTRL_DOZE_EN(x)                   (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_DOZE_EN_SHIFT))&EMVSIM_CTRL_DOZE_EN_MASK)
#define EMVSIM_CTRL_STOP_EN_MASK                 0x2000u
#define EMVSIM_CTRL_STOP_EN_SHIFT                13
#define EMVSIM_CTRL_STOP_EN_WIDTH                1
#define EMVSIM_CTRL_STOP_EN(x)                   (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_STOP_EN_SHIFT))&EMVSIM_CTRL_STOP_EN_MASK)
#define EMVSIM_CTRL_RCV_EN_MASK                  0x10000u
#define EMVSIM_CTRL_RCV_EN_SHIFT                 16
#define EMVSIM_CTRL_RCV_EN_WIDTH                 1
#define EMVSIM_CTRL_RCV_EN(x)                    (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_RCV_EN_SHIFT))&EMVSIM_CTRL_RCV_EN_MASK)
#define EMVSIM_CTRL_XMT_EN_MASK                  0x20000u
#define EMVSIM_CTRL_XMT_EN_SHIFT                 17
#define EMVSIM_CTRL_XMT_EN_WIDTH                 1
#define EMVSIM_CTRL_XMT_EN(x)                    (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_XMT_EN_SHIFT))&EMVSIM_CTRL_XMT_EN_MASK)
#define EMVSIM_CTRL_RCVR_11_MASK                 0x40000u
#define EMVSIM_CTRL_RCVR_11_SHIFT                18
#define EMVSIM_CTRL_RCVR_11_WIDTH                1
#define EMVSIM_CTRL_RCVR_11(x)                   (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_RCVR_11_SHIFT))&EMVSIM_CTRL_RCVR_11_MASK)
#define EMVSIM_CTRL_RX_DMA_EN_MASK               0x80000u
#define EMVSIM_CTRL_RX_DMA_EN_SHIFT              19
#define EMVSIM_CTRL_RX_DMA_EN_WIDTH              1
#define EMVSIM_CTRL_RX_DMA_EN(x)                 (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_RX_DMA_EN_SHIFT))&EMVSIM_CTRL_RX_DMA_EN_MASK)
#define EMVSIM_CTRL_TX_DMA_EN_MASK               0x100000u
#define EMVSIM_CTRL_TX_DMA_EN_SHIFT              20
#define EMVSIM_CTRL_TX_DMA_EN_WIDTH              1
#define EMVSIM_CTRL_TX_DMA_EN(x)                 (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_TX_DMA_EN_SHIFT))&EMVSIM_CTRL_TX_DMA_EN_MASK)
#define EMVSIM_CTRL_INV_CRC_VAL_MASK             0x1000000u
#define EMVSIM_CTRL_INV_CRC_VAL_SHIFT            24
#define EMVSIM_CTRL_INV_CRC_VAL_WIDTH            1
#define EMVSIM_CTRL_INV_CRC_VAL(x)               (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_INV_CRC_VAL_SHIFT))&EMVSIM_CTRL_INV_CRC_VAL_MASK)
#define EMVSIM_CTRL_CRC_OUT_FLIP_MASK            0x2000000u
#define EMVSIM_CTRL_CRC_OUT_FLIP_SHIFT           25
#define EMVSIM_CTRL_CRC_OUT_FLIP_WIDTH           1
#define EMVSIM_CTRL_CRC_OUT_FLIP(x)              (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_CRC_OUT_FLIP_SHIFT))&EMVSIM_CTRL_CRC_OUT_FLIP_MASK)
#define EMVSIM_CTRL_CRC_IN_FLIP_MASK             0x4000000u
#define EMVSIM_CTRL_CRC_IN_FLIP_SHIFT            26
#define EMVSIM_CTRL_CRC_IN_FLIP_WIDTH            1
#define EMVSIM_CTRL_CRC_IN_FLIP(x)               (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_CRC_IN_FLIP_SHIFT))&EMVSIM_CTRL_CRC_IN_FLIP_MASK)
#define EMVSIM_CTRL_CWT_EN_MASK                  0x8000000u
#define EMVSIM_CTRL_CWT_EN_SHIFT                 27
#define EMVSIM_CTRL_CWT_EN_WIDTH                 1
#define EMVSIM_CTRL_CWT_EN(x)                    (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_CWT_EN_SHIFT))&EMVSIM_CTRL_CWT_EN_MASK)
#define EMVSIM_CTRL_LRC_EN_MASK                  0x10000000u
#define EMVSIM_CTRL_LRC_EN_SHIFT                 28
#define EMVSIM_CTRL_LRC_EN_WIDTH                 1
#define EMVSIM_CTRL_LRC_EN(x)                    (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_LRC_EN_SHIFT))&EMVSIM_CTRL_LRC_EN_MASK)
#define EMVSIM_CTRL_CRC_EN_MASK                  0x20000000u
#define EMVSIM_CTRL_CRC_EN_SHIFT                 29
#define EMVSIM_CTRL_CRC_EN_WIDTH                 1
#define EMVSIM_CTRL_CRC_EN(x)                    (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_CRC_EN_SHIFT))&EMVSIM_CTRL_CRC_EN_MASK)
#define EMVSIM_CTRL_XMT_CRC_LRC_MASK             0x40000000u
#define EMVSIM_CTRL_XMT_CRC_LRC_SHIFT            30
#define EMVSIM_CTRL_XMT_CRC_LRC_WIDTH            1
#define EMVSIM_CTRL_XMT_CRC_LRC(x)               (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_XMT_CRC_LRC_SHIFT))&EMVSIM_CTRL_XMT_CRC_LRC_MASK)
#define EMVSIM_CTRL_BWT_EN_MASK                  0x80000000u
#define EMVSIM_CTRL_BWT_EN_SHIFT                 31
#define EMVSIM_CTRL_BWT_EN_WIDTH                 1
#define EMVSIM_CTRL_BWT_EN(x)                    (((uint32_t)(((uint32_t)(x))<<EMVSIM_CTRL_BWT_EN_SHIFT))&EMVSIM_CTRL_BWT_EN_MASK)
/* INT_MASK Bit Fields */
#define EMVSIM_INT_MASK_RDT_IM_MASK              0x1u
#define EMVSIM_INT_MASK_RDT_IM_SHIFT             0
#define EMVSIM_INT_MASK_RDT_IM_WIDTH             1
#define EMVSIM_INT_MASK_RDT_IM(x)                (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_RDT_IM_SHIFT))&EMVSIM_INT_MASK_RDT_IM_MASK)
#define EMVSIM_INT_MASK_TC_IM_MASK               0x2u
#define EMVSIM_INT_MASK_TC_IM_SHIFT              1
#define EMVSIM_INT_MASK_TC_IM_WIDTH              1
#define EMVSIM_INT_MASK_TC_IM(x)                 (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_TC_IM_SHIFT))&EMVSIM_INT_MASK_TC_IM_MASK)
#define EMVSIM_INT_MASK_RFO_IM_MASK              0x4u
#define EMVSIM_INT_MASK_RFO_IM_SHIFT             2
#define EMVSIM_INT_MASK_RFO_IM_WIDTH             1
#define EMVSIM_INT_MASK_RFO_IM(x)                (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_RFO_IM_SHIFT))&EMVSIM_INT_MASK_RFO_IM_MASK)
#define EMVSIM_INT_MASK_ETC_IM_MASK              0x8u
#define EMVSIM_INT_MASK_ETC_IM_SHIFT             3
#define EMVSIM_INT_MASK_ETC_IM_WIDTH             1
#define EMVSIM_INT_MASK_ETC_IM(x)                (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_ETC_IM_SHIFT))&EMVSIM_INT_MASK_ETC_IM_MASK)
#define EMVSIM_INT_MASK_TFE_IM_MASK              0x10u
#define EMVSIM_INT_MASK_TFE_IM_SHIFT             4
#define EMVSIM_INT_MASK_TFE_IM_WIDTH             1
#define EMVSIM_INT_MASK_TFE_IM(x)                (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_TFE_IM_SHIFT))&EMVSIM_INT_MASK_TFE_IM_MASK)
#define EMVSIM_INT_MASK_TNACK_IM_MASK            0x20u
#define EMVSIM_INT_MASK_TNACK_IM_SHIFT           5
#define EMVSIM_INT_MASK_TNACK_IM_WIDTH           1
#define EMVSIM_INT_MASK_TNACK_IM(x)              (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_TNACK_IM_SHIFT))&EMVSIM_INT_MASK_TNACK_IM_MASK)
#define EMVSIM_INT_MASK_TFF_IM_MASK              0x40u
#define EMVSIM_INT_MASK_TFF_IM_SHIFT             6
#define EMVSIM_INT_MASK_TFF_IM_WIDTH             1
#define EMVSIM_INT_MASK_TFF_IM(x)                (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_TFF_IM_SHIFT))&EMVSIM_INT_MASK_TFF_IM_MASK)
#define EMVSIM_INT_MASK_TDT_IM_MASK              0x80u
#define EMVSIM_INT_MASK_TDT_IM_SHIFT             7
#define EMVSIM_INT_MASK_TDT_IM_WIDTH             1
#define EMVSIM_INT_MASK_TDT_IM(x)                (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_TDT_IM_SHIFT))&EMVSIM_INT_MASK_TDT_IM_MASK)
#define EMVSIM_INT_MASK_GPCNT0_IM_MASK           0x100u
#define EMVSIM_INT_MASK_GPCNT0_IM_SHIFT          8
#define EMVSIM_INT_MASK_GPCNT0_IM_WIDTH          1
#define EMVSIM_INT_MASK_GPCNT0_IM(x)             (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_GPCNT0_IM_SHIFT))&EMVSIM_INT_MASK_GPCNT0_IM_MASK)
#define EMVSIM_INT_MASK_CWT_ERR_IM_MASK          0x200u
#define EMVSIM_INT_MASK_CWT_ERR_IM_SHIFT         9
#define EMVSIM_INT_MASK_CWT_ERR_IM_WIDTH         1
#define EMVSIM_INT_MASK_CWT_ERR_IM(x)            (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_CWT_ERR_IM_SHIFT))&EMVSIM_INT_MASK_CWT_ERR_IM_MASK)
#define EMVSIM_INT_MASK_RNACK_IM_MASK            0x400u
#define EMVSIM_INT_MASK_RNACK_IM_SHIFT           10
#define EMVSIM_INT_MASK_RNACK_IM_WIDTH           1
#define EMVSIM_INT_MASK_RNACK_IM(x)              (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_RNACK_IM_SHIFT))&EMVSIM_INT_MASK_RNACK_IM_MASK)
#define EMVSIM_INT_MASK_BWT_ERR_IM_MASK          0x800u
#define EMVSIM_INT_MASK_BWT_ERR_IM_SHIFT         11
#define EMVSIM_INT_MASK_BWT_ERR_IM_WIDTH         1
#define EMVSIM_INT_MASK_BWT_ERR_IM(x)            (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_BWT_ERR_IM_SHIFT))&EMVSIM_INT_MASK_BWT_ERR_IM_MASK)
#define EMVSIM_INT_MASK_BGT_ERR_IM_MASK          0x1000u
#define EMVSIM_INT_MASK_BGT_ERR_IM_SHIFT         12
#define EMVSIM_INT_MASK_BGT_ERR_IM_WIDTH         1
#define EMVSIM_INT_MASK_BGT_ERR_IM(x)            (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_BGT_ERR_IM_SHIFT))&EMVSIM_INT_MASK_BGT_ERR_IM_MASK)
#define EMVSIM_INT_MASK_GPCNT1_IM_MASK           0x2000u
#define EMVSIM_INT_MASK_GPCNT1_IM_SHIFT          13
#define EMVSIM_INT_MASK_GPCNT1_IM_WIDTH          1
#define EMVSIM_INT_MASK_GPCNT1_IM(x)             (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_GPCNT1_IM_SHIFT))&EMVSIM_INT_MASK_GPCNT1_IM_MASK)
#define EMVSIM_INT_MASK_RX_DATA_IM_MASK          0x4000u
#define EMVSIM_INT_MASK_RX_DATA_IM_SHIFT         14
#define EMVSIM_INT_MASK_RX_DATA_IM_WIDTH         1
#define EMVSIM_INT_MASK_RX_DATA_IM(x)            (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_RX_DATA_IM_SHIFT))&EMVSIM_INT_MASK_RX_DATA_IM_MASK)
#define EMVSIM_INT_MASK_PEF_IM_MASK              0x8000u
#define EMVSIM_INT_MASK_PEF_IM_SHIFT             15
#define EMVSIM_INT_MASK_PEF_IM_WIDTH             1
#define EMVSIM_INT_MASK_PEF_IM(x)                (((uint32_t)(((uint32_t)(x))<<EMVSIM_INT_MASK_PEF_IM_SHIFT))&EMVSIM_INT_MASK_PEF_IM_MASK)
/* RX_THD Bit Fields */
#define EMVSIM_RX_THD_RDT_MASK                   0xFu
#define EMVSIM_RX_THD_RDT_SHIFT                  0
#define EMVSIM_RX_THD_RDT_WIDTH                  4
#define EMVSIM_RX_THD_RDT(x)                     (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_THD_RDT_SHIFT))&EMVSIM_RX_THD_RDT_MASK)
#define EMVSIM_RX_THD_RNCK_THD_MASK              0xF00u
#define EMVSIM_RX_THD_RNCK_THD_SHIFT             8
#define EMVSIM_RX_THD_RNCK_THD_WIDTH             4
#define EMVSIM_RX_THD_RNCK_THD(x)                (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_THD_RNCK_THD_SHIFT))&EMVSIM_RX_THD_RNCK_THD_MASK)
/* TX_THD Bit Fields */
#define EMVSIM_TX_THD_TDT_MASK                   0xFu
#define EMVSIM_TX_THD_TDT_SHIFT                  0
#define EMVSIM_TX_THD_TDT_WIDTH                  4
#define EMVSIM_TX_THD_TDT(x)                     (((uint32_t)(((uint32_t)(x))<<EMVSIM_TX_THD_TDT_SHIFT))&EMVSIM_TX_THD_TDT_MASK)
#define EMVSIM_TX_THD_TNCK_THD_MASK              0xF00u
#define EMVSIM_TX_THD_TNCK_THD_SHIFT             8
#define EMVSIM_TX_THD_TNCK_THD_WIDTH             4
#define EMVSIM_TX_THD_TNCK_THD(x)                (((uint32_t)(((uint32_t)(x))<<EMVSIM_TX_THD_TNCK_THD_SHIFT))&EMVSIM_TX_THD_TNCK_THD_MASK)
/* RX_STATUS Bit Fields */
#define EMVSIM_RX_STATUS_RFO_MASK                0x1u
#define EMVSIM_RX_STATUS_RFO_SHIFT               0
#define EMVSIM_RX_STATUS_RFO_WIDTH               1
#define EMVSIM_RX_STATUS_RFO(x)                  (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_STATUS_RFO_SHIFT))&EMVSIM_RX_STATUS_RFO_MASK)
#define EMVSIM_RX_STATUS_RX_DATA_MASK            0x10u
#define EMVSIM_RX_STATUS_RX_DATA_SHIFT           4
#define EMVSIM_RX_STATUS_RX_DATA_WIDTH           1
#define EMVSIM_RX_STATUS_RX_DATA(x)              (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_STATUS_RX_DATA_SHIFT))&EMVSIM_RX_STATUS_RX_DATA_MASK)
#define EMVSIM_RX_STATUS_RDTF_MASK               0x20u
#define EMVSIM_RX_STATUS_RDTF_SHIFT              5
#define EMVSIM_RX_STATUS_RDTF_WIDTH              1
#define EMVSIM_RX_STATUS_RDTF(x)                 (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_STATUS_RDTF_SHIFT))&EMVSIM_RX_STATUS_RDTF_MASK)
#define EMVSIM_RX_STATUS_LRC_OK_MASK             0x40u
#define EMVSIM_RX_STATUS_LRC_OK_SHIFT            6
#define EMVSIM_RX_STATUS_LRC_OK_WIDTH            1
#define EMVSIM_RX_STATUS_LRC_OK(x)               (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_STATUS_LRC_OK_SHIFT))&EMVSIM_RX_STATUS_LRC_OK_MASK)
#define EMVSIM_RX_STATUS_CRC_OK_MASK             0x80u
#define EMVSIM_RX_STATUS_CRC_OK_SHIFT            7
#define EMVSIM_RX_STATUS_CRC_OK_WIDTH            1
#define EMVSIM_RX_STATUS_CRC_OK(x)               (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_STATUS_CRC_OK_SHIFT))&EMVSIM_RX_STATUS_CRC_OK_MASK)
#define EMVSIM_RX_STATUS_CWT_ERR_MASK            0x100u
#define EMVSIM_RX_STATUS_CWT_ERR_SHIFT           8
#define EMVSIM_RX_STATUS_CWT_ERR_WIDTH           1
#define EMVSIM_RX_STATUS_CWT_ERR(x)              (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_STATUS_CWT_ERR_SHIFT))&EMVSIM_RX_STATUS_CWT_ERR_MASK)
#define EMVSIM_RX_STATUS_RTE_MASK                0x200u
#define EMVSIM_RX_STATUS_RTE_SHIFT               9
#define EMVSIM_RX_STATUS_RTE_WIDTH               1
#define EMVSIM_RX_STATUS_RTE(x)                  (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_STATUS_RTE_SHIFT))&EMVSIM_RX_STATUS_RTE_MASK)
#define EMVSIM_RX_STATUS_BWT_ERR_MASK            0x400u
#define EMVSIM_RX_STATUS_BWT_ERR_SHIFT           10
#define EMVSIM_RX_STATUS_BWT_ERR_WIDTH           1
#define EMVSIM_RX_STATUS_BWT_ERR(x)              (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_STATUS_BWT_ERR_SHIFT))&EMVSIM_RX_STATUS_BWT_ERR_MASK)
#define EMVSIM_RX_STATUS_BGT_ERR_MASK            0x800u
#define EMVSIM_RX_STATUS_BGT_ERR_SHIFT           11
#define EMVSIM_RX_STATUS_BGT_ERR_WIDTH           1
#define EMVSIM_RX_STATUS_BGT_ERR(x)              (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_STATUS_BGT_ERR_SHIFT))&EMVSIM_RX_STATUS_BGT_ERR_MASK)
#define EMVSIM_RX_STATUS_PEF_MASK                0x1000u
#define EMVSIM_RX_STATUS_PEF_SHIFT               12
#define EMVSIM_RX_STATUS_PEF_WIDTH               1
#define EMVSIM_RX_STATUS_PEF(x)                  (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_STATUS_PEF_SHIFT))&EMVSIM_RX_STATUS_PEF_MASK)
#define EMVSIM_RX_STATUS_FEF_MASK                0x2000u
#define EMVSIM_RX_STATUS_FEF_SHIFT               13
#define EMVSIM_RX_STATUS_FEF_WIDTH               1
#define EMVSIM_RX_STATUS_FEF(x)                  (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_STATUS_FEF_SHIFT))&EMVSIM_RX_STATUS_FEF_MASK)
#define EMVSIM_RX_STATUS_RX_WPTR_MASK            0x30000u
#define EMVSIM_RX_STATUS_RX_WPTR_SHIFT           16
#define EMVSIM_RX_STATUS_RX_WPTR_WIDTH           2
#define EMVSIM_RX_STATUS_RX_WPTR(x)              (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_STATUS_RX_WPTR_SHIFT))&EMVSIM_RX_STATUS_RX_WPTR_MASK)
#define EMVSIM_RX_STATUS_RX_CNT_MASK             0x1C00000u
#define EMVSIM_RX_STATUS_RX_CNT_SHIFT            22
#define EMVSIM_RX_STATUS_RX_CNT_WIDTH            3
#define EMVSIM_RX_STATUS_RX_CNT(x)               (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_STATUS_RX_CNT_SHIFT))&EMVSIM_RX_STATUS_RX_CNT_MASK)
/* TX_STATUS Bit Fields */
#define EMVSIM_TX_STATUS_TNTE_MASK               0x1u
#define EMVSIM_TX_STATUS_TNTE_SHIFT              0
#define EMVSIM_TX_STATUS_TNTE_WIDTH              1
#define EMVSIM_TX_STATUS_TNTE(x)                 (((uint32_t)(((uint32_t)(x))<<EMVSIM_TX_STATUS_TNTE_SHIFT))&EMVSIM_TX_STATUS_TNTE_MASK)
#define EMVSIM_TX_STATUS_TFE_MASK                0x8u
#define EMVSIM_TX_STATUS_TFE_SHIFT               3
#define EMVSIM_TX_STATUS_TFE_WIDTH               1
#define EMVSIM_TX_STATUS_TFE(x)                  (((uint32_t)(((uint32_t)(x))<<EMVSIM_TX_STATUS_TFE_SHIFT))&EMVSIM_TX_STATUS_TFE_MASK)
#define EMVSIM_TX_STATUS_ETCF_MASK               0x10u
#define EMVSIM_TX_STATUS_ETCF_SHIFT              4
#define EMVSIM_TX_STATUS_ETCF_WIDTH              1
#define EMVSIM_TX_STATUS_ETCF(x)                 (((uint32_t)(((uint32_t)(x))<<EMVSIM_TX_STATUS_ETCF_SHIFT))&EMVSIM_TX_STATUS_ETCF_MASK)
#define EMVSIM_TX_STATUS_TCF_MASK                0x20u
#define EMVSIM_TX_STATUS_TCF_SHIFT               5
#define EMVSIM_TX_STATUS_TCF_WIDTH               1
#define EMVSIM_TX_STATUS_TCF(x)                  (((uint32_t)(((uint32_t)(x))<<EMVSIM_TX_STATUS_TCF_SHIFT))&EMVSIM_TX_STATUS_TCF_MASK)
#define EMVSIM_TX_STATUS_TFF_MASK                0x40u
#define EMVSIM_TX_STATUS_TFF_SHIFT               6
#define EMVSIM_TX_STATUS_TFF_WIDTH               1
#define EMVSIM_TX_STATUS_TFF(x)                  (((uint32_t)(((uint32_t)(x))<<EMVSIM_TX_STATUS_TFF_SHIFT))&EMVSIM_TX_STATUS_TFF_MASK)
#define EMVSIM_TX_STATUS_TDTF_MASK               0x80u
#define EMVSIM_TX_STATUS_TDTF_SHIFT              7
#define EMVSIM_TX_STATUS_TDTF_WIDTH              1
#define EMVSIM_TX_STATUS_TDTF(x)                 (((uint32_t)(((uint32_t)(x))<<EMVSIM_TX_STATUS_TDTF_SHIFT))&EMVSIM_TX_STATUS_TDTF_MASK)
#define EMVSIM_TX_STATUS_GPCNT0_TO_MASK          0x100u
#define EMVSIM_TX_STATUS_GPCNT0_TO_SHIFT         8
#define EMVSIM_TX_STATUS_GPCNT0_TO_WIDTH         1
#define EMVSIM_TX_STATUS_GPCNT0_TO(x)            (((uint32_t)(((uint32_t)(x))<<EMVSIM_TX_STATUS_GPCNT0_TO_SHIFT))&EMVSIM_TX_STATUS_GPCNT0_TO_MASK)
#define EMVSIM_TX_STATUS_GPCNT1_TO_MASK          0x200u
#define EMVSIM_TX_STATUS_GPCNT1_TO_SHIFT         9
#define EMVSIM_TX_STATUS_GPCNT1_TO_WIDTH         1
#define EMVSIM_TX_STATUS_GPCNT1_TO(x)            (((uint32_t)(((uint32_t)(x))<<EMVSIM_TX_STATUS_GPCNT1_TO_SHIFT))&EMVSIM_TX_STATUS_GPCNT1_TO_MASK)
#define EMVSIM_TX_STATUS_TX_RPTR_MASK            0x30000u
#define EMVSIM_TX_STATUS_TX_RPTR_SHIFT           16
#define EMVSIM_TX_STATUS_TX_RPTR_WIDTH           2
#define EMVSIM_TX_STATUS_TX_RPTR(x)              (((uint32_t)(((uint32_t)(x))<<EMVSIM_TX_STATUS_TX_RPTR_SHIFT))&EMVSIM_TX_STATUS_TX_RPTR_MASK)
#define EMVSIM_TX_STATUS_TX_CNT_MASK             0x1C00000u
#define EMVSIM_TX_STATUS_TX_CNT_SHIFT            22
#define EMVSIM_TX_STATUS_TX_CNT_WIDTH            3
#define EMVSIM_TX_STATUS_TX_CNT(x)               (((uint32_t)(((uint32_t)(x))<<EMVSIM_TX_STATUS_TX_CNT_SHIFT))&EMVSIM_TX_STATUS_TX_CNT_MASK)
/* PCSR Bit Fields */
#define EMVSIM_PCSR_SAPD_MASK                    0x1u
#define EMVSIM_PCSR_SAPD_SHIFT                   0
#define EMVSIM_PCSR_SAPD_WIDTH                   1
#define EMVSIM_PCSR_SAPD(x)                      (((uint32_t)(((uint32_t)(x))<<EMVSIM_PCSR_SAPD_SHIFT))&EMVSIM_PCSR_SAPD_MASK)
#define EMVSIM_PCSR_SVCC_EN_MASK                 0x2u
#define EMVSIM_PCSR_SVCC_EN_SHIFT                1
#define EMVSIM_PCSR_SVCC_EN_WIDTH                1
#define EMVSIM_PCSR_SVCC_EN(x)                   (((uint32_t)(((uint32_t)(x))<<EMVSIM_PCSR_SVCC_EN_SHIFT))&EMVSIM_PCSR_SVCC_EN_MASK)
#define EMVSIM_PCSR_VCCENP_MASK                  0x4u
#define EMVSIM_PCSR_VCCENP_SHIFT                 2
#define EMVSIM_PCSR_VCCENP_WIDTH                 1
#define EMVSIM_PCSR_VCCENP(x)                    (((uint32_t)(((uint32_t)(x))<<EMVSIM_PCSR_VCCENP_SHIFT))&EMVSIM_PCSR_VCCENP_MASK)
#define EMVSIM_PCSR_SRST_MASK                    0x8u
#define EMVSIM_PCSR_SRST_SHIFT                   3
#define EMVSIM_PCSR_SRST_WIDTH                   1
#define EMVSIM_PCSR_SRST(x)                      (((uint32_t)(((uint32_t)(x))<<EMVSIM_PCSR_SRST_SHIFT))&EMVSIM_PCSR_SRST_MASK)
#define EMVSIM_PCSR_SCEN_MASK                    0x10u
#define EMVSIM_PCSR_SCEN_SHIFT                   4
#define EMVSIM_PCSR_SCEN_WIDTH                   1
#define EMVSIM_PCSR_SCEN(x)                      (((uint32_t)(((uint32_t)(x))<<EMVSIM_PCSR_SCEN_SHIFT))&EMVSIM_PCSR_SCEN_MASK)
#define EMVSIM_PCSR_SCSP_MASK                    0x20u
#define EMVSIM_PCSR_SCSP_SHIFT                   5
#define EMVSIM_PCSR_SCSP_WIDTH                   1
#define EMVSIM_PCSR_SCSP(x)                      (((uint32_t)(((uint32_t)(x))<<EMVSIM_PCSR_SCSP_SHIFT))&EMVSIM_PCSR_SCSP_MASK)
#define EMVSIM_PCSR_SPD_MASK                     0x80u
#define EMVSIM_PCSR_SPD_SHIFT                    7
#define EMVSIM_PCSR_SPD_WIDTH                    1
#define EMVSIM_PCSR_SPD(x)                       (((uint32_t)(((uint32_t)(x))<<EMVSIM_PCSR_SPD_SHIFT))&EMVSIM_PCSR_SPD_MASK)
#define EMVSIM_PCSR_SPDIM_MASK                   0x1000000u
#define EMVSIM_PCSR_SPDIM_SHIFT                  24
#define EMVSIM_PCSR_SPDIM_WIDTH                  1
#define EMVSIM_PCSR_SPDIM(x)                     (((uint32_t)(((uint32_t)(x))<<EMVSIM_PCSR_SPDIM_SHIFT))&EMVSIM_PCSR_SPDIM_MASK)
#define EMVSIM_PCSR_SPDIF_MASK                   0x2000000u
#define EMVSIM_PCSR_SPDIF_SHIFT                  25
#define EMVSIM_PCSR_SPDIF_WIDTH                  1
#define EMVSIM_PCSR_SPDIF(x)                     (((uint32_t)(((uint32_t)(x))<<EMVSIM_PCSR_SPDIF_SHIFT))&EMVSIM_PCSR_SPDIF_MASK)
#define EMVSIM_PCSR_SPDP_MASK                    0x4000000u
#define EMVSIM_PCSR_SPDP_SHIFT                   26
#define EMVSIM_PCSR_SPDP_WIDTH                   1
#define EMVSIM_PCSR_SPDP(x)                      (((uint32_t)(((uint32_t)(x))<<EMVSIM_PCSR_SPDP_SHIFT))&EMVSIM_PCSR_SPDP_MASK)
#define EMVSIM_PCSR_SPDES_MASK                   0x8000000u
#define EMVSIM_PCSR_SPDES_SHIFT                  27
#define EMVSIM_PCSR_SPDES_WIDTH                  1
#define EMVSIM_PCSR_SPDES(x)                     (((uint32_t)(((uint32_t)(x))<<EMVSIM_PCSR_SPDES_SHIFT))&EMVSIM_PCSR_SPDES_MASK)
/* RX_BUF Bit Fields */
#define EMVSIM_RX_BUF_RX_BYTE_MASK               0xFFu
#define EMVSIM_RX_BUF_RX_BYTE_SHIFT              0
#define EMVSIM_RX_BUF_RX_BYTE_WIDTH              8
#define EMVSIM_RX_BUF_RX_BYTE(x)                 (((uint32_t)(((uint32_t)(x))<<EMVSIM_RX_BUF_RX_BYTE_SHIFT))&EMVSIM_RX_BUF_RX_BYTE_MASK)
/* TX_BUF Bit Fields */
#define EMVSIM_TX_BUF_TX_BYTE_MASK               0xFFu
#define EMVSIM_TX_BUF_TX_BYTE_SHIFT              0
#define EMVSIM_TX_BUF_TX_BYTE_WIDTH              8
#define EMVSIM_TX_BUF_TX_BYTE(x)                 (((uint32_t)(((uint32_t)(x))<<EMVSIM_TX_BUF_TX_BYTE_SHIFT))&EMVSIM_TX_BUF_TX_BYTE_MASK)
/* TX_GETU Bit Fields */
#define EMVSIM_TX_GETU_GETU_MASK                 0xFFu
#define EMVSIM_TX_GETU_GETU_SHIFT                0
#define EMVSIM_TX_GETU_GETU_WIDTH                8
#define EMVSIM_TX_GETU_GETU(x)                   (((uint32_t)(((uint32_t)(x))<<EMVSIM_TX_GETU_GETU_SHIFT))&EMVSIM_TX_GETU_GETU_MASK)
/* CWT_VAL Bit Fields */
#define EMVSIM_CWT_VAL_CWT_MASK                  0xFFFFu
#define EMVSIM_CWT_VAL_CWT_SHIFT                 0
#define EMVSIM_CWT_VAL_CWT_WIDTH                 16
#define EMVSIM_CWT_VAL_CWT(x)                    (((uint32_t)(((uint32_t)(x))<<EMVSIM_CWT_VAL_CWT_SHIFT))&EMVSIM_CWT_VAL_CWT_MASK)
/* BWT_VAL Bit Fields */
#define EMVSIM_BWT_VAL_BWT_MASK                  0xFFFFFFFFu
#define EMVSIM_BWT_VAL_BWT_SHIFT                 0
#define EMVSIM_BWT_VAL_BWT_WIDTH                 32
#define EMVSIM_BWT_VAL_BWT(x)                    (((uint32_t)(((uint32_t)(x))<<EMVSIM_BWT_VAL_BWT_SHIFT))&EMVSIM_BWT_VAL_BWT_MASK)
/* BGT_VAL Bit Fields */
#define EMVSIM_BGT_VAL_BGT_MASK                  0xFFFFu
#define EMVSIM_BGT_VAL_BGT_SHIFT                 0
#define EMVSIM_BGT_VAL_BGT_WIDTH                 16
#define EMVSIM_BGT_VAL_BGT(x)                    (((uint32_t)(((uint32_t)(x))<<EMVSIM_BGT_VAL_BGT_SHIFT))&EMVSIM_BGT_VAL_BGT_MASK)
/* GPCNT0_VAL Bit Fields */
#define EMVSIM_GPCNT0_VAL_GPCNT0_MASK            0xFFFFu
#define EMVSIM_GPCNT0_VAL_GPCNT0_SHIFT           0
#define EMVSIM_GPCNT0_VAL_GPCNT0_WIDTH           16
#define EMVSIM_GPCNT0_VAL_GPCNT0(x)              (((uint32_t)(((uint32_t)(x))<<EMVSIM_GPCNT0_VAL_GPCNT0_SHIFT))&EMVSIM_GPCNT0_VAL_GPCNT0_MASK)
/* GPCNT1_VAL Bit Fields */
#define EMVSIM_GPCNT1_VAL_GPCNT1_MASK            0xFFFFu
#define EMVSIM_GPCNT1_VAL_GPCNT1_SHIFT           0
#define EMVSIM_GPCNT1_VAL_GPCNT1_WIDTH           16
#define EMVSIM_GPCNT1_VAL_GPCNT1(x)              (((uint32_t)(((uint32_t)(x))<<EMVSIM_GPCNT1_VAL_GPCNT1_SHIFT))&EMVSIM_GPCNT1_VAL_GPCNT1_MASK)

/*!
 * @}
 */ /* end of group EMVSIM_Register_Masks */


/* EMVSIM - Peripheral instance base addresses */
/** Peripheral EMVSIM0 base address */
#define EMVSIM0_BASE                             (0x4004E000u)
/** Peripheral EMVSIM0 base pointer */
#define EMVSIM0                                  ((EMVSIM_Type *)EMVSIM0_BASE)
#define EMVSIM0_BASE_PTR                         (EMVSIM0)
/** Array initializer of EMVSIM peripheral base addresses */
#define EMVSIM_BASE_ADDRS                        { EMVSIM0_BASE }
/** Array initializer of EMVSIM peripheral base pointers */
#define EMVSIM_BASE_PTRS                         { EMVSIM0 }

/* ----------------------------------------------------------------------------
   -- EMVSIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EMVSIM_Register_Accessor_Macros EMVSIM - Register accessor macros
 * @{
 */


/* EMVSIM - Register instance definitions */
/* EMVSIM0 */
#define EMVSIM0_VER_ID                           EMVSIM_VER_ID_REG(EMVSIM0)
#define EMVSIM0_PARAM                            EMVSIM_PARAM_REG(EMVSIM0)
#define EMVSIM0_CLKCFG                           EMVSIM_CLKCFG_REG(EMVSIM0)
#define EMVSIM0_DIVISOR                          EMVSIM_DIVISOR_REG(EMVSIM0)
#define EMVSIM0_CTRL                             EMVSIM_CTRL_REG(EMVSIM0)
#define EMVSIM0_INT_MASK                         EMVSIM_INT_MASK_REG(EMVSIM0)
#define EMVSIM0_RX_THD                           EMVSIM_RX_THD_REG(EMVSIM0)
#define EMVSIM0_TX_THD                           EMVSIM_TX_THD_REG(EMVSIM0)
#define EMVSIM0_RX_STATUS                        EMVSIM_RX_STATUS_REG(EMVSIM0)
#define EMVSIM0_TX_STATUS                        EMVSIM_TX_STATUS_REG(EMVSIM0)
#define EMVSIM0_PCSR                             EMVSIM_PCSR_REG(EMVSIM0)
#define EMVSIM0_RX_BUF                           EMVSIM_RX_BUF_REG(EMVSIM0)
#define EMVSIM0_TX_BUF                           EMVSIM_TX_BUF_REG(EMVSIM0)
#define EMVSIM0_TX_GETU                          EMVSIM_TX_GETU_REG(EMVSIM0)
#define EMVSIM0_CWT_VAL                          EMVSIM_CWT_VAL_REG(EMVSIM0)
#define EMVSIM0_BWT_VAL                          EMVSIM_BWT_VAL_REG(EMVSIM0)
#define EMVSIM0_BGT_VAL                          EMVSIM_BGT_VAL_REG(EMVSIM0)
#define EMVSIM0_GPCNT0_VAL                       EMVSIM_GPCNT0_VAL_REG(EMVSIM0)
#define EMVSIM0_GPCNT1_VAL                       EMVSIM_GPCNT1_VAL_REG(EMVSIM0)

/*!
 * @}
 */ /* end of group EMVSIM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group EMVSIM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FGPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FGPIO_Peripheral_Access_Layer FGPIO Peripheral Access Layer
 * @{
 */

/** FGPIO - Register Layout Typedef */
typedef struct {
  __IO uint32_t PDOR;                              /**< Port Data Output Register, offset: 0x0 */
  __O  uint32_t PSOR;                              /**< Port Set Output Register, offset: 0x4 */
  __O  uint32_t PCOR;                              /**< Port Clear Output Register, offset: 0x8 */
  __O  uint32_t PTOR;                              /**< Port Toggle Output Register, offset: 0xC */
  __I  uint32_t PDIR;                              /**< Port Data Input Register, offset: 0x10 */
  __IO uint32_t PDDR;                              /**< Port Data Direction Register, offset: 0x14 */
} FGPIO_Type, *FGPIO_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FGPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FGPIO_Register_Accessor_Macros FGPIO - Register accessor macros
 * @{
 */


/* FGPIO - Register accessors */
#define FGPIO_PDOR_REG(base)                     ((base)->PDOR)
#define FGPIO_PSOR_REG(base)                     ((base)->PSOR)
#define FGPIO_PCOR_REG(base)                     ((base)->PCOR)
#define FGPIO_PTOR_REG(base)                     ((base)->PTOR)
#define FGPIO_PDIR_REG(base)                     ((base)->PDIR)
#define FGPIO_PDDR_REG(base)                     ((base)->PDDR)

/*!
 * @}
 */ /* end of group FGPIO_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FGPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FGPIO_Register_Masks FGPIO Register Masks
 * @{
 */

/* PDOR Bit Fields */
#define FGPIO_PDOR_PDO_MASK                      0xFFFFFFFFu
#define FGPIO_PDOR_PDO_SHIFT                     0
#define FGPIO_PDOR_PDO_WIDTH                     32
#define FGPIO_PDOR_PDO(x)                        (((uint32_t)(((uint32_t)(x))<<FGPIO_PDOR_PDO_SHIFT))&FGPIO_PDOR_PDO_MASK)
/* PSOR Bit Fields */
#define FGPIO_PSOR_PTSO_MASK                     0xFFFFFFFFu
#define FGPIO_PSOR_PTSO_SHIFT                    0
#define FGPIO_PSOR_PTSO_WIDTH                    32
#define FGPIO_PSOR_PTSO(x)                       (((uint32_t)(((uint32_t)(x))<<FGPIO_PSOR_PTSO_SHIFT))&FGPIO_PSOR_PTSO_MASK)
/* PCOR Bit Fields */
#define FGPIO_PCOR_PTCO_MASK                     0xFFFFFFFFu
#define FGPIO_PCOR_PTCO_SHIFT                    0
#define FGPIO_PCOR_PTCO_WIDTH                    32
#define FGPIO_PCOR_PTCO(x)                       (((uint32_t)(((uint32_t)(x))<<FGPIO_PCOR_PTCO_SHIFT))&FGPIO_PCOR_PTCO_MASK)
/* PTOR Bit Fields */
#define FGPIO_PTOR_PTTO_MASK                     0xFFFFFFFFu
#define FGPIO_PTOR_PTTO_SHIFT                    0
#define FGPIO_PTOR_PTTO_WIDTH                    32
#define FGPIO_PTOR_PTTO(x)                       (((uint32_t)(((uint32_t)(x))<<FGPIO_PTOR_PTTO_SHIFT))&FGPIO_PTOR_PTTO_MASK)
/* PDIR Bit Fields */
#define FGPIO_PDIR_PDI_MASK                      0xFFFFFFFFu
#define FGPIO_PDIR_PDI_SHIFT                     0
#define FGPIO_PDIR_PDI_WIDTH                     32
#define FGPIO_PDIR_PDI(x)                        (((uint32_t)(((uint32_t)(x))<<FGPIO_PDIR_PDI_SHIFT))&FGPIO_PDIR_PDI_MASK)
/* PDDR Bit Fields */
#define FGPIO_PDDR_PDD_MASK                      0xFFFFFFFFu
#define FGPIO_PDDR_PDD_SHIFT                     0
#define FGPIO_PDDR_PDD_WIDTH                     32
#define FGPIO_PDDR_PDD(x)                        (((uint32_t)(((uint32_t)(x))<<FGPIO_PDDR_PDD_SHIFT))&FGPIO_PDDR_PDD_MASK)

/*!
 * @}
 */ /* end of group FGPIO_Register_Masks */


/* FGPIO - Peripheral instance base addresses */
/** Peripheral FGPIOA base address */
#define FGPIOA_BASE                              (0xF8000000u)
/** Peripheral FGPIOA base pointer */
#define FGPIOA                                   ((FGPIO_Type *)FGPIOA_BASE)
#define FGPIOA_BASE_PTR                          (FGPIOA)
/** Array initializer of FGPIO peripheral base addresses */
#define FGPIO_BASE_ADDRS                         { FGPIOA_BASE }
/** Array initializer of FGPIO peripheral base pointers */
#define FGPIO_BASE_PTRS                          { FGPIOA }

/* ----------------------------------------------------------------------------
   -- FGPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FGPIO_Register_Accessor_Macros FGPIO - Register accessor macros
 * @{
 */


/* FGPIO - Register instance definitions */
/* FGPIOA */
#define FGPIOA_PDOR                              FGPIO_PDOR_REG(FGPIOA)
#define FGPIOA_PSOR                              FGPIO_PSOR_REG(FGPIOA)
#define FGPIOA_PCOR                              FGPIO_PCOR_REG(FGPIOA)
#define FGPIOA_PTOR                              FGPIO_PTOR_REG(FGPIOA)
#define FGPIOA_PDIR                              FGPIO_PDIR_REG(FGPIOA)
#define FGPIOA_PDDR                              FGPIO_PDDR_REG(FGPIOA)

/*!
 * @}
 */ /* end of group FGPIO_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group FGPIO_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FLEXIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXIO_Peripheral_Access_Layer FLEXIO Peripheral Access Layer
 * @{
 */

/** FLEXIO - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t CTRL;                              /**< FlexIO Control Register, offset: 0x8 */
  __I  uint32_t PIN;                               /**< Pin State Register, offset: 0xC */
  __IO uint32_t SHIFTSTAT;                         /**< Shifter Status Register, offset: 0x10 */
  __IO uint32_t SHIFTERR;                          /**< Shifter Error Register, offset: 0x14 */
  __IO uint32_t TIMSTAT;                           /**< Timer Status Register, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SHIFTSIEN;                         /**< Shifter Status Interrupt Enable, offset: 0x20 */
  __IO uint32_t SHIFTEIEN;                         /**< Shifter Error Interrupt Enable, offset: 0x24 */
  __IO uint32_t TIMIEN;                            /**< Timer Interrupt Enable Register, offset: 0x28 */
       uint8_t RESERVED_1[4];
  __IO uint32_t SHIFTSDEN;                         /**< Shifter Status DMA Enable, offset: 0x30 */
       uint8_t RESERVED_2[12];
  __IO uint32_t SHIFTSTATE;                        /**< Shifter State Register, offset: 0x40 */
       uint8_t RESERVED_3[60];
  __IO uint32_t SHIFTCTL[8];                       /**< Shifter Control N Register, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_4[96];
  __IO uint32_t SHIFTCFG[8];                       /**< Shifter Configuration N Register, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_5[224];
  __IO uint32_t SHIFTBUF[8];                       /**< Shifter Buffer N Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_6[96];
  __IO uint32_t SHIFTBUFBIS[8];                    /**< Shifter Buffer N Bit Swapped Register, array offset: 0x280, array step: 0x4 */
       uint8_t RESERVED_7[96];
  __IO uint32_t SHIFTBUFBYS[8];                    /**< Shifter Buffer N Byte Swapped Register, array offset: 0x300, array step: 0x4 */
       uint8_t RESERVED_8[96];
  __IO uint32_t SHIFTBUFBBS[8];                    /**< Shifter Buffer N Bit Byte Swapped Register, array offset: 0x380, array step: 0x4 */
       uint8_t RESERVED_9[96];
  __IO uint32_t TIMCTL[8];                         /**< Timer Control N Register, array offset: 0x400, array step: 0x4 */
       uint8_t RESERVED_10[96];
  __IO uint32_t TIMCFG[8];                         /**< Timer Configuration N Register, array offset: 0x480, array step: 0x4 */
       uint8_t RESERVED_11[96];
  __IO uint32_t TIMCMP[8];                         /**< Timer Compare N Register, array offset: 0x500, array step: 0x4 */
       uint8_t RESERVED_12[352];
  __IO uint32_t SHIFTBUFNBS[8];                    /**< Shifter Buffer N Nibble Byte Swapped Register, array offset: 0x680, array step: 0x4 */
       uint8_t RESERVED_13[96];
  __IO uint32_t SHIFTBUFHWS[8];                    /**< Shifter Buffer N Half Word Swapped Register, array offset: 0x700, array step: 0x4 */
       uint8_t RESERVED_14[96];
  __IO uint32_t SHIFTBUFNIS[8];                    /**< Shifter Buffer N Nibble Swapped Register, array offset: 0x780, array step: 0x4 */
} FLEXIO_Type, *FLEXIO_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FLEXIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXIO_Register_Accessor_Macros FLEXIO - Register accessor macros
 * @{
 */


/* FLEXIO - Register accessors */
#define FLEXIO_VERID_REG(base)                   ((base)->VERID)
#define FLEXIO_PARAM_REG(base)                   ((base)->PARAM)
#define FLEXIO_CTRL_REG(base)                    ((base)->CTRL)
#define FLEXIO_PIN_REG(base)                     ((base)->PIN)
#define FLEXIO_SHIFTSTAT_REG(base)               ((base)->SHIFTSTAT)
#define FLEXIO_SHIFTERR_REG(base)                ((base)->SHIFTERR)
#define FLEXIO_TIMSTAT_REG(base)                 ((base)->TIMSTAT)
#define FLEXIO_SHIFTSIEN_REG(base)               ((base)->SHIFTSIEN)
#define FLEXIO_SHIFTEIEN_REG(base)               ((base)->SHIFTEIEN)
#define FLEXIO_TIMIEN_REG(base)                  ((base)->TIMIEN)
#define FLEXIO_SHIFTSDEN_REG(base)               ((base)->SHIFTSDEN)
#define FLEXIO_SHIFTSTATE_REG(base)              ((base)->SHIFTSTATE)
#define FLEXIO_SHIFTCTL_REG(base,index)          ((base)->SHIFTCTL[index])
#define FLEXIO_SHIFTCTL_COUNT                    8
#define FLEXIO_SHIFTCFG_REG(base,index)          ((base)->SHIFTCFG[index])
#define FLEXIO_SHIFTCFG_COUNT                    8
#define FLEXIO_SHIFTBUF_REG(base,index)          ((base)->SHIFTBUF[index])
#define FLEXIO_SHIFTBUF_COUNT                    8
#define FLEXIO_SHIFTBUFBIS_REG(base,index)       ((base)->SHIFTBUFBIS[index])
#define FLEXIO_SHIFTBUFBIS_COUNT                 8
#define FLEXIO_SHIFTBUFBYS_REG(base,index)       ((base)->SHIFTBUFBYS[index])
#define FLEXIO_SHIFTBUFBYS_COUNT                 8
#define FLEXIO_SHIFTBUFBBS_REG(base,index)       ((base)->SHIFTBUFBBS[index])
#define FLEXIO_SHIFTBUFBBS_COUNT                 8
#define FLEXIO_TIMCTL_REG(base,index)            ((base)->TIMCTL[index])
#define FLEXIO_TIMCTL_COUNT                      8
#define FLEXIO_TIMCFG_REG(base,index)            ((base)->TIMCFG[index])
#define FLEXIO_TIMCFG_COUNT                      8
#define FLEXIO_TIMCMP_REG(base,index)            ((base)->TIMCMP[index])
#define FLEXIO_TIMCMP_COUNT                      8
#define FLEXIO_SHIFTBUFNBS_REG(base,index)       ((base)->SHIFTBUFNBS[index])
#define FLEXIO_SHIFTBUFNBS_COUNT                 8
#define FLEXIO_SHIFTBUFHWS_REG(base,index)       ((base)->SHIFTBUFHWS[index])
#define FLEXIO_SHIFTBUFHWS_COUNT                 8
#define FLEXIO_SHIFTBUFNIS_REG(base,index)       ((base)->SHIFTBUFNIS[index])
#define FLEXIO_SHIFTBUFNIS_COUNT                 8

/*!
 * @}
 */ /* end of group FLEXIO_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FLEXIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXIO_Register_Masks FLEXIO Register Masks
 * @{
 */

/* VERID Bit Fields */
#define FLEXIO_VERID_FEATURE_MASK                0xFFFFu
#define FLEXIO_VERID_FEATURE_SHIFT               0
#define FLEXIO_VERID_FEATURE_WIDTH               16
#define FLEXIO_VERID_FEATURE(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_VERID_FEATURE_SHIFT))&FLEXIO_VERID_FEATURE_MASK)
#define FLEXIO_VERID_MINOR_MASK                  0xFF0000u
#define FLEXIO_VERID_MINOR_SHIFT                 16
#define FLEXIO_VERID_MINOR_WIDTH                 8
#define FLEXIO_VERID_MINOR(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_VERID_MINOR_SHIFT))&FLEXIO_VERID_MINOR_MASK)
#define FLEXIO_VERID_MAJOR_MASK                  0xFF000000u
#define FLEXIO_VERID_MAJOR_SHIFT                 24
#define FLEXIO_VERID_MAJOR_WIDTH                 8
#define FLEXIO_VERID_MAJOR(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_VERID_MAJOR_SHIFT))&FLEXIO_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define FLEXIO_PARAM_SHIFTER_MASK                0xFFu
#define FLEXIO_PARAM_SHIFTER_SHIFT               0
#define FLEXIO_PARAM_SHIFTER_WIDTH               8
#define FLEXIO_PARAM_SHIFTER(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_PARAM_SHIFTER_SHIFT))&FLEXIO_PARAM_SHIFTER_MASK)
#define FLEXIO_PARAM_TIMER_MASK                  0xFF00u
#define FLEXIO_PARAM_TIMER_SHIFT                 8
#define FLEXIO_PARAM_TIMER_WIDTH                 8
#define FLEXIO_PARAM_TIMER(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_PARAM_TIMER_SHIFT))&FLEXIO_PARAM_TIMER_MASK)
#define FLEXIO_PARAM_PIN_MASK                    0xFF0000u
#define FLEXIO_PARAM_PIN_SHIFT                   16
#define FLEXIO_PARAM_PIN_WIDTH                   8
#define FLEXIO_PARAM_PIN(x)                      (((uint32_t)(((uint32_t)(x))<<FLEXIO_PARAM_PIN_SHIFT))&FLEXIO_PARAM_PIN_MASK)
#define FLEXIO_PARAM_TRIGGER_MASK                0xFF000000u
#define FLEXIO_PARAM_TRIGGER_SHIFT               24
#define FLEXIO_PARAM_TRIGGER_WIDTH               8
#define FLEXIO_PARAM_TRIGGER(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_PARAM_TRIGGER_SHIFT))&FLEXIO_PARAM_TRIGGER_MASK)
/* CTRL Bit Fields */
#define FLEXIO_CTRL_FLEXEN_MASK                  0x1u
#define FLEXIO_CTRL_FLEXEN_SHIFT                 0
#define FLEXIO_CTRL_FLEXEN_WIDTH                 1
#define FLEXIO_CTRL_FLEXEN(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_FLEXEN_SHIFT))&FLEXIO_CTRL_FLEXEN_MASK)
#define FLEXIO_CTRL_SWRST_MASK                   0x2u
#define FLEXIO_CTRL_SWRST_SHIFT                  1
#define FLEXIO_CTRL_SWRST_WIDTH                  1
#define FLEXIO_CTRL_SWRST(x)                     (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_SWRST_SHIFT))&FLEXIO_CTRL_SWRST_MASK)
#define FLEXIO_CTRL_FASTACC_MASK                 0x4u
#define FLEXIO_CTRL_FASTACC_SHIFT                2
#define FLEXIO_CTRL_FASTACC_WIDTH                1
#define FLEXIO_CTRL_FASTACC(x)                   (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_FASTACC_SHIFT))&FLEXIO_CTRL_FASTACC_MASK)
#define FLEXIO_CTRL_DBGE_MASK                    0x40000000u
#define FLEXIO_CTRL_DBGE_SHIFT                   30
#define FLEXIO_CTRL_DBGE_WIDTH                   1
#define FLEXIO_CTRL_DBGE(x)                      (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_DBGE_SHIFT))&FLEXIO_CTRL_DBGE_MASK)
#define FLEXIO_CTRL_DOZEN_MASK                   0x80000000u
#define FLEXIO_CTRL_DOZEN_SHIFT                  31
#define FLEXIO_CTRL_DOZEN_WIDTH                  1
#define FLEXIO_CTRL_DOZEN(x)                     (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_DOZEN_SHIFT))&FLEXIO_CTRL_DOZEN_MASK)
/* PIN Bit Fields */
#define FLEXIO_PIN_PDI_MASK                      0xFFFFFFFFu
#define FLEXIO_PIN_PDI_SHIFT                     0
#define FLEXIO_PIN_PDI_WIDTH                     32
#define FLEXIO_PIN_PDI(x)                        (((uint32_t)(((uint32_t)(x))<<FLEXIO_PIN_PDI_SHIFT))&FLEXIO_PIN_PDI_MASK)
/* SHIFTSTAT Bit Fields */
#define FLEXIO_SHIFTSTAT_SSF_MASK                0xFFu
#define FLEXIO_SHIFTSTAT_SSF_SHIFT               0
#define FLEXIO_SHIFTSTAT_SSF_WIDTH               8
#define FLEXIO_SHIFTSTAT_SSF(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTSTAT_SSF_SHIFT))&FLEXIO_SHIFTSTAT_SSF_MASK)
/* SHIFTERR Bit Fields */
#define FLEXIO_SHIFTERR_SEF_MASK                 0xFFu
#define FLEXIO_SHIFTERR_SEF_SHIFT                0
#define FLEXIO_SHIFTERR_SEF_WIDTH                8
#define FLEXIO_SHIFTERR_SEF(x)                   (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTERR_SEF_SHIFT))&FLEXIO_SHIFTERR_SEF_MASK)
/* TIMSTAT Bit Fields */
#define FLEXIO_TIMSTAT_TSF_MASK                  0xFFu
#define FLEXIO_TIMSTAT_TSF_SHIFT                 0
#define FLEXIO_TIMSTAT_TSF_WIDTH                 8
#define FLEXIO_TIMSTAT_TSF(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMSTAT_TSF_SHIFT))&FLEXIO_TIMSTAT_TSF_MASK)
/* SHIFTSIEN Bit Fields */
#define FLEXIO_SHIFTSIEN_SSIE_MASK               0xFFu
#define FLEXIO_SHIFTSIEN_SSIE_SHIFT              0
#define FLEXIO_SHIFTSIEN_SSIE_WIDTH              8
#define FLEXIO_SHIFTSIEN_SSIE(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTSIEN_SSIE_SHIFT))&FLEXIO_SHIFTSIEN_SSIE_MASK)
/* SHIFTEIEN Bit Fields */
#define FLEXIO_SHIFTEIEN_SEIE_MASK               0xFFu
#define FLEXIO_SHIFTEIEN_SEIE_SHIFT              0
#define FLEXIO_SHIFTEIEN_SEIE_WIDTH              8
#define FLEXIO_SHIFTEIEN_SEIE(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTEIEN_SEIE_SHIFT))&FLEXIO_SHIFTEIEN_SEIE_MASK)
/* TIMIEN Bit Fields */
#define FLEXIO_TIMIEN_TEIE_MASK                  0xFFu
#define FLEXIO_TIMIEN_TEIE_SHIFT                 0
#define FLEXIO_TIMIEN_TEIE_WIDTH                 8
#define FLEXIO_TIMIEN_TEIE(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMIEN_TEIE_SHIFT))&FLEXIO_TIMIEN_TEIE_MASK)
/* SHIFTSDEN Bit Fields */
#define FLEXIO_SHIFTSDEN_SSDE_MASK               0xFFu
#define FLEXIO_SHIFTSDEN_SSDE_SHIFT              0
#define FLEXIO_SHIFTSDEN_SSDE_WIDTH              8
#define FLEXIO_SHIFTSDEN_SSDE(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTSDEN_SSDE_SHIFT))&FLEXIO_SHIFTSDEN_SSDE_MASK)
/* SHIFTSTATE Bit Fields */
#define FLEXIO_SHIFTSTATE_STATE_MASK             0x7u
#define FLEXIO_SHIFTSTATE_STATE_SHIFT            0
#define FLEXIO_SHIFTSTATE_STATE_WIDTH            3
#define FLEXIO_SHIFTSTATE_STATE(x)               (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTSTATE_STATE_SHIFT))&FLEXIO_SHIFTSTATE_STATE_MASK)
/* SHIFTCTL Bit Fields */
#define FLEXIO_SHIFTCTL_SMOD_MASK                0x7u
#define FLEXIO_SHIFTCTL_SMOD_SHIFT               0
#define FLEXIO_SHIFTCTL_SMOD_WIDTH               3
#define FLEXIO_SHIFTCTL_SMOD(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_SMOD_SHIFT))&FLEXIO_SHIFTCTL_SMOD_MASK)
#define FLEXIO_SHIFTCTL_PINPOL_MASK              0x80u
#define FLEXIO_SHIFTCTL_PINPOL_SHIFT             7
#define FLEXIO_SHIFTCTL_PINPOL_WIDTH             1
#define FLEXIO_SHIFTCTL_PINPOL(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_PINPOL_SHIFT))&FLEXIO_SHIFTCTL_PINPOL_MASK)
#define FLEXIO_SHIFTCTL_PINSEL_MASK              0x1F00u
#define FLEXIO_SHIFTCTL_PINSEL_SHIFT             8
#define FLEXIO_SHIFTCTL_PINSEL_WIDTH             5
#define FLEXIO_SHIFTCTL_PINSEL(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_PINSEL_SHIFT))&FLEXIO_SHIFTCTL_PINSEL_MASK)
#define FLEXIO_SHIFTCTL_PINCFG_MASK              0x30000u
#define FLEXIO_SHIFTCTL_PINCFG_SHIFT             16
#define FLEXIO_SHIFTCTL_PINCFG_WIDTH             2
#define FLEXIO_SHIFTCTL_PINCFG(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_PINCFG_SHIFT))&FLEXIO_SHIFTCTL_PINCFG_MASK)
#define FLEXIO_SHIFTCTL_TIMPOL_MASK              0x800000u
#define FLEXIO_SHIFTCTL_TIMPOL_SHIFT             23
#define FLEXIO_SHIFTCTL_TIMPOL_WIDTH             1
#define FLEXIO_SHIFTCTL_TIMPOL(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_TIMPOL_SHIFT))&FLEXIO_SHIFTCTL_TIMPOL_MASK)
#define FLEXIO_SHIFTCTL_TIMSEL_MASK              0x7000000u
#define FLEXIO_SHIFTCTL_TIMSEL_SHIFT             24
#define FLEXIO_SHIFTCTL_TIMSEL_WIDTH             3
#define FLEXIO_SHIFTCTL_TIMSEL(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_TIMSEL_SHIFT))&FLEXIO_SHIFTCTL_TIMSEL_MASK)
/* SHIFTCFG Bit Fields */
#define FLEXIO_SHIFTCFG_SSTART_MASK              0x3u
#define FLEXIO_SHIFTCFG_SSTART_SHIFT             0
#define FLEXIO_SHIFTCFG_SSTART_WIDTH             2
#define FLEXIO_SHIFTCFG_SSTART(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCFG_SSTART_SHIFT))&FLEXIO_SHIFTCFG_SSTART_MASK)
#define FLEXIO_SHIFTCFG_SSTOP_MASK               0x30u
#define FLEXIO_SHIFTCFG_SSTOP_SHIFT              4
#define FLEXIO_SHIFTCFG_SSTOP_WIDTH              2
#define FLEXIO_SHIFTCFG_SSTOP(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCFG_SSTOP_SHIFT))&FLEXIO_SHIFTCFG_SSTOP_MASK)
#define FLEXIO_SHIFTCFG_INSRC_MASK               0x100u
#define FLEXIO_SHIFTCFG_INSRC_SHIFT              8
#define FLEXIO_SHIFTCFG_INSRC_WIDTH              1
#define FLEXIO_SHIFTCFG_INSRC(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCFG_INSRC_SHIFT))&FLEXIO_SHIFTCFG_INSRC_MASK)
#define FLEXIO_SHIFTCFG_PWIDTH_MASK              0x1F0000u
#define FLEXIO_SHIFTCFG_PWIDTH_SHIFT             16
#define FLEXIO_SHIFTCFG_PWIDTH_WIDTH             5
#define FLEXIO_SHIFTCFG_PWIDTH(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCFG_PWIDTH_SHIFT))&FLEXIO_SHIFTCFG_PWIDTH_MASK)
/* SHIFTBUF Bit Fields */
#define FLEXIO_SHIFTBUF_SHIFTBUF_MASK            0xFFFFFFFFu
#define FLEXIO_SHIFTBUF_SHIFTBUF_SHIFT           0
#define FLEXIO_SHIFTBUF_SHIFTBUF_WIDTH           32
#define FLEXIO_SHIFTBUF_SHIFTBUF(x)              (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUF_SHIFTBUF_SHIFT))&FLEXIO_SHIFTBUF_SHIFTBUF_MASK)
/* SHIFTBUFBIS Bit Fields */
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_MASK      0xFFFFFFFFu
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_SHIFT     0
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_WIDTH     32
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS(x)        (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_SHIFT))&FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_MASK)
/* SHIFTBUFBYS Bit Fields */
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_MASK      0xFFFFFFFFu
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_SHIFT     0
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_WIDTH     32
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS(x)        (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_SHIFT))&FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_MASK)
/* SHIFTBUFBBS Bit Fields */
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_MASK      0xFFFFFFFFu
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_SHIFT     0
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_WIDTH     32
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS(x)        (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_SHIFT))&FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_MASK)
/* TIMCTL Bit Fields */
#define FLEXIO_TIMCTL_TIMOD_MASK                 0x3u
#define FLEXIO_TIMCTL_TIMOD_SHIFT                0
#define FLEXIO_TIMCTL_TIMOD_WIDTH                2
#define FLEXIO_TIMCTL_TIMOD(x)                   (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_TIMOD_SHIFT))&FLEXIO_TIMCTL_TIMOD_MASK)
#define FLEXIO_TIMCTL_PINPOL_MASK                0x80u
#define FLEXIO_TIMCTL_PINPOL_SHIFT               7
#define FLEXIO_TIMCTL_PINPOL_WIDTH               1
#define FLEXIO_TIMCTL_PINPOL(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_PINPOL_SHIFT))&FLEXIO_TIMCTL_PINPOL_MASK)
#define FLEXIO_TIMCTL_PINSEL_MASK                0x1F00u
#define FLEXIO_TIMCTL_PINSEL_SHIFT               8
#define FLEXIO_TIMCTL_PINSEL_WIDTH               5
#define FLEXIO_TIMCTL_PINSEL(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_PINSEL_SHIFT))&FLEXIO_TIMCTL_PINSEL_MASK)
#define FLEXIO_TIMCTL_PINCFG_MASK                0x30000u
#define FLEXIO_TIMCTL_PINCFG_SHIFT               16
#define FLEXIO_TIMCTL_PINCFG_WIDTH               2
#define FLEXIO_TIMCTL_PINCFG(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_PINCFG_SHIFT))&FLEXIO_TIMCTL_PINCFG_MASK)
#define FLEXIO_TIMCTL_TRGSRC_MASK                0x400000u
#define FLEXIO_TIMCTL_TRGSRC_SHIFT               22
#define FLEXIO_TIMCTL_TRGSRC_WIDTH               1
#define FLEXIO_TIMCTL_TRGSRC(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_TRGSRC_SHIFT))&FLEXIO_TIMCTL_TRGSRC_MASK)
#define FLEXIO_TIMCTL_TRGPOL_MASK                0x800000u
#define FLEXIO_TIMCTL_TRGPOL_SHIFT               23
#define FLEXIO_TIMCTL_TRGPOL_WIDTH               1
#define FLEXIO_TIMCTL_TRGPOL(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_TRGPOL_SHIFT))&FLEXIO_TIMCTL_TRGPOL_MASK)
#define FLEXIO_TIMCTL_TRGSEL_MASK                0x3F000000u
#define FLEXIO_TIMCTL_TRGSEL_SHIFT               24
#define FLEXIO_TIMCTL_TRGSEL_WIDTH               6
#define FLEXIO_TIMCTL_TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_TRGSEL_SHIFT))&FLEXIO_TIMCTL_TRGSEL_MASK)
/* TIMCFG Bit Fields */
#define FLEXIO_TIMCFG_TSTART_MASK                0x2u
#define FLEXIO_TIMCFG_TSTART_SHIFT               1
#define FLEXIO_TIMCFG_TSTART_WIDTH               1
#define FLEXIO_TIMCFG_TSTART(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TSTART_SHIFT))&FLEXIO_TIMCFG_TSTART_MASK)
#define FLEXIO_TIMCFG_TSTOP_MASK                 0x30u
#define FLEXIO_TIMCFG_TSTOP_SHIFT                4
#define FLEXIO_TIMCFG_TSTOP_WIDTH                2
#define FLEXIO_TIMCFG_TSTOP(x)                   (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TSTOP_SHIFT))&FLEXIO_TIMCFG_TSTOP_MASK)
#define FLEXIO_TIMCFG_TIMENA_MASK                0x700u
#define FLEXIO_TIMCFG_TIMENA_SHIFT               8
#define FLEXIO_TIMCFG_TIMENA_WIDTH               3
#define FLEXIO_TIMCFG_TIMENA(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMENA_SHIFT))&FLEXIO_TIMCFG_TIMENA_MASK)
#define FLEXIO_TIMCFG_TIMDIS_MASK                0x7000u
#define FLEXIO_TIMCFG_TIMDIS_SHIFT               12
#define FLEXIO_TIMCFG_TIMDIS_WIDTH               3
#define FLEXIO_TIMCFG_TIMDIS(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMDIS_SHIFT))&FLEXIO_TIMCFG_TIMDIS_MASK)
#define FLEXIO_TIMCFG_TIMRST_MASK                0x70000u
#define FLEXIO_TIMCFG_TIMRST_SHIFT               16
#define FLEXIO_TIMCFG_TIMRST_WIDTH               3
#define FLEXIO_TIMCFG_TIMRST(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMRST_SHIFT))&FLEXIO_TIMCFG_TIMRST_MASK)
#define FLEXIO_TIMCFG_TIMDEC_MASK                0x300000u
#define FLEXIO_TIMCFG_TIMDEC_SHIFT               20
#define FLEXIO_TIMCFG_TIMDEC_WIDTH               2
#define FLEXIO_TIMCFG_TIMDEC(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMDEC_SHIFT))&FLEXIO_TIMCFG_TIMDEC_MASK)
#define FLEXIO_TIMCFG_TIMOUT_MASK                0x3000000u
#define FLEXIO_TIMCFG_TIMOUT_SHIFT               24
#define FLEXIO_TIMCFG_TIMOUT_WIDTH               2
#define FLEXIO_TIMCFG_TIMOUT(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMOUT_SHIFT))&FLEXIO_TIMCFG_TIMOUT_MASK)
/* TIMCMP Bit Fields */
#define FLEXIO_TIMCMP_CMP_MASK                   0xFFFFu
#define FLEXIO_TIMCMP_CMP_SHIFT                  0
#define FLEXIO_TIMCMP_CMP_WIDTH                  16
#define FLEXIO_TIMCMP_CMP(x)                     (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCMP_CMP_SHIFT))&FLEXIO_TIMCMP_CMP_MASK)
/* SHIFTBUFNBS Bit Fields */
#define FLEXIO_SHIFTBUFNBS_SHIFTBUFNBS_MASK      0xFFFFFFFFu
#define FLEXIO_SHIFTBUFNBS_SHIFTBUFNBS_SHIFT     0
#define FLEXIO_SHIFTBUFNBS_SHIFTBUFNBS_WIDTH     32
#define FLEXIO_SHIFTBUFNBS_SHIFTBUFNBS(x)        (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUFNBS_SHIFTBUFNBS_SHIFT))&FLEXIO_SHIFTBUFNBS_SHIFTBUFNBS_MASK)
/* SHIFTBUFHWS Bit Fields */
#define FLEXIO_SHIFTBUFHWS_SHIFTBUFHWS_MASK      0xFFFFFFFFu
#define FLEXIO_SHIFTBUFHWS_SHIFTBUFHWS_SHIFT     0
#define FLEXIO_SHIFTBUFHWS_SHIFTBUFHWS_WIDTH     32
#define FLEXIO_SHIFTBUFHWS_SHIFTBUFHWS(x)        (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUFHWS_SHIFTBUFHWS_SHIFT))&FLEXIO_SHIFTBUFHWS_SHIFTBUFHWS_MASK)
/* SHIFTBUFNIS Bit Fields */
#define FLEXIO_SHIFTBUFNIS_SHIFTBUFNIS_MASK      0xFFFFFFFFu
#define FLEXIO_SHIFTBUFNIS_SHIFTBUFNIS_SHIFT     0
#define FLEXIO_SHIFTBUFNIS_SHIFTBUFNIS_WIDTH     32
#define FLEXIO_SHIFTBUFNIS_SHIFTBUFNIS(x)        (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUFNIS_SHIFTBUFNIS_SHIFT))&FLEXIO_SHIFTBUFNIS_SHIFTBUFNIS_MASK)

/*!
 * @}
 */ /* end of group FLEXIO_Register_Masks */


/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO0 base address */
#define FLEXIO0_BASE                             (0x400CA000u)
/** Peripheral FLEXIO0 base pointer */
#define FLEXIO0                                  ((FLEXIO_Type *)FLEXIO0_BASE)
#define FLEXIO0_BASE_PTR                         (FLEXIO0)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { FLEXIO0_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { FLEXIO0 }

/* ----------------------------------------------------------------------------
   -- FLEXIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXIO_Register_Accessor_Macros FLEXIO - Register accessor macros
 * @{
 */


/* FLEXIO - Register instance definitions */
/* FLEXIO0 */
#define FLEXIO0_VERID                            FLEXIO_VERID_REG(FLEXIO0)
#define FLEXIO0_PARAM                            FLEXIO_PARAM_REG(FLEXIO0)
#define FLEXIO0_CTRL                             FLEXIO_CTRL_REG(FLEXIO0)
#define FLEXIO0_PIN                              FLEXIO_PIN_REG(FLEXIO0)
#define FLEXIO0_SHIFTSTAT                        FLEXIO_SHIFTSTAT_REG(FLEXIO0)
#define FLEXIO0_SHIFTERR                         FLEXIO_SHIFTERR_REG(FLEXIO0)
#define FLEXIO0_TIMSTAT                          FLEXIO_TIMSTAT_REG(FLEXIO0)
#define FLEXIO0_SHIFTSIEN                        FLEXIO_SHIFTSIEN_REG(FLEXIO0)
#define FLEXIO0_SHIFTEIEN                        FLEXIO_SHIFTEIEN_REG(FLEXIO0)
#define FLEXIO0_TIMIEN                           FLEXIO_TIMIEN_REG(FLEXIO0)
#define FLEXIO0_SHIFTSDEN                        FLEXIO_SHIFTSDEN_REG(FLEXIO0)
#define FLEXIO0_SHIFTSTATE                       FLEXIO_SHIFTSTATE_REG(FLEXIO0)
#define FLEXIO0_SHIFTCTL0                        FLEXIO_SHIFTCTL_REG(FLEXIO0,0)
#define FLEXIO0_SHIFTCTL1                        FLEXIO_SHIFTCTL_REG(FLEXIO0,1)
#define FLEXIO0_SHIFTCTL2                        FLEXIO_SHIFTCTL_REG(FLEXIO0,2)
#define FLEXIO0_SHIFTCTL3                        FLEXIO_SHIFTCTL_REG(FLEXIO0,3)
#define FLEXIO0_SHIFTCTL4                        FLEXIO_SHIFTCTL_REG(FLEXIO0,4)
#define FLEXIO0_SHIFTCTL5                        FLEXIO_SHIFTCTL_REG(FLEXIO0,5)
#define FLEXIO0_SHIFTCTL6                        FLEXIO_SHIFTCTL_REG(FLEXIO0,6)
#define FLEXIO0_SHIFTCTL7                        FLEXIO_SHIFTCTL_REG(FLEXIO0,7)
#define FLEXIO0_SHIFTCFG0                        FLEXIO_SHIFTCFG_REG(FLEXIO0,0)
#define FLEXIO0_SHIFTCFG1                        FLEXIO_SHIFTCFG_REG(FLEXIO0,1)
#define FLEXIO0_SHIFTCFG2                        FLEXIO_SHIFTCFG_REG(FLEXIO0,2)
#define FLEXIO0_SHIFTCFG3                        FLEXIO_SHIFTCFG_REG(FLEXIO0,3)
#define FLEXIO0_SHIFTCFG4                        FLEXIO_SHIFTCFG_REG(FLEXIO0,4)
#define FLEXIO0_SHIFTCFG5                        FLEXIO_SHIFTCFG_REG(FLEXIO0,5)
#define FLEXIO0_SHIFTCFG6                        FLEXIO_SHIFTCFG_REG(FLEXIO0,6)
#define FLEXIO0_SHIFTCFG7                        FLEXIO_SHIFTCFG_REG(FLEXIO0,7)
#define FLEXIO0_SHIFTBUF0                        FLEXIO_SHIFTBUF_REG(FLEXIO0,0)
#define FLEXIO0_SHIFTBUF1                        FLEXIO_SHIFTBUF_REG(FLEXIO0,1)
#define FLEXIO0_SHIFTBUF2                        FLEXIO_SHIFTBUF_REG(FLEXIO0,2)
#define FLEXIO0_SHIFTBUF3                        FLEXIO_SHIFTBUF_REG(FLEXIO0,3)
#define FLEXIO0_SHIFTBUF4                        FLEXIO_SHIFTBUF_REG(FLEXIO0,4)
#define FLEXIO0_SHIFTBUF5                        FLEXIO_SHIFTBUF_REG(FLEXIO0,5)
#define FLEXIO0_SHIFTBUF6                        FLEXIO_SHIFTBUF_REG(FLEXIO0,6)
#define FLEXIO0_SHIFTBUF7                        FLEXIO_SHIFTBUF_REG(FLEXIO0,7)
#define FLEXIO0_SHIFTBUFBIS0                     FLEXIO_SHIFTBUFBIS_REG(FLEXIO0,0)
#define FLEXIO0_SHIFTBUFBIS1                     FLEXIO_SHIFTBUFBIS_REG(FLEXIO0,1)
#define FLEXIO0_SHIFTBUFBIS2                     FLEXIO_SHIFTBUFBIS_REG(FLEXIO0,2)
#define FLEXIO0_SHIFTBUFBIS3                     FLEXIO_SHIFTBUFBIS_REG(FLEXIO0,3)
#define FLEXIO0_SHIFTBUFBIS4                     FLEXIO_SHIFTBUFBIS_REG(FLEXIO0,4)
#define FLEXIO0_SHIFTBUFBIS5                     FLEXIO_SHIFTBUFBIS_REG(FLEXIO0,5)
#define FLEXIO0_SHIFTBUFBIS6                     FLEXIO_SHIFTBUFBIS_REG(FLEXIO0,6)
#define FLEXIO0_SHIFTBUFBIS7                     FLEXIO_SHIFTBUFBIS_REG(FLEXIO0,7)
#define FLEXIO0_SHIFTBUFBYS0                     FLEXIO_SHIFTBUFBYS_REG(FLEXIO0,0)
#define FLEXIO0_SHIFTBUFBYS1                     FLEXIO_SHIFTBUFBYS_REG(FLEXIO0,1)
#define FLEXIO0_SHIFTBUFBYS2                     FLEXIO_SHIFTBUFBYS_REG(FLEXIO0,2)
#define FLEXIO0_SHIFTBUFBYS3                     FLEXIO_SHIFTBUFBYS_REG(FLEXIO0,3)
#define FLEXIO0_SHIFTBUFBYS4                     FLEXIO_SHIFTBUFBYS_REG(FLEXIO0,4)
#define FLEXIO0_SHIFTBUFBYS5                     FLEXIO_SHIFTBUFBYS_REG(FLEXIO0,5)
#define FLEXIO0_SHIFTBUFBYS6                     FLEXIO_SHIFTBUFBYS_REG(FLEXIO0,6)
#define FLEXIO0_SHIFTBUFBYS7                     FLEXIO_SHIFTBUFBYS_REG(FLEXIO0,7)
#define FLEXIO0_SHIFTBUFBBS0                     FLEXIO_SHIFTBUFBBS_REG(FLEXIO0,0)
#define FLEXIO0_SHIFTBUFBBS1                     FLEXIO_SHIFTBUFBBS_REG(FLEXIO0,1)
#define FLEXIO0_SHIFTBUFBBS2                     FLEXIO_SHIFTBUFBBS_REG(FLEXIO0,2)
#define FLEXIO0_SHIFTBUFBBS3                     FLEXIO_SHIFTBUFBBS_REG(FLEXIO0,3)
#define FLEXIO0_SHIFTBUFBBS4                     FLEXIO_SHIFTBUFBBS_REG(FLEXIO0,4)
#define FLEXIO0_SHIFTBUFBBS5                     FLEXIO_SHIFTBUFBBS_REG(FLEXIO0,5)
#define FLEXIO0_SHIFTBUFBBS6                     FLEXIO_SHIFTBUFBBS_REG(FLEXIO0,6)
#define FLEXIO0_SHIFTBUFBBS7                     FLEXIO_SHIFTBUFBBS_REG(FLEXIO0,7)
#define FLEXIO0_TIMCTL0                          FLEXIO_TIMCTL_REG(FLEXIO0,0)
#define FLEXIO0_TIMCTL1                          FLEXIO_TIMCTL_REG(FLEXIO0,1)
#define FLEXIO0_TIMCTL2                          FLEXIO_TIMCTL_REG(FLEXIO0,2)
#define FLEXIO0_TIMCTL3                          FLEXIO_TIMCTL_REG(FLEXIO0,3)
#define FLEXIO0_TIMCTL4                          FLEXIO_TIMCTL_REG(FLEXIO0,4)
#define FLEXIO0_TIMCTL5                          FLEXIO_TIMCTL_REG(FLEXIO0,5)
#define FLEXIO0_TIMCTL6                          FLEXIO_TIMCTL_REG(FLEXIO0,6)
#define FLEXIO0_TIMCTL7                          FLEXIO_TIMCTL_REG(FLEXIO0,7)
#define FLEXIO0_TIMCFG0                          FLEXIO_TIMCFG_REG(FLEXIO0,0)
#define FLEXIO0_TIMCFG1                          FLEXIO_TIMCFG_REG(FLEXIO0,1)
#define FLEXIO0_TIMCFG2                          FLEXIO_TIMCFG_REG(FLEXIO0,2)
#define FLEXIO0_TIMCFG3                          FLEXIO_TIMCFG_REG(FLEXIO0,3)
#define FLEXIO0_TIMCFG4                          FLEXIO_TIMCFG_REG(FLEXIO0,4)
#define FLEXIO0_TIMCFG5                          FLEXIO_TIMCFG_REG(FLEXIO0,5)
#define FLEXIO0_TIMCFG6                          FLEXIO_TIMCFG_REG(FLEXIO0,6)
#define FLEXIO0_TIMCFG7                          FLEXIO_TIMCFG_REG(FLEXIO0,7)
#define FLEXIO0_TIMCMP0                          FLEXIO_TIMCMP_REG(FLEXIO0,0)
#define FLEXIO0_TIMCMP1                          FLEXIO_TIMCMP_REG(FLEXIO0,1)
#define FLEXIO0_TIMCMP2                          FLEXIO_TIMCMP_REG(FLEXIO0,2)
#define FLEXIO0_TIMCMP3                          FLEXIO_TIMCMP_REG(FLEXIO0,3)
#define FLEXIO0_TIMCMP4                          FLEXIO_TIMCMP_REG(FLEXIO0,4)
#define FLEXIO0_TIMCMP5                          FLEXIO_TIMCMP_REG(FLEXIO0,5)
#define FLEXIO0_TIMCMP6                          FLEXIO_TIMCMP_REG(FLEXIO0,6)
#define FLEXIO0_TIMCMP7                          FLEXIO_TIMCMP_REG(FLEXIO0,7)
#define FLEXIO0_SHIFTBUFNBS0                     FLEXIO_SHIFTBUFNBS_REG(FLEXIO0,0)
#define FLEXIO0_SHIFTBUFNBS1                     FLEXIO_SHIFTBUFNBS_REG(FLEXIO0,1)
#define FLEXIO0_SHIFTBUFNBS2                     FLEXIO_SHIFTBUFNBS_REG(FLEXIO0,2)
#define FLEXIO0_SHIFTBUFNBS3                     FLEXIO_SHIFTBUFNBS_REG(FLEXIO0,3)
#define FLEXIO0_SHIFTBUFNBS4                     FLEXIO_SHIFTBUFNBS_REG(FLEXIO0,4)
#define FLEXIO0_SHIFTBUFNBS5                     FLEXIO_SHIFTBUFNBS_REG(FLEXIO0,5)
#define FLEXIO0_SHIFTBUFNBS6                     FLEXIO_SHIFTBUFNBS_REG(FLEXIO0,6)
#define FLEXIO0_SHIFTBUFNBS7                     FLEXIO_SHIFTBUFNBS_REG(FLEXIO0,7)
#define FLEXIO0_SHIFTBUFHWS0                     FLEXIO_SHIFTBUFHWS_REG(FLEXIO0,0)
#define FLEXIO0_SHIFTBUFHWS1                     FLEXIO_SHIFTBUFHWS_REG(FLEXIO0,1)
#define FLEXIO0_SHIFTBUFHWS2                     FLEXIO_SHIFTBUFHWS_REG(FLEXIO0,2)
#define FLEXIO0_SHIFTBUFHWS3                     FLEXIO_SHIFTBUFHWS_REG(FLEXIO0,3)
#define FLEXIO0_SHIFTBUFHWS4                     FLEXIO_SHIFTBUFHWS_REG(FLEXIO0,4)
#define FLEXIO0_SHIFTBUFHWS5                     FLEXIO_SHIFTBUFHWS_REG(FLEXIO0,5)
#define FLEXIO0_SHIFTBUFHWS6                     FLEXIO_SHIFTBUFHWS_REG(FLEXIO0,6)
#define FLEXIO0_SHIFTBUFHWS7                     FLEXIO_SHIFTBUFHWS_REG(FLEXIO0,7)
#define FLEXIO0_SHIFTBUFNIS0                     FLEXIO_SHIFTBUFNIS_REG(FLEXIO0,0)
#define FLEXIO0_SHIFTBUFNIS1                     FLEXIO_SHIFTBUFNIS_REG(FLEXIO0,1)
#define FLEXIO0_SHIFTBUFNIS2                     FLEXIO_SHIFTBUFNIS_REG(FLEXIO0,2)
#define FLEXIO0_SHIFTBUFNIS3                     FLEXIO_SHIFTBUFNIS_REG(FLEXIO0,3)
#define FLEXIO0_SHIFTBUFNIS4                     FLEXIO_SHIFTBUFNIS_REG(FLEXIO0,4)
#define FLEXIO0_SHIFTBUFNIS5                     FLEXIO_SHIFTBUFNIS_REG(FLEXIO0,5)
#define FLEXIO0_SHIFTBUFNIS6                     FLEXIO_SHIFTBUFNIS_REG(FLEXIO0,6)
#define FLEXIO0_SHIFTBUFNIS7                     FLEXIO_SHIFTBUFNIS_REG(FLEXIO0,7)

/* FLEXIO - Register array accessors */
#define FLEXIO0_SHIFTCTL(index)                  FLEXIO_SHIFTCTL_REG(FLEXIO0,index)
#define FLEXIO0_SHIFTCFG(index)                  FLEXIO_SHIFTCFG_REG(FLEXIO0,index)
#define FLEXIO0_SHIFTBUF(index)                  FLEXIO_SHIFTBUF_REG(FLEXIO0,index)
#define FLEXIO0_SHIFTBUFBIS(index)               FLEXIO_SHIFTBUFBIS_REG(FLEXIO0,index)
#define FLEXIO0_SHIFTBUFBYS(index)               FLEXIO_SHIFTBUFBYS_REG(FLEXIO0,index)
#define FLEXIO0_SHIFTBUFBBS(index)               FLEXIO_SHIFTBUFBBS_REG(FLEXIO0,index)
#define FLEXIO0_TIMCTL(index)                    FLEXIO_TIMCTL_REG(FLEXIO0,index)
#define FLEXIO0_TIMCFG(index)                    FLEXIO_TIMCFG_REG(FLEXIO0,index)
#define FLEXIO0_TIMCMP(index)                    FLEXIO_TIMCMP_REG(FLEXIO0,index)
#define FLEXIO0_SHIFTBUFNBS(index)               FLEXIO_SHIFTBUFNBS_REG(FLEXIO0,index)
#define FLEXIO0_SHIFTBUFHWS(index)               FLEXIO_SHIFTBUFHWS_REG(FLEXIO0,index)
#define FLEXIO0_SHIFTBUFNIS(index)               FLEXIO_SHIFTBUFNIS_REG(FLEXIO0,index)

/*!
 * @}
 */ /* end of group FLEXIO_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group FLEXIO_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FTFA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFA_Peripheral_Access_Layer FTFA Peripheral Access Layer
 * @{
 */

/** FTFA - Register Layout Typedef */
typedef struct {
  __IO uint8_t FSTAT;                              /**< Flash Status Register, offset: 0x0 */
  __IO uint8_t FCNFG;                              /**< Flash Configuration Register, offset: 0x1 */
  __I  uint8_t FSEC;                               /**< Flash Security Register, offset: 0x2 */
  __I  uint8_t FOPT;                               /**< Flash Option Register, offset: 0x3 */
  __IO uint8_t FCCOB3;                             /**< Flash Common Command Object Registers, offset: 0x4 */
  __IO uint8_t FCCOB2;                             /**< Flash Common Command Object Registers, offset: 0x5 */
  __IO uint8_t FCCOB1;                             /**< Flash Common Command Object Registers, offset: 0x6 */
  __IO uint8_t FCCOB0;                             /**< Flash Common Command Object Registers, offset: 0x7 */
  __IO uint8_t FCCOB7;                             /**< Flash Common Command Object Registers, offset: 0x8 */
  __IO uint8_t FCCOB6;                             /**< Flash Common Command Object Registers, offset: 0x9 */
  __IO uint8_t FCCOB5;                             /**< Flash Common Command Object Registers, offset: 0xA */
  __IO uint8_t FCCOB4;                             /**< Flash Common Command Object Registers, offset: 0xB */
  __IO uint8_t FCCOBB;                             /**< Flash Common Command Object Registers, offset: 0xC */
  __IO uint8_t FCCOBA;                             /**< Flash Common Command Object Registers, offset: 0xD */
  __IO uint8_t FCCOB9;                             /**< Flash Common Command Object Registers, offset: 0xE */
  __IO uint8_t FCCOB8;                             /**< Flash Common Command Object Registers, offset: 0xF */
  __IO uint8_t FPROT3;                             /**< Program Flash Protection Registers, offset: 0x10 */
  __IO uint8_t FPROT2;                             /**< Program Flash Protection Registers, offset: 0x11 */
  __IO uint8_t FPROT1;                             /**< Program Flash Protection Registers, offset: 0x12 */
  __IO uint8_t FPROT0;                             /**< Program Flash Protection Registers, offset: 0x13 */
       uint8_t RESERVED_0[4];
  __I  uint8_t XACCH3;                             /**< Execute-only Access Registers, offset: 0x18 */
  __I  uint8_t XACCH2;                             /**< Execute-only Access Registers, offset: 0x19 */
  __I  uint8_t XACCH1;                             /**< Execute-only Access Registers, offset: 0x1A */
  __I  uint8_t XACCH0;                             /**< Execute-only Access Registers, offset: 0x1B */
  __I  uint8_t XACCL3;                             /**< Execute-only Access Registers, offset: 0x1C */
  __I  uint8_t XACCL2;                             /**< Execute-only Access Registers, offset: 0x1D */
  __I  uint8_t XACCL1;                             /**< Execute-only Access Registers, offset: 0x1E */
  __I  uint8_t XACCL0;                             /**< Execute-only Access Registers, offset: 0x1F */
  __I  uint8_t SACCH3;                             /**< Supervisor-only Access Registers, offset: 0x20 */
  __I  uint8_t SACCH2;                             /**< Supervisor-only Access Registers, offset: 0x21 */
  __I  uint8_t SACCH1;                             /**< Supervisor-only Access Registers, offset: 0x22 */
  __I  uint8_t SACCH0;                             /**< Supervisor-only Access Registers, offset: 0x23 */
  __I  uint8_t SACCL3;                             /**< Supervisor-only Access Registers, offset: 0x24 */
  __I  uint8_t SACCL2;                             /**< Supervisor-only Access Registers, offset: 0x25 */
  __I  uint8_t SACCL1;                             /**< Supervisor-only Access Registers, offset: 0x26 */
  __I  uint8_t SACCL0;                             /**< Supervisor-only Access Registers, offset: 0x27 */
  __I  uint8_t FACSS;                              /**< Flash Access Segment Size Register, offset: 0x28 */
       uint8_t RESERVED_1[2];
  __I  uint8_t FACSN;                              /**< Flash Access Segment Number Register, offset: 0x2B */
} FTFA_Type, *FTFA_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTFA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFA_Register_Accessor_Macros FTFA - Register accessor macros
 * @{
 */


/* FTFA - Register accessors */
#define FTFA_FSTAT_REG(base)                     ((base)->FSTAT)
#define FTFA_FCNFG_REG(base)                     ((base)->FCNFG)
#define FTFA_FSEC_REG(base)                      ((base)->FSEC)
#define FTFA_FOPT_REG(base)                      ((base)->FOPT)
#define FTFA_FCCOB3_REG(base)                    ((base)->FCCOB3)
#define FTFA_FCCOB2_REG(base)                    ((base)->FCCOB2)
#define FTFA_FCCOB1_REG(base)                    ((base)->FCCOB1)
#define FTFA_FCCOB0_REG(base)                    ((base)->FCCOB0)
#define FTFA_FCCOB7_REG(base)                    ((base)->FCCOB7)
#define FTFA_FCCOB6_REG(base)                    ((base)->FCCOB6)
#define FTFA_FCCOB5_REG(base)                    ((base)->FCCOB5)
#define FTFA_FCCOB4_REG(base)                    ((base)->FCCOB4)
#define FTFA_FCCOBB_REG(base)                    ((base)->FCCOBB)
#define FTFA_FCCOBA_REG(base)                    ((base)->FCCOBA)
#define FTFA_FCCOB9_REG(base)                    ((base)->FCCOB9)
#define FTFA_FCCOB8_REG(base)                    ((base)->FCCOB8)
#define FTFA_FPROT3_REG(base)                    ((base)->FPROT3)
#define FTFA_FPROT2_REG(base)                    ((base)->FPROT2)
#define FTFA_FPROT1_REG(base)                    ((base)->FPROT1)
#define FTFA_FPROT0_REG(base)                    ((base)->FPROT0)
#define FTFA_XACCH3_REG(base)                    ((base)->XACCH3)
#define FTFA_XACCH2_REG(base)                    ((base)->XACCH2)
#define FTFA_XACCH1_REG(base)                    ((base)->XACCH1)
#define FTFA_XACCH0_REG(base)                    ((base)->XACCH0)
#define FTFA_XACCL3_REG(base)                    ((base)->XACCL3)
#define FTFA_XACCL2_REG(base)                    ((base)->XACCL2)
#define FTFA_XACCL1_REG(base)                    ((base)->XACCL1)
#define FTFA_XACCL0_REG(base)                    ((base)->XACCL0)
#define FTFA_SACCH3_REG(base)                    ((base)->SACCH3)
#define FTFA_SACCH2_REG(base)                    ((base)->SACCH2)
#define FTFA_SACCH1_REG(base)                    ((base)->SACCH1)
#define FTFA_SACCH0_REG(base)                    ((base)->SACCH0)
#define FTFA_SACCL3_REG(base)                    ((base)->SACCL3)
#define FTFA_SACCL2_REG(base)                    ((base)->SACCL2)
#define FTFA_SACCL1_REG(base)                    ((base)->SACCL1)
#define FTFA_SACCL0_REG(base)                    ((base)->SACCL0)
#define FTFA_FACSS_REG(base)                     ((base)->FACSS)
#define FTFA_FACSN_REG(base)                     ((base)->FACSN)

/*!
 * @}
 */ /* end of group FTFA_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTFA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFA_Register_Masks FTFA Register Masks
 * @{
 */

/* FSTAT Bit Fields */
#define FTFA_FSTAT_MGSTAT0_MASK                  0x1u
#define FTFA_FSTAT_MGSTAT0_SHIFT                 0
#define FTFA_FSTAT_MGSTAT0_WIDTH                 1
#define FTFA_FSTAT_MGSTAT0(x)                    (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_MGSTAT0_SHIFT))&FTFA_FSTAT_MGSTAT0_MASK)
#define FTFA_FSTAT_FPVIOL_MASK                   0x10u
#define FTFA_FSTAT_FPVIOL_SHIFT                  4
#define FTFA_FSTAT_FPVIOL_WIDTH                  1
#define FTFA_FSTAT_FPVIOL(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_FPVIOL_SHIFT))&FTFA_FSTAT_FPVIOL_MASK)
#define FTFA_FSTAT_ACCERR_MASK                   0x20u
#define FTFA_FSTAT_ACCERR_SHIFT                  5
#define FTFA_FSTAT_ACCERR_WIDTH                  1
#define FTFA_FSTAT_ACCERR(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_ACCERR_SHIFT))&FTFA_FSTAT_ACCERR_MASK)
#define FTFA_FSTAT_RDCOLERR_MASK                 0x40u
#define FTFA_FSTAT_RDCOLERR_SHIFT                6
#define FTFA_FSTAT_RDCOLERR_WIDTH                1
#define FTFA_FSTAT_RDCOLERR(x)                   (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_RDCOLERR_SHIFT))&FTFA_FSTAT_RDCOLERR_MASK)
#define FTFA_FSTAT_CCIF_MASK                     0x80u
#define FTFA_FSTAT_CCIF_SHIFT                    7
#define FTFA_FSTAT_CCIF_WIDTH                    1
#define FTFA_FSTAT_CCIF(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_CCIF_SHIFT))&FTFA_FSTAT_CCIF_MASK)
/* FCNFG Bit Fields */
#define FTFA_FCNFG_ERSSUSP_MASK                  0x10u
#define FTFA_FCNFG_ERSSUSP_SHIFT                 4
#define FTFA_FCNFG_ERSSUSP_WIDTH                 1
#define FTFA_FCNFG_ERSSUSP(x)                    (((uint8_t)(((uint8_t)(x))<<FTFA_FCNFG_ERSSUSP_SHIFT))&FTFA_FCNFG_ERSSUSP_MASK)
#define FTFA_FCNFG_ERSAREQ_MASK                  0x20u
#define FTFA_FCNFG_ERSAREQ_SHIFT                 5
#define FTFA_FCNFG_ERSAREQ_WIDTH                 1
#define FTFA_FCNFG_ERSAREQ(x)                    (((uint8_t)(((uint8_t)(x))<<FTFA_FCNFG_ERSAREQ_SHIFT))&FTFA_FCNFG_ERSAREQ_MASK)
#define FTFA_FCNFG_RDCOLLIE_MASK                 0x40u
#define FTFA_FCNFG_RDCOLLIE_SHIFT                6
#define FTFA_FCNFG_RDCOLLIE_WIDTH                1
#define FTFA_FCNFG_RDCOLLIE(x)                   (((uint8_t)(((uint8_t)(x))<<FTFA_FCNFG_RDCOLLIE_SHIFT))&FTFA_FCNFG_RDCOLLIE_MASK)
#define FTFA_FCNFG_CCIE_MASK                     0x80u
#define FTFA_FCNFG_CCIE_SHIFT                    7
#define FTFA_FCNFG_CCIE_WIDTH                    1
#define FTFA_FCNFG_CCIE(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FCNFG_CCIE_SHIFT))&FTFA_FCNFG_CCIE_MASK)
/* FSEC Bit Fields */
#define FTFA_FSEC_SEC_MASK                       0x3u
#define FTFA_FSEC_SEC_SHIFT                      0
#define FTFA_FSEC_SEC_WIDTH                      2
#define FTFA_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_SEC_SHIFT))&FTFA_FSEC_SEC_MASK)
#define FTFA_FSEC_FSLACC_MASK                    0xCu
#define FTFA_FSEC_FSLACC_SHIFT                   2
#define FTFA_FSEC_FSLACC_WIDTH                   2
#define FTFA_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_FSLACC_SHIFT))&FTFA_FSEC_FSLACC_MASK)
#define FTFA_FSEC_MEEN_MASK                      0x30u
#define FTFA_FSEC_MEEN_SHIFT                     4
#define FTFA_FSEC_MEEN_WIDTH                     2
#define FTFA_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_MEEN_SHIFT))&FTFA_FSEC_MEEN_MASK)
#define FTFA_FSEC_KEYEN_MASK                     0xC0u
#define FTFA_FSEC_KEYEN_SHIFT                    6
#define FTFA_FSEC_KEYEN_WIDTH                    2
#define FTFA_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_KEYEN_SHIFT))&FTFA_FSEC_KEYEN_MASK)
/* FOPT Bit Fields */
#define FTFA_FOPT_OPT_MASK                       0xFFu
#define FTFA_FOPT_OPT_SHIFT                      0
#define FTFA_FOPT_OPT_WIDTH                      8
#define FTFA_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x))<<FTFA_FOPT_OPT_SHIFT))&FTFA_FOPT_OPT_MASK)
/* FCCOB3 Bit Fields */
#define FTFA_FCCOB3_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB3_CCOBn_SHIFT                  0
#define FTFA_FCCOB3_CCOBn_WIDTH                  8
#define FTFA_FCCOB3_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB3_CCOBn_SHIFT))&FTFA_FCCOB3_CCOBn_MASK)
/* FCCOB2 Bit Fields */
#define FTFA_FCCOB2_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB2_CCOBn_SHIFT                  0
#define FTFA_FCCOB2_CCOBn_WIDTH                  8
#define FTFA_FCCOB2_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB2_CCOBn_SHIFT))&FTFA_FCCOB2_CCOBn_MASK)
/* FCCOB1 Bit Fields */
#define FTFA_FCCOB1_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB1_CCOBn_SHIFT                  0
#define FTFA_FCCOB1_CCOBn_WIDTH                  8
#define FTFA_FCCOB1_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB1_CCOBn_SHIFT))&FTFA_FCCOB1_CCOBn_MASK)
/* FCCOB0 Bit Fields */
#define FTFA_FCCOB0_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB0_CCOBn_SHIFT                  0
#define FTFA_FCCOB0_CCOBn_WIDTH                  8
#define FTFA_FCCOB0_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB0_CCOBn_SHIFT))&FTFA_FCCOB0_CCOBn_MASK)
/* FCCOB7 Bit Fields */
#define FTFA_FCCOB7_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB7_CCOBn_SHIFT                  0
#define FTFA_FCCOB7_CCOBn_WIDTH                  8
#define FTFA_FCCOB7_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB7_CCOBn_SHIFT))&FTFA_FCCOB7_CCOBn_MASK)
/* FCCOB6 Bit Fields */
#define FTFA_FCCOB6_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB6_CCOBn_SHIFT                  0
#define FTFA_FCCOB6_CCOBn_WIDTH                  8
#define FTFA_FCCOB6_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB6_CCOBn_SHIFT))&FTFA_FCCOB6_CCOBn_MASK)
/* FCCOB5 Bit Fields */
#define FTFA_FCCOB5_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB5_CCOBn_SHIFT                  0
#define FTFA_FCCOB5_CCOBn_WIDTH                  8
#define FTFA_FCCOB5_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB5_CCOBn_SHIFT))&FTFA_FCCOB5_CCOBn_MASK)
/* FCCOB4 Bit Fields */
#define FTFA_FCCOB4_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB4_CCOBn_SHIFT                  0
#define FTFA_FCCOB4_CCOBn_WIDTH                  8
#define FTFA_FCCOB4_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB4_CCOBn_SHIFT))&FTFA_FCCOB4_CCOBn_MASK)
/* FCCOBB Bit Fields */
#define FTFA_FCCOBB_CCOBn_MASK                   0xFFu
#define FTFA_FCCOBB_CCOBn_SHIFT                  0
#define FTFA_FCCOBB_CCOBn_WIDTH                  8
#define FTFA_FCCOBB_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOBB_CCOBn_SHIFT))&FTFA_FCCOBB_CCOBn_MASK)
/* FCCOBA Bit Fields */
#define FTFA_FCCOBA_CCOBn_MASK                   0xFFu
#define FTFA_FCCOBA_CCOBn_SHIFT                  0
#define FTFA_FCCOBA_CCOBn_WIDTH                  8
#define FTFA_FCCOBA_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOBA_CCOBn_SHIFT))&FTFA_FCCOBA_CCOBn_MASK)
/* FCCOB9 Bit Fields */
#define FTFA_FCCOB9_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB9_CCOBn_SHIFT                  0
#define FTFA_FCCOB9_CCOBn_WIDTH                  8
#define FTFA_FCCOB9_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB9_CCOBn_SHIFT))&FTFA_FCCOB9_CCOBn_MASK)
/* FCCOB8 Bit Fields */
#define FTFA_FCCOB8_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB8_CCOBn_SHIFT                  0
#define FTFA_FCCOB8_CCOBn_WIDTH                  8
#define FTFA_FCCOB8_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB8_CCOBn_SHIFT))&FTFA_FCCOB8_CCOBn_MASK)
/* FPROT3 Bit Fields */
#define FTFA_FPROT3_PROT_MASK                    0xFFu
#define FTFA_FPROT3_PROT_SHIFT                   0
#define FTFA_FPROT3_PROT_WIDTH                   8
#define FTFA_FPROT3_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT3_PROT_SHIFT))&FTFA_FPROT3_PROT_MASK)
/* FPROT2 Bit Fields */
#define FTFA_FPROT2_PROT_MASK                    0xFFu
#define FTFA_FPROT2_PROT_SHIFT                   0
#define FTFA_FPROT2_PROT_WIDTH                   8
#define FTFA_FPROT2_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT2_PROT_SHIFT))&FTFA_FPROT2_PROT_MASK)
/* FPROT1 Bit Fields */
#define FTFA_FPROT1_PROT_MASK                    0xFFu
#define FTFA_FPROT1_PROT_SHIFT                   0
#define FTFA_FPROT1_PROT_WIDTH                   8
#define FTFA_FPROT1_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT1_PROT_SHIFT))&FTFA_FPROT1_PROT_MASK)
/* FPROT0 Bit Fields */
#define FTFA_FPROT0_PROT_MASK                    0xFFu
#define FTFA_FPROT0_PROT_SHIFT                   0
#define FTFA_FPROT0_PROT_WIDTH                   8
#define FTFA_FPROT0_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT0_PROT_SHIFT))&FTFA_FPROT0_PROT_MASK)
/* XACCH3 Bit Fields */
#define FTFA_XACCH3_XA_MASK                      0xFFu
#define FTFA_XACCH3_XA_SHIFT                     0
#define FTFA_XACCH3_XA_WIDTH                     8
#define FTFA_XACCH3_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCH3_XA_SHIFT))&FTFA_XACCH3_XA_MASK)
/* XACCH2 Bit Fields */
#define FTFA_XACCH2_XA_MASK                      0xFFu
#define FTFA_XACCH2_XA_SHIFT                     0
#define FTFA_XACCH2_XA_WIDTH                     8
#define FTFA_XACCH2_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCH2_XA_SHIFT))&FTFA_XACCH2_XA_MASK)
/* XACCH1 Bit Fields */
#define FTFA_XACCH1_XA_MASK                      0xFFu
#define FTFA_XACCH1_XA_SHIFT                     0
#define FTFA_XACCH1_XA_WIDTH                     8
#define FTFA_XACCH1_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCH1_XA_SHIFT))&FTFA_XACCH1_XA_MASK)
/* XACCH0 Bit Fields */
#define FTFA_XACCH0_XA_MASK                      0xFFu
#define FTFA_XACCH0_XA_SHIFT                     0
#define FTFA_XACCH0_XA_WIDTH                     8
#define FTFA_XACCH0_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCH0_XA_SHIFT))&FTFA_XACCH0_XA_MASK)
/* XACCL3 Bit Fields */
#define FTFA_XACCL3_XA_MASK                      0xFFu
#define FTFA_XACCL3_XA_SHIFT                     0
#define FTFA_XACCL3_XA_WIDTH                     8
#define FTFA_XACCL3_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCL3_XA_SHIFT))&FTFA_XACCL3_XA_MASK)
/* XACCL2 Bit Fields */
#define FTFA_XACCL2_XA_MASK                      0xFFu
#define FTFA_XACCL2_XA_SHIFT                     0
#define FTFA_XACCL2_XA_WIDTH                     8
#define FTFA_XACCL2_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCL2_XA_SHIFT))&FTFA_XACCL2_XA_MASK)
/* XACCL1 Bit Fields */
#define FTFA_XACCL1_XA_MASK                      0xFFu
#define FTFA_XACCL1_XA_SHIFT                     0
#define FTFA_XACCL1_XA_WIDTH                     8
#define FTFA_XACCL1_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCL1_XA_SHIFT))&FTFA_XACCL1_XA_MASK)
/* XACCL0 Bit Fields */
#define FTFA_XACCL0_XA_MASK                      0xFFu
#define FTFA_XACCL0_XA_SHIFT                     0
#define FTFA_XACCL0_XA_WIDTH                     8
#define FTFA_XACCL0_XA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_XACCL0_XA_SHIFT))&FTFA_XACCL0_XA_MASK)
/* SACCH3 Bit Fields */
#define FTFA_SACCH3_SA_MASK                      0xFFu
#define FTFA_SACCH3_SA_SHIFT                     0
#define FTFA_SACCH3_SA_WIDTH                     8
#define FTFA_SACCH3_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCH3_SA_SHIFT))&FTFA_SACCH3_SA_MASK)
/* SACCH2 Bit Fields */
#define FTFA_SACCH2_SA_MASK                      0xFFu
#define FTFA_SACCH2_SA_SHIFT                     0
#define FTFA_SACCH2_SA_WIDTH                     8
#define FTFA_SACCH2_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCH2_SA_SHIFT))&FTFA_SACCH2_SA_MASK)
/* SACCH1 Bit Fields */
#define FTFA_SACCH1_SA_MASK                      0xFFu
#define FTFA_SACCH1_SA_SHIFT                     0
#define FTFA_SACCH1_SA_WIDTH                     8
#define FTFA_SACCH1_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCH1_SA_SHIFT))&FTFA_SACCH1_SA_MASK)
/* SACCH0 Bit Fields */
#define FTFA_SACCH0_SA_MASK                      0xFFu
#define FTFA_SACCH0_SA_SHIFT                     0
#define FTFA_SACCH0_SA_WIDTH                     8
#define FTFA_SACCH0_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCH0_SA_SHIFT))&FTFA_SACCH0_SA_MASK)
/* SACCL3 Bit Fields */
#define FTFA_SACCL3_SA_MASK                      0xFFu
#define FTFA_SACCL3_SA_SHIFT                     0
#define FTFA_SACCL3_SA_WIDTH                     8
#define FTFA_SACCL3_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCL3_SA_SHIFT))&FTFA_SACCL3_SA_MASK)
/* SACCL2 Bit Fields */
#define FTFA_SACCL2_SA_MASK                      0xFFu
#define FTFA_SACCL2_SA_SHIFT                     0
#define FTFA_SACCL2_SA_WIDTH                     8
#define FTFA_SACCL2_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCL2_SA_SHIFT))&FTFA_SACCL2_SA_MASK)
/* SACCL1 Bit Fields */
#define FTFA_SACCL1_SA_MASK                      0xFFu
#define FTFA_SACCL1_SA_SHIFT                     0
#define FTFA_SACCL1_SA_WIDTH                     8
#define FTFA_SACCL1_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCL1_SA_SHIFT))&FTFA_SACCL1_SA_MASK)
/* SACCL0 Bit Fields */
#define FTFA_SACCL0_SA_MASK                      0xFFu
#define FTFA_SACCL0_SA_SHIFT                     0
#define FTFA_SACCL0_SA_WIDTH                     8
#define FTFA_SACCL0_SA(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_SACCL0_SA_SHIFT))&FTFA_SACCL0_SA_MASK)
/* FACSS Bit Fields */
#define FTFA_FACSS_SGSIZE_MASK                   0xFFu
#define FTFA_FACSS_SGSIZE_SHIFT                  0
#define FTFA_FACSS_SGSIZE_WIDTH                  8
#define FTFA_FACSS_SGSIZE(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FACSS_SGSIZE_SHIFT))&FTFA_FACSS_SGSIZE_MASK)
/* FACSN Bit Fields */
#define FTFA_FACSN_NUMSG_MASK                    0xFFu
#define FTFA_FACSN_NUMSG_SHIFT                   0
#define FTFA_FACSN_NUMSG_WIDTH                   8
#define FTFA_FACSN_NUMSG(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FACSN_NUMSG_SHIFT))&FTFA_FACSN_NUMSG_MASK)

/*!
 * @}
 */ /* end of group FTFA_Register_Masks */


/* FTFA - Peripheral instance base addresses */
/** Peripheral FTFA base address */
#define FTFA_BASE                                (0x40020000u)
/** Peripheral FTFA base pointer */
#define FTFA                                     ((FTFA_Type *)FTFA_BASE)
#define FTFA_BASE_PTR                            (FTFA)
/** Array initializer of FTFA peripheral base addresses */
#define FTFA_BASE_ADDRS                          { FTFA_BASE }
/** Array initializer of FTFA peripheral base pointers */
#define FTFA_BASE_PTRS                           { FTFA }

/* ----------------------------------------------------------------------------
   -- FTFA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFA_Register_Accessor_Macros FTFA - Register accessor macros
 * @{
 */


/* FTFA - Register instance definitions */
/* FTFA */
#define FTFA_FSTAT                               FTFA_FSTAT_REG(FTFA)
#define FTFA_FCNFG                               FTFA_FCNFG_REG(FTFA)
#define FTFA_FSEC                                FTFA_FSEC_REG(FTFA)
#define FTFA_FOPT                                FTFA_FOPT_REG(FTFA)
#define FTFA_FCCOB3                              FTFA_FCCOB3_REG(FTFA)
#define FTFA_FCCOB2                              FTFA_FCCOB2_REG(FTFA)
#define FTFA_FCCOB1                              FTFA_FCCOB1_REG(FTFA)
#define FTFA_FCCOB0                              FTFA_FCCOB0_REG(FTFA)
#define FTFA_FCCOB7                              FTFA_FCCOB7_REG(FTFA)
#define FTFA_FCCOB6                              FTFA_FCCOB6_REG(FTFA)
#define FTFA_FCCOB5                              FTFA_FCCOB5_REG(FTFA)
#define FTFA_FCCOB4                              FTFA_FCCOB4_REG(FTFA)
#define FTFA_FCCOBB                              FTFA_FCCOBB_REG(FTFA)
#define FTFA_FCCOBA                              FTFA_FCCOBA_REG(FTFA)
#define FTFA_FCCOB9                              FTFA_FCCOB9_REG(FTFA)
#define FTFA_FCCOB8                              FTFA_FCCOB8_REG(FTFA)
#define FTFA_FPROT3                              FTFA_FPROT3_REG(FTFA)
#define FTFA_FPROT2                              FTFA_FPROT2_REG(FTFA)
#define FTFA_FPROT1                              FTFA_FPROT1_REG(FTFA)
#define FTFA_FPROT0                              FTFA_FPROT0_REG(FTFA)
#define FTFA_XACCH3                              FTFA_XACCH3_REG(FTFA)
#define FTFA_XACCH2                              FTFA_XACCH2_REG(FTFA)
#define FTFA_XACCH1                              FTFA_XACCH1_REG(FTFA)
#define FTFA_XACCH0                              FTFA_XACCH0_REG(FTFA)
#define FTFA_XACCL3                              FTFA_XACCL3_REG(FTFA)
#define FTFA_XACCL2                              FTFA_XACCL2_REG(FTFA)
#define FTFA_XACCL1                              FTFA_XACCL1_REG(FTFA)
#define FTFA_XACCL0                              FTFA_XACCL0_REG(FTFA)
#define FTFA_SACCH3                              FTFA_SACCH3_REG(FTFA)
#define FTFA_SACCH2                              FTFA_SACCH2_REG(FTFA)
#define FTFA_SACCH1                              FTFA_SACCH1_REG(FTFA)
#define FTFA_SACCH0                              FTFA_SACCH0_REG(FTFA)
#define FTFA_SACCL3                              FTFA_SACCL3_REG(FTFA)
#define FTFA_SACCL2                              FTFA_SACCL2_REG(FTFA)
#define FTFA_SACCL1                              FTFA_SACCL1_REG(FTFA)
#define FTFA_SACCL0                              FTFA_SACCL0_REG(FTFA)
#define FTFA_FACSS                               FTFA_FACSS_REG(FTFA)
#define FTFA_FACSN                               FTFA_FACSN_REG(FTFA)

/*!
 * @}
 */ /* end of group FTFA_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group FTFA_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO uint32_t PDOR;                              /**< Port Data Output Register, offset: 0x0 */
  __O  uint32_t PSOR;                              /**< Port Set Output Register, offset: 0x4 */
  __O  uint32_t PCOR;                              /**< Port Clear Output Register, offset: 0x8 */
  __O  uint32_t PTOR;                              /**< Port Toggle Output Register, offset: 0xC */
  __I  uint32_t PDIR;                              /**< Port Data Input Register, offset: 0x10 */
  __IO uint32_t PDDR;                              /**< Port Data Direction Register, offset: 0x14 */
} GPIO_Type, *GPIO_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- GPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Accessor_Macros GPIO - Register accessor macros
 * @{
 */


/* GPIO - Register accessors */
#define GPIO_PDOR_REG(base)                      ((base)->PDOR)
#define GPIO_PSOR_REG(base)                      ((base)->PSOR)
#define GPIO_PCOR_REG(base)                      ((base)->PCOR)
#define GPIO_PTOR_REG(base)                      ((base)->PTOR)
#define GPIO_PDIR_REG(base)                      ((base)->PDIR)
#define GPIO_PDDR_REG(base)                      ((base)->PDDR)

/*!
 * @}
 */ /* end of group GPIO_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/* PDOR Bit Fields */
#define GPIO_PDOR_PDO_MASK                       0xFFFFFFFFu
#define GPIO_PDOR_PDO_SHIFT                      0
#define GPIO_PDOR_PDO_WIDTH                      32
#define GPIO_PDOR_PDO(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDOR_PDO_SHIFT))&GPIO_PDOR_PDO_MASK)
/* PSOR Bit Fields */
#define GPIO_PSOR_PTSO_MASK                      0xFFFFFFFFu
#define GPIO_PSOR_PTSO_SHIFT                     0
#define GPIO_PSOR_PTSO_WIDTH                     32
#define GPIO_PSOR_PTSO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PSOR_PTSO_SHIFT))&GPIO_PSOR_PTSO_MASK)
/* PCOR Bit Fields */
#define GPIO_PCOR_PTCO_MASK                      0xFFFFFFFFu
#define GPIO_PCOR_PTCO_SHIFT                     0
#define GPIO_PCOR_PTCO_WIDTH                     32
#define GPIO_PCOR_PTCO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PCOR_PTCO_SHIFT))&GPIO_PCOR_PTCO_MASK)
/* PTOR Bit Fields */
#define GPIO_PTOR_PTTO_MASK                      0xFFFFFFFFu
#define GPIO_PTOR_PTTO_SHIFT                     0
#define GPIO_PTOR_PTTO_WIDTH                     32
#define GPIO_PTOR_PTTO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PTOR_PTTO_SHIFT))&GPIO_PTOR_PTTO_MASK)
/* PDIR Bit Fields */
#define GPIO_PDIR_PDI_MASK                       0xFFFFFFFFu
#define GPIO_PDIR_PDI_SHIFT                      0
#define GPIO_PDIR_PDI_WIDTH                      32
#define GPIO_PDIR_PDI(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDIR_PDI_SHIFT))&GPIO_PDIR_PDI_MASK)
/* PDDR Bit Fields */
#define GPIO_PDDR_PDD_MASK                       0xFFFFFFFFu
#define GPIO_PDDR_PDD_SHIFT                      0
#define GPIO_PDDR_PDD_WIDTH                      32
#define GPIO_PDDR_PDD(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDDR_PDD_SHIFT))&GPIO_PDDR_PDD_MASK)

/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base address */
#define GPIOA_BASE                               (0x4000F000u)
/** Peripheral GPIOA base pointer */
#define GPIOA                                    ((GPIO_Type *)GPIOA_BASE)
#define GPIOA_BASE_PTR                           (GPIOA)
/** Peripheral GPIOB base address */
#define GPIOB_BASE                               (0x4000F040u)
/** Peripheral GPIOB base pointer */
#define GPIOB                                    ((GPIO_Type *)GPIOB_BASE)
#define GPIOB_BASE_PTR                           (GPIOB)
/** Peripheral GPIOC base address */
#define GPIOC_BASE                               (0x4000F080u)
/** Peripheral GPIOC base pointer */
#define GPIOC                                    ((GPIO_Type *)GPIOC_BASE)
#define GPIOC_BASE_PTR                           (GPIOC)
/** Peripheral GPIOD base address */
#define GPIOD_BASE                               (0x4000F0C0u)
/** Peripheral GPIOD base pointer */
#define GPIOD                                    ((GPIO_Type *)GPIOD_BASE)
#define GPIOD_BASE_PTR                           (GPIOD)
/** Peripheral GPIOE base address */
#define GPIOE_BASE                               (0x4000F100u)
/** Peripheral GPIOE base pointer */
#define GPIOE                                    ((GPIO_Type *)GPIOE_BASE)
#define GPIOE_BASE_PTR                           (GPIOE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE, GPIOE_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE }

/* ----------------------------------------------------------------------------
   -- GPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Accessor_Macros GPIO - Register accessor macros
 * @{
 */


/* GPIO - Register instance definitions */
/* GPIOA */
#define GPIOA_PDOR                               GPIO_PDOR_REG(GPIOA)
#define GPIOA_PSOR                               GPIO_PSOR_REG(GPIOA)
#define GPIOA_PCOR                               GPIO_PCOR_REG(GPIOA)
#define GPIOA_PTOR                               GPIO_PTOR_REG(GPIOA)
#define GPIOA_PDIR                               GPIO_PDIR_REG(GPIOA)
#define GPIOA_PDDR                               GPIO_PDDR_REG(GPIOA)
/* GPIOB */
#define GPIOB_PDOR                               GPIO_PDOR_REG(GPIOB)
#define GPIOB_PSOR                               GPIO_PSOR_REG(GPIOB)
#define GPIOB_PCOR                               GPIO_PCOR_REG(GPIOB)
#define GPIOB_PTOR                               GPIO_PTOR_REG(GPIOB)
#define GPIOB_PDIR                               GPIO_PDIR_REG(GPIOB)
#define GPIOB_PDDR                               GPIO_PDDR_REG(GPIOB)
/* GPIOC */
#define GPIOC_PDOR                               GPIO_PDOR_REG(GPIOC)
#define GPIOC_PSOR                               GPIO_PSOR_REG(GPIOC)
#define GPIOC_PCOR                               GPIO_PCOR_REG(GPIOC)
#define GPIOC_PTOR                               GPIO_PTOR_REG(GPIOC)
#define GPIOC_PDIR                               GPIO_PDIR_REG(GPIOC)
#define GPIOC_PDDR                               GPIO_PDDR_REG(GPIOC)
/* GPIOD */
#define GPIOD_PDOR                               GPIO_PDOR_REG(GPIOD)
#define GPIOD_PSOR                               GPIO_PSOR_REG(GPIOD)
#define GPIOD_PCOR                               GPIO_PCOR_REG(GPIOD)
#define GPIOD_PTOR                               GPIO_PTOR_REG(GPIOD)
#define GPIOD_PDIR                               GPIO_PDIR_REG(GPIOD)
#define GPIOD_PDDR                               GPIO_PDDR_REG(GPIOD)
/* GPIOE */
#define GPIOE_PDOR                               GPIO_PDOR_REG(GPIOE)
#define GPIOE_PSOR                               GPIO_PSOR_REG(GPIOE)
#define GPIOE_PCOR                               GPIO_PCOR_REG(GPIOE)
#define GPIOE_PTOR                               GPIO_PTOR_REG(GPIOE)
#define GPIOE_PDIR                               GPIO_PDIR_REG(GPIOE)
#define GPIOE_PDDR                               GPIO_PDDR_REG(GPIOE)

/*!
 * @}
 */ /* end of group GPIO_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- I2S Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2S_Peripheral_Access_Layer I2S Peripheral Access Layer
 * @{
 */

/** I2S - Register Layout Typedef */
typedef struct {
  __IO uint32_t TCSR;                              /**< SAI Transmit Control Register, offset: 0x0 */
  __IO uint32_t TCR1;                              /**< SAI Transmit Configuration 1 Register, offset: 0x4 */
  __IO uint32_t TCR2;                              /**< SAI Transmit Configuration 2 Register, offset: 0x8 */
  __IO uint32_t TCR3;                              /**< SAI Transmit Configuration 3 Register, offset: 0xC */
  __IO uint32_t TCR4;                              /**< SAI Transmit Configuration 4 Register, offset: 0x10 */
  __IO uint32_t TCR5;                              /**< SAI Transmit Configuration 5 Register, offset: 0x14 */
       uint8_t RESERVED_0[8];
  __O  uint32_t TDR[1];                            /**< SAI Transmit Data Register, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_1[28];
  __I  uint32_t TFR[1];                            /**< SAI Transmit FIFO Register, array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_2[28];
  __IO uint32_t TMR;                               /**< SAI Transmit Mask Register, offset: 0x60 */
       uint8_t RESERVED_3[28];
  __IO uint32_t RCSR;                              /**< SAI Receive Control Register, offset: 0x80 */
  __IO uint32_t RCR1;                              /**< SAI Receive Configuration 1 Register, offset: 0x84 */
  __IO uint32_t RCR2;                              /**< SAI Receive Configuration 2 Register, offset: 0x88 */
  __IO uint32_t RCR3;                              /**< SAI Receive Configuration 3 Register, offset: 0x8C */
  __IO uint32_t RCR4;                              /**< SAI Receive Configuration 4 Register, offset: 0x90 */
  __IO uint32_t RCR5;                              /**< SAI Receive Configuration 5 Register, offset: 0x94 */
       uint8_t RESERVED_4[8];
  __I  uint32_t RDR[1];                            /**< SAI Receive Data Register, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_5[28];
  __I  uint32_t RFR[1];                            /**< SAI Receive FIFO Register, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_6[28];
  __IO uint32_t RMR;                               /**< SAI Receive Mask Register, offset: 0xE0 */
} I2S_Type, *I2S_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- I2S - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2S_Register_Accessor_Macros I2S - Register accessor macros
 * @{
 */


/* I2S - Register accessors */
#define I2S_TCSR_REG(base)                       ((base)->TCSR)
#define I2S_TCR1_REG(base)                       ((base)->TCR1)
#define I2S_TCR2_REG(base)                       ((base)->TCR2)
#define I2S_TCR3_REG(base)                       ((base)->TCR3)
#define I2S_TCR4_REG(base)                       ((base)->TCR4)
#define I2S_TCR5_REG(base)                       ((base)->TCR5)
#define I2S_TDR_REG(base,index)                  ((base)->TDR[index])
#define I2S_TDR_COUNT                            1
#define I2S_TFR_REG(base,index)                  ((base)->TFR[index])
#define I2S_TFR_COUNT                            1
#define I2S_TMR_REG(base)                        ((base)->TMR)
#define I2S_RCSR_REG(base)                       ((base)->RCSR)
#define I2S_RCR1_REG(base)                       ((base)->RCR1)
#define I2S_RCR2_REG(base)                       ((base)->RCR2)
#define I2S_RCR3_REG(base)                       ((base)->RCR3)
#define I2S_RCR4_REG(base)                       ((base)->RCR4)
#define I2S_RCR5_REG(base)                       ((base)->RCR5)
#define I2S_RDR_REG(base,index)                  ((base)->RDR[index])
#define I2S_RDR_COUNT                            1
#define I2S_RFR_REG(base,index)                  ((base)->RFR[index])
#define I2S_RFR_COUNT                            1
#define I2S_RMR_REG(base)                        ((base)->RMR)

/*!
 * @}
 */ /* end of group I2S_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- I2S Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2S_Register_Masks I2S Register Masks
 * @{
 */

/* TCSR Bit Fields */
#define I2S_TCSR_FRDE_MASK                       0x1u
#define I2S_TCSR_FRDE_SHIFT                      0
#define I2S_TCSR_FRDE_WIDTH                      1
#define I2S_TCSR_FRDE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FRDE_SHIFT))&I2S_TCSR_FRDE_MASK)
#define I2S_TCSR_FWDE_MASK                       0x2u
#define I2S_TCSR_FWDE_SHIFT                      1
#define I2S_TCSR_FWDE_WIDTH                      1
#define I2S_TCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FWDE_SHIFT))&I2S_TCSR_FWDE_MASK)
#define I2S_TCSR_FRIE_MASK                       0x100u
#define I2S_TCSR_FRIE_SHIFT                      8
#define I2S_TCSR_FRIE_WIDTH                      1
#define I2S_TCSR_FRIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FRIE_SHIFT))&I2S_TCSR_FRIE_MASK)
#define I2S_TCSR_FWIE_MASK                       0x200u
#define I2S_TCSR_FWIE_SHIFT                      9
#define I2S_TCSR_FWIE_WIDTH                      1
#define I2S_TCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FWIE_SHIFT))&I2S_TCSR_FWIE_MASK)
#define I2S_TCSR_FEIE_MASK                       0x400u
#define I2S_TCSR_FEIE_SHIFT                      10
#define I2S_TCSR_FEIE_WIDTH                      1
#define I2S_TCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FEIE_SHIFT))&I2S_TCSR_FEIE_MASK)
#define I2S_TCSR_SEIE_MASK                       0x800u
#define I2S_TCSR_SEIE_SHIFT                      11
#define I2S_TCSR_SEIE_WIDTH                      1
#define I2S_TCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_SEIE_SHIFT))&I2S_TCSR_SEIE_MASK)
#define I2S_TCSR_WSIE_MASK                       0x1000u
#define I2S_TCSR_WSIE_SHIFT                      12
#define I2S_TCSR_WSIE_WIDTH                      1
#define I2S_TCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_WSIE_SHIFT))&I2S_TCSR_WSIE_MASK)
#define I2S_TCSR_FRF_MASK                        0x10000u
#define I2S_TCSR_FRF_SHIFT                       16
#define I2S_TCSR_FRF_WIDTH                       1
#define I2S_TCSR_FRF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FRF_SHIFT))&I2S_TCSR_FRF_MASK)
#define I2S_TCSR_FWF_MASK                        0x20000u
#define I2S_TCSR_FWF_SHIFT                       17
#define I2S_TCSR_FWF_WIDTH                       1
#define I2S_TCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FWF_SHIFT))&I2S_TCSR_FWF_MASK)
#define I2S_TCSR_FEF_MASK                        0x40000u
#define I2S_TCSR_FEF_SHIFT                       18
#define I2S_TCSR_FEF_WIDTH                       1
#define I2S_TCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FEF_SHIFT))&I2S_TCSR_FEF_MASK)
#define I2S_TCSR_SEF_MASK                        0x80000u
#define I2S_TCSR_SEF_SHIFT                       19
#define I2S_TCSR_SEF_WIDTH                       1
#define I2S_TCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_SEF_SHIFT))&I2S_TCSR_SEF_MASK)
#define I2S_TCSR_WSF_MASK                        0x100000u
#define I2S_TCSR_WSF_SHIFT                       20
#define I2S_TCSR_WSF_WIDTH                       1
#define I2S_TCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_WSF_SHIFT))&I2S_TCSR_WSF_MASK)
#define I2S_TCSR_SR_MASK                         0x1000000u
#define I2S_TCSR_SR_SHIFT                        24
#define I2S_TCSR_SR_WIDTH                        1
#define I2S_TCSR_SR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_SR_SHIFT))&I2S_TCSR_SR_MASK)
#define I2S_TCSR_FR_MASK                         0x2000000u
#define I2S_TCSR_FR_SHIFT                        25
#define I2S_TCSR_FR_WIDTH                        1
#define I2S_TCSR_FR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FR_SHIFT))&I2S_TCSR_FR_MASK)
#define I2S_TCSR_BCE_MASK                        0x10000000u
#define I2S_TCSR_BCE_SHIFT                       28
#define I2S_TCSR_BCE_WIDTH                       1
#define I2S_TCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_BCE_SHIFT))&I2S_TCSR_BCE_MASK)
#define I2S_TCSR_DBGE_MASK                       0x20000000u
#define I2S_TCSR_DBGE_SHIFT                      29
#define I2S_TCSR_DBGE_WIDTH                      1
#define I2S_TCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_DBGE_SHIFT))&I2S_TCSR_DBGE_MASK)
#define I2S_TCSR_STOPE_MASK                      0x40000000u
#define I2S_TCSR_STOPE_SHIFT                     30
#define I2S_TCSR_STOPE_WIDTH                     1
#define I2S_TCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_STOPE_SHIFT))&I2S_TCSR_STOPE_MASK)
#define I2S_TCSR_TE_MASK                         0x80000000u
#define I2S_TCSR_TE_SHIFT                        31
#define I2S_TCSR_TE_WIDTH                        1
#define I2S_TCSR_TE(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_TE_SHIFT))&I2S_TCSR_TE_MASK)
/* TCR1 Bit Fields */
#define I2S_TCR1_TFW_MASK                        0x3u
#define I2S_TCR1_TFW_SHIFT                       0
#define I2S_TCR1_TFW_WIDTH                       2
#define I2S_TCR1_TFW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR1_TFW_SHIFT))&I2S_TCR1_TFW_MASK)
/* TCR2 Bit Fields */
#define I2S_TCR2_DIV_MASK                        0xFFu
#define I2S_TCR2_DIV_SHIFT                       0
#define I2S_TCR2_DIV_WIDTH                       8
#define I2S_TCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_DIV_SHIFT))&I2S_TCR2_DIV_MASK)
#define I2S_TCR2_BCD_MASK                        0x1000000u
#define I2S_TCR2_BCD_SHIFT                       24
#define I2S_TCR2_BCD_WIDTH                       1
#define I2S_TCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCD_SHIFT))&I2S_TCR2_BCD_MASK)
#define I2S_TCR2_BCP_MASK                        0x2000000u
#define I2S_TCR2_BCP_SHIFT                       25
#define I2S_TCR2_BCP_WIDTH                       1
#define I2S_TCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCP_SHIFT))&I2S_TCR2_BCP_MASK)
#define I2S_TCR2_MSEL_MASK                       0xC000000u
#define I2S_TCR2_MSEL_SHIFT                      26
#define I2S_TCR2_MSEL_WIDTH                      2
#define I2S_TCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_MSEL_SHIFT))&I2S_TCR2_MSEL_MASK)
#define I2S_TCR2_BCI_MASK                        0x10000000u
#define I2S_TCR2_BCI_SHIFT                       28
#define I2S_TCR2_BCI_WIDTH                       1
#define I2S_TCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCI_SHIFT))&I2S_TCR2_BCI_MASK)
#define I2S_TCR2_BCS_MASK                        0x20000000u
#define I2S_TCR2_BCS_SHIFT                       29
#define I2S_TCR2_BCS_WIDTH                       1
#define I2S_TCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCS_SHIFT))&I2S_TCR2_BCS_MASK)
#define I2S_TCR2_SYNC_MASK                       0xC0000000u
#define I2S_TCR2_SYNC_SHIFT                      30
#define I2S_TCR2_SYNC_WIDTH                      2
#define I2S_TCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_SYNC_SHIFT))&I2S_TCR2_SYNC_MASK)
/* TCR3 Bit Fields */
#define I2S_TCR3_WDFL_MASK                       0xFu
#define I2S_TCR3_WDFL_SHIFT                      0
#define I2S_TCR3_WDFL_WIDTH                      4
#define I2S_TCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR3_WDFL_SHIFT))&I2S_TCR3_WDFL_MASK)
#define I2S_TCR3_TCE_MASK                        0x10000u
#define I2S_TCR3_TCE_SHIFT                       16
#define I2S_TCR3_TCE_WIDTH                       1
#define I2S_TCR3_TCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR3_TCE_SHIFT))&I2S_TCR3_TCE_MASK)
/* TCR4 Bit Fields */
#define I2S_TCR4_FSD_MASK                        0x1u
#define I2S_TCR4_FSD_SHIFT                       0
#define I2S_TCR4_FSD_WIDTH                       1
#define I2S_TCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FSD_SHIFT))&I2S_TCR4_FSD_MASK)
#define I2S_TCR4_FSP_MASK                        0x2u
#define I2S_TCR4_FSP_SHIFT                       1
#define I2S_TCR4_FSP_WIDTH                       1
#define I2S_TCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FSP_SHIFT))&I2S_TCR4_FSP_MASK)
#define I2S_TCR4_ONDEM_MASK                      0x4u
#define I2S_TCR4_ONDEM_SHIFT                     2
#define I2S_TCR4_ONDEM_WIDTH                     1
#define I2S_TCR4_ONDEM(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_ONDEM_SHIFT))&I2S_TCR4_ONDEM_MASK)
#define I2S_TCR4_FSE_MASK                        0x8u
#define I2S_TCR4_FSE_SHIFT                       3
#define I2S_TCR4_FSE_WIDTH                       1
#define I2S_TCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FSE_SHIFT))&I2S_TCR4_FSE_MASK)
#define I2S_TCR4_MF_MASK                         0x10u
#define I2S_TCR4_MF_SHIFT                        4
#define I2S_TCR4_MF_WIDTH                        1
#define I2S_TCR4_MF(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_MF_SHIFT))&I2S_TCR4_MF_MASK)
#define I2S_TCR4_SYWD_MASK                       0x1F00u
#define I2S_TCR4_SYWD_SHIFT                      8
#define I2S_TCR4_SYWD_WIDTH                      5
#define I2S_TCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_SYWD_SHIFT))&I2S_TCR4_SYWD_MASK)
#define I2S_TCR4_FRSZ_MASK                       0xF0000u
#define I2S_TCR4_FRSZ_SHIFT                      16
#define I2S_TCR4_FRSZ_WIDTH                      4
#define I2S_TCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FRSZ_SHIFT))&I2S_TCR4_FRSZ_MASK)
#define I2S_TCR4_FPACK_MASK                      0x3000000u
#define I2S_TCR4_FPACK_SHIFT                     24
#define I2S_TCR4_FPACK_WIDTH                     2
#define I2S_TCR4_FPACK(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FPACK_SHIFT))&I2S_TCR4_FPACK_MASK)
#define I2S_TCR4_FCONT_MASK                      0x10000000u
#define I2S_TCR4_FCONT_SHIFT                     28
#define I2S_TCR4_FCONT_WIDTH                     1
#define I2S_TCR4_FCONT(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FCONT_SHIFT))&I2S_TCR4_FCONT_MASK)
/* TCR5 Bit Fields */
#define I2S_TCR5_FBT_MASK                        0x1F00u
#define I2S_TCR5_FBT_SHIFT                       8
#define I2S_TCR5_FBT_WIDTH                       5
#define I2S_TCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_FBT_SHIFT))&I2S_TCR5_FBT_MASK)
#define I2S_TCR5_W0W_MASK                        0x1F0000u
#define I2S_TCR5_W0W_SHIFT                       16
#define I2S_TCR5_W0W_WIDTH                       5
#define I2S_TCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_W0W_SHIFT))&I2S_TCR5_W0W_MASK)
#define I2S_TCR5_WNW_MASK                        0x1F000000u
#define I2S_TCR5_WNW_SHIFT                       24
#define I2S_TCR5_WNW_WIDTH                       5
#define I2S_TCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_WNW_SHIFT))&I2S_TCR5_WNW_MASK)
/* TDR Bit Fields */
#define I2S_TDR_TDR_MASK                         0xFFFFFFFFu
#define I2S_TDR_TDR_SHIFT                        0
#define I2S_TDR_TDR_WIDTH                        32
#define I2S_TDR_TDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TDR_TDR_SHIFT))&I2S_TDR_TDR_MASK)
/* TFR Bit Fields */
#define I2S_TFR_RFP_MASK                         0x7u
#define I2S_TFR_RFP_SHIFT                        0
#define I2S_TFR_RFP_WIDTH                        3
#define I2S_TFR_RFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TFR_RFP_SHIFT))&I2S_TFR_RFP_MASK)
#define I2S_TFR_WFP_MASK                         0x70000u
#define I2S_TFR_WFP_SHIFT                        16
#define I2S_TFR_WFP_WIDTH                        3
#define I2S_TFR_WFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TFR_WFP_SHIFT))&I2S_TFR_WFP_MASK)
/* TMR Bit Fields */
#define I2S_TMR_TWM_MASK                         0xFFFFu
#define I2S_TMR_TWM_SHIFT                        0
#define I2S_TMR_TWM_WIDTH                        16
#define I2S_TMR_TWM(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TMR_TWM_SHIFT))&I2S_TMR_TWM_MASK)
/* RCSR Bit Fields */
#define I2S_RCSR_FRDE_MASK                       0x1u
#define I2S_RCSR_FRDE_SHIFT                      0
#define I2S_RCSR_FRDE_WIDTH                      1
#define I2S_RCSR_FRDE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FRDE_SHIFT))&I2S_RCSR_FRDE_MASK)
#define I2S_RCSR_FWDE_MASK                       0x2u
#define I2S_RCSR_FWDE_SHIFT                      1
#define I2S_RCSR_FWDE_WIDTH                      1
#define I2S_RCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FWDE_SHIFT))&I2S_RCSR_FWDE_MASK)
#define I2S_RCSR_FRIE_MASK                       0x100u
#define I2S_RCSR_FRIE_SHIFT                      8
#define I2S_RCSR_FRIE_WIDTH                      1
#define I2S_RCSR_FRIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FRIE_SHIFT))&I2S_RCSR_FRIE_MASK)
#define I2S_RCSR_FWIE_MASK                       0x200u
#define I2S_RCSR_FWIE_SHIFT                      9
#define I2S_RCSR_FWIE_WIDTH                      1
#define I2S_RCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FWIE_SHIFT))&I2S_RCSR_FWIE_MASK)
#define I2S_RCSR_FEIE_MASK                       0x400u
#define I2S_RCSR_FEIE_SHIFT                      10
#define I2S_RCSR_FEIE_WIDTH                      1
#define I2S_RCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FEIE_SHIFT))&I2S_RCSR_FEIE_MASK)
#define I2S_RCSR_SEIE_MASK                       0x800u
#define I2S_RCSR_SEIE_SHIFT                      11
#define I2S_RCSR_SEIE_WIDTH                      1
#define I2S_RCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_SEIE_SHIFT))&I2S_RCSR_SEIE_MASK)
#define I2S_RCSR_WSIE_MASK                       0x1000u
#define I2S_RCSR_WSIE_SHIFT                      12
#define I2S_RCSR_WSIE_WIDTH                      1
#define I2S_RCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_WSIE_SHIFT))&I2S_RCSR_WSIE_MASK)
#define I2S_RCSR_FRF_MASK                        0x10000u
#define I2S_RCSR_FRF_SHIFT                       16
#define I2S_RCSR_FRF_WIDTH                       1
#define I2S_RCSR_FRF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FRF_SHIFT))&I2S_RCSR_FRF_MASK)
#define I2S_RCSR_FWF_MASK                        0x20000u
#define I2S_RCSR_FWF_SHIFT                       17
#define I2S_RCSR_FWF_WIDTH                       1
#define I2S_RCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FWF_SHIFT))&I2S_RCSR_FWF_MASK)
#define I2S_RCSR_FEF_MASK                        0x40000u
#define I2S_RCSR_FEF_SHIFT                       18
#define I2S_RCSR_FEF_WIDTH                       1
#define I2S_RCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FEF_SHIFT))&I2S_RCSR_FEF_MASK)
#define I2S_RCSR_SEF_MASK                        0x80000u
#define I2S_RCSR_SEF_SHIFT                       19
#define I2S_RCSR_SEF_WIDTH                       1
#define I2S_RCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_SEF_SHIFT))&I2S_RCSR_SEF_MASK)
#define I2S_RCSR_WSF_MASK                        0x100000u
#define I2S_RCSR_WSF_SHIFT                       20
#define I2S_RCSR_WSF_WIDTH                       1
#define I2S_RCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_WSF_SHIFT))&I2S_RCSR_WSF_MASK)
#define I2S_RCSR_SR_MASK                         0x1000000u
#define I2S_RCSR_SR_SHIFT                        24
#define I2S_RCSR_SR_WIDTH                        1
#define I2S_RCSR_SR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_SR_SHIFT))&I2S_RCSR_SR_MASK)
#define I2S_RCSR_FR_MASK                         0x2000000u
#define I2S_RCSR_FR_SHIFT                        25
#define I2S_RCSR_FR_WIDTH                        1
#define I2S_RCSR_FR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FR_SHIFT))&I2S_RCSR_FR_MASK)
#define I2S_RCSR_BCE_MASK                        0x10000000u
#define I2S_RCSR_BCE_SHIFT                       28
#define I2S_RCSR_BCE_WIDTH                       1
#define I2S_RCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_BCE_SHIFT))&I2S_RCSR_BCE_MASK)
#define I2S_RCSR_DBGE_MASK                       0x20000000u
#define I2S_RCSR_DBGE_SHIFT                      29
#define I2S_RCSR_DBGE_WIDTH                      1
#define I2S_RCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_DBGE_SHIFT))&I2S_RCSR_DBGE_MASK)
#define I2S_RCSR_STOPE_MASK                      0x40000000u
#define I2S_RCSR_STOPE_SHIFT                     30
#define I2S_RCSR_STOPE_WIDTH                     1
#define I2S_RCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_STOPE_SHIFT))&I2S_RCSR_STOPE_MASK)
#define I2S_RCSR_RE_MASK                         0x80000000u
#define I2S_RCSR_RE_SHIFT                        31
#define I2S_RCSR_RE_WIDTH                        1
#define I2S_RCSR_RE(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_RE_SHIFT))&I2S_RCSR_RE_MASK)
/* RCR1 Bit Fields */
#define I2S_RCR1_RFW_MASK                        0x3u
#define I2S_RCR1_RFW_SHIFT                       0
#define I2S_RCR1_RFW_WIDTH                       2
#define I2S_RCR1_RFW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR1_RFW_SHIFT))&I2S_RCR1_RFW_MASK)
/* RCR2 Bit Fields */
#define I2S_RCR2_DIV_MASK                        0xFFu
#define I2S_RCR2_DIV_SHIFT                       0
#define I2S_RCR2_DIV_WIDTH                       8
#define I2S_RCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_DIV_SHIFT))&I2S_RCR2_DIV_MASK)
#define I2S_RCR2_BCD_MASK                        0x1000000u
#define I2S_RCR2_BCD_SHIFT                       24
#define I2S_RCR2_BCD_WIDTH                       1
#define I2S_RCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCD_SHIFT))&I2S_RCR2_BCD_MASK)
#define I2S_RCR2_BCP_MASK                        0x2000000u
#define I2S_RCR2_BCP_SHIFT                       25
#define I2S_RCR2_BCP_WIDTH                       1
#define I2S_RCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCP_SHIFT))&I2S_RCR2_BCP_MASK)
#define I2S_RCR2_MSEL_MASK                       0xC000000u
#define I2S_RCR2_MSEL_SHIFT                      26
#define I2S_RCR2_MSEL_WIDTH                      2
#define I2S_RCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_MSEL_SHIFT))&I2S_RCR2_MSEL_MASK)
#define I2S_RCR2_BCI_MASK                        0x10000000u
#define I2S_RCR2_BCI_SHIFT                       28
#define I2S_RCR2_BCI_WIDTH                       1
#define I2S_RCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCI_SHIFT))&I2S_RCR2_BCI_MASK)
#define I2S_RCR2_BCS_MASK                        0x20000000u
#define I2S_RCR2_BCS_SHIFT                       29
#define I2S_RCR2_BCS_WIDTH                       1
#define I2S_RCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCS_SHIFT))&I2S_RCR2_BCS_MASK)
#define I2S_RCR2_SYNC_MASK                       0xC0000000u
#define I2S_RCR2_SYNC_SHIFT                      30
#define I2S_RCR2_SYNC_WIDTH                      2
#define I2S_RCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_SYNC_SHIFT))&I2S_RCR2_SYNC_MASK)
/* RCR3 Bit Fields */
#define I2S_RCR3_WDFL_MASK                       0xFu
#define I2S_RCR3_WDFL_SHIFT                      0
#define I2S_RCR3_WDFL_WIDTH                      4
#define I2S_RCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR3_WDFL_SHIFT))&I2S_RCR3_WDFL_MASK)
#define I2S_RCR3_RCE_MASK                        0x10000u
#define I2S_RCR3_RCE_SHIFT                       16
#define I2S_RCR3_RCE_WIDTH                       1
#define I2S_RCR3_RCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR3_RCE_SHIFT))&I2S_RCR3_RCE_MASK)
/* RCR4 Bit Fields */
#define I2S_RCR4_FSD_MASK                        0x1u
#define I2S_RCR4_FSD_SHIFT                       0
#define I2S_RCR4_FSD_WIDTH                       1
#define I2S_RCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FSD_SHIFT))&I2S_RCR4_FSD_MASK)
#define I2S_RCR4_FSP_MASK                        0x2u
#define I2S_RCR4_FSP_SHIFT                       1
#define I2S_RCR4_FSP_WIDTH                       1
#define I2S_RCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FSP_SHIFT))&I2S_RCR4_FSP_MASK)
#define I2S_RCR4_ONDEM_MASK                      0x4u
#define I2S_RCR4_ONDEM_SHIFT                     2
#define I2S_RCR4_ONDEM_WIDTH                     1
#define I2S_RCR4_ONDEM(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_ONDEM_SHIFT))&I2S_RCR4_ONDEM_MASK)
#define I2S_RCR4_FSE_MASK                        0x8u
#define I2S_RCR4_FSE_SHIFT                       3
#define I2S_RCR4_FSE_WIDTH                       1
#define I2S_RCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FSE_SHIFT))&I2S_RCR4_FSE_MASK)
#define I2S_RCR4_MF_MASK                         0x10u
#define I2S_RCR4_MF_SHIFT                        4
#define I2S_RCR4_MF_WIDTH                        1
#define I2S_RCR4_MF(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_MF_SHIFT))&I2S_RCR4_MF_MASK)
#define I2S_RCR4_SYWD_MASK                       0x1F00u
#define I2S_RCR4_SYWD_SHIFT                      8
#define I2S_RCR4_SYWD_WIDTH                      5
#define I2S_RCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_SYWD_SHIFT))&I2S_RCR4_SYWD_MASK)
#define I2S_RCR4_FRSZ_MASK                       0xF0000u
#define I2S_RCR4_FRSZ_SHIFT                      16
#define I2S_RCR4_FRSZ_WIDTH                      4
#define I2S_RCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FRSZ_SHIFT))&I2S_RCR4_FRSZ_MASK)
#define I2S_RCR4_FPACK_MASK                      0x3000000u
#define I2S_RCR4_FPACK_SHIFT                     24
#define I2S_RCR4_FPACK_WIDTH                     2
#define I2S_RCR4_FPACK(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FPACK_SHIFT))&I2S_RCR4_FPACK_MASK)
#define I2S_RCR4_FCONT_MASK                      0x10000000u
#define I2S_RCR4_FCONT_SHIFT                     28
#define I2S_RCR4_FCONT_WIDTH                     1
#define I2S_RCR4_FCONT(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FCONT_SHIFT))&I2S_RCR4_FCONT_MASK)
/* RCR5 Bit Fields */
#define I2S_RCR5_FBT_MASK                        0x1F00u
#define I2S_RCR5_FBT_SHIFT                       8
#define I2S_RCR5_FBT_WIDTH                       5
#define I2S_RCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_FBT_SHIFT))&I2S_RCR5_FBT_MASK)
#define I2S_RCR5_W0W_MASK                        0x1F0000u
#define I2S_RCR5_W0W_SHIFT                       16
#define I2S_RCR5_W0W_WIDTH                       5
#define I2S_RCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_W0W_SHIFT))&I2S_RCR5_W0W_MASK)
#define I2S_RCR5_WNW_MASK                        0x1F000000u
#define I2S_RCR5_WNW_SHIFT                       24
#define I2S_RCR5_WNW_WIDTH                       5
#define I2S_RCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_WNW_SHIFT))&I2S_RCR5_WNW_MASK)
/* RDR Bit Fields */
#define I2S_RDR_RDR_MASK                         0xFFFFFFFFu
#define I2S_RDR_RDR_SHIFT                        0
#define I2S_RDR_RDR_WIDTH                        32
#define I2S_RDR_RDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RDR_RDR_SHIFT))&I2S_RDR_RDR_MASK)
/* RFR Bit Fields */
#define I2S_RFR_RFP_MASK                         0x7u
#define I2S_RFR_RFP_SHIFT                        0
#define I2S_RFR_RFP_WIDTH                        3
#define I2S_RFR_RFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RFR_RFP_SHIFT))&I2S_RFR_RFP_MASK)
#define I2S_RFR_WFP_MASK                         0x70000u
#define I2S_RFR_WFP_SHIFT                        16
#define I2S_RFR_WFP_WIDTH                        3
#define I2S_RFR_WFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RFR_WFP_SHIFT))&I2S_RFR_WFP_MASK)
/* RMR Bit Fields */
#define I2S_RMR_RWM_MASK                         0xFFFFu
#define I2S_RMR_RWM_SHIFT                        0
#define I2S_RMR_RWM_WIDTH                        16
#define I2S_RMR_RWM(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RMR_RWM_SHIFT))&I2S_RMR_RWM_MASK)

/*!
 * @}
 */ /* end of group I2S_Register_Masks */


/* I2S - Peripheral instance base addresses */
/** Peripheral I2S0 base address */
#define I2S0_BASE                                (0x4004C000u)
/** Peripheral I2S0 base pointer */
#define I2S0                                     ((I2S_Type *)I2S0_BASE)
#define I2S0_BASE_PTR                            (I2S0)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { I2S0_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { I2S0 }

/* ----------------------------------------------------------------------------
   -- I2S - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2S_Register_Accessor_Macros I2S - Register accessor macros
 * @{
 */


/* I2S - Register instance definitions */
/* I2S0 */
#define I2S0_TCSR                                I2S_TCSR_REG(I2S0)
#define I2S0_TCR1                                I2S_TCR1_REG(I2S0)
#define I2S0_TCR2                                I2S_TCR2_REG(I2S0)
#define I2S0_TCR3                                I2S_TCR3_REG(I2S0)
#define I2S0_TCR4                                I2S_TCR4_REG(I2S0)
#define I2S0_TCR5                                I2S_TCR5_REG(I2S0)
#define I2S0_TDR0                                I2S_TDR_REG(I2S0,0)
#define I2S0_TFR0                                I2S_TFR_REG(I2S0,0)
#define I2S0_TMR                                 I2S_TMR_REG(I2S0)
#define I2S0_RCSR                                I2S_RCSR_REG(I2S0)
#define I2S0_RCR1                                I2S_RCR1_REG(I2S0)
#define I2S0_RCR2                                I2S_RCR2_REG(I2S0)
#define I2S0_RCR3                                I2S_RCR3_REG(I2S0)
#define I2S0_RCR4                                I2S_RCR4_REG(I2S0)
#define I2S0_RCR5                                I2S_RCR5_REG(I2S0)
#define I2S0_RDR0                                I2S_RDR_REG(I2S0,0)
#define I2S0_RFR0                                I2S_RFR_REG(I2S0,0)
#define I2S0_RMR                                 I2S_RMR_REG(I2S0)

/* I2S - Register array accessors */
#define I2S0_TDR(index)                          I2S_TDR_REG(I2S0,index)
#define I2S0_TFR(index)                          I2S_TFR_REG(I2S0,index)
#define I2S0_RDR(index)                          I2S_RDR_REG(I2S0,index)
#define I2S0_RFR(index)                          I2S_RFR_REG(I2S0,index)

/*!
 * @}
 */ /* end of group I2S_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group I2S_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- INTMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTMUX_Peripheral_Access_Layer INTMUX Peripheral Access Layer
 * @{
 */

/** INTMUX - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x40 */
    __IO uint32_t CHn_CSR;                           /**< Channel n Control Status Register, array offset: 0x0, array step: 0x40 */
    __I  uint32_t CHn_VEC;                           /**< Channel n Vector Number Register, array offset: 0x4, array step: 0x40 */
         uint8_t RESERVED_0[8];
    __IO uint32_t CHn_IER_31_0;                      /**< Channel n Interrupt Enable Register, array offset: 0x10, array step: 0x40 */
         uint8_t RESERVED_1[12];
    __I  uint32_t CHn_IPR_31_0;                      /**< Channel n Interrupt Pending Register, array offset: 0x20, array step: 0x40 */
         uint8_t RESERVED_2[28];
  } CHANNEL[4];
} INTMUX_Type, *INTMUX_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- INTMUX - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTMUX_Register_Accessor_Macros INTMUX - Register accessor macros
 * @{
 */


/* INTMUX - Register accessors */
#define INTMUX_CHn_CSR_REG(base,index)           ((base)->CHANNEL[index].CHn_CSR)
#define INTMUX_CHn_CSR_COUNT                     4
#define INTMUX_CHn_VEC_REG(base,index)           ((base)->CHANNEL[index].CHn_VEC)
#define INTMUX_CHn_VEC_COUNT                     4
#define INTMUX_CHn_IER_31_0_REG(base,index)      ((base)->CHANNEL[index].CHn_IER_31_0)
#define INTMUX_CHn_IER_31_0_COUNT                4
#define INTMUX_CHn_IPR_31_0_REG(base,index)      ((base)->CHANNEL[index].CHn_IPR_31_0)
#define INTMUX_CHn_IPR_31_0_COUNT                4

/*!
 * @}
 */ /* end of group INTMUX_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- INTMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTMUX_Register_Masks INTMUX Register Masks
 * @{
 */

/* CHn_CSR Bit Fields */
#define INTMUX_CHn_CSR_RST_MASK                  0x1u
#define INTMUX_CHn_CSR_RST_SHIFT                 0
#define INTMUX_CHn_CSR_RST_WIDTH                 1
#define INTMUX_CHn_CSR_RST(x)                    (((uint32_t)(((uint32_t)(x))<<INTMUX_CHn_CSR_RST_SHIFT))&INTMUX_CHn_CSR_RST_MASK)
#define INTMUX_CHn_CSR_AND_MASK                  0x2u
#define INTMUX_CHn_CSR_AND_SHIFT                 1
#define INTMUX_CHn_CSR_AND_WIDTH                 1
#define INTMUX_CHn_CSR_AND(x)                    (((uint32_t)(((uint32_t)(x))<<INTMUX_CHn_CSR_AND_SHIFT))&INTMUX_CHn_CSR_AND_MASK)
#define INTMUX_CHn_CSR_IRQN_MASK                 0x30u
#define INTMUX_CHn_CSR_IRQN_SHIFT                4
#define INTMUX_CHn_CSR_IRQN_WIDTH                2
#define INTMUX_CHn_CSR_IRQN(x)                   (((uint32_t)(((uint32_t)(x))<<INTMUX_CHn_CSR_IRQN_SHIFT))&INTMUX_CHn_CSR_IRQN_MASK)
#define INTMUX_CHn_CSR_CHIN_MASK                 0xF00u
#define INTMUX_CHn_CSR_CHIN_SHIFT                8
#define INTMUX_CHn_CSR_CHIN_WIDTH                4
#define INTMUX_CHn_CSR_CHIN(x)                   (((uint32_t)(((uint32_t)(x))<<INTMUX_CHn_CSR_CHIN_SHIFT))&INTMUX_CHn_CSR_CHIN_MASK)
#define INTMUX_CHn_CSR_IRQP_MASK                 0x80000000u
#define INTMUX_CHn_CSR_IRQP_SHIFT                31
#define INTMUX_CHn_CSR_IRQP_WIDTH                1
#define INTMUX_CHn_CSR_IRQP(x)                   (((uint32_t)(((uint32_t)(x))<<INTMUX_CHn_CSR_IRQP_SHIFT))&INTMUX_CHn_CSR_IRQP_MASK)
/* CHn_VEC Bit Fields */
#define INTMUX_CHn_VEC_VECN_MASK                 0x3FFCu
#define INTMUX_CHn_VEC_VECN_SHIFT                2
#define INTMUX_CHn_VEC_VECN_WIDTH                12
#define INTMUX_CHn_VEC_VECN(x)                   (((uint32_t)(((uint32_t)(x))<<INTMUX_CHn_VEC_VECN_SHIFT))&INTMUX_CHn_VEC_VECN_MASK)
/* CHn_IER_31_0 Bit Fields */
#define INTMUX_CHn_IER_31_0_INTE_MASK            0xFFFFFFFFu
#define INTMUX_CHn_IER_31_0_INTE_SHIFT           0
#define INTMUX_CHn_IER_31_0_INTE_WIDTH           32
#define INTMUX_CHn_IER_31_0_INTE(x)              (((uint32_t)(((uint32_t)(x))<<INTMUX_CHn_IER_31_0_INTE_SHIFT))&INTMUX_CHn_IER_31_0_INTE_MASK)
/* CHn_IPR_31_0 Bit Fields */
#define INTMUX_CHn_IPR_31_0_INTP_MASK            0xFFFFFFFFu
#define INTMUX_CHn_IPR_31_0_INTP_SHIFT           0
#define INTMUX_CHn_IPR_31_0_INTP_WIDTH           32
#define INTMUX_CHn_IPR_31_0_INTP(x)              (((uint32_t)(((uint32_t)(x))<<INTMUX_CHn_IPR_31_0_INTP_SHIFT))&INTMUX_CHn_IPR_31_0_INTP_MASK)

/*!
 * @}
 */ /* end of group INTMUX_Register_Masks */


/* INTMUX - Peripheral instance base addresses */
/** Peripheral INTMUX0 base address */
#define INTMUX0_BASE                             (0x40024000u)
/** Peripheral INTMUX0 base pointer */
#define INTMUX0                                  ((INTMUX_Type *)INTMUX0_BASE)
#define INTMUX0_BASE_PTR                         (INTMUX0)
/** Array initializer of INTMUX peripheral base addresses */
#define INTMUX_BASE_ADDRS                        { INTMUX0_BASE }
/** Array initializer of INTMUX peripheral base pointers */
#define INTMUX_BASE_PTRS                         { INTMUX0 }

/* ----------------------------------------------------------------------------
   -- INTMUX - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTMUX_Register_Accessor_Macros INTMUX - Register accessor macros
 * @{
 */


/* INTMUX - Register instance definitions */
/* INTMUX0 */
#define INTMUX0_CH0_CSR                          INTMUX_CHn_CSR_REG(INTMUX0,0)
#define INTMUX0_CH0_VEC                          INTMUX_CHn_VEC_REG(INTMUX0,0)
#define INTMUX0_CH0_IER_31_0                     INTMUX_CHn_IER_31_0_REG(INTMUX0,0)
#define INTMUX0_CH0_IPR_31_0                     INTMUX_CHn_IPR_31_0_REG(INTMUX0,0)
#define INTMUX0_CH1_CSR                          INTMUX_CHn_CSR_REG(INTMUX0,1)
#define INTMUX0_CH1_VEC                          INTMUX_CHn_VEC_REG(INTMUX0,1)
#define INTMUX0_CH1_IER_31_0                     INTMUX_CHn_IER_31_0_REG(INTMUX0,1)
#define INTMUX0_CH1_IPR_31_0                     INTMUX_CHn_IPR_31_0_REG(INTMUX0,1)
#define INTMUX0_CH2_CSR                          INTMUX_CHn_CSR_REG(INTMUX0,2)
#define INTMUX0_CH2_VEC                          INTMUX_CHn_VEC_REG(INTMUX0,2)
#define INTMUX0_CH2_IER_31_0                     INTMUX_CHn_IER_31_0_REG(INTMUX0,2)
#define INTMUX0_CH2_IPR_31_0                     INTMUX_CHn_IPR_31_0_REG(INTMUX0,2)
#define INTMUX0_CH3_CSR                          INTMUX_CHn_CSR_REG(INTMUX0,3)
#define INTMUX0_CH3_VEC                          INTMUX_CHn_VEC_REG(INTMUX0,3)
#define INTMUX0_CH3_IER_31_0                     INTMUX_CHn_IER_31_0_REG(INTMUX0,3)
#define INTMUX0_CH3_IPR_31_0                     INTMUX_CHn_IPR_31_0_REG(INTMUX0,3)

/* INTMUX - Register array accessors */
#define INTMUX0_CHn_CSR(index)                   INTMUX_CHn_CSR_REG(INTMUX0,index)
#define INTMUX0_CHn_VEC(index)                   INTMUX_CHn_VEC_REG(INTMUX0,index)
#define INTMUX0_CHn_IER_31_0(index)              INTMUX_CHn_IER_31_0_REG(INTMUX0,index)
#define INTMUX0_CHn_IPR_31_0(index)              INTMUX_CHn_IPR_31_0_REG(INTMUX0,index)

/*!
 * @}
 */ /* end of group INTMUX_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group INTMUX_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LLWU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Peripheral_Access_Layer LLWU Peripheral Access Layer
 * @{
 */

/** LLWU - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t PE1;                               /**< LLWU Pin Enable 1 register, offset: 0x8 */
  __IO uint32_t PE2;                               /**< LLWU Pin Enable 2 register, offset: 0xC */
       uint8_t RESERVED_0[8];
  __IO uint32_t ME;                                /**< LLWU Module Interrupt Enable register, offset: 0x18 */
  __IO uint32_t DE;                                /**< LLWU Module DMA Enable register, offset: 0x1C */
  __IO uint32_t PF;                                /**< LLWU Pin Flag register, offset: 0x20 */
       uint8_t RESERVED_1[4];
  __I  uint32_t MF;                                /**< LLWU Module Interrupt Flag register, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t FILT;                              /**< LLWU Pin Filter register, offset: 0x30 */
} LLWU_Type, *LLWU_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LLWU - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Register_Accessor_Macros LLWU - Register accessor macros
 * @{
 */


/* LLWU - Register accessors */
#define LLWU_VERID_REG(base)                     ((base)->VERID)
#define LLWU_PARAM_REG(base)                     ((base)->PARAM)
#define LLWU_PE1_REG(base)                       ((base)->PE1)
#define LLWU_PE2_REG(base)                       ((base)->PE2)
#define LLWU_ME_REG(base)                        ((base)->ME)
#define LLWU_DE_REG(base)                        ((base)->DE)
#define LLWU_PF_REG(base)                        ((base)->PF)
#define LLWU_MF_REG(base)                        ((base)->MF)
#define LLWU_FILT_REG(base)                      ((base)->FILT)

/*!
 * @}
 */ /* end of group LLWU_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LLWU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Register_Masks LLWU Register Masks
 * @{
 */

/* VERID Bit Fields */
#define LLWU_VERID_FEATURE_MASK                  0xFFFFu
#define LLWU_VERID_FEATURE_SHIFT                 0
#define LLWU_VERID_FEATURE_WIDTH                 16
#define LLWU_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x))<<LLWU_VERID_FEATURE_SHIFT))&LLWU_VERID_FEATURE_MASK)
#define LLWU_VERID_MINOR_MASK                    0xFF0000u
#define LLWU_VERID_MINOR_SHIFT                   16
#define LLWU_VERID_MINOR_WIDTH                   8
#define LLWU_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x))<<LLWU_VERID_MINOR_SHIFT))&LLWU_VERID_MINOR_MASK)
#define LLWU_VERID_MAJOR_MASK                    0xFF000000u
#define LLWU_VERID_MAJOR_SHIFT                   24
#define LLWU_VERID_MAJOR_WIDTH                   8
#define LLWU_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x))<<LLWU_VERID_MAJOR_SHIFT))&LLWU_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define LLWU_PARAM_FILTERS_MASK                  0xFFu
#define LLWU_PARAM_FILTERS_SHIFT                 0
#define LLWU_PARAM_FILTERS_WIDTH                 8
#define LLWU_PARAM_FILTERS(x)                    (((uint32_t)(((uint32_t)(x))<<LLWU_PARAM_FILTERS_SHIFT))&LLWU_PARAM_FILTERS_MASK)
#define LLWU_PARAM_DMAS_MASK                     0xFF00u
#define LLWU_PARAM_DMAS_SHIFT                    8
#define LLWU_PARAM_DMAS_WIDTH                    8
#define LLWU_PARAM_DMAS(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PARAM_DMAS_SHIFT))&LLWU_PARAM_DMAS_MASK)
#define LLWU_PARAM_MODULES_MASK                  0xFF0000u
#define LLWU_PARAM_MODULES_SHIFT                 16
#define LLWU_PARAM_MODULES_WIDTH                 8
#define LLWU_PARAM_MODULES(x)                    (((uint32_t)(((uint32_t)(x))<<LLWU_PARAM_MODULES_SHIFT))&LLWU_PARAM_MODULES_MASK)
#define LLWU_PARAM_PINS_MASK                     0xFF000000u
#define LLWU_PARAM_PINS_SHIFT                    24
#define LLWU_PARAM_PINS_WIDTH                    8
#define LLWU_PARAM_PINS(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PARAM_PINS_SHIFT))&LLWU_PARAM_PINS_MASK)
/* PE1 Bit Fields */
#define LLWU_PE1_WUPE0_MASK                      0x3u
#define LLWU_PE1_WUPE0_SHIFT                     0
#define LLWU_PE1_WUPE0_WIDTH                     2
#define LLWU_PE1_WUPE0(x)                        (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE0_SHIFT))&LLWU_PE1_WUPE0_MASK)
#define LLWU_PE1_WUPE1_MASK                      0xCu
#define LLWU_PE1_WUPE1_SHIFT                     2
#define LLWU_PE1_WUPE1_WIDTH                     2
#define LLWU_PE1_WUPE1(x)                        (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE1_SHIFT))&LLWU_PE1_WUPE1_MASK)
#define LLWU_PE1_WUPE2_MASK                      0x30u
#define LLWU_PE1_WUPE2_SHIFT                     4
#define LLWU_PE1_WUPE2_WIDTH                     2
#define LLWU_PE1_WUPE2(x)                        (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE2_SHIFT))&LLWU_PE1_WUPE2_MASK)
#define LLWU_PE1_WUPE3_MASK                      0xC0u
#define LLWU_PE1_WUPE3_SHIFT                     6
#define LLWU_PE1_WUPE3_WIDTH                     2
#define LLWU_PE1_WUPE3(x)                        (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE3_SHIFT))&LLWU_PE1_WUPE3_MASK)
#define LLWU_PE1_WUPE4_MASK                      0x300u
#define LLWU_PE1_WUPE4_SHIFT                     8
#define LLWU_PE1_WUPE4_WIDTH                     2
#define LLWU_PE1_WUPE4(x)                        (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE4_SHIFT))&LLWU_PE1_WUPE4_MASK)
#define LLWU_PE1_WUPE5_MASK                      0xC00u
#define LLWU_PE1_WUPE5_SHIFT                     10
#define LLWU_PE1_WUPE5_WIDTH                     2
#define LLWU_PE1_WUPE5(x)                        (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE5_SHIFT))&LLWU_PE1_WUPE5_MASK)
#define LLWU_PE1_WUPE6_MASK                      0x3000u
#define LLWU_PE1_WUPE6_SHIFT                     12
#define LLWU_PE1_WUPE6_WIDTH                     2
#define LLWU_PE1_WUPE6(x)                        (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE6_SHIFT))&LLWU_PE1_WUPE6_MASK)
#define LLWU_PE1_WUPE7_MASK                      0xC000u
#define LLWU_PE1_WUPE7_SHIFT                     14
#define LLWU_PE1_WUPE7_WIDTH                     2
#define LLWU_PE1_WUPE7(x)                        (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE7_SHIFT))&LLWU_PE1_WUPE7_MASK)
#define LLWU_PE1_WUPE8_MASK                      0x30000u
#define LLWU_PE1_WUPE8_SHIFT                     16
#define LLWU_PE1_WUPE8_WIDTH                     2
#define LLWU_PE1_WUPE8(x)                        (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE8_SHIFT))&LLWU_PE1_WUPE8_MASK)
#define LLWU_PE1_WUPE9_MASK                      0xC0000u
#define LLWU_PE1_WUPE9_SHIFT                     18
#define LLWU_PE1_WUPE9_WIDTH                     2
#define LLWU_PE1_WUPE9(x)                        (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE9_SHIFT))&LLWU_PE1_WUPE9_MASK)
#define LLWU_PE1_WUPE10_MASK                     0x300000u
#define LLWU_PE1_WUPE10_SHIFT                    20
#define LLWU_PE1_WUPE10_WIDTH                    2
#define LLWU_PE1_WUPE10(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE10_SHIFT))&LLWU_PE1_WUPE10_MASK)
#define LLWU_PE1_WUPE11_MASK                     0xC00000u
#define LLWU_PE1_WUPE11_SHIFT                    22
#define LLWU_PE1_WUPE11_WIDTH                    2
#define LLWU_PE1_WUPE11(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE11_SHIFT))&LLWU_PE1_WUPE11_MASK)
#define LLWU_PE1_WUPE12_MASK                     0x3000000u
#define LLWU_PE1_WUPE12_SHIFT                    24
#define LLWU_PE1_WUPE12_WIDTH                    2
#define LLWU_PE1_WUPE12(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE12_SHIFT))&LLWU_PE1_WUPE12_MASK)
#define LLWU_PE1_WUPE13_MASK                     0xC000000u
#define LLWU_PE1_WUPE13_SHIFT                    26
#define LLWU_PE1_WUPE13_WIDTH                    2
#define LLWU_PE1_WUPE13(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE13_SHIFT))&LLWU_PE1_WUPE13_MASK)
#define LLWU_PE1_WUPE14_MASK                     0x30000000u
#define LLWU_PE1_WUPE14_SHIFT                    28
#define LLWU_PE1_WUPE14_WIDTH                    2
#define LLWU_PE1_WUPE14(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE14_SHIFT))&LLWU_PE1_WUPE14_MASK)
#define LLWU_PE1_WUPE15_MASK                     0xC0000000u
#define LLWU_PE1_WUPE15_SHIFT                    30
#define LLWU_PE1_WUPE15_WIDTH                    2
#define LLWU_PE1_WUPE15(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE1_WUPE15_SHIFT))&LLWU_PE1_WUPE15_MASK)
/* PE2 Bit Fields */
#define LLWU_PE2_WUPE16_MASK                     0x3u
#define LLWU_PE2_WUPE16_SHIFT                    0
#define LLWU_PE2_WUPE16_WIDTH                    2
#define LLWU_PE2_WUPE16(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE16_SHIFT))&LLWU_PE2_WUPE16_MASK)
#define LLWU_PE2_WUPE17_MASK                     0xCu
#define LLWU_PE2_WUPE17_SHIFT                    2
#define LLWU_PE2_WUPE17_WIDTH                    2
#define LLWU_PE2_WUPE17(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE17_SHIFT))&LLWU_PE2_WUPE17_MASK)
#define LLWU_PE2_WUPE18_MASK                     0x30u
#define LLWU_PE2_WUPE18_SHIFT                    4
#define LLWU_PE2_WUPE18_WIDTH                    2
#define LLWU_PE2_WUPE18(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE18_SHIFT))&LLWU_PE2_WUPE18_MASK)
#define LLWU_PE2_WUPE19_MASK                     0xC0u
#define LLWU_PE2_WUPE19_SHIFT                    6
#define LLWU_PE2_WUPE19_WIDTH                    2
#define LLWU_PE2_WUPE19(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE19_SHIFT))&LLWU_PE2_WUPE19_MASK)
#define LLWU_PE2_WUPE20_MASK                     0x300u
#define LLWU_PE2_WUPE20_SHIFT                    8
#define LLWU_PE2_WUPE20_WIDTH                    2
#define LLWU_PE2_WUPE20(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE20_SHIFT))&LLWU_PE2_WUPE20_MASK)
#define LLWU_PE2_WUPE21_MASK                     0xC00u
#define LLWU_PE2_WUPE21_SHIFT                    10
#define LLWU_PE2_WUPE21_WIDTH                    2
#define LLWU_PE2_WUPE21(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE21_SHIFT))&LLWU_PE2_WUPE21_MASK)
#define LLWU_PE2_WUPE22_MASK                     0x3000u
#define LLWU_PE2_WUPE22_SHIFT                    12
#define LLWU_PE2_WUPE22_WIDTH                    2
#define LLWU_PE2_WUPE22(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE22_SHIFT))&LLWU_PE2_WUPE22_MASK)
#define LLWU_PE2_WUPE23_MASK                     0xC000u
#define LLWU_PE2_WUPE23_SHIFT                    14
#define LLWU_PE2_WUPE23_WIDTH                    2
#define LLWU_PE2_WUPE23(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE23_SHIFT))&LLWU_PE2_WUPE23_MASK)
#define LLWU_PE2_WUPE24_MASK                     0x30000u
#define LLWU_PE2_WUPE24_SHIFT                    16
#define LLWU_PE2_WUPE24_WIDTH                    2
#define LLWU_PE2_WUPE24(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE24_SHIFT))&LLWU_PE2_WUPE24_MASK)
#define LLWU_PE2_WUPE25_MASK                     0xC0000u
#define LLWU_PE2_WUPE25_SHIFT                    18
#define LLWU_PE2_WUPE25_WIDTH                    2
#define LLWU_PE2_WUPE25(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE25_SHIFT))&LLWU_PE2_WUPE25_MASK)
#define LLWU_PE2_WUPE26_MASK                     0x300000u
#define LLWU_PE2_WUPE26_SHIFT                    20
#define LLWU_PE2_WUPE26_WIDTH                    2
#define LLWU_PE2_WUPE26(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE26_SHIFT))&LLWU_PE2_WUPE26_MASK)
#define LLWU_PE2_WUPE27_MASK                     0xC00000u
#define LLWU_PE2_WUPE27_SHIFT                    22
#define LLWU_PE2_WUPE27_WIDTH                    2
#define LLWU_PE2_WUPE27(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE27_SHIFT))&LLWU_PE2_WUPE27_MASK)
#define LLWU_PE2_WUPE28_MASK                     0x3000000u
#define LLWU_PE2_WUPE28_SHIFT                    24
#define LLWU_PE2_WUPE28_WIDTH                    2
#define LLWU_PE2_WUPE28(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE28_SHIFT))&LLWU_PE2_WUPE28_MASK)
#define LLWU_PE2_WUPE29_MASK                     0xC000000u
#define LLWU_PE2_WUPE29_SHIFT                    26
#define LLWU_PE2_WUPE29_WIDTH                    2
#define LLWU_PE2_WUPE29(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE29_SHIFT))&LLWU_PE2_WUPE29_MASK)
#define LLWU_PE2_WUPE30_MASK                     0x30000000u
#define LLWU_PE2_WUPE30_SHIFT                    28
#define LLWU_PE2_WUPE30_WIDTH                    2
#define LLWU_PE2_WUPE30(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE30_SHIFT))&LLWU_PE2_WUPE30_MASK)
#define LLWU_PE2_WUPE31_MASK                     0xC0000000u
#define LLWU_PE2_WUPE31_SHIFT                    30
#define LLWU_PE2_WUPE31_WIDTH                    2
#define LLWU_PE2_WUPE31(x)                       (((uint32_t)(((uint32_t)(x))<<LLWU_PE2_WUPE31_SHIFT))&LLWU_PE2_WUPE31_MASK)
/* ME Bit Fields */
#define LLWU_ME_WUME0_MASK                       0x1u
#define LLWU_ME_WUME0_SHIFT                      0
#define LLWU_ME_WUME0_WIDTH                      1
#define LLWU_ME_WUME0(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_ME_WUME0_SHIFT))&LLWU_ME_WUME0_MASK)
#define LLWU_ME_WUME1_MASK                       0x2u
#define LLWU_ME_WUME1_SHIFT                      1
#define LLWU_ME_WUME1_WIDTH                      1
#define LLWU_ME_WUME1(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_ME_WUME1_SHIFT))&LLWU_ME_WUME1_MASK)
#define LLWU_ME_WUME2_MASK                       0x4u
#define LLWU_ME_WUME2_SHIFT                      2
#define LLWU_ME_WUME2_WIDTH                      1
#define LLWU_ME_WUME2(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_ME_WUME2_SHIFT))&LLWU_ME_WUME2_MASK)
#define LLWU_ME_WUME3_MASK                       0x8u
#define LLWU_ME_WUME3_SHIFT                      3
#define LLWU_ME_WUME3_WIDTH                      1
#define LLWU_ME_WUME3(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_ME_WUME3_SHIFT))&LLWU_ME_WUME3_MASK)
#define LLWU_ME_WUME4_MASK                       0x10u
#define LLWU_ME_WUME4_SHIFT                      4
#define LLWU_ME_WUME4_WIDTH                      1
#define LLWU_ME_WUME4(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_ME_WUME4_SHIFT))&LLWU_ME_WUME4_MASK)
#define LLWU_ME_WUME5_MASK                       0x20u
#define LLWU_ME_WUME5_SHIFT                      5
#define LLWU_ME_WUME5_WIDTH                      1
#define LLWU_ME_WUME5(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_ME_WUME5_SHIFT))&LLWU_ME_WUME5_MASK)
#define LLWU_ME_WUME6_MASK                       0x40u
#define LLWU_ME_WUME6_SHIFT                      6
#define LLWU_ME_WUME6_WIDTH                      1
#define LLWU_ME_WUME6(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_ME_WUME6_SHIFT))&LLWU_ME_WUME6_MASK)
#define LLWU_ME_WUME7_MASK                       0x80u
#define LLWU_ME_WUME7_SHIFT                      7
#define LLWU_ME_WUME7_WIDTH                      1
#define LLWU_ME_WUME7(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_ME_WUME7_SHIFT))&LLWU_ME_WUME7_MASK)
/* DE Bit Fields */
#define LLWU_DE_WUDE0_MASK                       0x1u
#define LLWU_DE_WUDE0_SHIFT                      0
#define LLWU_DE_WUDE0_WIDTH                      1
#define LLWU_DE_WUDE0(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_DE_WUDE0_SHIFT))&LLWU_DE_WUDE0_MASK)
#define LLWU_DE_WUDE1_MASK                       0x2u
#define LLWU_DE_WUDE1_SHIFT                      1
#define LLWU_DE_WUDE1_WIDTH                      1
#define LLWU_DE_WUDE1(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_DE_WUDE1_SHIFT))&LLWU_DE_WUDE1_MASK)
#define LLWU_DE_WUDE2_MASK                       0x4u
#define LLWU_DE_WUDE2_SHIFT                      2
#define LLWU_DE_WUDE2_WIDTH                      1
#define LLWU_DE_WUDE2(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_DE_WUDE2_SHIFT))&LLWU_DE_WUDE2_MASK)
#define LLWU_DE_WUDE3_MASK                       0x8u
#define LLWU_DE_WUDE3_SHIFT                      3
#define LLWU_DE_WUDE3_WIDTH                      1
#define LLWU_DE_WUDE3(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_DE_WUDE3_SHIFT))&LLWU_DE_WUDE3_MASK)
#define LLWU_DE_WUDE4_MASK                       0x10u
#define LLWU_DE_WUDE4_SHIFT                      4
#define LLWU_DE_WUDE4_WIDTH                      1
#define LLWU_DE_WUDE4(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_DE_WUDE4_SHIFT))&LLWU_DE_WUDE4_MASK)
#define LLWU_DE_WUDE5_MASK                       0x20u
#define LLWU_DE_WUDE5_SHIFT                      5
#define LLWU_DE_WUDE5_WIDTH                      1
#define LLWU_DE_WUDE5(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_DE_WUDE5_SHIFT))&LLWU_DE_WUDE5_MASK)
#define LLWU_DE_WUDE6_MASK                       0x40u
#define LLWU_DE_WUDE6_SHIFT                      6
#define LLWU_DE_WUDE6_WIDTH                      1
#define LLWU_DE_WUDE6(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_DE_WUDE6_SHIFT))&LLWU_DE_WUDE6_MASK)
#define LLWU_DE_WUDE7_MASK                       0x80u
#define LLWU_DE_WUDE7_SHIFT                      7
#define LLWU_DE_WUDE7_WIDTH                      1
#define LLWU_DE_WUDE7(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_DE_WUDE7_SHIFT))&LLWU_DE_WUDE7_MASK)
/* PF Bit Fields */
#define LLWU_PF_WUF0_MASK                        0x1u
#define LLWU_PF_WUF0_SHIFT                       0
#define LLWU_PF_WUF0_WIDTH                       1
#define LLWU_PF_WUF0(x)                          (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF0_SHIFT))&LLWU_PF_WUF0_MASK)
#define LLWU_PF_WUF1_MASK                        0x2u
#define LLWU_PF_WUF1_SHIFT                       1
#define LLWU_PF_WUF1_WIDTH                       1
#define LLWU_PF_WUF1(x)                          (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF1_SHIFT))&LLWU_PF_WUF1_MASK)
#define LLWU_PF_WUF2_MASK                        0x4u
#define LLWU_PF_WUF2_SHIFT                       2
#define LLWU_PF_WUF2_WIDTH                       1
#define LLWU_PF_WUF2(x)                          (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF2_SHIFT))&LLWU_PF_WUF2_MASK)
#define LLWU_PF_WUF3_MASK                        0x8u
#define LLWU_PF_WUF3_SHIFT                       3
#define LLWU_PF_WUF3_WIDTH                       1
#define LLWU_PF_WUF3(x)                          (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF3_SHIFT))&LLWU_PF_WUF3_MASK)
#define LLWU_PF_WUF4_MASK                        0x10u
#define LLWU_PF_WUF4_SHIFT                       4
#define LLWU_PF_WUF4_WIDTH                       1
#define LLWU_PF_WUF4(x)                          (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF4_SHIFT))&LLWU_PF_WUF4_MASK)
#define LLWU_PF_WUF5_MASK                        0x20u
#define LLWU_PF_WUF5_SHIFT                       5
#define LLWU_PF_WUF5_WIDTH                       1
#define LLWU_PF_WUF5(x)                          (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF5_SHIFT))&LLWU_PF_WUF5_MASK)
#define LLWU_PF_WUF6_MASK                        0x40u
#define LLWU_PF_WUF6_SHIFT                       6
#define LLWU_PF_WUF6_WIDTH                       1
#define LLWU_PF_WUF6(x)                          (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF6_SHIFT))&LLWU_PF_WUF6_MASK)
#define LLWU_PF_WUF7_MASK                        0x80u
#define LLWU_PF_WUF7_SHIFT                       7
#define LLWU_PF_WUF7_WIDTH                       1
#define LLWU_PF_WUF7(x)                          (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF7_SHIFT))&LLWU_PF_WUF7_MASK)
#define LLWU_PF_WUF8_MASK                        0x100u
#define LLWU_PF_WUF8_SHIFT                       8
#define LLWU_PF_WUF8_WIDTH                       1
#define LLWU_PF_WUF8(x)                          (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF8_SHIFT))&LLWU_PF_WUF8_MASK)
#define LLWU_PF_WUF9_MASK                        0x200u
#define LLWU_PF_WUF9_SHIFT                       9
#define LLWU_PF_WUF9_WIDTH                       1
#define LLWU_PF_WUF9(x)                          (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF9_SHIFT))&LLWU_PF_WUF9_MASK)
#define LLWU_PF_WUF10_MASK                       0x400u
#define LLWU_PF_WUF10_SHIFT                      10
#define LLWU_PF_WUF10_WIDTH                      1
#define LLWU_PF_WUF10(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF10_SHIFT))&LLWU_PF_WUF10_MASK)
#define LLWU_PF_WUF11_MASK                       0x800u
#define LLWU_PF_WUF11_SHIFT                      11
#define LLWU_PF_WUF11_WIDTH                      1
#define LLWU_PF_WUF11(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF11_SHIFT))&LLWU_PF_WUF11_MASK)
#define LLWU_PF_WUF12_MASK                       0x1000u
#define LLWU_PF_WUF12_SHIFT                      12
#define LLWU_PF_WUF12_WIDTH                      1
#define LLWU_PF_WUF12(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF12_SHIFT))&LLWU_PF_WUF12_MASK)
#define LLWU_PF_WUF13_MASK                       0x2000u
#define LLWU_PF_WUF13_SHIFT                      13
#define LLWU_PF_WUF13_WIDTH                      1
#define LLWU_PF_WUF13(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF13_SHIFT))&LLWU_PF_WUF13_MASK)
#define LLWU_PF_WUF14_MASK                       0x4000u
#define LLWU_PF_WUF14_SHIFT                      14
#define LLWU_PF_WUF14_WIDTH                      1
#define LLWU_PF_WUF14(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF14_SHIFT))&LLWU_PF_WUF14_MASK)
#define LLWU_PF_WUF15_MASK                       0x8000u
#define LLWU_PF_WUF15_SHIFT                      15
#define LLWU_PF_WUF15_WIDTH                      1
#define LLWU_PF_WUF15(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF15_SHIFT))&LLWU_PF_WUF15_MASK)
#define LLWU_PF_WUF16_MASK                       0x10000u
#define LLWU_PF_WUF16_SHIFT                      16
#define LLWU_PF_WUF16_WIDTH                      1
#define LLWU_PF_WUF16(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF16_SHIFT))&LLWU_PF_WUF16_MASK)
#define LLWU_PF_WUF17_MASK                       0x20000u
#define LLWU_PF_WUF17_SHIFT                      17
#define LLWU_PF_WUF17_WIDTH                      1
#define LLWU_PF_WUF17(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF17_SHIFT))&LLWU_PF_WUF17_MASK)
#define LLWU_PF_WUF18_MASK                       0x40000u
#define LLWU_PF_WUF18_SHIFT                      18
#define LLWU_PF_WUF18_WIDTH                      1
#define LLWU_PF_WUF18(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF18_SHIFT))&LLWU_PF_WUF18_MASK)
#define LLWU_PF_WUF19_MASK                       0x80000u
#define LLWU_PF_WUF19_SHIFT                      19
#define LLWU_PF_WUF19_WIDTH                      1
#define LLWU_PF_WUF19(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF19_SHIFT))&LLWU_PF_WUF19_MASK)
#define LLWU_PF_WUF20_MASK                       0x100000u
#define LLWU_PF_WUF20_SHIFT                      20
#define LLWU_PF_WUF20_WIDTH                      1
#define LLWU_PF_WUF20(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF20_SHIFT))&LLWU_PF_WUF20_MASK)
#define LLWU_PF_WUF21_MASK                       0x200000u
#define LLWU_PF_WUF21_SHIFT                      21
#define LLWU_PF_WUF21_WIDTH                      1
#define LLWU_PF_WUF21(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF21_SHIFT))&LLWU_PF_WUF21_MASK)
#define LLWU_PF_WUF22_MASK                       0x400000u
#define LLWU_PF_WUF22_SHIFT                      22
#define LLWU_PF_WUF22_WIDTH                      1
#define LLWU_PF_WUF22(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF22_SHIFT))&LLWU_PF_WUF22_MASK)
#define LLWU_PF_WUF23_MASK                       0x800000u
#define LLWU_PF_WUF23_SHIFT                      23
#define LLWU_PF_WUF23_WIDTH                      1
#define LLWU_PF_WUF23(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF23_SHIFT))&LLWU_PF_WUF23_MASK)
#define LLWU_PF_WUF24_MASK                       0x1000000u
#define LLWU_PF_WUF24_SHIFT                      24
#define LLWU_PF_WUF24_WIDTH                      1
#define LLWU_PF_WUF24(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF24_SHIFT))&LLWU_PF_WUF24_MASK)
#define LLWU_PF_WUF25_MASK                       0x2000000u
#define LLWU_PF_WUF25_SHIFT                      25
#define LLWU_PF_WUF25_WIDTH                      1
#define LLWU_PF_WUF25(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF25_SHIFT))&LLWU_PF_WUF25_MASK)
#define LLWU_PF_WUF26_MASK                       0x4000000u
#define LLWU_PF_WUF26_SHIFT                      26
#define LLWU_PF_WUF26_WIDTH                      1
#define LLWU_PF_WUF26(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF26_SHIFT))&LLWU_PF_WUF26_MASK)
#define LLWU_PF_WUF27_MASK                       0x8000000u
#define LLWU_PF_WUF27_SHIFT                      27
#define LLWU_PF_WUF27_WIDTH                      1
#define LLWU_PF_WUF27(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF27_SHIFT))&LLWU_PF_WUF27_MASK)
#define LLWU_PF_WUF28_MASK                       0x10000000u
#define LLWU_PF_WUF28_SHIFT                      28
#define LLWU_PF_WUF28_WIDTH                      1
#define LLWU_PF_WUF28(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF28_SHIFT))&LLWU_PF_WUF28_MASK)
#define LLWU_PF_WUF29_MASK                       0x20000000u
#define LLWU_PF_WUF29_SHIFT                      29
#define LLWU_PF_WUF29_WIDTH                      1
#define LLWU_PF_WUF29(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF29_SHIFT))&LLWU_PF_WUF29_MASK)
#define LLWU_PF_WUF30_MASK                       0x40000000u
#define LLWU_PF_WUF30_SHIFT                      30
#define LLWU_PF_WUF30_WIDTH                      1
#define LLWU_PF_WUF30(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF30_SHIFT))&LLWU_PF_WUF30_MASK)
#define LLWU_PF_WUF31_MASK                       0x80000000u
#define LLWU_PF_WUF31_SHIFT                      31
#define LLWU_PF_WUF31_WIDTH                      1
#define LLWU_PF_WUF31(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_PF_WUF31_SHIFT))&LLWU_PF_WUF31_MASK)
/* MF Bit Fields */
#define LLWU_MF_MWUF0_MASK                       0x1u
#define LLWU_MF_MWUF0_SHIFT                      0
#define LLWU_MF_MWUF0_WIDTH                      1
#define LLWU_MF_MWUF0(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_MF_MWUF0_SHIFT))&LLWU_MF_MWUF0_MASK)
#define LLWU_MF_MWUF1_MASK                       0x2u
#define LLWU_MF_MWUF1_SHIFT                      1
#define LLWU_MF_MWUF1_WIDTH                      1
#define LLWU_MF_MWUF1(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_MF_MWUF1_SHIFT))&LLWU_MF_MWUF1_MASK)
#define LLWU_MF_MWUF2_MASK                       0x4u
#define LLWU_MF_MWUF2_SHIFT                      2
#define LLWU_MF_MWUF2_WIDTH                      1
#define LLWU_MF_MWUF2(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_MF_MWUF2_SHIFT))&LLWU_MF_MWUF2_MASK)
#define LLWU_MF_MWUF3_MASK                       0x8u
#define LLWU_MF_MWUF3_SHIFT                      3
#define LLWU_MF_MWUF3_WIDTH                      1
#define LLWU_MF_MWUF3(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_MF_MWUF3_SHIFT))&LLWU_MF_MWUF3_MASK)
#define LLWU_MF_MWUF4_MASK                       0x10u
#define LLWU_MF_MWUF4_SHIFT                      4
#define LLWU_MF_MWUF4_WIDTH                      1
#define LLWU_MF_MWUF4(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_MF_MWUF4_SHIFT))&LLWU_MF_MWUF4_MASK)
#define LLWU_MF_MWUF5_MASK                       0x20u
#define LLWU_MF_MWUF5_SHIFT                      5
#define LLWU_MF_MWUF5_WIDTH                      1
#define LLWU_MF_MWUF5(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_MF_MWUF5_SHIFT))&LLWU_MF_MWUF5_MASK)
#define LLWU_MF_MWUF6_MASK                       0x40u
#define LLWU_MF_MWUF6_SHIFT                      6
#define LLWU_MF_MWUF6_WIDTH                      1
#define LLWU_MF_MWUF6(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_MF_MWUF6_SHIFT))&LLWU_MF_MWUF6_MASK)
#define LLWU_MF_MWUF7_MASK                       0x80u
#define LLWU_MF_MWUF7_SHIFT                      7
#define LLWU_MF_MWUF7_WIDTH                      1
#define LLWU_MF_MWUF7(x)                         (((uint32_t)(((uint32_t)(x))<<LLWU_MF_MWUF7_SHIFT))&LLWU_MF_MWUF7_MASK)
/* FILT Bit Fields */
#define LLWU_FILT_FILTSEL1_MASK                  0x1Fu
#define LLWU_FILT_FILTSEL1_SHIFT                 0
#define LLWU_FILT_FILTSEL1_WIDTH                 5
#define LLWU_FILT_FILTSEL1(x)                    (((uint32_t)(((uint32_t)(x))<<LLWU_FILT_FILTSEL1_SHIFT))&LLWU_FILT_FILTSEL1_MASK)
#define LLWU_FILT_FILTE1_MASK                    0x60u
#define LLWU_FILT_FILTE1_SHIFT                   5
#define LLWU_FILT_FILTE1_WIDTH                   2
#define LLWU_FILT_FILTE1(x)                      (((uint32_t)(((uint32_t)(x))<<LLWU_FILT_FILTE1_SHIFT))&LLWU_FILT_FILTE1_MASK)
#define LLWU_FILT_FILTF1_MASK                    0x80u
#define LLWU_FILT_FILTF1_SHIFT                   7
#define LLWU_FILT_FILTF1_WIDTH                   1
#define LLWU_FILT_FILTF1(x)                      (((uint32_t)(((uint32_t)(x))<<LLWU_FILT_FILTF1_SHIFT))&LLWU_FILT_FILTF1_MASK)
#define LLWU_FILT_FILTSEL2_MASK                  0x1F00u
#define LLWU_FILT_FILTSEL2_SHIFT                 8
#define LLWU_FILT_FILTSEL2_WIDTH                 5
#define LLWU_FILT_FILTSEL2(x)                    (((uint32_t)(((uint32_t)(x))<<LLWU_FILT_FILTSEL2_SHIFT))&LLWU_FILT_FILTSEL2_MASK)
#define LLWU_FILT_FILTE2_MASK                    0x6000u
#define LLWU_FILT_FILTE2_SHIFT                   13
#define LLWU_FILT_FILTE2_WIDTH                   2
#define LLWU_FILT_FILTE2(x)                      (((uint32_t)(((uint32_t)(x))<<LLWU_FILT_FILTE2_SHIFT))&LLWU_FILT_FILTE2_MASK)
#define LLWU_FILT_FILTF2_MASK                    0x8000u
#define LLWU_FILT_FILTF2_SHIFT                   15
#define LLWU_FILT_FILTF2_WIDTH                   1
#define LLWU_FILT_FILTF2(x)                      (((uint32_t)(((uint32_t)(x))<<LLWU_FILT_FILTF2_SHIFT))&LLWU_FILT_FILTF2_MASK)
#define LLWU_FILT_FILTSEL3_MASK                  0x1F0000u
#define LLWU_FILT_FILTSEL3_SHIFT                 16
#define LLWU_FILT_FILTSEL3_WIDTH                 5
#define LLWU_FILT_FILTSEL3(x)                    (((uint32_t)(((uint32_t)(x))<<LLWU_FILT_FILTSEL3_SHIFT))&LLWU_FILT_FILTSEL3_MASK)
#define LLWU_FILT_FILTE3_MASK                    0x600000u
#define LLWU_FILT_FILTE3_SHIFT                   21
#define LLWU_FILT_FILTE3_WIDTH                   2
#define LLWU_FILT_FILTE3(x)                      (((uint32_t)(((uint32_t)(x))<<LLWU_FILT_FILTE3_SHIFT))&LLWU_FILT_FILTE3_MASK)
#define LLWU_FILT_FILTF3_MASK                    0x800000u
#define LLWU_FILT_FILTF3_SHIFT                   23
#define LLWU_FILT_FILTF3_WIDTH                   1
#define LLWU_FILT_FILTF3(x)                      (((uint32_t)(((uint32_t)(x))<<LLWU_FILT_FILTF3_SHIFT))&LLWU_FILT_FILTF3_MASK)
#define LLWU_FILT_FILTSEL4_MASK                  0x1F000000u
#define LLWU_FILT_FILTSEL4_SHIFT                 24
#define LLWU_FILT_FILTSEL4_WIDTH                 5
#define LLWU_FILT_FILTSEL4(x)                    (((uint32_t)(((uint32_t)(x))<<LLWU_FILT_FILTSEL4_SHIFT))&LLWU_FILT_FILTSEL4_MASK)
#define LLWU_FILT_FILTE4_MASK                    0x60000000u
#define LLWU_FILT_FILTE4_SHIFT                   29
#define LLWU_FILT_FILTE4_WIDTH                   2
#define LLWU_FILT_FILTE4(x)                      (((uint32_t)(((uint32_t)(x))<<LLWU_FILT_FILTE4_SHIFT))&LLWU_FILT_FILTE4_MASK)
#define LLWU_FILT_FILTF4_MASK                    0x80000000u
#define LLWU_FILT_FILTF4_SHIFT                   31
#define LLWU_FILT_FILTF4_WIDTH                   1
#define LLWU_FILT_FILTF4(x)                      (((uint32_t)(((uint32_t)(x))<<LLWU_FILT_FILTF4_SHIFT))&LLWU_FILT_FILTF4_MASK)

/*!
 * @}
 */ /* end of group LLWU_Register_Masks */


/* LLWU - Peripheral instance base addresses */
/** Peripheral LLWU0 base address */
#define LLWU0_BASE                               (0x40061000u)
/** Peripheral LLWU0 base pointer */
#define LLWU0                                    ((LLWU_Type *)LLWU0_BASE)
#define LLWU0_BASE_PTR                           (LLWU0)
/** Array initializer of LLWU peripheral base addresses */
#define LLWU_BASE_ADDRS                          { LLWU0_BASE }
/** Array initializer of LLWU peripheral base pointers */
#define LLWU_BASE_PTRS                           { LLWU0 }

/* ----------------------------------------------------------------------------
   -- LLWU - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Register_Accessor_Macros LLWU - Register accessor macros
 * @{
 */


/* LLWU - Register instance definitions */
/* LLWU0 */
#define LLWU0_VERID                              LLWU_VERID_REG(LLWU0)
#define LLWU0_PARAM                              LLWU_PARAM_REG(LLWU0)
#define LLWU0_PE1                                LLWU_PE1_REG(LLWU0)
#define LLWU0_PE2                                LLWU_PE2_REG(LLWU0)
#define LLWU0_ME                                 LLWU_ME_REG(LLWU0)
#define LLWU0_DE                                 LLWU_DE_REG(LLWU0)
#define LLWU0_PF                                 LLWU_PF_REG(LLWU0)
#define LLWU0_MF                                 LLWU_MF_REG(LLWU0)
#define LLWU0_FILT                               LLWU_FILT_REG(LLWU0)

/*!
 * @}
 */ /* end of group LLWU_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group LLWU_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPI2C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPI2C_Peripheral_Access_Layer LPI2C Peripheral Access Layer
 * @{
 */

/** LPI2C - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t MCR;                               /**< Master Control Register, offset: 0x10 */
  __IO uint32_t MSR;                               /**< Master Status Register, offset: 0x14 */
  __IO uint32_t MIER;                              /**< Master Interrupt Enable Register, offset: 0x18 */
  __IO uint32_t MDER;                              /**< Master DMA Enable Register, offset: 0x1C */
  __IO uint32_t MCFGR0;                            /**< Master Configuration Register 0, offset: 0x20 */
  __IO uint32_t MCFGR1;                            /**< Master Configuration Register 1, offset: 0x24 */
  __IO uint32_t MCFGR2;                            /**< Master Configuration Register 2, offset: 0x28 */
  __IO uint32_t MCFGR3;                            /**< Master Configuration Register 3, offset: 0x2C */
       uint8_t RESERVED_1[16];
  __IO uint32_t MDMR;                              /**< Master Data Match Register, offset: 0x40 */
       uint8_t RESERVED_2[4];
  __IO uint32_t MCCR0;                             /**< Master Clock Configuration Register 0, offset: 0x48 */
       uint8_t RESERVED_3[4];
  __IO uint32_t MCCR1;                             /**< Master Clock Configuration Register 1, offset: 0x50 */
       uint8_t RESERVED_4[4];
  __IO uint32_t MFCR;                              /**< Master FIFO Control Register, offset: 0x58 */
  __I  uint32_t MFSR;                              /**< Master FIFO Status Register, offset: 0x5C */
  __O  uint32_t MTDR;                              /**< Master Transmit Data Register, offset: 0x60 */
       uint8_t RESERVED_5[12];
  __I  uint32_t MRDR;                              /**< Master Receive Data Register, offset: 0x70 */
       uint8_t RESERVED_6[156];
  __IO uint32_t SCR;                               /**< Slave Control Register, offset: 0x110 */
  __IO uint32_t SSR;                               /**< Slave Status Register, offset: 0x114 */
  __IO uint32_t SIER;                              /**< Slave Interrupt Enable Register, offset: 0x118 */
  __IO uint32_t SDER;                              /**< Slave DMA Enable Register, offset: 0x11C */
       uint8_t RESERVED_7[4];
  __IO uint32_t SCFGR1;                            /**< Slave Configuration Register 1, offset: 0x124 */
  __IO uint32_t SCFGR2;                            /**< Slave Configuration Register 2, offset: 0x128 */
       uint8_t RESERVED_8[20];
  __IO uint32_t SAMR;                              /**< Slave Address Match Register, offset: 0x140 */
       uint8_t RESERVED_9[12];
  __I  uint32_t SASR;                              /**< Slave Address Status Register, offset: 0x150 */
  __IO uint32_t STAR;                              /**< Slave Transmit ACK Register, offset: 0x154 */
       uint8_t RESERVED_10[8];
  __O  uint32_t STDR;                              /**< Slave Transmit Data Register, offset: 0x160 */
       uint8_t RESERVED_11[12];
  __I  uint32_t SRDR;                              /**< Slave Receive Data Register, offset: 0x170 */
} LPI2C_Type, *LPI2C_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LPI2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPI2C_Register_Accessor_Macros LPI2C - Register accessor macros
 * @{
 */


/* LPI2C - Register accessors */
#define LPI2C_VERID_REG(base)                    ((base)->VERID)
#define LPI2C_PARAM_REG(base)                    ((base)->PARAM)
#define LPI2C_MCR_REG(base)                      ((base)->MCR)
#define LPI2C_MSR_REG(base)                      ((base)->MSR)
#define LPI2C_MIER_REG(base)                     ((base)->MIER)
#define LPI2C_MDER_REG(base)                     ((base)->MDER)
#define LPI2C_MCFGR0_REG(base)                   ((base)->MCFGR0)
#define LPI2C_MCFGR1_REG(base)                   ((base)->MCFGR1)
#define LPI2C_MCFGR2_REG(base)                   ((base)->MCFGR2)
#define LPI2C_MCFGR3_REG(base)                   ((base)->MCFGR3)
#define LPI2C_MDMR_REG(base)                     ((base)->MDMR)
#define LPI2C_MCCR0_REG(base)                    ((base)->MCCR0)
#define LPI2C_MCCR1_REG(base)                    ((base)->MCCR1)
#define LPI2C_MFCR_REG(base)                     ((base)->MFCR)
#define LPI2C_MFSR_REG(base)                     ((base)->MFSR)
#define LPI2C_MTDR_REG(base)                     ((base)->MTDR)
#define LPI2C_MRDR_REG(base)                     ((base)->MRDR)
#define LPI2C_SCR_REG(base)                      ((base)->SCR)
#define LPI2C_SSR_REG(base)                      ((base)->SSR)
#define LPI2C_SIER_REG(base)                     ((base)->SIER)
#define LPI2C_SDER_REG(base)                     ((base)->SDER)
#define LPI2C_SCFGR1_REG(base)                   ((base)->SCFGR1)
#define LPI2C_SCFGR2_REG(base)                   ((base)->SCFGR2)
#define LPI2C_SAMR_REG(base)                     ((base)->SAMR)
#define LPI2C_SASR_REG(base)                     ((base)->SASR)
#define LPI2C_STAR_REG(base)                     ((base)->STAR)
#define LPI2C_STDR_REG(base)                     ((base)->STDR)
#define LPI2C_SRDR_REG(base)                     ((base)->SRDR)

/*!
 * @}
 */ /* end of group LPI2C_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LPI2C Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPI2C_Register_Masks LPI2C Register Masks
 * @{
 */

/* VERID Bit Fields */
#define LPI2C_VERID_FEATURE_MASK                 0xFFFFu
#define LPI2C_VERID_FEATURE_SHIFT                0
#define LPI2C_VERID_FEATURE_WIDTH                16
#define LPI2C_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_VERID_FEATURE_SHIFT))&LPI2C_VERID_FEATURE_MASK)
#define LPI2C_VERID_MINOR_MASK                   0xFF0000u
#define LPI2C_VERID_MINOR_SHIFT                  16
#define LPI2C_VERID_MINOR_WIDTH                  8
#define LPI2C_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_VERID_MINOR_SHIFT))&LPI2C_VERID_MINOR_MASK)
#define LPI2C_VERID_MAJOR_MASK                   0xFF000000u
#define LPI2C_VERID_MAJOR_SHIFT                  24
#define LPI2C_VERID_MAJOR_WIDTH                  8
#define LPI2C_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_VERID_MAJOR_SHIFT))&LPI2C_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define LPI2C_PARAM_MTXFIFO_MASK                 0xFu
#define LPI2C_PARAM_MTXFIFO_SHIFT                0
#define LPI2C_PARAM_MTXFIFO_WIDTH                4
#define LPI2C_PARAM_MTXFIFO(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_PARAM_MTXFIFO_SHIFT))&LPI2C_PARAM_MTXFIFO_MASK)
#define LPI2C_PARAM_MRXFIFO_MASK                 0xF00u
#define LPI2C_PARAM_MRXFIFO_SHIFT                8
#define LPI2C_PARAM_MRXFIFO_WIDTH                4
#define LPI2C_PARAM_MRXFIFO(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_PARAM_MRXFIFO_SHIFT))&LPI2C_PARAM_MRXFIFO_MASK)
/* MCR Bit Fields */
#define LPI2C_MCR_MEN_MASK                       0x1u
#define LPI2C_MCR_MEN_SHIFT                      0
#define LPI2C_MCR_MEN_WIDTH                      1
#define LPI2C_MCR_MEN(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MCR_MEN_SHIFT))&LPI2C_MCR_MEN_MASK)
#define LPI2C_MCR_RST_MASK                       0x2u
#define LPI2C_MCR_RST_SHIFT                      1
#define LPI2C_MCR_RST_WIDTH                      1
#define LPI2C_MCR_RST(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MCR_RST_SHIFT))&LPI2C_MCR_RST_MASK)
#define LPI2C_MCR_DOZEN_MASK                     0x4u
#define LPI2C_MCR_DOZEN_SHIFT                    2
#define LPI2C_MCR_DOZEN_WIDTH                    1
#define LPI2C_MCR_DOZEN(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MCR_DOZEN_SHIFT))&LPI2C_MCR_DOZEN_MASK)
#define LPI2C_MCR_DBGEN_MASK                     0x8u
#define LPI2C_MCR_DBGEN_SHIFT                    3
#define LPI2C_MCR_DBGEN_WIDTH                    1
#define LPI2C_MCR_DBGEN(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MCR_DBGEN_SHIFT))&LPI2C_MCR_DBGEN_MASK)
#define LPI2C_MCR_RTF_MASK                       0x100u
#define LPI2C_MCR_RTF_SHIFT                      8
#define LPI2C_MCR_RTF_WIDTH                      1
#define LPI2C_MCR_RTF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MCR_RTF_SHIFT))&LPI2C_MCR_RTF_MASK)
#define LPI2C_MCR_RRF_MASK                       0x200u
#define LPI2C_MCR_RRF_SHIFT                      9
#define LPI2C_MCR_RRF_WIDTH                      1
#define LPI2C_MCR_RRF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MCR_RRF_SHIFT))&LPI2C_MCR_RRF_MASK)
/* MSR Bit Fields */
#define LPI2C_MSR_TDF_MASK                       0x1u
#define LPI2C_MSR_TDF_SHIFT                      0
#define LPI2C_MSR_TDF_WIDTH                      1
#define LPI2C_MSR_TDF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_TDF_SHIFT))&LPI2C_MSR_TDF_MASK)
#define LPI2C_MSR_RDF_MASK                       0x2u
#define LPI2C_MSR_RDF_SHIFT                      1
#define LPI2C_MSR_RDF_WIDTH                      1
#define LPI2C_MSR_RDF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_RDF_SHIFT))&LPI2C_MSR_RDF_MASK)
#define LPI2C_MSR_EPF_MASK                       0x100u
#define LPI2C_MSR_EPF_SHIFT                      8
#define LPI2C_MSR_EPF_WIDTH                      1
#define LPI2C_MSR_EPF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_EPF_SHIFT))&LPI2C_MSR_EPF_MASK)
#define LPI2C_MSR_SDF_MASK                       0x200u
#define LPI2C_MSR_SDF_SHIFT                      9
#define LPI2C_MSR_SDF_WIDTH                      1
#define LPI2C_MSR_SDF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_SDF_SHIFT))&LPI2C_MSR_SDF_MASK)
#define LPI2C_MSR_NDF_MASK                       0x400u
#define LPI2C_MSR_NDF_SHIFT                      10
#define LPI2C_MSR_NDF_WIDTH                      1
#define LPI2C_MSR_NDF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_NDF_SHIFT))&LPI2C_MSR_NDF_MASK)
#define LPI2C_MSR_ALF_MASK                       0x800u
#define LPI2C_MSR_ALF_SHIFT                      11
#define LPI2C_MSR_ALF_WIDTH                      1
#define LPI2C_MSR_ALF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_ALF_SHIFT))&LPI2C_MSR_ALF_MASK)
#define LPI2C_MSR_FEF_MASK                       0x1000u
#define LPI2C_MSR_FEF_SHIFT                      12
#define LPI2C_MSR_FEF_WIDTH                      1
#define LPI2C_MSR_FEF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_FEF_SHIFT))&LPI2C_MSR_FEF_MASK)
#define LPI2C_MSR_PLTF_MASK                      0x2000u
#define LPI2C_MSR_PLTF_SHIFT                     13
#define LPI2C_MSR_PLTF_WIDTH                     1
#define LPI2C_MSR_PLTF(x)                        (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_PLTF_SHIFT))&LPI2C_MSR_PLTF_MASK)
#define LPI2C_MSR_DMF_MASK                       0x4000u
#define LPI2C_MSR_DMF_SHIFT                      14
#define LPI2C_MSR_DMF_WIDTH                      1
#define LPI2C_MSR_DMF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_DMF_SHIFT))&LPI2C_MSR_DMF_MASK)
#define LPI2C_MSR_MBF_MASK                       0x1000000u
#define LPI2C_MSR_MBF_SHIFT                      24
#define LPI2C_MSR_MBF_WIDTH                      1
#define LPI2C_MSR_MBF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_MBF_SHIFT))&LPI2C_MSR_MBF_MASK)
#define LPI2C_MSR_BBF_MASK                       0x2000000u
#define LPI2C_MSR_BBF_SHIFT                      25
#define LPI2C_MSR_BBF_WIDTH                      1
#define LPI2C_MSR_BBF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_BBF_SHIFT))&LPI2C_MSR_BBF_MASK)
/* MIER Bit Fields */
#define LPI2C_MIER_TDIE_MASK                     0x1u
#define LPI2C_MIER_TDIE_SHIFT                    0
#define LPI2C_MIER_TDIE_WIDTH                    1
#define LPI2C_MIER_TDIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_TDIE_SHIFT))&LPI2C_MIER_TDIE_MASK)
#define LPI2C_MIER_RDIE_MASK                     0x2u
#define LPI2C_MIER_RDIE_SHIFT                    1
#define LPI2C_MIER_RDIE_WIDTH                    1
#define LPI2C_MIER_RDIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_RDIE_SHIFT))&LPI2C_MIER_RDIE_MASK)
#define LPI2C_MIER_EPIE_MASK                     0x100u
#define LPI2C_MIER_EPIE_SHIFT                    8
#define LPI2C_MIER_EPIE_WIDTH                    1
#define LPI2C_MIER_EPIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_EPIE_SHIFT))&LPI2C_MIER_EPIE_MASK)
#define LPI2C_MIER_SDIE_MASK                     0x200u
#define LPI2C_MIER_SDIE_SHIFT                    9
#define LPI2C_MIER_SDIE_WIDTH                    1
#define LPI2C_MIER_SDIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_SDIE_SHIFT))&LPI2C_MIER_SDIE_MASK)
#define LPI2C_MIER_NDIE_MASK                     0x400u
#define LPI2C_MIER_NDIE_SHIFT                    10
#define LPI2C_MIER_NDIE_WIDTH                    1
#define LPI2C_MIER_NDIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_NDIE_SHIFT))&LPI2C_MIER_NDIE_MASK)
#define LPI2C_MIER_ALIE_MASK                     0x800u
#define LPI2C_MIER_ALIE_SHIFT                    11
#define LPI2C_MIER_ALIE_WIDTH                    1
#define LPI2C_MIER_ALIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_ALIE_SHIFT))&LPI2C_MIER_ALIE_MASK)
#define LPI2C_MIER_FEIE_MASK                     0x1000u
#define LPI2C_MIER_FEIE_SHIFT                    12
#define LPI2C_MIER_FEIE_WIDTH                    1
#define LPI2C_MIER_FEIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_FEIE_SHIFT))&LPI2C_MIER_FEIE_MASK)
#define LPI2C_MIER_PLTIE_MASK                    0x2000u
#define LPI2C_MIER_PLTIE_SHIFT                   13
#define LPI2C_MIER_PLTIE_WIDTH                   1
#define LPI2C_MIER_PLTIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_PLTIE_SHIFT))&LPI2C_MIER_PLTIE_MASK)
#define LPI2C_MIER_DMIE_MASK                     0x4000u
#define LPI2C_MIER_DMIE_SHIFT                    14
#define LPI2C_MIER_DMIE_WIDTH                    1
#define LPI2C_MIER_DMIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_DMIE_SHIFT))&LPI2C_MIER_DMIE_MASK)
/* MDER Bit Fields */
#define LPI2C_MDER_TDDE_MASK                     0x1u
#define LPI2C_MDER_TDDE_SHIFT                    0
#define LPI2C_MDER_TDDE_WIDTH                    1
#define LPI2C_MDER_TDDE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MDER_TDDE_SHIFT))&LPI2C_MDER_TDDE_MASK)
#define LPI2C_MDER_RDDE_MASK                     0x2u
#define LPI2C_MDER_RDDE_SHIFT                    1
#define LPI2C_MDER_RDDE_WIDTH                    1
#define LPI2C_MDER_RDDE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MDER_RDDE_SHIFT))&LPI2C_MDER_RDDE_MASK)
/* MCFGR0 Bit Fields */
#define LPI2C_MCFGR0_HREN_MASK                   0x1u
#define LPI2C_MCFGR0_HREN_SHIFT                  0
#define LPI2C_MCFGR0_HREN_WIDTH                  1
#define LPI2C_MCFGR0_HREN(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR0_HREN_SHIFT))&LPI2C_MCFGR0_HREN_MASK)
#define LPI2C_MCFGR0_HRPOL_MASK                  0x2u
#define LPI2C_MCFGR0_HRPOL_SHIFT                 1
#define LPI2C_MCFGR0_HRPOL_WIDTH                 1
#define LPI2C_MCFGR0_HRPOL(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR0_HRPOL_SHIFT))&LPI2C_MCFGR0_HRPOL_MASK)
#define LPI2C_MCFGR0_HRSEL_MASK                  0x4u
#define LPI2C_MCFGR0_HRSEL_SHIFT                 2
#define LPI2C_MCFGR0_HRSEL_WIDTH                 1
#define LPI2C_MCFGR0_HRSEL(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR0_HRSEL_SHIFT))&LPI2C_MCFGR0_HRSEL_MASK)
#define LPI2C_MCFGR0_CIRFIFO_MASK                0x100u
#define LPI2C_MCFGR0_CIRFIFO_SHIFT               8
#define LPI2C_MCFGR0_CIRFIFO_WIDTH               1
#define LPI2C_MCFGR0_CIRFIFO(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR0_CIRFIFO_SHIFT))&LPI2C_MCFGR0_CIRFIFO_MASK)
#define LPI2C_MCFGR0_RDMO_MASK                   0x200u
#define LPI2C_MCFGR0_RDMO_SHIFT                  9
#define LPI2C_MCFGR0_RDMO_WIDTH                  1
#define LPI2C_MCFGR0_RDMO(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR0_RDMO_SHIFT))&LPI2C_MCFGR0_RDMO_MASK)
/* MCFGR1 Bit Fields */
#define LPI2C_MCFGR1_PRESCALE_MASK               0x7u
#define LPI2C_MCFGR1_PRESCALE_SHIFT              0
#define LPI2C_MCFGR1_PRESCALE_WIDTH              3
#define LPI2C_MCFGR1_PRESCALE(x)                 (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR1_PRESCALE_SHIFT))&LPI2C_MCFGR1_PRESCALE_MASK)
#define LPI2C_MCFGR1_AUTOSTOP_MASK               0x100u
#define LPI2C_MCFGR1_AUTOSTOP_SHIFT              8
#define LPI2C_MCFGR1_AUTOSTOP_WIDTH              1
#define LPI2C_MCFGR1_AUTOSTOP(x)                 (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR1_AUTOSTOP_SHIFT))&LPI2C_MCFGR1_AUTOSTOP_MASK)
#define LPI2C_MCFGR1_IGNACK_MASK                 0x200u
#define LPI2C_MCFGR1_IGNACK_SHIFT                9
#define LPI2C_MCFGR1_IGNACK_WIDTH                1
#define LPI2C_MCFGR1_IGNACK(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR1_IGNACK_SHIFT))&LPI2C_MCFGR1_IGNACK_MASK)
#define LPI2C_MCFGR1_TIMECFG_MASK                0x400u
#define LPI2C_MCFGR1_TIMECFG_SHIFT               10
#define LPI2C_MCFGR1_TIMECFG_WIDTH               1
#define LPI2C_MCFGR1_TIMECFG(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR1_TIMECFG_SHIFT))&LPI2C_MCFGR1_TIMECFG_MASK)
#define LPI2C_MCFGR1_MATCFG_MASK                 0x70000u
#define LPI2C_MCFGR1_MATCFG_SHIFT                16
#define LPI2C_MCFGR1_MATCFG_WIDTH                3
#define LPI2C_MCFGR1_MATCFG(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR1_MATCFG_SHIFT))&LPI2C_MCFGR1_MATCFG_MASK)
#define LPI2C_MCFGR1_PINCFG_MASK                 0x7000000u
#define LPI2C_MCFGR1_PINCFG_SHIFT                24
#define LPI2C_MCFGR1_PINCFG_WIDTH                3
#define LPI2C_MCFGR1_PINCFG(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR1_PINCFG_SHIFT))&LPI2C_MCFGR1_PINCFG_MASK)
/* MCFGR2 Bit Fields */
#define LPI2C_MCFGR2_BUSIDLE_MASK                0xFFFu
#define LPI2C_MCFGR2_BUSIDLE_SHIFT               0
#define LPI2C_MCFGR2_BUSIDLE_WIDTH               12
#define LPI2C_MCFGR2_BUSIDLE(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR2_BUSIDLE_SHIFT))&LPI2C_MCFGR2_BUSIDLE_MASK)
#define LPI2C_MCFGR2_FILTSCL_MASK                0xF0000u
#define LPI2C_MCFGR2_FILTSCL_SHIFT               16
#define LPI2C_MCFGR2_FILTSCL_WIDTH               4
#define LPI2C_MCFGR2_FILTSCL(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR2_FILTSCL_SHIFT))&LPI2C_MCFGR2_FILTSCL_MASK)
#define LPI2C_MCFGR2_FILTSDA_MASK                0xF000000u
#define LPI2C_MCFGR2_FILTSDA_SHIFT               24
#define LPI2C_MCFGR2_FILTSDA_WIDTH               4
#define LPI2C_MCFGR2_FILTSDA(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR2_FILTSDA_SHIFT))&LPI2C_MCFGR2_FILTSDA_MASK)
/* MCFGR3 Bit Fields */
#define LPI2C_MCFGR3_PINLOW_MASK                 0xFFF00u
#define LPI2C_MCFGR3_PINLOW_SHIFT                8
#define LPI2C_MCFGR3_PINLOW_WIDTH                12
#define LPI2C_MCFGR3_PINLOW(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR3_PINLOW_SHIFT))&LPI2C_MCFGR3_PINLOW_MASK)
/* MDMR Bit Fields */
#define LPI2C_MDMR_MATCH0_MASK                   0xFFu
#define LPI2C_MDMR_MATCH0_SHIFT                  0
#define LPI2C_MDMR_MATCH0_WIDTH                  8
#define LPI2C_MDMR_MATCH0(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MDMR_MATCH0_SHIFT))&LPI2C_MDMR_MATCH0_MASK)
#define LPI2C_MDMR_MATCH1_MASK                   0xFF0000u
#define LPI2C_MDMR_MATCH1_SHIFT                  16
#define LPI2C_MDMR_MATCH1_WIDTH                  8
#define LPI2C_MDMR_MATCH1(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MDMR_MATCH1_SHIFT))&LPI2C_MDMR_MATCH1_MASK)
/* MCCR0 Bit Fields */
#define LPI2C_MCCR0_CLKLO_MASK                   0x3Fu
#define LPI2C_MCCR0_CLKLO_SHIFT                  0
#define LPI2C_MCCR0_CLKLO_WIDTH                  6
#define LPI2C_MCCR0_CLKLO(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR0_CLKLO_SHIFT))&LPI2C_MCCR0_CLKLO_MASK)
#define LPI2C_MCCR0_CLKHI_MASK                   0x3F00u
#define LPI2C_MCCR0_CLKHI_SHIFT                  8
#define LPI2C_MCCR0_CLKHI_WIDTH                  6
#define LPI2C_MCCR0_CLKHI(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR0_CLKHI_SHIFT))&LPI2C_MCCR0_CLKHI_MASK)
#define LPI2C_MCCR0_SETHOLD_MASK                 0x3F0000u
#define LPI2C_MCCR0_SETHOLD_SHIFT                16
#define LPI2C_MCCR0_SETHOLD_WIDTH                6
#define LPI2C_MCCR0_SETHOLD(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR0_SETHOLD_SHIFT))&LPI2C_MCCR0_SETHOLD_MASK)
#define LPI2C_MCCR0_DATAVD_MASK                  0x3F000000u
#define LPI2C_MCCR0_DATAVD_SHIFT                 24
#define LPI2C_MCCR0_DATAVD_WIDTH                 6
#define LPI2C_MCCR0_DATAVD(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR0_DATAVD_SHIFT))&LPI2C_MCCR0_DATAVD_MASK)
/* MCCR1 Bit Fields */
#define LPI2C_MCCR1_CLKLO_MASK                   0x3Fu
#define LPI2C_MCCR1_CLKLO_SHIFT                  0
#define LPI2C_MCCR1_CLKLO_WIDTH                  6
#define LPI2C_MCCR1_CLKLO(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR1_CLKLO_SHIFT))&LPI2C_MCCR1_CLKLO_MASK)
#define LPI2C_MCCR1_CLKHI_MASK                   0x3F00u
#define LPI2C_MCCR1_CLKHI_SHIFT                  8
#define LPI2C_MCCR1_CLKHI_WIDTH                  6
#define LPI2C_MCCR1_CLKHI(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR1_CLKHI_SHIFT))&LPI2C_MCCR1_CLKHI_MASK)
#define LPI2C_MCCR1_SETHOLD_MASK                 0x3F0000u
#define LPI2C_MCCR1_SETHOLD_SHIFT                16
#define LPI2C_MCCR1_SETHOLD_WIDTH                6
#define LPI2C_MCCR1_SETHOLD(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR1_SETHOLD_SHIFT))&LPI2C_MCCR1_SETHOLD_MASK)
#define LPI2C_MCCR1_DATAVD_MASK                  0x3F000000u
#define LPI2C_MCCR1_DATAVD_SHIFT                 24
#define LPI2C_MCCR1_DATAVD_WIDTH                 6
#define LPI2C_MCCR1_DATAVD(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR1_DATAVD_SHIFT))&LPI2C_MCCR1_DATAVD_MASK)
/* MFCR Bit Fields */
#define LPI2C_MFCR_TXWATER_MASK                  0xFFu
#define LPI2C_MFCR_TXWATER_SHIFT                 0
#define LPI2C_MFCR_TXWATER_WIDTH                 8
#define LPI2C_MFCR_TXWATER(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MFCR_TXWATER_SHIFT))&LPI2C_MFCR_TXWATER_MASK)
#define LPI2C_MFCR_RXWATER_MASK                  0xFF0000u
#define LPI2C_MFCR_RXWATER_SHIFT                 16
#define LPI2C_MFCR_RXWATER_WIDTH                 8
#define LPI2C_MFCR_RXWATER(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MFCR_RXWATER_SHIFT))&LPI2C_MFCR_RXWATER_MASK)
/* MFSR Bit Fields */
#define LPI2C_MFSR_TXCOUNT_MASK                  0xFFu
#define LPI2C_MFSR_TXCOUNT_SHIFT                 0
#define LPI2C_MFSR_TXCOUNT_WIDTH                 8
#define LPI2C_MFSR_TXCOUNT(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MFSR_TXCOUNT_SHIFT))&LPI2C_MFSR_TXCOUNT_MASK)
#define LPI2C_MFSR_RXCOUNT_MASK                  0xFF0000u
#define LPI2C_MFSR_RXCOUNT_SHIFT                 16
#define LPI2C_MFSR_RXCOUNT_WIDTH                 8
#define LPI2C_MFSR_RXCOUNT(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MFSR_RXCOUNT_SHIFT))&LPI2C_MFSR_RXCOUNT_MASK)
/* MTDR Bit Fields */
#define LPI2C_MTDR_DATA_MASK                     0xFFu
#define LPI2C_MTDR_DATA_SHIFT                    0
#define LPI2C_MTDR_DATA_WIDTH                    8
#define LPI2C_MTDR_DATA(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MTDR_DATA_SHIFT))&LPI2C_MTDR_DATA_MASK)
#define LPI2C_MTDR_CMD_MASK                      0x700u
#define LPI2C_MTDR_CMD_SHIFT                     8
#define LPI2C_MTDR_CMD_WIDTH                     3
#define LPI2C_MTDR_CMD(x)                        (((uint32_t)(((uint32_t)(x))<<LPI2C_MTDR_CMD_SHIFT))&LPI2C_MTDR_CMD_MASK)
/* MRDR Bit Fields */
#define LPI2C_MRDR_DATA_MASK                     0xFFu
#define LPI2C_MRDR_DATA_SHIFT                    0
#define LPI2C_MRDR_DATA_WIDTH                    8
#define LPI2C_MRDR_DATA(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MRDR_DATA_SHIFT))&LPI2C_MRDR_DATA_MASK)
#define LPI2C_MRDR_RXEMPTY_MASK                  0x4000u
#define LPI2C_MRDR_RXEMPTY_SHIFT                 14
#define LPI2C_MRDR_RXEMPTY_WIDTH                 1
#define LPI2C_MRDR_RXEMPTY(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MRDR_RXEMPTY_SHIFT))&LPI2C_MRDR_RXEMPTY_MASK)
/* SCR Bit Fields */
#define LPI2C_SCR_SEN_MASK                       0x1u
#define LPI2C_SCR_SEN_SHIFT                      0
#define LPI2C_SCR_SEN_WIDTH                      1
#define LPI2C_SCR_SEN(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SCR_SEN_SHIFT))&LPI2C_SCR_SEN_MASK)
#define LPI2C_SCR_RST_MASK                       0x2u
#define LPI2C_SCR_RST_SHIFT                      1
#define LPI2C_SCR_RST_WIDTH                      1
#define LPI2C_SCR_RST(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SCR_RST_SHIFT))&LPI2C_SCR_RST_MASK)
#define LPI2C_SCR_FILTEN_MASK                    0x10u
#define LPI2C_SCR_FILTEN_SHIFT                   4
#define LPI2C_SCR_FILTEN_WIDTH                   1
#define LPI2C_SCR_FILTEN(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_SCR_FILTEN_SHIFT))&LPI2C_SCR_FILTEN_MASK)
#define LPI2C_SCR_FILTDZ_MASK                    0x20u
#define LPI2C_SCR_FILTDZ_SHIFT                   5
#define LPI2C_SCR_FILTDZ_WIDTH                   1
#define LPI2C_SCR_FILTDZ(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_SCR_FILTDZ_SHIFT))&LPI2C_SCR_FILTDZ_MASK)
#define LPI2C_SCR_RTF_MASK                       0x100u
#define LPI2C_SCR_RTF_SHIFT                      8
#define LPI2C_SCR_RTF_WIDTH                      1
#define LPI2C_SCR_RTF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SCR_RTF_SHIFT))&LPI2C_SCR_RTF_MASK)
#define LPI2C_SCR_RRF_MASK                       0x200u
#define LPI2C_SCR_RRF_SHIFT                      9
#define LPI2C_SCR_RRF_WIDTH                      1
#define LPI2C_SCR_RRF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SCR_RRF_SHIFT))&LPI2C_SCR_RRF_MASK)
/* SSR Bit Fields */
#define LPI2C_SSR_TDF_MASK                       0x1u
#define LPI2C_SSR_TDF_SHIFT                      0
#define LPI2C_SSR_TDF_WIDTH                      1
#define LPI2C_SSR_TDF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_TDF_SHIFT))&LPI2C_SSR_TDF_MASK)
#define LPI2C_SSR_RDF_MASK                       0x2u
#define LPI2C_SSR_RDF_SHIFT                      1
#define LPI2C_SSR_RDF_WIDTH                      1
#define LPI2C_SSR_RDF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_RDF_SHIFT))&LPI2C_SSR_RDF_MASK)
#define LPI2C_SSR_AVF_MASK                       0x4u
#define LPI2C_SSR_AVF_SHIFT                      2
#define LPI2C_SSR_AVF_WIDTH                      1
#define LPI2C_SSR_AVF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_AVF_SHIFT))&LPI2C_SSR_AVF_MASK)
#define LPI2C_SSR_TAF_MASK                       0x8u
#define LPI2C_SSR_TAF_SHIFT                      3
#define LPI2C_SSR_TAF_WIDTH                      1
#define LPI2C_SSR_TAF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_TAF_SHIFT))&LPI2C_SSR_TAF_MASK)
#define LPI2C_SSR_RSF_MASK                       0x100u
#define LPI2C_SSR_RSF_SHIFT                      8
#define LPI2C_SSR_RSF_WIDTH                      1
#define LPI2C_SSR_RSF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_RSF_SHIFT))&LPI2C_SSR_RSF_MASK)
#define LPI2C_SSR_SDF_MASK                       0x200u
#define LPI2C_SSR_SDF_SHIFT                      9
#define LPI2C_SSR_SDF_WIDTH                      1
#define LPI2C_SSR_SDF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_SDF_SHIFT))&LPI2C_SSR_SDF_MASK)
#define LPI2C_SSR_BEF_MASK                       0x400u
#define LPI2C_SSR_BEF_SHIFT                      10
#define LPI2C_SSR_BEF_WIDTH                      1
#define LPI2C_SSR_BEF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_BEF_SHIFT))&LPI2C_SSR_BEF_MASK)
#define LPI2C_SSR_FEF_MASK                       0x800u
#define LPI2C_SSR_FEF_SHIFT                      11
#define LPI2C_SSR_FEF_WIDTH                      1
#define LPI2C_SSR_FEF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_FEF_SHIFT))&LPI2C_SSR_FEF_MASK)
#define LPI2C_SSR_AM0F_MASK                      0x1000u
#define LPI2C_SSR_AM0F_SHIFT                     12
#define LPI2C_SSR_AM0F_WIDTH                     1
#define LPI2C_SSR_AM0F(x)                        (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_AM0F_SHIFT))&LPI2C_SSR_AM0F_MASK)
#define LPI2C_SSR_AM1F_MASK                      0x2000u
#define LPI2C_SSR_AM1F_SHIFT                     13
#define LPI2C_SSR_AM1F_WIDTH                     1
#define LPI2C_SSR_AM1F(x)                        (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_AM1F_SHIFT))&LPI2C_SSR_AM1F_MASK)
#define LPI2C_SSR_GCF_MASK                       0x4000u
#define LPI2C_SSR_GCF_SHIFT                      14
#define LPI2C_SSR_GCF_WIDTH                      1
#define LPI2C_SSR_GCF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_GCF_SHIFT))&LPI2C_SSR_GCF_MASK)
#define LPI2C_SSR_SARF_MASK                      0x8000u
#define LPI2C_SSR_SARF_SHIFT                     15
#define LPI2C_SSR_SARF_WIDTH                     1
#define LPI2C_SSR_SARF(x)                        (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_SARF_SHIFT))&LPI2C_SSR_SARF_MASK)
#define LPI2C_SSR_SBF_MASK                       0x1000000u
#define LPI2C_SSR_SBF_SHIFT                      24
#define LPI2C_SSR_SBF_WIDTH                      1
#define LPI2C_SSR_SBF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_SBF_SHIFT))&LPI2C_SSR_SBF_MASK)
#define LPI2C_SSR_BBF_MASK                       0x2000000u
#define LPI2C_SSR_BBF_SHIFT                      25
#define LPI2C_SSR_BBF_WIDTH                      1
#define LPI2C_SSR_BBF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_BBF_SHIFT))&LPI2C_SSR_BBF_MASK)
/* SIER Bit Fields */
#define LPI2C_SIER_TDIE_MASK                     0x1u
#define LPI2C_SIER_TDIE_SHIFT                    0
#define LPI2C_SIER_TDIE_WIDTH                    1
#define LPI2C_SIER_TDIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_TDIE_SHIFT))&LPI2C_SIER_TDIE_MASK)
#define LPI2C_SIER_RDIE_MASK                     0x2u
#define LPI2C_SIER_RDIE_SHIFT                    1
#define LPI2C_SIER_RDIE_WIDTH                    1
#define LPI2C_SIER_RDIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_RDIE_SHIFT))&LPI2C_SIER_RDIE_MASK)
#define LPI2C_SIER_AVIE_MASK                     0x4u
#define LPI2C_SIER_AVIE_SHIFT                    2
#define LPI2C_SIER_AVIE_WIDTH                    1
#define LPI2C_SIER_AVIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_AVIE_SHIFT))&LPI2C_SIER_AVIE_MASK)
#define LPI2C_SIER_TAIE_MASK                     0x8u
#define LPI2C_SIER_TAIE_SHIFT                    3
#define LPI2C_SIER_TAIE_WIDTH                    1
#define LPI2C_SIER_TAIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_TAIE_SHIFT))&LPI2C_SIER_TAIE_MASK)
#define LPI2C_SIER_RSIE_MASK                     0x100u
#define LPI2C_SIER_RSIE_SHIFT                    8
#define LPI2C_SIER_RSIE_WIDTH                    1
#define LPI2C_SIER_RSIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_RSIE_SHIFT))&LPI2C_SIER_RSIE_MASK)
#define LPI2C_SIER_SDIE_MASK                     0x200u
#define LPI2C_SIER_SDIE_SHIFT                    9
#define LPI2C_SIER_SDIE_WIDTH                    1
#define LPI2C_SIER_SDIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_SDIE_SHIFT))&LPI2C_SIER_SDIE_MASK)
#define LPI2C_SIER_BEIE_MASK                     0x400u
#define LPI2C_SIER_BEIE_SHIFT                    10
#define LPI2C_SIER_BEIE_WIDTH                    1
#define LPI2C_SIER_BEIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_BEIE_SHIFT))&LPI2C_SIER_BEIE_MASK)
#define LPI2C_SIER_FEIE_MASK                     0x800u
#define LPI2C_SIER_FEIE_SHIFT                    11
#define LPI2C_SIER_FEIE_WIDTH                    1
#define LPI2C_SIER_FEIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_FEIE_SHIFT))&LPI2C_SIER_FEIE_MASK)
#define LPI2C_SIER_AM0IE_MASK                    0x1000u
#define LPI2C_SIER_AM0IE_SHIFT                   12
#define LPI2C_SIER_AM0IE_WIDTH                   1
#define LPI2C_SIER_AM0IE(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_AM0IE_SHIFT))&LPI2C_SIER_AM0IE_MASK)
#define LPI2C_SIER_AM1F_MASK                     0x2000u
#define LPI2C_SIER_AM1F_SHIFT                    13
#define LPI2C_SIER_AM1F_WIDTH                    1
#define LPI2C_SIER_AM1F(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_AM1F_SHIFT))&LPI2C_SIER_AM1F_MASK)
#define LPI2C_SIER_GCIE_MASK                     0x4000u
#define LPI2C_SIER_GCIE_SHIFT                    14
#define LPI2C_SIER_GCIE_WIDTH                    1
#define LPI2C_SIER_GCIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_GCIE_SHIFT))&LPI2C_SIER_GCIE_MASK)
#define LPI2C_SIER_SARIE_MASK                    0x8000u
#define LPI2C_SIER_SARIE_SHIFT                   15
#define LPI2C_SIER_SARIE_WIDTH                   1
#define LPI2C_SIER_SARIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_SARIE_SHIFT))&LPI2C_SIER_SARIE_MASK)
/* SDER Bit Fields */
#define LPI2C_SDER_TDDE_MASK                     0x1u
#define LPI2C_SDER_TDDE_SHIFT                    0
#define LPI2C_SDER_TDDE_WIDTH                    1
#define LPI2C_SDER_TDDE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SDER_TDDE_SHIFT))&LPI2C_SDER_TDDE_MASK)
#define LPI2C_SDER_RDDE_MASK                     0x2u
#define LPI2C_SDER_RDDE_SHIFT                    1
#define LPI2C_SDER_RDDE_WIDTH                    1
#define LPI2C_SDER_RDDE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SDER_RDDE_SHIFT))&LPI2C_SDER_RDDE_MASK)
#define LPI2C_SDER_AVDE_MASK                     0x4u
#define LPI2C_SDER_AVDE_SHIFT                    2
#define LPI2C_SDER_AVDE_WIDTH                    1
#define LPI2C_SDER_AVDE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SDER_AVDE_SHIFT))&LPI2C_SDER_AVDE_MASK)
/* SCFGR1 Bit Fields */
#define LPI2C_SCFGR1_ADRSTALL_MASK               0x1u
#define LPI2C_SCFGR1_ADRSTALL_SHIFT              0
#define LPI2C_SCFGR1_ADRSTALL_WIDTH              1
#define LPI2C_SCFGR1_ADRSTALL(x)                 (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_ADRSTALL_SHIFT))&LPI2C_SCFGR1_ADRSTALL_MASK)
#define LPI2C_SCFGR1_RXSTALL_MASK                0x2u
#define LPI2C_SCFGR1_RXSTALL_SHIFT               1
#define LPI2C_SCFGR1_RXSTALL_WIDTH               1
#define LPI2C_SCFGR1_RXSTALL(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_RXSTALL_SHIFT))&LPI2C_SCFGR1_RXSTALL_MASK)
#define LPI2C_SCFGR1_TXDSTALL_MASK               0x4u
#define LPI2C_SCFGR1_TXDSTALL_SHIFT              2
#define LPI2C_SCFGR1_TXDSTALL_WIDTH              1
#define LPI2C_SCFGR1_TXDSTALL(x)                 (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_TXDSTALL_SHIFT))&LPI2C_SCFGR1_TXDSTALL_MASK)
#define LPI2C_SCFGR1_ACKSTALL_MASK               0x8u
#define LPI2C_SCFGR1_ACKSTALL_SHIFT              3
#define LPI2C_SCFGR1_ACKSTALL_WIDTH              1
#define LPI2C_SCFGR1_ACKSTALL(x)                 (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_ACKSTALL_SHIFT))&LPI2C_SCFGR1_ACKSTALL_MASK)
#define LPI2C_SCFGR1_GCEN_MASK                   0x100u
#define LPI2C_SCFGR1_GCEN_SHIFT                  8
#define LPI2C_SCFGR1_GCEN_WIDTH                  1
#define LPI2C_SCFGR1_GCEN(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_GCEN_SHIFT))&LPI2C_SCFGR1_GCEN_MASK)
#define LPI2C_SCFGR1_SAEN_MASK                   0x200u
#define LPI2C_SCFGR1_SAEN_SHIFT                  9
#define LPI2C_SCFGR1_SAEN_WIDTH                  1
#define LPI2C_SCFGR1_SAEN(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_SAEN_SHIFT))&LPI2C_SCFGR1_SAEN_MASK)
#define LPI2C_SCFGR1_TXCFG_MASK                  0x400u
#define LPI2C_SCFGR1_TXCFG_SHIFT                 10
#define LPI2C_SCFGR1_TXCFG_WIDTH                 1
#define LPI2C_SCFGR1_TXCFG(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_TXCFG_SHIFT))&LPI2C_SCFGR1_TXCFG_MASK)
#define LPI2C_SCFGR1_RXCFG_MASK                  0x800u
#define LPI2C_SCFGR1_RXCFG_SHIFT                 11
#define LPI2C_SCFGR1_RXCFG_WIDTH                 1
#define LPI2C_SCFGR1_RXCFG(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_RXCFG_SHIFT))&LPI2C_SCFGR1_RXCFG_MASK)
#define LPI2C_SCFGR1_IGNACK_MASK                 0x1000u
#define LPI2C_SCFGR1_IGNACK_SHIFT                12
#define LPI2C_SCFGR1_IGNACK_WIDTH                1
#define LPI2C_SCFGR1_IGNACK(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_IGNACK_SHIFT))&LPI2C_SCFGR1_IGNACK_MASK)
#define LPI2C_SCFGR1_HSMEN_MASK                  0x2000u
#define LPI2C_SCFGR1_HSMEN_SHIFT                 13
#define LPI2C_SCFGR1_HSMEN_WIDTH                 1
#define LPI2C_SCFGR1_HSMEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_HSMEN_SHIFT))&LPI2C_SCFGR1_HSMEN_MASK)
#define LPI2C_SCFGR1_ADDRCFG_MASK                0x70000u
#define LPI2C_SCFGR1_ADDRCFG_SHIFT               16
#define LPI2C_SCFGR1_ADDRCFG_WIDTH               3
#define LPI2C_SCFGR1_ADDRCFG(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_ADDRCFG_SHIFT))&LPI2C_SCFGR1_ADDRCFG_MASK)
/* SCFGR2 Bit Fields */
#define LPI2C_SCFGR2_CLKHOLD_MASK                0xFu
#define LPI2C_SCFGR2_CLKHOLD_SHIFT               0
#define LPI2C_SCFGR2_CLKHOLD_WIDTH               4
#define LPI2C_SCFGR2_CLKHOLD(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR2_CLKHOLD_SHIFT))&LPI2C_SCFGR2_CLKHOLD_MASK)
#define LPI2C_SCFGR2_DATAVD_MASK                 0x3F00u
#define LPI2C_SCFGR2_DATAVD_SHIFT                8
#define LPI2C_SCFGR2_DATAVD_WIDTH                6
#define LPI2C_SCFGR2_DATAVD(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR2_DATAVD_SHIFT))&LPI2C_SCFGR2_DATAVD_MASK)
#define LPI2C_SCFGR2_FILTSCL_MASK                0xF0000u
#define LPI2C_SCFGR2_FILTSCL_SHIFT               16
#define LPI2C_SCFGR2_FILTSCL_WIDTH               4
#define LPI2C_SCFGR2_FILTSCL(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR2_FILTSCL_SHIFT))&LPI2C_SCFGR2_FILTSCL_MASK)
#define LPI2C_SCFGR2_FILTSDA_MASK                0xF000000u
#define LPI2C_SCFGR2_FILTSDA_SHIFT               24
#define LPI2C_SCFGR2_FILTSDA_WIDTH               4
#define LPI2C_SCFGR2_FILTSDA(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR2_FILTSDA_SHIFT))&LPI2C_SCFGR2_FILTSDA_MASK)
/* SAMR Bit Fields */
#define LPI2C_SAMR_ADDR0_MASK                    0x7FEu
#define LPI2C_SAMR_ADDR0_SHIFT                   1
#define LPI2C_SAMR_ADDR0_WIDTH                   10
#define LPI2C_SAMR_ADDR0(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_SAMR_ADDR0_SHIFT))&LPI2C_SAMR_ADDR0_MASK)
#define LPI2C_SAMR_ADDR1_MASK                    0x7FE0000u
#define LPI2C_SAMR_ADDR1_SHIFT                   17
#define LPI2C_SAMR_ADDR1_WIDTH                   10
#define LPI2C_SAMR_ADDR1(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_SAMR_ADDR1_SHIFT))&LPI2C_SAMR_ADDR1_MASK)
/* SASR Bit Fields */
#define LPI2C_SASR_RADDR_MASK                    0x7FFu
#define LPI2C_SASR_RADDR_SHIFT                   0
#define LPI2C_SASR_RADDR_WIDTH                   11
#define LPI2C_SASR_RADDR(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_SASR_RADDR_SHIFT))&LPI2C_SASR_RADDR_MASK)
#define LPI2C_SASR_ANV_MASK                      0x4000u
#define LPI2C_SASR_ANV_SHIFT                     14
#define LPI2C_SASR_ANV_WIDTH                     1
#define LPI2C_SASR_ANV(x)                        (((uint32_t)(((uint32_t)(x))<<LPI2C_SASR_ANV_SHIFT))&LPI2C_SASR_ANV_MASK)
/* STAR Bit Fields */
#define LPI2C_STAR_TXNACK_MASK                   0x1u
#define LPI2C_STAR_TXNACK_SHIFT                  0
#define LPI2C_STAR_TXNACK_WIDTH                  1
#define LPI2C_STAR_TXNACK(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_STAR_TXNACK_SHIFT))&LPI2C_STAR_TXNACK_MASK)
/* STDR Bit Fields */
#define LPI2C_STDR_DATA_MASK                     0xFFu
#define LPI2C_STDR_DATA_SHIFT                    0
#define LPI2C_STDR_DATA_WIDTH                    8
#define LPI2C_STDR_DATA(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_STDR_DATA_SHIFT))&LPI2C_STDR_DATA_MASK)
/* SRDR Bit Fields */
#define LPI2C_SRDR_DATA_MASK                     0xFFu
#define LPI2C_SRDR_DATA_SHIFT                    0
#define LPI2C_SRDR_DATA_WIDTH                    8
#define LPI2C_SRDR_DATA(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SRDR_DATA_SHIFT))&LPI2C_SRDR_DATA_MASK)
#define LPI2C_SRDR_RXEMPTY_MASK                  0x4000u
#define LPI2C_SRDR_RXEMPTY_SHIFT                 14
#define LPI2C_SRDR_RXEMPTY_WIDTH                 1
#define LPI2C_SRDR_RXEMPTY(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_SRDR_RXEMPTY_SHIFT))&LPI2C_SRDR_RXEMPTY_MASK)
#define LPI2C_SRDR_SOF_MASK                      0x8000u
#define LPI2C_SRDR_SOF_SHIFT                     15
#define LPI2C_SRDR_SOF_WIDTH                     1
#define LPI2C_SRDR_SOF(x)                        (((uint32_t)(((uint32_t)(x))<<LPI2C_SRDR_SOF_SHIFT))&LPI2C_SRDR_SOF_MASK)

/*!
 * @}
 */ /* end of group LPI2C_Register_Masks */


/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              (0x400C0000u)
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
#define LPI2C0_BASE_PTR                          (LPI2C0)
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0x400C1000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
#define LPI2C1_BASE_PTR                          (LPI2C1)
/** Peripheral LPI2C2 base address */
#define LPI2C2_BASE                              (0x40042000u)
/** Peripheral LPI2C2 base pointer */
#define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
#define LPI2C2_BASE_PTR                          (LPI2C2)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, LPI2C2_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, LPI2C2 }

/* ----------------------------------------------------------------------------
   -- LPI2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPI2C_Register_Accessor_Macros LPI2C - Register accessor macros
 * @{
 */


/* LPI2C - Register instance definitions */
/* LPI2C0 */
#define LPI2C0_VERID                             LPI2C_VERID_REG(LPI2C0)
#define LPI2C0_PARAM                             LPI2C_PARAM_REG(LPI2C0)
#define LPI2C0_MCR                               LPI2C_MCR_REG(LPI2C0)
#define LPI2C0_MSR                               LPI2C_MSR_REG(LPI2C0)
#define LPI2C0_MIER                              LPI2C_MIER_REG(LPI2C0)
#define LPI2C0_MDER                              LPI2C_MDER_REG(LPI2C0)
#define LPI2C0_MCFGR0                            LPI2C_MCFGR0_REG(LPI2C0)
#define LPI2C0_MCFGR1                            LPI2C_MCFGR1_REG(LPI2C0)
#define LPI2C0_MCFGR2                            LPI2C_MCFGR2_REG(LPI2C0)
#define LPI2C0_MCFGR3                            LPI2C_MCFGR3_REG(LPI2C0)
#define LPI2C0_MDMR                              LPI2C_MDMR_REG(LPI2C0)
#define LPI2C0_MCCR0                             LPI2C_MCCR0_REG(LPI2C0)
#define LPI2C0_MCCR1                             LPI2C_MCCR1_REG(LPI2C0)
#define LPI2C0_MFCR                              LPI2C_MFCR_REG(LPI2C0)
#define LPI2C0_MFSR                              LPI2C_MFSR_REG(LPI2C0)
#define LPI2C0_MTDR                              LPI2C_MTDR_REG(LPI2C0)
#define LPI2C0_MRDR                              LPI2C_MRDR_REG(LPI2C0)
#define LPI2C0_SCR                               LPI2C_SCR_REG(LPI2C0)
#define LPI2C0_SSR                               LPI2C_SSR_REG(LPI2C0)
#define LPI2C0_SIER                              LPI2C_SIER_REG(LPI2C0)
#define LPI2C0_SDER                              LPI2C_SDER_REG(LPI2C0)
#define LPI2C0_SCFGR1                            LPI2C_SCFGR1_REG(LPI2C0)
#define LPI2C0_SCFGR2                            LPI2C_SCFGR2_REG(LPI2C0)
#define LPI2C0_SAMR                              LPI2C_SAMR_REG(LPI2C0)
#define LPI2C0_SASR                              LPI2C_SASR_REG(LPI2C0)
#define LPI2C0_STAR                              LPI2C_STAR_REG(LPI2C0)
#define LPI2C0_STDR                              LPI2C_STDR_REG(LPI2C0)
#define LPI2C0_SRDR                              LPI2C_SRDR_REG(LPI2C0)
/* LPI2C1 */
#define LPI2C1_VERID                             LPI2C_VERID_REG(LPI2C1)
#define LPI2C1_PARAM                             LPI2C_PARAM_REG(LPI2C1)
#define LPI2C1_MCR                               LPI2C_MCR_REG(LPI2C1)
#define LPI2C1_MSR                               LPI2C_MSR_REG(LPI2C1)
#define LPI2C1_MIER                              LPI2C_MIER_REG(LPI2C1)
#define LPI2C1_MDER                              LPI2C_MDER_REG(LPI2C1)
#define LPI2C1_MCFGR0                            LPI2C_MCFGR0_REG(LPI2C1)
#define LPI2C1_MCFGR1                            LPI2C_MCFGR1_REG(LPI2C1)
#define LPI2C1_MCFGR2                            LPI2C_MCFGR2_REG(LPI2C1)
#define LPI2C1_MCFGR3                            LPI2C_MCFGR3_REG(LPI2C1)
#define LPI2C1_MDMR                              LPI2C_MDMR_REG(LPI2C1)
#define LPI2C1_MCCR0                             LPI2C_MCCR0_REG(LPI2C1)
#define LPI2C1_MCCR1                             LPI2C_MCCR1_REG(LPI2C1)
#define LPI2C1_MFCR                              LPI2C_MFCR_REG(LPI2C1)
#define LPI2C1_MFSR                              LPI2C_MFSR_REG(LPI2C1)
#define LPI2C1_MTDR                              LPI2C_MTDR_REG(LPI2C1)
#define LPI2C1_MRDR                              LPI2C_MRDR_REG(LPI2C1)
#define LPI2C1_SCR                               LPI2C_SCR_REG(LPI2C1)
#define LPI2C1_SSR                               LPI2C_SSR_REG(LPI2C1)
#define LPI2C1_SIER                              LPI2C_SIER_REG(LPI2C1)
#define LPI2C1_SDER                              LPI2C_SDER_REG(LPI2C1)
#define LPI2C1_SCFGR1                            LPI2C_SCFGR1_REG(LPI2C1)
#define LPI2C1_SCFGR2                            LPI2C_SCFGR2_REG(LPI2C1)
#define LPI2C1_SAMR                              LPI2C_SAMR_REG(LPI2C1)
#define LPI2C1_SASR                              LPI2C_SASR_REG(LPI2C1)
#define LPI2C1_STAR                              LPI2C_STAR_REG(LPI2C1)
#define LPI2C1_STDR                              LPI2C_STDR_REG(LPI2C1)
#define LPI2C1_SRDR                              LPI2C_SRDR_REG(LPI2C1)
/* LPI2C2 */
#define LPI2C2_VERID                             LPI2C_VERID_REG(LPI2C2)
#define LPI2C2_PARAM                             LPI2C_PARAM_REG(LPI2C2)
#define LPI2C2_MCR                               LPI2C_MCR_REG(LPI2C2)
#define LPI2C2_MSR                               LPI2C_MSR_REG(LPI2C2)
#define LPI2C2_MIER                              LPI2C_MIER_REG(LPI2C2)
#define LPI2C2_MDER                              LPI2C_MDER_REG(LPI2C2)
#define LPI2C2_MCFGR0                            LPI2C_MCFGR0_REG(LPI2C2)
#define LPI2C2_MCFGR1                            LPI2C_MCFGR1_REG(LPI2C2)
#define LPI2C2_MCFGR2                            LPI2C_MCFGR2_REG(LPI2C2)
#define LPI2C2_MCFGR3                            LPI2C_MCFGR3_REG(LPI2C2)
#define LPI2C2_MDMR                              LPI2C_MDMR_REG(LPI2C2)
#define LPI2C2_MCCR0                             LPI2C_MCCR0_REG(LPI2C2)
#define LPI2C2_MCCR1                             LPI2C_MCCR1_REG(LPI2C2)
#define LPI2C2_MFCR                              LPI2C_MFCR_REG(LPI2C2)
#define LPI2C2_MFSR                              LPI2C_MFSR_REG(LPI2C2)
#define LPI2C2_MTDR                              LPI2C_MTDR_REG(LPI2C2)
#define LPI2C2_MRDR                              LPI2C_MRDR_REG(LPI2C2)
#define LPI2C2_SCR                               LPI2C_SCR_REG(LPI2C2)
#define LPI2C2_SSR                               LPI2C_SSR_REG(LPI2C2)
#define LPI2C2_SIER                              LPI2C_SIER_REG(LPI2C2)
#define LPI2C2_SDER                              LPI2C_SDER_REG(LPI2C2)
#define LPI2C2_SCFGR1                            LPI2C_SCFGR1_REG(LPI2C2)
#define LPI2C2_SCFGR2                            LPI2C_SCFGR2_REG(LPI2C2)
#define LPI2C2_SAMR                              LPI2C_SAMR_REG(LPI2C2)
#define LPI2C2_SASR                              LPI2C_SASR_REG(LPI2C2)
#define LPI2C2_STAR                              LPI2C_STAR_REG(LPI2C2)
#define LPI2C2_STDR                              LPI2C_STDR_REG(LPI2C2)
#define LPI2C2_SRDR                              LPI2C_SRDR_REG(LPI2C2)

/*!
 * @}
 */ /* end of group LPI2C_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group LPI2C_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPIT_Peripheral_Access_Layer LPIT Peripheral Access Layer
 * @{
 */

/** LPIT - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t MCR;                               /**< Module Control Register, offset: 0x8 */
  __IO uint32_t MSR;                               /**< Module Status Register, offset: 0xC */
  __IO uint32_t MIER;                              /**< Module Interrupt Enable Register, offset: 0x10 */
  __IO uint32_t SETTEN;                            /**< Set Timer Enable Register, offset: 0x14 */
  __IO uint32_t CLRTEN;                            /**< Clear Timer Enable Register, offset: 0x18 */
       uint8_t RESERVED_0[4];
  struct {                                         /* offset: 0x20, array step: 0x10 */
    __IO uint32_t TVAL;                              /**< Timer Value Register, array offset: 0x20, array step: 0x10 */
    __I  uint32_t CVAL;                              /**< Current Timer Value, array offset: 0x24, array step: 0x10 */
    __IO uint32_t TCTRL;                             /**< Timer Control Register, array offset: 0x28, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } CHANNEL[4];
} LPIT_Type, *LPIT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LPIT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPIT_Register_Accessor_Macros LPIT - Register accessor macros
 * @{
 */


/* LPIT - Register accessors */
#define LPIT_VERID_REG(base)                     ((base)->VERID)
#define LPIT_PARAM_REG(base)                     ((base)->PARAM)
#define LPIT_MCR_REG(base)                       ((base)->MCR)
#define LPIT_MSR_REG(base)                       ((base)->MSR)
#define LPIT_MIER_REG(base)                      ((base)->MIER)
#define LPIT_SETTEN_REG(base)                    ((base)->SETTEN)
#define LPIT_CLRTEN_REG(base)                    ((base)->CLRTEN)
#define LPIT_TVAL_REG(base,index)                ((base)->CHANNEL[index].TVAL)
#define LPIT_TVAL_COUNT                          4
#define LPIT_CVAL_REG(base,index)                ((base)->CHANNEL[index].CVAL)
#define LPIT_CVAL_COUNT                          4
#define LPIT_TCTRL_REG(base,index)               ((base)->CHANNEL[index].TCTRL)
#define LPIT_TCTRL_COUNT                         4

/*!
 * @}
 */ /* end of group LPIT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LPIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPIT_Register_Masks LPIT Register Masks
 * @{
 */

/* VERID Bit Fields */
#define LPIT_VERID_FEATURE_MASK                  0xFFFFu
#define LPIT_VERID_FEATURE_SHIFT                 0
#define LPIT_VERID_FEATURE_WIDTH                 16
#define LPIT_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x))<<LPIT_VERID_FEATURE_SHIFT))&LPIT_VERID_FEATURE_MASK)
#define LPIT_VERID_MINOR_MASK                    0xFF0000u
#define LPIT_VERID_MINOR_SHIFT                   16
#define LPIT_VERID_MINOR_WIDTH                   8
#define LPIT_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x))<<LPIT_VERID_MINOR_SHIFT))&LPIT_VERID_MINOR_MASK)
#define LPIT_VERID_MAJOR_MASK                    0xFF000000u
#define LPIT_VERID_MAJOR_SHIFT                   24
#define LPIT_VERID_MAJOR_WIDTH                   8
#define LPIT_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x))<<LPIT_VERID_MAJOR_SHIFT))&LPIT_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define LPIT_PARAM_CHANNEL_MASK                  0xFFu
#define LPIT_PARAM_CHANNEL_SHIFT                 0
#define LPIT_PARAM_CHANNEL_WIDTH                 8
#define LPIT_PARAM_CHANNEL(x)                    (((uint32_t)(((uint32_t)(x))<<LPIT_PARAM_CHANNEL_SHIFT))&LPIT_PARAM_CHANNEL_MASK)
#define LPIT_PARAM_EXT_TRIG_MASK                 0xFF00u
#define LPIT_PARAM_EXT_TRIG_SHIFT                8
#define LPIT_PARAM_EXT_TRIG_WIDTH                8
#define LPIT_PARAM_EXT_TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<LPIT_PARAM_EXT_TRIG_SHIFT))&LPIT_PARAM_EXT_TRIG_MASK)
/* MCR Bit Fields */
#define LPIT_MCR_M_CEN_MASK                      0x1u
#define LPIT_MCR_M_CEN_SHIFT                     0
#define LPIT_MCR_M_CEN_WIDTH                     1
#define LPIT_MCR_M_CEN(x)                        (((uint32_t)(((uint32_t)(x))<<LPIT_MCR_M_CEN_SHIFT))&LPIT_MCR_M_CEN_MASK)
#define LPIT_MCR_SW_RST_MASK                     0x2u
#define LPIT_MCR_SW_RST_SHIFT                    1
#define LPIT_MCR_SW_RST_WIDTH                    1
#define LPIT_MCR_SW_RST(x)                       (((uint32_t)(((uint32_t)(x))<<LPIT_MCR_SW_RST_SHIFT))&LPIT_MCR_SW_RST_MASK)
#define LPIT_MCR_DOZE_EN_MASK                    0x4u
#define LPIT_MCR_DOZE_EN_SHIFT                   2
#define LPIT_MCR_DOZE_EN_WIDTH                   1
#define LPIT_MCR_DOZE_EN(x)                      (((uint32_t)(((uint32_t)(x))<<LPIT_MCR_DOZE_EN_SHIFT))&LPIT_MCR_DOZE_EN_MASK)
#define LPIT_MCR_DBG_EN_MASK                     0x8u
#define LPIT_MCR_DBG_EN_SHIFT                    3
#define LPIT_MCR_DBG_EN_WIDTH                    1
#define LPIT_MCR_DBG_EN(x)                       (((uint32_t)(((uint32_t)(x))<<LPIT_MCR_DBG_EN_SHIFT))&LPIT_MCR_DBG_EN_MASK)
/* MSR Bit Fields */
#define LPIT_MSR_TIF0_MASK                       0x1u
#define LPIT_MSR_TIF0_SHIFT                      0
#define LPIT_MSR_TIF0_WIDTH                      1
#define LPIT_MSR_TIF0(x)                         (((uint32_t)(((uint32_t)(x))<<LPIT_MSR_TIF0_SHIFT))&LPIT_MSR_TIF0_MASK)
#define LPIT_MSR_TIF1_MASK                       0x2u
#define LPIT_MSR_TIF1_SHIFT                      1
#define LPIT_MSR_TIF1_WIDTH                      1
#define LPIT_MSR_TIF1(x)                         (((uint32_t)(((uint32_t)(x))<<LPIT_MSR_TIF1_SHIFT))&LPIT_MSR_TIF1_MASK)
#define LPIT_MSR_TIF2_MASK                       0x4u
#define LPIT_MSR_TIF2_SHIFT                      2
#define LPIT_MSR_TIF2_WIDTH                      1
#define LPIT_MSR_TIF2(x)                         (((uint32_t)(((uint32_t)(x))<<LPIT_MSR_TIF2_SHIFT))&LPIT_MSR_TIF2_MASK)
#define LPIT_MSR_TIF3_MASK                       0x8u
#define LPIT_MSR_TIF3_SHIFT                      3
#define LPIT_MSR_TIF3_WIDTH                      1
#define LPIT_MSR_TIF3(x)                         (((uint32_t)(((uint32_t)(x))<<LPIT_MSR_TIF3_SHIFT))&LPIT_MSR_TIF3_MASK)
/* MIER Bit Fields */
#define LPIT_MIER_TIE0_MASK                      0x1u
#define LPIT_MIER_TIE0_SHIFT                     0
#define LPIT_MIER_TIE0_WIDTH                     1
#define LPIT_MIER_TIE0(x)                        (((uint32_t)(((uint32_t)(x))<<LPIT_MIER_TIE0_SHIFT))&LPIT_MIER_TIE0_MASK)
#define LPIT_MIER_TIE1_MASK                      0x2u
#define LPIT_MIER_TIE1_SHIFT                     1
#define LPIT_MIER_TIE1_WIDTH                     1
#define LPIT_MIER_TIE1(x)                        (((uint32_t)(((uint32_t)(x))<<LPIT_MIER_TIE1_SHIFT))&LPIT_MIER_TIE1_MASK)
#define LPIT_MIER_TIE2_MASK                      0x4u
#define LPIT_MIER_TIE2_SHIFT                     2
#define LPIT_MIER_TIE2_WIDTH                     1
#define LPIT_MIER_TIE2(x)                        (((uint32_t)(((uint32_t)(x))<<LPIT_MIER_TIE2_SHIFT))&LPIT_MIER_TIE2_MASK)
#define LPIT_MIER_TIE3_MASK                      0x8u
#define LPIT_MIER_TIE3_SHIFT                     3
#define LPIT_MIER_TIE3_WIDTH                     1
#define LPIT_MIER_TIE3(x)                        (((uint32_t)(((uint32_t)(x))<<LPIT_MIER_TIE3_SHIFT))&LPIT_MIER_TIE3_MASK)
/* SETTEN Bit Fields */
#define LPIT_SETTEN_SET_T_EN_0_MASK              0x1u
#define LPIT_SETTEN_SET_T_EN_0_SHIFT             0
#define LPIT_SETTEN_SET_T_EN_0_WIDTH             1
#define LPIT_SETTEN_SET_T_EN_0(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_SETTEN_SET_T_EN_0_SHIFT))&LPIT_SETTEN_SET_T_EN_0_MASK)
#define LPIT_SETTEN_SET_T_EN_1_MASK              0x2u
#define LPIT_SETTEN_SET_T_EN_1_SHIFT             1
#define LPIT_SETTEN_SET_T_EN_1_WIDTH             1
#define LPIT_SETTEN_SET_T_EN_1(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_SETTEN_SET_T_EN_1_SHIFT))&LPIT_SETTEN_SET_T_EN_1_MASK)
#define LPIT_SETTEN_SET_T_EN_2_MASK              0x4u
#define LPIT_SETTEN_SET_T_EN_2_SHIFT             2
#define LPIT_SETTEN_SET_T_EN_2_WIDTH             1
#define LPIT_SETTEN_SET_T_EN_2(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_SETTEN_SET_T_EN_2_SHIFT))&LPIT_SETTEN_SET_T_EN_2_MASK)
#define LPIT_SETTEN_SET_T_EN_3_MASK              0x8u
#define LPIT_SETTEN_SET_T_EN_3_SHIFT             3
#define LPIT_SETTEN_SET_T_EN_3_WIDTH             1
#define LPIT_SETTEN_SET_T_EN_3(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_SETTEN_SET_T_EN_3_SHIFT))&LPIT_SETTEN_SET_T_EN_3_MASK)
/* CLRTEN Bit Fields */
#define LPIT_CLRTEN_CLR_T_EN_0_MASK              0x1u
#define LPIT_CLRTEN_CLR_T_EN_0_SHIFT             0
#define LPIT_CLRTEN_CLR_T_EN_0_WIDTH             1
#define LPIT_CLRTEN_CLR_T_EN_0(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_CLRTEN_CLR_T_EN_0_SHIFT))&LPIT_CLRTEN_CLR_T_EN_0_MASK)
#define LPIT_CLRTEN_CLR_T_EN_1_MASK              0x2u
#define LPIT_CLRTEN_CLR_T_EN_1_SHIFT             1
#define LPIT_CLRTEN_CLR_T_EN_1_WIDTH             1
#define LPIT_CLRTEN_CLR_T_EN_1(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_CLRTEN_CLR_T_EN_1_SHIFT))&LPIT_CLRTEN_CLR_T_EN_1_MASK)
#define LPIT_CLRTEN_CLR_T_EN_2_MASK              0x4u
#define LPIT_CLRTEN_CLR_T_EN_2_SHIFT             2
#define LPIT_CLRTEN_CLR_T_EN_2_WIDTH             1
#define LPIT_CLRTEN_CLR_T_EN_2(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_CLRTEN_CLR_T_EN_2_SHIFT))&LPIT_CLRTEN_CLR_T_EN_2_MASK)
#define LPIT_CLRTEN_CLR_T_EN_3_MASK              0x8u
#define LPIT_CLRTEN_CLR_T_EN_3_SHIFT             3
#define LPIT_CLRTEN_CLR_T_EN_3_WIDTH             1
#define LPIT_CLRTEN_CLR_T_EN_3(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_CLRTEN_CLR_T_EN_3_SHIFT))&LPIT_CLRTEN_CLR_T_EN_3_MASK)
/* TVAL Bit Fields */
#define LPIT_TVAL_TMR_VAL_MASK                   0xFFFFFFFFu
#define LPIT_TVAL_TMR_VAL_SHIFT                  0
#define LPIT_TVAL_TMR_VAL_WIDTH                  32
#define LPIT_TVAL_TMR_VAL(x)                     (((uint32_t)(((uint32_t)(x))<<LPIT_TVAL_TMR_VAL_SHIFT))&LPIT_TVAL_TMR_VAL_MASK)
/* CVAL Bit Fields */
#define LPIT_CVAL_TMR_CUR_VAL_MASK               0xFFFFFFFFu
#define LPIT_CVAL_TMR_CUR_VAL_SHIFT              0
#define LPIT_CVAL_TMR_CUR_VAL_WIDTH              32
#define LPIT_CVAL_TMR_CUR_VAL(x)                 (((uint32_t)(((uint32_t)(x))<<LPIT_CVAL_TMR_CUR_VAL_SHIFT))&LPIT_CVAL_TMR_CUR_VAL_MASK)
/* TCTRL Bit Fields */
#define LPIT_TCTRL_T_EN_MASK                     0x1u
#define LPIT_TCTRL_T_EN_SHIFT                    0
#define LPIT_TCTRL_T_EN_WIDTH                    1
#define LPIT_TCTRL_T_EN(x)                       (((uint32_t)(((uint32_t)(x))<<LPIT_TCTRL_T_EN_SHIFT))&LPIT_TCTRL_T_EN_MASK)
#define LPIT_TCTRL_CHAIN_MASK                    0x2u
#define LPIT_TCTRL_CHAIN_SHIFT                   1
#define LPIT_TCTRL_CHAIN_WIDTH                   1
#define LPIT_TCTRL_CHAIN(x)                      (((uint32_t)(((uint32_t)(x))<<LPIT_TCTRL_CHAIN_SHIFT))&LPIT_TCTRL_CHAIN_MASK)
#define LPIT_TCTRL_MODE_MASK                     0xCu
#define LPIT_TCTRL_MODE_SHIFT                    2
#define LPIT_TCTRL_MODE_WIDTH                    2
#define LPIT_TCTRL_MODE(x)                       (((uint32_t)(((uint32_t)(x))<<LPIT_TCTRL_MODE_SHIFT))&LPIT_TCTRL_MODE_MASK)
#define LPIT_TCTRL_TSOT_MASK                     0x10000u
#define LPIT_TCTRL_TSOT_SHIFT                    16
#define LPIT_TCTRL_TSOT_WIDTH                    1
#define LPIT_TCTRL_TSOT(x)                       (((uint32_t)(((uint32_t)(x))<<LPIT_TCTRL_TSOT_SHIFT))&LPIT_TCTRL_TSOT_MASK)
#define LPIT_TCTRL_TSOI_MASK                     0x20000u
#define LPIT_TCTRL_TSOI_SHIFT                    17
#define LPIT_TCTRL_TSOI_WIDTH                    1
#define LPIT_TCTRL_TSOI(x)                       (((uint32_t)(((uint32_t)(x))<<LPIT_TCTRL_TSOI_SHIFT))&LPIT_TCTRL_TSOI_MASK)
#define LPIT_TCTRL_TROT_MASK                     0x40000u
#define LPIT_TCTRL_TROT_SHIFT                    18
#define LPIT_TCTRL_TROT_WIDTH                    1
#define LPIT_TCTRL_TROT(x)                       (((uint32_t)(((uint32_t)(x))<<LPIT_TCTRL_TROT_SHIFT))&LPIT_TCTRL_TROT_MASK)
#define LPIT_TCTRL_TRG_SRC_MASK                  0x800000u
#define LPIT_TCTRL_TRG_SRC_SHIFT                 23
#define LPIT_TCTRL_TRG_SRC_WIDTH                 1
#define LPIT_TCTRL_TRG_SRC(x)                    (((uint32_t)(((uint32_t)(x))<<LPIT_TCTRL_TRG_SRC_SHIFT))&LPIT_TCTRL_TRG_SRC_MASK)
#define LPIT_TCTRL_TRG_SEL_MASK                  0xF000000u
#define LPIT_TCTRL_TRG_SEL_SHIFT                 24
#define LPIT_TCTRL_TRG_SEL_WIDTH                 4
#define LPIT_TCTRL_TRG_SEL(x)                    (((uint32_t)(((uint32_t)(x))<<LPIT_TCTRL_TRG_SEL_SHIFT))&LPIT_TCTRL_TRG_SEL_MASK)

/*!
 * @}
 */ /* end of group LPIT_Register_Masks */


/* LPIT - Peripheral instance base addresses */
/** Peripheral LPIT0 base address */
#define LPIT0_BASE                               (0x40030000u)
/** Peripheral LPIT0 base pointer */
#define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)
#define LPIT0_BASE_PTR                           (LPIT0)
/** Array initializer of LPIT peripheral base addresses */
#define LPIT_BASE_ADDRS                          { LPIT0_BASE }
/** Array initializer of LPIT peripheral base pointers */
#define LPIT_BASE_PTRS                           { LPIT0 }

/* ----------------------------------------------------------------------------
   -- LPIT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPIT_Register_Accessor_Macros LPIT - Register accessor macros
 * @{
 */


/* LPIT - Register instance definitions */
/* LPIT0 */
#define LPIT0_VERID                              LPIT_VERID_REG(LPIT0)
#define LPIT0_PARAM                              LPIT_PARAM_REG(LPIT0)
#define LPIT0_MCR                                LPIT_MCR_REG(LPIT0)
#define LPIT0_MSR                                LPIT_MSR_REG(LPIT0)
#define LPIT0_MIER                               LPIT_MIER_REG(LPIT0)
#define LPIT0_SETTEN                             LPIT_SETTEN_REG(LPIT0)
#define LPIT0_CLRTEN                             LPIT_CLRTEN_REG(LPIT0)
#define LPIT0_TVAL0                              LPIT_TVAL_REG(LPIT0,0)
#define LPIT0_CVAL0                              LPIT_CVAL_REG(LPIT0,0)
#define LPIT0_TCTRL0                             LPIT_TCTRL_REG(LPIT0,0)
#define LPIT0_TVAL1                              LPIT_TVAL_REG(LPIT0,1)
#define LPIT0_CVAL1                              LPIT_CVAL_REG(LPIT0,1)
#define LPIT0_TCTRL1                             LPIT_TCTRL_REG(LPIT0,1)
#define LPIT0_TVAL2                              LPIT_TVAL_REG(LPIT0,2)
#define LPIT0_CVAL2                              LPIT_CVAL_REG(LPIT0,2)
#define LPIT0_TCTRL2                             LPIT_TCTRL_REG(LPIT0,2)
#define LPIT0_TVAL3                              LPIT_TVAL_REG(LPIT0,3)
#define LPIT0_CVAL3                              LPIT_CVAL_REG(LPIT0,3)
#define LPIT0_TCTRL3                             LPIT_TCTRL_REG(LPIT0,3)

/* LPIT - Register array accessors */
#define LPIT0_TVAL(index)                        LPIT_TVAL_REG(LPIT0,index)
#define LPIT0_CVAL(index)                        LPIT_CVAL_REG(LPIT0,index)
#define LPIT0_TCTRL(index)                       LPIT_TCTRL_REG(LPIT0,index)

/*!
 * @}
 */ /* end of group LPIT_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group LPIT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPSPI_Peripheral_Access_Layer LPSPI Peripheral Access Layer
 * @{
 */

/** LPSPI - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t CR;                                /**< Control Register, offset: 0x10 */
  __IO uint32_t SR;                                /**< Status Register, offset: 0x14 */
  __IO uint32_t IER;                               /**< Interrupt Enable Register, offset: 0x18 */
  __IO uint32_t DER;                               /**< DMA Enable Register, offset: 0x1C */
  __IO uint32_t CFGR0;                             /**< Configuration Register 0, offset: 0x20 */
  __IO uint32_t CFGR1;                             /**< Configuration Register 1, offset: 0x24 */
       uint8_t RESERVED_1[8];
  __IO uint32_t DMR0;                              /**< Data Match Register 0, offset: 0x30 */
  __IO uint32_t DMR1;                              /**< Data Match Register 1, offset: 0x34 */
       uint8_t RESERVED_2[8];
  __IO uint32_t CCR;                               /**< Clock Configuration Register, offset: 0x40 */
       uint8_t RESERVED_3[20];
  __IO uint32_t FCR;                               /**< FIFO Control Register, offset: 0x58 */
  __I  uint32_t FSR;                               /**< FIFO Status Register, offset: 0x5C */
  __IO uint32_t TCR;                               /**< Transmit Command Register, offset: 0x60 */
  __O  uint32_t TDR;                               /**< Transmit Data Register, offset: 0x64 */
       uint8_t RESERVED_4[8];
  __I  uint32_t RSR;                               /**< Receive Status Register, offset: 0x70 */
  __I  uint32_t RDR;                               /**< Receive Data Register, offset: 0x74 */
} LPSPI_Type, *LPSPI_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LPSPI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPSPI_Register_Accessor_Macros LPSPI - Register accessor macros
 * @{
 */


/* LPSPI - Register accessors */
#define LPSPI_VERID_REG(base)                    ((base)->VERID)
#define LPSPI_PARAM_REG(base)                    ((base)->PARAM)
#define LPSPI_CR_REG(base)                       ((base)->CR)
#define LPSPI_SR_REG(base)                       ((base)->SR)
#define LPSPI_IER_REG(base)                      ((base)->IER)
#define LPSPI_DER_REG(base)                      ((base)->DER)
#define LPSPI_CFGR0_REG(base)                    ((base)->CFGR0)
#define LPSPI_CFGR1_REG(base)                    ((base)->CFGR1)
#define LPSPI_DMR0_REG(base)                     ((base)->DMR0)
#define LPSPI_DMR1_REG(base)                     ((base)->DMR1)
#define LPSPI_CCR_REG(base)                      ((base)->CCR)
#define LPSPI_FCR_REG(base)                      ((base)->FCR)
#define LPSPI_FSR_REG(base)                      ((base)->FSR)
#define LPSPI_TCR_REG(base)                      ((base)->TCR)
#define LPSPI_TDR_REG(base)                      ((base)->TDR)
#define LPSPI_RSR_REG(base)                      ((base)->RSR)
#define LPSPI_RDR_REG(base)                      ((base)->RDR)

/*!
 * @}
 */ /* end of group LPSPI_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LPSPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPSPI_Register_Masks LPSPI Register Masks
 * @{
 */

/* VERID Bit Fields */
#define LPSPI_VERID_FEATURE_MASK                 0xFFFFu
#define LPSPI_VERID_FEATURE_SHIFT                0
#define LPSPI_VERID_FEATURE_WIDTH                16
#define LPSPI_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x))<<LPSPI_VERID_FEATURE_SHIFT))&LPSPI_VERID_FEATURE_MASK)
#define LPSPI_VERID_MINOR_MASK                   0xFF0000u
#define LPSPI_VERID_MINOR_SHIFT                  16
#define LPSPI_VERID_MINOR_WIDTH                  8
#define LPSPI_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x))<<LPSPI_VERID_MINOR_SHIFT))&LPSPI_VERID_MINOR_MASK)
#define LPSPI_VERID_MAJOR_MASK                   0xFF000000u
#define LPSPI_VERID_MAJOR_SHIFT                  24
#define LPSPI_VERID_MAJOR_WIDTH                  8
#define LPSPI_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x))<<LPSPI_VERID_MAJOR_SHIFT))&LPSPI_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define LPSPI_PARAM_TXFIFO_MASK                  0xFFu
#define LPSPI_PARAM_TXFIFO_SHIFT                 0
#define LPSPI_PARAM_TXFIFO_WIDTH                 8
#define LPSPI_PARAM_TXFIFO(x)                    (((uint32_t)(((uint32_t)(x))<<LPSPI_PARAM_TXFIFO_SHIFT))&LPSPI_PARAM_TXFIFO_MASK)
#define LPSPI_PARAM_RXFIFO_MASK                  0xFF00u
#define LPSPI_PARAM_RXFIFO_SHIFT                 8
#define LPSPI_PARAM_RXFIFO_WIDTH                 8
#define LPSPI_PARAM_RXFIFO(x)                    (((uint32_t)(((uint32_t)(x))<<LPSPI_PARAM_RXFIFO_SHIFT))&LPSPI_PARAM_RXFIFO_MASK)
/* CR Bit Fields */
#define LPSPI_CR_MEN_MASK                        0x1u
#define LPSPI_CR_MEN_SHIFT                       0
#define LPSPI_CR_MEN_WIDTH                       1
#define LPSPI_CR_MEN(x)                          (((uint32_t)(((uint32_t)(x))<<LPSPI_CR_MEN_SHIFT))&LPSPI_CR_MEN_MASK)
#define LPSPI_CR_RST_MASK                        0x2u
#define LPSPI_CR_RST_SHIFT                       1
#define LPSPI_CR_RST_WIDTH                       1
#define LPSPI_CR_RST(x)                          (((uint32_t)(((uint32_t)(x))<<LPSPI_CR_RST_SHIFT))&LPSPI_CR_RST_MASK)
#define LPSPI_CR_DOZEN_MASK                      0x4u
#define LPSPI_CR_DOZEN_SHIFT                     2
#define LPSPI_CR_DOZEN_WIDTH                     1
#define LPSPI_CR_DOZEN(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_CR_DOZEN_SHIFT))&LPSPI_CR_DOZEN_MASK)
#define LPSPI_CR_DBGEN_MASK                      0x8u
#define LPSPI_CR_DBGEN_SHIFT                     3
#define LPSPI_CR_DBGEN_WIDTH                     1
#define LPSPI_CR_DBGEN(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_CR_DBGEN_SHIFT))&LPSPI_CR_DBGEN_MASK)
#define LPSPI_CR_RTF_MASK                        0x100u
#define LPSPI_CR_RTF_SHIFT                       8
#define LPSPI_CR_RTF_WIDTH                       1
#define LPSPI_CR_RTF(x)                          (((uint32_t)(((uint32_t)(x))<<LPSPI_CR_RTF_SHIFT))&LPSPI_CR_RTF_MASK)
#define LPSPI_CR_RRF_MASK                        0x200u
#define LPSPI_CR_RRF_SHIFT                       9
#define LPSPI_CR_RRF_WIDTH                       1
#define LPSPI_CR_RRF(x)                          (((uint32_t)(((uint32_t)(x))<<LPSPI_CR_RRF_SHIFT))&LPSPI_CR_RRF_MASK)
/* SR Bit Fields */
#define LPSPI_SR_TDF_MASK                        0x1u
#define LPSPI_SR_TDF_SHIFT                       0
#define LPSPI_SR_TDF_WIDTH                       1
#define LPSPI_SR_TDF(x)                          (((uint32_t)(((uint32_t)(x))<<LPSPI_SR_TDF_SHIFT))&LPSPI_SR_TDF_MASK)
#define LPSPI_SR_RDF_MASK                        0x2u
#define LPSPI_SR_RDF_SHIFT                       1
#define LPSPI_SR_RDF_WIDTH                       1
#define LPSPI_SR_RDF(x)                          (((uint32_t)(((uint32_t)(x))<<LPSPI_SR_RDF_SHIFT))&LPSPI_SR_RDF_MASK)
#define LPSPI_SR_WCF_MASK                        0x100u
#define LPSPI_SR_WCF_SHIFT                       8
#define LPSPI_SR_WCF_WIDTH                       1
#define LPSPI_SR_WCF(x)                          (((uint32_t)(((uint32_t)(x))<<LPSPI_SR_WCF_SHIFT))&LPSPI_SR_WCF_MASK)
#define LPSPI_SR_FCF_MASK                        0x200u
#define LPSPI_SR_FCF_SHIFT                       9
#define LPSPI_SR_FCF_WIDTH                       1
#define LPSPI_SR_FCF(x)                          (((uint32_t)(((uint32_t)(x))<<LPSPI_SR_FCF_SHIFT))&LPSPI_SR_FCF_MASK)
#define LPSPI_SR_TCF_MASK                        0x400u
#define LPSPI_SR_TCF_SHIFT                       10
#define LPSPI_SR_TCF_WIDTH                       1
#define LPSPI_SR_TCF(x)                          (((uint32_t)(((uint32_t)(x))<<LPSPI_SR_TCF_SHIFT))&LPSPI_SR_TCF_MASK)
#define LPSPI_SR_TEF_MASK                        0x800u
#define LPSPI_SR_TEF_SHIFT                       11
#define LPSPI_SR_TEF_WIDTH                       1
#define LPSPI_SR_TEF(x)                          (((uint32_t)(((uint32_t)(x))<<LPSPI_SR_TEF_SHIFT))&LPSPI_SR_TEF_MASK)
#define LPSPI_SR_REF_MASK                        0x1000u
#define LPSPI_SR_REF_SHIFT                       12
#define LPSPI_SR_REF_WIDTH                       1
#define LPSPI_SR_REF(x)                          (((uint32_t)(((uint32_t)(x))<<LPSPI_SR_REF_SHIFT))&LPSPI_SR_REF_MASK)
#define LPSPI_SR_DMF_MASK                        0x2000u
#define LPSPI_SR_DMF_SHIFT                       13
#define LPSPI_SR_DMF_WIDTH                       1
#define LPSPI_SR_DMF(x)                          (((uint32_t)(((uint32_t)(x))<<LPSPI_SR_DMF_SHIFT))&LPSPI_SR_DMF_MASK)
#define LPSPI_SR_MBF_MASK                        0x1000000u
#define LPSPI_SR_MBF_SHIFT                       24
#define LPSPI_SR_MBF_WIDTH                       1
#define LPSPI_SR_MBF(x)                          (((uint32_t)(((uint32_t)(x))<<LPSPI_SR_MBF_SHIFT))&LPSPI_SR_MBF_MASK)
/* IER Bit Fields */
#define LPSPI_IER_TDIE_MASK                      0x1u
#define LPSPI_IER_TDIE_SHIFT                     0
#define LPSPI_IER_TDIE_WIDTH                     1
#define LPSPI_IER_TDIE(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_IER_TDIE_SHIFT))&LPSPI_IER_TDIE_MASK)
#define LPSPI_IER_RDIE_MASK                      0x2u
#define LPSPI_IER_RDIE_SHIFT                     1
#define LPSPI_IER_RDIE_WIDTH                     1
#define LPSPI_IER_RDIE(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_IER_RDIE_SHIFT))&LPSPI_IER_RDIE_MASK)
#define LPSPI_IER_WCIE_MASK                      0x100u
#define LPSPI_IER_WCIE_SHIFT                     8
#define LPSPI_IER_WCIE_WIDTH                     1
#define LPSPI_IER_WCIE(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_IER_WCIE_SHIFT))&LPSPI_IER_WCIE_MASK)
#define LPSPI_IER_FCIE_MASK                      0x200u
#define LPSPI_IER_FCIE_SHIFT                     9
#define LPSPI_IER_FCIE_WIDTH                     1
#define LPSPI_IER_FCIE(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_IER_FCIE_SHIFT))&LPSPI_IER_FCIE_MASK)
#define LPSPI_IER_TCIE_MASK                      0x400u
#define LPSPI_IER_TCIE_SHIFT                     10
#define LPSPI_IER_TCIE_WIDTH                     1
#define LPSPI_IER_TCIE(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_IER_TCIE_SHIFT))&LPSPI_IER_TCIE_MASK)
#define LPSPI_IER_TEIE_MASK                      0x800u
#define LPSPI_IER_TEIE_SHIFT                     11
#define LPSPI_IER_TEIE_WIDTH                     1
#define LPSPI_IER_TEIE(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_IER_TEIE_SHIFT))&LPSPI_IER_TEIE_MASK)
#define LPSPI_IER_REIE_MASK                      0x1000u
#define LPSPI_IER_REIE_SHIFT                     12
#define LPSPI_IER_REIE_WIDTH                     1
#define LPSPI_IER_REIE(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_IER_REIE_SHIFT))&LPSPI_IER_REIE_MASK)
#define LPSPI_IER_DMIE_MASK                      0x2000u
#define LPSPI_IER_DMIE_SHIFT                     13
#define LPSPI_IER_DMIE_WIDTH                     1
#define LPSPI_IER_DMIE(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_IER_DMIE_SHIFT))&LPSPI_IER_DMIE_MASK)
/* DER Bit Fields */
#define LPSPI_DER_TDDE_MASK                      0x1u
#define LPSPI_DER_TDDE_SHIFT                     0
#define LPSPI_DER_TDDE_WIDTH                     1
#define LPSPI_DER_TDDE(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_DER_TDDE_SHIFT))&LPSPI_DER_TDDE_MASK)
#define LPSPI_DER_RDDE_MASK                      0x2u
#define LPSPI_DER_RDDE_SHIFT                     1
#define LPSPI_DER_RDDE_WIDTH                     1
#define LPSPI_DER_RDDE(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_DER_RDDE_SHIFT))&LPSPI_DER_RDDE_MASK)
/* CFGR0 Bit Fields */
#define LPSPI_CFGR0_HREN_MASK                    0x1u
#define LPSPI_CFGR0_HREN_SHIFT                   0
#define LPSPI_CFGR0_HREN_WIDTH                   1
#define LPSPI_CFGR0_HREN(x)                      (((uint32_t)(((uint32_t)(x))<<LPSPI_CFGR0_HREN_SHIFT))&LPSPI_CFGR0_HREN_MASK)
#define LPSPI_CFGR0_HRPOL_MASK                   0x2u
#define LPSPI_CFGR0_HRPOL_SHIFT                  1
#define LPSPI_CFGR0_HRPOL_WIDTH                  1
#define LPSPI_CFGR0_HRPOL(x)                     (((uint32_t)(((uint32_t)(x))<<LPSPI_CFGR0_HRPOL_SHIFT))&LPSPI_CFGR0_HRPOL_MASK)
#define LPSPI_CFGR0_HRSEL_MASK                   0x4u
#define LPSPI_CFGR0_HRSEL_SHIFT                  2
#define LPSPI_CFGR0_HRSEL_WIDTH                  1
#define LPSPI_CFGR0_HRSEL(x)                     (((uint32_t)(((uint32_t)(x))<<LPSPI_CFGR0_HRSEL_SHIFT))&LPSPI_CFGR0_HRSEL_MASK)
#define LPSPI_CFGR0_CIRFIFO_MASK                 0x100u
#define LPSPI_CFGR0_CIRFIFO_SHIFT                8
#define LPSPI_CFGR0_CIRFIFO_WIDTH                1
#define LPSPI_CFGR0_CIRFIFO(x)                   (((uint32_t)(((uint32_t)(x))<<LPSPI_CFGR0_CIRFIFO_SHIFT))&LPSPI_CFGR0_CIRFIFO_MASK)
#define LPSPI_CFGR0_RDMO_MASK                    0x200u
#define LPSPI_CFGR0_RDMO_SHIFT                   9
#define LPSPI_CFGR0_RDMO_WIDTH                   1
#define LPSPI_CFGR0_RDMO(x)                      (((uint32_t)(((uint32_t)(x))<<LPSPI_CFGR0_RDMO_SHIFT))&LPSPI_CFGR0_RDMO_MASK)
/* CFGR1 Bit Fields */
#define LPSPI_CFGR1_MASTER_MASK                  0x1u
#define LPSPI_CFGR1_MASTER_SHIFT                 0
#define LPSPI_CFGR1_MASTER_WIDTH                 1
#define LPSPI_CFGR1_MASTER(x)                    (((uint32_t)(((uint32_t)(x))<<LPSPI_CFGR1_MASTER_SHIFT))&LPSPI_CFGR1_MASTER_MASK)
#define LPSPI_CFGR1_SAMPLE_MASK                  0x2u
#define LPSPI_CFGR1_SAMPLE_SHIFT                 1
#define LPSPI_CFGR1_SAMPLE_WIDTH                 1
#define LPSPI_CFGR1_SAMPLE(x)                    (((uint32_t)(((uint32_t)(x))<<LPSPI_CFGR1_SAMPLE_SHIFT))&LPSPI_CFGR1_SAMPLE_MASK)
#define LPSPI_CFGR1_AUTOPCS_MASK                 0x4u
#define LPSPI_CFGR1_AUTOPCS_SHIFT                2
#define LPSPI_CFGR1_AUTOPCS_WIDTH                1
#define LPSPI_CFGR1_AUTOPCS(x)                   (((uint32_t)(((uint32_t)(x))<<LPSPI_CFGR1_AUTOPCS_SHIFT))&LPSPI_CFGR1_AUTOPCS_MASK)
#define LPSPI_CFGR1_NOSTALL_MASK                 0x8u
#define LPSPI_CFGR1_NOSTALL_SHIFT                3
#define LPSPI_CFGR1_NOSTALL_WIDTH                1
#define LPSPI_CFGR1_NOSTALL(x)                   (((uint32_t)(((uint32_t)(x))<<LPSPI_CFGR1_NOSTALL_SHIFT))&LPSPI_CFGR1_NOSTALL_MASK)
#define LPSPI_CFGR1_PCSPOL_MASK                  0xF00u
#define LPSPI_CFGR1_PCSPOL_SHIFT                 8
#define LPSPI_CFGR1_PCSPOL_WIDTH                 4
#define LPSPI_CFGR1_PCSPOL(x)                    (((uint32_t)(((uint32_t)(x))<<LPSPI_CFGR1_PCSPOL_SHIFT))&LPSPI_CFGR1_PCSPOL_MASK)
#define LPSPI_CFGR1_MATCFG_MASK                  0x70000u
#define LPSPI_CFGR1_MATCFG_SHIFT                 16
#define LPSPI_CFGR1_MATCFG_WIDTH                 3
#define LPSPI_CFGR1_MATCFG(x)                    (((uint32_t)(((uint32_t)(x))<<LPSPI_CFGR1_MATCFG_SHIFT))&LPSPI_CFGR1_MATCFG_MASK)
#define LPSPI_CFGR1_PINCFG_MASK                  0x3000000u
#define LPSPI_CFGR1_PINCFG_SHIFT                 24
#define LPSPI_CFGR1_PINCFG_WIDTH                 2
#define LPSPI_CFGR1_PINCFG(x)                    (((uint32_t)(((uint32_t)(x))<<LPSPI_CFGR1_PINCFG_SHIFT))&LPSPI_CFGR1_PINCFG_MASK)
#define LPSPI_CFGR1_OUTCFG_MASK                  0x4000000u
#define LPSPI_CFGR1_OUTCFG_SHIFT                 26
#define LPSPI_CFGR1_OUTCFG_WIDTH                 1
#define LPSPI_CFGR1_OUTCFG(x)                    (((uint32_t)(((uint32_t)(x))<<LPSPI_CFGR1_OUTCFG_SHIFT))&LPSPI_CFGR1_OUTCFG_MASK)
#define LPSPI_CFGR1_PCSCFG_MASK                  0x8000000u
#define LPSPI_CFGR1_PCSCFG_SHIFT                 27
#define LPSPI_CFGR1_PCSCFG_WIDTH                 1
#define LPSPI_CFGR1_PCSCFG(x)                    (((uint32_t)(((uint32_t)(x))<<LPSPI_CFGR1_PCSCFG_SHIFT))&LPSPI_CFGR1_PCSCFG_MASK)
/* DMR0 Bit Fields */
#define LPSPI_DMR0_MATCH0_MASK                   0xFFFFFFFFu
#define LPSPI_DMR0_MATCH0_SHIFT                  0
#define LPSPI_DMR0_MATCH0_WIDTH                  32
#define LPSPI_DMR0_MATCH0(x)                     (((uint32_t)(((uint32_t)(x))<<LPSPI_DMR0_MATCH0_SHIFT))&LPSPI_DMR0_MATCH0_MASK)
/* DMR1 Bit Fields */
#define LPSPI_DMR1_MATCH1_MASK                   0xFFFFFFFFu
#define LPSPI_DMR1_MATCH1_SHIFT                  0
#define LPSPI_DMR1_MATCH1_WIDTH                  32
#define LPSPI_DMR1_MATCH1(x)                     (((uint32_t)(((uint32_t)(x))<<LPSPI_DMR1_MATCH1_SHIFT))&LPSPI_DMR1_MATCH1_MASK)
/* CCR Bit Fields */
#define LPSPI_CCR_SCKDIV_MASK                    0xFFu
#define LPSPI_CCR_SCKDIV_SHIFT                   0
#define LPSPI_CCR_SCKDIV_WIDTH                   8
#define LPSPI_CCR_SCKDIV(x)                      (((uint32_t)(((uint32_t)(x))<<LPSPI_CCR_SCKDIV_SHIFT))&LPSPI_CCR_SCKDIV_MASK)
#define LPSPI_CCR_DBT_MASK                       0xFF00u
#define LPSPI_CCR_DBT_SHIFT                      8
#define LPSPI_CCR_DBT_WIDTH                      8
#define LPSPI_CCR_DBT(x)                         (((uint32_t)(((uint32_t)(x))<<LPSPI_CCR_DBT_SHIFT))&LPSPI_CCR_DBT_MASK)
#define LPSPI_CCR_PCSSCK_MASK                    0xFF0000u
#define LPSPI_CCR_PCSSCK_SHIFT                   16
#define LPSPI_CCR_PCSSCK_WIDTH                   8
#define LPSPI_CCR_PCSSCK(x)                      (((uint32_t)(((uint32_t)(x))<<LPSPI_CCR_PCSSCK_SHIFT))&LPSPI_CCR_PCSSCK_MASK)
#define LPSPI_CCR_SCKPCS_MASK                    0xFF000000u
#define LPSPI_CCR_SCKPCS_SHIFT                   24
#define LPSPI_CCR_SCKPCS_WIDTH                   8
#define LPSPI_CCR_SCKPCS(x)                      (((uint32_t)(((uint32_t)(x))<<LPSPI_CCR_SCKPCS_SHIFT))&LPSPI_CCR_SCKPCS_MASK)
/* FCR Bit Fields */
#define LPSPI_FCR_TXWATER_MASK                   0xFFu
#define LPSPI_FCR_TXWATER_SHIFT                  0
#define LPSPI_FCR_TXWATER_WIDTH                  8
#define LPSPI_FCR_TXWATER(x)                     (((uint32_t)(((uint32_t)(x))<<LPSPI_FCR_TXWATER_SHIFT))&LPSPI_FCR_TXWATER_MASK)
#define LPSPI_FCR_RXWATER_MASK                   0xFF0000u
#define LPSPI_FCR_RXWATER_SHIFT                  16
#define LPSPI_FCR_RXWATER_WIDTH                  8
#define LPSPI_FCR_RXWATER(x)                     (((uint32_t)(((uint32_t)(x))<<LPSPI_FCR_RXWATER_SHIFT))&LPSPI_FCR_RXWATER_MASK)
/* FSR Bit Fields */
#define LPSPI_FSR_TXCOUNT_MASK                   0xFFu
#define LPSPI_FSR_TXCOUNT_SHIFT                  0
#define LPSPI_FSR_TXCOUNT_WIDTH                  8
#define LPSPI_FSR_TXCOUNT(x)                     (((uint32_t)(((uint32_t)(x))<<LPSPI_FSR_TXCOUNT_SHIFT))&LPSPI_FSR_TXCOUNT_MASK)
#define LPSPI_FSR_RXCOUNT_MASK                   0xFF0000u
#define LPSPI_FSR_RXCOUNT_SHIFT                  16
#define LPSPI_FSR_RXCOUNT_WIDTH                  8
#define LPSPI_FSR_RXCOUNT(x)                     (((uint32_t)(((uint32_t)(x))<<LPSPI_FSR_RXCOUNT_SHIFT))&LPSPI_FSR_RXCOUNT_MASK)
/* TCR Bit Fields */
#define LPSPI_TCR_FRAMESZ_MASK                   0xFFFu
#define LPSPI_TCR_FRAMESZ_SHIFT                  0
#define LPSPI_TCR_FRAMESZ_WIDTH                  12
#define LPSPI_TCR_FRAMESZ(x)                     (((uint32_t)(((uint32_t)(x))<<LPSPI_TCR_FRAMESZ_SHIFT))&LPSPI_TCR_FRAMESZ_MASK)
#define LPSPI_TCR_WIDTH_MASK                     0x30000u
#define LPSPI_TCR_WIDTH_SHIFT                    16
#define LPSPI_TCR_WIDTH_WIDTH                    2
#define LPSPI_TCR_WIDTH(x)                       (((uint32_t)(((uint32_t)(x))<<LPSPI_TCR_WIDTH_SHIFT))&LPSPI_TCR_WIDTH_MASK)
#define LPSPI_TCR_TXMSK_MASK                     0x40000u
#define LPSPI_TCR_TXMSK_SHIFT                    18
#define LPSPI_TCR_TXMSK_WIDTH                    1
#define LPSPI_TCR_TXMSK(x)                       (((uint32_t)(((uint32_t)(x))<<LPSPI_TCR_TXMSK_SHIFT))&LPSPI_TCR_TXMSK_MASK)
#define LPSPI_TCR_RXMSK_MASK                     0x80000u
#define LPSPI_TCR_RXMSK_SHIFT                    19
#define LPSPI_TCR_RXMSK_WIDTH                    1
#define LPSPI_TCR_RXMSK(x)                       (((uint32_t)(((uint32_t)(x))<<LPSPI_TCR_RXMSK_SHIFT))&LPSPI_TCR_RXMSK_MASK)
#define LPSPI_TCR_CONTC_MASK                     0x100000u
#define LPSPI_TCR_CONTC_SHIFT                    20
#define LPSPI_TCR_CONTC_WIDTH                    1
#define LPSPI_TCR_CONTC(x)                       (((uint32_t)(((uint32_t)(x))<<LPSPI_TCR_CONTC_SHIFT))&LPSPI_TCR_CONTC_MASK)
#define LPSPI_TCR_CONT_MASK                      0x200000u
#define LPSPI_TCR_CONT_SHIFT                     21
#define LPSPI_TCR_CONT_WIDTH                     1
#define LPSPI_TCR_CONT(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_TCR_CONT_SHIFT))&LPSPI_TCR_CONT_MASK)
#define LPSPI_TCR_BYSW_MASK                      0x400000u
#define LPSPI_TCR_BYSW_SHIFT                     22
#define LPSPI_TCR_BYSW_WIDTH                     1
#define LPSPI_TCR_BYSW(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_TCR_BYSW_SHIFT))&LPSPI_TCR_BYSW_MASK)
#define LPSPI_TCR_LSBF_MASK                      0x800000u
#define LPSPI_TCR_LSBF_SHIFT                     23
#define LPSPI_TCR_LSBF_WIDTH                     1
#define LPSPI_TCR_LSBF(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_TCR_LSBF_SHIFT))&LPSPI_TCR_LSBF_MASK)
#define LPSPI_TCR_PCS_MASK                       0x3000000u
#define LPSPI_TCR_PCS_SHIFT                      24
#define LPSPI_TCR_PCS_WIDTH                      2
#define LPSPI_TCR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<LPSPI_TCR_PCS_SHIFT))&LPSPI_TCR_PCS_MASK)
#define LPSPI_TCR_PRESCALE_MASK                  0x38000000u
#define LPSPI_TCR_PRESCALE_SHIFT                 27
#define LPSPI_TCR_PRESCALE_WIDTH                 3
#define LPSPI_TCR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x))<<LPSPI_TCR_PRESCALE_SHIFT))&LPSPI_TCR_PRESCALE_MASK)
#define LPSPI_TCR_CPHA_MASK                      0x40000000u
#define LPSPI_TCR_CPHA_SHIFT                     30
#define LPSPI_TCR_CPHA_WIDTH                     1
#define LPSPI_TCR_CPHA(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_TCR_CPHA_SHIFT))&LPSPI_TCR_CPHA_MASK)
#define LPSPI_TCR_CPOL_MASK                      0x80000000u
#define LPSPI_TCR_CPOL_SHIFT                     31
#define LPSPI_TCR_CPOL_WIDTH                     1
#define LPSPI_TCR_CPOL(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_TCR_CPOL_SHIFT))&LPSPI_TCR_CPOL_MASK)
/* TDR Bit Fields */
#define LPSPI_TDR_DATA_MASK                      0xFFFFFFFFu
#define LPSPI_TDR_DATA_SHIFT                     0
#define LPSPI_TDR_DATA_WIDTH                     32
#define LPSPI_TDR_DATA(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_TDR_DATA_SHIFT))&LPSPI_TDR_DATA_MASK)
/* RSR Bit Fields */
#define LPSPI_RSR_SOF_MASK                       0x1u
#define LPSPI_RSR_SOF_SHIFT                      0
#define LPSPI_RSR_SOF_WIDTH                      1
#define LPSPI_RSR_SOF(x)                         (((uint32_t)(((uint32_t)(x))<<LPSPI_RSR_SOF_SHIFT))&LPSPI_RSR_SOF_MASK)
#define LPSPI_RSR_RXEMPTY_MASK                   0x2u
#define LPSPI_RSR_RXEMPTY_SHIFT                  1
#define LPSPI_RSR_RXEMPTY_WIDTH                  1
#define LPSPI_RSR_RXEMPTY(x)                     (((uint32_t)(((uint32_t)(x))<<LPSPI_RSR_RXEMPTY_SHIFT))&LPSPI_RSR_RXEMPTY_MASK)
/* RDR Bit Fields */
#define LPSPI_RDR_DATA_MASK                      0xFFFFFFFFu
#define LPSPI_RDR_DATA_SHIFT                     0
#define LPSPI_RDR_DATA_WIDTH                     32
#define LPSPI_RDR_DATA(x)                        (((uint32_t)(((uint32_t)(x))<<LPSPI_RDR_DATA_SHIFT))&LPSPI_RDR_DATA_MASK)

/*!
 * @}
 */ /* end of group LPSPI_Register_Masks */


/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI0 base address */
#define LPSPI0_BASE                              (0x400BC000u)
/** Peripheral LPSPI0 base pointer */
#define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
#define LPSPI0_BASE_PTR                          (LPSPI0)
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x400BD000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
#define LPSPI1_BASE_PTR                          (LPSPI1)
/** Peripheral LPSPI2 base address */
#define LPSPI2_BASE                              (0x4003E000u)
/** Peripheral LPSPI2 base pointer */
#define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
#define LPSPI2_BASE_PTR                          (LPSPI2)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE, LPSPI2_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1, LPSPI2 }

/* ----------------------------------------------------------------------------
   -- LPSPI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPSPI_Register_Accessor_Macros LPSPI - Register accessor macros
 * @{
 */


/* LPSPI - Register instance definitions */
/* LPSPI0 */
#define LPSPI0_VERID                             LPSPI_VERID_REG(LPSPI0)
#define LPSPI0_PARAM                             LPSPI_PARAM_REG(LPSPI0)
#define LPSPI0_CR                                LPSPI_CR_REG(LPSPI0)
#define LPSPI0_SR                                LPSPI_SR_REG(LPSPI0)
#define LPSPI0_IER                               LPSPI_IER_REG(LPSPI0)
#define LPSPI0_DER                               LPSPI_DER_REG(LPSPI0)
#define LPSPI0_CFGR0                             LPSPI_CFGR0_REG(LPSPI0)
#define LPSPI0_CFGR1                             LPSPI_CFGR1_REG(LPSPI0)
#define LPSPI0_DMR0                              LPSPI_DMR0_REG(LPSPI0)
#define LPSPI0_DMR1                              LPSPI_DMR1_REG(LPSPI0)
#define LPSPI0_CCR                               LPSPI_CCR_REG(LPSPI0)
#define LPSPI0_FCR                               LPSPI_FCR_REG(LPSPI0)
#define LPSPI0_FSR                               LPSPI_FSR_REG(LPSPI0)
#define LPSPI0_TCR                               LPSPI_TCR_REG(LPSPI0)
#define LPSPI0_TDR                               LPSPI_TDR_REG(LPSPI0)
#define LPSPI0_RSR                               LPSPI_RSR_REG(LPSPI0)
#define LPSPI0_RDR                               LPSPI_RDR_REG(LPSPI0)
/* LPSPI1 */
#define LPSPI1_VERID                             LPSPI_VERID_REG(LPSPI1)
#define LPSPI1_PARAM                             LPSPI_PARAM_REG(LPSPI1)
#define LPSPI1_CR                                LPSPI_CR_REG(LPSPI1)
#define LPSPI1_SR                                LPSPI_SR_REG(LPSPI1)
#define LPSPI1_IER                               LPSPI_IER_REG(LPSPI1)
#define LPSPI1_DER                               LPSPI_DER_REG(LPSPI1)
#define LPSPI1_CFGR0                             LPSPI_CFGR0_REG(LPSPI1)
#define LPSPI1_CFGR1                             LPSPI_CFGR1_REG(LPSPI1)
#define LPSPI1_DMR0                              LPSPI_DMR0_REG(LPSPI1)
#define LPSPI1_DMR1                              LPSPI_DMR1_REG(LPSPI1)
#define LPSPI1_CCR                               LPSPI_CCR_REG(LPSPI1)
#define LPSPI1_FCR                               LPSPI_FCR_REG(LPSPI1)
#define LPSPI1_FSR                               LPSPI_FSR_REG(LPSPI1)
#define LPSPI1_TCR                               LPSPI_TCR_REG(LPSPI1)
#define LPSPI1_TDR                               LPSPI_TDR_REG(LPSPI1)
#define LPSPI1_RSR                               LPSPI_RSR_REG(LPSPI1)
#define LPSPI1_RDR                               LPSPI_RDR_REG(LPSPI1)
/* LPSPI2 */
#define LPSPI2_VERID                             LPSPI_VERID_REG(LPSPI2)
#define LPSPI2_PARAM                             LPSPI_PARAM_REG(LPSPI2)
#define LPSPI2_CR                                LPSPI_CR_REG(LPSPI2)
#define LPSPI2_SR                                LPSPI_SR_REG(LPSPI2)
#define LPSPI2_IER                               LPSPI_IER_REG(LPSPI2)
#define LPSPI2_DER                               LPSPI_DER_REG(LPSPI2)
#define LPSPI2_CFGR0                             LPSPI_CFGR0_REG(LPSPI2)
#define LPSPI2_CFGR1                             LPSPI_CFGR1_REG(LPSPI2)
#define LPSPI2_DMR0                              LPSPI_DMR0_REG(LPSPI2)
#define LPSPI2_DMR1                              LPSPI_DMR1_REG(LPSPI2)
#define LPSPI2_CCR                               LPSPI_CCR_REG(LPSPI2)
#define LPSPI2_FCR                               LPSPI_FCR_REG(LPSPI2)
#define LPSPI2_FSR                               LPSPI_FSR_REG(LPSPI2)
#define LPSPI2_TCR                               LPSPI_TCR_REG(LPSPI2)
#define LPSPI2_TDR                               LPSPI_TDR_REG(LPSPI2)
#define LPSPI2_RSR                               LPSPI_RSR_REG(LPSPI2)
#define LPSPI2_RDR                               LPSPI_RDR_REG(LPSPI2)

/*!
 * @}
 */ /* end of group LPSPI_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group LPSPI_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPTMR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTMR_Peripheral_Access_Layer LPTMR Peripheral Access Layer
 * @{
 */

/** LPTMR - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSR;                               /**< Low Power Timer Control Status Register, offset: 0x0 */
  __IO uint32_t PSR;                               /**< Low Power Timer Prescale Register, offset: 0x4 */
  __IO uint32_t CMR;                               /**< Low Power Timer Compare Register, offset: 0x8 */
  __IO uint32_t CNR;                               /**< Low Power Timer Counter Register, offset: 0xC */
} LPTMR_Type, *LPTMR_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LPTMR - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTMR_Register_Accessor_Macros LPTMR - Register accessor macros
 * @{
 */


/* LPTMR - Register accessors */
#define LPTMR_CSR_REG(base)                      ((base)->CSR)
#define LPTMR_PSR_REG(base)                      ((base)->PSR)
#define LPTMR_CMR_REG(base)                      ((base)->CMR)
#define LPTMR_CNR_REG(base)                      ((base)->CNR)

/*!
 * @}
 */ /* end of group LPTMR_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LPTMR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTMR_Register_Masks LPTMR Register Masks
 * @{
 */

/* CSR Bit Fields */
#define LPTMR_CSR_TEN_MASK                       0x1u
#define LPTMR_CSR_TEN_SHIFT                      0
#define LPTMR_CSR_TEN_WIDTH                      1
#define LPTMR_CSR_TEN(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TEN_SHIFT))&LPTMR_CSR_TEN_MASK)
#define LPTMR_CSR_TMS_MASK                       0x2u
#define LPTMR_CSR_TMS_SHIFT                      1
#define LPTMR_CSR_TMS_WIDTH                      1
#define LPTMR_CSR_TMS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TMS_SHIFT))&LPTMR_CSR_TMS_MASK)
#define LPTMR_CSR_TFC_MASK                       0x4u
#define LPTMR_CSR_TFC_SHIFT                      2
#define LPTMR_CSR_TFC_WIDTH                      1
#define LPTMR_CSR_TFC(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TFC_SHIFT))&LPTMR_CSR_TFC_MASK)
#define LPTMR_CSR_TPP_MASK                       0x8u
#define LPTMR_CSR_TPP_SHIFT                      3
#define LPTMR_CSR_TPP_WIDTH                      1
#define LPTMR_CSR_TPP(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPP_SHIFT))&LPTMR_CSR_TPP_MASK)
#define LPTMR_CSR_TPS_MASK                       0x30u
#define LPTMR_CSR_TPS_SHIFT                      4
#define LPTMR_CSR_TPS_WIDTH                      2
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPS_SHIFT))&LPTMR_CSR_TPS_MASK)
#define LPTMR_CSR_TIE_MASK                       0x40u
#define LPTMR_CSR_TIE_SHIFT                      6
#define LPTMR_CSR_TIE_WIDTH                      1
#define LPTMR_CSR_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TIE_SHIFT))&LPTMR_CSR_TIE_MASK)
#define LPTMR_CSR_TCF_MASK                       0x80u
#define LPTMR_CSR_TCF_SHIFT                      7
#define LPTMR_CSR_TCF_WIDTH                      1
#define LPTMR_CSR_TCF(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TCF_SHIFT))&LPTMR_CSR_TCF_MASK)
#define LPTMR_CSR_TDRE_MASK                      0x100u
#define LPTMR_CSR_TDRE_SHIFT                     8
#define LPTMR_CSR_TDRE_WIDTH                     1
#define LPTMR_CSR_TDRE(x)                        (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TDRE_SHIFT))&LPTMR_CSR_TDRE_MASK)
/* PSR Bit Fields */
#define LPTMR_PSR_PCS_MASK                       0x3u
#define LPTMR_PSR_PCS_SHIFT                      0
#define LPTMR_PSR_PCS_WIDTH                      2
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PCS_SHIFT))&LPTMR_PSR_PCS_MASK)
#define LPTMR_PSR_PBYP_MASK                      0x4u
#define LPTMR_PSR_PBYP_SHIFT                     2
#define LPTMR_PSR_PBYP_WIDTH                     1
#define LPTMR_PSR_PBYP(x)                        (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PBYP_SHIFT))&LPTMR_PSR_PBYP_MASK)
#define LPTMR_PSR_PRESCALE_MASK                  0x78u
#define LPTMR_PSR_PRESCALE_SHIFT                 3
#define LPTMR_PSR_PRESCALE_WIDTH                 4
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PRESCALE_SHIFT))&LPTMR_PSR_PRESCALE_MASK)
/* CMR Bit Fields */
#define LPTMR_CMR_COMPARE_MASK                   0xFFFFu
#define LPTMR_CMR_COMPARE_SHIFT                  0
#define LPTMR_CMR_COMPARE_WIDTH                  16
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CMR_COMPARE_SHIFT))&LPTMR_CMR_COMPARE_MASK)
/* CNR Bit Fields */
#define LPTMR_CNR_COUNTER_MASK                   0xFFFFu
#define LPTMR_CNR_COUNTER_SHIFT                  0
#define LPTMR_CNR_COUNTER_WIDTH                  16
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CNR_COUNTER_SHIFT))&LPTMR_CNR_COUNTER_MASK)

/*!
 * @}
 */ /* end of group LPTMR_Register_Masks */


/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR0 base address */
#define LPTMR0_BASE                              (0x40034000u)
/** Peripheral LPTMR0 base pointer */
#define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
#define LPTMR0_BASE_PTR                          (LPTMR0)
/** Peripheral LPTMR1 base address */
#define LPTMR1_BASE                              (0x400B5000u)
/** Peripheral LPTMR1 base pointer */
#define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
#define LPTMR1_BASE_PTR                          (LPTMR1)
/** Array initializer of LPTMR peripheral base addresses */
#define LPTMR_BASE_ADDRS                         { LPTMR0_BASE, LPTMR1_BASE }
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { LPTMR0, LPTMR1 }

/* ----------------------------------------------------------------------------
   -- LPTMR - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTMR_Register_Accessor_Macros LPTMR - Register accessor macros
 * @{
 */


/* LPTMR - Register instance definitions */
/* LPTMR0 */
#define LPTMR0_CSR                               LPTMR_CSR_REG(LPTMR0)
#define LPTMR0_PSR                               LPTMR_PSR_REG(LPTMR0)
#define LPTMR0_CMR                               LPTMR_CMR_REG(LPTMR0)
#define LPTMR0_CNR                               LPTMR_CNR_REG(LPTMR0)
/* LPTMR1 */
#define LPTMR1_CSR                               LPTMR_CSR_REG(LPTMR1)
#define LPTMR1_PSR                               LPTMR_PSR_REG(LPTMR1)
#define LPTMR1_CMR                               LPTMR_CMR_REG(LPTMR1)
#define LPTMR1_CNR                               LPTMR_CNR_REG(LPTMR1)

/*!
 * @}
 */ /* end of group LPTMR_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group LPTMR_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPUART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPUART_Peripheral_Access_Layer LPUART Peripheral Access Layer
 * @{
 */

/** LPUART - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t GLOBAL;                            /**< LPUART Global Register, offset: 0x8 */
  __IO uint32_t PINCFG;                            /**< LPUART Pin Configuration Register, offset: 0xC */
  __IO uint32_t BAUD;                              /**< LPUART Baud Rate Register, offset: 0x10 */
  __IO uint32_t STAT;                              /**< LPUART Status Register, offset: 0x14 */
  __IO uint32_t CTRL;                              /**< LPUART Control Register, offset: 0x18 */
  __IO uint32_t DATA;                              /**< LPUART Data Register, offset: 0x1C */
  __IO uint32_t MATCH;                             /**< LPUART Match Address Register, offset: 0x20 */
  __IO uint32_t MODIR;                             /**< LPUART Modem IrDA Register, offset: 0x24 */
  __IO uint32_t FIFO;                              /**< LPUART FIFO Register, offset: 0x28 */
  __IO uint32_t WATER;                             /**< LPUART Watermark Register, offset: 0x2C */
} LPUART_Type, *LPUART_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LPUART - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPUART_Register_Accessor_Macros LPUART - Register accessor macros
 * @{
 */


/* LPUART - Register accessors */
#define LPUART_VERID_REG(base)                   ((base)->VERID)
#define LPUART_PARAM_REG(base)                   ((base)->PARAM)
#define LPUART_GLOBAL_REG(base)                  ((base)->GLOBAL)
#define LPUART_PINCFG_REG(base)                  ((base)->PINCFG)
#define LPUART_BAUD_REG(base)                    ((base)->BAUD)
#define LPUART_STAT_REG(base)                    ((base)->STAT)
#define LPUART_CTRL_REG(base)                    ((base)->CTRL)
#define LPUART_DATA_REG(base)                    ((base)->DATA)
#define LPUART_MATCH_REG(base)                   ((base)->MATCH)
#define LPUART_MODIR_REG(base)                   ((base)->MODIR)
#define LPUART_FIFO_REG(base)                    ((base)->FIFO)
#define LPUART_WATER_REG(base)                   ((base)->WATER)

/*!
 * @}
 */ /* end of group LPUART_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LPUART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPUART_Register_Masks LPUART Register Masks
 * @{
 */

/* VERID Bit Fields */
#define LPUART_VERID_FEATURE_MASK                0xFFFFu
#define LPUART_VERID_FEATURE_SHIFT               0
#define LPUART_VERID_FEATURE_WIDTH               16
#define LPUART_VERID_FEATURE(x)                  (((uint32_t)(((uint32_t)(x))<<LPUART_VERID_FEATURE_SHIFT))&LPUART_VERID_FEATURE_MASK)
#define LPUART_VERID_MINOR_MASK                  0xFF0000u
#define LPUART_VERID_MINOR_SHIFT                 16
#define LPUART_VERID_MINOR_WIDTH                 8
#define LPUART_VERID_MINOR(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_VERID_MINOR_SHIFT))&LPUART_VERID_MINOR_MASK)
#define LPUART_VERID_MAJOR_MASK                  0xFF000000u
#define LPUART_VERID_MAJOR_SHIFT                 24
#define LPUART_VERID_MAJOR_WIDTH                 8
#define LPUART_VERID_MAJOR(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_VERID_MAJOR_SHIFT))&LPUART_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define LPUART_PARAM_TXFIFO_MASK                 0xFFu
#define LPUART_PARAM_TXFIFO_SHIFT                0
#define LPUART_PARAM_TXFIFO_WIDTH                8
#define LPUART_PARAM_TXFIFO(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_PARAM_TXFIFO_SHIFT))&LPUART_PARAM_TXFIFO_MASK)
#define LPUART_PARAM_RXFIFO_MASK                 0xFF00u
#define LPUART_PARAM_RXFIFO_SHIFT                8
#define LPUART_PARAM_RXFIFO_WIDTH                8
#define LPUART_PARAM_RXFIFO(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_PARAM_RXFIFO_SHIFT))&LPUART_PARAM_RXFIFO_MASK)
/* GLOBAL Bit Fields */
#define LPUART_GLOBAL_RST_MASK                   0x2u
#define LPUART_GLOBAL_RST_SHIFT                  1
#define LPUART_GLOBAL_RST_WIDTH                  1
#define LPUART_GLOBAL_RST(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_GLOBAL_RST_SHIFT))&LPUART_GLOBAL_RST_MASK)
/* PINCFG Bit Fields */
#define LPUART_PINCFG_TRGSEL_MASK                0x3u
#define LPUART_PINCFG_TRGSEL_SHIFT               0
#define LPUART_PINCFG_TRGSEL_WIDTH               2
#define LPUART_PINCFG_TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<LPUART_PINCFG_TRGSEL_SHIFT))&LPUART_PINCFG_TRGSEL_MASK)
/* BAUD Bit Fields */
#define LPUART_BAUD_SBR_MASK                     0x1FFFu
#define LPUART_BAUD_SBR_SHIFT                    0
#define LPUART_BAUD_SBR_WIDTH                    13
#define LPUART_BAUD_SBR(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_SBR_SHIFT))&LPUART_BAUD_SBR_MASK)
#define LPUART_BAUD_SBNS_MASK                    0x2000u
#define LPUART_BAUD_SBNS_SHIFT                   13
#define LPUART_BAUD_SBNS_WIDTH                   1
#define LPUART_BAUD_SBNS(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_SBNS_SHIFT))&LPUART_BAUD_SBNS_MASK)
#define LPUART_BAUD_RXEDGIE_MASK                 0x4000u
#define LPUART_BAUD_RXEDGIE_SHIFT                14
#define LPUART_BAUD_RXEDGIE_WIDTH                1
#define LPUART_BAUD_RXEDGIE(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_RXEDGIE_SHIFT))&LPUART_BAUD_RXEDGIE_MASK)
#define LPUART_BAUD_LBKDIE_MASK                  0x8000u
#define LPUART_BAUD_LBKDIE_SHIFT                 15
#define LPUART_BAUD_LBKDIE_WIDTH                 1
#define LPUART_BAUD_LBKDIE(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_LBKDIE_SHIFT))&LPUART_BAUD_LBKDIE_MASK)
#define LPUART_BAUD_RESYNCDIS_MASK               0x10000u
#define LPUART_BAUD_RESYNCDIS_SHIFT              16
#define LPUART_BAUD_RESYNCDIS_WIDTH              1
#define LPUART_BAUD_RESYNCDIS(x)                 (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_RESYNCDIS_SHIFT))&LPUART_BAUD_RESYNCDIS_MASK)
#define LPUART_BAUD_BOTHEDGE_MASK                0x20000u
#define LPUART_BAUD_BOTHEDGE_SHIFT               17
#define LPUART_BAUD_BOTHEDGE_WIDTH               1
#define LPUART_BAUD_BOTHEDGE(x)                  (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_BOTHEDGE_SHIFT))&LPUART_BAUD_BOTHEDGE_MASK)
#define LPUART_BAUD_MATCFG_MASK                  0xC0000u
#define LPUART_BAUD_MATCFG_SHIFT                 18
#define LPUART_BAUD_MATCFG_WIDTH                 2
#define LPUART_BAUD_MATCFG(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_MATCFG_SHIFT))&LPUART_BAUD_MATCFG_MASK)
#define LPUART_BAUD_RDMAE_MASK                   0x200000u
#define LPUART_BAUD_RDMAE_SHIFT                  21
#define LPUART_BAUD_RDMAE_WIDTH                  1
#define LPUART_BAUD_RDMAE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_RDMAE_SHIFT))&LPUART_BAUD_RDMAE_MASK)
#define LPUART_BAUD_TDMAE_MASK                   0x800000u
#define LPUART_BAUD_TDMAE_SHIFT                  23
#define LPUART_BAUD_TDMAE_WIDTH                  1
#define LPUART_BAUD_TDMAE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_TDMAE_SHIFT))&LPUART_BAUD_TDMAE_MASK)
#define LPUART_BAUD_OSR_MASK                     0x1F000000u
#define LPUART_BAUD_OSR_SHIFT                    24
#define LPUART_BAUD_OSR_WIDTH                    5
#define LPUART_BAUD_OSR(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_OSR_SHIFT))&LPUART_BAUD_OSR_MASK)
#define LPUART_BAUD_M10_MASK                     0x20000000u
#define LPUART_BAUD_M10_SHIFT                    29
#define LPUART_BAUD_M10_WIDTH                    1
#define LPUART_BAUD_M10(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_M10_SHIFT))&LPUART_BAUD_M10_MASK)
#define LPUART_BAUD_MAEN2_MASK                   0x40000000u
#define LPUART_BAUD_MAEN2_SHIFT                  30
#define LPUART_BAUD_MAEN2_WIDTH                  1
#define LPUART_BAUD_MAEN2(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_MAEN2_SHIFT))&LPUART_BAUD_MAEN2_MASK)
#define LPUART_BAUD_MAEN1_MASK                   0x80000000u
#define LPUART_BAUD_MAEN1_SHIFT                  31
#define LPUART_BAUD_MAEN1_WIDTH                  1
#define LPUART_BAUD_MAEN1(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_MAEN1_SHIFT))&LPUART_BAUD_MAEN1_MASK)
/* STAT Bit Fields */
#define LPUART_STAT_MA2F_MASK                    0x4000u
#define LPUART_STAT_MA2F_SHIFT                   14
#define LPUART_STAT_MA2F_WIDTH                   1
#define LPUART_STAT_MA2F(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_MA2F_SHIFT))&LPUART_STAT_MA2F_MASK)
#define LPUART_STAT_MA1F_MASK                    0x8000u
#define LPUART_STAT_MA1F_SHIFT                   15
#define LPUART_STAT_MA1F_WIDTH                   1
#define LPUART_STAT_MA1F(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_MA1F_SHIFT))&LPUART_STAT_MA1F_MASK)
#define LPUART_STAT_PF_MASK                      0x10000u
#define LPUART_STAT_PF_SHIFT                     16
#define LPUART_STAT_PF_WIDTH                     1
#define LPUART_STAT_PF(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_PF_SHIFT))&LPUART_STAT_PF_MASK)
#define LPUART_STAT_FE_MASK                      0x20000u
#define LPUART_STAT_FE_SHIFT                     17
#define LPUART_STAT_FE_WIDTH                     1
#define LPUART_STAT_FE(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_FE_SHIFT))&LPUART_STAT_FE_MASK)
#define LPUART_STAT_NF_MASK                      0x40000u
#define LPUART_STAT_NF_SHIFT                     18
#define LPUART_STAT_NF_WIDTH                     1
#define LPUART_STAT_NF(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_NF_SHIFT))&LPUART_STAT_NF_MASK)
#define LPUART_STAT_OR_MASK                      0x80000u
#define LPUART_STAT_OR_SHIFT                     19
#define LPUART_STAT_OR_WIDTH                     1
#define LPUART_STAT_OR(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_OR_SHIFT))&LPUART_STAT_OR_MASK)
#define LPUART_STAT_IDLE_MASK                    0x100000u
#define LPUART_STAT_IDLE_SHIFT                   20
#define LPUART_STAT_IDLE_WIDTH                   1
#define LPUART_STAT_IDLE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_IDLE_SHIFT))&LPUART_STAT_IDLE_MASK)
#define LPUART_STAT_RDRF_MASK                    0x200000u
#define LPUART_STAT_RDRF_SHIFT                   21
#define LPUART_STAT_RDRF_WIDTH                   1
#define LPUART_STAT_RDRF(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RDRF_SHIFT))&LPUART_STAT_RDRF_MASK)
#define LPUART_STAT_TC_MASK                      0x400000u
#define LPUART_STAT_TC_SHIFT                     22
#define LPUART_STAT_TC_WIDTH                     1
#define LPUART_STAT_TC(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_TC_SHIFT))&LPUART_STAT_TC_MASK)
#define LPUART_STAT_TDRE_MASK                    0x800000u
#define LPUART_STAT_TDRE_SHIFT                   23
#define LPUART_STAT_TDRE_WIDTH                   1
#define LPUART_STAT_TDRE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_TDRE_SHIFT))&LPUART_STAT_TDRE_MASK)
#define LPUART_STAT_RAF_MASK                     0x1000000u
#define LPUART_STAT_RAF_SHIFT                    24
#define LPUART_STAT_RAF_WIDTH                    1
#define LPUART_STAT_RAF(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RAF_SHIFT))&LPUART_STAT_RAF_MASK)
#define LPUART_STAT_LBKDE_MASK                   0x2000000u
#define LPUART_STAT_LBKDE_SHIFT                  25
#define LPUART_STAT_LBKDE_WIDTH                  1
#define LPUART_STAT_LBKDE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_LBKDE_SHIFT))&LPUART_STAT_LBKDE_MASK)
#define LPUART_STAT_BRK13_MASK                   0x4000000u
#define LPUART_STAT_BRK13_SHIFT                  26
#define LPUART_STAT_BRK13_WIDTH                  1
#define LPUART_STAT_BRK13(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_BRK13_SHIFT))&LPUART_STAT_BRK13_MASK)
#define LPUART_STAT_RWUID_MASK                   0x8000000u
#define LPUART_STAT_RWUID_SHIFT                  27
#define LPUART_STAT_RWUID_WIDTH                  1
#define LPUART_STAT_RWUID(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RWUID_SHIFT))&LPUART_STAT_RWUID_MASK)
#define LPUART_STAT_RXINV_MASK                   0x10000000u
#define LPUART_STAT_RXINV_SHIFT                  28
#define LPUART_STAT_RXINV_WIDTH                  1
#define LPUART_STAT_RXINV(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RXINV_SHIFT))&LPUART_STAT_RXINV_MASK)
#define LPUART_STAT_MSBF_MASK                    0x20000000u
#define LPUART_STAT_MSBF_SHIFT                   29
#define LPUART_STAT_MSBF_WIDTH                   1
#define LPUART_STAT_MSBF(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_MSBF_SHIFT))&LPUART_STAT_MSBF_MASK)
#define LPUART_STAT_RXEDGIF_MASK                 0x40000000u
#define LPUART_STAT_RXEDGIF_SHIFT                30
#define LPUART_STAT_RXEDGIF_WIDTH                1
#define LPUART_STAT_RXEDGIF(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RXEDGIF_SHIFT))&LPUART_STAT_RXEDGIF_MASK)
#define LPUART_STAT_LBKDIF_MASK                  0x80000000u
#define LPUART_STAT_LBKDIF_SHIFT                 31
#define LPUART_STAT_LBKDIF_WIDTH                 1
#define LPUART_STAT_LBKDIF(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_LBKDIF_SHIFT))&LPUART_STAT_LBKDIF_MASK)
/* CTRL Bit Fields */
#define LPUART_CTRL_PT_MASK                      0x1u
#define LPUART_CTRL_PT_SHIFT                     0
#define LPUART_CTRL_PT_WIDTH                     1
#define LPUART_CTRL_PT(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_PT_SHIFT))&LPUART_CTRL_PT_MASK)
#define LPUART_CTRL_PE_MASK                      0x2u
#define LPUART_CTRL_PE_SHIFT                     1
#define LPUART_CTRL_PE_WIDTH                     1
#define LPUART_CTRL_PE(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_PE_SHIFT))&LPUART_CTRL_PE_MASK)
#define LPUART_CTRL_ILT_MASK                     0x4u
#define LPUART_CTRL_ILT_SHIFT                    2
#define LPUART_CTRL_ILT_WIDTH                    1
#define LPUART_CTRL_ILT(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_ILT_SHIFT))&LPUART_CTRL_ILT_MASK)
#define LPUART_CTRL_WAKE_MASK                    0x8u
#define LPUART_CTRL_WAKE_SHIFT                   3
#define LPUART_CTRL_WAKE_WIDTH                   1
#define LPUART_CTRL_WAKE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_WAKE_SHIFT))&LPUART_CTRL_WAKE_MASK)
#define LPUART_CTRL_M_MASK                       0x10u
#define LPUART_CTRL_M_SHIFT                      4
#define LPUART_CTRL_M_WIDTH                      1
#define LPUART_CTRL_M(x)                         (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_M_SHIFT))&LPUART_CTRL_M_MASK)
#define LPUART_CTRL_RSRC_MASK                    0x20u
#define LPUART_CTRL_RSRC_SHIFT                   5
#define LPUART_CTRL_RSRC_WIDTH                   1
#define LPUART_CTRL_RSRC(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_RSRC_SHIFT))&LPUART_CTRL_RSRC_MASK)
#define LPUART_CTRL_DOZEEN_MASK                  0x40u
#define LPUART_CTRL_DOZEEN_SHIFT                 6
#define LPUART_CTRL_DOZEEN_WIDTH                 1
#define LPUART_CTRL_DOZEEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_DOZEEN_SHIFT))&LPUART_CTRL_DOZEEN_MASK)
#define LPUART_CTRL_LOOPS_MASK                   0x80u
#define LPUART_CTRL_LOOPS_SHIFT                  7
#define LPUART_CTRL_LOOPS_WIDTH                  1
#define LPUART_CTRL_LOOPS(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_LOOPS_SHIFT))&LPUART_CTRL_LOOPS_MASK)
#define LPUART_CTRL_IDLECFG_MASK                 0x700u
#define LPUART_CTRL_IDLECFG_SHIFT                8
#define LPUART_CTRL_IDLECFG_WIDTH                3
#define LPUART_CTRL_IDLECFG(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_IDLECFG_SHIFT))&LPUART_CTRL_IDLECFG_MASK)
#define LPUART_CTRL_MA2IE_MASK                   0x4000u
#define LPUART_CTRL_MA2IE_SHIFT                  14
#define LPUART_CTRL_MA2IE_WIDTH                  1
#define LPUART_CTRL_MA2IE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_MA2IE_SHIFT))&LPUART_CTRL_MA2IE_MASK)
#define LPUART_CTRL_MA1IE_MASK                   0x8000u
#define LPUART_CTRL_MA1IE_SHIFT                  15
#define LPUART_CTRL_MA1IE_WIDTH                  1
#define LPUART_CTRL_MA1IE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_MA1IE_SHIFT))&LPUART_CTRL_MA1IE_MASK)
#define LPUART_CTRL_SBK_MASK                     0x10000u
#define LPUART_CTRL_SBK_SHIFT                    16
#define LPUART_CTRL_SBK_WIDTH                    1
#define LPUART_CTRL_SBK(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_SBK_SHIFT))&LPUART_CTRL_SBK_MASK)
#define LPUART_CTRL_RWU_MASK                     0x20000u
#define LPUART_CTRL_RWU_SHIFT                    17
#define LPUART_CTRL_RWU_WIDTH                    1
#define LPUART_CTRL_RWU(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_RWU_SHIFT))&LPUART_CTRL_RWU_MASK)
#define LPUART_CTRL_RE_MASK                      0x40000u
#define LPUART_CTRL_RE_SHIFT                     18
#define LPUART_CTRL_RE_WIDTH                     1
#define LPUART_CTRL_RE(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_RE_SHIFT))&LPUART_CTRL_RE_MASK)
#define LPUART_CTRL_TE_MASK                      0x80000u
#define LPUART_CTRL_TE_SHIFT                     19
#define LPUART_CTRL_TE_WIDTH                     1
#define LPUART_CTRL_TE(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TE_SHIFT))&LPUART_CTRL_TE_MASK)
#define LPUART_CTRL_ILIE_MASK                    0x100000u
#define LPUART_CTRL_ILIE_SHIFT                   20
#define LPUART_CTRL_ILIE_WIDTH                   1
#define LPUART_CTRL_ILIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_ILIE_SHIFT))&LPUART_CTRL_ILIE_MASK)
#define LPUART_CTRL_RIE_MASK                     0x200000u
#define LPUART_CTRL_RIE_SHIFT                    21
#define LPUART_CTRL_RIE_WIDTH                    1
#define LPUART_CTRL_RIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_RIE_SHIFT))&LPUART_CTRL_RIE_MASK)
#define LPUART_CTRL_TCIE_MASK                    0x400000u
#define LPUART_CTRL_TCIE_SHIFT                   22
#define LPUART_CTRL_TCIE_WIDTH                   1
#define LPUART_CTRL_TCIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TCIE_SHIFT))&LPUART_CTRL_TCIE_MASK)
#define LPUART_CTRL_TIE_MASK                     0x800000u
#define LPUART_CTRL_TIE_SHIFT                    23
#define LPUART_CTRL_TIE_WIDTH                    1
#define LPUART_CTRL_TIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TIE_SHIFT))&LPUART_CTRL_TIE_MASK)
#define LPUART_CTRL_PEIE_MASK                    0x1000000u
#define LPUART_CTRL_PEIE_SHIFT                   24
#define LPUART_CTRL_PEIE_WIDTH                   1
#define LPUART_CTRL_PEIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_PEIE_SHIFT))&LPUART_CTRL_PEIE_MASK)
#define LPUART_CTRL_FEIE_MASK                    0x2000000u
#define LPUART_CTRL_FEIE_SHIFT                   25
#define LPUART_CTRL_FEIE_WIDTH                   1
#define LPUART_CTRL_FEIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_FEIE_SHIFT))&LPUART_CTRL_FEIE_MASK)
#define LPUART_CTRL_NEIE_MASK                    0x4000000u
#define LPUART_CTRL_NEIE_SHIFT                   26
#define LPUART_CTRL_NEIE_WIDTH                   1
#define LPUART_CTRL_NEIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_NEIE_SHIFT))&LPUART_CTRL_NEIE_MASK)
#define LPUART_CTRL_ORIE_MASK                    0x8000000u
#define LPUART_CTRL_ORIE_SHIFT                   27
#define LPUART_CTRL_ORIE_WIDTH                   1
#define LPUART_CTRL_ORIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_ORIE_SHIFT))&LPUART_CTRL_ORIE_MASK)
#define LPUART_CTRL_TXINV_MASK                   0x10000000u
#define LPUART_CTRL_TXINV_SHIFT                  28
#define LPUART_CTRL_TXINV_WIDTH                  1
#define LPUART_CTRL_TXINV(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TXINV_SHIFT))&LPUART_CTRL_TXINV_MASK)
#define LPUART_CTRL_TXDIR_MASK                   0x20000000u
#define LPUART_CTRL_TXDIR_SHIFT                  29
#define LPUART_CTRL_TXDIR_WIDTH                  1
#define LPUART_CTRL_TXDIR(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TXDIR_SHIFT))&LPUART_CTRL_TXDIR_MASK)
#define LPUART_CTRL_R9T8_MASK                    0x40000000u
#define LPUART_CTRL_R9T8_SHIFT                   30
#define LPUART_CTRL_R9T8_WIDTH                   1
#define LPUART_CTRL_R9T8(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_R9T8_SHIFT))&LPUART_CTRL_R9T8_MASK)
#define LPUART_CTRL_R8T9_MASK                    0x80000000u
#define LPUART_CTRL_R8T9_SHIFT                   31
#define LPUART_CTRL_R8T9_WIDTH                   1
#define LPUART_CTRL_R8T9(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_R8T9_SHIFT))&LPUART_CTRL_R8T9_MASK)
/* DATA Bit Fields */
#define LPUART_DATA_R0T0_MASK                    0x1u
#define LPUART_DATA_R0T0_SHIFT                   0
#define LPUART_DATA_R0T0_WIDTH                   1
#define LPUART_DATA_R0T0(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_R0T0_SHIFT))&LPUART_DATA_R0T0_MASK)
#define LPUART_DATA_R1T1_MASK                    0x2u
#define LPUART_DATA_R1T1_SHIFT                   1
#define LPUART_DATA_R1T1_WIDTH                   1
#define LPUART_DATA_R1T1(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_R1T1_SHIFT))&LPUART_DATA_R1T1_MASK)
#define LPUART_DATA_R2T2_MASK                    0x4u
#define LPUART_DATA_R2T2_SHIFT                   2
#define LPUART_DATA_R2T2_WIDTH                   1
#define LPUART_DATA_R2T2(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_R2T2_SHIFT))&LPUART_DATA_R2T2_MASK)
#define LPUART_DATA_R3T3_MASK                    0x8u
#define LPUART_DATA_R3T3_SHIFT                   3
#define LPUART_DATA_R3T3_WIDTH                   1
#define LPUART_DATA_R3T3(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_R3T3_SHIFT))&LPUART_DATA_R3T3_MASK)
#define LPUART_DATA_R4T4_MASK                    0x10u
#define LPUART_DATA_R4T4_SHIFT                   4
#define LPUART_DATA_R4T4_WIDTH                   1
#define LPUART_DATA_R4T4(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_R4T4_SHIFT))&LPUART_DATA_R4T4_MASK)
#define LPUART_DATA_R5T5_MASK                    0x20u
#define LPUART_DATA_R5T5_SHIFT                   5
#define LPUART_DATA_R5T5_WIDTH                   1
#define LPUART_DATA_R5T5(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_R5T5_SHIFT))&LPUART_DATA_R5T5_MASK)
#define LPUART_DATA_R6T6_MASK                    0x40u
#define LPUART_DATA_R6T6_SHIFT                   6
#define LPUART_DATA_R6T6_WIDTH                   1
#define LPUART_DATA_R6T6(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_R6T6_SHIFT))&LPUART_DATA_R6T6_MASK)
#define LPUART_DATA_R7T7_MASK                    0x80u
#define LPUART_DATA_R7T7_SHIFT                   7
#define LPUART_DATA_R7T7_WIDTH                   1
#define LPUART_DATA_R7T7(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_R7T7_SHIFT))&LPUART_DATA_R7T7_MASK)
#define LPUART_DATA_R8T8_MASK                    0x100u
#define LPUART_DATA_R8T8_SHIFT                   8
#define LPUART_DATA_R8T8_WIDTH                   1
#define LPUART_DATA_R8T8(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_R8T8_SHIFT))&LPUART_DATA_R8T8_MASK)
#define LPUART_DATA_R9T9_MASK                    0x200u
#define LPUART_DATA_R9T9_SHIFT                   9
#define LPUART_DATA_R9T9_WIDTH                   1
#define LPUART_DATA_R9T9(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_R9T9_SHIFT))&LPUART_DATA_R9T9_MASK)
#define LPUART_DATA_IDLINE_MASK                  0x800u
#define LPUART_DATA_IDLINE_SHIFT                 11
#define LPUART_DATA_IDLINE_WIDTH                 1
#define LPUART_DATA_IDLINE(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_IDLINE_SHIFT))&LPUART_DATA_IDLINE_MASK)
#define LPUART_DATA_RXEMPT_MASK                  0x1000u
#define LPUART_DATA_RXEMPT_SHIFT                 12
#define LPUART_DATA_RXEMPT_WIDTH                 1
#define LPUART_DATA_RXEMPT(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_RXEMPT_SHIFT))&LPUART_DATA_RXEMPT_MASK)
#define LPUART_DATA_FRETSC_MASK                  0x2000u
#define LPUART_DATA_FRETSC_SHIFT                 13
#define LPUART_DATA_FRETSC_WIDTH                 1
#define LPUART_DATA_FRETSC(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_FRETSC_SHIFT))&LPUART_DATA_FRETSC_MASK)
#define LPUART_DATA_PARITYE_MASK                 0x4000u
#define LPUART_DATA_PARITYE_SHIFT                14
#define LPUART_DATA_PARITYE_WIDTH                1
#define LPUART_DATA_PARITYE(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_PARITYE_SHIFT))&LPUART_DATA_PARITYE_MASK)
#define LPUART_DATA_NOISY_MASK                   0x8000u
#define LPUART_DATA_NOISY_SHIFT                  15
#define LPUART_DATA_NOISY_WIDTH                  1
#define LPUART_DATA_NOISY(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_NOISY_SHIFT))&LPUART_DATA_NOISY_MASK)
/* MATCH Bit Fields */
#define LPUART_MATCH_MA1_MASK                    0x3FFu
#define LPUART_MATCH_MA1_SHIFT                   0
#define LPUART_MATCH_MA1_WIDTH                   10
#define LPUART_MATCH_MA1(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_MATCH_MA1_SHIFT))&LPUART_MATCH_MA1_MASK)
#define LPUART_MATCH_MA2_MASK                    0x3FF0000u
#define LPUART_MATCH_MA2_SHIFT                   16
#define LPUART_MATCH_MA2_WIDTH                   10
#define LPUART_MATCH_MA2(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_MATCH_MA2_SHIFT))&LPUART_MATCH_MA2_MASK)
/* MODIR Bit Fields */
#define LPUART_MODIR_TXCTSE_MASK                 0x1u
#define LPUART_MODIR_TXCTSE_SHIFT                0
#define LPUART_MODIR_TXCTSE_WIDTH                1
#define LPUART_MODIR_TXCTSE(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_MODIR_TXCTSE_SHIFT))&LPUART_MODIR_TXCTSE_MASK)
#define LPUART_MODIR_TXRTSE_MASK                 0x2u
#define LPUART_MODIR_TXRTSE_SHIFT                1
#define LPUART_MODIR_TXRTSE_WIDTH                1
#define LPUART_MODIR_TXRTSE(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_MODIR_TXRTSE_SHIFT))&LPUART_MODIR_TXRTSE_MASK)
#define LPUART_MODIR_TXRTSPOL_MASK               0x4u
#define LPUART_MODIR_TXRTSPOL_SHIFT              2
#define LPUART_MODIR_TXRTSPOL_WIDTH              1
#define LPUART_MODIR_TXRTSPOL(x)                 (((uint32_t)(((uint32_t)(x))<<LPUART_MODIR_TXRTSPOL_SHIFT))&LPUART_MODIR_TXRTSPOL_MASK)
#define LPUART_MODIR_RXRTSE_MASK                 0x8u
#define LPUART_MODIR_RXRTSE_SHIFT                3
#define LPUART_MODIR_RXRTSE_WIDTH                1
#define LPUART_MODIR_RXRTSE(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_MODIR_RXRTSE_SHIFT))&LPUART_MODIR_RXRTSE_MASK)
#define LPUART_MODIR_TXCTSC_MASK                 0x10u
#define LPUART_MODIR_TXCTSC_SHIFT                4
#define LPUART_MODIR_TXCTSC_WIDTH                1
#define LPUART_MODIR_TXCTSC(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_MODIR_TXCTSC_SHIFT))&LPUART_MODIR_TXCTSC_MASK)
#define LPUART_MODIR_TXCTSSRC_MASK               0x20u
#define LPUART_MODIR_TXCTSSRC_SHIFT              5
#define LPUART_MODIR_TXCTSSRC_WIDTH              1
#define LPUART_MODIR_TXCTSSRC(x)                 (((uint32_t)(((uint32_t)(x))<<LPUART_MODIR_TXCTSSRC_SHIFT))&LPUART_MODIR_TXCTSSRC_MASK)
#define LPUART_MODIR_RTSWATER_MASK               0xFF00u
#define LPUART_MODIR_RTSWATER_SHIFT              8
#define LPUART_MODIR_RTSWATER_WIDTH              8
#define LPUART_MODIR_RTSWATER(x)                 (((uint32_t)(((uint32_t)(x))<<LPUART_MODIR_RTSWATER_SHIFT))&LPUART_MODIR_RTSWATER_MASK)
#define LPUART_MODIR_TNP_MASK                    0x30000u
#define LPUART_MODIR_TNP_SHIFT                   16
#define LPUART_MODIR_TNP_WIDTH                   2
#define LPUART_MODIR_TNP(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_MODIR_TNP_SHIFT))&LPUART_MODIR_TNP_MASK)
#define LPUART_MODIR_IREN_MASK                   0x40000u
#define LPUART_MODIR_IREN_SHIFT                  18
#define LPUART_MODIR_IREN_WIDTH                  1
#define LPUART_MODIR_IREN(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_MODIR_IREN_SHIFT))&LPUART_MODIR_IREN_MASK)
/* FIFO Bit Fields */
#define LPUART_FIFO_RXFIFOSIZE_MASK              0x7u
#define LPUART_FIFO_RXFIFOSIZE_SHIFT             0
#define LPUART_FIFO_RXFIFOSIZE_WIDTH             3
#define LPUART_FIFO_RXFIFOSIZE(x)                (((uint32_t)(((uint32_t)(x))<<LPUART_FIFO_RXFIFOSIZE_SHIFT))&LPUART_FIFO_RXFIFOSIZE_MASK)
#define LPUART_FIFO_RXFE_MASK                    0x8u
#define LPUART_FIFO_RXFE_SHIFT                   3
#define LPUART_FIFO_RXFE_WIDTH                   1
#define LPUART_FIFO_RXFE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_FIFO_RXFE_SHIFT))&LPUART_FIFO_RXFE_MASK)
#define LPUART_FIFO_TXFIFOSIZE_MASK              0x70u
#define LPUART_FIFO_TXFIFOSIZE_SHIFT             4
#define LPUART_FIFO_TXFIFOSIZE_WIDTH             3
#define LPUART_FIFO_TXFIFOSIZE(x)                (((uint32_t)(((uint32_t)(x))<<LPUART_FIFO_TXFIFOSIZE_SHIFT))&LPUART_FIFO_TXFIFOSIZE_MASK)
#define LPUART_FIFO_TXFE_MASK                    0x80u
#define LPUART_FIFO_TXFE_SHIFT                   7
#define LPUART_FIFO_TXFE_WIDTH                   1
#define LPUART_FIFO_TXFE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_FIFO_TXFE_SHIFT))&LPUART_FIFO_TXFE_MASK)
#define LPUART_FIFO_RXUFE_MASK                   0x100u
#define LPUART_FIFO_RXUFE_SHIFT                  8
#define LPUART_FIFO_RXUFE_WIDTH                  1
#define LPUART_FIFO_RXUFE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_FIFO_RXUFE_SHIFT))&LPUART_FIFO_RXUFE_MASK)
#define LPUART_FIFO_TXOFE_MASK                   0x200u
#define LPUART_FIFO_TXOFE_SHIFT                  9
#define LPUART_FIFO_TXOFE_WIDTH                  1
#define LPUART_FIFO_TXOFE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_FIFO_TXOFE_SHIFT))&LPUART_FIFO_TXOFE_MASK)
#define LPUART_FIFO_RXIDEN_MASK                  0x1C00u
#define LPUART_FIFO_RXIDEN_SHIFT                 10
#define LPUART_FIFO_RXIDEN_WIDTH                 3
#define LPUART_FIFO_RXIDEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_FIFO_RXIDEN_SHIFT))&LPUART_FIFO_RXIDEN_MASK)
#define LPUART_FIFO_RXFLUSH_MASK                 0x4000u
#define LPUART_FIFO_RXFLUSH_SHIFT                14
#define LPUART_FIFO_RXFLUSH_WIDTH                1
#define LPUART_FIFO_RXFLUSH(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_FIFO_RXFLUSH_SHIFT))&LPUART_FIFO_RXFLUSH_MASK)
#define LPUART_FIFO_TXFLUSH_MASK                 0x8000u
#define LPUART_FIFO_TXFLUSH_SHIFT                15
#define LPUART_FIFO_TXFLUSH_WIDTH                1
#define LPUART_FIFO_TXFLUSH(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_FIFO_TXFLUSH_SHIFT))&LPUART_FIFO_TXFLUSH_MASK)
#define LPUART_FIFO_RXUF_MASK                    0x10000u
#define LPUART_FIFO_RXUF_SHIFT                   16
#define LPUART_FIFO_RXUF_WIDTH                   1
#define LPUART_FIFO_RXUF(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_FIFO_RXUF_SHIFT))&LPUART_FIFO_RXUF_MASK)
#define LPUART_FIFO_TXOF_MASK                    0x20000u
#define LPUART_FIFO_TXOF_SHIFT                   17
#define LPUART_FIFO_TXOF_WIDTH                   1
#define LPUART_FIFO_TXOF(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_FIFO_TXOF_SHIFT))&LPUART_FIFO_TXOF_MASK)
#define LPUART_FIFO_RXEMPT_MASK                  0x400000u
#define LPUART_FIFO_RXEMPT_SHIFT                 22
#define LPUART_FIFO_RXEMPT_WIDTH                 1
#define LPUART_FIFO_RXEMPT(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_FIFO_RXEMPT_SHIFT))&LPUART_FIFO_RXEMPT_MASK)
#define LPUART_FIFO_TXEMPT_MASK                  0x800000u
#define LPUART_FIFO_TXEMPT_SHIFT                 23
#define LPUART_FIFO_TXEMPT_WIDTH                 1
#define LPUART_FIFO_TXEMPT(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_FIFO_TXEMPT_SHIFT))&LPUART_FIFO_TXEMPT_MASK)
/* WATER Bit Fields */
#define LPUART_WATER_TXWATER_MASK                0xFFu
#define LPUART_WATER_TXWATER_SHIFT               0
#define LPUART_WATER_TXWATER_WIDTH               8
#define LPUART_WATER_TXWATER(x)                  (((uint32_t)(((uint32_t)(x))<<LPUART_WATER_TXWATER_SHIFT))&LPUART_WATER_TXWATER_MASK)
#define LPUART_WATER_TXCOUNT_MASK                0xFF00u
#define LPUART_WATER_TXCOUNT_SHIFT               8
#define LPUART_WATER_TXCOUNT_WIDTH               8
#define LPUART_WATER_TXCOUNT(x)                  (((uint32_t)(((uint32_t)(x))<<LPUART_WATER_TXCOUNT_SHIFT))&LPUART_WATER_TXCOUNT_MASK)
#define LPUART_WATER_RXWATER_MASK                0xFF0000u
#define LPUART_WATER_RXWATER_SHIFT               16
#define LPUART_WATER_RXWATER_WIDTH               8
#define LPUART_WATER_RXWATER(x)                  (((uint32_t)(((uint32_t)(x))<<LPUART_WATER_RXWATER_SHIFT))&LPUART_WATER_RXWATER_MASK)
#define LPUART_WATER_RXCOUNT_MASK                0xFF000000u
#define LPUART_WATER_RXCOUNT_SHIFT               24
#define LPUART_WATER_RXCOUNT_WIDTH               8
#define LPUART_WATER_RXCOUNT(x)                  (((uint32_t)(((uint32_t)(x))<<LPUART_WATER_RXCOUNT_SHIFT))&LPUART_WATER_RXCOUNT_MASK)

/*!
 * @}
 */ /* end of group LPUART_Register_Masks */


/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             (0x400C4000u)
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
#define LPUART0_BASE_PTR                         (LPUART0)
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x400C5000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
#define LPUART1_BASE_PTR                         (LPUART1)
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x40046000u)
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
#define LPUART2_BASE_PTR                         (LPUART2)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2 }

/* ----------------------------------------------------------------------------
   -- LPUART - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPUART_Register_Accessor_Macros LPUART - Register accessor macros
 * @{
 */


/* LPUART - Register instance definitions */
/* LPUART0 */
#define LPUART0_VERID                            LPUART_VERID_REG(LPUART0)
#define LPUART0_PARAM                            LPUART_PARAM_REG(LPUART0)
#define LPUART0_GLOBAL                           LPUART_GLOBAL_REG(LPUART0)
#define LPUART0_PINCFG                           LPUART_PINCFG_REG(LPUART0)
#define LPUART0_BAUD                             LPUART_BAUD_REG(LPUART0)
#define LPUART0_STAT                             LPUART_STAT_REG(LPUART0)
#define LPUART0_CTRL                             LPUART_CTRL_REG(LPUART0)
#define LPUART0_DATA                             LPUART_DATA_REG(LPUART0)
#define LPUART0_MATCH                            LPUART_MATCH_REG(LPUART0)
#define LPUART0_MODIR                            LPUART_MODIR_REG(LPUART0)
#define LPUART0_FIFO                             LPUART_FIFO_REG(LPUART0)
#define LPUART0_WATER                            LPUART_WATER_REG(LPUART0)
/* LPUART1 */
#define LPUART1_VERID                            LPUART_VERID_REG(LPUART1)
#define LPUART1_PARAM                            LPUART_PARAM_REG(LPUART1)
#define LPUART1_GLOBAL                           LPUART_GLOBAL_REG(LPUART1)
#define LPUART1_PINCFG                           LPUART_PINCFG_REG(LPUART1)
#define LPUART1_BAUD                             LPUART_BAUD_REG(LPUART1)
#define LPUART1_STAT                             LPUART_STAT_REG(LPUART1)
#define LPUART1_CTRL                             LPUART_CTRL_REG(LPUART1)
#define LPUART1_DATA                             LPUART_DATA_REG(LPUART1)
#define LPUART1_MATCH                            LPUART_MATCH_REG(LPUART1)
#define LPUART1_MODIR                            LPUART_MODIR_REG(LPUART1)
#define LPUART1_FIFO                             LPUART_FIFO_REG(LPUART1)
#define LPUART1_WATER                            LPUART_WATER_REG(LPUART1)
/* LPUART2 */
#define LPUART2_VERID                            LPUART_VERID_REG(LPUART2)
#define LPUART2_PARAM                            LPUART_PARAM_REG(LPUART2)
#define LPUART2_GLOBAL                           LPUART_GLOBAL_REG(LPUART2)
#define LPUART2_PINCFG                           LPUART_PINCFG_REG(LPUART2)
#define LPUART2_BAUD                             LPUART_BAUD_REG(LPUART2)
#define LPUART2_STAT                             LPUART_STAT_REG(LPUART2)
#define LPUART2_CTRL                             LPUART_CTRL_REG(LPUART2)
#define LPUART2_DATA                             LPUART_DATA_REG(LPUART2)
#define LPUART2_MATCH                            LPUART_MATCH_REG(LPUART2)
#define LPUART2_MODIR                            LPUART_MODIR_REG(LPUART2)
#define LPUART2_FIFO                             LPUART_FIFO_REG(LPUART2)
#define LPUART2_WATER                            LPUART_WATER_REG(LPUART2)

/*!
 * @}
 */ /* end of group LPUART_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group LPUART_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Peripheral_Access_Layer MCM Peripheral Access Layer
 * @{
 */

/** MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __I  uint16_t PLASC;                             /**< Crossbar Switch (AXBS) Slave Configuration, offset: 0x8 */
  __I  uint16_t PLAMC;                             /**< Crossbar Switch (AXBS) Master Configuration, offset: 0xA */
  __IO uint32_t PLACR;                             /**< Platform Control Register, offset: 0xC */
       uint8_t RESERVED_1[48];
  __IO uint32_t CPO;                               /**< Compute Operation Control Register, offset: 0x40 */
} MCM_Type, *MCM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Accessor_Macros MCM - Register accessor macros
 * @{
 */


/* MCM - Register accessors */
#define MCM_PLASC_REG(base)                      ((base)->PLASC)
#define MCM_PLAMC_REG(base)                      ((base)->PLAMC)
#define MCM_PLACR_REG(base)                      ((base)->PLACR)
#define MCM_CPO_REG(base)                        ((base)->CPO)

/*!
 * @}
 */ /* end of group MCM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/* PLASC Bit Fields */
#define MCM_PLASC_ASC_MASK                       0xFFu
#define MCM_PLASC_ASC_SHIFT                      0
#define MCM_PLASC_ASC_WIDTH                      8
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLASC_ASC_SHIFT))&MCM_PLASC_ASC_MASK)
/* PLAMC Bit Fields */
#define MCM_PLAMC_AMC_MASK                       0xFFu
#define MCM_PLAMC_AMC_SHIFT                      0
#define MCM_PLAMC_AMC_WIDTH                      8
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLAMC_AMC_SHIFT))&MCM_PLAMC_AMC_MASK)
/* PLACR Bit Fields */
#define MCM_PLACR_MMCAU_MASK                     0x100u
#define MCM_PLACR_MMCAU_SHIFT                    8
#define MCM_PLACR_MMCAU_WIDTH                    1
#define MCM_PLACR_MMCAU(x)                       (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_MMCAU_SHIFT))&MCM_PLACR_MMCAU_MASK)
#define MCM_PLACR_ARB_MASK                       0x200u
#define MCM_PLACR_ARB_SHIFT                      9
#define MCM_PLACR_ARB_WIDTH                      1
#define MCM_PLACR_ARB(x)                         (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_ARB_SHIFT))&MCM_PLACR_ARB_MASK)
#define MCM_PLACR_CFCC_MASK                      0x400u
#define MCM_PLACR_CFCC_SHIFT                     10
#define MCM_PLACR_CFCC_WIDTH                     1
#define MCM_PLACR_CFCC(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_CFCC_SHIFT))&MCM_PLACR_CFCC_MASK)
#define MCM_PLACR_DFCDA_MASK                     0x800u
#define MCM_PLACR_DFCDA_SHIFT                    11
#define MCM_PLACR_DFCDA_WIDTH                    1
#define MCM_PLACR_DFCDA(x)                       (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_DFCDA_SHIFT))&MCM_PLACR_DFCDA_MASK)
#define MCM_PLACR_DFCIC_MASK                     0x1000u
#define MCM_PLACR_DFCIC_SHIFT                    12
#define MCM_PLACR_DFCIC_WIDTH                    1
#define MCM_PLACR_DFCIC(x)                       (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_DFCIC_SHIFT))&MCM_PLACR_DFCIC_MASK)
#define MCM_PLACR_DFCC_MASK                      0x2000u
#define MCM_PLACR_DFCC_SHIFT                     13
#define MCM_PLACR_DFCC_WIDTH                     1
#define MCM_PLACR_DFCC(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_DFCC_SHIFT))&MCM_PLACR_DFCC_MASK)
#define MCM_PLACR_EFDS_MASK                      0x4000u
#define MCM_PLACR_EFDS_SHIFT                     14
#define MCM_PLACR_EFDS_WIDTH                     1
#define MCM_PLACR_EFDS(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_EFDS_SHIFT))&MCM_PLACR_EFDS_MASK)
#define MCM_PLACR_DFCS_MASK                      0x8000u
#define MCM_PLACR_DFCS_SHIFT                     15
#define MCM_PLACR_DFCS_WIDTH                     1
#define MCM_PLACR_DFCS(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_DFCS_SHIFT))&MCM_PLACR_DFCS_MASK)
#define MCM_PLACR_ESFC_MASK                      0x10000u
#define MCM_PLACR_ESFC_SHIFT                     16
#define MCM_PLACR_ESFC_WIDTH                     1
#define MCM_PLACR_ESFC(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_ESFC_SHIFT))&MCM_PLACR_ESFC_MASK)
/* CPO Bit Fields */
#define MCM_CPO_CPOREQ_MASK                      0x1u
#define MCM_CPO_CPOREQ_SHIFT                     0
#define MCM_CPO_CPOREQ_WIDTH                     1
#define MCM_CPO_CPOREQ(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CPO_CPOREQ_SHIFT))&MCM_CPO_CPOREQ_MASK)
#define MCM_CPO_CPOACK_MASK                      0x2u
#define MCM_CPO_CPOACK_SHIFT                     1
#define MCM_CPO_CPOACK_WIDTH                     1
#define MCM_CPO_CPOACK(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CPO_CPOACK_SHIFT))&MCM_CPO_CPOACK_MASK)
#define MCM_CPO_CPOWOI_MASK                      0x4u
#define MCM_CPO_CPOWOI_SHIFT                     2
#define MCM_CPO_CPOWOI_WIDTH                     1
#define MCM_CPO_CPOWOI(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CPO_CPOWOI_SHIFT))&MCM_CPO_CPOWOI_MASK)

/*!
 * @}
 */ /* end of group MCM_Register_Masks */


/* MCM - Peripheral instance base addresses */
/** Peripheral MCM0 base address */
#define MCM0_BASE                                (0xF0003000u)
/** Peripheral MCM0 base pointer */
#define MCM0                                     ((MCM_Type *)MCM0_BASE)
#define MCM0_BASE_PTR                            (MCM0)
/** Array initializer of MCM peripheral base addresses */
#define MCM_BASE_ADDRS                           { MCM0_BASE }
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS                            { MCM0 }

/* ----------------------------------------------------------------------------
   -- MCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Accessor_Macros MCM - Register accessor macros
 * @{
 */


/* MCM - Register instance definitions */
/* MCM0 */
#define MCM0_PLASC                               MCM_PLASC_REG(MCM0)
#define MCM0_PLAMC                               MCM_PLAMC_REG(MCM0)
#define MCM0_PLACR                               MCM_PLACR_REG(MCM0)
#define MCM0_CPO                                 MCM_CPO_REG(MCM0)

/*!
 * @}
 */ /* end of group MCM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MMDVSQ Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MMDVSQ_Peripheral_Access_Layer MMDVSQ Peripheral Access Layer
 * @{
 */

/** MMDVSQ - Register Layout Typedef */
typedef struct {
  __IO uint32_t DEND;                              /**< Dividend Register, offset: 0x0 */
  __IO uint32_t DSOR;                              /**< Divisor Register, offset: 0x4 */
  __IO uint32_t CSR;                               /**< Control/Status Register, offset: 0x8 */
  __IO uint32_t RES;                               /**< Result Register, offset: 0xC */
  __IO uint32_t RCND;                              /**< Radicand Register, offset: 0x10 */
} MMDVSQ_Type, *MMDVSQ_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MMDVSQ - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MMDVSQ_Register_Accessor_Macros MMDVSQ - Register accessor macros
 * @{
 */


/* MMDVSQ - Register accessors */
#define MMDVSQ_DEND_REG(base)                    ((base)->DEND)
#define MMDVSQ_DSOR_REG(base)                    ((base)->DSOR)
#define MMDVSQ_CSR_REG(base)                     ((base)->CSR)
#define MMDVSQ_RES_REG(base)                     ((base)->RES)
#define MMDVSQ_RCND_REG(base)                    ((base)->RCND)

/*!
 * @}
 */ /* end of group MMDVSQ_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MMDVSQ Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MMDVSQ_Register_Masks MMDVSQ Register Masks
 * @{
 */

/* DEND Bit Fields */
#define MMDVSQ_DEND_DIVIDEND_MASK                0xFFFFFFFFu
#define MMDVSQ_DEND_DIVIDEND_SHIFT               0
#define MMDVSQ_DEND_DIVIDEND_WIDTH               32
#define MMDVSQ_DEND_DIVIDEND(x)                  (((uint32_t)(((uint32_t)(x))<<MMDVSQ_DEND_DIVIDEND_SHIFT))&MMDVSQ_DEND_DIVIDEND_MASK)
/* DSOR Bit Fields */
#define MMDVSQ_DSOR_DIVISOR_MASK                 0xFFFFFFFFu
#define MMDVSQ_DSOR_DIVISOR_SHIFT                0
#define MMDVSQ_DSOR_DIVISOR_WIDTH                32
#define MMDVSQ_DSOR_DIVISOR(x)                   (((uint32_t)(((uint32_t)(x))<<MMDVSQ_DSOR_DIVISOR_SHIFT))&MMDVSQ_DSOR_DIVISOR_MASK)
/* CSR Bit Fields */
#define MMDVSQ_CSR_SRT_MASK                      0x1u
#define MMDVSQ_CSR_SRT_SHIFT                     0
#define MMDVSQ_CSR_SRT_WIDTH                     1
#define MMDVSQ_CSR_SRT(x)                        (((uint32_t)(((uint32_t)(x))<<MMDVSQ_CSR_SRT_SHIFT))&MMDVSQ_CSR_SRT_MASK)
#define MMDVSQ_CSR_USGN_MASK                     0x2u
#define MMDVSQ_CSR_USGN_SHIFT                    1
#define MMDVSQ_CSR_USGN_WIDTH                    1
#define MMDVSQ_CSR_USGN(x)                       (((uint32_t)(((uint32_t)(x))<<MMDVSQ_CSR_USGN_SHIFT))&MMDVSQ_CSR_USGN_MASK)
#define MMDVSQ_CSR_REM_MASK                      0x4u
#define MMDVSQ_CSR_REM_SHIFT                     2
#define MMDVSQ_CSR_REM_WIDTH                     1
#define MMDVSQ_CSR_REM(x)                        (((uint32_t)(((uint32_t)(x))<<MMDVSQ_CSR_REM_SHIFT))&MMDVSQ_CSR_REM_MASK)
#define MMDVSQ_CSR_DZE_MASK                      0x8u
#define MMDVSQ_CSR_DZE_SHIFT                     3
#define MMDVSQ_CSR_DZE_WIDTH                     1
#define MMDVSQ_CSR_DZE(x)                        (((uint32_t)(((uint32_t)(x))<<MMDVSQ_CSR_DZE_SHIFT))&MMDVSQ_CSR_DZE_MASK)
#define MMDVSQ_CSR_DZ_MASK                       0x10u
#define MMDVSQ_CSR_DZ_SHIFT                      4
#define MMDVSQ_CSR_DZ_WIDTH                      1
#define MMDVSQ_CSR_DZ(x)                         (((uint32_t)(((uint32_t)(x))<<MMDVSQ_CSR_DZ_SHIFT))&MMDVSQ_CSR_DZ_MASK)
#define MMDVSQ_CSR_DFS_MASK                      0x20u
#define MMDVSQ_CSR_DFS_SHIFT                     5
#define MMDVSQ_CSR_DFS_WIDTH                     1
#define MMDVSQ_CSR_DFS(x)                        (((uint32_t)(((uint32_t)(x))<<MMDVSQ_CSR_DFS_SHIFT))&MMDVSQ_CSR_DFS_MASK)
#define MMDVSQ_CSR_SQRT_MASK                     0x20000000u
#define MMDVSQ_CSR_SQRT_SHIFT                    29
#define MMDVSQ_CSR_SQRT_WIDTH                    1
#define MMDVSQ_CSR_SQRT(x)                       (((uint32_t)(((uint32_t)(x))<<MMDVSQ_CSR_SQRT_SHIFT))&MMDVSQ_CSR_SQRT_MASK)
#define MMDVSQ_CSR_DIV_MASK                      0x40000000u
#define MMDVSQ_CSR_DIV_SHIFT                     30
#define MMDVSQ_CSR_DIV_WIDTH                     1
#define MMDVSQ_CSR_DIV(x)                        (((uint32_t)(((uint32_t)(x))<<MMDVSQ_CSR_DIV_SHIFT))&MMDVSQ_CSR_DIV_MASK)
#define MMDVSQ_CSR_BUSY_MASK                     0x80000000u
#define MMDVSQ_CSR_BUSY_SHIFT                    31
#define MMDVSQ_CSR_BUSY_WIDTH                    1
#define MMDVSQ_CSR_BUSY(x)                       (((uint32_t)(((uint32_t)(x))<<MMDVSQ_CSR_BUSY_SHIFT))&MMDVSQ_CSR_BUSY_MASK)
/* RES Bit Fields */
#define MMDVSQ_RES_RESULT_MASK                   0xFFFFFFFFu
#define MMDVSQ_RES_RESULT_SHIFT                  0
#define MMDVSQ_RES_RESULT_WIDTH                  32
#define MMDVSQ_RES_RESULT(x)                     (((uint32_t)(((uint32_t)(x))<<MMDVSQ_RES_RESULT_SHIFT))&MMDVSQ_RES_RESULT_MASK)
/* RCND Bit Fields */
#define MMDVSQ_RCND_RADICAND_MASK                0xFFFFFFFFu
#define MMDVSQ_RCND_RADICAND_SHIFT               0
#define MMDVSQ_RCND_RADICAND_WIDTH               32
#define MMDVSQ_RCND_RADICAND(x)                  (((uint32_t)(((uint32_t)(x))<<MMDVSQ_RCND_RADICAND_SHIFT))&MMDVSQ_RCND_RADICAND_MASK)

/*!
 * @}
 */ /* end of group MMDVSQ_Register_Masks */


/* MMDVSQ - Peripheral instance base addresses */
/** Peripheral MMDVSQ0 base address */
#define MMDVSQ0_BASE                             (0xF0004000u)
/** Peripheral MMDVSQ0 base pointer */
#define MMDVSQ0                                  ((MMDVSQ_Type *)MMDVSQ0_BASE)
#define MMDVSQ0_BASE_PTR                         (MMDVSQ0)
/** Array initializer of MMDVSQ peripheral base addresses */
#define MMDVSQ_BASE_ADDRS                        { MMDVSQ0_BASE }
/** Array initializer of MMDVSQ peripheral base pointers */
#define MMDVSQ_BASE_PTRS                         { MMDVSQ0 }

/* ----------------------------------------------------------------------------
   -- MMDVSQ - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MMDVSQ_Register_Accessor_Macros MMDVSQ - Register accessor macros
 * @{
 */


/* MMDVSQ - Register instance definitions */
/* MMDVSQ0 */
#define MMDVSQ0_DEND                             MMDVSQ_DEND_REG(MMDVSQ0)
#define MMDVSQ0_DSOR                             MMDVSQ_DSOR_REG(MMDVSQ0)
#define MMDVSQ0_CSR                              MMDVSQ_CSR_REG(MMDVSQ0)
#define MMDVSQ0_RES                              MMDVSQ_RES_REG(MMDVSQ0)
#define MMDVSQ0_RCND                             MMDVSQ_RCND_REG(MMDVSQ0)

/*!
 * @}
 */ /* end of group MMDVSQ_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group MMDVSQ_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MSCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Peripheral_Access_Layer MSCM Peripheral Access Layer
 * @{
 */

/** MSCM - Register Layout Typedef */
typedef struct {
  __I  uint32_t CPxTYPE;                           /**< Processor X Type Register, offset: 0x0 */
  __I  uint32_t CPxNUM;                            /**< Processor X Number Register, offset: 0x4 */
  __I  uint32_t CPxMASTER;                         /**< Processor X Master Register, offset: 0x8 */
  __I  uint32_t CPxCOUNT;                          /**< Processor X Count Register, offset: 0xC */
  __I  uint32_t CPxCFG[4];                         /**< Processor X Configuration Register, array offset: 0x10, array step: 0x4 */
  __I  uint32_t CP0TYPE;                           /**< Processor 0 Type Register, offset: 0x20 */
  __I  uint32_t CP0NUM;                            /**< Processor 0 Number Register, offset: 0x24 */
  __I  uint32_t CP0MASTER;                         /**< Processor 0 Master Register, offset: 0x28 */
  __I  uint32_t CP0COUNT;                          /**< Processor 0 Count Register, offset: 0x2C */
  __I  uint32_t CP0CFG[4];                         /**< Processor 0 Configuration Register, array offset: 0x30, array step: 0x4 */
       uint8_t RESERVED_0[960];
  __I  uint32_t OCMDR[3];                          /**< On-Chip Memory Descriptor Register, array offset: 0x400, array step: 0x4 */
} MSCM_Type, *MSCM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MSCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Register_Accessor_Macros MSCM - Register accessor macros
 * @{
 */


/* MSCM - Register accessors */
#define MSCM_CPxTYPE_REG(base)                   ((base)->CPxTYPE)
#define MSCM_CPxNUM_REG(base)                    ((base)->CPxNUM)
#define MSCM_CPxMASTER_REG(base)                 ((base)->CPxMASTER)
#define MSCM_CPxCOUNT_REG(base)                  ((base)->CPxCOUNT)
#define MSCM_CPxCFG_REG(base,index)              ((base)->CPxCFG[index])
#define MSCM_CPxCFG_COUNT                        4
#define MSCM_CP0TYPE_REG(base)                   ((base)->CP0TYPE)
#define MSCM_CP0NUM_REG(base)                    ((base)->CP0NUM)
#define MSCM_CP0MASTER_REG(base)                 ((base)->CP0MASTER)
#define MSCM_CP0COUNT_REG(base)                  ((base)->CP0COUNT)
#define MSCM_CP0CFG_REG(base,index)              ((base)->CP0CFG[index])
#define MSCM_CP0CFG_COUNT                        4
#define MSCM_OCMDR_REG(base,index)               ((base)->OCMDR[index])
#define MSCM_OCMDR_COUNT                         3

/*!
 * @}
 */ /* end of group MSCM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MSCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Register_Masks MSCM Register Masks
 * @{
 */

/* CPxTYPE Bit Fields */
#define MSCM_CPxTYPE_RYPZ_MASK                   0xFFu
#define MSCM_CPxTYPE_RYPZ_SHIFT                  0
#define MSCM_CPxTYPE_RYPZ_WIDTH                  8
#define MSCM_CPxTYPE_RYPZ(x)                     (((uint32_t)(((uint32_t)(x))<<MSCM_CPxTYPE_RYPZ_SHIFT))&MSCM_CPxTYPE_RYPZ_MASK)
#define MSCM_CPxTYPE_PERSONALITY_MASK            0xFFFFFF00u
#define MSCM_CPxTYPE_PERSONALITY_SHIFT           8
#define MSCM_CPxTYPE_PERSONALITY_WIDTH           24
#define MSCM_CPxTYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x))<<MSCM_CPxTYPE_PERSONALITY_SHIFT))&MSCM_CPxTYPE_PERSONALITY_MASK)
/* CPxNUM Bit Fields */
#define MSCM_CPxNUM_CPN_MASK                     0x1u
#define MSCM_CPxNUM_CPN_SHIFT                    0
#define MSCM_CPxNUM_CPN_WIDTH                    1
#define MSCM_CPxNUM_CPN(x)                       (((uint32_t)(((uint32_t)(x))<<MSCM_CPxNUM_CPN_SHIFT))&MSCM_CPxNUM_CPN_MASK)
/* CPxMASTER Bit Fields */
#define MSCM_CPxMASTER_PPN_MASK                  0x3Fu
#define MSCM_CPxMASTER_PPN_SHIFT                 0
#define MSCM_CPxMASTER_PPN_WIDTH                 6
#define MSCM_CPxMASTER_PPN(x)                    (((uint32_t)(((uint32_t)(x))<<MSCM_CPxMASTER_PPN_SHIFT))&MSCM_CPxMASTER_PPN_MASK)
/* CPxCOUNT Bit Fields */
#define MSCM_CPxCOUNT_PCNT_MASK                  0x3u
#define MSCM_CPxCOUNT_PCNT_SHIFT                 0
#define MSCM_CPxCOUNT_PCNT_WIDTH                 2
#define MSCM_CPxCOUNT_PCNT(x)                    (((uint32_t)(((uint32_t)(x))<<MSCM_CPxCOUNT_PCNT_SHIFT))&MSCM_CPxCOUNT_PCNT_MASK)
/* CPxCFG Bit Fields */
#define MSCM_CPxCFG_DCWY_MASK                    0xFFu
#define MSCM_CPxCFG_DCWY_SHIFT                   0
#define MSCM_CPxCFG_DCWY_WIDTH                   8
#define MSCM_CPxCFG_DCWY(x)                      (((uint32_t)(((uint32_t)(x))<<MSCM_CPxCFG_DCWY_SHIFT))&MSCM_CPxCFG_DCWY_MASK)
#define MSCM_CPxCFG_DCSZ_MASK                    0xFF00u
#define MSCM_CPxCFG_DCSZ_SHIFT                   8
#define MSCM_CPxCFG_DCSZ_WIDTH                   8
#define MSCM_CPxCFG_DCSZ(x)                      (((uint32_t)(((uint32_t)(x))<<MSCM_CPxCFG_DCSZ_SHIFT))&MSCM_CPxCFG_DCSZ_MASK)
#define MSCM_CPxCFG_ICWY_MASK                    0xFF0000u
#define MSCM_CPxCFG_ICWY_SHIFT                   16
#define MSCM_CPxCFG_ICWY_WIDTH                   8
#define MSCM_CPxCFG_ICWY(x)                      (((uint32_t)(((uint32_t)(x))<<MSCM_CPxCFG_ICWY_SHIFT))&MSCM_CPxCFG_ICWY_MASK)
#define MSCM_CPxCFG_ICSZ_MASK                    0xFF000000u
#define MSCM_CPxCFG_ICSZ_SHIFT                   24
#define MSCM_CPxCFG_ICSZ_WIDTH                   8
#define MSCM_CPxCFG_ICSZ(x)                      (((uint32_t)(((uint32_t)(x))<<MSCM_CPxCFG_ICSZ_SHIFT))&MSCM_CPxCFG_ICSZ_MASK)
/* CP0TYPE Bit Fields */
#define MSCM_CP0TYPE_RYPZ_MASK                   0xFFu
#define MSCM_CP0TYPE_RYPZ_SHIFT                  0
#define MSCM_CP0TYPE_RYPZ_WIDTH                  8
#define MSCM_CP0TYPE_RYPZ(x)                     (((uint32_t)(((uint32_t)(x))<<MSCM_CP0TYPE_RYPZ_SHIFT))&MSCM_CP0TYPE_RYPZ_MASK)
#define MSCM_CP0TYPE_PERSONALITY_MASK            0xFFFFFF00u
#define MSCM_CP0TYPE_PERSONALITY_SHIFT           8
#define MSCM_CP0TYPE_PERSONALITY_WIDTH           24
#define MSCM_CP0TYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x))<<MSCM_CP0TYPE_PERSONALITY_SHIFT))&MSCM_CP0TYPE_PERSONALITY_MASK)
/* CP0NUM Bit Fields */
#define MSCM_CP0NUM_CPN_MASK                     0x1u
#define MSCM_CP0NUM_CPN_SHIFT                    0
#define MSCM_CP0NUM_CPN_WIDTH                    1
#define MSCM_CP0NUM_CPN(x)                       (((uint32_t)(((uint32_t)(x))<<MSCM_CP0NUM_CPN_SHIFT))&MSCM_CP0NUM_CPN_MASK)
/* CP0MASTER Bit Fields */
#define MSCM_CP0MASTER_PPN_MASK                  0x3Fu
#define MSCM_CP0MASTER_PPN_SHIFT                 0
#define MSCM_CP0MASTER_PPN_WIDTH                 6
#define MSCM_CP0MASTER_PPN(x)                    (((uint32_t)(((uint32_t)(x))<<MSCM_CP0MASTER_PPN_SHIFT))&MSCM_CP0MASTER_PPN_MASK)
/* CP0COUNT Bit Fields */
#define MSCM_CP0COUNT_PCNT_MASK                  0x3u
#define MSCM_CP0COUNT_PCNT_SHIFT                 0
#define MSCM_CP0COUNT_PCNT_WIDTH                 2
#define MSCM_CP0COUNT_PCNT(x)                    (((uint32_t)(((uint32_t)(x))<<MSCM_CP0COUNT_PCNT_SHIFT))&MSCM_CP0COUNT_PCNT_MASK)
/* CP0CFG Bit Fields */
#define MSCM_CP0CFG_DCWY_MASK                    0xFFu
#define MSCM_CP0CFG_DCWY_SHIFT                   0
#define MSCM_CP0CFG_DCWY_WIDTH                   8
#define MSCM_CP0CFG_DCWY(x)                      (((uint32_t)(((uint32_t)(x))<<MSCM_CP0CFG_DCWY_SHIFT))&MSCM_CP0CFG_DCWY_MASK)
#define MSCM_CP0CFG_DCSZ_MASK                    0xFF00u
#define MSCM_CP0CFG_DCSZ_SHIFT                   8
#define MSCM_CP0CFG_DCSZ_WIDTH                   8
#define MSCM_CP0CFG_DCSZ(x)                      (((uint32_t)(((uint32_t)(x))<<MSCM_CP0CFG_DCSZ_SHIFT))&MSCM_CP0CFG_DCSZ_MASK)
#define MSCM_CP0CFG_ICWY_MASK                    0xFF0000u
#define MSCM_CP0CFG_ICWY_SHIFT                   16
#define MSCM_CP0CFG_ICWY_WIDTH                   8
#define MSCM_CP0CFG_ICWY(x)                      (((uint32_t)(((uint32_t)(x))<<MSCM_CP0CFG_ICWY_SHIFT))&MSCM_CP0CFG_ICWY_MASK)
#define MSCM_CP0CFG_ICSZ_MASK                    0xFF000000u
#define MSCM_CP0CFG_ICSZ_SHIFT                   24
#define MSCM_CP0CFG_ICSZ_WIDTH                   8
#define MSCM_CP0CFG_ICSZ(x)                      (((uint32_t)(((uint32_t)(x))<<MSCM_CP0CFG_ICSZ_SHIFT))&MSCM_CP0CFG_ICSZ_MASK)
/* OCMDR Bit Fields */
#define MSCM_OCMDR_OCMPU_MASK                    0x1000u
#define MSCM_OCMDR_OCMPU_SHIFT                   12
#define MSCM_OCMDR_OCMPU_WIDTH                   1
#define MSCM_OCMDR_OCMPU(x)                      (((uint32_t)(((uint32_t)(x))<<MSCM_OCMDR_OCMPU_SHIFT))&MSCM_OCMDR_OCMPU_MASK)
#define MSCM_OCMDR_OCMT_MASK                     0xE000u
#define MSCM_OCMDR_OCMT_SHIFT                    13
#define MSCM_OCMDR_OCMT_WIDTH                    3
#define MSCM_OCMDR_OCMT(x)                       (((uint32_t)(((uint32_t)(x))<<MSCM_OCMDR_OCMT_SHIFT))&MSCM_OCMDR_OCMT_MASK)
#define MSCM_OCMDR_RO_MASK                       0x10000u
#define MSCM_OCMDR_RO_SHIFT                      16
#define MSCM_OCMDR_RO_WIDTH                      1
#define MSCM_OCMDR_RO(x)                         (((uint32_t)(((uint32_t)(x))<<MSCM_OCMDR_RO_SHIFT))&MSCM_OCMDR_RO_MASK)
#define MSCM_OCMDR_OCMW_MASK                     0xE0000u
#define MSCM_OCMDR_OCMW_SHIFT                    17
#define MSCM_OCMDR_OCMW_WIDTH                    3
#define MSCM_OCMDR_OCMW(x)                       (((uint32_t)(((uint32_t)(x))<<MSCM_OCMDR_OCMW_SHIFT))&MSCM_OCMDR_OCMW_MASK)
#define MSCM_OCMDR_OCMSZ_MASK                    0xF000000u
#define MSCM_OCMDR_OCMSZ_SHIFT                   24
#define MSCM_OCMDR_OCMSZ_WIDTH                   4
#define MSCM_OCMDR_OCMSZ(x)                      (((uint32_t)(((uint32_t)(x))<<MSCM_OCMDR_OCMSZ_SHIFT))&MSCM_OCMDR_OCMSZ_MASK)
#define MSCM_OCMDR_OCMSZH_MASK                   0x10000000u
#define MSCM_OCMDR_OCMSZH_SHIFT                  28
#define MSCM_OCMDR_OCMSZH_WIDTH                  1
#define MSCM_OCMDR_OCMSZH(x)                     (((uint32_t)(((uint32_t)(x))<<MSCM_OCMDR_OCMSZH_SHIFT))&MSCM_OCMDR_OCMSZH_MASK)
#define MSCM_OCMDR_V_MASK                        0x80000000u
#define MSCM_OCMDR_V_SHIFT                       31
#define MSCM_OCMDR_V_WIDTH                       1
#define MSCM_OCMDR_V(x)                          (((uint32_t)(((uint32_t)(x))<<MSCM_OCMDR_V_SHIFT))&MSCM_OCMDR_V_MASK)

/*!
 * @}
 */ /* end of group MSCM_Register_Masks */


/* MSCM - Peripheral instance base addresses */
/** Peripheral MSCM base address */
#define MSCM_BASE                                (0x40001000u)
/** Peripheral MSCM base pointer */
#define MSCM                                     ((MSCM_Type *)MSCM_BASE)
#define MSCM_BASE_PTR                            (MSCM)
/** Array initializer of MSCM peripheral base addresses */
#define MSCM_BASE_ADDRS                          { MSCM_BASE }
/** Array initializer of MSCM peripheral base pointers */
#define MSCM_BASE_PTRS                           { MSCM }

/* ----------------------------------------------------------------------------
   -- MSCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Register_Accessor_Macros MSCM - Register accessor macros
 * @{
 */


/* MSCM - Register instance definitions */
/* MSCM */
#define MSCM_CPxTYPE                             MSCM_CPxTYPE_REG(MSCM)
#define MSCM_CPxNUM                              MSCM_CPxNUM_REG(MSCM)
#define MSCM_CPxMASTER                           MSCM_CPxMASTER_REG(MSCM)
#define MSCM_CPxCOUNT                            MSCM_CPxCOUNT_REG(MSCM)
#define MSCM_CPxCFG0                             MSCM_CPxCFG_REG(MSCM,0)
#define MSCM_CPxCFG1                             MSCM_CPxCFG_REG(MSCM,1)
#define MSCM_CPxCFG2                             MSCM_CPxCFG_REG(MSCM,2)
#define MSCM_CPxCFG3                             MSCM_CPxCFG_REG(MSCM,3)
#define MSCM_CP0TYPE                             MSCM_CP0TYPE_REG(MSCM)
#define MSCM_CP0NUM                              MSCM_CP0NUM_REG(MSCM)
#define MSCM_CP0MASTER                           MSCM_CP0MASTER_REG(MSCM)
#define MSCM_CP0COUNT                            MSCM_CP0COUNT_REG(MSCM)
#define MSCM_CP0CFG0                             MSCM_CP0CFG_REG(MSCM,0)
#define MSCM_CP0CFG1                             MSCM_CP0CFG_REG(MSCM,1)
#define MSCM_CP0CFG2                             MSCM_CP0CFG_REG(MSCM,2)
#define MSCM_CP0CFG3                             MSCM_CP0CFG_REG(MSCM,3)
#define MSCM_OCMDR0                              MSCM_OCMDR_REG(MSCM,0)
#define MSCM_OCMDR1                              MSCM_OCMDR_REG(MSCM,1)
#define MSCM_OCMDR2                              MSCM_OCMDR_REG(MSCM,2)

/* MSCM - Register array accessors */
#define MSCM_CPxCFG(index)                       MSCM_CPxCFG_REG(MSCM,index)
#define MSCM_CP0CFG(index)                       MSCM_CP0CFG_REG(MSCM,index)
#define MSCM_OCMDR(index)                        MSCM_OCMDR_REG(MSCM,index)

/*!
 * @}
 */ /* end of group MSCM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group MSCM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MTB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTB_Peripheral_Access_Layer MTB Peripheral Access Layer
 * @{
 */

/** MTB - Register Layout Typedef */
typedef struct {
  __IO uint32_t POSITION;                          /**< MTB Position Register, offset: 0x0 */
  __IO uint32_t MASTER;                            /**< MTB Master Register, offset: 0x4 */
  __IO uint32_t FLOW;                              /**< MTB Flow Register, offset: 0x8 */
  __I  uint32_t BASE;                              /**< MTB Base Register, offset: 0xC */
       uint8_t RESERVED_0[3824];
  __I  uint32_t MODECTRL;                          /**< Integration Mode Control Register, offset: 0xF00 */
       uint8_t RESERVED_1[156];
  __I  uint32_t TAGSET;                            /**< Claim TAG Set Register, offset: 0xFA0 */
  __I  uint32_t TAGCLEAR;                          /**< Claim TAG Clear Register, offset: 0xFA4 */
       uint8_t RESERVED_2[8];
  __I  uint32_t LOCKACCESS;                        /**< Lock Access Register, offset: 0xFB0 */
  __I  uint32_t LOCKSTAT;                          /**< Lock Status Register, offset: 0xFB4 */
  __I  uint32_t AUTHSTAT;                          /**< Authentication Status Register, offset: 0xFB8 */
  __I  uint32_t DEVICEARCH;                        /**< Device Architecture Register, offset: 0xFBC */
       uint8_t RESERVED_3[8];
  __I  uint32_t DEVICECFG;                         /**< Device Configuration Register, offset: 0xFC8 */
  __I  uint32_t DEVICETYPID;                       /**< Device Type Identifier Register, offset: 0xFCC */
  __I  uint32_t PERIPHID[8];                       /**< Peripheral ID Register, array offset: 0xFD0, array step: 0x4 */
  __I  uint32_t COMPID[4];                         /**< Component ID Register, array offset: 0xFF0, array step: 0x4 */
} MTB_Type, *MTB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MTB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTB_Register_Accessor_Macros MTB - Register accessor macros
 * @{
 */


/* MTB - Register accessors */
#define MTB_POSITION_REG(base)                   ((base)->POSITION)
#define MTB_MASTER_REG(base)                     ((base)->MASTER)
#define MTB_FLOW_REG(base)                       ((base)->FLOW)
#define MTB_BASE_REG(base)                       ((base)->BASE)
#define MTB_MODECTRL_REG(base)                   ((base)->MODECTRL)
#define MTB_TAGSET_REG(base)                     ((base)->TAGSET)
#define MTB_TAGCLEAR_REG(base)                   ((base)->TAGCLEAR)
#define MTB_LOCKACCESS_REG(base)                 ((base)->LOCKACCESS)
#define MTB_LOCKSTAT_REG(base)                   ((base)->LOCKSTAT)
#define MTB_AUTHSTAT_REG(base)                   ((base)->AUTHSTAT)
#define MTB_DEVICEARCH_REG(base)                 ((base)->DEVICEARCH)
#define MTB_DEVICECFG_REG(base)                  ((base)->DEVICECFG)
#define MTB_DEVICETYPID_REG(base)                ((base)->DEVICETYPID)
#define MTB_PERIPHID_REG(base,index)             ((base)->PERIPHID[index])
#define MTB_PERIPHID_COUNT                       8
#define MTB_COMPID_REG(base,index)               ((base)->COMPID[index])
#define MTB_COMPID_COUNT                         4

/*!
 * @}
 */ /* end of group MTB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MTB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTB_Register_Masks MTB Register Masks
 * @{
 */

/* POSITION Bit Fields */
#define MTB_POSITION_WRAP_MASK                   0x4u
#define MTB_POSITION_WRAP_SHIFT                  2
#define MTB_POSITION_WRAP_WIDTH                  1
#define MTB_POSITION_WRAP(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_POSITION_WRAP_SHIFT))&MTB_POSITION_WRAP_MASK)
#define MTB_POSITION_POINTER_MASK                0xFFFFFFF8u
#define MTB_POSITION_POINTER_SHIFT               3
#define MTB_POSITION_POINTER_WIDTH               29
#define MTB_POSITION_POINTER(x)                  (((uint32_t)(((uint32_t)(x))<<MTB_POSITION_POINTER_SHIFT))&MTB_POSITION_POINTER_MASK)
/* MASTER Bit Fields */
#define MTB_MASTER_MASK_MASK                     0x1Fu
#define MTB_MASTER_MASK_SHIFT                    0
#define MTB_MASTER_MASK_WIDTH                    5
#define MTB_MASTER_MASK(x)                       (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_MASK_SHIFT))&MTB_MASTER_MASK_MASK)
#define MTB_MASTER_TSTARTEN_MASK                 0x20u
#define MTB_MASTER_TSTARTEN_SHIFT                5
#define MTB_MASTER_TSTARTEN_WIDTH                1
#define MTB_MASTER_TSTARTEN(x)                   (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_TSTARTEN_SHIFT))&MTB_MASTER_TSTARTEN_MASK)
#define MTB_MASTER_TSTOPEN_MASK                  0x40u
#define MTB_MASTER_TSTOPEN_SHIFT                 6
#define MTB_MASTER_TSTOPEN_WIDTH                 1
#define MTB_MASTER_TSTOPEN(x)                    (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_TSTOPEN_SHIFT))&MTB_MASTER_TSTOPEN_MASK)
#define MTB_MASTER_SFRWPRIV_MASK                 0x80u
#define MTB_MASTER_SFRWPRIV_SHIFT                7
#define MTB_MASTER_SFRWPRIV_WIDTH                1
#define MTB_MASTER_SFRWPRIV(x)                   (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_SFRWPRIV_SHIFT))&MTB_MASTER_SFRWPRIV_MASK)
#define MTB_MASTER_RAMPRIV_MASK                  0x100u
#define MTB_MASTER_RAMPRIV_SHIFT                 8
#define MTB_MASTER_RAMPRIV_WIDTH                 1
#define MTB_MASTER_RAMPRIV(x)                    (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_RAMPRIV_SHIFT))&MTB_MASTER_RAMPRIV_MASK)
#define MTB_MASTER_HALTREQ_MASK                  0x200u
#define MTB_MASTER_HALTREQ_SHIFT                 9
#define MTB_MASTER_HALTREQ_WIDTH                 1
#define MTB_MASTER_HALTREQ(x)                    (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_HALTREQ_SHIFT))&MTB_MASTER_HALTREQ_MASK)
#define MTB_MASTER_EN_MASK                       0x80000000u
#define MTB_MASTER_EN_SHIFT                      31
#define MTB_MASTER_EN_WIDTH                      1
#define MTB_MASTER_EN(x)                         (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_EN_SHIFT))&MTB_MASTER_EN_MASK)
/* FLOW Bit Fields */
#define MTB_FLOW_AUTOSTOP_MASK                   0x1u
#define MTB_FLOW_AUTOSTOP_SHIFT                  0
#define MTB_FLOW_AUTOSTOP_WIDTH                  1
#define MTB_FLOW_AUTOSTOP(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_FLOW_AUTOSTOP_SHIFT))&MTB_FLOW_AUTOSTOP_MASK)
#define MTB_FLOW_AUTOHALT_MASK                   0x2u
#define MTB_FLOW_AUTOHALT_SHIFT                  1
#define MTB_FLOW_AUTOHALT_WIDTH                  1
#define MTB_FLOW_AUTOHALT(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_FLOW_AUTOHALT_SHIFT))&MTB_FLOW_AUTOHALT_MASK)
#define MTB_FLOW_WATERMARK_MASK                  0xFFFFFFF8u
#define MTB_FLOW_WATERMARK_SHIFT                 3
#define MTB_FLOW_WATERMARK_WIDTH                 29
#define MTB_FLOW_WATERMARK(x)                    (((uint32_t)(((uint32_t)(x))<<MTB_FLOW_WATERMARK_SHIFT))&MTB_FLOW_WATERMARK_MASK)
/* BASE Bit Fields */
#define MTB_BASE_BASEADDR_MASK                   0xFFFFFFFFu
#define MTB_BASE_BASEADDR_SHIFT                  0
#define MTB_BASE_BASEADDR_WIDTH                  32
#define MTB_BASE_BASEADDR(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_BASE_BASEADDR_SHIFT))&MTB_BASE_BASEADDR_MASK)
/* MODECTRL Bit Fields */
#define MTB_MODECTRL_MODECTRL_MASK               0xFFFFFFFFu
#define MTB_MODECTRL_MODECTRL_SHIFT              0
#define MTB_MODECTRL_MODECTRL_WIDTH              32
#define MTB_MODECTRL_MODECTRL(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_MODECTRL_MODECTRL_SHIFT))&MTB_MODECTRL_MODECTRL_MASK)
/* TAGSET Bit Fields */
#define MTB_TAGSET_TAGSET_MASK                   0xFFFFFFFFu
#define MTB_TAGSET_TAGSET_SHIFT                  0
#define MTB_TAGSET_TAGSET_WIDTH                  32
#define MTB_TAGSET_TAGSET(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_TAGSET_TAGSET_SHIFT))&MTB_TAGSET_TAGSET_MASK)
/* TAGCLEAR Bit Fields */
#define MTB_TAGCLEAR_TAGCLEAR_MASK               0xFFFFFFFFu
#define MTB_TAGCLEAR_TAGCLEAR_SHIFT              0
#define MTB_TAGCLEAR_TAGCLEAR_WIDTH              32
#define MTB_TAGCLEAR_TAGCLEAR(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_TAGCLEAR_TAGCLEAR_SHIFT))&MTB_TAGCLEAR_TAGCLEAR_MASK)
/* LOCKACCESS Bit Fields */
#define MTB_LOCKACCESS_LOCKACCESS_MASK           0xFFFFFFFFu
#define MTB_LOCKACCESS_LOCKACCESS_SHIFT          0
#define MTB_LOCKACCESS_LOCKACCESS_WIDTH          32
#define MTB_LOCKACCESS_LOCKACCESS(x)             (((uint32_t)(((uint32_t)(x))<<MTB_LOCKACCESS_LOCKACCESS_SHIFT))&MTB_LOCKACCESS_LOCKACCESS_MASK)
/* LOCKSTAT Bit Fields */
#define MTB_LOCKSTAT_LOCKSTAT_MASK               0xFFFFFFFFu
#define MTB_LOCKSTAT_LOCKSTAT_SHIFT              0
#define MTB_LOCKSTAT_LOCKSTAT_WIDTH              32
#define MTB_LOCKSTAT_LOCKSTAT(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_LOCKSTAT_LOCKSTAT_SHIFT))&MTB_LOCKSTAT_LOCKSTAT_MASK)
/* AUTHSTAT Bit Fields */
#define MTB_AUTHSTAT_BIT0_MASK                   0x1u
#define MTB_AUTHSTAT_BIT0_SHIFT                  0
#define MTB_AUTHSTAT_BIT0_WIDTH                  1
#define MTB_AUTHSTAT_BIT0(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_AUTHSTAT_BIT0_SHIFT))&MTB_AUTHSTAT_BIT0_MASK)
#define MTB_AUTHSTAT_BIT1_MASK                   0x2u
#define MTB_AUTHSTAT_BIT1_SHIFT                  1
#define MTB_AUTHSTAT_BIT1_WIDTH                  1
#define MTB_AUTHSTAT_BIT1(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_AUTHSTAT_BIT1_SHIFT))&MTB_AUTHSTAT_BIT1_MASK)
#define MTB_AUTHSTAT_BIT2_MASK                   0x4u
#define MTB_AUTHSTAT_BIT2_SHIFT                  2
#define MTB_AUTHSTAT_BIT2_WIDTH                  1
#define MTB_AUTHSTAT_BIT2(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_AUTHSTAT_BIT2_SHIFT))&MTB_AUTHSTAT_BIT2_MASK)
#define MTB_AUTHSTAT_BIT3_MASK                   0x8u
#define MTB_AUTHSTAT_BIT3_SHIFT                  3
#define MTB_AUTHSTAT_BIT3_WIDTH                  1
#define MTB_AUTHSTAT_BIT3(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_AUTHSTAT_BIT3_SHIFT))&MTB_AUTHSTAT_BIT3_MASK)
/* DEVICEARCH Bit Fields */
#define MTB_DEVICEARCH_DEVICEARCH_MASK           0xFFFFFFFFu
#define MTB_DEVICEARCH_DEVICEARCH_SHIFT          0
#define MTB_DEVICEARCH_DEVICEARCH_WIDTH          32
#define MTB_DEVICEARCH_DEVICEARCH(x)             (((uint32_t)(((uint32_t)(x))<<MTB_DEVICEARCH_DEVICEARCH_SHIFT))&MTB_DEVICEARCH_DEVICEARCH_MASK)
/* DEVICECFG Bit Fields */
#define MTB_DEVICECFG_DEVICECFG_MASK             0xFFFFFFFFu
#define MTB_DEVICECFG_DEVICECFG_SHIFT            0
#define MTB_DEVICECFG_DEVICECFG_WIDTH            32
#define MTB_DEVICECFG_DEVICECFG(x)               (((uint32_t)(((uint32_t)(x))<<MTB_DEVICECFG_DEVICECFG_SHIFT))&MTB_DEVICECFG_DEVICECFG_MASK)
/* DEVICETYPID Bit Fields */
#define MTB_DEVICETYPID_DEVICETYPID_MASK         0xFFFFFFFFu
#define MTB_DEVICETYPID_DEVICETYPID_SHIFT        0
#define MTB_DEVICETYPID_DEVICETYPID_WIDTH        32
#define MTB_DEVICETYPID_DEVICETYPID(x)           (((uint32_t)(((uint32_t)(x))<<MTB_DEVICETYPID_DEVICETYPID_SHIFT))&MTB_DEVICETYPID_DEVICETYPID_MASK)
/* PERIPHID Bit Fields */
#define MTB_PERIPHID_PERIPHID_MASK               0xFFFFFFFFu
#define MTB_PERIPHID_PERIPHID_SHIFT              0
#define MTB_PERIPHID_PERIPHID_WIDTH              32
#define MTB_PERIPHID_PERIPHID(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_PERIPHID_PERIPHID_SHIFT))&MTB_PERIPHID_PERIPHID_MASK)
/* COMPID Bit Fields */
#define MTB_COMPID_COMPID_MASK                   0xFFFFFFFFu
#define MTB_COMPID_COMPID_SHIFT                  0
#define MTB_COMPID_COMPID_WIDTH                  32
#define MTB_COMPID_COMPID(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_COMPID_COMPID_SHIFT))&MTB_COMPID_COMPID_MASK)

/*!
 * @}
 */ /* end of group MTB_Register_Masks */


/* MTB - Peripheral instance base addresses */
/** Peripheral MTB0 base address */
#define MTB0_BASE                                (0xF0000000u)
/** Peripheral MTB0 base pointer */
#define MTB0                                     ((MTB_Type *)MTB0_BASE)
#define MTB0_BASE_PTR                            (MTB0)
/** Array initializer of MTB peripheral base addresses */
#define MTB_BASE_ADDRS                           { MTB0_BASE }
/** Array initializer of MTB peripheral base pointers */
#define MTB_BASE_PTRS                            { MTB0 }

/* ----------------------------------------------------------------------------
   -- MTB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTB_Register_Accessor_Macros MTB - Register accessor macros
 * @{
 */


/* MTB - Register instance definitions */
/* MTB0 */
#define MTB0_POSITION                            MTB_POSITION_REG(MTB0)
#define MTB0_MASTER                              MTB_MASTER_REG(MTB0)
#define MTB0_FLOW                                MTB_FLOW_REG(MTB0)
#define MTB0_BASEr                               MTB_BASE_REG(MTB0)
#define MTB0_MODECTRL                            MTB_MODECTRL_REG(MTB0)
#define MTB0_TAGSET                              MTB_TAGSET_REG(MTB0)
#define MTB0_TAGCLEAR                            MTB_TAGCLEAR_REG(MTB0)
#define MTB0_LOCKACCESS                          MTB_LOCKACCESS_REG(MTB0)
#define MTB0_LOCKSTAT                            MTB_LOCKSTAT_REG(MTB0)
#define MTB0_AUTHSTAT                            MTB_AUTHSTAT_REG(MTB0)
#define MTB0_DEVICEARCH                          MTB_DEVICEARCH_REG(MTB0)
#define MTB0_DEVICECFG                           MTB_DEVICECFG_REG(MTB0)
#define MTB0_DEVICETYPID                         MTB_DEVICETYPID_REG(MTB0)
#define MTB0_PERIPHID4                           MTB_PERIPHID_REG(MTB0,0)
#define MTB0_PERIPHID5                           MTB_PERIPHID_REG(MTB0,1)
#define MTB0_PERIPHID6                           MTB_PERIPHID_REG(MTB0,2)
#define MTB0_PERIPHID7                           MTB_PERIPHID_REG(MTB0,3)
#define MTB0_PERIPHID0                           MTB_PERIPHID_REG(MTB0,4)
#define MTB0_PERIPHID1                           MTB_PERIPHID_REG(MTB0,5)
#define MTB0_PERIPHID2                           MTB_PERIPHID_REG(MTB0,6)
#define MTB0_PERIPHID3                           MTB_PERIPHID_REG(MTB0,7)
#define MTB0_COMPID0                             MTB_COMPID_REG(MTB0,0)
#define MTB0_COMPID1                             MTB_COMPID_REG(MTB0,1)
#define MTB0_COMPID2                             MTB_COMPID_REG(MTB0,2)
#define MTB0_COMPID3                             MTB_COMPID_REG(MTB0,3)

/* MTB - Register array accessors */
#define MTB0_PERIPHID(index)                     MTB_PERIPHID_REG(MTB0,index)
#define MTB0_COMPID(index)                       MTB_COMPID_REG(MTB0,index)

/*!
 * @}
 */ /* end of group MTB_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group MTB_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- NV Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Peripheral_Access_Layer NV Peripheral Access Layer
 * @{
 */

/** NV - Register Layout Typedef */
typedef struct {
  __I  uint8_t BACKKEY3;                           /**< Backdoor Comparison Key 3., offset: 0x0 */
  __I  uint8_t BACKKEY2;                           /**< Backdoor Comparison Key 2., offset: 0x1 */
  __I  uint8_t BACKKEY1;                           /**< Backdoor Comparison Key 1., offset: 0x2 */
  __I  uint8_t BACKKEY0;                           /**< Backdoor Comparison Key 0., offset: 0x3 */
  __I  uint8_t BACKKEY7;                           /**< Backdoor Comparison Key 7., offset: 0x4 */
  __I  uint8_t BACKKEY6;                           /**< Backdoor Comparison Key 6., offset: 0x5 */
  __I  uint8_t BACKKEY5;                           /**< Backdoor Comparison Key 5., offset: 0x6 */
  __I  uint8_t BACKKEY4;                           /**< Backdoor Comparison Key 4., offset: 0x7 */
  __I  uint8_t FPROT3;                             /**< Non-volatile P-Flash Protection 1 - Low Register, offset: 0x8 */
  __I  uint8_t FPROT2;                             /**< Non-volatile P-Flash Protection 1 - High Register, offset: 0x9 */
  __I  uint8_t FPROT1;                             /**< Non-volatile P-Flash Protection 0 - Low Register, offset: 0xA */
  __I  uint8_t FPROT0;                             /**< Non-volatile P-Flash Protection 0 - High Register, offset: 0xB */
  __I  uint8_t FSEC;                               /**< Non-volatile Flash Security Register, offset: 0xC */
  __I  uint8_t FOPT;                               /**< Non-volatile Flash Option Register, offset: 0xD */
} NV_Type, *NV_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Register_Accessor_Macros NV - Register accessor macros
 * @{
 */


/* NV - Register accessors */
#define NV_BACKKEY3_REG(base)                    ((base)->BACKKEY3)
#define NV_BACKKEY2_REG(base)                    ((base)->BACKKEY2)
#define NV_BACKKEY1_REG(base)                    ((base)->BACKKEY1)
#define NV_BACKKEY0_REG(base)                    ((base)->BACKKEY0)
#define NV_BACKKEY7_REG(base)                    ((base)->BACKKEY7)
#define NV_BACKKEY6_REG(base)                    ((base)->BACKKEY6)
#define NV_BACKKEY5_REG(base)                    ((base)->BACKKEY5)
#define NV_BACKKEY4_REG(base)                    ((base)->BACKKEY4)
#define NV_FPROT3_REG(base)                      ((base)->FPROT3)
#define NV_FPROT2_REG(base)                      ((base)->FPROT2)
#define NV_FPROT1_REG(base)                      ((base)->FPROT1)
#define NV_FPROT0_REG(base)                      ((base)->FPROT0)
#define NV_FSEC_REG(base)                        ((base)->FSEC)
#define NV_FOPT_REG(base)                        ((base)->FOPT)

/*!
 * @}
 */ /* end of group NV_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- NV Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Register_Masks NV Register Masks
 * @{
 */

/* BACKKEY3 Bit Fields */
#define NV_BACKKEY3_KEY_MASK                     0xFFu
#define NV_BACKKEY3_KEY_SHIFT                    0
#define NV_BACKKEY3_KEY_WIDTH                    8
#define NV_BACKKEY3_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY3_KEY_SHIFT))&NV_BACKKEY3_KEY_MASK)
/* BACKKEY2 Bit Fields */
#define NV_BACKKEY2_KEY_MASK                     0xFFu
#define NV_BACKKEY2_KEY_SHIFT                    0
#define NV_BACKKEY2_KEY_WIDTH                    8
#define NV_BACKKEY2_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY2_KEY_SHIFT))&NV_BACKKEY2_KEY_MASK)
/* BACKKEY1 Bit Fields */
#define NV_BACKKEY1_KEY_MASK                     0xFFu
#define NV_BACKKEY1_KEY_SHIFT                    0
#define NV_BACKKEY1_KEY_WIDTH                    8
#define NV_BACKKEY1_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY1_KEY_SHIFT))&NV_BACKKEY1_KEY_MASK)
/* BACKKEY0 Bit Fields */
#define NV_BACKKEY0_KEY_MASK                     0xFFu
#define NV_BACKKEY0_KEY_SHIFT                    0
#define NV_BACKKEY0_KEY_WIDTH                    8
#define NV_BACKKEY0_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY0_KEY_SHIFT))&NV_BACKKEY0_KEY_MASK)
/* BACKKEY7 Bit Fields */
#define NV_BACKKEY7_KEY_MASK                     0xFFu
#define NV_BACKKEY7_KEY_SHIFT                    0
#define NV_BACKKEY7_KEY_WIDTH                    8
#define NV_BACKKEY7_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY7_KEY_SHIFT))&NV_BACKKEY7_KEY_MASK)
/* BACKKEY6 Bit Fields */
#define NV_BACKKEY6_KEY_MASK                     0xFFu
#define NV_BACKKEY6_KEY_SHIFT                    0
#define NV_BACKKEY6_KEY_WIDTH                    8
#define NV_BACKKEY6_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY6_KEY_SHIFT))&NV_BACKKEY6_KEY_MASK)
/* BACKKEY5 Bit Fields */
#define NV_BACKKEY5_KEY_MASK                     0xFFu
#define NV_BACKKEY5_KEY_SHIFT                    0
#define NV_BACKKEY5_KEY_WIDTH                    8
#define NV_BACKKEY5_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY5_KEY_SHIFT))&NV_BACKKEY5_KEY_MASK)
/* BACKKEY4 Bit Fields */
#define NV_BACKKEY4_KEY_MASK                     0xFFu
#define NV_BACKKEY4_KEY_SHIFT                    0
#define NV_BACKKEY4_KEY_WIDTH                    8
#define NV_BACKKEY4_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY4_KEY_SHIFT))&NV_BACKKEY4_KEY_MASK)
/* FPROT3 Bit Fields */
#define NV_FPROT3_PROT_MASK                      0xFFu
#define NV_FPROT3_PROT_SHIFT                     0
#define NV_FPROT3_PROT_WIDTH                     8
#define NV_FPROT3_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT3_PROT_SHIFT))&NV_FPROT3_PROT_MASK)
/* FPROT2 Bit Fields */
#define NV_FPROT2_PROT_MASK                      0xFFu
#define NV_FPROT2_PROT_SHIFT                     0
#define NV_FPROT2_PROT_WIDTH                     8
#define NV_FPROT2_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT2_PROT_SHIFT))&NV_FPROT2_PROT_MASK)
/* FPROT1 Bit Fields */
#define NV_FPROT1_PROT_MASK                      0xFFu
#define NV_FPROT1_PROT_SHIFT                     0
#define NV_FPROT1_PROT_WIDTH                     8
#define NV_FPROT1_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT1_PROT_SHIFT))&NV_FPROT1_PROT_MASK)
/* FPROT0 Bit Fields */
#define NV_FPROT0_PROT_MASK                      0xFFu
#define NV_FPROT0_PROT_SHIFT                     0
#define NV_FPROT0_PROT_WIDTH                     8
#define NV_FPROT0_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT0_PROT_SHIFT))&NV_FPROT0_PROT_MASK)
/* FSEC Bit Fields */
#define NV_FSEC_SEC_MASK                         0x3u
#define NV_FSEC_SEC_SHIFT                        0
#define NV_FSEC_SEC_WIDTH                        2
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<NV_FSEC_SEC_SHIFT))&NV_FSEC_SEC_MASK)
#define NV_FSEC_FSLACC_MASK                      0xCu
#define NV_FSEC_FSLACC_SHIFT                     2
#define NV_FSEC_FSLACC_WIDTH                     2
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FSEC_FSLACC_SHIFT))&NV_FSEC_FSLACC_MASK)
#define NV_FSEC_MEEN_MASK                        0x30u
#define NV_FSEC_MEEN_SHIFT                       4
#define NV_FSEC_MEEN_WIDTH                       2
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x))<<NV_FSEC_MEEN_SHIFT))&NV_FSEC_MEEN_MASK)
#define NV_FSEC_KEYEN_MASK                       0xC0u
#define NV_FSEC_KEYEN_SHIFT                      6
#define NV_FSEC_KEYEN_WIDTH                      2
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FSEC_KEYEN_SHIFT))&NV_FSEC_KEYEN_MASK)
/* FOPT Bit Fields */
#define NV_FOPT_LPBOOT0_MASK                     0x1u
#define NV_FOPT_LPBOOT0_SHIFT                    0
#define NV_FOPT_LPBOOT0_WIDTH                    1
#define NV_FOPT_LPBOOT0(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FOPT_LPBOOT0_SHIFT))&NV_FOPT_LPBOOT0_MASK)
#define NV_FOPT_BOOTPIN_OPT_MASK                 0x2u
#define NV_FOPT_BOOTPIN_OPT_SHIFT                1
#define NV_FOPT_BOOTPIN_OPT_WIDTH                1
#define NV_FOPT_BOOTPIN_OPT(x)                   (((uint8_t)(((uint8_t)(x))<<NV_FOPT_BOOTPIN_OPT_SHIFT))&NV_FOPT_BOOTPIN_OPT_MASK)
#define NV_FOPT_NMI_DIS_MASK                     0x4u
#define NV_FOPT_NMI_DIS_SHIFT                    2
#define NV_FOPT_NMI_DIS_WIDTH                    1
#define NV_FOPT_NMI_DIS(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FOPT_NMI_DIS_SHIFT))&NV_FOPT_NMI_DIS_MASK)
#define NV_FOPT_RESET_PIN_CFG_MASK               0x8u
#define NV_FOPT_RESET_PIN_CFG_SHIFT              3
#define NV_FOPT_RESET_PIN_CFG_WIDTH              1
#define NV_FOPT_RESET_PIN_CFG(x)                 (((uint8_t)(((uint8_t)(x))<<NV_FOPT_RESET_PIN_CFG_SHIFT))&NV_FOPT_RESET_PIN_CFG_MASK)
#define NV_FOPT_LPBOOT1_MASK                     0x10u
#define NV_FOPT_LPBOOT1_SHIFT                    4
#define NV_FOPT_LPBOOT1_WIDTH                    1
#define NV_FOPT_LPBOOT1(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FOPT_LPBOOT1_SHIFT))&NV_FOPT_LPBOOT1_MASK)
#define NV_FOPT_FAST_INIT_MASK                   0x20u
#define NV_FOPT_FAST_INIT_SHIFT                  5
#define NV_FOPT_FAST_INIT_WIDTH                  1
#define NV_FOPT_FAST_INIT(x)                     (((uint8_t)(((uint8_t)(x))<<NV_FOPT_FAST_INIT_SHIFT))&NV_FOPT_FAST_INIT_MASK)
#define NV_FOPT_BOOTSRC_SEL_MASK                 0xC0u
#define NV_FOPT_BOOTSRC_SEL_SHIFT                6
#define NV_FOPT_BOOTSRC_SEL_WIDTH                2
#define NV_FOPT_BOOTSRC_SEL(x)                   (((uint8_t)(((uint8_t)(x))<<NV_FOPT_BOOTSRC_SEL_SHIFT))&NV_FOPT_BOOTSRC_SEL_MASK)

/*!
 * @}
 */ /* end of group NV_Register_Masks */


/* NV - Peripheral instance base addresses */
/** Peripheral FTFA_FlashConfig base address */
#define FTFA_FlashConfig_BASE                    (0x400u)
/** Peripheral FTFA_FlashConfig base pointer */
#define FTFA_FlashConfig                         ((NV_Type *)FTFA_FlashConfig_BASE)
#define FTFA_FlashConfig_BASE_PTR                (FTFA_FlashConfig)
/** Array initializer of NV peripheral base addresses */
#define NV_BASE_ADDRS                            { FTFA_FlashConfig_BASE }
/** Array initializer of NV peripheral base pointers */
#define NV_BASE_PTRS                             { FTFA_FlashConfig }

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Register_Accessor_Macros NV - Register accessor macros
 * @{
 */


/* NV - Register instance definitions */
/* FTFA_FlashConfig */
#define NV_BACKKEY3                              NV_BACKKEY3_REG(FTFA_FlashConfig)
#define NV_BACKKEY2                              NV_BACKKEY2_REG(FTFA_FlashConfig)
#define NV_BACKKEY1                              NV_BACKKEY1_REG(FTFA_FlashConfig)
#define NV_BACKKEY0                              NV_BACKKEY0_REG(FTFA_FlashConfig)
#define NV_BACKKEY7                              NV_BACKKEY7_REG(FTFA_FlashConfig)
#define NV_BACKKEY6                              NV_BACKKEY6_REG(FTFA_FlashConfig)
#define NV_BACKKEY5                              NV_BACKKEY5_REG(FTFA_FlashConfig)
#define NV_BACKKEY4                              NV_BACKKEY4_REG(FTFA_FlashConfig)
#define NV_FPROT3                                NV_FPROT3_REG(FTFA_FlashConfig)
#define NV_FPROT2                                NV_FPROT2_REG(FTFA_FlashConfig)
#define NV_FPROT1                                NV_FPROT1_REG(FTFA_FlashConfig)
#define NV_FPROT0                                NV_FPROT0_REG(FTFA_FlashConfig)
#define NV_FSEC                                  NV_FSEC_REG(FTFA_FlashConfig)
#define NV_FOPT                                  NV_FOPT_REG(FTFA_FlashConfig)

/*!
 * @}
 */ /* end of group NV_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group NV_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PCC0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC0_Peripheral_Access_Layer PCC0 Peripheral Access Layer
 * @{
 */

/** PCC0 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t PCC_DMA0;                          /**< PCC_DMA0 Register, offset: 0x20 */
       uint8_t RESERVED_1[92];
  __IO uint32_t PCC_FLASH;                         /**< PCC_FLASH Register, offset: 0x80 */
  __IO uint32_t PCC_DMAMUX0;                       /**< PCC_DMAMUX0 Register, offset: 0x84 */
       uint8_t RESERVED_2[8];
  __IO uint32_t PCC_INTMUX0;                       /**< PCC_INTMUX0 Register, offset: 0x90 */
       uint8_t RESERVED_3[36];
  __IO uint32_t PCC_TPM2;                          /**< PCC_TPM2 Register, offset: 0xB8 */
       uint8_t RESERVED_4[4];
  __IO uint32_t PCC_LPIT0;                         /**< PCC_LPIT0 Register, offset: 0xC0 */
       uint8_t RESERVED_5[12];
  __IO uint32_t PCC_LPTMR0;                        /**< PCC_LPTMR0 Register, offset: 0xD0 */
       uint8_t RESERVED_6[12];
  __IO uint32_t PCC_RTC;                           /**< PCC_RTC Register, offset: 0xE0 */
       uint8_t RESERVED_7[20];
  __IO uint32_t PCC_LPSPI2;                        /**< PCC_LPSPI2 Register, offset: 0xF8 */
       uint8_t RESERVED_8[12];
  __IO uint32_t PCC_LPI2C2;                        /**< PCC_LPI2C2 Register, offset: 0x108 */
       uint8_t RESERVED_9[12];
  __IO uint32_t PCC_LPUART2;                       /**< PCC_LPUART2 Register, offset: 0x118 */
       uint8_t RESERVED_10[20];
  __IO uint32_t PCC_SAI0;                          /**< PCC_SAI0 Register, offset: 0x130 */
       uint8_t RESERVED_11[4];
  __IO uint32_t PCC_EVMSIM0;                       /**< PCC_EVMSIM0 Register, offset: 0x138 */
       uint8_t RESERVED_12[24];
  __IO uint32_t PCC_USB0FS;                        /**< PCC_USB0FS Register, offset: 0x154 */
       uint8_t RESERVED_13[16];
  __IO uint32_t PCC_PORTA;                         /**< PCC_PORTA Register, offset: 0x168 */
  __IO uint32_t PCC_PORTB;                         /**< PCC_PORTB Register, offset: 0x16C */
  __IO uint32_t PCC_PORTC;                         /**< PCC_PORTC Register, offset: 0x170 */
  __IO uint32_t PCC_PORTD;                         /**< PCC_PORTD Register, offset: 0x174 */
  __IO uint32_t PCC_PORTE;                         /**< PCC_PORTE Register, offset: 0x178 */
       uint8_t RESERVED_14[12];
  __IO uint32_t PCC_TSI0;                          /**< PCC_TSI0 Register, offset: 0x188 */
       uint8_t RESERVED_15[12];
  __IO uint32_t PCC_ADC0;                          /**< PCC_ADC0 Register, offset: 0x198 */
       uint8_t RESERVED_16[12];
  __IO uint32_t PCC_DAC0;                          /**< PCC_DAC0 Register, offset: 0x1A8 */
       uint8_t RESERVED_17[12];
  __IO uint32_t PCC_CMP0;                          /**< PCC_CMP0 Register, offset: 0x1B8 */
       uint8_t RESERVED_18[12];
  __IO uint32_t PCC_VREF;                          /**< PCC_VREF Register, offset: 0x1C8 */
       uint8_t RESERVED_19[20];
  __IO uint32_t PCC_CRC;                           /**< PCC_CRC Register, offset: 0x1E0 */
} PCC0_Type, *PCC0_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PCC0 - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC0_Register_Accessor_Macros PCC0 - Register accessor macros
 * @{
 */


/* PCC0 - Register accessors */
#define PCC0_PCC_DMA0_REG(base)                  ((base)->PCC_DMA0)
#define PCC0_PCC_FLASH_REG(base)                 ((base)->PCC_FLASH)
#define PCC0_PCC_DMAMUX0_REG(base)               ((base)->PCC_DMAMUX0)
#define PCC0_PCC_INTMUX0_REG(base)               ((base)->PCC_INTMUX0)
#define PCC0_PCC_TPM2_REG(base)                  ((base)->PCC_TPM2)
#define PCC0_PCC_LPIT0_REG(base)                 ((base)->PCC_LPIT0)
#define PCC0_PCC_LPTMR0_REG(base)                ((base)->PCC_LPTMR0)
#define PCC0_PCC_RTC_REG(base)                   ((base)->PCC_RTC)
#define PCC0_PCC_LPSPI2_REG(base)                ((base)->PCC_LPSPI2)
#define PCC0_PCC_LPI2C2_REG(base)                ((base)->PCC_LPI2C2)
#define PCC0_PCC_LPUART2_REG(base)               ((base)->PCC_LPUART2)
#define PCC0_PCC_SAI0_REG(base)                  ((base)->PCC_SAI0)
#define PCC0_PCC_EVMSIM0_REG(base)               ((base)->PCC_EVMSIM0)
#define PCC0_PCC_USB0FS_REG(base)                ((base)->PCC_USB0FS)
#define PCC0_PCC_PORTA_REG(base)                 ((base)->PCC_PORTA)
#define PCC0_PCC_PORTB_REG(base)                 ((base)->PCC_PORTB)
#define PCC0_PCC_PORTC_REG(base)                 ((base)->PCC_PORTC)
#define PCC0_PCC_PORTD_REG(base)                 ((base)->PCC_PORTD)
#define PCC0_PCC_PORTE_REG(base)                 ((base)->PCC_PORTE)
#define PCC0_PCC_TSI0_REG(base)                  ((base)->PCC_TSI0)
#define PCC0_PCC_ADC0_REG(base)                  ((base)->PCC_ADC0)
#define PCC0_PCC_DAC0_REG(base)                  ((base)->PCC_DAC0)
#define PCC0_PCC_CMP0_REG(base)                  ((base)->PCC_CMP0)
#define PCC0_PCC_VREF_REG(base)                  ((base)->PCC_VREF)
#define PCC0_PCC_CRC_REG(base)                   ((base)->PCC_CRC)

/*!
 * @}
 */ /* end of group PCC0_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PCC0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC0_Register_Masks PCC0 Register Masks
 * @{
 */

/* PCC_DMA0 Bit Fields */
#define PCC0_PCC_DMA0_INUSE_MASK                 0x20000000u
#define PCC0_PCC_DMA0_INUSE_SHIFT                29
#define PCC0_PCC_DMA0_INUSE_WIDTH                1
#define PCC0_PCC_DMA0_INUSE(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_DMA0_INUSE_SHIFT))&PCC0_PCC_DMA0_INUSE_MASK)
#define PCC0_PCC_DMA0_CGC_MASK                   0x40000000u
#define PCC0_PCC_DMA0_CGC_SHIFT                  30
#define PCC0_PCC_DMA0_CGC_WIDTH                  1
#define PCC0_PCC_DMA0_CGC(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_DMA0_CGC_SHIFT))&PCC0_PCC_DMA0_CGC_MASK)
#define PCC0_PCC_DMA0_PR_MASK                    0x80000000u
#define PCC0_PCC_DMA0_PR_SHIFT                   31
#define PCC0_PCC_DMA0_PR_WIDTH                   1
#define PCC0_PCC_DMA0_PR(x)                      (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_DMA0_PR_SHIFT))&PCC0_PCC_DMA0_PR_MASK)
/* PCC_FLASH Bit Fields */
#define PCC0_PCC_FLASH_INUSE_MASK                0x20000000u
#define PCC0_PCC_FLASH_INUSE_SHIFT               29
#define PCC0_PCC_FLASH_INUSE_WIDTH               1
#define PCC0_PCC_FLASH_INUSE(x)                  (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_FLASH_INUSE_SHIFT))&PCC0_PCC_FLASH_INUSE_MASK)
#define PCC0_PCC_FLASH_CGC_MASK                  0x40000000u
#define PCC0_PCC_FLASH_CGC_SHIFT                 30
#define PCC0_PCC_FLASH_CGC_WIDTH                 1
#define PCC0_PCC_FLASH_CGC(x)                    (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_FLASH_CGC_SHIFT))&PCC0_PCC_FLASH_CGC_MASK)
#define PCC0_PCC_FLASH_PR_MASK                   0x80000000u
#define PCC0_PCC_FLASH_PR_SHIFT                  31
#define PCC0_PCC_FLASH_PR_WIDTH                  1
#define PCC0_PCC_FLASH_PR(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_FLASH_PR_SHIFT))&PCC0_PCC_FLASH_PR_MASK)
/* PCC_DMAMUX0 Bit Fields */
#define PCC0_PCC_DMAMUX0_INUSE_MASK              0x20000000u
#define PCC0_PCC_DMAMUX0_INUSE_SHIFT             29
#define PCC0_PCC_DMAMUX0_INUSE_WIDTH             1
#define PCC0_PCC_DMAMUX0_INUSE(x)                (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_DMAMUX0_INUSE_SHIFT))&PCC0_PCC_DMAMUX0_INUSE_MASK)
#define PCC0_PCC_DMAMUX0_CGC_MASK                0x40000000u
#define PCC0_PCC_DMAMUX0_CGC_SHIFT               30
#define PCC0_PCC_DMAMUX0_CGC_WIDTH               1
#define PCC0_PCC_DMAMUX0_CGC(x)                  (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_DMAMUX0_CGC_SHIFT))&PCC0_PCC_DMAMUX0_CGC_MASK)
#define PCC0_PCC_DMAMUX0_PR_MASK                 0x80000000u
#define PCC0_PCC_DMAMUX0_PR_SHIFT                31
#define PCC0_PCC_DMAMUX0_PR_WIDTH                1
#define PCC0_PCC_DMAMUX0_PR(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_DMAMUX0_PR_SHIFT))&PCC0_PCC_DMAMUX0_PR_MASK)
/* PCC_INTMUX0 Bit Fields */
#define PCC0_PCC_INTMUX0_INUSE_MASK              0x20000000u
#define PCC0_PCC_INTMUX0_INUSE_SHIFT             29
#define PCC0_PCC_INTMUX0_INUSE_WIDTH             1
#define PCC0_PCC_INTMUX0_INUSE(x)                (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_INTMUX0_INUSE_SHIFT))&PCC0_PCC_INTMUX0_INUSE_MASK)
#define PCC0_PCC_INTMUX0_CGC_MASK                0x40000000u
#define PCC0_PCC_INTMUX0_CGC_SHIFT               30
#define PCC0_PCC_INTMUX0_CGC_WIDTH               1
#define PCC0_PCC_INTMUX0_CGC(x)                  (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_INTMUX0_CGC_SHIFT))&PCC0_PCC_INTMUX0_CGC_MASK)
#define PCC0_PCC_INTMUX0_PR_MASK                 0x80000000u
#define PCC0_PCC_INTMUX0_PR_SHIFT                31
#define PCC0_PCC_INTMUX0_PR_WIDTH                1
#define PCC0_PCC_INTMUX0_PR(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_INTMUX0_PR_SHIFT))&PCC0_PCC_INTMUX0_PR_MASK)
/* PCC_TPM2 Bit Fields */
#define PCC0_PCC_TPM2_PCS_MASK                   0x7000000u
#define PCC0_PCC_TPM2_PCS_SHIFT                  24
#define PCC0_PCC_TPM2_PCS_WIDTH                  3
#define PCC0_PCC_TPM2_PCS(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_TPM2_PCS_SHIFT))&PCC0_PCC_TPM2_PCS_MASK)
#define PCC0_PCC_TPM2_INUSE_MASK                 0x20000000u
#define PCC0_PCC_TPM2_INUSE_SHIFT                29
#define PCC0_PCC_TPM2_INUSE_WIDTH                1
#define PCC0_PCC_TPM2_INUSE(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_TPM2_INUSE_SHIFT))&PCC0_PCC_TPM2_INUSE_MASK)
#define PCC0_PCC_TPM2_CGC_MASK                   0x40000000u
#define PCC0_PCC_TPM2_CGC_SHIFT                  30
#define PCC0_PCC_TPM2_CGC_WIDTH                  1
#define PCC0_PCC_TPM2_CGC(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_TPM2_CGC_SHIFT))&PCC0_PCC_TPM2_CGC_MASK)
#define PCC0_PCC_TPM2_PR_MASK                    0x80000000u
#define PCC0_PCC_TPM2_PR_SHIFT                   31
#define PCC0_PCC_TPM2_PR_WIDTH                   1
#define PCC0_PCC_TPM2_PR(x)                      (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_TPM2_PR_SHIFT))&PCC0_PCC_TPM2_PR_MASK)
/* PCC_LPIT0 Bit Fields */
#define PCC0_PCC_LPIT0_PCS_MASK                  0x7000000u
#define PCC0_PCC_LPIT0_PCS_SHIFT                 24
#define PCC0_PCC_LPIT0_PCS_WIDTH                 3
#define PCC0_PCC_LPIT0_PCS(x)                    (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPIT0_PCS_SHIFT))&PCC0_PCC_LPIT0_PCS_MASK)
#define PCC0_PCC_LPIT0_INUSE_MASK                0x20000000u
#define PCC0_PCC_LPIT0_INUSE_SHIFT               29
#define PCC0_PCC_LPIT0_INUSE_WIDTH               1
#define PCC0_PCC_LPIT0_INUSE(x)                  (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPIT0_INUSE_SHIFT))&PCC0_PCC_LPIT0_INUSE_MASK)
#define PCC0_PCC_LPIT0_CGC_MASK                  0x40000000u
#define PCC0_PCC_LPIT0_CGC_SHIFT                 30
#define PCC0_PCC_LPIT0_CGC_WIDTH                 1
#define PCC0_PCC_LPIT0_CGC(x)                    (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPIT0_CGC_SHIFT))&PCC0_PCC_LPIT0_CGC_MASK)
#define PCC0_PCC_LPIT0_PR_MASK                   0x80000000u
#define PCC0_PCC_LPIT0_PR_SHIFT                  31
#define PCC0_PCC_LPIT0_PR_WIDTH                  1
#define PCC0_PCC_LPIT0_PR(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPIT0_PR_SHIFT))&PCC0_PCC_LPIT0_PR_MASK)
/* PCC_LPTMR0 Bit Fields */
#define PCC0_PCC_LPTMR0_INUSE_MASK               0x20000000u
#define PCC0_PCC_LPTMR0_INUSE_SHIFT              29
#define PCC0_PCC_LPTMR0_INUSE_WIDTH              1
#define PCC0_PCC_LPTMR0_INUSE(x)                 (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPTMR0_INUSE_SHIFT))&PCC0_PCC_LPTMR0_INUSE_MASK)
#define PCC0_PCC_LPTMR0_CGC_MASK                 0x40000000u
#define PCC0_PCC_LPTMR0_CGC_SHIFT                30
#define PCC0_PCC_LPTMR0_CGC_WIDTH                1
#define PCC0_PCC_LPTMR0_CGC(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPTMR0_CGC_SHIFT))&PCC0_PCC_LPTMR0_CGC_MASK)
#define PCC0_PCC_LPTMR0_PR_MASK                  0x80000000u
#define PCC0_PCC_LPTMR0_PR_SHIFT                 31
#define PCC0_PCC_LPTMR0_PR_WIDTH                 1
#define PCC0_PCC_LPTMR0_PR(x)                    (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPTMR0_PR_SHIFT))&PCC0_PCC_LPTMR0_PR_MASK)
/* PCC_RTC Bit Fields */
#define PCC0_PCC_RTC_INUSE_MASK                  0x20000000u
#define PCC0_PCC_RTC_INUSE_SHIFT                 29
#define PCC0_PCC_RTC_INUSE_WIDTH                 1
#define PCC0_PCC_RTC_INUSE(x)                    (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_RTC_INUSE_SHIFT))&PCC0_PCC_RTC_INUSE_MASK)
#define PCC0_PCC_RTC_CGC_MASK                    0x40000000u
#define PCC0_PCC_RTC_CGC_SHIFT                   30
#define PCC0_PCC_RTC_CGC_WIDTH                   1
#define PCC0_PCC_RTC_CGC(x)                      (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_RTC_CGC_SHIFT))&PCC0_PCC_RTC_CGC_MASK)
#define PCC0_PCC_RTC_PR_MASK                     0x80000000u
#define PCC0_PCC_RTC_PR_SHIFT                    31
#define PCC0_PCC_RTC_PR_WIDTH                    1
#define PCC0_PCC_RTC_PR(x)                       (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_RTC_PR_SHIFT))&PCC0_PCC_RTC_PR_MASK)
/* PCC_LPSPI2 Bit Fields */
#define PCC0_PCC_LPSPI2_PCS_MASK                 0x7000000u
#define PCC0_PCC_LPSPI2_PCS_SHIFT                24
#define PCC0_PCC_LPSPI2_PCS_WIDTH                3
#define PCC0_PCC_LPSPI2_PCS(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPSPI2_PCS_SHIFT))&PCC0_PCC_LPSPI2_PCS_MASK)
#define PCC0_PCC_LPSPI2_INUSE_MASK               0x20000000u
#define PCC0_PCC_LPSPI2_INUSE_SHIFT              29
#define PCC0_PCC_LPSPI2_INUSE_WIDTH              1
#define PCC0_PCC_LPSPI2_INUSE(x)                 (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPSPI2_INUSE_SHIFT))&PCC0_PCC_LPSPI2_INUSE_MASK)
#define PCC0_PCC_LPSPI2_CGC_MASK                 0x40000000u
#define PCC0_PCC_LPSPI2_CGC_SHIFT                30
#define PCC0_PCC_LPSPI2_CGC_WIDTH                1
#define PCC0_PCC_LPSPI2_CGC(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPSPI2_CGC_SHIFT))&PCC0_PCC_LPSPI2_CGC_MASK)
#define PCC0_PCC_LPSPI2_PR_MASK                  0x80000000u
#define PCC0_PCC_LPSPI2_PR_SHIFT                 31
#define PCC0_PCC_LPSPI2_PR_WIDTH                 1
#define PCC0_PCC_LPSPI2_PR(x)                    (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPSPI2_PR_SHIFT))&PCC0_PCC_LPSPI2_PR_MASK)
/* PCC_LPI2C2 Bit Fields */
#define PCC0_PCC_LPI2C2_PCS_MASK                 0x7000000u
#define PCC0_PCC_LPI2C2_PCS_SHIFT                24
#define PCC0_PCC_LPI2C2_PCS_WIDTH                3
#define PCC0_PCC_LPI2C2_PCS(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPI2C2_PCS_SHIFT))&PCC0_PCC_LPI2C2_PCS_MASK)
#define PCC0_PCC_LPI2C2_INUSE_MASK               0x20000000u
#define PCC0_PCC_LPI2C2_INUSE_SHIFT              29
#define PCC0_PCC_LPI2C2_INUSE_WIDTH              1
#define PCC0_PCC_LPI2C2_INUSE(x)                 (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPI2C2_INUSE_SHIFT))&PCC0_PCC_LPI2C2_INUSE_MASK)
#define PCC0_PCC_LPI2C2_CGC_MASK                 0x40000000u
#define PCC0_PCC_LPI2C2_CGC_SHIFT                30
#define PCC0_PCC_LPI2C2_CGC_WIDTH                1
#define PCC0_PCC_LPI2C2_CGC(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPI2C2_CGC_SHIFT))&PCC0_PCC_LPI2C2_CGC_MASK)
#define PCC0_PCC_LPI2C2_PR_MASK                  0x80000000u
#define PCC0_PCC_LPI2C2_PR_SHIFT                 31
#define PCC0_PCC_LPI2C2_PR_WIDTH                 1
#define PCC0_PCC_LPI2C2_PR(x)                    (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPI2C2_PR_SHIFT))&PCC0_PCC_LPI2C2_PR_MASK)
/* PCC_LPUART2 Bit Fields */
#define PCC0_PCC_LPUART2_PCS_MASK                0x7000000u
#define PCC0_PCC_LPUART2_PCS_SHIFT               24
#define PCC0_PCC_LPUART2_PCS_WIDTH               3
#define PCC0_PCC_LPUART2_PCS(x)                  (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPUART2_PCS_SHIFT))&PCC0_PCC_LPUART2_PCS_MASK)
#define PCC0_PCC_LPUART2_INUSE_MASK              0x20000000u
#define PCC0_PCC_LPUART2_INUSE_SHIFT             29
#define PCC0_PCC_LPUART2_INUSE_WIDTH             1
#define PCC0_PCC_LPUART2_INUSE(x)                (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPUART2_INUSE_SHIFT))&PCC0_PCC_LPUART2_INUSE_MASK)
#define PCC0_PCC_LPUART2_CGC_MASK                0x40000000u
#define PCC0_PCC_LPUART2_CGC_SHIFT               30
#define PCC0_PCC_LPUART2_CGC_WIDTH               1
#define PCC0_PCC_LPUART2_CGC(x)                  (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPUART2_CGC_SHIFT))&PCC0_PCC_LPUART2_CGC_MASK)
#define PCC0_PCC_LPUART2_PR_MASK                 0x80000000u
#define PCC0_PCC_LPUART2_PR_SHIFT                31
#define PCC0_PCC_LPUART2_PR_WIDTH                1
#define PCC0_PCC_LPUART2_PR(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_LPUART2_PR_SHIFT))&PCC0_PCC_LPUART2_PR_MASK)
/* PCC_SAI0 Bit Fields */
#define PCC0_PCC_SAI0_PCS_MASK                   0x7000000u
#define PCC0_PCC_SAI0_PCS_SHIFT                  24
#define PCC0_PCC_SAI0_PCS_WIDTH                  3
#define PCC0_PCC_SAI0_PCS(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_SAI0_PCS_SHIFT))&PCC0_PCC_SAI0_PCS_MASK)
#define PCC0_PCC_SAI0_INUSE_MASK                 0x20000000u
#define PCC0_PCC_SAI0_INUSE_SHIFT                29
#define PCC0_PCC_SAI0_INUSE_WIDTH                1
#define PCC0_PCC_SAI0_INUSE(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_SAI0_INUSE_SHIFT))&PCC0_PCC_SAI0_INUSE_MASK)
#define PCC0_PCC_SAI0_CGC_MASK                   0x40000000u
#define PCC0_PCC_SAI0_CGC_SHIFT                  30
#define PCC0_PCC_SAI0_CGC_WIDTH                  1
#define PCC0_PCC_SAI0_CGC(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_SAI0_CGC_SHIFT))&PCC0_PCC_SAI0_CGC_MASK)
#define PCC0_PCC_SAI0_PR_MASK                    0x80000000u
#define PCC0_PCC_SAI0_PR_SHIFT                   31
#define PCC0_PCC_SAI0_PR_WIDTH                   1
#define PCC0_PCC_SAI0_PR(x)                      (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_SAI0_PR_SHIFT))&PCC0_PCC_SAI0_PR_MASK)
/* PCC_EVMSIM0 Bit Fields */
#define PCC0_PCC_EVMSIM0_PCS_MASK                0x7000000u
#define PCC0_PCC_EVMSIM0_PCS_SHIFT               24
#define PCC0_PCC_EVMSIM0_PCS_WIDTH               3
#define PCC0_PCC_EVMSIM0_PCS(x)                  (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_EVMSIM0_PCS_SHIFT))&PCC0_PCC_EVMSIM0_PCS_MASK)
#define PCC0_PCC_EVMSIM0_INUSE_MASK              0x20000000u
#define PCC0_PCC_EVMSIM0_INUSE_SHIFT             29
#define PCC0_PCC_EVMSIM0_INUSE_WIDTH             1
#define PCC0_PCC_EVMSIM0_INUSE(x)                (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_EVMSIM0_INUSE_SHIFT))&PCC0_PCC_EVMSIM0_INUSE_MASK)
#define PCC0_PCC_EVMSIM0_CGC_MASK                0x40000000u
#define PCC0_PCC_EVMSIM0_CGC_SHIFT               30
#define PCC0_PCC_EVMSIM0_CGC_WIDTH               1
#define PCC0_PCC_EVMSIM0_CGC(x)                  (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_EVMSIM0_CGC_SHIFT))&PCC0_PCC_EVMSIM0_CGC_MASK)
#define PCC0_PCC_EVMSIM0_PR_MASK                 0x80000000u
#define PCC0_PCC_EVMSIM0_PR_SHIFT                31
#define PCC0_PCC_EVMSIM0_PR_WIDTH                1
#define PCC0_PCC_EVMSIM0_PR(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_EVMSIM0_PR_SHIFT))&PCC0_PCC_EVMSIM0_PR_MASK)
/* PCC_USB0FS Bit Fields */
#define PCC0_PCC_USB0FS_PCD_MASK                 0x7u
#define PCC0_PCC_USB0FS_PCD_SHIFT                0
#define PCC0_PCC_USB0FS_PCD_WIDTH                3
#define PCC0_PCC_USB0FS_PCD(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_USB0FS_PCD_SHIFT))&PCC0_PCC_USB0FS_PCD_MASK)
#define PCC0_PCC_USB0FS_FRAC_MASK                0x8u
#define PCC0_PCC_USB0FS_FRAC_SHIFT               3
#define PCC0_PCC_USB0FS_FRAC_WIDTH               1
#define PCC0_PCC_USB0FS_FRAC(x)                  (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_USB0FS_FRAC_SHIFT))&PCC0_PCC_USB0FS_FRAC_MASK)
#define PCC0_PCC_USB0FS_PCS_MASK                 0x7000000u
#define PCC0_PCC_USB0FS_PCS_SHIFT                24
#define PCC0_PCC_USB0FS_PCS_WIDTH                3
#define PCC0_PCC_USB0FS_PCS(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_USB0FS_PCS_SHIFT))&PCC0_PCC_USB0FS_PCS_MASK)
#define PCC0_PCC_USB0FS_INUSE_MASK               0x20000000u
#define PCC0_PCC_USB0FS_INUSE_SHIFT              29
#define PCC0_PCC_USB0FS_INUSE_WIDTH              1
#define PCC0_PCC_USB0FS_INUSE(x)                 (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_USB0FS_INUSE_SHIFT))&PCC0_PCC_USB0FS_INUSE_MASK)
#define PCC0_PCC_USB0FS_CGC_MASK                 0x40000000u
#define PCC0_PCC_USB0FS_CGC_SHIFT                30
#define PCC0_PCC_USB0FS_CGC_WIDTH                1
#define PCC0_PCC_USB0FS_CGC(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_USB0FS_CGC_SHIFT))&PCC0_PCC_USB0FS_CGC_MASK)
#define PCC0_PCC_USB0FS_PR_MASK                  0x80000000u
#define PCC0_PCC_USB0FS_PR_SHIFT                 31
#define PCC0_PCC_USB0FS_PR_WIDTH                 1
#define PCC0_PCC_USB0FS_PR(x)                    (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_USB0FS_PR_SHIFT))&PCC0_PCC_USB0FS_PR_MASK)
/* PCC_PORTA Bit Fields */
#define PCC0_PCC_PORTA_INUSE_MASK                0x20000000u
#define PCC0_PCC_PORTA_INUSE_SHIFT               29
#define PCC0_PCC_PORTA_INUSE_WIDTH               1
#define PCC0_PCC_PORTA_INUSE(x)                  (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTA_INUSE_SHIFT))&PCC0_PCC_PORTA_INUSE_MASK)
#define PCC0_PCC_PORTA_CGC_MASK                  0x40000000u
#define PCC0_PCC_PORTA_CGC_SHIFT                 30
#define PCC0_PCC_PORTA_CGC_WIDTH                 1
#define PCC0_PCC_PORTA_CGC(x)                    (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTA_CGC_SHIFT))&PCC0_PCC_PORTA_CGC_MASK)
#define PCC0_PCC_PORTA_PR_MASK                   0x80000000u
#define PCC0_PCC_PORTA_PR_SHIFT                  31
#define PCC0_PCC_PORTA_PR_WIDTH                  1
#define PCC0_PCC_PORTA_PR(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTA_PR_SHIFT))&PCC0_PCC_PORTA_PR_MASK)
/* PCC_PORTB Bit Fields */
#define PCC0_PCC_PORTB_INUSE_MASK                0x20000000u
#define PCC0_PCC_PORTB_INUSE_SHIFT               29
#define PCC0_PCC_PORTB_INUSE_WIDTH               1
#define PCC0_PCC_PORTB_INUSE(x)                  (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTB_INUSE_SHIFT))&PCC0_PCC_PORTB_INUSE_MASK)
#define PCC0_PCC_PORTB_CGC_MASK                  0x40000000u
#define PCC0_PCC_PORTB_CGC_SHIFT                 30
#define PCC0_PCC_PORTB_CGC_WIDTH                 1
#define PCC0_PCC_PORTB_CGC(x)                    (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTB_CGC_SHIFT))&PCC0_PCC_PORTB_CGC_MASK)
#define PCC0_PCC_PORTB_PR_MASK                   0x80000000u
#define PCC0_PCC_PORTB_PR_SHIFT                  31
#define PCC0_PCC_PORTB_PR_WIDTH                  1
#define PCC0_PCC_PORTB_PR(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTB_PR_SHIFT))&PCC0_PCC_PORTB_PR_MASK)
/* PCC_PORTC Bit Fields */
#define PCC0_PCC_PORTC_INUSE_MASK                0x20000000u
#define PCC0_PCC_PORTC_INUSE_SHIFT               29
#define PCC0_PCC_PORTC_INUSE_WIDTH               1
#define PCC0_PCC_PORTC_INUSE(x)                  (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTC_INUSE_SHIFT))&PCC0_PCC_PORTC_INUSE_MASK)
#define PCC0_PCC_PORTC_CGC_MASK                  0x40000000u
#define PCC0_PCC_PORTC_CGC_SHIFT                 30
#define PCC0_PCC_PORTC_CGC_WIDTH                 1
#define PCC0_PCC_PORTC_CGC(x)                    (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTC_CGC_SHIFT))&PCC0_PCC_PORTC_CGC_MASK)
#define PCC0_PCC_PORTC_PR_MASK                   0x80000000u
#define PCC0_PCC_PORTC_PR_SHIFT                  31
#define PCC0_PCC_PORTC_PR_WIDTH                  1
#define PCC0_PCC_PORTC_PR(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTC_PR_SHIFT))&PCC0_PCC_PORTC_PR_MASK)
/* PCC_PORTD Bit Fields */
#define PCC0_PCC_PORTD_INUSE_MASK                0x20000000u
#define PCC0_PCC_PORTD_INUSE_SHIFT               29
#define PCC0_PCC_PORTD_INUSE_WIDTH               1
#define PCC0_PCC_PORTD_INUSE(x)                  (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTD_INUSE_SHIFT))&PCC0_PCC_PORTD_INUSE_MASK)
#define PCC0_PCC_PORTD_CGC_MASK                  0x40000000u
#define PCC0_PCC_PORTD_CGC_SHIFT                 30
#define PCC0_PCC_PORTD_CGC_WIDTH                 1
#define PCC0_PCC_PORTD_CGC(x)                    (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTD_CGC_SHIFT))&PCC0_PCC_PORTD_CGC_MASK)
#define PCC0_PCC_PORTD_PR_MASK                   0x80000000u
#define PCC0_PCC_PORTD_PR_SHIFT                  31
#define PCC0_PCC_PORTD_PR_WIDTH                  1
#define PCC0_PCC_PORTD_PR(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTD_PR_SHIFT))&PCC0_PCC_PORTD_PR_MASK)
/* PCC_PORTE Bit Fields */
#define PCC0_PCC_PORTE_INUSE_MASK                0x20000000u
#define PCC0_PCC_PORTE_INUSE_SHIFT               29
#define PCC0_PCC_PORTE_INUSE_WIDTH               1
#define PCC0_PCC_PORTE_INUSE(x)                  (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTE_INUSE_SHIFT))&PCC0_PCC_PORTE_INUSE_MASK)
#define PCC0_PCC_PORTE_CGC_MASK                  0x40000000u
#define PCC0_PCC_PORTE_CGC_SHIFT                 30
#define PCC0_PCC_PORTE_CGC_WIDTH                 1
#define PCC0_PCC_PORTE_CGC(x)                    (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTE_CGC_SHIFT))&PCC0_PCC_PORTE_CGC_MASK)
#define PCC0_PCC_PORTE_PR_MASK                   0x80000000u
#define PCC0_PCC_PORTE_PR_SHIFT                  31
#define PCC0_PCC_PORTE_PR_WIDTH                  1
#define PCC0_PCC_PORTE_PR(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_PORTE_PR_SHIFT))&PCC0_PCC_PORTE_PR_MASK)
/* PCC_TSI0 Bit Fields */
#define PCC0_PCC_TSI0_INUSE_MASK                 0x20000000u
#define PCC0_PCC_TSI0_INUSE_SHIFT                29
#define PCC0_PCC_TSI0_INUSE_WIDTH                1
#define PCC0_PCC_TSI0_INUSE(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_TSI0_INUSE_SHIFT))&PCC0_PCC_TSI0_INUSE_MASK)
#define PCC0_PCC_TSI0_CGC_MASK                   0x40000000u
#define PCC0_PCC_TSI0_CGC_SHIFT                  30
#define PCC0_PCC_TSI0_CGC_WIDTH                  1
#define PCC0_PCC_TSI0_CGC(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_TSI0_CGC_SHIFT))&PCC0_PCC_TSI0_CGC_MASK)
#define PCC0_PCC_TSI0_PR_MASK                    0x80000000u
#define PCC0_PCC_TSI0_PR_SHIFT                   31
#define PCC0_PCC_TSI0_PR_WIDTH                   1
#define PCC0_PCC_TSI0_PR(x)                      (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_TSI0_PR_SHIFT))&PCC0_PCC_TSI0_PR_MASK)
/* PCC_ADC0 Bit Fields */
#define PCC0_PCC_ADC0_PCS_MASK                   0x7000000u
#define PCC0_PCC_ADC0_PCS_SHIFT                  24
#define PCC0_PCC_ADC0_PCS_WIDTH                  3
#define PCC0_PCC_ADC0_PCS(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_ADC0_PCS_SHIFT))&PCC0_PCC_ADC0_PCS_MASK)
#define PCC0_PCC_ADC0_INUSE_MASK                 0x20000000u
#define PCC0_PCC_ADC0_INUSE_SHIFT                29
#define PCC0_PCC_ADC0_INUSE_WIDTH                1
#define PCC0_PCC_ADC0_INUSE(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_ADC0_INUSE_SHIFT))&PCC0_PCC_ADC0_INUSE_MASK)
#define PCC0_PCC_ADC0_CGC_MASK                   0x40000000u
#define PCC0_PCC_ADC0_CGC_SHIFT                  30
#define PCC0_PCC_ADC0_CGC_WIDTH                  1
#define PCC0_PCC_ADC0_CGC(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_ADC0_CGC_SHIFT))&PCC0_PCC_ADC0_CGC_MASK)
#define PCC0_PCC_ADC0_PR_MASK                    0x80000000u
#define PCC0_PCC_ADC0_PR_SHIFT                   31
#define PCC0_PCC_ADC0_PR_WIDTH                   1
#define PCC0_PCC_ADC0_PR(x)                      (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_ADC0_PR_SHIFT))&PCC0_PCC_ADC0_PR_MASK)
/* PCC_DAC0 Bit Fields */
#define PCC0_PCC_DAC0_INUSE_MASK                 0x20000000u
#define PCC0_PCC_DAC0_INUSE_SHIFT                29
#define PCC0_PCC_DAC0_INUSE_WIDTH                1
#define PCC0_PCC_DAC0_INUSE(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_DAC0_INUSE_SHIFT))&PCC0_PCC_DAC0_INUSE_MASK)
#define PCC0_PCC_DAC0_CGC_MASK                   0x40000000u
#define PCC0_PCC_DAC0_CGC_SHIFT                  30
#define PCC0_PCC_DAC0_CGC_WIDTH                  1
#define PCC0_PCC_DAC0_CGC(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_DAC0_CGC_SHIFT))&PCC0_PCC_DAC0_CGC_MASK)
#define PCC0_PCC_DAC0_PR_MASK                    0x80000000u
#define PCC0_PCC_DAC0_PR_SHIFT                   31
#define PCC0_PCC_DAC0_PR_WIDTH                   1
#define PCC0_PCC_DAC0_PR(x)                      (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_DAC0_PR_SHIFT))&PCC0_PCC_DAC0_PR_MASK)
/* PCC_CMP0 Bit Fields */
#define PCC0_PCC_CMP0_INUSE_MASK                 0x20000000u
#define PCC0_PCC_CMP0_INUSE_SHIFT                29
#define PCC0_PCC_CMP0_INUSE_WIDTH                1
#define PCC0_PCC_CMP0_INUSE(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_CMP0_INUSE_SHIFT))&PCC0_PCC_CMP0_INUSE_MASK)
#define PCC0_PCC_CMP0_CGC_MASK                   0x40000000u
#define PCC0_PCC_CMP0_CGC_SHIFT                  30
#define PCC0_PCC_CMP0_CGC_WIDTH                  1
#define PCC0_PCC_CMP0_CGC(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_CMP0_CGC_SHIFT))&PCC0_PCC_CMP0_CGC_MASK)
#define PCC0_PCC_CMP0_PR_MASK                    0x80000000u
#define PCC0_PCC_CMP0_PR_SHIFT                   31
#define PCC0_PCC_CMP0_PR_WIDTH                   1
#define PCC0_PCC_CMP0_PR(x)                      (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_CMP0_PR_SHIFT))&PCC0_PCC_CMP0_PR_MASK)
/* PCC_VREF Bit Fields */
#define PCC0_PCC_VREF_INUSE_MASK                 0x20000000u
#define PCC0_PCC_VREF_INUSE_SHIFT                29
#define PCC0_PCC_VREF_INUSE_WIDTH                1
#define PCC0_PCC_VREF_INUSE(x)                   (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_VREF_INUSE_SHIFT))&PCC0_PCC_VREF_INUSE_MASK)
#define PCC0_PCC_VREF_CGC_MASK                   0x40000000u
#define PCC0_PCC_VREF_CGC_SHIFT                  30
#define PCC0_PCC_VREF_CGC_WIDTH                  1
#define PCC0_PCC_VREF_CGC(x)                     (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_VREF_CGC_SHIFT))&PCC0_PCC_VREF_CGC_MASK)
#define PCC0_PCC_VREF_PR_MASK                    0x80000000u
#define PCC0_PCC_VREF_PR_SHIFT                   31
#define PCC0_PCC_VREF_PR_WIDTH                   1
#define PCC0_PCC_VREF_PR(x)                      (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_VREF_PR_SHIFT))&PCC0_PCC_VREF_PR_MASK)
/* PCC_CRC Bit Fields */
#define PCC0_PCC_CRC_INUSE_MASK                  0x20000000u
#define PCC0_PCC_CRC_INUSE_SHIFT                 29
#define PCC0_PCC_CRC_INUSE_WIDTH                 1
#define PCC0_PCC_CRC_INUSE(x)                    (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_CRC_INUSE_SHIFT))&PCC0_PCC_CRC_INUSE_MASK)
#define PCC0_PCC_CRC_CGC_MASK                    0x40000000u
#define PCC0_PCC_CRC_CGC_SHIFT                   30
#define PCC0_PCC_CRC_CGC_WIDTH                   1
#define PCC0_PCC_CRC_CGC(x)                      (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_CRC_CGC_SHIFT))&PCC0_PCC_CRC_CGC_MASK)
#define PCC0_PCC_CRC_PR_MASK                     0x80000000u
#define PCC0_PCC_CRC_PR_SHIFT                    31
#define PCC0_PCC_CRC_PR_WIDTH                    1
#define PCC0_PCC_CRC_PR(x)                       (((uint32_t)(((uint32_t)(x))<<PCC0_PCC_CRC_PR_SHIFT))&PCC0_PCC_CRC_PR_MASK)

/*!
 * @}
 */ /* end of group PCC0_Register_Masks */


/* PCC0 - Peripheral instance base addresses */
/** Peripheral PCC0 base address */
#define PCC0_BASE                                (0x4007A000u)
/** Peripheral PCC0 base pointer */
#define PCC0                                     ((PCC0_Type *)PCC0_BASE)
#define PCC0_BASE_PTR                            (PCC0)
/** Array initializer of PCC0 peripheral base addresses */
#define PCC0_BASE_ADDRS                          { PCC0_BASE }
/** Array initializer of PCC0 peripheral base pointers */
#define PCC0_BASE_PTRS                           { PCC0 }

/* ----------------------------------------------------------------------------
   -- PCC0 - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC0_Register_Accessor_Macros PCC0 - Register accessor macros
 * @{
 */


/* PCC0 - Register instance definitions */
/* PCC0 */
#define PCC_PCC_DMA0                             PCC0_PCC_DMA0_REG(PCC0)
#define PCC_PCC_FLASH                            PCC0_PCC_FLASH_REG(PCC0)
#define PCC_PCC_DMAMUX0                          PCC0_PCC_DMAMUX0_REG(PCC0)
#define PCC_PCC_INTMUX0                          PCC0_PCC_INTMUX0_REG(PCC0)
#define PCC_PCC_TPM2                             PCC0_PCC_TPM2_REG(PCC0)
#define PCC_PCC_LPIT0                            PCC0_PCC_LPIT0_REG(PCC0)
#define PCC_PCC_LPTMR0                           PCC0_PCC_LPTMR0_REG(PCC0)
#define PCC_PCC_RTC                              PCC0_PCC_RTC_REG(PCC0)
#define PCC_PCC_LPSPI2                           PCC0_PCC_LPSPI2_REG(PCC0)
#define PCC_PCC_LPI2C2                           PCC0_PCC_LPI2C2_REG(PCC0)
#define PCC_PCC_LPUART2                          PCC0_PCC_LPUART2_REG(PCC0)
#define PCC_PCC_SAI0                             PCC0_PCC_SAI0_REG(PCC0)
#define PCC_PCC_EVMSIM0                          PCC0_PCC_EVMSIM0_REG(PCC0)
#define PCC_PCC_USB0FS                           PCC0_PCC_USB0FS_REG(PCC0)
#define PCC_PCC_PORTA                            PCC0_PCC_PORTA_REG(PCC0)
#define PCC_PCC_PORTB                            PCC0_PCC_PORTB_REG(PCC0)
#define PCC_PCC_PORTC                            PCC0_PCC_PORTC_REG(PCC0)
#define PCC_PCC_PORTD                            PCC0_PCC_PORTD_REG(PCC0)
#define PCC_PCC_PORTE                            PCC0_PCC_PORTE_REG(PCC0)
#define PCC_PCC_TSI0                             PCC0_PCC_TSI0_REG(PCC0)
#define PCC_PCC_ADC0                             PCC0_PCC_ADC0_REG(PCC0)
#define PCC_PCC_DAC0                             PCC0_PCC_DAC0_REG(PCC0)
#define PCC_PCC_CMP0                             PCC0_PCC_CMP0_REG(PCC0)
#define PCC_PCC_VREF                             PCC0_PCC_VREF_REG(PCC0)
#define PCC_PCC_CRC                              PCC0_PCC_CRC_REG(PCC0)

/*!
 * @}
 */ /* end of group PCC0_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PCC0_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PCC1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC1_Peripheral_Access_Layer PCC1 Peripheral Access Layer
 * @{
 */

/** PCC1 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[148];
  __IO uint32_t PCC_TRNG;                          /**< PCC_TRNG Register, offset: 0x94 */
       uint8_t RESERVED_1[24];
  __IO uint32_t PCC_TPM0;                          /**< PCC_TPM0 Register, offset: 0xB0 */
  __IO uint32_t PCC_TPM1;                          /**< PCC_TPM1 Register, offset: 0xB4 */
       uint8_t RESERVED_2[28];
  __IO uint32_t PCC_LPTMR1;                        /**< PCC_LPTMR1 Register, offset: 0xD4 */
       uint8_t RESERVED_3[24];
  __IO uint32_t PCC_LPSPI0;                        /**< PCC_LPSPI0 Register, offset: 0xF0 */
  __IO uint32_t PCC_LPSPI1;                        /**< PCC_LPSPI1 Register, offset: 0xF4 */
       uint8_t RESERVED_4[8];
  __IO uint32_t PCC_LPI2C0;                        /**< PCC_LPI2C0 Register, offset: 0x100 */
  __IO uint32_t PCC_LPI2C1;                        /**< PCC_LPI2C1 Register, offset: 0x104 */
       uint8_t RESERVED_5[8];
  __IO uint32_t PCC_LPUART0;                       /**< PCC_LPUART0 Register, offset: 0x110 */
  __IO uint32_t PCC_LPUART1;                       /**< PCC_LPUART1 Register, offset: 0x114 */
       uint8_t RESERVED_6[16];
  __IO uint32_t PCC_FLEXIO0;                       /**< PCC_FLEXIO0 Register, offset: 0x128 */
       uint8_t RESERVED_7[144];
  __IO uint32_t PCC_CMP1;                          /**< PCC_CMP1 Register, offset: 0x1BC */
} PCC1_Type, *PCC1_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PCC1 - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC1_Register_Accessor_Macros PCC1 - Register accessor macros
 * @{
 */


/* PCC1 - Register accessors */
#define PCC1_PCC_TRNG_REG(base)                  ((base)->PCC_TRNG)
#define PCC1_PCC_TPM0_REG(base)                  ((base)->PCC_TPM0)
#define PCC1_PCC_TPM1_REG(base)                  ((base)->PCC_TPM1)
#define PCC1_PCC_LPTMR1_REG(base)                ((base)->PCC_LPTMR1)
#define PCC1_PCC_LPSPI0_REG(base)                ((base)->PCC_LPSPI0)
#define PCC1_PCC_LPSPI1_REG(base)                ((base)->PCC_LPSPI1)
#define PCC1_PCC_LPI2C0_REG(base)                ((base)->PCC_LPI2C0)
#define PCC1_PCC_LPI2C1_REG(base)                ((base)->PCC_LPI2C1)
#define PCC1_PCC_LPUART0_REG(base)               ((base)->PCC_LPUART0)
#define PCC1_PCC_LPUART1_REG(base)               ((base)->PCC_LPUART1)
#define PCC1_PCC_FLEXIO0_REG(base)               ((base)->PCC_FLEXIO0)
#define PCC1_PCC_CMP1_REG(base)                  ((base)->PCC_CMP1)

/*!
 * @}
 */ /* end of group PCC1_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PCC1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC1_Register_Masks PCC1 Register Masks
 * @{
 */

/* PCC_TRNG Bit Fields */
#define PCC1_PCC_TRNG_INUSE_MASK                 0x20000000u
#define PCC1_PCC_TRNG_INUSE_SHIFT                29
#define PCC1_PCC_TRNG_INUSE_WIDTH                1
#define PCC1_PCC_TRNG_INUSE(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_TRNG_INUSE_SHIFT))&PCC1_PCC_TRNG_INUSE_MASK)
#define PCC1_PCC_TRNG_CGC_MASK                   0x40000000u
#define PCC1_PCC_TRNG_CGC_SHIFT                  30
#define PCC1_PCC_TRNG_CGC_WIDTH                  1
#define PCC1_PCC_TRNG_CGC(x)                     (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_TRNG_CGC_SHIFT))&PCC1_PCC_TRNG_CGC_MASK)
#define PCC1_PCC_TRNG_PR_MASK                    0x80000000u
#define PCC1_PCC_TRNG_PR_SHIFT                   31
#define PCC1_PCC_TRNG_PR_WIDTH                   1
#define PCC1_PCC_TRNG_PR(x)                      (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_TRNG_PR_SHIFT))&PCC1_PCC_TRNG_PR_MASK)
/* PCC_TPM0 Bit Fields */
#define PCC1_PCC_TPM0_PCS_MASK                   0x7000000u
#define PCC1_PCC_TPM0_PCS_SHIFT                  24
#define PCC1_PCC_TPM0_PCS_WIDTH                  3
#define PCC1_PCC_TPM0_PCS(x)                     (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_TPM0_PCS_SHIFT))&PCC1_PCC_TPM0_PCS_MASK)
#define PCC1_PCC_TPM0_INUSE_MASK                 0x20000000u
#define PCC1_PCC_TPM0_INUSE_SHIFT                29
#define PCC1_PCC_TPM0_INUSE_WIDTH                1
#define PCC1_PCC_TPM0_INUSE(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_TPM0_INUSE_SHIFT))&PCC1_PCC_TPM0_INUSE_MASK)
#define PCC1_PCC_TPM0_CGC_MASK                   0x40000000u
#define PCC1_PCC_TPM0_CGC_SHIFT                  30
#define PCC1_PCC_TPM0_CGC_WIDTH                  1
#define PCC1_PCC_TPM0_CGC(x)                     (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_TPM0_CGC_SHIFT))&PCC1_PCC_TPM0_CGC_MASK)
#define PCC1_PCC_TPM0_PR_MASK                    0x80000000u
#define PCC1_PCC_TPM0_PR_SHIFT                   31
#define PCC1_PCC_TPM0_PR_WIDTH                   1
#define PCC1_PCC_TPM0_PR(x)                      (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_TPM0_PR_SHIFT))&PCC1_PCC_TPM0_PR_MASK)
/* PCC_TPM1 Bit Fields */
#define PCC1_PCC_TPM1_PCS_MASK                   0x7000000u
#define PCC1_PCC_TPM1_PCS_SHIFT                  24
#define PCC1_PCC_TPM1_PCS_WIDTH                  3
#define PCC1_PCC_TPM1_PCS(x)                     (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_TPM1_PCS_SHIFT))&PCC1_PCC_TPM1_PCS_MASK)
#define PCC1_PCC_TPM1_INUSE_MASK                 0x20000000u
#define PCC1_PCC_TPM1_INUSE_SHIFT                29
#define PCC1_PCC_TPM1_INUSE_WIDTH                1
#define PCC1_PCC_TPM1_INUSE(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_TPM1_INUSE_SHIFT))&PCC1_PCC_TPM1_INUSE_MASK)
#define PCC1_PCC_TPM1_CGC_MASK                   0x40000000u
#define PCC1_PCC_TPM1_CGC_SHIFT                  30
#define PCC1_PCC_TPM1_CGC_WIDTH                  1
#define PCC1_PCC_TPM1_CGC(x)                     (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_TPM1_CGC_SHIFT))&PCC1_PCC_TPM1_CGC_MASK)
#define PCC1_PCC_TPM1_PR_MASK                    0x80000000u
#define PCC1_PCC_TPM1_PR_SHIFT                   31
#define PCC1_PCC_TPM1_PR_WIDTH                   1
#define PCC1_PCC_TPM1_PR(x)                      (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_TPM1_PR_SHIFT))&PCC1_PCC_TPM1_PR_MASK)
/* PCC_LPTMR1 Bit Fields */
#define PCC1_PCC_LPTMR1_INUSE_MASK               0x20000000u
#define PCC1_PCC_LPTMR1_INUSE_SHIFT              29
#define PCC1_PCC_LPTMR1_INUSE_WIDTH              1
#define PCC1_PCC_LPTMR1_INUSE(x)                 (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPTMR1_INUSE_SHIFT))&PCC1_PCC_LPTMR1_INUSE_MASK)
#define PCC1_PCC_LPTMR1_CGC_MASK                 0x40000000u
#define PCC1_PCC_LPTMR1_CGC_SHIFT                30
#define PCC1_PCC_LPTMR1_CGC_WIDTH                1
#define PCC1_PCC_LPTMR1_CGC(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPTMR1_CGC_SHIFT))&PCC1_PCC_LPTMR1_CGC_MASK)
#define PCC1_PCC_LPTMR1_PR_MASK                  0x80000000u
#define PCC1_PCC_LPTMR1_PR_SHIFT                 31
#define PCC1_PCC_LPTMR1_PR_WIDTH                 1
#define PCC1_PCC_LPTMR1_PR(x)                    (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPTMR1_PR_SHIFT))&PCC1_PCC_LPTMR1_PR_MASK)
/* PCC_LPSPI0 Bit Fields */
#define PCC1_PCC_LPSPI0_PCS_MASK                 0x7000000u
#define PCC1_PCC_LPSPI0_PCS_SHIFT                24
#define PCC1_PCC_LPSPI0_PCS_WIDTH                3
#define PCC1_PCC_LPSPI0_PCS(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPSPI0_PCS_SHIFT))&PCC1_PCC_LPSPI0_PCS_MASK)
#define PCC1_PCC_LPSPI0_INUSE_MASK               0x20000000u
#define PCC1_PCC_LPSPI0_INUSE_SHIFT              29
#define PCC1_PCC_LPSPI0_INUSE_WIDTH              1
#define PCC1_PCC_LPSPI0_INUSE(x)                 (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPSPI0_INUSE_SHIFT))&PCC1_PCC_LPSPI0_INUSE_MASK)
#define PCC1_PCC_LPSPI0_CGC_MASK                 0x40000000u
#define PCC1_PCC_LPSPI0_CGC_SHIFT                30
#define PCC1_PCC_LPSPI0_CGC_WIDTH                1
#define PCC1_PCC_LPSPI0_CGC(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPSPI0_CGC_SHIFT))&PCC1_PCC_LPSPI0_CGC_MASK)
#define PCC1_PCC_LPSPI0_PR_MASK                  0x80000000u
#define PCC1_PCC_LPSPI0_PR_SHIFT                 31
#define PCC1_PCC_LPSPI0_PR_WIDTH                 1
#define PCC1_PCC_LPSPI0_PR(x)                    (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPSPI0_PR_SHIFT))&PCC1_PCC_LPSPI0_PR_MASK)
/* PCC_LPSPI1 Bit Fields */
#define PCC1_PCC_LPSPI1_PCS_MASK                 0x7000000u
#define PCC1_PCC_LPSPI1_PCS_SHIFT                24
#define PCC1_PCC_LPSPI1_PCS_WIDTH                3
#define PCC1_PCC_LPSPI1_PCS(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPSPI1_PCS_SHIFT))&PCC1_PCC_LPSPI1_PCS_MASK)
#define PCC1_PCC_LPSPI1_INUSE_MASK               0x20000000u
#define PCC1_PCC_LPSPI1_INUSE_SHIFT              29
#define PCC1_PCC_LPSPI1_INUSE_WIDTH              1
#define PCC1_PCC_LPSPI1_INUSE(x)                 (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPSPI1_INUSE_SHIFT))&PCC1_PCC_LPSPI1_INUSE_MASK)
#define PCC1_PCC_LPSPI1_CGC_MASK                 0x40000000u
#define PCC1_PCC_LPSPI1_CGC_SHIFT                30
#define PCC1_PCC_LPSPI1_CGC_WIDTH                1
#define PCC1_PCC_LPSPI1_CGC(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPSPI1_CGC_SHIFT))&PCC1_PCC_LPSPI1_CGC_MASK)
#define PCC1_PCC_LPSPI1_PR_MASK                  0x80000000u
#define PCC1_PCC_LPSPI1_PR_SHIFT                 31
#define PCC1_PCC_LPSPI1_PR_WIDTH                 1
#define PCC1_PCC_LPSPI1_PR(x)                    (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPSPI1_PR_SHIFT))&PCC1_PCC_LPSPI1_PR_MASK)
/* PCC_LPI2C0 Bit Fields */
#define PCC1_PCC_LPI2C0_PCS_MASK                 0x7000000u
#define PCC1_PCC_LPI2C0_PCS_SHIFT                24
#define PCC1_PCC_LPI2C0_PCS_WIDTH                3
#define PCC1_PCC_LPI2C0_PCS(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPI2C0_PCS_SHIFT))&PCC1_PCC_LPI2C0_PCS_MASK)
#define PCC1_PCC_LPI2C0_INUSE_MASK               0x20000000u
#define PCC1_PCC_LPI2C0_INUSE_SHIFT              29
#define PCC1_PCC_LPI2C0_INUSE_WIDTH              1
#define PCC1_PCC_LPI2C0_INUSE(x)                 (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPI2C0_INUSE_SHIFT))&PCC1_PCC_LPI2C0_INUSE_MASK)
#define PCC1_PCC_LPI2C0_CGC_MASK                 0x40000000u
#define PCC1_PCC_LPI2C0_CGC_SHIFT                30
#define PCC1_PCC_LPI2C0_CGC_WIDTH                1
#define PCC1_PCC_LPI2C0_CGC(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPI2C0_CGC_SHIFT))&PCC1_PCC_LPI2C0_CGC_MASK)
#define PCC1_PCC_LPI2C0_PR_MASK                  0x80000000u
#define PCC1_PCC_LPI2C0_PR_SHIFT                 31
#define PCC1_PCC_LPI2C0_PR_WIDTH                 1
#define PCC1_PCC_LPI2C0_PR(x)                    (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPI2C0_PR_SHIFT))&PCC1_PCC_LPI2C0_PR_MASK)
/* PCC_LPI2C1 Bit Fields */
#define PCC1_PCC_LPI2C1_PCS_MASK                 0x7000000u
#define PCC1_PCC_LPI2C1_PCS_SHIFT                24
#define PCC1_PCC_LPI2C1_PCS_WIDTH                3
#define PCC1_PCC_LPI2C1_PCS(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPI2C1_PCS_SHIFT))&PCC1_PCC_LPI2C1_PCS_MASK)
#define PCC1_PCC_LPI2C1_INUSE_MASK               0x20000000u
#define PCC1_PCC_LPI2C1_INUSE_SHIFT              29
#define PCC1_PCC_LPI2C1_INUSE_WIDTH              1
#define PCC1_PCC_LPI2C1_INUSE(x)                 (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPI2C1_INUSE_SHIFT))&PCC1_PCC_LPI2C1_INUSE_MASK)
#define PCC1_PCC_LPI2C1_CGC_MASK                 0x40000000u
#define PCC1_PCC_LPI2C1_CGC_SHIFT                30
#define PCC1_PCC_LPI2C1_CGC_WIDTH                1
#define PCC1_PCC_LPI2C1_CGC(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPI2C1_CGC_SHIFT))&PCC1_PCC_LPI2C1_CGC_MASK)
#define PCC1_PCC_LPI2C1_PR_MASK                  0x80000000u
#define PCC1_PCC_LPI2C1_PR_SHIFT                 31
#define PCC1_PCC_LPI2C1_PR_WIDTH                 1
#define PCC1_PCC_LPI2C1_PR(x)                    (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPI2C1_PR_SHIFT))&PCC1_PCC_LPI2C1_PR_MASK)
/* PCC_LPUART0 Bit Fields */
#define PCC1_PCC_LPUART0_PCS_MASK                0x7000000u
#define PCC1_PCC_LPUART0_PCS_SHIFT               24
#define PCC1_PCC_LPUART0_PCS_WIDTH               3
#define PCC1_PCC_LPUART0_PCS(x)                  (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPUART0_PCS_SHIFT))&PCC1_PCC_LPUART0_PCS_MASK)
#define PCC1_PCC_LPUART0_INUSE_MASK              0x20000000u
#define PCC1_PCC_LPUART0_INUSE_SHIFT             29
#define PCC1_PCC_LPUART0_INUSE_WIDTH             1
#define PCC1_PCC_LPUART0_INUSE(x)                (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPUART0_INUSE_SHIFT))&PCC1_PCC_LPUART0_INUSE_MASK)
#define PCC1_PCC_LPUART0_CGC_MASK                0x40000000u
#define PCC1_PCC_LPUART0_CGC_SHIFT               30
#define PCC1_PCC_LPUART0_CGC_WIDTH               1
#define PCC1_PCC_LPUART0_CGC(x)                  (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPUART0_CGC_SHIFT))&PCC1_PCC_LPUART0_CGC_MASK)
#define PCC1_PCC_LPUART0_PR_MASK                 0x80000000u
#define PCC1_PCC_LPUART0_PR_SHIFT                31
#define PCC1_PCC_LPUART0_PR_WIDTH                1
#define PCC1_PCC_LPUART0_PR(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPUART0_PR_SHIFT))&PCC1_PCC_LPUART0_PR_MASK)
/* PCC_LPUART1 Bit Fields */
#define PCC1_PCC_LPUART1_PCS_MASK                0x7000000u
#define PCC1_PCC_LPUART1_PCS_SHIFT               24
#define PCC1_PCC_LPUART1_PCS_WIDTH               3
#define PCC1_PCC_LPUART1_PCS(x)                  (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPUART1_PCS_SHIFT))&PCC1_PCC_LPUART1_PCS_MASK)
#define PCC1_PCC_LPUART1_INUSE_MASK              0x20000000u
#define PCC1_PCC_LPUART1_INUSE_SHIFT             29
#define PCC1_PCC_LPUART1_INUSE_WIDTH             1
#define PCC1_PCC_LPUART1_INUSE(x)                (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPUART1_INUSE_SHIFT))&PCC1_PCC_LPUART1_INUSE_MASK)
#define PCC1_PCC_LPUART1_CGC_MASK                0x40000000u
#define PCC1_PCC_LPUART1_CGC_SHIFT               30
#define PCC1_PCC_LPUART1_CGC_WIDTH               1
#define PCC1_PCC_LPUART1_CGC(x)                  (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPUART1_CGC_SHIFT))&PCC1_PCC_LPUART1_CGC_MASK)
#define PCC1_PCC_LPUART1_PR_MASK                 0x80000000u
#define PCC1_PCC_LPUART1_PR_SHIFT                31
#define PCC1_PCC_LPUART1_PR_WIDTH                1
#define PCC1_PCC_LPUART1_PR(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_LPUART1_PR_SHIFT))&PCC1_PCC_LPUART1_PR_MASK)
/* PCC_FLEXIO0 Bit Fields */
#define PCC1_PCC_FLEXIO0_PCS_MASK                0x7000000u
#define PCC1_PCC_FLEXIO0_PCS_SHIFT               24
#define PCC1_PCC_FLEXIO0_PCS_WIDTH               3
#define PCC1_PCC_FLEXIO0_PCS(x)                  (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_FLEXIO0_PCS_SHIFT))&PCC1_PCC_FLEXIO0_PCS_MASK)
#define PCC1_PCC_FLEXIO0_INUSE_MASK              0x20000000u
#define PCC1_PCC_FLEXIO0_INUSE_SHIFT             29
#define PCC1_PCC_FLEXIO0_INUSE_WIDTH             1
#define PCC1_PCC_FLEXIO0_INUSE(x)                (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_FLEXIO0_INUSE_SHIFT))&PCC1_PCC_FLEXIO0_INUSE_MASK)
#define PCC1_PCC_FLEXIO0_CGC_MASK                0x40000000u
#define PCC1_PCC_FLEXIO0_CGC_SHIFT               30
#define PCC1_PCC_FLEXIO0_CGC_WIDTH               1
#define PCC1_PCC_FLEXIO0_CGC(x)                  (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_FLEXIO0_CGC_SHIFT))&PCC1_PCC_FLEXIO0_CGC_MASK)
#define PCC1_PCC_FLEXIO0_PR_MASK                 0x80000000u
#define PCC1_PCC_FLEXIO0_PR_SHIFT                31
#define PCC1_PCC_FLEXIO0_PR_WIDTH                1
#define PCC1_PCC_FLEXIO0_PR(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_FLEXIO0_PR_SHIFT))&PCC1_PCC_FLEXIO0_PR_MASK)
/* PCC_CMP1 Bit Fields */
#define PCC1_PCC_CMP1_INUSE_MASK                 0x20000000u
#define PCC1_PCC_CMP1_INUSE_SHIFT                29
#define PCC1_PCC_CMP1_INUSE_WIDTH                1
#define PCC1_PCC_CMP1_INUSE(x)                   (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_CMP1_INUSE_SHIFT))&PCC1_PCC_CMP1_INUSE_MASK)
#define PCC1_PCC_CMP1_CGC_MASK                   0x40000000u
#define PCC1_PCC_CMP1_CGC_SHIFT                  30
#define PCC1_PCC_CMP1_CGC_WIDTH                  1
#define PCC1_PCC_CMP1_CGC(x)                     (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_CMP1_CGC_SHIFT))&PCC1_PCC_CMP1_CGC_MASK)
#define PCC1_PCC_CMP1_PR_MASK                    0x80000000u
#define PCC1_PCC_CMP1_PR_SHIFT                   31
#define PCC1_PCC_CMP1_PR_WIDTH                   1
#define PCC1_PCC_CMP1_PR(x)                      (((uint32_t)(((uint32_t)(x))<<PCC1_PCC_CMP1_PR_SHIFT))&PCC1_PCC_CMP1_PR_MASK)

/*!
 * @}
 */ /* end of group PCC1_Register_Masks */


/* PCC1 - Peripheral instance base addresses */
/** Peripheral PCC1 base address */
#define PCC1_BASE                                (0x400FA000u)
/** Peripheral PCC1 base pointer */
#define PCC1                                     ((PCC1_Type *)PCC1_BASE)
#define PCC1_BASE_PTR                            (PCC1)
/** Array initializer of PCC1 peripheral base addresses */
#define PCC1_BASE_ADDRS                          { PCC1_BASE }
/** Array initializer of PCC1 peripheral base pointers */
#define PCC1_BASE_PTRS                           { PCC1 }

/* ----------------------------------------------------------------------------
   -- PCC1 - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC1_Register_Accessor_Macros PCC1 - Register accessor macros
 * @{
 */


/* PCC1 - Register instance definitions */
/* PCC1 */
#define PCC_PCC_TRNG                             PCC1_PCC_TRNG_REG(PCC1)
#define PCC_PCC_TPM0                             PCC1_PCC_TPM0_REG(PCC1)
#define PCC_PCC_TPM1                             PCC1_PCC_TPM1_REG(PCC1)
#define PCC_PCC_LPTMR1                           PCC1_PCC_LPTMR1_REG(PCC1)
#define PCC_PCC_LPSPI0                           PCC1_PCC_LPSPI0_REG(PCC1)
#define PCC_PCC_LPSPI1                           PCC1_PCC_LPSPI1_REG(PCC1)
#define PCC_PCC_LPI2C0                           PCC1_PCC_LPI2C0_REG(PCC1)
#define PCC_PCC_LPI2C1                           PCC1_PCC_LPI2C1_REG(PCC1)
#define PCC_PCC_LPUART0                          PCC1_PCC_LPUART0_REG(PCC1)
#define PCC_PCC_LPUART1                          PCC1_PCC_LPUART1_REG(PCC1)
#define PCC_PCC_FLEXIO0                          PCC1_PCC_FLEXIO0_REG(PCC1)
#define PCC_PCC_CMP1                             PCC1_PCC_CMP1_REG(PCC1)

/*!
 * @}
 */ /* end of group PCC1_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PCC1_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter register, offset: 0x4 */
  __IO uint32_t LVDSC1;                            /**< Low Voltage Detect Status And Control 1 register, offset: 0x8 */
  __IO uint32_t LVDSC2;                            /**< Low Voltage Detect Status And Control 2 register, offset: 0xC */
  __IO uint32_t REGSC;                             /**< Regulator Status And Control register, offset: 0x10 */
       uint8_t RESERVED_0[32];
  __IO uint32_t HVDSC1;                            /**< High Voltage Detect Status And Control 1 register, offset: 0x34 */
} PMC_Type, *PMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros
 * @{
 */


/* PMC - Register accessors */
#define PMC_VERID_REG(base)                      ((base)->VERID)
#define PMC_PARAM_REG(base)                      ((base)->PARAM)
#define PMC_LVDSC1_REG(base)                     ((base)->LVDSC1)
#define PMC_LVDSC2_REG(base)                     ((base)->LVDSC2)
#define PMC_REGSC_REG(base)                      ((base)->REGSC)
#define PMC_HVDSC1_REG(base)                     ((base)->HVDSC1)

/*!
 * @}
 */ /* end of group PMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/* VERID Bit Fields */
#define PMC_VERID_FEATURE_MASK                   0xFFFFu
#define PMC_VERID_FEATURE_SHIFT                  0
#define PMC_VERID_FEATURE_WIDTH                  16
#define PMC_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x))<<PMC_VERID_FEATURE_SHIFT))&PMC_VERID_FEATURE_MASK)
#define PMC_VERID_MINOR_MASK                     0xFF0000u
#define PMC_VERID_MINOR_SHIFT                    16
#define PMC_VERID_MINOR_WIDTH                    8
#define PMC_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x))<<PMC_VERID_MINOR_SHIFT))&PMC_VERID_MINOR_MASK)
#define PMC_VERID_MAJOR_MASK                     0xFF000000u
#define PMC_VERID_MAJOR_SHIFT                    24
#define PMC_VERID_MAJOR_WIDTH                    8
#define PMC_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x))<<PMC_VERID_MAJOR_SHIFT))&PMC_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define PMC_PARAM_VLPOE_MASK                     0x1u
#define PMC_PARAM_VLPOE_SHIFT                    0
#define PMC_PARAM_VLPOE_WIDTH                    1
#define PMC_PARAM_VLPOE(x)                       (((uint32_t)(((uint32_t)(x))<<PMC_PARAM_VLPOE_SHIFT))&PMC_PARAM_VLPOE_MASK)
#define PMC_PARAM_HVDE_MASK                      0x2u
#define PMC_PARAM_HVDE_SHIFT                     1
#define PMC_PARAM_HVDE_WIDTH                     1
#define PMC_PARAM_HVDE(x)                        (((uint32_t)(((uint32_t)(x))<<PMC_PARAM_HVDE_SHIFT))&PMC_PARAM_HVDE_MASK)
/* LVDSC1 Bit Fields */
#define PMC_LVDSC1_LVDV_MASK                     0x3u
#define PMC_LVDSC1_LVDV_SHIFT                    0
#define PMC_LVDSC1_LVDV_WIDTH                    2
#define PMC_LVDSC1_LVDV(x)                       (((uint32_t)(((uint32_t)(x))<<PMC_LVDSC1_LVDV_SHIFT))&PMC_LVDSC1_LVDV_MASK)
#define PMC_LVDSC1_LVDRE_MASK                    0x10u
#define PMC_LVDSC1_LVDRE_SHIFT                   4
#define PMC_LVDSC1_LVDRE_WIDTH                   1
#define PMC_LVDSC1_LVDRE(x)                      (((uint32_t)(((uint32_t)(x))<<PMC_LVDSC1_LVDRE_SHIFT))&PMC_LVDSC1_LVDRE_MASK)
#define PMC_LVDSC1_LVDIE_MASK                    0x20u
#define PMC_LVDSC1_LVDIE_SHIFT                   5
#define PMC_LVDSC1_LVDIE_WIDTH                   1
#define PMC_LVDSC1_LVDIE(x)                      (((uint32_t)(((uint32_t)(x))<<PMC_LVDSC1_LVDIE_SHIFT))&PMC_LVDSC1_LVDIE_MASK)
#define PMC_LVDSC1_LVDACK_MASK                   0x40u
#define PMC_LVDSC1_LVDACK_SHIFT                  6
#define PMC_LVDSC1_LVDACK_WIDTH                  1
#define PMC_LVDSC1_LVDACK(x)                     (((uint32_t)(((uint32_t)(x))<<PMC_LVDSC1_LVDACK_SHIFT))&PMC_LVDSC1_LVDACK_MASK)
#define PMC_LVDSC1_LVDF_MASK                     0x80u
#define PMC_LVDSC1_LVDF_SHIFT                    7
#define PMC_LVDSC1_LVDF_WIDTH                    1
#define PMC_LVDSC1_LVDF(x)                       (((uint32_t)(((uint32_t)(x))<<PMC_LVDSC1_LVDF_SHIFT))&PMC_LVDSC1_LVDF_MASK)
/* LVDSC2 Bit Fields */
#define PMC_LVDSC2_LVWV_MASK                     0x3u
#define PMC_LVDSC2_LVWV_SHIFT                    0
#define PMC_LVDSC2_LVWV_WIDTH                    2
#define PMC_LVDSC2_LVWV(x)                       (((uint32_t)(((uint32_t)(x))<<PMC_LVDSC2_LVWV_SHIFT))&PMC_LVDSC2_LVWV_MASK)
#define PMC_LVDSC2_LVWIE_MASK                    0x20u
#define PMC_LVDSC2_LVWIE_SHIFT                   5
#define PMC_LVDSC2_LVWIE_WIDTH                   1
#define PMC_LVDSC2_LVWIE(x)                      (((uint32_t)(((uint32_t)(x))<<PMC_LVDSC2_LVWIE_SHIFT))&PMC_LVDSC2_LVWIE_MASK)
#define PMC_LVDSC2_LVWACK_MASK                   0x40u
#define PMC_LVDSC2_LVWACK_SHIFT                  6
#define PMC_LVDSC2_LVWACK_WIDTH                  1
#define PMC_LVDSC2_LVWACK(x)                     (((uint32_t)(((uint32_t)(x))<<PMC_LVDSC2_LVWACK_SHIFT))&PMC_LVDSC2_LVWACK_MASK)
#define PMC_LVDSC2_LVWF_MASK                     0x80u
#define PMC_LVDSC2_LVWF_SHIFT                    7
#define PMC_LVDSC2_LVWF_WIDTH                    1
#define PMC_LVDSC2_LVWF(x)                       (((uint32_t)(((uint32_t)(x))<<PMC_LVDSC2_LVWF_SHIFT))&PMC_LVDSC2_LVWF_MASK)
/* REGSC Bit Fields */
#define PMC_REGSC_BGBE_MASK                      0x1u
#define PMC_REGSC_BGBE_SHIFT                     0
#define PMC_REGSC_BGBE_WIDTH                     1
#define PMC_REGSC_BGBE(x)                        (((uint32_t)(((uint32_t)(x))<<PMC_REGSC_BGBE_SHIFT))&PMC_REGSC_BGBE_MASK)
#define PMC_REGSC_REGONS_MASK                    0x4u
#define PMC_REGSC_REGONS_SHIFT                   2
#define PMC_REGSC_REGONS_WIDTH                   1
#define PMC_REGSC_REGONS(x)                      (((uint32_t)(((uint32_t)(x))<<PMC_REGSC_REGONS_SHIFT))&PMC_REGSC_REGONS_MASK)
#define PMC_REGSC_ACKISO_MASK                    0x8u
#define PMC_REGSC_ACKISO_SHIFT                   3
#define PMC_REGSC_ACKISO_WIDTH                   1
#define PMC_REGSC_ACKISO(x)                      (((uint32_t)(((uint32_t)(x))<<PMC_REGSC_ACKISO_SHIFT))&PMC_REGSC_ACKISO_MASK)
#define PMC_REGSC_BGEN_MASK                      0x10u
#define PMC_REGSC_BGEN_SHIFT                     4
#define PMC_REGSC_BGEN_WIDTH                     1
#define PMC_REGSC_BGEN(x)                        (((uint32_t)(((uint32_t)(x))<<PMC_REGSC_BGEN_SHIFT))&PMC_REGSC_BGEN_MASK)
#define PMC_REGSC_VLPO_MASK                      0x40u
#define PMC_REGSC_VLPO_SHIFT                     6
#define PMC_REGSC_VLPO_WIDTH                     1
#define PMC_REGSC_VLPO(x)                        (((uint32_t)(((uint32_t)(x))<<PMC_REGSC_VLPO_SHIFT))&PMC_REGSC_VLPO_MASK)
/* HVDSC1 Bit Fields */
#define PMC_HVDSC1_HVDV_MASK                     0x1u
#define PMC_HVDSC1_HVDV_SHIFT                    0
#define PMC_HVDSC1_HVDV_WIDTH                    1
#define PMC_HVDSC1_HVDV(x)                       (((uint32_t)(((uint32_t)(x))<<PMC_HVDSC1_HVDV_SHIFT))&PMC_HVDSC1_HVDV_MASK)
#define PMC_HVDSC1_HVDRE_MASK                    0x10u
#define PMC_HVDSC1_HVDRE_SHIFT                   4
#define PMC_HVDSC1_HVDRE_WIDTH                   1
#define PMC_HVDSC1_HVDRE(x)                      (((uint32_t)(((uint32_t)(x))<<PMC_HVDSC1_HVDRE_SHIFT))&PMC_HVDSC1_HVDRE_MASK)
#define PMC_HVDSC1_HVDIE_MASK                    0x20u
#define PMC_HVDSC1_HVDIE_SHIFT                   5
#define PMC_HVDSC1_HVDIE_WIDTH                   1
#define PMC_HVDSC1_HVDIE(x)                      (((uint32_t)(((uint32_t)(x))<<PMC_HVDSC1_HVDIE_SHIFT))&PMC_HVDSC1_HVDIE_MASK)
#define PMC_HVDSC1_HVDACK_MASK                   0x40u
#define PMC_HVDSC1_HVDACK_SHIFT                  6
#define PMC_HVDSC1_HVDACK_WIDTH                  1
#define PMC_HVDSC1_HVDACK(x)                     (((uint32_t)(((uint32_t)(x))<<PMC_HVDSC1_HVDACK_SHIFT))&PMC_HVDSC1_HVDACK_MASK)
#define PMC_HVDSC1_HVDF_MASK                     0x80u
#define PMC_HVDSC1_HVDF_SHIFT                    7
#define PMC_HVDSC1_HVDF_WIDTH                    1
#define PMC_HVDSC1_HVDF(x)                       (((uint32_t)(((uint32_t)(x))<<PMC_HVDSC1_HVDF_SHIFT))&PMC_HVDSC1_HVDF_MASK)

/*!
 * @}
 */ /* end of group PMC_Register_Masks */


/* PMC - Peripheral instance base addresses */
/** Peripheral PMC base address */
#define PMC_BASE                                 (0x4007D000u)
/** Peripheral PMC base pointer */
#define PMC                                      ((PMC_Type *)PMC_BASE)
#define PMC_BASE_PTR                             (PMC)
/** Array initializer of PMC peripheral base addresses */
#define PMC_BASE_ADDRS                           { PMC_BASE }
/** Array initializer of PMC peripheral base pointers */
#define PMC_BASE_PTRS                            { PMC }

/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros
 * @{
 */


/* PMC - Register instance definitions */
/* PMC */
#define PMC_VERID                                PMC_VERID_REG(PMC)
#define PMC_PARAM                                PMC_PARAM_REG(PMC)
#define PMC_LVDSC1                               PMC_LVDSC1_REG(PMC)
#define PMC_LVDSC2                               PMC_LVDSC2_REG(PMC)
#define PMC_REGSC                                PMC_REGSC_REG(PMC)
#define PMC_HVDSC1                               PMC_HVDSC1_REG(PMC)

/*!
 * @}
 */ /* end of group PMC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PMC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Peripheral_Access_Layer PORT Peripheral Access Layer
 * @{
 */

/** PORT - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCR[32];                           /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
  __O  uint32_t GPCLR;                             /**< Global Pin Control Low Register, offset: 0x80 */
  __O  uint32_t GPCHR;                             /**< Global Pin Control High Register, offset: 0x84 */
  __O  uint32_t GICLR;                             /**< Global Interrupt Control Low Register, offset: 0x88 */
  __O  uint32_t GICHR;                             /**< Global Interrupt Control High Register, offset: 0x8C */
       uint8_t RESERVED_0[16];
  __IO uint32_t ISFR;                              /**< Interrupt Status Flag Register, offset: 0xA0 */
       uint8_t RESERVED_1[28];
  __IO uint32_t DFER;                              /**< Digital Filter Enable Register, offset: 0xC0 */
  __IO uint32_t DFCR;                              /**< Digital Filter Clock Register, offset: 0xC4 */
  __IO uint32_t DFWR;                              /**< Digital Filter Width Register, offset: 0xC8 */
} PORT_Type, *PORT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PORT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Accessor_Macros PORT - Register accessor macros
 * @{
 */


/* PORT - Register accessors */
#define PORT_PCR_REG(base,index)                 ((base)->PCR[index])
#define PORT_PCR_COUNT                           32
#define PORT_GPCLR_REG(base)                     ((base)->GPCLR)
#define PORT_GPCHR_REG(base)                     ((base)->GPCHR)
#define PORT_GICLR_REG(base)                     ((base)->GICLR)
#define PORT_GICHR_REG(base)                     ((base)->GICHR)
#define PORT_ISFR_REG(base)                      ((base)->ISFR)
#define PORT_DFER_REG(base)                      ((base)->DFER)
#define PORT_DFCR_REG(base)                      ((base)->DFCR)
#define PORT_DFWR_REG(base)                      ((base)->DFWR)

/*!
 * @}
 */ /* end of group PORT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/* PCR Bit Fields */
#define PORT_PCR_PS_MASK                         0x1u
#define PORT_PCR_PS_SHIFT                        0
#define PORT_PCR_PS_WIDTH                        1
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PS_SHIFT))&PORT_PCR_PS_MASK)
#define PORT_PCR_PE_MASK                         0x2u
#define PORT_PCR_PE_SHIFT                        1
#define PORT_PCR_PE_WIDTH                        1
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PE_SHIFT))&PORT_PCR_PE_MASK)
#define PORT_PCR_SRE_MASK                        0x4u
#define PORT_PCR_SRE_SHIFT                       2
#define PORT_PCR_SRE_WIDTH                       1
#define PORT_PCR_SRE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_SRE_SHIFT))&PORT_PCR_SRE_MASK)
#define PORT_PCR_PFE_MASK                        0x10u
#define PORT_PCR_PFE_SHIFT                       4
#define PORT_PCR_PFE_WIDTH                       1
#define PORT_PCR_PFE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PFE_SHIFT))&PORT_PCR_PFE_MASK)
#define PORT_PCR_ODE_MASK                        0x20u
#define PORT_PCR_ODE_SHIFT                       5
#define PORT_PCR_ODE_WIDTH                       1
#define PORT_PCR_ODE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_ODE_SHIFT))&PORT_PCR_ODE_MASK)
#define PORT_PCR_DSE_MASK                        0x40u
#define PORT_PCR_DSE_SHIFT                       6
#define PORT_PCR_DSE_WIDTH                       1
#define PORT_PCR_DSE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_DSE_SHIFT))&PORT_PCR_DSE_MASK)
#define PORT_PCR_MUX_MASK                        0x700u
#define PORT_PCR_MUX_SHIFT                       8
#define PORT_PCR_MUX_WIDTH                       3
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_MUX_SHIFT))&PORT_PCR_MUX_MASK)
#define PORT_PCR_IRQC_MASK                       0xF0000u
#define PORT_PCR_IRQC_SHIFT                      16
#define PORT_PCR_IRQC_WIDTH                      4
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_PCR_IRQC_SHIFT))&PORT_PCR_IRQC_MASK)
#define PORT_PCR_ISF_MASK                        0x1000000u
#define PORT_PCR_ISF_SHIFT                       24
#define PORT_PCR_ISF_WIDTH                       1
#define PORT_PCR_ISF(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_ISF_SHIFT))&PORT_PCR_ISF_MASK)
/* GPCLR Bit Fields */
#define PORT_GPCLR_GPWD_MASK                     0xFFFFu
#define PORT_GPCLR_GPWD_SHIFT                    0
#define PORT_GPCLR_GPWD_WIDTH                    16
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWD_SHIFT))&PORT_GPCLR_GPWD_MASK)
#define PORT_GPCLR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCLR_GPWE_SHIFT                    16
#define PORT_GPCLR_GPWE_WIDTH                    16
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWE_SHIFT))&PORT_GPCLR_GPWE_MASK)
/* GPCHR Bit Fields */
#define PORT_GPCHR_GPWD_MASK                     0xFFFFu
#define PORT_GPCHR_GPWD_SHIFT                    0
#define PORT_GPCHR_GPWD_WIDTH                    16
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWD_SHIFT))&PORT_GPCHR_GPWD_MASK)
#define PORT_GPCHR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCHR_GPWE_SHIFT                    16
#define PORT_GPCHR_GPWE_WIDTH                    16
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWE_SHIFT))&PORT_GPCHR_GPWE_MASK)
/* GICLR Bit Fields */
#define PORT_GICLR_GIWE_MASK                     0xFFFFu
#define PORT_GICLR_GIWE_SHIFT                    0
#define PORT_GICLR_GIWE_WIDTH                    16
#define PORT_GICLR_GIWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GICLR_GIWE_SHIFT))&PORT_GICLR_GIWE_MASK)
#define PORT_GICLR_GIWD_MASK                     0xFFFF0000u
#define PORT_GICLR_GIWD_SHIFT                    16
#define PORT_GICLR_GIWD_WIDTH                    16
#define PORT_GICLR_GIWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GICLR_GIWD_SHIFT))&PORT_GICLR_GIWD_MASK)
/* GICHR Bit Fields */
#define PORT_GICHR_GIWE_MASK                     0xFFFFu
#define PORT_GICHR_GIWE_SHIFT                    0
#define PORT_GICHR_GIWE_WIDTH                    16
#define PORT_GICHR_GIWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GICHR_GIWE_SHIFT))&PORT_GICHR_GIWE_MASK)
#define PORT_GICHR_GIWD_MASK                     0xFFFF0000u
#define PORT_GICHR_GIWD_SHIFT                    16
#define PORT_GICHR_GIWD_WIDTH                    16
#define PORT_GICHR_GIWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GICHR_GIWD_SHIFT))&PORT_GICHR_GIWD_MASK)
/* ISFR Bit Fields */
#define PORT_ISFR_ISF_MASK                       0xFFFFFFFFu
#define PORT_ISFR_ISF_SHIFT                      0
#define PORT_ISFR_ISF_WIDTH                      32
#define PORT_ISFR_ISF(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_ISFR_ISF_SHIFT))&PORT_ISFR_ISF_MASK)
/* DFER Bit Fields */
#define PORT_DFER_DFE_MASK                       0xFFFFFFFFu
#define PORT_DFER_DFE_SHIFT                      0
#define PORT_DFER_DFE_WIDTH                      32
#define PORT_DFER_DFE(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_DFER_DFE_SHIFT))&PORT_DFER_DFE_MASK)
/* DFCR Bit Fields */
#define PORT_DFCR_CS_MASK                        0x1u
#define PORT_DFCR_CS_SHIFT                       0
#define PORT_DFCR_CS_WIDTH                       1
#define PORT_DFCR_CS(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_DFCR_CS_SHIFT))&PORT_DFCR_CS_MASK)
/* DFWR Bit Fields */
#define PORT_DFWR_FILT_MASK                      0x1Fu
#define PORT_DFWR_FILT_SHIFT                     0
#define PORT_DFWR_FILT_WIDTH                     5
#define PORT_DFWR_FILT(x)                        (((uint32_t)(((uint32_t)(x))<<PORT_DFWR_FILT_SHIFT))&PORT_DFWR_FILT_MASK)

/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE                               (0x4005A000u)
/** Peripheral PORTA base pointer */
#define PORTA                                    ((PORT_Type *)PORTA_BASE)
#define PORTA_BASE_PTR                           (PORTA)
/** Peripheral PORTB base address */
#define PORTB_BASE                               (0x4005B000u)
/** Peripheral PORTB base pointer */
#define PORTB                                    ((PORT_Type *)PORTB_BASE)
#define PORTB_BASE_PTR                           (PORTB)
/** Peripheral PORTC base address */
#define PORTC_BASE                               (0x4005C000u)
/** Peripheral PORTC base pointer */
#define PORTC                                    ((PORT_Type *)PORTC_BASE)
#define PORTC_BASE_PTR                           (PORTC)
/** Peripheral PORTD base address */
#define PORTD_BASE                               (0x4005D000u)
/** Peripheral PORTD base pointer */
#define PORTD                                    ((PORT_Type *)PORTD_BASE)
#define PORTD_BASE_PTR                           (PORTD)
/** Peripheral PORTE base address */
#define PORTE_BASE                               (0x4005E000u)
/** Peripheral PORTE base pointer */
#define PORTE                                    ((PORT_Type *)PORTE_BASE)
#define PORTE_BASE_PTR                           (PORTE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE, PORTE_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, PORTD, PORTE }

/* ----------------------------------------------------------------------------
   -- PORT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Accessor_Macros PORT - Register accessor macros
 * @{
 */


/* PORT - Register instance definitions */
/* PORTA */
#define PORTA_PCR0                               PORT_PCR_REG(PORTA,0)
#define PORTA_PCR1                               PORT_PCR_REG(PORTA,1)
#define PORTA_PCR2                               PORT_PCR_REG(PORTA,2)
#define PORTA_PCR3                               PORT_PCR_REG(PORTA,3)
#define PORTA_PCR4                               PORT_PCR_REG(PORTA,4)
#define PORTA_PCR5                               PORT_PCR_REG(PORTA,5)
#define PORTA_PCR6                               PORT_PCR_REG(PORTA,6)
#define PORTA_PCR7                               PORT_PCR_REG(PORTA,7)
#define PORTA_PCR8                               PORT_PCR_REG(PORTA,8)
#define PORTA_PCR9                               PORT_PCR_REG(PORTA,9)
#define PORTA_PCR10                              PORT_PCR_REG(PORTA,10)
#define PORTA_PCR11                              PORT_PCR_REG(PORTA,11)
#define PORTA_PCR12                              PORT_PCR_REG(PORTA,12)
#define PORTA_PCR13                              PORT_PCR_REG(PORTA,13)
#define PORTA_PCR14                              PORT_PCR_REG(PORTA,14)
#define PORTA_PCR15                              PORT_PCR_REG(PORTA,15)
#define PORTA_PCR16                              PORT_PCR_REG(PORTA,16)
#define PORTA_PCR17                              PORT_PCR_REG(PORTA,17)
#define PORTA_PCR18                              PORT_PCR_REG(PORTA,18)
#define PORTA_PCR19                              PORT_PCR_REG(PORTA,19)
#define PORTA_PCR20                              PORT_PCR_REG(PORTA,20)
#define PORTA_PCR21                              PORT_PCR_REG(PORTA,21)
#define PORTA_PCR22                              PORT_PCR_REG(PORTA,22)
#define PORTA_PCR23                              PORT_PCR_REG(PORTA,23)
#define PORTA_PCR24                              PORT_PCR_REG(PORTA,24)
#define PORTA_PCR25                              PORT_PCR_REG(PORTA,25)
#define PORTA_PCR26                              PORT_PCR_REG(PORTA,26)
#define PORTA_PCR27                              PORT_PCR_REG(PORTA,27)
#define PORTA_PCR28                              PORT_PCR_REG(PORTA,28)
#define PORTA_PCR29                              PORT_PCR_REG(PORTA,29)
#define PORTA_PCR30                              PORT_PCR_REG(PORTA,30)
#define PORTA_PCR31                              PORT_PCR_REG(PORTA,31)
#define PORTA_GPCLR                              PORT_GPCLR_REG(PORTA)
#define PORTA_GPCHR                              PORT_GPCHR_REG(PORTA)
#define PORTA_GICLR                              PORT_GICLR_REG(PORTA)
#define PORTA_GICHR                              PORT_GICHR_REG(PORTA)
#define PORTA_ISFR                               PORT_ISFR_REG(PORTA)
#define PORTA_DFER                               PORT_DFER_REG(PORTA)
#define PORTA_DFCR                               PORT_DFCR_REG(PORTA)
#define PORTA_DFWR                               PORT_DFWR_REG(PORTA)
/* PORTB */
#define PORTB_PCR0                               PORT_PCR_REG(PORTB,0)
#define PORTB_PCR1                               PORT_PCR_REG(PORTB,1)
#define PORTB_PCR2                               PORT_PCR_REG(PORTB,2)
#define PORTB_PCR3                               PORT_PCR_REG(PORTB,3)
#define PORTB_PCR4                               PORT_PCR_REG(PORTB,4)
#define PORTB_PCR5                               PORT_PCR_REG(PORTB,5)
#define PORTB_PCR6                               PORT_PCR_REG(PORTB,6)
#define PORTB_PCR7                               PORT_PCR_REG(PORTB,7)
#define PORTB_PCR8                               PORT_PCR_REG(PORTB,8)
#define PORTB_PCR9                               PORT_PCR_REG(PORTB,9)
#define PORTB_PCR10                              PORT_PCR_REG(PORTB,10)
#define PORTB_PCR11                              PORT_PCR_REG(PORTB,11)
#define PORTB_PCR12                              PORT_PCR_REG(PORTB,12)
#define PORTB_PCR13                              PORT_PCR_REG(PORTB,13)
#define PORTB_PCR14                              PORT_PCR_REG(PORTB,14)
#define PORTB_PCR15                              PORT_PCR_REG(PORTB,15)
#define PORTB_PCR16                              PORT_PCR_REG(PORTB,16)
#define PORTB_PCR17                              PORT_PCR_REG(PORTB,17)
#define PORTB_PCR18                              PORT_PCR_REG(PORTB,18)
#define PORTB_PCR19                              PORT_PCR_REG(PORTB,19)
#define PORTB_PCR20                              PORT_PCR_REG(PORTB,20)
#define PORTB_PCR21                              PORT_PCR_REG(PORTB,21)
#define PORTB_PCR22                              PORT_PCR_REG(PORTB,22)
#define PORTB_PCR23                              PORT_PCR_REG(PORTB,23)
#define PORTB_PCR24                              PORT_PCR_REG(PORTB,24)
#define PORTB_PCR25                              PORT_PCR_REG(PORTB,25)
#define PORTB_PCR26                              PORT_PCR_REG(PORTB,26)
#define PORTB_PCR27                              PORT_PCR_REG(PORTB,27)
#define PORTB_PCR28                              PORT_PCR_REG(PORTB,28)
#define PORTB_PCR29                              PORT_PCR_REG(PORTB,29)
#define PORTB_PCR30                              PORT_PCR_REG(PORTB,30)
#define PORTB_PCR31                              PORT_PCR_REG(PORTB,31)
#define PORTB_GPCLR                              PORT_GPCLR_REG(PORTB)
#define PORTB_GPCHR                              PORT_GPCHR_REG(PORTB)
#define PORTB_GICLR                              PORT_GICLR_REG(PORTB)
#define PORTB_GICHR                              PORT_GICHR_REG(PORTB)
#define PORTB_ISFR                               PORT_ISFR_REG(PORTB)
#define PORTB_DFER                               PORT_DFER_REG(PORTB)
#define PORTB_DFCR                               PORT_DFCR_REG(PORTB)
#define PORTB_DFWR                               PORT_DFWR_REG(PORTB)
/* PORTC */
#define PORTC_PCR0                               PORT_PCR_REG(PORTC,0)
#define PORTC_PCR1                               PORT_PCR_REG(PORTC,1)
#define PORTC_PCR2                               PORT_PCR_REG(PORTC,2)
#define PORTC_PCR3                               PORT_PCR_REG(PORTC,3)
#define PORTC_PCR4                               PORT_PCR_REG(PORTC,4)
#define PORTC_PCR5                               PORT_PCR_REG(PORTC,5)
#define PORTC_PCR6                               PORT_PCR_REG(PORTC,6)
#define PORTC_PCR7                               PORT_PCR_REG(PORTC,7)
#define PORTC_PCR8                               PORT_PCR_REG(PORTC,8)
#define PORTC_PCR9                               PORT_PCR_REG(PORTC,9)
#define PORTC_PCR10                              PORT_PCR_REG(PORTC,10)
#define PORTC_PCR11                              PORT_PCR_REG(PORTC,11)
#define PORTC_PCR12                              PORT_PCR_REG(PORTC,12)
#define PORTC_PCR13                              PORT_PCR_REG(PORTC,13)
#define PORTC_PCR14                              PORT_PCR_REG(PORTC,14)
#define PORTC_PCR15                              PORT_PCR_REG(PORTC,15)
#define PORTC_PCR16                              PORT_PCR_REG(PORTC,16)
#define PORTC_PCR17                              PORT_PCR_REG(PORTC,17)
#define PORTC_PCR18                              PORT_PCR_REG(PORTC,18)
#define PORTC_PCR19                              PORT_PCR_REG(PORTC,19)
#define PORTC_PCR20                              PORT_PCR_REG(PORTC,20)
#define PORTC_PCR21                              PORT_PCR_REG(PORTC,21)
#define PORTC_PCR22                              PORT_PCR_REG(PORTC,22)
#define PORTC_PCR23                              PORT_PCR_REG(PORTC,23)
#define PORTC_PCR24                              PORT_PCR_REG(PORTC,24)
#define PORTC_PCR25                              PORT_PCR_REG(PORTC,25)
#define PORTC_PCR26                              PORT_PCR_REG(PORTC,26)
#define PORTC_PCR27                              PORT_PCR_REG(PORTC,27)
#define PORTC_PCR28                              PORT_PCR_REG(PORTC,28)
#define PORTC_PCR29                              PORT_PCR_REG(PORTC,29)
#define PORTC_PCR30                              PORT_PCR_REG(PORTC,30)
#define PORTC_PCR31                              PORT_PCR_REG(PORTC,31)
#define PORTC_GPCLR                              PORT_GPCLR_REG(PORTC)
#define PORTC_GPCHR                              PORT_GPCHR_REG(PORTC)
#define PORTC_GICLR                              PORT_GICLR_REG(PORTC)
#define PORTC_GICHR                              PORT_GICHR_REG(PORTC)
#define PORTC_ISFR                               PORT_ISFR_REG(PORTC)
#define PORTC_DFER                               PORT_DFER_REG(PORTC)
#define PORTC_DFCR                               PORT_DFCR_REG(PORTC)
#define PORTC_DFWR                               PORT_DFWR_REG(PORTC)
/* PORTD */
#define PORTD_PCR0                               PORT_PCR_REG(PORTD,0)
#define PORTD_PCR1                               PORT_PCR_REG(PORTD,1)
#define PORTD_PCR2                               PORT_PCR_REG(PORTD,2)
#define PORTD_PCR3                               PORT_PCR_REG(PORTD,3)
#define PORTD_PCR4                               PORT_PCR_REG(PORTD,4)
#define PORTD_PCR5                               PORT_PCR_REG(PORTD,5)
#define PORTD_PCR6                               PORT_PCR_REG(PORTD,6)
#define PORTD_PCR7                               PORT_PCR_REG(PORTD,7)
#define PORTD_PCR8                               PORT_PCR_REG(PORTD,8)
#define PORTD_PCR9                               PORT_PCR_REG(PORTD,9)
#define PORTD_PCR10                              PORT_PCR_REG(PORTD,10)
#define PORTD_PCR11                              PORT_PCR_REG(PORTD,11)
#define PORTD_PCR12                              PORT_PCR_REG(PORTD,12)
#define PORTD_PCR13                              PORT_PCR_REG(PORTD,13)
#define PORTD_PCR14                              PORT_PCR_REG(PORTD,14)
#define PORTD_PCR15                              PORT_PCR_REG(PORTD,15)
#define PORTD_PCR16                              PORT_PCR_REG(PORTD,16)
#define PORTD_PCR17                              PORT_PCR_REG(PORTD,17)
#define PORTD_PCR18                              PORT_PCR_REG(PORTD,18)
#define PORTD_PCR19                              PORT_PCR_REG(PORTD,19)
#define PORTD_PCR20                              PORT_PCR_REG(PORTD,20)
#define PORTD_PCR21                              PORT_PCR_REG(PORTD,21)
#define PORTD_PCR22                              PORT_PCR_REG(PORTD,22)
#define PORTD_PCR23                              PORT_PCR_REG(PORTD,23)
#define PORTD_PCR24                              PORT_PCR_REG(PORTD,24)
#define PORTD_PCR25                              PORT_PCR_REG(PORTD,25)
#define PORTD_PCR26                              PORT_PCR_REG(PORTD,26)
#define PORTD_PCR27                              PORT_PCR_REG(PORTD,27)
#define PORTD_PCR28                              PORT_PCR_REG(PORTD,28)
#define PORTD_PCR29                              PORT_PCR_REG(PORTD,29)
#define PORTD_PCR30                              PORT_PCR_REG(PORTD,30)
#define PORTD_PCR31                              PORT_PCR_REG(PORTD,31)
#define PORTD_GPCLR                              PORT_GPCLR_REG(PORTD)
#define PORTD_GPCHR                              PORT_GPCHR_REG(PORTD)
#define PORTD_GICLR                              PORT_GICLR_REG(PORTD)
#define PORTD_GICHR                              PORT_GICHR_REG(PORTD)
#define PORTD_ISFR                               PORT_ISFR_REG(PORTD)
#define PORTD_DFER                               PORT_DFER_REG(PORTD)
#define PORTD_DFCR                               PORT_DFCR_REG(PORTD)
#define PORTD_DFWR                               PORT_DFWR_REG(PORTD)
/* PORTE */
#define PORTE_PCR0                               PORT_PCR_REG(PORTE,0)
#define PORTE_PCR1                               PORT_PCR_REG(PORTE,1)
#define PORTE_PCR2                               PORT_PCR_REG(PORTE,2)
#define PORTE_PCR3                               PORT_PCR_REG(PORTE,3)
#define PORTE_PCR4                               PORT_PCR_REG(PORTE,4)
#define PORTE_PCR5                               PORT_PCR_REG(PORTE,5)
#define PORTE_PCR6                               PORT_PCR_REG(PORTE,6)
#define PORTE_PCR7                               PORT_PCR_REG(PORTE,7)
#define PORTE_PCR8                               PORT_PCR_REG(PORTE,8)
#define PORTE_PCR9                               PORT_PCR_REG(PORTE,9)
#define PORTE_PCR10                              PORT_PCR_REG(PORTE,10)
#define PORTE_PCR11                              PORT_PCR_REG(PORTE,11)
#define PORTE_PCR12                              PORT_PCR_REG(PORTE,12)
#define PORTE_PCR13                              PORT_PCR_REG(PORTE,13)
#define PORTE_PCR14                              PORT_PCR_REG(PORTE,14)
#define PORTE_PCR15                              PORT_PCR_REG(PORTE,15)
#define PORTE_PCR16                              PORT_PCR_REG(PORTE,16)
#define PORTE_PCR17                              PORT_PCR_REG(PORTE,17)
#define PORTE_PCR18                              PORT_PCR_REG(PORTE,18)
#define PORTE_PCR19                              PORT_PCR_REG(PORTE,19)
#define PORTE_PCR20                              PORT_PCR_REG(PORTE,20)
#define PORTE_PCR21                              PORT_PCR_REG(PORTE,21)
#define PORTE_PCR22                              PORT_PCR_REG(PORTE,22)
#define PORTE_PCR23                              PORT_PCR_REG(PORTE,23)
#define PORTE_PCR24                              PORT_PCR_REG(PORTE,24)
#define PORTE_PCR25                              PORT_PCR_REG(PORTE,25)
#define PORTE_PCR26                              PORT_PCR_REG(PORTE,26)
#define PORTE_PCR27                              PORT_PCR_REG(PORTE,27)
#define PORTE_PCR28                              PORT_PCR_REG(PORTE,28)
#define PORTE_PCR29                              PORT_PCR_REG(PORTE,29)
#define PORTE_PCR30                              PORT_PCR_REG(PORTE,30)
#define PORTE_PCR31                              PORT_PCR_REG(PORTE,31)
#define PORTE_GPCLR                              PORT_GPCLR_REG(PORTE)
#define PORTE_GPCHR                              PORT_GPCHR_REG(PORTE)
#define PORTE_GICLR                              PORT_GICLR_REG(PORTE)
#define PORTE_GICHR                              PORT_GICHR_REG(PORTE)
#define PORTE_ISFR                               PORT_ISFR_REG(PORTE)
#define PORTE_DFER                               PORT_DFER_REG(PORTE)
#define PORTE_DFCR                               PORT_DFCR_REG(PORTE)
#define PORTE_DFWR                               PORT_DFWR_REG(PORTE)

/* PORT - Register array accessors */
#define PORTA_PCR(index)                         PORT_PCR_REG(PORTA,index)
#define PORTB_PCR(index)                         PORT_PCR_REG(PORTB,index)
#define PORTC_PCR(index)                         PORT_PCR_REG(PORTC,index)
#define PORTD_PCR(index)                         PORT_PCR_REG(PORTD,index)
#define PORTE_PCR(index)                         PORT_PCR_REG(PORTE,index)

/*!
 * @}
 */ /* end of group PORT_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PORT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Peripheral_Access_Layer RCM Peripheral Access Layer
 * @{
 */

/** RCM - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __I  uint32_t SRS;                               /**< System Reset Status Register, offset: 0x8 */
  __IO uint32_t RPC;                               /**< Reset Pin Control register, offset: 0xC */
  __IO uint32_t MR;                                /**< Mode Register, offset: 0x10 */
  __IO uint32_t FM;                                /**< Force Mode Register, offset: 0x14 */
  __IO uint32_t SSRS;                              /**< Sticky System Reset Status Register, offset: 0x18 */
  __IO uint32_t SRIE;                              /**< System Reset Interrupt Enable Register, offset: 0x1C */
} RCM_Type, *RCM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Register_Accessor_Macros RCM - Register accessor macros
 * @{
 */


/* RCM - Register accessors */
#define RCM_VERID_REG(base)                      ((base)->VERID)
#define RCM_PARAM_REG(base)                      ((base)->PARAM)
#define RCM_SRS_REG(base)                        ((base)->SRS)
#define RCM_RPC_REG(base)                        ((base)->RPC)
#define RCM_MR_REG(base)                         ((base)->MR)
#define RCM_FM_REG(base)                         ((base)->FM)
#define RCM_SSRS_REG(base)                       ((base)->SSRS)
#define RCM_SRIE_REG(base)                       ((base)->SRIE)

/*!
 * @}
 */ /* end of group RCM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Register_Masks RCM Register Masks
 * @{
 */

/* VERID Bit Fields */
#define RCM_VERID_FEATURE_MASK                   0xFFFFu
#define RCM_VERID_FEATURE_SHIFT                  0
#define RCM_VERID_FEATURE_WIDTH                  16
#define RCM_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x))<<RCM_VERID_FEATURE_SHIFT))&RCM_VERID_FEATURE_MASK)
#define RCM_VERID_MINOR_MASK                     0xFF0000u
#define RCM_VERID_MINOR_SHIFT                    16
#define RCM_VERID_MINOR_WIDTH                    8
#define RCM_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x))<<RCM_VERID_MINOR_SHIFT))&RCM_VERID_MINOR_MASK)
#define RCM_VERID_MAJOR_MASK                     0xFF000000u
#define RCM_VERID_MAJOR_SHIFT                    24
#define RCM_VERID_MAJOR_WIDTH                    8
#define RCM_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x))<<RCM_VERID_MAJOR_SHIFT))&RCM_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define RCM_PARAM_RSTSRC_MASK                    0xFFFFFFFFu
#define RCM_PARAM_RSTSRC_SHIFT                   0
#define RCM_PARAM_RSTSRC_WIDTH                   32
#define RCM_PARAM_RSTSRC(x)                      (((uint32_t)(((uint32_t)(x))<<RCM_PARAM_RSTSRC_SHIFT))&RCM_PARAM_RSTSRC_MASK)
/* SRS Bit Fields */
#define RCM_SRS_WAKEUP_MASK                      0x1u
#define RCM_SRS_WAKEUP_SHIFT                     0
#define RCM_SRS_WAKEUP_WIDTH                     1
#define RCM_SRS_WAKEUP(x)                        (((uint32_t)(((uint32_t)(x))<<RCM_SRS_WAKEUP_SHIFT))&RCM_SRS_WAKEUP_MASK)
#define RCM_SRS_LVD_MASK                         0x2u
#define RCM_SRS_LVD_SHIFT                        1
#define RCM_SRS_LVD_WIDTH                        1
#define RCM_SRS_LVD(x)                           (((uint32_t)(((uint32_t)(x))<<RCM_SRS_LVD_SHIFT))&RCM_SRS_LVD_MASK)
#define RCM_SRS_LOC_MASK                         0x4u
#define RCM_SRS_LOC_SHIFT                        2
#define RCM_SRS_LOC_WIDTH                        1
#define RCM_SRS_LOC(x)                           (((uint32_t)(((uint32_t)(x))<<RCM_SRS_LOC_SHIFT))&RCM_SRS_LOC_MASK)
#define RCM_SRS_LOL_MASK                         0x8u
#define RCM_SRS_LOL_SHIFT                        3
#define RCM_SRS_LOL_WIDTH                        1
#define RCM_SRS_LOL(x)                           (((uint32_t)(((uint32_t)(x))<<RCM_SRS_LOL_SHIFT))&RCM_SRS_LOL_MASK)
#define RCM_SRS_WDOG_MASK                        0x20u
#define RCM_SRS_WDOG_SHIFT                       5
#define RCM_SRS_WDOG_WIDTH                       1
#define RCM_SRS_WDOG(x)                          (((uint32_t)(((uint32_t)(x))<<RCM_SRS_WDOG_SHIFT))&RCM_SRS_WDOG_MASK)
#define RCM_SRS_PIN_MASK                         0x40u
#define RCM_SRS_PIN_SHIFT                        6
#define RCM_SRS_PIN_WIDTH                        1
#define RCM_SRS_PIN(x)                           (((uint32_t)(((uint32_t)(x))<<RCM_SRS_PIN_SHIFT))&RCM_SRS_PIN_MASK)
#define RCM_SRS_POR_MASK                         0x80u
#define RCM_SRS_POR_SHIFT                        7
#define RCM_SRS_POR_WIDTH                        1
#define RCM_SRS_POR(x)                           (((uint32_t)(((uint32_t)(x))<<RCM_SRS_POR_SHIFT))&RCM_SRS_POR_MASK)
#define RCM_SRS_LOCKUP_MASK                      0x200u
#define RCM_SRS_LOCKUP_SHIFT                     9
#define RCM_SRS_LOCKUP_WIDTH                     1
#define RCM_SRS_LOCKUP(x)                        (((uint32_t)(((uint32_t)(x))<<RCM_SRS_LOCKUP_SHIFT))&RCM_SRS_LOCKUP_MASK)
#define RCM_SRS_SW_MASK                          0x400u
#define RCM_SRS_SW_SHIFT                         10
#define RCM_SRS_SW_WIDTH                         1
#define RCM_SRS_SW(x)                            (((uint32_t)(((uint32_t)(x))<<RCM_SRS_SW_SHIFT))&RCM_SRS_SW_MASK)
#define RCM_SRS_MDM_AP_MASK                      0x800u
#define RCM_SRS_MDM_AP_SHIFT                     11
#define RCM_SRS_MDM_AP_WIDTH                     1
#define RCM_SRS_MDM_AP(x)                        (((uint32_t)(((uint32_t)(x))<<RCM_SRS_MDM_AP_SHIFT))&RCM_SRS_MDM_AP_MASK)
#define RCM_SRS_SACKERR_MASK                     0x2000u
#define RCM_SRS_SACKERR_SHIFT                    13
#define RCM_SRS_SACKERR_WIDTH                    1
#define RCM_SRS_SACKERR(x)                       (((uint32_t)(((uint32_t)(x))<<RCM_SRS_SACKERR_SHIFT))&RCM_SRS_SACKERR_MASK)
/* RPC Bit Fields */
#define RCM_RPC_RSTFLTSRW_MASK                   0x3u
#define RCM_RPC_RSTFLTSRW_SHIFT                  0
#define RCM_RPC_RSTFLTSRW_WIDTH                  2
#define RCM_RPC_RSTFLTSRW(x)                     (((uint32_t)(((uint32_t)(x))<<RCM_RPC_RSTFLTSRW_SHIFT))&RCM_RPC_RSTFLTSRW_MASK)
#define RCM_RPC_RSTFLTSS_MASK                    0x4u
#define RCM_RPC_RSTFLTSS_SHIFT                   2
#define RCM_RPC_RSTFLTSS_WIDTH                   1
#define RCM_RPC_RSTFLTSS(x)                      (((uint32_t)(((uint32_t)(x))<<RCM_RPC_RSTFLTSS_SHIFT))&RCM_RPC_RSTFLTSS_MASK)
#define RCM_RPC_RSTFLTSEL_MASK                   0x1F00u
#define RCM_RPC_RSTFLTSEL_SHIFT                  8
#define RCM_RPC_RSTFLTSEL_WIDTH                  5
#define RCM_RPC_RSTFLTSEL(x)                     (((uint32_t)(((uint32_t)(x))<<RCM_RPC_RSTFLTSEL_SHIFT))&RCM_RPC_RSTFLTSEL_MASK)
/* MR Bit Fields */
#define RCM_MR_BOOTROM_MASK                      0x6u
#define RCM_MR_BOOTROM_SHIFT                     1
#define RCM_MR_BOOTROM_WIDTH                     2
#define RCM_MR_BOOTROM(x)                        (((uint32_t)(((uint32_t)(x))<<RCM_MR_BOOTROM_SHIFT))&RCM_MR_BOOTROM_MASK)
/* FM Bit Fields */
#define RCM_FM_FORCEROM_MASK                     0x6u
#define RCM_FM_FORCEROM_SHIFT                    1
#define RCM_FM_FORCEROM_WIDTH                    2
#define RCM_FM_FORCEROM(x)                       (((uint32_t)(((uint32_t)(x))<<RCM_FM_FORCEROM_SHIFT))&RCM_FM_FORCEROM_MASK)
/* SSRS Bit Fields */
#define RCM_SSRS_SWAKEUP_MASK                    0x1u
#define RCM_SSRS_SWAKEUP_SHIFT                   0
#define RCM_SSRS_SWAKEUP_WIDTH                   1
#define RCM_SSRS_SWAKEUP(x)                      (((uint32_t)(((uint32_t)(x))<<RCM_SSRS_SWAKEUP_SHIFT))&RCM_SSRS_SWAKEUP_MASK)
#define RCM_SSRS_SLVD_MASK                       0x2u
#define RCM_SSRS_SLVD_SHIFT                      1
#define RCM_SSRS_SLVD_WIDTH                      1
#define RCM_SSRS_SLVD(x)                         (((uint32_t)(((uint32_t)(x))<<RCM_SSRS_SLVD_SHIFT))&RCM_SSRS_SLVD_MASK)
#define RCM_SSRS_SLOC_MASK                       0x4u
#define RCM_SSRS_SLOC_SHIFT                      2
#define RCM_SSRS_SLOC_WIDTH                      1
#define RCM_SSRS_SLOC(x)                         (((uint32_t)(((uint32_t)(x))<<RCM_SSRS_SLOC_SHIFT))&RCM_SSRS_SLOC_MASK)
#define RCM_SSRS_SLOL_MASK                       0x8u
#define RCM_SSRS_SLOL_SHIFT                      3
#define RCM_SSRS_SLOL_WIDTH                      1
#define RCM_SSRS_SLOL(x)                         (((uint32_t)(((uint32_t)(x))<<RCM_SSRS_SLOL_SHIFT))&RCM_SSRS_SLOL_MASK)
#define RCM_SSRS_SWDOG_MASK                      0x20u
#define RCM_SSRS_SWDOG_SHIFT                     5
#define RCM_SSRS_SWDOG_WIDTH                     1
#define RCM_SSRS_SWDOG(x)                        (((uint32_t)(((uint32_t)(x))<<RCM_SSRS_SWDOG_SHIFT))&RCM_SSRS_SWDOG_MASK)
#define RCM_SSRS_SPIN_MASK                       0x40u
#define RCM_SSRS_SPIN_SHIFT                      6
#define RCM_SSRS_SPIN_WIDTH                      1
#define RCM_SSRS_SPIN(x)                         (((uint32_t)(((uint32_t)(x))<<RCM_SSRS_SPIN_SHIFT))&RCM_SSRS_SPIN_MASK)
#define RCM_SSRS_SPOR_MASK                       0x80u
#define RCM_SSRS_SPOR_SHIFT                      7
#define RCM_SSRS_SPOR_WIDTH                      1
#define RCM_SSRS_SPOR(x)                         (((uint32_t)(((uint32_t)(x))<<RCM_SSRS_SPOR_SHIFT))&RCM_SSRS_SPOR_MASK)
#define RCM_SSRS_SLOCKUP_MASK                    0x200u
#define RCM_SSRS_SLOCKUP_SHIFT                   9
#define RCM_SSRS_SLOCKUP_WIDTH                   1
#define RCM_SSRS_SLOCKUP(x)                      (((uint32_t)(((uint32_t)(x))<<RCM_SSRS_SLOCKUP_SHIFT))&RCM_SSRS_SLOCKUP_MASK)
#define RCM_SSRS_SSW_MASK                        0x400u
#define RCM_SSRS_SSW_SHIFT                       10
#define RCM_SSRS_SSW_WIDTH                       1
#define RCM_SSRS_SSW(x)                          (((uint32_t)(((uint32_t)(x))<<RCM_SSRS_SSW_SHIFT))&RCM_SSRS_SSW_MASK)
#define RCM_SSRS_SSACKERR_MASK                   0x2000u
#define RCM_SSRS_SSACKERR_SHIFT                  13
#define RCM_SSRS_SSACKERR_WIDTH                  1
#define RCM_SSRS_SSACKERR(x)                     (((uint32_t)(((uint32_t)(x))<<RCM_SSRS_SSACKERR_SHIFT))&RCM_SSRS_SSACKERR_MASK)
/* SRIE Bit Fields */
#define RCM_SRIE_DELAY_MASK                      0x3u
#define RCM_SRIE_DELAY_SHIFT                     0
#define RCM_SRIE_DELAY_WIDTH                     2
#define RCM_SRIE_DELAY(x)                        (((uint32_t)(((uint32_t)(x))<<RCM_SRIE_DELAY_SHIFT))&RCM_SRIE_DELAY_MASK)
#define RCM_SRIE_LOC_MASK                        0x4u
#define RCM_SRIE_LOC_SHIFT                       2
#define RCM_SRIE_LOC_WIDTH                       1
#define RCM_SRIE_LOC(x)                          (((uint32_t)(((uint32_t)(x))<<RCM_SRIE_LOC_SHIFT))&RCM_SRIE_LOC_MASK)
#define RCM_SRIE_LOL_MASK                        0x8u
#define RCM_SRIE_LOL_SHIFT                       3
#define RCM_SRIE_LOL_WIDTH                       1
#define RCM_SRIE_LOL(x)                          (((uint32_t)(((uint32_t)(x))<<RCM_SRIE_LOL_SHIFT))&RCM_SRIE_LOL_MASK)
#define RCM_SRIE_WDOG_MASK                       0x20u
#define RCM_SRIE_WDOG_SHIFT                      5
#define RCM_SRIE_WDOG_WIDTH                      1
#define RCM_SRIE_WDOG(x)                         (((uint32_t)(((uint32_t)(x))<<RCM_SRIE_WDOG_SHIFT))&RCM_SRIE_WDOG_MASK)
#define RCM_SRIE_PIN_MASK                        0x40u
#define RCM_SRIE_PIN_SHIFT                       6
#define RCM_SRIE_PIN_WIDTH                       1
#define RCM_SRIE_PIN(x)                          (((uint32_t)(((uint32_t)(x))<<RCM_SRIE_PIN_SHIFT))&RCM_SRIE_PIN_MASK)
#define RCM_SRIE_GIE_MASK                        0x80u
#define RCM_SRIE_GIE_SHIFT                       7
#define RCM_SRIE_GIE_WIDTH                       1
#define RCM_SRIE_GIE(x)                          (((uint32_t)(((uint32_t)(x))<<RCM_SRIE_GIE_SHIFT))&RCM_SRIE_GIE_MASK)
#define RCM_SRIE_LOCKUP_MASK                     0x200u
#define RCM_SRIE_LOCKUP_SHIFT                    9
#define RCM_SRIE_LOCKUP_WIDTH                    1
#define RCM_SRIE_LOCKUP(x)                       (((uint32_t)(((uint32_t)(x))<<RCM_SRIE_LOCKUP_SHIFT))&RCM_SRIE_LOCKUP_MASK)
#define RCM_SRIE_SW_MASK                         0x400u
#define RCM_SRIE_SW_SHIFT                        10
#define RCM_SRIE_SW_WIDTH                        1
#define RCM_SRIE_SW(x)                           (((uint32_t)(((uint32_t)(x))<<RCM_SRIE_SW_SHIFT))&RCM_SRIE_SW_MASK)
#define RCM_SRIE_SACKERR_MASK                    0x2000u
#define RCM_SRIE_SACKERR_SHIFT                   13
#define RCM_SRIE_SACKERR_WIDTH                   1
#define RCM_SRIE_SACKERR(x)                      (((uint32_t)(((uint32_t)(x))<<RCM_SRIE_SACKERR_SHIFT))&RCM_SRIE_SACKERR_MASK)

/*!
 * @}
 */ /* end of group RCM_Register_Masks */


/* RCM - Peripheral instance base addresses */
/** Peripheral RCM base address */
#define RCM_BASE                                 (0x4007F000u)
/** Peripheral RCM base pointer */
#define RCM                                      ((RCM_Type *)RCM_BASE)
#define RCM_BASE_PTR                             (RCM)
/** Array initializer of RCM peripheral base addresses */
#define RCM_BASE_ADDRS                           { RCM_BASE }
/** Array initializer of RCM peripheral base pointers */
#define RCM_BASE_PTRS                            { RCM }

/* ----------------------------------------------------------------------------
   -- RCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Register_Accessor_Macros RCM - Register accessor macros
 * @{
 */


/* RCM - Register instance definitions */
/* RCM */
#define RCM_VERID                                RCM_VERID_REG(RCM)
#define RCM_PARAM                                RCM_PARAM_REG(RCM)
#define RCM_SRS                                  RCM_SRS_REG(RCM)
#define RCM_RPC                                  RCM_RPC_REG(RCM)
#define RCM_MR                                   RCM_MR_REG(RCM)
#define RCM_FM                                   RCM_FM_REG(RCM)
#define RCM_SSRS                                 RCM_SSRS_REG(RCM)
#define RCM_SRIE                                 RCM_SRIE_REG(RCM)

/*!
 * @}
 */ /* end of group RCM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group RCM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */

/** RTC - Register Layout Typedef */
typedef struct {
  __IO uint32_t TSR;                               /**< RTC Time Seconds Register, offset: 0x0 */
  __IO uint32_t TPR;                               /**< RTC Time Prescaler Register, offset: 0x4 */
  __IO uint32_t TAR;                               /**< RTC Time Alarm Register, offset: 0x8 */
  __IO uint32_t TCR;                               /**< RTC Time Compensation Register, offset: 0xC */
  __IO uint32_t CR;                                /**< RTC Control Register, offset: 0x10 */
  __IO uint32_t SR;                                /**< RTC Status Register, offset: 0x14 */
  __IO uint32_t LR;                                /**< RTC Lock Register, offset: 0x18 */
  __IO uint32_t IER;                               /**< RTC Interrupt Enable Register, offset: 0x1C */
} RTC_Type, *RTC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RTC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Accessor_Macros RTC - Register accessor macros
 * @{
 */


/* RTC - Register accessors */
#define RTC_TSR_REG(base)                        ((base)->TSR)
#define RTC_TPR_REG(base)                        ((base)->TPR)
#define RTC_TAR_REG(base)                        ((base)->TAR)
#define RTC_TCR_REG(base)                        ((base)->TCR)
#define RTC_CR_REG(base)                         ((base)->CR)
#define RTC_SR_REG(base)                         ((base)->SR)
#define RTC_LR_REG(base)                         ((base)->LR)
#define RTC_IER_REG(base)                        ((base)->IER)

/*!
 * @}
 */ /* end of group RTC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/* TSR Bit Fields */
#define RTC_TSR_TSR_MASK                         0xFFFFFFFFu
#define RTC_TSR_TSR_SHIFT                        0
#define RTC_TSR_TSR_WIDTH                        32
#define RTC_TSR_TSR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSR_TSR_SHIFT))&RTC_TSR_TSR_MASK)
/* TPR Bit Fields */
#define RTC_TPR_TPR_MASK                         0xFFFFu
#define RTC_TPR_TPR_SHIFT                        0
#define RTC_TPR_TPR_WIDTH                        16
#define RTC_TPR_TPR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TPR_TPR_SHIFT))&RTC_TPR_TPR_MASK)
/* TAR Bit Fields */
#define RTC_TAR_TAR_MASK                         0xFFFFFFFFu
#define RTC_TAR_TAR_SHIFT                        0
#define RTC_TAR_TAR_WIDTH                        32
#define RTC_TAR_TAR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TAR_TAR_SHIFT))&RTC_TAR_TAR_MASK)
/* TCR Bit Fields */
#define RTC_TCR_TCR_MASK                         0xFFu
#define RTC_TCR_TCR_SHIFT                        0
#define RTC_TCR_TCR_WIDTH                        8
#define RTC_TCR_TCR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_TCR_SHIFT))&RTC_TCR_TCR_MASK)
#define RTC_TCR_CIR_MASK                         0xFF00u
#define RTC_TCR_CIR_SHIFT                        8
#define RTC_TCR_CIR_WIDTH                        8
#define RTC_TCR_CIR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_CIR_SHIFT))&RTC_TCR_CIR_MASK)
#define RTC_TCR_TCV_MASK                         0xFF0000u
#define RTC_TCR_TCV_SHIFT                        16
#define RTC_TCR_TCV_WIDTH                        8
#define RTC_TCR_TCV(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_TCV_SHIFT))&RTC_TCR_TCV_MASK)
#define RTC_TCR_CIC_MASK                         0xFF000000u
#define RTC_TCR_CIC_SHIFT                        24
#define RTC_TCR_CIC_WIDTH                        8
#define RTC_TCR_CIC(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_CIC_SHIFT))&RTC_TCR_CIC_MASK)
/* CR Bit Fields */
#define RTC_CR_SWR_MASK                          0x1u
#define RTC_CR_SWR_SHIFT                         0
#define RTC_CR_SWR_WIDTH                         1
#define RTC_CR_SWR(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_SWR_SHIFT))&RTC_CR_SWR_MASK)
#define RTC_CR_WPE_MASK                          0x2u
#define RTC_CR_WPE_SHIFT                         1
#define RTC_CR_WPE_WIDTH                         1
#define RTC_CR_WPE(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_WPE_SHIFT))&RTC_CR_WPE_MASK)
#define RTC_CR_SUP_MASK                          0x4u
#define RTC_CR_SUP_SHIFT                         2
#define RTC_CR_SUP_WIDTH                         1
#define RTC_CR_SUP(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_SUP_SHIFT))&RTC_CR_SUP_MASK)
#define RTC_CR_UM_MASK                           0x8u
#define RTC_CR_UM_SHIFT                          3
#define RTC_CR_UM_WIDTH                          1
#define RTC_CR_UM(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_CR_UM_SHIFT))&RTC_CR_UM_MASK)
#define RTC_CR_WPS_MASK                          0x10u
#define RTC_CR_WPS_SHIFT                         4
#define RTC_CR_WPS_WIDTH                         1
#define RTC_CR_WPS(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_WPS_SHIFT))&RTC_CR_WPS_MASK)
#define RTC_CR_CPS_MASK                          0x20u
#define RTC_CR_CPS_SHIFT                         5
#define RTC_CR_CPS_WIDTH                         1
#define RTC_CR_CPS(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_CPS_SHIFT))&RTC_CR_CPS_MASK)
#define RTC_CR_LPOS_MASK                         0x80u
#define RTC_CR_LPOS_SHIFT                        7
#define RTC_CR_LPOS_WIDTH                        1
#define RTC_CR_LPOS(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_LPOS_SHIFT))&RTC_CR_LPOS_MASK)
#define RTC_CR_OSCE_MASK                         0x100u
#define RTC_CR_OSCE_SHIFT                        8
#define RTC_CR_OSCE_WIDTH                        1
#define RTC_CR_OSCE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_OSCE_SHIFT))&RTC_CR_OSCE_MASK)
#define RTC_CR_CLKO_MASK                         0x200u
#define RTC_CR_CLKO_SHIFT                        9
#define RTC_CR_CLKO_WIDTH                        1
#define RTC_CR_CLKO(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_CLKO_SHIFT))&RTC_CR_CLKO_MASK)
#define RTC_CR_SC16P_MASK                        0x400u
#define RTC_CR_SC16P_SHIFT                       10
#define RTC_CR_SC16P_WIDTH                       1
#define RTC_CR_SC16P(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC16P_SHIFT))&RTC_CR_SC16P_MASK)
#define RTC_CR_SC8P_MASK                         0x800u
#define RTC_CR_SC8P_SHIFT                        11
#define RTC_CR_SC8P_WIDTH                        1
#define RTC_CR_SC8P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC8P_SHIFT))&RTC_CR_SC8P_MASK)
#define RTC_CR_SC4P_MASK                         0x1000u
#define RTC_CR_SC4P_SHIFT                        12
#define RTC_CR_SC4P_WIDTH                        1
#define RTC_CR_SC4P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC4P_SHIFT))&RTC_CR_SC4P_MASK)
#define RTC_CR_SC2P_MASK                         0x2000u
#define RTC_CR_SC2P_SHIFT                        13
#define RTC_CR_SC2P_WIDTH                        1
#define RTC_CR_SC2P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC2P_SHIFT))&RTC_CR_SC2P_MASK)
#define RTC_CR_CPE_MASK                          0x3000000u
#define RTC_CR_CPE_SHIFT                         24
#define RTC_CR_CPE_WIDTH                         2
#define RTC_CR_CPE(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_CPE_SHIFT))&RTC_CR_CPE_MASK)
/* SR Bit Fields */
#define RTC_SR_TIF_MASK                          0x1u
#define RTC_SR_TIF_SHIFT                         0
#define RTC_SR_TIF_WIDTH                         1
#define RTC_SR_TIF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TIF_SHIFT))&RTC_SR_TIF_MASK)
#define RTC_SR_TOF_MASK                          0x2u
#define RTC_SR_TOF_SHIFT                         1
#define RTC_SR_TOF_WIDTH                         1
#define RTC_SR_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TOF_SHIFT))&RTC_SR_TOF_MASK)
#define RTC_SR_TAF_MASK                          0x4u
#define RTC_SR_TAF_SHIFT                         2
#define RTC_SR_TAF_WIDTH                         1
#define RTC_SR_TAF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TAF_SHIFT))&RTC_SR_TAF_MASK)
#define RTC_SR_TCE_MASK                          0x10u
#define RTC_SR_TCE_SHIFT                         4
#define RTC_SR_TCE_WIDTH                         1
#define RTC_SR_TCE(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TCE_SHIFT))&RTC_SR_TCE_MASK)
/* LR Bit Fields */
#define RTC_LR_TCL_MASK                          0x8u
#define RTC_LR_TCL_SHIFT                         3
#define RTC_LR_TCL_WIDTH                         1
#define RTC_LR_TCL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_TCL_SHIFT))&RTC_LR_TCL_MASK)
#define RTC_LR_CRL_MASK                          0x10u
#define RTC_LR_CRL_SHIFT                         4
#define RTC_LR_CRL_WIDTH                         1
#define RTC_LR_CRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_CRL_SHIFT))&RTC_LR_CRL_MASK)
#define RTC_LR_SRL_MASK                          0x20u
#define RTC_LR_SRL_SHIFT                         5
#define RTC_LR_SRL_WIDTH                         1
#define RTC_LR_SRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_SRL_SHIFT))&RTC_LR_SRL_MASK)
#define RTC_LR_LRL_MASK                          0x40u
#define RTC_LR_LRL_SHIFT                         6
#define RTC_LR_LRL_WIDTH                         1
#define RTC_LR_LRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_LRL_SHIFT))&RTC_LR_LRL_MASK)
/* IER Bit Fields */
#define RTC_IER_TIIE_MASK                        0x1u
#define RTC_IER_TIIE_SHIFT                       0
#define RTC_IER_TIIE_WIDTH                       1
#define RTC_IER_TIIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TIIE_SHIFT))&RTC_IER_TIIE_MASK)
#define RTC_IER_TOIE_MASK                        0x2u
#define RTC_IER_TOIE_SHIFT                       1
#define RTC_IER_TOIE_WIDTH                       1
#define RTC_IER_TOIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TOIE_SHIFT))&RTC_IER_TOIE_MASK)
#define RTC_IER_TAIE_MASK                        0x4u
#define RTC_IER_TAIE_SHIFT                       2
#define RTC_IER_TAIE_WIDTH                       1
#define RTC_IER_TAIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TAIE_SHIFT))&RTC_IER_TAIE_MASK)
#define RTC_IER_TSIE_MASK                        0x10u
#define RTC_IER_TSIE_SHIFT                       4
#define RTC_IER_TSIE_WIDTH                       1
#define RTC_IER_TSIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TSIE_SHIFT))&RTC_IER_TSIE_MASK)
#define RTC_IER_WPON_MASK                        0x80u
#define RTC_IER_WPON_SHIFT                       7
#define RTC_IER_WPON_WIDTH                       1
#define RTC_IER_WPON(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_WPON_SHIFT))&RTC_IER_WPON_MASK)
#define RTC_IER_TSIC_MASK                        0x70000u
#define RTC_IER_TSIC_SHIFT                       16
#define RTC_IER_TSIC_WIDTH                       3
#define RTC_IER_TSIC(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TSIC_SHIFT))&RTC_IER_TSIC_MASK)

/*!
 * @}
 */ /* end of group RTC_Register_Masks */


/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define RTC_BASE                                 (0x40038000u)
/** Peripheral RTC base pointer */
#define RTC                                      ((RTC_Type *)RTC_BASE)
#define RTC_BASE_PTR                             (RTC)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC }

/* ----------------------------------------------------------------------------
   -- RTC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Accessor_Macros RTC - Register accessor macros
 * @{
 */


/* RTC - Register instance definitions */
/* RTC */
#define RTC_TSR                                  RTC_TSR_REG(RTC)
#define RTC_TPR                                  RTC_TPR_REG(RTC)
#define RTC_TAR                                  RTC_TAR_REG(RTC)
#define RTC_TCR                                  RTC_TCR_REG(RTC)
#define RTC_CR                                   RTC_CR_REG(RTC)
#define RTC_SR                                   RTC_SR_REG(RTC)
#define RTC_LR                                   RTC_LR_REG(RTC)
#define RTC_IER                                  RTC_IER_REG(RTC)

/*!
 * @}
 */ /* end of group RTC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group RTC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SCG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCG_Peripheral_Access_Layer SCG Peripheral Access Layer
 * @{
 */

/** SCG - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __I  uint32_t CSR;                               /**< Clock Status Register, offset: 0x10 */
  __IO uint32_t RCCR;                              /**< Run Clock Control Register, offset: 0x14 */
  __IO uint32_t VCCR;                              /**< VLPR Clock Control Register, offset: 0x18 */
  __IO uint32_t HCCR;                              /**< HSRUN Clock Control Register, offset: 0x1C */
  __IO uint32_t CLKOUTCNFG;                        /**< SCG CLKOUT Configuration Register, offset: 0x20 */
       uint8_t RESERVED_1[220];
  __IO uint32_t SOSCCSR;                           /**< System OSC Control Status Register, offset: 0x100 */
  __IO uint32_t SOSCDIV;                           /**< System OSC Divide Register, offset: 0x104 */
  __IO uint32_t SOSCCFG;                           /**< System Oscillator Configuration Register, offset: 0x108 */
       uint8_t RESERVED_2[244];
  __IO uint32_t SIRCCSR;                           /**< Slow IRC Control Status Register, offset: 0x200 */
  __IO uint32_t SIRCDIV;                           /**< Slow IRC Divide Register, offset: 0x204 */
  __IO uint32_t SIRCCFG;                           /**< Slow IRC Configuration Register, offset: 0x208 */
       uint8_t RESERVED_3[244];
  __IO uint32_t FIRCCSR;                           /**< Fast IRC Control Status Register, offset: 0x300 */
  __IO uint32_t FIRCDIV;                           /**< Fast IRC Divide Register, offset: 0x304 */
  __IO uint32_t FIRCCFG;                           /**< Fast IRC Configuration Register, offset: 0x308 */
  __IO uint32_t FIRCTCFG;                          /**< Fast IRC Trim Configuration Register, offset: 0x30C */
       uint8_t RESERVED_4[8];
  __IO uint32_t FIRCSTAT;                          /**< Fast IRC Status Register, offset: 0x318 */
       uint8_t RESERVED_5[740];
  __IO uint32_t SPLLCSR;                           /**< System PLL Control Status Register, offset: 0x600 */
  __IO uint32_t SPLLDIV;                           /**< System PLL Divide Register, offset: 0x604 */
  __IO uint32_t SPLLCFG;                           /**< System PLL Configuration Register, offset: 0x608 */
} SCG_Type, *SCG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SCG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCG_Register_Accessor_Macros SCG - Register accessor macros
 * @{
 */


/* SCG - Register accessors */
#define SCG_VERID_REG(base)                      ((base)->VERID)
#define SCG_PARAM_REG(base)                      ((base)->PARAM)
#define SCG_CSR_REG(base)                        ((base)->CSR)
#define SCG_RCCR_REG(base)                       ((base)->RCCR)
#define SCG_VCCR_REG(base)                       ((base)->VCCR)
#define SCG_HCCR_REG(base)                       ((base)->HCCR)
#define SCG_CLKOUTCNFG_REG(base)                 ((base)->CLKOUTCNFG)
#define SCG_SOSCCSR_REG(base)                    ((base)->SOSCCSR)
#define SCG_SOSCDIV_REG(base)                    ((base)->SOSCDIV)
#define SCG_SOSCCFG_REG(base)                    ((base)->SOSCCFG)
#define SCG_SIRCCSR_REG(base)                    ((base)->SIRCCSR)
#define SCG_SIRCDIV_REG(base)                    ((base)->SIRCDIV)
#define SCG_SIRCCFG_REG(base)                    ((base)->SIRCCFG)
#define SCG_FIRCCSR_REG(base)                    ((base)->FIRCCSR)
#define SCG_FIRCDIV_REG(base)                    ((base)->FIRCDIV)
#define SCG_FIRCCFG_REG(base)                    ((base)->FIRCCFG)
#define SCG_FIRCTCFG_REG(base)                   ((base)->FIRCTCFG)
#define SCG_FIRCSTAT_REG(base)                   ((base)->FIRCSTAT)
#define SCG_SPLLCSR_REG(base)                    ((base)->SPLLCSR)
#define SCG_SPLLDIV_REG(base)                    ((base)->SPLLDIV)
#define SCG_SPLLCFG_REG(base)                    ((base)->SPLLCFG)

/*!
 * @}
 */ /* end of group SCG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SCG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCG_Register_Masks SCG Register Masks
 * @{
 */

/* VERID Bit Fields */
#define SCG_VERID_VERSION_MASK                   0xFFFFFFFFu
#define SCG_VERID_VERSION_SHIFT                  0
#define SCG_VERID_VERSION_WIDTH                  32
#define SCG_VERID_VERSION(x)                     (((uint32_t)(((uint32_t)(x))<<SCG_VERID_VERSION_SHIFT))&SCG_VERID_VERSION_MASK)
/* PARAM Bit Fields */
#define SCG_PARAM_CLKPRES_MASK                   0xFFu
#define SCG_PARAM_CLKPRES_SHIFT                  0
#define SCG_PARAM_CLKPRES_WIDTH                  8
#define SCG_PARAM_CLKPRES(x)                     (((uint32_t)(((uint32_t)(x))<<SCG_PARAM_CLKPRES_SHIFT))&SCG_PARAM_CLKPRES_MASK)
#define SCG_PARAM_DIVPRES_MASK                   0xF8000000u
#define SCG_PARAM_DIVPRES_SHIFT                  27
#define SCG_PARAM_DIVPRES_WIDTH                  5
#define SCG_PARAM_DIVPRES(x)                     (((uint32_t)(((uint32_t)(x))<<SCG_PARAM_DIVPRES_SHIFT))&SCG_PARAM_DIVPRES_MASK)
/* CSR Bit Fields */
#define SCG_CSR_DIVSLOW_MASK                     0xFu
#define SCG_CSR_DIVSLOW_SHIFT                    0
#define SCG_CSR_DIVSLOW_WIDTH                    4
#define SCG_CSR_DIVSLOW(x)                       (((uint32_t)(((uint32_t)(x))<<SCG_CSR_DIVSLOW_SHIFT))&SCG_CSR_DIVSLOW_MASK)
#define SCG_CSR_DIVCORE_MASK                     0xF0000u
#define SCG_CSR_DIVCORE_SHIFT                    16
#define SCG_CSR_DIVCORE_WIDTH                    4
#define SCG_CSR_DIVCORE(x)                       (((uint32_t)(((uint32_t)(x))<<SCG_CSR_DIVCORE_SHIFT))&SCG_CSR_DIVCORE_MASK)
#define SCG_CSR_SCS_MASK                         0xF000000u
#define SCG_CSR_SCS_SHIFT                        24
#define SCG_CSR_SCS_WIDTH                        4
#define SCG_CSR_SCS(x)                           (((uint32_t)(((uint32_t)(x))<<SCG_CSR_SCS_SHIFT))&SCG_CSR_SCS_MASK)
/* RCCR Bit Fields */
#define SCG_RCCR_DIVSLOW_MASK                    0xFu
#define SCG_RCCR_DIVSLOW_SHIFT                   0
#define SCG_RCCR_DIVSLOW_WIDTH                   4
#define SCG_RCCR_DIVSLOW(x)                      (((uint32_t)(((uint32_t)(x))<<SCG_RCCR_DIVSLOW_SHIFT))&SCG_RCCR_DIVSLOW_MASK)
#define SCG_RCCR_DIVCORE_MASK                    0xF0000u
#define SCG_RCCR_DIVCORE_SHIFT                   16
#define SCG_RCCR_DIVCORE_WIDTH                   4
#define SCG_RCCR_DIVCORE(x)                      (((uint32_t)(((uint32_t)(x))<<SCG_RCCR_DIVCORE_SHIFT))&SCG_RCCR_DIVCORE_MASK)
#define SCG_RCCR_SCS_MASK                        0xF000000u
#define SCG_RCCR_SCS_SHIFT                       24
#define SCG_RCCR_SCS_WIDTH                       4
#define SCG_RCCR_SCS(x)                          (((uint32_t)(((uint32_t)(x))<<SCG_RCCR_SCS_SHIFT))&SCG_RCCR_SCS_MASK)
/* VCCR Bit Fields */
#define SCG_VCCR_DIVSLOW_MASK                    0xFu
#define SCG_VCCR_DIVSLOW_SHIFT                   0
#define SCG_VCCR_DIVSLOW_WIDTH                   4
#define SCG_VCCR_DIVSLOW(x)                      (((uint32_t)(((uint32_t)(x))<<SCG_VCCR_DIVSLOW_SHIFT))&SCG_VCCR_DIVSLOW_MASK)
#define SCG_VCCR_DIVCORE_MASK                    0xF0000u
#define SCG_VCCR_DIVCORE_SHIFT                   16
#define SCG_VCCR_DIVCORE_WIDTH                   4
#define SCG_VCCR_DIVCORE(x)                      (((uint32_t)(((uint32_t)(x))<<SCG_VCCR_DIVCORE_SHIFT))&SCG_VCCR_DIVCORE_MASK)
#define SCG_VCCR_SCS_MASK                        0xF000000u
#define SCG_VCCR_SCS_SHIFT                       24
#define SCG_VCCR_SCS_WIDTH                       4
#define SCG_VCCR_SCS(x)                          (((uint32_t)(((uint32_t)(x))<<SCG_VCCR_SCS_SHIFT))&SCG_VCCR_SCS_MASK)
/* HCCR Bit Fields */
#define SCG_HCCR_DIVSLOW_MASK                    0xFu
#define SCG_HCCR_DIVSLOW_SHIFT                   0
#define SCG_HCCR_DIVSLOW_WIDTH                   4
#define SCG_HCCR_DIVSLOW(x)                      (((uint32_t)(((uint32_t)(x))<<SCG_HCCR_DIVSLOW_SHIFT))&SCG_HCCR_DIVSLOW_MASK)
#define SCG_HCCR_DIVCORE_MASK                    0xF0000u
#define SCG_HCCR_DIVCORE_SHIFT                   16
#define SCG_HCCR_DIVCORE_WIDTH                   4
#define SCG_HCCR_DIVCORE(x)                      (((uint32_t)(((uint32_t)(x))<<SCG_HCCR_DIVCORE_SHIFT))&SCG_HCCR_DIVCORE_MASK)
#define SCG_HCCR_SCS_MASK                        0xF000000u
#define SCG_HCCR_SCS_SHIFT                       24
#define SCG_HCCR_SCS_WIDTH                       4
#define SCG_HCCR_SCS(x)                          (((uint32_t)(((uint32_t)(x))<<SCG_HCCR_SCS_SHIFT))&SCG_HCCR_SCS_MASK)
/* CLKOUTCNFG Bit Fields */
#define SCG_CLKOUTCNFG_CLKOUTSEL_MASK            0xF000000u
#define SCG_CLKOUTCNFG_CLKOUTSEL_SHIFT           24
#define SCG_CLKOUTCNFG_CLKOUTSEL_WIDTH           4
#define SCG_CLKOUTCNFG_CLKOUTSEL(x)              (((uint32_t)(((uint32_t)(x))<<SCG_CLKOUTCNFG_CLKOUTSEL_SHIFT))&SCG_CLKOUTCNFG_CLKOUTSEL_MASK)
/* SOSCCSR Bit Fields */
#define SCG_SOSCCSR_SOSCEN_MASK                  0x1u
#define SCG_SOSCCSR_SOSCEN_SHIFT                 0
#define SCG_SOSCCSR_SOSCEN_WIDTH                 1
#define SCG_SOSCCSR_SOSCEN(x)                    (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCSR_SOSCEN_SHIFT))&SCG_SOSCCSR_SOSCEN_MASK)
#define SCG_SOSCCSR_SOSCSTEN_MASK                0x2u
#define SCG_SOSCCSR_SOSCSTEN_SHIFT               1
#define SCG_SOSCCSR_SOSCSTEN_WIDTH               1
#define SCG_SOSCCSR_SOSCSTEN(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCSR_SOSCSTEN_SHIFT))&SCG_SOSCCSR_SOSCSTEN_MASK)
#define SCG_SOSCCSR_SOSCLPEN_MASK                0x4u
#define SCG_SOSCCSR_SOSCLPEN_SHIFT               2
#define SCG_SOSCCSR_SOSCLPEN_WIDTH               1
#define SCG_SOSCCSR_SOSCLPEN(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCSR_SOSCLPEN_SHIFT))&SCG_SOSCCSR_SOSCLPEN_MASK)
#define SCG_SOSCCSR_SOSCERCLKEN_MASK             0x8u
#define SCG_SOSCCSR_SOSCERCLKEN_SHIFT            3
#define SCG_SOSCCSR_SOSCERCLKEN_WIDTH            1
#define SCG_SOSCCSR_SOSCERCLKEN(x)               (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCSR_SOSCERCLKEN_SHIFT))&SCG_SOSCCSR_SOSCERCLKEN_MASK)
#define SCG_SOSCCSR_SOSCCM_MASK                  0x10000u
#define SCG_SOSCCSR_SOSCCM_SHIFT                 16
#define SCG_SOSCCSR_SOSCCM_WIDTH                 1
#define SCG_SOSCCSR_SOSCCM(x)                    (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCSR_SOSCCM_SHIFT))&SCG_SOSCCSR_SOSCCM_MASK)
#define SCG_SOSCCSR_SOSCCMRE_MASK                0x20000u
#define SCG_SOSCCSR_SOSCCMRE_SHIFT               17
#define SCG_SOSCCSR_SOSCCMRE_WIDTH               1
#define SCG_SOSCCSR_SOSCCMRE(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCSR_SOSCCMRE_SHIFT))&SCG_SOSCCSR_SOSCCMRE_MASK)
#define SCG_SOSCCSR_LK_MASK                      0x800000u
#define SCG_SOSCCSR_LK_SHIFT                     23
#define SCG_SOSCCSR_LK_WIDTH                     1
#define SCG_SOSCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCSR_LK_SHIFT))&SCG_SOSCCSR_LK_MASK)
#define SCG_SOSCCSR_SOSCVLD_MASK                 0x1000000u
#define SCG_SOSCCSR_SOSCVLD_SHIFT                24
#define SCG_SOSCCSR_SOSCVLD_WIDTH                1
#define SCG_SOSCCSR_SOSCVLD(x)                   (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCSR_SOSCVLD_SHIFT))&SCG_SOSCCSR_SOSCVLD_MASK)
#define SCG_SOSCCSR_SOSCSEL_MASK                 0x2000000u
#define SCG_SOSCCSR_SOSCSEL_SHIFT                25
#define SCG_SOSCCSR_SOSCSEL_WIDTH                1
#define SCG_SOSCCSR_SOSCSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCSR_SOSCSEL_SHIFT))&SCG_SOSCCSR_SOSCSEL_MASK)
#define SCG_SOSCCSR_SOSCERR_MASK                 0x4000000u
#define SCG_SOSCCSR_SOSCERR_SHIFT                26
#define SCG_SOSCCSR_SOSCERR_WIDTH                1
#define SCG_SOSCCSR_SOSCERR(x)                   (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCSR_SOSCERR_SHIFT))&SCG_SOSCCSR_SOSCERR_MASK)
/* SOSCDIV Bit Fields */
#define SCG_SOSCDIV_SOSCDIV1_MASK                0x7u
#define SCG_SOSCDIV_SOSCDIV1_SHIFT               0
#define SCG_SOSCDIV_SOSCDIV1_WIDTH               3
#define SCG_SOSCDIV_SOSCDIV1(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SOSCDIV_SOSCDIV1_SHIFT))&SCG_SOSCDIV_SOSCDIV1_MASK)
#define SCG_SOSCDIV_SOSCDIV2_MASK                0x700u
#define SCG_SOSCDIV_SOSCDIV2_SHIFT               8
#define SCG_SOSCDIV_SOSCDIV2_WIDTH               3
#define SCG_SOSCDIV_SOSCDIV2(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SOSCDIV_SOSCDIV2_SHIFT))&SCG_SOSCDIV_SOSCDIV2_MASK)
#define SCG_SOSCDIV_SOSCDIV3_MASK                0x70000u
#define SCG_SOSCDIV_SOSCDIV3_SHIFT               16
#define SCG_SOSCDIV_SOSCDIV3_WIDTH               3
#define SCG_SOSCDIV_SOSCDIV3(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SOSCDIV_SOSCDIV3_SHIFT))&SCG_SOSCDIV_SOSCDIV3_MASK)
/* SOSCCFG Bit Fields */
#define SCG_SOSCCFG_EREFS_MASK                   0x4u
#define SCG_SOSCCFG_EREFS_SHIFT                  2
#define SCG_SOSCCFG_EREFS_WIDTH                  1
#define SCG_SOSCCFG_EREFS(x)                     (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCFG_EREFS_SHIFT))&SCG_SOSCCFG_EREFS_MASK)
#define SCG_SOSCCFG_HGO_MASK                     0x8u
#define SCG_SOSCCFG_HGO_SHIFT                    3
#define SCG_SOSCCFG_HGO_WIDTH                    1
#define SCG_SOSCCFG_HGO(x)                       (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCFG_HGO_SHIFT))&SCG_SOSCCFG_HGO_MASK)
#define SCG_SOSCCFG_RANGE_MASK                   0x30u
#define SCG_SOSCCFG_RANGE_SHIFT                  4
#define SCG_SOSCCFG_RANGE_WIDTH                  2
#define SCG_SOSCCFG_RANGE(x)                     (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCFG_RANGE_SHIFT))&SCG_SOSCCFG_RANGE_MASK)
#define SCG_SOSCCFG_SC16P_MASK                   0x100u
#define SCG_SOSCCFG_SC16P_SHIFT                  8
#define SCG_SOSCCFG_SC16P_WIDTH                  1
#define SCG_SOSCCFG_SC16P(x)                     (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCFG_SC16P_SHIFT))&SCG_SOSCCFG_SC16P_MASK)
#define SCG_SOSCCFG_SC8P_MASK                    0x200u
#define SCG_SOSCCFG_SC8P_SHIFT                   9
#define SCG_SOSCCFG_SC8P_WIDTH                   1
#define SCG_SOSCCFG_SC8P(x)                      (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCFG_SC8P_SHIFT))&SCG_SOSCCFG_SC8P_MASK)
#define SCG_SOSCCFG_SC4P_MASK                    0x400u
#define SCG_SOSCCFG_SC4P_SHIFT                   10
#define SCG_SOSCCFG_SC4P_WIDTH                   1
#define SCG_SOSCCFG_SC4P(x)                      (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCFG_SC4P_SHIFT))&SCG_SOSCCFG_SC4P_MASK)
#define SCG_SOSCCFG_SC2P_MASK                    0x800u
#define SCG_SOSCCFG_SC2P_SHIFT                   11
#define SCG_SOSCCFG_SC2P_WIDTH                   1
#define SCG_SOSCCFG_SC2P(x)                      (((uint32_t)(((uint32_t)(x))<<SCG_SOSCCFG_SC2P_SHIFT))&SCG_SOSCCFG_SC2P_MASK)
/* SIRCCSR Bit Fields */
#define SCG_SIRCCSR_SIRCEN_MASK                  0x1u
#define SCG_SIRCCSR_SIRCEN_SHIFT                 0
#define SCG_SIRCCSR_SIRCEN_WIDTH                 1
#define SCG_SIRCCSR_SIRCEN(x)                    (((uint32_t)(((uint32_t)(x))<<SCG_SIRCCSR_SIRCEN_SHIFT))&SCG_SIRCCSR_SIRCEN_MASK)
#define SCG_SIRCCSR_SIRCSTEN_MASK                0x2u
#define SCG_SIRCCSR_SIRCSTEN_SHIFT               1
#define SCG_SIRCCSR_SIRCSTEN_WIDTH               1
#define SCG_SIRCCSR_SIRCSTEN(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SIRCCSR_SIRCSTEN_SHIFT))&SCG_SIRCCSR_SIRCSTEN_MASK)
#define SCG_SIRCCSR_SIRCLPEN_MASK                0x4u
#define SCG_SIRCCSR_SIRCLPEN_SHIFT               2
#define SCG_SIRCCSR_SIRCLPEN_WIDTH               1
#define SCG_SIRCCSR_SIRCLPEN(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SIRCCSR_SIRCLPEN_SHIFT))&SCG_SIRCCSR_SIRCLPEN_MASK)
#define SCG_SIRCCSR_LK_MASK                      0x800000u
#define SCG_SIRCCSR_LK_SHIFT                     23
#define SCG_SIRCCSR_LK_WIDTH                     1
#define SCG_SIRCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x))<<SCG_SIRCCSR_LK_SHIFT))&SCG_SIRCCSR_LK_MASK)
#define SCG_SIRCCSR_SIRCVLD_MASK                 0x1000000u
#define SCG_SIRCCSR_SIRCVLD_SHIFT                24
#define SCG_SIRCCSR_SIRCVLD_WIDTH                1
#define SCG_SIRCCSR_SIRCVLD(x)                   (((uint32_t)(((uint32_t)(x))<<SCG_SIRCCSR_SIRCVLD_SHIFT))&SCG_SIRCCSR_SIRCVLD_MASK)
#define SCG_SIRCCSR_SIRCSEL_MASK                 0x2000000u
#define SCG_SIRCCSR_SIRCSEL_SHIFT                25
#define SCG_SIRCCSR_SIRCSEL_WIDTH                1
#define SCG_SIRCCSR_SIRCSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SCG_SIRCCSR_SIRCSEL_SHIFT))&SCG_SIRCCSR_SIRCSEL_MASK)
/* SIRCDIV Bit Fields */
#define SCG_SIRCDIV_SIRCDIV1_MASK                0x7u
#define SCG_SIRCDIV_SIRCDIV1_SHIFT               0
#define SCG_SIRCDIV_SIRCDIV1_WIDTH               3
#define SCG_SIRCDIV_SIRCDIV1(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SIRCDIV_SIRCDIV1_SHIFT))&SCG_SIRCDIV_SIRCDIV1_MASK)
#define SCG_SIRCDIV_SIRCDIV2_MASK                0x700u
#define SCG_SIRCDIV_SIRCDIV2_SHIFT               8
#define SCG_SIRCDIV_SIRCDIV2_WIDTH               3
#define SCG_SIRCDIV_SIRCDIV2(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SIRCDIV_SIRCDIV2_SHIFT))&SCG_SIRCDIV_SIRCDIV2_MASK)
#define SCG_SIRCDIV_SIRCDIV3_MASK                0x70000u
#define SCG_SIRCDIV_SIRCDIV3_SHIFT               16
#define SCG_SIRCDIV_SIRCDIV3_WIDTH               3
#define SCG_SIRCDIV_SIRCDIV3(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SIRCDIV_SIRCDIV3_SHIFT))&SCG_SIRCDIV_SIRCDIV3_MASK)
/* SIRCCFG Bit Fields */
#define SCG_SIRCCFG_RANGE_MASK                   0x1u
#define SCG_SIRCCFG_RANGE_SHIFT                  0
#define SCG_SIRCCFG_RANGE_WIDTH                  1
#define SCG_SIRCCFG_RANGE(x)                     (((uint32_t)(((uint32_t)(x))<<SCG_SIRCCFG_RANGE_SHIFT))&SCG_SIRCCFG_RANGE_MASK)
/* FIRCCSR Bit Fields */
#define SCG_FIRCCSR_FIRCEN_MASK                  0x1u
#define SCG_FIRCCSR_FIRCEN_SHIFT                 0
#define SCG_FIRCCSR_FIRCEN_WIDTH                 1
#define SCG_FIRCCSR_FIRCEN(x)                    (((uint32_t)(((uint32_t)(x))<<SCG_FIRCCSR_FIRCEN_SHIFT))&SCG_FIRCCSR_FIRCEN_MASK)
#define SCG_FIRCCSR_FIRCSTEN_MASK                0x2u
#define SCG_FIRCCSR_FIRCSTEN_SHIFT               1
#define SCG_FIRCCSR_FIRCSTEN_WIDTH               1
#define SCG_FIRCCSR_FIRCSTEN(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_FIRCCSR_FIRCSTEN_SHIFT))&SCG_FIRCCSR_FIRCSTEN_MASK)
#define SCG_FIRCCSR_FIRCREGOFF_MASK              0x4u
#define SCG_FIRCCSR_FIRCREGOFF_SHIFT             2
#define SCG_FIRCCSR_FIRCREGOFF_WIDTH             1
#define SCG_FIRCCSR_FIRCREGOFF(x)                (((uint32_t)(((uint32_t)(x))<<SCG_FIRCCSR_FIRCREGOFF_SHIFT))&SCG_FIRCCSR_FIRCREGOFF_MASK)
#define SCG_FIRCCSR_FIRCLPEN_MASK                0x8u
#define SCG_FIRCCSR_FIRCLPEN_SHIFT               3
#define SCG_FIRCCSR_FIRCLPEN_WIDTH               1
#define SCG_FIRCCSR_FIRCLPEN(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_FIRCCSR_FIRCLPEN_SHIFT))&SCG_FIRCCSR_FIRCLPEN_MASK)
#define SCG_FIRCCSR_FIRCTREN_MASK                0x100u
#define SCG_FIRCCSR_FIRCTREN_SHIFT               8
#define SCG_FIRCCSR_FIRCTREN_WIDTH               1
#define SCG_FIRCCSR_FIRCTREN(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_FIRCCSR_FIRCTREN_SHIFT))&SCG_FIRCCSR_FIRCTREN_MASK)
#define SCG_FIRCCSR_FIRCTRUP_MASK                0x200u
#define SCG_FIRCCSR_FIRCTRUP_SHIFT               9
#define SCG_FIRCCSR_FIRCTRUP_WIDTH               1
#define SCG_FIRCCSR_FIRCTRUP(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_FIRCCSR_FIRCTRUP_SHIFT))&SCG_FIRCCSR_FIRCTRUP_MASK)
#define SCG_FIRCCSR_LK_MASK                      0x800000u
#define SCG_FIRCCSR_LK_SHIFT                     23
#define SCG_FIRCCSR_LK_WIDTH                     1
#define SCG_FIRCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x))<<SCG_FIRCCSR_LK_SHIFT))&SCG_FIRCCSR_LK_MASK)
#define SCG_FIRCCSR_FIRCVLD_MASK                 0x1000000u
#define SCG_FIRCCSR_FIRCVLD_SHIFT                24
#define SCG_FIRCCSR_FIRCVLD_WIDTH                1
#define SCG_FIRCCSR_FIRCVLD(x)                   (((uint32_t)(((uint32_t)(x))<<SCG_FIRCCSR_FIRCVLD_SHIFT))&SCG_FIRCCSR_FIRCVLD_MASK)
#define SCG_FIRCCSR_FIRCSEL_MASK                 0x2000000u
#define SCG_FIRCCSR_FIRCSEL_SHIFT                25
#define SCG_FIRCCSR_FIRCSEL_WIDTH                1
#define SCG_FIRCCSR_FIRCSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SCG_FIRCCSR_FIRCSEL_SHIFT))&SCG_FIRCCSR_FIRCSEL_MASK)
#define SCG_FIRCCSR_FIRCERR_MASK                 0x4000000u
#define SCG_FIRCCSR_FIRCERR_SHIFT                26
#define SCG_FIRCCSR_FIRCERR_WIDTH                1
#define SCG_FIRCCSR_FIRCERR(x)                   (((uint32_t)(((uint32_t)(x))<<SCG_FIRCCSR_FIRCERR_SHIFT))&SCG_FIRCCSR_FIRCERR_MASK)
/* FIRCDIV Bit Fields */
#define SCG_FIRCDIV_FIRCDIV1_MASK                0x7u
#define SCG_FIRCDIV_FIRCDIV1_SHIFT               0
#define SCG_FIRCDIV_FIRCDIV1_WIDTH               3
#define SCG_FIRCDIV_FIRCDIV1(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_FIRCDIV_FIRCDIV1_SHIFT))&SCG_FIRCDIV_FIRCDIV1_MASK)
#define SCG_FIRCDIV_FIRCDIV2_MASK                0x700u
#define SCG_FIRCDIV_FIRCDIV2_SHIFT               8
#define SCG_FIRCDIV_FIRCDIV2_WIDTH               3
#define SCG_FIRCDIV_FIRCDIV2(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_FIRCDIV_FIRCDIV2_SHIFT))&SCG_FIRCDIV_FIRCDIV2_MASK)
#define SCG_FIRCDIV_FIRCDIV3_MASK                0x70000u
#define SCG_FIRCDIV_FIRCDIV3_SHIFT               16
#define SCG_FIRCDIV_FIRCDIV3_WIDTH               3
#define SCG_FIRCDIV_FIRCDIV3(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_FIRCDIV_FIRCDIV3_SHIFT))&SCG_FIRCDIV_FIRCDIV3_MASK)
/* FIRCCFG Bit Fields */
#define SCG_FIRCCFG_RANGE_MASK                   0x3u
#define SCG_FIRCCFG_RANGE_SHIFT                  0
#define SCG_FIRCCFG_RANGE_WIDTH                  2
#define SCG_FIRCCFG_RANGE(x)                     (((uint32_t)(((uint32_t)(x))<<SCG_FIRCCFG_RANGE_SHIFT))&SCG_FIRCCFG_RANGE_MASK)
/* FIRCTCFG Bit Fields */
#define SCG_FIRCTCFG_TRIMSRC_MASK                0x3u
#define SCG_FIRCTCFG_TRIMSRC_SHIFT               0
#define SCG_FIRCTCFG_TRIMSRC_WIDTH               2
#define SCG_FIRCTCFG_TRIMSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_FIRCTCFG_TRIMSRC_SHIFT))&SCG_FIRCTCFG_TRIMSRC_MASK)
#define SCG_FIRCTCFG_TRIMDIV_MASK                0x700u
#define SCG_FIRCTCFG_TRIMDIV_SHIFT               8
#define SCG_FIRCTCFG_TRIMDIV_WIDTH               3
#define SCG_FIRCTCFG_TRIMDIV(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_FIRCTCFG_TRIMDIV_SHIFT))&SCG_FIRCTCFG_TRIMDIV_MASK)
/* FIRCSTAT Bit Fields */
#define SCG_FIRCSTAT_TRIMFINE_MASK               0x7Fu
#define SCG_FIRCSTAT_TRIMFINE_SHIFT              0
#define SCG_FIRCSTAT_TRIMFINE_WIDTH              7
#define SCG_FIRCSTAT_TRIMFINE(x)                 (((uint32_t)(((uint32_t)(x))<<SCG_FIRCSTAT_TRIMFINE_SHIFT))&SCG_FIRCSTAT_TRIMFINE_MASK)
#define SCG_FIRCSTAT_TRIMCOAR_MASK               0xFF00u
#define SCG_FIRCSTAT_TRIMCOAR_SHIFT              8
#define SCG_FIRCSTAT_TRIMCOAR_WIDTH              8
#define SCG_FIRCSTAT_TRIMCOAR(x)                 (((uint32_t)(((uint32_t)(x))<<SCG_FIRCSTAT_TRIMCOAR_SHIFT))&SCG_FIRCSTAT_TRIMCOAR_MASK)
/* SPLLCSR Bit Fields */
#define SCG_SPLLCSR_SPLLEN_MASK                  0x1u
#define SCG_SPLLCSR_SPLLEN_SHIFT                 0
#define SCG_SPLLCSR_SPLLEN_WIDTH                 1
#define SCG_SPLLCSR_SPLLEN(x)                    (((uint32_t)(((uint32_t)(x))<<SCG_SPLLCSR_SPLLEN_SHIFT))&SCG_SPLLCSR_SPLLEN_MASK)
#define SCG_SPLLCSR_SPLLSTEN_MASK                0x2u
#define SCG_SPLLCSR_SPLLSTEN_SHIFT               1
#define SCG_SPLLCSR_SPLLSTEN_WIDTH               1
#define SCG_SPLLCSR_SPLLSTEN(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SPLLCSR_SPLLSTEN_SHIFT))&SCG_SPLLCSR_SPLLSTEN_MASK)
#define SCG_SPLLCSR_SPLLCM_MASK                  0x10000u
#define SCG_SPLLCSR_SPLLCM_SHIFT                 16
#define SCG_SPLLCSR_SPLLCM_WIDTH                 1
#define SCG_SPLLCSR_SPLLCM(x)                    (((uint32_t)(((uint32_t)(x))<<SCG_SPLLCSR_SPLLCM_SHIFT))&SCG_SPLLCSR_SPLLCM_MASK)
#define SCG_SPLLCSR_SPLLCMRE_MASK                0x20000u
#define SCG_SPLLCSR_SPLLCMRE_SHIFT               17
#define SCG_SPLLCSR_SPLLCMRE_WIDTH               1
#define SCG_SPLLCSR_SPLLCMRE(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SPLLCSR_SPLLCMRE_SHIFT))&SCG_SPLLCSR_SPLLCMRE_MASK)
#define SCG_SPLLCSR_LK_MASK                      0x800000u
#define SCG_SPLLCSR_LK_SHIFT                     23
#define SCG_SPLLCSR_LK_WIDTH                     1
#define SCG_SPLLCSR_LK(x)                        (((uint32_t)(((uint32_t)(x))<<SCG_SPLLCSR_LK_SHIFT))&SCG_SPLLCSR_LK_MASK)
#define SCG_SPLLCSR_SPLLVLD_MASK                 0x1000000u
#define SCG_SPLLCSR_SPLLVLD_SHIFT                24
#define SCG_SPLLCSR_SPLLVLD_WIDTH                1
#define SCG_SPLLCSR_SPLLVLD(x)                   (((uint32_t)(((uint32_t)(x))<<SCG_SPLLCSR_SPLLVLD_SHIFT))&SCG_SPLLCSR_SPLLVLD_MASK)
#define SCG_SPLLCSR_SPLLSEL_MASK                 0x2000000u
#define SCG_SPLLCSR_SPLLSEL_SHIFT                25
#define SCG_SPLLCSR_SPLLSEL_WIDTH                1
#define SCG_SPLLCSR_SPLLSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SCG_SPLLCSR_SPLLSEL_SHIFT))&SCG_SPLLCSR_SPLLSEL_MASK)
#define SCG_SPLLCSR_SPLLERR_MASK                 0x4000000u
#define SCG_SPLLCSR_SPLLERR_SHIFT                26
#define SCG_SPLLCSR_SPLLERR_WIDTH                1
#define SCG_SPLLCSR_SPLLERR(x)                   (((uint32_t)(((uint32_t)(x))<<SCG_SPLLCSR_SPLLERR_SHIFT))&SCG_SPLLCSR_SPLLERR_MASK)
/* SPLLDIV Bit Fields */
#define SCG_SPLLDIV_SPLLDIV1_MASK                0x7u
#define SCG_SPLLDIV_SPLLDIV1_SHIFT               0
#define SCG_SPLLDIV_SPLLDIV1_WIDTH               3
#define SCG_SPLLDIV_SPLLDIV1(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SPLLDIV_SPLLDIV1_SHIFT))&SCG_SPLLDIV_SPLLDIV1_MASK)
#define SCG_SPLLDIV_SPLLDIV2_MASK                0x700u
#define SCG_SPLLDIV_SPLLDIV2_SHIFT               8
#define SCG_SPLLDIV_SPLLDIV2_WIDTH               3
#define SCG_SPLLDIV_SPLLDIV2(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SPLLDIV_SPLLDIV2_SHIFT))&SCG_SPLLDIV_SPLLDIV2_MASK)
#define SCG_SPLLDIV_SPLLDIV3_MASK                0x70000u
#define SCG_SPLLDIV_SPLLDIV3_SHIFT               16
#define SCG_SPLLDIV_SPLLDIV3_WIDTH               3
#define SCG_SPLLDIV_SPLLDIV3(x)                  (((uint32_t)(((uint32_t)(x))<<SCG_SPLLDIV_SPLLDIV3_SHIFT))&SCG_SPLLDIV_SPLLDIV3_MASK)
/* SPLLCFG Bit Fields */
#define SCG_SPLLCFG_SOURCE_MASK                  0x1u
#define SCG_SPLLCFG_SOURCE_SHIFT                 0
#define SCG_SPLLCFG_SOURCE_WIDTH                 1
#define SCG_SPLLCFG_SOURCE(x)                    (((uint32_t)(((uint32_t)(x))<<SCG_SPLLCFG_SOURCE_SHIFT))&SCG_SPLLCFG_SOURCE_MASK)
#define SCG_SPLLCFG_PREDIV_MASK                  0x700u
#define SCG_SPLLCFG_PREDIV_SHIFT                 8
#define SCG_SPLLCFG_PREDIV_WIDTH                 3
#define SCG_SPLLCFG_PREDIV(x)                    (((uint32_t)(((uint32_t)(x))<<SCG_SPLLCFG_PREDIV_SHIFT))&SCG_SPLLCFG_PREDIV_MASK)
#define SCG_SPLLCFG_MULT_MASK                    0x1F0000u
#define SCG_SPLLCFG_MULT_SHIFT                   16
#define SCG_SPLLCFG_MULT_WIDTH                   5
#define SCG_SPLLCFG_MULT(x)                      (((uint32_t)(((uint32_t)(x))<<SCG_SPLLCFG_MULT_SHIFT))&SCG_SPLLCFG_MULT_MASK)

/*!
 * @}
 */ /* end of group SCG_Register_Masks */


/* SCG - Peripheral instance base addresses */
/** Peripheral SCG base address */
#define SCG_BASE                                 (0x4007B000u)
/** Peripheral SCG base pointer */
#define SCG                                      ((SCG_Type *)SCG_BASE)
#define SCG_BASE_PTR                             (SCG)
/** Array initializer of SCG peripheral base addresses */
#define SCG_BASE_ADDRS                           { SCG_BASE }
/** Array initializer of SCG peripheral base pointers */
#define SCG_BASE_PTRS                            { SCG }

/* ----------------------------------------------------------------------------
   -- SCG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCG_Register_Accessor_Macros SCG - Register accessor macros
 * @{
 */


/* SCG - Register instance definitions */
/* SCG */
#define SCG_VERID                                SCG_VERID_REG(SCG)
#define SCG_PARAM                                SCG_PARAM_REG(SCG)
#define SCG_CSR                                  SCG_CSR_REG(SCG)
#define SCG_RCCR                                 SCG_RCCR_REG(SCG)
#define SCG_VCCR                                 SCG_VCCR_REG(SCG)
#define SCG_HCCR                                 SCG_HCCR_REG(SCG)
#define SCG_CLKOUTCNFG                           SCG_CLKOUTCNFG_REG(SCG)
#define SCG_SOSCCSR                              SCG_SOSCCSR_REG(SCG)
#define SCG_SOSCDIV                              SCG_SOSCDIV_REG(SCG)
#define SCG_SOSCCFG                              SCG_SOSCCFG_REG(SCG)
#define SCG_SIRCCSR                              SCG_SIRCCSR_REG(SCG)
#define SCG_SIRCDIV                              SCG_SIRCDIV_REG(SCG)
#define SCG_SIRCCFG                              SCG_SIRCCFG_REG(SCG)
#define SCG_FIRCCSR                              SCG_FIRCCSR_REG(SCG)
#define SCG_FIRCDIV                              SCG_FIRCDIV_REG(SCG)
#define SCG_FIRCCFG                              SCG_FIRCCFG_REG(SCG)
#define SCG_FIRCTCFG                             SCG_FIRCTCFG_REG(SCG)
#define SCG_FIRCSTAT                             SCG_FIRCSTAT_REG(SCG)
#define SCG_SPLLCSR                              SCG_SPLLCSR_REG(SCG)
#define SCG_SPLLDIV                              SCG_SPLLDIV_REG(SCG)
#define SCG_SPLLCFG                              SCG_SPLLCFG_REG(SCG)

/*!
 * @}
 */ /* end of group SCG_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group SCG_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */

/** SIM - Register Layout Typedef */
typedef struct {
  __IO uint32_t SOPT1;                             /**< System Options Register 1, offset: 0x0 */
  __IO uint32_t SOPT1CFG;                          /**< SOPT1 Configuration Register, offset: 0x4 */
       uint8_t RESERVED_0[4124];
  __I  uint32_t SDID;                              /**< System Device Identification Register, offset: 0x1024 */
       uint8_t RESERVED_1[36];
  __IO uint32_t FCFG1;                             /**< Flash Configuration Register 1, offset: 0x104C */
  __I  uint32_t FCFG2;                             /**< Flash Configuration Register 2, offset: 0x1050 */
       uint8_t RESERVED_2[4];
  __I  uint32_t UIDMH;                             /**< Unique Identification Register Mid-High, offset: 0x1058 */
  __I  uint32_t UIDML;                             /**< Unique Identification Register Mid Low, offset: 0x105C */
  __I  uint32_t UIDL;                              /**< Unique Identification Register Low, offset: 0x1060 */
} SIM_Type, *SIM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros
 * @{
 */


/* SIM - Register accessors */
#define SIM_SOPT1_REG(base)                      ((base)->SOPT1)
#define SIM_SOPT1CFG_REG(base)                   ((base)->SOPT1CFG)
#define SIM_SDID_REG(base)                       ((base)->SDID)
#define SIM_FCFG1_REG(base)                      ((base)->FCFG1)
#define SIM_FCFG2_REG(base)                      ((base)->FCFG2)
#define SIM_UIDMH_REG(base)                      ((base)->UIDMH)
#define SIM_UIDML_REG(base)                      ((base)->UIDML)
#define SIM_UIDL_REG(base)                       ((base)->UIDL)

/*!
 * @}
 */ /* end of group SIM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/* SOPT1 Bit Fields */
#define SIM_SOPT1_USBVSTBY_MASK                  0x20000000u
#define SIM_SOPT1_USBVSTBY_SHIFT                 29
#define SIM_SOPT1_USBVSTBY_WIDTH                 1
#define SIM_SOPT1_USBVSTBY(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_USBVSTBY_SHIFT))&SIM_SOPT1_USBVSTBY_MASK)
#define SIM_SOPT1_USBSSTBY_MASK                  0x40000000u
#define SIM_SOPT1_USBSSTBY_SHIFT                 30
#define SIM_SOPT1_USBSSTBY_WIDTH                 1
#define SIM_SOPT1_USBSSTBY(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_USBSSTBY_SHIFT))&SIM_SOPT1_USBSSTBY_MASK)
#define SIM_SOPT1_USBREGEN_MASK                  0x80000000u
#define SIM_SOPT1_USBREGEN_SHIFT                 31
#define SIM_SOPT1_USBREGEN_WIDTH                 1
#define SIM_SOPT1_USBREGEN(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_USBREGEN_SHIFT))&SIM_SOPT1_USBREGEN_MASK)
/* SOPT1CFG Bit Fields */
#define SIM_SOPT1CFG_URWE_MASK                   0x1000000u
#define SIM_SOPT1CFG_URWE_SHIFT                  24
#define SIM_SOPT1CFG_URWE_WIDTH                  1
#define SIM_SOPT1CFG_URWE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1CFG_URWE_SHIFT))&SIM_SOPT1CFG_URWE_MASK)
#define SIM_SOPT1CFG_UVSWE_MASK                  0x2000000u
#define SIM_SOPT1CFG_UVSWE_SHIFT                 25
#define SIM_SOPT1CFG_UVSWE_WIDTH                 1
#define SIM_SOPT1CFG_UVSWE(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1CFG_UVSWE_SHIFT))&SIM_SOPT1CFG_UVSWE_MASK)
#define SIM_SOPT1CFG_USSWE_MASK                  0x4000000u
#define SIM_SOPT1CFG_USSWE_SHIFT                 26
#define SIM_SOPT1CFG_USSWE_WIDTH                 1
#define SIM_SOPT1CFG_USSWE(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1CFG_USSWE_SHIFT))&SIM_SOPT1CFG_USSWE_MASK)
/* SDID Bit Fields */
#define SIM_SDID_PINID_MASK                      0xFu
#define SIM_SDID_PINID_SHIFT                     0
#define SIM_SDID_PINID_WIDTH                     4
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_PINID_SHIFT))&SIM_SDID_PINID_MASK)
#define SIM_SDID_KEYATT_MASK                     0x70u
#define SIM_SDID_KEYATT_SHIFT                    4
#define SIM_SDID_KEYATT_WIDTH                    3
#define SIM_SDID_KEYATT(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SDID_KEYATT_SHIFT))&SIM_SDID_KEYATT_MASK)
#define SIM_SDID_DIEID_MASK                      0xF80u
#define SIM_SDID_DIEID_SHIFT                     7
#define SIM_SDID_DIEID_WIDTH                     5
#define SIM_SDID_DIEID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_DIEID_SHIFT))&SIM_SDID_DIEID_MASK)
#define SIM_SDID_REVID_MASK                      0xF000u
#define SIM_SDID_REVID_SHIFT                     12
#define SIM_SDID_REVID_WIDTH                     4
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_REVID_SHIFT))&SIM_SDID_REVID_MASK)
#define SIM_SDID_SRAMSIZE_MASK                   0xF0000u
#define SIM_SDID_SRAMSIZE_SHIFT                  16
#define SIM_SDID_SRAMSIZE_WIDTH                  4
#define SIM_SDID_SRAMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SRAMSIZE_SHIFT))&SIM_SDID_SRAMSIZE_MASK)
#define SIM_SDID_SERIESID_MASK                   0xF00000u
#define SIM_SDID_SERIESID_SHIFT                  20
#define SIM_SDID_SERIESID_WIDTH                  4
#define SIM_SDID_SERIESID(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SERIESID_SHIFT))&SIM_SDID_SERIESID_MASK)
#define SIM_SDID_SUBFAMID_MASK                   0xF000000u
#define SIM_SDID_SUBFAMID_SHIFT                  24
#define SIM_SDID_SUBFAMID_WIDTH                  4
#define SIM_SDID_SUBFAMID(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SUBFAMID_SHIFT))&SIM_SDID_SUBFAMID_MASK)
#define SIM_SDID_FAMID_MASK                      0xF0000000u
#define SIM_SDID_FAMID_SHIFT                     28
#define SIM_SDID_FAMID_WIDTH                     4
#define SIM_SDID_FAMID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_FAMID_SHIFT))&SIM_SDID_FAMID_MASK)
/* FCFG1 Bit Fields */
#define SIM_FCFG1_FLASHDIS_MASK                  0x1u
#define SIM_FCFG1_FLASHDIS_SHIFT                 0
#define SIM_FCFG1_FLASHDIS_WIDTH                 1
#define SIM_FCFG1_FLASHDIS(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_FLASHDIS_SHIFT))&SIM_FCFG1_FLASHDIS_MASK)
#define SIM_FCFG1_FLASHDOZE_MASK                 0x2u
#define SIM_FCFG1_FLASHDOZE_SHIFT                1
#define SIM_FCFG1_FLASHDOZE_WIDTH                1
#define SIM_FCFG1_FLASHDOZE(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_FLASHDOZE_SHIFT))&SIM_FCFG1_FLASHDOZE_MASK)
#define SIM_FCFG1_PFSIZE_MASK                    0xF000000u
#define SIM_FCFG1_PFSIZE_SHIFT                   24
#define SIM_FCFG1_PFSIZE_WIDTH                   4
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_PFSIZE_SHIFT))&SIM_FCFG1_PFSIZE_MASK)
/* FCFG2 Bit Fields */
#define SIM_FCFG2_MAXADDR1_MASK                  0x7F0000u
#define SIM_FCFG2_MAXADDR1_SHIFT                 16
#define SIM_FCFG2_MAXADDR1_WIDTH                 7
#define SIM_FCFG2_MAXADDR1(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR1_SHIFT))&SIM_FCFG2_MAXADDR1_MASK)
#define SIM_FCFG2_MAXADDR0_MASK                  0x7F000000u
#define SIM_FCFG2_MAXADDR0_SHIFT                 24
#define SIM_FCFG2_MAXADDR0_WIDTH                 7
#define SIM_FCFG2_MAXADDR0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR0_SHIFT))&SIM_FCFG2_MAXADDR0_MASK)
/* UIDMH Bit Fields */
#define SIM_UIDMH_UID_MASK                       0xFFFFu
#define SIM_UIDMH_UID_SHIFT                      0
#define SIM_UIDMH_UID_WIDTH                      16
#define SIM_UIDMH_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDMH_UID_SHIFT))&SIM_UIDMH_UID_MASK)
/* UIDML Bit Fields */
#define SIM_UIDML_UID_MASK                       0xFFFFFFFFu
#define SIM_UIDML_UID_SHIFT                      0
#define SIM_UIDML_UID_WIDTH                      32
#define SIM_UIDML_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDML_UID_SHIFT))&SIM_UIDML_UID_MASK)
/* UIDL Bit Fields */
#define SIM_UIDL_UID_MASK                        0xFFFFFFFFu
#define SIM_UIDL_UID_SHIFT                       0
#define SIM_UIDL_UID_WIDTH                       32
#define SIM_UIDL_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UIDL_UID_SHIFT))&SIM_UIDL_UID_MASK)

/*!
 * @}
 */ /* end of group SIM_Register_Masks */


/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base address */
#define SIM_BASE                                 (0x40074000u)
/** Peripheral SIM base pointer */
#define SIM                                      ((SIM_Type *)SIM_BASE)
#define SIM_BASE_PTR                             (SIM)
/** Array initializer of SIM peripheral base addresses */
#define SIM_BASE_ADDRS                           { SIM_BASE }
/** Array initializer of SIM peripheral base pointers */
#define SIM_BASE_PTRS                            { SIM }

/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros
 * @{
 */


/* SIM - Register instance definitions */
/* SIM */
#define SIM_SOPT1                                SIM_SOPT1_REG(SIM)
#define SIM_SOPT1CFG                             SIM_SOPT1CFG_REG(SIM)
#define SIM_SDID                                 SIM_SDID_REG(SIM)
#define SIM_FCFG1                                SIM_FCFG1_REG(SIM)
#define SIM_FCFG2                                SIM_FCFG2_REG(SIM)
#define SIM_UIDMH                                SIM_UIDMH_REG(SIM)
#define SIM_UIDML                                SIM_UIDML_REG(SIM)
#define SIM_UIDL                                 SIM_UIDL_REG(SIM)

/*!
 * @}
 */ /* end of group SIM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group SIM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Peripheral_Access_Layer SMC Peripheral Access Layer
 * @{
 */

/** SMC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< SMC Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< SMC Parameter Register, offset: 0x4 */
  __IO uint32_t PMPROT;                            /**< Power Mode Protection register, offset: 0x8 */
  __IO uint32_t PMCTRL;                            /**< Power Mode Control register, offset: 0xC */
  __IO uint32_t STOPCTRL;                          /**< Stop Control Register, offset: 0x10 */
  __I  uint32_t PMSTAT;                            /**< Power Mode Status register, offset: 0x14 */
} SMC_Type, *SMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Register_Accessor_Macros SMC - Register accessor macros
 * @{
 */


/* SMC - Register accessors */
#define SMC_VERID_REG(base)                      ((base)->VERID)
#define SMC_PARAM_REG(base)                      ((base)->PARAM)
#define SMC_PMPROT_REG(base)                     ((base)->PMPROT)
#define SMC_PMCTRL_REG(base)                     ((base)->PMCTRL)
#define SMC_STOPCTRL_REG(base)                   ((base)->STOPCTRL)
#define SMC_PMSTAT_REG(base)                     ((base)->PMSTAT)

/*!
 * @}
 */ /* end of group SMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Register_Masks SMC Register Masks
 * @{
 */

/* VERID Bit Fields */
#define SMC_VERID_FEATURE_MASK                   0xFFFFu
#define SMC_VERID_FEATURE_SHIFT                  0
#define SMC_VERID_FEATURE_WIDTH                  16
#define SMC_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x))<<SMC_VERID_FEATURE_SHIFT))&SMC_VERID_FEATURE_MASK)
#define SMC_VERID_MINOR_MASK                     0xFF0000u
#define SMC_VERID_MINOR_SHIFT                    16
#define SMC_VERID_MINOR_WIDTH                    8
#define SMC_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x))<<SMC_VERID_MINOR_SHIFT))&SMC_VERID_MINOR_MASK)
#define SMC_VERID_MAJOR_MASK                     0xFF000000u
#define SMC_VERID_MAJOR_SHIFT                    24
#define SMC_VERID_MAJOR_WIDTH                    8
#define SMC_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x))<<SMC_VERID_MAJOR_SHIFT))&SMC_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define SMC_PARAM_EHSRUN_MASK                    0x1u
#define SMC_PARAM_EHSRUN_SHIFT                   0
#define SMC_PARAM_EHSRUN_WIDTH                   1
#define SMC_PARAM_EHSRUN(x)                      (((uint32_t)(((uint32_t)(x))<<SMC_PARAM_EHSRUN_SHIFT))&SMC_PARAM_EHSRUN_MASK)
#define SMC_PARAM_ELLS_MASK                      0x8u
#define SMC_PARAM_ELLS_SHIFT                     3
#define SMC_PARAM_ELLS_WIDTH                     1
#define SMC_PARAM_ELLS(x)                        (((uint32_t)(((uint32_t)(x))<<SMC_PARAM_ELLS_SHIFT))&SMC_PARAM_ELLS_MASK)
#define SMC_PARAM_ELLS2_MASK                     0x20u
#define SMC_PARAM_ELLS2_SHIFT                    5
#define SMC_PARAM_ELLS2_WIDTH                    1
#define SMC_PARAM_ELLS2(x)                       (((uint32_t)(((uint32_t)(x))<<SMC_PARAM_ELLS2_SHIFT))&SMC_PARAM_ELLS2_MASK)
#define SMC_PARAM_EVLLS0_MASK                    0x40u
#define SMC_PARAM_EVLLS0_SHIFT                   6
#define SMC_PARAM_EVLLS0_WIDTH                   1
#define SMC_PARAM_EVLLS0(x)                      (((uint32_t)(((uint32_t)(x))<<SMC_PARAM_EVLLS0_SHIFT))&SMC_PARAM_EVLLS0_MASK)
/* PMPROT Bit Fields */
#define SMC_PMPROT_AVLLS_MASK                    0x2u
#define SMC_PMPROT_AVLLS_SHIFT                   1
#define SMC_PMPROT_AVLLS_WIDTH                   1
#define SMC_PMPROT_AVLLS(x)                      (((uint32_t)(((uint32_t)(x))<<SMC_PMPROT_AVLLS_SHIFT))&SMC_PMPROT_AVLLS_MASK)
#define SMC_PMPROT_ALLS_MASK                     0x8u
#define SMC_PMPROT_ALLS_SHIFT                    3
#define SMC_PMPROT_ALLS_WIDTH                    1
#define SMC_PMPROT_ALLS(x)                       (((uint32_t)(((uint32_t)(x))<<SMC_PMPROT_ALLS_SHIFT))&SMC_PMPROT_ALLS_MASK)
#define SMC_PMPROT_AVLP_MASK                     0x20u
#define SMC_PMPROT_AVLP_SHIFT                    5
#define SMC_PMPROT_AVLP_WIDTH                    1
#define SMC_PMPROT_AVLP(x)                       (((uint32_t)(((uint32_t)(x))<<SMC_PMPROT_AVLP_SHIFT))&SMC_PMPROT_AVLP_MASK)
#define SMC_PMPROT_AHSRUN_MASK                   0x80u
#define SMC_PMPROT_AHSRUN_SHIFT                  7
#define SMC_PMPROT_AHSRUN_WIDTH                  1
#define SMC_PMPROT_AHSRUN(x)                     (((uint32_t)(((uint32_t)(x))<<SMC_PMPROT_AHSRUN_SHIFT))&SMC_PMPROT_AHSRUN_MASK)
/* PMCTRL Bit Fields */
#define SMC_PMCTRL_STOPM_MASK                    0x7u
#define SMC_PMCTRL_STOPM_SHIFT                   0
#define SMC_PMCTRL_STOPM_WIDTH                   3
#define SMC_PMCTRL_STOPM(x)                      (((uint32_t)(((uint32_t)(x))<<SMC_PMCTRL_STOPM_SHIFT))&SMC_PMCTRL_STOPM_MASK)
#define SMC_PMCTRL_STOPA_MASK                    0x8u
#define SMC_PMCTRL_STOPA_SHIFT                   3
#define SMC_PMCTRL_STOPA_WIDTH                   1
#define SMC_PMCTRL_STOPA(x)                      (((uint32_t)(((uint32_t)(x))<<SMC_PMCTRL_STOPA_SHIFT))&SMC_PMCTRL_STOPA_MASK)
#define SMC_PMCTRL_RUNM_MASK                     0x60u
#define SMC_PMCTRL_RUNM_SHIFT                    5
#define SMC_PMCTRL_RUNM_WIDTH                    2
#define SMC_PMCTRL_RUNM(x)                       (((uint32_t)(((uint32_t)(x))<<SMC_PMCTRL_RUNM_SHIFT))&SMC_PMCTRL_RUNM_MASK)
/* STOPCTRL Bit Fields */
#define SMC_STOPCTRL_LLSM_MASK                   0x7u
#define SMC_STOPCTRL_LLSM_SHIFT                  0
#define SMC_STOPCTRL_LLSM_WIDTH                  3
#define SMC_STOPCTRL_LLSM(x)                     (((uint32_t)(((uint32_t)(x))<<SMC_STOPCTRL_LLSM_SHIFT))&SMC_STOPCTRL_LLSM_MASK)
#define SMC_STOPCTRL_LPOPO_MASK                  0x8u
#define SMC_STOPCTRL_LPOPO_SHIFT                 3
#define SMC_STOPCTRL_LPOPO_WIDTH                 1
#define SMC_STOPCTRL_LPOPO(x)                    (((uint32_t)(((uint32_t)(x))<<SMC_STOPCTRL_LPOPO_SHIFT))&SMC_STOPCTRL_LPOPO_MASK)
#define SMC_STOPCTRL_PORPO_MASK                  0x20u
#define SMC_STOPCTRL_PORPO_SHIFT                 5
#define SMC_STOPCTRL_PORPO_WIDTH                 1
#define SMC_STOPCTRL_PORPO(x)                    (((uint32_t)(((uint32_t)(x))<<SMC_STOPCTRL_PORPO_SHIFT))&SMC_STOPCTRL_PORPO_MASK)
#define SMC_STOPCTRL_PSTOPO_MASK                 0xC0u
#define SMC_STOPCTRL_PSTOPO_SHIFT                6
#define SMC_STOPCTRL_PSTOPO_WIDTH                2
#define SMC_STOPCTRL_PSTOPO(x)                   (((uint32_t)(((uint32_t)(x))<<SMC_STOPCTRL_PSTOPO_SHIFT))&SMC_STOPCTRL_PSTOPO_MASK)
/* PMSTAT Bit Fields */
#define SMC_PMSTAT_PMSTAT_MASK                   0xFFu
#define SMC_PMSTAT_PMSTAT_SHIFT                  0
#define SMC_PMSTAT_PMSTAT_WIDTH                  8
#define SMC_PMSTAT_PMSTAT(x)                     (((uint32_t)(((uint32_t)(x))<<SMC_PMSTAT_PMSTAT_SHIFT))&SMC_PMSTAT_PMSTAT_MASK)

/*!
 * @}
 */ /* end of group SMC_Register_Masks */


/* SMC - Peripheral instance base addresses */
/** Peripheral SMC base address */
#define SMC_BASE                                 (0x4007E000u)
/** Peripheral SMC base pointer */
#define SMC                                      ((SMC_Type *)SMC_BASE)
#define SMC_BASE_PTR                             (SMC)
/** Array initializer of SMC peripheral base addresses */
#define SMC_BASE_ADDRS                           { SMC_BASE }
/** Array initializer of SMC peripheral base pointers */
#define SMC_BASE_PTRS                            { SMC }

/* ----------------------------------------------------------------------------
   -- SMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Register_Accessor_Macros SMC - Register accessor macros
 * @{
 */


/* SMC - Register instance definitions */
/* SMC */
#define SMC_VERID                                SMC_VERID_REG(SMC)
#define SMC_PARAM                                SMC_PARAM_REG(SMC)
#define SMC_PMPROT                               SMC_PMPROT_REG(SMC)
#define SMC_PMCTRL                               SMC_PMCTRL_REG(SMC)
#define SMC_STOPCTRL                             SMC_STOPCTRL_REG(SMC)
#define SMC_PMSTAT                               SMC_PMSTAT_REG(SMC)

/*!
 * @}
 */ /* end of group SMC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group SMC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- TPM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TPM_Peripheral_Access_Layer TPM Peripheral Access Layer
 * @{
 */

/** TPM - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t GLOBAL;                            /**< TPM Global Register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SC;                                /**< Status and Control, offset: 0x10 */
  __IO uint32_t CNT;                               /**< Counter, offset: 0x14 */
  __IO uint32_t MOD;                               /**< Modulo, offset: 0x18 */
  __IO uint32_t STATUS;                            /**< Capture and Compare Status, offset: 0x1C */
  struct {                                         /* offset: 0x20, array step: 0x8 */
    __IO uint32_t CnSC;                              /**< Channel (n) Status and Control, array offset: 0x20, array step: 0x8 */
    __IO uint32_t CnV;                               /**< Channel (n) Value, array offset: 0x24, array step: 0x8 */
  } CONTROLS[6];
       uint8_t RESERVED_1[20];
  __IO uint32_t COMBINE;                           /**< Combine Channel Register, offset: 0x64 */
       uint8_t RESERVED_2[4];
  __IO uint32_t TRIG;                              /**< Channel Trigger, offset: 0x6C */
  __IO uint32_t POL;                               /**< Channel Polarity, offset: 0x70 */
       uint8_t RESERVED_3[4];
  __IO uint32_t FILTER;                            /**< Filter Control, offset: 0x78 */
       uint8_t RESERVED_4[4];
  __IO uint32_t QDCTRL;                            /**< Quadrature Decoder Control and Status, offset: 0x80 */
  __IO uint32_t CONF;                              /**< Configuration, offset: 0x84 */
} TPM_Type, *TPM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- TPM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TPM_Register_Accessor_Macros TPM - Register accessor macros
 * @{
 */


/* TPM - Register accessors */
#define TPM_VERID_REG(base)                      ((base)->VERID)
#define TPM_PARAM_REG(base)                      ((base)->PARAM)
#define TPM_GLOBAL_REG(base)                     ((base)->GLOBAL)
#define TPM_SC_REG(base)                         ((base)->SC)
#define TPM_CNT_REG(base)                        ((base)->CNT)
#define TPM_MOD_REG(base)                        ((base)->MOD)
#define TPM_STATUS_REG(base)                     ((base)->STATUS)
#define TPM_CnSC_REG(base,index)                 ((base)->CONTROLS[index].CnSC)
#define TPM_CnSC_COUNT                           6
#define TPM_CnV_REG(base,index)                  ((base)->CONTROLS[index].CnV)
#define TPM_CnV_COUNT                            6
#define TPM_COMBINE_REG(base)                    ((base)->COMBINE)
#define TPM_TRIG_REG(base)                       ((base)->TRIG)
#define TPM_POL_REG(base)                        ((base)->POL)
#define TPM_FILTER_REG(base)                     ((base)->FILTER)
#define TPM_QDCTRL_REG(base)                     ((base)->QDCTRL)
#define TPM_CONF_REG(base)                       ((base)->CONF)

/*!
 * @}
 */ /* end of group TPM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- TPM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TPM_Register_Masks TPM Register Masks
 * @{
 */

/* VERID Bit Fields */
#define TPM_VERID_FEATURE_MASK                   0xFFFFu
#define TPM_VERID_FEATURE_SHIFT                  0
#define TPM_VERID_FEATURE_WIDTH                  16
#define TPM_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x))<<TPM_VERID_FEATURE_SHIFT))&TPM_VERID_FEATURE_MASK)
#define TPM_VERID_MINOR_MASK                     0xFF0000u
#define TPM_VERID_MINOR_SHIFT                    16
#define TPM_VERID_MINOR_WIDTH                    8
#define TPM_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_VERID_MINOR_SHIFT))&TPM_VERID_MINOR_MASK)
#define TPM_VERID_MAJOR_MASK                     0xFF000000u
#define TPM_VERID_MAJOR_SHIFT                    24
#define TPM_VERID_MAJOR_WIDTH                    8
#define TPM_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_VERID_MAJOR_SHIFT))&TPM_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define TPM_PARAM_CHAN_MASK                      0xFFu
#define TPM_PARAM_CHAN_SHIFT                     0
#define TPM_PARAM_CHAN_WIDTH                     8
#define TPM_PARAM_CHAN(x)                        (((uint32_t)(((uint32_t)(x))<<TPM_PARAM_CHAN_SHIFT))&TPM_PARAM_CHAN_MASK)
#define TPM_PARAM_TRIG_MASK                      0xFF00u
#define TPM_PARAM_TRIG_SHIFT                     8
#define TPM_PARAM_TRIG_WIDTH                     8
#define TPM_PARAM_TRIG(x)                        (((uint32_t)(((uint32_t)(x))<<TPM_PARAM_TRIG_SHIFT))&TPM_PARAM_TRIG_MASK)
#define TPM_PARAM_WIDTH_MASK                     0xFF0000u
#define TPM_PARAM_WIDTH_SHIFT                    16
#define TPM_PARAM_WIDTH_WIDTH                    8
#define TPM_PARAM_WIDTH(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_PARAM_WIDTH_SHIFT))&TPM_PARAM_WIDTH_MASK)
/* GLOBAL Bit Fields */
#define TPM_GLOBAL_RST_MASK                      0x2u
#define TPM_GLOBAL_RST_SHIFT                     1
#define TPM_GLOBAL_RST_WIDTH                     1
#define TPM_GLOBAL_RST(x)                        (((uint32_t)(((uint32_t)(x))<<TPM_GLOBAL_RST_SHIFT))&TPM_GLOBAL_RST_MASK)
/* SC Bit Fields */
#define TPM_SC_PS_MASK                           0x7u
#define TPM_SC_PS_SHIFT                          0
#define TPM_SC_PS_WIDTH                          3
#define TPM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<TPM_SC_PS_SHIFT))&TPM_SC_PS_MASK)
#define TPM_SC_CMOD_MASK                         0x18u
#define TPM_SC_CMOD_SHIFT                        3
#define TPM_SC_CMOD_WIDTH                        2
#define TPM_SC_CMOD(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_SC_CMOD_SHIFT))&TPM_SC_CMOD_MASK)
#define TPM_SC_CPWMS_MASK                        0x20u
#define TPM_SC_CPWMS_SHIFT                       5
#define TPM_SC_CPWMS_WIDTH                       1
#define TPM_SC_CPWMS(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_SC_CPWMS_SHIFT))&TPM_SC_CPWMS_MASK)
#define TPM_SC_TOIE_MASK                         0x40u
#define TPM_SC_TOIE_SHIFT                        6
#define TPM_SC_TOIE_WIDTH                        1
#define TPM_SC_TOIE(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_SC_TOIE_SHIFT))&TPM_SC_TOIE_MASK)
#define TPM_SC_TOF_MASK                          0x80u
#define TPM_SC_TOF_SHIFT                         7
#define TPM_SC_TOF_WIDTH                         1
#define TPM_SC_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<TPM_SC_TOF_SHIFT))&TPM_SC_TOF_MASK)
#define TPM_SC_DMA_MASK                          0x100u
#define TPM_SC_DMA_SHIFT                         8
#define TPM_SC_DMA_WIDTH                         1
#define TPM_SC_DMA(x)                            (((uint32_t)(((uint32_t)(x))<<TPM_SC_DMA_SHIFT))&TPM_SC_DMA_MASK)
/* CNT Bit Fields */
#define TPM_CNT_COUNT_MASK                       0xFFFFu
#define TPM_CNT_COUNT_SHIFT                      0
#define TPM_CNT_COUNT_WIDTH                      16
#define TPM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CNT_COUNT_SHIFT))&TPM_CNT_COUNT_MASK)
/* MOD Bit Fields */
#define TPM_MOD_MOD_MASK                         0xFFFFu
#define TPM_MOD_MOD_SHIFT                        0
#define TPM_MOD_MOD_WIDTH                        16
#define TPM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_MOD_MOD_SHIFT))&TPM_MOD_MOD_MASK)
/* STATUS Bit Fields */
#define TPM_STATUS_CH0F_MASK                     0x1u
#define TPM_STATUS_CH0F_SHIFT                    0
#define TPM_STATUS_CH0F_WIDTH                    1
#define TPM_STATUS_CH0F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH0F_SHIFT))&TPM_STATUS_CH0F_MASK)
#define TPM_STATUS_CH1F_MASK                     0x2u
#define TPM_STATUS_CH1F_SHIFT                    1
#define TPM_STATUS_CH1F_WIDTH                    1
#define TPM_STATUS_CH1F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH1F_SHIFT))&TPM_STATUS_CH1F_MASK)
#define TPM_STATUS_CH2F_MASK                     0x4u
#define TPM_STATUS_CH2F_SHIFT                    2
#define TPM_STATUS_CH2F_WIDTH                    1
#define TPM_STATUS_CH2F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH2F_SHIFT))&TPM_STATUS_CH2F_MASK)
#define TPM_STATUS_CH3F_MASK                     0x8u
#define TPM_STATUS_CH3F_SHIFT                    3
#define TPM_STATUS_CH3F_WIDTH                    1
#define TPM_STATUS_CH3F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH3F_SHIFT))&TPM_STATUS_CH3F_MASK)
#define TPM_STATUS_CH4F_MASK                     0x10u
#define TPM_STATUS_CH4F_SHIFT                    4
#define TPM_STATUS_CH4F_WIDTH                    1
#define TPM_STATUS_CH4F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH4F_SHIFT))&TPM_STATUS_CH4F_MASK)
#define TPM_STATUS_CH5F_MASK                     0x20u
#define TPM_STATUS_CH5F_SHIFT                    5
#define TPM_STATUS_CH5F_WIDTH                    1
#define TPM_STATUS_CH5F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH5F_SHIFT))&TPM_STATUS_CH5F_MASK)
#define TPM_STATUS_TOF_MASK                      0x100u
#define TPM_STATUS_TOF_SHIFT                     8
#define TPM_STATUS_TOF_WIDTH                     1
#define TPM_STATUS_TOF(x)                        (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_TOF_SHIFT))&TPM_STATUS_TOF_MASK)
/* CnSC Bit Fields */
#define TPM_CnSC_DMA_MASK                        0x1u
#define TPM_CnSC_DMA_SHIFT                       0
#define TPM_CnSC_DMA_WIDTH                       1
#define TPM_CnSC_DMA(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_DMA_SHIFT))&TPM_CnSC_DMA_MASK)
#define TPM_CnSC_ELSA_MASK                       0x4u
#define TPM_CnSC_ELSA_SHIFT                      2
#define TPM_CnSC_ELSA_WIDTH                      1
#define TPM_CnSC_ELSA(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_ELSA_SHIFT))&TPM_CnSC_ELSA_MASK)
#define TPM_CnSC_ELSB_MASK                       0x8u
#define TPM_CnSC_ELSB_SHIFT                      3
#define TPM_CnSC_ELSB_WIDTH                      1
#define TPM_CnSC_ELSB(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_ELSB_SHIFT))&TPM_CnSC_ELSB_MASK)
#define TPM_CnSC_MSA_MASK                        0x10u
#define TPM_CnSC_MSA_SHIFT                       4
#define TPM_CnSC_MSA_WIDTH                       1
#define TPM_CnSC_MSA(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_MSA_SHIFT))&TPM_CnSC_MSA_MASK)
#define TPM_CnSC_MSB_MASK                        0x20u
#define TPM_CnSC_MSB_SHIFT                       5
#define TPM_CnSC_MSB_WIDTH                       1
#define TPM_CnSC_MSB(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_MSB_SHIFT))&TPM_CnSC_MSB_MASK)
#define TPM_CnSC_CHIE_MASK                       0x40u
#define TPM_CnSC_CHIE_SHIFT                      6
#define TPM_CnSC_CHIE_WIDTH                      1
#define TPM_CnSC_CHIE(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_CHIE_SHIFT))&TPM_CnSC_CHIE_MASK)
#define TPM_CnSC_CHF_MASK                        0x80u
#define TPM_CnSC_CHF_SHIFT                       7
#define TPM_CnSC_CHF_WIDTH                       1
#define TPM_CnSC_CHF(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_CHF_SHIFT))&TPM_CnSC_CHF_MASK)
/* CnV Bit Fields */
#define TPM_CnV_VAL_MASK                         0xFFFFu
#define TPM_CnV_VAL_SHIFT                        0
#define TPM_CnV_VAL_WIDTH                        16
#define TPM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_CnV_VAL_SHIFT))&TPM_CnV_VAL_MASK)
/* COMBINE Bit Fields */
#define TPM_COMBINE_COMBINE0_MASK                0x1u
#define TPM_COMBINE_COMBINE0_SHIFT               0
#define TPM_COMBINE_COMBINE0_WIDTH               1
#define TPM_COMBINE_COMBINE0(x)                  (((uint32_t)(((uint32_t)(x))<<TPM_COMBINE_COMBINE0_SHIFT))&TPM_COMBINE_COMBINE0_MASK)
#define TPM_COMBINE_COMSWAP0_MASK                0x2u
#define TPM_COMBINE_COMSWAP0_SHIFT               1
#define TPM_COMBINE_COMSWAP0_WIDTH               1
#define TPM_COMBINE_COMSWAP0(x)                  (((uint32_t)(((uint32_t)(x))<<TPM_COMBINE_COMSWAP0_SHIFT))&TPM_COMBINE_COMSWAP0_MASK)
#define TPM_COMBINE_COMBINE1_MASK                0x100u
#define TPM_COMBINE_COMBINE1_SHIFT               8
#define TPM_COMBINE_COMBINE1_WIDTH               1
#define TPM_COMBINE_COMBINE1(x)                  (((uint32_t)(((uint32_t)(x))<<TPM_COMBINE_COMBINE1_SHIFT))&TPM_COMBINE_COMBINE1_MASK)
#define TPM_COMBINE_COMSWAP1_MASK                0x200u
#define TPM_COMBINE_COMSWAP1_SHIFT               9
#define TPM_COMBINE_COMSWAP1_WIDTH               1
#define TPM_COMBINE_COMSWAP1(x)                  (((uint32_t)(((uint32_t)(x))<<TPM_COMBINE_COMSWAP1_SHIFT))&TPM_COMBINE_COMSWAP1_MASK)
#define TPM_COMBINE_COMBINE2_MASK                0x10000u
#define TPM_COMBINE_COMBINE2_SHIFT               16
#define TPM_COMBINE_COMBINE2_WIDTH               1
#define TPM_COMBINE_COMBINE2(x)                  (((uint32_t)(((uint32_t)(x))<<TPM_COMBINE_COMBINE2_SHIFT))&TPM_COMBINE_COMBINE2_MASK)
#define TPM_COMBINE_COMSWAP2_MASK                0x20000u
#define TPM_COMBINE_COMSWAP2_SHIFT               17
#define TPM_COMBINE_COMSWAP2_WIDTH               1
#define TPM_COMBINE_COMSWAP2(x)                  (((uint32_t)(((uint32_t)(x))<<TPM_COMBINE_COMSWAP2_SHIFT))&TPM_COMBINE_COMSWAP2_MASK)
/* TRIG Bit Fields */
#define TPM_TRIG_TRIG0_MASK                      0x1u
#define TPM_TRIG_TRIG0_SHIFT                     0
#define TPM_TRIG_TRIG0_WIDTH                     1
#define TPM_TRIG_TRIG0(x)                        (((uint32_t)(((uint32_t)(x))<<TPM_TRIG_TRIG0_SHIFT))&TPM_TRIG_TRIG0_MASK)
#define TPM_TRIG_TRIG1_MASK                      0x2u
#define TPM_TRIG_TRIG1_SHIFT                     1
#define TPM_TRIG_TRIG1_WIDTH                     1
#define TPM_TRIG_TRIG1(x)                        (((uint32_t)(((uint32_t)(x))<<TPM_TRIG_TRIG1_SHIFT))&TPM_TRIG_TRIG1_MASK)
#define TPM_TRIG_TRIG2_MASK                      0x4u
#define TPM_TRIG_TRIG2_SHIFT                     2
#define TPM_TRIG_TRIG2_WIDTH                     1
#define TPM_TRIG_TRIG2(x)                        (((uint32_t)(((uint32_t)(x))<<TPM_TRIG_TRIG2_SHIFT))&TPM_TRIG_TRIG2_MASK)
#define TPM_TRIG_TRIG3_MASK                      0x8u
#define TPM_TRIG_TRIG3_SHIFT                     3
#define TPM_TRIG_TRIG3_WIDTH                     1
#define TPM_TRIG_TRIG3(x)                        (((uint32_t)(((uint32_t)(x))<<TPM_TRIG_TRIG3_SHIFT))&TPM_TRIG_TRIG3_MASK)
#define TPM_TRIG_TRIG4_MASK                      0x10u
#define TPM_TRIG_TRIG4_SHIFT                     4
#define TPM_TRIG_TRIG4_WIDTH                     1
#define TPM_TRIG_TRIG4(x)                        (((uint32_t)(((uint32_t)(x))<<TPM_TRIG_TRIG4_SHIFT))&TPM_TRIG_TRIG4_MASK)
#define TPM_TRIG_TRIG5_MASK                      0x20u
#define TPM_TRIG_TRIG5_SHIFT                     5
#define TPM_TRIG_TRIG5_WIDTH                     1
#define TPM_TRIG_TRIG5(x)                        (((uint32_t)(((uint32_t)(x))<<TPM_TRIG_TRIG5_SHIFT))&TPM_TRIG_TRIG5_MASK)
/* POL Bit Fields */
#define TPM_POL_POL0_MASK                        0x1u
#define TPM_POL_POL0_SHIFT                       0
#define TPM_POL_POL0_WIDTH                       1
#define TPM_POL_POL0(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL0_SHIFT))&TPM_POL_POL0_MASK)
#define TPM_POL_POL1_MASK                        0x2u
#define TPM_POL_POL1_SHIFT                       1
#define TPM_POL_POL1_WIDTH                       1
#define TPM_POL_POL1(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL1_SHIFT))&TPM_POL_POL1_MASK)
#define TPM_POL_POL2_MASK                        0x4u
#define TPM_POL_POL2_SHIFT                       2
#define TPM_POL_POL2_WIDTH                       1
#define TPM_POL_POL2(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL2_SHIFT))&TPM_POL_POL2_MASK)
#define TPM_POL_POL3_MASK                        0x8u
#define TPM_POL_POL3_SHIFT                       3
#define TPM_POL_POL3_WIDTH                       1
#define TPM_POL_POL3(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL3_SHIFT))&TPM_POL_POL3_MASK)
#define TPM_POL_POL4_MASK                        0x10u
#define TPM_POL_POL4_SHIFT                       4
#define TPM_POL_POL4_WIDTH                       1
#define TPM_POL_POL4(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL4_SHIFT))&TPM_POL_POL4_MASK)
#define TPM_POL_POL5_MASK                        0x20u
#define TPM_POL_POL5_SHIFT                       5
#define TPM_POL_POL5_WIDTH                       1
#define TPM_POL_POL5(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL5_SHIFT))&TPM_POL_POL5_MASK)
/* FILTER Bit Fields */
#define TPM_FILTER_CH0FVAL_MASK                  0xFu
#define TPM_FILTER_CH0FVAL_SHIFT                 0
#define TPM_FILTER_CH0FVAL_WIDTH                 4
#define TPM_FILTER_CH0FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<TPM_FILTER_CH0FVAL_SHIFT))&TPM_FILTER_CH0FVAL_MASK)
#define TPM_FILTER_CH1FVAL_MASK                  0xF0u
#define TPM_FILTER_CH1FVAL_SHIFT                 4
#define TPM_FILTER_CH1FVAL_WIDTH                 4
#define TPM_FILTER_CH1FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<TPM_FILTER_CH1FVAL_SHIFT))&TPM_FILTER_CH1FVAL_MASK)
#define TPM_FILTER_CH2FVAL_MASK                  0xF00u
#define TPM_FILTER_CH2FVAL_SHIFT                 8
#define TPM_FILTER_CH2FVAL_WIDTH                 4
#define TPM_FILTER_CH2FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<TPM_FILTER_CH2FVAL_SHIFT))&TPM_FILTER_CH2FVAL_MASK)
#define TPM_FILTER_CH3FVAL_MASK                  0xF000u
#define TPM_FILTER_CH3FVAL_SHIFT                 12
#define TPM_FILTER_CH3FVAL_WIDTH                 4
#define TPM_FILTER_CH3FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<TPM_FILTER_CH3FVAL_SHIFT))&TPM_FILTER_CH3FVAL_MASK)
#define TPM_FILTER_CH4FVAL_MASK                  0xF0000u
#define TPM_FILTER_CH4FVAL_SHIFT                 16
#define TPM_FILTER_CH4FVAL_WIDTH                 4
#define TPM_FILTER_CH4FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<TPM_FILTER_CH4FVAL_SHIFT))&TPM_FILTER_CH4FVAL_MASK)
#define TPM_FILTER_CH5FVAL_MASK                  0xF00000u
#define TPM_FILTER_CH5FVAL_SHIFT                 20
#define TPM_FILTER_CH5FVAL_WIDTH                 4
#define TPM_FILTER_CH5FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<TPM_FILTER_CH5FVAL_SHIFT))&TPM_FILTER_CH5FVAL_MASK)
/* QDCTRL Bit Fields */
#define TPM_QDCTRL_QUADEN_MASK                   0x1u
#define TPM_QDCTRL_QUADEN_SHIFT                  0
#define TPM_QDCTRL_QUADEN_WIDTH                  1
#define TPM_QDCTRL_QUADEN(x)                     (((uint32_t)(((uint32_t)(x))<<TPM_QDCTRL_QUADEN_SHIFT))&TPM_QDCTRL_QUADEN_MASK)
#define TPM_QDCTRL_TOFDIR_MASK                   0x2u
#define TPM_QDCTRL_TOFDIR_SHIFT                  1
#define TPM_QDCTRL_TOFDIR_WIDTH                  1
#define TPM_QDCTRL_TOFDIR(x)                     (((uint32_t)(((uint32_t)(x))<<TPM_QDCTRL_TOFDIR_SHIFT))&TPM_QDCTRL_TOFDIR_MASK)
#define TPM_QDCTRL_QUADIR_MASK                   0x4u
#define TPM_QDCTRL_QUADIR_SHIFT                  2
#define TPM_QDCTRL_QUADIR_WIDTH                  1
#define TPM_QDCTRL_QUADIR(x)                     (((uint32_t)(((uint32_t)(x))<<TPM_QDCTRL_QUADIR_SHIFT))&TPM_QDCTRL_QUADIR_MASK)
#define TPM_QDCTRL_QUADMODE_MASK                 0x8u
#define TPM_QDCTRL_QUADMODE_SHIFT                3
#define TPM_QDCTRL_QUADMODE_WIDTH                1
#define TPM_QDCTRL_QUADMODE(x)                   (((uint32_t)(((uint32_t)(x))<<TPM_QDCTRL_QUADMODE_SHIFT))&TPM_QDCTRL_QUADMODE_MASK)
/* CONF Bit Fields */
#define TPM_CONF_DOZEEN_MASK                     0x20u
#define TPM_CONF_DOZEEN_SHIFT                    5
#define TPM_CONF_DOZEEN_WIDTH                    1
#define TPM_CONF_DOZEEN(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_DOZEEN_SHIFT))&TPM_CONF_DOZEEN_MASK)
#define TPM_CONF_DBGMODE_MASK                    0xC0u
#define TPM_CONF_DBGMODE_SHIFT                   6
#define TPM_CONF_DBGMODE_WIDTH                   2
#define TPM_CONF_DBGMODE(x)                      (((uint32_t)(((uint32_t)(x))<<TPM_CONF_DBGMODE_SHIFT))&TPM_CONF_DBGMODE_MASK)
#define TPM_CONF_GTBSYNC_MASK                    0x100u
#define TPM_CONF_GTBSYNC_SHIFT                   8
#define TPM_CONF_GTBSYNC_WIDTH                   1
#define TPM_CONF_GTBSYNC(x)                      (((uint32_t)(((uint32_t)(x))<<TPM_CONF_GTBSYNC_SHIFT))&TPM_CONF_GTBSYNC_MASK)
#define TPM_CONF_GTBEEN_MASK                     0x200u
#define TPM_CONF_GTBEEN_SHIFT                    9
#define TPM_CONF_GTBEEN_WIDTH                    1
#define TPM_CONF_GTBEEN(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_GTBEEN_SHIFT))&TPM_CONF_GTBEEN_MASK)
#define TPM_CONF_CSOT_MASK                       0x10000u
#define TPM_CONF_CSOT_SHIFT                      16
#define TPM_CONF_CSOT_WIDTH                      1
#define TPM_CONF_CSOT(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CONF_CSOT_SHIFT))&TPM_CONF_CSOT_MASK)
#define TPM_CONF_CSOO_MASK                       0x20000u
#define TPM_CONF_CSOO_SHIFT                      17
#define TPM_CONF_CSOO_WIDTH                      1
#define TPM_CONF_CSOO(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CONF_CSOO_SHIFT))&TPM_CONF_CSOO_MASK)
#define TPM_CONF_CROT_MASK                       0x40000u
#define TPM_CONF_CROT_SHIFT                      18
#define TPM_CONF_CROT_WIDTH                      1
#define TPM_CONF_CROT(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CONF_CROT_SHIFT))&TPM_CONF_CROT_MASK)
#define TPM_CONF_CPOT_MASK                       0x80000u
#define TPM_CONF_CPOT_SHIFT                      19
#define TPM_CONF_CPOT_WIDTH                      1
#define TPM_CONF_CPOT(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CONF_CPOT_SHIFT))&TPM_CONF_CPOT_MASK)
#define TPM_CONF_TRGPOL_MASK                     0x400000u
#define TPM_CONF_TRGPOL_SHIFT                    22
#define TPM_CONF_TRGPOL_WIDTH                    1
#define TPM_CONF_TRGPOL(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_TRGPOL_SHIFT))&TPM_CONF_TRGPOL_MASK)
#define TPM_CONF_TRGSRC_MASK                     0x800000u
#define TPM_CONF_TRGSRC_SHIFT                    23
#define TPM_CONF_TRGSRC_WIDTH                    1
#define TPM_CONF_TRGSRC(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_TRGSRC_SHIFT))&TPM_CONF_TRGSRC_MASK)
#define TPM_CONF_TRGSEL_MASK                     0xF000000u
#define TPM_CONF_TRGSEL_SHIFT                    24
#define TPM_CONF_TRGSEL_WIDTH                    4
#define TPM_CONF_TRGSEL(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_TRGSEL_SHIFT))&TPM_CONF_TRGSEL_MASK)

/*!
 * @}
 */ /* end of group TPM_Register_Masks */


/* TPM - Peripheral instance base addresses */
/** Peripheral TPM0 base address */
#define TPM0_BASE                                (0x400AC000u)
/** Peripheral TPM0 base pointer */
#define TPM0                                     ((TPM_Type *)TPM0_BASE)
#define TPM0_BASE_PTR                            (TPM0)
/** Peripheral TPM1 base address */
#define TPM1_BASE                                (0x400AD000u)
/** Peripheral TPM1 base pointer */
#define TPM1                                     ((TPM_Type *)TPM1_BASE)
#define TPM1_BASE_PTR                            (TPM1)
/** Peripheral TPM2 base address */
#define TPM2_BASE                                (0x4002E000u)
/** Peripheral TPM2 base pointer */
#define TPM2                                     ((TPM_Type *)TPM2_BASE)
#define TPM2_BASE_PTR                            (TPM2)
/** Array initializer of TPM peripheral base addresses */
#define TPM_BASE_ADDRS                           { TPM0_BASE, TPM1_BASE, TPM2_BASE }
/** Array initializer of TPM peripheral base pointers */
#define TPM_BASE_PTRS                            { TPM0, TPM1, TPM2 }

/* ----------------------------------------------------------------------------
   -- TPM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TPM_Register_Accessor_Macros TPM - Register accessor macros
 * @{
 */


/* TPM - Register instance definitions */
/* TPM0 */
#define TPM0_VERID                               TPM_VERID_REG(TPM0)
#define TPM0_PARAM                               TPM_PARAM_REG(TPM0)
#define TPM0_GLOBAL                              TPM_GLOBAL_REG(TPM0)
#define TPM0_SC                                  TPM_SC_REG(TPM0)
#define TPM0_CNT                                 TPM_CNT_REG(TPM0)
#define TPM0_MOD                                 TPM_MOD_REG(TPM0)
#define TPM0_STATUS                              TPM_STATUS_REG(TPM0)
#define TPM0_C0SC                                TPM_CnSC_REG(TPM0,0)
#define TPM0_C0V                                 TPM_CnV_REG(TPM0,0)
#define TPM0_C1SC                                TPM_CnSC_REG(TPM0,1)
#define TPM0_C1V                                 TPM_CnV_REG(TPM0,1)
#define TPM0_C2SC                                TPM_CnSC_REG(TPM0,2)
#define TPM0_C2V                                 TPM_CnV_REG(TPM0,2)
#define TPM0_C3SC                                TPM_CnSC_REG(TPM0,3)
#define TPM0_C3V                                 TPM_CnV_REG(TPM0,3)
#define TPM0_C4SC                                TPM_CnSC_REG(TPM0,4)
#define TPM0_C4V                                 TPM_CnV_REG(TPM0,4)
#define TPM0_C5SC                                TPM_CnSC_REG(TPM0,5)
#define TPM0_C5V                                 TPM_CnV_REG(TPM0,5)
#define TPM0_COMBINE                             TPM_COMBINE_REG(TPM0)
#define TPM0_TRIG                                TPM_TRIG_REG(TPM0)
#define TPM0_POL                                 TPM_POL_REG(TPM0)
#define TPM0_FILTER                              TPM_FILTER_REG(TPM0)
#define TPM0_QDCTRL                              TPM_QDCTRL_REG(TPM0)
#define TPM0_CONF                                TPM_CONF_REG(TPM0)
/* TPM1 */
#define TPM1_VERID                               TPM_VERID_REG(TPM1)
#define TPM1_PARAM                               TPM_PARAM_REG(TPM1)
#define TPM1_GLOBAL                              TPM_GLOBAL_REG(TPM1)
#define TPM1_SC                                  TPM_SC_REG(TPM1)
#define TPM1_CNT                                 TPM_CNT_REG(TPM1)
#define TPM1_MOD                                 TPM_MOD_REG(TPM1)
#define TPM1_STATUS                              TPM_STATUS_REG(TPM1)
#define TPM1_C0SC                                TPM_CnSC_REG(TPM1,0)
#define TPM1_C0V                                 TPM_CnV_REG(TPM1,0)
#define TPM1_C1SC                                TPM_CnSC_REG(TPM1,1)
#define TPM1_C1V                                 TPM_CnV_REG(TPM1,1)
#define TPM1_COMBINE                             TPM_COMBINE_REG(TPM1)
#define TPM1_TRIG                                TPM_TRIG_REG(TPM1)
#define TPM1_POL                                 TPM_POL_REG(TPM1)
#define TPM1_FILTER                              TPM_FILTER_REG(TPM1)
#define TPM1_QDCTRL                              TPM_QDCTRL_REG(TPM1)
#define TPM1_CONF                                TPM_CONF_REG(TPM1)
/* TPM2 */
#define TPM2_VERID                               TPM_VERID_REG(TPM2)
#define TPM2_PARAM                               TPM_PARAM_REG(TPM2)
#define TPM2_GLOBAL                              TPM_GLOBAL_REG(TPM2)
#define TPM2_SC                                  TPM_SC_REG(TPM2)
#define TPM2_CNT                                 TPM_CNT_REG(TPM2)
#define TPM2_MOD                                 TPM_MOD_REG(TPM2)
#define TPM2_STATUS                              TPM_STATUS_REG(TPM2)
#define TPM2_C0SC                                TPM_CnSC_REG(TPM2,0)
#define TPM2_C0V                                 TPM_CnV_REG(TPM2,0)
#define TPM2_C1SC                                TPM_CnSC_REG(TPM2,1)
#define TPM2_C1V                                 TPM_CnV_REG(TPM2,1)
#define TPM2_COMBINE                             TPM_COMBINE_REG(TPM2)
#define TPM2_TRIG                                TPM_TRIG_REG(TPM2)
#define TPM2_POL                                 TPM_POL_REG(TPM2)
#define TPM2_FILTER                              TPM_FILTER_REG(TPM2)
#define TPM2_QDCTRL                              TPM_QDCTRL_REG(TPM2)
#define TPM2_CONF                                TPM_CONF_REG(TPM2)

/* TPM - Register array accessors */
#define TPM0_CnSC(index)                         TPM_CnSC_REG(TPM0,index)
#define TPM1_CnSC(index)                         TPM_CnSC_REG(TPM1,index)
#define TPM2_CnSC(index)                         TPM_CnSC_REG(TPM2,index)
#define TPM0_CnV(index)                          TPM_CnV_REG(TPM0,index)
#define TPM1_CnV(index)                          TPM_CnV_REG(TPM1,index)
#define TPM2_CnV(index)                          TPM_CnV_REG(TPM2,index)

/*!
 * @}
 */ /* end of group TPM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group TPM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- TRGMUX0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX0_Peripheral_Access_Layer TRGMUX0 Peripheral Access Layer
 * @{
 */

/** TRGMUX0 - Register Layout Typedef */
typedef struct {
  __IO uint32_t TRGMUX_DMAMUX0;                    /**< TRGMUX TRGCFG Register, offset: 0x0 */
  __IO uint32_t TRGMUX_LPIT0;                      /**< TRGMUX TRGCFG Register, offset: 0x4 */
  __IO uint32_t TRGMUX_TPM2;                       /**< TRGMUX TRGCFG Register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t TRGMUX_ADC0;                       /**< TRGMUX TRGCFG Register, offset: 0x10 */
  __IO uint32_t TRGMUX_LPUART2;                    /**< TRGMUX TRGCFG Register, offset: 0x14 */
       uint8_t RESERVED_1[4];
  __IO uint32_t TRGMUX_LPI2C2;                     /**< TRGMUX TRGCFG Register, offset: 0x1C */
       uint8_t RESERVED_2[4];
  __IO uint32_t TRGMUX_LPSPI2;                     /**< TRGMUX TRGCFG Register, offset: 0x24 */
       uint8_t RESERVED_3[4];
  __IO uint32_t TRGMUX_CMP0;                       /**< TRGMUX TRGCFG Register, offset: 0x2C */
  __IO uint32_t TRGMUX_CMP1;                       /**< TRGMUX TRGCFG Register, offset: 0x30 */
  __IO uint32_t TRGMUX_DAC0;                       /**< TRGMUX TRGCFG Register, offset: 0x34 */
} TRGMUX0_Type, *TRGMUX0_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- TRGMUX0 - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX0_Register_Accessor_Macros TRGMUX0 - Register accessor macros
 * @{
 */


/* TRGMUX0 - Register accessors */
#define TRGMUX0_TRGMUX_DMAMUX0_REG(base)         ((base)->TRGMUX_DMAMUX0)
#define TRGMUX0_TRGMUX_LPIT0_REG(base)           ((base)->TRGMUX_LPIT0)
#define TRGMUX0_TRGMUX_TPM2_REG(base)            ((base)->TRGMUX_TPM2)
#define TRGMUX0_TRGMUX_ADC0_REG(base)            ((base)->TRGMUX_ADC0)
#define TRGMUX0_TRGMUX_LPUART2_REG(base)         ((base)->TRGMUX_LPUART2)
#define TRGMUX0_TRGMUX_LPI2C2_REG(base)          ((base)->TRGMUX_LPI2C2)
#define TRGMUX0_TRGMUX_LPSPI2_REG(base)          ((base)->TRGMUX_LPSPI2)
#define TRGMUX0_TRGMUX_CMP0_REG(base)            ((base)->TRGMUX_CMP0)
#define TRGMUX0_TRGMUX_CMP1_REG(base)            ((base)->TRGMUX_CMP1)
#define TRGMUX0_TRGMUX_DAC0_REG(base)            ((base)->TRGMUX_DAC0)

/*!
 * @}
 */ /* end of group TRGMUX0_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- TRGMUX0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX0_Register_Masks TRGMUX0 Register Masks
 * @{
 */

/* TRGMUX_DMAMUX0 Bit Fields */
#define TRGMUX0_TRGMUX_DMAMUX0_SEL0_MASK         0x3Fu
#define TRGMUX0_TRGMUX_DMAMUX0_SEL0_SHIFT        0
#define TRGMUX0_TRGMUX_DMAMUX0_SEL0_WIDTH        6
#define TRGMUX0_TRGMUX_DMAMUX0_SEL0(x)           (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_DMAMUX0_SEL0_SHIFT))&TRGMUX0_TRGMUX_DMAMUX0_SEL0_MASK)
#define TRGMUX0_TRGMUX_DMAMUX0_SEL1_MASK         0x3F00u
#define TRGMUX0_TRGMUX_DMAMUX0_SEL1_SHIFT        8
#define TRGMUX0_TRGMUX_DMAMUX0_SEL1_WIDTH        6
#define TRGMUX0_TRGMUX_DMAMUX0_SEL1(x)           (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_DMAMUX0_SEL1_SHIFT))&TRGMUX0_TRGMUX_DMAMUX0_SEL1_MASK)
#define TRGMUX0_TRGMUX_DMAMUX0_SEL2_MASK         0x3F0000u
#define TRGMUX0_TRGMUX_DMAMUX0_SEL2_SHIFT        16
#define TRGMUX0_TRGMUX_DMAMUX0_SEL2_WIDTH        6
#define TRGMUX0_TRGMUX_DMAMUX0_SEL2(x)           (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_DMAMUX0_SEL2_SHIFT))&TRGMUX0_TRGMUX_DMAMUX0_SEL2_MASK)
#define TRGMUX0_TRGMUX_DMAMUX0_SEL3_MASK         0x3F000000u
#define TRGMUX0_TRGMUX_DMAMUX0_SEL3_SHIFT        24
#define TRGMUX0_TRGMUX_DMAMUX0_SEL3_WIDTH        6
#define TRGMUX0_TRGMUX_DMAMUX0_SEL3(x)           (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_DMAMUX0_SEL3_SHIFT))&TRGMUX0_TRGMUX_DMAMUX0_SEL3_MASK)
#define TRGMUX0_TRGMUX_DMAMUX0_LK_MASK           0x80000000u
#define TRGMUX0_TRGMUX_DMAMUX0_LK_SHIFT          31
#define TRGMUX0_TRGMUX_DMAMUX0_LK_WIDTH          1
#define TRGMUX0_TRGMUX_DMAMUX0_LK(x)             (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_DMAMUX0_LK_SHIFT))&TRGMUX0_TRGMUX_DMAMUX0_LK_MASK)
/* TRGMUX_LPIT0 Bit Fields */
#define TRGMUX0_TRGMUX_LPIT0_SEL0_MASK           0x3Fu
#define TRGMUX0_TRGMUX_LPIT0_SEL0_SHIFT          0
#define TRGMUX0_TRGMUX_LPIT0_SEL0_WIDTH          6
#define TRGMUX0_TRGMUX_LPIT0_SEL0(x)             (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_LPIT0_SEL0_SHIFT))&TRGMUX0_TRGMUX_LPIT0_SEL0_MASK)
#define TRGMUX0_TRGMUX_LPIT0_SEL1_MASK           0x3F00u
#define TRGMUX0_TRGMUX_LPIT0_SEL1_SHIFT          8
#define TRGMUX0_TRGMUX_LPIT0_SEL1_WIDTH          6
#define TRGMUX0_TRGMUX_LPIT0_SEL1(x)             (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_LPIT0_SEL1_SHIFT))&TRGMUX0_TRGMUX_LPIT0_SEL1_MASK)
#define TRGMUX0_TRGMUX_LPIT0_SEL2_MASK           0x3F0000u
#define TRGMUX0_TRGMUX_LPIT0_SEL2_SHIFT          16
#define TRGMUX0_TRGMUX_LPIT0_SEL2_WIDTH          6
#define TRGMUX0_TRGMUX_LPIT0_SEL2(x)             (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_LPIT0_SEL2_SHIFT))&TRGMUX0_TRGMUX_LPIT0_SEL2_MASK)
#define TRGMUX0_TRGMUX_LPIT0_SEL3_MASK           0x3F000000u
#define TRGMUX0_TRGMUX_LPIT0_SEL3_SHIFT          24
#define TRGMUX0_TRGMUX_LPIT0_SEL3_WIDTH          6
#define TRGMUX0_TRGMUX_LPIT0_SEL3(x)             (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_LPIT0_SEL3_SHIFT))&TRGMUX0_TRGMUX_LPIT0_SEL3_MASK)
#define TRGMUX0_TRGMUX_LPIT0_LK_MASK             0x80000000u
#define TRGMUX0_TRGMUX_LPIT0_LK_SHIFT            31
#define TRGMUX0_TRGMUX_LPIT0_LK_WIDTH            1
#define TRGMUX0_TRGMUX_LPIT0_LK(x)               (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_LPIT0_LK_SHIFT))&TRGMUX0_TRGMUX_LPIT0_LK_MASK)
/* TRGMUX_TPM2 Bit Fields */
#define TRGMUX0_TRGMUX_TPM2_SEL0_MASK            0x3Fu
#define TRGMUX0_TRGMUX_TPM2_SEL0_SHIFT           0
#define TRGMUX0_TRGMUX_TPM2_SEL0_WIDTH           6
#define TRGMUX0_TRGMUX_TPM2_SEL0(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_TPM2_SEL0_SHIFT))&TRGMUX0_TRGMUX_TPM2_SEL0_MASK)
#define TRGMUX0_TRGMUX_TPM2_SEL1_MASK            0x3F00u
#define TRGMUX0_TRGMUX_TPM2_SEL1_SHIFT           8
#define TRGMUX0_TRGMUX_TPM2_SEL1_WIDTH           6
#define TRGMUX0_TRGMUX_TPM2_SEL1(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_TPM2_SEL1_SHIFT))&TRGMUX0_TRGMUX_TPM2_SEL1_MASK)
#define TRGMUX0_TRGMUX_TPM2_SEL2_MASK            0x3F0000u
#define TRGMUX0_TRGMUX_TPM2_SEL2_SHIFT           16
#define TRGMUX0_TRGMUX_TPM2_SEL2_WIDTH           6
#define TRGMUX0_TRGMUX_TPM2_SEL2(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_TPM2_SEL2_SHIFT))&TRGMUX0_TRGMUX_TPM2_SEL2_MASK)
#define TRGMUX0_TRGMUX_TPM2_LK_MASK              0x80000000u
#define TRGMUX0_TRGMUX_TPM2_LK_SHIFT             31
#define TRGMUX0_TRGMUX_TPM2_LK_WIDTH             1
#define TRGMUX0_TRGMUX_TPM2_LK(x)                (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_TPM2_LK_SHIFT))&TRGMUX0_TRGMUX_TPM2_LK_MASK)
/* TRGMUX_ADC0 Bit Fields */
#define TRGMUX0_TRGMUX_ADC0_SEL0_MASK            0x3Fu
#define TRGMUX0_TRGMUX_ADC0_SEL0_SHIFT           0
#define TRGMUX0_TRGMUX_ADC0_SEL0_WIDTH           6
#define TRGMUX0_TRGMUX_ADC0_SEL0(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_ADC0_SEL0_SHIFT))&TRGMUX0_TRGMUX_ADC0_SEL0_MASK)
#define TRGMUX0_TRGMUX_ADC0_SEL1_MASK            0x3F00u
#define TRGMUX0_TRGMUX_ADC0_SEL1_SHIFT           8
#define TRGMUX0_TRGMUX_ADC0_SEL1_WIDTH           6
#define TRGMUX0_TRGMUX_ADC0_SEL1(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_ADC0_SEL1_SHIFT))&TRGMUX0_TRGMUX_ADC0_SEL1_MASK)
#define TRGMUX0_TRGMUX_ADC0_LK_MASK              0x80000000u
#define TRGMUX0_TRGMUX_ADC0_LK_SHIFT             31
#define TRGMUX0_TRGMUX_ADC0_LK_WIDTH             1
#define TRGMUX0_TRGMUX_ADC0_LK(x)                (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_ADC0_LK_SHIFT))&TRGMUX0_TRGMUX_ADC0_LK_MASK)
/* TRGMUX_LPUART2 Bit Fields */
#define TRGMUX0_TRGMUX_LPUART2_SEL0_MASK         0x3Fu
#define TRGMUX0_TRGMUX_LPUART2_SEL0_SHIFT        0
#define TRGMUX0_TRGMUX_LPUART2_SEL0_WIDTH        6
#define TRGMUX0_TRGMUX_LPUART2_SEL0(x)           (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_LPUART2_SEL0_SHIFT))&TRGMUX0_TRGMUX_LPUART2_SEL0_MASK)
#define TRGMUX0_TRGMUX_LPUART2_LK_MASK           0x80000000u
#define TRGMUX0_TRGMUX_LPUART2_LK_SHIFT          31
#define TRGMUX0_TRGMUX_LPUART2_LK_WIDTH          1
#define TRGMUX0_TRGMUX_LPUART2_LK(x)             (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_LPUART2_LK_SHIFT))&TRGMUX0_TRGMUX_LPUART2_LK_MASK)
/* TRGMUX_LPI2C2 Bit Fields */
#define TRGMUX0_TRGMUX_LPI2C2_SEL0_MASK          0x3Fu
#define TRGMUX0_TRGMUX_LPI2C2_SEL0_SHIFT         0
#define TRGMUX0_TRGMUX_LPI2C2_SEL0_WIDTH         6
#define TRGMUX0_TRGMUX_LPI2C2_SEL0(x)            (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_LPI2C2_SEL0_SHIFT))&TRGMUX0_TRGMUX_LPI2C2_SEL0_MASK)
#define TRGMUX0_TRGMUX_LPI2C2_LK_MASK            0x80000000u
#define TRGMUX0_TRGMUX_LPI2C2_LK_SHIFT           31
#define TRGMUX0_TRGMUX_LPI2C2_LK_WIDTH           1
#define TRGMUX0_TRGMUX_LPI2C2_LK(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_LPI2C2_LK_SHIFT))&TRGMUX0_TRGMUX_LPI2C2_LK_MASK)
/* TRGMUX_LPSPI2 Bit Fields */
#define TRGMUX0_TRGMUX_LPSPI2_SEL0_MASK          0x3Fu
#define TRGMUX0_TRGMUX_LPSPI2_SEL0_SHIFT         0
#define TRGMUX0_TRGMUX_LPSPI2_SEL0_WIDTH         6
#define TRGMUX0_TRGMUX_LPSPI2_SEL0(x)            (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_LPSPI2_SEL0_SHIFT))&TRGMUX0_TRGMUX_LPSPI2_SEL0_MASK)
#define TRGMUX0_TRGMUX_LPSPI2_LK_MASK            0x80000000u
#define TRGMUX0_TRGMUX_LPSPI2_LK_SHIFT           31
#define TRGMUX0_TRGMUX_LPSPI2_LK_WIDTH           1
#define TRGMUX0_TRGMUX_LPSPI2_LK(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_LPSPI2_LK_SHIFT))&TRGMUX0_TRGMUX_LPSPI2_LK_MASK)
/* TRGMUX_CMP0 Bit Fields */
#define TRGMUX0_TRGMUX_CMP0_SEL0_MASK            0x3Fu
#define TRGMUX0_TRGMUX_CMP0_SEL0_SHIFT           0
#define TRGMUX0_TRGMUX_CMP0_SEL0_WIDTH           6
#define TRGMUX0_TRGMUX_CMP0_SEL0(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_CMP0_SEL0_SHIFT))&TRGMUX0_TRGMUX_CMP0_SEL0_MASK)
#define TRGMUX0_TRGMUX_CMP0_LK_MASK              0x80000000u
#define TRGMUX0_TRGMUX_CMP0_LK_SHIFT             31
#define TRGMUX0_TRGMUX_CMP0_LK_WIDTH             1
#define TRGMUX0_TRGMUX_CMP0_LK(x)                (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_CMP0_LK_SHIFT))&TRGMUX0_TRGMUX_CMP0_LK_MASK)
/* TRGMUX_CMP1 Bit Fields */
#define TRGMUX0_TRGMUX_CMP1_SEL0_MASK            0x3Fu
#define TRGMUX0_TRGMUX_CMP1_SEL0_SHIFT           0
#define TRGMUX0_TRGMUX_CMP1_SEL0_WIDTH           6
#define TRGMUX0_TRGMUX_CMP1_SEL0(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_CMP1_SEL0_SHIFT))&TRGMUX0_TRGMUX_CMP1_SEL0_MASK)
#define TRGMUX0_TRGMUX_CMP1_LK_MASK              0x80000000u
#define TRGMUX0_TRGMUX_CMP1_LK_SHIFT             31
#define TRGMUX0_TRGMUX_CMP1_LK_WIDTH             1
#define TRGMUX0_TRGMUX_CMP1_LK(x)                (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_CMP1_LK_SHIFT))&TRGMUX0_TRGMUX_CMP1_LK_MASK)
/* TRGMUX_DAC0 Bit Fields */
#define TRGMUX0_TRGMUX_DAC0_SEL0_MASK            0x3Fu
#define TRGMUX0_TRGMUX_DAC0_SEL0_SHIFT           0
#define TRGMUX0_TRGMUX_DAC0_SEL0_WIDTH           6
#define TRGMUX0_TRGMUX_DAC0_SEL0(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_DAC0_SEL0_SHIFT))&TRGMUX0_TRGMUX_DAC0_SEL0_MASK)
#define TRGMUX0_TRGMUX_DAC0_LK_MASK              0x80000000u
#define TRGMUX0_TRGMUX_DAC0_LK_SHIFT             31
#define TRGMUX0_TRGMUX_DAC0_LK_WIDTH             1
#define TRGMUX0_TRGMUX_DAC0_LK(x)                (((uint32_t)(((uint32_t)(x))<<TRGMUX0_TRGMUX_DAC0_LK_SHIFT))&TRGMUX0_TRGMUX_DAC0_LK_MASK)

/*!
 * @}
 */ /* end of group TRGMUX0_Register_Masks */


/* TRGMUX0 - Peripheral instance base addresses */
/** Peripheral TRGMUX0 base address */
#define TRGMUX0_BASE                             (0x40027000u)
/** Peripheral TRGMUX0 base pointer */
#define TRGMUX0                                  ((TRGMUX0_Type *)TRGMUX0_BASE)
#define TRGMUX0_BASE_PTR                         (TRGMUX0)
/** Array initializer of TRGMUX0 peripheral base addresses */
#define TRGMUX0_BASE_ADDRS                       { TRGMUX0_BASE }
/** Array initializer of TRGMUX0 peripheral base pointers */
#define TRGMUX0_BASE_PTRS                        { TRGMUX0 }

/* ----------------------------------------------------------------------------
   -- TRGMUX0 - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX0_Register_Accessor_Macros TRGMUX0 - Register accessor macros
 * @{
 */


/* TRGMUX0 - Register instance definitions */
/* TRGMUX0 */
#define TRGMUX_TRGMUX_DMAMUX0                    TRGMUX0_TRGMUX_DMAMUX0_REG(TRGMUX0)
#define TRGMUX_TRGMUX_LPIT0                      TRGMUX0_TRGMUX_LPIT0_REG(TRGMUX0)
#define TRGMUX_TRGMUX_TPM2                       TRGMUX0_TRGMUX_TPM2_REG(TRGMUX0)
#define TRGMUX_TRGMUX_ADC0                       TRGMUX0_TRGMUX_ADC0_REG(TRGMUX0)
#define TRGMUX_TRGMUX_LPUART2                    TRGMUX0_TRGMUX_LPUART2_REG(TRGMUX0)
#define TRGMUX_TRGMUX_LPI2C2                     TRGMUX0_TRGMUX_LPI2C2_REG(TRGMUX0)
#define TRGMUX_TRGMUX_LPSPI2                     TRGMUX0_TRGMUX_LPSPI2_REG(TRGMUX0)
#define TRGMUX_TRGMUX_CMP0                       TRGMUX0_TRGMUX_CMP0_REG(TRGMUX0)
#define TRGMUX_TRGMUX_CMP1                       TRGMUX0_TRGMUX_CMP1_REG(TRGMUX0)
#define TRGMUX_TRGMUX_DAC0                       TRGMUX0_TRGMUX_DAC0_REG(TRGMUX0)

/*!
 * @}
 */ /* end of group TRGMUX0_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group TRGMUX0_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- TRGMUX1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX1_Peripheral_Access_Layer TRGMUX1 Peripheral Access Layer
 * @{
 */

/** TRGMUX1 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __IO uint32_t TRGMUX_TPM0;                       /**< TRGMUX TRGCFG Register, offset: 0x8 */
  __IO uint32_t TRGMUX_TPM1;                       /**< TRGMUX TRGCFG Register, offset: 0xC */
  __IO uint32_t TRGMUX_FLEXIO0;                    /**< TRGMUX TRGCFG Register, offset: 0x10 */
  __IO uint32_t TRGMUX_LPUART0;                    /**< TRGMUX TRGCFG Register, offset: 0x14 */
  __IO uint32_t TRGMUX_LPUART1;                    /**< TRGMUX TRGCFG Register, offset: 0x18 */
  __IO uint32_t TRGMUX_LPI2C0;                     /**< TRGMUX TRGCFG Register, offset: 0x1C */
  __IO uint32_t TRGMUX_LPI2C1;                     /**< TRGMUX TRGCFG Register, offset: 0x20 */
  __IO uint32_t TRGMUX_LPSPI0;                     /**< TRGMUX TRGCFG Register, offset: 0x24 */
  __IO uint32_t TRGMUX_LPSPI1;                     /**< TRGMUX TRGCFG Register, offset: 0x28 */
} TRGMUX1_Type, *TRGMUX1_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- TRGMUX1 - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX1_Register_Accessor_Macros TRGMUX1 - Register accessor macros
 * @{
 */


/* TRGMUX1 - Register accessors */
#define TRGMUX1_TRGMUX_TPM0_REG(base)            ((base)->TRGMUX_TPM0)
#define TRGMUX1_TRGMUX_TPM1_REG(base)            ((base)->TRGMUX_TPM1)
#define TRGMUX1_TRGMUX_FLEXIO0_REG(base)         ((base)->TRGMUX_FLEXIO0)
#define TRGMUX1_TRGMUX_LPUART0_REG(base)         ((base)->TRGMUX_LPUART0)
#define TRGMUX1_TRGMUX_LPUART1_REG(base)         ((base)->TRGMUX_LPUART1)
#define TRGMUX1_TRGMUX_LPI2C0_REG(base)          ((base)->TRGMUX_LPI2C0)
#define TRGMUX1_TRGMUX_LPI2C1_REG(base)          ((base)->TRGMUX_LPI2C1)
#define TRGMUX1_TRGMUX_LPSPI0_REG(base)          ((base)->TRGMUX_LPSPI0)
#define TRGMUX1_TRGMUX_LPSPI1_REG(base)          ((base)->TRGMUX_LPSPI1)

/*!
 * @}
 */ /* end of group TRGMUX1_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- TRGMUX1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX1_Register_Masks TRGMUX1 Register Masks
 * @{
 */

/* TRGMUX_TPM0 Bit Fields */
#define TRGMUX1_TRGMUX_TPM0_SEL0_MASK            0x3Fu
#define TRGMUX1_TRGMUX_TPM0_SEL0_SHIFT           0
#define TRGMUX1_TRGMUX_TPM0_SEL0_WIDTH           6
#define TRGMUX1_TRGMUX_TPM0_SEL0(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_TPM0_SEL0_SHIFT))&TRGMUX1_TRGMUX_TPM0_SEL0_MASK)
#define TRGMUX1_TRGMUX_TPM0_SEL1_MASK            0x3F00u
#define TRGMUX1_TRGMUX_TPM0_SEL1_SHIFT           8
#define TRGMUX1_TRGMUX_TPM0_SEL1_WIDTH           6
#define TRGMUX1_TRGMUX_TPM0_SEL1(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_TPM0_SEL1_SHIFT))&TRGMUX1_TRGMUX_TPM0_SEL1_MASK)
#define TRGMUX1_TRGMUX_TPM0_SEL2_MASK            0x3F0000u
#define TRGMUX1_TRGMUX_TPM0_SEL2_SHIFT           16
#define TRGMUX1_TRGMUX_TPM0_SEL2_WIDTH           6
#define TRGMUX1_TRGMUX_TPM0_SEL2(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_TPM0_SEL2_SHIFT))&TRGMUX1_TRGMUX_TPM0_SEL2_MASK)
#define TRGMUX1_TRGMUX_TPM0_LK_MASK              0x80000000u
#define TRGMUX1_TRGMUX_TPM0_LK_SHIFT             31
#define TRGMUX1_TRGMUX_TPM0_LK_WIDTH             1
#define TRGMUX1_TRGMUX_TPM0_LK(x)                (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_TPM0_LK_SHIFT))&TRGMUX1_TRGMUX_TPM0_LK_MASK)
/* TRGMUX_TPM1 Bit Fields */
#define TRGMUX1_TRGMUX_TPM1_SEL0_MASK            0x3Fu
#define TRGMUX1_TRGMUX_TPM1_SEL0_SHIFT           0
#define TRGMUX1_TRGMUX_TPM1_SEL0_WIDTH           6
#define TRGMUX1_TRGMUX_TPM1_SEL0(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_TPM1_SEL0_SHIFT))&TRGMUX1_TRGMUX_TPM1_SEL0_MASK)
#define TRGMUX1_TRGMUX_TPM1_SEL1_MASK            0x3F00u
#define TRGMUX1_TRGMUX_TPM1_SEL1_SHIFT           8
#define TRGMUX1_TRGMUX_TPM1_SEL1_WIDTH           6
#define TRGMUX1_TRGMUX_TPM1_SEL1(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_TPM1_SEL1_SHIFT))&TRGMUX1_TRGMUX_TPM1_SEL1_MASK)
#define TRGMUX1_TRGMUX_TPM1_SEL2_MASK            0x3F0000u
#define TRGMUX1_TRGMUX_TPM1_SEL2_SHIFT           16
#define TRGMUX1_TRGMUX_TPM1_SEL2_WIDTH           6
#define TRGMUX1_TRGMUX_TPM1_SEL2(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_TPM1_SEL2_SHIFT))&TRGMUX1_TRGMUX_TPM1_SEL2_MASK)
#define TRGMUX1_TRGMUX_TPM1_LK_MASK              0x80000000u
#define TRGMUX1_TRGMUX_TPM1_LK_SHIFT             31
#define TRGMUX1_TRGMUX_TPM1_LK_WIDTH             1
#define TRGMUX1_TRGMUX_TPM1_LK(x)                (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_TPM1_LK_SHIFT))&TRGMUX1_TRGMUX_TPM1_LK_MASK)
/* TRGMUX_FLEXIO0 Bit Fields */
#define TRGMUX1_TRGMUX_FLEXIO0_SEL0_MASK         0x3Fu
#define TRGMUX1_TRGMUX_FLEXIO0_SEL0_SHIFT        0
#define TRGMUX1_TRGMUX_FLEXIO0_SEL0_WIDTH        6
#define TRGMUX1_TRGMUX_FLEXIO0_SEL0(x)           (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_FLEXIO0_SEL0_SHIFT))&TRGMUX1_TRGMUX_FLEXIO0_SEL0_MASK)
#define TRGMUX1_TRGMUX_FLEXIO0_SEL1_MASK         0x3F00u
#define TRGMUX1_TRGMUX_FLEXIO0_SEL1_SHIFT        8
#define TRGMUX1_TRGMUX_FLEXIO0_SEL1_WIDTH        6
#define TRGMUX1_TRGMUX_FLEXIO0_SEL1(x)           (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_FLEXIO0_SEL1_SHIFT))&TRGMUX1_TRGMUX_FLEXIO0_SEL1_MASK)
#define TRGMUX1_TRGMUX_FLEXIO0_SEL2_MASK         0x3F0000u
#define TRGMUX1_TRGMUX_FLEXIO0_SEL2_SHIFT        16
#define TRGMUX1_TRGMUX_FLEXIO0_SEL2_WIDTH        6
#define TRGMUX1_TRGMUX_FLEXIO0_SEL2(x)           (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_FLEXIO0_SEL2_SHIFT))&TRGMUX1_TRGMUX_FLEXIO0_SEL2_MASK)
#define TRGMUX1_TRGMUX_FLEXIO0_SEL3_MASK         0x3F000000u
#define TRGMUX1_TRGMUX_FLEXIO0_SEL3_SHIFT        24
#define TRGMUX1_TRGMUX_FLEXIO0_SEL3_WIDTH        6
#define TRGMUX1_TRGMUX_FLEXIO0_SEL3(x)           (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_FLEXIO0_SEL3_SHIFT))&TRGMUX1_TRGMUX_FLEXIO0_SEL3_MASK)
#define TRGMUX1_TRGMUX_FLEXIO0_LK_MASK           0x80000000u
#define TRGMUX1_TRGMUX_FLEXIO0_LK_SHIFT          31
#define TRGMUX1_TRGMUX_FLEXIO0_LK_WIDTH          1
#define TRGMUX1_TRGMUX_FLEXIO0_LK(x)             (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_FLEXIO0_LK_SHIFT))&TRGMUX1_TRGMUX_FLEXIO0_LK_MASK)
/* TRGMUX_LPUART0 Bit Fields */
#define TRGMUX1_TRGMUX_LPUART0_SEL0_MASK         0x3Fu
#define TRGMUX1_TRGMUX_LPUART0_SEL0_SHIFT        0
#define TRGMUX1_TRGMUX_LPUART0_SEL0_WIDTH        6
#define TRGMUX1_TRGMUX_LPUART0_SEL0(x)           (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_LPUART0_SEL0_SHIFT))&TRGMUX1_TRGMUX_LPUART0_SEL0_MASK)
#define TRGMUX1_TRGMUX_LPUART0_LK_MASK           0x80000000u
#define TRGMUX1_TRGMUX_LPUART0_LK_SHIFT          31
#define TRGMUX1_TRGMUX_LPUART0_LK_WIDTH          1
#define TRGMUX1_TRGMUX_LPUART0_LK(x)             (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_LPUART0_LK_SHIFT))&TRGMUX1_TRGMUX_LPUART0_LK_MASK)
/* TRGMUX_LPUART1 Bit Fields */
#define TRGMUX1_TRGMUX_LPUART1_SEL0_MASK         0x3Fu
#define TRGMUX1_TRGMUX_LPUART1_SEL0_SHIFT        0
#define TRGMUX1_TRGMUX_LPUART1_SEL0_WIDTH        6
#define TRGMUX1_TRGMUX_LPUART1_SEL0(x)           (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_LPUART1_SEL0_SHIFT))&TRGMUX1_TRGMUX_LPUART1_SEL0_MASK)
#define TRGMUX1_TRGMUX_LPUART1_LK_MASK           0x80000000u
#define TRGMUX1_TRGMUX_LPUART1_LK_SHIFT          31
#define TRGMUX1_TRGMUX_LPUART1_LK_WIDTH          1
#define TRGMUX1_TRGMUX_LPUART1_LK(x)             (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_LPUART1_LK_SHIFT))&TRGMUX1_TRGMUX_LPUART1_LK_MASK)
/* TRGMUX_LPI2C0 Bit Fields */
#define TRGMUX1_TRGMUX_LPI2C0_SEL0_MASK          0x3Fu
#define TRGMUX1_TRGMUX_LPI2C0_SEL0_SHIFT         0
#define TRGMUX1_TRGMUX_LPI2C0_SEL0_WIDTH         6
#define TRGMUX1_TRGMUX_LPI2C0_SEL0(x)            (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_LPI2C0_SEL0_SHIFT))&TRGMUX1_TRGMUX_LPI2C0_SEL0_MASK)
#define TRGMUX1_TRGMUX_LPI2C0_LK_MASK            0x80000000u
#define TRGMUX1_TRGMUX_LPI2C0_LK_SHIFT           31
#define TRGMUX1_TRGMUX_LPI2C0_LK_WIDTH           1
#define TRGMUX1_TRGMUX_LPI2C0_LK(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_LPI2C0_LK_SHIFT))&TRGMUX1_TRGMUX_LPI2C0_LK_MASK)
/* TRGMUX_LPI2C1 Bit Fields */
#define TRGMUX1_TRGMUX_LPI2C1_SEL0_MASK          0x3Fu
#define TRGMUX1_TRGMUX_LPI2C1_SEL0_SHIFT         0
#define TRGMUX1_TRGMUX_LPI2C1_SEL0_WIDTH         6
#define TRGMUX1_TRGMUX_LPI2C1_SEL0(x)            (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_LPI2C1_SEL0_SHIFT))&TRGMUX1_TRGMUX_LPI2C1_SEL0_MASK)
#define TRGMUX1_TRGMUX_LPI2C1_LK_MASK            0x80000000u
#define TRGMUX1_TRGMUX_LPI2C1_LK_SHIFT           31
#define TRGMUX1_TRGMUX_LPI2C1_LK_WIDTH           1
#define TRGMUX1_TRGMUX_LPI2C1_LK(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_LPI2C1_LK_SHIFT))&TRGMUX1_TRGMUX_LPI2C1_LK_MASK)
/* TRGMUX_LPSPI0 Bit Fields */
#define TRGMUX1_TRGMUX_LPSPI0_SEL0_MASK          0x3Fu
#define TRGMUX1_TRGMUX_LPSPI0_SEL0_SHIFT         0
#define TRGMUX1_TRGMUX_LPSPI0_SEL0_WIDTH         6
#define TRGMUX1_TRGMUX_LPSPI0_SEL0(x)            (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_LPSPI0_SEL0_SHIFT))&TRGMUX1_TRGMUX_LPSPI0_SEL0_MASK)
#define TRGMUX1_TRGMUX_LPSPI0_LK_MASK            0x80000000u
#define TRGMUX1_TRGMUX_LPSPI0_LK_SHIFT           31
#define TRGMUX1_TRGMUX_LPSPI0_LK_WIDTH           1
#define TRGMUX1_TRGMUX_LPSPI0_LK(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_LPSPI0_LK_SHIFT))&TRGMUX1_TRGMUX_LPSPI0_LK_MASK)
/* TRGMUX_LPSPI1 Bit Fields */
#define TRGMUX1_TRGMUX_LPSPI1_SEL0_MASK          0x3Fu
#define TRGMUX1_TRGMUX_LPSPI1_SEL0_SHIFT         0
#define TRGMUX1_TRGMUX_LPSPI1_SEL0_WIDTH         6
#define TRGMUX1_TRGMUX_LPSPI1_SEL0(x)            (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_LPSPI1_SEL0_SHIFT))&TRGMUX1_TRGMUX_LPSPI1_SEL0_MASK)
#define TRGMUX1_TRGMUX_LPSPI1_LK_MASK            0x80000000u
#define TRGMUX1_TRGMUX_LPSPI1_LK_SHIFT           31
#define TRGMUX1_TRGMUX_LPSPI1_LK_WIDTH           1
#define TRGMUX1_TRGMUX_LPSPI1_LK(x)              (((uint32_t)(((uint32_t)(x))<<TRGMUX1_TRGMUX_LPSPI1_LK_SHIFT))&TRGMUX1_TRGMUX_LPSPI1_LK_MASK)

/*!
 * @}
 */ /* end of group TRGMUX1_Register_Masks */


/* TRGMUX1 - Peripheral instance base addresses */
/** Peripheral TRGMUX1 base address */
#define TRGMUX1_BASE                             (0x400A7000u)
/** Peripheral TRGMUX1 base pointer */
#define TRGMUX1                                  ((TRGMUX1_Type *)TRGMUX1_BASE)
#define TRGMUX1_BASE_PTR                         (TRGMUX1)
/** Array initializer of TRGMUX1 peripheral base addresses */
#define TRGMUX1_BASE_ADDRS                       { TRGMUX1_BASE }
/** Array initializer of TRGMUX1 peripheral base pointers */
#define TRGMUX1_BASE_PTRS                        { TRGMUX1 }

/* ----------------------------------------------------------------------------
   -- TRGMUX1 - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX1_Register_Accessor_Macros TRGMUX1 - Register accessor macros
 * @{
 */


/* TRGMUX1 - Register instance definitions */
/* TRGMUX1 */
#define TRGMUX_TRGMUX_TPM0                       TRGMUX1_TRGMUX_TPM0_REG(TRGMUX1)
#define TRGMUX_TRGMUX_TPM1                       TRGMUX1_TRGMUX_TPM1_REG(TRGMUX1)
#define TRGMUX_TRGMUX_FLEXIO0                    TRGMUX1_TRGMUX_FLEXIO0_REG(TRGMUX1)
#define TRGMUX_TRGMUX_LPUART0                    TRGMUX1_TRGMUX_LPUART0_REG(TRGMUX1)
#define TRGMUX_TRGMUX_LPUART1                    TRGMUX1_TRGMUX_LPUART1_REG(TRGMUX1)
#define TRGMUX_TRGMUX_LPI2C0                     TRGMUX1_TRGMUX_LPI2C0_REG(TRGMUX1)
#define TRGMUX_TRGMUX_LPI2C1                     TRGMUX1_TRGMUX_LPI2C1_REG(TRGMUX1)
#define TRGMUX_TRGMUX_LPSPI0                     TRGMUX1_TRGMUX_LPSPI0_REG(TRGMUX1)
#define TRGMUX_TRGMUX_LPSPI1                     TRGMUX1_TRGMUX_LPSPI1_REG(TRGMUX1)

/*!
 * @}
 */ /* end of group TRGMUX1_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group TRGMUX1_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- TRNG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRNG_Peripheral_Access_Layer TRNG Peripheral Access Layer
 * @{
 */

/** TRNG - Register Layout Typedef */
typedef struct {
  __IO uint32_t RTMCTL;                            /**< RNG Miscellaneous Control Register, offset: 0x0 */
  __IO uint32_t RTSCMISC;                          /**< RNG Statistical Check Miscellaneous Register, offset: 0x4 */
  __IO uint32_t RTPKRRNG;                          /**< RNG Poker Range Register, offset: 0x8 */
  union {                                          /* offset: 0xC */
    __IO uint32_t RTPKRMAX;                          /**< RNG Poker Maximum Limit Register, offset: 0xC */
    __I  uint32_t RTPKRSQ;                           /**< RNG Poker Square Calculation Result Register, offset: 0xC */
  };
  __IO uint32_t RTSDCTL;                           /**< RNG Seed Control Register, offset: 0x10 */
  union {                                          /* offset: 0x14 */
    __IO uint32_t RTSBLIM;                           /**< RNG Sparse Bit Limit Register, offset: 0x14 */
    __I  uint32_t RTTOTSAM;                          /**< RNG Total Samples Register, offset: 0x14 */
  };
  __IO uint32_t RTFRQMIN;                          /**< RNG Frequency Count Minimum Limit Register, offset: 0x18 */
  union {                                          /* offset: 0x1C */
    __I  uint32_t RTFRQCNT;                          /**< RNG Frequency Count Register, offset: 0x1C */
    __IO uint32_t RTFRQMAX;                          /**< RNG Frequency Count Maximum Limit Register, offset: 0x1C */
  };
  union {                                          /* offset: 0x20 */
    __I  uint32_t RTSCMC;                            /**< RNG Statistical Check Monobit Count Register, offset: 0x20 */
    __IO uint32_t RTSCML;                            /**< RNG Statistical Check Monobit Limit Register, offset: 0x20 */
  };
  union {                                          /* offset: 0x24 */
    __I  uint32_t RTSCR1C;                           /**< RNG Statistical Check Run Length 1 Count Register, offset: 0x24 */
    __IO uint32_t RTSCR1L;                           /**< RNG Statistical Check Run Length 1 Limit Register, offset: 0x24 */
  };
  union {                                          /* offset: 0x28 */
    __I  uint32_t RTSCR2C;                           /**< RNG Statistical Check Run Length 2 Count Register, offset: 0x28 */
    __IO uint32_t RTSCR2L;                           /**< RNG Statistical Check Run Length 2 Limit Register, offset: 0x28 */
  };
  union {                                          /* offset: 0x2C */
    __I  uint32_t RTSCR3C;                           /**< RNG Statistical Check Run Length 3 Count Register, offset: 0x2C */
    __IO uint32_t RTSCR3L;                           /**< RNG Statistical Check Run Length 3 Limit Register, offset: 0x2C */
  };
  union {                                          /* offset: 0x30 */
    __I  uint32_t RTSCR4C;                           /**< RNG Statistical Check Run Length 4 Count Register, offset: 0x30 */
    __IO uint32_t RTSCR4L;                           /**< RNG Statistical Check Run Length 4 Limit Register, offset: 0x30 */
  };
  union {                                          /* offset: 0x34 */
    __I  uint32_t RTSCR5C;                           /**< RNG Statistical Check Run Length 5 Count Register, offset: 0x34 */
    __IO uint32_t RTSCR5L;                           /**< RNG Statistical Check Run Length 5 Limit Register, offset: 0x34 */
  };
  union {                                          /* offset: 0x38 */
    __I  uint32_t RTSCR6PC;                          /**< RNG Statistical Check Run Length 6+ Count Register, offset: 0x38 */
    __IO uint32_t RTSCR6PL;                          /**< RNG Statistical Check Run Length 6+ Limit Register, offset: 0x38 */
  };
  __I  uint32_t RTSTATUS;                          /**< RNG Status Register, offset: 0x3C */
  __I  uint32_t RTENT0;                            /**< RNG TRNG Entropy Read Register, offset: 0x40 */
  __I  uint32_t RTENT1;                            /**< RNG TRNG Entropy Read Register, offset: 0x44 */
  __I  uint32_t RTENT2;                            /**< RNG TRNG Entropy Read Register, offset: 0x48 */
  __I  uint32_t RTENT3;                            /**< RNG TRNG Entropy Read Register, offset: 0x4C */
  __I  uint32_t RTENT4;                            /**< RNG TRNG Entropy Read Register, offset: 0x50 */
  __I  uint32_t RTENT5;                            /**< RNG TRNG Entropy Read Register, offset: 0x54 */
  __I  uint32_t RTENT6;                            /**< RNG TRNG Entropy Read Register, offset: 0x58 */
  __I  uint32_t RTENT7;                            /**< RNG TRNG Entropy Read Register, offset: 0x5C */
  __I  uint32_t RTENT8;                            /**< RNG TRNG Entropy Read Register, offset: 0x60 */
  __I  uint32_t RTENT9;                            /**< RNG TRNG Entropy Read Register, offset: 0x64 */
  __I  uint32_t RTENT10;                           /**< RNG TRNG Entropy Read Register, offset: 0x68 */
  __I  uint32_t RTENT11;                           /**< RNG TRNG Entropy Read Register, offset: 0x6C */
  __I  uint32_t RTENT12;                           /**< RNG TRNG Entropy Read Register, offset: 0x70 */
  __I  uint32_t RTENT13;                           /**< RNG TRNG Entropy Read Register, offset: 0x74 */
  __I  uint32_t RTENT14;                           /**< RNG TRNG Entropy Read Register, offset: 0x78 */
  __I  uint32_t RTENT15;                           /**< RNG TRNG Entropy Read Register, offset: 0x7C */
  __I  uint32_t RTPKRCNT10;                        /**< RNG Statistical Check Poker Count 1 and 0 Register, offset: 0x80 */
  __I  uint32_t RTPKRCNT32;                        /**< RNG Statistical Check Poker Count 3 and 2 Register, offset: 0x84 */
  __I  uint32_t RTPKRCNT54;                        /**< RNG Statistical Check Poker Count 5 and 4 Register, offset: 0x88 */
  __I  uint32_t RTPKRCNT76;                        /**< RNG Statistical Check Poker Count 7 and 6 Register, offset: 0x8C */
  __I  uint32_t RTPKRCNT98;                        /**< RNG Statistical Check Poker Count 9 and 8 Register, offset: 0x90 */
  __I  uint32_t RTPKRCNTBA;                        /**< RNG Statistical Check Poker Count B and A Register, offset: 0x94 */
  __I  uint32_t RTPKRCNTDC;                        /**< RNG Statistical Check Poker Count D and C Register, offset: 0x98 */
  __I  uint32_t RTPKRCNTFE;                        /**< RNG Statistical Check Poker Count F and E Register, offset: 0x9C */
  __IO uint32_t SA_TRNG_SEC_CFG;                   /**< RNG Security Configuration Register, offset: 0xA0 */
  __IO uint32_t SA_TRNG_INT_CTRL;                  /**< RNG Interrupt Control Register, offset: 0xA4 */
  __IO uint32_t SA_TRNG_INT_MASK;                  /**< RNG Mask Register, offset: 0xA8 */
  __IO uint32_t SA_TRNG_INT_STATUS;                /**< RNG Interrupt Status Register, offset: 0xAC */
       uint8_t RESERVED_0[64];
  __I  uint32_t SA_TRNG_VID1;                      /**< RNG Version ID Register (MS), offset: 0xF0 */
  __I  uint32_t SA_TRNG_VID2;                      /**< RNG Version ID Register (LS), offset: 0xF4 */
} TRNG_Type, *TRNG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- TRNG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRNG_Register_Accessor_Macros TRNG - Register accessor macros
 * @{
 */


/* TRNG - Register accessors */
#define TRNG_RTMCTL_REG(base)                    ((base)->RTMCTL)
#define TRNG_RTSCMISC_REG(base)                  ((base)->RTSCMISC)
#define TRNG_RTPKRRNG_REG(base)                  ((base)->RTPKRRNG)
#define TRNG_RTPKRMAX_REG(base)                  ((base)->RTPKRMAX)
#define TRNG_RTPKRSQ_REG(base)                   ((base)->RTPKRSQ)
#define TRNG_RTSDCTL_REG(base)                   ((base)->RTSDCTL)
#define TRNG_RTSBLIM_REG(base)                   ((base)->RTSBLIM)
#define TRNG_RTTOTSAM_REG(base)                  ((base)->RTTOTSAM)
#define TRNG_RTFRQMIN_REG(base)                  ((base)->RTFRQMIN)
#define TRNG_RTFRQCNT_REG(base)                  ((base)->RTFRQCNT)
#define TRNG_RTFRQMAX_REG(base)                  ((base)->RTFRQMAX)
#define TRNG_RTSCMC_REG(base)                    ((base)->RTSCMC)
#define TRNG_RTSCML_REG(base)                    ((base)->RTSCML)
#define TRNG_RTSCR1C_REG(base)                   ((base)->RTSCR1C)
#define TRNG_RTSCR1L_REG(base)                   ((base)->RTSCR1L)
#define TRNG_RTSCR2C_REG(base)                   ((base)->RTSCR2C)
#define TRNG_RTSCR2L_REG(base)                   ((base)->RTSCR2L)
#define TRNG_RTSCR3C_REG(base)                   ((base)->RTSCR3C)
#define TRNG_RTSCR3L_REG(base)                   ((base)->RTSCR3L)
#define TRNG_RTSCR4C_REG(base)                   ((base)->RTSCR4C)
#define TRNG_RTSCR4L_REG(base)                   ((base)->RTSCR4L)
#define TRNG_RTSCR5C_REG(base)                   ((base)->RTSCR5C)
#define TRNG_RTSCR5L_REG(base)                   ((base)->RTSCR5L)
#define TRNG_RTSCR6PC_REG(base)                  ((base)->RTSCR6PC)
#define TRNG_RTSCR6PL_REG(base)                  ((base)->RTSCR6PL)
#define TRNG_RTSTATUS_REG(base)                  ((base)->RTSTATUS)
#define TRNG_RTENT0_REG(base)                    ((base)->RTENT0)
#define TRNG_RTENT1_REG(base)                    ((base)->RTENT1)
#define TRNG_RTENT2_REG(base)                    ((base)->RTENT2)
#define TRNG_RTENT3_REG(base)                    ((base)->RTENT3)
#define TRNG_RTENT4_REG(base)                    ((base)->RTENT4)
#define TRNG_RTENT5_REG(base)                    ((base)->RTENT5)
#define TRNG_RTENT6_REG(base)                    ((base)->RTENT6)
#define TRNG_RTENT7_REG(base)                    ((base)->RTENT7)
#define TRNG_RTENT8_REG(base)                    ((base)->RTENT8)
#define TRNG_RTENT9_REG(base)                    ((base)->RTENT9)
#define TRNG_RTENT10_REG(base)                   ((base)->RTENT10)
#define TRNG_RTENT11_REG(base)                   ((base)->RTENT11)
#define TRNG_RTENT12_REG(base)                   ((base)->RTENT12)
#define TRNG_RTENT13_REG(base)                   ((base)->RTENT13)
#define TRNG_RTENT14_REG(base)                   ((base)->RTENT14)
#define TRNG_RTENT15_REG(base)                   ((base)->RTENT15)
#define TRNG_RTPKRCNT10_REG(base)                ((base)->RTPKRCNT10)
#define TRNG_RTPKRCNT32_REG(base)                ((base)->RTPKRCNT32)
#define TRNG_RTPKRCNT54_REG(base)                ((base)->RTPKRCNT54)
#define TRNG_RTPKRCNT76_REG(base)                ((base)->RTPKRCNT76)
#define TRNG_RTPKRCNT98_REG(base)                ((base)->RTPKRCNT98)
#define TRNG_RTPKRCNTBA_REG(base)                ((base)->RTPKRCNTBA)
#define TRNG_RTPKRCNTDC_REG(base)                ((base)->RTPKRCNTDC)
#define TRNG_RTPKRCNTFE_REG(base)                ((base)->RTPKRCNTFE)
#define TRNG_SA_TRNG_SEC_CFG_REG(base)           ((base)->SA_TRNG_SEC_CFG)
#define TRNG_SA_TRNG_INT_CTRL_REG(base)          ((base)->SA_TRNG_INT_CTRL)
#define TRNG_SA_TRNG_INT_MASK_REG(base)          ((base)->SA_TRNG_INT_MASK)
#define TRNG_SA_TRNG_INT_STATUS_REG(base)        ((base)->SA_TRNG_INT_STATUS)
#define TRNG_SA_TRNG_VID1_REG(base)              ((base)->SA_TRNG_VID1)
#define TRNG_SA_TRNG_VID2_REG(base)              ((base)->SA_TRNG_VID2)

/*!
 * @}
 */ /* end of group TRNG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- TRNG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRNG_Register_Masks TRNG Register Masks
 * @{
 */

/* RTMCTL Bit Fields */
#define TRNG_RTMCTL_SAMP_MODE_MASK               0x3u
#define TRNG_RTMCTL_SAMP_MODE_SHIFT              0
#define TRNG_RTMCTL_SAMP_MODE_WIDTH              2
#define TRNG_RTMCTL_SAMP_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTMCTL_SAMP_MODE_SHIFT))&TRNG_RTMCTL_SAMP_MODE_MASK)
#define TRNG_RTMCTL_OSC_DIV_MASK                 0xCu
#define TRNG_RTMCTL_OSC_DIV_SHIFT                2
#define TRNG_RTMCTL_OSC_DIV_WIDTH                2
#define TRNG_RTMCTL_OSC_DIV(x)                   (((uint32_t)(((uint32_t)(x))<<TRNG_RTMCTL_OSC_DIV_SHIFT))&TRNG_RTMCTL_OSC_DIV_MASK)
#define TRNG_RTMCTL_UNUSED_MASK                  0x10u
#define TRNG_RTMCTL_UNUSED_SHIFT                 4
#define TRNG_RTMCTL_UNUSED_WIDTH                 1
#define TRNG_RTMCTL_UNUSED(x)                    (((uint32_t)(((uint32_t)(x))<<TRNG_RTMCTL_UNUSED_SHIFT))&TRNG_RTMCTL_UNUSED_MASK)
#define TRNG_RTMCTL_TRNG_ACC_MASK                0x20u
#define TRNG_RTMCTL_TRNG_ACC_SHIFT               5
#define TRNG_RTMCTL_TRNG_ACC_WIDTH               1
#define TRNG_RTMCTL_TRNG_ACC(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTMCTL_TRNG_ACC_SHIFT))&TRNG_RTMCTL_TRNG_ACC_MASK)
#define TRNG_RTMCTL_RST_DEF_MASK                 0x40u
#define TRNG_RTMCTL_RST_DEF_SHIFT                6
#define TRNG_RTMCTL_RST_DEF_WIDTH                1
#define TRNG_RTMCTL_RST_DEF(x)                   (((uint32_t)(((uint32_t)(x))<<TRNG_RTMCTL_RST_DEF_SHIFT))&TRNG_RTMCTL_RST_DEF_MASK)
#define TRNG_RTMCTL_FOR_SCLK_MASK                0x80u
#define TRNG_RTMCTL_FOR_SCLK_SHIFT               7
#define TRNG_RTMCTL_FOR_SCLK_WIDTH               1
#define TRNG_RTMCTL_FOR_SCLK(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTMCTL_FOR_SCLK_SHIFT))&TRNG_RTMCTL_FOR_SCLK_MASK)
#define TRNG_RTMCTL_FCT_FAIL_MASK                0x100u
#define TRNG_RTMCTL_FCT_FAIL_SHIFT               8
#define TRNG_RTMCTL_FCT_FAIL_WIDTH               1
#define TRNG_RTMCTL_FCT_FAIL(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTMCTL_FCT_FAIL_SHIFT))&TRNG_RTMCTL_FCT_FAIL_MASK)
#define TRNG_RTMCTL_FCT_VAL_MASK                 0x200u
#define TRNG_RTMCTL_FCT_VAL_SHIFT                9
#define TRNG_RTMCTL_FCT_VAL_WIDTH                1
#define TRNG_RTMCTL_FCT_VAL(x)                   (((uint32_t)(((uint32_t)(x))<<TRNG_RTMCTL_FCT_VAL_SHIFT))&TRNG_RTMCTL_FCT_VAL_MASK)
#define TRNG_RTMCTL_ENT_VAL_MASK                 0x400u
#define TRNG_RTMCTL_ENT_VAL_SHIFT                10
#define TRNG_RTMCTL_ENT_VAL_WIDTH                1
#define TRNG_RTMCTL_ENT_VAL(x)                   (((uint32_t)(((uint32_t)(x))<<TRNG_RTMCTL_ENT_VAL_SHIFT))&TRNG_RTMCTL_ENT_VAL_MASK)
#define TRNG_RTMCTL_TST_OUT_MASK                 0x800u
#define TRNG_RTMCTL_TST_OUT_SHIFT                11
#define TRNG_RTMCTL_TST_OUT_WIDTH                1
#define TRNG_RTMCTL_TST_OUT(x)                   (((uint32_t)(((uint32_t)(x))<<TRNG_RTMCTL_TST_OUT_SHIFT))&TRNG_RTMCTL_TST_OUT_MASK)
#define TRNG_RTMCTL_ERR_MASK                     0x1000u
#define TRNG_RTMCTL_ERR_SHIFT                    12
#define TRNG_RTMCTL_ERR_WIDTH                    1
#define TRNG_RTMCTL_ERR(x)                       (((uint32_t)(((uint32_t)(x))<<TRNG_RTMCTL_ERR_SHIFT))&TRNG_RTMCTL_ERR_MASK)
#define TRNG_RTMCTL_TSTOP_OK_MASK                0x2000u
#define TRNG_RTMCTL_TSTOP_OK_SHIFT               13
#define TRNG_RTMCTL_TSTOP_OK_WIDTH               1
#define TRNG_RTMCTL_TSTOP_OK(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTMCTL_TSTOP_OK_SHIFT))&TRNG_RTMCTL_TSTOP_OK_MASK)
#define TRNG_RTMCTL_PRGM_MASK                    0x10000u
#define TRNG_RTMCTL_PRGM_SHIFT                   16
#define TRNG_RTMCTL_PRGM_WIDTH                   1
#define TRNG_RTMCTL_PRGM(x)                      (((uint32_t)(((uint32_t)(x))<<TRNG_RTMCTL_PRGM_SHIFT))&TRNG_RTMCTL_PRGM_MASK)
/* RTSCMISC Bit Fields */
#define TRNG_RTSCMISC_LRUN_MAX_MASK              0xFFu
#define TRNG_RTSCMISC_LRUN_MAX_SHIFT             0
#define TRNG_RTSCMISC_LRUN_MAX_WIDTH             8
#define TRNG_RTSCMISC_LRUN_MAX(x)                (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCMISC_LRUN_MAX_SHIFT))&TRNG_RTSCMISC_LRUN_MAX_MASK)
#define TRNG_RTSCMISC_RTY_CT_MASK                0xF0000u
#define TRNG_RTSCMISC_RTY_CT_SHIFT               16
#define TRNG_RTSCMISC_RTY_CT_WIDTH               4
#define TRNG_RTSCMISC_RTY_CT(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCMISC_RTY_CT_SHIFT))&TRNG_RTSCMISC_RTY_CT_MASK)
/* RTPKRRNG Bit Fields */
#define TRNG_RTPKRRNG_PKR_RNG_MASK               0xFFFFu
#define TRNG_RTPKRRNG_PKR_RNG_SHIFT              0
#define TRNG_RTPKRRNG_PKR_RNG_WIDTH              16
#define TRNG_RTPKRRNG_PKR_RNG(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRRNG_PKR_RNG_SHIFT))&TRNG_RTPKRRNG_PKR_RNG_MASK)
/* RTPKRMAX Bit Fields */
#define TRNG_RTPKRMAX_PKR_MAX_MASK               0xFFFFFFu
#define TRNG_RTPKRMAX_PKR_MAX_SHIFT              0
#define TRNG_RTPKRMAX_PKR_MAX_WIDTH              24
#define TRNG_RTPKRMAX_PKR_MAX(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRMAX_PKR_MAX_SHIFT))&TRNG_RTPKRMAX_PKR_MAX_MASK)
/* RTPKRSQ Bit Fields */
#define TRNG_RTPKRSQ_PKR_SQ_MASK                 0xFFFFFFu
#define TRNG_RTPKRSQ_PKR_SQ_SHIFT                0
#define TRNG_RTPKRSQ_PKR_SQ_WIDTH                24
#define TRNG_RTPKRSQ_PKR_SQ(x)                   (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRSQ_PKR_SQ_SHIFT))&TRNG_RTPKRSQ_PKR_SQ_MASK)
/* RTSDCTL Bit Fields */
#define TRNG_RTSDCTL_SAMP_SIZE_MASK              0xFFFFu
#define TRNG_RTSDCTL_SAMP_SIZE_SHIFT             0
#define TRNG_RTSDCTL_SAMP_SIZE_WIDTH             16
#define TRNG_RTSDCTL_SAMP_SIZE(x)                (((uint32_t)(((uint32_t)(x))<<TRNG_RTSDCTL_SAMP_SIZE_SHIFT))&TRNG_RTSDCTL_SAMP_SIZE_MASK)
#define TRNG_RTSDCTL_ENT_DLY_MASK                0xFFFF0000u
#define TRNG_RTSDCTL_ENT_DLY_SHIFT               16
#define TRNG_RTSDCTL_ENT_DLY_WIDTH               16
#define TRNG_RTSDCTL_ENT_DLY(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSDCTL_ENT_DLY_SHIFT))&TRNG_RTSDCTL_ENT_DLY_MASK)
/* RTSBLIM Bit Fields */
#define TRNG_RTSBLIM_SB_LIM_MASK                 0x3FFu
#define TRNG_RTSBLIM_SB_LIM_SHIFT                0
#define TRNG_RTSBLIM_SB_LIM_WIDTH                10
#define TRNG_RTSBLIM_SB_LIM(x)                   (((uint32_t)(((uint32_t)(x))<<TRNG_RTSBLIM_SB_LIM_SHIFT))&TRNG_RTSBLIM_SB_LIM_MASK)
/* RTTOTSAM Bit Fields */
#define TRNG_RTTOTSAM_TOT_SAM_MASK               0xFFFFFu
#define TRNG_RTTOTSAM_TOT_SAM_SHIFT              0
#define TRNG_RTTOTSAM_TOT_SAM_WIDTH              20
#define TRNG_RTTOTSAM_TOT_SAM(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTTOTSAM_TOT_SAM_SHIFT))&TRNG_RTTOTSAM_TOT_SAM_MASK)
/* RTFRQMIN Bit Fields */
#define TRNG_RTFRQMIN_FRQ_MIN_MASK               0x3FFFFFu
#define TRNG_RTFRQMIN_FRQ_MIN_SHIFT              0
#define TRNG_RTFRQMIN_FRQ_MIN_WIDTH              22
#define TRNG_RTFRQMIN_FRQ_MIN(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTFRQMIN_FRQ_MIN_SHIFT))&TRNG_RTFRQMIN_FRQ_MIN_MASK)
/* RTFRQCNT Bit Fields */
#define TRNG_RTFRQCNT_FRQ_CT_MASK                0x3FFFFFu
#define TRNG_RTFRQCNT_FRQ_CT_SHIFT               0
#define TRNG_RTFRQCNT_FRQ_CT_WIDTH               22
#define TRNG_RTFRQCNT_FRQ_CT(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTFRQCNT_FRQ_CT_SHIFT))&TRNG_RTFRQCNT_FRQ_CT_MASK)
/* RTFRQMAX Bit Fields */
#define TRNG_RTFRQMAX_FRQ_MAX_MASK               0x3FFFFFu
#define TRNG_RTFRQMAX_FRQ_MAX_SHIFT              0
#define TRNG_RTFRQMAX_FRQ_MAX_WIDTH              22
#define TRNG_RTFRQMAX_FRQ_MAX(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTFRQMAX_FRQ_MAX_SHIFT))&TRNG_RTFRQMAX_FRQ_MAX_MASK)
/* RTSCMC Bit Fields */
#define TRNG_RTSCMC_MONO_CT_MASK                 0xFFFFu
#define TRNG_RTSCMC_MONO_CT_SHIFT                0
#define TRNG_RTSCMC_MONO_CT_WIDTH                16
#define TRNG_RTSCMC_MONO_CT(x)                   (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCMC_MONO_CT_SHIFT))&TRNG_RTSCMC_MONO_CT_MASK)
/* RTSCML Bit Fields */
#define TRNG_RTSCML_MONO_MAX_MASK                0xFFFFu
#define TRNG_RTSCML_MONO_MAX_SHIFT               0
#define TRNG_RTSCML_MONO_MAX_WIDTH               16
#define TRNG_RTSCML_MONO_MAX(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCML_MONO_MAX_SHIFT))&TRNG_RTSCML_MONO_MAX_MASK)
#define TRNG_RTSCML_MONO_RNG_MASK                0xFFFF0000u
#define TRNG_RTSCML_MONO_RNG_SHIFT               16
#define TRNG_RTSCML_MONO_RNG_WIDTH               16
#define TRNG_RTSCML_MONO_RNG(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCML_MONO_RNG_SHIFT))&TRNG_RTSCML_MONO_RNG_MASK)
/* RTSCR1C Bit Fields */
#define TRNG_RTSCR1C_R1_0_CT_MASK                0x7FFFu
#define TRNG_RTSCR1C_R1_0_CT_SHIFT               0
#define TRNG_RTSCR1C_R1_0_CT_WIDTH               15
#define TRNG_RTSCR1C_R1_0_CT(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR1C_R1_0_CT_SHIFT))&TRNG_RTSCR1C_R1_0_CT_MASK)
#define TRNG_RTSCR1C_R1_1_CT_MASK                0x7FFF0000u
#define TRNG_RTSCR1C_R1_1_CT_SHIFT               16
#define TRNG_RTSCR1C_R1_1_CT_WIDTH               15
#define TRNG_RTSCR1C_R1_1_CT(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR1C_R1_1_CT_SHIFT))&TRNG_RTSCR1C_R1_1_CT_MASK)
/* RTSCR1L Bit Fields */
#define TRNG_RTSCR1L_RUN1_MAX_MASK               0x7FFFu
#define TRNG_RTSCR1L_RUN1_MAX_SHIFT              0
#define TRNG_RTSCR1L_RUN1_MAX_WIDTH              15
#define TRNG_RTSCR1L_RUN1_MAX(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR1L_RUN1_MAX_SHIFT))&TRNG_RTSCR1L_RUN1_MAX_MASK)
#define TRNG_RTSCR1L_RUN1_RNG_MASK               0x7FFF0000u
#define TRNG_RTSCR1L_RUN1_RNG_SHIFT              16
#define TRNG_RTSCR1L_RUN1_RNG_WIDTH              15
#define TRNG_RTSCR1L_RUN1_RNG(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR1L_RUN1_RNG_SHIFT))&TRNG_RTSCR1L_RUN1_RNG_MASK)
/* RTSCR2C Bit Fields */
#define TRNG_RTSCR2C_R2_0_CT_MASK                0x3FFFu
#define TRNG_RTSCR2C_R2_0_CT_SHIFT               0
#define TRNG_RTSCR2C_R2_0_CT_WIDTH               14
#define TRNG_RTSCR2C_R2_0_CT(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR2C_R2_0_CT_SHIFT))&TRNG_RTSCR2C_R2_0_CT_MASK)
#define TRNG_RTSCR2C_R2_1_CT_MASK                0x3FFF0000u
#define TRNG_RTSCR2C_R2_1_CT_SHIFT               16
#define TRNG_RTSCR2C_R2_1_CT_WIDTH               14
#define TRNG_RTSCR2C_R2_1_CT(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR2C_R2_1_CT_SHIFT))&TRNG_RTSCR2C_R2_1_CT_MASK)
/* RTSCR2L Bit Fields */
#define TRNG_RTSCR2L_RUN2_MAX_MASK               0x3FFFu
#define TRNG_RTSCR2L_RUN2_MAX_SHIFT              0
#define TRNG_RTSCR2L_RUN2_MAX_WIDTH              14
#define TRNG_RTSCR2L_RUN2_MAX(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR2L_RUN2_MAX_SHIFT))&TRNG_RTSCR2L_RUN2_MAX_MASK)
#define TRNG_RTSCR2L_RUN2_RNG_MASK               0x3FFF0000u
#define TRNG_RTSCR2L_RUN2_RNG_SHIFT              16
#define TRNG_RTSCR2L_RUN2_RNG_WIDTH              14
#define TRNG_RTSCR2L_RUN2_RNG(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR2L_RUN2_RNG_SHIFT))&TRNG_RTSCR2L_RUN2_RNG_MASK)
/* RTSCR3C Bit Fields */
#define TRNG_RTSCR3C_R3_0_CT_MASK                0x1FFFu
#define TRNG_RTSCR3C_R3_0_CT_SHIFT               0
#define TRNG_RTSCR3C_R3_0_CT_WIDTH               13
#define TRNG_RTSCR3C_R3_0_CT(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR3C_R3_0_CT_SHIFT))&TRNG_RTSCR3C_R3_0_CT_MASK)
#define TRNG_RTSCR3C_R3_1_CT_MASK                0x1FFF0000u
#define TRNG_RTSCR3C_R3_1_CT_SHIFT               16
#define TRNG_RTSCR3C_R3_1_CT_WIDTH               13
#define TRNG_RTSCR3C_R3_1_CT(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR3C_R3_1_CT_SHIFT))&TRNG_RTSCR3C_R3_1_CT_MASK)
/* RTSCR3L Bit Fields */
#define TRNG_RTSCR3L_RUN3_MAX_MASK               0x1FFFu
#define TRNG_RTSCR3L_RUN3_MAX_SHIFT              0
#define TRNG_RTSCR3L_RUN3_MAX_WIDTH              13
#define TRNG_RTSCR3L_RUN3_MAX(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR3L_RUN3_MAX_SHIFT))&TRNG_RTSCR3L_RUN3_MAX_MASK)
#define TRNG_RTSCR3L_RUN3_RNG_MASK               0x1FFF0000u
#define TRNG_RTSCR3L_RUN3_RNG_SHIFT              16
#define TRNG_RTSCR3L_RUN3_RNG_WIDTH              13
#define TRNG_RTSCR3L_RUN3_RNG(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR3L_RUN3_RNG_SHIFT))&TRNG_RTSCR3L_RUN3_RNG_MASK)
/* RTSCR4C Bit Fields */
#define TRNG_RTSCR4C_R4_0_CT_MASK                0xFFFu
#define TRNG_RTSCR4C_R4_0_CT_SHIFT               0
#define TRNG_RTSCR4C_R4_0_CT_WIDTH               12
#define TRNG_RTSCR4C_R4_0_CT(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR4C_R4_0_CT_SHIFT))&TRNG_RTSCR4C_R4_0_CT_MASK)
#define TRNG_RTSCR4C_R4_1_CT_MASK                0xFFF0000u
#define TRNG_RTSCR4C_R4_1_CT_SHIFT               16
#define TRNG_RTSCR4C_R4_1_CT_WIDTH               12
#define TRNG_RTSCR4C_R4_1_CT(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR4C_R4_1_CT_SHIFT))&TRNG_RTSCR4C_R4_1_CT_MASK)
/* RTSCR4L Bit Fields */
#define TRNG_RTSCR4L_RUN4_MAX_MASK               0xFFFu
#define TRNG_RTSCR4L_RUN4_MAX_SHIFT              0
#define TRNG_RTSCR4L_RUN4_MAX_WIDTH              12
#define TRNG_RTSCR4L_RUN4_MAX(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR4L_RUN4_MAX_SHIFT))&TRNG_RTSCR4L_RUN4_MAX_MASK)
#define TRNG_RTSCR4L_RUN4_RNG_MASK               0xFFF0000u
#define TRNG_RTSCR4L_RUN4_RNG_SHIFT              16
#define TRNG_RTSCR4L_RUN4_RNG_WIDTH              12
#define TRNG_RTSCR4L_RUN4_RNG(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR4L_RUN4_RNG_SHIFT))&TRNG_RTSCR4L_RUN4_RNG_MASK)
/* RTSCR5C Bit Fields */
#define TRNG_RTSCR5C_R5_0_CT_MASK                0x7FFu
#define TRNG_RTSCR5C_R5_0_CT_SHIFT               0
#define TRNG_RTSCR5C_R5_0_CT_WIDTH               11
#define TRNG_RTSCR5C_R5_0_CT(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR5C_R5_0_CT_SHIFT))&TRNG_RTSCR5C_R5_0_CT_MASK)
#define TRNG_RTSCR5C_R5_1_CT_MASK                0x7FF0000u
#define TRNG_RTSCR5C_R5_1_CT_SHIFT               16
#define TRNG_RTSCR5C_R5_1_CT_WIDTH               11
#define TRNG_RTSCR5C_R5_1_CT(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR5C_R5_1_CT_SHIFT))&TRNG_RTSCR5C_R5_1_CT_MASK)
/* RTSCR5L Bit Fields */
#define TRNG_RTSCR5L_RUN5_MAX_MASK               0x7FFu
#define TRNG_RTSCR5L_RUN5_MAX_SHIFT              0
#define TRNG_RTSCR5L_RUN5_MAX_WIDTH              11
#define TRNG_RTSCR5L_RUN5_MAX(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR5L_RUN5_MAX_SHIFT))&TRNG_RTSCR5L_RUN5_MAX_MASK)
#define TRNG_RTSCR5L_RUN5_RNG_MASK               0x7FF0000u
#define TRNG_RTSCR5L_RUN5_RNG_SHIFT              16
#define TRNG_RTSCR5L_RUN5_RNG_WIDTH              11
#define TRNG_RTSCR5L_RUN5_RNG(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR5L_RUN5_RNG_SHIFT))&TRNG_RTSCR5L_RUN5_RNG_MASK)
/* RTSCR6PC Bit Fields */
#define TRNG_RTSCR6PC_R6P_0_CT_MASK              0x7FFu
#define TRNG_RTSCR6PC_R6P_0_CT_SHIFT             0
#define TRNG_RTSCR6PC_R6P_0_CT_WIDTH             11
#define TRNG_RTSCR6PC_R6P_0_CT(x)                (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR6PC_R6P_0_CT_SHIFT))&TRNG_RTSCR6PC_R6P_0_CT_MASK)
#define TRNG_RTSCR6PC_R6P_1_CT_MASK              0x7FF0000u
#define TRNG_RTSCR6PC_R6P_1_CT_SHIFT             16
#define TRNG_RTSCR6PC_R6P_1_CT_WIDTH             11
#define TRNG_RTSCR6PC_R6P_1_CT(x)                (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR6PC_R6P_1_CT_SHIFT))&TRNG_RTSCR6PC_R6P_1_CT_MASK)
/* RTSCR6PL Bit Fields */
#define TRNG_RTSCR6PL_RUN6P_MAX_MASK             0x7FFu
#define TRNG_RTSCR6PL_RUN6P_MAX_SHIFT            0
#define TRNG_RTSCR6PL_RUN6P_MAX_WIDTH            11
#define TRNG_RTSCR6PL_RUN6P_MAX(x)               (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR6PL_RUN6P_MAX_SHIFT))&TRNG_RTSCR6PL_RUN6P_MAX_MASK)
#define TRNG_RTSCR6PL_RUN6P_RNG_MASK             0x7FF0000u
#define TRNG_RTSCR6PL_RUN6P_RNG_SHIFT            16
#define TRNG_RTSCR6PL_RUN6P_RNG_WIDTH            11
#define TRNG_RTSCR6PL_RUN6P_RNG(x)               (((uint32_t)(((uint32_t)(x))<<TRNG_RTSCR6PL_RUN6P_RNG_SHIFT))&TRNG_RTSCR6PL_RUN6P_RNG_MASK)
/* RTSTATUS Bit Fields */
#define TRNG_RTSTATUS_TF1BR0_MASK                0x1u
#define TRNG_RTSTATUS_TF1BR0_SHIFT               0
#define TRNG_RTSTATUS_TF1BR0_WIDTH               1
#define TRNG_RTSTATUS_TF1BR0(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TF1BR0_SHIFT))&TRNG_RTSTATUS_TF1BR0_MASK)
#define TRNG_RTSTATUS_TF1BR1_MASK                0x2u
#define TRNG_RTSTATUS_TF1BR1_SHIFT               1
#define TRNG_RTSTATUS_TF1BR1_WIDTH               1
#define TRNG_RTSTATUS_TF1BR1(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TF1BR1_SHIFT))&TRNG_RTSTATUS_TF1BR1_MASK)
#define TRNG_RTSTATUS_TF2BR0_MASK                0x4u
#define TRNG_RTSTATUS_TF2BR0_SHIFT               2
#define TRNG_RTSTATUS_TF2BR0_WIDTH               1
#define TRNG_RTSTATUS_TF2BR0(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TF2BR0_SHIFT))&TRNG_RTSTATUS_TF2BR0_MASK)
#define TRNG_RTSTATUS_TF2BR1_MASK                0x8u
#define TRNG_RTSTATUS_TF2BR1_SHIFT               3
#define TRNG_RTSTATUS_TF2BR1_WIDTH               1
#define TRNG_RTSTATUS_TF2BR1(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TF2BR1_SHIFT))&TRNG_RTSTATUS_TF2BR1_MASK)
#define TRNG_RTSTATUS_TF3BR0_MASK                0x10u
#define TRNG_RTSTATUS_TF3BR0_SHIFT               4
#define TRNG_RTSTATUS_TF3BR0_WIDTH               1
#define TRNG_RTSTATUS_TF3BR0(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TF3BR0_SHIFT))&TRNG_RTSTATUS_TF3BR0_MASK)
#define TRNG_RTSTATUS_TF3BR1_MASK                0x20u
#define TRNG_RTSTATUS_TF3BR1_SHIFT               5
#define TRNG_RTSTATUS_TF3BR1_WIDTH               1
#define TRNG_RTSTATUS_TF3BR1(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TF3BR1_SHIFT))&TRNG_RTSTATUS_TF3BR1_MASK)
#define TRNG_RTSTATUS_TF4BR0_MASK                0x40u
#define TRNG_RTSTATUS_TF4BR0_SHIFT               6
#define TRNG_RTSTATUS_TF4BR0_WIDTH               1
#define TRNG_RTSTATUS_TF4BR0(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TF4BR0_SHIFT))&TRNG_RTSTATUS_TF4BR0_MASK)
#define TRNG_RTSTATUS_TF4BR1_MASK                0x80u
#define TRNG_RTSTATUS_TF4BR1_SHIFT               7
#define TRNG_RTSTATUS_TF4BR1_WIDTH               1
#define TRNG_RTSTATUS_TF4BR1(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TF4BR1_SHIFT))&TRNG_RTSTATUS_TF4BR1_MASK)
#define TRNG_RTSTATUS_TF5BR0_MASK                0x100u
#define TRNG_RTSTATUS_TF5BR0_SHIFT               8
#define TRNG_RTSTATUS_TF5BR0_WIDTH               1
#define TRNG_RTSTATUS_TF5BR0(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TF5BR0_SHIFT))&TRNG_RTSTATUS_TF5BR0_MASK)
#define TRNG_RTSTATUS_TF5BR1_MASK                0x200u
#define TRNG_RTSTATUS_TF5BR1_SHIFT               9
#define TRNG_RTSTATUS_TF5BR1_WIDTH               1
#define TRNG_RTSTATUS_TF5BR1(x)                  (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TF5BR1_SHIFT))&TRNG_RTSTATUS_TF5BR1_MASK)
#define TRNG_RTSTATUS_TF6PBR0_MASK               0x400u
#define TRNG_RTSTATUS_TF6PBR0_SHIFT              10
#define TRNG_RTSTATUS_TF6PBR0_WIDTH              1
#define TRNG_RTSTATUS_TF6PBR0(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TF6PBR0_SHIFT))&TRNG_RTSTATUS_TF6PBR0_MASK)
#define TRNG_RTSTATUS_TF6PBR1_MASK               0x800u
#define TRNG_RTSTATUS_TF6PBR1_SHIFT              11
#define TRNG_RTSTATUS_TF6PBR1_WIDTH              1
#define TRNG_RTSTATUS_TF6PBR1(x)                 (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TF6PBR1_SHIFT))&TRNG_RTSTATUS_TF6PBR1_MASK)
#define TRNG_RTSTATUS_TFSB_MASK                  0x1000u
#define TRNG_RTSTATUS_TFSB_SHIFT                 12
#define TRNG_RTSTATUS_TFSB_WIDTH                 1
#define TRNG_RTSTATUS_TFSB(x)                    (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TFSB_SHIFT))&TRNG_RTSTATUS_TFSB_MASK)
#define TRNG_RTSTATUS_TFLR_MASK                  0x2000u
#define TRNG_RTSTATUS_TFLR_SHIFT                 13
#define TRNG_RTSTATUS_TFLR_WIDTH                 1
#define TRNG_RTSTATUS_TFLR(x)                    (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TFLR_SHIFT))&TRNG_RTSTATUS_TFLR_MASK)
#define TRNG_RTSTATUS_TFP_MASK                   0x4000u
#define TRNG_RTSTATUS_TFP_SHIFT                  14
#define TRNG_RTSTATUS_TFP_WIDTH                  1
#define TRNG_RTSTATUS_TFP(x)                     (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TFP_SHIFT))&TRNG_RTSTATUS_TFP_MASK)
#define TRNG_RTSTATUS_TFMB_MASK                  0x8000u
#define TRNG_RTSTATUS_TFMB_SHIFT                 15
#define TRNG_RTSTATUS_TFMB_WIDTH                 1
#define TRNG_RTSTATUS_TFMB(x)                    (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_TFMB_SHIFT))&TRNG_RTSTATUS_TFMB_MASK)
#define TRNG_RTSTATUS_RETRY_CT_MASK              0xF0000u
#define TRNG_RTSTATUS_RETRY_CT_SHIFT             16
#define TRNG_RTSTATUS_RETRY_CT_WIDTH             4
#define TRNG_RTSTATUS_RETRY_CT(x)                (((uint32_t)(((uint32_t)(x))<<TRNG_RTSTATUS_RETRY_CT_SHIFT))&TRNG_RTSTATUS_RETRY_CT_MASK)
/* RTENT0 Bit Fields */
#define TRNG_RTENT0_ENT_MASK                     0xFFFFFFFFu
#define TRNG_RTENT0_ENT_SHIFT                    0
#define TRNG_RTENT0_ENT_WIDTH                    32
#define TRNG_RTENT0_ENT(x)                       (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT0_ENT_SHIFT))&TRNG_RTENT0_ENT_MASK)
/* RTENT1 Bit Fields */
#define TRNG_RTENT1_ENT_MASK                     0xFFFFFFFFu
#define TRNG_RTENT1_ENT_SHIFT                    0
#define TRNG_RTENT1_ENT_WIDTH                    32
#define TRNG_RTENT1_ENT(x)                       (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT1_ENT_SHIFT))&TRNG_RTENT1_ENT_MASK)
/* RTENT2 Bit Fields */
#define TRNG_RTENT2_ENT_MASK                     0xFFFFFFFFu
#define TRNG_RTENT2_ENT_SHIFT                    0
#define TRNG_RTENT2_ENT_WIDTH                    32
#define TRNG_RTENT2_ENT(x)                       (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT2_ENT_SHIFT))&TRNG_RTENT2_ENT_MASK)
/* RTENT3 Bit Fields */
#define TRNG_RTENT3_ENT_MASK                     0xFFFFFFFFu
#define TRNG_RTENT3_ENT_SHIFT                    0
#define TRNG_RTENT3_ENT_WIDTH                    32
#define TRNG_RTENT3_ENT(x)                       (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT3_ENT_SHIFT))&TRNG_RTENT3_ENT_MASK)
/* RTENT4 Bit Fields */
#define TRNG_RTENT4_ENT_MASK                     0xFFFFFFFFu
#define TRNG_RTENT4_ENT_SHIFT                    0
#define TRNG_RTENT4_ENT_WIDTH                    32
#define TRNG_RTENT4_ENT(x)                       (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT4_ENT_SHIFT))&TRNG_RTENT4_ENT_MASK)
/* RTENT5 Bit Fields */
#define TRNG_RTENT5_ENT_MASK                     0xFFFFFFFFu
#define TRNG_RTENT5_ENT_SHIFT                    0
#define TRNG_RTENT5_ENT_WIDTH                    32
#define TRNG_RTENT5_ENT(x)                       (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT5_ENT_SHIFT))&TRNG_RTENT5_ENT_MASK)
/* RTENT6 Bit Fields */
#define TRNG_RTENT6_ENT_MASK                     0xFFFFFFFFu
#define TRNG_RTENT6_ENT_SHIFT                    0
#define TRNG_RTENT6_ENT_WIDTH                    32
#define TRNG_RTENT6_ENT(x)                       (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT6_ENT_SHIFT))&TRNG_RTENT6_ENT_MASK)
/* RTENT7 Bit Fields */
#define TRNG_RTENT7_ENT_MASK                     0xFFFFFFFFu
#define TRNG_RTENT7_ENT_SHIFT                    0
#define TRNG_RTENT7_ENT_WIDTH                    32
#define TRNG_RTENT7_ENT(x)                       (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT7_ENT_SHIFT))&TRNG_RTENT7_ENT_MASK)
/* RTENT8 Bit Fields */
#define TRNG_RTENT8_ENT_MASK                     0xFFFFFFFFu
#define TRNG_RTENT8_ENT_SHIFT                    0
#define TRNG_RTENT8_ENT_WIDTH                    32
#define TRNG_RTENT8_ENT(x)                       (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT8_ENT_SHIFT))&TRNG_RTENT8_ENT_MASK)
/* RTENT9 Bit Fields */
#define TRNG_RTENT9_ENT_MASK                     0xFFFFFFFFu
#define TRNG_RTENT9_ENT_SHIFT                    0
#define TRNG_RTENT9_ENT_WIDTH                    32
#define TRNG_RTENT9_ENT(x)                       (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT9_ENT_SHIFT))&TRNG_RTENT9_ENT_MASK)
/* RTENT10 Bit Fields */
#define TRNG_RTENT10_ENT_MASK                    0xFFFFFFFFu
#define TRNG_RTENT10_ENT_SHIFT                   0
#define TRNG_RTENT10_ENT_WIDTH                   32
#define TRNG_RTENT10_ENT(x)                      (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT10_ENT_SHIFT))&TRNG_RTENT10_ENT_MASK)
/* RTENT11 Bit Fields */
#define TRNG_RTENT11_ENT_MASK                    0xFFFFFFFFu
#define TRNG_RTENT11_ENT_SHIFT                   0
#define TRNG_RTENT11_ENT_WIDTH                   32
#define TRNG_RTENT11_ENT(x)                      (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT11_ENT_SHIFT))&TRNG_RTENT11_ENT_MASK)
/* RTENT12 Bit Fields */
#define TRNG_RTENT12_ENT_MASK                    0xFFFFFFFFu
#define TRNG_RTENT12_ENT_SHIFT                   0
#define TRNG_RTENT12_ENT_WIDTH                   32
#define TRNG_RTENT12_ENT(x)                      (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT12_ENT_SHIFT))&TRNG_RTENT12_ENT_MASK)
/* RTENT13 Bit Fields */
#define TRNG_RTENT13_ENT_MASK                    0xFFFFFFFFu
#define TRNG_RTENT13_ENT_SHIFT                   0
#define TRNG_RTENT13_ENT_WIDTH                   32
#define TRNG_RTENT13_ENT(x)                      (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT13_ENT_SHIFT))&TRNG_RTENT13_ENT_MASK)
/* RTENT14 Bit Fields */
#define TRNG_RTENT14_ENT_MASK                    0xFFFFFFFFu
#define TRNG_RTENT14_ENT_SHIFT                   0
#define TRNG_RTENT14_ENT_WIDTH                   32
#define TRNG_RTENT14_ENT(x)                      (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT14_ENT_SHIFT))&TRNG_RTENT14_ENT_MASK)
/* RTENT15 Bit Fields */
#define TRNG_RTENT15_ENT_MASK                    0xFFFFFFFFu
#define TRNG_RTENT15_ENT_SHIFT                   0
#define TRNG_RTENT15_ENT_WIDTH                   32
#define TRNG_RTENT15_ENT(x)                      (((uint32_t)(((uint32_t)(x))<<TRNG_RTENT15_ENT_SHIFT))&TRNG_RTENT15_ENT_MASK)
/* RTPKRCNT10 Bit Fields */
#define TRNG_RTPKRCNT10_PKR_0_CT_MASK            0xFFFFu
#define TRNG_RTPKRCNT10_PKR_0_CT_SHIFT           0
#define TRNG_RTPKRCNT10_PKR_0_CT_WIDTH           16
#define TRNG_RTPKRCNT10_PKR_0_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNT10_PKR_0_CT_SHIFT))&TRNG_RTPKRCNT10_PKR_0_CT_MASK)
#define TRNG_RTPKRCNT10_PKR_1_CT_MASK            0xFFFF0000u
#define TRNG_RTPKRCNT10_PKR_1_CT_SHIFT           16
#define TRNG_RTPKRCNT10_PKR_1_CT_WIDTH           16
#define TRNG_RTPKRCNT10_PKR_1_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNT10_PKR_1_CT_SHIFT))&TRNG_RTPKRCNT10_PKR_1_CT_MASK)
/* RTPKRCNT32 Bit Fields */
#define TRNG_RTPKRCNT32_PKR_2_CT_MASK            0xFFFFu
#define TRNG_RTPKRCNT32_PKR_2_CT_SHIFT           0
#define TRNG_RTPKRCNT32_PKR_2_CT_WIDTH           16
#define TRNG_RTPKRCNT32_PKR_2_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNT32_PKR_2_CT_SHIFT))&TRNG_RTPKRCNT32_PKR_2_CT_MASK)
#define TRNG_RTPKRCNT32_PKR_3_CT_MASK            0xFFFF0000u
#define TRNG_RTPKRCNT32_PKR_3_CT_SHIFT           16
#define TRNG_RTPKRCNT32_PKR_3_CT_WIDTH           16
#define TRNG_RTPKRCNT32_PKR_3_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNT32_PKR_3_CT_SHIFT))&TRNG_RTPKRCNT32_PKR_3_CT_MASK)
/* RTPKRCNT54 Bit Fields */
#define TRNG_RTPKRCNT54_PKR_4_CT_MASK            0xFFFFu
#define TRNG_RTPKRCNT54_PKR_4_CT_SHIFT           0
#define TRNG_RTPKRCNT54_PKR_4_CT_WIDTH           16
#define TRNG_RTPKRCNT54_PKR_4_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNT54_PKR_4_CT_SHIFT))&TRNG_RTPKRCNT54_PKR_4_CT_MASK)
#define TRNG_RTPKRCNT54_PKR_5_CT_MASK            0xFFFF0000u
#define TRNG_RTPKRCNT54_PKR_5_CT_SHIFT           16
#define TRNG_RTPKRCNT54_PKR_5_CT_WIDTH           16
#define TRNG_RTPKRCNT54_PKR_5_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNT54_PKR_5_CT_SHIFT))&TRNG_RTPKRCNT54_PKR_5_CT_MASK)
/* RTPKRCNT76 Bit Fields */
#define TRNG_RTPKRCNT76_PKR_6_CT_MASK            0xFFFFu
#define TRNG_RTPKRCNT76_PKR_6_CT_SHIFT           0
#define TRNG_RTPKRCNT76_PKR_6_CT_WIDTH           16
#define TRNG_RTPKRCNT76_PKR_6_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNT76_PKR_6_CT_SHIFT))&TRNG_RTPKRCNT76_PKR_6_CT_MASK)
#define TRNG_RTPKRCNT76_PKR_7_CT_MASK            0xFFFF0000u
#define TRNG_RTPKRCNT76_PKR_7_CT_SHIFT           16
#define TRNG_RTPKRCNT76_PKR_7_CT_WIDTH           16
#define TRNG_RTPKRCNT76_PKR_7_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNT76_PKR_7_CT_SHIFT))&TRNG_RTPKRCNT76_PKR_7_CT_MASK)
/* RTPKRCNT98 Bit Fields */
#define TRNG_RTPKRCNT98_PKR_8_CT_MASK            0xFFFFu
#define TRNG_RTPKRCNT98_PKR_8_CT_SHIFT           0
#define TRNG_RTPKRCNT98_PKR_8_CT_WIDTH           16
#define TRNG_RTPKRCNT98_PKR_8_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNT98_PKR_8_CT_SHIFT))&TRNG_RTPKRCNT98_PKR_8_CT_MASK)
#define TRNG_RTPKRCNT98_PKR_9_CT_MASK            0xFFFF0000u
#define TRNG_RTPKRCNT98_PKR_9_CT_SHIFT           16
#define TRNG_RTPKRCNT98_PKR_9_CT_WIDTH           16
#define TRNG_RTPKRCNT98_PKR_9_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNT98_PKR_9_CT_SHIFT))&TRNG_RTPKRCNT98_PKR_9_CT_MASK)
/* RTPKRCNTBA Bit Fields */
#define TRNG_RTPKRCNTBA_PKR_A_CT_MASK            0xFFFFu
#define TRNG_RTPKRCNTBA_PKR_A_CT_SHIFT           0
#define TRNG_RTPKRCNTBA_PKR_A_CT_WIDTH           16
#define TRNG_RTPKRCNTBA_PKR_A_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNTBA_PKR_A_CT_SHIFT))&TRNG_RTPKRCNTBA_PKR_A_CT_MASK)
#define TRNG_RTPKRCNTBA_PKR_B_CT_MASK            0xFFFF0000u
#define TRNG_RTPKRCNTBA_PKR_B_CT_SHIFT           16
#define TRNG_RTPKRCNTBA_PKR_B_CT_WIDTH           16
#define TRNG_RTPKRCNTBA_PKR_B_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNTBA_PKR_B_CT_SHIFT))&TRNG_RTPKRCNTBA_PKR_B_CT_MASK)
/* RTPKRCNTDC Bit Fields */
#define TRNG_RTPKRCNTDC_PKR_C_CT_MASK            0xFFFFu
#define TRNG_RTPKRCNTDC_PKR_C_CT_SHIFT           0
#define TRNG_RTPKRCNTDC_PKR_C_CT_WIDTH           16
#define TRNG_RTPKRCNTDC_PKR_C_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNTDC_PKR_C_CT_SHIFT))&TRNG_RTPKRCNTDC_PKR_C_CT_MASK)
#define TRNG_RTPKRCNTDC_PKR_D_CT_MASK            0xFFFF0000u
#define TRNG_RTPKRCNTDC_PKR_D_CT_SHIFT           16
#define TRNG_RTPKRCNTDC_PKR_D_CT_WIDTH           16
#define TRNG_RTPKRCNTDC_PKR_D_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNTDC_PKR_D_CT_SHIFT))&TRNG_RTPKRCNTDC_PKR_D_CT_MASK)
/* RTPKRCNTFE Bit Fields */
#define TRNG_RTPKRCNTFE_PKR_E_CT_MASK            0xFFFFu
#define TRNG_RTPKRCNTFE_PKR_E_CT_SHIFT           0
#define TRNG_RTPKRCNTFE_PKR_E_CT_WIDTH           16
#define TRNG_RTPKRCNTFE_PKR_E_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNTFE_PKR_E_CT_SHIFT))&TRNG_RTPKRCNTFE_PKR_E_CT_MASK)
#define TRNG_RTPKRCNTFE_PKR_F_CT_MASK            0xFFFF0000u
#define TRNG_RTPKRCNTFE_PKR_F_CT_SHIFT           16
#define TRNG_RTPKRCNTFE_PKR_F_CT_WIDTH           16
#define TRNG_RTPKRCNTFE_PKR_F_CT(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_RTPKRCNTFE_PKR_F_CT_SHIFT))&TRNG_RTPKRCNTFE_PKR_F_CT_MASK)
/* SA_TRNG_SEC_CFG Bit Fields */
#define TRNG_SA_TRNG_SEC_CFG_SH0_MASK            0x1u
#define TRNG_SA_TRNG_SEC_CFG_SH0_SHIFT           0
#define TRNG_SA_TRNG_SEC_CFG_SH0_WIDTH           1
#define TRNG_SA_TRNG_SEC_CFG_SH0(x)              (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_SEC_CFG_SH0_SHIFT))&TRNG_SA_TRNG_SEC_CFG_SH0_MASK)
#define TRNG_SA_TRNG_SEC_CFG_NO_PRGM_MASK        0x2u
#define TRNG_SA_TRNG_SEC_CFG_NO_PRGM_SHIFT       1
#define TRNG_SA_TRNG_SEC_CFG_NO_PRGM_WIDTH       1
#define TRNG_SA_TRNG_SEC_CFG_NO_PRGM(x)          (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_SEC_CFG_NO_PRGM_SHIFT))&TRNG_SA_TRNG_SEC_CFG_NO_PRGM_MASK)
#define TRNG_SA_TRNG_SEC_CFG_SK_VAL_MASK         0x4u
#define TRNG_SA_TRNG_SEC_CFG_SK_VAL_SHIFT        2
#define TRNG_SA_TRNG_SEC_CFG_SK_VAL_WIDTH        1
#define TRNG_SA_TRNG_SEC_CFG_SK_VAL(x)           (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_SEC_CFG_SK_VAL_SHIFT))&TRNG_SA_TRNG_SEC_CFG_SK_VAL_MASK)
/* SA_TRNG_INT_CTRL Bit Fields */
#define TRNG_SA_TRNG_INT_CTRL_HW_ERR_MASK        0x1u
#define TRNG_SA_TRNG_INT_CTRL_HW_ERR_SHIFT       0
#define TRNG_SA_TRNG_INT_CTRL_HW_ERR_WIDTH       1
#define TRNG_SA_TRNG_INT_CTRL_HW_ERR(x)          (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_INT_CTRL_HW_ERR_SHIFT))&TRNG_SA_TRNG_INT_CTRL_HW_ERR_MASK)
#define TRNG_SA_TRNG_INT_CTRL_ENT_VAL_MASK       0x2u
#define TRNG_SA_TRNG_INT_CTRL_ENT_VAL_SHIFT      1
#define TRNG_SA_TRNG_INT_CTRL_ENT_VAL_WIDTH      1
#define TRNG_SA_TRNG_INT_CTRL_ENT_VAL(x)         (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_INT_CTRL_ENT_VAL_SHIFT))&TRNG_SA_TRNG_INT_CTRL_ENT_VAL_MASK)
#define TRNG_SA_TRNG_INT_CTRL_FRQ_CT_FAIL_MASK   0x4u
#define TRNG_SA_TRNG_INT_CTRL_FRQ_CT_FAIL_SHIFT  2
#define TRNG_SA_TRNG_INT_CTRL_FRQ_CT_FAIL_WIDTH  1
#define TRNG_SA_TRNG_INT_CTRL_FRQ_CT_FAIL(x)     (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_INT_CTRL_FRQ_CT_FAIL_SHIFT))&TRNG_SA_TRNG_INT_CTRL_FRQ_CT_FAIL_MASK)
#define TRNG_SA_TRNG_INT_CTRL_UNUSED_MASK        0xFFFFFFF8u
#define TRNG_SA_TRNG_INT_CTRL_UNUSED_SHIFT       3
#define TRNG_SA_TRNG_INT_CTRL_UNUSED_WIDTH       29
#define TRNG_SA_TRNG_INT_CTRL_UNUSED(x)          (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_INT_CTRL_UNUSED_SHIFT))&TRNG_SA_TRNG_INT_CTRL_UNUSED_MASK)
/* SA_TRNG_INT_MASK Bit Fields */
#define TRNG_SA_TRNG_INT_MASK_HW_ERR_MASK        0x1u
#define TRNG_SA_TRNG_INT_MASK_HW_ERR_SHIFT       0
#define TRNG_SA_TRNG_INT_MASK_HW_ERR_WIDTH       1
#define TRNG_SA_TRNG_INT_MASK_HW_ERR(x)          (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_INT_MASK_HW_ERR_SHIFT))&TRNG_SA_TRNG_INT_MASK_HW_ERR_MASK)
#define TRNG_SA_TRNG_INT_MASK_ENT_VAL_MASK       0x2u
#define TRNG_SA_TRNG_INT_MASK_ENT_VAL_SHIFT      1
#define TRNG_SA_TRNG_INT_MASK_ENT_VAL_WIDTH      1
#define TRNG_SA_TRNG_INT_MASK_ENT_VAL(x)         (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_INT_MASK_ENT_VAL_SHIFT))&TRNG_SA_TRNG_INT_MASK_ENT_VAL_MASK)
#define TRNG_SA_TRNG_INT_MASK_FRQ_CT_FAIL_MASK   0x4u
#define TRNG_SA_TRNG_INT_MASK_FRQ_CT_FAIL_SHIFT  2
#define TRNG_SA_TRNG_INT_MASK_FRQ_CT_FAIL_WIDTH  1
#define TRNG_SA_TRNG_INT_MASK_FRQ_CT_FAIL(x)     (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_INT_MASK_FRQ_CT_FAIL_SHIFT))&TRNG_SA_TRNG_INT_MASK_FRQ_CT_FAIL_MASK)
/* SA_TRNG_INT_STATUS Bit Fields */
#define TRNG_SA_TRNG_INT_STATUS_HW_ERR_MASK      0x1u
#define TRNG_SA_TRNG_INT_STATUS_HW_ERR_SHIFT     0
#define TRNG_SA_TRNG_INT_STATUS_HW_ERR_WIDTH     1
#define TRNG_SA_TRNG_INT_STATUS_HW_ERR(x)        (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_INT_STATUS_HW_ERR_SHIFT))&TRNG_SA_TRNG_INT_STATUS_HW_ERR_MASK)
#define TRNG_SA_TRNG_INT_STATUS_ENT_VAL_MASK     0x2u
#define TRNG_SA_TRNG_INT_STATUS_ENT_VAL_SHIFT    1
#define TRNG_SA_TRNG_INT_STATUS_ENT_VAL_WIDTH    1
#define TRNG_SA_TRNG_INT_STATUS_ENT_VAL(x)       (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_INT_STATUS_ENT_VAL_SHIFT))&TRNG_SA_TRNG_INT_STATUS_ENT_VAL_MASK)
#define TRNG_SA_TRNG_INT_STATUS_FRQ_CT_FAIL_MASK 0x4u
#define TRNG_SA_TRNG_INT_STATUS_FRQ_CT_FAIL_SHIFT 2
#define TRNG_SA_TRNG_INT_STATUS_FRQ_CT_FAIL_WIDTH 1
#define TRNG_SA_TRNG_INT_STATUS_FRQ_CT_FAIL(x)   (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_INT_STATUS_FRQ_CT_FAIL_SHIFT))&TRNG_SA_TRNG_INT_STATUS_FRQ_CT_FAIL_MASK)
/* SA_TRNG_VID1 Bit Fields */
#define TRNG_SA_TRNG_VID1_RNG_MIN_REV_MASK       0xFFu
#define TRNG_SA_TRNG_VID1_RNG_MIN_REV_SHIFT      0
#define TRNG_SA_TRNG_VID1_RNG_MIN_REV_WIDTH      8
#define TRNG_SA_TRNG_VID1_RNG_MIN_REV(x)         (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_VID1_RNG_MIN_REV_SHIFT))&TRNG_SA_TRNG_VID1_RNG_MIN_REV_MASK)
#define TRNG_SA_TRNG_VID1_RNG_MAJ_REV_MASK       0xFF00u
#define TRNG_SA_TRNG_VID1_RNG_MAJ_REV_SHIFT      8
#define TRNG_SA_TRNG_VID1_RNG_MAJ_REV_WIDTH      8
#define TRNG_SA_TRNG_VID1_RNG_MAJ_REV(x)         (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_VID1_RNG_MAJ_REV_SHIFT))&TRNG_SA_TRNG_VID1_RNG_MAJ_REV_MASK)
#define TRNG_SA_TRNG_VID1_RNG_IP_ID_MASK         0xFFFF0000u
#define TRNG_SA_TRNG_VID1_RNG_IP_ID_SHIFT        16
#define TRNG_SA_TRNG_VID1_RNG_IP_ID_WIDTH        16
#define TRNG_SA_TRNG_VID1_RNG_IP_ID(x)           (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_VID1_RNG_IP_ID_SHIFT))&TRNG_SA_TRNG_VID1_RNG_IP_ID_MASK)
/* SA_TRNG_VID2 Bit Fields */
#define TRNG_SA_TRNG_VID2_RNG_CONFIG_OPT_MASK    0xFFu
#define TRNG_SA_TRNG_VID2_RNG_CONFIG_OPT_SHIFT   0
#define TRNG_SA_TRNG_VID2_RNG_CONFIG_OPT_WIDTH   8
#define TRNG_SA_TRNG_VID2_RNG_CONFIG_OPT(x)      (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_VID2_RNG_CONFIG_OPT_SHIFT))&TRNG_SA_TRNG_VID2_RNG_CONFIG_OPT_MASK)
#define TRNG_SA_TRNG_VID2_RNG_ECO_REV_MASK       0xFF00u
#define TRNG_SA_TRNG_VID2_RNG_ECO_REV_SHIFT      8
#define TRNG_SA_TRNG_VID2_RNG_ECO_REV_WIDTH      8
#define TRNG_SA_TRNG_VID2_RNG_ECO_REV(x)         (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_VID2_RNG_ECO_REV_SHIFT))&TRNG_SA_TRNG_VID2_RNG_ECO_REV_MASK)
#define TRNG_SA_TRNG_VID2_RNG_INTG_OPT_MASK      0xFF0000u
#define TRNG_SA_TRNG_VID2_RNG_INTG_OPT_SHIFT     16
#define TRNG_SA_TRNG_VID2_RNG_INTG_OPT_WIDTH     8
#define TRNG_SA_TRNG_VID2_RNG_INTG_OPT(x)        (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_VID2_RNG_INTG_OPT_SHIFT))&TRNG_SA_TRNG_VID2_RNG_INTG_OPT_MASK)
#define TRNG_SA_TRNG_VID2_RNG_ERA_MASK           0xFF000000u
#define TRNG_SA_TRNG_VID2_RNG_ERA_SHIFT          24
#define TRNG_SA_TRNG_VID2_RNG_ERA_WIDTH          8
#define TRNG_SA_TRNG_VID2_RNG_ERA(x)             (((uint32_t)(((uint32_t)(x))<<TRNG_SA_TRNG_VID2_RNG_ERA_SHIFT))&TRNG_SA_TRNG_VID2_RNG_ERA_MASK)

/*!
 * @}
 */ /* end of group TRNG_Register_Masks */


/* TRNG - Peripheral instance base addresses */
/** Peripheral TRNG base address */
#define TRNG_BASE                                (0x400A5000u)
/** Peripheral TRNG base pointer */
#define TRNG                                     ((TRNG_Type *)TRNG_BASE)
#define TRNG_BASE_PTR                            (TRNG)
/** Array initializer of TRNG peripheral base addresses */
#define TRNG_BASE_ADDRS                          { TRNG_BASE }
/** Array initializer of TRNG peripheral base pointers */
#define TRNG_BASE_PTRS                           { TRNG }

/* ----------------------------------------------------------------------------
   -- TRNG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRNG_Register_Accessor_Macros TRNG - Register accessor macros
 * @{
 */


/* TRNG - Register instance definitions */
/* TRNG */
#define TRNG_RTMCTL                              TRNG_RTMCTL_REG(TRNG)
#define TRNG_RTSCMISC                            TRNG_RTSCMISC_REG(TRNG)
#define TRNG_RTPKRRNG                            TRNG_RTPKRRNG_REG(TRNG)
#define TRNG_RTPKRMAX                            TRNG_RTPKRMAX_REG(TRNG)
#define TRNG_RTPKRSQ                             TRNG_RTPKRSQ_REG(TRNG)
#define TRNG_RTSDCTL                             TRNG_RTSDCTL_REG(TRNG)
#define TRNG_RTSBLIM                             TRNG_RTSBLIM_REG(TRNG)
#define TRNG_RTTOTSAM                            TRNG_RTTOTSAM_REG(TRNG)
#define TRNG_RTFRQMIN                            TRNG_RTFRQMIN_REG(TRNG)
#define TRNG_RTFRQCNT                            TRNG_RTFRQCNT_REG(TRNG)
#define TRNG_RTFRQMAX                            TRNG_RTFRQMAX_REG(TRNG)
#define TRNG_RTSCMC                              TRNG_RTSCMC_REG(TRNG)
#define TRNG_RTSCML                              TRNG_RTSCML_REG(TRNG)
#define TRNG_RTSCR1C                             TRNG_RTSCR1C_REG(TRNG)
#define TRNG_RTSCR1L                             TRNG_RTSCR1L_REG(TRNG)
#define TRNG_RTSCR2C                             TRNG_RTSCR2C_REG(TRNG)
#define TRNG_RTSCR2L                             TRNG_RTSCR2L_REG(TRNG)
#define TRNG_RTSCR3C                             TRNG_RTSCR3C_REG(TRNG)
#define TRNG_RTSCR3L                             TRNG_RTSCR3L_REG(TRNG)
#define TRNG_RTSCR4C                             TRNG_RTSCR4C_REG(TRNG)
#define TRNG_RTSCR4L                             TRNG_RTSCR4L_REG(TRNG)
#define TRNG_RTSCR5C                             TRNG_RTSCR5C_REG(TRNG)
#define TRNG_RTSCR5L                             TRNG_RTSCR5L_REG(TRNG)
#define TRNG_RTSCR6PC                            TRNG_RTSCR6PC_REG(TRNG)
#define TRNG_RTSCR6PL                            TRNG_RTSCR6PL_REG(TRNG)
#define TRNG_RTSTATUS                            TRNG_RTSTATUS_REG(TRNG)
#define TRNG_RTENT0                              TRNG_RTENT0_REG(TRNG)
#define TRNG_RTENT1                              TRNG_RTENT1_REG(TRNG)
#define TRNG_RTENT2                              TRNG_RTENT2_REG(TRNG)
#define TRNG_RTENT3                              TRNG_RTENT3_REG(TRNG)
#define TRNG_RTENT4                              TRNG_RTENT4_REG(TRNG)
#define TRNG_RTENT5                              TRNG_RTENT5_REG(TRNG)
#define TRNG_RTENT6                              TRNG_RTENT6_REG(TRNG)
#define TRNG_RTENT7                              TRNG_RTENT7_REG(TRNG)
#define TRNG_RTENT8                              TRNG_RTENT8_REG(TRNG)
#define TRNG_RTENT9                              TRNG_RTENT9_REG(TRNG)
#define TRNG_RTENT10                             TRNG_RTENT10_REG(TRNG)
#define TRNG_RTENT11                             TRNG_RTENT11_REG(TRNG)
#define TRNG_RTENT12                             TRNG_RTENT12_REG(TRNG)
#define TRNG_RTENT13                             TRNG_RTENT13_REG(TRNG)
#define TRNG_RTENT14                             TRNG_RTENT14_REG(TRNG)
#define TRNG_RTENT15                             TRNG_RTENT15_REG(TRNG)
#define TRNG_RTPKRCNT10                          TRNG_RTPKRCNT10_REG(TRNG)
#define TRNG_RTPKRCNT32                          TRNG_RTPKRCNT32_REG(TRNG)
#define TRNG_RTPKRCNT54                          TRNG_RTPKRCNT54_REG(TRNG)
#define TRNG_RTPKRCNT76                          TRNG_RTPKRCNT76_REG(TRNG)
#define TRNG_RTPKRCNT98                          TRNG_RTPKRCNT98_REG(TRNG)
#define TRNG_RTPKRCNTBA                          TRNG_RTPKRCNTBA_REG(TRNG)
#define TRNG_RTPKRCNTDC                          TRNG_RTPKRCNTDC_REG(TRNG)
#define TRNG_RTPKRCNTFE                          TRNG_RTPKRCNTFE_REG(TRNG)
#define TRNG_SA_TRNG_SEC_CFG                     TRNG_SA_TRNG_SEC_CFG_REG(TRNG)
#define TRNG_SA_TRNG_INT_CTRL                    TRNG_SA_TRNG_INT_CTRL_REG(TRNG)
#define TRNG_SA_TRNG_INT_MASK                    TRNG_SA_TRNG_INT_MASK_REG(TRNG)
#define TRNG_SA_TRNG_INT_STATUS                  TRNG_SA_TRNG_INT_STATUS_REG(TRNG)
#define TRNG_SA_TRNG_VID1                        TRNG_SA_TRNG_VID1_REG(TRNG)
#define TRNG_SA_TRNG_VID2                        TRNG_SA_TRNG_VID2_REG(TRNG)

/*!
 * @}
 */ /* end of group TRNG_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group TRNG_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- TSI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSI_Peripheral_Access_Layer TSI Peripheral Access Layer
 * @{
 */

/** TSI - Register Layout Typedef */
typedef struct {
  __IO uint32_t GENCS;                             /**< TSI General Control and Status Register, offset: 0x0 */
  __IO uint32_t DATA;                              /**< TSI DATA Register, offset: 0x4 */
  __IO uint32_t TSHD;                              /**< TSI Threshold Register, offset: 0x8 */
} TSI_Type, *TSI_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- TSI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSI_Register_Accessor_Macros TSI - Register accessor macros
 * @{
 */


/* TSI - Register accessors */
#define TSI_GENCS_REG(base)                      ((base)->GENCS)
#define TSI_DATA_REG(base)                       ((base)->DATA)
#define TSI_TSHD_REG(base)                       ((base)->TSHD)

/*!
 * @}
 */ /* end of group TSI_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- TSI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSI_Register_Masks TSI Register Masks
 * @{
 */

/* GENCS Bit Fields */
#define TSI_GENCS_EOSDMEO_MASK                   0x1u
#define TSI_GENCS_EOSDMEO_SHIFT                  0
#define TSI_GENCS_EOSDMEO_WIDTH                  1
#define TSI_GENCS_EOSDMEO(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_EOSDMEO_SHIFT))&TSI_GENCS_EOSDMEO_MASK)
#define TSI_GENCS_CURSW_MASK                     0x2u
#define TSI_GENCS_CURSW_SHIFT                    1
#define TSI_GENCS_CURSW_WIDTH                    1
#define TSI_GENCS_CURSW(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_CURSW_SHIFT))&TSI_GENCS_CURSW_MASK)
#define TSI_GENCS_EOSF_MASK                      0x4u
#define TSI_GENCS_EOSF_SHIFT                     2
#define TSI_GENCS_EOSF_WIDTH                     1
#define TSI_GENCS_EOSF(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_EOSF_SHIFT))&TSI_GENCS_EOSF_MASK)
#define TSI_GENCS_SCNIP_MASK                     0x8u
#define TSI_GENCS_SCNIP_SHIFT                    3
#define TSI_GENCS_SCNIP_WIDTH                    1
#define TSI_GENCS_SCNIP(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_SCNIP_SHIFT))&TSI_GENCS_SCNIP_MASK)
#define TSI_GENCS_STM_MASK                       0x10u
#define TSI_GENCS_STM_SHIFT                      4
#define TSI_GENCS_STM_WIDTH                      1
#define TSI_GENCS_STM(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_STM_SHIFT))&TSI_GENCS_STM_MASK)
#define TSI_GENCS_STPE_MASK                      0x20u
#define TSI_GENCS_STPE_SHIFT                     5
#define TSI_GENCS_STPE_WIDTH                     1
#define TSI_GENCS_STPE(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_STPE_SHIFT))&TSI_GENCS_STPE_MASK)
#define TSI_GENCS_TSIIEN_MASK                    0x40u
#define TSI_GENCS_TSIIEN_SHIFT                   6
#define TSI_GENCS_TSIIEN_WIDTH                   1
#define TSI_GENCS_TSIIEN(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_TSIIEN_SHIFT))&TSI_GENCS_TSIIEN_MASK)
#define TSI_GENCS_TSIEN_MASK                     0x80u
#define TSI_GENCS_TSIEN_SHIFT                    7
#define TSI_GENCS_TSIEN_WIDTH                    1
#define TSI_GENCS_TSIEN(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_TSIEN_SHIFT))&TSI_GENCS_TSIEN_MASK)
#define TSI_GENCS_NSCN_MASK                      0x1F00u
#define TSI_GENCS_NSCN_SHIFT                     8
#define TSI_GENCS_NSCN_WIDTH                     5
#define TSI_GENCS_NSCN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_NSCN_SHIFT))&TSI_GENCS_NSCN_MASK)
#define TSI_GENCS_PS_MASK                        0xE000u
#define TSI_GENCS_PS_SHIFT                       13
#define TSI_GENCS_PS_WIDTH                       3
#define TSI_GENCS_PS(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_PS_SHIFT))&TSI_GENCS_PS_MASK)
#define TSI_GENCS_EXTCHRG_MASK                   0x70000u
#define TSI_GENCS_EXTCHRG_SHIFT                  16
#define TSI_GENCS_EXTCHRG_WIDTH                  3
#define TSI_GENCS_EXTCHRG(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_EXTCHRG_SHIFT))&TSI_GENCS_EXTCHRG_MASK)
#define TSI_GENCS_DVOLT_MASK                     0x180000u
#define TSI_GENCS_DVOLT_SHIFT                    19
#define TSI_GENCS_DVOLT_WIDTH                    2
#define TSI_GENCS_DVOLT(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_DVOLT_SHIFT))&TSI_GENCS_DVOLT_MASK)
#define TSI_GENCS_REFCHRG_MASK                   0xE00000u
#define TSI_GENCS_REFCHRG_SHIFT                  21
#define TSI_GENCS_REFCHRG_WIDTH                  3
#define TSI_GENCS_REFCHRG(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_REFCHRG_SHIFT))&TSI_GENCS_REFCHRG_MASK)
#define TSI_GENCS_MODE_MASK                      0xF000000u
#define TSI_GENCS_MODE_SHIFT                     24
#define TSI_GENCS_MODE_WIDTH                     4
#define TSI_GENCS_MODE(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_MODE_SHIFT))&TSI_GENCS_MODE_MASK)
#define TSI_GENCS_ESOR_MASK                      0x10000000u
#define TSI_GENCS_ESOR_SHIFT                     28
#define TSI_GENCS_ESOR_WIDTH                     1
#define TSI_GENCS_ESOR(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_ESOR_SHIFT))&TSI_GENCS_ESOR_MASK)
#define TSI_GENCS_OUTRGF_MASK                    0x80000000u
#define TSI_GENCS_OUTRGF_SHIFT                   31
#define TSI_GENCS_OUTRGF_WIDTH                   1
#define TSI_GENCS_OUTRGF(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_OUTRGF_SHIFT))&TSI_GENCS_OUTRGF_MASK)
/* DATA Bit Fields */
#define TSI_DATA_TSICNT_MASK                     0xFFFFu
#define TSI_DATA_TSICNT_SHIFT                    0
#define TSI_DATA_TSICNT_WIDTH                    16
#define TSI_DATA_TSICNT(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_DATA_TSICNT_SHIFT))&TSI_DATA_TSICNT_MASK)
#define TSI_DATA_SWTS_MASK                       0x400000u
#define TSI_DATA_SWTS_SHIFT                      22
#define TSI_DATA_SWTS_WIDTH                      1
#define TSI_DATA_SWTS(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_DATA_SWTS_SHIFT))&TSI_DATA_SWTS_MASK)
#define TSI_DATA_DMAEN_MASK                      0x800000u
#define TSI_DATA_DMAEN_SHIFT                     23
#define TSI_DATA_DMAEN_WIDTH                     1
#define TSI_DATA_DMAEN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_DATA_DMAEN_SHIFT))&TSI_DATA_DMAEN_MASK)
#define TSI_DATA_TSICH_MASK                      0xF0000000u
#define TSI_DATA_TSICH_SHIFT                     28
#define TSI_DATA_TSICH_WIDTH                     4
#define TSI_DATA_TSICH(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_DATA_TSICH_SHIFT))&TSI_DATA_TSICH_MASK)
/* TSHD Bit Fields */
#define TSI_TSHD_THRESL_MASK                     0xFFFFu
#define TSI_TSHD_THRESL_SHIFT                    0
#define TSI_TSHD_THRESL_WIDTH                    16
#define TSI_TSHD_THRESL(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_TSHD_THRESL_SHIFT))&TSI_TSHD_THRESL_MASK)
#define TSI_TSHD_THRESH_MASK                     0xFFFF0000u
#define TSI_TSHD_THRESH_SHIFT                    16
#define TSI_TSHD_THRESH_WIDTH                    16
#define TSI_TSHD_THRESH(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_TSHD_THRESH_SHIFT))&TSI_TSHD_THRESH_MASK)

/*!
 * @}
 */ /* end of group TSI_Register_Masks */


/* TSI - Peripheral instance base addresses */
/** Peripheral TSI0 base address */
#define TSI0_BASE                                (0x40062000u)
/** Peripheral TSI0 base pointer */
#define TSI0                                     ((TSI_Type *)TSI0_BASE)
#define TSI0_BASE_PTR                            (TSI0)
/** Array initializer of TSI peripheral base addresses */
#define TSI_BASE_ADDRS                           { TSI0_BASE }
/** Array initializer of TSI peripheral base pointers */
#define TSI_BASE_PTRS                            { TSI0 }

/* ----------------------------------------------------------------------------
   -- TSI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSI_Register_Accessor_Macros TSI - Register accessor macros
 * @{
 */


/* TSI - Register instance definitions */
/* TSI0 */
#define TSI0_GENCS                               TSI_GENCS_REG(TSI0)
#define TSI0_DATA                                TSI_DATA_REG(TSI0)
#define TSI0_TSHD                                TSI_TSHD_REG(TSI0)

/*!
 * @}
 */ /* end of group TSI_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group TSI_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- TSTMR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSTMR_Peripheral_Access_Layer TSTMR Peripheral Access Layer
 * @{
 */

/** TSTMR - Register Layout Typedef */
typedef struct {
  __I  uint32_t L;                                 /**< Time Stamp Timer Register Low, offset: 0x0 */
  __I  uint32_t H;                                 /**< Time Stamp Timer Register High, offset: 0x4 */
} TSTMR_Type, *TSTMR_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- TSTMR - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSTMR_Register_Accessor_Macros TSTMR - Register accessor macros
 * @{
 */


/* TSTMR - Register accessors */
#define TSTMR_L_REG(base)                        ((base)->L)
#define TSTMR_H_REG(base)                        ((base)->H)

/*!
 * @}
 */ /* end of group TSTMR_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- TSTMR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSTMR_Register_Masks TSTMR Register Masks
 * @{
 */

/* L Bit Fields */
#define TSTMR_L_VALUE_MASK                       0xFFFFFFFFu
#define TSTMR_L_VALUE_SHIFT                      0
#define TSTMR_L_VALUE_WIDTH                      32
#define TSTMR_L_VALUE(x)                         (((uint32_t)(((uint32_t)(x))<<TSTMR_L_VALUE_SHIFT))&TSTMR_L_VALUE_MASK)
/* H Bit Fields */
#define TSTMR_H_VALUE_MASK                       0xFFFFFFu
#define TSTMR_H_VALUE_SHIFT                      0
#define TSTMR_H_VALUE_WIDTH                      24
#define TSTMR_H_VALUE(x)                         (((uint32_t)(((uint32_t)(x))<<TSTMR_H_VALUE_SHIFT))&TSTMR_H_VALUE_MASK)

/*!
 * @}
 */ /* end of group TSTMR_Register_Masks */


/* TSTMR - Peripheral instance base addresses */
/** Peripheral TSTMR0 base address */
#define TSTMR0_BASE                              (0x400750F0u)
/** Peripheral TSTMR0 base pointer */
#define TSTMR0                                   ((TSTMR_Type *)TSTMR0_BASE)
#define TSTMR0_BASE_PTR                          (TSTMR0)
/** Peripheral TSTMR1 base address */
#define TSTMR1_BASE                              (0x400F50F0u)
/** Peripheral TSTMR1 base pointer */
#define TSTMR1                                   ((TSTMR_Type *)TSTMR1_BASE)
#define TSTMR1_BASE_PTR                          (TSTMR1)
/** Array initializer of TSTMR peripheral base addresses */
#define TSTMR_BASE_ADDRS                         { TSTMR0_BASE, TSTMR1_BASE }
/** Array initializer of TSTMR peripheral base pointers */
#define TSTMR_BASE_PTRS                          { TSTMR0, TSTMR1 }

/* ----------------------------------------------------------------------------
   -- TSTMR - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSTMR_Register_Accessor_Macros TSTMR - Register accessor macros
 * @{
 */


/* TSTMR - Register instance definitions */
/* TSTMR0 */
#define TSTMR0_L                                 TSTMR_L_REG(TSTMR0)
#define TSTMR0_H                                 TSTMR_H_REG(TSTMR0)
/* TSTMR1 */
#define TSTMR1_L                                 TSTMR_L_REG(TSTMR1)
#define TSTMR1_H                                 TSTMR_H_REG(TSTMR1)

/*!
 * @}
 */ /* end of group TSTMR_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group TSTMR_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- USB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Peripheral_Access_Layer USB Peripheral Access Layer
 * @{
 */

/** USB - Register Layout Typedef */
typedef struct {
  __I  uint8_t PERID;                              /**< Peripheral ID register, offset: 0x0 */
       uint8_t RESERVED_0[3];
  __I  uint8_t IDCOMP;                             /**< Peripheral ID Complement register, offset: 0x4 */
       uint8_t RESERVED_1[3];
  __I  uint8_t REV;                                /**< Peripheral Revision register, offset: 0x8 */
       uint8_t RESERVED_2[3];
  __I  uint8_t ADDINFO;                            /**< Peripheral Additional Info register, offset: 0xC */
       uint8_t RESERVED_3[3];
  __IO uint8_t OTGISTAT;                           /**< OTG Interrupt Status register, offset: 0x10 */
       uint8_t RESERVED_4[3];
  __IO uint8_t OTGICR;                             /**< OTG Interrupt Control register, offset: 0x14 */
       uint8_t RESERVED_5[3];
  __IO uint8_t OTGSTAT;                            /**< OTG Status register, offset: 0x18 */
       uint8_t RESERVED_6[3];
  __IO uint8_t OTGCTL;                             /**< OTG Control register, offset: 0x1C */
       uint8_t RESERVED_7[99];
  __IO uint8_t ISTAT;                              /**< Interrupt Status register, offset: 0x80 */
       uint8_t RESERVED_8[3];
  __IO uint8_t INTEN;                              /**< Interrupt Enable register, offset: 0x84 */
       uint8_t RESERVED_9[3];
  __IO uint8_t ERRSTAT;                            /**< Error Interrupt Status register, offset: 0x88 */
       uint8_t RESERVED_10[3];
  __IO uint8_t ERREN;                              /**< Error Interrupt Enable register, offset: 0x8C */
       uint8_t RESERVED_11[3];
  __I  uint8_t STAT;                               /**< Status register, offset: 0x90 */
       uint8_t RESERVED_12[3];
  __IO uint8_t CTL;                                /**< Control register, offset: 0x94 */
       uint8_t RESERVED_13[3];
  __IO uint8_t ADDR;                               /**< Address register, offset: 0x98 */
       uint8_t RESERVED_14[3];
  __IO uint8_t BDTPAGE1;                           /**< BDT Page register 1, offset: 0x9C */
       uint8_t RESERVED_15[3];
  __IO uint8_t FRMNUML;                            /**< Frame Number register Low, offset: 0xA0 */
       uint8_t RESERVED_16[3];
  __IO uint8_t FRMNUMH;                            /**< Frame Number register High, offset: 0xA4 */
       uint8_t RESERVED_17[3];
  __IO uint8_t TOKEN;                              /**< Token register, offset: 0xA8 */
       uint8_t RESERVED_18[3];
  __IO uint8_t SOFTHLD;                            /**< SOF Threshold register, offset: 0xAC */
       uint8_t RESERVED_19[3];
  __IO uint8_t BDTPAGE2;                           /**< BDT Page Register 2, offset: 0xB0 */
       uint8_t RESERVED_20[3];
  __IO uint8_t BDTPAGE3;                           /**< BDT Page Register 3, offset: 0xB4 */
       uint8_t RESERVED_21[11];
  struct {                                         /* offset: 0xC0, array step: 0x4 */
    __IO uint8_t ENDPT;                              /**< Endpoint Control register, array offset: 0xC0, array step: 0x4 */
         uint8_t RESERVED_0[3];
  } ENDPOINT[16];
  __IO uint8_t USBCTRL;                            /**< USB Control register, offset: 0x100 */
       uint8_t RESERVED_22[3];
  __I  uint8_t OBSERVE;                            /**< USB OTG Observe register, offset: 0x104 */
       uint8_t RESERVED_23[3];
  __IO uint8_t CONTROL;                            /**< USB OTG Control register, offset: 0x108 */
       uint8_t RESERVED_24[3];
  __IO uint8_t USBTRC0;                            /**< USB Transceiver Control register 0, offset: 0x10C */
       uint8_t RESERVED_25[7];
  __IO uint8_t USBFRMADJUST;                       /**< Frame Adjust Register, offset: 0x114 */
       uint8_t RESERVED_26[15];
  __IO uint8_t KEEP_ALIVE_CTRL;                    /**< Keep Alive mode control, offset: 0x124 */
       uint8_t RESERVED_27[3];
  __IO uint8_t KEEP_ALIVE_WKCTRL;                  /**< Keep Alive mode wakeup control, offset: 0x128 */
       uint8_t RESERVED_28[3];
  __IO uint8_t MISCCTRL;                           /**< Miscellaneous Control register, offset: 0x12C */
       uint8_t RESERVED_29[19];
  __IO uint8_t CLK_RECOVER_CTRL;                   /**< USB Clock recovery control, offset: 0x140 */
       uint8_t RESERVED_30[3];
  __IO uint8_t CLK_RECOVER_IRC_EN;                 /**< IRC48M oscillator enable register, offset: 0x144 */
       uint8_t RESERVED_31[15];
  __IO uint8_t CLK_RECOVER_INT_EN;                 /**< Clock recovery combined interrupt enable, offset: 0x154 */
       uint8_t RESERVED_32[7];
  __IO uint8_t CLK_RECOVER_INT_STATUS;             /**< Clock recovery separated interrupt status, offset: 0x15C */
} USB_Type, *USB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- USB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Register_Accessor_Macros USB - Register accessor macros
 * @{
 */


/* USB - Register accessors */
#define USB_PERID_REG(base)                      ((base)->PERID)
#define USB_IDCOMP_REG(base)                     ((base)->IDCOMP)
#define USB_REV_REG(base)                        ((base)->REV)
#define USB_ADDINFO_REG(base)                    ((base)->ADDINFO)
#define USB_OTGISTAT_REG(base)                   ((base)->OTGISTAT)
#define USB_OTGICR_REG(base)                     ((base)->OTGICR)
#define USB_OTGSTAT_REG(base)                    ((base)->OTGSTAT)
#define USB_OTGCTL_REG(base)                     ((base)->OTGCTL)
#define USB_ISTAT_REG(base)                      ((base)->ISTAT)
#define USB_INTEN_REG(base)                      ((base)->INTEN)
#define USB_ERRSTAT_REG(base)                    ((base)->ERRSTAT)
#define USB_ERREN_REG(base)                      ((base)->ERREN)
#define USB_STAT_REG(base)                       ((base)->STAT)
#define USB_CTL_REG(base)                        ((base)->CTL)
#define USB_ADDR_REG(base)                       ((base)->ADDR)
#define USB_BDTPAGE1_REG(base)                   ((base)->BDTPAGE1)
#define USB_FRMNUML_REG(base)                    ((base)->FRMNUML)
#define USB_FRMNUMH_REG(base)                    ((base)->FRMNUMH)
#define USB_TOKEN_REG(base)                      ((base)->TOKEN)
#define USB_SOFTHLD_REG(base)                    ((base)->SOFTHLD)
#define USB_BDTPAGE2_REG(base)                   ((base)->BDTPAGE2)
#define USB_BDTPAGE3_REG(base)                   ((base)->BDTPAGE3)
#define USB_ENDPT_REG(base,index)                ((base)->ENDPOINT[index].ENDPT)
#define USB_ENDPT_COUNT                          16
#define USB_USBCTRL_REG(base)                    ((base)->USBCTRL)
#define USB_OBSERVE_REG(base)                    ((base)->OBSERVE)
#define USB_CONTROL_REG(base)                    ((base)->CONTROL)
#define USB_USBTRC0_REG(base)                    ((base)->USBTRC0)
#define USB_USBFRMADJUST_REG(base)               ((base)->USBFRMADJUST)
#define USB_KEEP_ALIVE_CTRL_REG(base)            ((base)->KEEP_ALIVE_CTRL)
#define USB_KEEP_ALIVE_WKCTRL_REG(base)          ((base)->KEEP_ALIVE_WKCTRL)
#define USB_MISCCTRL_REG(base)                   ((base)->MISCCTRL)
#define USB_CLK_RECOVER_CTRL_REG(base)           ((base)->CLK_RECOVER_CTRL)
#define USB_CLK_RECOVER_IRC_EN_REG(base)         ((base)->CLK_RECOVER_IRC_EN)
#define USB_CLK_RECOVER_INT_EN_REG(base)         ((base)->CLK_RECOVER_INT_EN)
#define USB_CLK_RECOVER_INT_STATUS_REG(base)     ((base)->CLK_RECOVER_INT_STATUS)

/*!
 * @}
 */ /* end of group USB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- USB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Register_Masks USB Register Masks
 * @{
 */

/* PERID Bit Fields */
#define USB_PERID_ID_MASK                        0x3Fu
#define USB_PERID_ID_SHIFT                       0
#define USB_PERID_ID_WIDTH                       6
#define USB_PERID_ID(x)                          (((uint8_t)(((uint8_t)(x))<<USB_PERID_ID_SHIFT))&USB_PERID_ID_MASK)
/* IDCOMP Bit Fields */
#define USB_IDCOMP_NID_MASK                      0x3Fu
#define USB_IDCOMP_NID_SHIFT                     0
#define USB_IDCOMP_NID_WIDTH                     6
#define USB_IDCOMP_NID(x)                        (((uint8_t)(((uint8_t)(x))<<USB_IDCOMP_NID_SHIFT))&USB_IDCOMP_NID_MASK)
/* REV Bit Fields */
#define USB_REV_REV_MASK                         0xFFu
#define USB_REV_REV_SHIFT                        0
#define USB_REV_REV_WIDTH                        8
#define USB_REV_REV(x)                           (((uint8_t)(((uint8_t)(x))<<USB_REV_REV_SHIFT))&USB_REV_REV_MASK)
/* ADDINFO Bit Fields */
#define USB_ADDINFO_IEHOST_MASK                  0x1u
#define USB_ADDINFO_IEHOST_SHIFT                 0
#define USB_ADDINFO_IEHOST_WIDTH                 1
#define USB_ADDINFO_IEHOST(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ADDINFO_IEHOST_SHIFT))&USB_ADDINFO_IEHOST_MASK)
/* OTGISTAT Bit Fields */
#define USB_OTGISTAT_AVBUSCHG_MASK               0x1u
#define USB_OTGISTAT_AVBUSCHG_SHIFT              0
#define USB_OTGISTAT_AVBUSCHG_WIDTH              1
#define USB_OTGISTAT_AVBUSCHG(x)                 (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_AVBUSCHG_SHIFT))&USB_OTGISTAT_AVBUSCHG_MASK)
#define USB_OTGISTAT_B_SESS_CHG_MASK             0x4u
#define USB_OTGISTAT_B_SESS_CHG_SHIFT            2
#define USB_OTGISTAT_B_SESS_CHG_WIDTH            1
#define USB_OTGISTAT_B_SESS_CHG(x)               (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_B_SESS_CHG_SHIFT))&USB_OTGISTAT_B_SESS_CHG_MASK)
#define USB_OTGISTAT_SESSVLDCHG_MASK             0x8u
#define USB_OTGISTAT_SESSVLDCHG_SHIFT            3
#define USB_OTGISTAT_SESSVLDCHG_WIDTH            1
#define USB_OTGISTAT_SESSVLDCHG(x)               (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_SESSVLDCHG_SHIFT))&USB_OTGISTAT_SESSVLDCHG_MASK)
#define USB_OTGISTAT_LINE_STATE_CHG_MASK         0x20u
#define USB_OTGISTAT_LINE_STATE_CHG_SHIFT        5
#define USB_OTGISTAT_LINE_STATE_CHG_WIDTH        1
#define USB_OTGISTAT_LINE_STATE_CHG(x)           (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_LINE_STATE_CHG_SHIFT))&USB_OTGISTAT_LINE_STATE_CHG_MASK)
#define USB_OTGISTAT_ONEMSEC_MASK                0x40u
#define USB_OTGISTAT_ONEMSEC_SHIFT               6
#define USB_OTGISTAT_ONEMSEC_WIDTH               1
#define USB_OTGISTAT_ONEMSEC(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_ONEMSEC_SHIFT))&USB_OTGISTAT_ONEMSEC_MASK)
#define USB_OTGISTAT_IDCHG_MASK                  0x80u
#define USB_OTGISTAT_IDCHG_SHIFT                 7
#define USB_OTGISTAT_IDCHG_WIDTH                 1
#define USB_OTGISTAT_IDCHG(x)                    (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_IDCHG_SHIFT))&USB_OTGISTAT_IDCHG_MASK)
/* OTGICR Bit Fields */
#define USB_OTGICR_AVBUSEN_MASK                  0x1u
#define USB_OTGICR_AVBUSEN_SHIFT                 0
#define USB_OTGICR_AVBUSEN_WIDTH                 1
#define USB_OTGICR_AVBUSEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_AVBUSEN_SHIFT))&USB_OTGICR_AVBUSEN_MASK)
#define USB_OTGICR_BSESSEN_MASK                  0x4u
#define USB_OTGICR_BSESSEN_SHIFT                 2
#define USB_OTGICR_BSESSEN_WIDTH                 1
#define USB_OTGICR_BSESSEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_BSESSEN_SHIFT))&USB_OTGICR_BSESSEN_MASK)
#define USB_OTGICR_SESSVLDEN_MASK                0x8u
#define USB_OTGICR_SESSVLDEN_SHIFT               3
#define USB_OTGICR_SESSVLDEN_WIDTH               1
#define USB_OTGICR_SESSVLDEN(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_SESSVLDEN_SHIFT))&USB_OTGICR_SESSVLDEN_MASK)
#define USB_OTGICR_LINESTATEEN_MASK              0x20u
#define USB_OTGICR_LINESTATEEN_SHIFT             5
#define USB_OTGICR_LINESTATEEN_WIDTH             1
#define USB_OTGICR_LINESTATEEN(x)                (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_LINESTATEEN_SHIFT))&USB_OTGICR_LINESTATEEN_MASK)
#define USB_OTGICR_ONEMSECEN_MASK                0x40u
#define USB_OTGICR_ONEMSECEN_SHIFT               6
#define USB_OTGICR_ONEMSECEN_WIDTH               1
#define USB_OTGICR_ONEMSECEN(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_ONEMSECEN_SHIFT))&USB_OTGICR_ONEMSECEN_MASK)
#define USB_OTGICR_IDEN_MASK                     0x80u
#define USB_OTGICR_IDEN_SHIFT                    7
#define USB_OTGICR_IDEN_WIDTH                    1
#define USB_OTGICR_IDEN(x)                       (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_IDEN_SHIFT))&USB_OTGICR_IDEN_MASK)
/* OTGSTAT Bit Fields */
#define USB_OTGSTAT_AVBUSVLD_MASK                0x1u
#define USB_OTGSTAT_AVBUSVLD_SHIFT               0
#define USB_OTGSTAT_AVBUSVLD_WIDTH               1
#define USB_OTGSTAT_AVBUSVLD(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_AVBUSVLD_SHIFT))&USB_OTGSTAT_AVBUSVLD_MASK)
#define USB_OTGSTAT_BSESSEND_MASK                0x4u
#define USB_OTGSTAT_BSESSEND_SHIFT               2
#define USB_OTGSTAT_BSESSEND_WIDTH               1
#define USB_OTGSTAT_BSESSEND(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_BSESSEND_SHIFT))&USB_OTGSTAT_BSESSEND_MASK)
#define USB_OTGSTAT_SESS_VLD_MASK                0x8u
#define USB_OTGSTAT_SESS_VLD_SHIFT               3
#define USB_OTGSTAT_SESS_VLD_WIDTH               1
#define USB_OTGSTAT_SESS_VLD(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_SESS_VLD_SHIFT))&USB_OTGSTAT_SESS_VLD_MASK)
#define USB_OTGSTAT_LINESTATESTABLE_MASK         0x20u
#define USB_OTGSTAT_LINESTATESTABLE_SHIFT        5
#define USB_OTGSTAT_LINESTATESTABLE_WIDTH        1
#define USB_OTGSTAT_LINESTATESTABLE(x)           (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_LINESTATESTABLE_SHIFT))&USB_OTGSTAT_LINESTATESTABLE_MASK)
#define USB_OTGSTAT_ONEMSECEN_MASK               0x40u
#define USB_OTGSTAT_ONEMSECEN_SHIFT              6
#define USB_OTGSTAT_ONEMSECEN_WIDTH              1
#define USB_OTGSTAT_ONEMSECEN(x)                 (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_ONEMSECEN_SHIFT))&USB_OTGSTAT_ONEMSECEN_MASK)
#define USB_OTGSTAT_ID_MASK                      0x80u
#define USB_OTGSTAT_ID_SHIFT                     7
#define USB_OTGSTAT_ID_WIDTH                     1
#define USB_OTGSTAT_ID(x)                        (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_ID_SHIFT))&USB_OTGSTAT_ID_MASK)
/* OTGCTL Bit Fields */
#define USB_OTGCTL_OTGEN_MASK                    0x4u
#define USB_OTGCTL_OTGEN_SHIFT                   2
#define USB_OTGCTL_OTGEN_WIDTH                   1
#define USB_OTGCTL_OTGEN(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OTGCTL_OTGEN_SHIFT))&USB_OTGCTL_OTGEN_MASK)
#define USB_OTGCTL_DMLOW_MASK                    0x10u
#define USB_OTGCTL_DMLOW_SHIFT                   4
#define USB_OTGCTL_DMLOW_WIDTH                   1
#define USB_OTGCTL_DMLOW(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OTGCTL_DMLOW_SHIFT))&USB_OTGCTL_DMLOW_MASK)
#define USB_OTGCTL_DPLOW_MASK                    0x20u
#define USB_OTGCTL_DPLOW_SHIFT                   5
#define USB_OTGCTL_DPLOW_WIDTH                   1
#define USB_OTGCTL_DPLOW(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OTGCTL_DPLOW_SHIFT))&USB_OTGCTL_DPLOW_MASK)
#define USB_OTGCTL_DPHIGH_MASK                   0x80u
#define USB_OTGCTL_DPHIGH_SHIFT                  7
#define USB_OTGCTL_DPHIGH_WIDTH                  1
#define USB_OTGCTL_DPHIGH(x)                     (((uint8_t)(((uint8_t)(x))<<USB_OTGCTL_DPHIGH_SHIFT))&USB_OTGCTL_DPHIGH_MASK)
/* ISTAT Bit Fields */
#define USB_ISTAT_USBRST_MASK                    0x1u
#define USB_ISTAT_USBRST_SHIFT                   0
#define USB_ISTAT_USBRST_WIDTH                   1
#define USB_ISTAT_USBRST(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_USBRST_SHIFT))&USB_ISTAT_USBRST_MASK)
#define USB_ISTAT_ERROR_MASK                     0x2u
#define USB_ISTAT_ERROR_SHIFT                    1
#define USB_ISTAT_ERROR_WIDTH                    1
#define USB_ISTAT_ERROR(x)                       (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_ERROR_SHIFT))&USB_ISTAT_ERROR_MASK)
#define USB_ISTAT_SOFTOK_MASK                    0x4u
#define USB_ISTAT_SOFTOK_SHIFT                   2
#define USB_ISTAT_SOFTOK_WIDTH                   1
#define USB_ISTAT_SOFTOK(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_SOFTOK_SHIFT))&USB_ISTAT_SOFTOK_MASK)
#define USB_ISTAT_TOKDNE_MASK                    0x8u
#define USB_ISTAT_TOKDNE_SHIFT                   3
#define USB_ISTAT_TOKDNE_WIDTH                   1
#define USB_ISTAT_TOKDNE(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_TOKDNE_SHIFT))&USB_ISTAT_TOKDNE_MASK)
#define USB_ISTAT_SLEEP_MASK                     0x10u
#define USB_ISTAT_SLEEP_SHIFT                    4
#define USB_ISTAT_SLEEP_WIDTH                    1
#define USB_ISTAT_SLEEP(x)                       (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_SLEEP_SHIFT))&USB_ISTAT_SLEEP_MASK)
#define USB_ISTAT_RESUME_MASK                    0x20u
#define USB_ISTAT_RESUME_SHIFT                   5
#define USB_ISTAT_RESUME_WIDTH                   1
#define USB_ISTAT_RESUME(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_RESUME_SHIFT))&USB_ISTAT_RESUME_MASK)
#define USB_ISTAT_ATTACH_MASK                    0x40u
#define USB_ISTAT_ATTACH_SHIFT                   6
#define USB_ISTAT_ATTACH_WIDTH                   1
#define USB_ISTAT_ATTACH(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_ATTACH_SHIFT))&USB_ISTAT_ATTACH_MASK)
#define USB_ISTAT_STALL_MASK                     0x80u
#define USB_ISTAT_STALL_SHIFT                    7
#define USB_ISTAT_STALL_WIDTH                    1
#define USB_ISTAT_STALL(x)                       (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_STALL_SHIFT))&USB_ISTAT_STALL_MASK)
/* INTEN Bit Fields */
#define USB_INTEN_USBRSTEN_MASK                  0x1u
#define USB_INTEN_USBRSTEN_SHIFT                 0
#define USB_INTEN_USBRSTEN_WIDTH                 1
#define USB_INTEN_USBRSTEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_USBRSTEN_SHIFT))&USB_INTEN_USBRSTEN_MASK)
#define USB_INTEN_ERROREN_MASK                   0x2u
#define USB_INTEN_ERROREN_SHIFT                  1
#define USB_INTEN_ERROREN_WIDTH                  1
#define USB_INTEN_ERROREN(x)                     (((uint8_t)(((uint8_t)(x))<<USB_INTEN_ERROREN_SHIFT))&USB_INTEN_ERROREN_MASK)
#define USB_INTEN_SOFTOKEN_MASK                  0x4u
#define USB_INTEN_SOFTOKEN_SHIFT                 2
#define USB_INTEN_SOFTOKEN_WIDTH                 1
#define USB_INTEN_SOFTOKEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_SOFTOKEN_SHIFT))&USB_INTEN_SOFTOKEN_MASK)
#define USB_INTEN_TOKDNEEN_MASK                  0x8u
#define USB_INTEN_TOKDNEEN_SHIFT                 3
#define USB_INTEN_TOKDNEEN_WIDTH                 1
#define USB_INTEN_TOKDNEEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_TOKDNEEN_SHIFT))&USB_INTEN_TOKDNEEN_MASK)
#define USB_INTEN_SLEEPEN_MASK                   0x10u
#define USB_INTEN_SLEEPEN_SHIFT                  4
#define USB_INTEN_SLEEPEN_WIDTH                  1
#define USB_INTEN_SLEEPEN(x)                     (((uint8_t)(((uint8_t)(x))<<USB_INTEN_SLEEPEN_SHIFT))&USB_INTEN_SLEEPEN_MASK)
#define USB_INTEN_RESUMEEN_MASK                  0x20u
#define USB_INTEN_RESUMEEN_SHIFT                 5
#define USB_INTEN_RESUMEEN_WIDTH                 1
#define USB_INTEN_RESUMEEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_RESUMEEN_SHIFT))&USB_INTEN_RESUMEEN_MASK)
#define USB_INTEN_ATTACHEN_MASK                  0x40u
#define USB_INTEN_ATTACHEN_SHIFT                 6
#define USB_INTEN_ATTACHEN_WIDTH                 1
#define USB_INTEN_ATTACHEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_ATTACHEN_SHIFT))&USB_INTEN_ATTACHEN_MASK)
#define USB_INTEN_STALLEN_MASK                   0x80u
#define USB_INTEN_STALLEN_SHIFT                  7
#define USB_INTEN_STALLEN_WIDTH                  1
#define USB_INTEN_STALLEN(x)                     (((uint8_t)(((uint8_t)(x))<<USB_INTEN_STALLEN_SHIFT))&USB_INTEN_STALLEN_MASK)
/* ERRSTAT Bit Fields */
#define USB_ERRSTAT_PIDERR_MASK                  0x1u
#define USB_ERRSTAT_PIDERR_SHIFT                 0
#define USB_ERRSTAT_PIDERR_WIDTH                 1
#define USB_ERRSTAT_PIDERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_PIDERR_SHIFT))&USB_ERRSTAT_PIDERR_MASK)
#define USB_ERRSTAT_CRC5EOF_MASK                 0x2u
#define USB_ERRSTAT_CRC5EOF_SHIFT                1
#define USB_ERRSTAT_CRC5EOF_WIDTH                1
#define USB_ERRSTAT_CRC5EOF(x)                   (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_CRC5EOF_SHIFT))&USB_ERRSTAT_CRC5EOF_MASK)
#define USB_ERRSTAT_CRC16_MASK                   0x4u
#define USB_ERRSTAT_CRC16_SHIFT                  2
#define USB_ERRSTAT_CRC16_WIDTH                  1
#define USB_ERRSTAT_CRC16(x)                     (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_CRC16_SHIFT))&USB_ERRSTAT_CRC16_MASK)
#define USB_ERRSTAT_DFN8_MASK                    0x8u
#define USB_ERRSTAT_DFN8_SHIFT                   3
#define USB_ERRSTAT_DFN8_WIDTH                   1
#define USB_ERRSTAT_DFN8(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_DFN8_SHIFT))&USB_ERRSTAT_DFN8_MASK)
#define USB_ERRSTAT_BTOERR_MASK                  0x10u
#define USB_ERRSTAT_BTOERR_SHIFT                 4
#define USB_ERRSTAT_BTOERR_WIDTH                 1
#define USB_ERRSTAT_BTOERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_BTOERR_SHIFT))&USB_ERRSTAT_BTOERR_MASK)
#define USB_ERRSTAT_DMAERR_MASK                  0x20u
#define USB_ERRSTAT_DMAERR_SHIFT                 5
#define USB_ERRSTAT_DMAERR_WIDTH                 1
#define USB_ERRSTAT_DMAERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_DMAERR_SHIFT))&USB_ERRSTAT_DMAERR_MASK)
#define USB_ERRSTAT_OWNERR_MASK                  0x40u
#define USB_ERRSTAT_OWNERR_SHIFT                 6
#define USB_ERRSTAT_OWNERR_WIDTH                 1
#define USB_ERRSTAT_OWNERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_OWNERR_SHIFT))&USB_ERRSTAT_OWNERR_MASK)
#define USB_ERRSTAT_BTSERR_MASK                  0x80u
#define USB_ERRSTAT_BTSERR_SHIFT                 7
#define USB_ERRSTAT_BTSERR_WIDTH                 1
#define USB_ERRSTAT_BTSERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_BTSERR_SHIFT))&USB_ERRSTAT_BTSERR_MASK)
/* ERREN Bit Fields */
#define USB_ERREN_PIDERREN_MASK                  0x1u
#define USB_ERREN_PIDERREN_SHIFT                 0
#define USB_ERREN_PIDERREN_WIDTH                 1
#define USB_ERREN_PIDERREN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERREN_PIDERREN_SHIFT))&USB_ERREN_PIDERREN_MASK)
#define USB_ERREN_CRC5EOFEN_MASK                 0x2u
#define USB_ERREN_CRC5EOFEN_SHIFT                1
#define USB_ERREN_CRC5EOFEN_WIDTH                1
#define USB_ERREN_CRC5EOFEN(x)                   (((uint8_t)(((uint8_t)(x))<<USB_ERREN_CRC5EOFEN_SHIFT))&USB_ERREN_CRC5EOFEN_MASK)
#define USB_ERREN_CRC16EN_MASK                   0x4u
#define USB_ERREN_CRC16EN_SHIFT                  2
#define USB_ERREN_CRC16EN_WIDTH                  1
#define USB_ERREN_CRC16EN(x)                     (((uint8_t)(((uint8_t)(x))<<USB_ERREN_CRC16EN_SHIFT))&USB_ERREN_CRC16EN_MASK)
#define USB_ERREN_DFN8EN_MASK                    0x8u
#define USB_ERREN_DFN8EN_SHIFT                   3
#define USB_ERREN_DFN8EN_WIDTH                   1
#define USB_ERREN_DFN8EN(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ERREN_DFN8EN_SHIFT))&USB_ERREN_DFN8EN_MASK)
#define USB_ERREN_BTOERREN_MASK                  0x10u
#define USB_ERREN_BTOERREN_SHIFT                 4
#define USB_ERREN_BTOERREN_WIDTH                 1
#define USB_ERREN_BTOERREN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERREN_BTOERREN_SHIFT))&USB_ERREN_BTOERREN_MASK)
#define USB_ERREN_DMAERREN_MASK                  0x20u
#define USB_ERREN_DMAERREN_SHIFT                 5
#define USB_ERREN_DMAERREN_WIDTH                 1
#define USB_ERREN_DMAERREN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERREN_DMAERREN_SHIFT))&USB_ERREN_DMAERREN_MASK)
#define USB_ERREN_OWNERREN_MASK                  0x40u
#define USB_ERREN_OWNERREN_SHIFT                 6
#define USB_ERREN_OWNERREN_WIDTH                 1
#define USB_ERREN_OWNERREN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERREN_OWNERREN_SHIFT))&USB_ERREN_OWNERREN_MASK)
#define USB_ERREN_BTSERREN_MASK                  0x80u
#define USB_ERREN_BTSERREN_SHIFT                 7
#define USB_ERREN_BTSERREN_WIDTH                 1
#define USB_ERREN_BTSERREN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERREN_BTSERREN_SHIFT))&USB_ERREN_BTSERREN_MASK)
/* STAT Bit Fields */
#define USB_STAT_ODD_MASK                        0x4u
#define USB_STAT_ODD_SHIFT                       2
#define USB_STAT_ODD_WIDTH                       1
#define USB_STAT_ODD(x)                          (((uint8_t)(((uint8_t)(x))<<USB_STAT_ODD_SHIFT))&USB_STAT_ODD_MASK)
#define USB_STAT_TX_MASK                         0x8u
#define USB_STAT_TX_SHIFT                        3
#define USB_STAT_TX_WIDTH                        1
#define USB_STAT_TX(x)                           (((uint8_t)(((uint8_t)(x))<<USB_STAT_TX_SHIFT))&USB_STAT_TX_MASK)
#define USB_STAT_ENDP_MASK                       0xF0u
#define USB_STAT_ENDP_SHIFT                      4
#define USB_STAT_ENDP_WIDTH                      4
#define USB_STAT_ENDP(x)                         (((uint8_t)(((uint8_t)(x))<<USB_STAT_ENDP_SHIFT))&USB_STAT_ENDP_MASK)
/* CTL Bit Fields */
#define USB_CTL_USBENSOFEN_MASK                  0x1u
#define USB_CTL_USBENSOFEN_SHIFT                 0
#define USB_CTL_USBENSOFEN_WIDTH                 1
#define USB_CTL_USBENSOFEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_CTL_USBENSOFEN_SHIFT))&USB_CTL_USBENSOFEN_MASK)
#define USB_CTL_ODDRST_MASK                      0x2u
#define USB_CTL_ODDRST_SHIFT                     1
#define USB_CTL_ODDRST_WIDTH                     1
#define USB_CTL_ODDRST(x)                        (((uint8_t)(((uint8_t)(x))<<USB_CTL_ODDRST_SHIFT))&USB_CTL_ODDRST_MASK)
#define USB_CTL_RESUME_MASK                      0x4u
#define USB_CTL_RESUME_SHIFT                     2
#define USB_CTL_RESUME_WIDTH                     1
#define USB_CTL_RESUME(x)                        (((uint8_t)(((uint8_t)(x))<<USB_CTL_RESUME_SHIFT))&USB_CTL_RESUME_MASK)
#define USB_CTL_HOSTMODEEN_MASK                  0x8u
#define USB_CTL_HOSTMODEEN_SHIFT                 3
#define USB_CTL_HOSTMODEEN_WIDTH                 1
#define USB_CTL_HOSTMODEEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_CTL_HOSTMODEEN_SHIFT))&USB_CTL_HOSTMODEEN_MASK)
#define USB_CTL_RESET_MASK                       0x10u
#define USB_CTL_RESET_SHIFT                      4
#define USB_CTL_RESET_WIDTH                      1
#define USB_CTL_RESET(x)                         (((uint8_t)(((uint8_t)(x))<<USB_CTL_RESET_SHIFT))&USB_CTL_RESET_MASK)
#define USB_CTL_TXSUSPENDTOKENBUSY_MASK          0x20u
#define USB_CTL_TXSUSPENDTOKENBUSY_SHIFT         5
#define USB_CTL_TXSUSPENDTOKENBUSY_WIDTH         1
#define USB_CTL_TXSUSPENDTOKENBUSY(x)            (((uint8_t)(((uint8_t)(x))<<USB_CTL_TXSUSPENDTOKENBUSY_SHIFT))&USB_CTL_TXSUSPENDTOKENBUSY_MASK)
#define USB_CTL_SE0_MASK                         0x40u
#define USB_CTL_SE0_SHIFT                        6
#define USB_CTL_SE0_WIDTH                        1
#define USB_CTL_SE0(x)                           (((uint8_t)(((uint8_t)(x))<<USB_CTL_SE0_SHIFT))&USB_CTL_SE0_MASK)
#define USB_CTL_JSTATE_MASK                      0x80u
#define USB_CTL_JSTATE_SHIFT                     7
#define USB_CTL_JSTATE_WIDTH                     1
#define USB_CTL_JSTATE(x)                        (((uint8_t)(((uint8_t)(x))<<USB_CTL_JSTATE_SHIFT))&USB_CTL_JSTATE_MASK)
/* ADDR Bit Fields */
#define USB_ADDR_ADDR_MASK                       0x7Fu
#define USB_ADDR_ADDR_SHIFT                      0
#define USB_ADDR_ADDR_WIDTH                      7
#define USB_ADDR_ADDR(x)                         (((uint8_t)(((uint8_t)(x))<<USB_ADDR_ADDR_SHIFT))&USB_ADDR_ADDR_MASK)
#define USB_ADDR_LSEN_MASK                       0x80u
#define USB_ADDR_LSEN_SHIFT                      7
#define USB_ADDR_LSEN_WIDTH                      1
#define USB_ADDR_LSEN(x)                         (((uint8_t)(((uint8_t)(x))<<USB_ADDR_LSEN_SHIFT))&USB_ADDR_LSEN_MASK)
/* BDTPAGE1 Bit Fields */
#define USB_BDTPAGE1_BDTBA_MASK                  0xFEu
#define USB_BDTPAGE1_BDTBA_SHIFT                 1
#define USB_BDTPAGE1_BDTBA_WIDTH                 7
#define USB_BDTPAGE1_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE1_BDTBA_SHIFT))&USB_BDTPAGE1_BDTBA_MASK)
/* FRMNUML Bit Fields */
#define USB_FRMNUML_FRM_MASK                     0xFFu
#define USB_FRMNUML_FRM_SHIFT                    0
#define USB_FRMNUML_FRM_WIDTH                    8
#define USB_FRMNUML_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<USB_FRMNUML_FRM_SHIFT))&USB_FRMNUML_FRM_MASK)
/* FRMNUMH Bit Fields */
#define USB_FRMNUMH_FRM_MASK                     0x7u
#define USB_FRMNUMH_FRM_SHIFT                    0
#define USB_FRMNUMH_FRM_WIDTH                    3
#define USB_FRMNUMH_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<USB_FRMNUMH_FRM_SHIFT))&USB_FRMNUMH_FRM_MASK)
/* TOKEN Bit Fields */
#define USB_TOKEN_TOKENENDPT_MASK                0xFu
#define USB_TOKEN_TOKENENDPT_SHIFT               0
#define USB_TOKEN_TOKENENDPT_WIDTH               4
#define USB_TOKEN_TOKENENDPT(x)                  (((uint8_t)(((uint8_t)(x))<<USB_TOKEN_TOKENENDPT_SHIFT))&USB_TOKEN_TOKENENDPT_MASK)
#define USB_TOKEN_TOKENPID_MASK                  0xF0u
#define USB_TOKEN_TOKENPID_SHIFT                 4
#define USB_TOKEN_TOKENPID_WIDTH                 4
#define USB_TOKEN_TOKENPID(x)                    (((uint8_t)(((uint8_t)(x))<<USB_TOKEN_TOKENPID_SHIFT))&USB_TOKEN_TOKENPID_MASK)
/* SOFTHLD Bit Fields */
#define USB_SOFTHLD_CNT_MASK                     0xFFu
#define USB_SOFTHLD_CNT_SHIFT                    0
#define USB_SOFTHLD_CNT_WIDTH                    8
#define USB_SOFTHLD_CNT(x)                       (((uint8_t)(((uint8_t)(x))<<USB_SOFTHLD_CNT_SHIFT))&USB_SOFTHLD_CNT_MASK)
/* BDTPAGE2 Bit Fields */
#define USB_BDTPAGE2_BDTBA_MASK                  0xFFu
#define USB_BDTPAGE2_BDTBA_SHIFT                 0
#define USB_BDTPAGE2_BDTBA_WIDTH                 8
#define USB_BDTPAGE2_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE2_BDTBA_SHIFT))&USB_BDTPAGE2_BDTBA_MASK)
/* BDTPAGE3 Bit Fields */
#define USB_BDTPAGE3_BDTBA_MASK                  0xFFu
#define USB_BDTPAGE3_BDTBA_SHIFT                 0
#define USB_BDTPAGE3_BDTBA_WIDTH                 8
#define USB_BDTPAGE3_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE3_BDTBA_SHIFT))&USB_BDTPAGE3_BDTBA_MASK)
/* ENDPT Bit Fields */
#define USB_ENDPT_EPHSHK_MASK                    0x1u
#define USB_ENDPT_EPHSHK_SHIFT                   0
#define USB_ENDPT_EPHSHK_WIDTH                   1
#define USB_ENDPT_EPHSHK(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPHSHK_SHIFT))&USB_ENDPT_EPHSHK_MASK)
#define USB_ENDPT_EPSTALL_MASK                   0x2u
#define USB_ENDPT_EPSTALL_SHIFT                  1
#define USB_ENDPT_EPSTALL_WIDTH                  1
#define USB_ENDPT_EPSTALL(x)                     (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPSTALL_SHIFT))&USB_ENDPT_EPSTALL_MASK)
#define USB_ENDPT_EPTXEN_MASK                    0x4u
#define USB_ENDPT_EPTXEN_SHIFT                   2
#define USB_ENDPT_EPTXEN_WIDTH                   1
#define USB_ENDPT_EPTXEN(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPTXEN_SHIFT))&USB_ENDPT_EPTXEN_MASK)
#define USB_ENDPT_EPRXEN_MASK                    0x8u
#define USB_ENDPT_EPRXEN_SHIFT                   3
#define USB_ENDPT_EPRXEN_WIDTH                   1
#define USB_ENDPT_EPRXEN(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPRXEN_SHIFT))&USB_ENDPT_EPRXEN_MASK)
#define USB_ENDPT_EPCTLDIS_MASK                  0x10u
#define USB_ENDPT_EPCTLDIS_SHIFT                 4
#define USB_ENDPT_EPCTLDIS_WIDTH                 1
#define USB_ENDPT_EPCTLDIS(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPCTLDIS_SHIFT))&USB_ENDPT_EPCTLDIS_MASK)
#define USB_ENDPT_RETRYDIS_MASK                  0x40u
#define USB_ENDPT_RETRYDIS_SHIFT                 6
#define USB_ENDPT_RETRYDIS_WIDTH                 1
#define USB_ENDPT_RETRYDIS(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_RETRYDIS_SHIFT))&USB_ENDPT_RETRYDIS_MASK)
#define USB_ENDPT_HOSTWOHUB_MASK                 0x80u
#define USB_ENDPT_HOSTWOHUB_SHIFT                7
#define USB_ENDPT_HOSTWOHUB_WIDTH                1
#define USB_ENDPT_HOSTWOHUB(x)                   (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_HOSTWOHUB_SHIFT))&USB_ENDPT_HOSTWOHUB_MASK)
/* USBCTRL Bit Fields */
#define USB_USBCTRL_UARTSEL_MASK                 0x10u
#define USB_USBCTRL_UARTSEL_SHIFT                4
#define USB_USBCTRL_UARTSEL_WIDTH                1
#define USB_USBCTRL_UARTSEL(x)                   (((uint8_t)(((uint8_t)(x))<<USB_USBCTRL_UARTSEL_SHIFT))&USB_USBCTRL_UARTSEL_MASK)
#define USB_USBCTRL_UARTCHLS_MASK                0x20u
#define USB_USBCTRL_UARTCHLS_SHIFT               5
#define USB_USBCTRL_UARTCHLS_WIDTH               1
#define USB_USBCTRL_UARTCHLS(x)                  (((uint8_t)(((uint8_t)(x))<<USB_USBCTRL_UARTCHLS_SHIFT))&USB_USBCTRL_UARTCHLS_MASK)
#define USB_USBCTRL_PDE_MASK                     0x40u
#define USB_USBCTRL_PDE_SHIFT                    6
#define USB_USBCTRL_PDE_WIDTH                    1
#define USB_USBCTRL_PDE(x)                       (((uint8_t)(((uint8_t)(x))<<USB_USBCTRL_PDE_SHIFT))&USB_USBCTRL_PDE_MASK)
#define USB_USBCTRL_SUSP_MASK                    0x80u
#define USB_USBCTRL_SUSP_SHIFT                   7
#define USB_USBCTRL_SUSP_WIDTH                   1
#define USB_USBCTRL_SUSP(x)                      (((uint8_t)(((uint8_t)(x))<<USB_USBCTRL_SUSP_SHIFT))&USB_USBCTRL_SUSP_MASK)
/* OBSERVE Bit Fields */
#define USB_OBSERVE_DMPD_MASK                    0x10u
#define USB_OBSERVE_DMPD_SHIFT                   4
#define USB_OBSERVE_DMPD_WIDTH                   1
#define USB_OBSERVE_DMPD(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OBSERVE_DMPD_SHIFT))&USB_OBSERVE_DMPD_MASK)
#define USB_OBSERVE_DPPD_MASK                    0x40u
#define USB_OBSERVE_DPPD_SHIFT                   6
#define USB_OBSERVE_DPPD_WIDTH                   1
#define USB_OBSERVE_DPPD(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OBSERVE_DPPD_SHIFT))&USB_OBSERVE_DPPD_MASK)
#define USB_OBSERVE_DPPU_MASK                    0x80u
#define USB_OBSERVE_DPPU_SHIFT                   7
#define USB_OBSERVE_DPPU_WIDTH                   1
#define USB_OBSERVE_DPPU(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OBSERVE_DPPU_SHIFT))&USB_OBSERVE_DPPU_MASK)
/* CONTROL Bit Fields */
#define USB_CONTROL_DPPULLUPNONOTG_MASK          0x10u
#define USB_CONTROL_DPPULLUPNONOTG_SHIFT         4
#define USB_CONTROL_DPPULLUPNONOTG_WIDTH         1
#define USB_CONTROL_DPPULLUPNONOTG(x)            (((uint8_t)(((uint8_t)(x))<<USB_CONTROL_DPPULLUPNONOTG_SHIFT))&USB_CONTROL_DPPULLUPNONOTG_MASK)
/* USBTRC0 Bit Fields */
#define USB_USBTRC0_USB_RESUME_INT_MASK          0x1u
#define USB_USBTRC0_USB_RESUME_INT_SHIFT         0
#define USB_USBTRC0_USB_RESUME_INT_WIDTH         1
#define USB_USBTRC0_USB_RESUME_INT(x)            (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_USB_RESUME_INT_SHIFT))&USB_USBTRC0_USB_RESUME_INT_MASK)
#define USB_USBTRC0_SYNC_DET_MASK                0x2u
#define USB_USBTRC0_SYNC_DET_SHIFT               1
#define USB_USBTRC0_SYNC_DET_WIDTH               1
#define USB_USBTRC0_SYNC_DET(x)                  (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_SYNC_DET_SHIFT))&USB_USBTRC0_SYNC_DET_MASK)
#define USB_USBTRC0_USB_CLK_RECOVERY_INT_MASK    0x4u
#define USB_USBTRC0_USB_CLK_RECOVERY_INT_SHIFT   2
#define USB_USBTRC0_USB_CLK_RECOVERY_INT_WIDTH   1
#define USB_USBTRC0_USB_CLK_RECOVERY_INT(x)      (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_USB_CLK_RECOVERY_INT_SHIFT))&USB_USBTRC0_USB_CLK_RECOVERY_INT_MASK)
#define USB_USBTRC0_VREDG_DET_MASK               0x8u
#define USB_USBTRC0_VREDG_DET_SHIFT              3
#define USB_USBTRC0_VREDG_DET_WIDTH              1
#define USB_USBTRC0_VREDG_DET(x)                 (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_VREDG_DET_SHIFT))&USB_USBTRC0_VREDG_DET_MASK)
#define USB_USBTRC0_VFEDG_DET_MASK               0x10u
#define USB_USBTRC0_VFEDG_DET_SHIFT              4
#define USB_USBTRC0_VFEDG_DET_WIDTH              1
#define USB_USBTRC0_VFEDG_DET(x)                 (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_VFEDG_DET_SHIFT))&USB_USBTRC0_VFEDG_DET_MASK)
#define USB_USBTRC0_USBRESMEN_MASK               0x20u
#define USB_USBTRC0_USBRESMEN_SHIFT              5
#define USB_USBTRC0_USBRESMEN_WIDTH              1
#define USB_USBTRC0_USBRESMEN(x)                 (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_USBRESMEN_SHIFT))&USB_USBTRC0_USBRESMEN_MASK)
#define USB_USBTRC0_USBRESET_MASK                0x80u
#define USB_USBTRC0_USBRESET_SHIFT               7
#define USB_USBTRC0_USBRESET_WIDTH               1
#define USB_USBTRC0_USBRESET(x)                  (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_USBRESET_SHIFT))&USB_USBTRC0_USBRESET_MASK)
/* USBFRMADJUST Bit Fields */
#define USB_USBFRMADJUST_ADJ_MASK                0xFFu
#define USB_USBFRMADJUST_ADJ_SHIFT               0
#define USB_USBFRMADJUST_ADJ_WIDTH               8
#define USB_USBFRMADJUST_ADJ(x)                  (((uint8_t)(((uint8_t)(x))<<USB_USBFRMADJUST_ADJ_SHIFT))&USB_USBFRMADJUST_ADJ_MASK)
/* KEEP_ALIVE_CTRL Bit Fields */
#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_MASK   0x1u
#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_SHIFT  0
#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_WIDTH  1
#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN(x)     (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_SHIFT))&USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_MASK)
#define USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_MASK   0x2u
#define USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_SHIFT  1
#define USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_WIDTH  1
#define USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN(x)     (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_SHIFT))&USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_MASK)
#define USB_KEEP_ALIVE_CTRL_AHB_DLY_EN_MASK      0x8u
#define USB_KEEP_ALIVE_CTRL_AHB_DLY_EN_SHIFT     3
#define USB_KEEP_ALIVE_CTRL_AHB_DLY_EN_WIDTH     1
#define USB_KEEP_ALIVE_CTRL_AHB_DLY_EN(x)        (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_CTRL_AHB_DLY_EN_SHIFT))&USB_KEEP_ALIVE_CTRL_AHB_DLY_EN_MASK)
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_MASK     0x10u
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_SHIFT    4
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_WIDTH    1
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_EN(x)       (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_SHIFT))&USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_MASK)
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_MASK    0x80u
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_SHIFT   7
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_WIDTH   1
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_STS(x)      (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_SHIFT))&USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_MASK)
/* KEEP_ALIVE_WKCTRL Bit Fields */
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_MASK  0xFu
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_SHIFT 0
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_WIDTH 4
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS(x)    (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_SHIFT))&USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_MASK)
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_MASK    0xF0u
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_SHIFT   4
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_WIDTH   4
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT(x)      (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_SHIFT))&USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_MASK)
/* MISCCTRL Bit Fields */
#define USB_MISCCTRL_SOFDYNTHLD_MASK             0x1u
#define USB_MISCCTRL_SOFDYNTHLD_SHIFT            0
#define USB_MISCCTRL_SOFDYNTHLD_WIDTH            1
#define USB_MISCCTRL_SOFDYNTHLD(x)               (((uint8_t)(((uint8_t)(x))<<USB_MISCCTRL_SOFDYNTHLD_SHIFT))&USB_MISCCTRL_SOFDYNTHLD_MASK)
#define USB_MISCCTRL_SOFBUSSET_MASK              0x2u
#define USB_MISCCTRL_SOFBUSSET_SHIFT             1
#define USB_MISCCTRL_SOFBUSSET_WIDTH             1
#define USB_MISCCTRL_SOFBUSSET(x)                (((uint8_t)(((uint8_t)(x))<<USB_MISCCTRL_SOFBUSSET_SHIFT))&USB_MISCCTRL_SOFBUSSET_MASK)
#define USB_MISCCTRL_OWNERRISODIS_MASK           0x4u
#define USB_MISCCTRL_OWNERRISODIS_SHIFT          2
#define USB_MISCCTRL_OWNERRISODIS_WIDTH          1
#define USB_MISCCTRL_OWNERRISODIS(x)             (((uint8_t)(((uint8_t)(x))<<USB_MISCCTRL_OWNERRISODIS_SHIFT))&USB_MISCCTRL_OWNERRISODIS_MASK)
#define USB_MISCCTRL_VREDG_EN_MASK               0x8u
#define USB_MISCCTRL_VREDG_EN_SHIFT              3
#define USB_MISCCTRL_VREDG_EN_WIDTH              1
#define USB_MISCCTRL_VREDG_EN(x)                 (((uint8_t)(((uint8_t)(x))<<USB_MISCCTRL_VREDG_EN_SHIFT))&USB_MISCCTRL_VREDG_EN_MASK)
#define USB_MISCCTRL_VFEDG_EN_MASK               0x10u
#define USB_MISCCTRL_VFEDG_EN_SHIFT              4
#define USB_MISCCTRL_VFEDG_EN_WIDTH              1
#define USB_MISCCTRL_VFEDG_EN(x)                 (((uint8_t)(((uint8_t)(x))<<USB_MISCCTRL_VFEDG_EN_SHIFT))&USB_MISCCTRL_VFEDG_EN_MASK)
/* CLK_RECOVER_CTRL Bit Fields */
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK 0x20u
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT 5
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_WIDTH 1
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN(x) (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT))&USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK)
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_MASK 0x40u
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_SHIFT 6
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_WIDTH 1
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN(x) (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_SHIFT))&USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_MASK)
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_MASK 0x80u
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_SHIFT 7
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_WIDTH 1
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN(x) (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_SHIFT))&USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_MASK)
/* CLK_RECOVER_IRC_EN Bit Fields */
#define USB_CLK_RECOVER_IRC_EN_REG_EN_MASK       0x1u
#define USB_CLK_RECOVER_IRC_EN_REG_EN_SHIFT      0
#define USB_CLK_RECOVER_IRC_EN_REG_EN_WIDTH      1
#define USB_CLK_RECOVER_IRC_EN_REG_EN(x)         (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_IRC_EN_REG_EN_SHIFT))&USB_CLK_RECOVER_IRC_EN_REG_EN_MASK)
#define USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK       0x2u
#define USB_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT      1
#define USB_CLK_RECOVER_IRC_EN_IRC_EN_WIDTH      1
#define USB_CLK_RECOVER_IRC_EN_IRC_EN(x)         (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT))&USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK)
/* CLK_RECOVER_INT_EN Bit Fields */
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK 0x10u
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT 4
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_WIDTH 1
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN(x)   (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT))&USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK)
/* CLK_RECOVER_INT_STATUS Bit Fields */
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_MASK 0x10u
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_SHIFT 4
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_WIDTH 1
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR(x)  (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_SHIFT))&USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_MASK)

/*!
 * @}
 */ /* end of group USB_Register_Masks */


/* USB - Peripheral instance base addresses */
/** Peripheral USB0 base address */
#define USB0_BASE                                (0x40055000u)
/** Peripheral USB0 base pointer */
#define USB0                                     ((USB_Type *)USB0_BASE)
#define USB0_BASE_PTR                            (USB0)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { USB0_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { USB0 }

/* ----------------------------------------------------------------------------
   -- USB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Register_Accessor_Macros USB - Register accessor macros
 * @{
 */


/* USB - Register instance definitions */
/* USB0 */
#define USB0_PERID                               USB_PERID_REG(USB0)
#define USB0_IDCOMP                              USB_IDCOMP_REG(USB0)
#define USB0_REV                                 USB_REV_REG(USB0)
#define USB0_ADDINFO                             USB_ADDINFO_REG(USB0)
#define USB0_OTGISTAT                            USB_OTGISTAT_REG(USB0)
#define USB0_OTGICR                              USB_OTGICR_REG(USB0)
#define USB0_OTGSTAT                             USB_OTGSTAT_REG(USB0)
#define USB0_OTGCTL                              USB_OTGCTL_REG(USB0)
#define USB0_ISTAT                               USB_ISTAT_REG(USB0)
#define USB0_INTEN                               USB_INTEN_REG(USB0)
#define USB0_ERRSTAT                             USB_ERRSTAT_REG(USB0)
#define USB0_ERREN                               USB_ERREN_REG(USB0)
#define USB0_STAT                                USB_STAT_REG(USB0)
#define USB0_CTL                                 USB_CTL_REG(USB0)
#define USB0_ADDR                                USB_ADDR_REG(USB0)
#define USB0_BDTPAGE1                            USB_BDTPAGE1_REG(USB0)
#define USB0_FRMNUML                             USB_FRMNUML_REG(USB0)
#define USB0_FRMNUMH                             USB_FRMNUMH_REG(USB0)
#define USB0_TOKEN                               USB_TOKEN_REG(USB0)
#define USB0_SOFTHLD                             USB_SOFTHLD_REG(USB0)
#define USB0_BDTPAGE2                            USB_BDTPAGE2_REG(USB0)
#define USB0_BDTPAGE3                            USB_BDTPAGE3_REG(USB0)
#define USB0_ENDPT0                              USB_ENDPT_REG(USB0,0)
#define USB0_ENDPT1                              USB_ENDPT_REG(USB0,1)
#define USB0_ENDPT2                              USB_ENDPT_REG(USB0,2)
#define USB0_ENDPT3                              USB_ENDPT_REG(USB0,3)
#define USB0_ENDPT4                              USB_ENDPT_REG(USB0,4)
#define USB0_ENDPT5                              USB_ENDPT_REG(USB0,5)
#define USB0_ENDPT6                              USB_ENDPT_REG(USB0,6)
#define USB0_ENDPT7                              USB_ENDPT_REG(USB0,7)
#define USB0_ENDPT8                              USB_ENDPT_REG(USB0,8)
#define USB0_ENDPT9                              USB_ENDPT_REG(USB0,9)
#define USB0_ENDPT10                             USB_ENDPT_REG(USB0,10)
#define USB0_ENDPT11                             USB_ENDPT_REG(USB0,11)
#define USB0_ENDPT12                             USB_ENDPT_REG(USB0,12)
#define USB0_ENDPT13                             USB_ENDPT_REG(USB0,13)
#define USB0_ENDPT14                             USB_ENDPT_REG(USB0,14)
#define USB0_ENDPT15                             USB_ENDPT_REG(USB0,15)
#define USB0_USBCTRL                             USB_USBCTRL_REG(USB0)
#define USB0_OBSERVE                             USB_OBSERVE_REG(USB0)
#define USB0_CONTROL                             USB_CONTROL_REG(USB0)
#define USB0_USBTRC0                             USB_USBTRC0_REG(USB0)
#define USB0_USBFRMADJUST                        USB_USBFRMADJUST_REG(USB0)
#define USB0_KEEP_ALIVE_CTRL                     USB_KEEP_ALIVE_CTRL_REG(USB0)
#define USB0_KEEP_ALIVE_WKCTRL                   USB_KEEP_ALIVE_WKCTRL_REG(USB0)
#define USB0_MISCCTRL                            USB_MISCCTRL_REG(USB0)
#define USB0_CLK_RECOVER_CTRL                    USB_CLK_RECOVER_CTRL_REG(USB0)
#define USB0_CLK_RECOVER_IRC_EN                  USB_CLK_RECOVER_IRC_EN_REG(USB0)
#define USB0_CLK_RECOVER_INT_EN                  USB_CLK_RECOVER_INT_EN_REG(USB0)
#define USB0_CLK_RECOVER_INT_STATUS              USB_CLK_RECOVER_INT_STATUS_REG(USB0)

/* USB - Register array accessors */
#define USB0_ENDPT(index)                        USB_ENDPT_REG(USB0,index)

/*!
 * @}
 */ /* end of group USB_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group USB_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- VREF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VREF_Peripheral_Access_Layer VREF Peripheral Access Layer
 * @{
 */

/** VREF - Register Layout Typedef */
typedef struct {
  __IO uint8_t TRM;                                /**< VREF Trim Register, offset: 0x0 */
  __IO uint8_t SC;                                 /**< VREF Status and Control Register, offset: 0x1 */
  __IO uint8_t TRM1;                               /**< VREF Trim Register 1, offset: 0x2 */
  __IO uint8_t TRM2;                               /**< VREF Trim Register 2, offset: 0x3 */
  __IO uint8_t TRM3;                               /**< VREF Trim Register 3, offset: 0x4 */
  __IO uint8_t TRM4;                               /**< VREF Trim Register 4, offset: 0x5 */
} VREF_Type, *VREF_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- VREF - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VREF_Register_Accessor_Macros VREF - Register accessor macros
 * @{
 */


/* VREF - Register accessors */
#define VREF_TRM_REG(base)                       ((base)->TRM)
#define VREF_SC_REG(base)                        ((base)->SC)
#define VREF_TRM1_REG(base)                      ((base)->TRM1)
#define VREF_TRM2_REG(base)                      ((base)->TRM2)
#define VREF_TRM3_REG(base)                      ((base)->TRM3)
#define VREF_TRM4_REG(base)                      ((base)->TRM4)

/*!
 * @}
 */ /* end of group VREF_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- VREF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VREF_Register_Masks VREF Register Masks
 * @{
 */

/* TRM Bit Fields */
#define VREF_TRM_TRIM_MASK                       0x3Fu
#define VREF_TRM_TRIM_SHIFT                      0
#define VREF_TRM_TRIM_WIDTH                      6
#define VREF_TRM_TRIM(x)                         (((uint8_t)(((uint8_t)(x))<<VREF_TRM_TRIM_SHIFT))&VREF_TRM_TRIM_MASK)
#define VREF_TRM_CHOPEN_MASK                     0x40u
#define VREF_TRM_CHOPEN_SHIFT                    6
#define VREF_TRM_CHOPEN_WIDTH                    1
#define VREF_TRM_CHOPEN(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_TRM_CHOPEN_SHIFT))&VREF_TRM_CHOPEN_MASK)
#define VREF_TRM_FLIP_MASK                       0x80u
#define VREF_TRM_FLIP_SHIFT                      7
#define VREF_TRM_FLIP_WIDTH                      1
#define VREF_TRM_FLIP(x)                         (((uint8_t)(((uint8_t)(x))<<VREF_TRM_FLIP_SHIFT))&VREF_TRM_FLIP_MASK)
/* SC Bit Fields */
#define VREF_SC_MODE_LV_MASK                     0x3u
#define VREF_SC_MODE_LV_SHIFT                    0
#define VREF_SC_MODE_LV_WIDTH                    2
#define VREF_SC_MODE_LV(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_SC_MODE_LV_SHIFT))&VREF_SC_MODE_LV_MASK)
#define VREF_SC_VREFST_MASK                      0x4u
#define VREF_SC_VREFST_SHIFT                     2
#define VREF_SC_VREFST_WIDTH                     1
#define VREF_SC_VREFST(x)                        (((uint8_t)(((uint8_t)(x))<<VREF_SC_VREFST_SHIFT))&VREF_SC_VREFST_MASK)
#define VREF_SC_TMUXEN_MASK                      0x8u
#define VREF_SC_TMUXEN_SHIFT                     3
#define VREF_SC_TMUXEN_WIDTH                     1
#define VREF_SC_TMUXEN(x)                        (((uint8_t)(((uint8_t)(x))<<VREF_SC_TMUXEN_SHIFT))&VREF_SC_TMUXEN_MASK)
#define VREF_SC_TRESEN_MASK                      0x10u
#define VREF_SC_TRESEN_SHIFT                     4
#define VREF_SC_TRESEN_WIDTH                     1
#define VREF_SC_TRESEN(x)                        (((uint8_t)(((uint8_t)(x))<<VREF_SC_TRESEN_SHIFT))&VREF_SC_TRESEN_MASK)
#define VREF_SC_ICOMPEN_MASK                     0x20u
#define VREF_SC_ICOMPEN_SHIFT                    5
#define VREF_SC_ICOMPEN_WIDTH                    1
#define VREF_SC_ICOMPEN(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_SC_ICOMPEN_SHIFT))&VREF_SC_ICOMPEN_MASK)
#define VREF_SC_REGEN_MASK                       0x40u
#define VREF_SC_REGEN_SHIFT                      6
#define VREF_SC_REGEN_WIDTH                      1
#define VREF_SC_REGEN(x)                         (((uint8_t)(((uint8_t)(x))<<VREF_SC_REGEN_SHIFT))&VREF_SC_REGEN_MASK)
#define VREF_SC_VREFEN_MASK                      0x80u
#define VREF_SC_VREFEN_SHIFT                     7
#define VREF_SC_VREFEN_WIDTH                     1
#define VREF_SC_VREFEN(x)                        (((uint8_t)(((uint8_t)(x))<<VREF_SC_VREFEN_SHIFT))&VREF_SC_VREFEN_MASK)
/* TRM1 Bit Fields */
#define VREF_TRM1_BPLSB_MASK                     0xFu
#define VREF_TRM1_BPLSB_SHIFT                    0
#define VREF_TRM1_BPLSB_WIDTH                    4
#define VREF_TRM1_BPLSB(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_TRM1_BPLSB_SHIFT))&VREF_TRM1_BPLSB_MASK)
#define VREF_TRM1_BPMSB_MASK                     0xE0u
#define VREF_TRM1_BPMSB_SHIFT                    5
#define VREF_TRM1_BPMSB_WIDTH                    3
#define VREF_TRM1_BPMSB(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_TRM1_BPMSB_SHIFT))&VREF_TRM1_BPMSB_MASK)
/* TRM2 Bit Fields */
#define VREF_TRM2_COMPLSB_MASK                   0x7u
#define VREF_TRM2_COMPLSB_SHIFT                  0
#define VREF_TRM2_COMPLSB_WIDTH                  3
#define VREF_TRM2_COMPLSB(x)                     (((uint8_t)(((uint8_t)(x))<<VREF_TRM2_COMPLSB_SHIFT))&VREF_TRM2_COMPLSB_MASK)
#define VREF_TRM2_COMPMSB_MASK                   0xE0u
#define VREF_TRM2_COMPMSB_SHIFT                  5
#define VREF_TRM2_COMPMSB_WIDTH                  3
#define VREF_TRM2_COMPMSB(x)                     (((uint8_t)(((uint8_t)(x))<<VREF_TRM2_COMPMSB_SHIFT))&VREF_TRM2_COMPMSB_MASK)
/* TRM3 Bit Fields */
#define VREF_TRM3_CHOPOSCTRM_MASK                0xFu
#define VREF_TRM3_CHOPOSCTRM_SHIFT               0
#define VREF_TRM3_CHOPOSCTRM_WIDTH               4
#define VREF_TRM3_CHOPOSCTRM(x)                  (((uint8_t)(((uint8_t)(x))<<VREF_TRM3_CHOPOSCTRM_SHIFT))&VREF_TRM3_CHOPOSCTRM_MASK)
/* TRM4 Bit Fields */
#define VREF_TRM4_TRIM2V1_MASK                   0x3Fu
#define VREF_TRM4_TRIM2V1_SHIFT                  0
#define VREF_TRM4_TRIM2V1_WIDTH                  6
#define VREF_TRM4_TRIM2V1(x)                     (((uint8_t)(((uint8_t)(x))<<VREF_TRM4_TRIM2V1_SHIFT))&VREF_TRM4_TRIM2V1_MASK)
#define VREF_TRM4_VREF2V1_EN_MASK                0x80u
#define VREF_TRM4_VREF2V1_EN_SHIFT               7
#define VREF_TRM4_VREF2V1_EN_WIDTH               1
#define VREF_TRM4_VREF2V1_EN(x)                  (((uint8_t)(((uint8_t)(x))<<VREF_TRM4_VREF2V1_EN_SHIFT))&VREF_TRM4_VREF2V1_EN_MASK)

/*!
 * @}
 */ /* end of group VREF_Register_Masks */


/* VREF - Peripheral instance base addresses */
/** Peripheral VREF base address */
#define VREF_BASE                                (0x40072000u)
/** Peripheral VREF base pointer */
#define VREF                                     ((VREF_Type *)VREF_BASE)
#define VREF_BASE_PTR                            (VREF)
/** Array initializer of VREF peripheral base addresses */
#define VREF_BASE_ADDRS                          { VREF_BASE }
/** Array initializer of VREF peripheral base pointers */
#define VREF_BASE_PTRS                           { VREF }

/* ----------------------------------------------------------------------------
   -- VREF - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VREF_Register_Accessor_Macros VREF - Register accessor macros
 * @{
 */


/* VREF - Register instance definitions */
/* VREF */
#define VREF_TRM                                 VREF_TRM_REG(VREF)
#define VREF_SC                                  VREF_SC_REG(VREF)
#define VREF_TRM1                                VREF_TRM1_REG(VREF)
#define VREF_TRM2                                VREF_TRM2_REG(VREF)
#define VREF_TRM3                                VREF_TRM3_REG(VREF)
#define VREF_TRM4                                VREF_TRM4_REG(VREF)

/*!
 * @}
 */ /* end of group VREF_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group VREF_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- WDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Peripheral_Access_Layer WDOG Peripheral Access Layer
 * @{
 */

/** WDOG - Register Layout Typedef */
typedef struct {
  __IO uint32_t CS;                                /**< Watchdog Control and Status Register, offset: 0x0 */
  __IO uint32_t CNT;                               /**< Watchdog Counter Register, offset: 0x4 */
  __IO uint32_t TOVAL;                             /**< Watchdog Timeout Value Register, offset: 0x8 */
  __IO uint32_t WIN;                               /**< Watchdog Window Register, offset: 0xC */
} WDOG_Type, *WDOG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- WDOG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Accessor_Macros WDOG - Register accessor macros
 * @{
 */


/* WDOG - Register accessors */
#define WDOG_CS_REG(base)                        ((base)->CS)
#define WDOG_CNT_REG(base)                       ((base)->CNT)
#define WDOG_TOVAL_REG(base)                     ((base)->TOVAL)
#define WDOG_WIN_REG(base)                       ((base)->WIN)

/*!
 * @}
 */ /* end of group WDOG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Masks WDOG Register Masks
 * @{
 */

/* CS Bit Fields */
#define WDOG_CS_STOP_MASK                        0x1u
#define WDOG_CS_STOP_SHIFT                       0
#define WDOG_CS_STOP_WIDTH                       1
#define WDOG_CS_STOP(x)                          (((uint32_t)(((uint32_t)(x))<<WDOG_CS_STOP_SHIFT))&WDOG_CS_STOP_MASK)
#define WDOG_CS_WAIT_MASK                        0x2u
#define WDOG_CS_WAIT_SHIFT                       1
#define WDOG_CS_WAIT_WIDTH                       1
#define WDOG_CS_WAIT(x)                          (((uint32_t)(((uint32_t)(x))<<WDOG_CS_WAIT_SHIFT))&WDOG_CS_WAIT_MASK)
#define WDOG_CS_DBG_MASK                         0x4u
#define WDOG_CS_DBG_SHIFT                        2
#define WDOG_CS_DBG_WIDTH                        1
#define WDOG_CS_DBG(x)                           (((uint32_t)(((uint32_t)(x))<<WDOG_CS_DBG_SHIFT))&WDOG_CS_DBG_MASK)
#define WDOG_CS_TST_MASK                         0x18u
#define WDOG_CS_TST_SHIFT                        3
#define WDOG_CS_TST_WIDTH                        2
#define WDOG_CS_TST(x)                           (((uint32_t)(((uint32_t)(x))<<WDOG_CS_TST_SHIFT))&WDOG_CS_TST_MASK)
#define WDOG_CS_UPDATE_MASK                      0x20u
#define WDOG_CS_UPDATE_SHIFT                     5
#define WDOG_CS_UPDATE_WIDTH                     1
#define WDOG_CS_UPDATE(x)                        (((uint32_t)(((uint32_t)(x))<<WDOG_CS_UPDATE_SHIFT))&WDOG_CS_UPDATE_MASK)
#define WDOG_CS_INT_MASK                         0x40u
#define WDOG_CS_INT_SHIFT                        6
#define WDOG_CS_INT_WIDTH                        1
#define WDOG_CS_INT(x)                           (((uint32_t)(((uint32_t)(x))<<WDOG_CS_INT_SHIFT))&WDOG_CS_INT_MASK)
#define WDOG_CS_EN_MASK                          0x80u
#define WDOG_CS_EN_SHIFT                         7
#define WDOG_CS_EN_WIDTH                         1
#define WDOG_CS_EN(x)                            (((uint32_t)(((uint32_t)(x))<<WDOG_CS_EN_SHIFT))&WDOG_CS_EN_MASK)
#define WDOG_CS_CLK_MASK                         0x300u
#define WDOG_CS_CLK_SHIFT                        8
#define WDOG_CS_CLK_WIDTH                        2
#define WDOG_CS_CLK(x)                           (((uint32_t)(((uint32_t)(x))<<WDOG_CS_CLK_SHIFT))&WDOG_CS_CLK_MASK)
#define WDOG_CS_PRES_MASK                        0x1000u
#define WDOG_CS_PRES_SHIFT                       12
#define WDOG_CS_PRES_WIDTH                       1
#define WDOG_CS_PRES(x)                          (((uint32_t)(((uint32_t)(x))<<WDOG_CS_PRES_SHIFT))&WDOG_CS_PRES_MASK)
#define WDOG_CS_FLG_MASK                         0x4000u
#define WDOG_CS_FLG_SHIFT                        14
#define WDOG_CS_FLG_WIDTH                        1
#define WDOG_CS_FLG(x)                           (((uint32_t)(((uint32_t)(x))<<WDOG_CS_FLG_SHIFT))&WDOG_CS_FLG_MASK)
#define WDOG_CS_WIN_MASK                         0x8000u
#define WDOG_CS_WIN_SHIFT                        15
#define WDOG_CS_WIN_WIDTH                        1
#define WDOG_CS_WIN(x)                           (((uint32_t)(((uint32_t)(x))<<WDOG_CS_WIN_SHIFT))&WDOG_CS_WIN_MASK)
/* CNT Bit Fields */
#define WDOG_CNT_CNTLOW_MASK                     0xFFu
#define WDOG_CNT_CNTLOW_SHIFT                    0
#define WDOG_CNT_CNTLOW_WIDTH                    8
#define WDOG_CNT_CNTLOW(x)                       (((uint32_t)(((uint32_t)(x))<<WDOG_CNT_CNTLOW_SHIFT))&WDOG_CNT_CNTLOW_MASK)
#define WDOG_CNT_CNTHIGH_MASK                    0xFF00u
#define WDOG_CNT_CNTHIGH_SHIFT                   8
#define WDOG_CNT_CNTHIGH_WIDTH                   8
#define WDOG_CNT_CNTHIGH(x)                      (((uint32_t)(((uint32_t)(x))<<WDOG_CNT_CNTHIGH_SHIFT))&WDOG_CNT_CNTHIGH_MASK)
/* TOVAL Bit Fields */
#define WDOG_TOVAL_TOVALLOW_MASK                 0xFFu
#define WDOG_TOVAL_TOVALLOW_SHIFT                0
#define WDOG_TOVAL_TOVALLOW_WIDTH                8
#define WDOG_TOVAL_TOVALLOW(x)                   (((uint32_t)(((uint32_t)(x))<<WDOG_TOVAL_TOVALLOW_SHIFT))&WDOG_TOVAL_TOVALLOW_MASK)
#define WDOG_TOVAL_TOVALHIGH_MASK                0xFF00u
#define WDOG_TOVAL_TOVALHIGH_SHIFT               8
#define WDOG_TOVAL_TOVALHIGH_WIDTH               8
#define WDOG_TOVAL_TOVALHIGH(x)                  (((uint32_t)(((uint32_t)(x))<<WDOG_TOVAL_TOVALHIGH_SHIFT))&WDOG_TOVAL_TOVALHIGH_MASK)
/* WIN Bit Fields */
#define WDOG_WIN_WINLOW_MASK                     0xFFu
#define WDOG_WIN_WINLOW_SHIFT                    0
#define WDOG_WIN_WINLOW_WIDTH                    8
#define WDOG_WIN_WINLOW(x)                       (((uint32_t)(((uint32_t)(x))<<WDOG_WIN_WINLOW_SHIFT))&WDOG_WIN_WINLOW_MASK)
#define WDOG_WIN_WINHIGH_MASK                    0xFF00u
#define WDOG_WIN_WINHIGH_SHIFT                   8
#define WDOG_WIN_WINHIGH_WIDTH                   8
#define WDOG_WIN_WINHIGH(x)                      (((uint32_t)(((uint32_t)(x))<<WDOG_WIN_WINHIGH_SHIFT))&WDOG_WIN_WINHIGH_MASK)

/*!
 * @}
 */ /* end of group WDOG_Register_Masks */


/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG0 base address */
#define WDOG0_BASE                               (0x40076000u)
/** Peripheral WDOG0 base pointer */
#define WDOG0                                    ((WDOG_Type *)WDOG0_BASE)
#define WDOG0_BASE_PTR                           (WDOG0)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG0_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG0 }

/* ----------------------------------------------------------------------------
   -- WDOG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Accessor_Macros WDOG - Register accessor macros
 * @{
 */


/* WDOG - Register instance definitions */
/* WDOG0 */
#define WDOG0_CS                                 WDOG_CS_REG(WDOG0)
#define WDOG0_CNT                                WDOG_CNT_REG(WDOG0)
#define WDOG0_TOVAL                              WDOG_TOVAL_REG(WDOG0)
#define WDOG0_WIN                                WDOG_WIN_REG(WDOG0)

/*!
 * @}
 */ /* end of group WDOG_Register_Accessor_Macros */

#define WDOG_UPDATE_KEY        (0xD928C520)
#define WDOG_REFRESH_KEY       (0xB480A602)


/*!
 * @}
 */ /* end of group WDOG_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #pragma pop
#elif defined(__CWCC__)
  #pragma pop
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


/* ----------------------------------------------------------------------------
   -- Backward Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Backward_Compatibility_Symbols Backward Compatibility
 * @{
 */

#define I2S_TCR2_CLKMODE_MASK                    I2S_TCR2_MSEL_MASK
#define I2S_TCR2_CLKMODE_SHIFT                   I2S_TCR2_MSEL_SHIFT
#define I2S_TCR2_CLKMODE(x)                      I2S_TCR2_MSEL(x)
#define I2S_RCR2_CLKMODE_MASK                    I2S_RCR2_MSEL_MASK
#define I2S_RCR2_CLKMODE_SHIFT                   I2S_RCR2_MSEL_SHIFT
#define I2S_RCR2_CLKMODE(x)                      I2S_RCR2_MSEL(x)
#define ADC_BASES                                ADC_BASE_PTRS
#define CMP_BASES                                CMP_BASE_PTRS
#define DAC_BASES                                DAC_BASE_PTRS
#define DMA_BASES                                DMA_BASE_PTRS
#define DMAMUX_BASES                             DMAMUX_BASE_PTRS
#define FGPIO_BASES                              FGPIO_BASE_PTRS
#define GPIO_BASES                               GPIO_BASE_PTRS
#define FTFA_BASES                               FTFA_BASE_PTRS
#define I2S_BASES                                I2S_BASE_PTRS
#define LLWU_BASES                               LLWU_BASE_PTRS
#define LPTMR_BASES                              LPTMR_BASE_PTRS
#define MCM_BASES                                MCM_BASE_PTRS
#define MTB_BASES                                MTB_BASE_PTRS
#define MTBDWT_BASES                             MTBDWT_BASE_PTRS
#define NV_BASES                                 NV_BASES
#define OSC_BASES                                OSC_BASE_PTRS
#define LPIT_BASES                               LPIT_BASE_PTRS
#define PMC_BASES                                PMC_BASE_PTRS
#define PORT_BASES                               PORT_BASE_PTRS
#define RCM_BASES                                RCM_BASE_PTRS
#define ROM_BASES                                ROM_BASE_PTRS
#define RTC_BASES                                RTC_BASE_PTRS
#define SIM_BASES                                SIM_BASE_PTRS
#define SMC_BASES                                SMC_BASE_PTRS
#define LPI2C_BASES                              LPI2C_BASE_PTRS
#define LPSPI_BASES                              LPSPI_BASE_PTRS
#define TPM_BASES                                TPM_BASE_PTRS
#define TSI_BASES                                TSI_BASE_PTRS
#define LPUART_BASES                             LPUART_BASE_PTRS
#define FPTA_BASE                                FGPIOA_BASE
#define FPTA                                     FGPIOA
#define PTA_BASE                                 GPIOA_BASE
#define PTA                                      GPIOA
#define PTB_BASE                                 GPIOB_BASE
#define PTB                                      GPIOB
#define PTC_BASE                                 GPIOC_BASE
#define PTC                                      GPIOC
#define PTD_BASE                                 GPIOD_BASE
#define PTD                                      GPIOD
#define PTE_BASE                                 GPIOE_BASE
#define PTE                                      GPIOE
#define I2C_FLT_STOPIE_MASK                      This_symbol_has_been_deprecated
#define I2C_FLT_STOPIE_SHIFT                     This_symbol_has_been_deprecated
#define I2S_RCR2_CLKMODE_MASK                    I2S_RCR2_MSEL_MASK
#define I2S_RCR2_CLKMODE_SHIFT                   I2S_RCR2_MSEL_SHIFT
#define I2S_RCR2_CLKMODE(x)                      I2S_RCR2_MSEL(x)
#define I2S_TCR2_CLKMODE_MASK                    I2S_TCR2_MSEL_MASK
#define I2S_TCR2_CLKMODE_SHIFT                   I2S_TCR2_MSEL_SHIFT
#define I2S_TCR2_CLKMODE(x)                      I2S_TCR2_MSEL(x)
#define LPTimer_IRQn                             LPTMR0_IRQn
#define LPTimer_IRQHandler                       LPTMR0_IRQHandler

/*!
 * @}
 */ /* end of group Backward_Compatibility_Symbols */


#else /* #if !defined(MKL28Z7_H_) */
  /* There is already included the same memory map. Check if it is compatible (has the same major version) */
  #if (MCU_MEM_MAP_VERSION != 0x0100u)
    #if (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING))
      #warning There are included two not compatible versions of memory maps. Please check possible differences.
    #endif /* (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING)) */
  #endif /* (MCU_MEM_MAP_VERSION != 0x0100u) */
#endif  /* #if !defined(MKL28Z7_H_) */

/* MKL28Z7.h, eof. */
