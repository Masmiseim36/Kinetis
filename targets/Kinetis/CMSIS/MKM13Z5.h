/*
** ###################################################################
**     Compilers:           ARM Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    MKMxxZxxCxx5RM Rev. 4, June 2013
**     Version:             rev. 1.2, 2015-07-23
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MKM13Z5
**
**     Copyright: 1997 - 2015 Freescale, Inc. All Rights Reserved.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2012-10-18)
**         Initial version.
**     - rev. 1.1 (2013-04-05)
**         Changed start of doxygen comment.
**     - rev. 1.2 (2015-07-23)
**         Update according to final version of reference manual rev. 4.
**
** ###################################################################
*/

/*!
 * @file MKM13Z5.h
 * @version 1.2
 * @date 2015-07-23
 * @brief CMSIS Peripheral Access Layer for MKM13Z5
 *
 * CMSIS Peripheral Access Layer for MKM13Z5
 */

#if !defined(MKM13Z5_H_)
#define MKM13Z5_H_                               /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100u
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0002u


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
typedef enum IRQn {
  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M0 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M0 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M0 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M0 System Tick Interrupt */

  /* Device specific interrupts */
  DMA0_IRQn                    = 0,                /**< DMA Channel 0 Transfer Complete */
  DMA1_IRQn                    = 1,                /**< DMA Channel 1 Transfer Complete */
  DMA2_IRQn                    = 2,                /**< DMA Channel 2 Transfer Complete */
  DMA3_IRQn                    = 3,                /**< DMA Channel 3 Transfer Complete */
  SPI0_IRQn                    = 4,                /**< ORed Interrupt SPI0 */
  SPI1_IRQn                    = 5,                /**< ORed Interrupt SPI1 */
  PMC_IRQn                     = 6,                /**< Low-voltage detect, low-voltage warning */
  TMR0_IRQn                    = 7,                /**< Quad Timer Counter0 */
  TMR1_IRQn                    = 8,                /**< Quad Timer Counter1 */
  TMR2_IRQn                    = 9,                /**< Quad Timer Counter2 */
  TMR3_IRQn                    = 10,               /**< Quad Timer Counter3 */
  PIT0_PIT1_IRQn               = 11,               /**< ORed Interrupt of PITs */
  LLWU_IRQn                    = 12,               /**< Low Leakage Wakeup */
  FTFA_IRQn                    = 13,               /**< ORed interrupt for Flash Command Complete/Read collision */
  CMP0_CMP1_IRQn               = 14,               /**< ORed Interrupt of PRACMP */
  LCD_IRQn                     = 15,               /**< ORed Interrupt of SLCD */
  ADC_IRQn                     = 16,               /**< ORed Interrupt from SAR */
  PTx_IRQn                     = 17,               /**< ORed Interrupt from all GPIO (PTx) ports */
  RNGA_IRQn                    = 18,               /**< ORed Interrupt from RNGA */
  SCI0_SCI1_IRQn               = 19,               /**< ORed Interrupt SCI0 and SCI1 */
  SCI2_SCI3_IRQn               = 20,               /**< ORed Interrupt SCI2 and SCI3 */
  AFE0_IRQn                    = 21,               /**< AFE Channel 0 ORed Interrupt */
  AFE1_IRQn                    = 22,               /**< AFE Channel 1 ORed Interrupt */
  AFE2_IRQn                    = 23,               /**< AFE Channel 2 ORed Interrupt */
  Reserved40_IRQn              = 24,               /**< Reserved interrupt 40 */
  RTC_IRQn                     = 25,               /**< iRTC Interrupt */
  I2C0_I2C1_IRQn               = 26,               /**< ORed I2C interrupt */
  EWM_IRQn                     = 27,               /**< External Watchdog Monitor */
  MCG_IRQn                     = 28,               /**< MCG Loss of Clock, Loss of Lock */
  Watchdog_IRQn                = 29,               /**< ORed WDOG Interrupt */
  LPTMR_IRQn                   = 30,               /**< ORed LPTIMER Interrupt */
  PXBAR_IRQn                   = 31                /**< Peripheral XBAR ORed Interrupt */
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
#include "system_MKM13Z5.h"            /* Device specific configuration file */

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
  __IO uint32_t SC1[4];                            /**< ADC Status and Control Registers 1, array offset: 0x0, array step: 0x4 */
  __IO uint32_t CFG1;                              /**< ADC Configuration Register 1, offset: 0x10 */
  __IO uint32_t CFG2;                              /**< ADC Configuration Register 2, offset: 0x14 */
  __I  uint32_t R[4];                              /**< ADC Data Result Register, array offset: 0x18, array step: 0x4 */
  __IO uint32_t CV1;                               /**< Compare Value Registers, offset: 0x28 */
  __IO uint32_t CV2;                               /**< Compare Value Registers, offset: 0x2C */
  __IO uint32_t SC2;                               /**< Status and Control Register 2, offset: 0x30 */
  __IO uint32_t SC3;                               /**< Status and Control Register 3, offset: 0x34 */
  __IO uint32_t OFS;                               /**< ADC Offset Correction Register, offset: 0x38 */
  __IO uint32_t PG;                                /**< ADC Plus-Side Gain Register, offset: 0x3C */
       uint8_t RESERVED_0[4];
  __IO uint32_t CLPD;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x44 */
  __IO uint32_t CLPS;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x48 */
  __IO uint32_t CLP4;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x4C */
  __IO uint32_t CLP3;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x50 */
  __IO uint32_t CLP2;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x54 */
  __IO uint32_t CLP1;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x58 */
  __IO uint32_t CLP0;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x5C */
} ADC_Type;

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
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_ADCH_SHIFT))&ADC_SC1_ADCH_MASK)
#define ADC_SC1_AIEN_MASK                        0x40u
#define ADC_SC1_AIEN_SHIFT                       6
#define ADC_SC1_COCO_MASK                        0x80u
#define ADC_SC1_COCO_SHIFT                       7
/* CFG1 Bit Fields */
#define ADC_CFG1_ADICLK_MASK                     0x3u
#define ADC_CFG1_ADICLK_SHIFT                    0
#define ADC_CFG1_ADICLK(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADICLK_SHIFT))&ADC_CFG1_ADICLK_MASK)
#define ADC_CFG1_MODE_MASK                       0xCu
#define ADC_CFG1_MODE_SHIFT                      2
#define ADC_CFG1_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_MODE_SHIFT))&ADC_CFG1_MODE_MASK)
#define ADC_CFG1_ADLSMP_MASK                     0x10u
#define ADC_CFG1_ADLSMP_SHIFT                    4
#define ADC_CFG1_ADIV_MASK                       0x60u
#define ADC_CFG1_ADIV_SHIFT                      5
#define ADC_CFG1_ADIV(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADIV_SHIFT))&ADC_CFG1_ADIV_MASK)
#define ADC_CFG1_ADLPC_MASK                      0x80u
#define ADC_CFG1_ADLPC_SHIFT                     7
/* CFG2 Bit Fields */
#define ADC_CFG2_ADLSTS_MASK                     0x3u
#define ADC_CFG2_ADLSTS_SHIFT                    0
#define ADC_CFG2_ADLSTS(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADLSTS_SHIFT))&ADC_CFG2_ADLSTS_MASK)
#define ADC_CFG2_ADHSC_MASK                      0x4u
#define ADC_CFG2_ADHSC_SHIFT                     2
#define ADC_CFG2_ADACKEN_MASK                    0x8u
#define ADC_CFG2_ADACKEN_SHIFT                   3
#define ADC_CFG2_MUXSEL_MASK                     0x10u
#define ADC_CFG2_MUXSEL_SHIFT                    4
/* R Bit Fields */
#define ADC_R_D_MASK                             0xFFFFu
#define ADC_R_D_SHIFT                            0
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x))<<ADC_R_D_SHIFT))&ADC_R_D_MASK)
/* CV1 Bit Fields */
#define ADC_CV1_CV_MASK                          0xFFFFu
#define ADC_CV1_CV_SHIFT                         0
#define ADC_CV1_CV(x)                            (((uint32_t)(((uint32_t)(x))<<ADC_CV1_CV_SHIFT))&ADC_CV1_CV_MASK)
/* CV2 Bit Fields */
#define ADC_CV2_CV_MASK                          0xFFFFu
#define ADC_CV2_CV_SHIFT                         0
#define ADC_CV2_CV(x)                            (((uint32_t)(((uint32_t)(x))<<ADC_CV2_CV_SHIFT))&ADC_CV2_CV_MASK)
/* SC2 Bit Fields */
#define ADC_SC2_REFSEL_MASK                      0x3u
#define ADC_SC2_REFSEL_SHIFT                     0
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC2_REFSEL_SHIFT))&ADC_SC2_REFSEL_MASK)
#define ADC_SC2_DMAEN_MASK                       0x4u
#define ADC_SC2_DMAEN_SHIFT                      2
#define ADC_SC2_ACREN_MASK                       0x8u
#define ADC_SC2_ACREN_SHIFT                      3
#define ADC_SC2_ACFGT_MASK                       0x10u
#define ADC_SC2_ACFGT_SHIFT                      4
#define ADC_SC2_ACFE_MASK                        0x20u
#define ADC_SC2_ACFE_SHIFT                       5
#define ADC_SC2_ADTRG_MASK                       0x40u
#define ADC_SC2_ADTRG_SHIFT                      6
#define ADC_SC2_ADACT_MASK                       0x80u
#define ADC_SC2_ADACT_SHIFT                      7
/* SC3 Bit Fields */
#define ADC_SC3_AVGS_MASK                        0x3u
#define ADC_SC3_AVGS_SHIFT                       0
#define ADC_SC3_AVGS(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGS_SHIFT))&ADC_SC3_AVGS_MASK)
#define ADC_SC3_AVGE_MASK                        0x4u
#define ADC_SC3_AVGE_SHIFT                       2
#define ADC_SC3_ADCO_MASK                        0x8u
#define ADC_SC3_ADCO_SHIFT                       3
#define ADC_SC3_CALF_MASK                        0x40u
#define ADC_SC3_CALF_SHIFT                       6
#define ADC_SC3_CAL_MASK                         0x80u
#define ADC_SC3_CAL_SHIFT                        7
/* OFS Bit Fields */
#define ADC_OFS_OFS_MASK                         0xFFFFu
#define ADC_OFS_OFS_SHIFT                        0
#define ADC_OFS_OFS(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_OFS_OFS_SHIFT))&ADC_OFS_OFS_MASK)
/* PG Bit Fields */
#define ADC_PG_PG_MASK                           0xFFFFu
#define ADC_PG_PG_SHIFT                          0
#define ADC_PG_PG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_PG_PG_SHIFT))&ADC_PG_PG_MASK)
/* CLPD Bit Fields */
#define ADC_CLPD_CLPD_MASK                       0x3Fu
#define ADC_CLPD_CLPD_SHIFT                      0
#define ADC_CLPD_CLPD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPD_CLPD_SHIFT))&ADC_CLPD_CLPD_MASK)
/* CLPS Bit Fields */
#define ADC_CLPS_CLPS_MASK                       0x3Fu
#define ADC_CLPS_CLPS_SHIFT                      0
#define ADC_CLPS_CLPS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPS_CLPS_SHIFT))&ADC_CLPS_CLPS_MASK)
/* CLP4 Bit Fields */
#define ADC_CLP4_CLP4_MASK                       0x3FFu
#define ADC_CLP4_CLP4_SHIFT                      0
#define ADC_CLP4_CLP4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP4_CLP4_SHIFT))&ADC_CLP4_CLP4_MASK)
/* CLP3 Bit Fields */
#define ADC_CLP3_CLP3_MASK                       0x1FFu
#define ADC_CLP3_CLP3_SHIFT                      0
#define ADC_CLP3_CLP3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP3_CLP3_SHIFT))&ADC_CLP3_CLP3_MASK)
/* CLP2 Bit Fields */
#define ADC_CLP2_CLP2_MASK                       0xFFu
#define ADC_CLP2_CLP2_SHIFT                      0
#define ADC_CLP2_CLP2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP2_CLP2_SHIFT))&ADC_CLP2_CLP2_MASK)
/* CLP1 Bit Fields */
#define ADC_CLP1_CLP1_MASK                       0x7Fu
#define ADC_CLP1_CLP1_SHIFT                      0
#define ADC_CLP1_CLP1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP1_CLP1_SHIFT))&ADC_CLP1_CLP1_MASK)
/* CLP0 Bit Fields */
#define ADC_CLP0_CLP0_MASK                       0x3Fu
#define ADC_CLP0_CLP0_SHIFT                      0
#define ADC_CLP0_CLP0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP0_CLP0_SHIFT))&ADC_CLP0_CLP0_MASK)

/*!
 * @}
 */ /* end of group ADC_Register_Masks */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC base address */
#define ADC_BASE                                 (0x4002B000u)
/** Peripheral ADC base pointer */
#define ADC                                      ((ADC_Type *)ADC_BASE)
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASES                                { ADC }

/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- AFE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AFE_Peripheral_Access_Layer AFE Peripheral Access Layer
 * @{
 */

/** AFE - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFR[3];                            /**< Channel0 Configuration Register..Channel2 Configuration Register, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[12];
  __IO uint32_t CR;                                /**< Control Register, offset: 0x18 */
  __IO uint32_t CKR;                               /**< Clock Configuration Register, offset: 0x1C */
  __IO uint32_t DI;                                /**< DMA and Interrupt Register, offset: 0x20 */
       uint8_t RESERVED_1[8];
  __IO uint32_t DR[3];                             /**< Channel0 Delay Register..Channel2 Delay Register, array offset: 0x2C, array step: 0x4 */
       uint8_t RESERVED_2[12];
  __I  uint32_t RR[3];                             /**< Channel0 Result Register..Channel2 Result Register, array offset: 0x44, array step: 0x4 */
       uint8_t RESERVED_3[12];
  __I  uint32_t SR;                                /**< Status Register, offset: 0x5C */
} AFE_Type;

/* ----------------------------------------------------------------------------
   -- AFE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AFE_Register_Masks AFE Register Masks
 * @{
 */

/* CFR Bit Fields */
#define AFE_CFR_HW_TRG_MASK                      0x200u
#define AFE_CFR_HW_TRG_SHIFT                     9
#define AFE_CFR_DEC_CLK_INP_SEL_MASK             0x400u
#define AFE_CFR_DEC_CLK_INP_SEL_SHIFT            10
#define AFE_CFR_DEC_CLK_EDGE_SEL_MASK            0x800u
#define AFE_CFR_DEC_CLK_EDGE_SEL_SHIFT           11
#define AFE_CFR_CC_MASK                          0x1000u
#define AFE_CFR_CC_SHIFT                         12
#define AFE_CFR_DEC_EN_MASK                      0x2000u
#define AFE_CFR_DEC_EN_SHIFT                     13
#define AFE_CFR_SD_MOD_EN_MASK                   0x4000u
#define AFE_CFR_SD_MOD_EN_SHIFT                  14
#define AFE_CFR_BYP_MODE_MASK                    0x20000u
#define AFE_CFR_BYP_MODE_SHIFT                   17
#define AFE_CFR_PGA_GAIN_SEL_MASK                0x380000u
#define AFE_CFR_PGA_GAIN_SEL_SHIFT               19
#define AFE_CFR_PGA_GAIN_SEL(x)                  (((uint32_t)(((uint32_t)(x))<<AFE_CFR_PGA_GAIN_SEL_SHIFT))&AFE_CFR_PGA_GAIN_SEL_MASK)
#define AFE_CFR_PGA_EN_MASK                      0x1000000u
#define AFE_CFR_PGA_EN_SHIFT                     24
#define AFE_CFR_DEC_OSR_MASK                     0xE0000000u
#define AFE_CFR_DEC_OSR_SHIFT                    29
#define AFE_CFR_DEC_OSR(x)                       (((uint32_t)(((uint32_t)(x))<<AFE_CFR_DEC_OSR_SHIFT))&AFE_CFR_DEC_OSR_MASK)
/* CR Bit Fields */
#define AFE_CR_STRTUP_CNT_MASK                   0xFE00u
#define AFE_CR_STRTUP_CNT_SHIFT                  9
#define AFE_CR_STRTUP_CNT(x)                     (((uint32_t)(((uint32_t)(x))<<AFE_CR_STRTUP_CNT_SHIFT))&AFE_CR_STRTUP_CNT_MASK)
#define AFE_CR_RESULT_FORMAT_MASK                0x40000u
#define AFE_CR_RESULT_FORMAT_SHIFT               18
#define AFE_CR_DLY_OK_MASK                       0x200000u
#define AFE_CR_DLY_OK_SHIFT                      21
#define AFE_CR_RST_B_MASK                        0x400000u
#define AFE_CR_RST_B_SHIFT                       22
#define AFE_CR_LPM_EN_MASK                       0x2000000u
#define AFE_CR_LPM_EN_SHIFT                      25
#define AFE_CR_SOFT_TRG3_MASK                    0x8000000u
#define AFE_CR_SOFT_TRG3_SHIFT                   27
#define AFE_CR_SOFT_TRG2_MASK                    0x10000000u
#define AFE_CR_SOFT_TRG2_SHIFT                   28
#define AFE_CR_SOFT_TRG1_MASK                    0x20000000u
#define AFE_CR_SOFT_TRG1_SHIFT                   29
#define AFE_CR_SOFT_TRG0_MASK                    0x40000000u
#define AFE_CR_SOFT_TRG0_SHIFT                   30
#define AFE_CR_MSTR_EN_MASK                      0x80000000u
#define AFE_CR_MSTR_EN_SHIFT                     31
/* CKR Bit Fields */
#define AFE_CKR_CLS_MASK                         0x600000u
#define AFE_CKR_CLS_SHIFT                        21
#define AFE_CKR_CLS(x)                           (((uint32_t)(((uint32_t)(x))<<AFE_CKR_CLS_SHIFT))&AFE_CKR_CLS_MASK)
#define AFE_CKR_DIV_MASK                         0xF0000000u
#define AFE_CKR_DIV_SHIFT                        28
#define AFE_CKR_DIV(x)                           (((uint32_t)(((uint32_t)(x))<<AFE_CKR_DIV_SHIFT))&AFE_CKR_DIV_MASK)
/* DI Bit Fields */
#define AFE_DI_INTEN3_MASK                       0x800000u
#define AFE_DI_INTEN3_SHIFT                      23
#define AFE_DI_INTEN2_MASK                       0x1000000u
#define AFE_DI_INTEN2_SHIFT                      24
#define AFE_DI_INTEN1_MASK                       0x2000000u
#define AFE_DI_INTEN1_SHIFT                      25
#define AFE_DI_INTEN0_MASK                       0x4000000u
#define AFE_DI_INTEN0_SHIFT                      26
#define AFE_DI_DMAEN3_MASK                       0x10000000u
#define AFE_DI_DMAEN3_SHIFT                      28
#define AFE_DI_DMAEN2_MASK                       0x20000000u
#define AFE_DI_DMAEN2_SHIFT                      29
#define AFE_DI_DMAEN1_MASK                       0x40000000u
#define AFE_DI_DMAEN1_SHIFT                      30
#define AFE_DI_DMAEN0_MASK                       0x80000000u
#define AFE_DI_DMAEN0_SHIFT                      31
/* DR Bit Fields */
#define AFE_DR_DLY_MASK                          0x7FFu
#define AFE_DR_DLY_SHIFT                         0
#define AFE_DR_DLY(x)                            (((uint32_t)(((uint32_t)(x))<<AFE_DR_DLY_SHIFT))&AFE_DR_DLY_MASK)
/* RR Bit Fields */
#define AFE_RR_SDR_MASK                          0x7FFFFFu
#define AFE_RR_SDR_SHIFT                         0
#define AFE_RR_SDR(x)                            (((uint32_t)(((uint32_t)(x))<<AFE_RR_SDR_SHIFT))&AFE_RR_SDR_MASK)
#define AFE_RR_SIGN_BITS_MASK                    0xFF800000u
#define AFE_RR_SIGN_BITS_SHIFT                   23
#define AFE_RR_SIGN_BITS(x)                      (((uint32_t)(((uint32_t)(x))<<AFE_RR_SIGN_BITS_SHIFT))&AFE_RR_SIGN_BITS_MASK)
/* SR Bit Fields */
#define AFE_SR_RDY3_MASK                         0x10000u
#define AFE_SR_RDY3_SHIFT                        16
#define AFE_SR_RDY2_MASK                         0x20000u
#define AFE_SR_RDY2_SHIFT                        17
#define AFE_SR_RDY1_MASK                         0x40000u
#define AFE_SR_RDY1_SHIFT                        18
#define AFE_SR_RDY0_MASK                         0x80000u
#define AFE_SR_RDY0_SHIFT                        19
#define AFE_SR_OVR3_MASK                         0x200000u
#define AFE_SR_OVR3_SHIFT                        21
#define AFE_SR_OVR2_MASK                         0x400000u
#define AFE_SR_OVR2_SHIFT                        22
#define AFE_SR_OVR1_MASK                         0x800000u
#define AFE_SR_OVR1_SHIFT                        23
#define AFE_SR_OVR0_MASK                         0x1000000u
#define AFE_SR_OVR0_SHIFT                        24
#define AFE_SR_COC3_MASK                         0x10000000u
#define AFE_SR_COC3_SHIFT                        28
#define AFE_SR_COC2_MASK                         0x20000000u
#define AFE_SR_COC2_SHIFT                        29
#define AFE_SR_COC1_MASK                         0x40000000u
#define AFE_SR_COC1_SHIFT                        30
#define AFE_SR_COC0_MASK                         0x80000000u
#define AFE_SR_COC0_SHIFT                        31

/*!
 * @}
 */ /* end of group AFE_Register_Masks */


/* AFE - Peripheral instance base addresses */
/** Peripheral AFE base address */
#define AFE_BASE                                 (0x40030000u)
/** Peripheral AFE base pointer */
#define AFE                                      ((AFE_Type *)AFE_BASE)
/** Array initializer of AFE peripheral base pointers */
#define AFE_BASES                                { AFE }

/*!
 * @}
 */ /* end of group AFE_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- AIPS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AIPS_Peripheral_Access_Layer AIPS Peripheral Access Layer
 * @{
 */

/** AIPS - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t PACRA;                             /**< Peripheral Access Control Register, offset: 0x20 */
  __IO uint32_t PACRB;                             /**< Peripheral Access Control Register, offset: 0x24 */
       uint8_t RESERVED_1[24];
  __IO uint32_t PACRE;                             /**< Peripheral Access Control Register, offset: 0x40 */
  __IO uint32_t PACRF;                             /**< Peripheral Access Control Register, offset: 0x44 */
  __IO uint32_t PACRG;                             /**< Peripheral Access Control Register, offset: 0x48 */
  __IO uint32_t PACRH;                             /**< Peripheral Access Control Register, offset: 0x4C */
  __IO uint32_t PACRI;                             /**< Peripheral Access Control Register, offset: 0x50 */
  __IO uint32_t PACRJ;                             /**< Peripheral Access Control Register, offset: 0x54 */
  __IO uint32_t PACRK;                             /**< Peripheral Access Control Register, offset: 0x58 */
  __IO uint32_t PACRL;                             /**< Peripheral Access Control Register, offset: 0x5C */
  __IO uint32_t PACRM;                             /**< Peripheral Access Control Register, offset: 0x60 */
  __IO uint32_t PACRN;                             /**< Peripheral Access Control Register, offset: 0x64 */
  __IO uint32_t PACRO;                             /**< Peripheral Access Control Register, offset: 0x68 */
  __IO uint32_t PACRP;                             /**< Peripheral Access Control Register, offset: 0x6C */
} AIPS_Type;

/* ----------------------------------------------------------------------------
   -- AIPS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AIPS_Register_Masks AIPS Register Masks
 * @{
 */

/* PACRA Bit Fields */
#define AIPS_PACRA_AC7_MASK                      0x7u
#define AIPS_PACRA_AC7_SHIFT                     0
#define AIPS_PACRA_AC7(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRA_AC7_SHIFT))&AIPS_PACRA_AC7_MASK)
#define AIPS_PACRA_RO7_MASK                      0x8u
#define AIPS_PACRA_RO7_SHIFT                     3
#define AIPS_PACRA_AC6_MASK                      0x70u
#define AIPS_PACRA_AC6_SHIFT                     4
#define AIPS_PACRA_AC6(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRA_AC6_SHIFT))&AIPS_PACRA_AC6_MASK)
#define AIPS_PACRA_RO6_MASK                      0x80u
#define AIPS_PACRA_RO6_SHIFT                     7
#define AIPS_PACRA_AC5_MASK                      0x700u
#define AIPS_PACRA_AC5_SHIFT                     8
#define AIPS_PACRA_AC5(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRA_AC5_SHIFT))&AIPS_PACRA_AC5_MASK)
#define AIPS_PACRA_RO5_MASK                      0x800u
#define AIPS_PACRA_RO5_SHIFT                     11
#define AIPS_PACRA_AC4_MASK                      0x7000u
#define AIPS_PACRA_AC4_SHIFT                     12
#define AIPS_PACRA_AC4(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRA_AC4_SHIFT))&AIPS_PACRA_AC4_MASK)
#define AIPS_PACRA_RO4_MASK                      0x8000u
#define AIPS_PACRA_RO4_SHIFT                     15
#define AIPS_PACRA_AC3_MASK                      0x70000u
#define AIPS_PACRA_AC3_SHIFT                     16
#define AIPS_PACRA_AC3(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRA_AC3_SHIFT))&AIPS_PACRA_AC3_MASK)
#define AIPS_PACRA_RO3_MASK                      0x80000u
#define AIPS_PACRA_RO3_SHIFT                     19
#define AIPS_PACRA_AC2_MASK                      0x700000u
#define AIPS_PACRA_AC2_SHIFT                     20
#define AIPS_PACRA_AC2(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRA_AC2_SHIFT))&AIPS_PACRA_AC2_MASK)
#define AIPS_PACRA_RO2_MASK                      0x800000u
#define AIPS_PACRA_RO2_SHIFT                     23
#define AIPS_PACRA_AC1_MASK                      0x7000000u
#define AIPS_PACRA_AC1_SHIFT                     24
#define AIPS_PACRA_AC1(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRA_AC1_SHIFT))&AIPS_PACRA_AC1_MASK)
#define AIPS_PACRA_RO1_MASK                      0x8000000u
#define AIPS_PACRA_RO1_SHIFT                     27
#define AIPS_PACRA_AC0_MASK                      0x70000000u
#define AIPS_PACRA_AC0_SHIFT                     28
#define AIPS_PACRA_AC0(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRA_AC0_SHIFT))&AIPS_PACRA_AC0_MASK)
#define AIPS_PACRA_RO0_MASK                      0x80000000u
#define AIPS_PACRA_RO0_SHIFT                     31
/* PACRB Bit Fields */
#define AIPS_PACRB_AC7_MASK                      0x7u
#define AIPS_PACRB_AC7_SHIFT                     0
#define AIPS_PACRB_AC7(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRB_AC7_SHIFT))&AIPS_PACRB_AC7_MASK)
#define AIPS_PACRB_RO7_MASK                      0x8u
#define AIPS_PACRB_RO7_SHIFT                     3
#define AIPS_PACRB_AC6_MASK                      0x70u
#define AIPS_PACRB_AC6_SHIFT                     4
#define AIPS_PACRB_AC6(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRB_AC6_SHIFT))&AIPS_PACRB_AC6_MASK)
#define AIPS_PACRB_RO6_MASK                      0x80u
#define AIPS_PACRB_RO6_SHIFT                     7
#define AIPS_PACRB_AC5_MASK                      0x700u
#define AIPS_PACRB_AC5_SHIFT                     8
#define AIPS_PACRB_AC5(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRB_AC5_SHIFT))&AIPS_PACRB_AC5_MASK)
#define AIPS_PACRB_RO5_MASK                      0x800u
#define AIPS_PACRB_RO5_SHIFT                     11
#define AIPS_PACRB_AC4_MASK                      0x7000u
#define AIPS_PACRB_AC4_SHIFT                     12
#define AIPS_PACRB_AC4(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRB_AC4_SHIFT))&AIPS_PACRB_AC4_MASK)
#define AIPS_PACRB_RO4_MASK                      0x8000u
#define AIPS_PACRB_RO4_SHIFT                     15
#define AIPS_PACRB_AC3_MASK                      0x70000u
#define AIPS_PACRB_AC3_SHIFT                     16
#define AIPS_PACRB_AC3(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRB_AC3_SHIFT))&AIPS_PACRB_AC3_MASK)
#define AIPS_PACRB_RO3_MASK                      0x80000u
#define AIPS_PACRB_RO3_SHIFT                     19
#define AIPS_PACRB_AC2_MASK                      0x700000u
#define AIPS_PACRB_AC2_SHIFT                     20
#define AIPS_PACRB_AC2(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRB_AC2_SHIFT))&AIPS_PACRB_AC2_MASK)
#define AIPS_PACRB_RO2_MASK                      0x800000u
#define AIPS_PACRB_RO2_SHIFT                     23
#define AIPS_PACRB_AC1_MASK                      0x7000000u
#define AIPS_PACRB_AC1_SHIFT                     24
#define AIPS_PACRB_AC1(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRB_AC1_SHIFT))&AIPS_PACRB_AC1_MASK)
#define AIPS_PACRB_RO1_MASK                      0x8000000u
#define AIPS_PACRB_RO1_SHIFT                     27
#define AIPS_PACRB_AC0_MASK                      0x70000000u
#define AIPS_PACRB_AC0_SHIFT                     28
#define AIPS_PACRB_AC0(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRB_AC0_SHIFT))&AIPS_PACRB_AC0_MASK)
#define AIPS_PACRB_RO0_MASK                      0x80000000u
#define AIPS_PACRB_RO0_SHIFT                     31
/* PACRE Bit Fields */
#define AIPS_PACRE_AC7_MASK                      0x7u
#define AIPS_PACRE_AC7_SHIFT                     0
#define AIPS_PACRE_AC7(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRE_AC7_SHIFT))&AIPS_PACRE_AC7_MASK)
#define AIPS_PACRE_RO7_MASK                      0x8u
#define AIPS_PACRE_RO7_SHIFT                     3
#define AIPS_PACRE_AC6_MASK                      0x70u
#define AIPS_PACRE_AC6_SHIFT                     4
#define AIPS_PACRE_AC6(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRE_AC6_SHIFT))&AIPS_PACRE_AC6_MASK)
#define AIPS_PACRE_RO6_MASK                      0x80u
#define AIPS_PACRE_RO6_SHIFT                     7
#define AIPS_PACRE_AC5_MASK                      0x700u
#define AIPS_PACRE_AC5_SHIFT                     8
#define AIPS_PACRE_AC5(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRE_AC5_SHIFT))&AIPS_PACRE_AC5_MASK)
#define AIPS_PACRE_RO5_MASK                      0x800u
#define AIPS_PACRE_RO5_SHIFT                     11
#define AIPS_PACRE_AC4_MASK                      0x7000u
#define AIPS_PACRE_AC4_SHIFT                     12
#define AIPS_PACRE_AC4(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRE_AC4_SHIFT))&AIPS_PACRE_AC4_MASK)
#define AIPS_PACRE_RO4_MASK                      0x8000u
#define AIPS_PACRE_RO4_SHIFT                     15
#define AIPS_PACRE_AC3_MASK                      0x70000u
#define AIPS_PACRE_AC3_SHIFT                     16
#define AIPS_PACRE_AC3(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRE_AC3_SHIFT))&AIPS_PACRE_AC3_MASK)
#define AIPS_PACRE_RO3_MASK                      0x80000u
#define AIPS_PACRE_RO3_SHIFT                     19
#define AIPS_PACRE_AC2_MASK                      0x700000u
#define AIPS_PACRE_AC2_SHIFT                     20
#define AIPS_PACRE_AC2(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRE_AC2_SHIFT))&AIPS_PACRE_AC2_MASK)
#define AIPS_PACRE_RO2_MASK                      0x800000u
#define AIPS_PACRE_RO2_SHIFT                     23
#define AIPS_PACRE_AC1_MASK                      0x7000000u
#define AIPS_PACRE_AC1_SHIFT                     24
#define AIPS_PACRE_AC1(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRE_AC1_SHIFT))&AIPS_PACRE_AC1_MASK)
#define AIPS_PACRE_RO1_MASK                      0x8000000u
#define AIPS_PACRE_RO1_SHIFT                     27
#define AIPS_PACRE_AC0_MASK                      0x70000000u
#define AIPS_PACRE_AC0_SHIFT                     28
#define AIPS_PACRE_AC0(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRE_AC0_SHIFT))&AIPS_PACRE_AC0_MASK)
#define AIPS_PACRE_RO0_MASK                      0x80000000u
#define AIPS_PACRE_RO0_SHIFT                     31
/* PACRF Bit Fields */
#define AIPS_PACRF_AC7_MASK                      0x7u
#define AIPS_PACRF_AC7_SHIFT                     0
#define AIPS_PACRF_AC7(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRF_AC7_SHIFT))&AIPS_PACRF_AC7_MASK)
#define AIPS_PACRF_RO7_MASK                      0x8u
#define AIPS_PACRF_RO7_SHIFT                     3
#define AIPS_PACRF_AC6_MASK                      0x70u
#define AIPS_PACRF_AC6_SHIFT                     4
#define AIPS_PACRF_AC6(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRF_AC6_SHIFT))&AIPS_PACRF_AC6_MASK)
#define AIPS_PACRF_RO6_MASK                      0x80u
#define AIPS_PACRF_RO6_SHIFT                     7
#define AIPS_PACRF_AC5_MASK                      0x700u
#define AIPS_PACRF_AC5_SHIFT                     8
#define AIPS_PACRF_AC5(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRF_AC5_SHIFT))&AIPS_PACRF_AC5_MASK)
#define AIPS_PACRF_RO5_MASK                      0x800u
#define AIPS_PACRF_RO5_SHIFT                     11
#define AIPS_PACRF_AC4_MASK                      0x7000u
#define AIPS_PACRF_AC4_SHIFT                     12
#define AIPS_PACRF_AC4(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRF_AC4_SHIFT))&AIPS_PACRF_AC4_MASK)
#define AIPS_PACRF_RO4_MASK                      0x8000u
#define AIPS_PACRF_RO4_SHIFT                     15
#define AIPS_PACRF_AC3_MASK                      0x70000u
#define AIPS_PACRF_AC3_SHIFT                     16
#define AIPS_PACRF_AC3(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRF_AC3_SHIFT))&AIPS_PACRF_AC3_MASK)
#define AIPS_PACRF_RO3_MASK                      0x80000u
#define AIPS_PACRF_RO3_SHIFT                     19
#define AIPS_PACRF_AC2_MASK                      0x700000u
#define AIPS_PACRF_AC2_SHIFT                     20
#define AIPS_PACRF_AC2(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRF_AC2_SHIFT))&AIPS_PACRF_AC2_MASK)
#define AIPS_PACRF_RO2_MASK                      0x800000u
#define AIPS_PACRF_RO2_SHIFT                     23
#define AIPS_PACRF_AC1_MASK                      0x7000000u
#define AIPS_PACRF_AC1_SHIFT                     24
#define AIPS_PACRF_AC1(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRF_AC1_SHIFT))&AIPS_PACRF_AC1_MASK)
#define AIPS_PACRF_RO1_MASK                      0x8000000u
#define AIPS_PACRF_RO1_SHIFT                     27
#define AIPS_PACRF_AC0_MASK                      0x70000000u
#define AIPS_PACRF_AC0_SHIFT                     28
#define AIPS_PACRF_AC0(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRF_AC0_SHIFT))&AIPS_PACRF_AC0_MASK)
#define AIPS_PACRF_RO0_MASK                      0x80000000u
#define AIPS_PACRF_RO0_SHIFT                     31
/* PACRG Bit Fields */
#define AIPS_PACRG_AC7_MASK                      0x7u
#define AIPS_PACRG_AC7_SHIFT                     0
#define AIPS_PACRG_AC7(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRG_AC7_SHIFT))&AIPS_PACRG_AC7_MASK)
#define AIPS_PACRG_RO7_MASK                      0x8u
#define AIPS_PACRG_RO7_SHIFT                     3
#define AIPS_PACRG_AC6_MASK                      0x70u
#define AIPS_PACRG_AC6_SHIFT                     4
#define AIPS_PACRG_AC6(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRG_AC6_SHIFT))&AIPS_PACRG_AC6_MASK)
#define AIPS_PACRG_RO6_MASK                      0x80u
#define AIPS_PACRG_RO6_SHIFT                     7
#define AIPS_PACRG_AC5_MASK                      0x700u
#define AIPS_PACRG_AC5_SHIFT                     8
#define AIPS_PACRG_AC5(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRG_AC5_SHIFT))&AIPS_PACRG_AC5_MASK)
#define AIPS_PACRG_RO5_MASK                      0x800u
#define AIPS_PACRG_RO5_SHIFT                     11
#define AIPS_PACRG_AC4_MASK                      0x7000u
#define AIPS_PACRG_AC4_SHIFT                     12
#define AIPS_PACRG_AC4(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRG_AC4_SHIFT))&AIPS_PACRG_AC4_MASK)
#define AIPS_PACRG_RO4_MASK                      0x8000u
#define AIPS_PACRG_RO4_SHIFT                     15
#define AIPS_PACRG_AC3_MASK                      0x70000u
#define AIPS_PACRG_AC3_SHIFT                     16
#define AIPS_PACRG_AC3(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRG_AC3_SHIFT))&AIPS_PACRG_AC3_MASK)
#define AIPS_PACRG_RO3_MASK                      0x80000u
#define AIPS_PACRG_RO3_SHIFT                     19
#define AIPS_PACRG_AC2_MASK                      0x700000u
#define AIPS_PACRG_AC2_SHIFT                     20
#define AIPS_PACRG_AC2(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRG_AC2_SHIFT))&AIPS_PACRG_AC2_MASK)
#define AIPS_PACRG_RO2_MASK                      0x800000u
#define AIPS_PACRG_RO2_SHIFT                     23
#define AIPS_PACRG_AC1_MASK                      0x7000000u
#define AIPS_PACRG_AC1_SHIFT                     24
#define AIPS_PACRG_AC1(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRG_AC1_SHIFT))&AIPS_PACRG_AC1_MASK)
#define AIPS_PACRG_RO1_MASK                      0x8000000u
#define AIPS_PACRG_RO1_SHIFT                     27
#define AIPS_PACRG_AC0_MASK                      0x70000000u
#define AIPS_PACRG_AC0_SHIFT                     28
#define AIPS_PACRG_AC0(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRG_AC0_SHIFT))&AIPS_PACRG_AC0_MASK)
#define AIPS_PACRG_RO0_MASK                      0x80000000u
#define AIPS_PACRG_RO0_SHIFT                     31
/* PACRH Bit Fields */
#define AIPS_PACRH_AC7_MASK                      0x7u
#define AIPS_PACRH_AC7_SHIFT                     0
#define AIPS_PACRH_AC7(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRH_AC7_SHIFT))&AIPS_PACRH_AC7_MASK)
#define AIPS_PACRH_RO7_MASK                      0x8u
#define AIPS_PACRH_RO7_SHIFT                     3
#define AIPS_PACRH_AC6_MASK                      0x70u
#define AIPS_PACRH_AC6_SHIFT                     4
#define AIPS_PACRH_AC6(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRH_AC6_SHIFT))&AIPS_PACRH_AC6_MASK)
#define AIPS_PACRH_RO6_MASK                      0x80u
#define AIPS_PACRH_RO6_SHIFT                     7
#define AIPS_PACRH_AC5_MASK                      0x700u
#define AIPS_PACRH_AC5_SHIFT                     8
#define AIPS_PACRH_AC5(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRH_AC5_SHIFT))&AIPS_PACRH_AC5_MASK)
#define AIPS_PACRH_RO5_MASK                      0x800u
#define AIPS_PACRH_RO5_SHIFT                     11
#define AIPS_PACRH_AC4_MASK                      0x7000u
#define AIPS_PACRH_AC4_SHIFT                     12
#define AIPS_PACRH_AC4(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRH_AC4_SHIFT))&AIPS_PACRH_AC4_MASK)
#define AIPS_PACRH_RO4_MASK                      0x8000u
#define AIPS_PACRH_RO4_SHIFT                     15
#define AIPS_PACRH_AC3_MASK                      0x70000u
#define AIPS_PACRH_AC3_SHIFT                     16
#define AIPS_PACRH_AC3(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRH_AC3_SHIFT))&AIPS_PACRH_AC3_MASK)
#define AIPS_PACRH_RO3_MASK                      0x80000u
#define AIPS_PACRH_RO3_SHIFT                     19
#define AIPS_PACRH_AC2_MASK                      0x700000u
#define AIPS_PACRH_AC2_SHIFT                     20
#define AIPS_PACRH_AC2(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRH_AC2_SHIFT))&AIPS_PACRH_AC2_MASK)
#define AIPS_PACRH_RO2_MASK                      0x800000u
#define AIPS_PACRH_RO2_SHIFT                     23
#define AIPS_PACRH_AC1_MASK                      0x7000000u
#define AIPS_PACRH_AC1_SHIFT                     24
#define AIPS_PACRH_AC1(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRH_AC1_SHIFT))&AIPS_PACRH_AC1_MASK)
#define AIPS_PACRH_RO1_MASK                      0x8000000u
#define AIPS_PACRH_RO1_SHIFT                     27
#define AIPS_PACRH_AC0_MASK                      0x70000000u
#define AIPS_PACRH_AC0_SHIFT                     28
#define AIPS_PACRH_AC0(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRH_AC0_SHIFT))&AIPS_PACRH_AC0_MASK)
#define AIPS_PACRH_RO0_MASK                      0x80000000u
#define AIPS_PACRH_RO0_SHIFT                     31
/* PACRI Bit Fields */
#define AIPS_PACRI_AC7_MASK                      0x7u
#define AIPS_PACRI_AC7_SHIFT                     0
#define AIPS_PACRI_AC7(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRI_AC7_SHIFT))&AIPS_PACRI_AC7_MASK)
#define AIPS_PACRI_RO7_MASK                      0x8u
#define AIPS_PACRI_RO7_SHIFT                     3
#define AIPS_PACRI_AC6_MASK                      0x70u
#define AIPS_PACRI_AC6_SHIFT                     4
#define AIPS_PACRI_AC6(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRI_AC6_SHIFT))&AIPS_PACRI_AC6_MASK)
#define AIPS_PACRI_RO6_MASK                      0x80u
#define AIPS_PACRI_RO6_SHIFT                     7
#define AIPS_PACRI_AC5_MASK                      0x700u
#define AIPS_PACRI_AC5_SHIFT                     8
#define AIPS_PACRI_AC5(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRI_AC5_SHIFT))&AIPS_PACRI_AC5_MASK)
#define AIPS_PACRI_RO5_MASK                      0x800u
#define AIPS_PACRI_RO5_SHIFT                     11
#define AIPS_PACRI_AC4_MASK                      0x7000u
#define AIPS_PACRI_AC4_SHIFT                     12
#define AIPS_PACRI_AC4(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRI_AC4_SHIFT))&AIPS_PACRI_AC4_MASK)
#define AIPS_PACRI_RO4_MASK                      0x8000u
#define AIPS_PACRI_RO4_SHIFT                     15
#define AIPS_PACRI_AC3_MASK                      0x70000u
#define AIPS_PACRI_AC3_SHIFT                     16
#define AIPS_PACRI_AC3(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRI_AC3_SHIFT))&AIPS_PACRI_AC3_MASK)
#define AIPS_PACRI_RO3_MASK                      0x80000u
#define AIPS_PACRI_RO3_SHIFT                     19
#define AIPS_PACRI_AC2_MASK                      0x700000u
#define AIPS_PACRI_AC2_SHIFT                     20
#define AIPS_PACRI_AC2(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRI_AC2_SHIFT))&AIPS_PACRI_AC2_MASK)
#define AIPS_PACRI_RO2_MASK                      0x800000u
#define AIPS_PACRI_RO2_SHIFT                     23
#define AIPS_PACRI_AC1_MASK                      0x7000000u
#define AIPS_PACRI_AC1_SHIFT                     24
#define AIPS_PACRI_AC1(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRI_AC1_SHIFT))&AIPS_PACRI_AC1_MASK)
#define AIPS_PACRI_RO1_MASK                      0x8000000u
#define AIPS_PACRI_RO1_SHIFT                     27
#define AIPS_PACRI_AC0_MASK                      0x70000000u
#define AIPS_PACRI_AC0_SHIFT                     28
#define AIPS_PACRI_AC0(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRI_AC0_SHIFT))&AIPS_PACRI_AC0_MASK)
#define AIPS_PACRI_RO0_MASK                      0x80000000u
#define AIPS_PACRI_RO0_SHIFT                     31
/* PACRJ Bit Fields */
#define AIPS_PACRJ_AC7_MASK                      0x7u
#define AIPS_PACRJ_AC7_SHIFT                     0
#define AIPS_PACRJ_AC7(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRJ_AC7_SHIFT))&AIPS_PACRJ_AC7_MASK)
#define AIPS_PACRJ_RO7_MASK                      0x8u
#define AIPS_PACRJ_RO7_SHIFT                     3
#define AIPS_PACRJ_AC6_MASK                      0x70u
#define AIPS_PACRJ_AC6_SHIFT                     4
#define AIPS_PACRJ_AC6(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRJ_AC6_SHIFT))&AIPS_PACRJ_AC6_MASK)
#define AIPS_PACRJ_RO6_MASK                      0x80u
#define AIPS_PACRJ_RO6_SHIFT                     7
#define AIPS_PACRJ_AC5_MASK                      0x700u
#define AIPS_PACRJ_AC5_SHIFT                     8
#define AIPS_PACRJ_AC5(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRJ_AC5_SHIFT))&AIPS_PACRJ_AC5_MASK)
#define AIPS_PACRJ_RO5_MASK                      0x800u
#define AIPS_PACRJ_RO5_SHIFT                     11
#define AIPS_PACRJ_AC4_MASK                      0x7000u
#define AIPS_PACRJ_AC4_SHIFT                     12
#define AIPS_PACRJ_AC4(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRJ_AC4_SHIFT))&AIPS_PACRJ_AC4_MASK)
#define AIPS_PACRJ_RO4_MASK                      0x8000u
#define AIPS_PACRJ_RO4_SHIFT                     15
#define AIPS_PACRJ_AC3_MASK                      0x70000u
#define AIPS_PACRJ_AC3_SHIFT                     16
#define AIPS_PACRJ_AC3(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRJ_AC3_SHIFT))&AIPS_PACRJ_AC3_MASK)
#define AIPS_PACRJ_RO3_MASK                      0x80000u
#define AIPS_PACRJ_RO3_SHIFT                     19
#define AIPS_PACRJ_AC2_MASK                      0x700000u
#define AIPS_PACRJ_AC2_SHIFT                     20
#define AIPS_PACRJ_AC2(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRJ_AC2_SHIFT))&AIPS_PACRJ_AC2_MASK)
#define AIPS_PACRJ_RO2_MASK                      0x800000u
#define AIPS_PACRJ_RO2_SHIFT                     23
#define AIPS_PACRJ_AC1_MASK                      0x7000000u
#define AIPS_PACRJ_AC1_SHIFT                     24
#define AIPS_PACRJ_AC1(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRJ_AC1_SHIFT))&AIPS_PACRJ_AC1_MASK)
#define AIPS_PACRJ_RO1_MASK                      0x8000000u
#define AIPS_PACRJ_RO1_SHIFT                     27
#define AIPS_PACRJ_AC0_MASK                      0x70000000u
#define AIPS_PACRJ_AC0_SHIFT                     28
#define AIPS_PACRJ_AC0(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRJ_AC0_SHIFT))&AIPS_PACRJ_AC0_MASK)
#define AIPS_PACRJ_RO0_MASK                      0x80000000u
#define AIPS_PACRJ_RO0_SHIFT                     31
/* PACRK Bit Fields */
#define AIPS_PACRK_AC7_MASK                      0x7u
#define AIPS_PACRK_AC7_SHIFT                     0
#define AIPS_PACRK_AC7(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRK_AC7_SHIFT))&AIPS_PACRK_AC7_MASK)
#define AIPS_PACRK_RO7_MASK                      0x8u
#define AIPS_PACRK_RO7_SHIFT                     3
#define AIPS_PACRK_AC6_MASK                      0x70u
#define AIPS_PACRK_AC6_SHIFT                     4
#define AIPS_PACRK_AC6(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRK_AC6_SHIFT))&AIPS_PACRK_AC6_MASK)
#define AIPS_PACRK_RO6_MASK                      0x80u
#define AIPS_PACRK_RO6_SHIFT                     7
#define AIPS_PACRK_AC5_MASK                      0x700u
#define AIPS_PACRK_AC5_SHIFT                     8
#define AIPS_PACRK_AC5(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRK_AC5_SHIFT))&AIPS_PACRK_AC5_MASK)
#define AIPS_PACRK_RO5_MASK                      0x800u
#define AIPS_PACRK_RO5_SHIFT                     11
#define AIPS_PACRK_AC4_MASK                      0x7000u
#define AIPS_PACRK_AC4_SHIFT                     12
#define AIPS_PACRK_AC4(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRK_AC4_SHIFT))&AIPS_PACRK_AC4_MASK)
#define AIPS_PACRK_RO4_MASK                      0x8000u
#define AIPS_PACRK_RO4_SHIFT                     15
#define AIPS_PACRK_AC3_MASK                      0x70000u
#define AIPS_PACRK_AC3_SHIFT                     16
#define AIPS_PACRK_AC3(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRK_AC3_SHIFT))&AIPS_PACRK_AC3_MASK)
#define AIPS_PACRK_RO3_MASK                      0x80000u
#define AIPS_PACRK_RO3_SHIFT                     19
#define AIPS_PACRK_AC2_MASK                      0x700000u
#define AIPS_PACRK_AC2_SHIFT                     20
#define AIPS_PACRK_AC2(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRK_AC2_SHIFT))&AIPS_PACRK_AC2_MASK)
#define AIPS_PACRK_RO2_MASK                      0x800000u
#define AIPS_PACRK_RO2_SHIFT                     23
#define AIPS_PACRK_AC1_MASK                      0x7000000u
#define AIPS_PACRK_AC1_SHIFT                     24
#define AIPS_PACRK_AC1(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRK_AC1_SHIFT))&AIPS_PACRK_AC1_MASK)
#define AIPS_PACRK_RO1_MASK                      0x8000000u
#define AIPS_PACRK_RO1_SHIFT                     27
#define AIPS_PACRK_AC0_MASK                      0x70000000u
#define AIPS_PACRK_AC0_SHIFT                     28
#define AIPS_PACRK_AC0(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRK_AC0_SHIFT))&AIPS_PACRK_AC0_MASK)
#define AIPS_PACRK_RO0_MASK                      0x80000000u
#define AIPS_PACRK_RO0_SHIFT                     31
/* PACRL Bit Fields */
#define AIPS_PACRL_AC7_MASK                      0x7u
#define AIPS_PACRL_AC7_SHIFT                     0
#define AIPS_PACRL_AC7(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRL_AC7_SHIFT))&AIPS_PACRL_AC7_MASK)
#define AIPS_PACRL_RO7_MASK                      0x8u
#define AIPS_PACRL_RO7_SHIFT                     3
#define AIPS_PACRL_AC6_MASK                      0x70u
#define AIPS_PACRL_AC6_SHIFT                     4
#define AIPS_PACRL_AC6(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRL_AC6_SHIFT))&AIPS_PACRL_AC6_MASK)
#define AIPS_PACRL_RO6_MASK                      0x80u
#define AIPS_PACRL_RO6_SHIFT                     7
#define AIPS_PACRL_AC5_MASK                      0x700u
#define AIPS_PACRL_AC5_SHIFT                     8
#define AIPS_PACRL_AC5(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRL_AC5_SHIFT))&AIPS_PACRL_AC5_MASK)
#define AIPS_PACRL_RO5_MASK                      0x800u
#define AIPS_PACRL_RO5_SHIFT                     11
#define AIPS_PACRL_AC4_MASK                      0x7000u
#define AIPS_PACRL_AC4_SHIFT                     12
#define AIPS_PACRL_AC4(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRL_AC4_SHIFT))&AIPS_PACRL_AC4_MASK)
#define AIPS_PACRL_RO4_MASK                      0x8000u
#define AIPS_PACRL_RO4_SHIFT                     15
#define AIPS_PACRL_AC3_MASK                      0x70000u
#define AIPS_PACRL_AC3_SHIFT                     16
#define AIPS_PACRL_AC3(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRL_AC3_SHIFT))&AIPS_PACRL_AC3_MASK)
#define AIPS_PACRL_RO3_MASK                      0x80000u
#define AIPS_PACRL_RO3_SHIFT                     19
#define AIPS_PACRL_AC2_MASK                      0x700000u
#define AIPS_PACRL_AC2_SHIFT                     20
#define AIPS_PACRL_AC2(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRL_AC2_SHIFT))&AIPS_PACRL_AC2_MASK)
#define AIPS_PACRL_RO2_MASK                      0x800000u
#define AIPS_PACRL_RO2_SHIFT                     23
#define AIPS_PACRL_AC1_MASK                      0x7000000u
#define AIPS_PACRL_AC1_SHIFT                     24
#define AIPS_PACRL_AC1(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRL_AC1_SHIFT))&AIPS_PACRL_AC1_MASK)
#define AIPS_PACRL_RO1_MASK                      0x8000000u
#define AIPS_PACRL_RO1_SHIFT                     27
#define AIPS_PACRL_AC0_MASK                      0x70000000u
#define AIPS_PACRL_AC0_SHIFT                     28
#define AIPS_PACRL_AC0(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRL_AC0_SHIFT))&AIPS_PACRL_AC0_MASK)
#define AIPS_PACRL_RO0_MASK                      0x80000000u
#define AIPS_PACRL_RO0_SHIFT                     31
/* PACRM Bit Fields */
#define AIPS_PACRM_AC7_MASK                      0x7u
#define AIPS_PACRM_AC7_SHIFT                     0
#define AIPS_PACRM_AC7(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRM_AC7_SHIFT))&AIPS_PACRM_AC7_MASK)
#define AIPS_PACRM_RO7_MASK                      0x8u
#define AIPS_PACRM_RO7_SHIFT                     3
#define AIPS_PACRM_AC6_MASK                      0x70u
#define AIPS_PACRM_AC6_SHIFT                     4
#define AIPS_PACRM_AC6(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRM_AC6_SHIFT))&AIPS_PACRM_AC6_MASK)
#define AIPS_PACRM_RO6_MASK                      0x80u
#define AIPS_PACRM_RO6_SHIFT                     7
#define AIPS_PACRM_AC5_MASK                      0x700u
#define AIPS_PACRM_AC5_SHIFT                     8
#define AIPS_PACRM_AC5(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRM_AC5_SHIFT))&AIPS_PACRM_AC5_MASK)
#define AIPS_PACRM_RO5_MASK                      0x800u
#define AIPS_PACRM_RO5_SHIFT                     11
#define AIPS_PACRM_AC4_MASK                      0x7000u
#define AIPS_PACRM_AC4_SHIFT                     12
#define AIPS_PACRM_AC4(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRM_AC4_SHIFT))&AIPS_PACRM_AC4_MASK)
#define AIPS_PACRM_RO4_MASK                      0x8000u
#define AIPS_PACRM_RO4_SHIFT                     15
#define AIPS_PACRM_AC3_MASK                      0x70000u
#define AIPS_PACRM_AC3_SHIFT                     16
#define AIPS_PACRM_AC3(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRM_AC3_SHIFT))&AIPS_PACRM_AC3_MASK)
#define AIPS_PACRM_RO3_MASK                      0x80000u
#define AIPS_PACRM_RO3_SHIFT                     19
#define AIPS_PACRM_AC2_MASK                      0x700000u
#define AIPS_PACRM_AC2_SHIFT                     20
#define AIPS_PACRM_AC2(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRM_AC2_SHIFT))&AIPS_PACRM_AC2_MASK)
#define AIPS_PACRM_RO2_MASK                      0x800000u
#define AIPS_PACRM_RO2_SHIFT                     23
#define AIPS_PACRM_AC1_MASK                      0x7000000u
#define AIPS_PACRM_AC1_SHIFT                     24
#define AIPS_PACRM_AC1(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRM_AC1_SHIFT))&AIPS_PACRM_AC1_MASK)
#define AIPS_PACRM_RO1_MASK                      0x8000000u
#define AIPS_PACRM_RO1_SHIFT                     27
#define AIPS_PACRM_AC0_MASK                      0x70000000u
#define AIPS_PACRM_AC0_SHIFT                     28
#define AIPS_PACRM_AC0(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRM_AC0_SHIFT))&AIPS_PACRM_AC0_MASK)
#define AIPS_PACRM_RO0_MASK                      0x80000000u
#define AIPS_PACRM_RO0_SHIFT                     31
/* PACRN Bit Fields */
#define AIPS_PACRN_AC7_MASK                      0x7u
#define AIPS_PACRN_AC7_SHIFT                     0
#define AIPS_PACRN_AC7(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRN_AC7_SHIFT))&AIPS_PACRN_AC7_MASK)
#define AIPS_PACRN_RO7_MASK                      0x8u
#define AIPS_PACRN_RO7_SHIFT                     3
#define AIPS_PACRN_AC6_MASK                      0x70u
#define AIPS_PACRN_AC6_SHIFT                     4
#define AIPS_PACRN_AC6(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRN_AC6_SHIFT))&AIPS_PACRN_AC6_MASK)
#define AIPS_PACRN_RO6_MASK                      0x80u
#define AIPS_PACRN_RO6_SHIFT                     7
#define AIPS_PACRN_AC5_MASK                      0x700u
#define AIPS_PACRN_AC5_SHIFT                     8
#define AIPS_PACRN_AC5(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRN_AC5_SHIFT))&AIPS_PACRN_AC5_MASK)
#define AIPS_PACRN_RO5_MASK                      0x800u
#define AIPS_PACRN_RO5_SHIFT                     11
#define AIPS_PACRN_AC4_MASK                      0x7000u
#define AIPS_PACRN_AC4_SHIFT                     12
#define AIPS_PACRN_AC4(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRN_AC4_SHIFT))&AIPS_PACRN_AC4_MASK)
#define AIPS_PACRN_RO4_MASK                      0x8000u
#define AIPS_PACRN_RO4_SHIFT                     15
#define AIPS_PACRN_AC3_MASK                      0x70000u
#define AIPS_PACRN_AC3_SHIFT                     16
#define AIPS_PACRN_AC3(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRN_AC3_SHIFT))&AIPS_PACRN_AC3_MASK)
#define AIPS_PACRN_RO3_MASK                      0x80000u
#define AIPS_PACRN_RO3_SHIFT                     19
#define AIPS_PACRN_AC2_MASK                      0x700000u
#define AIPS_PACRN_AC2_SHIFT                     20
#define AIPS_PACRN_AC2(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRN_AC2_SHIFT))&AIPS_PACRN_AC2_MASK)
#define AIPS_PACRN_RO2_MASK                      0x800000u
#define AIPS_PACRN_RO2_SHIFT                     23
#define AIPS_PACRN_AC1_MASK                      0x7000000u
#define AIPS_PACRN_AC1_SHIFT                     24
#define AIPS_PACRN_AC1(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRN_AC1_SHIFT))&AIPS_PACRN_AC1_MASK)
#define AIPS_PACRN_RO1_MASK                      0x8000000u
#define AIPS_PACRN_RO1_SHIFT                     27
#define AIPS_PACRN_AC0_MASK                      0x70000000u
#define AIPS_PACRN_AC0_SHIFT                     28
#define AIPS_PACRN_AC0(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRN_AC0_SHIFT))&AIPS_PACRN_AC0_MASK)
#define AIPS_PACRN_RO0_MASK                      0x80000000u
#define AIPS_PACRN_RO0_SHIFT                     31
/* PACRO Bit Fields */
#define AIPS_PACRO_AC7_MASK                      0x7u
#define AIPS_PACRO_AC7_SHIFT                     0
#define AIPS_PACRO_AC7(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRO_AC7_SHIFT))&AIPS_PACRO_AC7_MASK)
#define AIPS_PACRO_RO7_MASK                      0x8u
#define AIPS_PACRO_RO7_SHIFT                     3
#define AIPS_PACRO_AC6_MASK                      0x70u
#define AIPS_PACRO_AC6_SHIFT                     4
#define AIPS_PACRO_AC6(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRO_AC6_SHIFT))&AIPS_PACRO_AC6_MASK)
#define AIPS_PACRO_RO6_MASK                      0x80u
#define AIPS_PACRO_RO6_SHIFT                     7
#define AIPS_PACRO_AC5_MASK                      0x700u
#define AIPS_PACRO_AC5_SHIFT                     8
#define AIPS_PACRO_AC5(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRO_AC5_SHIFT))&AIPS_PACRO_AC5_MASK)
#define AIPS_PACRO_RO5_MASK                      0x800u
#define AIPS_PACRO_RO5_SHIFT                     11
#define AIPS_PACRO_AC4_MASK                      0x7000u
#define AIPS_PACRO_AC4_SHIFT                     12
#define AIPS_PACRO_AC4(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRO_AC4_SHIFT))&AIPS_PACRO_AC4_MASK)
#define AIPS_PACRO_RO4_MASK                      0x8000u
#define AIPS_PACRO_RO4_SHIFT                     15
#define AIPS_PACRO_AC3_MASK                      0x70000u
#define AIPS_PACRO_AC3_SHIFT                     16
#define AIPS_PACRO_AC3(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRO_AC3_SHIFT))&AIPS_PACRO_AC3_MASK)
#define AIPS_PACRO_RO3_MASK                      0x80000u
#define AIPS_PACRO_RO3_SHIFT                     19
#define AIPS_PACRO_AC2_MASK                      0x700000u
#define AIPS_PACRO_AC2_SHIFT                     20
#define AIPS_PACRO_AC2(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRO_AC2_SHIFT))&AIPS_PACRO_AC2_MASK)
#define AIPS_PACRO_RO2_MASK                      0x800000u
#define AIPS_PACRO_RO2_SHIFT                     23
#define AIPS_PACRO_AC1_MASK                      0x7000000u
#define AIPS_PACRO_AC1_SHIFT                     24
#define AIPS_PACRO_AC1(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRO_AC1_SHIFT))&AIPS_PACRO_AC1_MASK)
#define AIPS_PACRO_RO1_MASK                      0x8000000u
#define AIPS_PACRO_RO1_SHIFT                     27
#define AIPS_PACRO_AC0_MASK                      0x70000000u
#define AIPS_PACRO_AC0_SHIFT                     28
#define AIPS_PACRO_AC0(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRO_AC0_SHIFT))&AIPS_PACRO_AC0_MASK)
#define AIPS_PACRO_RO0_MASK                      0x80000000u
#define AIPS_PACRO_RO0_SHIFT                     31
/* PACRP Bit Fields */
#define AIPS_PACRP_AC7_MASK                      0x7u
#define AIPS_PACRP_AC7_SHIFT                     0
#define AIPS_PACRP_AC7(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRP_AC7_SHIFT))&AIPS_PACRP_AC7_MASK)
#define AIPS_PACRP_RO7_MASK                      0x8u
#define AIPS_PACRP_RO7_SHIFT                     3
#define AIPS_PACRP_AC6_MASK                      0x70u
#define AIPS_PACRP_AC6_SHIFT                     4
#define AIPS_PACRP_AC6(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRP_AC6_SHIFT))&AIPS_PACRP_AC6_MASK)
#define AIPS_PACRP_RO6_MASK                      0x80u
#define AIPS_PACRP_RO6_SHIFT                     7
#define AIPS_PACRP_AC5_MASK                      0x700u
#define AIPS_PACRP_AC5_SHIFT                     8
#define AIPS_PACRP_AC5(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRP_AC5_SHIFT))&AIPS_PACRP_AC5_MASK)
#define AIPS_PACRP_RO5_MASK                      0x800u
#define AIPS_PACRP_RO5_SHIFT                     11
#define AIPS_PACRP_AC4_MASK                      0x7000u
#define AIPS_PACRP_AC4_SHIFT                     12
#define AIPS_PACRP_AC4(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRP_AC4_SHIFT))&AIPS_PACRP_AC4_MASK)
#define AIPS_PACRP_RO4_MASK                      0x8000u
#define AIPS_PACRP_RO4_SHIFT                     15
#define AIPS_PACRP_AC3_MASK                      0x70000u
#define AIPS_PACRP_AC3_SHIFT                     16
#define AIPS_PACRP_AC3(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRP_AC3_SHIFT))&AIPS_PACRP_AC3_MASK)
#define AIPS_PACRP_RO3_MASK                      0x80000u
#define AIPS_PACRP_RO3_SHIFT                     19
#define AIPS_PACRP_AC2_MASK                      0x700000u
#define AIPS_PACRP_AC2_SHIFT                     20
#define AIPS_PACRP_AC2(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRP_AC2_SHIFT))&AIPS_PACRP_AC2_MASK)
#define AIPS_PACRP_RO2_MASK                      0x800000u
#define AIPS_PACRP_RO2_SHIFT                     23
#define AIPS_PACRP_AC1_MASK                      0x7000000u
#define AIPS_PACRP_AC1_SHIFT                     24
#define AIPS_PACRP_AC1(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRP_AC1_SHIFT))&AIPS_PACRP_AC1_MASK)
#define AIPS_PACRP_RO1_MASK                      0x8000000u
#define AIPS_PACRP_RO1_SHIFT                     27
#define AIPS_PACRP_AC0_MASK                      0x70000000u
#define AIPS_PACRP_AC0_SHIFT                     28
#define AIPS_PACRP_AC0(x)                        (((uint32_t)(((uint32_t)(x))<<AIPS_PACRP_AC0_SHIFT))&AIPS_PACRP_AC0_MASK)
#define AIPS_PACRP_RO0_MASK                      0x80000000u
#define AIPS_PACRP_RO0_SHIFT                     31

/*!
 * @}
 */ /* end of group AIPS_Register_Masks */


/* AIPS - Peripheral instance base addresses */
/** Peripheral AIPS base address */
#define AIPS_BASE                                (0x40000000u)
/** Peripheral AIPS base pointer */
#define AIPS                                     ((AIPS_Type *)AIPS_BASE)
/** Array initializer of AIPS peripheral base pointers */
#define AIPS_BASES                               { AIPS }

/*!
 * @}
 */ /* end of group AIPS_Peripheral_Access_Layer */


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
} CMP_Type;

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
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_CR0_HYSTCTR_SHIFT))&CMP_CR0_HYSTCTR_MASK)
#define CMP_CR0_FILTER_CNT_MASK                  0x70u
#define CMP_CR0_FILTER_CNT_SHIFT                 4
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x))<<CMP_CR0_FILTER_CNT_SHIFT))&CMP_CR0_FILTER_CNT_MASK)
/* CR1 Bit Fields */
#define CMP_CR1_EN_MASK                          0x1u
#define CMP_CR1_EN_SHIFT                         0
#define CMP_CR1_OPE_MASK                         0x2u
#define CMP_CR1_OPE_SHIFT                        1
#define CMP_CR1_COS_MASK                         0x4u
#define CMP_CR1_COS_SHIFT                        2
#define CMP_CR1_INV_MASK                         0x8u
#define CMP_CR1_INV_SHIFT                        3
#define CMP_CR1_PMODE_MASK                       0x10u
#define CMP_CR1_PMODE_SHIFT                      4
#define CMP_CR1_TRIGM_MASK                       0x20u
#define CMP_CR1_TRIGM_SHIFT                      5
#define CMP_CR1_WE_MASK                          0x40u
#define CMP_CR1_WE_SHIFT                         6
#define CMP_CR1_SE_MASK                          0x80u
#define CMP_CR1_SE_SHIFT                         7
/* FPR Bit Fields */
#define CMP_FPR_FILT_PER_MASK                    0xFFu
#define CMP_FPR_FILT_PER_SHIFT                   0
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x))<<CMP_FPR_FILT_PER_SHIFT))&CMP_FPR_FILT_PER_MASK)
/* SCR Bit Fields */
#define CMP_SCR_COUT_MASK                        0x1u
#define CMP_SCR_COUT_SHIFT                       0
#define CMP_SCR_CFF_MASK                         0x2u
#define CMP_SCR_CFF_SHIFT                        1
#define CMP_SCR_CFR_MASK                         0x4u
#define CMP_SCR_CFR_SHIFT                        2
#define CMP_SCR_IEF_MASK                         0x8u
#define CMP_SCR_IEF_SHIFT                        3
#define CMP_SCR_IER_MASK                         0x10u
#define CMP_SCR_IER_SHIFT                        4
#define CMP_SCR_DMAEN_MASK                       0x40u
#define CMP_SCR_DMAEN_SHIFT                      6
/* DACCR Bit Fields */
#define CMP_DACCR_VOSEL_MASK                     0x3Fu
#define CMP_DACCR_VOSEL_SHIFT                    0
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VOSEL_SHIFT))&CMP_DACCR_VOSEL_MASK)
#define CMP_DACCR_VRSEL_MASK                     0x40u
#define CMP_DACCR_VRSEL_SHIFT                    6
#define CMP_DACCR_DACEN_MASK                     0x80u
#define CMP_DACCR_DACEN_SHIFT                    7
/* MUXCR Bit Fields */
#define CMP_MUXCR_MSEL_MASK                      0x7u
#define CMP_MUXCR_MSEL_SHIFT                     0
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_MSEL_SHIFT))&CMP_MUXCR_MSEL_MASK)
#define CMP_MUXCR_PSEL_MASK                      0x38u
#define CMP_MUXCR_PSEL_SHIFT                     3
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSEL_SHIFT))&CMP_MUXCR_PSEL_MASK)

/*!
 * @}
 */ /* end of group CMP_Register_Masks */


/* CMP - Peripheral instance base addresses */
/** Peripheral CMP0 base address */
#define CMP0_BASE                                (0x40072000u)
/** Peripheral CMP0 base pointer */
#define CMP0                                     ((CMP_Type *)CMP0_BASE)
/** Peripheral CMP1 base address */
#define CMP1_BASE                                (0x40072008u)
/** Peripheral CMP1 base pointer */
#define CMP1                                     ((CMP_Type *)CMP1_BASE)
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASES                                { CMP0, CMP1 }

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
} CRC_Type;

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
#define CRC_DATAL_DATAL(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAL_DATAL_SHIFT))&CRC_DATAL_DATAL_MASK)
/* DATAH Bit Fields */
#define CRC_DATAH_DATAH_MASK                     0xFFFFu
#define CRC_DATAH_DATAH_SHIFT                    0
#define CRC_DATAH_DATAH(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAH_DATAH_SHIFT))&CRC_DATAH_DATAH_MASK)
/* DATA Bit Fields */
#define CRC_DATA_LL_MASK                         0xFFu
#define CRC_DATA_LL_SHIFT                        0
#define CRC_DATA_LL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LL_SHIFT))&CRC_DATA_LL_MASK)
#define CRC_DATA_LU_MASK                         0xFF00u
#define CRC_DATA_LU_SHIFT                        8
#define CRC_DATA_LU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LU_SHIFT))&CRC_DATA_LU_MASK)
#define CRC_DATA_HL_MASK                         0xFF0000u
#define CRC_DATA_HL_SHIFT                        16
#define CRC_DATA_HL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HL_SHIFT))&CRC_DATA_HL_MASK)
#define CRC_DATA_HU_MASK                         0xFF000000u
#define CRC_DATA_HU_SHIFT                        24
#define CRC_DATA_HU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HU_SHIFT))&CRC_DATA_HU_MASK)
/* DATALL Bit Fields */
#define CRC_DATALL_DATALL_MASK                   0xFFu
#define CRC_DATALL_DATALL_SHIFT                  0
#define CRC_DATALL_DATALL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALL_DATALL_SHIFT))&CRC_DATALL_DATALL_MASK)
/* DATALU Bit Fields */
#define CRC_DATALU_DATALU_MASK                   0xFFu
#define CRC_DATALU_DATALU_SHIFT                  0
#define CRC_DATALU_DATALU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALU_DATALU_SHIFT))&CRC_DATALU_DATALU_MASK)
/* DATAHL Bit Fields */
#define CRC_DATAHL_DATAHL_MASK                   0xFFu
#define CRC_DATAHL_DATAHL_SHIFT                  0
#define CRC_DATAHL_DATAHL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHL_DATAHL_SHIFT))&CRC_DATAHL_DATAHL_MASK)
/* DATAHU Bit Fields */
#define CRC_DATAHU_DATAHU_MASK                   0xFFu
#define CRC_DATAHU_DATAHU_SHIFT                  0
#define CRC_DATAHU_DATAHU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHU_DATAHU_SHIFT))&CRC_DATAHU_DATAHU_MASK)
/* GPOLYL Bit Fields */
#define CRC_GPOLYL_GPOLYL_MASK                   0xFFFFu
#define CRC_GPOLYL_GPOLYL_SHIFT                  0
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYL_GPOLYL_SHIFT))&CRC_GPOLYL_GPOLYL_MASK)
/* GPOLYH Bit Fields */
#define CRC_GPOLYH_GPOLYH_MASK                   0xFFFFu
#define CRC_GPOLYH_GPOLYH_SHIFT                  0
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYH_GPOLYH_SHIFT))&CRC_GPOLYH_GPOLYH_MASK)
/* GPOLY Bit Fields */
#define CRC_GPOLY_LOW_MASK                       0xFFFFu
#define CRC_GPOLY_LOW_SHIFT                      0
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_LOW_SHIFT))&CRC_GPOLY_LOW_MASK)
#define CRC_GPOLY_HIGH_MASK                      0xFFFF0000u
#define CRC_GPOLY_HIGH_SHIFT                     16
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_HIGH_SHIFT))&CRC_GPOLY_HIGH_MASK)
/* GPOLYLL Bit Fields */
#define CRC_GPOLYLL_GPOLYLL_MASK                 0xFFu
#define CRC_GPOLYLL_GPOLYLL_SHIFT                0
#define CRC_GPOLYLL_GPOLYLL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLL_GPOLYLL_SHIFT))&CRC_GPOLYLL_GPOLYLL_MASK)
/* GPOLYLU Bit Fields */
#define CRC_GPOLYLU_GPOLYLU_MASK                 0xFFu
#define CRC_GPOLYLU_GPOLYLU_SHIFT                0
#define CRC_GPOLYLU_GPOLYLU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLU_GPOLYLU_SHIFT))&CRC_GPOLYLU_GPOLYLU_MASK)
/* GPOLYHL Bit Fields */
#define CRC_GPOLYHL_GPOLYHL_MASK                 0xFFu
#define CRC_GPOLYHL_GPOLYHL_SHIFT                0
#define CRC_GPOLYHL_GPOLYHL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHL_GPOLYHL_SHIFT))&CRC_GPOLYHL_GPOLYHL_MASK)
/* GPOLYHU Bit Fields */
#define CRC_GPOLYHU_GPOLYHU_MASK                 0xFFu
#define CRC_GPOLYHU_GPOLYHU_SHIFT                0
#define CRC_GPOLYHU_GPOLYHU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHU_GPOLYHU_SHIFT))&CRC_GPOLYHU_GPOLYHU_MASK)
/* CTRL Bit Fields */
#define CRC_CTRL_TCRC_MASK                       0x1000000u
#define CRC_CTRL_TCRC_SHIFT                      24
#define CRC_CTRL_WAS_MASK                        0x2000000u
#define CRC_CTRL_WAS_SHIFT                       25
#define CRC_CTRL_FXOR_MASK                       0x4000000u
#define CRC_CTRL_FXOR_SHIFT                      26
#define CRC_CTRL_TOTR_MASK                       0x30000000u
#define CRC_CTRL_TOTR_SHIFT                      28
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOTR_SHIFT))&CRC_CTRL_TOTR_MASK)
#define CRC_CTRL_TOT_MASK                        0xC0000000u
#define CRC_CTRL_TOT_SHIFT                       30
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOT_SHIFT))&CRC_CTRL_TOT_MASK)
/* CTRLHU Bit Fields */
#define CRC_CTRLHU_TCRC_MASK                     0x1u
#define CRC_CTRLHU_TCRC_SHIFT                    0
#define CRC_CTRLHU_WAS_MASK                      0x2u
#define CRC_CTRLHU_WAS_SHIFT                     1
#define CRC_CTRLHU_FXOR_MASK                     0x4u
#define CRC_CTRLHU_FXOR_SHIFT                    2
#define CRC_CTRLHU_TOTR_MASK                     0x30u
#define CRC_CTRLHU_TOTR_SHIFT                    4
#define CRC_CTRLHU_TOTR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOTR_SHIFT))&CRC_CTRLHU_TOTR_MASK)
#define CRC_CTRLHU_TOT_MASK                      0xC0u
#define CRC_CTRLHU_TOT_SHIFT                     6
#define CRC_CTRLHU_TOT(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOT_SHIFT))&CRC_CTRLHU_TOT_MASK)

/*!
 * @}
 */ /* end of group CRC_Register_Masks */


/* CRC - Peripheral instance base addresses */
/** Peripheral CRC base address */
#define CRC_BASE                                 (0x40034000u)
/** Peripheral CRC base pointer */
#define CRC0                                     ((CRC_Type *)CRC_BASE)
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASES                                { CRC0 }

/*!
 * @}
 */ /* end of group CRC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[256];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    __IO uint32_t SAR;                               /**< Source Address Register, array offset: 0x100, array step: 0x10 */
    __IO uint32_t DAR;                               /**< Destination Address Register, array offset: 0x104, array step: 0x10 */
    union {                                          /* offset: 0x108, array step: 0x10 */
      __IO uint32_t DSR_BCR;                           /**< DMA Status Register / Byte Count Register, array offset: 0x108, array step: 0x10 */
      struct {                                         /* offset: 0x108, array step: 0x10 */
             uint8_t RESERVED_0[3];
        __IO uint8_t DSR;                                /**< DMA_DSR0 register...DMA_DSR3 register., array offset: 0x10B, array step: 0x10 */
      } DMA_DSR_ACCESS8BIT;
    };
    __IO uint32_t DCR;                               /**< DMA Control Register, array offset: 0x10C, array step: 0x10 */
  } DMA[4];
} DMA_Type;

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/* SAR Bit Fields */
#define DMA_SAR_SAR_MASK                         0xFFFFFFFFu
#define DMA_SAR_SAR_SHIFT                        0
#define DMA_SAR_SAR(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_SAR_SAR_SHIFT))&DMA_SAR_SAR_MASK)
/* DAR Bit Fields */
#define DMA_DAR_DAR_MASK                         0xFFFFFFFFu
#define DMA_DAR_DAR_SHIFT                        0
#define DMA_DAR_DAR(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_DAR_DAR_SHIFT))&DMA_DAR_DAR_MASK)
/* DSR_BCR Bit Fields */
#define DMA_DSR_BCR_BCR_MASK                     0xFFFFFFu
#define DMA_DSR_BCR_BCR_SHIFT                    0
#define DMA_DSR_BCR_BCR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_BCR_SHIFT))&DMA_DSR_BCR_BCR_MASK)
#define DMA_DSR_BCR_DONE_MASK                    0x1000000u
#define DMA_DSR_BCR_DONE_SHIFT                   24
#define DMA_DSR_BCR_BSY_MASK                     0x2000000u
#define DMA_DSR_BCR_BSY_SHIFT                    25
#define DMA_DSR_BCR_REQ_MASK                     0x4000000u
#define DMA_DSR_BCR_REQ_SHIFT                    26
#define DMA_DSR_BCR_BED_MASK                     0x10000000u
#define DMA_DSR_BCR_BED_SHIFT                    28
#define DMA_DSR_BCR_BES_MASK                     0x20000000u
#define DMA_DSR_BCR_BES_SHIFT                    29
#define DMA_DSR_BCR_CE_MASK                      0x40000000u
#define DMA_DSR_BCR_CE_SHIFT                     30
/* DCR Bit Fields */
#define DMA_DCR_LCH2_MASK                        0x3u
#define DMA_DCR_LCH2_SHIFT                       0
#define DMA_DCR_LCH2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH2_SHIFT))&DMA_DCR_LCH2_MASK)
#define DMA_DCR_LCH1_MASK                        0xCu
#define DMA_DCR_LCH1_SHIFT                       2
#define DMA_DCR_LCH1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH1_SHIFT))&DMA_DCR_LCH1_MASK)
#define DMA_DCR_LINKCC_MASK                      0x30u
#define DMA_DCR_LINKCC_SHIFT                     4
#define DMA_DCR_LINKCC(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LINKCC_SHIFT))&DMA_DCR_LINKCC_MASK)
#define DMA_DCR_D_REQ_MASK                       0x80u
#define DMA_DCR_D_REQ_SHIFT                      7
#define DMA_DCR_DMOD_MASK                        0xF00u
#define DMA_DCR_DMOD_SHIFT                       8
#define DMA_DCR_DMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DMOD_SHIFT))&DMA_DCR_DMOD_MASK)
#define DMA_DCR_SMOD_MASK                        0xF000u
#define DMA_DCR_SMOD_SHIFT                       12
#define DMA_DCR_SMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SMOD_SHIFT))&DMA_DCR_SMOD_MASK)
#define DMA_DCR_START_MASK                       0x10000u
#define DMA_DCR_START_SHIFT                      16
#define DMA_DCR_DSIZE_MASK                       0x60000u
#define DMA_DCR_DSIZE_SHIFT                      17
#define DMA_DCR_DSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DSIZE_SHIFT))&DMA_DCR_DSIZE_MASK)
#define DMA_DCR_DINC_MASK                        0x80000u
#define DMA_DCR_DINC_SHIFT                       19
#define DMA_DCR_SSIZE_MASK                       0x300000u
#define DMA_DCR_SSIZE_SHIFT                      20
#define DMA_DCR_SSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SSIZE_SHIFT))&DMA_DCR_SSIZE_MASK)
#define DMA_DCR_SINC_MASK                        0x400000u
#define DMA_DCR_SINC_SHIFT                       22
#define DMA_DCR_EADREQ_MASK                      0x800000u
#define DMA_DCR_EADREQ_SHIFT                     23
#define DMA_DCR_UMNSM_MASK                       0x3000000u
#define DMA_DCR_UMNSM_SHIFT                      24
#define DMA_DCR_UMNSM(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_UMNSM_SHIFT))&DMA_DCR_UMNSM_MASK)
#define DMA_DCR_CHACR_MASK                       0xC000000u
#define DMA_DCR_CHACR_SHIFT                      26
#define DMA_DCR_CHACR(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_CHACR_SHIFT))&DMA_DCR_CHACR_MASK)
#define DMA_DCR_AA_MASK                          0x10000000u
#define DMA_DCR_AA_SHIFT                         28
#define DMA_DCR_CS_MASK                          0x20000000u
#define DMA_DCR_CS_SHIFT                         29
#define DMA_DCR_ERQ_MASK                         0x40000000u
#define DMA_DCR_ERQ_SHIFT                        30
#define DMA_DCR_EINT_MASK                        0x80000000u
#define DMA_DCR_EINT_SHIFT                       31

/*!
 * @}
 */ /* end of group DMA_Register_Masks */


/* DMA - Peripheral instance base addresses */
/** Peripheral DMA base address */
#define DMA_BASE                                 (0x40008000u)
/** Peripheral DMA base pointer */
#define DMA0                                     ((DMA_Type *)DMA_BASE)
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASES                                { DMA0 }

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
  __IO uint8_t CHCFG;                              /**< Channel Configuration register, offset: 0x0 */
} DMAMUX_Type;

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
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_SOURCE_SHIFT))&DMAMUX_CHCFG_SOURCE_MASK)
#define DMAMUX_CHCFG_TRIG_MASK                   0x40u
#define DMAMUX_CHCFG_TRIG_SHIFT                  6
#define DMAMUX_CHCFG_ENBL_MASK                   0x80u
#define DMAMUX_CHCFG_ENBL_SHIFT                  7

/*!
 * @}
 */ /* end of group DMAMUX_Register_Masks */


/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX0 base address */
#define DMAMUX0_BASE                             (0x40021000u)
/** Peripheral DMAMUX0 base pointer */
#define DMAMUX0                                  ((DMAMUX_Type *)DMAMUX0_BASE)
/** Peripheral DMAMUX1 base address */
#define DMAMUX1_BASE                             (0x40022000u)
/** Peripheral DMAMUX1 base pointer */
#define DMAMUX1                                  ((DMAMUX_Type *)DMAMUX1_BASE)
/** Peripheral DMAMUX2 base address */
#define DMAMUX2_BASE                             (0x40023000u)
/** Peripheral DMAMUX2 base pointer */
#define DMAMUX2                                  ((DMAMUX_Type *)DMAMUX2_BASE)
/** Peripheral DMAMUX3 base address */
#define DMAMUX3_BASE                             (0x40024000u)
/** Peripheral DMAMUX3 base pointer */
#define DMAMUX3                                  ((DMAMUX_Type *)DMAMUX3_BASE)
/** Array initializer of DMAMUX peripheral base pointers */
#define DMAMUX_BASES                             { DMAMUX0, DMAMUX1, DMAMUX2, DMAMUX3 }

/*!
 * @}
 */ /* end of group DMAMUX_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- EWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Peripheral_Access_Layer EWM Peripheral Access Layer
 * @{
 */

/** EWM - Register Layout Typedef */
typedef struct {
  __IO uint8_t CTRL;                               /**< Control Register, offset: 0x0 */
  __O  uint8_t SERV;                               /**< Service Register, offset: 0x1 */
  __IO uint8_t CMPL;                               /**< Compare Low Register, offset: 0x2 */
  __IO uint8_t CMPH;                               /**< Compare High Register, offset: 0x3 */
} EWM_Type;

/* ----------------------------------------------------------------------------
   -- EWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Register_Masks EWM Register Masks
 * @{
 */

/* CTRL Bit Fields */
#define EWM_CTRL_EWMEN_MASK                      0x1u
#define EWM_CTRL_EWMEN_SHIFT                     0
#define EWM_CTRL_ASSIN_MASK                      0x2u
#define EWM_CTRL_ASSIN_SHIFT                     1
#define EWM_CTRL_INEN_MASK                       0x4u
#define EWM_CTRL_INEN_SHIFT                      2
#define EWM_CTRL_INTEN_MASK                      0x8u
#define EWM_CTRL_INTEN_SHIFT                     3
/* SERV Bit Fields */
#define EWM_SERV_SERVICE_MASK                    0xFFu
#define EWM_SERV_SERVICE_SHIFT                   0
#define EWM_SERV_SERVICE(x)                      (((uint8_t)(((uint8_t)(x))<<EWM_SERV_SERVICE_SHIFT))&EWM_SERV_SERVICE_MASK)
/* CMPL Bit Fields */
#define EWM_CMPL_COMPAREL_MASK                   0xFFu
#define EWM_CMPL_COMPAREL_SHIFT                  0
#define EWM_CMPL_COMPAREL(x)                     (((uint8_t)(((uint8_t)(x))<<EWM_CMPL_COMPAREL_SHIFT))&EWM_CMPL_COMPAREL_MASK)
/* CMPH Bit Fields */
#define EWM_CMPH_COMPAREH_MASK                   0xFFu
#define EWM_CMPH_COMPAREH_SHIFT                  0
#define EWM_CMPH_COMPAREH(x)                     (((uint8_t)(((uint8_t)(x))<<EWM_CMPH_COMPAREH_SHIFT))&EWM_CMPH_COMPAREH_MASK)

/*!
 * @}
 */ /* end of group EWM_Register_Masks */


/* EWM - Peripheral instance base addresses */
/** Peripheral EWM base address */
#define EWM_BASE                                 (0x40061000u)
/** Peripheral EWM base pointer */
#define EWM                                      ((EWM_Type *)EWM_BASE)
/** Array initializer of EWM peripheral base pointers */
#define EWM_BASES                                { EWM }

/*!
 * @}
 */ /* end of group EWM_Peripheral_Access_Layer */


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
} FTFA_Type;

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
#define FTFA_FSTAT_FPVIOL_MASK                   0x10u
#define FTFA_FSTAT_FPVIOL_SHIFT                  4
#define FTFA_FSTAT_ACCERR_MASK                   0x20u
#define FTFA_FSTAT_ACCERR_SHIFT                  5
#define FTFA_FSTAT_RDCOLERR_MASK                 0x40u
#define FTFA_FSTAT_RDCOLERR_SHIFT                6
#define FTFA_FSTAT_CCIF_MASK                     0x80u
#define FTFA_FSTAT_CCIF_SHIFT                    7
/* FCNFG Bit Fields */
#define FTFA_FCNFG_ERSSUSP_MASK                  0x10u
#define FTFA_FCNFG_ERSSUSP_SHIFT                 4
#define FTFA_FCNFG_ERSAREQ_MASK                  0x20u
#define FTFA_FCNFG_ERSAREQ_SHIFT                 5
#define FTFA_FCNFG_RDCOLLIE_MASK                 0x40u
#define FTFA_FCNFG_RDCOLLIE_SHIFT                6
#define FTFA_FCNFG_CCIE_MASK                     0x80u
#define FTFA_FCNFG_CCIE_SHIFT                    7
/* FSEC Bit Fields */
#define FTFA_FSEC_SEC_MASK                       0x3u
#define FTFA_FSEC_SEC_SHIFT                      0
#define FTFA_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_SEC_SHIFT))&FTFA_FSEC_SEC_MASK)
#define FTFA_FSEC_FSLACC_MASK                    0xCu
#define FTFA_FSEC_FSLACC_SHIFT                   2
#define FTFA_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_FSLACC_SHIFT))&FTFA_FSEC_FSLACC_MASK)
#define FTFA_FSEC_MEEN_MASK                      0x30u
#define FTFA_FSEC_MEEN_SHIFT                     4
#define FTFA_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_MEEN_SHIFT))&FTFA_FSEC_MEEN_MASK)
#define FTFA_FSEC_KEYEN_MASK                     0xC0u
#define FTFA_FSEC_KEYEN_SHIFT                    6
#define FTFA_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_KEYEN_SHIFT))&FTFA_FSEC_KEYEN_MASK)
/* FOPT Bit Fields */
#define FTFA_FOPT_OPT_MASK                       0xFFu
#define FTFA_FOPT_OPT_SHIFT                      0
#define FTFA_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x))<<FTFA_FOPT_OPT_SHIFT))&FTFA_FOPT_OPT_MASK)
/* FCCOB3 Bit Fields */
#define FTFA_FCCOB3_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB3_CCOBn_SHIFT                  0
#define FTFA_FCCOB3_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB3_CCOBn_SHIFT))&FTFA_FCCOB3_CCOBn_MASK)
/* FCCOB2 Bit Fields */
#define FTFA_FCCOB2_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB2_CCOBn_SHIFT                  0
#define FTFA_FCCOB2_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB2_CCOBn_SHIFT))&FTFA_FCCOB2_CCOBn_MASK)
/* FCCOB1 Bit Fields */
#define FTFA_FCCOB1_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB1_CCOBn_SHIFT                  0
#define FTFA_FCCOB1_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB1_CCOBn_SHIFT))&FTFA_FCCOB1_CCOBn_MASK)
/* FCCOB0 Bit Fields */
#define FTFA_FCCOB0_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB0_CCOBn_SHIFT                  0
#define FTFA_FCCOB0_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB0_CCOBn_SHIFT))&FTFA_FCCOB0_CCOBn_MASK)
/* FCCOB7 Bit Fields */
#define FTFA_FCCOB7_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB7_CCOBn_SHIFT                  0
#define FTFA_FCCOB7_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB7_CCOBn_SHIFT))&FTFA_FCCOB7_CCOBn_MASK)
/* FCCOB6 Bit Fields */
#define FTFA_FCCOB6_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB6_CCOBn_SHIFT                  0
#define FTFA_FCCOB6_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB6_CCOBn_SHIFT))&FTFA_FCCOB6_CCOBn_MASK)
/* FCCOB5 Bit Fields */
#define FTFA_FCCOB5_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB5_CCOBn_SHIFT                  0
#define FTFA_FCCOB5_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB5_CCOBn_SHIFT))&FTFA_FCCOB5_CCOBn_MASK)
/* FCCOB4 Bit Fields */
#define FTFA_FCCOB4_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB4_CCOBn_SHIFT                  0
#define FTFA_FCCOB4_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB4_CCOBn_SHIFT))&FTFA_FCCOB4_CCOBn_MASK)
/* FCCOBB Bit Fields */
#define FTFA_FCCOBB_CCOBn_MASK                   0xFFu
#define FTFA_FCCOBB_CCOBn_SHIFT                  0
#define FTFA_FCCOBB_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOBB_CCOBn_SHIFT))&FTFA_FCCOBB_CCOBn_MASK)
/* FCCOBA Bit Fields */
#define FTFA_FCCOBA_CCOBn_MASK                   0xFFu
#define FTFA_FCCOBA_CCOBn_SHIFT                  0
#define FTFA_FCCOBA_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOBA_CCOBn_SHIFT))&FTFA_FCCOBA_CCOBn_MASK)
/* FCCOB9 Bit Fields */
#define FTFA_FCCOB9_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB9_CCOBn_SHIFT                  0
#define FTFA_FCCOB9_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB9_CCOBn_SHIFT))&FTFA_FCCOB9_CCOBn_MASK)
/* FCCOB8 Bit Fields */
#define FTFA_FCCOB8_CCOBn_MASK                   0xFFu
#define FTFA_FCCOB8_CCOBn_SHIFT                  0
#define FTFA_FCCOB8_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB8_CCOBn_SHIFT))&FTFA_FCCOB8_CCOBn_MASK)
/* FPROT3 Bit Fields */
#define FTFA_FPROT3_PROT_MASK                    0xFFu
#define FTFA_FPROT3_PROT_SHIFT                   0
#define FTFA_FPROT3_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT3_PROT_SHIFT))&FTFA_FPROT3_PROT_MASK)
/* FPROT2 Bit Fields */
#define FTFA_FPROT2_PROT_MASK                    0xFFu
#define FTFA_FPROT2_PROT_SHIFT                   0
#define FTFA_FPROT2_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT2_PROT_SHIFT))&FTFA_FPROT2_PROT_MASK)
/* FPROT1 Bit Fields */
#define FTFA_FPROT1_PROT_MASK                    0xFFu
#define FTFA_FPROT1_PROT_SHIFT                   0
#define FTFA_FPROT1_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT1_PROT_SHIFT))&FTFA_FPROT1_PROT_MASK)
/* FPROT0 Bit Fields */
#define FTFA_FPROT0_PROT_MASK                    0xFFu
#define FTFA_FPROT0_PROT_SHIFT                   0
#define FTFA_FPROT0_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT0_PROT_SHIFT))&FTFA_FPROT0_PROT_MASK)

/*!
 * @}
 */ /* end of group FTFA_Register_Masks */


/* FTFA - Peripheral instance base addresses */
/** Peripheral FTFA base address */
#define FTFA_BASE                                (0x40020000u)
/** Peripheral FTFA base pointer */
#define FTFA                                     ((FTFA_Type *)FTFA_BASE)
/** Array initializer of FTFA peripheral base pointers */
#define FTFA_BASES                               { FTFA }

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
  __IO uint8_t PDOR;                               /**< Port Data Output Register, offset: 0x0 */
       uint8_t RESERVED_0[15];
  __I  uint8_t PDIR;                               /**< Port Data Input Register, offset: 0x10 */
       uint8_t RESERVED_1[3];
  __IO uint8_t PDDR;                               /**< Port Data Direction Register, offset: 0x14 */
       uint8_t RESERVED_2[7];
  __IO uint8_t GACR;                               /**< GPIO Attribute Checker Register, offset: 0x1C */
} GPIO_Type;

/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/* PDOR Bit Fields */
#define GPIO_PDOR_PDO_MASK                       0xFFu
#define GPIO_PDOR_PDO_SHIFT                      0
#define GPIO_PDOR_PDO(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_PDOR_PDO_SHIFT))&GPIO_PDOR_PDO_MASK)
/* PDIR Bit Fields */
#define GPIO_PDIR_PDI_MASK                       0xFFu
#define GPIO_PDIR_PDI_SHIFT                      0
#define GPIO_PDIR_PDI(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_PDIR_PDI_SHIFT))&GPIO_PDIR_PDI_MASK)
/* PDDR Bit Fields */
#define GPIO_PDDR_PDD_MASK                       0xFFu
#define GPIO_PDDR_PDD_SHIFT                      0
#define GPIO_PDDR_PDD(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_PDDR_PDD_SHIFT))&GPIO_PDDR_PDD_MASK)
/* GACR Bit Fields */
#define GPIO_GACR_ACB_MASK                       0x7u
#define GPIO_GACR_ACB_SHIFT                      0
#define GPIO_GACR_ACB(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_GACR_ACB_SHIFT))&GPIO_GACR_ACB_MASK)
#define GPIO_GACR_ROB_MASK                       0x80u
#define GPIO_GACR_ROB_SHIFT                      7

/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base address */
#define GPIOA_BASE                               (0x400FF000u)
/** Peripheral GPIOA base pointer */
#define GPIOA                                    ((GPIO_Type *)GPIOA_BASE)
/** Peripheral GPIOB base address */
#define GPIOB_BASE                               (0x400FF001u)
/** Peripheral GPIOB base pointer */
#define GPIOB                                    ((GPIO_Type *)GPIOB_BASE)
/** Peripheral GPIOC base address */
#define GPIOC_BASE                               (0x400FF002u)
/** Peripheral GPIOC base pointer */
#define GPIOC                                    ((GPIO_Type *)GPIOC_BASE)
/** Peripheral GPIOD base address */
#define GPIOD_BASE                               (0x400FF003u)
/** Peripheral GPIOD base pointer */
#define GPIOD                                    ((GPIO_Type *)GPIOD_BASE)
/** Peripheral GPIOE base address */
#define GPIOE_BASE                               (0x400FF040u)
/** Peripheral GPIOE base pointer */
#define GPIOE                                    ((GPIO_Type *)GPIOE_BASE)
/** Peripheral GPIOF base address */
#define GPIOF_BASE                               (0x400FF041u)
/** Peripheral GPIOF base pointer */
#define GPIOF                                    ((GPIO_Type *)GPIOF_BASE)
/** Peripheral GPIOG base address */
#define GPIOG_BASE                               (0x400FF042u)
/** Peripheral GPIOG base pointer */
#define GPIOG                                    ((GPIO_Type *)GPIOG_BASE)
/** Peripheral GPIOH base address */
#define GPIOH_BASE                               (0x400FF043u)
/** Peripheral GPIOH base pointer */
#define GPIOH                                    ((GPIO_Type *)GPIOH_BASE)
/** Peripheral GPIOI base address */
#define GPIOI_BASE                               (0x400FF080u)
/** Peripheral GPIOI base pointer */
#define GPIOI                                    ((GPIO_Type *)GPIOI_BASE)
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASES                               { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH, GPIOI }

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
  __IO uint8_t FLT;                                /**< I2C Programmable Input Glitch Filter register, offset: 0x6 */
  __IO uint8_t RA;                                 /**< I2C Range Address register, offset: 0x7 */
  __IO uint8_t SMB;                                /**< I2C SMBus Control and Status register, offset: 0x8 */
  __IO uint8_t A2;                                 /**< I2C Address Register 2, offset: 0x9 */
  __IO uint8_t SLTH;                               /**< I2C SCL Low Timeout Register High, offset: 0xA */
  __IO uint8_t SLTL;                               /**< I2C SCL Low Timeout Register Low, offset: 0xB */
} I2C_Type;

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
#define I2C_C1_DMAEN_MASK                        0x1u
#define I2C_C1_DMAEN_SHIFT                       0
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
#define I2C_C2_HDRS_MASK                         0x20u
#define I2C_C2_HDRS_SHIFT                        5
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
#define I2C0_BASE                                (0x40067000u)
/** Peripheral I2C0 base pointer */
#define I2C0                                     ((I2C_Type *)I2C0_BASE)
/** Peripheral I2C1 base address */
#define I2C1_BASE                                (0x40068000u)
/** Peripheral I2C1 base pointer */
#define I2C1                                     ((I2C_Type *)I2C1_BASE)
/** Array initializer of I2C peripheral base pointers */
#define I2C_BASES                                { I2C0, I2C1 }

/*!
 * @}
 */ /* end of group I2C_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LLWU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Peripheral_Access_Layer LLWU Peripheral Access Layer
 * @{
 */

/** LLWU - Register Layout Typedef */
typedef struct {
  __IO uint8_t PE1;                                /**< LLWU Pin Enable 1 register, offset: 0x0 */
  __IO uint8_t PE2;                                /**< LLWU Pin Enable 2 register, offset: 0x1 */
  __IO uint8_t PE3;                                /**< LLWU Pin Enable 3 register, offset: 0x2 */
  __IO uint8_t PE4;                                /**< LLWU Pin Enable 4 register, offset: 0x3 */
  __IO uint8_t ME;                                 /**< LLWU Module Enable register, offset: 0x4 */
  __IO uint8_t F1;                                 /**< LLWU Flag 1 register, offset: 0x5 */
  __IO uint8_t F2;                                 /**< LLWU Flag 2 register, offset: 0x6 */
  __I  uint8_t F3;                                 /**< LLWU Flag 3 register, offset: 0x7 */
  __IO uint8_t FILT1;                              /**< LLWU Pin Filter 1 register, offset: 0x8 */
  __IO uint8_t FILT2;                              /**< LLWU Pin Filter 2 register, offset: 0x9 */
} LLWU_Type;

/* ----------------------------------------------------------------------------
   -- LLWU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Register_Masks LLWU Register Masks
 * @{
 */

/* PE1 Bit Fields */
#define LLWU_PE1_WUPE0_MASK                      0x3u
#define LLWU_PE1_WUPE0_SHIFT                     0
#define LLWU_PE1_WUPE0(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE0_SHIFT))&LLWU_PE1_WUPE0_MASK)
#define LLWU_PE1_WUPE1_MASK                      0xCu
#define LLWU_PE1_WUPE1_SHIFT                     2
#define LLWU_PE1_WUPE1(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE1_SHIFT))&LLWU_PE1_WUPE1_MASK)
#define LLWU_PE1_WUPE2_MASK                      0x30u
#define LLWU_PE1_WUPE2_SHIFT                     4
#define LLWU_PE1_WUPE2(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE2_SHIFT))&LLWU_PE1_WUPE2_MASK)
#define LLWU_PE1_WUPE3_MASK                      0xC0u
#define LLWU_PE1_WUPE3_SHIFT                     6
#define LLWU_PE1_WUPE3(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE3_SHIFT))&LLWU_PE1_WUPE3_MASK)
/* PE2 Bit Fields */
#define LLWU_PE2_WUPE4_MASK                      0x3u
#define LLWU_PE2_WUPE4_SHIFT                     0
#define LLWU_PE2_WUPE4(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE4_SHIFT))&LLWU_PE2_WUPE4_MASK)
#define LLWU_PE2_WUPE5_MASK                      0xCu
#define LLWU_PE2_WUPE5_SHIFT                     2
#define LLWU_PE2_WUPE5(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE5_SHIFT))&LLWU_PE2_WUPE5_MASK)
#define LLWU_PE2_WUPE6_MASK                      0x30u
#define LLWU_PE2_WUPE6_SHIFT                     4
#define LLWU_PE2_WUPE6(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE6_SHIFT))&LLWU_PE2_WUPE6_MASK)
#define LLWU_PE2_WUPE7_MASK                      0xC0u
#define LLWU_PE2_WUPE7_SHIFT                     6
#define LLWU_PE2_WUPE7(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE7_SHIFT))&LLWU_PE2_WUPE7_MASK)
/* PE3 Bit Fields */
#define LLWU_PE3_WUPE8_MASK                      0x3u
#define LLWU_PE3_WUPE8_SHIFT                     0
#define LLWU_PE3_WUPE8(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE8_SHIFT))&LLWU_PE3_WUPE8_MASK)
#define LLWU_PE3_WUPE9_MASK                      0xCu
#define LLWU_PE3_WUPE9_SHIFT                     2
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE9_SHIFT))&LLWU_PE3_WUPE9_MASK)
#define LLWU_PE3_WUPE10_MASK                     0x30u
#define LLWU_PE3_WUPE10_SHIFT                    4
#define LLWU_PE3_WUPE10(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE10_SHIFT))&LLWU_PE3_WUPE10_MASK)
#define LLWU_PE3_WUPE11_MASK                     0xC0u
#define LLWU_PE3_WUPE11_SHIFT                    6
#define LLWU_PE3_WUPE11(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE11_SHIFT))&LLWU_PE3_WUPE11_MASK)
/* PE4 Bit Fields */
#define LLWU_PE4_WUPE12_MASK                     0x3u
#define LLWU_PE4_WUPE12_SHIFT                    0
#define LLWU_PE4_WUPE12(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE12_SHIFT))&LLWU_PE4_WUPE12_MASK)
#define LLWU_PE4_WUPE13_MASK                     0xCu
#define LLWU_PE4_WUPE13_SHIFT                    2
#define LLWU_PE4_WUPE13(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE13_SHIFT))&LLWU_PE4_WUPE13_MASK)
#define LLWU_PE4_WUPE14_MASK                     0x30u
#define LLWU_PE4_WUPE14_SHIFT                    4
#define LLWU_PE4_WUPE14(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE14_SHIFT))&LLWU_PE4_WUPE14_MASK)
#define LLWU_PE4_WUPE15_MASK                     0xC0u
#define LLWU_PE4_WUPE15_SHIFT                    6
#define LLWU_PE4_WUPE15(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE15_SHIFT))&LLWU_PE4_WUPE15_MASK)
/* ME Bit Fields */
#define LLWU_ME_WUME0_MASK                       0x1u
#define LLWU_ME_WUME0_SHIFT                      0
#define LLWU_ME_WUME1_MASK                       0x2u
#define LLWU_ME_WUME1_SHIFT                      1
#define LLWU_ME_WUME2_MASK                       0x4u
#define LLWU_ME_WUME2_SHIFT                      2
#define LLWU_ME_WUME3_MASK                       0x8u
#define LLWU_ME_WUME3_SHIFT                      3
#define LLWU_ME_WUME4_MASK                       0x10u
#define LLWU_ME_WUME4_SHIFT                      4
#define LLWU_ME_WUME5_MASK                       0x20u
#define LLWU_ME_WUME5_SHIFT                      5
#define LLWU_ME_WUME6_MASK                       0x40u
#define LLWU_ME_WUME6_SHIFT                      6
#define LLWU_ME_WUME7_MASK                       0x80u
#define LLWU_ME_WUME7_SHIFT                      7
/* F1 Bit Fields */
#define LLWU_F1_WUF0_MASK                        0x1u
#define LLWU_F1_WUF0_SHIFT                       0
#define LLWU_F1_WUF1_MASK                        0x2u
#define LLWU_F1_WUF1_SHIFT                       1
#define LLWU_F1_WUF2_MASK                        0x4u
#define LLWU_F1_WUF2_SHIFT                       2
#define LLWU_F1_WUF3_MASK                        0x8u
#define LLWU_F1_WUF3_SHIFT                       3
#define LLWU_F1_WUF4_MASK                        0x10u
#define LLWU_F1_WUF4_SHIFT                       4
#define LLWU_F1_WUF5_MASK                        0x20u
#define LLWU_F1_WUF5_SHIFT                       5
#define LLWU_F1_WUF6_MASK                        0x40u
#define LLWU_F1_WUF6_SHIFT                       6
#define LLWU_F1_WUF7_MASK                        0x80u
#define LLWU_F1_WUF7_SHIFT                       7
/* F2 Bit Fields */
#define LLWU_F2_WUF8_MASK                        0x1u
#define LLWU_F2_WUF8_SHIFT                       0
#define LLWU_F2_WUF9_MASK                        0x2u
#define LLWU_F2_WUF9_SHIFT                       1
#define LLWU_F2_WUF10_MASK                       0x4u
#define LLWU_F2_WUF10_SHIFT                      2
#define LLWU_F2_WUF11_MASK                       0x8u
#define LLWU_F2_WUF11_SHIFT                      3
#define LLWU_F2_WUF12_MASK                       0x10u
#define LLWU_F2_WUF12_SHIFT                      4
#define LLWU_F2_WUF13_MASK                       0x20u
#define LLWU_F2_WUF13_SHIFT                      5
#define LLWU_F2_WUF14_MASK                       0x40u
#define LLWU_F2_WUF14_SHIFT                      6
#define LLWU_F2_WUF15_MASK                       0x80u
#define LLWU_F2_WUF15_SHIFT                      7
/* F3 Bit Fields */
#define LLWU_F3_MWUF0_MASK                       0x1u
#define LLWU_F3_MWUF0_SHIFT                      0
#define LLWU_F3_MWUF1_MASK                       0x2u
#define LLWU_F3_MWUF1_SHIFT                      1
#define LLWU_F3_MWUF2_MASK                       0x4u
#define LLWU_F3_MWUF2_SHIFT                      2
#define LLWU_F3_MWUF3_MASK                       0x8u
#define LLWU_F3_MWUF3_SHIFT                      3
#define LLWU_F3_MWUF4_MASK                       0x10u
#define LLWU_F3_MWUF4_SHIFT                      4
#define LLWU_F3_MWUF5_MASK                       0x20u
#define LLWU_F3_MWUF5_SHIFT                      5
#define LLWU_F3_MWUF6_MASK                       0x40u
#define LLWU_F3_MWUF6_SHIFT                      6
#define LLWU_F3_MWUF7_MASK                       0x80u
#define LLWU_F3_MWUF7_SHIFT                      7
/* FILT1 Bit Fields */
#define LLWU_FILT1_FILTSEL_MASK                  0xFu
#define LLWU_FILT1_FILTSEL_SHIFT                 0
#define LLWU_FILT1_FILTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<LLWU_FILT1_FILTSEL_SHIFT))&LLWU_FILT1_FILTSEL_MASK)
#define LLWU_FILT1_FILTE_MASK                    0x60u
#define LLWU_FILT1_FILTE_SHIFT                   5
#define LLWU_FILT1_FILTE(x)                      (((uint8_t)(((uint8_t)(x))<<LLWU_FILT1_FILTE_SHIFT))&LLWU_FILT1_FILTE_MASK)
#define LLWU_FILT1_FILTF_MASK                    0x80u
#define LLWU_FILT1_FILTF_SHIFT                   7
/* FILT2 Bit Fields */
#define LLWU_FILT2_FILTSEL_MASK                  0xFu
#define LLWU_FILT2_FILTSEL_SHIFT                 0
#define LLWU_FILT2_FILTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<LLWU_FILT2_FILTSEL_SHIFT))&LLWU_FILT2_FILTSEL_MASK)
#define LLWU_FILT2_FILTE_MASK                    0x60u
#define LLWU_FILT2_FILTE_SHIFT                   5
#define LLWU_FILT2_FILTE(x)                      (((uint8_t)(((uint8_t)(x))<<LLWU_FILT2_FILTE_SHIFT))&LLWU_FILT2_FILTE_MASK)
#define LLWU_FILT2_FILTF_MASK                    0x80u
#define LLWU_FILT2_FILTF_SHIFT                   7

/*!
 * @}
 */ /* end of group LLWU_Register_Masks */


/* LLWU - Peripheral instance base addresses */
/** Peripheral LLWU base address */
#define LLWU_BASE                                (0x4007C000u)
/** Peripheral LLWU base pointer */
#define LLWU                                     ((LLWU_Type *)LLWU_BASE)
/** Array initializer of LLWU peripheral base pointers */
#define LLWU_BASES                               { LLWU }

/*!
 * @}
 */ /* end of group LLWU_Peripheral_Access_Layer */


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
} LPTMR_Type;

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
#define LPTMR_CSR_TMS_MASK                       0x2u
#define LPTMR_CSR_TMS_SHIFT                      1
#define LPTMR_CSR_TFC_MASK                       0x4u
#define LPTMR_CSR_TFC_SHIFT                      2
#define LPTMR_CSR_TPP_MASK                       0x8u
#define LPTMR_CSR_TPP_SHIFT                      3
#define LPTMR_CSR_TPS_MASK                       0x30u
#define LPTMR_CSR_TPS_SHIFT                      4
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPS_SHIFT))&LPTMR_CSR_TPS_MASK)
#define LPTMR_CSR_TIE_MASK                       0x40u
#define LPTMR_CSR_TIE_SHIFT                      6
#define LPTMR_CSR_TCF_MASK                       0x80u
#define LPTMR_CSR_TCF_SHIFT                      7
/* PSR Bit Fields */
#define LPTMR_PSR_PCS_MASK                       0x3u
#define LPTMR_PSR_PCS_SHIFT                      0
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PCS_SHIFT))&LPTMR_PSR_PCS_MASK)
#define LPTMR_PSR_PBYP_MASK                      0x4u
#define LPTMR_PSR_PBYP_SHIFT                     2
#define LPTMR_PSR_PRESCALE_MASK                  0x78u
#define LPTMR_PSR_PRESCALE_SHIFT                 3
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PRESCALE_SHIFT))&LPTMR_PSR_PRESCALE_MASK)
/* CMR Bit Fields */
#define LPTMR_CMR_COMPARE_MASK                   0xFFFFu
#define LPTMR_CMR_COMPARE_SHIFT                  0
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CMR_COMPARE_SHIFT))&LPTMR_CMR_COMPARE_MASK)
/* CNR Bit Fields */
#define LPTMR_CNR_COUNTER_MASK                   0xFFFFu
#define LPTMR_CNR_COUNTER_SHIFT                  0
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CNR_COUNTER_SHIFT))&LPTMR_CNR_COUNTER_MASK)

/*!
 * @}
 */ /* end of group LPTMR_Register_Masks */


/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR base address */
#define LPTMR_BASE                               (0x4003C000u)
/** Peripheral LPTMR base pointer */
#define LPTMR                                    ((LPTMR_Type *)LPTMR_BASE)
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASES                              { LPTMR }

/*!
 * @}
 */ /* end of group LPTMR_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MCG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Peripheral_Access_Layer MCG Peripheral Access Layer
 * @{
 */

/** MCG - Register Layout Typedef */
typedef struct {
  __IO uint8_t C1;                                 /**< MCG Control 1 Register, offset: 0x0 */
  __IO uint8_t C2;                                 /**< MCG Control 2 Register, offset: 0x1 */
  __IO uint8_t C3;                                 /**< MCG Control 3 Register, offset: 0x2 */
  __IO uint8_t C4;                                 /**< MCG Control 4 Register, offset: 0x3 */
  __IO uint8_t C5;                                 /**< MCG Control 5 Register, offset: 0x4 */
  __IO uint8_t C6;                                 /**< MCG Control 6 Register, offset: 0x5 */
  __IO uint8_t S;                                  /**< MCG Status Register, offset: 0x6 */
       uint8_t RESERVED_0[1];
  __IO uint8_t SC;                                 /**< MCG Status and Control Register, offset: 0x8 */
       uint8_t RESERVED_1[1];
  __IO uint8_t ATCVH;                              /**< MCG Auto Trim Compare Value High Register, offset: 0xA */
  __IO uint8_t ATCVL;                              /**< MCG Auto Trim Compare Value Low Register, offset: 0xB */
  __IO uint8_t C7;                                 /**< MCG Control 7 Register, offset: 0xC */
  __IO uint8_t C8;                                 /**< MCG Control 8 Register, offset: 0xD */
  __I  uint8_t C9;                                 /**< MCG Control 9 Register, offset: 0xE */
  __I  uint8_t C10;                                /**< MCG Control 10 Register, offset: 0xF */
} MCG_Type;

/* ----------------------------------------------------------------------------
   -- MCG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Register_Masks MCG Register Masks
 * @{
 */

/* C1 Bit Fields */
#define MCG_C1_IREFSTEN_MASK                     0x1u
#define MCG_C1_IREFSTEN_SHIFT                    0
#define MCG_C1_IRCLKEN_MASK                      0x2u
#define MCG_C1_IRCLKEN_SHIFT                     1
#define MCG_C1_IREFS_MASK                        0x4u
#define MCG_C1_IREFS_SHIFT                       2
#define MCG_C1_FRDIV_MASK                        0x38u
#define MCG_C1_FRDIV_SHIFT                       3
#define MCG_C1_FRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C1_FRDIV_SHIFT))&MCG_C1_FRDIV_MASK)
#define MCG_C1_CLKS_MASK                         0xC0u
#define MCG_C1_CLKS_SHIFT                        6
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C1_CLKS_SHIFT))&MCG_C1_CLKS_MASK)
/* C2 Bit Fields */
#define MCG_C2_IRCS_MASK                         0x1u
#define MCG_C2_IRCS_SHIFT                        0
#define MCG_C2_LP_MASK                           0x2u
#define MCG_C2_LP_SHIFT                          1
#define MCG_C2_EREFS0_MASK                       0x4u
#define MCG_C2_EREFS0_SHIFT                      2
#define MCG_C2_HGO0_MASK                         0x8u
#define MCG_C2_HGO0_SHIFT                        3
#define MCG_C2_RANGE0_MASK                       0x30u
#define MCG_C2_RANGE0_SHIFT                      4
#define MCG_C2_RANGE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_RANGE0_SHIFT))&MCG_C2_RANGE0_MASK)
#define MCG_C2_LOCRE0_MASK                       0x80u
#define MCG_C2_LOCRE0_SHIFT                      7
/* C3 Bit Fields */
#define MCG_C3_SCTRIM_MASK                       0xFFu
#define MCG_C3_SCTRIM_SHIFT                      0
#define MCG_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C3_SCTRIM_SHIFT))&MCG_C3_SCTRIM_MASK)
/* C4 Bit Fields */
#define MCG_C4_SCFTRIM_MASK                      0x1u
#define MCG_C4_SCFTRIM_SHIFT                     0
#define MCG_C4_FCTRIM_MASK                       0x1Eu
#define MCG_C4_FCTRIM_SHIFT                      1
#define MCG_C4_FCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C4_FCTRIM_SHIFT))&MCG_C4_FCTRIM_MASK)
#define MCG_C4_DRST_DRS_MASK                     0x60u
#define MCG_C4_DRST_DRS_SHIFT                    5
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C4_DRST_DRS_SHIFT))&MCG_C4_DRST_DRS_MASK)
#define MCG_C4_DMX32_MASK                        0x80u
#define MCG_C4_DMX32_SHIFT                       7
/* C5 Bit Fields */
#define MCG_C5_PLLSTEN0_MASK                     0x20u
#define MCG_C5_PLLSTEN0_SHIFT                    5
#define MCG_C5_PLLCLKEN0_MASK                    0x40u
#define MCG_C5_PLLCLKEN0_SHIFT                   6
/* C6 Bit Fields */
#define MCG_C6_CHGPMP_BIAS_MASK                  0x1Fu
#define MCG_C6_CHGPMP_BIAS_SHIFT                 0
#define MCG_C6_CHGPMP_BIAS(x)                    (((uint8_t)(((uint8_t)(x))<<MCG_C6_CHGPMP_BIAS_SHIFT))&MCG_C6_CHGPMP_BIAS_MASK)
#define MCG_C6_CME0_MASK                         0x20u
#define MCG_C6_CME0_SHIFT                        5
#define MCG_C6_PLLS_MASK                         0x40u
#define MCG_C6_PLLS_SHIFT                        6
#define MCG_C6_LOLIE0_MASK                       0x80u
#define MCG_C6_LOLIE0_SHIFT                      7
/* S Bit Fields */
#define MCG_S_IRCST_MASK                         0x1u
#define MCG_S_IRCST_SHIFT                        0
#define MCG_S_OSCINIT0_MASK                      0x2u
#define MCG_S_OSCINIT0_SHIFT                     1
#define MCG_S_CLKST_MASK                         0xCu
#define MCG_S_CLKST_SHIFT                        2
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_CLKST_SHIFT))&MCG_S_CLKST_MASK)
#define MCG_S_IREFST_MASK                        0x10u
#define MCG_S_IREFST_SHIFT                       4
#define MCG_S_PLLST_MASK                         0x20u
#define MCG_S_PLLST_SHIFT                        5
#define MCG_S_LOCK0_MASK                         0x40u
#define MCG_S_LOCK0_SHIFT                        6
#define MCG_S_LOLS_MASK                          0x80u
#define MCG_S_LOLS_SHIFT                         7
/* SC Bit Fields */
#define MCG_SC_LOCS0_MASK                        0x1u
#define MCG_SC_LOCS0_SHIFT                       0
#define MCG_SC_FCRDIV_MASK                       0xEu
#define MCG_SC_FCRDIV_SHIFT                      1
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_SC_FCRDIV_SHIFT))&MCG_SC_FCRDIV_MASK)
#define MCG_SC_FLTPRSRV_MASK                     0x10u
#define MCG_SC_FLTPRSRV_SHIFT                    4
#define MCG_SC_ATMF_MASK                         0x20u
#define MCG_SC_ATMF_SHIFT                        5
#define MCG_SC_ATMS_MASK                         0x40u
#define MCG_SC_ATMS_SHIFT                        6
#define MCG_SC_ATME_MASK                         0x80u
#define MCG_SC_ATME_SHIFT                        7
/* ATCVH Bit Fields */
#define MCG_ATCVH_ATCVH_MASK                     0xFFu
#define MCG_ATCVH_ATCVH_SHIFT                    0
#define MCG_ATCVH_ATCVH(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVH_ATCVH_SHIFT))&MCG_ATCVH_ATCVH_MASK)
/* ATCVL Bit Fields */
#define MCG_ATCVL_ATCVL_MASK                     0xFFu
#define MCG_ATCVL_ATCVL_SHIFT                    0
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVL_ATCVL_SHIFT))&MCG_ATCVL_ATCVL_MASK)
/* C7 Bit Fields */
#define MCG_C7_OSCSEL_MASK                       0x1u
#define MCG_C7_OSCSEL_SHIFT                      0
#define MCG_C7_PLL32KREFSEL_MASK                 0xC0u
#define MCG_C7_PLL32KREFSEL_SHIFT                6
#define MCG_C7_PLL32KREFSEL(x)                   (((uint8_t)(((uint8_t)(x))<<MCG_C7_PLL32KREFSEL_SHIFT))&MCG_C7_PLL32KREFSEL_MASK)
/* C8 Bit Fields */
#define MCG_C8_LOCS1_MASK                        0x1u
#define MCG_C8_LOCS1_SHIFT                       0
#define MCG_C8_COARSE_LOLIE_MASK                 0x10u
#define MCG_C8_COARSE_LOLIE_SHIFT                4
#define MCG_C8_CME1_MASK                         0x20u
#define MCG_C8_CME1_SHIFT                        5
#define MCG_C8_LOLRE_MASK                        0x40u
#define MCG_C8_LOLRE_SHIFT                       6
#define MCG_C8_LOCRE1_MASK                       0x80u
#define MCG_C8_LOCRE1_SHIFT                      7
/* C9 Bit Fields */
#define MCG_C9_COARSE_LOCK_MASK                  0x40u
#define MCG_C9_COARSE_LOCK_SHIFT                 6
#define MCG_C9_COARSE_LOLS_MASK                  0x80u
#define MCG_C9_COARSE_LOLS_SHIFT                 7

/*!
 * @}
 */ /* end of group MCG_Register_Masks */


/* MCG - Peripheral instance base addresses */
/** Peripheral MCG base address */
#define MCG_BASE                                 (0x40064000u)
/** Peripheral MCG base pointer */
#define MCG                                      ((MCG_Type *)MCG_BASE)
/** Array initializer of MCG peripheral base pointers */
#define MCG_BASES                                { MCG }

/*!
 * @}
 */ /* end of group MCG_Peripheral_Access_Layer */


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
       uint8_t RESERVED_1[32];
  __IO uint32_t PID;                               /**< Process ID register, offset: 0x30 */
       uint8_t RESERVED_2[12];
  __IO uint32_t CPO;                               /**< Compute Operation Control Register, offset: 0x40 */
       uint8_t RESERVED_3[60];
  __IO uint32_t MATCR[1];                          /**< Master Attribute Configuration Register, array offset: 0x80, array step: 0x4 */
} MCM_Type;

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
#define MCM_PLACR_CFCC_MASK                      0x400u
#define MCM_PLACR_CFCC_SHIFT                     10
#define MCM_PLACR_DFCDA_MASK                     0x800u
#define MCM_PLACR_DFCDA_SHIFT                    11
#define MCM_PLACR_DFCIC_MASK                     0x1000u
#define MCM_PLACR_DFCIC_SHIFT                    12
#define MCM_PLACR_DFCC_MASK                      0x2000u
#define MCM_PLACR_DFCC_SHIFT                     13
#define MCM_PLACR_EFDS_MASK                      0x4000u
#define MCM_PLACR_EFDS_SHIFT                     14
#define MCM_PLACR_DFCS_MASK                      0x8000u
#define MCM_PLACR_DFCS_SHIFT                     15
#define MCM_PLACR_ESFC_MASK                      0x10000u
#define MCM_PLACR_ESFC_SHIFT                     16
/* PID Bit Fields */
#define MCM_PID_PID_MASK                         0xFFu
#define MCM_PID_PID_SHIFT                        0
#define MCM_PID_PID(x)                           (((uint32_t)(((uint32_t)(x))<<MCM_PID_PID_SHIFT))&MCM_PID_PID_MASK)
/* CPO Bit Fields */
#define MCM_CPO_CPOREQ_MASK                      0x1u
#define MCM_CPO_CPOREQ_SHIFT                     0
#define MCM_CPO_CPOACK_MASK                      0x2u
#define MCM_CPO_CPOACK_SHIFT                     1
#define MCM_CPO_CPOWOI_MASK                      0x4u
#define MCM_CPO_CPOWOI_SHIFT                     2
/* MATCR Bit Fields */
#define MCM_MATCR_ATC0_MASK                      0x7u
#define MCM_MATCR_ATC0_SHIFT                     0
#define MCM_MATCR_ATC0(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_MATCR_ATC0_SHIFT))&MCM_MATCR_ATC0_MASK)
#define MCM_MATCR_RO0_MASK                       0x80u
#define MCM_MATCR_RO0_SHIFT                      7
#define MCM_MATCR_ATC2_MASK                      0x70000u
#define MCM_MATCR_ATC2_SHIFT                     16
#define MCM_MATCR_ATC2(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_MATCR_ATC2_SHIFT))&MCM_MATCR_ATC2_MASK)
#define MCM_MATCR_RO2_MASK                       0x800000u
#define MCM_MATCR_RO2_SHIFT                      23

/*!
 * @}
 */ /* end of group MCM_Register_Masks */


/* MCM - Peripheral instance base addresses */
/** Peripheral MCM base address */
#define MCM_BASE                                 (0xF0003000u)
/** Peripheral MCM base pointer */
#define MCM                                      ((MCM_Type *)MCM_BASE)
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASES                                { MCM }

/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MPU_Peripheral_Access_Layer MPU Peripheral Access Layer
 * @{
 */

/** MPU - Register Layout Typedef */
typedef struct {
  __IO uint32_t CESR;                              /**< Control/Error Status Register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  struct {                                         /* offset: 0x10, array step: 0x8 */
    __I  uint32_t EAR;                               /**< Error Address Register, slave port n, array offset: 0x10, array step: 0x8 */
    __I  uint32_t EDR;                               /**< Error Detail Register, slave port n, array offset: 0x14, array step: 0x8 */
  } SP[2];
       uint8_t RESERVED_1[992];
  __IO uint32_t WORD[8][4];                        /**< Region Descriptor n, Word 0..Region Descriptor n, Word 3, array offset: 0x400, array step: index*0x10, index2*0x4 */
       uint8_t RESERVED_2[896];
  __IO uint32_t RGDAAC[8];                         /**< Region Descriptor Alternate Access Control n, array offset: 0x800, array step: 0x4 */
} MPU_Type;

/* ----------------------------------------------------------------------------
   -- MPU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MPU_Register_Masks MPU Register Masks
 * @{
 */

/* CESR Bit Fields */
#define MPU_CESR_VLD_MASK                        0x1u
#define MPU_CESR_VLD_SHIFT                       0
#define MPU_CESR_NRGD_MASK                       0xF00u
#define MPU_CESR_NRGD_SHIFT                      8
#define MPU_CESR_NRGD(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_CESR_NRGD_SHIFT))&MPU_CESR_NRGD_MASK)
#define MPU_CESR_NSP_MASK                        0xF000u
#define MPU_CESR_NSP_SHIFT                       12
#define MPU_CESR_NSP(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_CESR_NSP_SHIFT))&MPU_CESR_NSP_MASK)
#define MPU_CESR_HRL_MASK                        0xF0000u
#define MPU_CESR_HRL_SHIFT                       16
#define MPU_CESR_HRL(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_CESR_HRL_SHIFT))&MPU_CESR_HRL_MASK)
#define MPU_CESR_SPERR_MASK                      0xC0000000u
#define MPU_CESR_SPERR_SHIFT                     30
#define MPU_CESR_SPERR(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_CESR_SPERR_SHIFT))&MPU_CESR_SPERR_MASK)
/* EAR Bit Fields */
#define MPU_EAR_EADDR_MASK                       0xFFFFFFFFu
#define MPU_EAR_EADDR_SHIFT                      0
#define MPU_EAR_EADDR(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_EAR_EADDR_SHIFT))&MPU_EAR_EADDR_MASK)
/* EDR Bit Fields */
#define MPU_EDR_ERW_MASK                         0x1u
#define MPU_EDR_ERW_SHIFT                        0
#define MPU_EDR_EATTR_MASK                       0xEu
#define MPU_EDR_EATTR_SHIFT                      1
#define MPU_EDR_EATTR(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_EDR_EATTR_SHIFT))&MPU_EDR_EATTR_MASK)
#define MPU_EDR_EMN_MASK                         0xF0u
#define MPU_EDR_EMN_SHIFT                        4
#define MPU_EDR_EMN(x)                           (((uint32_t)(((uint32_t)(x))<<MPU_EDR_EMN_SHIFT))&MPU_EDR_EMN_MASK)
#define MPU_EDR_EPID_MASK                        0xFF00u
#define MPU_EDR_EPID_SHIFT                       8
#define MPU_EDR_EPID(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_EDR_EPID_SHIFT))&MPU_EDR_EPID_MASK)
#define MPU_EDR_EACD_MASK                        0xFFFF0000u
#define MPU_EDR_EACD_SHIFT                       16
#define MPU_EDR_EACD(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_EDR_EACD_SHIFT))&MPU_EDR_EACD_MASK)
/* WORD Bit Fields */
#define MPU_WORD_VLD_MASK                        0x1u
#define MPU_WORD_VLD_SHIFT                       0
#define MPU_WORD_M0UM_MASK                       0x7u
#define MPU_WORD_M0UM_SHIFT                      0
#define MPU_WORD_M0UM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M0UM_SHIFT))&MPU_WORD_M0UM_MASK)
#define MPU_WORD_M0SM_MASK                       0x18u
#define MPU_WORD_M0SM_SHIFT                      3
#define MPU_WORD_M0SM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M0SM_SHIFT))&MPU_WORD_M0SM_MASK)
#define MPU_WORD_M0PE_MASK                       0x20u
#define MPU_WORD_M0PE_SHIFT                      5
#define MPU_WORD_ENDADDR_MASK                    0xFFFFFFE0u
#define MPU_WORD_ENDADDR_SHIFT                   5
#define MPU_WORD_ENDADDR(x)                      (((uint32_t)(((uint32_t)(x))<<MPU_WORD_ENDADDR_SHIFT))&MPU_WORD_ENDADDR_MASK)
#define MPU_WORD_SRTADDR_MASK                    0xFFFFFFE0u
#define MPU_WORD_SRTADDR_SHIFT                   5
#define MPU_WORD_SRTADDR(x)                      (((uint32_t)(((uint32_t)(x))<<MPU_WORD_SRTADDR_SHIFT))&MPU_WORD_SRTADDR_MASK)
#define MPU_WORD_M1UM_MASK                       0x1C0u
#define MPU_WORD_M1UM_SHIFT                      6
#define MPU_WORD_M1UM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M1UM_SHIFT))&MPU_WORD_M1UM_MASK)
#define MPU_WORD_M1SM_MASK                       0x600u
#define MPU_WORD_M1SM_SHIFT                      9
#define MPU_WORD_M1SM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M1SM_SHIFT))&MPU_WORD_M1SM_MASK)
#define MPU_WORD_M1PE_MASK                       0x800u
#define MPU_WORD_M1PE_SHIFT                      11
#define MPU_WORD_M2UM_MASK                       0x7000u
#define MPU_WORD_M2UM_SHIFT                      12
#define MPU_WORD_M2UM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M2UM_SHIFT))&MPU_WORD_M2UM_MASK)
#define MPU_WORD_M2SM_MASK                       0x18000u
#define MPU_WORD_M2SM_SHIFT                      15
#define MPU_WORD_M2SM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M2SM_SHIFT))&MPU_WORD_M2SM_MASK)
#define MPU_WORD_PIDMASK_MASK                    0xFF0000u
#define MPU_WORD_PIDMASK_SHIFT                   16
#define MPU_WORD_PIDMASK(x)                      (((uint32_t)(((uint32_t)(x))<<MPU_WORD_PIDMASK_SHIFT))&MPU_WORD_PIDMASK_MASK)
#define MPU_WORD_M2PE_MASK                       0x20000u
#define MPU_WORD_M2PE_SHIFT                      17
#define MPU_WORD_M3UM_MASK                       0x1C0000u
#define MPU_WORD_M3UM_SHIFT                      18
#define MPU_WORD_M3UM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M3UM_SHIFT))&MPU_WORD_M3UM_MASK)
#define MPU_WORD_M3SM_MASK                       0x600000u
#define MPU_WORD_M3SM_SHIFT                      21
#define MPU_WORD_M3SM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M3SM_SHIFT))&MPU_WORD_M3SM_MASK)
#define MPU_WORD_M3PE_MASK                       0x800000u
#define MPU_WORD_M3PE_SHIFT                      23
#define MPU_WORD_PID_MASK                        0xFF000000u
#define MPU_WORD_PID_SHIFT                       24
#define MPU_WORD_PID(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_WORD_PID_SHIFT))&MPU_WORD_PID_MASK)
#define MPU_WORD_M4WE_MASK                       0x1000000u
#define MPU_WORD_M4WE_SHIFT                      24
#define MPU_WORD_M4RE_MASK                       0x2000000u
#define MPU_WORD_M4RE_SHIFT                      25
#define MPU_WORD_M5WE_MASK                       0x4000000u
#define MPU_WORD_M5WE_SHIFT                      26
#define MPU_WORD_M5RE_MASK                       0x8000000u
#define MPU_WORD_M5RE_SHIFT                      27
#define MPU_WORD_M6WE_MASK                       0x10000000u
#define MPU_WORD_M6WE_SHIFT                      28
#define MPU_WORD_M6RE_MASK                       0x20000000u
#define MPU_WORD_M6RE_SHIFT                      29
#define MPU_WORD_M7WE_MASK                       0x40000000u
#define MPU_WORD_M7WE_SHIFT                      30
#define MPU_WORD_M7RE_MASK                       0x80000000u
#define MPU_WORD_M7RE_SHIFT                      31
/* RGDAAC Bit Fields */
#define MPU_RGDAAC_M0UM_MASK                     0x7u
#define MPU_RGDAAC_M0UM_SHIFT                    0
#define MPU_RGDAAC_M0UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M0UM_SHIFT))&MPU_RGDAAC_M0UM_MASK)
#define MPU_RGDAAC_M0SM_MASK                     0x18u
#define MPU_RGDAAC_M0SM_SHIFT                    3
#define MPU_RGDAAC_M0SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M0SM_SHIFT))&MPU_RGDAAC_M0SM_MASK)
#define MPU_RGDAAC_M0PE_MASK                     0x20u
#define MPU_RGDAAC_M0PE_SHIFT                    5
#define MPU_RGDAAC_M1UM_MASK                     0x1C0u
#define MPU_RGDAAC_M1UM_SHIFT                    6
#define MPU_RGDAAC_M1UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M1UM_SHIFT))&MPU_RGDAAC_M1UM_MASK)
#define MPU_RGDAAC_M1SM_MASK                     0x600u
#define MPU_RGDAAC_M1SM_SHIFT                    9
#define MPU_RGDAAC_M1SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M1SM_SHIFT))&MPU_RGDAAC_M1SM_MASK)
#define MPU_RGDAAC_M1PE_MASK                     0x800u
#define MPU_RGDAAC_M1PE_SHIFT                    11
#define MPU_RGDAAC_M2UM_MASK                     0x7000u
#define MPU_RGDAAC_M2UM_SHIFT                    12
#define MPU_RGDAAC_M2UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M2UM_SHIFT))&MPU_RGDAAC_M2UM_MASK)
#define MPU_RGDAAC_M2SM_MASK                     0x18000u
#define MPU_RGDAAC_M2SM_SHIFT                    15
#define MPU_RGDAAC_M2SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M2SM_SHIFT))&MPU_RGDAAC_M2SM_MASK)
#define MPU_RGDAAC_M2PE_MASK                     0x20000u
#define MPU_RGDAAC_M2PE_SHIFT                    17
#define MPU_RGDAAC_M3UM_MASK                     0x1C0000u
#define MPU_RGDAAC_M3UM_SHIFT                    18
#define MPU_RGDAAC_M3UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M3UM_SHIFT))&MPU_RGDAAC_M3UM_MASK)
#define MPU_RGDAAC_M3SM_MASK                     0x600000u
#define MPU_RGDAAC_M3SM_SHIFT                    21
#define MPU_RGDAAC_M3SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M3SM_SHIFT))&MPU_RGDAAC_M3SM_MASK)
#define MPU_RGDAAC_M3PE_MASK                     0x800000u
#define MPU_RGDAAC_M3PE_SHIFT                    23
#define MPU_RGDAAC_M4WE_MASK                     0x1000000u
#define MPU_RGDAAC_M4WE_SHIFT                    24
#define MPU_RGDAAC_M4RE_MASK                     0x2000000u
#define MPU_RGDAAC_M4RE_SHIFT                    25
#define MPU_RGDAAC_M5WE_MASK                     0x4000000u
#define MPU_RGDAAC_M5WE_SHIFT                    26
#define MPU_RGDAAC_M5RE_MASK                     0x8000000u
#define MPU_RGDAAC_M5RE_SHIFT                    27
#define MPU_RGDAAC_M6WE_MASK                     0x10000000u
#define MPU_RGDAAC_M6WE_SHIFT                    28
#define MPU_RGDAAC_M6RE_MASK                     0x20000000u
#define MPU_RGDAAC_M6RE_SHIFT                    29
#define MPU_RGDAAC_M7WE_MASK                     0x40000000u
#define MPU_RGDAAC_M7WE_SHIFT                    30
#define MPU_RGDAAC_M7RE_MASK                     0x80000000u
#define MPU_RGDAAC_M7RE_SHIFT                    31

/*!
 * @}
 */ /* end of group MPU_Register_Masks */


/* MPU - Peripheral instance base addresses */
/** Peripheral MPU base address */
#define MPU_BASE                                 (0x4000A000u)
/** Peripheral MPU base pointer */
#define MPU                                      ((MPU_Type *)MPU_BASE)
/** Array initializer of MPU peripheral base pointers */
#define MPU_BASES                                { MPU }

/*!
 * @}
 */ /* end of group MPU_Peripheral_Access_Layer */


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
} MTB_Type;

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
#define MTB_POSITION_POINTER_MASK                0xFFFFFFF8u
#define MTB_POSITION_POINTER_SHIFT               3
#define MTB_POSITION_POINTER(x)                  (((uint32_t)(((uint32_t)(x))<<MTB_POSITION_POINTER_SHIFT))&MTB_POSITION_POINTER_MASK)
/* MASTER Bit Fields */
#define MTB_MASTER_MASK_MASK                     0x1Fu
#define MTB_MASTER_MASK_SHIFT                    0
#define MTB_MASTER_MASK(x)                       (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_MASK_SHIFT))&MTB_MASTER_MASK_MASK)
#define MTB_MASTER_TSTARTEN_MASK                 0x20u
#define MTB_MASTER_TSTARTEN_SHIFT                5
#define MTB_MASTER_TSTOPEN_MASK                  0x40u
#define MTB_MASTER_TSTOPEN_SHIFT                 6
#define MTB_MASTER_SFRWPRIV_MASK                 0x80u
#define MTB_MASTER_SFRWPRIV_SHIFT                7
#define MTB_MASTER_RAMPRIV_MASK                  0x100u
#define MTB_MASTER_RAMPRIV_SHIFT                 8
#define MTB_MASTER_HALTREQ_MASK                  0x200u
#define MTB_MASTER_HALTREQ_SHIFT                 9
#define MTB_MASTER_EN_MASK                       0x80000000u
#define MTB_MASTER_EN_SHIFT                      31
/* FLOW Bit Fields */
#define MTB_FLOW_AUTOSTOP_MASK                   0x1u
#define MTB_FLOW_AUTOSTOP_SHIFT                  0
#define MTB_FLOW_AUTOHALT_MASK                   0x2u
#define MTB_FLOW_AUTOHALT_SHIFT                  1
#define MTB_FLOW_WATERMARK_MASK                  0xFFFFFFF8u
#define MTB_FLOW_WATERMARK_SHIFT                 3
#define MTB_FLOW_WATERMARK(x)                    (((uint32_t)(((uint32_t)(x))<<MTB_FLOW_WATERMARK_SHIFT))&MTB_FLOW_WATERMARK_MASK)
/* BASE Bit Fields */
#define MTB_BASE_BASEADDR_MASK                   0xFFFFFFFFu
#define MTB_BASE_BASEADDR_SHIFT                  0
#define MTB_BASE_BASEADDR(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_BASE_BASEADDR_SHIFT))&MTB_BASE_BASEADDR_MASK)
/* MODECTRL Bit Fields */
#define MTB_MODECTRL_MODECTRL_MASK               0xFFFFFFFFu
#define MTB_MODECTRL_MODECTRL_SHIFT              0
#define MTB_MODECTRL_MODECTRL(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_MODECTRL_MODECTRL_SHIFT))&MTB_MODECTRL_MODECTRL_MASK)
/* TAGSET Bit Fields */
#define MTB_TAGSET_TAGSET_MASK                   0xFFFFFFFFu
#define MTB_TAGSET_TAGSET_SHIFT                  0
#define MTB_TAGSET_TAGSET(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_TAGSET_TAGSET_SHIFT))&MTB_TAGSET_TAGSET_MASK)
/* TAGCLEAR Bit Fields */
#define MTB_TAGCLEAR_TAGCLEAR_MASK               0xFFFFFFFFu
#define MTB_TAGCLEAR_TAGCLEAR_SHIFT              0
#define MTB_TAGCLEAR_TAGCLEAR(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_TAGCLEAR_TAGCLEAR_SHIFT))&MTB_TAGCLEAR_TAGCLEAR_MASK)
/* LOCKACCESS Bit Fields */
#define MTB_LOCKACCESS_LOCKACCESS_MASK           0xFFFFFFFFu
#define MTB_LOCKACCESS_LOCKACCESS_SHIFT          0
#define MTB_LOCKACCESS_LOCKACCESS(x)             (((uint32_t)(((uint32_t)(x))<<MTB_LOCKACCESS_LOCKACCESS_SHIFT))&MTB_LOCKACCESS_LOCKACCESS_MASK)
/* LOCKSTAT Bit Fields */
#define MTB_LOCKSTAT_LOCKSTAT_MASK               0xFFFFFFFFu
#define MTB_LOCKSTAT_LOCKSTAT_SHIFT              0
#define MTB_LOCKSTAT_LOCKSTAT(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_LOCKSTAT_LOCKSTAT_SHIFT))&MTB_LOCKSTAT_LOCKSTAT_MASK)
/* AUTHSTAT Bit Fields */
#define MTB_AUTHSTAT_BIT0_MASK                   0x1u
#define MTB_AUTHSTAT_BIT0_SHIFT                  0
#define MTB_AUTHSTAT_BIT1_MASK                   0x2u
#define MTB_AUTHSTAT_BIT1_SHIFT                  1
#define MTB_AUTHSTAT_BIT2_MASK                   0x4u
#define MTB_AUTHSTAT_BIT2_SHIFT                  2
#define MTB_AUTHSTAT_BIT3_MASK                   0x8u
#define MTB_AUTHSTAT_BIT3_SHIFT                  3
/* DEVICEARCH Bit Fields */
#define MTB_DEVICEARCH_DEVICEARCH_MASK           0xFFFFFFFFu
#define MTB_DEVICEARCH_DEVICEARCH_SHIFT          0
#define MTB_DEVICEARCH_DEVICEARCH(x)             (((uint32_t)(((uint32_t)(x))<<MTB_DEVICEARCH_DEVICEARCH_SHIFT))&MTB_DEVICEARCH_DEVICEARCH_MASK)
/* DEVICECFG Bit Fields */
#define MTB_DEVICECFG_DEVICECFG_MASK             0xFFFFFFFFu
#define MTB_DEVICECFG_DEVICECFG_SHIFT            0
#define MTB_DEVICECFG_DEVICECFG(x)               (((uint32_t)(((uint32_t)(x))<<MTB_DEVICECFG_DEVICECFG_SHIFT))&MTB_DEVICECFG_DEVICECFG_MASK)
/* DEVICETYPID Bit Fields */
#define MTB_DEVICETYPID_DEVICETYPID_MASK         0xFFFFFFFFu
#define MTB_DEVICETYPID_DEVICETYPID_SHIFT        0
#define MTB_DEVICETYPID_DEVICETYPID(x)           (((uint32_t)(((uint32_t)(x))<<MTB_DEVICETYPID_DEVICETYPID_SHIFT))&MTB_DEVICETYPID_DEVICETYPID_MASK)
/* PERIPHID Bit Fields */
#define MTB_PERIPHID_PERIPHID_MASK               0xFFFFFFFFu
#define MTB_PERIPHID_PERIPHID_SHIFT              0
#define MTB_PERIPHID_PERIPHID(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_PERIPHID_PERIPHID_SHIFT))&MTB_PERIPHID_PERIPHID_MASK)
/* COMPID Bit Fields */
#define MTB_COMPID_COMPID_MASK                   0xFFFFFFFFu
#define MTB_COMPID_COMPID_SHIFT                  0
#define MTB_COMPID_COMPID(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_COMPID_COMPID_SHIFT))&MTB_COMPID_COMPID_MASK)

/*!
 * @}
 */ /* end of group MTB_Register_Masks */


/* MTB - Peripheral instance base addresses */
/** Peripheral MTB base address */
#define MTB_BASE                                 (0xF0000000u)
/** Peripheral MTB base pointer */
#define MTB                                      ((MTB_Type *)MTB_BASE)
/** Array initializer of MTB peripheral base pointers */
#define MTB_BASES                                { MTB }

/*!
 * @}
 */ /* end of group MTB_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MTBDWT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTBDWT_Peripheral_Access_Layer MTBDWT Peripheral Access Layer
 * @{
 */

/** MTBDWT - Register Layout Typedef */
typedef struct {
  __I  uint32_t CTRL;                              /**< MTB DWT Control Register, offset: 0x0 */
       uint8_t RESERVED_0[28];
  struct {                                         /* offset: 0x20, array step: 0x10 */
    __IO uint32_t COMP;                              /**< MTB_DWT Comparator Register, array offset: 0x20, array step: 0x10 */
    __IO uint32_t MASK;                              /**< MTB_DWT Comparator Mask Register, array offset: 0x24, array step: 0x10 */
    __IO uint32_t FCT;                               /**< MTB_DWT Comparator Function Register 0..MTB_DWT Comparator Function Register 1, array offset: 0x28, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } COMPARATOR[2];
       uint8_t RESERVED_1[448];
  __IO uint32_t TBCTRL;                            /**< MTB_DWT Trace Buffer Control Register, offset: 0x200 */
       uint8_t RESERVED_2[3524];
  __I  uint32_t DEVICECFG;                         /**< Device Configuration Register, offset: 0xFC8 */
  __I  uint32_t DEVICETYPID;                       /**< Device Type Identifier Register, offset: 0xFCC */
  __I  uint32_t PERIPHID[8];                       /**< Peripheral ID Register, array offset: 0xFD0, array step: 0x4 */
  __I  uint32_t COMPID[4];                         /**< Component ID Register, array offset: 0xFF0, array step: 0x4 */
} MTBDWT_Type;

/* ----------------------------------------------------------------------------
   -- MTBDWT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTBDWT_Register_Masks MTBDWT Register Masks
 * @{
 */

/* CTRL Bit Fields */
#define MTBDWT_CTRL_DWTCFGCTRL_MASK              0xFFFFFFFu
#define MTBDWT_CTRL_DWTCFGCTRL_SHIFT             0
#define MTBDWT_CTRL_DWTCFGCTRL(x)                (((uint32_t)(((uint32_t)(x))<<MTBDWT_CTRL_DWTCFGCTRL_SHIFT))&MTBDWT_CTRL_DWTCFGCTRL_MASK)
#define MTBDWT_CTRL_NUMCMP_MASK                  0xF0000000u
#define MTBDWT_CTRL_NUMCMP_SHIFT                 28
#define MTBDWT_CTRL_NUMCMP(x)                    (((uint32_t)(((uint32_t)(x))<<MTBDWT_CTRL_NUMCMP_SHIFT))&MTBDWT_CTRL_NUMCMP_MASK)
/* COMP Bit Fields */
#define MTBDWT_COMP_COMP_MASK                    0xFFFFFFFFu
#define MTBDWT_COMP_COMP_SHIFT                   0
#define MTBDWT_COMP_COMP(x)                      (((uint32_t)(((uint32_t)(x))<<MTBDWT_COMP_COMP_SHIFT))&MTBDWT_COMP_COMP_MASK)
/* MASK Bit Fields */
#define MTBDWT_MASK_MASK_MASK                    0x1Fu
#define MTBDWT_MASK_MASK_SHIFT                   0
#define MTBDWT_MASK_MASK(x)                      (((uint32_t)(((uint32_t)(x))<<MTBDWT_MASK_MASK_SHIFT))&MTBDWT_MASK_MASK_MASK)
/* FCT Bit Fields */
#define MTBDWT_FCT_FUNCTION_MASK                 0xFu
#define MTBDWT_FCT_FUNCTION_SHIFT                0
#define MTBDWT_FCT_FUNCTION(x)                   (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_FUNCTION_SHIFT))&MTBDWT_FCT_FUNCTION_MASK)
#define MTBDWT_FCT_DATAVMATCH_MASK               0x100u
#define MTBDWT_FCT_DATAVMATCH_SHIFT              8
#define MTBDWT_FCT_DATAVSIZE_MASK                0xC00u
#define MTBDWT_FCT_DATAVSIZE_SHIFT               10
#define MTBDWT_FCT_DATAVSIZE(x)                  (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_DATAVSIZE_SHIFT))&MTBDWT_FCT_DATAVSIZE_MASK)
#define MTBDWT_FCT_DATAVADDR0_MASK               0xF000u
#define MTBDWT_FCT_DATAVADDR0_SHIFT              12
#define MTBDWT_FCT_DATAVADDR0(x)                 (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_DATAVADDR0_SHIFT))&MTBDWT_FCT_DATAVADDR0_MASK)
#define MTBDWT_FCT_MATCHED_MASK                  0x1000000u
#define MTBDWT_FCT_MATCHED_SHIFT                 24
/* TBCTRL Bit Fields */
#define MTBDWT_TBCTRL_ACOMP0_MASK                0x1u
#define MTBDWT_TBCTRL_ACOMP0_SHIFT               0
#define MTBDWT_TBCTRL_ACOMP1_MASK                0x2u
#define MTBDWT_TBCTRL_ACOMP1_SHIFT               1
#define MTBDWT_TBCTRL_NUMCOMP_MASK               0xF0000000u
#define MTBDWT_TBCTRL_NUMCOMP_SHIFT              28
#define MTBDWT_TBCTRL_NUMCOMP(x)                 (((uint32_t)(((uint32_t)(x))<<MTBDWT_TBCTRL_NUMCOMP_SHIFT))&MTBDWT_TBCTRL_NUMCOMP_MASK)
/* DEVICECFG Bit Fields */
#define MTBDWT_DEVICECFG_DEVICECFG_MASK          0xFFFFFFFFu
#define MTBDWT_DEVICECFG_DEVICECFG_SHIFT         0
#define MTBDWT_DEVICECFG_DEVICECFG(x)            (((uint32_t)(((uint32_t)(x))<<MTBDWT_DEVICECFG_DEVICECFG_SHIFT))&MTBDWT_DEVICECFG_DEVICECFG_MASK)
/* DEVICETYPID Bit Fields */
#define MTBDWT_DEVICETYPID_DEVICETYPID_MASK      0xFFFFFFFFu
#define MTBDWT_DEVICETYPID_DEVICETYPID_SHIFT     0
#define MTBDWT_DEVICETYPID_DEVICETYPID(x)        (((uint32_t)(((uint32_t)(x))<<MTBDWT_DEVICETYPID_DEVICETYPID_SHIFT))&MTBDWT_DEVICETYPID_DEVICETYPID_MASK)
/* PERIPHID Bit Fields */
#define MTBDWT_PERIPHID_PERIPHID_MASK            0xFFFFFFFFu
#define MTBDWT_PERIPHID_PERIPHID_SHIFT           0
#define MTBDWT_PERIPHID_PERIPHID(x)              (((uint32_t)(((uint32_t)(x))<<MTBDWT_PERIPHID_PERIPHID_SHIFT))&MTBDWT_PERIPHID_PERIPHID_MASK)
/* COMPID Bit Fields */
#define MTBDWT_COMPID_COMPID_MASK                0xFFFFFFFFu
#define MTBDWT_COMPID_COMPID_SHIFT               0
#define MTBDWT_COMPID_COMPID(x)                  (((uint32_t)(((uint32_t)(x))<<MTBDWT_COMPID_COMPID_SHIFT))&MTBDWT_COMPID_COMPID_MASK)

/*!
 * @}
 */ /* end of group MTBDWT_Register_Masks */


/* MTBDWT - Peripheral instance base addresses */
/** Peripheral MTBDWT base address */
#define MTBDWT_BASE                              (0xF0001000u)
/** Peripheral MTBDWT base pointer */
#define MTBDWT                                   ((MTBDWT_Type *)MTBDWT_BASE)
/** Array initializer of MTBDWT peripheral base pointers */
#define MTBDWT_BASES                             { MTBDWT }

/*!
 * @}
 */ /* end of group MTBDWT_Peripheral_Access_Layer */


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
} NV_Type;

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
#define NV_BACKKEY3_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY3_KEY_SHIFT))&NV_BACKKEY3_KEY_MASK)
/* BACKKEY2 Bit Fields */
#define NV_BACKKEY2_KEY_MASK                     0xFFu
#define NV_BACKKEY2_KEY_SHIFT                    0
#define NV_BACKKEY2_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY2_KEY_SHIFT))&NV_BACKKEY2_KEY_MASK)
/* BACKKEY1 Bit Fields */
#define NV_BACKKEY1_KEY_MASK                     0xFFu
#define NV_BACKKEY1_KEY_SHIFT                    0
#define NV_BACKKEY1_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY1_KEY_SHIFT))&NV_BACKKEY1_KEY_MASK)
/* BACKKEY0 Bit Fields */
#define NV_BACKKEY0_KEY_MASK                     0xFFu
#define NV_BACKKEY0_KEY_SHIFT                    0
#define NV_BACKKEY0_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY0_KEY_SHIFT))&NV_BACKKEY0_KEY_MASK)
/* BACKKEY7 Bit Fields */
#define NV_BACKKEY7_KEY_MASK                     0xFFu
#define NV_BACKKEY7_KEY_SHIFT                    0
#define NV_BACKKEY7_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY7_KEY_SHIFT))&NV_BACKKEY7_KEY_MASK)
/* BACKKEY6 Bit Fields */
#define NV_BACKKEY6_KEY_MASK                     0xFFu
#define NV_BACKKEY6_KEY_SHIFT                    0
#define NV_BACKKEY6_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY6_KEY_SHIFT))&NV_BACKKEY6_KEY_MASK)
/* BACKKEY5 Bit Fields */
#define NV_BACKKEY5_KEY_MASK                     0xFFu
#define NV_BACKKEY5_KEY_SHIFT                    0
#define NV_BACKKEY5_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY5_KEY_SHIFT))&NV_BACKKEY5_KEY_MASK)
/* BACKKEY4 Bit Fields */
#define NV_BACKKEY4_KEY_MASK                     0xFFu
#define NV_BACKKEY4_KEY_SHIFT                    0
#define NV_BACKKEY4_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY4_KEY_SHIFT))&NV_BACKKEY4_KEY_MASK)
/* FPROT3 Bit Fields */
#define NV_FPROT3_PROT_MASK                      0xFFu
#define NV_FPROT3_PROT_SHIFT                     0
#define NV_FPROT3_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT3_PROT_SHIFT))&NV_FPROT3_PROT_MASK)
/* FPROT2 Bit Fields */
#define NV_FPROT2_PROT_MASK                      0xFFu
#define NV_FPROT2_PROT_SHIFT                     0
#define NV_FPROT2_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT2_PROT_SHIFT))&NV_FPROT2_PROT_MASK)
/* FPROT1 Bit Fields */
#define NV_FPROT1_PROT_MASK                      0xFFu
#define NV_FPROT1_PROT_SHIFT                     0
#define NV_FPROT1_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT1_PROT_SHIFT))&NV_FPROT1_PROT_MASK)
/* FPROT0 Bit Fields */
#define NV_FPROT0_PROT_MASK                      0xFFu
#define NV_FPROT0_PROT_SHIFT                     0
#define NV_FPROT0_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT0_PROT_SHIFT))&NV_FPROT0_PROT_MASK)
/* FSEC Bit Fields */
#define NV_FSEC_SEC_MASK                         0x3u
#define NV_FSEC_SEC_SHIFT                        0
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<NV_FSEC_SEC_SHIFT))&NV_FSEC_SEC_MASK)
#define NV_FSEC_FSLACC_MASK                      0xCu
#define NV_FSEC_FSLACC_SHIFT                     2
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FSEC_FSLACC_SHIFT))&NV_FSEC_FSLACC_MASK)
#define NV_FSEC_MEEN_MASK                        0x30u
#define NV_FSEC_MEEN_SHIFT                       4
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x))<<NV_FSEC_MEEN_SHIFT))&NV_FSEC_MEEN_MASK)
#define NV_FSEC_KEYEN_MASK                       0xC0u
#define NV_FSEC_KEYEN_SHIFT                      6
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FSEC_KEYEN_SHIFT))&NV_FSEC_KEYEN_MASK)
/* FOPT Bit Fields */
#define NV_FOPT_LPBOOT_MASK                      0x1u
#define NV_FOPT_LPBOOT_SHIFT                     0
#define NV_FOPT_NMI_EN_MASK                      0x4u
#define NV_FOPT_NMI_EN_SHIFT                     2
#define NV_FOPT_EXE_MODE_MASK                    0x8u
#define NV_FOPT_EXE_MODE_SHIFT                   3
#define NV_FOPT_CLK_SRC_MASK                     0x20u
#define NV_FOPT_CLK_SRC_SHIFT                    5

/*!
 * @}
 */ /* end of group NV_Register_Masks */


/* NV - Peripheral instance base addresses */
/** Peripheral FTFA_FlashConfig base address */
#define FTFA_FlashConfig_BASE                    (0x400u)
/** Peripheral FTFA_FlashConfig base pointer */
#define FTFA_FlashConfig                         ((NV_Type *)FTFA_FlashConfig_BASE)
/** Array initializer of NV peripheral base pointers */
#define NV_BASES                                 { FTFA_FlashConfig }

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
} OSC_Type;

/* ----------------------------------------------------------------------------
   -- OSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Register_Masks OSC Register Masks
 * @{
 */

/* CR Bit Fields */
#define OSC_CR_SC16P_MASK                        0x1u
#define OSC_CR_SC16P_SHIFT                       0
#define OSC_CR_SC8P_MASK                         0x2u
#define OSC_CR_SC8P_SHIFT                        1
#define OSC_CR_SC4P_MASK                         0x4u
#define OSC_CR_SC4P_SHIFT                        2
#define OSC_CR_SC2P_MASK                         0x8u
#define OSC_CR_SC2P_SHIFT                        3
#define OSC_CR_EREFSTEN_MASK                     0x20u
#define OSC_CR_EREFSTEN_SHIFT                    5
#define OSC_CR_ERCLKEN_MASK                      0x80u
#define OSC_CR_ERCLKEN_SHIFT                     7

/*!
 * @}
 */ /* end of group OSC_Register_Masks */


/* OSC - Peripheral instance base addresses */
/** Peripheral OSC base address */
#define OSC_BASE                                 (0x40066000u)
/** Peripheral OSC base pointer */
#define OSC                                      ((OSC_Type *)OSC_BASE)
/** Array initializer of OSC peripheral base pointers */
#define OSC_BASES                                { OSC }

/*!
 * @}
 */ /* end of group OSC_Peripheral_Access_Layer */


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
} PIT_Type;

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
/** Peripheral PIT0 base address */
#define PIT0_BASE                                (0x4002D000u)
/** Peripheral PIT0 base pointer */
#define PIT0                                     ((PIT_Type *)PIT0_BASE)
/** Peripheral PIT1 base address */
#define PIT1_BASE                                (0x4002E000u)
/** Peripheral PIT1 base pointer */
#define PIT1                                     ((PIT_Type *)PIT1_BASE)
/** Array initializer of PIT peripheral base pointers */
#define PIT_BASES                                { PIT0, PIT1 }

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
  __IO uint8_t LVDSC1;                             /**< Low Voltage Detect Status And Control 1 register, offset: 0x0 */
  __IO uint8_t LVDSC2;                             /**< Low Voltage Detect Status And Control 2 register, offset: 0x1 */
  __IO uint8_t REGSC;                              /**< Regulator Status And Control register, offset: 0x2 */
} PMC_Type;

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/* LVDSC1 Bit Fields */
#define PMC_LVDSC1_LVDV_MASK                     0x3u
#define PMC_LVDSC1_LVDV_SHIFT                    0
#define PMC_LVDSC1_LVDV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDV_SHIFT))&PMC_LVDSC1_LVDV_MASK)
#define PMC_LVDSC1_LVDRE_MASK                    0x10u
#define PMC_LVDSC1_LVDRE_SHIFT                   4
#define PMC_LVDSC1_LVDIE_MASK                    0x20u
#define PMC_LVDSC1_LVDIE_SHIFT                   5
#define PMC_LVDSC1_LVDACK_MASK                   0x40u
#define PMC_LVDSC1_LVDACK_SHIFT                  6
#define PMC_LVDSC1_LVDF_MASK                     0x80u
#define PMC_LVDSC1_LVDF_SHIFT                    7
/* LVDSC2 Bit Fields */
#define PMC_LVDSC2_LVWV_MASK                     0x3u
#define PMC_LVDSC2_LVWV_SHIFT                    0
#define PMC_LVDSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWV_SHIFT))&PMC_LVDSC2_LVWV_MASK)
#define PMC_LVDSC2_LVWIE_MASK                    0x20u
#define PMC_LVDSC2_LVWIE_SHIFT                   5
#define PMC_LVDSC2_LVWACK_MASK                   0x40u
#define PMC_LVDSC2_LVWACK_SHIFT                  6
#define PMC_LVDSC2_LVWF_MASK                     0x80u
#define PMC_LVDSC2_LVWF_SHIFT                    7
/* REGSC Bit Fields */
#define PMC_REGSC_BGBE_MASK                      0x1u
#define PMC_REGSC_BGBE_SHIFT                     0
#define PMC_REGSC_BGBDS_MASK                     0x2u
#define PMC_REGSC_BGBDS_SHIFT                    1
#define PMC_REGSC_REGONS_MASK                    0x4u
#define PMC_REGSC_REGONS_SHIFT                   2
#define PMC_REGSC_ACKISO_MASK                    0x8u
#define PMC_REGSC_ACKISO_SHIFT                   3
#define PMC_REGSC_BGEN_MASK                      0x10u
#define PMC_REGSC_BGEN_SHIFT                     4

/*!
 * @}
 */ /* end of group PMC_Register_Masks */


/* PMC - Peripheral instance base addresses */
/** Peripheral PMC base address */
#define PMC_BASE                                 (0x4007D000u)
/** Peripheral PMC base pointer */
#define PMC                                      ((PMC_Type *)PMC_BASE)
/** Array initializer of PMC peripheral base pointers */
#define PMC_BASES                                { PMC }

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
  __IO uint32_t PCR[8];                            /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[96];
  __O  uint32_t GPCLR;                             /**< Global Pin Control Low Register, offset: 0x80 */
  __O  uint32_t GPCHR;                             /**< Global Pin Control High Register, offset: 0x84 */
       uint8_t RESERVED_1[24];
  __IO uint32_t ISFR;                              /**< Interrupt Status Flag Register, offset: 0xA0 */
       uint8_t RESERVED_2[28];
  __IO uint32_t DFER;                              /**< Digital Filter Enable Register, offset: 0xC0 */
  __IO uint32_t DFCR;                              /**< Digital Filter Clock Register, offset: 0xC4 */
  __IO uint32_t DFWR;                              /**< Digital Filter Width Register, offset: 0xC8 */
} PORT_Type;

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
#define PORT_PCR_PE_MASK                         0x2u
#define PORT_PCR_PE_SHIFT                        1
#define PORT_PCR_SRE_MASK                        0x4u
#define PORT_PCR_SRE_SHIFT                       2
#define PORT_PCR_MUX_MASK                        0x700u
#define PORT_PCR_MUX_SHIFT                       8
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_MUX_SHIFT))&PORT_PCR_MUX_MASK)
#define PORT_PCR_LK_MASK                         0x8000u
#define PORT_PCR_LK_SHIFT                        15
#define PORT_PCR_IRQC_MASK                       0xF0000u
#define PORT_PCR_IRQC_SHIFT                      16
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_PCR_IRQC_SHIFT))&PORT_PCR_IRQC_MASK)
#define PORT_PCR_ISF_MASK                        0x1000000u
#define PORT_PCR_ISF_SHIFT                       24
/* GPCLR Bit Fields */
#define PORT_GPCLR_GPWD_MASK                     0xFFFFu
#define PORT_GPCLR_GPWD_SHIFT                    0
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWD_SHIFT))&PORT_GPCLR_GPWD_MASK)
#define PORT_GPCLR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCLR_GPWE_SHIFT                    16
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWE_SHIFT))&PORT_GPCLR_GPWE_MASK)
/* GPCHR Bit Fields */
#define PORT_GPCHR_GPWD_MASK                     0xFFFFu
#define PORT_GPCHR_GPWD_SHIFT                    0
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWD_SHIFT))&PORT_GPCHR_GPWD_MASK)
#define PORT_GPCHR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCHR_GPWE_SHIFT                    16
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWE_SHIFT))&PORT_GPCHR_GPWE_MASK)
/* ISFR Bit Fields */
#define PORT_ISFR_ISF_MASK                       0xFFFFFFFFu
#define PORT_ISFR_ISF_SHIFT                      0
#define PORT_ISFR_ISF(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_ISFR_ISF_SHIFT))&PORT_ISFR_ISF_MASK)
/* DFER Bit Fields */
#define PORT_DFER_DFE_MASK                       0xFFFFFFFFu
#define PORT_DFER_DFE_SHIFT                      0
#define PORT_DFER_DFE(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_DFER_DFE_SHIFT))&PORT_DFER_DFE_MASK)
/* DFCR Bit Fields */
#define PORT_DFCR_CS_MASK                        0x1u
#define PORT_DFCR_CS_SHIFT                       0
/* DFWR Bit Fields */
#define PORT_DFWR_FILT_MASK                      0x1Fu
#define PORT_DFWR_FILT_SHIFT                     0
#define PORT_DFWR_FILT(x)                        (((uint32_t)(((uint32_t)(x))<<PORT_DFWR_FILT_SHIFT))&PORT_DFWR_FILT_MASK)

/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE                               (0x40046000u)
/** Peripheral PORTA base pointer */
#define PORTA                                    ((PORT_Type *)PORTA_BASE)
/** Peripheral PORTB base address */
#define PORTB_BASE                               (0x40047000u)
/** Peripheral PORTB base pointer */
#define PORTB                                    ((PORT_Type *)PORTB_BASE)
/** Peripheral PORTC base address */
#define PORTC_BASE                               (0x40048000u)
/** Peripheral PORTC base pointer */
#define PORTC                                    ((PORT_Type *)PORTC_BASE)
/** Peripheral PORTD base address */
#define PORTD_BASE                               (0x40049000u)
/** Peripheral PORTD base pointer */
#define PORTD                                    ((PORT_Type *)PORTD_BASE)
/** Peripheral PORTE base address */
#define PORTE_BASE                               (0x4004A000u)
/** Peripheral PORTE base pointer */
#define PORTE                                    ((PORT_Type *)PORTE_BASE)
/** Peripheral PORTF base address */
#define PORTF_BASE                               (0x4004B000u)
/** Peripheral PORTF base pointer */
#define PORTF                                    ((PORT_Type *)PORTF_BASE)
/** Peripheral PORTG base address */
#define PORTG_BASE                               (0x4004C000u)
/** Peripheral PORTG base pointer */
#define PORTG                                    ((PORT_Type *)PORTG_BASE)
/** Peripheral PORTH base address */
#define PORTH_BASE                               (0x4004D000u)
/** Peripheral PORTH base pointer */
#define PORTH                                    ((PORT_Type *)PORTH_BASE)
/** Peripheral PORTI base address */
#define PORTI_BASE                               (0x4004E000u)
/** Peripheral PORTI base pointer */
#define PORTI                                    ((PORT_Type *)PORTI_BASE)
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASES                               { PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG, PORTH, PORTI }

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
  __I  uint8_t SRS0;                               /**< System Reset Status Register 0, offset: 0x0 */
  __I  uint8_t SRS1;                               /**< System Reset Status Register 1, offset: 0x1 */
       uint8_t RESERVED_0[2];
  __IO uint8_t RPFC;                               /**< Reset Pin Filter Control register, offset: 0x4 */
  __IO uint8_t RPFW;                               /**< Reset Pin Filter Width register, offset: 0x5 */
} RCM_Type;

/* ----------------------------------------------------------------------------
   -- RCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Register_Masks RCM Register Masks
 * @{
 */

/* SRS0 Bit Fields */
#define RCM_SRS0_WAKEUP_MASK                     0x1u
#define RCM_SRS0_WAKEUP_SHIFT                    0
#define RCM_SRS0_LVD_MASK                        0x2u
#define RCM_SRS0_LVD_SHIFT                       1
#define RCM_SRS0_LOC_MASK                        0x4u
#define RCM_SRS0_LOC_SHIFT                       2
#define RCM_SRS0_LOL_MASK                        0x8u
#define RCM_SRS0_LOL_SHIFT                       3
#define RCM_SRS0_WDOG_MASK                       0x20u
#define RCM_SRS0_WDOG_SHIFT                      5
#define RCM_SRS0_PIN_MASK                        0x40u
#define RCM_SRS0_PIN_SHIFT                       6
#define RCM_SRS0_POR_MASK                        0x80u
#define RCM_SRS0_POR_SHIFT                       7
/* SRS1 Bit Fields */
#define RCM_SRS1_LOCKUP_MASK                     0x2u
#define RCM_SRS1_LOCKUP_SHIFT                    1
#define RCM_SRS1_SW_MASK                         0x4u
#define RCM_SRS1_SW_SHIFT                        2
#define RCM_SRS1_MDM_AP_MASK                     0x8u
#define RCM_SRS1_MDM_AP_SHIFT                    3
#define RCM_SRS1_SACKERR_MASK                    0x20u
#define RCM_SRS1_SACKERR_SHIFT                   5
/* RPFC Bit Fields */
#define RCM_RPFC_RSTFLTSRW_MASK                  0x3u
#define RCM_RPFC_RSTFLTSRW_SHIFT                 0
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSRW_SHIFT))&RCM_RPFC_RSTFLTSRW_MASK)
#define RCM_RPFC_RSTFLTSS_MASK                   0x4u
#define RCM_RPFC_RSTFLTSS_SHIFT                  2
/* RPFW Bit Fields */
#define RCM_RPFW_RSTFLTSEL_MASK                  0x1Fu
#define RCM_RPFW_RSTFLTSEL_SHIFT                 0
#define RCM_RPFW_RSTFLTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFW_RSTFLTSEL_SHIFT))&RCM_RPFW_RSTFLTSEL_MASK)

/*!
 * @}
 */ /* end of group RCM_Register_Masks */


/* RCM - Peripheral instance base addresses */
/** Peripheral RCM base address */
#define RCM_BASE                                 (0x4007B000u)
/** Peripheral RCM base pointer */
#define RCM                                      ((RCM_Type *)RCM_BASE)
/** Array initializer of RCM peripheral base pointers */
#define RCM_BASES                                { RCM }

/*!
 * @}
 */ /* end of group RCM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RNG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RNG_Peripheral_Access_Layer RNG Peripheral Access Layer
 * @{
 */

/** RNG - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< RNGA Control Register, offset: 0x0 */
  __I  uint32_t SR;                                /**< RNGA Status Register, offset: 0x4 */
  __O  uint32_t ER;                                /**< RNGA Entropy Register, offset: 0x8 */
  __I  uint32_t OR;                                /**< RNGA Output Register, offset: 0xC */
} RNG_Type;

/* ----------------------------------------------------------------------------
   -- RNG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RNG_Register_Masks RNG Register Masks
 * @{
 */

/* CR Bit Fields */
#define RNG_CR_GO_MASK                           0x1u
#define RNG_CR_GO_SHIFT                          0
#define RNG_CR_HA_MASK                           0x2u
#define RNG_CR_HA_SHIFT                          1
#define RNG_CR_INTM_MASK                         0x4u
#define RNG_CR_INTM_SHIFT                        2
#define RNG_CR_CLRI_MASK                         0x8u
#define RNG_CR_CLRI_SHIFT                        3
#define RNG_CR_SLP_MASK                          0x10u
#define RNG_CR_SLP_SHIFT                         4
/* SR Bit Fields */
#define RNG_SR_SECV_MASK                         0x1u
#define RNG_SR_SECV_SHIFT                        0
#define RNG_SR_LRS_MASK                          0x2u
#define RNG_SR_LRS_SHIFT                         1
#define RNG_SR_ORU_MASK                          0x4u
#define RNG_SR_ORU_SHIFT                         2
#define RNG_SR_ERRI_MASK                         0x8u
#define RNG_SR_ERRI_SHIFT                        3
#define RNG_SR_SLP_MASK                          0x10u
#define RNG_SR_SLP_SHIFT                         4
#define RNG_SR_OREG_LVL_MASK                     0xFF00u
#define RNG_SR_OREG_LVL_SHIFT                    8
#define RNG_SR_OREG_LVL(x)                       (((uint32_t)(((uint32_t)(x))<<RNG_SR_OREG_LVL_SHIFT))&RNG_SR_OREG_LVL_MASK)
#define RNG_SR_OREG_SIZE_MASK                    0xFF0000u
#define RNG_SR_OREG_SIZE_SHIFT                   16
#define RNG_SR_OREG_SIZE(x)                      (((uint32_t)(((uint32_t)(x))<<RNG_SR_OREG_SIZE_SHIFT))&RNG_SR_OREG_SIZE_MASK)
/* ER Bit Fields */
#define RNG_ER_EXT_ENT_MASK                      0xFFFFFFFFu
#define RNG_ER_EXT_ENT_SHIFT                     0
#define RNG_ER_EXT_ENT(x)                        (((uint32_t)(((uint32_t)(x))<<RNG_ER_EXT_ENT_SHIFT))&RNG_ER_EXT_ENT_MASK)
/* OR Bit Fields */
#define RNG_OR_RANDOUT_MASK                      0xFFFFFFFFu
#define RNG_OR_RANDOUT_SHIFT                     0
#define RNG_OR_RANDOUT(x)                        (((uint32_t)(((uint32_t)(x))<<RNG_OR_RANDOUT_SHIFT))&RNG_OR_RANDOUT_MASK)

/*!
 * @}
 */ /* end of group RNG_Register_Masks */


/* RNG - Peripheral instance base addresses */
/** Peripheral RNG base address */
#define RNG_BASE                                 (0x40029000u)
/** Peripheral RNG base pointer */
#define RNG                                      ((RNG_Type *)RNG_BASE)
/** Array initializer of RNG peripheral base pointers */
#define RNG_BASES                                { RNG }

/*!
 * @}
 */ /* end of group RNG_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- ROM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROM_Peripheral_Access_Layer ROM Peripheral Access Layer
 * @{
 */

/** ROM - Register Layout Typedef */
typedef struct {
  __I  uint32_t ENTRY[3];                          /**< Entry, array offset: 0x0, array step: 0x4 */
  __I  uint32_t TABLEMARK;                         /**< End of Table Marker Register, offset: 0xC */
       uint8_t RESERVED_0[4028];
  __I  uint32_t SYSACCESS;                         /**< System Access Register, offset: 0xFCC */
  __I  uint32_t PERIPHID4;                         /**< Peripheral ID Register, offset: 0xFD0 */
  __I  uint32_t PERIPHID5;                         /**< Peripheral ID Register, offset: 0xFD4 */
  __I  uint32_t PERIPHID6;                         /**< Peripheral ID Register, offset: 0xFD8 */
  __I  uint32_t PERIPHID7;                         /**< Peripheral ID Register, offset: 0xFDC */
  __I  uint32_t PERIPHID0;                         /**< Peripheral ID Register, offset: 0xFE0 */
  __I  uint32_t PERIPHID1;                         /**< Peripheral ID Register, offset: 0xFE4 */
  __I  uint32_t PERIPHID2;                         /**< Peripheral ID Register, offset: 0xFE8 */
  __I  uint32_t PERIPHID3;                         /**< Peripheral ID Register, offset: 0xFEC */
  __I  uint32_t COMPID[4];                         /**< Component ID Register, array offset: 0xFF0, array step: 0x4 */
} ROM_Type;

/* ----------------------------------------------------------------------------
   -- ROM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROM_Register_Masks ROM Register Masks
 * @{
 */

/* ENTRY Bit Fields */
#define ROM_ENTRY_ENTRY_MASK                     0xFFFFFFFFu
#define ROM_ENTRY_ENTRY_SHIFT                    0
#define ROM_ENTRY_ENTRY(x)                       (((uint32_t)(((uint32_t)(x))<<ROM_ENTRY_ENTRY_SHIFT))&ROM_ENTRY_ENTRY_MASK)
/* TABLEMARK Bit Fields */
#define ROM_TABLEMARK_MARK_MASK                  0xFFFFFFFFu
#define ROM_TABLEMARK_MARK_SHIFT                 0
#define ROM_TABLEMARK_MARK(x)                    (((uint32_t)(((uint32_t)(x))<<ROM_TABLEMARK_MARK_SHIFT))&ROM_TABLEMARK_MARK_MASK)
/* SYSACCESS Bit Fields */
#define ROM_SYSACCESS_SYSACCESS_MASK             0xFFFFFFFFu
#define ROM_SYSACCESS_SYSACCESS_SHIFT            0
#define ROM_SYSACCESS_SYSACCESS(x)               (((uint32_t)(((uint32_t)(x))<<ROM_SYSACCESS_SYSACCESS_SHIFT))&ROM_SYSACCESS_SYSACCESS_MASK)
/* PERIPHID4 Bit Fields */
#define ROM_PERIPHID4_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID4_PERIPHID_SHIFT             0
#define ROM_PERIPHID4_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID4_PERIPHID_SHIFT))&ROM_PERIPHID4_PERIPHID_MASK)
/* PERIPHID5 Bit Fields */
#define ROM_PERIPHID5_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID5_PERIPHID_SHIFT             0
#define ROM_PERIPHID5_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID5_PERIPHID_SHIFT))&ROM_PERIPHID5_PERIPHID_MASK)
/* PERIPHID6 Bit Fields */
#define ROM_PERIPHID6_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID6_PERIPHID_SHIFT             0
#define ROM_PERIPHID6_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID6_PERIPHID_SHIFT))&ROM_PERIPHID6_PERIPHID_MASK)
/* PERIPHID7 Bit Fields */
#define ROM_PERIPHID7_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID7_PERIPHID_SHIFT             0
#define ROM_PERIPHID7_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID7_PERIPHID_SHIFT))&ROM_PERIPHID7_PERIPHID_MASK)
/* PERIPHID0 Bit Fields */
#define ROM_PERIPHID0_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID0_PERIPHID_SHIFT             0
#define ROM_PERIPHID0_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID0_PERIPHID_SHIFT))&ROM_PERIPHID0_PERIPHID_MASK)
/* PERIPHID1 Bit Fields */
#define ROM_PERIPHID1_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID1_PERIPHID_SHIFT             0
#define ROM_PERIPHID1_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID1_PERIPHID_SHIFT))&ROM_PERIPHID1_PERIPHID_MASK)
/* PERIPHID2 Bit Fields */
#define ROM_PERIPHID2_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID2_PERIPHID_SHIFT             0
#define ROM_PERIPHID2_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID2_PERIPHID_SHIFT))&ROM_PERIPHID2_PERIPHID_MASK)
/* PERIPHID3 Bit Fields */
#define ROM_PERIPHID3_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID3_PERIPHID_SHIFT             0
#define ROM_PERIPHID3_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID3_PERIPHID_SHIFT))&ROM_PERIPHID3_PERIPHID_MASK)
/* COMPID Bit Fields */
#define ROM_COMPID_COMPID_MASK                   0xFFFFFFFFu
#define ROM_COMPID_COMPID_SHIFT                  0
#define ROM_COMPID_COMPID(x)                     (((uint32_t)(((uint32_t)(x))<<ROM_COMPID_COMPID_SHIFT))&ROM_COMPID_COMPID_MASK)

/*!
 * @}
 */ /* end of group ROM_Register_Masks */


/* ROM - Peripheral instance base addresses */
/** Peripheral ROM base address */
#define ROM_BASE                                 (0xF0002000u)
/** Peripheral ROM base pointer */
#define ROM                                      ((ROM_Type *)ROM_BASE)
/** Array initializer of ROM peripheral base pointers */
#define ROM_BASES                                { ROM }

/*!
 * @}
 */ /* end of group ROM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */

/** RTC - Register Layout Typedef */
typedef struct {
  __IO uint16_t YEARMON;                           /**< RTC Year and Month Counters Register, offset: 0x0 */
  __IO uint16_t DAYS;                              /**< RTC Days and Day-of-Week Counters Register, offset: 0x2 */
  __IO uint16_t HOURMIN;                           /**< RTC Hours and Minutes Counters Register, offset: 0x4 */
  __IO uint16_t SECONDS;                           /**< RTC Seconds Counters Register, offset: 0x6 */
  __IO uint16_t ALM_YEARMON;                       /**< RTC Year and Months Alarm Register, offset: 0x8 */
  __IO uint16_t ALM_DAYS;                          /**< RTC Days Alarm Register, offset: 0xA */
  __IO uint16_t ALM_HOURMIN;                       /**< RTC Hours and Minutes Alarm Register, offset: 0xC */
  __IO uint16_t ALM_SECONDS;                       /**< RTC Seconds Alarm Register, offset: 0xE */
  __IO uint16_t CTRL;                              /**< RTC Control Register, offset: 0x10 */
  __IO uint16_t STATUS;                            /**< RTC Status Register, offset: 0x12 */
  __IO uint16_t ISR;                               /**< RTC Interrupt Status Register, offset: 0x14 */
  __IO uint16_t IER;                               /**< RTC Interrupt Enable Register, offset: 0x16 */
       uint8_t RESERVED_0[8];
  __IO uint16_t GP_DATA_REG;                       /**< RTC General Purpose Data Register, offset: 0x20 */
  __IO uint16_t DST_HOUR;                          /**< RTC Daylight Saving Hour Register, offset: 0x22 */
  __IO uint16_t DST_MONTH;                         /**< RTC Daylight Saving Month Register, offset: 0x24 */
  __IO uint16_t DST_DAY;                           /**< RTC Daylight Saving Day Register, offset: 0x26 */
  __IO uint16_t COMPEN;                            /**< RTC Compensation Register, offset: 0x28 */
       uint8_t RESERVED_1[2];
  __IO uint16_t TAMPER_DIRECTION;                  /**< Tamper Direction Register, offset: 0x2C */
  __IO uint16_t TAMPER_QSCR;                       /**< Tamper Queue Status and Control Register, offset: 0x2E */
       uint8_t RESERVED_2[2];
  __IO uint16_t TAMPER_SCR;                        /**< RTC Tamper Status and Control Register, offset: 0x32 */
  __IO uint16_t FILTER01_CFG;                      /**< RTC Tamper 0 1 Filter Configuration Register, offset: 0x34 */
  __IO uint16_t FILTER2_CFG;                       /**< RTC Tamper 2 Filter Configuration Register, offset: 0x36 */
       uint8_t RESERVED_3[8];
  __I  uint16_t TAMPER_QUEUE;                      /**< Tamper Queue Register, offset: 0x40 */
  __IO uint16_t CTRL2;                             /**< RTC Control 2 Register, offset: 0x42 */
} RTC_Type;

/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/* YEARMON Bit Fields */
#define RTC_YEARMON_MON_CNT_MASK                 0xFu
#define RTC_YEARMON_MON_CNT_SHIFT                0
#define RTC_YEARMON_MON_CNT(x)                   (((uint16_t)(((uint16_t)(x))<<RTC_YEARMON_MON_CNT_SHIFT))&RTC_YEARMON_MON_CNT_MASK)
#define RTC_YEARMON_YROFST_MASK                  0xFF00u
#define RTC_YEARMON_YROFST_SHIFT                 8
#define RTC_YEARMON_YROFST(x)                    (((uint16_t)(((uint16_t)(x))<<RTC_YEARMON_YROFST_SHIFT))&RTC_YEARMON_YROFST_MASK)
/* DAYS Bit Fields */
#define RTC_DAYS_DAY_CNT_MASK                    0x1Fu
#define RTC_DAYS_DAY_CNT_SHIFT                   0
#define RTC_DAYS_DAY_CNT(x)                      (((uint16_t)(((uint16_t)(x))<<RTC_DAYS_DAY_CNT_SHIFT))&RTC_DAYS_DAY_CNT_MASK)
#define RTC_DAYS_DOW_MASK                        0x700u
#define RTC_DAYS_DOW_SHIFT                       8
#define RTC_DAYS_DOW(x)                          (((uint16_t)(((uint16_t)(x))<<RTC_DAYS_DOW_SHIFT))&RTC_DAYS_DOW_MASK)
/* HOURMIN Bit Fields */
#define RTC_HOURMIN_MIN_CNT_MASK                 0x3Fu
#define RTC_HOURMIN_MIN_CNT_SHIFT                0
#define RTC_HOURMIN_MIN_CNT(x)                   (((uint16_t)(((uint16_t)(x))<<RTC_HOURMIN_MIN_CNT_SHIFT))&RTC_HOURMIN_MIN_CNT_MASK)
#define RTC_HOURMIN_HOUR_CNT_MASK                0x1F00u
#define RTC_HOURMIN_HOUR_CNT_SHIFT               8
#define RTC_HOURMIN_HOUR_CNT(x)                  (((uint16_t)(((uint16_t)(x))<<RTC_HOURMIN_HOUR_CNT_SHIFT))&RTC_HOURMIN_HOUR_CNT_MASK)
/* SECONDS Bit Fields */
#define RTC_SECONDS_SEC_CNT_MASK                 0x3Fu
#define RTC_SECONDS_SEC_CNT_SHIFT                0
#define RTC_SECONDS_SEC_CNT(x)                   (((uint16_t)(((uint16_t)(x))<<RTC_SECONDS_SEC_CNT_SHIFT))&RTC_SECONDS_SEC_CNT_MASK)
/* ALM_YEARMON Bit Fields */
#define RTC_ALM_YEARMON_ALM_MON_MASK             0xFu
#define RTC_ALM_YEARMON_ALM_MON_SHIFT            0
#define RTC_ALM_YEARMON_ALM_MON(x)               (((uint16_t)(((uint16_t)(x))<<RTC_ALM_YEARMON_ALM_MON_SHIFT))&RTC_ALM_YEARMON_ALM_MON_MASK)
#define RTC_ALM_YEARMON_ALM_YEAR_MASK            0xFF00u
#define RTC_ALM_YEARMON_ALM_YEAR_SHIFT           8
#define RTC_ALM_YEARMON_ALM_YEAR(x)              (((uint16_t)(((uint16_t)(x))<<RTC_ALM_YEARMON_ALM_YEAR_SHIFT))&RTC_ALM_YEARMON_ALM_YEAR_MASK)
/* ALM_DAYS Bit Fields */
#define RTC_ALM_DAYS_ALM_DAY_MASK                0x1Fu
#define RTC_ALM_DAYS_ALM_DAY_SHIFT               0
#define RTC_ALM_DAYS_ALM_DAY(x)                  (((uint16_t)(((uint16_t)(x))<<RTC_ALM_DAYS_ALM_DAY_SHIFT))&RTC_ALM_DAYS_ALM_DAY_MASK)
/* ALM_HOURMIN Bit Fields */
#define RTC_ALM_HOURMIN_ALM_MIN_MASK             0x3Fu
#define RTC_ALM_HOURMIN_ALM_MIN_SHIFT            0
#define RTC_ALM_HOURMIN_ALM_MIN(x)               (((uint16_t)(((uint16_t)(x))<<RTC_ALM_HOURMIN_ALM_MIN_SHIFT))&RTC_ALM_HOURMIN_ALM_MIN_MASK)
#define RTC_ALM_HOURMIN_ALM_HOUR_MASK            0x1F00u
#define RTC_ALM_HOURMIN_ALM_HOUR_SHIFT           8
#define RTC_ALM_HOURMIN_ALM_HOUR(x)              (((uint16_t)(((uint16_t)(x))<<RTC_ALM_HOURMIN_ALM_HOUR_SHIFT))&RTC_ALM_HOURMIN_ALM_HOUR_MASK)
/* ALM_SECONDS Bit Fields */
#define RTC_ALM_SECONDS_ALM_SEC_MASK             0x3Fu
#define RTC_ALM_SECONDS_ALM_SEC_SHIFT            0
#define RTC_ALM_SECONDS_ALM_SEC(x)               (((uint16_t)(((uint16_t)(x))<<RTC_ALM_SECONDS_ALM_SEC_SHIFT))&RTC_ALM_SECONDS_ALM_SEC_MASK)
#define RTC_ALM_SECONDS_DEC_SEC_MASK             0x100u
#define RTC_ALM_SECONDS_DEC_SEC_SHIFT            8
#define RTC_ALM_SECONDS_INC_SEC_MASK             0x200u
#define RTC_ALM_SECONDS_INC_SEC_SHIFT            9
/* CTRL Bit Fields */
#define RTC_CTRL_FINEEN_MASK                     0x1u
#define RTC_CTRL_FINEEN_SHIFT                    0
#define RTC_CTRL_COMP_EN_MASK                    0x2u
#define RTC_CTRL_COMP_EN_SHIFT                   1
#define RTC_CTRL_ALM_MATCH_MASK                  0xCu
#define RTC_CTRL_ALM_MATCH_SHIFT                 2
#define RTC_CTRL_ALM_MATCH(x)                    (((uint16_t)(((uint16_t)(x))<<RTC_CTRL_ALM_MATCH_SHIFT))&RTC_CTRL_ALM_MATCH_MASK)
#define RTC_CTRL_TIMER_STB_MASK_MASK             0x10u
#define RTC_CTRL_TIMER_STB_MASK_SHIFT            4
#define RTC_CTRL_DST_EN_MASK                     0x40u
#define RTC_CTRL_DST_EN_SHIFT                    6
#define RTC_CTRL_SWR_MASK                        0x100u
#define RTC_CTRL_SWR_SHIFT                       8
#define RTC_CTRL_CLKOUT_MASK                     0x6000u
#define RTC_CTRL_CLKOUT_SHIFT                    13
#define RTC_CTRL_CLKOUT(x)                       (((uint16_t)(((uint16_t)(x))<<RTC_CTRL_CLKOUT_SHIFT))&RTC_CTRL_CLKOUT_MASK)
/* STATUS Bit Fields */
#define RTC_STATUS_INVAL_BIT_MASK                0x1u
#define RTC_STATUS_INVAL_BIT_SHIFT               0
#define RTC_STATUS_WRITE_PROT_EN_MASK            0x2u
#define RTC_STATUS_WRITE_PROT_EN_SHIFT           1
#define RTC_STATUS_CPU_LOW_VOLT_MASK             0x4u
#define RTC_STATUS_CPU_LOW_VOLT_SHIFT            2
#define RTC_STATUS_RST_SRC_MASK                  0x8u
#define RTC_STATUS_RST_SRC_SHIFT                 3
#define RTC_STATUS_CMP_INT_MASK                  0x20u
#define RTC_STATUS_CMP_INT_SHIFT                 5
#define RTC_STATUS_WE_MASK                       0xC0u
#define RTC_STATUS_WE_SHIFT                      6
#define RTC_STATUS_WE(x)                         (((uint16_t)(((uint16_t)(x))<<RTC_STATUS_WE_SHIFT))&RTC_STATUS_WE_MASK)
#define RTC_STATUS_BUS_ERR_MASK                  0x100u
#define RTC_STATUS_BUS_ERR_SHIFT                 8
#define RTC_STATUS_CMP_DONE_MASK                 0x800u
#define RTC_STATUS_CMP_DONE_SHIFT                11
/* ISR Bit Fields */
#define RTC_ISR_TAMPER_IS_MASK                   0x1u
#define RTC_ISR_TAMPER_IS_SHIFT                  0
#define RTC_ISR_ALM_IS_MASK                      0x4u
#define RTC_ISR_ALM_IS_SHIFT                     2
#define RTC_ISR_DAY_IS_MASK                      0x8u
#define RTC_ISR_DAY_IS_SHIFT                     3
#define RTC_ISR_HOUR_IS_MASK                     0x10u
#define RTC_ISR_HOUR_IS_SHIFT                    4
#define RTC_ISR_MIN_IS_MASK                      0x20u
#define RTC_ISR_MIN_IS_SHIFT                     5
#define RTC_ISR_IS_1HZ_MASK                      0x40u
#define RTC_ISR_IS_1HZ_SHIFT                     6
#define RTC_ISR_IS_2HZ_MASK                      0x80u
#define RTC_ISR_IS_2HZ_SHIFT                     7
#define RTC_ISR_IS_4HZ_MASK                      0x100u
#define RTC_ISR_IS_4HZ_SHIFT                     8
#define RTC_ISR_IS_8HZ_MASK                      0x200u
#define RTC_ISR_IS_8HZ_SHIFT                     9
#define RTC_ISR_IS_16HZ_MASK                     0x400u
#define RTC_ISR_IS_16HZ_SHIFT                    10
#define RTC_ISR_IS_32HZ_MASK                     0x800u
#define RTC_ISR_IS_32HZ_SHIFT                    11
#define RTC_ISR_IS_64HZ_MASK                     0x1000u
#define RTC_ISR_IS_64HZ_SHIFT                    12
#define RTC_ISR_IS_128HZ_MASK                    0x2000u
#define RTC_ISR_IS_128HZ_SHIFT                   13
#define RTC_ISR_IS_256HZ_MASK                    0x4000u
#define RTC_ISR_IS_256HZ_SHIFT                   14
#define RTC_ISR_IS_512HZ_MASK                    0x8000u
#define RTC_ISR_IS_512HZ_SHIFT                   15
/* IER Bit Fields */
#define RTC_IER_TAMPER_IE_MASK                   0x1u
#define RTC_IER_TAMPER_IE_SHIFT                  0
#define RTC_IER_ALM_IE_MASK                      0x4u
#define RTC_IER_ALM_IE_SHIFT                     2
#define RTC_IER_DAY_IE_MASK                      0x8u
#define RTC_IER_DAY_IE_SHIFT                     3
#define RTC_IER_HOUR_IE_MASK                     0x10u
#define RTC_IER_HOUR_IE_SHIFT                    4
#define RTC_IER_MIN_IE_MASK                      0x20u
#define RTC_IER_MIN_IE_SHIFT                     5
#define RTC_IER_IE_1HZ_MASK                      0x40u
#define RTC_IER_IE_1HZ_SHIFT                     6
#define RTC_IER_IE_2HZ_MASK                      0x80u
#define RTC_IER_IE_2HZ_SHIFT                     7
#define RTC_IER_IE_4HZ_MASK                      0x100u
#define RTC_IER_IE_4HZ_SHIFT                     8
#define RTC_IER_IE_8HZ_MASK                      0x200u
#define RTC_IER_IE_8HZ_SHIFT                     9
#define RTC_IER_IE_16HZ_MASK                     0x400u
#define RTC_IER_IE_16HZ_SHIFT                    10
#define RTC_IER_IE_32HZ_MASK                     0x800u
#define RTC_IER_IE_32HZ_SHIFT                    11
#define RTC_IER_IE_64HZ_MASK                     0x1000u
#define RTC_IER_IE_64HZ_SHIFT                    12
#define RTC_IER_IE_128HZ_MASK                    0x2000u
#define RTC_IER_IE_128HZ_SHIFT                   13
#define RTC_IER_IE_256HZ_MASK                    0x4000u
#define RTC_IER_IE_256HZ_SHIFT                   14
#define RTC_IER_IE_512HZ_MASK                    0x8000u
#define RTC_IER_IE_512HZ_SHIFT                   15
/* GP_DATA_REG Bit Fields */
#define RTC_GP_DATA_REG_GP_DATA_REG_MASK         0xFFFFu
#define RTC_GP_DATA_REG_GP_DATA_REG_SHIFT        0
#define RTC_GP_DATA_REG_GP_DATA_REG(x)           (((uint16_t)(((uint16_t)(x))<<RTC_GP_DATA_REG_GP_DATA_REG_SHIFT))&RTC_GP_DATA_REG_GP_DATA_REG_MASK)
/* DST_HOUR Bit Fields */
#define RTC_DST_HOUR_DST_END_HOUR_MASK           0x1Fu
#define RTC_DST_HOUR_DST_END_HOUR_SHIFT          0
#define RTC_DST_HOUR_DST_END_HOUR(x)             (((uint16_t)(((uint16_t)(x))<<RTC_DST_HOUR_DST_END_HOUR_SHIFT))&RTC_DST_HOUR_DST_END_HOUR_MASK)
#define RTC_DST_HOUR_DST_START_HOUR_MASK         0x1F00u
#define RTC_DST_HOUR_DST_START_HOUR_SHIFT        8
#define RTC_DST_HOUR_DST_START_HOUR(x)           (((uint16_t)(((uint16_t)(x))<<RTC_DST_HOUR_DST_START_HOUR_SHIFT))&RTC_DST_HOUR_DST_START_HOUR_MASK)
/* DST_MONTH Bit Fields */
#define RTC_DST_MONTH_DST_END_MONTH_MASK         0xFu
#define RTC_DST_MONTH_DST_END_MONTH_SHIFT        0
#define RTC_DST_MONTH_DST_END_MONTH(x)           (((uint16_t)(((uint16_t)(x))<<RTC_DST_MONTH_DST_END_MONTH_SHIFT))&RTC_DST_MONTH_DST_END_MONTH_MASK)
#define RTC_DST_MONTH_DST_START_MONTH_MASK       0xF00u
#define RTC_DST_MONTH_DST_START_MONTH_SHIFT      8
#define RTC_DST_MONTH_DST_START_MONTH(x)         (((uint16_t)(((uint16_t)(x))<<RTC_DST_MONTH_DST_START_MONTH_SHIFT))&RTC_DST_MONTH_DST_START_MONTH_MASK)
/* DST_DAY Bit Fields */
#define RTC_DST_DAY_DST_END_DAY_MASK             0x1Fu
#define RTC_DST_DAY_DST_END_DAY_SHIFT            0
#define RTC_DST_DAY_DST_END_DAY(x)               (((uint16_t)(((uint16_t)(x))<<RTC_DST_DAY_DST_END_DAY_SHIFT))&RTC_DST_DAY_DST_END_DAY_MASK)
#define RTC_DST_DAY_DST_START_DAY_MASK           0x1F00u
#define RTC_DST_DAY_DST_START_DAY_SHIFT          8
#define RTC_DST_DAY_DST_START_DAY(x)             (((uint16_t)(((uint16_t)(x))<<RTC_DST_DAY_DST_START_DAY_SHIFT))&RTC_DST_DAY_DST_START_DAY_MASK)
/* COMPEN Bit Fields */
#define RTC_COMPEN_COMPEN_VAL_MASK               0xFFFFu
#define RTC_COMPEN_COMPEN_VAL_SHIFT              0
#define RTC_COMPEN_COMPEN_VAL(x)                 (((uint16_t)(((uint16_t)(x))<<RTC_COMPEN_COMPEN_VAL_SHIFT))&RTC_COMPEN_COMPEN_VAL_MASK)
/* TAMPER_DIRECTION Bit Fields */
#define RTC_TAMPER_DIRECTION_A_P_TAMP_MASK       0xFu
#define RTC_TAMPER_DIRECTION_A_P_TAMP_SHIFT      0
#define RTC_TAMPER_DIRECTION_A_P_TAMP(x)         (((uint16_t)(((uint16_t)(x))<<RTC_TAMPER_DIRECTION_A_P_TAMP_SHIFT))&RTC_TAMPER_DIRECTION_A_P_TAMP_MASK)
#define RTC_TAMPER_DIRECTION_I_O_TAMP_MASK       0xF00u
#define RTC_TAMPER_DIRECTION_I_O_TAMP_SHIFT      8
#define RTC_TAMPER_DIRECTION_I_O_TAMP(x)         (((uint16_t)(((uint16_t)(x))<<RTC_TAMPER_DIRECTION_I_O_TAMP_SHIFT))&RTC_TAMPER_DIRECTION_I_O_TAMP_MASK)
/* TAMPER_QSCR Bit Fields */
#define RTC_TAMPER_QSCR_Q_FULL_MASK              0x1u
#define RTC_TAMPER_QSCR_Q_FULL_SHIFT             0
#define RTC_TAMPER_QSCR_Q_FULL_INT_EN_MASK       0x2u
#define RTC_TAMPER_QSCR_Q_FULL_INT_EN_SHIFT      1
#define RTC_TAMPER_QSCR_Q_CLEAR_MASK             0x4u
#define RTC_TAMPER_QSCR_Q_CLEAR_SHIFT            2
#define RTC_TAMPER_QSCR_LFSR_CLK_SEL_MASK        0x700u
#define RTC_TAMPER_QSCR_LFSR_CLK_SEL_SHIFT       8
#define RTC_TAMPER_QSCR_LFSR_CLK_SEL(x)          (((uint16_t)(((uint16_t)(x))<<RTC_TAMPER_QSCR_LFSR_CLK_SEL_SHIFT))&RTC_TAMPER_QSCR_LFSR_CLK_SEL_MASK)
#define RTC_TAMPER_QSCR_LFSR_DURATION_MASK       0xF000u
#define RTC_TAMPER_QSCR_LFSR_DURATION_SHIFT      12
#define RTC_TAMPER_QSCR_LFSR_DURATION(x)         (((uint16_t)(((uint16_t)(x))<<RTC_TAMPER_QSCR_LFSR_DURATION_SHIFT))&RTC_TAMPER_QSCR_LFSR_DURATION_MASK)
/* TAMPER_SCR Bit Fields */
#define RTC_TAMPER_SCR_TMPR_EN_MASK              0xFu
#define RTC_TAMPER_SCR_TMPR_EN_SHIFT             0
#define RTC_TAMPER_SCR_TMPR_EN(x)                (((uint16_t)(((uint16_t)(x))<<RTC_TAMPER_SCR_TMPR_EN_SHIFT))&RTC_TAMPER_SCR_TMPR_EN_MASK)
#define RTC_TAMPER_SCR_TMPR_STS_MASK             0xF00u
#define RTC_TAMPER_SCR_TMPR_STS_SHIFT            8
#define RTC_TAMPER_SCR_TMPR_STS(x)               (((uint16_t)(((uint16_t)(x))<<RTC_TAMPER_SCR_TMPR_STS_SHIFT))&RTC_TAMPER_SCR_TMPR_STS_MASK)
/* FILTER01_CFG Bit Fields */
#define RTC_FILTER01_CFG_FIL_DUR1_MASK           0xFu
#define RTC_FILTER01_CFG_FIL_DUR1_SHIFT          0
#define RTC_FILTER01_CFG_FIL_DUR1(x)             (((uint16_t)(((uint16_t)(x))<<RTC_FILTER01_CFG_FIL_DUR1_SHIFT))&RTC_FILTER01_CFG_FIL_DUR1_MASK)
#define RTC_FILTER01_CFG_CLK_SEL1_MASK           0x70u
#define RTC_FILTER01_CFG_CLK_SEL1_SHIFT          4
#define RTC_FILTER01_CFG_CLK_SEL1(x)             (((uint16_t)(((uint16_t)(x))<<RTC_FILTER01_CFG_CLK_SEL1_SHIFT))&RTC_FILTER01_CFG_CLK_SEL1_MASK)
#define RTC_FILTER01_CFG_POL1_MASK               0x80u
#define RTC_FILTER01_CFG_POL1_SHIFT              7
#define RTC_FILTER01_CFG_FIL_DUR0_MASK           0xF00u
#define RTC_FILTER01_CFG_FIL_DUR0_SHIFT          8
#define RTC_FILTER01_CFG_FIL_DUR0(x)             (((uint16_t)(((uint16_t)(x))<<RTC_FILTER01_CFG_FIL_DUR0_SHIFT))&RTC_FILTER01_CFG_FIL_DUR0_MASK)
#define RTC_FILTER01_CFG_CLK_SEL0_MASK           0x7000u
#define RTC_FILTER01_CFG_CLK_SEL0_SHIFT          12
#define RTC_FILTER01_CFG_CLK_SEL0(x)             (((uint16_t)(((uint16_t)(x))<<RTC_FILTER01_CFG_CLK_SEL0_SHIFT))&RTC_FILTER01_CFG_CLK_SEL0_MASK)
#define RTC_FILTER01_CFG_POL0_MASK               0x8000u
#define RTC_FILTER01_CFG_POL0_SHIFT              15
/* FILTER2_CFG Bit Fields */
#define RTC_FILTER2_CFG_FIL_DUR2_MASK            0xF00u
#define RTC_FILTER2_CFG_FIL_DUR2_SHIFT           8
#define RTC_FILTER2_CFG_FIL_DUR2(x)              (((uint16_t)(((uint16_t)(x))<<RTC_FILTER2_CFG_FIL_DUR2_SHIFT))&RTC_FILTER2_CFG_FIL_DUR2_MASK)
#define RTC_FILTER2_CFG_CLK_SEL2_MASK            0x7000u
#define RTC_FILTER2_CFG_CLK_SEL2_SHIFT           12
#define RTC_FILTER2_CFG_CLK_SEL2(x)              (((uint16_t)(((uint16_t)(x))<<RTC_FILTER2_CFG_CLK_SEL2_SHIFT))&RTC_FILTER2_CFG_CLK_SEL2_MASK)
#define RTC_FILTER2_CFG_POL2_MASK                0x8000u
#define RTC_FILTER2_CFG_POL2_SHIFT               15
/* TAMPER_QUEUE Bit Fields */
#define RTC_TAMPER_QUEUE_TAMPER_DATA_MASK        0xFFFFu
#define RTC_TAMPER_QUEUE_TAMPER_DATA_SHIFT       0
#define RTC_TAMPER_QUEUE_TAMPER_DATA(x)          (((uint16_t)(((uint16_t)(x))<<RTC_TAMPER_QUEUE_TAMPER_DATA_SHIFT))&RTC_TAMPER_QUEUE_TAMPER_DATA_MASK)
/* CTRL2 Bit Fields */
#define RTC_CTRL2_TAMP_CFG_OVER_MASK             0x1u
#define RTC_CTRL2_TAMP_CFG_OVER_SHIFT            0
#define RTC_CTRL2_WAKEUP_STATUS_MASK             0x60u
#define RTC_CTRL2_WAKEUP_STATUS_SHIFT            5
#define RTC_CTRL2_WAKEUP_STATUS(x)               (((uint16_t)(((uint16_t)(x))<<RTC_CTRL2_WAKEUP_STATUS_SHIFT))&RTC_CTRL2_WAKEUP_STATUS_MASK)
#define RTC_CTRL2_WAKEUP_MODE_MASK               0x80u
#define RTC_CTRL2_WAKEUP_MODE_SHIFT              7

/*!
 * @}
 */ /* end of group RTC_Register_Masks */


/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define RTC_BASE                                 (0x40050000u)
/** Peripheral RTC base pointer */
#define RTC                                      ((RTC_Type *)RTC_BASE)
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASES                                { RTC }

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
  __IO uint32_t SOPT1;                             /**< System Options Register 1, offset: 0x0 */
  __IO uint32_t SOPT1_CFG;                         /**< SOPT1 Configuration Register, offset: 0x4 */
       uint8_t RESERVED_0[4092];
  __IO uint32_t CTRL_REG;                          /**< System Control Register, offset: 0x1004 */
       uint8_t RESERVED_1[28];
  __I  uint32_t SDID;                              /**< System Device Identification Register, offset: 0x1024 */
       uint8_t RESERVED_2[12];
  __IO uint32_t SCGC4;                             /**< System Clock Gating Control Register 4, offset: 0x1034 */
  __IO uint32_t SCGC5;                             /**< System Clock Gating Control Register 5, offset: 0x1038 */
  __IO uint32_t SCGC6;                             /**< System Clock Gating Control Register 6, offset: 0x103C */
  __IO uint32_t SCGC7;                             /**< System Clock Gating Control Register 7, offset: 0x1040 */
  __IO uint32_t CLKDIV1;                           /**< System Clock Divider Register 1, offset: 0x1044 */
       uint8_t RESERVED_3[4];
  __IO uint32_t FCFG1;                             /**< Flash Configuration Register 1, offset: 0x104C */
  __I  uint32_t FCFG2;                             /**< Flash Configuration Register 2, offset: 0x1050 */
  __I  uint32_t UID0;                              /**< Unique Identification Register 0, offset: 0x1054 */
  __I  uint32_t UID1;                              /**< Unique Identification Register 1, offset: 0x1058 */
  __I  uint32_t UID2;                              /**< Unique Identification Register 2, offset: 0x105C */
  __I  uint32_t UID3;                              /**< Unique Identification Register 3, offset: 0x1060 */
       uint8_t RESERVED_4[8];
  __IO uint32_t MISC_CTL;                          /**< Miscellaneous Control Register, offset: 0x106C */
} SIM_Type;

/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/* SOPT1 Bit Fields */
#define SIM_SOPT1_SRAMSIZE_MASK                  0xF000u
#define SIM_SOPT1_SRAMSIZE_SHIFT                 12
#define SIM_SOPT1_SRAMSIZE(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_SRAMSIZE_SHIFT))&SIM_SOPT1_SRAMSIZE_MASK)
#define SIM_SOPT1_OSC32KSEL_MASK                 0xC0000u
#define SIM_SOPT1_OSC32KSEL_SHIFT                18
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_OSC32KSEL_SHIFT))&SIM_SOPT1_OSC32KSEL_MASK)
/* SOPT1_CFG Bit Fields */
#define SIM_SOPT1_CFG_LPTMR1SEL_MASK             0x3u
#define SIM_SOPT1_CFG_LPTMR1SEL_SHIFT            0
#define SIM_SOPT1_CFG_LPTMR1SEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_CFG_LPTMR1SEL_SHIFT))&SIM_SOPT1_CFG_LPTMR1SEL_MASK)
#define SIM_SOPT1_CFG_LPTMR2SEL_MASK             0xCu
#define SIM_SOPT1_CFG_LPTMR2SEL_SHIFT            2
#define SIM_SOPT1_CFG_LPTMR2SEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_CFG_LPTMR2SEL_SHIFT))&SIM_SOPT1_CFG_LPTMR2SEL_MASK)
#define SIM_SOPT1_CFG_LPTMR3SEL_MASK             0x30u
#define SIM_SOPT1_CFG_LPTMR3SEL_SHIFT            4
#define SIM_SOPT1_CFG_LPTMR3SEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_CFG_LPTMR3SEL_SHIFT))&SIM_SOPT1_CFG_LPTMR3SEL_MASK)
#define SIM_SOPT1_CFG_CMPOLPTMR0SEL_MASK         0x40u
#define SIM_SOPT1_CFG_CMPOLPTMR0SEL_SHIFT        6
#define SIM_SOPT1_CFG_RAMSBDIS_MASK              0x100u
#define SIM_SOPT1_CFG_RAMSBDIS_SHIFT             8
#define SIM_SOPT1_CFG_RAMBPEN_MASK               0x200u
#define SIM_SOPT1_CFG_RAMBPEN_SHIFT              9
/* CTRL_REG Bit Fields */
#define SIM_CTRL_REG_NMIDIS_MASK                 0x1u
#define SIM_CTRL_REG_NMIDIS_SHIFT                0
#define SIM_CTRL_REG_PLL_VLP_EN_MASK             0x2u
#define SIM_CTRL_REG_PLL_VLP_EN_SHIFT            1
#define SIM_CTRL_REG_PTC2_HD_EN_MASK             0x4u
#define SIM_CTRL_REG_PTC2_HD_EN_SHIFT            2
#define SIM_CTRL_REG_SAR_TRG_CLK_SEL_MASK        0x18u
#define SIM_CTRL_REG_SAR_TRG_CLK_SEL_SHIFT       3
#define SIM_CTRL_REG_SAR_TRG_CLK_SEL(x)          (((uint32_t)(((uint32_t)(x))<<SIM_CTRL_REG_SAR_TRG_CLK_SEL_SHIFT))&SIM_CTRL_REG_SAR_TRG_CLK_SEL_MASK)
#define SIM_CTRL_REG_CLKOUTSEL_MASK              0xE0u
#define SIM_CTRL_REG_CLKOUTSEL_SHIFT             5
#define SIM_CTRL_REG_CLKOUTSEL(x)                (((uint32_t)(((uint32_t)(x))<<SIM_CTRL_REG_CLKOUTSEL_SHIFT))&SIM_CTRL_REG_CLKOUTSEL_MASK)
/* SDID Bit Fields */
#define SIM_SDID_PINID_MASK                      0xFu
#define SIM_SDID_PINID_SHIFT                     0
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_PINID_SHIFT))&SIM_SDID_PINID_MASK)
#define SIM_SDID_DIEID_MASK                      0xF0u
#define SIM_SDID_DIEID_SHIFT                     4
#define SIM_SDID_DIEID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_DIEID_SHIFT))&SIM_SDID_DIEID_MASK)
#define SIM_SDID_REVID_MASK                      0xF00u
#define SIM_SDID_REVID_SHIFT                     8
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_REVID_SHIFT))&SIM_SDID_REVID_MASK)
#define SIM_SDID_SRAMSIZE_MASK                   0xF000u
#define SIM_SDID_SRAMSIZE_SHIFT                  12
#define SIM_SDID_SRAMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SRAMSIZE_SHIFT))&SIM_SDID_SRAMSIZE_MASK)
#define SIM_SDID_ATTR_MASK                       0xF0000u
#define SIM_SDID_ATTR_SHIFT                      16
#define SIM_SDID_ATTR(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SDID_ATTR_SHIFT))&SIM_SDID_ATTR_MASK)
#define SIM_SDID_SERIESID_MASK                   0xF00000u
#define SIM_SDID_SERIESID_SHIFT                  20
#define SIM_SDID_SERIESID(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SERIESID_SHIFT))&SIM_SDID_SERIESID_MASK)
#define SIM_SDID_SUBFAMID_MASK                   0xF000000u
#define SIM_SDID_SUBFAMID_SHIFT                  24
#define SIM_SDID_SUBFAMID(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SUBFAMID_SHIFT))&SIM_SDID_SUBFAMID_MASK)
#define SIM_SDID_FAMID_MASK                      0xF0000000u
#define SIM_SDID_FAMID_SHIFT                     28
#define SIM_SDID_FAMID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_FAMID_SHIFT))&SIM_SDID_FAMID_MASK)
/* SCGC4 Bit Fields */
#define SIM_SCGC4_EWM_MASK                       0x2u
#define SIM_SCGC4_EWM_SHIFT                      1
#define SIM_SCGC4_MCG_MASK                       0x10u
#define SIM_SCGC4_MCG_SHIFT                      4
#define SIM_SCGC4_OSC_MASK                       0x40u
#define SIM_SCGC4_OSC_SHIFT                      6
#define SIM_SCGC4_I2C0_MASK                      0x80u
#define SIM_SCGC4_I2C0_SHIFT                     7
#define SIM_SCGC4_I2C1_MASK                      0x100u
#define SIM_SCGC4_I2C1_SHIFT                     8
#define SIM_SCGC4_UART0_MASK                     0x400u
#define SIM_SCGC4_UART0_SHIFT                    10
#define SIM_SCGC4_UART1_MASK                     0x800u
#define SIM_SCGC4_UART1_SHIFT                    11
#define SIM_SCGC4_UART2_MASK                     0x1000u
#define SIM_SCGC4_UART2_SHIFT                    12
#define SIM_SCGC4_UART3_MASK                     0x2000u
#define SIM_SCGC4_UART3_SHIFT                    13
#define SIM_SCGC4_VREF_MASK                      0x8000u
#define SIM_SCGC4_VREF_SHIFT                     15
#define SIM_SCGC4_CMP0_MASK                      0x40000u
#define SIM_SCGC4_CMP0_SHIFT                     18
#define SIM_SCGC4_CMP1_MASK                      0x80000u
#define SIM_SCGC4_CMP1_SHIFT                     19
#define SIM_SCGC4_SPI0_MASK                      0x200000u
#define SIM_SCGC4_SPI0_SHIFT                     21
#define SIM_SCGC4_SPI1_MASK                      0x400000u
#define SIM_SCGC4_SPI1_SHIFT                     22
/* SCGC5 Bit Fields */
#define SIM_SCGC5_SLCD_MASK                      0x8u
#define SIM_SCGC5_SLCD_SHIFT                     3
#define SIM_SCGC5_PORTA_MASK                     0x40u
#define SIM_SCGC5_PORTA_SHIFT                    6
#define SIM_SCGC5_PORTB_MASK                     0x80u
#define SIM_SCGC5_PORTB_SHIFT                    7
#define SIM_SCGC5_PORTC_MASK                     0x100u
#define SIM_SCGC5_PORTC_SHIFT                    8
#define SIM_SCGC5_PORTD_MASK                     0x200u
#define SIM_SCGC5_PORTD_SHIFT                    9
#define SIM_SCGC5_PORTE_MASK                     0x400u
#define SIM_SCGC5_PORTE_SHIFT                    10
#define SIM_SCGC5_PORTF_MASK                     0x800u
#define SIM_SCGC5_PORTF_SHIFT                    11
#define SIM_SCGC5_PORTG_MASK                     0x1000u
#define SIM_SCGC5_PORTG_SHIFT                    12
#define SIM_SCGC5_PORTH_MASK                     0x2000u
#define SIM_SCGC5_PORTH_SHIFT                    13
#define SIM_SCGC5_PORTI_MASK                     0x4000u
#define SIM_SCGC5_PORTI_SHIFT                    14
#define SIM_SCGC5_IRTC_MASK                      0x10000u
#define SIM_SCGC5_IRTC_SHIFT                     16
#define SIM_SCGC5_IRTCREGFILE_MASK               0x20000u
#define SIM_SCGC5_IRTCREGFILE_SHIFT              17
#define SIM_SCGC5_WDOG_MASK                      0x80000u
#define SIM_SCGC5_WDOG_SHIFT                     19
#define SIM_SCGC5_XBAR_MASK                      0x200000u
#define SIM_SCGC5_XBAR_SHIFT                     21
#define SIM_SCGC5_TMR0_MASK                      0x800000u
#define SIM_SCGC5_TMR0_SHIFT                     23
#define SIM_SCGC5_TMR1_MASK                      0x1000000u
#define SIM_SCGC5_TMR1_SHIFT                     24
#define SIM_SCGC5_TMR2_MASK                      0x2000000u
#define SIM_SCGC5_TMR2_SHIFT                     25
#define SIM_SCGC5_TMR3_MASK                      0x4000000u
#define SIM_SCGC5_TMR3_SHIFT                     26
/* SCGC6 Bit Fields */
#define SIM_SCGC6_FTFA_MASK                      0x1u
#define SIM_SCGC6_FTFA_SHIFT                     0
#define SIM_SCGC6_DMAMUX0_MASK                   0x2u
#define SIM_SCGC6_DMAMUX0_SHIFT                  1
#define SIM_SCGC6_DMAMUX1_MASK                   0x4u
#define SIM_SCGC6_DMAMUX1_SHIFT                  2
#define SIM_SCGC6_DMAMUX2_MASK                   0x8u
#define SIM_SCGC6_DMAMUX2_SHIFT                  3
#define SIM_SCGC6_DMAMUX3_MASK                   0x10u
#define SIM_SCGC6_DMAMUX3_SHIFT                  4
#define SIM_SCGC6_RNGA_MASK                      0x200u
#define SIM_SCGC6_RNGA_SHIFT                     9
#define SIM_SCGC6_ADC_MASK                       0x800u
#define SIM_SCGC6_ADC_SHIFT                      11
#define SIM_SCGC6_PIT0_MASK                      0x2000u
#define SIM_SCGC6_PIT0_SHIFT                     13
#define SIM_SCGC6_PIT1_MASK                      0x4000u
#define SIM_SCGC6_PIT1_SHIFT                     14
#define SIM_SCGC6_AFE_MASK                       0x10000u
#define SIM_SCGC6_AFE_SHIFT                      16
#define SIM_SCGC6_CRC_MASK                       0x100000u
#define SIM_SCGC6_CRC_SHIFT                      20
#define SIM_SCGC6_LPTMR_MASK                     0x10000000u
#define SIM_SCGC6_LPTMR_SHIFT                    28
#define SIM_SCGC6_SIM_LP_MASK                    0x40000000u
#define SIM_SCGC6_SIM_LP_SHIFT                   30
#define SIM_SCGC6_SIM_HP_MASK                    0x80000000u
#define SIM_SCGC6_SIM_HP_SHIFT                   31
/* SCGC7 Bit Fields */
#define SIM_SCGC7_MPU_MASK                       0x1u
#define SIM_SCGC7_MPU_SHIFT                      0
#define SIM_SCGC7_DMA_MASK                       0x2u
#define SIM_SCGC7_DMA_SHIFT                      1
/* CLKDIV1 Bit Fields */
#define SIM_CLKDIV1_SYSCLKMODE_MASK              0x8000000u
#define SIM_CLKDIV1_SYSCLKMODE_SHIFT             27
#define SIM_CLKDIV1_SYSDIV_MASK                  0xF0000000u
#define SIM_CLKDIV1_SYSDIV_SHIFT                 28
#define SIM_CLKDIV1_SYSDIV(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_SYSDIV_SHIFT))&SIM_CLKDIV1_SYSDIV_MASK)
/* FCFG1 Bit Fields */
#define SIM_FCFG1_FLASHDIS_MASK                  0x1u
#define SIM_FCFG1_FLASHDIS_SHIFT                 0
#define SIM_FCFG1_FLASHDOZE_MASK                 0x2u
#define SIM_FCFG1_FLASHDOZE_SHIFT                1
#define SIM_FCFG1_PFSIZE_MASK                    0xF000000u
#define SIM_FCFG1_PFSIZE_SHIFT                   24
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_PFSIZE_SHIFT))&SIM_FCFG1_PFSIZE_MASK)
/* FCFG2 Bit Fields */
#define SIM_FCFG2_MAXADDR_MASK                   0x7F000000u
#define SIM_FCFG2_MAXADDR_SHIFT                  24
#define SIM_FCFG2_MAXADDR(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR_SHIFT))&SIM_FCFG2_MAXADDR_MASK)
/* UID0 Bit Fields */
#define SIM_UID0_UID_MASK                        0xFFFFFFFFu
#define SIM_UID0_UID_SHIFT                       0
#define SIM_UID0_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UID0_UID_SHIFT))&SIM_UID0_UID_MASK)
/* UID1 Bit Fields */
#define SIM_UID1_UID_MASK                        0xFFFFFFFFu
#define SIM_UID1_UID_SHIFT                       0
#define SIM_UID1_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UID1_UID_SHIFT))&SIM_UID1_UID_MASK)
/* UID2 Bit Fields */
#define SIM_UID2_UID_MASK                        0xFFFFFFFFu
#define SIM_UID2_UID_SHIFT                       0
#define SIM_UID2_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UID2_UID_SHIFT))&SIM_UID2_UID_MASK)
/* UID3 Bit Fields */
#define SIM_UID3_UID_MASK                        0xFFFFFFFFu
#define SIM_UID3_UID_SHIFT                       0
#define SIM_UID3_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UID3_UID_SHIFT))&SIM_UID3_UID_MASK)
/* MISC_CTL Bit Fields */
#define SIM_MISC_CTL_XBARAFEMODOUTSEL_MASK       0x3u
#define SIM_MISC_CTL_XBARAFEMODOUTSEL_SHIFT      0
#define SIM_MISC_CTL_XBARAFEMODOUTSEL(x)         (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_XBARAFEMODOUTSEL_SHIFT))&SIM_MISC_CTL_XBARAFEMODOUTSEL_MASK)
#define SIM_MISC_CTL_DMADONESEL_MASK             0xCu
#define SIM_MISC_CTL_DMADONESEL_SHIFT            2
#define SIM_MISC_CTL_DMADONESEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_DMADONESEL_SHIFT))&SIM_MISC_CTL_DMADONESEL_MASK)
#define SIM_MISC_CTL_AFECLKSEL_MASK              0x30u
#define SIM_MISC_CTL_AFECLKSEL_SHIFT             4
#define SIM_MISC_CTL_AFECLKSEL(x)                (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_AFECLKSEL_SHIFT))&SIM_MISC_CTL_AFECLKSEL_MASK)
#define SIM_MISC_CTL_AFECLKPADDIR_MASK           0x40u
#define SIM_MISC_CTL_AFECLKPADDIR_SHIFT          6
#define SIM_MISC_CTL_UARTMODTYPE_MASK            0x80u
#define SIM_MISC_CTL_UARTMODTYPE_SHIFT           7
#define SIM_MISC_CTL_UART0IRSEL_MASK             0x100u
#define SIM_MISC_CTL_UART0IRSEL_SHIFT            8
#define SIM_MISC_CTL_UART1IRSEL_MASK             0x200u
#define SIM_MISC_CTL_UART1IRSEL_SHIFT            9
#define SIM_MISC_CTL_UART2IRSEL_MASK             0x400u
#define SIM_MISC_CTL_UART2IRSEL_SHIFT            10
#define SIM_MISC_CTL_UART3IRSEL_MASK             0x800u
#define SIM_MISC_CTL_UART3IRSEL_SHIFT            11
#define SIM_MISC_CTL_XBARPITOUTSEL_MASK          0x3000u
#define SIM_MISC_CTL_XBARPITOUTSEL_SHIFT         12
#define SIM_MISC_CTL_XBARPITOUTSEL(x)            (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_XBARPITOUTSEL_SHIFT))&SIM_MISC_CTL_XBARPITOUTSEL_MASK)
#define SIM_MISC_CTL_EWMINSEL_MASK               0x4000u
#define SIM_MISC_CTL_EWMINSEL_SHIFT              14
#define SIM_MISC_CTL_TMR0PLLCLKSEL_MASK          0x8000u
#define SIM_MISC_CTL_TMR0PLLCLKSEL_SHIFT         15
#define SIM_MISC_CTL_TMR0SCSSEL_MASK             0x10000u
#define SIM_MISC_CTL_TMR0SCSSEL_SHIFT            16
#define SIM_MISC_CTL_TMR1SCSSEL_MASK             0x20000u
#define SIM_MISC_CTL_TMR1SCSSEL_SHIFT            17
#define SIM_MISC_CTL_TMR2SCSSEL_MASK             0x40000u
#define SIM_MISC_CTL_TMR2SCSSEL_SHIFT            18
#define SIM_MISC_CTL_TMR3SCSSEL_MASK             0x80000u
#define SIM_MISC_CTL_TMR3SCSSEL_SHIFT            19
#define SIM_MISC_CTL_TMR0PCSSEL_MASK             0x300000u
#define SIM_MISC_CTL_TMR0PCSSEL_SHIFT            20
#define SIM_MISC_CTL_TMR0PCSSEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_TMR0PCSSEL_SHIFT))&SIM_MISC_CTL_TMR0PCSSEL_MASK)
#define SIM_MISC_CTL_TMR1PCSSEL_MASK             0xC00000u
#define SIM_MISC_CTL_TMR1PCSSEL_SHIFT            22
#define SIM_MISC_CTL_TMR1PCSSEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_TMR1PCSSEL_SHIFT))&SIM_MISC_CTL_TMR1PCSSEL_MASK)
#define SIM_MISC_CTL_TMR2PCSSEL_MASK             0x3000000u
#define SIM_MISC_CTL_TMR2PCSSEL_SHIFT            24
#define SIM_MISC_CTL_TMR2PCSSEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_TMR2PCSSEL_SHIFT))&SIM_MISC_CTL_TMR2PCSSEL_MASK)
#define SIM_MISC_CTL_TMR3PCSSEL_MASK             0xC000000u
#define SIM_MISC_CTL_TMR3PCSSEL_SHIFT            26
#define SIM_MISC_CTL_TMR3PCSSEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_TMR3PCSSEL_SHIFT))&SIM_MISC_CTL_TMR3PCSSEL_MASK)
#define SIM_MISC_CTL_RTCCLKSEL_MASK              0x10000000u
#define SIM_MISC_CTL_RTCCLKSEL_SHIFT             28
#define SIM_MISC_CTL_VREFBUFOUTEN_MASK           0x20000000u
#define SIM_MISC_CTL_VREFBUFOUTEN_SHIFT          29
#define SIM_MISC_CTL_VREFBUFINSEL_MASK           0x40000000u
#define SIM_MISC_CTL_VREFBUFINSEL_SHIFT          30
#define SIM_MISC_CTL_VREFBUFPD_MASK              0x80000000u
#define SIM_MISC_CTL_VREFBUFPD_SHIFT             31

/*!
 * @}
 */ /* end of group SIM_Register_Masks */


/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base address */
#define SIM_BASE                                 (0x4003E000u)
/** Peripheral SIM base pointer */
#define SIM                                      ((SIM_Type *)SIM_BASE)
/** Array initializer of SIM peripheral base pointers */
#define SIM_BASES                                { SIM }

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
  __IO uint8_t PMPROT;                             /**< Power Mode Protection register, offset: 0x0 */
  __IO uint8_t PMCTRL;                             /**< Power Mode Control register, offset: 0x1 */
  __IO uint8_t STOPCTRL;                           /**< Stop Control Register, offset: 0x2 */
  __I  uint8_t PMSTAT;                             /**< Power Mode Status register, offset: 0x3 */
} SMC_Type;

/* ----------------------------------------------------------------------------
   -- SMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Register_Masks SMC Register Masks
 * @{
 */

/* PMPROT Bit Fields */
#define SMC_PMPROT_AVLLS_MASK                    0x2u
#define SMC_PMPROT_AVLLS_SHIFT                   1
#define SMC_PMPROT_AVLP_MASK                     0x20u
#define SMC_PMPROT_AVLP_SHIFT                    5
/* PMCTRL Bit Fields */
#define SMC_PMCTRL_STOPM_MASK                    0x7u
#define SMC_PMCTRL_STOPM_SHIFT                   0
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPM_SHIFT))&SMC_PMCTRL_STOPM_MASK)
#define SMC_PMCTRL_STOPA_MASK                    0x8u
#define SMC_PMCTRL_STOPA_SHIFT                   3
#define SMC_PMCTRL_RUNM_MASK                     0x60u
#define SMC_PMCTRL_RUNM_SHIFT                    5
#define SMC_PMCTRL_RUNM(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_RUNM_SHIFT))&SMC_PMCTRL_RUNM_MASK)
/* STOPCTRL Bit Fields */
#define SMC_STOPCTRL_VLLSM_MASK                  0x7u
#define SMC_STOPCTRL_VLLSM_SHIFT                 0
#define SMC_STOPCTRL_VLLSM(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_VLLSM_SHIFT))&SMC_STOPCTRL_VLLSM_MASK)
#define SMC_STOPCTRL_PORPO_MASK                  0x20u
#define SMC_STOPCTRL_PORPO_SHIFT                 5
#define SMC_STOPCTRL_PSTOPO_MASK                 0xC0u
#define SMC_STOPCTRL_PSTOPO_SHIFT                6
#define SMC_STOPCTRL_PSTOPO(x)                   (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_PSTOPO_SHIFT))&SMC_STOPCTRL_PSTOPO_MASK)
/* PMSTAT Bit Fields */
#define SMC_PMSTAT_PMSTAT_MASK                   0x7Fu
#define SMC_PMSTAT_PMSTAT_SHIFT                  0
#define SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)(x))<<SMC_PMSTAT_PMSTAT_SHIFT))&SMC_PMSTAT_PMSTAT_MASK)

/*!
 * @}
 */ /* end of group SMC_Register_Masks */


/* SMC - Peripheral instance base addresses */
/** Peripheral SMC base address */
#define SMC_BASE                                 (0x4007E000u)
/** Peripheral SMC base pointer */
#define SMC                                      ((SMC_Type *)SMC_BASE)
/** Array initializer of SMC peripheral base pointers */
#define SMC_BASES                                { SMC }

/*!
 * @}
 */ /* end of group SMC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Peripheral_Access_Layer SPI Peripheral Access Layer
 * @{
 */

/** SPI - Register Layout Typedef */
typedef struct {
  __I  uint8_t S;                                  /**< SPI status register, offset: 0x0 */
  __IO uint8_t BR;                                 /**< SPI baud rate register, offset: 0x1 */
  __IO uint8_t C2;                                 /**< SPI control register 2, offset: 0x2 */
  __IO uint8_t C1;                                 /**< SPI control register 1, offset: 0x3 */
  __IO uint8_t ML;                                 /**< SPI match register low, offset: 0x4 */
  __IO uint8_t MH;                                 /**< SPI match register high, offset: 0x5 */
  __IO uint8_t DL;                                 /**< SPI data register low, offset: 0x6 */
  __IO uint8_t DH;                                 /**< SPI data register high, offset: 0x7 */
       uint8_t RESERVED_0[2];
  __IO uint8_t CI;                                 /**< SPI clear interrupt register, offset: 0xA */
  __IO uint8_t C3;                                 /**< SPI control register 3, offset: 0xB */
} SPI_Type;

/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Register_Masks SPI Register Masks
 * @{
 */

/* S Bit Fields */
#define SPI_S_RFIFOEF_MASK                       0x1u
#define SPI_S_RFIFOEF_SHIFT                      0
#define SPI_S_TXFULLF_MASK                       0x2u
#define SPI_S_TXFULLF_SHIFT                      1
#define SPI_S_TNEAREF_MASK                       0x4u
#define SPI_S_TNEAREF_SHIFT                      2
#define SPI_S_RNFULLF_MASK                       0x8u
#define SPI_S_RNFULLF_SHIFT                      3
#define SPI_S_MODF_MASK                          0x10u
#define SPI_S_MODF_SHIFT                         4
#define SPI_S_SPTEF_MASK                         0x20u
#define SPI_S_SPTEF_SHIFT                        5
#define SPI_S_SPMF_MASK                          0x40u
#define SPI_S_SPMF_SHIFT                         6
#define SPI_S_SPRF_MASK                          0x80u
#define SPI_S_SPRF_SHIFT                         7
/* BR Bit Fields */
#define SPI_BR_SPR_MASK                          0xFu
#define SPI_BR_SPR_SHIFT                         0
#define SPI_BR_SPR(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPR_SHIFT))&SPI_BR_SPR_MASK)
#define SPI_BR_SPPR_MASK                         0x70u
#define SPI_BR_SPPR_SHIFT                        4
#define SPI_BR_SPPR(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPPR_SHIFT))&SPI_BR_SPPR_MASK)
/* C2 Bit Fields */
#define SPI_C2_SPC0_MASK                         0x1u
#define SPI_C2_SPC0_SHIFT                        0
#define SPI_C2_SPISWAI_MASK                      0x2u
#define SPI_C2_SPISWAI_SHIFT                     1
#define SPI_C2_RXDMAE_MASK                       0x4u
#define SPI_C2_RXDMAE_SHIFT                      2
#define SPI_C2_BIDIROE_MASK                      0x8u
#define SPI_C2_BIDIROE_SHIFT                     3
#define SPI_C2_MODFEN_MASK                       0x10u
#define SPI_C2_MODFEN_SHIFT                      4
#define SPI_C2_TXDMAE_MASK                       0x20u
#define SPI_C2_TXDMAE_SHIFT                      5
#define SPI_C2_SPIMODE_MASK                      0x40u
#define SPI_C2_SPIMODE_SHIFT                     6
#define SPI_C2_SPMIE_MASK                        0x80u
#define SPI_C2_SPMIE_SHIFT                       7
/* C1 Bit Fields */
#define SPI_C1_LSBFE_MASK                        0x1u
#define SPI_C1_LSBFE_SHIFT                       0
#define SPI_C1_SSOE_MASK                         0x2u
#define SPI_C1_SSOE_SHIFT                        1
#define SPI_C1_CPHA_MASK                         0x4u
#define SPI_C1_CPHA_SHIFT                        2
#define SPI_C1_CPOL_MASK                         0x8u
#define SPI_C1_CPOL_SHIFT                        3
#define SPI_C1_MSTR_MASK                         0x10u
#define SPI_C1_MSTR_SHIFT                        4
#define SPI_C1_SPTIE_MASK                        0x20u
#define SPI_C1_SPTIE_SHIFT                       5
#define SPI_C1_SPE_MASK                          0x40u
#define SPI_C1_SPE_SHIFT                         6
#define SPI_C1_SPIE_MASK                         0x80u
#define SPI_C1_SPIE_SHIFT                        7
/* ML Bit Fields */
#define SPI_ML_Bits_MASK                         0xFFu
#define SPI_ML_Bits_SHIFT                        0
#define SPI_ML_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_ML_Bits_SHIFT))&SPI_ML_Bits_MASK)
/* MH Bit Fields */
#define SPI_MH_Bits_MASK                         0xFFu
#define SPI_MH_Bits_SHIFT                        0
#define SPI_MH_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_MH_Bits_SHIFT))&SPI_MH_Bits_MASK)
/* DL Bit Fields */
#define SPI_DL_Bits_MASK                         0xFFu
#define SPI_DL_Bits_SHIFT                        0
#define SPI_DL_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_DL_Bits_SHIFT))&SPI_DL_Bits_MASK)
/* DH Bit Fields */
#define SPI_DH_Bits_MASK                         0xFFu
#define SPI_DH_Bits_SHIFT                        0
#define SPI_DH_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_DH_Bits_SHIFT))&SPI_DH_Bits_MASK)
/* CI Bit Fields */
#define SPI_CI_SPRFCI_MASK                       0x1u
#define SPI_CI_SPRFCI_SHIFT                      0
#define SPI_CI_SPTEFCI_MASK                      0x2u
#define SPI_CI_SPTEFCI_SHIFT                     1
#define SPI_CI_RNFULLFCI_MASK                    0x4u
#define SPI_CI_RNFULLFCI_SHIFT                   2
#define SPI_CI_TNEAREFCI_MASK                    0x8u
#define SPI_CI_TNEAREFCI_SHIFT                   3
#define SPI_CI_RXFOF_MASK                        0x10u
#define SPI_CI_RXFOF_SHIFT                       4
#define SPI_CI_TXFOF_MASK                        0x20u
#define SPI_CI_TXFOF_SHIFT                       5
#define SPI_CI_RXFERR_MASK                       0x40u
#define SPI_CI_RXFERR_SHIFT                      6
#define SPI_CI_TXFERR_MASK                       0x80u
#define SPI_CI_TXFERR_SHIFT                      7
/* C3 Bit Fields */
#define SPI_C3_FIFOMODE_MASK                     0x1u
#define SPI_C3_FIFOMODE_SHIFT                    0
#define SPI_C3_RNFULLIEN_MASK                    0x2u
#define SPI_C3_RNFULLIEN_SHIFT                   1
#define SPI_C3_TNEARIEN_MASK                     0x4u
#define SPI_C3_TNEARIEN_SHIFT                    2
#define SPI_C3_INTCLR_MASK                       0x8u
#define SPI_C3_INTCLR_SHIFT                      3
#define SPI_C3_RNFULLF_MARK_MASK                 0x10u
#define SPI_C3_RNFULLF_MARK_SHIFT                4
#define SPI_C3_TNEAREF_MARK_MASK                 0x20u
#define SPI_C3_TNEAREF_MARK_SHIFT                5

/*!
 * @}
 */ /* end of group SPI_Register_Masks */


/* SPI - Peripheral instance base addresses */
/** Peripheral SPI0 base address */
#define SPI0_BASE                                (0x40075000u)
/** Peripheral SPI0 base pointer */
#define SPI0                                     ((SPI_Type *)SPI0_BASE)
/** Peripheral SPI1 base address */
#define SPI1_BASE                                (0x40076000u)
/** Peripheral SPI1 base pointer */
#define SPI1                                     ((SPI_Type *)SPI1_BASE)
/** Array initializer of SPI peripheral base pointers */
#define SPI_BASES                                { SPI0, SPI1 }

/*!
 * @}
 */ /* end of group SPI_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- TMR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMR_Peripheral_Access_Layer TMR Peripheral Access Layer
 * @{
 */

/** TMR - Register Layout Typedef */
typedef struct {
  __IO uint16_t COMP1;                             /**< Timer Channel Compare Register 1, offset: 0x0 */
  __IO uint16_t COMP2;                             /**< Timer Channel Compare Register 2, offset: 0x2 */
  __IO uint16_t CAPT;                              /**< Timer Channel Capture Register, offset: 0x4 */
  __IO uint16_t LOAD;                              /**< Timer Channel Load Register, offset: 0x6 */
  __IO uint16_t HOLD;                              /**< Timer Channel Hold Register, offset: 0x8 */
  __IO uint16_t CNTR;                              /**< Timer Channel Counter Register, offset: 0xA */
  __IO uint16_t CTRL;                              /**< Timer Channel Control Register, offset: 0xC */
  __IO uint16_t SCTRL;                             /**< Timer Channel Status and Control Register, offset: 0xE */
  __IO uint16_t CMPLD1;                            /**< Timer Channel Comparator Load Register 1, offset: 0x10 */
  __IO uint16_t CMPLD2;                            /**< Timer Channel Comparator Load Register 2, offset: 0x12 */
  __IO uint16_t CSCTRL;                            /**< Timer Channel Comparator Status and Control Register, offset: 0x14 */
  __IO uint16_t FILT;                              /**< Timer Channel Input Filter Register, offset: 0x16 */
       uint8_t RESERVED_0[6];
  __IO uint16_t ENBL;                              /**< Timer Channel Enable Register, offset: 0x1E */
} TMR_Type;

/* ----------------------------------------------------------------------------
   -- TMR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMR_Register_Masks TMR Register Masks
 * @{
 */

/* COMP1 Bit Fields */
#define TMR_COMP1_COMPARISON_1_MASK              0xFFFFu
#define TMR_COMP1_COMPARISON_1_SHIFT             0
#define TMR_COMP1_COMPARISON_1(x)                (((uint16_t)(((uint16_t)(x))<<TMR_COMP1_COMPARISON_1_SHIFT))&TMR_COMP1_COMPARISON_1_MASK)
/* COMP2 Bit Fields */
#define TMR_COMP2_COMPARISON_2_MASK              0xFFFFu
#define TMR_COMP2_COMPARISON_2_SHIFT             0
#define TMR_COMP2_COMPARISON_2(x)                (((uint16_t)(((uint16_t)(x))<<TMR_COMP2_COMPARISON_2_SHIFT))&TMR_COMP2_COMPARISON_2_MASK)
/* CAPT Bit Fields */
#define TMR_CAPT_CAPTURE_MASK                    0xFFFFu
#define TMR_CAPT_CAPTURE_SHIFT                   0
#define TMR_CAPT_CAPTURE(x)                      (((uint16_t)(((uint16_t)(x))<<TMR_CAPT_CAPTURE_SHIFT))&TMR_CAPT_CAPTURE_MASK)
/* LOAD Bit Fields */
#define TMR_LOAD_LOAD_MASK                       0xFFFFu
#define TMR_LOAD_LOAD_SHIFT                      0
#define TMR_LOAD_LOAD(x)                         (((uint16_t)(((uint16_t)(x))<<TMR_LOAD_LOAD_SHIFT))&TMR_LOAD_LOAD_MASK)
/* HOLD Bit Fields */
#define TMR_HOLD_HOLD_MASK                       0xFFFFu
#define TMR_HOLD_HOLD_SHIFT                      0
#define TMR_HOLD_HOLD(x)                         (((uint16_t)(((uint16_t)(x))<<TMR_HOLD_HOLD_SHIFT))&TMR_HOLD_HOLD_MASK)
/* CNTR Bit Fields */
#define TMR_CNTR_COUNTER_MASK                    0xFFFFu
#define TMR_CNTR_COUNTER_SHIFT                   0
#define TMR_CNTR_COUNTER(x)                      (((uint16_t)(((uint16_t)(x))<<TMR_CNTR_COUNTER_SHIFT))&TMR_CNTR_COUNTER_MASK)
/* CTRL Bit Fields */
#define TMR_CTRL_OUTMODE_MASK                    0x7u
#define TMR_CTRL_OUTMODE_SHIFT                   0
#define TMR_CTRL_OUTMODE(x)                      (((uint16_t)(((uint16_t)(x))<<TMR_CTRL_OUTMODE_SHIFT))&TMR_CTRL_OUTMODE_MASK)
#define TMR_CTRL_COINIT_MASK                     0x8u
#define TMR_CTRL_COINIT_SHIFT                    3
#define TMR_CTRL_DIR_MASK                        0x10u
#define TMR_CTRL_DIR_SHIFT                       4
#define TMR_CTRL_LENGTH_MASK                     0x20u
#define TMR_CTRL_LENGTH_SHIFT                    5
#define TMR_CTRL_ONCE_MASK                       0x40u
#define TMR_CTRL_ONCE_SHIFT                      6
#define TMR_CTRL_SCS_MASK                        0x180u
#define TMR_CTRL_SCS_SHIFT                       7
#define TMR_CTRL_SCS(x)                          (((uint16_t)(((uint16_t)(x))<<TMR_CTRL_SCS_SHIFT))&TMR_CTRL_SCS_MASK)
#define TMR_CTRL_PCS_MASK                        0x1E00u
#define TMR_CTRL_PCS_SHIFT                       9
#define TMR_CTRL_PCS(x)                          (((uint16_t)(((uint16_t)(x))<<TMR_CTRL_PCS_SHIFT))&TMR_CTRL_PCS_MASK)
#define TMR_CTRL_CM_MASK                         0xE000u
#define TMR_CTRL_CM_SHIFT                        13
#define TMR_CTRL_CM(x)                           (((uint16_t)(((uint16_t)(x))<<TMR_CTRL_CM_SHIFT))&TMR_CTRL_CM_MASK)
/* SCTRL Bit Fields */
#define TMR_SCTRL_OEN_MASK                       0x1u
#define TMR_SCTRL_OEN_SHIFT                      0
#define TMR_SCTRL_OPS_MASK                       0x2u
#define TMR_SCTRL_OPS_SHIFT                      1
#define TMR_SCTRL_FORCE_MASK                     0x4u
#define TMR_SCTRL_FORCE_SHIFT                    2
#define TMR_SCTRL_VAL_MASK                       0x8u
#define TMR_SCTRL_VAL_SHIFT                      3
#define TMR_SCTRL_EEOF_MASK                      0x10u
#define TMR_SCTRL_EEOF_SHIFT                     4
#define TMR_SCTRL_MSTR_MASK                      0x20u
#define TMR_SCTRL_MSTR_SHIFT                     5
#define TMR_SCTRL_CAPTURE_MODE_MASK              0xC0u
#define TMR_SCTRL_CAPTURE_MODE_SHIFT             6
#define TMR_SCTRL_CAPTURE_MODE(x)                (((uint16_t)(((uint16_t)(x))<<TMR_SCTRL_CAPTURE_MODE_SHIFT))&TMR_SCTRL_CAPTURE_MODE_MASK)
#define TMR_SCTRL_INPUT_MASK                     0x100u
#define TMR_SCTRL_INPUT_SHIFT                    8
#define TMR_SCTRL_IPS_MASK                       0x200u
#define TMR_SCTRL_IPS_SHIFT                      9
#define TMR_SCTRL_IEFIE_MASK                     0x400u
#define TMR_SCTRL_IEFIE_SHIFT                    10
#define TMR_SCTRL_IEF_MASK                       0x800u
#define TMR_SCTRL_IEF_SHIFT                      11
#define TMR_SCTRL_TOFIE_MASK                     0x1000u
#define TMR_SCTRL_TOFIE_SHIFT                    12
#define TMR_SCTRL_TOF_MASK                       0x2000u
#define TMR_SCTRL_TOF_SHIFT                      13
#define TMR_SCTRL_TCFIE_MASK                     0x4000u
#define TMR_SCTRL_TCFIE_SHIFT                    14
#define TMR_SCTRL_TCF_MASK                       0x8000u
#define TMR_SCTRL_TCF_SHIFT                      15
/* CMPLD1 Bit Fields */
#define TMR_CMPLD1_COMPARATOR_LOAD_1_MASK        0xFFFFu
#define TMR_CMPLD1_COMPARATOR_LOAD_1_SHIFT       0
#define TMR_CMPLD1_COMPARATOR_LOAD_1(x)          (((uint16_t)(((uint16_t)(x))<<TMR_CMPLD1_COMPARATOR_LOAD_1_SHIFT))&TMR_CMPLD1_COMPARATOR_LOAD_1_MASK)
/* CMPLD2 Bit Fields */
#define TMR_CMPLD2_COMPARATOR_LOAD_2_MASK        0xFFFFu
#define TMR_CMPLD2_COMPARATOR_LOAD_2_SHIFT       0
#define TMR_CMPLD2_COMPARATOR_LOAD_2(x)          (((uint16_t)(((uint16_t)(x))<<TMR_CMPLD2_COMPARATOR_LOAD_2_SHIFT))&TMR_CMPLD2_COMPARATOR_LOAD_2_MASK)
/* CSCTRL Bit Fields */
#define TMR_CSCTRL_CL1_MASK                      0x3u
#define TMR_CSCTRL_CL1_SHIFT                     0
#define TMR_CSCTRL_CL1(x)                        (((uint16_t)(((uint16_t)(x))<<TMR_CSCTRL_CL1_SHIFT))&TMR_CSCTRL_CL1_MASK)
#define TMR_CSCTRL_CL2_MASK                      0xCu
#define TMR_CSCTRL_CL2_SHIFT                     2
#define TMR_CSCTRL_CL2(x)                        (((uint16_t)(((uint16_t)(x))<<TMR_CSCTRL_CL2_SHIFT))&TMR_CSCTRL_CL2_MASK)
#define TMR_CSCTRL_TCF1_MASK                     0x10u
#define TMR_CSCTRL_TCF1_SHIFT                    4
#define TMR_CSCTRL_TCF2_MASK                     0x20u
#define TMR_CSCTRL_TCF2_SHIFT                    5
#define TMR_CSCTRL_TCF1EN_MASK                   0x40u
#define TMR_CSCTRL_TCF1EN_SHIFT                  6
#define TMR_CSCTRL_TCF2EN_MASK                   0x80u
#define TMR_CSCTRL_TCF2EN_SHIFT                  7
#define TMR_CSCTRL_UP_MASK                       0x200u
#define TMR_CSCTRL_UP_SHIFT                      9
#define TMR_CSCTRL_TCI_MASK                      0x400u
#define TMR_CSCTRL_TCI_SHIFT                     10
#define TMR_CSCTRL_ROC_MASK                      0x800u
#define TMR_CSCTRL_ROC_SHIFT                     11
#define TMR_CSCTRL_ALT_LOAD_MASK                 0x1000u
#define TMR_CSCTRL_ALT_LOAD_SHIFT                12
#define TMR_CSCTRL_FAULT_MASK                    0x2000u
#define TMR_CSCTRL_FAULT_SHIFT                   13
#define TMR_CSCTRL_DBG_EN_MASK                   0xC000u
#define TMR_CSCTRL_DBG_EN_SHIFT                  14
#define TMR_CSCTRL_DBG_EN(x)                     (((uint16_t)(((uint16_t)(x))<<TMR_CSCTRL_DBG_EN_SHIFT))&TMR_CSCTRL_DBG_EN_MASK)
/* FILT Bit Fields */
#define TMR_FILT_FILT_PER_MASK                   0xFFu
#define TMR_FILT_FILT_PER_SHIFT                  0
#define TMR_FILT_FILT_PER(x)                     (((uint16_t)(((uint16_t)(x))<<TMR_FILT_FILT_PER_SHIFT))&TMR_FILT_FILT_PER_MASK)
#define TMR_FILT_FILT_CNT_MASK                   0x700u
#define TMR_FILT_FILT_CNT_SHIFT                  8
#define TMR_FILT_FILT_CNT(x)                     (((uint16_t)(((uint16_t)(x))<<TMR_FILT_FILT_CNT_SHIFT))&TMR_FILT_FILT_CNT_MASK)
/* ENBL Bit Fields */
#define TMR_ENBL_ENBL_MASK                       0xFu
#define TMR_ENBL_ENBL_SHIFT                      0
#define TMR_ENBL_ENBL(x)                         (((uint16_t)(((uint16_t)(x))<<TMR_ENBL_ENBL_SHIFT))&TMR_ENBL_ENBL_MASK)

/*!
 * @}
 */ /* end of group TMR_Register_Masks */


/* TMR - Peripheral instance base addresses */
/** Peripheral TMR0 base address */
#define TMR0_BASE                                (0x40057000u)
/** Peripheral TMR0 base pointer */
#define TMR0                                     ((TMR_Type *)TMR0_BASE)
/** Peripheral TMR1 base address */
#define TMR1_BASE                                (0x40058000u)
/** Peripheral TMR1 base pointer */
#define TMR1                                     ((TMR_Type *)TMR1_BASE)
/** Peripheral TMR2 base address */
#define TMR2_BASE                                (0x40059000u)
/** Peripheral TMR2 base pointer */
#define TMR2                                     ((TMR_Type *)TMR2_BASE)
/** Peripheral TMR3 base address */
#define TMR3_BASE                                (0x4005A000u)
/** Peripheral TMR3 base pointer */
#define TMR3                                     ((TMR_Type *)TMR3_BASE)
/** Array initializer of TMR peripheral base pointers */
#define TMR_BASES                                { TMR0, TMR1, TMR2, TMR3 }

/*!
 * @}
 */ /* end of group TMR_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- UART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Peripheral_Access_Layer UART Peripheral Access Layer
 * @{
 */

/** UART - Register Layout Typedef */
typedef struct {
  __IO uint8_t BDH;                                /**< UART Baud Rate Registers: High, offset: 0x0 */
  __IO uint8_t BDL;                                /**< UART Baud Rate Registers: Low, offset: 0x1 */
  __IO uint8_t C1;                                 /**< UART Control Register 1, offset: 0x2 */
  __IO uint8_t C2;                                 /**< UART Control Register 2, offset: 0x3 */
  __I  uint8_t S1;                                 /**< UART Status Register 1, offset: 0x4 */
  __IO uint8_t S2;                                 /**< UART Status Register 2, offset: 0x5 */
  __IO uint8_t C3;                                 /**< UART Control Register 3, offset: 0x6 */
  __IO uint8_t D;                                  /**< UART Data Register, offset: 0x7 */
  __IO uint8_t MA1;                                /**< UART Match Address Registers 1, offset: 0x8 */
  __IO uint8_t MA2;                                /**< UART Match Address Registers 2, offset: 0x9 */
  __IO uint8_t C4;                                 /**< UART Control Register 4, offset: 0xA */
  __IO uint8_t C5;                                 /**< UART Control Register 5, offset: 0xB */
  __I  uint8_t ED;                                 /**< UART Extended Data Register, offset: 0xC */
  __IO uint8_t MODEM;                              /**< UART Modem Register, offset: 0xD */
       uint8_t RESERVED_0[2];
  __IO uint8_t PFIFO;                              /**< UART FIFO Parameters, offset: 0x10 */
  __IO uint8_t CFIFO;                              /**< UART FIFO Control Register, offset: 0x11 */
  __IO uint8_t SFIFO;                              /**< UART FIFO Status Register, offset: 0x12 */
  __IO uint8_t TWFIFO;                             /**< UART FIFO Transmit Watermark, offset: 0x13 */
  __I  uint8_t TCFIFO;                             /**< UART FIFO Transmit Count, offset: 0x14 */
  __IO uint8_t RWFIFO;                             /**< UART FIFO Receive Watermark, offset: 0x15 */
  __I  uint8_t RCFIFO;                             /**< UART FIFO Receive Count, offset: 0x16 */
       uint8_t RESERVED_1[1];
  __IO uint8_t C7816;                              /**< UART 7816 Control Register, offset: 0x18 */
  __IO uint8_t IE7816;                             /**< UART 7816 Interrupt Enable Register, offset: 0x19 */
  __IO uint8_t IS7816;                             /**< UART 7816 Interrupt Status Register, offset: 0x1A */
  union {                                          /* offset: 0x1B */
    __IO uint8_t WP7816_T_TYPE0;                     /**< UART 7816 Wait Parameter Register, offset: 0x1B */
    __IO uint8_t WP7816_T_TYPE1;                     /**< UART 7816 Wait Parameter Register, offset: 0x1B */
  };
  __IO uint8_t WN7816;                             /**< UART 7816 Wait N Register, offset: 0x1C */
  __IO uint8_t WF7816;                             /**< UART 7816 Wait FD Register, offset: 0x1D */
  __IO uint8_t ET7816;                             /**< UART 7816 Error Threshold Register, offset: 0x1E */
  __IO uint8_t TL7816;                             /**< UART 7816 Transmit Length Register, offset: 0x1F */
} UART_Type;

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
#define UART_BDH_RXEDGIE_MASK                    0x40u
#define UART_BDH_RXEDGIE_SHIFT                   6
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
#define UART_S2_BRK13_MASK                       0x4u
#define UART_S2_BRK13_SHIFT                      2
#define UART_S2_RWUID_MASK                       0x8u
#define UART_S2_RWUID_SHIFT                      3
#define UART_S2_RXINV_MASK                       0x10u
#define UART_S2_RXINV_SHIFT                      4
#define UART_S2_MSBF_MASK                        0x20u
#define UART_S2_MSBF_SHIFT                       5
#define UART_S2_RXEDGIF_MASK                     0x40u
#define UART_S2_RXEDGIF_SHIFT                    6
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
#define UART_D_RT_MASK                           0xFFu
#define UART_D_RT_SHIFT                          0
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<UART_D_RT_SHIFT))&UART_D_RT_MASK)
/* MA1 Bit Fields */
#define UART_MA1_MA_MASK                         0xFFu
#define UART_MA1_MA_SHIFT                        0
#define UART_MA1_MA(x)                           (((uint8_t)(((uint8_t)(x))<<UART_MA1_MA_SHIFT))&UART_MA1_MA_MASK)
/* MA2 Bit Fields */
#define UART_MA2_MA_MASK                         0xFFu
#define UART_MA2_MA_SHIFT                        0
#define UART_MA2_MA(x)                           (((uint8_t)(((uint8_t)(x))<<UART_MA2_MA_SHIFT))&UART_MA2_MA_MASK)
/* C4 Bit Fields */
#define UART_C4_BRFA_MASK                        0x1Fu
#define UART_C4_BRFA_SHIFT                       0
#define UART_C4_BRFA(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C4_BRFA_SHIFT))&UART_C4_BRFA_MASK)
#define UART_C4_M10_MASK                         0x20u
#define UART_C4_M10_SHIFT                        5
#define UART_C4_MAEN2_MASK                       0x40u
#define UART_C4_MAEN2_SHIFT                      6
#define UART_C4_MAEN1_MASK                       0x80u
#define UART_C4_MAEN1_SHIFT                      7
/* C5 Bit Fields */
#define UART_C5_RDMAS_MASK                       0x20u
#define UART_C5_RDMAS_SHIFT                      5
#define UART_C5_TDMAS_MASK                       0x80u
#define UART_C5_TDMAS_SHIFT                      7
/* ED Bit Fields */
#define UART_ED_PARITYE_MASK                     0x40u
#define UART_ED_PARITYE_SHIFT                    6
#define UART_ED_NOISY_MASK                       0x80u
#define UART_ED_NOISY_SHIFT                      7
/* MODEM Bit Fields */
#define UART_MODEM_TXCTSE_MASK                   0x1u
#define UART_MODEM_TXCTSE_SHIFT                  0
#define UART_MODEM_TXRTSE_MASK                   0x2u
#define UART_MODEM_TXRTSE_SHIFT                  1
#define UART_MODEM_TXRTSPOL_MASK                 0x4u
#define UART_MODEM_TXRTSPOL_SHIFT                2
#define UART_MODEM_RXRTSE_MASK                   0x8u
#define UART_MODEM_RXRTSE_SHIFT                  3
/* PFIFO Bit Fields */
#define UART_PFIFO_RXFIFOSIZE_MASK               0x7u
#define UART_PFIFO_RXFIFOSIZE_SHIFT              0
#define UART_PFIFO_RXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_RXFIFOSIZE_SHIFT))&UART_PFIFO_RXFIFOSIZE_MASK)
#define UART_PFIFO_RXFE_MASK                     0x8u
#define UART_PFIFO_RXFE_SHIFT                    3
#define UART_PFIFO_TXFIFOSIZE_MASK               0x70u
#define UART_PFIFO_TXFIFOSIZE_SHIFT              4
#define UART_PFIFO_TXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_TXFIFOSIZE_SHIFT))&UART_PFIFO_TXFIFOSIZE_MASK)
#define UART_PFIFO_TXFE_MASK                     0x80u
#define UART_PFIFO_TXFE_SHIFT                    7
/* CFIFO Bit Fields */
#define UART_CFIFO_RXUFE_MASK                    0x1u
#define UART_CFIFO_RXUFE_SHIFT                   0
#define UART_CFIFO_TXOFE_MASK                    0x2u
#define UART_CFIFO_TXOFE_SHIFT                   1
#define UART_CFIFO_RXOFE_MASK                    0x4u
#define UART_CFIFO_RXOFE_SHIFT                   2
#define UART_CFIFO_RXFLUSH_MASK                  0x40u
#define UART_CFIFO_RXFLUSH_SHIFT                 6
#define UART_CFIFO_TXFLUSH_MASK                  0x80u
#define UART_CFIFO_TXFLUSH_SHIFT                 7
/* SFIFO Bit Fields */
#define UART_SFIFO_RXUF_MASK                     0x1u
#define UART_SFIFO_RXUF_SHIFT                    0
#define UART_SFIFO_TXOF_MASK                     0x2u
#define UART_SFIFO_TXOF_SHIFT                    1
#define UART_SFIFO_RXOF_MASK                     0x4u
#define UART_SFIFO_RXOF_SHIFT                    2
#define UART_SFIFO_RXEMPT_MASK                   0x40u
#define UART_SFIFO_RXEMPT_SHIFT                  6
#define UART_SFIFO_TXEMPT_MASK                   0x80u
#define UART_SFIFO_TXEMPT_SHIFT                  7
/* TWFIFO Bit Fields */
#define UART_TWFIFO_TXWATER_MASK                 0xFFu
#define UART_TWFIFO_TXWATER_SHIFT                0
#define UART_TWFIFO_TXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TWFIFO_TXWATER_SHIFT))&UART_TWFIFO_TXWATER_MASK)
/* TCFIFO Bit Fields */
#define UART_TCFIFO_TXCOUNT_MASK                 0xFFu
#define UART_TCFIFO_TXCOUNT_SHIFT                0
#define UART_TCFIFO_TXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TCFIFO_TXCOUNT_SHIFT))&UART_TCFIFO_TXCOUNT_MASK)
/* RWFIFO Bit Fields */
#define UART_RWFIFO_RXWATER_MASK                 0xFFu
#define UART_RWFIFO_RXWATER_SHIFT                0
#define UART_RWFIFO_RXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RWFIFO_RXWATER_SHIFT))&UART_RWFIFO_RXWATER_MASK)
/* RCFIFO Bit Fields */
#define UART_RCFIFO_RXCOUNT_MASK                 0xFFu
#define UART_RCFIFO_RXCOUNT_SHIFT                0
#define UART_RCFIFO_RXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RCFIFO_RXCOUNT_SHIFT))&UART_RCFIFO_RXCOUNT_MASK)
/* C7816 Bit Fields */
#define UART_C7816_ISO_7816E_MASK                0x1u
#define UART_C7816_ISO_7816E_SHIFT               0
#define UART_C7816_TTYPE_MASK                    0x2u
#define UART_C7816_TTYPE_SHIFT                   1
#define UART_C7816_INIT_MASK                     0x4u
#define UART_C7816_INIT_SHIFT                    2
#define UART_C7816_ANACK_MASK                    0x8u
#define UART_C7816_ANACK_SHIFT                   3
#define UART_C7816_ONACK_MASK                    0x10u
#define UART_C7816_ONACK_SHIFT                   4
/* IE7816 Bit Fields */
#define UART_IE7816_RXTE_MASK                    0x1u
#define UART_IE7816_RXTE_SHIFT                   0
#define UART_IE7816_TXTE_MASK                    0x2u
#define UART_IE7816_TXTE_SHIFT                   1
#define UART_IE7816_GTVE_MASK                    0x4u
#define UART_IE7816_GTVE_SHIFT                   2
#define UART_IE7816_INITDE_MASK                  0x10u
#define UART_IE7816_INITDE_SHIFT                 4
#define UART_IE7816_BWTE_MASK                    0x20u
#define UART_IE7816_BWTE_SHIFT                   5
#define UART_IE7816_CWTE_MASK                    0x40u
#define UART_IE7816_CWTE_SHIFT                   6
#define UART_IE7816_WTE_MASK                     0x80u
#define UART_IE7816_WTE_SHIFT                    7
/* IS7816 Bit Fields */
#define UART_IS7816_RXT_MASK                     0x1u
#define UART_IS7816_RXT_SHIFT                    0
#define UART_IS7816_TXT_MASK                     0x2u
#define UART_IS7816_TXT_SHIFT                    1
#define UART_IS7816_GTV_MASK                     0x4u
#define UART_IS7816_GTV_SHIFT                    2
#define UART_IS7816_INITD_MASK                   0x10u
#define UART_IS7816_INITD_SHIFT                  4
#define UART_IS7816_BWT_MASK                     0x20u
#define UART_IS7816_BWT_SHIFT                    5
#define UART_IS7816_CWT_MASK                     0x40u
#define UART_IS7816_CWT_SHIFT                    6
#define UART_IS7816_WT_MASK                      0x80u
#define UART_IS7816_WT_SHIFT                     7
/* WP7816_T_TYPE0 Bit Fields */
#define UART_WP7816_T_TYPE0_WI_MASK              0xFFu
#define UART_WP7816_T_TYPE0_WI_SHIFT             0
#define UART_WP7816_T_TYPE0_WI(x)                (((uint8_t)(((uint8_t)(x))<<UART_WP7816_T_TYPE0_WI_SHIFT))&UART_WP7816_T_TYPE0_WI_MASK)
/* WP7816_T_TYPE1 Bit Fields */
#define UART_WP7816_T_TYPE1_BWI_MASK             0xFu
#define UART_WP7816_T_TYPE1_BWI_SHIFT            0
#define UART_WP7816_T_TYPE1_BWI(x)               (((uint8_t)(((uint8_t)(x))<<UART_WP7816_T_TYPE1_BWI_SHIFT))&UART_WP7816_T_TYPE1_BWI_MASK)
#define UART_WP7816_T_TYPE1_CWI_MASK             0xF0u
#define UART_WP7816_T_TYPE1_CWI_SHIFT            4
#define UART_WP7816_T_TYPE1_CWI(x)               (((uint8_t)(((uint8_t)(x))<<UART_WP7816_T_TYPE1_CWI_SHIFT))&UART_WP7816_T_TYPE1_CWI_MASK)
/* WN7816 Bit Fields */
#define UART_WN7816_GTN_MASK                     0xFFu
#define UART_WN7816_GTN_SHIFT                    0
#define UART_WN7816_GTN(x)                       (((uint8_t)(((uint8_t)(x))<<UART_WN7816_GTN_SHIFT))&UART_WN7816_GTN_MASK)
/* WF7816 Bit Fields */
#define UART_WF7816_GTFD_MASK                    0xFFu
#define UART_WF7816_GTFD_SHIFT                   0
#define UART_WF7816_GTFD(x)                      (((uint8_t)(((uint8_t)(x))<<UART_WF7816_GTFD_SHIFT))&UART_WF7816_GTFD_MASK)
/* ET7816 Bit Fields */
#define UART_ET7816_RXTHRESHOLD_MASK             0xFu
#define UART_ET7816_RXTHRESHOLD_SHIFT            0
#define UART_ET7816_RXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_RXTHRESHOLD_SHIFT))&UART_ET7816_RXTHRESHOLD_MASK)
#define UART_ET7816_TXTHRESHOLD_MASK             0xF0u
#define UART_ET7816_TXTHRESHOLD_SHIFT            4
#define UART_ET7816_TXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_TXTHRESHOLD_SHIFT))&UART_ET7816_TXTHRESHOLD_MASK)
/* TL7816 Bit Fields */
#define UART_TL7816_TLEN_MASK                    0xFFu
#define UART_TL7816_TLEN_SHIFT                   0
#define UART_TL7816_TLEN(x)                      (((uint8_t)(((uint8_t)(x))<<UART_TL7816_TLEN_SHIFT))&UART_TL7816_TLEN_MASK)

/*!
 * @}
 */ /* end of group UART_Register_Masks */


/* UART - Peripheral instance base addresses */
/** Peripheral UART0 base address */
#define UART0_BASE                               (0x4006A000u)
/** Peripheral UART0 base pointer */
#define UART0                                    ((UART_Type *)UART0_BASE)
/** Peripheral UART1 base address */
#define UART1_BASE                               (0x4006B000u)
/** Peripheral UART1 base pointer */
#define UART1                                    ((UART_Type *)UART1_BASE)
/** Peripheral UART2 base address */
#define UART2_BASE                               (0x4006C000u)
/** Peripheral UART2 base pointer */
#define UART2                                    ((UART_Type *)UART2_BASE)
/** Peripheral UART3 base address */
#define UART3_BASE                               (0x4006D000u)
/** Peripheral UART3 base pointer */
#define UART3                                    ((UART_Type *)UART3_BASE)
/** Array initializer of UART peripheral base pointers */
#define UART_BASES                               { UART0, UART1, UART2, UART3 }

/*!
 * @}
 */ /* end of group UART_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- VREF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VREF_Peripheral_Access_Layer VREF Peripheral Access Layer
 * @{
 */

/** VREF - Register Layout Typedef */
typedef struct {
  __IO uint8_t VREFH_TRM;                          /**< VREF Trim Register, offset: 0x0 */
  __IO uint8_t VREFH_SC;                           /**< VREF Status and Control Register, offset: 0x1 */
       uint8_t RESERVED_0[3];
  __IO uint8_t VREFL_TRM;                          /**< VREFL TRIM Register, offset: 0x5 */
} VREF_Type;

/* ----------------------------------------------------------------------------
   -- VREF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VREF_Register_Masks VREF Register Masks
 * @{
 */

/* VREFH_TRM Bit Fields */
#define VREF_VREFH_TRM_TRIM_MASK                 0x3Fu
#define VREF_VREFH_TRM_TRIM_SHIFT                0
#define VREF_VREFH_TRM_TRIM(x)                   (((uint8_t)(((uint8_t)(x))<<VREF_VREFH_TRM_TRIM_SHIFT))&VREF_VREFH_TRM_TRIM_MASK)
#define VREF_VREFH_TRM_CHOPEN_MASK               0x40u
#define VREF_VREFH_TRM_CHOPEN_SHIFT              6
/* VREFH_SC Bit Fields */
#define VREF_VREFH_SC_MODE_LV_MASK               0x3u
#define VREF_VREFH_SC_MODE_LV_SHIFT              0
#define VREF_VREFH_SC_MODE_LV(x)                 (((uint8_t)(((uint8_t)(x))<<VREF_VREFH_SC_MODE_LV_SHIFT))&VREF_VREFH_SC_MODE_LV_MASK)
#define VREF_VREFH_SC_VREFST_MASK                0x4u
#define VREF_VREFH_SC_VREFST_SHIFT               2
#define VREF_VREFH_SC_REGEN_MASK                 0x40u
#define VREF_VREFH_SC_REGEN_SHIFT                6
#define VREF_VREFH_SC_VREFEN_MASK                0x80u
#define VREF_VREFH_SC_VREFEN_SHIFT               7
/* VREFL_TRM Bit Fields */
#define VREF_VREFL_TRM_VREFL_TRIM_MASK           0x7u
#define VREF_VREFL_TRM_VREFL_TRIM_SHIFT          0
#define VREF_VREFL_TRM_VREFL_TRIM(x)             (((uint8_t)(((uint8_t)(x))<<VREF_VREFL_TRM_VREFL_TRIM_SHIFT))&VREF_VREFL_TRM_VREFL_TRIM_MASK)
#define VREF_VREFL_TRM_VREFL_EN_MASK             0x8u
#define VREF_VREFL_TRM_VREFL_EN_SHIFT            3
#define VREF_VREFL_TRM_VREFL_SEL_MASK            0x10u
#define VREF_VREFL_TRM_VREFL_SEL_SHIFT           4

/*!
 * @}
 */ /* end of group VREF_Register_Masks */


/* VREF - Peripheral instance base addresses */
/** Peripheral VREF base address */
#define VREF_BASE                                (0x4006F000u)
/** Peripheral VREF base pointer */
#define VREF                                     ((VREF_Type *)VREF_BASE)
/** Array initializer of VREF peripheral base pointers */
#define VREF_BASES                               { VREF }

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
  __IO uint16_t STCTRLH;                           /**< Watchdog Status and Control Register High, offset: 0x0 */
  __IO uint16_t STCTRLL;                           /**< Watchdog Status and Control Register Low, offset: 0x2 */
  __IO uint16_t TOVALH;                            /**< Watchdog Time-out Value Register High, offset: 0x4 */
  __IO uint16_t TOVALL;                            /**< Watchdog Time-out Value Register Low, offset: 0x6 */
  __IO uint16_t WINH;                              /**< Watchdog Window Register High, offset: 0x8 */
  __IO uint16_t WINL;                              /**< Watchdog Window Register Low, offset: 0xA */
  __IO uint16_t REFRESH;                           /**< Watchdog Refresh register, offset: 0xC */
  __IO uint16_t UNLOCK;                            /**< Watchdog Unlock register, offset: 0xE */
  __IO uint16_t TMROUTH;                           /**< Watchdog Timer Output Register High, offset: 0x10 */
  __IO uint16_t TMROUTL;                           /**< Watchdog Timer Output Register Low, offset: 0x12 */
  __IO uint16_t RSTCNT;                            /**< Watchdog Reset Count register, offset: 0x14 */
  __IO uint16_t PRESC;                             /**< Watchdog Prescaler register, offset: 0x16 */
} WDOG_Type;

/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Masks WDOG Register Masks
 * @{
 */

/* STCTRLH Bit Fields */
#define WDOG_STCTRLH_WDOGEN_MASK                 0x1u
#define WDOG_STCTRLH_WDOGEN_SHIFT                0
#define WDOG_STCTRLH_CLKSRC_MASK                 0x2u
#define WDOG_STCTRLH_CLKSRC_SHIFT                1
#define WDOG_STCTRLH_IRQRSTEN_MASK               0x4u
#define WDOG_STCTRLH_IRQRSTEN_SHIFT              2
#define WDOG_STCTRLH_WINEN_MASK                  0x8u
#define WDOG_STCTRLH_WINEN_SHIFT                 3
#define WDOG_STCTRLH_ALLOWUPDATE_MASK            0x10u
#define WDOG_STCTRLH_ALLOWUPDATE_SHIFT           4
#define WDOG_STCTRLH_DBGEN_MASK                  0x20u
#define WDOG_STCTRLH_DBGEN_SHIFT                 5
#define WDOG_STCTRLH_STOPEN_MASK                 0x40u
#define WDOG_STCTRLH_STOPEN_SHIFT                6
#define WDOG_STCTRLH_TESTWDOG_MASK               0x400u
#define WDOG_STCTRLH_TESTWDOG_SHIFT              10
#define WDOG_STCTRLH_TESTSEL_MASK                0x800u
#define WDOG_STCTRLH_TESTSEL_SHIFT               11
#define WDOG_STCTRLH_BYTESEL_MASK                0x3000u
#define WDOG_STCTRLH_BYTESEL_SHIFT               12
#define WDOG_STCTRLH_BYTESEL(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_BYTESEL_SHIFT))&WDOG_STCTRLH_BYTESEL_MASK)
#define WDOG_STCTRLH_DISTESTWDOG_MASK            0x4000u
#define WDOG_STCTRLH_DISTESTWDOG_SHIFT           14
/* STCTRLL Bit Fields */
#define WDOG_STCTRLL_INTFLG_MASK                 0x8000u
#define WDOG_STCTRLL_INTFLG_SHIFT                15
/* TOVALH Bit Fields */
#define WDOG_TOVALH_TOVALHIGH_MASK               0xFFFFu
#define WDOG_TOVALH_TOVALHIGH_SHIFT              0
#define WDOG_TOVALH_TOVALHIGH(x)                 (((uint16_t)(((uint16_t)(x))<<WDOG_TOVALH_TOVALHIGH_SHIFT))&WDOG_TOVALH_TOVALHIGH_MASK)
/* TOVALL Bit Fields */
#define WDOG_TOVALL_TOVALLOW_MASK                0xFFFFu
#define WDOG_TOVALL_TOVALLOW_SHIFT               0
#define WDOG_TOVALL_TOVALLOW(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_TOVALL_TOVALLOW_SHIFT))&WDOG_TOVALL_TOVALLOW_MASK)
/* WINH Bit Fields */
#define WDOG_WINH_WINHIGH_MASK                   0xFFFFu
#define WDOG_WINH_WINHIGH_SHIFT                  0
#define WDOG_WINH_WINHIGH(x)                     (((uint16_t)(((uint16_t)(x))<<WDOG_WINH_WINHIGH_SHIFT))&WDOG_WINH_WINHIGH_MASK)
/* WINL Bit Fields */
#define WDOG_WINL_WINLOW_MASK                    0xFFFFu
#define WDOG_WINL_WINLOW_SHIFT                   0
#define WDOG_WINL_WINLOW(x)                      (((uint16_t)(((uint16_t)(x))<<WDOG_WINL_WINLOW_SHIFT))&WDOG_WINL_WINLOW_MASK)
/* REFRESH Bit Fields */
#define WDOG_REFRESH_WDOGREFRESH_MASK            0xFFFFu
#define WDOG_REFRESH_WDOGREFRESH_SHIFT           0
#define WDOG_REFRESH_WDOGREFRESH(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_REFRESH_WDOGREFRESH_SHIFT))&WDOG_REFRESH_WDOGREFRESH_MASK)
/* UNLOCK Bit Fields */
#define WDOG_UNLOCK_WDOGUNLOCK_MASK              0xFFFFu
#define WDOG_UNLOCK_WDOGUNLOCK_SHIFT             0
#define WDOG_UNLOCK_WDOGUNLOCK(x)                (((uint16_t)(((uint16_t)(x))<<WDOG_UNLOCK_WDOGUNLOCK_SHIFT))&WDOG_UNLOCK_WDOGUNLOCK_MASK)
/* TMROUTH Bit Fields */
#define WDOG_TMROUTH_TIMEROUTHIGH_MASK           0xFFFFu
#define WDOG_TMROUTH_TIMEROUTHIGH_SHIFT          0
#define WDOG_TMROUTH_TIMEROUTHIGH(x)             (((uint16_t)(((uint16_t)(x))<<WDOG_TMROUTH_TIMEROUTHIGH_SHIFT))&WDOG_TMROUTH_TIMEROUTHIGH_MASK)
/* TMROUTL Bit Fields */
#define WDOG_TMROUTL_TIMEROUTLOW_MASK            0xFFFFu
#define WDOG_TMROUTL_TIMEROUTLOW_SHIFT           0
#define WDOG_TMROUTL_TIMEROUTLOW(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_TMROUTL_TIMEROUTLOW_SHIFT))&WDOG_TMROUTL_TIMEROUTLOW_MASK)
/* RSTCNT Bit Fields */
#define WDOG_RSTCNT_RSTCNT_MASK                  0xFFFFu
#define WDOG_RSTCNT_RSTCNT_SHIFT                 0
#define WDOG_RSTCNT_RSTCNT(x)                    (((uint16_t)(((uint16_t)(x))<<WDOG_RSTCNT_RSTCNT_SHIFT))&WDOG_RSTCNT_RSTCNT_MASK)
/* PRESC Bit Fields */
#define WDOG_PRESC_PRESCVAL_MASK                 0x700u
#define WDOG_PRESC_PRESCVAL_SHIFT                8
#define WDOG_PRESC_PRESCVAL(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_PRESC_PRESCVAL_SHIFT))&WDOG_PRESC_PRESCVAL_MASK)

/*!
 * @}
 */ /* end of group WDOG_Register_Masks */


/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG base address */
#define WDOG_BASE                                (0x40053000u)
/** Peripheral WDOG base pointer */
#define WDOG                                     ((WDOG_Type *)WDOG_BASE)
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASES                               { WDOG }

/*!
 * @}
 */ /* end of group WDOG_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- XBAR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR_Peripheral_Access_Layer XBAR Peripheral Access Layer
 * @{
 */

/** XBAR - Register Layout Typedef */
typedef struct {
  __IO uint16_t SEL0;                              /**< Crossbar Select Register 0, offset: 0x0 */
  __IO uint16_t SEL1;                              /**< Crossbar Select Register 1, offset: 0x2 */
  __IO uint16_t SEL2;                              /**< Crossbar Select Register 2, offset: 0x4 */
  __IO uint16_t SEL3;                              /**< Crossbar Select Register 3, offset: 0x6 */
  __IO uint16_t SEL4;                              /**< Crossbar Select Register 4, offset: 0x8 */
  __IO uint16_t SEL5;                              /**< Crossbar Select Register 5, offset: 0xA */
  __IO uint16_t SEL6;                              /**< Crossbar Select Register 6, offset: 0xC */
  __IO uint16_t SEL7;                              /**< Crossbar Select Register 7, offset: 0xE */
  __IO uint16_t SEL8;                              /**< Crossbar Select Register 8, offset: 0x10 */
  __IO uint16_t SEL9;                              /**< Crossbar Select Register 9, offset: 0x12 */
  __IO uint16_t SEL10;                             /**< Crossbar Select Register 10, offset: 0x14 */
  __IO uint16_t SEL11;                             /**< Crossbar Select Register 11, offset: 0x16 */
  __IO uint16_t SEL12;                             /**< Crossbar Select Register 12, offset: 0x18 */
  __IO uint16_t SEL13;                             /**< Crossbar Select Register 13, offset: 0x1A */
  __IO uint16_t SEL14;                             /**< Crossbar Select Register 14, offset: 0x1C */
  __IO uint16_t SEL15;                             /**< Crossbar Select Register 15, offset: 0x1E */
  __IO uint16_t SEL16;                             /**< Crossbar Select Register 16, offset: 0x20 */
  __IO uint16_t CTRL0;                             /**< Crossbar Control Register 0, offset: 0x22 */
} XBAR_Type;

/* ----------------------------------------------------------------------------
   -- XBAR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR_Register_Masks XBAR Register Masks
 * @{
 */

/* SEL0 Bit Fields */
#define XBAR_SEL0_SEL0_MASK                      0x3Fu
#define XBAR_SEL0_SEL0_SHIFT                     0
#define XBAR_SEL0_SEL0(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL0_SEL0_SHIFT))&XBAR_SEL0_SEL0_MASK)
#define XBAR_SEL0_SEL1_MASK                      0x3F00u
#define XBAR_SEL0_SEL1_SHIFT                     8
#define XBAR_SEL0_SEL1(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL0_SEL1_SHIFT))&XBAR_SEL0_SEL1_MASK)
/* SEL1 Bit Fields */
#define XBAR_SEL1_SEL2_MASK                      0x3Fu
#define XBAR_SEL1_SEL2_SHIFT                     0
#define XBAR_SEL1_SEL2(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL1_SEL2_SHIFT))&XBAR_SEL1_SEL2_MASK)
#define XBAR_SEL1_SEL3_MASK                      0x3F00u
#define XBAR_SEL1_SEL3_SHIFT                     8
#define XBAR_SEL1_SEL3(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL1_SEL3_SHIFT))&XBAR_SEL1_SEL3_MASK)
/* SEL2 Bit Fields */
#define XBAR_SEL2_SEL4_MASK                      0x3Fu
#define XBAR_SEL2_SEL4_SHIFT                     0
#define XBAR_SEL2_SEL4(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL2_SEL4_SHIFT))&XBAR_SEL2_SEL4_MASK)
#define XBAR_SEL2_SEL5_MASK                      0x3F00u
#define XBAR_SEL2_SEL5_SHIFT                     8
#define XBAR_SEL2_SEL5(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL2_SEL5_SHIFT))&XBAR_SEL2_SEL5_MASK)
/* SEL3 Bit Fields */
#define XBAR_SEL3_SEL6_MASK                      0x3Fu
#define XBAR_SEL3_SEL6_SHIFT                     0
#define XBAR_SEL3_SEL6(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL3_SEL6_SHIFT))&XBAR_SEL3_SEL6_MASK)
#define XBAR_SEL3_SEL7_MASK                      0x3F00u
#define XBAR_SEL3_SEL7_SHIFT                     8
#define XBAR_SEL3_SEL7(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL3_SEL7_SHIFT))&XBAR_SEL3_SEL7_MASK)
/* SEL4 Bit Fields */
#define XBAR_SEL4_SEL8_MASK                      0x3Fu
#define XBAR_SEL4_SEL8_SHIFT                     0
#define XBAR_SEL4_SEL8(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL4_SEL8_SHIFT))&XBAR_SEL4_SEL8_MASK)
#define XBAR_SEL4_SEL9_MASK                      0x3F00u
#define XBAR_SEL4_SEL9_SHIFT                     8
#define XBAR_SEL4_SEL9(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL4_SEL9_SHIFT))&XBAR_SEL4_SEL9_MASK)
/* SEL5 Bit Fields */
#define XBAR_SEL5_SEL10_MASK                     0x3Fu
#define XBAR_SEL5_SEL10_SHIFT                    0
#define XBAR_SEL5_SEL10(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL5_SEL10_SHIFT))&XBAR_SEL5_SEL10_MASK)
#define XBAR_SEL5_SEL11_MASK                     0x3F00u
#define XBAR_SEL5_SEL11_SHIFT                    8
#define XBAR_SEL5_SEL11(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL5_SEL11_SHIFT))&XBAR_SEL5_SEL11_MASK)
/* SEL6 Bit Fields */
#define XBAR_SEL6_SEL12_MASK                     0x3Fu
#define XBAR_SEL6_SEL12_SHIFT                    0
#define XBAR_SEL6_SEL12(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL6_SEL12_SHIFT))&XBAR_SEL6_SEL12_MASK)
#define XBAR_SEL6_SEL13_MASK                     0x3F00u
#define XBAR_SEL6_SEL13_SHIFT                    8
#define XBAR_SEL6_SEL13(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL6_SEL13_SHIFT))&XBAR_SEL6_SEL13_MASK)
/* SEL7 Bit Fields */
#define XBAR_SEL7_SEL14_MASK                     0x3Fu
#define XBAR_SEL7_SEL14_SHIFT                    0
#define XBAR_SEL7_SEL14(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL7_SEL14_SHIFT))&XBAR_SEL7_SEL14_MASK)
#define XBAR_SEL7_SEL15_MASK                     0x3F00u
#define XBAR_SEL7_SEL15_SHIFT                    8
#define XBAR_SEL7_SEL15(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL7_SEL15_SHIFT))&XBAR_SEL7_SEL15_MASK)
/* SEL8 Bit Fields */
#define XBAR_SEL8_SEL16_MASK                     0x3Fu
#define XBAR_SEL8_SEL16_SHIFT                    0
#define XBAR_SEL8_SEL16(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL8_SEL16_SHIFT))&XBAR_SEL8_SEL16_MASK)
#define XBAR_SEL8_SEL17_MASK                     0x3F00u
#define XBAR_SEL8_SEL17_SHIFT                    8
#define XBAR_SEL8_SEL17(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL8_SEL17_SHIFT))&XBAR_SEL8_SEL17_MASK)
/* SEL9 Bit Fields */
#define XBAR_SEL9_SEL18_MASK                     0x3Fu
#define XBAR_SEL9_SEL18_SHIFT                    0
#define XBAR_SEL9_SEL18(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL9_SEL18_SHIFT))&XBAR_SEL9_SEL18_MASK)
#define XBAR_SEL9_SEL19_MASK                     0x3F00u
#define XBAR_SEL9_SEL19_SHIFT                    8
#define XBAR_SEL9_SEL19(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL9_SEL19_SHIFT))&XBAR_SEL9_SEL19_MASK)
/* SEL10 Bit Fields */
#define XBAR_SEL10_SEL20_MASK                    0x1Fu
#define XBAR_SEL10_SEL20_SHIFT                   0
#define XBAR_SEL10_SEL20(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL10_SEL20_SHIFT))&XBAR_SEL10_SEL20_MASK)
#define XBAR_SEL10_SEL21_MASK                    0x1F00u
#define XBAR_SEL10_SEL21_SHIFT                   8
#define XBAR_SEL10_SEL21(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL10_SEL21_SHIFT))&XBAR_SEL10_SEL21_MASK)
/* SEL11 Bit Fields */
#define XBAR_SEL11_SEL22_MASK                    0x3Fu
#define XBAR_SEL11_SEL22_SHIFT                   0
#define XBAR_SEL11_SEL22(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL11_SEL22_SHIFT))&XBAR_SEL11_SEL22_MASK)
#define XBAR_SEL11_SEL23_MASK                    0x3F00u
#define XBAR_SEL11_SEL23_SHIFT                   8
#define XBAR_SEL11_SEL23(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL11_SEL23_SHIFT))&XBAR_SEL11_SEL23_MASK)
/* SEL12 Bit Fields */
#define XBAR_SEL12_SEL24_MASK                    0x1Fu
#define XBAR_SEL12_SEL24_SHIFT                   0
#define XBAR_SEL12_SEL24(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL12_SEL24_SHIFT))&XBAR_SEL12_SEL24_MASK)
#define XBAR_SEL12_SEL25_MASK                    0x1F00u
#define XBAR_SEL12_SEL25_SHIFT                   8
#define XBAR_SEL12_SEL25(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL12_SEL25_SHIFT))&XBAR_SEL12_SEL25_MASK)
/* SEL13 Bit Fields */
#define XBAR_SEL13_SEL26_MASK                    0x3Fu
#define XBAR_SEL13_SEL26_SHIFT                   0
#define XBAR_SEL13_SEL26(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL13_SEL26_SHIFT))&XBAR_SEL13_SEL26_MASK)
#define XBAR_SEL13_SEL27_MASK                    0x3F00u
#define XBAR_SEL13_SEL27_SHIFT                   8
#define XBAR_SEL13_SEL27(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL13_SEL27_SHIFT))&XBAR_SEL13_SEL27_MASK)
/* SEL14 Bit Fields */
#define XBAR_SEL14_SEL28_MASK                    0x3Fu
#define XBAR_SEL14_SEL28_SHIFT                   0
#define XBAR_SEL14_SEL28(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL14_SEL28_SHIFT))&XBAR_SEL14_SEL28_MASK)
#define XBAR_SEL14_SEL29_MASK                    0x3F00u
#define XBAR_SEL14_SEL29_SHIFT                   8
#define XBAR_SEL14_SEL29(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL14_SEL29_SHIFT))&XBAR_SEL14_SEL29_MASK)
/* SEL15 Bit Fields */
#define XBAR_SEL15_SEL30_MASK                    0x1Fu
#define XBAR_SEL15_SEL30_SHIFT                   0
#define XBAR_SEL15_SEL30(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL15_SEL30_SHIFT))&XBAR_SEL15_SEL30_MASK)
#define XBAR_SEL15_SEL31_MASK                    0x1F00u
#define XBAR_SEL15_SEL31_SHIFT                   8
#define XBAR_SEL15_SEL31(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL15_SEL31_SHIFT))&XBAR_SEL15_SEL31_MASK)
/* SEL16 Bit Fields */
#define XBAR_SEL16_SEL32_MASK                    0x3Fu
#define XBAR_SEL16_SEL32_SHIFT                   0
#define XBAR_SEL16_SEL32(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL16_SEL32_SHIFT))&XBAR_SEL16_SEL32_MASK)
/* CTRL0 Bit Fields */
#define XBAR_CTRL0_DEN0_MASK                     0x1u
#define XBAR_CTRL0_DEN0_SHIFT                    0
#define XBAR_CTRL0_IEN0_MASK                     0x2u
#define XBAR_CTRL0_IEN0_SHIFT                    1
#define XBAR_CTRL0_EDGE0_MASK                    0xCu
#define XBAR_CTRL0_EDGE0_SHIFT                   2
#define XBAR_CTRL0_EDGE0(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_CTRL0_EDGE0_SHIFT))&XBAR_CTRL0_EDGE0_MASK)
#define XBAR_CTRL0_STS0_MASK                     0x10u
#define XBAR_CTRL0_STS0_SHIFT                    4

/*!
 * @}
 */ /* end of group XBAR_Register_Masks */


/* XBAR - Peripheral instance base addresses */
/** Peripheral XBAR base address */
#define XBAR_BASE                                (0x40055000u)
/** Peripheral XBAR base pointer */
#define XBAR                                     ((XBAR_Type *)XBAR_BASE)
/** Array initializer of XBAR peripheral base pointers */
#define XBAR_BASES                               { XBAR }

/*!
 * @}
 */ /* end of group XBAR_Peripheral_Access_Layer */


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

#define CRC_CRCL_CRCL_MASK                       CRC_DATAL_DATAL_MASK
#define CRC_CRCL_CRCL_SHIFT                      CRC_DATAL_DATAL_SHIFT
#define CRC_CRCL_CRCL(x)                         CRC_DATAL_DATAL(x)
#define CRC_CRCH_CRCH_MASK                       CRC_DATAH_DATAH_MASK
#define CRC_CRCH_CRCH_SHIFT                      CRC_DATAH_DATAH_SHIFT
#define CRC_CRCH_CRCH(x)                         CRC_DATAH_DATAH(x)
#define CRC_CRC_LL_MASK                          CRC_DATA_LL_MASK
#define CRC_CRC_LL_SHIFT                         CRC_DATA_LL_SHIFT
#define CRC_CRC_LL(x)                            CRC_DATA_LL(x)
#define CRC_CRC_LU_MASK                          CRC_DATA_LU_MASK
#define CRC_CRC_LU_SHIFT                         CRC_DATA_LU_SHIFT
#define CRC_CRC_LU(x)                            CRC_DATA_LU(x)
#define CRC_CRC_HL_MASK                          CRC_DATA_HL_MASK
#define CRC_CRC_HL_SHIFT                         CRC_DATA_HL_SHIFT
#define CRC_CRC_HL(x)                            CRC_DATA_HL(x)
#define CRC_CRC_HU_MASK                          CRC_DATA_HU_MASK
#define CRC_CRC_HU_SHIFT                         CRC_DATA_HU_SHIFT
#define CRC_CRC_HU(x)                            CRC_DATA_HU(x)
#define CRC_CRCLL_CRCLL_MASK                     CRC_DATALL_DATALL_MASK
#define CRC_CRCLL_CRCLL_SHIFT                    CRC_DATALL_DATALL_SHIFT
#define CRC_CRCLL_CRCLL(x)                       CRC_DATALL_DATALL(x)
#define CRC_CRCLU_CRCLU_MASK                     CRC_DATALU_DATALU_MASK
#define CRC_CRCLU_CRCLU_SHIFT                    CRC_DATALU_DATALU_SHIFT
#define CRC_CRCLU_CRCLU(x)                       CRC_DATALU_DATALU(x)
#define CRC_CRCHL_CRCHL_MASK                     CRC_DATAHL_DATAHL_MASK
#define CRC_CRCHL_CRCHL_SHIFT                    CRC_DATAHL_DATAHL_SHIFT
#define CRC_CRCHL_CRCHL(x)                       CRC_DATAHL_DATAHL(x)
#define CRC_CRCHU_CRCHU_MASK                     CRC_DATAHU_DATAHU_MASK
#define CRC_CRCHU_CRCHU_SHIFT                    CRC_DATAHU_DATAHU_SHIFT
#define CRC_CRCHU_CRCHU(x)                       CRC_DATAHU_DATAHU(x)
#define MCG_C11_PLLCS_MASK                       This_symbol_has_been_deprecated
#define MCG_C11_PLLCS_SHIFT                      This_symbol_has_been_deprecated
#define MCM_MATCR_ATC1_MASK                      This_symbol_has_been_deprecated
#define MCM_MATCR_ATC1_SHIFT                     This_symbol_has_been_deprecated
#define MCM_MATCR_ATC1(x)                        This_symbol_has_been_deprecated
#define MCM_MATCR_RO1_MASK                       This_symbol_has_been_deprecated
#define MCM_MATCR_RO1_SHIFT                      This_symbol_has_been_deprecated
#define MCM_MATCR_ATC3_MASK                      This_symbol_has_been_deprecated
#define MCM_MATCR_ATC3_SHIFT                     This_symbol_has_been_deprecated
#define MCM_MATCR_ATC3(x)                        This_symbol_has_been_deprecated
#define MCM_MATCR_RO3_MASK                       This_symbol_has_been_deprecated
#define MCM_MATCR_RO3_SHIFT                      This_symbol_has_been_deprecated

/*!
 * @}
 */ /* end of group Backward_Compatibility_Symbols */


#endif  /* #if !defined(MKM13Z5_H_) */

/* MKM13Z5.h, eof. */
