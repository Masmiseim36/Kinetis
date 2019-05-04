/*
** ###################################################################
**     Processors:          MWPR1516CAL
**                          MWPR1516CFM
**
**     Compilers:           Keil ARM C/C++ Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          GNU C Compiler - CodeSourcery Sourcery G++
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    MWPR1516RM, Rev. 2 Draft A, Sep 2014
**     Version:             rev. 1.5, 2014-12-12
**     Build:               b141212
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MWPR1516
**
**     Copyright (c) 1997 - 2014 Freescale Semiconductor, Inc.
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
**     - rev. 1.0 (2014-04-23)
**         Initial version.
**     - rev. 1.1 (2014-07-07)
**         ADC - Bitfield AUT_RSTA has been added into register CTL1.
**         CNC - Register ANACFG has been renamed to ANACFG1.
**         FSKDT - Register OTRGTH has been renamed to OPCTH.
**         FSKDT - Bitfield OTRGIE in register CR has been renamed to OPIE.
**         FSKDT - Bitfield OTRGF in register SR has been renamed to OPF.
**         FTM - Register EXTTRIG has been added.
**         LDO - Bitfield INCLPE in register CR has been renamed to BASHDN.
**     - rev. 1.2 (2014-08-01)
**         PMC - Added peripheral.
**     - rev. 1.3 (2014-08-08)
**         PMC - BITFIELD 5VT has been renamed to T5V.
**     - rev. 1.4 (2014-10-01)
**         FTM1 - Base address has been changed from 0x4003A000 to 0x40039000.
**         Other peripheries - little changes like after reset values and so on.
**     - rev. 1.5 (2014-12-12)
**         LDO - LDO_CTRM[15:9] has been changed to reserved.
**         WDOG - Interrupt name has been synchronized.
**
** ###################################################################
*/

/*!
 * @file MWPR1516.h
 * @version 1.5
 * @date 2014-12-12
 * @brief CMSIS Peripheral Access Layer for MWPR1516
 *
 * CMSIS Peripheral Access Layer for MWPR1516
 */


/* ----------------------------------------------------------------------------
   -- MCU activation
   ---------------------------------------------------------------------------- */

/* Prevention from multiple including the same memory map */
#if !defined(MWPR1516_H_)  /* Check if memory map has not been already included */
#define MWPR1516_H_
#define MCU_MWPR1516

/* Check if another memory map has not been also included */
#if (defined(MCU_ACTIVE))
  #error MWPR1516 memory map: There is already included another memory map. Only one memory map can be included.
#endif /* (defined(MCU_ACTIVE)) */
#define MCU_ACTIVE

#include <stdint.h>

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100u
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0005u


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 48                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M0 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M0 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M0 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M0 System Tick Interrupt */

  /* Device specific interrupts */
  Reserved16_IRQn              = 0,                /**< Reserved interrupt */
  Reserved17_IRQn              = 1,                /**< Reserved interrupt */
  Reserved18_IRQn              = 2,                /**< Reserved interrupt */
  Reserved19_IRQn              = 3,                /**< Reserved interrupt */
  Reserved20_IRQn              = 4,                /**< Reserved interrupt */
  FTMRE_IRQn                   = 5,                /**< Command complete and read collision */
  PMC_IRQn                     = 6,                /**< Low-voltage detect, low-voltage warning */
  IRQ_IRQn                     = 7,                /**< External Interrupt */
  I2C0_IRQn                    = 8,                /**< I2C0 interrupt */
  Reserved25_IRQn              = 9,                /**< Reserved interrupt */
  Reserved26_IRQn              = 10,               /**< Reserved interrupt */
  Reserved27_IRQn              = 11,               /**< Reserved interrupt */
  UART0_IRQn                   = 12,               /**< UART0 status and error */
  Reserved29_IRQn              = 13,               /**< Reserved interrupt */
  ADC_ERR_ABORT_IRQn           = 14,               /**< ADC error or conversion sequence abort */
  ADC_CONV_COMPLETE_IRQn       = 15,               /**< ADC conversion complete interrupt */
  ACMP0_IRQn                   = 16,               /**< ACMP0 interrupt */
  FTM0_IRQn                    = 17,               /**< FTM0 single interrupt vector for all sources */
  FTM1_IRQn                    = 18,               /**< FTM1 single interrupt vector for all sources */
  Reserved35_IRQn              = 19,               /**< Reserved interrupt */
  RTC_IRQn                     = 20,               /**< RTC overflow */
  Reserved37_IRQn              = 21,               /**< Reserved interrupt */
  PIT_CH0_IRQn                 = 22,               /**< PIT CH0 overflow */
  PIT_CH1_IRQn                 = 23,               /**< PIT CH1 overflow */
  Reserved40_IRQn              = 24,               /**< Reserved interrupt */
  Reserved41_IRQn              = 25,               /**< Reserved interrupt */
  FSKDT_IRQn                   = 26,               /**< FSKDT single interrupt vector for all sources */
  ICS_IRQn                     = 27,               /**< ICS interrupt */
  WDOG_IRQn                    = 28,               /**< Watchdog timeout */
  Reserved45_IRQn              = 29,               /**< Reserved interrupt */
  CNC_IRQn                     = 30,               /**< CNC single interrupt vector for all sources */
  LDO_IRQn                     = 31                /**< LDO single interrupt vector for all sources */
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
#include "system_MWPR1516.h"           /* Device specific configuration file */

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
   -- ACMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACMP_Peripheral_Access_Layer ACMP Peripheral Access Layer
 * @{
 */

/** ACMP - Register Layout Typedef */
typedef struct {
  __IO uint8_t CS;                                 /**< ACMP Control and Status Register, offset: 0x0 */
  __IO uint8_t C0;                                 /**< ACMP Control Register 0, offset: 0x1 */
  __IO uint8_t C1;                                 /**< ACMP Control Register 1, offset: 0x2 */
  __IO uint8_t C2;                                 /**< ACMP Control Register 2, offset: 0x3 */
} ACMP_Type, *ACMP_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ACMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACMP_Register_Accessor_Macros ACMP - Register accessor macros
 * @{
 */


/* ACMP - Register accessors */
#define ACMP_CS_REG(base)                        ((base)->CS)
#define ACMP_C0_REG(base)                        ((base)->C0)
#define ACMP_C1_REG(base)                        ((base)->C1)
#define ACMP_C2_REG(base)                        ((base)->C2)

/*!
 * @}
 */ /* end of group ACMP_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ACMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACMP_Register_Masks ACMP Register Masks
 * @{
 */

/* CS Bit Fields */
#define ACMP_CS_ACMOD_MASK                       0x3u
#define ACMP_CS_ACMOD_SHIFT                      0
#define ACMP_CS_ACMOD(x)                         (((uint8_t)(((uint8_t)(x))<<ACMP_CS_ACMOD_SHIFT))&ACMP_CS_ACMOD_MASK)
#define ACMP_CS_ACOPE_MASK                       0x4u
#define ACMP_CS_ACOPE_SHIFT                      2
#define ACMP_CS_ACO_MASK                         0x8u
#define ACMP_CS_ACO_SHIFT                        3
#define ACMP_CS_ACIE_MASK                        0x10u
#define ACMP_CS_ACIE_SHIFT                       4
#define ACMP_CS_ACF_MASK                         0x20u
#define ACMP_CS_ACF_SHIFT                        5
#define ACMP_CS_HYST_MASK                        0x40u
#define ACMP_CS_HYST_SHIFT                       6
#define ACMP_CS_ACE_MASK                         0x80u
#define ACMP_CS_ACE_SHIFT                        7
/* C0 Bit Fields */
#define ACMP_C0_ACNSEL_MASK                      0x3u
#define ACMP_C0_ACNSEL_SHIFT                     0
#define ACMP_C0_ACNSEL(x)                        (((uint8_t)(((uint8_t)(x))<<ACMP_C0_ACNSEL_SHIFT))&ACMP_C0_ACNSEL_MASK)
#define ACMP_C0_ACPSEL_MASK                      0x30u
#define ACMP_C0_ACPSEL_SHIFT                     4
#define ACMP_C0_ACPSEL(x)                        (((uint8_t)(((uint8_t)(x))<<ACMP_C0_ACPSEL_SHIFT))&ACMP_C0_ACPSEL_MASK)
/* C1 Bit Fields */
#define ACMP_C1_DACVAL_MASK                      0x3Fu
#define ACMP_C1_DACVAL_SHIFT                     0
#define ACMP_C1_DACVAL(x)                        (((uint8_t)(((uint8_t)(x))<<ACMP_C1_DACVAL_SHIFT))&ACMP_C1_DACVAL_MASK)
#define ACMP_C1_DACREF_MASK                      0x40u
#define ACMP_C1_DACREF_SHIFT                     6
#define ACMP_C1_DACEN_MASK                       0x80u
#define ACMP_C1_DACEN_SHIFT                      7
/* C2 Bit Fields */
#define ACMP_C2_ACIPE_MASK                       0x7u
#define ACMP_C2_ACIPE_SHIFT                      0
#define ACMP_C2_ACIPE(x)                         (((uint8_t)(((uint8_t)(x))<<ACMP_C2_ACIPE_SHIFT))&ACMP_C2_ACIPE_MASK)

/*!
 * @}
 */ /* end of group ACMP_Register_Masks */


/* ACMP - Peripheral instance base addresses */
/** Peripheral ACMP0 base address */
#define ACMP0_BASE                               (0x40073000u)
/** Peripheral ACMP0 base pointer */
#define ACMP0                                    ((ACMP_Type *)ACMP0_BASE)
#define ACMP0_BASE_PTR                           (ACMP0)
/** Array initializer of ACMP peripheral base addresses */
#define ACMP_BASE_ADDRS                          { ACMP0_BASE }
/** Array initializer of ACMP peripheral base pointers */
#define ACMP_BASE_PTRS                           { ACMP0 }

/* ----------------------------------------------------------------------------
   -- ACMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACMP_Register_Accessor_Macros ACMP - Register accessor macros
 * @{
 */


/* ACMP - Register instance definitions */
/* ACMP0 */
#define ACMP0_CS                                 ACMP_CS_REG(ACMP0)
#define ACMP0_C0                                 ACMP_C0_REG(ACMP0)
#define ACMP0_C1                                 ACMP_C1_REG(ACMP0)
#define ACMP0_C2                                 ACMP_C2_REG(ACMP0)

/*!
 * @}
 */ /* end of group ACMP_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group ACMP_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint8_t TIM;                                /**< ADC Timing Register, offset: 0x0 */
  __IO uint8_t STS;                                /**< ADC Status Register, offset: 0x1 */
  __IO uint8_t CTL1;                               /**< ADC Control Register 1, offset: 0x2 */
  __IO uint8_t CTL0;                               /**< ADC Control Register 0, offset: 0x3 */
  __IO uint8_t IE;                                 /**< ADC Interrupt Enable Register, offset: 0x4 */
  __IO uint8_t EIE;                                /**< ADC Error Interrupt Enable Register, offset: 0x5 */
  __IO uint8_t FLWCTL;                             /**< ADC Conversion Flow Control Register, offset: 0x6 */
  __IO uint8_t FMT;                                /**< ADC Format Register, offset: 0x7 */
  __IO uint8_t CONIE1;                             /**< ADC Conversion Interrupt Enable Register 1, offset: 0x8 */
  __IO uint8_t CONIE0;                             /**< ADC Conversion Interrupt Enable Register 0, offset: 0x9 */
  __IO uint8_t IF;                                 /**< ADC Interrupt Flag Register, offset: 0xA */
  __IO uint8_t EIF;                                /**< ADC Error Interrupt Flag Register, offset: 0xB */
  __I  uint8_t IMDRI1;                             /**< ADC Intermediate Result Information Register 1, offset: 0xC */
  __I  uint8_t IMDRI0;                             /**< ADC Intermediate Result Information Register 0, offset: 0xD */
  __IO uint8_t CONIF1;                             /**< ADC Conversion Interrupt Flag Register 1, offset: 0xE */
  __IO uint8_t CONIF0;                             /**< ADC Conversion Interrupt Flag Register 0, offset: 0xF */
       uint8_t RESERVED_0[3];
  __I  uint8_t EOLRI;                              /**< ADC End Of List Result Information Register, offset: 0x13 */
       uint8_t RESERVED_1[1];
  __IO uint8_t CMD2;                               /**< ADC Command Register 2, offset: 0x15 */
  __IO uint8_t CMD1;                               /**< ADC Command Register 1, offset: 0x16 */
  __IO uint8_t CMD0;                               /**< ADC Command Register 0, offset: 0x17 */
       uint8_t RESERVED_2[4];
  __IO uint8_t CBP2;                               /**< ADC Command Base Pointer Register 2, offset: 0x1C */
  __IO uint8_t CBP1;                               /**< ADC Command Base Pointer Register 1, offset: 0x1D */
  __IO uint8_t CBP0;                               /**< ADC Command Base Pointer Register 0, offset: 0x1E */
  __I  uint8_t CIDX;                               /**< ADC Command Index Register, offset: 0x1F */
  __IO uint8_t RBP2;                               /**< ADC Result Base Pointer Register 2, offset: 0x20 */
  __IO uint8_t RBP1;                               /**< ADC Result Base Pointer Register 1, offset: 0x21 */
       uint8_t RESERVED_3[1];
  __I  uint8_t RIDX;                               /**< ADC Result Index Register, offset: 0x23 */
       uint8_t RESERVED_4[2];
  __IO uint8_t CROFF1;                             /**< ADC Command and Result Offset Register 1, offset: 0x26 */
  __I  uint8_t CROFF0;                             /**< ADC Command and Result Offset Register 0, offset: 0x27 */
} ADC_Type, *ADC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros
 * @{
 */


/* ADC - Register accessors */
#define ADC_TIM_REG(base)                        ((base)->TIM)
#define ADC_STS_REG(base)                        ((base)->STS)
#define ADC_CTL1_REG(base)                       ((base)->CTL1)
#define ADC_CTL0_REG(base)                       ((base)->CTL0)
#define ADC_IE_REG(base)                         ((base)->IE)
#define ADC_EIE_REG(base)                        ((base)->EIE)
#define ADC_FLWCTL_REG(base)                     ((base)->FLWCTL)
#define ADC_FMT_REG(base)                        ((base)->FMT)
#define ADC_CONIE1_REG(base)                     ((base)->CONIE1)
#define ADC_CONIE0_REG(base)                     ((base)->CONIE0)
#define ADC_IF_REG(base)                         ((base)->IF)
#define ADC_EIF_REG(base)                        ((base)->EIF)
#define ADC_IMDRI1_REG(base)                     ((base)->IMDRI1)
#define ADC_IMDRI0_REG(base)                     ((base)->IMDRI0)
#define ADC_CONIF1_REG(base)                     ((base)->CONIF1)
#define ADC_CONIF0_REG(base)                     ((base)->CONIF0)
#define ADC_EOLRI_REG(base)                      ((base)->EOLRI)
#define ADC_CMD2_REG(base)                       ((base)->CMD2)
#define ADC_CMD1_REG(base)                       ((base)->CMD1)
#define ADC_CMD0_REG(base)                       ((base)->CMD0)
#define ADC_CBP2_REG(base)                       ((base)->CBP2)
#define ADC_CBP1_REG(base)                       ((base)->CBP1)
#define ADC_CBP0_REG(base)                       ((base)->CBP0)
#define ADC_CIDX_REG(base)                       ((base)->CIDX)
#define ADC_RBP2_REG(base)                       ((base)->RBP2)
#define ADC_RBP1_REG(base)                       ((base)->RBP1)
#define ADC_RIDX_REG(base)                       ((base)->RIDX)
#define ADC_CROFF1_REG(base)                     ((base)->CROFF1)
#define ADC_CROFF0_REG(base)                     ((base)->CROFF0)

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

/* TIM Bit Fields */
#define ADC_TIM_PRS_MASK                         0x7Fu
#define ADC_TIM_PRS_SHIFT                        0
#define ADC_TIM_PRS(x)                           (((uint8_t)(((uint8_t)(x))<<ADC_TIM_PRS_SHIFT))&ADC_TIM_PRS_MASK)
/* STS Bit Fields */
#define ADC_STS_READY_MASK                       0x8u
#define ADC_STS_READY_SHIFT                      3
#define ADC_STS_RVL_SEL_MASK                     0x40u
#define ADC_STS_RVL_SEL_SHIFT                    6
#define ADC_STS_CSL_SEL_MASK                     0x80u
#define ADC_STS_CSL_SEL_SHIFT                    7
/* CTL1 Bit Fields */
#define ADC_CTL1_AUT_RSTA_MASK                   0x10u
#define ADC_CTL1_AUT_RSTA_SHIFT                  4
#define ADC_CTL1_SMOD_ACC_MASK                   0x20u
#define ADC_CTL1_SMOD_ACC_SHIFT                  5
#define ADC_CTL1_RVL_BMOD_MASK                   0x40u
#define ADC_CTL1_RVL_BMOD_SHIFT                  6
#define ADC_CTL1_CSL_BMOD_MASK                   0x80u
#define ADC_CTL1_CSL_BMOD_SHIFT                  7
/* CTL0 Bit Fields */
#define ADC_CTL0_MOD_CFG_MASK                    0x1u
#define ADC_CTL0_MOD_CFG_SHIFT                   0
#define ADC_CTL0_STR_SEQA_MASK                   0x2u
#define ADC_CTL0_STR_SEQA_SHIFT                  1
#define ADC_CTL0_ACC_CFG_MASK                    0xCu
#define ADC_CTL0_ACC_CFG_SHIFT                   2
#define ADC_CTL0_ACC_CFG(x)                      (((uint8_t)(((uint8_t)(x))<<ADC_CTL0_ACC_CFG_SHIFT))&ADC_CTL0_ACC_CFG_MASK)
#define ADC_CTL0_SWAI_MASK                       0x10u
#define ADC_CTL0_SWAI_SHIFT                      4
#define ADC_CTL0_FRZ_MOD_MASK                    0x20u
#define ADC_CTL0_FRZ_MOD_SHIFT                   5
#define ADC_CTL0_ADC_SR_MASK                     0x40u
#define ADC_CTL0_ADC_SR_SHIFT                    6
#define ADC_CTL0_ADC_EN_MASK                     0x80u
#define ADC_CTL0_ADC_EN_SHIFT                    7
/* IE Bit Fields */
#define ADC_IE_CONIF_OIE_MASK                    0x40u
#define ADC_IE_CONIF_OIE_SHIFT                   6
#define ADC_IE_SEQAD_IE_MASK                     0x80u
#define ADC_IE_SEQAD_IE_SHIFT                    7
/* EIE Bit Fields */
#define ADC_EIE_RA_EIE_MASK                      0x1u
#define ADC_EIE_RA_EIE_SHIFT                     0
#define ADC_EIE_LDOK_EIE_MASK                    0x2u
#define ADC_EIE_LDOK_EIE_SHIFT                   1
#define ADC_EIE_RSTAR_EIE_MASK                   0x4u
#define ADC_EIE_RSTAR_EIE_SHIFT                  2
#define ADC_EIE_TRIG_EIE_MASK                    0x8u
#define ADC_EIE_TRIG_EIE_SHIFT                   3
#define ADC_EIE_EOL_EIE_MASK                     0x20u
#define ADC_EIE_EOL_EIE_SHIFT                    5
#define ADC_EIE_CMD_EIE_MASK                     0x40u
#define ADC_EIE_CMD_EIE_SHIFT                    6
#define ADC_EIE_WA_EIE_MASK                      0x80u
#define ADC_EIE_WA_EIE_SHIFT                     7
/* FLWCTL Bit Fields */
#define ADC_FLWCTL_LDOK_MASK                     0x10u
#define ADC_FLWCTL_LDOK_SHIFT                    4
#define ADC_FLWCTL_RSTA_MASK                     0x20u
#define ADC_FLWCTL_RSTA_SHIFT                    5
#define ADC_FLWCTL_TRIG_MASK                     0x40u
#define ADC_FLWCTL_TRIG_SHIFT                    6
#define ADC_FLWCTL_SEQA_MASK                     0x80u
#define ADC_FLWCTL_SEQA_SHIFT                    7
/* FMT Bit Fields */
#define ADC_FMT_SRES_MASK                        0x7u
#define ADC_FMT_SRES_SHIFT                       0
#define ADC_FMT_SRES(x)                          (((uint8_t)(((uint8_t)(x))<<ADC_FMT_SRES_SHIFT))&ADC_FMT_SRES_MASK)
#define ADC_FMT_DJM_MASK                         0x80u
#define ADC_FMT_DJM_SHIFT                        7
/* CONIE1 Bit Fields */
#define ADC_CONIE1_EOL_IE_MASK                   0x1u
#define ADC_CONIE1_EOL_IE_SHIFT                  0
#define ADC_CONIE1_CON_IE_MASK                   0xFEu
#define ADC_CONIE1_CON_IE_SHIFT                  1
#define ADC_CONIE1_CON_IE(x)                     (((uint8_t)(((uint8_t)(x))<<ADC_CONIE1_CON_IE_SHIFT))&ADC_CONIE1_CON_IE_MASK)
/* CONIE0 Bit Fields */
#define ADC_CONIE0_CON_IE_MASK                   0xFFu
#define ADC_CONIE0_CON_IE_SHIFT                  0
#define ADC_CONIE0_CON_IE(x)                     (((uint8_t)(((uint8_t)(x))<<ADC_CONIE0_CON_IE_SHIFT))&ADC_CONIE0_CON_IE_MASK)
/* IF Bit Fields */
#define ADC_IF_CONIF_OIF_MASK                    0x40u
#define ADC_IF_CONIF_OIF_SHIFT                   6
#define ADC_IF_SEQAD_IF_MASK                     0x80u
#define ADC_IF_SEQAD_IF_SHIFT                    7
/* EIF Bit Fields */
#define ADC_EIF_RA_EIF_MASK                      0x1u
#define ADC_EIF_RA_EIF_SHIFT                     0
#define ADC_EIF_LDOK_EIF_MASK                    0x2u
#define ADC_EIF_LDOK_EIF_SHIFT                   1
#define ADC_EIF_RSTAR_EIF_MASK                   0x4u
#define ADC_EIF_RSTAR_EIF_SHIFT                  2
#define ADC_EIF_TRIG_EIF_MASK                    0x8u
#define ADC_EIF_TRIG_EIF_SHIFT                   3
#define ADC_EIF_EOL_EIF_MASK                     0x20u
#define ADC_EIF_EOL_EIF_SHIFT                    5
#define ADC_EIF_CMD_EIF_MASK                     0x40u
#define ADC_EIF_CMD_EIF_SHIFT                    6
#define ADC_EIF_WA_EIF_MASK                      0x80u
#define ADC_EIF_WA_EIF_SHIFT                     7
/* IMDRI1 Bit Fields */
#define ADC_IMDRI1_RIDX_IMD_MASK                 0x3Fu
#define ADC_IMDRI1_RIDX_IMD_SHIFT                0
#define ADC_IMDRI1_RIDX_IMD(x)                   (((uint8_t)(((uint8_t)(x))<<ADC_IMDRI1_RIDX_IMD_SHIFT))&ADC_IMDRI1_RIDX_IMD_MASK)
/* IMDRI0 Bit Fields */
#define ADC_IMDRI0_RVL_IMD_MASK                  0x40u
#define ADC_IMDRI0_RVL_IMD_SHIFT                 6
#define ADC_IMDRI0_CSL_IMD_MASK                  0x80u
#define ADC_IMDRI0_CSL_IMD_SHIFT                 7
/* CONIF1 Bit Fields */
#define ADC_CONIF1_EOL_IF_MASK                   0x1u
#define ADC_CONIF1_EOL_IF_SHIFT                  0
#define ADC_CONIF1_CON_IF_MASK                   0xFEu
#define ADC_CONIF1_CON_IF_SHIFT                  1
#define ADC_CONIF1_CON_IF(x)                     (((uint8_t)(((uint8_t)(x))<<ADC_CONIF1_CON_IF_SHIFT))&ADC_CONIF1_CON_IF_MASK)
/* CONIF0 Bit Fields */
#define ADC_CONIF0_CON_IF_MASK                   0xFFu
#define ADC_CONIF0_CON_IF_SHIFT                  0
#define ADC_CONIF0_CON_IF(x)                     (((uint8_t)(((uint8_t)(x))<<ADC_CONIF0_CON_IF_SHIFT))&ADC_CONIF0_CON_IF_MASK)
/* EOLRI Bit Fields */
#define ADC_EOLRI_RVL_EOL_MASK                   0x40u
#define ADC_EOLRI_RVL_EOL_SHIFT                  6
#define ADC_EOLRI_CSL_EOL_MASK                   0x80u
#define ADC_EOLRI_CSL_EOL_SHIFT                  7
/* CMD2 Bit Fields */
#define ADC_CMD2_SMP_MASK                        0xF8u
#define ADC_CMD2_SMP_SHIFT                       3
#define ADC_CMD2_SMP(x)                          (((uint8_t)(((uint8_t)(x))<<ADC_CMD2_SMP_SHIFT))&ADC_CMD2_SMP_MASK)
/* CMD1 Bit Fields */
#define ADC_CMD1_CH_SEL_MASK                     0x3Fu
#define ADC_CMD1_CH_SEL_SHIFT                    0
#define ADC_CMD1_CH_SEL(x)                       (((uint8_t)(((uint8_t)(x))<<ADC_CMD1_CH_SEL_SHIFT))&ADC_CMD1_CH_SEL_MASK)
#define ADC_CMD1_INTFLG_SEL_MASK                 0x40u
#define ADC_CMD1_INTFLG_SEL_SHIFT                6
#define ADC_CMD1_VRH_SEL_MASK                    0x80u
#define ADC_CMD1_VRH_SEL_SHIFT                   7
/* CMD0 Bit Fields */
#define ADC_CMD0_INTFLG_SEL_MASK                 0xFu
#define ADC_CMD0_INTFLG_SEL_SHIFT                0
#define ADC_CMD0_INTFLG_SEL(x)                   (((uint8_t)(((uint8_t)(x))<<ADC_CMD0_INTFLG_SEL_SHIFT))&ADC_CMD0_INTFLG_SEL_MASK)
#define ADC_CMD0_CMD_SEL_MASK                    0xC0u
#define ADC_CMD0_CMD_SEL_SHIFT                   6
#define ADC_CMD0_CMD_SEL(x)                      (((uint8_t)(((uint8_t)(x))<<ADC_CMD0_CMD_SEL_SHIFT))&ADC_CMD0_CMD_SEL_MASK)
/* CBP2 Bit Fields */
#define ADC_CBP2_CMD_PTR_MASK                    0xFCu
#define ADC_CBP2_CMD_PTR_SHIFT                   2
#define ADC_CBP2_CMD_PTR(x)                      (((uint8_t)(((uint8_t)(x))<<ADC_CBP2_CMD_PTR_SHIFT))&ADC_CBP2_CMD_PTR_MASK)
/* CBP1 Bit Fields */
#define ADC_CBP1_CMD_PTR_MASK                    0xFFu
#define ADC_CBP1_CMD_PTR_SHIFT                   0
#define ADC_CBP1_CMD_PTR(x)                      (((uint8_t)(((uint8_t)(x))<<ADC_CBP1_CMD_PTR_SHIFT))&ADC_CBP1_CMD_PTR_MASK)
/* CBP0 Bit Fields */
#define ADC_CBP0_CMD_PTR_MASK                    0x80u
#define ADC_CBP0_CMD_PTR_SHIFT                   7
/* CIDX Bit Fields */
#define ADC_CIDX_CMD_IDX_MASK                    0x3Fu
#define ADC_CIDX_CMD_IDX_SHIFT                   0
#define ADC_CIDX_CMD_IDX(x)                      (((uint8_t)(((uint8_t)(x))<<ADC_CIDX_CMD_IDX_SHIFT))&ADC_CIDX_CMD_IDX_MASK)
/* RBP2 Bit Fields */
#define ADC_RBP2_RES_PTR_MASK                    0xFCu
#define ADC_RBP2_RES_PTR_SHIFT                   2
#define ADC_RBP2_RES_PTR(x)                      (((uint8_t)(((uint8_t)(x))<<ADC_RBP2_RES_PTR_SHIFT))&ADC_RBP2_RES_PTR_MASK)
/* RBP1 Bit Fields */
#define ADC_RBP1_RES_PTR_MASK                    0xFFu
#define ADC_RBP1_RES_PTR_SHIFT                   0
#define ADC_RBP1_RES_PTR(x)                      (((uint8_t)(((uint8_t)(x))<<ADC_RBP1_RES_PTR_SHIFT))&ADC_RBP1_RES_PTR_MASK)
/* RIDX Bit Fields */
#define ADC_RIDX_RES_IDX_MASK                    0x3Fu
#define ADC_RIDX_RES_IDX_SHIFT                   0
#define ADC_RIDX_RES_IDX(x)                      (((uint8_t)(((uint8_t)(x))<<ADC_RIDX_RES_IDX_SHIFT))&ADC_RIDX_RES_IDX_MASK)
/* CROFF1 Bit Fields */
#define ADC_CROFF1_CMDRES_OFF1_MASK              0x7Fu
#define ADC_CROFF1_CMDRES_OFF1_SHIFT             0
#define ADC_CROFF1_CMDRES_OFF1(x)                (((uint8_t)(((uint8_t)(x))<<ADC_CROFF1_CMDRES_OFF1_SHIFT))&ADC_CROFF1_CMDRES_OFF1_MASK)
/* CROFF0 Bit Fields */
#define ADC_CROFF0_CMDRES_OFF0_MASK              0x7Fu
#define ADC_CROFF0_CMDRES_OFF0_SHIFT             0
#define ADC_CROFF0_CMDRES_OFF0(x)                (((uint8_t)(((uint8_t)(x))<<ADC_CROFF0_CMDRES_OFF0_SHIFT))&ADC_CROFF0_CMDRES_OFF0_MASK)

/*!
 * @}
 */ /* end of group ADC_Register_Masks */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC base address */
#define ADC_BASE                                 (0x4003B000u)
/** Peripheral ADC base pointer */
#define ADC                                      ((ADC_Type *)ADC_BASE)
#define ADC_BASE_PTR                             (ADC)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC }

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros
 * @{
 */


/* ADC - Register instance definitions */
/* ADC */
#define ADC_TIM                                  ADC_TIM_REG(ADC)
#define ADC_STS                                  ADC_STS_REG(ADC)
#define ADC_CTL1                                 ADC_CTL1_REG(ADC)
#define ADC_CTL0                                 ADC_CTL0_REG(ADC)
#define ADC_IE                                   ADC_IE_REG(ADC)
#define ADC_EIE                                  ADC_EIE_REG(ADC)
#define ADC_FLWCTL                               ADC_FLWCTL_REG(ADC)
#define ADC_FMT                                  ADC_FMT_REG(ADC)
#define ADC_CONIE1                               ADC_CONIE1_REG(ADC)
#define ADC_CONIE0                               ADC_CONIE0_REG(ADC)
#define ADC_IF                                   ADC_IF_REG(ADC)
#define ADC_EIF                                  ADC_EIF_REG(ADC)
#define ADC_IMDRI1                               ADC_IMDRI1_REG(ADC)
#define ADC_IMDRI0                               ADC_IMDRI0_REG(ADC)
#define ADC_CONIF1                               ADC_CONIF1_REG(ADC)
#define ADC_CONIF0                               ADC_CONIF0_REG(ADC)
#define ADC_EOLRI                                ADC_EOLRI_REG(ADC)
#define ADC_CMD2                                 ADC_CMD2_REG(ADC)
#define ADC_CMD1                                 ADC_CMD1_REG(ADC)
#define ADC_CMD0                                 ADC_CMD0_REG(ADC)
#define ADC_CBP2                                 ADC_CBP2_REG(ADC)
#define ADC_CBP1                                 ADC_CBP1_REG(ADC)
#define ADC_CBP0                                 ADC_CBP0_REG(ADC)
#define ADC_CIDX                                 ADC_CIDX_REG(ADC)
#define ADC_RBP2                                 ADC_RBP2_REG(ADC)
#define ADC_RBP1                                 ADC_RBP1_REG(ADC)
#define ADC_RIDX                                 ADC_RIDX_REG(ADC)
#define ADC_CROFF1                               ADC_CROFF1_REG(ADC)
#define ADC_CROFF0                               ADC_CROFF0_REG(ADC)

/*!
 * @}
 */ /* end of group ADC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CNC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CNC_Peripheral_Access_Layer CNC Peripheral Access Layer
 * @{
 */

/** CNC - Register Layout Typedef */
typedef struct {
  __IO uint16_t CR;                                /**< Control Register, offset: 0x0 */
  __IO uint16_t ANACFG1;                           /**< Analog Configuration Register 1, offset: 0x2 */
  __IO uint16_t ANACFG2;                           /**< Analog Configuration Register 2, offset: 0x4 */
  __IO uint16_t STAS;                              /**< Status Register, offset: 0x6 */
  __IO uint16_t VRECOE;                            /**< VREC Overvoltage clamp drive Enable Register, offset: 0x8 */
  __IO uint16_t VRECFLTC;                          /**< VREC Filter Control Register, offset: 0xA */
  __IO uint16_t VADFLTC;                           /**< AD_IN Filter Control Register, offset: 0xC */
} CNC_Type, *CNC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CNC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CNC_Register_Accessor_Macros CNC - Register accessor macros
 * @{
 */


/* CNC - Register accessors */
#define CNC_CR_REG(base)                         ((base)->CR)
#define CNC_ANACFG1_REG(base)                    ((base)->ANACFG1)
#define CNC_ANACFG2_REG(base)                    ((base)->ANACFG2)
#define CNC_STAS_REG(base)                       ((base)->STAS)
#define CNC_VRECOE_REG(base)                     ((base)->VRECOE)
#define CNC_VRECFLTC_REG(base)                   ((base)->VRECFLTC)
#define CNC_VADFLTC_REG(base)                    ((base)->VADFLTC)

/*!
 * @}
 */ /* end of group CNC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CNC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CNC_Register_Masks CNC Register Masks
 * @{
 */

/* CR Bit Fields */
#define CNC_CR_SWCLPD_MASK                       0x1u
#define CNC_CR_SWCLPD_SHIFT                      0
#define CNC_CR_CLPDPE_MASK                       0x20u
#define CNC_CR_CLPDPE_SHIFT                      5
#define CNC_CR_EXTCLPDE_MASK                     0x40u
#define CNC_CR_EXTCLPDE_SHIFT                    6
#define CNC_CR_VRECDE_MASK                       0x80u
#define CNC_CR_VRECDE_SHIFT                      7
#define CNC_CR_VADVDIE_MASK                      0x100u
#define CNC_CR_VADVDIE_SHIFT                     8
#define CNC_CR_SWADS_MASK                        0x200u
#define CNC_CR_SWADS_SHIFT                       9
#define CNC_CR_ADE_MASK                          0x400u
#define CNC_CR_ADE_SHIFT                         10
#define CNC_CR_LVIE_MASK                         0x1000u
#define CNC_CR_LVIE_SHIFT                        12
#define CNC_CR_OVIE_MASK                         0x2000u
#define CNC_CR_OVIE_SHIFT                        13
#define CNC_CR_ADANE_MASK                        0x4000u
#define CNC_CR_ADANE_SHIFT                       14
#define CNC_CR_ZCDE_MASK                         0x8000u
#define CNC_CR_ZCDE_SHIFT                        15
/* ANACFG1 Bit Fields */
#define CNC_ANACFG1_VADDIVOE_MASK                0x1u
#define CNC_ANACFG1_VADDIVOE_SHIFT               0
#define CNC_ANACFG1_VADLVTRM_MASK                0x6u
#define CNC_ANACFG1_VADLVTRM_SHIFT               1
#define CNC_ANACFG1_VADLVTRM(x)                  (((uint16_t)(((uint16_t)(x))<<CNC_ANACFG1_VADLVTRM_SHIFT))&CNC_ANACFG1_VADLVTRM_MASK)
#define CNC_ANACFG1_VADOVTRM_MASK                0x18u
#define CNC_ANACFG1_VADOVTRM_SHIFT               3
#define CNC_ANACFG1_VADOVTRM(x)                  (((uint16_t)(((uint16_t)(x))<<CNC_ANACFG1_VADOVTRM_SHIFT))&CNC_ANACFG1_VADOVTRM_MASK)
#define CNC_ANACFG1_VRECOVLVL_MASK               0x1800u
#define CNC_ANACFG1_VRECOVLVL_SHIFT              11
#define CNC_ANACFG1_VRECOVLVL(x)                 (((uint16_t)(((uint16_t)(x))<<CNC_ANACFG1_VRECOVLVL_SHIFT))&CNC_ANACFG1_VRECOVLVL_MASK)
#define CNC_ANACFG1_AC1DIVOE_MASK                0x2000u
#define CNC_ANACFG1_AC1DIVOE_SHIFT               13
#define CNC_ANACFG1_ZCDHYST_MASK                 0xC000u
#define CNC_ANACFG1_ZCDHYST_SHIFT                14
#define CNC_ANACFG1_ZCDHYST(x)                   (((uint16_t)(((uint16_t)(x))<<CNC_ANACFG1_ZCDHYST_SHIFT))&CNC_ANACFG1_ZCDHYST_MASK)
/* ANACFG2 Bit Fields */
#define CNC_ANACFG2_ACDIV_MASK                   0xFu
#define CNC_ANACFG2_ACDIV_SHIFT                  0
#define CNC_ANACFG2_ACDIV(x)                     (((uint16_t)(((uint16_t)(x))<<CNC_ANACFG2_ACDIV_SHIFT))&CNC_ANACFG2_ACDIV_MASK)
#define CNC_ANACFG2_ACFLTC_MASK                  0x30u
#define CNC_ANACFG2_ACFLTC_SHIFT                 4
#define CNC_ANACFG2_ACFLTC(x)                    (((uint16_t)(((uint16_t)(x))<<CNC_ANACFG2_ACFLTC_SHIFT))&CNC_ANACFG2_ACFLTC_MASK)
#define CNC_ANACFG2_ACFLTE_MASK                  0x40u
#define CNC_ANACFG2_ACFLTE_SHIFT                 6
#define CNC_ANACFG2_BIAE_MASK                    0x80u
#define CNC_ANACFG2_BIAE_SHIFT                   7
#define CNC_ANACFG2_VAOHY20_MASK                 0x100u
#define CNC_ANACFG2_VAOHY20_SHIFT                8
#define CNC_ANACFG2_VAOHY40_MASK                 0x200u
#define CNC_ANACFG2_VAOHY40_SHIFT                9
/* STAS Bit Fields */
#define CNC_STAS_FSKO_MASK                       0x1u
#define CNC_STAS_FSKO_SHIFT                      0
#define CNC_STAS_VADOV5P5_MASK                   0x2u
#define CNC_STAS_VADOV5P5_SHIFT                  1
#define CNC_STAS_VADOK4P5_MASK                   0x4u
#define CNC_STAS_VADOK4P5_SHIFT                  2
#define CNC_STAS_VADCHGF_MASK                    0x8u
#define CNC_STAS_VADCHGF_SHIFT                   3
#define CNC_STAS_VRECOVF_MASK                    0x10u
#define CNC_STAS_VRECOVF_SHIFT                   4
#define CNC_STAS_VRECLVF_MASK                    0x20u
#define CNC_STAS_VRECLVF_SHIFT                   5
#define CNC_STAS_VRECOVS_MASK                    0x40u
#define CNC_STAS_VRECOVS_SHIFT                   6
#define CNC_STAS_VRECLVS_MASK                    0x80u
#define CNC_STAS_VRECLVS_SHIFT                   7
/* VRECOE Bit Fields */
#define CNC_VRECOE_VRECOVE_MASK                  0x1u
#define CNC_VRECOE_VRECOVE_SHIFT                 0
/* VRECFLTC Bit Fields */
#define CNC_VRECFLTC_CNT_MASK                    0xFFFFu
#define CNC_VRECFLTC_CNT_SHIFT                   0
#define CNC_VRECFLTC_CNT(x)                      (((uint16_t)(((uint16_t)(x))<<CNC_VRECFLTC_CNT_SHIFT))&CNC_VRECFLTC_CNT_MASK)
/* VADFLTC Bit Fields */
#define CNC_VADFLTC_CNT_MASK                     0xFFFFu
#define CNC_VADFLTC_CNT_SHIFT                    0
#define CNC_VADFLTC_CNT(x)                       (((uint16_t)(((uint16_t)(x))<<CNC_VADFLTC_CNT_SHIFT))&CNC_VADFLTC_CNT_MASK)

/*!
 * @}
 */ /* end of group CNC_Register_Masks */


/* CNC - Peripheral instance base addresses */
/** Peripheral CNC base address */
#define CNC_BASE                                 (0x4006E000u)
/** Peripheral CNC base pointer */
#define CNC                                      ((CNC_Type *)CNC_BASE)
#define CNC_BASE_PTR                             (CNC)
/** Array initializer of CNC peripheral base addresses */
#define CNC_BASE_ADDRS                           { CNC_BASE }
/** Array initializer of CNC peripheral base pointers */
#define CNC_BASE_PTRS                            { CNC }

/* ----------------------------------------------------------------------------
   -- CNC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CNC_Register_Accessor_Macros CNC - Register accessor macros
 * @{
 */


/* CNC - Register instance definitions */
/* CNC */
#define CNC_CR                                   CNC_CR_REG(CNC)
#define CNC_ANACFG1                              CNC_ANACFG1_REG(CNC)
#define CNC_ANACFG2                              CNC_ANACFG2_REG(CNC)
#define CNC_STAS                                 CNC_STAS_REG(CNC)
#define CNC_VRECOE                               CNC_VRECOE_REG(CNC)
#define CNC_VRECFLTC                             CNC_VRECFLTC_REG(CNC)
#define CNC_VADFLTC                              CNC_VADFLTC_REG(CNC)

/*!
 * @}
 */ /* end of group CNC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group CNC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FSKDT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSKDT_Peripheral_Access_Layer FSKDT Peripheral Access Layer
 * @{
 */

/** FSKDT - Register Layout Typedef */
typedef struct {
  __IO uint16_t CR;                                /**< Control Register, offset: 0x0 */
  __IO uint16_t SR;                                /**< Status Register, offset: 0x2 */
  __I  uint16_t PH0;                               /**< Phase0 counter value, offset: 0x4 */
  __I  uint16_t PH1;                               /**< Phase1 counter value, offset: 0x6 */
  __I  uint16_t PH2;                               /**< Phase2 counter value, offset: 0x8 */
  __I  uint16_t CURPOS;                            /**< Current Position Register, offset: 0xA */
  __IO uint16_t OPCTH;                             /**< Out-of-Period Counter Threshold Register, offset: 0xC */
  __IO uint16_t ERRTH;                             /**< Error Threshold Register, offset: 0xE */
  __IO uint16_t DATA;                              /**< Demodulation Data Register, offset: 0x10 */
  __IO uint16_t DSR;                               /**< Demodulation Data Status Register, offset: 0x12 */
} FSKDT_Type, *FSKDT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FSKDT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSKDT_Register_Accessor_Macros FSKDT - Register accessor macros
 * @{
 */


/* FSKDT - Register accessors */
#define FSKDT_CR_REG(base)                       ((base)->CR)
#define FSKDT_SR_REG(base)                       ((base)->SR)
#define FSKDT_PH0_REG(base)                      ((base)->PH0)
#define FSKDT_PH1_REG(base)                      ((base)->PH1)
#define FSKDT_PH2_REG(base)                      ((base)->PH2)
#define FSKDT_CURPOS_REG(base)                   ((base)->CURPOS)
#define FSKDT_OPCTH_REG(base)                    ((base)->OPCTH)
#define FSKDT_ERRTH_REG(base)                    ((base)->ERRTH)
#define FSKDT_DATA_REG(base)                     ((base)->DATA)
#define FSKDT_DSR_REG(base)                      ((base)->DSR)

/*!
 * @}
 */ /* end of group FSKDT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FSKDT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSKDT_Register_Masks FSKDT Register Masks
 * @{
 */

/* CR Bit Fields */
#define FSKDT_CR_OPIE_MASK                       0x1u
#define FSKDT_CR_OPIE_SHIFT                      0
#define FSKDT_CR_EOSMIE_MASK                     0x2u
#define FSKDT_CR_EOSMIE_SHIFT                    1
#define FSKDT_CR_EOAMIE_MASK                     0x4u
#define FSKDT_CR_EOAMIE_SHIFT                    2
#define FSKDT_CR_ERRIE_MASK                      0x8u
#define FSKDT_CR_ERRIE_SHIFT                     3
#define FSKDT_CR_SWRST_MASK                      0x1000u
#define FSKDT_CR_SWRST_SHIFT                     12
#define FSKDT_CR_NST_MASK                        0x6000u
#define FSKDT_CR_NST_SHIFT                       13
#define FSKDT_CR_NST(x)                          (((uint16_t)(((uint16_t)(x))<<FSKDT_CR_NST_SHIFT))&FSKDT_CR_NST_MASK)
#define FSKDT_CR_EN_MASK                         0x8000u
#define FSKDT_CR_EN_SHIFT                        15
/* SR Bit Fields */
#define FSKDT_SR_OPF_MASK                        0x1u
#define FSKDT_SR_OPF_SHIFT                       0
#define FSKDT_SR_EOSMF_MASK                      0x2u
#define FSKDT_SR_EOSMF_SHIFT                     1
#define FSKDT_SR_EOAMF_MASK                      0x4u
#define FSKDT_SR_EOAMF_SHIFT                     2
#define FSKDT_SR_ERRF_MASK                       0x8u
#define FSKDT_SR_ERRF_SHIFT                      3
/* PH0 Bit Fields */
#define FSKDT_PH0_PH0CNTR_MASK                   0xFFFFu
#define FSKDT_PH0_PH0CNTR_SHIFT                  0
#define FSKDT_PH0_PH0CNTR(x)                     (((uint16_t)(((uint16_t)(x))<<FSKDT_PH0_PH0CNTR_SHIFT))&FSKDT_PH0_PH0CNTR_MASK)
/* PH1 Bit Fields */
#define FSKDT_PH1_PH1CNTR_MASK                   0xFFFFu
#define FSKDT_PH1_PH1CNTR_SHIFT                  0
#define FSKDT_PH1_PH1CNTR(x)                     (((uint16_t)(((uint16_t)(x))<<FSKDT_PH1_PH1CNTR_SHIFT))&FSKDT_PH1_PH1CNTR_MASK)
/* PH2 Bit Fields */
#define FSKDT_PH2_PH2CNTR_MASK                   0xFFFFu
#define FSKDT_PH2_PH2CNTR_SHIFT                  0
#define FSKDT_PH2_PH2CNTR(x)                     (((uint16_t)(((uint16_t)(x))<<FSKDT_PH2_PH2CNTR_SHIFT))&FSKDT_PH2_PH2CNTR_MASK)
/* CURPOS Bit Fields */
#define FSKDT_CURPOS_CURPOS_MASK                 0xFFFFu
#define FSKDT_CURPOS_CURPOS_SHIFT                0
#define FSKDT_CURPOS_CURPOS(x)                   (((uint16_t)(((uint16_t)(x))<<FSKDT_CURPOS_CURPOS_SHIFT))&FSKDT_CURPOS_CURPOS_MASK)
/* OPCTH Bit Fields */
#define FSKDT_OPCTH_OPCTH_MASK                   0x3FFu
#define FSKDT_OPCTH_OPCTH_SHIFT                  0
#define FSKDT_OPCTH_OPCTH(x)                     (((uint16_t)(((uint16_t)(x))<<FSKDT_OPCTH_OPCTH_SHIFT))&FSKDT_OPCTH_OPCTH_MASK)
/* ERRTH Bit Fields */
#define FSKDT_ERRTH_LOLMT_MASK                   0x3Fu
#define FSKDT_ERRTH_LOLMT_SHIFT                  0
#define FSKDT_ERRTH_LOLMT(x)                     (((uint16_t)(((uint16_t)(x))<<FSKDT_ERRTH_LOLMT_SHIFT))&FSKDT_ERRTH_LOLMT_MASK)
#define FSKDT_ERRTH_HILMT_MASK                   0xFFC0u
#define FSKDT_ERRTH_HILMT_SHIFT                  6
#define FSKDT_ERRTH_HILMT(x)                     (((uint16_t)(((uint16_t)(x))<<FSKDT_ERRTH_HILMT_SHIFT))&FSKDT_ERRTH_HILMT_MASK)
/* DATA Bit Fields */
#define FSKDT_DATA_DATA_MASK                     0x7FFu
#define FSKDT_DATA_DATA_SHIFT                    0
#define FSKDT_DATA_DATA(x)                       (((uint16_t)(((uint16_t)(x))<<FSKDT_DATA_DATA_SHIFT))&FSKDT_DATA_DATA_MASK)
#define FSKDT_DATA_BM_MASK                       0x2000u
#define FSKDT_DATA_BM_SHIFT                      13
#define FSKDT_DATA_WBNBIE_MASK                   0x4000u
#define FSKDT_DATA_WBNBIE_SHIFT                  14
#define FSKDT_DATA_NBIE_MASK                     0x8000u
#define FSKDT_DATA_NBIE_SHIFT                    15
/* DSR Bit Fields */
#define FSKDT_DSR_TCNTD_MASK                     0xFu
#define FSKDT_DSR_TCNTD_SHIFT                    0
#define FSKDT_DSR_TCNTD(x)                       (((uint16_t)(((uint16_t)(x))<<FSKDT_DSR_TCNTD_SHIFT))&FSKDT_DSR_TCNTD_MASK)
#define FSKDT_DSR_WBNF_MASK                      0x4000u
#define FSKDT_DSR_WBNF_SHIFT                     14
#define FSKDT_DSR_NBF_MASK                       0x8000u
#define FSKDT_DSR_NBF_SHIFT                      15

/*!
 * @}
 */ /* end of group FSKDT_Register_Masks */


/* FSKDT - Peripheral instance base addresses */
/** Peripheral FSKDT base address */
#define FSKDT_BASE                               (0x40034000u)
/** Peripheral FSKDT base pointer */
#define FSKDT                                    ((FSKDT_Type *)FSKDT_BASE)
#define FSKDT_BASE_PTR                           (FSKDT)
/** Array initializer of FSKDT peripheral base addresses */
#define FSKDT_BASE_ADDRS                         { FSKDT_BASE }
/** Array initializer of FSKDT peripheral base pointers */
#define FSKDT_BASE_PTRS                          { FSKDT }

/* ----------------------------------------------------------------------------
   -- FSKDT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSKDT_Register_Accessor_Macros FSKDT - Register accessor macros
 * @{
 */


/* FSKDT - Register instance definitions */
/* FSKDT */
#define FSKDT_CR                                 FSKDT_CR_REG(FSKDT)
#define FSKDT_SR                                 FSKDT_SR_REG(FSKDT)
#define FSKDT_PH0                                FSKDT_PH0_REG(FSKDT)
#define FSKDT_PH1                                FSKDT_PH1_REG(FSKDT)
#define FSKDT_PH2                                FSKDT_PH2_REG(FSKDT)
#define FSKDT_CURPOS                             FSKDT_CURPOS_REG(FSKDT)
#define FSKDT_OPCTH                              FSKDT_OPCTH_REG(FSKDT)
#define FSKDT_ERRTH                              FSKDT_ERRTH_REG(FSKDT)
#define FSKDT_DATA                               FSKDT_DATA_REG(FSKDT)
#define FSKDT_DSR                                FSKDT_DSR_REG(FSKDT)

/*!
 * @}
 */ /* end of group FSKDT_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group FSKDT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FTM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Peripheral_Access_Layer FTM Peripheral Access Layer
 * @{
 */

/** FTM - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC;                                /**< Status And Control, offset: 0x0 */
  __IO uint32_t CNT;                               /**< Counter, offset: 0x4 */
  __IO uint32_t MOD;                               /**< Modulo, offset: 0x8 */
  struct {                                         /* offset: 0xC, array step: 0x8 */
    __IO uint32_t CnSC;                              /**< Channel (n) Status And Control, array offset: 0xC, array step: 0x8 */
    __IO uint32_t CnV;                               /**< Channel (n) Value, array offset: 0x10, array step: 0x8 */
  } CONTROLS[2];
       uint8_t RESERVED_0[80];
  __IO uint32_t EXTTRIG;                           /**< FTM External Trigger, offset: 0x6C */
} FTM_Type, *FTM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Register_Accessor_Macros FTM - Register accessor macros
 * @{
 */


/* FTM - Register accessors */
#define FTM_SC_REG(base)                         ((base)->SC)
#define FTM_CNT_REG(base)                        ((base)->CNT)
#define FTM_MOD_REG(base)                        ((base)->MOD)
#define FTM_CnSC_REG(base,index)                 ((base)->CONTROLS[index].CnSC)
#define FTM_CnV_REG(base,index)                  ((base)->CONTROLS[index].CnV)
#define FTM_EXTTRIG_REG(base)                    ((base)->EXTTRIG)

/*!
 * @}
 */ /* end of group FTM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Register_Masks FTM Register Masks
 * @{
 */

/* SC Bit Fields */
#define FTM_SC_PS_MASK                           0x7u
#define FTM_SC_PS_SHIFT                          0
#define FTM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<FTM_SC_PS_SHIFT))&FTM_SC_PS_MASK)
#define FTM_SC_CLKS_MASK                         0x18u
#define FTM_SC_CLKS_SHIFT                        3
#define FTM_SC_CLKS(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_SC_CLKS_SHIFT))&FTM_SC_CLKS_MASK)
#define FTM_SC_CPWMS_MASK                        0x20u
#define FTM_SC_CPWMS_SHIFT                       5
#define FTM_SC_TOIE_MASK                         0x40u
#define FTM_SC_TOIE_SHIFT                        6
#define FTM_SC_TOF_MASK                          0x80u
#define FTM_SC_TOF_SHIFT                         7
/* CNT Bit Fields */
#define FTM_CNT_COUNT_MASK                       0xFFFFu
#define FTM_CNT_COUNT_SHIFT                      0
#define FTM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CNT_COUNT_SHIFT))&FTM_CNT_COUNT_MASK)
/* MOD Bit Fields */
#define FTM_MOD_MOD_MASK                         0xFFFFu
#define FTM_MOD_MOD_SHIFT                        0
#define FTM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_MOD_MOD_SHIFT))&FTM_MOD_MOD_MASK)
/* CnSC Bit Fields */
#define FTM_CnSC_ELSA_MASK                       0x4u
#define FTM_CnSC_ELSA_SHIFT                      2
#define FTM_CnSC_ELSB_MASK                       0x8u
#define FTM_CnSC_ELSB_SHIFT                      3
#define FTM_CnSC_MSA_MASK                        0x10u
#define FTM_CnSC_MSA_SHIFT                       4
#define FTM_CnSC_MSB_MASK                        0x20u
#define FTM_CnSC_MSB_SHIFT                       5
#define FTM_CnSC_CHIE_MASK                       0x40u
#define FTM_CnSC_CHIE_SHIFT                      6
#define FTM_CnSC_CHF_MASK                        0x80u
#define FTM_CnSC_CHF_SHIFT                       7
/* CnV Bit Fields */
#define FTM_CnV_VAL_MASK                         0xFFFFu
#define FTM_CnV_VAL_SHIFT                        0
#define FTM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_CnV_VAL_SHIFT))&FTM_CnV_VAL_MASK)
/* EXTTRIG Bit Fields */
#define FTM_EXTTRIG_INITTRIGEN_MASK              0x40u
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             6

/*!
 * @}
 */ /* end of group FTM_Register_Masks */


/* FTM - Peripheral instance base addresses */
/** Peripheral FTM0 base address */
#define FTM0_BASE                                (0x40038000u)
/** Peripheral FTM0 base pointer */
#define FTM0                                     ((FTM_Type *)FTM0_BASE)
#define FTM0_BASE_PTR                            (FTM0)
/** Peripheral FTM1 base address */
#define FTM1_BASE                                (0x40039000u)
/** Peripheral FTM1 base pointer */
#define FTM1                                     ((FTM_Type *)FTM1_BASE)
#define FTM1_BASE_PTR                            (FTM1)
/** Array initializer of FTM peripheral base addresses */
#define FTM_BASE_ADDRS                           { FTM0_BASE, FTM1_BASE }
/** Array initializer of FTM peripheral base pointers */
#define FTM_BASE_PTRS                            { FTM0, FTM1 }

/* ----------------------------------------------------------------------------
   -- FTM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Register_Accessor_Macros FTM - Register accessor macros
 * @{
 */


/* FTM - Register instance definitions */
/* FTM0 */
#define FTM0_SC                                  FTM_SC_REG(FTM0)
#define FTM0_CNT                                 FTM_CNT_REG(FTM0)
#define FTM0_MOD                                 FTM_MOD_REG(FTM0)
#define FTM0_C0SC                                FTM_CnSC_REG(FTM0,0)
#define FTM0_C0V                                 FTM_CnV_REG(FTM0,0)
#define FTM0_C1SC                                FTM_CnSC_REG(FTM0,1)
#define FTM0_C1V                                 FTM_CnV_REG(FTM0,1)
#define FTM0_EXTTRIG                             FTM_EXTTRIG_REG(FTM0)
/* FTM1 */
#define FTM1_SC                                  FTM_SC_REG(FTM1)
#define FTM1_CNT                                 FTM_CNT_REG(FTM1)
#define FTM1_MOD                                 FTM_MOD_REG(FTM1)
#define FTM1_C0SC                                FTM_CnSC_REG(FTM1,0)
#define FTM1_C0V                                 FTM_CnV_REG(FTM1,0)
#define FTM1_C1SC                                FTM_CnSC_REG(FTM1,1)
#define FTM1_C1V                                 FTM_CnV_REG(FTM1,1)
#define FTM1_EXTTRIG                             FTM_EXTTRIG_REG(FTM1)

/* FTM - Register array accessors */
#define FTM0_CnSC(index)                         FTM_CnSC_REG(FTM0,index)
#define FTM1_CnSC(index)                         FTM_CnSC_REG(FTM1,index)
#define FTM0_CnV(index)                          FTM_CnV_REG(FTM0,index)
#define FTM1_CnV(index)                          FTM_CnV_REG(FTM1,index)

/*!
 * @}
 */ /* end of group FTM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group FTM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FTMRE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTMRE_Peripheral_Access_Layer FTMRE Peripheral Access Layer
 * @{
 */

/** FTMRE - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[1];
  __IO uint8_t FCCOBIX;                            /**< Flash CCOB Index Register, offset: 0x1 */
  __I  uint8_t FSEC;                               /**< Flash Security Register, offset: 0x2 */
  __IO uint8_t FCLKDIV;                            /**< Flash Clock Divider Register, offset: 0x3 */
       uint8_t RESERVED_1[1];
  __IO uint8_t FSTAT;                              /**< Flash Status Register, offset: 0x5 */
       uint8_t RESERVED_2[1];
  __IO uint8_t FCNFG;                              /**< Flash Configuration Register, offset: 0x7 */
  __IO uint8_t FCCOBLO;                            /**< Flash Common Command Object Register: Low, offset: 0x8 */
  __IO uint8_t FCCOBHI;                            /**< Flash Common Command Object Register:High, offset: 0x9 */
       uint8_t RESERVED_3[1];
  __IO uint8_t FPROT;                              /**< Flash Protection Register, offset: 0xB */
       uint8_t RESERVED_4[3];
  __I  uint8_t FOPT;                               /**< Flash Option Register, offset: 0xF */
} FTMRE_Type, *FTMRE_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTMRE - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTMRE_Register_Accessor_Macros FTMRE - Register accessor macros
 * @{
 */


/* FTMRE - Register accessors */
#define FTMRE_FCCOBIX_REG(base)                  ((base)->FCCOBIX)
#define FTMRE_FSEC_REG(base)                     ((base)->FSEC)
#define FTMRE_FCLKDIV_REG(base)                  ((base)->FCLKDIV)
#define FTMRE_FSTAT_REG(base)                    ((base)->FSTAT)
#define FTMRE_FCNFG_REG(base)                    ((base)->FCNFG)
#define FTMRE_FCCOBLO_REG(base)                  ((base)->FCCOBLO)
#define FTMRE_FCCOBHI_REG(base)                  ((base)->FCCOBHI)
#define FTMRE_FPROT_REG(base)                    ((base)->FPROT)
#define FTMRE_FOPT_REG(base)                     ((base)->FOPT)

/*!
 * @}
 */ /* end of group FTMRE_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTMRE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTMRE_Register_Masks FTMRE Register Masks
 * @{
 */

/* FCCOBIX Bit Fields */
#define FTMRE_FCCOBIX_CCOBIX_MASK                0x7u
#define FTMRE_FCCOBIX_CCOBIX_SHIFT               0
#define FTMRE_FCCOBIX_CCOBIX(x)                  (((uint8_t)(((uint8_t)(x))<<FTMRE_FCCOBIX_CCOBIX_SHIFT))&FTMRE_FCCOBIX_CCOBIX_MASK)
/* FSEC Bit Fields */
#define FTMRE_FSEC_SEC_MASK                      0x3u
#define FTMRE_FSEC_SEC_SHIFT                     0
#define FTMRE_FSEC_SEC(x)                        (((uint8_t)(((uint8_t)(x))<<FTMRE_FSEC_SEC_SHIFT))&FTMRE_FSEC_SEC_MASK)
#define FTMRE_FSEC_KEYEN_MASK                    0xC0u
#define FTMRE_FSEC_KEYEN_SHIFT                   6
#define FTMRE_FSEC_KEYEN(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRE_FSEC_KEYEN_SHIFT))&FTMRE_FSEC_KEYEN_MASK)
/* FCLKDIV Bit Fields */
#define FTMRE_FCLKDIV_FDIV_MASK                  0x3Fu
#define FTMRE_FCLKDIV_FDIV_SHIFT                 0
#define FTMRE_FCLKDIV_FDIV(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRE_FCLKDIV_FDIV_SHIFT))&FTMRE_FCLKDIV_FDIV_MASK)
#define FTMRE_FCLKDIV_FDIVLCK_MASK               0x40u
#define FTMRE_FCLKDIV_FDIVLCK_SHIFT              6
#define FTMRE_FCLKDIV_FDIVLD_MASK                0x80u
#define FTMRE_FCLKDIV_FDIVLD_SHIFT               7
/* FSTAT Bit Fields */
#define FTMRE_FSTAT_MGSTAT_MASK                  0x3u
#define FTMRE_FSTAT_MGSTAT_SHIFT                 0
#define FTMRE_FSTAT_MGSTAT(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRE_FSTAT_MGSTAT_SHIFT))&FTMRE_FSTAT_MGSTAT_MASK)
#define FTMRE_FSTAT_MGBUSY_MASK                  0x8u
#define FTMRE_FSTAT_MGBUSY_SHIFT                 3
#define FTMRE_FSTAT_FPVIOL_MASK                  0x10u
#define FTMRE_FSTAT_FPVIOL_SHIFT                 4
#define FTMRE_FSTAT_ACCERR_MASK                  0x20u
#define FTMRE_FSTAT_ACCERR_SHIFT                 5
#define FTMRE_FSTAT_CCIF_MASK                    0x80u
#define FTMRE_FSTAT_CCIF_SHIFT                   7
/* FCNFG Bit Fields */
#define FTMRE_FCNFG_ERSAREQ_MASK                 0x20u
#define FTMRE_FCNFG_ERSAREQ_SHIFT                5
#define FTMRE_FCNFG_CCIE_MASK                    0x80u
#define FTMRE_FCNFG_CCIE_SHIFT                   7
/* FCCOBLO Bit Fields */
#define FTMRE_FCCOBLO_CCOB_MASK                  0xFFu
#define FTMRE_FCCOBLO_CCOB_SHIFT                 0
#define FTMRE_FCCOBLO_CCOB(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRE_FCCOBLO_CCOB_SHIFT))&FTMRE_FCCOBLO_CCOB_MASK)
/* FCCOBHI Bit Fields */
#define FTMRE_FCCOBHI_CCOB_MASK                  0xFFu
#define FTMRE_FCCOBHI_CCOB_SHIFT                 0
#define FTMRE_FCCOBHI_CCOB(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRE_FCCOBHI_CCOB_SHIFT))&FTMRE_FCCOBHI_CCOB_MASK)
/* FPROT Bit Fields */
#define FTMRE_FPROT_FPLS_MASK                    0x3u
#define FTMRE_FPROT_FPLS_SHIFT                   0
#define FTMRE_FPROT_FPLS(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRE_FPROT_FPLS_SHIFT))&FTMRE_FPROT_FPLS_MASK)
#define FTMRE_FPROT_FPLDIS_MASK                  0x4u
#define FTMRE_FPROT_FPLDIS_SHIFT                 2
#define FTMRE_FPROT_RNV_MASK                     0x38u
#define FTMRE_FPROT_RNV_SHIFT                    3
#define FTMRE_FPROT_RNV(x)                       (((uint8_t)(((uint8_t)(x))<<FTMRE_FPROT_RNV_SHIFT))&FTMRE_FPROT_RNV_MASK)
#define FTMRE_FPROT_RNV6_MASK                    0x40u
#define FTMRE_FPROT_RNV6_SHIFT                   6
#define FTMRE_FPROT_FPOPEN_MASK                  0x80u
#define FTMRE_FPROT_FPOPEN_SHIFT                 7
/* FOPT Bit Fields */
#define FTMRE_FOPT_NV_MASK                       0xFFu
#define FTMRE_FOPT_NV_SHIFT                      0
#define FTMRE_FOPT_NV(x)                         (((uint8_t)(((uint8_t)(x))<<FTMRE_FOPT_NV_SHIFT))&FTMRE_FOPT_NV_MASK)

/*!
 * @}
 */ /* end of group FTMRE_Register_Masks */


/* FTMRE - Peripheral instance base addresses */
/** Peripheral FTMRE base address */
#define FTMRE_BASE                               (0x40020000u)
/** Peripheral FTMRE base pointer */
#define FTMRE                                    ((FTMRE_Type *)FTMRE_BASE)
#define FTMRE_BASE_PTR                           (FTMRE)
/** Array initializer of FTMRE peripheral base addresses */
#define FTMRE_BASE_ADDRS                         { FTMRE_BASE }
/** Array initializer of FTMRE peripheral base pointers */
#define FTMRE_BASE_PTRS                          { FTMRE }

/* ----------------------------------------------------------------------------
   -- FTMRE - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTMRE_Register_Accessor_Macros FTMRE - Register accessor macros
 * @{
 */


/* FTMRE - Register instance definitions */
/* FTMRE */
#define FTMRE_FCCOBIX                            FTMRE_FCCOBIX_REG(FTMRE)
#define FTMRE_FSEC                               FTMRE_FSEC_REG(FTMRE)
#define FTMRE_FCLKDIV                            FTMRE_FCLKDIV_REG(FTMRE)
#define FTMRE_FSTAT                              FTMRE_FSTAT_REG(FTMRE)
#define FTMRE_FCNFG                              FTMRE_FCNFG_REG(FTMRE)
#define FTMRE_FCCOBLO                            FTMRE_FCCOBLO_REG(FTMRE)
#define FTMRE_FCCOBHI                            FTMRE_FCCOBHI_REG(FTMRE)
#define FTMRE_FPROT                              FTMRE_FPROT_REG(FTMRE)
#define FTMRE_FOPT                               FTMRE_FOPT_REG(FTMRE)

/*!
 * @}
 */ /* end of group FTMRE_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group FTMRE_Peripheral_Access_Layer */


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
  __IO uint32_t PIDR;                              /**< Port Input Disable Register, offset: 0x18 */
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
#define GPIO_PIDR_REG(base)                      ((base)->PIDR)

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
#define GPIO_PDOR_PDO(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDOR_PDO_SHIFT))&GPIO_PDOR_PDO_MASK)
/* PSOR Bit Fields */
#define GPIO_PSOR_PTSO_MASK                      0xFFFFFFFFu
#define GPIO_PSOR_PTSO_SHIFT                     0
#define GPIO_PSOR_PTSO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PSOR_PTSO_SHIFT))&GPIO_PSOR_PTSO_MASK)
/* PCOR Bit Fields */
#define GPIO_PCOR_PTCO_MASK                      0xFFFFFFFFu
#define GPIO_PCOR_PTCO_SHIFT                     0
#define GPIO_PCOR_PTCO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PCOR_PTCO_SHIFT))&GPIO_PCOR_PTCO_MASK)
/* PTOR Bit Fields */
#define GPIO_PTOR_PTTO_MASK                      0xFFFFFFFFu
#define GPIO_PTOR_PTTO_SHIFT                     0
#define GPIO_PTOR_PTTO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PTOR_PTTO_SHIFT))&GPIO_PTOR_PTTO_MASK)
/* PDIR Bit Fields */
#define GPIO_PDIR_PDI_MASK                       0xFFFFFFFFu
#define GPIO_PDIR_PDI_SHIFT                      0
#define GPIO_PDIR_PDI(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDIR_PDI_SHIFT))&GPIO_PDIR_PDI_MASK)
/* PDDR Bit Fields */
#define GPIO_PDDR_PDD_MASK                       0xFFFFFFFFu
#define GPIO_PDDR_PDD_SHIFT                      0
#define GPIO_PDDR_PDD(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDDR_PDD_SHIFT))&GPIO_PDDR_PDD_MASK)
/* PIDR Bit Fields */
#define GPIO_PIDR_PID_MASK                       0xFFFFFFFFu
#define GPIO_PIDR_PID_SHIFT                      0
#define GPIO_PIDR_PID(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PIDR_PID_SHIFT))&GPIO_PIDR_PID_MASK)

/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base address */
#define GPIOA_BASE                               (0x4000F000u)
/** Peripheral GPIOA base pointer */
#define GPIOA                                    ((GPIO_Type *)GPIOA_BASE)
#define GPIOA_BASE_PTR                           (GPIOA)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIOA_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIOA }

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
#define GPIOA_PIDR                               GPIO_PIDR_REG(GPIOA)

/*!
 * @}
 */ /* end of group GPIO_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- I2C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Peripheral_Access_Layer I2C Peripheral Access Layer
 * @{
 */

/** I2C - Register Layout Typedef */
typedef struct {
  __IO uint8_t A1;                                 /**< I2C Address Register 1, offset: 0x0 */
  __IO uint8_t F;                                  /**< I2C Frequency Divider register, offset: 0x1 */
  __IO uint8_t C1;                                 /**< I2C Control Register 1, offset: 0x2 */
  __IO uint8_t S;                                  /**< I2C Status register, offset: 0x3 */
  __IO uint8_t D;                                  /**< I2C Data I/O register, offset: 0x4 */
  __IO uint8_t C2;                                 /**< I2C Control Register 2, offset: 0x5 */
  __IO uint8_t FLT;                                /**< I2C Programmable Input Glitch Filter Register, offset: 0x6 */
  __IO uint8_t RA;                                 /**< I2C Range Address register, offset: 0x7 */
  __IO uint8_t SMB;                                /**< I2C SMBus Control and Status register, offset: 0x8 */
  __IO uint8_t A2;                                 /**< I2C Address Register 2, offset: 0x9 */
  __IO uint8_t SLTH;                               /**< I2C SCL Low Timeout Register High, offset: 0xA */
  __IO uint8_t SLTL;                               /**< I2C SCL Low Timeout Register Low, offset: 0xB */
} I2C_Type, *I2C_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros
 * @{
 */


/* I2C - Register accessors */
#define I2C_A1_REG(base)                         ((base)->A1)
#define I2C_F_REG(base)                          ((base)->F)
#define I2C_C1_REG(base)                         ((base)->C1)
#define I2C_S_REG(base)                          ((base)->S)
#define I2C_D_REG(base)                          ((base)->D)
#define I2C_C2_REG(base)                         ((base)->C2)
#define I2C_FLT_REG(base)                        ((base)->FLT)
#define I2C_RA_REG(base)                         ((base)->RA)
#define I2C_SMB_REG(base)                        ((base)->SMB)
#define I2C_A2_REG(base)                         ((base)->A2)
#define I2C_SLTH_REG(base)                       ((base)->SLTH)
#define I2C_SLTL_REG(base)                       ((base)->SLTL)

/*!
 * @}
 */ /* end of group I2C_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- I2C Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Register_Masks I2C Register Masks
 * @{
 */

/* A1 Bit Fields */
#define I2C_A1_AD_MASK                           0xFEu
#define I2C_A1_AD_SHIFT                          1
#define I2C_A1_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_A1_AD_SHIFT))&I2C_A1_AD_MASK)
/* F Bit Fields */
#define I2C_F_ICR_MASK                           0x3Fu
#define I2C_F_ICR_SHIFT                          0
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_F_ICR_SHIFT))&I2C_F_ICR_MASK)
#define I2C_F_MULT_MASK                          0xC0u
#define I2C_F_MULT_SHIFT                         6
#define I2C_F_MULT(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_F_MULT_SHIFT))&I2C_F_MULT_MASK)
/* C1 Bit Fields */
#define I2C_C1_WUEN_MASK                         0x2u
#define I2C_C1_WUEN_SHIFT                        1
#define I2C_C1_RSTA_MASK                         0x4u
#define I2C_C1_RSTA_SHIFT                        2
#define I2C_C1_TXAK_MASK                         0x8u
#define I2C_C1_TXAK_SHIFT                        3
#define I2C_C1_TX_MASK                           0x10u
#define I2C_C1_TX_SHIFT                          4
#define I2C_C1_MST_MASK                          0x20u
#define I2C_C1_MST_SHIFT                         5
#define I2C_C1_IICIE_MASK                        0x40u
#define I2C_C1_IICIE_SHIFT                       6
#define I2C_C1_IICEN_MASK                        0x80u
#define I2C_C1_IICEN_SHIFT                       7
/* S Bit Fields */
#define I2C_S_RXAK_MASK                          0x1u
#define I2C_S_RXAK_SHIFT                         0
#define I2C_S_IICIF_MASK                         0x2u
#define I2C_S_IICIF_SHIFT                        1
#define I2C_S_SRW_MASK                           0x4u
#define I2C_S_SRW_SHIFT                          2
#define I2C_S_RAM_MASK                           0x8u
#define I2C_S_RAM_SHIFT                          3
#define I2C_S_ARBL_MASK                          0x10u
#define I2C_S_ARBL_SHIFT                         4
#define I2C_S_BUSY_MASK                          0x20u
#define I2C_S_BUSY_SHIFT                         5
#define I2C_S_IAAS_MASK                          0x40u
#define I2C_S_IAAS_SHIFT                         6
#define I2C_S_TCF_MASK                           0x80u
#define I2C_S_TCF_SHIFT                          7
/* D Bit Fields */
#define I2C_D_DATA_MASK                          0xFFu
#define I2C_D_DATA_SHIFT                         0
#define I2C_D_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_D_DATA_SHIFT))&I2C_D_DATA_MASK)
/* C2 Bit Fields */
#define I2C_C2_AD_MASK                           0x7u
#define I2C_C2_AD_SHIFT                          0
#define I2C_C2_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C2_AD_SHIFT))&I2C_C2_AD_MASK)
#define I2C_C2_RMEN_MASK                         0x8u
#define I2C_C2_RMEN_SHIFT                        3
#define I2C_C2_SBRC_MASK                         0x10u
#define I2C_C2_SBRC_SHIFT                        4
#define I2C_C2_ADEXT_MASK                        0x40u
#define I2C_C2_ADEXT_SHIFT                       6
#define I2C_C2_GCAEN_MASK                        0x80u
#define I2C_C2_GCAEN_SHIFT                       7
/* FLT Bit Fields */
#define I2C_FLT_FLT_MASK                         0xFu
#define I2C_FLT_FLT_SHIFT                        0
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_FLT_FLT_SHIFT))&I2C_FLT_FLT_MASK)
#define I2C_FLT_STARTF_MASK                      0x10u
#define I2C_FLT_STARTF_SHIFT                     4
#define I2C_FLT_SSIE_MASK                        0x20u
#define I2C_FLT_SSIE_SHIFT                       5
#define I2C_FLT_STOPF_MASK                       0x40u
#define I2C_FLT_STOPF_SHIFT                      6
#define I2C_FLT_SHEN_MASK                        0x80u
#define I2C_FLT_SHEN_SHIFT                       7
/* RA Bit Fields */
#define I2C_RA_RAD_MASK                          0xFEu
#define I2C_RA_RAD_SHIFT                         1
#define I2C_RA_RAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_RA_RAD_SHIFT))&I2C_RA_RAD_MASK)
/* SMB Bit Fields */
#define I2C_SMB_SHTF2IE_MASK                     0x1u
#define I2C_SMB_SHTF2IE_SHIFT                    0
#define I2C_SMB_SHTF2_MASK                       0x2u
#define I2C_SMB_SHTF2_SHIFT                      1
#define I2C_SMB_SHTF1_MASK                       0x4u
#define I2C_SMB_SHTF1_SHIFT                      2
#define I2C_SMB_SLTF_MASK                        0x8u
#define I2C_SMB_SLTF_SHIFT                       3
#define I2C_SMB_TCKSEL_MASK                      0x10u
#define I2C_SMB_TCKSEL_SHIFT                     4
#define I2C_SMB_SIICAEN_MASK                     0x20u
#define I2C_SMB_SIICAEN_SHIFT                    5
#define I2C_SMB_ALERTEN_MASK                     0x40u
#define I2C_SMB_ALERTEN_SHIFT                    6
#define I2C_SMB_FACK_MASK                        0x80u
#define I2C_SMB_FACK_SHIFT                       7
/* A2 Bit Fields */
#define I2C_A2_SAD_MASK                          0xFEu
#define I2C_A2_SAD_SHIFT                         1
#define I2C_A2_SAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_A2_SAD_SHIFT))&I2C_A2_SAD_MASK)
/* SLTH Bit Fields */
#define I2C_SLTH_SSLT_MASK                       0xFFu
#define I2C_SLTH_SSLT_SHIFT                      0
#define I2C_SLTH_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTH_SSLT_SHIFT))&I2C_SLTH_SSLT_MASK)
/* SLTL Bit Fields */
#define I2C_SLTL_SSLT_MASK                       0xFFu
#define I2C_SLTL_SSLT_SHIFT                      0
#define I2C_SLTL_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTL_SSLT_SHIFT))&I2C_SLTL_SSLT_MASK)

/*!
 * @}
 */ /* end of group I2C_Register_Masks */


/* I2C - Peripheral instance base addresses */
/** Peripheral I2C0 base address */
#define I2C0_BASE                                (0x40066000u)
/** Peripheral I2C0 base pointer */
#define I2C0                                     ((I2C_Type *)I2C0_BASE)
#define I2C0_BASE_PTR                            (I2C0)
/** Array initializer of I2C peripheral base addresses */
#define I2C_BASE_ADDRS                           { I2C0_BASE }
/** Array initializer of I2C peripheral base pointers */
#define I2C_BASE_PTRS                            { I2C0 }

/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros
 * @{
 */


/* I2C - Register instance definitions */
/* I2C0 */
#define I2C0_A1                                  I2C_A1_REG(I2C0)
#define I2C0_F                                   I2C_F_REG(I2C0)
#define I2C0_C1                                  I2C_C1_REG(I2C0)
#define I2C0_S                                   I2C_S_REG(I2C0)
#define I2C0_D                                   I2C_D_REG(I2C0)
#define I2C0_C2                                  I2C_C2_REG(I2C0)
#define I2C0_FLT                                 I2C_FLT_REG(I2C0)
#define I2C0_RA                                  I2C_RA_REG(I2C0)
#define I2C0_SMB                                 I2C_SMB_REG(I2C0)
#define I2C0_A2                                  I2C_A2_REG(I2C0)
#define I2C0_SLTH                                I2C_SLTH_REG(I2C0)
#define I2C0_SLTL                                I2C_SLTL_REG(I2C0)

/*!
 * @}
 */ /* end of group I2C_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group I2C_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- ICS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ICS_Peripheral_Access_Layer ICS Peripheral Access Layer
 * @{
 */

/** ICS - Register Layout Typedef */
typedef struct {
  __IO uint8_t C1;                                 /**< ICS Control Register 1, offset: 0x0 */
  __IO uint8_t C2;                                 /**< ICS Control Register 2, offset: 0x1 */
  __IO uint8_t C3;                                 /**< ICS Control Register 3, offset: 0x2 */
  __IO uint8_t C4;                                 /**< ICS Control Register 4, offset: 0x3 */
  __IO uint8_t S;                                  /**< ICS Status Register, offset: 0x4 */
} ICS_Type, *ICS_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ICS - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ICS_Register_Accessor_Macros ICS - Register accessor macros
 * @{
 */


/* ICS - Register accessors */
#define ICS_C1_REG(base)                         ((base)->C1)
#define ICS_C2_REG(base)                         ((base)->C2)
#define ICS_C3_REG(base)                         ((base)->C3)
#define ICS_C4_REG(base)                         ((base)->C4)
#define ICS_S_REG(base)                          ((base)->S)

/*!
 * @}
 */ /* end of group ICS_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ICS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ICS_Register_Masks ICS Register Masks
 * @{
 */

/* C1 Bit Fields */
#define ICS_C1_IREFSTEN_MASK                     0x1u
#define ICS_C1_IREFSTEN_SHIFT                    0
#define ICS_C1_IRCLKEN_MASK                      0x2u
#define ICS_C1_IRCLKEN_SHIFT                     1
#define ICS_C1_IREFS_MASK                        0x4u
#define ICS_C1_IREFS_SHIFT                       2
#define ICS_C1_RDIV_MASK                         0x38u
#define ICS_C1_RDIV_SHIFT                        3
#define ICS_C1_RDIV(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_C1_RDIV_SHIFT))&ICS_C1_RDIV_MASK)
#define ICS_C1_CLKS_MASK                         0xC0u
#define ICS_C1_CLKS_SHIFT                        6
#define ICS_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_C1_CLKS_SHIFT))&ICS_C1_CLKS_MASK)
/* C2 Bit Fields */
#define ICS_C2_LP_MASK                           0x10u
#define ICS_C2_LP_SHIFT                          4
#define ICS_C2_BDIV_MASK                         0xE0u
#define ICS_C2_BDIV_SHIFT                        5
#define ICS_C2_BDIV(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_C2_BDIV_SHIFT))&ICS_C2_BDIV_MASK)
/* C3 Bit Fields */
#define ICS_C3_SCTRIM_MASK                       0xFFu
#define ICS_C3_SCTRIM_SHIFT                      0
#define ICS_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<ICS_C3_SCTRIM_SHIFT))&ICS_C3_SCTRIM_MASK)
/* C4 Bit Fields */
#define ICS_C4_SCFTRIM_MASK                      0x1u
#define ICS_C4_SCFTRIM_SHIFT                     0
#define ICS_C4_CME_MASK                          0x20u
#define ICS_C4_CME_SHIFT                         5
#define ICS_C4_LOLIE_MASK                        0x80u
#define ICS_C4_LOLIE_SHIFT                       7
/* S Bit Fields */
#define ICS_S_CLKST_MASK                         0xCu
#define ICS_S_CLKST_SHIFT                        2
#define ICS_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_S_CLKST_SHIFT))&ICS_S_CLKST_MASK)
#define ICS_S_IREFST_MASK                        0x10u
#define ICS_S_IREFST_SHIFT                       4
#define ICS_S_LOCK_MASK                          0x40u
#define ICS_S_LOCK_SHIFT                         6
#define ICS_S_LOLS_MASK                          0x80u
#define ICS_S_LOLS_SHIFT                         7

/*!
 * @}
 */ /* end of group ICS_Register_Masks */


/* ICS - Peripheral instance base addresses */
/** Peripheral ICS base address */
#define ICS_BASE                                 (0x40064000u)
/** Peripheral ICS base pointer */
#define ICS                                      ((ICS_Type *)ICS_BASE)
#define ICS_BASE_PTR                             (ICS)
/** Array initializer of ICS peripheral base addresses */
#define ICS_BASE_ADDRS                           { ICS_BASE }
/** Array initializer of ICS peripheral base pointers */
#define ICS_BASE_PTRS                            { ICS }

/* ----------------------------------------------------------------------------
   -- ICS - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ICS_Register_Accessor_Macros ICS - Register accessor macros
 * @{
 */


/* ICS - Register instance definitions */
/* ICS */
#define ICS_C1                                   ICS_C1_REG(ICS)
#define ICS_C2                                   ICS_C2_REG(ICS)
#define ICS_C3                                   ICS_C3_REG(ICS)
#define ICS_C4                                   ICS_C4_REG(ICS)
#define ICS_S                                    ICS_S_REG(ICS)

/*!
 * @}
 */ /* end of group ICS_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group ICS_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- IRQ Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQ_Peripheral_Access_Layer IRQ Peripheral Access Layer
 * @{
 */

/** IRQ - Register Layout Typedef */
typedef struct {
  __IO uint8_t SC;                                 /**< Interrupt Pin Request Status and Control Register, offset: 0x0 */
} IRQ_Type, *IRQ_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- IRQ - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQ_Register_Accessor_Macros IRQ - Register accessor macros
 * @{
 */


/* IRQ - Register accessors */
#define IRQ_SC_REG(base)                         ((base)->SC)

/*!
 * @}
 */ /* end of group IRQ_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- IRQ Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQ_Register_Masks IRQ Register Masks
 * @{
 */

/* SC Bit Fields */
#define IRQ_SC_IRQMOD_MASK                       0x1u
#define IRQ_SC_IRQMOD_SHIFT                      0
#define IRQ_SC_IRQIE_MASK                        0x2u
#define IRQ_SC_IRQIE_SHIFT                       1
#define IRQ_SC_IRQACK_MASK                       0x4u
#define IRQ_SC_IRQACK_SHIFT                      2
#define IRQ_SC_IRQF_MASK                         0x8u
#define IRQ_SC_IRQF_SHIFT                        3
#define IRQ_SC_IRQPE_MASK                        0x10u
#define IRQ_SC_IRQPE_SHIFT                       4
#define IRQ_SC_IRQEDG_MASK                       0x20u
#define IRQ_SC_IRQEDG_SHIFT                      5
#define IRQ_SC_IRQPDD_MASK                       0x40u
#define IRQ_SC_IRQPDD_SHIFT                      6

/*!
 * @}
 */ /* end of group IRQ_Register_Masks */


/* IRQ - Peripheral instance base addresses */
/** Peripheral IRQ base address */
#define IRQ_BASE                                 (0x40031000u)
/** Peripheral IRQ base pointer */
#define IRQ                                      ((IRQ_Type *)IRQ_BASE)
#define IRQ_BASE_PTR                             (IRQ)
/** Array initializer of IRQ peripheral base addresses */
#define IRQ_BASE_ADDRS                           { IRQ_BASE }
/** Array initializer of IRQ peripheral base pointers */
#define IRQ_BASE_PTRS                            { IRQ }

/* ----------------------------------------------------------------------------
   -- IRQ - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQ_Register_Accessor_Macros IRQ - Register accessor macros
 * @{
 */


/* IRQ - Register instance definitions */
/* IRQ */
#define IRQ_SC                                   IRQ_SC_REG(IRQ)

/*!
 * @}
 */ /* end of group IRQ_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group IRQ_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LDO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LDO_Peripheral_Access_Layer LDO Peripheral Access Layer
 * @{
 */

/** LDO - Register Layout Typedef */
typedef struct {
  __IO uint16_t CR;                                /**< Control Register, offset: 0x0 */
  __IO uint16_t SR;                                /**< Status Register, offset: 0x2 */
  __IO uint16_t CTRM;                              /**< Current Trim Register, offset: 0x4 */
  __IO uint16_t VTRM;                              /**< Voltage Trim Register, offset: 0x6 */
  __IO uint16_t OCFILT;                            /**< Overcurrent Filter Register, offset: 0x8 */
  __IO uint16_t OVFILT;                            /**< Overvoltage Filter Register, offset: 0xA */
  __IO uint16_t SCR;                               /**< Shutdown Control Register, offset: 0xC */
} LDO_Type, *LDO_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LDO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LDO_Register_Accessor_Macros LDO - Register accessor macros
 * @{
 */


/* LDO - Register accessors */
#define LDO_CR_REG(base)                         ((base)->CR)
#define LDO_SR_REG(base)                         ((base)->SR)
#define LDO_CTRM_REG(base)                       ((base)->CTRM)
#define LDO_VTRM_REG(base)                       ((base)->VTRM)
#define LDO_OCFILT_REG(base)                     ((base)->OCFILT)
#define LDO_OVFILT_REG(base)                     ((base)->OVFILT)
#define LDO_SCR_REG(base)                        ((base)->SCR)

/*!
 * @}
 */ /* end of group LDO_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LDO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LDO_Register_Masks LDO Register Masks
 * @{
 */

/* CR Bit Fields */
#define LDO_CR_OVDTE_MASK                        0x1u
#define LDO_CR_OVDTE_SHIFT                       0
#define LDO_CR_OVIE_MASK                         0x2u
#define LDO_CR_OVIE_SHIFT                        1
#define LDO_CR_OCIE_MASK                         0x4u
#define LDO_CR_OCIE_SHIFT                        2
#define LDO_CR_CPCLKPS_MASK                      0x18u
#define LDO_CR_CPCLKPS_SHIFT                     3
#define LDO_CR_CPCLKPS(x)                        (((uint16_t)(((uint16_t)(x))<<LDO_CR_CPCLKPS_SHIFT))&LDO_CR_CPCLKPS_MASK)
#define LDO_CR_OVTHLD_MASK                       0xC0u
#define LDO_CR_OVTHLD_SHIFT                      6
#define LDO_CR_OVTHLD(x)                         (((uint16_t)(((uint16_t)(x))<<LDO_CR_OVTHLD_SHIFT))&LDO_CR_OVTHLD_MASK)
#define LDO_CR_OCDTE_MASK                        0x100u
#define LDO_CR_OCDTE_SHIFT                       8
#define LDO_CR_BASHDN_MASK                       0x200u
#define LDO_CR_BASHDN_SHIFT                      9
#define LDO_CR_OCTHLD_MASK                       0x1C00u
#define LDO_CR_OCTHLD_SHIFT                      10
#define LDO_CR_OCTHLD(x)                         (((uint16_t)(((uint16_t)(x))<<LDO_CR_OCTHLD_SHIFT))&LDO_CR_OCTHLD_MASK)
#define LDO_CR_LDOREGEN_MASK                     0x2000u
#define LDO_CR_LDOREGEN_SHIFT                    13
#define LDO_CR_CPEN_MASK                         0x4000u
#define LDO_CR_CPEN_SHIFT                        14
#define LDO_CR_LDOEN_MASK                        0x8000u
#define LDO_CR_LDOEN_SHIFT                       15
/* SR Bit Fields */
#define LDO_SR_OVF_MASK                          0x1u
#define LDO_SR_OVF_SHIFT                         0
#define LDO_SR_OCF_MASK                          0x2u
#define LDO_SR_OCF_SHIFT                         1
#define LDO_SR_OVST_MASK                         0x4u
#define LDO_SR_OVST_SHIFT                        2
#define LDO_SR_OCST_MASK                         0x8u
#define LDO_SR_OCST_SHIFT                        3
#define LDO_SR_CPOKF_MASK                        0x8000u
#define LDO_SR_CPOKF_SHIFT                       15
/* CTRM Bit Fields */
#define LDO_CTRM_CTRM_MASK                       0x1FFu
#define LDO_CTRM_CTRM_SHIFT                      0
#define LDO_CTRM_CTRM(x)                         (((uint16_t)(((uint16_t)(x))<<LDO_CTRM_CTRM_SHIFT))&LDO_CTRM_CTRM_MASK)
/* VTRM Bit Fields */
#define LDO_VTRM_VTRM_MASK                       0x1FFu
#define LDO_VTRM_VTRM_SHIFT                      0
#define LDO_VTRM_VTRM(x)                         (((uint16_t)(((uint16_t)(x))<<LDO_VTRM_VTRM_SHIFT))&LDO_VTRM_VTRM_MASK)
/* OCFILT Bit Fields */
#define LDO_OCFILT_CNT_MASK                      0xFFFFu
#define LDO_OCFILT_CNT_SHIFT                     0
#define LDO_OCFILT_CNT(x)                        (((uint16_t)(((uint16_t)(x))<<LDO_OCFILT_CNT_SHIFT))&LDO_OCFILT_CNT_MASK)
/* OVFILT Bit Fields */
#define LDO_OVFILT_CNT_MASK                      0xFFFFu
#define LDO_OVFILT_CNT_SHIFT                     0
#define LDO_OVFILT_CNT(x)                        (((uint16_t)(((uint16_t)(x))<<LDO_OVFILT_CNT_SHIFT))&LDO_OVFILT_CNT_MASK)
/* SCR Bit Fields */
#define LDO_SCR_OCASDE_MASK                      0x1u
#define LDO_SCR_OCASDE_SHIFT                     0
#define LDO_SCR_OVASDE_MASK                      0x2u
#define LDO_SCR_OVASDE_SHIFT                     1
#define LDO_SCR_EXTSDE_MASK                      0x4u
#define LDO_SCR_EXTSDE_SHIFT                     2

/*!
 * @}
 */ /* end of group LDO_Register_Masks */


/* LDO - Peripheral instance base addresses */
/** Peripheral LDO base address */
#define LDO_BASE                                 (0x40070000u)
/** Peripheral LDO base pointer */
#define LDO                                      ((LDO_Type *)LDO_BASE)
#define LDO_BASE_PTR                             (LDO)
/** Array initializer of LDO peripheral base addresses */
#define LDO_BASE_ADDRS                           { LDO_BASE }
/** Array initializer of LDO peripheral base pointers */
#define LDO_BASE_PTRS                            { LDO }

/* ----------------------------------------------------------------------------
   -- LDO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LDO_Register_Accessor_Macros LDO - Register accessor macros
 * @{
 */


/* LDO - Register instance definitions */
/* LDO */
#define LDO_CR                                   LDO_CR_REG(LDO)
#define LDO_SR                                   LDO_SR_REG(LDO)
#define LDO_CTRM                                 LDO_CTRM_REG(LDO)
#define LDO_VTRM                                 LDO_VTRM_REG(LDO)
#define LDO_OCFILT                               LDO_OCFILT_REG(LDO)
#define LDO_OVFILT                               LDO_OVFILT_REG(LDO)
#define LDO_SCR                                  LDO_SCR_REG(LDO)

/*!
 * @}
 */ /* end of group LDO_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group LDO_Peripheral_Access_Layer */


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
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLASC_ASC_SHIFT))&MCM_PLASC_ASC_MASK)
/* PLAMC Bit Fields */
#define MCM_PLAMC_AMC_MASK                       0xFFu
#define MCM_PLAMC_AMC_SHIFT                      0
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLAMC_AMC_SHIFT))&MCM_PLAMC_AMC_MASK)
/* PLACR Bit Fields */
#define MCM_PLACR_ARB_MASK                       0x200u
#define MCM_PLACR_ARB_SHIFT                      9
#define MCM_PLACR_EFDS_MASK                      0x4000u
#define MCM_PLACR_EFDS_SHIFT                     14
#define MCM_PLACR_DFCS_MASK                      0x8000u
#define MCM_PLACR_DFCS_SHIFT                     15
#define MCM_PLACR_ESFC_MASK                      0x10000u
#define MCM_PLACR_ESFC_SHIFT                     16

/*!
 * @}
 */ /* end of group MCM_Register_Masks */


/* MCM - Peripheral instance base addresses */
/** Peripheral MCM base address */
#define MCM_BASE                                 (0xF0003000u)
/** Peripheral MCM base pointer */
#define MCM                                      ((MCM_Type *)MCM_BASE)
#define MCM_BASE_PTR                             (MCM)
/** Array initializer of MCM peripheral base addresses */
#define MCM_BASE_ADDRS                           { MCM_BASE }
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS                            { MCM }

/* ----------------------------------------------------------------------------
   -- MCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Accessor_Macros MCM - Register accessor macros
 * @{
 */


/* MCM - Register instance definitions */
/* MCM */
#define MCM_PLASC                                MCM_PLASC_REG(MCM)
#define MCM_PLAMC                                MCM_PLAMC_REG(MCM)
#define MCM_PLACR                                MCM_PLACR_REG(MCM)

/*!
 * @}
 */ /* end of group MCM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- NV Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Peripheral_Access_Layer NV Peripheral Access Layer
 * @{
 */

/** NV - Register Layout Typedef */
typedef struct {
  __I  uint8_t BACKKEY0;                           /**< Backdoor Comparison Key 0, offset: 0x0 */
  __I  uint8_t BACKKEY1;                           /**< Backdoor Comparison Key 1, offset: 0x1 */
  __I  uint8_t BACKKEY2;                           /**< Backdoor Comparison Key 2, offset: 0x2 */
  __I  uint8_t BACKKEY3;                           /**< Backdoor Comparison Key 3, offset: 0x3 */
  __I  uint8_t BACKKEY4;                           /**< Backdoor Comparison Key 4, offset: 0x4 */
  __I  uint8_t BACKKEY5;                           /**< Backdoor Comparison Key 5, offset: 0x5 */
  __I  uint8_t BACKKEY6;                           /**< Backdoor Comparison Key 6, offset: 0x6 */
  __I  uint8_t BACKKEY7;                           /**< Backdoor Comparison Key 7, offset: 0x7 */
       uint8_t RESERVED_0[5];
  __I  uint8_t FPROT;                              /**< Non-volatile P-Flash Protection Register, offset: 0xD */
  __I  uint8_t FSEC;                               /**< Non-volatile Flash Security Register, offset: 0xE */
  __I  uint8_t FOPT;                               /**< Non-volatile Flash Option Register, offset: 0xF */
} NV_Type, *NV_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Register_Accessor_Macros NV - Register accessor macros
 * @{
 */


/* NV - Register accessors */
#define NV_BACKKEY0_REG(base)                    ((base)->BACKKEY0)
#define NV_BACKKEY1_REG(base)                    ((base)->BACKKEY1)
#define NV_BACKKEY2_REG(base)                    ((base)->BACKKEY2)
#define NV_BACKKEY3_REG(base)                    ((base)->BACKKEY3)
#define NV_BACKKEY4_REG(base)                    ((base)->BACKKEY4)
#define NV_BACKKEY5_REG(base)                    ((base)->BACKKEY5)
#define NV_BACKKEY6_REG(base)                    ((base)->BACKKEY6)
#define NV_BACKKEY7_REG(base)                    ((base)->BACKKEY7)
#define NV_FPROT_REG(base)                       ((base)->FPROT)
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

/* BACKKEY0 Bit Fields */
#define NV_BACKKEY0_KEY_MASK                     0xFFu
#define NV_BACKKEY0_KEY_SHIFT                    0
#define NV_BACKKEY0_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY0_KEY_SHIFT))&NV_BACKKEY0_KEY_MASK)
/* BACKKEY1 Bit Fields */
#define NV_BACKKEY1_KEY_MASK                     0xFFu
#define NV_BACKKEY1_KEY_SHIFT                    0
#define NV_BACKKEY1_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY1_KEY_SHIFT))&NV_BACKKEY1_KEY_MASK)
/* BACKKEY2 Bit Fields */
#define NV_BACKKEY2_KEY_MASK                     0xFFu
#define NV_BACKKEY2_KEY_SHIFT                    0
#define NV_BACKKEY2_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY2_KEY_SHIFT))&NV_BACKKEY2_KEY_MASK)
/* BACKKEY3 Bit Fields */
#define NV_BACKKEY3_KEY_MASK                     0xFFu
#define NV_BACKKEY3_KEY_SHIFT                    0
#define NV_BACKKEY3_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY3_KEY_SHIFT))&NV_BACKKEY3_KEY_MASK)
/* BACKKEY4 Bit Fields */
#define NV_BACKKEY4_KEY_MASK                     0xFFu
#define NV_BACKKEY4_KEY_SHIFT                    0
#define NV_BACKKEY4_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY4_KEY_SHIFT))&NV_BACKKEY4_KEY_MASK)
/* BACKKEY5 Bit Fields */
#define NV_BACKKEY5_KEY_MASK                     0xFFu
#define NV_BACKKEY5_KEY_SHIFT                    0
#define NV_BACKKEY5_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY5_KEY_SHIFT))&NV_BACKKEY5_KEY_MASK)
/* BACKKEY6 Bit Fields */
#define NV_BACKKEY6_KEY_MASK                     0xFFu
#define NV_BACKKEY6_KEY_SHIFT                    0
#define NV_BACKKEY6_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY6_KEY_SHIFT))&NV_BACKKEY6_KEY_MASK)
/* BACKKEY7 Bit Fields */
#define NV_BACKKEY7_KEY_MASK                     0xFFu
#define NV_BACKKEY7_KEY_SHIFT                    0
#define NV_BACKKEY7_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY7_KEY_SHIFT))&NV_BACKKEY7_KEY_MASK)
/* FPROT Bit Fields */
#define NV_FPROT_FPLS_MASK                       0x3u
#define NV_FPROT_FPLS_SHIFT                      0
#define NV_FPROT_FPLS(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FPROT_FPLS_SHIFT))&NV_FPROT_FPLS_MASK)
#define NV_FPROT_FPLDIS_MASK                     0x4u
#define NV_FPROT_FPLDIS_SHIFT                    2
#define NV_FPROT_FPHS_MASK                       0x18u
#define NV_FPROT_FPHS_SHIFT                      3
#define NV_FPROT_FPHS(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FPROT_FPHS_SHIFT))&NV_FPROT_FPHS_MASK)
#define NV_FPROT_FPHDIS_MASK                     0x20u
#define NV_FPROT_FPHDIS_SHIFT                    5
#define NV_FPROT_FPOPEN_MASK                     0x80u
#define NV_FPROT_FPOPEN_SHIFT                    7
/* FSEC Bit Fields */
#define NV_FSEC_SEC_MASK                         0x3u
#define NV_FSEC_SEC_SHIFT                        0
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<NV_FSEC_SEC_SHIFT))&NV_FSEC_SEC_MASK)
#define NV_FSEC_KEYEN_MASK                       0xC0u
#define NV_FSEC_KEYEN_SHIFT                      6
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FSEC_KEYEN_SHIFT))&NV_FSEC_KEYEN_MASK)

/*!
 * @}
 */ /* end of group NV_Register_Masks */


/* NV - Peripheral instance base addresses */
/** Peripheral FTMRE_FlashConfig base address */
#define FTMRE_FlashConfig_BASE                   (0x400u)
/** Peripheral FTMRE_FlashConfig base pointer */
#define FTMRE_FlashConfig                        ((NV_Type *)FTMRE_FlashConfig_BASE)
#define FTMRE_FlashConfig_BASE_PTR               (FTMRE_FlashConfig)
/** Array initializer of NV peripheral base addresses */
#define NV_BASE_ADDRS                            { FTMRE_FlashConfig_BASE }
/** Array initializer of NV peripheral base pointers */
#define NV_BASE_PTRS                             { FTMRE_FlashConfig }

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Register_Accessor_Macros NV - Register accessor macros
 * @{
 */


/* NV - Register instance definitions */
/* FTMRE_FlashConfig */
#define NV_BACKKEY0                              NV_BACKKEY0_REG(FTMRE_FlashConfig)
#define NV_BACKKEY1                              NV_BACKKEY1_REG(FTMRE_FlashConfig)
#define NV_BACKKEY2                              NV_BACKKEY2_REG(FTMRE_FlashConfig)
#define NV_BACKKEY3                              NV_BACKKEY3_REG(FTMRE_FlashConfig)
#define NV_BACKKEY4                              NV_BACKKEY4_REG(FTMRE_FlashConfig)
#define NV_BACKKEY5                              NV_BACKKEY5_REG(FTMRE_FlashConfig)
#define NV_BACKKEY6                              NV_BACKKEY6_REG(FTMRE_FlashConfig)
#define NV_BACKKEY7                              NV_BACKKEY7_REG(FTMRE_FlashConfig)
#define NV_FPROT                                 NV_FPROT_REG(FTMRE_FlashConfig)
#define NV_FSEC                                  NV_FSEC_REG(FTMRE_FlashConfig)
#define NV_FOPT                                  NV_FOPT_REG(FTMRE_FlashConfig)

/*!
 * @}
 */ /* end of group NV_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group NV_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- OSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Peripheral_Access_Layer OSC Peripheral Access Layer
 * @{
 */

/** OSC - Register Layout Typedef */
typedef struct {
  __IO uint8_t CR;                                 /**< OSC Control Register, offset: 0x0 */
} OSC_Type, *OSC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- OSC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Register_Accessor_Macros OSC - Register accessor macros
 * @{
 */


/* OSC - Register accessors */
#define OSC_CR_REG(base)                         ((base)->CR)

/*!
 * @}
 */ /* end of group OSC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- OSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Register_Masks OSC Register Masks
 * @{
 */

/* CR Bit Fields */
#define OSC_CR_OSCINIT_MASK                      0x1u
#define OSC_CR_OSCINIT_SHIFT                     0
#define OSC_CR_HGO_MASK                          0x2u
#define OSC_CR_HGO_SHIFT                         1
#define OSC_CR_RANGE_MASK                        0x4u
#define OSC_CR_RANGE_SHIFT                       2
#define OSC_CR_OSCOS_MASK                        0x10u
#define OSC_CR_OSCOS_SHIFT                       4
#define OSC_CR_OSCSTEN_MASK                      0x20u
#define OSC_CR_OSCSTEN_SHIFT                     5
#define OSC_CR_OSCEN_MASK                        0x80u
#define OSC_CR_OSCEN_SHIFT                       7

/*!
 * @}
 */ /* end of group OSC_Register_Masks */


/* OSC - Peripheral instance base addresses */
/** Peripheral OSC base address */
#define OSC_BASE                                 (0x40065000u)
/** Peripheral OSC base pointer */
#define OSC                                      ((OSC_Type *)OSC_BASE)
#define OSC_BASE_PTR                             (OSC)
/** Array initializer of OSC peripheral base addresses */
#define OSC_BASE_ADDRS                           { OSC_BASE }
/** Array initializer of OSC peripheral base pointers */
#define OSC_BASE_PTRS                            { OSC }

/* ----------------------------------------------------------------------------
   -- OSC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Register_Accessor_Macros OSC - Register accessor macros
 * @{
 */


/* OSC - Register instance definitions */
/* OSC */
#define OSC_CR                                   OSC_CR_REG(OSC)

/*!
 * @}
 */ /* end of group OSC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group OSC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PGA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PGA_Peripheral_Access_Layer PGA Peripheral Access Layer
 * @{
 */

/** PGA - Register Layout Typedef */
typedef struct {
  __IO uint8_t CTRL;                               /**< Control Register, offset: 0x0 */
} PGA_Type, *PGA_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PGA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PGA_Register_Accessor_Macros PGA - Register accessor macros
 * @{
 */


/* PGA - Register accessors */
#define PGA_CTRL_REG(base)                       ((base)->CTRL)

/*!
 * @}
 */ /* end of group PGA_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PGA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PGA_Register_Masks PGA Register Masks
 * @{
 */

/* CTRL Bit Fields */
#define PGA_CTRL_PGAEN_MASK                      0x1u
#define PGA_CTRL_PGAEN_SHIFT                     0
#define PGA_CTRL_GAIN_MASK                       0x6u
#define PGA_CTRL_GAIN_SHIFT                      1
#define PGA_CTRL_GAIN(x)                         (((uint8_t)(((uint8_t)(x))<<PGA_CTRL_GAIN_SHIFT))&PGA_CTRL_GAIN_MASK)

/*!
 * @}
 */ /* end of group PGA_Register_Masks */


/* PGA - Peripheral instance base addresses */
/** Peripheral PGA base address */
#define PGA_BASE                                 (0x40071000u)
/** Peripheral PGA base pointer */
#define PGA                                      ((PGA_Type *)PGA_BASE)
#define PGA_BASE_PTR                             (PGA)
/** Array initializer of PGA peripheral base addresses */
#define PGA_BASE_ADDRS                           { PGA_BASE }
/** Array initializer of PGA peripheral base pointers */
#define PGA_BASE_PTRS                            { PGA }

/* ----------------------------------------------------------------------------
   -- PGA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PGA_Register_Accessor_Macros PGA - Register accessor macros
 * @{
 */


/* PGA - Register instance definitions */
/* PGA */
#define PGA_CTRL                                 PGA_CTRL_REG(PGA)

/*!
 * @}
 */ /* end of group PGA_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PGA_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Peripheral_Access_Layer PIT Peripheral Access Layer
 * @{
 */

/** PIT - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< PIT Module Control Register, offset: 0x0 */
       uint8_t RESERVED_0[252];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    __IO uint32_t LDVAL;                             /**< Timer Load Value Register, array offset: 0x100, array step: 0x10 */
    __I  uint32_t CVAL;                              /**< Current Timer Value Register, array offset: 0x104, array step: 0x10 */
    __IO uint32_t TCTRL;                             /**< Timer Control Register, array offset: 0x108, array step: 0x10 */
    __IO uint32_t TFLG;                              /**< Timer Flag Register, array offset: 0x10C, array step: 0x10 */
  } CHANNEL[2];
} PIT_Type, *PIT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PIT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Register_Accessor_Macros PIT - Register accessor macros
 * @{
 */


/* PIT - Register accessors */
#define PIT_MCR_REG(base)                        ((base)->MCR)
#define PIT_LDVAL_REG(base,index)                ((base)->CHANNEL[index].LDVAL)
#define PIT_CVAL_REG(base,index)                 ((base)->CHANNEL[index].CVAL)
#define PIT_TCTRL_REG(base,index)                ((base)->CHANNEL[index].TCTRL)
#define PIT_TFLG_REG(base,index)                 ((base)->CHANNEL[index].TFLG)

/*!
 * @}
 */ /* end of group PIT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Register_Masks PIT Register Masks
 * @{
 */

/* MCR Bit Fields */
#define PIT_MCR_FRZ_MASK                         0x1u
#define PIT_MCR_FRZ_SHIFT                        0
#define PIT_MCR_MDIS_MASK                        0x2u
#define PIT_MCR_MDIS_SHIFT                       1
/* LDVAL Bit Fields */
#define PIT_LDVAL_TSV_MASK                       0xFFFFFFFFu
#define PIT_LDVAL_TSV_SHIFT                      0
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL_TSV_SHIFT))&PIT_LDVAL_TSV_MASK)
/* CVAL Bit Fields */
#define PIT_CVAL_TVL_MASK                        0xFFFFFFFFu
#define PIT_CVAL_TVL_SHIFT                       0
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_CVAL_TVL_SHIFT))&PIT_CVAL_TVL_MASK)
/* TCTRL Bit Fields */
#define PIT_TCTRL_TEN_MASK                       0x1u
#define PIT_TCTRL_TEN_SHIFT                      0
#define PIT_TCTRL_TIE_MASK                       0x2u
#define PIT_TCTRL_TIE_SHIFT                      1
#define PIT_TCTRL_CHN_MASK                       0x4u
#define PIT_TCTRL_CHN_SHIFT                      2
/* TFLG Bit Fields */
#define PIT_TFLG_TIF_MASK                        0x1u
#define PIT_TFLG_TIF_SHIFT                       0

/*!
 * @}
 */ /* end of group PIT_Register_Masks */


/* PIT - Peripheral instance base addresses */
/** Peripheral PIT base address */
#define PIT_BASE                                 (0x40037000u)
/** Peripheral PIT base pointer */
#define PIT                                      ((PIT_Type *)PIT_BASE)
#define PIT_BASE_PTR                             (PIT)
/** Array initializer of PIT peripheral base addresses */
#define PIT_BASE_ADDRS                           { PIT_BASE }
/** Array initializer of PIT peripheral base pointers */
#define PIT_BASE_PTRS                            { PIT }

/* ----------------------------------------------------------------------------
   -- PIT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Register_Accessor_Macros PIT - Register accessor macros
 * @{
 */


/* PIT - Register instance definitions */
/* PIT */
#define PIT_MCR                                  PIT_MCR_REG(PIT)
#define PIT_LDVAL0                               PIT_LDVAL_REG(PIT,0)
#define PIT_CVAL0                                PIT_CVAL_REG(PIT,0)
#define PIT_TCTRL0                               PIT_TCTRL_REG(PIT,0)
#define PIT_TFLG0                                PIT_TFLG_REG(PIT,0)
#define PIT_LDVAL1                               PIT_LDVAL_REG(PIT,1)
#define PIT_CVAL1                                PIT_CVAL_REG(PIT,1)
#define PIT_TCTRL1                               PIT_TCTRL_REG(PIT,1)
#define PIT_TFLG1                                PIT_TFLG_REG(PIT,1)

/* PIT - Register array accessors */
#define PIT_LDVAL(index)                         PIT_LDVAL_REG(PIT,index)
#define PIT_CVAL(index)                          PIT_CVAL_REG(PIT,index)
#define PIT_TCTRL(index)                         PIT_TCTRL_REG(PIT,index)
#define PIT_TFLG(index)                          PIT_TFLG_REG(PIT,index)

/*!
 * @}
 */ /* end of group PIT_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PIT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct {
  __IO uint8_t CTRL;                               /**< Control Register, offset: 0x0 */
  __IO uint8_t RST;                                /**< Reset Flags Register, offset: 0x1 */
  __IO uint8_t TPCTRLSTAT;                         /**< Temperature Control and Status Register, offset: 0x2 */
  __IO uint8_t TPTM;                               /**< Temperature Offset Step Trim Register, offset: 0x3 */
  __IO uint8_t RC20KTRM;                           /**< RC Oscillator Offset Step Trim Register, offset: 0x4 */
  __IO uint8_t LVCTLSTAT1;                         /**< Low Voltage Control and Status Register 1 (system 5 V), offset: 0x5 */
  __IO uint8_t LVCTLSTAT2;                         /**< Low Voltage Control and Status Register 2 (VREFH), offset: 0x6 */
  __IO uint8_t VREFHCFG;                           /**< VREFH Configuration Register, offset: 0x7 */
  __IO uint8_t VREFHLVW;                           /**< VREFH Low Voltage Warning (LVW) Configuration Register, offset: 0x8 */
  __I  uint8_t STAT;                               /**< Status Register, offset: 0x9 */
} PMC_Type, *PMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros
 * @{
 */


/* PMC - Register accessors */
#define PMC_CTRL_REG(base)                       ((base)->CTRL)
#define PMC_RST_REG(base)                        ((base)->RST)
#define PMC_TPCTRLSTAT_REG(base)                 ((base)->TPCTRLSTAT)
#define PMC_TPTM_REG(base)                       ((base)->TPTM)
#define PMC_RC20KTRM_REG(base)                   ((base)->RC20KTRM)
#define PMC_LVCTLSTAT1_REG(base)                 ((base)->LVCTLSTAT1)
#define PMC_LVCTLSTAT2_REG(base)                 ((base)->LVCTLSTAT2)
#define PMC_VREFHCFG_REG(base)                   ((base)->VREFHCFG)
#define PMC_VREFHLVW_REG(base)                   ((base)->VREFHLVW)
#define PMC_STAT_REG(base)                       ((base)->STAT)

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

/* CTRL Bit Fields */
#define PMC_CTRL_RC20KENSTP_MASK                 0x2u
#define PMC_CTRL_RC20KENSTP_SHIFT                1
#define PMC_CTRL_VREFDN_MASK                     0x4u
#define PMC_CTRL_VREFDN_SHIFT                    2
#define PMC_CTRL_GWREN_MASK                      0x80u
#define PMC_CTRL_GWREN_SHIFT                     7
/* RST Bit Fields */
#define PMC_RST_LVRF_MASK                        0x20u
#define PMC_RST_LVRF_SHIFT                       5
#define PMC_RST_PORF_MASK                        0x40u
#define PMC_RST_PORF_SHIFT                       6
/* TPCTRLSTAT Bit Fields */
#define PMC_TPCTRLSTAT_HTIF_MASK                 0x1u
#define PMC_TPCTRLSTAT_HTIF_SHIFT                0
#define PMC_TPCTRLSTAT_HTIE_MASK                 0x2u
#define PMC_TPCTRLSTAT_HTIE_SHIFT                1
#define PMC_TPCTRLSTAT_HTDS_MASK                 0x4u
#define PMC_TPCTRLSTAT_HTDS_SHIFT                2
#define PMC_TPCTRLSTAT_TEMPEN_MASK               0x8u
#define PMC_TPCTRLSTAT_TEMPEN_SHIFT              3
#define PMC_TPCTRLSTAT_SWON_MASK                 0x10u
#define PMC_TPCTRLSTAT_SWON_SHIFT                4
/* TPTM Bit Fields */
#define PMC_TPTM_TOT_MASK                        0xFu
#define PMC_TPTM_TOT_SHIFT                       0
#define PMC_TPTM_TOT(x)                          (((uint8_t)(((uint8_t)(x))<<PMC_TPTM_TOT_SHIFT))&PMC_TPTM_TOT_MASK)
#define PMC_TPTM_TRMTPEN_MASK                    0x80u
#define PMC_TPTM_TRMTPEN_SHIFT                   7
/* RC20KTRM Bit Fields */
#define PMC_RC20KTRM_OSCOT_MASK                  0x3Fu
#define PMC_RC20KTRM_OSCOT_SHIFT                 0
#define PMC_RC20KTRM_OSCOT(x)                    (((uint8_t)(((uint8_t)(x))<<PMC_RC20KTRM_OSCOT_SHIFT))&PMC_RC20KTRM_OSCOT_MASK)
/* LVCTLSTAT1 Bit Fields */
#define PMC_LVCTLSTAT1_SLVWSEL_MASK              0x2u
#define PMC_LVCTLSTAT1_SLVWSEL_SHIFT             1
#define PMC_LVCTLSTAT1_SLVWIE_MASK               0x4u
#define PMC_LVCTLSTAT1_SLVWIE_SHIFT              2
#define PMC_LVCTLSTAT1_SLVWACK_MASK              0x8u
#define PMC_LVCTLSTAT1_SLVWACK_SHIFT             3
#define PMC_LVCTLSTAT1_SLVWF_MASK                0x10u
#define PMC_LVCTLSTAT1_SLVWF_SHIFT               4
/* LVCTLSTAT2 Bit Fields */
#define PMC_LVCTLSTAT2_RLVWIE_MASK               0x4u
#define PMC_LVCTLSTAT2_RLVWIE_SHIFT              2
#define PMC_LVCTLSTAT2_RLVWACK_MASK              0x8u
#define PMC_LVCTLSTAT2_RLVWACK_SHIFT             3
#define PMC_LVCTLSTAT2_RLVWF_MASK                0x10u
#define PMC_LVCTLSTAT2_RLVWF_SHIFT               4
/* VREFHCFG Bit Fields */
#define PMC_VREFHCFG_T5V_MASK                    0x3Fu
#define PMC_VREFHCFG_T5V_SHIFT                   0
#define PMC_VREFHCFG_T5V(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_VREFHCFG_T5V_SHIFT))&PMC_VREFHCFG_T5V_MASK)
/* VREFHLVW Bit Fields */
#define PMC_VREFHLVW_LVWCFG_MASK                 0x3u
#define PMC_VREFHLVW_LVWCFG_SHIFT                0
#define PMC_VREFHLVW_LVWCFG(x)                   (((uint8_t)(((uint8_t)(x))<<PMC_VREFHLVW_LVWCFG_SHIFT))&PMC_VREFHLVW_LVWCFG_MASK)
/* STAT Bit Fields */
#define PMC_STAT_VREFRDY_MASK                    0x1u
#define PMC_STAT_VREFRDY_SHIFT                   0
#define PMC_STAT_HBGRDY_MASK                     0x4u
#define PMC_STAT_HBGRDY_SHIFT                    2

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
#define PMC_CTRL                                 PMC_CTRL_REG(PMC)
#define PMC_RST                                  PMC_RST_REG(PMC)
#define PMC_TPCTRLSTAT                           PMC_TPCTRLSTAT_REG(PMC)
#define PMC_TPTM                                 PMC_TPTM_REG(PMC)
#define PMC_RC20KTRM                             PMC_RC20KTRM_REG(PMC)
#define PMC_LVCTLSTAT1                           PMC_LVCTLSTAT1_REG(PMC)
#define PMC_LVCTLSTAT2                           PMC_LVCTLSTAT2_REG(PMC)
#define PMC_VREFHCFG                             PMC_VREFHCFG_REG(PMC)
#define PMC_VREFHLVW                             PMC_VREFHLVW_REG(PMC)
#define PMC_STAT                                 PMC_STAT_REG(PMC)

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
  __IO uint32_t IOFLT0;                            /**< Port Filter Control Register 0, offset: 0x0 */
  __IO uint32_t PUE0;                              /**< Port Pullup Enable Register 0, offset: 0x4 */
} PORT_Type, *PORT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PORT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Accessor_Macros PORT - Register accessor macros
 * @{
 */


/* PORT - Register accessors */
#define PORT_IOFLT0_REG(base)                    ((base)->IOFLT0)
#define PORT_PUE0_REG(base)                      ((base)->PUE0)

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

/* IOFLT0 Bit Fields */
#define PORT_IOFLT0_FLTRST_MASK                  0x3u
#define PORT_IOFLT0_FLTRST_SHIFT                 0
#define PORT_IOFLT0_FLTRST(x)                    (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT0_FLTRST_SHIFT))&PORT_IOFLT0_FLTRST_MASK)
#define PORT_IOFLT0_FLTDIV1_MASK                 0x3000000u
#define PORT_IOFLT0_FLTDIV1_SHIFT                24
#define PORT_IOFLT0_FLTDIV1(x)                   (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT0_FLTDIV1_SHIFT))&PORT_IOFLT0_FLTDIV1_MASK)
#define PORT_IOFLT0_FLTDIV2_MASK                 0x1C000000u
#define PORT_IOFLT0_FLTDIV2_SHIFT                26
#define PORT_IOFLT0_FLTDIV2(x)                   (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT0_FLTDIV2_SHIFT))&PORT_IOFLT0_FLTDIV2_MASK)
#define PORT_IOFLT0_FLTDIV3_MASK                 0xE0000000u
#define PORT_IOFLT0_FLTDIV3_SHIFT                29
#define PORT_IOFLT0_FLTDIV3(x)                   (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT0_FLTDIV3_SHIFT))&PORT_IOFLT0_FLTDIV3_MASK)
/* PUE0 Bit Fields */
#define PORT_PUE0_PTAPE0_MASK                    0x1u
#define PORT_PUE0_PTAPE0_SHIFT                   0
#define PORT_PUE0_PTAPE1_MASK                    0x2u
#define PORT_PUE0_PTAPE1_SHIFT                   1
#define PORT_PUE0_PTAPE2_MASK                    0x4u
#define PORT_PUE0_PTAPE2_SHIFT                   2
#define PORT_PUE0_PTAPE3_MASK                    0x8u
#define PORT_PUE0_PTAPE3_SHIFT                   3
#define PORT_PUE0_PTAPE4_MASK                    0x10u
#define PORT_PUE0_PTAPE4_SHIFT                   4
#define PORT_PUE0_PTAPE5_MASK                    0x20u
#define PORT_PUE0_PTAPE5_SHIFT                   5
#define PORT_PUE0_PTAPE6_MASK                    0x40u
#define PORT_PUE0_PTAPE6_SHIFT                   6
#define PORT_PUE0_PTAPE7_MASK                    0x80u
#define PORT_PUE0_PTAPE7_SHIFT                   7
#define PORT_PUE0_PTBPE0_MASK                    0x100u
#define PORT_PUE0_PTBPE0_SHIFT                   8
#define PORT_PUE0_PTBPE1_MASK                    0x200u
#define PORT_PUE0_PTBPE1_SHIFT                   9
#define PORT_PUE0_PTBPE2_MASK                    0x400u
#define PORT_PUE0_PTBPE2_SHIFT                   10
#define PORT_PUE0_PTBPE3_MASK                    0x800u
#define PORT_PUE0_PTBPE3_SHIFT                   11
#define PORT_PUE0_PTBPE4_MASK                    0x1000u
#define PORT_PUE0_PTBPE4_SHIFT                   12

/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/* PORT - Peripheral instance base addresses */
/** Peripheral PORT base address */
#define PORT_BASE                                (0x40049000u)
/** Peripheral PORT base pointer */
#define PORT                                     ((PORT_Type *)PORT_BASE)
#define PORT_BASE_PTR                            (PORT)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORT_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORT }

/* ----------------------------------------------------------------------------
   -- PORT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Accessor_Macros PORT - Register accessor macros
 * @{
 */


/* PORT - Register instance definitions */
/* PORT */
#define PORT_IOFLT0                              PORT_IOFLT0_REG(PORT)
#define PORT_PUE0                                PORT_PUE0_REG(PORT)

/*!
 * @}
 */ /* end of group PORT_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PORT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */

/** RTC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC;                                /**< RTC Status and Control Register, offset: 0x0 */
  __IO uint32_t MOD;                               /**< RTC Modulo Register, offset: 0x4 */
  __I  uint32_t CNT;                               /**< RTC Counter Register, offset: 0x8 */
} RTC_Type, *RTC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RTC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Accessor_Macros RTC - Register accessor macros
 * @{
 */


/* RTC - Register accessors */
#define RTC_SC_REG(base)                         ((base)->SC)
#define RTC_MOD_REG(base)                        ((base)->MOD)
#define RTC_CNT_REG(base)                        ((base)->CNT)

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

/* SC Bit Fields */
#define RTC_SC_RTCO_MASK                         0x10u
#define RTC_SC_RTCO_SHIFT                        4
#define RTC_SC_RTIE_MASK                         0x40u
#define RTC_SC_RTIE_SHIFT                        6
#define RTC_SC_RTIF_MASK                         0x80u
#define RTC_SC_RTIF_SHIFT                        7
#define RTC_SC_RTCPS_MASK                        0x700u
#define RTC_SC_RTCPS_SHIFT                       8
#define RTC_SC_RTCPS(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_SC_RTCPS_SHIFT))&RTC_SC_RTCPS_MASK)
#define RTC_SC_RTCLKS_MASK                       0xC000u
#define RTC_SC_RTCLKS_SHIFT                      14
#define RTC_SC_RTCLKS(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_SC_RTCLKS_SHIFT))&RTC_SC_RTCLKS_MASK)
/* MOD Bit Fields */
#define RTC_MOD_MOD_MASK                         0xFFFFu
#define RTC_MOD_MOD_SHIFT                        0
#define RTC_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_MOD_MOD_SHIFT))&RTC_MOD_MOD_MASK)
/* CNT Bit Fields */
#define RTC_CNT_CNT_MASK                         0xFFFFu
#define RTC_CNT_CNT_SHIFT                        0
#define RTC_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CNT_CNT_SHIFT))&RTC_CNT_CNT_MASK)

/*!
 * @}
 */ /* end of group RTC_Register_Masks */


/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define RTC_BASE                                 (0x4003D000u)
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
#define RTC_SC                                   RTC_SC_REG(RTC)
#define RTC_MOD                                  RTC_MOD_REG(RTC)
#define RTC_CNT                                  RTC_CNT_REG(RTC)

/*!
 * @}
 */ /* end of group RTC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group RTC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */

/** SIM - Register Layout Typedef */
typedef struct {
  __I  uint32_t SRSID;                             /**< System Reset Status and ID Register, offset: 0x0 */
  __IO uint32_t SOPT0;                             /**< System Options Register 0, offset: 0x4 */
  __IO uint32_t TBARCFG0;                          /**< Trigger Crossbar Configuration Register 0, offset: 0x8 */
  __IO uint32_t TBARCFG1;                          /**< Trigger Crossbar Configuration Register 1, offset: 0xC */
  __IO uint32_t SBARCFG;                           /**< Signal Crossbar Configuration Register, offset: 0x10 */
  __IO uint32_t XBARCFG;                           /**< FSK Configuration Register, offset: 0x14 */
  __IO uint32_t SCGC;                              /**< System Clock Gating Control Register, offset: 0x18 */
  __IO uint32_t RST;                               /**< Reset control Register, offset: 0x1C */
  __IO uint32_t CLKDIV;                            /**< Clock Divider Register, offset: 0x20 */
  __IO uint32_t FLG;                               /**< CNC external clamp and LDO external shutdown Flags Register, offset: 0x24 */
  __IO uint32_t AOICFG;                            /**< AOI function Configuration Register, offset: 0x28 */
  __IO uint32_t CR;                                /**< ACMP channel 2 Configuration and SIM_SCGC[ADC] write enable Register, offset: 0x2C */
  __I  uint32_t UUIDL;                             /**< Universally Unique Identifier Low Register, offset: 0x30 */
  __I  uint32_t UUIDML;                            /**< Universally Unique Identifier Middle Low Register, offset: 0x34 */
  __I  uint32_t UUIDMH;                            /**< Universally Unique Identifier Middle High Register, offset: 0x38 */
  __I  uint32_t IFR0;                              /**< Peripherals IFR bits Register 0, offset: 0x3C */
  __I  uint32_t IFR1;                              /**< Peripherals IFR bits Register 1, offset: 0x40 */
  __I  uint32_t IFR2;                              /**< Peripherals IFR bits Register 2, offset: 0x44 */
  __I  uint32_t IFR3;                              /**< Peripherals IFR bits Register 3, offset: 0x48 */
} SIM_Type, *SIM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros
 * @{
 */


/* SIM - Register accessors */
#define SIM_SRSID_REG(base)                      ((base)->SRSID)
#define SIM_SOPT0_REG(base)                      ((base)->SOPT0)
#define SIM_TBARCFG0_REG(base)                   ((base)->TBARCFG0)
#define SIM_TBARCFG1_REG(base)                   ((base)->TBARCFG1)
#define SIM_SBARCFG_REG(base)                    ((base)->SBARCFG)
#define SIM_XBARCFG_REG(base)                    ((base)->XBARCFG)
#define SIM_SCGC_REG(base)                       ((base)->SCGC)
#define SIM_RST_REG(base)                        ((base)->RST)
#define SIM_CLKDIV_REG(base)                     ((base)->CLKDIV)
#define SIM_FLG_REG(base)                        ((base)->FLG)
#define SIM_AOICFG_REG(base)                     ((base)->AOICFG)
#define SIM_CR_REG(base)                         ((base)->CR)
#define SIM_UUIDL_REG(base)                      ((base)->UUIDL)
#define SIM_UUIDML_REG(base)                     ((base)->UUIDML)
#define SIM_UUIDMH_REG(base)                     ((base)->UUIDMH)
#define SIM_IFR0_REG(base)                       ((base)->IFR0)
#define SIM_IFR1_REG(base)                       ((base)->IFR1)
#define SIM_IFR2_REG(base)                       ((base)->IFR2)
#define SIM_IFR3_REG(base)                       ((base)->IFR3)

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

/* SRSID Bit Fields */
#define SIM_SRSID_LVD_MASK                       0x2u
#define SIM_SRSID_LVD_SHIFT                      1
#define SIM_SRSID_LOC_MASK                       0x4u
#define SIM_SRSID_LOC_SHIFT                      2
#define SIM_SRSID_WDOG_MASK                      0x20u
#define SIM_SRSID_WDOG_SHIFT                     5
#define SIM_SRSID_PIN_MASK                       0x40u
#define SIM_SRSID_PIN_SHIFT                      6
#define SIM_SRSID_POR_MASK                       0x80u
#define SIM_SRSID_POR_SHIFT                      7
#define SIM_SRSID_LOCKUP_MASK                    0x200u
#define SIM_SRSID_LOCKUP_SHIFT                   9
#define SIM_SRSID_SW_MASK                        0x400u
#define SIM_SRSID_SW_SHIFT                       10
#define SIM_SRSID_MDMAP_MASK                     0x800u
#define SIM_SRSID_MDMAP_SHIFT                    11
#define SIM_SRSID_SACKERR_MASK                   0x2000u
#define SIM_SRSID_SACKERR_SHIFT                  13
#define SIM_SRSID_SUBFAMID_MASK                  0xF000000u
#define SIM_SRSID_SUBFAMID_SHIFT                 24
#define SIM_SRSID_SUBFAMID(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_SUBFAMID_SHIFT))&SIM_SRSID_SUBFAMID_MASK)
#define SIM_SRSID_FAMID_MASK                     0xF0000000u
#define SIM_SRSID_FAMID_SHIFT                    28
#define SIM_SRSID_FAMID(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_FAMID_SHIFT))&SIM_SRSID_FAMID_MASK)
/* SOPT0 Bit Fields */
#define SIM_SOPT0_NMIE_MASK                      0x2u
#define SIM_SOPT0_NMIE_SHIFT                     1
#define SIM_SOPT0_RSTPE_MASK                     0x4u
#define SIM_SOPT0_RSTPE_SHIFT                    2
#define SIM_SOPT0_SWDE_MASK                      0x8u
#define SIM_SOPT0_SWDE_SHIFT                     3
#define SIM_SOPT0_FTM0CHEN_MASK                  0x300u
#define SIM_SOPT0_FTM0CHEN_SHIFT                 8
#define SIM_SOPT0_FTM0CHEN(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT0_FTM0CHEN_SHIFT))&SIM_SOPT0_FTM0CHEN_MASK)
#define SIM_SOPT0_FTM1CHEN_MASK                  0xC00u
#define SIM_SOPT0_FTM1CHEN_SHIFT                 10
#define SIM_SOPT0_FTM1CHEN(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT0_FTM1CHEN_SHIFT))&SIM_SOPT0_FTM1CHEN_MASK)
#define SIM_SOPT0_UARTRXEN_MASK                  0x1000u
#define SIM_SOPT0_UARTRXEN_SHIFT                 12
#define SIM_SOPT0_UARTTXEN_MASK                  0x2000u
#define SIM_SOPT0_UARTTXEN_SHIFT                 13
#define SIM_SOPT0_SBARIN0EN_MASK                 0x4000u
#define SIM_SOPT0_SBARIN0EN_SHIFT                14
#define SIM_SOPT0_SBARIN1EN_MASK                 0x8000u
#define SIM_SOPT0_SBARIN1EN_SHIFT                15
#define SIM_SOPT0_BUSREF_MASK                    0x70000u
#define SIM_SOPT0_BUSREF_SHIFT                   16
#define SIM_SOPT0_BUSREF(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT0_BUSREF_SHIFT))&SIM_SOPT0_BUSREF_MASK)
#define SIM_SOPT0_CLKOE_MASK                     0x80000u
#define SIM_SOPT0_CLKOE_SHIFT                    19
#define SIM_SOPT0_DLYACT_MASK                    0x800000u
#define SIM_SOPT0_DLYACT_SHIFT                   23
#define SIM_SOPT0_DELAY_MASK                     0xFF000000u
#define SIM_SOPT0_DELAY_SHIFT                    24
#define SIM_SOPT0_DELAY(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SOPT0_DELAY_SHIFT))&SIM_SOPT0_DELAY_MASK)
/* TBARCFG0 Bit Fields */
#define SIM_TBARCFG0_ADCTRIG_MASK                0xFu
#define SIM_TBARCFG0_ADCTRIG_SHIFT               0
#define SIM_TBARCFG0_ADCTRIG(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_TBARCFG0_ADCTRIG_SHIFT))&SIM_TBARCFG0_ADCTRIG_MASK)
#define SIM_TBARCFG0_ADCRESTART_MASK             0xF0u
#define SIM_TBARCFG0_ADCRESTART_SHIFT            4
#define SIM_TBARCFG0_ADCRESTART(x)               (((uint32_t)(((uint32_t)(x))<<SIM_TBARCFG0_ADCRESTART_SHIFT))&SIM_TBARCFG0_ADCRESTART_MASK)
#define SIM_TBARCFG0_ADCABORT_MASK               0xF00u
#define SIM_TBARCFG0_ADCABORT_SHIFT              8
#define SIM_TBARCFG0_ADCABORT(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_TBARCFG0_ADCABORT_SHIFT))&SIM_TBARCFG0_ADCABORT_MASK)
#define SIM_TBARCFG0_ADCLOADOK_MASK              0xF000u
#define SIM_TBARCFG0_ADCLOADOK_SHIFT             12
#define SIM_TBARCFG0_ADCLOADOK(x)                (((uint32_t)(((uint32_t)(x))<<SIM_TBARCFG0_ADCLOADOK_SHIFT))&SIM_TBARCFG0_ADCLOADOK_MASK)
#define SIM_TBARCFG0_CNCEXCLAMP_MASK             0xF0000u
#define SIM_TBARCFG0_CNCEXCLAMP_SHIFT            16
#define SIM_TBARCFG0_CNCEXCLAMP(x)               (((uint32_t)(((uint32_t)(x))<<SIM_TBARCFG0_CNCEXCLAMP_SHIFT))&SIM_TBARCFG0_CNCEXCLAMP_MASK)
#define SIM_TBARCFG0_LDOSHUTDOWN0_MASK           0xF00000u
#define SIM_TBARCFG0_LDOSHUTDOWN0_SHIFT          20
#define SIM_TBARCFG0_LDOSHUTDOWN0(x)             (((uint32_t)(((uint32_t)(x))<<SIM_TBARCFG0_LDOSHUTDOWN0_SHIFT))&SIM_TBARCFG0_LDOSHUTDOWN0_MASK)
#define SIM_TBARCFG0_LDOSHUTDOWN1_MASK           0xF000000u
#define SIM_TBARCFG0_LDOSHUTDOWN1_SHIFT          24
#define SIM_TBARCFG0_LDOSHUTDOWN1(x)             (((uint32_t)(((uint32_t)(x))<<SIM_TBARCFG0_LDOSHUTDOWN1_SHIFT))&SIM_TBARCFG0_LDOSHUTDOWN1_MASK)
#define SIM_TBARCFG0_LDOSHUTDOWN2_MASK           0xF0000000u
#define SIM_TBARCFG0_LDOSHUTDOWN2_SHIFT          28
#define SIM_TBARCFG0_LDOSHUTDOWN2(x)             (((uint32_t)(((uint32_t)(x))<<SIM_TBARCFG0_LDOSHUTDOWN2_SHIFT))&SIM_TBARCFG0_LDOSHUTDOWN2_MASK)
/* TBARCFG1 Bit Fields */
#define SIM_TBARCFG1_TBAROUT_MASK                0xFu
#define SIM_TBARCFG1_TBAROUT_SHIFT               0
#define SIM_TBARCFG1_TBAROUT(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_TBARCFG1_TBAROUT_SHIFT))&SIM_TBARCFG1_TBAROUT_MASK)
/* SBARCFG Bit Fields */
#define SIM_SBARCFG_FSKDTIN_MASK                 0xFu
#define SIM_SBARCFG_FSKDTIN_SHIFT                0
#define SIM_SBARCFG_FSKDTIN(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SBARCFG_FSKDTIN_SHIFT))&SIM_SBARCFG_FSKDTIN_MASK)
#define SIM_SBARCFG_IRQ_MASK                     0xF0u
#define SIM_SBARCFG_IRQ_SHIFT                    4
#define SIM_SBARCFG_IRQ(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SBARCFG_IRQ_SHIFT))&SIM_SBARCFG_IRQ_MASK)
#define SIM_SBARCFG_FTM1CH0IN_MASK               0xF00u
#define SIM_SBARCFG_FTM1CH0IN_SHIFT              8
#define SIM_SBARCFG_FTM1CH0IN(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_SBARCFG_FTM1CH0IN_SHIFT))&SIM_SBARCFG_FTM1CH0IN_MASK)
#define SIM_SBARCFG_FTM1CH1IN_MASK               0xF000u
#define SIM_SBARCFG_FTM1CH1IN_SHIFT              12
#define SIM_SBARCFG_FTM1CH1IN(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_SBARCFG_FTM1CH1IN_SHIFT))&SIM_SBARCFG_FTM1CH1IN_MASK)
#define SIM_SBARCFG_UARTRX_MASK                  0xF0000u
#define SIM_SBARCFG_UARTRX_SHIFT                 16
#define SIM_SBARCFG_UARTRX(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SBARCFG_UARTRX_SHIFT))&SIM_SBARCFG_UARTRX_MASK)
#define SIM_SBARCFG_SBAROUT0_MASK                0xF00000u
#define SIM_SBARCFG_SBAROUT0_SHIFT               20
#define SIM_SBARCFG_SBAROUT0(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SBARCFG_SBAROUT0_SHIFT))&SIM_SBARCFG_SBAROUT0_MASK)
#define SIM_SBARCFG_SBAROUT1_MASK                0xF000000u
#define SIM_SBARCFG_SBAROUT1_SHIFT               24
#define SIM_SBARCFG_SBAROUT1(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SBARCFG_SBAROUT1_SHIFT))&SIM_SBARCFG_SBAROUT1_MASK)
#define SIM_SBARCFG_SBAROUT2_MASK                0xF0000000u
#define SIM_SBARCFG_SBAROUT2_SHIFT               28
#define SIM_SBARCFG_SBAROUT2(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SBARCFG_SBAROUT2_SHIFT))&SIM_SBARCFG_SBAROUT2_MASK)
/* XBARCFG Bit Fields */
#define SIM_XBARCFG_SBARDIV_MASK                 0xFu
#define SIM_XBARCFG_SBARDIV_SHIFT                0
#define SIM_XBARCFG_SBARDIV(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_XBARCFG_SBARDIV_SHIFT))&SIM_XBARCFG_SBARDIV_MASK)
#define SIM_XBARCFG_TBARDIV_MASK                 0x700u
#define SIM_XBARCFG_TBARDIV_SHIFT                8
#define SIM_XBARCFG_TBARDIV(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_XBARCFG_TBARDIV_SHIFT))&SIM_XBARCFG_TBARDIV_MASK)
#define SIM_XBARCFG_FILT0_MASK                   0xF000u
#define SIM_XBARCFG_FILT0_SHIFT                  12
#define SIM_XBARCFG_FILT0(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_XBARCFG_FILT0_SHIFT))&SIM_XBARCFG_FILT0_MASK)
#define SIM_XBARCFG_FILT1_MASK                   0xFF0000u
#define SIM_XBARCFG_FILT1_SHIFT                  16
#define SIM_XBARCFG_FILT1(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_XBARCFG_FILT1_SHIFT))&SIM_XBARCFG_FILT1_MASK)
#define SIM_XBARCFG_FSKCLKEN_MASK                0x80000000u
#define SIM_XBARCFG_FSKCLKEN_SHIFT               31
/* SCGC Bit Fields */
#define SIM_SCGC_RTC_MASK                        0x1u
#define SIM_SCGC_RTC_SHIFT                       0
#define SIM_SCGC_PIT_MASK                        0x2u
#define SIM_SCGC_PIT_SHIFT                       1
#define SIM_SCGC_FSKDT_MASK                      0x10u
#define SIM_SCGC_FSKDT_SHIFT                     4
#define SIM_SCGC_FTM0_MASK                       0x20u
#define SIM_SCGC_FTM0_SHIFT                      5
#define SIM_SCGC_FTM1_MASK                       0x40u
#define SIM_SCGC_FTM1_SHIFT                      6
#define SIM_SCGC_CNC_MASK                        0x100u
#define SIM_SCGC_CNC_SHIFT                       8
#define SIM_SCGC_PGA_MASK                        0x200u
#define SIM_SCGC_PGA_SHIFT                       9
#define SIM_SCGC_LDO_MASK                        0x400u
#define SIM_SCGC_LDO_SHIFT                       10
#define SIM_SCGC_FLASH_MASK                      0x1000u
#define SIM_SCGC_FLASH_SHIFT                     12
#define SIM_SCGC_SWD_MASK                        0x2000u
#define SIM_SCGC_SWD_SHIFT                       13
#define SIM_SCGC_I2C0_MASK                       0x10000u
#define SIM_SCGC_I2C0_SHIFT                      16
#define SIM_SCGC_UART0_MASK                      0x100000u
#define SIM_SCGC_UART0_SHIFT                     20
#define SIM_SCGC_IRQ_MASK                        0x8000000u
#define SIM_SCGC_IRQ_SHIFT                       27
#define SIM_SCGC_ADC_MASK                        0x20000000u
#define SIM_SCGC_ADC_SHIFT                       29
#define SIM_SCGC_ACMP0_MASK                      0x40000000u
#define SIM_SCGC_ACMP0_SHIFT                     30
/* RST Bit Fields */
#define SIM_RST_RTC_MASK                         0x1u
#define SIM_RST_RTC_SHIFT                        0
#define SIM_RST_PIT_MASK                         0x2u
#define SIM_RST_PIT_SHIFT                        1
#define SIM_RST_FSKDT_MASK                       0x10u
#define SIM_RST_FSKDT_SHIFT                      4
#define SIM_RST_FTM0_MASK                        0x20u
#define SIM_RST_FTM0_SHIFT                       5
#define SIM_RST_FTM1_MASK                        0x40u
#define SIM_RST_FTM1_SHIFT                       6
#define SIM_RST_CNC_MASK                         0x100u
#define SIM_RST_CNC_SHIFT                        8
#define SIM_RST_LDO_MASK                         0x400u
#define SIM_RST_LDO_SHIFT                        10
#define SIM_RST_I2C0_MASK                        0x10000u
#define SIM_RST_I2C0_SHIFT                       16
#define SIM_RST_UART0_MASK                       0x100000u
#define SIM_RST_UART0_SHIFT                      20
#define SIM_RST_IRQ_MASK                         0x8000000u
#define SIM_RST_IRQ_SHIFT                        27
#define SIM_RST_ACMP0_MASK                       0x40000000u
#define SIM_RST_ACMP0_SHIFT                      30
/* CLKDIV Bit Fields */
#define SIM_CLKDIV_OUTDIV3_MASK                  0x100000u
#define SIM_CLKDIV_OUTDIV3_SHIFT                 20
#define SIM_CLKDIV_OUTDIV2_MASK                  0x1000000u
#define SIM_CLKDIV_OUTDIV2_SHIFT                 24
#define SIM_CLKDIV_OUTDIV1_MASK                  0x30000000u
#define SIM_CLKDIV_OUTDIV1_SHIFT                 28
#define SIM_CLKDIV_OUTDIV1(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV_OUTDIV1_SHIFT))&SIM_CLKDIV_OUTDIV1_MASK)
/* FLG Bit Fields */
#define SIM_FLG_ECLAMPF_MASK                     0x1u
#define SIM_FLG_ECLAMPF_SHIFT                    0
#define SIM_FLG_ESHUTF_MASK                      0x2u
#define SIM_FLG_ESHUTF_SHIFT                     1
/* AOICFG Bit Fields */
#define SIM_AOICFG_PT3_DC_MASK                   0x3u
#define SIM_AOICFG_PT3_DC_SHIFT                  0
#define SIM_AOICFG_PT3_DC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT3_DC_SHIFT))&SIM_AOICFG_PT3_DC_MASK)
#define SIM_AOICFG_PT3_CC_MASK                   0xCu
#define SIM_AOICFG_PT3_CC_SHIFT                  2
#define SIM_AOICFG_PT3_CC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT3_CC_SHIFT))&SIM_AOICFG_PT3_CC_MASK)
#define SIM_AOICFG_PT3_BC_MASK                   0x30u
#define SIM_AOICFG_PT3_BC_SHIFT                  4
#define SIM_AOICFG_PT3_BC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT3_BC_SHIFT))&SIM_AOICFG_PT3_BC_MASK)
#define SIM_AOICFG_PT3_AC_MASK                   0xC0u
#define SIM_AOICFG_PT3_AC_SHIFT                  6
#define SIM_AOICFG_PT3_AC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT3_AC_SHIFT))&SIM_AOICFG_PT3_AC_MASK)
#define SIM_AOICFG_PT2_DC_MASK                   0x300u
#define SIM_AOICFG_PT2_DC_SHIFT                  8
#define SIM_AOICFG_PT2_DC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT2_DC_SHIFT))&SIM_AOICFG_PT2_DC_MASK)
#define SIM_AOICFG_PT2_CC_MASK                   0xC00u
#define SIM_AOICFG_PT2_CC_SHIFT                  10
#define SIM_AOICFG_PT2_CC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT2_CC_SHIFT))&SIM_AOICFG_PT2_CC_MASK)
#define SIM_AOICFG_PT2_BC_MASK                   0x3000u
#define SIM_AOICFG_PT2_BC_SHIFT                  12
#define SIM_AOICFG_PT2_BC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT2_BC_SHIFT))&SIM_AOICFG_PT2_BC_MASK)
#define SIM_AOICFG_PT2_AC_MASK                   0xC000u
#define SIM_AOICFG_PT2_AC_SHIFT                  14
#define SIM_AOICFG_PT2_AC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT2_AC_SHIFT))&SIM_AOICFG_PT2_AC_MASK)
#define SIM_AOICFG_PT1_DC_MASK                   0x30000u
#define SIM_AOICFG_PT1_DC_SHIFT                  16
#define SIM_AOICFG_PT1_DC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT1_DC_SHIFT))&SIM_AOICFG_PT1_DC_MASK)
#define SIM_AOICFG_PT1_CC_MASK                   0xC0000u
#define SIM_AOICFG_PT1_CC_SHIFT                  18
#define SIM_AOICFG_PT1_CC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT1_CC_SHIFT))&SIM_AOICFG_PT1_CC_MASK)
#define SIM_AOICFG_PT1_BC_MASK                   0x300000u
#define SIM_AOICFG_PT1_BC_SHIFT                  20
#define SIM_AOICFG_PT1_BC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT1_BC_SHIFT))&SIM_AOICFG_PT1_BC_MASK)
#define SIM_AOICFG_PT1_AC_MASK                   0xC00000u
#define SIM_AOICFG_PT1_AC_SHIFT                  22
#define SIM_AOICFG_PT1_AC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT1_AC_SHIFT))&SIM_AOICFG_PT1_AC_MASK)
#define SIM_AOICFG_PT0_DC_MASK                   0x3000000u
#define SIM_AOICFG_PT0_DC_SHIFT                  24
#define SIM_AOICFG_PT0_DC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT0_DC_SHIFT))&SIM_AOICFG_PT0_DC_MASK)
#define SIM_AOICFG_PT0_CC_MASK                   0xC000000u
#define SIM_AOICFG_PT0_CC_SHIFT                  26
#define SIM_AOICFG_PT0_CC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT0_CC_SHIFT))&SIM_AOICFG_PT0_CC_MASK)
#define SIM_AOICFG_PT0_BC_MASK                   0x30000000u
#define SIM_AOICFG_PT0_BC_SHIFT                  28
#define SIM_AOICFG_PT0_BC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT0_BC_SHIFT))&SIM_AOICFG_PT0_BC_MASK)
#define SIM_AOICFG_PT0_AC_MASK                   0xC0000000u
#define SIM_AOICFG_PT0_AC_SHIFT                  30
#define SIM_AOICFG_PT0_AC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_AOICFG_PT0_AC_SHIFT))&SIM_AOICFG_PT0_AC_MASK)
/* CR Bit Fields */
#define SIM_CR_ADCGCWEN_MASK                     0x100u
#define SIM_CR_ADCGCWEN_SHIFT                    8
#define SIM_CR_ACMP0CH2SEL_MASK                  0x3000000u
#define SIM_CR_ACMP0CH2SEL_SHIFT                 24
#define SIM_CR_ACMP0CH2SEL(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_CR_ACMP0CH2SEL_SHIFT))&SIM_CR_ACMP0CH2SEL_MASK)
/* UUIDL Bit Fields */
#define SIM_UUIDL_ID_MASK                        0xFFFFFFFFu
#define SIM_UUIDL_ID_SHIFT                       0
#define SIM_UUIDL_ID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UUIDL_ID_SHIFT))&SIM_UUIDL_ID_MASK)
/* UUIDML Bit Fields */
#define SIM_UUIDML_ID_MASK                       0xFFFFFFFFu
#define SIM_UUIDML_ID_SHIFT                      0
#define SIM_UUIDML_ID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UUIDML_ID_SHIFT))&SIM_UUIDML_ID_MASK)
/* UUIDMH Bit Fields */
#define SIM_UUIDMH_ID_MASK                       0xFFFFu
#define SIM_UUIDMH_ID_SHIFT                      0
#define SIM_UUIDMH_ID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UUIDMH_ID_SHIFT))&SIM_UUIDMH_ID_MASK)
/* IFR0 Bit Fields */
#define SIM_IFR0_IFR0_20_10_MASK                 0x1FFC00u
#define SIM_IFR0_IFR0_20_10_SHIFT                10
#define SIM_IFR0_IFR0_20_10(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_IFR0_IFR0_20_10_SHIFT))&SIM_IFR0_IFR0_20_10_MASK)
#define SIM_IFR0_IFR0_31_21_MASK                 0xFFE00000u
#define SIM_IFR0_IFR0_31_21_SHIFT                21
#define SIM_IFR0_IFR0_31_21(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_IFR0_IFR0_31_21_SHIFT))&SIM_IFR0_IFR0_31_21_MASK)
/* IFR1 Bit Fields */
#define SIM_IFR1_IFR1_5_0_MASK                   0x3Fu
#define SIM_IFR1_IFR1_5_0_SHIFT                  0
#define SIM_IFR1_IFR1_5_0(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_IFR1_IFR1_5_0_SHIFT))&SIM_IFR1_IFR1_5_0_MASK)
#define SIM_IFR1_IFR1_11_6_MASK                  0xFC0u
#define SIM_IFR1_IFR1_11_6_SHIFT                 6
#define SIM_IFR1_IFR1_11_6(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_IFR1_IFR1_11_6_SHIFT))&SIM_IFR1_IFR1_11_6_MASK)
#define SIM_IFR1_IFR1_17_12_MASK                 0x3F000u
#define SIM_IFR1_IFR1_17_12_SHIFT                12
#define SIM_IFR1_IFR1_17_12(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_IFR1_IFR1_17_12_SHIFT))&SIM_IFR1_IFR1_17_12_MASK)
/* IFR2 Bit Fields */
#define SIM_IFR2_IFR2_10_0_MASK                  0x7FFu
#define SIM_IFR2_IFR2_10_0_SHIFT                 0
#define SIM_IFR2_IFR2_10_0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_IFR2_IFR2_10_0_SHIFT))&SIM_IFR2_IFR2_10_0_MASK)
#define SIM_IFR2_IFR2_21_11_MASK                 0x3FF800u
#define SIM_IFR2_IFR2_21_11_SHIFT                11
#define SIM_IFR2_IFR2_21_11(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_IFR2_IFR2_21_11_SHIFT))&SIM_IFR2_IFR2_21_11_MASK)
/* IFR3 Bit Fields */
#define SIM_IFR3_IFR3_11_0_MASK                  0xFFFu
#define SIM_IFR3_IFR3_11_0_SHIFT                 0
#define SIM_IFR3_IFR3_11_0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_IFR3_IFR3_11_0_SHIFT))&SIM_IFR3_IFR3_11_0_MASK)
#define SIM_IFR3_IFR3_22_12_MASK                 0x7FF000u
#define SIM_IFR3_IFR3_22_12_SHIFT                12
#define SIM_IFR3_IFR3_22_12(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_IFR3_IFR3_22_12_SHIFT))&SIM_IFR3_IFR3_22_12_MASK)

/*!
 * @}
 */ /* end of group SIM_Register_Masks */


/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base address */
#define SIM_BASE                                 (0x40048000u)
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
#define SIM_SRSID                                SIM_SRSID_REG(SIM)
#define SIM_SOPT0                                SIM_SOPT0_REG(SIM)
#define SIM_TBARCFG0                             SIM_TBARCFG0_REG(SIM)
#define SIM_TBARCFG1                             SIM_TBARCFG1_REG(SIM)
#define SIM_SBARCFG                              SIM_SBARCFG_REG(SIM)
#define SIM_XBARCFG                              SIM_XBARCFG_REG(SIM)
#define SIM_SCGC                                 SIM_SCGC_REG(SIM)
#define SIM_RST                                  SIM_RST_REG(SIM)
#define SIM_CLKDIV                               SIM_CLKDIV_REG(SIM)
#define SIM_FLG                                  SIM_FLG_REG(SIM)
#define SIM_AOICFG                               SIM_AOICFG_REG(SIM)
#define SIM_CR                                   SIM_CR_REG(SIM)
#define SIM_UUIDL                                SIM_UUIDL_REG(SIM)
#define SIM_UUIDML                               SIM_UUIDML_REG(SIM)
#define SIM_UUIDMH                               SIM_UUIDMH_REG(SIM)
#define SIM_IFR0                                 SIM_IFR0_REG(SIM)
#define SIM_IFR1                                 SIM_IFR1_REG(SIM)
#define SIM_IFR2                                 SIM_IFR2_REG(SIM)
#define SIM_IFR3                                 SIM_IFR3_REG(SIM)

/*!
 * @}
 */ /* end of group SIM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group SIM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- UART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Peripheral_Access_Layer UART Peripheral Access Layer
 * @{
 */

/** UART - Register Layout Typedef */
typedef struct {
  __IO uint8_t BDH;                                /**< UART Baud Rate Register: High, offset: 0x0 */
  __IO uint8_t BDL;                                /**< UART Baud Rate Register: Low, offset: 0x1 */
  __IO uint8_t C1;                                 /**< UART Control Register 1, offset: 0x2 */
  __IO uint8_t C2;                                 /**< UART Control Register 2, offset: 0x3 */
  __I  uint8_t S1;                                 /**< UART Status Register 1, offset: 0x4 */
  __IO uint8_t S2;                                 /**< UART Status Register 2, offset: 0x5 */
  __IO uint8_t C3;                                 /**< UART Control Register 3, offset: 0x6 */
  __IO uint8_t D;                                  /**< UART Data Register, offset: 0x7 */
} UART_Type, *UART_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Accessor_Macros UART - Register accessor macros
 * @{
 */


/* UART - Register accessors */
#define UART_BDH_REG(base)                       ((base)->BDH)
#define UART_BDL_REG(base)                       ((base)->BDL)
#define UART_C1_REG(base)                        ((base)->C1)
#define UART_C2_REG(base)                        ((base)->C2)
#define UART_S1_REG(base)                        ((base)->S1)
#define UART_S2_REG(base)                        ((base)->S2)
#define UART_C3_REG(base)                        ((base)->C3)
#define UART_D_REG(base)                         ((base)->D)

/*!
 * @}
 */ /* end of group UART_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Masks UART Register Masks
 * @{
 */

/* BDH Bit Fields */
#define UART_BDH_SBR_MASK                        0x1Fu
#define UART_BDH_SBR_SHIFT                       0
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBR_SHIFT))&UART_BDH_SBR_MASK)
#define UART_BDH_SBNS_MASK                       0x20u
#define UART_BDH_SBNS_SHIFT                      5
#define UART_BDH_RXEDGIE_MASK                    0x40u
#define UART_BDH_RXEDGIE_SHIFT                   6
#define UART_BDH_LBKDIE_MASK                     0x80u
#define UART_BDH_LBKDIE_SHIFT                    7
/* BDL Bit Fields */
#define UART_BDL_SBR_MASK                        0xFFu
#define UART_BDL_SBR_SHIFT                       0
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDL_SBR_SHIFT))&UART_BDL_SBR_MASK)
/* C1 Bit Fields */
#define UART_C1_PT_MASK                          0x1u
#define UART_C1_PT_SHIFT                         0
#define UART_C1_PE_MASK                          0x2u
#define UART_C1_PE_SHIFT                         1
#define UART_C1_ILT_MASK                         0x4u
#define UART_C1_ILT_SHIFT                        2
#define UART_C1_WAKE_MASK                        0x8u
#define UART_C1_WAKE_SHIFT                       3
#define UART_C1_M_MASK                           0x10u
#define UART_C1_M_SHIFT                          4
#define UART_C1_RSRC_MASK                        0x20u
#define UART_C1_RSRC_SHIFT                       5
#define UART_C1_UARTSWAI_MASK                    0x40u
#define UART_C1_UARTSWAI_SHIFT                   6
#define UART_C1_LOOPS_MASK                       0x80u
#define UART_C1_LOOPS_SHIFT                      7
/* C2 Bit Fields */
#define UART_C2_SBK_MASK                         0x1u
#define UART_C2_SBK_SHIFT                        0
#define UART_C2_RWU_MASK                         0x2u
#define UART_C2_RWU_SHIFT                        1
#define UART_C2_RE_MASK                          0x4u
#define UART_C2_RE_SHIFT                         2
#define UART_C2_TE_MASK                          0x8u
#define UART_C2_TE_SHIFT                         3
#define UART_C2_ILIE_MASK                        0x10u
#define UART_C2_ILIE_SHIFT                       4
#define UART_C2_RIE_MASK                         0x20u
#define UART_C2_RIE_SHIFT                        5
#define UART_C2_TCIE_MASK                        0x40u
#define UART_C2_TCIE_SHIFT                       6
#define UART_C2_TIE_MASK                         0x80u
#define UART_C2_TIE_SHIFT                        7
/* S1 Bit Fields */
#define UART_S1_PF_MASK                          0x1u
#define UART_S1_PF_SHIFT                         0
#define UART_S1_FE_MASK                          0x2u
#define UART_S1_FE_SHIFT                         1
#define UART_S1_NF_MASK                          0x4u
#define UART_S1_NF_SHIFT                         2
#define UART_S1_OR_MASK                          0x8u
#define UART_S1_OR_SHIFT                         3
#define UART_S1_IDLE_MASK                        0x10u
#define UART_S1_IDLE_SHIFT                       4
#define UART_S1_RDRF_MASK                        0x20u
#define UART_S1_RDRF_SHIFT                       5
#define UART_S1_TC_MASK                          0x40u
#define UART_S1_TC_SHIFT                         6
#define UART_S1_TDRE_MASK                        0x80u
#define UART_S1_TDRE_SHIFT                       7
/* S2 Bit Fields */
#define UART_S2_RAF_MASK                         0x1u
#define UART_S2_RAF_SHIFT                        0
#define UART_S2_LBKDE_MASK                       0x2u
#define UART_S2_LBKDE_SHIFT                      1
#define UART_S2_BRK13_MASK                       0x4u
#define UART_S2_BRK13_SHIFT                      2
#define UART_S2_RWUID_MASK                       0x8u
#define UART_S2_RWUID_SHIFT                      3
#define UART_S2_RXINV_MASK                       0x10u
#define UART_S2_RXINV_SHIFT                      4
#define UART_S2_RXEDGIF_MASK                     0x40u
#define UART_S2_RXEDGIF_SHIFT                    6
#define UART_S2_LBKDIF_MASK                      0x80u
#define UART_S2_LBKDIF_SHIFT                     7
/* C3 Bit Fields */
#define UART_C3_PEIE_MASK                        0x1u
#define UART_C3_PEIE_SHIFT                       0
#define UART_C3_FEIE_MASK                        0x2u
#define UART_C3_FEIE_SHIFT                       1
#define UART_C3_NEIE_MASK                        0x4u
#define UART_C3_NEIE_SHIFT                       2
#define UART_C3_ORIE_MASK                        0x8u
#define UART_C3_ORIE_SHIFT                       3
#define UART_C3_TXINV_MASK                       0x10u
#define UART_C3_TXINV_SHIFT                      4
#define UART_C3_TXDIR_MASK                       0x20u
#define UART_C3_TXDIR_SHIFT                      5
#define UART_C3_T8_MASK                          0x40u
#define UART_C3_T8_SHIFT                         6
#define UART_C3_R8_MASK                          0x80u
#define UART_C3_R8_SHIFT                         7
/* D Bit Fields */
#define UART_D_R0T0_MASK                         0x1u
#define UART_D_R0T0_SHIFT                        0
#define UART_D_R1T1_MASK                         0x2u
#define UART_D_R1T1_SHIFT                        1
#define UART_D_R2T2_MASK                         0x4u
#define UART_D_R2T2_SHIFT                        2
#define UART_D_R3T3_MASK                         0x8u
#define UART_D_R3T3_SHIFT                        3
#define UART_D_R4T4_MASK                         0x10u
#define UART_D_R4T4_SHIFT                        4
#define UART_D_R5T5_MASK                         0x20u
#define UART_D_R5T5_SHIFT                        5
#define UART_D_R6T6_MASK                         0x40u
#define UART_D_R6T6_SHIFT                        6
#define UART_D_R7T7_MASK                         0x80u
#define UART_D_R7T7_SHIFT                        7

/*!
 * @}
 */ /* end of group UART_Register_Masks */


/* UART - Peripheral instance base addresses */
/** Peripheral UART0 base address */
#define UART0_BASE                               (0x4006A000u)
/** Peripheral UART0 base pointer */
#define UART0                                    ((UART_Type *)UART0_BASE)
#define UART0_BASE_PTR                           (UART0)
/** Array initializer of UART peripheral base addresses */
#define UART_BASE_ADDRS                          { UART0_BASE }
/** Array initializer of UART peripheral base pointers */
#define UART_BASE_PTRS                           { UART0 }

/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Accessor_Macros UART - Register accessor macros
 * @{
 */


/* UART - Register instance definitions */
/* UART0 */
#define UART0_BDH                                UART_BDH_REG(UART0)
#define UART0_BDL                                UART_BDL_REG(UART0)
#define UART0_C1                                 UART_C1_REG(UART0)
#define UART0_C2                                 UART_C2_REG(UART0)
#define UART0_S1                                 UART_S1_REG(UART0)
#define UART0_S2                                 UART_S2_REG(UART0)
#define UART0_C3                                 UART_C3_REG(UART0)
#define UART0_D                                  UART_D_REG(UART0)

/*!
 * @}
 */ /* end of group UART_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group UART_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- WDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Peripheral_Access_Layer WDOG Peripheral Access Layer
 * @{
 */

/** WDOG - Register Layout Typedef */
typedef struct {
  __IO uint8_t CS1;                                /**< Watchdog Control and Status Register 1, offset: 0x0 */
  __IO uint8_t CS2;                                /**< Watchdog Control and Status Register 2, offset: 0x1 */
  union {                                          /* offset: 0x2 */
    __IO uint16_t CNT;                               /**< Watchdog Counter Register., offset: 0x2 */
    struct {                                         /* offset: 0x2 */
      __I  uint8_t CNTH;                               /**< Watchdog Counter Register: High, offset: 0x2 */
      __I  uint8_t CNTL;                               /**< Watchdog Counter Register: Low, offset: 0x3 */
    } CNT8B;
  };
  union {                                          /* offset: 0x4 */
    __IO uint16_t TOVAL;                             /**< Watchdog Timeout Value Register., offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      __IO uint8_t TOVALH;                             /**< Watchdog Timeout Value Register: High, offset: 0x4 */
      __IO uint8_t TOVALL;                             /**< Watchdog Timeout Value Register: Low, offset: 0x5 */
    } TOVAL8B;
  };
  union {                                          /* offset: 0x6 */
    __IO uint16_t WIN;                               /**< Watchdog Window Register., offset: 0x6 */
    struct {                                         /* offset: 0x6 */
      __IO uint8_t WINH;                               /**< Watchdog Window Register: High, offset: 0x6 */
      __IO uint8_t WINL;                               /**< Watchdog Window Register: Low, offset: 0x7 */
    } WIN8B;
  };
} WDOG_Type, *WDOG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- WDOG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Accessor_Macros WDOG - Register accessor macros
 * @{
 */


/* WDOG - Register accessors */
#define WDOG_CS1_REG(base)                       ((base)->CS1)
#define WDOG_CS2_REG(base)                       ((base)->CS2)
#define WDOG_CNT_REG(base)                       ((base)->CNT)
#define WDOG_CNTH_REG(base)                      ((base)->CNT8B.CNTH)
#define WDOG_CNTL_REG(base)                      ((base)->CNT8B.CNTL)
#define WDOG_TOVAL_REG(base)                     ((base)->TOVAL)
#define WDOG_TOVALH_REG(base)                    ((base)->TOVAL8B.TOVALH)
#define WDOG_TOVALL_REG(base)                    ((base)->TOVAL8B.TOVALL)
#define WDOG_WIN_REG(base)                       ((base)->WIN)
#define WDOG_WINH_REG(base)                      ((base)->WIN8B.WINH)
#define WDOG_WINL_REG(base)                      ((base)->WIN8B.WINL)

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

/* CS1 Bit Fields */
#define WDOG_CS1_STOP_MASK                       0x1u
#define WDOG_CS1_STOP_SHIFT                      0
#define WDOG_CS1_WAIT_MASK                       0x2u
#define WDOG_CS1_WAIT_SHIFT                      1
#define WDOG_CS1_DBG_MASK                        0x4u
#define WDOG_CS1_DBG_SHIFT                       2
#define WDOG_CS1_TST_MASK                        0x18u
#define WDOG_CS1_TST_SHIFT                       3
#define WDOG_CS1_TST(x)                          (((uint8_t)(((uint8_t)(x))<<WDOG_CS1_TST_SHIFT))&WDOG_CS1_TST_MASK)
#define WDOG_CS1_UPDATE_MASK                     0x20u
#define WDOG_CS1_UPDATE_SHIFT                    5
#define WDOG_CS1_INT_MASK                        0x40u
#define WDOG_CS1_INT_SHIFT                       6
#define WDOG_CS1_EN_MASK                         0x80u
#define WDOG_CS1_EN_SHIFT                        7
/* CS2 Bit Fields */
#define WDOG_CS2_CLK_MASK                        0x3u
#define WDOG_CS2_CLK_SHIFT                       0
#define WDOG_CS2_CLK(x)                          (((uint8_t)(((uint8_t)(x))<<WDOG_CS2_CLK_SHIFT))&WDOG_CS2_CLK_MASK)
#define WDOG_CS2_PRES_MASK                       0x10u
#define WDOG_CS2_PRES_SHIFT                      4
#define WDOG_CS2_FLG_MASK                        0x40u
#define WDOG_CS2_FLG_SHIFT                       6
#define WDOG_CS2_WIN_MASK                        0x80u
#define WDOG_CS2_WIN_SHIFT                       7
/* CNT Bit Fields */
#define WDOG_CNT_CNT_MASK                        0xFFFFu
#define WDOG_CNT_CNT_SHIFT                       0
#define WDOG_CNT_CNT(x)                          (((uint16_t)(((uint16_t)(x))<<WDOG_CNT_CNT_SHIFT))&WDOG_CNT_CNT_MASK)
/* CNTH Bit Fields */
#define WDOG_CNTH_CNTHIGH_MASK                   0xFFu
#define WDOG_CNTH_CNTHIGH_SHIFT                  0
#define WDOG_CNTH_CNTHIGH(x)                     (((uint8_t)(((uint8_t)(x))<<WDOG_CNTH_CNTHIGH_SHIFT))&WDOG_CNTH_CNTHIGH_MASK)
/* CNTL Bit Fields */
#define WDOG_CNTL_CNTLOW_MASK                    0xFFu
#define WDOG_CNTL_CNTLOW_SHIFT                   0
#define WDOG_CNTL_CNTLOW(x)                      (((uint8_t)(((uint8_t)(x))<<WDOG_CNTL_CNTLOW_SHIFT))&WDOG_CNTL_CNTLOW_MASK)
/* TOVAL Bit Fields */
#define WDOG_TOVAL_TOVAL_MASK                    0xFFFFu
#define WDOG_TOVAL_TOVAL_SHIFT                   0
#define WDOG_TOVAL_TOVAL(x)                      (((uint16_t)(((uint16_t)(x))<<WDOG_TOVAL_TOVAL_SHIFT))&WDOG_TOVAL_TOVAL_MASK)
/* TOVALH Bit Fields */
#define WDOG_TOVALH_TOVALHIGH_MASK               0xFFu
#define WDOG_TOVALH_TOVALHIGH_SHIFT              0
#define WDOG_TOVALH_TOVALHIGH(x)                 (((uint8_t)(((uint8_t)(x))<<WDOG_TOVALH_TOVALHIGH_SHIFT))&WDOG_TOVALH_TOVALHIGH_MASK)
/* TOVALL Bit Fields */
#define WDOG_TOVALL_TOVALLOW_MASK                0xFFu
#define WDOG_TOVALL_TOVALLOW_SHIFT               0
#define WDOG_TOVALL_TOVALLOW(x)                  (((uint8_t)(((uint8_t)(x))<<WDOG_TOVALL_TOVALLOW_SHIFT))&WDOG_TOVALL_TOVALLOW_MASK)
/* WIN Bit Fields */
#define WDOG_WIN_WIN_MASK                        0xFFFFu
#define WDOG_WIN_WIN_SHIFT                       0
#define WDOG_WIN_WIN(x)                          (((uint16_t)(((uint16_t)(x))<<WDOG_WIN_WIN_SHIFT))&WDOG_WIN_WIN_MASK)
/* WINH Bit Fields */
#define WDOG_WINH_WINHIGH_MASK                   0xFFu
#define WDOG_WINH_WINHIGH_SHIFT                  0
#define WDOG_WINH_WINHIGH(x)                     (((uint8_t)(((uint8_t)(x))<<WDOG_WINH_WINHIGH_SHIFT))&WDOG_WINH_WINHIGH_MASK)
/* WINL Bit Fields */
#define WDOG_WINL_WINLOW_MASK                    0xFFu
#define WDOG_WINL_WINLOW_SHIFT                   0
#define WDOG_WINL_WINLOW(x)                      (((uint8_t)(((uint8_t)(x))<<WDOG_WINL_WINLOW_SHIFT))&WDOG_WINL_WINLOW_MASK)

/*!
 * @}
 */ /* end of group WDOG_Register_Masks */


/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG base address */
#define WDOG_BASE                                (0x40052000u)
/** Peripheral WDOG base pointer */
#define WDOG                                     ((WDOG_Type *)WDOG_BASE)
#define WDOG_BASE_PTR                            (WDOG)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG }

/* ----------------------------------------------------------------------------
   -- WDOG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Accessor_Macros WDOG - Register accessor macros
 * @{
 */


/* WDOG - Register instance definitions */
/* WDOG */
#define WDOG_CS1                                 WDOG_CS1_REG(WDOG)
#define WDOG_CS2                                 WDOG_CS2_REG(WDOG)
#define WDOG_CNT                                 WDOG_CNT_REG(WDOG)
#define WDOG_CNTH                                WDOG_CNTH_REG(WDOG)
#define WDOG_CNTL                                WDOG_CNTL_REG(WDOG)
#define WDOG_TOVAL                               WDOG_TOVAL_REG(WDOG)
#define WDOG_TOVALH                              WDOG_TOVALH_REG(WDOG)
#define WDOG_TOVALL                              WDOG_TOVALL_REG(WDOG)
#define WDOG_WIN                                 WDOG_WIN_REG(WDOG)
#define WDOG_WINH                                WDOG_WINH_REG(WDOG)
#define WDOG_WINL                                WDOG_WINL_REG(WDOG)

/*!
 * @}
 */ /* end of group WDOG_Register_Accessor_Macros */


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

#define Watchdog_IRQn                           WDOG_IRQn
#define Watchdog_IRQHandler                     WDOG_IRQHandler
#define LDO_CTRM_CSLTM_MASK                     This_symb_has_been_deprecated
#define LDO_CTRM_CSLTM_SHIFT                    This_symb_has_been_deprecated
#define LDO_CTRM_CSLTM(x)                       This_symb_has_been_deprecated
#define LDO_CTRM_CSHTM_MASK                     This_symb_has_been_deprecated
#define LDO_CTRM_CSHTM_SHIFT                    This_symb_has_been_deprecated
#define LDO_CTRM_CSHTM(x)                       This_symb_has_been_deprecated

/*!
 * @}
 */ /* end of group Backward_Compatibility_Symbols */


#else /* #if !defined(MWPR1516_H_) */
  /* There is already included the same memory map. Check if it is compatible (has the same major version) */
  #if (MCU_MEM_MAP_VERSION != 0x0100u)
    #if (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING))
      #warning There are included two not compatible versions of memory maps. Please check possible differences.
    #endif /* (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING)) */
  #endif /* (MCU_MEM_MAP_VERSION != 0x0100u) */
#endif  /* #if !defined(MWPR1516_H_) */

/* MWPR1516.h, eof. */
