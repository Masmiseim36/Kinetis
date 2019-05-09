/*
 * Copyright 2014-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __FSL_DEVICE_REGISTERS_H__
#define __FSL_DEVICE_REGISTERS_H__

/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */
#if (defined(CPU_MK02FN128VFM10) || defined(CPU_MK02FN128VLF10) || defined(CPU_MK02FN128VLH10) || \
	defined(CPU_MK02FN64VFM10) || defined(CPU_MK02FN64VLF10) || defined(CPU_MK02FN64VLH10) || defined(MK02F12810))
	#define K02F12810_SERIES
	/* CMSIS-style register definitions */
	#include "MK02F12810.h"
	/* CPU specific feature definitions */
	#include "MK02F12810_features.h"
#elif (defined(CPU_MK22FN512CAP12) || defined(CPU_MK22FN512VDC12) || defined(CPU_MK22FN512VFX12) || \
	defined(CPU_MK22FN512VLH12) || defined(CPU_MK22FN512VLL12) || defined(CPU_MK22FN512VMP12) || defined(MK22F51212))
	#define K22F51212_SERIES
	/* CMSIS-style register definitions */
	#include "MK22F51212.h"
	/* CPU specific feature definitions */
	#include "MK22F51212_features.h"
#elif (defined(CPU_MK28FN2M0CAU15R) || defined(CPU_MK28FN2M0VMI15) || defined(MK28F15))
	#define K28F15_SERIES
	/* CMSIS-style register definitions */
	#include "MK28F15.h"
	/* CPU specific feature definitions */
	#include "MK28F15_features.h"
#elif (defined(CPU_MK64FN1M0CAJ12) || defined(CPU_MK64FN1M0VDC12) || defined(CPU_MK64FN1M0VLL12) || \
	defined(CPU_MK64FN1M0VLQ12) || defined(CPU_MK64FN1M0VMD12) || defined(CPU_MK64FX512VDC12) || \
	defined(CPU_MK64FX512VLL12) || defined(CPU_MK64FX512VLQ12) || defined(CPU_MK64FX512VMD12) || defined(MK64F12))
	#define K64F12_SERIES
	/* CMSIS-style register definitions */
	#include "MK64F12.h"
	/* CPU specific feature definitions */
	#include "MK64F12_features.h"
#elif (defined(CPU_MK65FN2M0CAC18) || defined(CPU_MK65FX1M0CAC18) || defined(CPU_MK65FN2M0VMI18) || \
	defined(CPU_MK65FX1M0VMI18) || defined(MK65F18))
	#define K65F18_SERIES
	/* CMSIS-style register definitions */
	#include "MK65F18.h"
	/* CPU specific feature definitions */
	#include "MK65F18_features.h"
#elif (defined(CPU_MK66FN2M0VLQ18) || defined(CPU_MK66FN2M0VMD18) || defined(CPU_MK66FX1M0VLQ18) || \
	defined(CPU_MK66FX1M0VMD18) || defined(MK66F18))
	#define K66F18_SERIES
	/* CMSIS-style register definitions */
	#include "MK66F18.h"
	/* CPU specific feature definitions */
	#include "MK66F18_features.h"
#elif (defined(CPU_MK80FN256CAx15) || defined(CPU_MK80FN256VDC15) || defined(CPU_MK80FN256VLL15) || \
	defined(CPU_MK80FN256VLQ15) || defined(MK80F25615))
	#define K80F25615_SERIES
	/* CMSIS-style register definitions */
	#include "MK80F25615.h"
	/* CPU specific feature definitions */
	#include "MK80F25615_features.h"
#elif (defined(CPU_MK82FN256CAx15) || defined(CPU_MK82FN256VDC15) || defined(CPU_MK82FN256VLL15) || \
    defined(CPU_MK82FN256VLQ15) || defined(MK82F25615))
	#define K82F25615_SERIES
	/* CMSIS-style register definitions */
	#include "MK82F25615.h"
	/* CPU specific feature definitions */
	#include "MK82F25615_features.h"
#elif (defined(CPU_MKL25Z128VFM4) || defined(CPU_MKL25Z128VFT4) || defined(CPU_MKL25Z128VLH4) || \
	defined(CPU_MKL25Z128VLK4) || defined(CPU_MKL25Z32VFM4) || defined(CPU_MKL25Z32VFT4) || \
	defined(CPU_MKL25Z32VLH4) || defined(CPU_MKL25Z32VLK4) || defined(CPU_MKL25Z64VFM4) || \
	defined(CPU_MKL25Z64VFT4) || defined(CPU_MKL25Z64VLH4) || defined(CPU_MKL25Z64VLK4) || defined(MKL25Z4))
	#define KL25Z4_SERIES´
	/* CMSIS-style register definitions */
	#include "MKL25Z4.h"
	/* CPU specific feature definitions */
	#include "MKL25Z4_features.h"
#elif (defined(CPU_MKL82Z128VLH7) || defined(CPU_MKL82Z128VLK7) || defined(CPU_MKL82Z128VLL7) || \
	defined(CPU_MKL82Z128VMC7) || defined(CPU_MKL82Z128VMP7) || defined(MKL82Z7))
	#define KL82Z7_SERIES
	/* CMSIS-style register definitions */
	#include "MKL82Z7.h"
	/* CPU specific feature definitions */
	#include "MKL82Z7_features.h"
#elif (defined(CPU_MKV11Z128VFM7) || defined(CPU_MKV11Z128VLC7) || defined(CPU_MKV11Z128VLF7) || \
	defined(CPU_MKV11Z128VLH7) || defined(CPU_MKV11Z64VFM7) || defined(CPU_MKV11Z64VLC7) || \
	defined(CPU_MKV11Z64VLF7) || defined(CPU_MKV11Z64VLH7) || defined(MKV11Z7))
	#define KV11Z7_SERIES
	/* CMSIS-style register definitions */
	#include "MKV11Z7.h"
	/* CPU specific feature definitions */
	#include "MKV11Z7_features.h"
#elif (defined(CPU_MKV31F512VLH12) || defined(CPU_MKV31F512VLL12) || defined(MKV31F51212))
	#define KV31F51212_SERIES
	/* CMSIS-style register definitions */
	#include "MKV31F51212.h"
	/* CPU specific feature definitions */
	#include "MKV31F51212_features.h"
#elif (defined(CPU_MKV46F128VLH16) || defined(CPU_MKV46F128VLL16) || defined(CPU_MKV46F256VLH16) || \
	defined(CPU_MKV46F256VLL16) || defined(MKV46F16))
	#define KV46F16_SERIES
	/* CMSIS-style register definitions */
	#include "MKV46F16.h"
	/* CPU specific feature definitions */
	#include "MKV46F16_features.h"
#elif (defined(CPU_MKV58F1M0VLL24) || defined(CPU_MKV58F1M0VLQ24) || defined(CPU_MKV58F1M0VMD24) || \
    defined(CPU_MKV58F512VLL24) || defined(CPU_MKV58F512VLQ24) || defined(CPU_MKV58F512VMD24) || defined(MKV58F24))
	#define KV58F24_SERIES
	/* CMSIS-style register definitions */
	#include "MKV58F24.h"
	/* CPU specific feature definitions */
	#include "MKV58F24_features.h"
#elif (defined(CPU_MKW31Z256VHT4) || defined(CPU_MKW31Z512CAT4) || defined(CPU_MKW31Z512VHT4) || defined(MKW31Z4))
	#define KW31Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKW31Z4.h"
	/* CPU specific feature definitions */
	#include "MKW31Z4_features.h"
#elif (defined(CPU_MKW41Z256VHT4) || defined(CPU_MKW41Z512CAT4) || defined(CPU_MKW41Z512VHT4) || defined(MKW41Z4))
	#define KW41Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKW41Z4.h"
	/* CPU specific feature definitions */
	#include "MKW41Z4_features.h"
#else
	#error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
