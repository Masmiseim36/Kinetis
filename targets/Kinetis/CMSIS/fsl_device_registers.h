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
#elif (defined(CPU_MK10DN512VLK10) || defined(CPU_MK10DN512VLL10) || defined(CPU_MK10DN512VLQ10) || \
	defined(CPU_MK10DN512VMC10) || defined(CPU_MK10DN512VMD10) || defined(CPU_MK10DX128VLQ10) || \
	defined(CPU_MK10DX128VMD10) || defined(CPU_MK10DX256VLQ10) || defined(CPU_MK10DX256VMD10) || defined(MK10D10))
	#define K10D10_SERIES
	/* CMSIS-style register definitions */
	#include "MK10D10.h"
	/* CPU specific feature definitions */
	#include "MK10D10_features.h"
#elif (defined(CPU_MK11DN512AVLK5) || defined(CPU_MK11DN512AVMC5) || defined(CPU_MK11DX128AVLK5) || \
	defined(CPU_MK11DX128AVMC5) || defined(CPU_MK11DX256AVLK5) || defined(CPU_MK11DX256AVMC5) || defined(MK11DA5))
	#define K11DA5_SERIES
	/* CMSIS-style register definitions */
	#include "MK11DA5.h"
	/* CPU specific feature definitions */
	#include "MK11DA5_features.h"
#elif (defined(CPU_MK11DN512VLK5) || defined(CPU_MK11DN512VMC5) || defined(CPU_MK11DX128VLK5) || \
	defined(CPU_MK11DX128VMC5) || defined(CPU_MK11DX256VLK5) || defined(CPU_MK11DX256VMC5) || defined(MK11D5))
	#define K11D5_SERIES
	/* CMSIS-style register definitions */
	#include "MK11D5.h"
	/* CPU specific feature definitions */
	#include "MK11D5_features.h"
#elif (defined(CPU_MK12DN512VLH5) || defined(CPU_MK12DN512VLK5) || defined(CPU_MK12DN512VMC5) || \
	defined(CPU_MK12DX128VLF5) || defined(CPU_MK12DX128VLH5) || defined(CPU_MK12DX128VLK5) || \
	defined(CPU_MK12DX128VMC5) || defined(CPU_MK12DX256VLF5) || defined(CPU_MK12DX256VLH5) || \
	defined(CPU_MK12DX256VLK5) || defined(CPU_MK12DX256VMC5) || defined(MK12D5))
	#define K12D5_SERIES
	/* CMSIS-style register definitions */
	#include "MK12D5.h"
	/* CPU specific feature definitions */
	#include "MK12D5_features.h"
#elif (defined(CPU_MK20DN512VLK10) || defined(CPU_MK20DN512VLL10) || defined(CPU_MK20DN512VLQ10) || \
	defined(CPU_MK20DN512VMC10) || defined(CPU_MK20DN512VMD10) || defined(CPU_MK20DX128VLQ10) || \
	defined(CPU_MK20DX128VMD10) || defined(CPU_MK20DX256VLK10) || defined(CPU_MK20DX256VLL10) || \
	defined(CPU_MK20DX256VLQ10) || defined(CPU_MK20DX256VMC10) || defined(CPU_MK20DX256VMD10) || defined(MK20D10))
	#define K20D10_SERIES
	/* CMSIS-style register definitions */
	#include "MK20D10.h"
	/* CPU specific feature definitions */
	#include "MK20D10_features.h"
#elif (defined(CPU_MK21DN512VLK5) || defined(CPU_MK21DN512VMC5) || defined(CPU_MK21DX128VLK5) || \
	defined(CPU_MK21DX128VMC5) || defined(CPU_MK21DX256VLK5) || defined(CPU_MK21DX256VMC5) || defined(MK21D5))
	#define K21D5_SERIES
	/* CMSIS-style register definitions */
	#include "MK21D5.h"
	/* CPU specific feature definitions */
	#include "MK21D5_features.h"
#elif (defined(CPU_MK21DN512AVLK5) || defined(CPU_MK21DN512AVMC5) || defined(CPU_MK21DX128AVLK5) || \
	defined(CPU_MK21DX128AVMC5) || defined(CPU_MK21DX256AVLK5) || defined(CPU_MK21DX256AVMC5) || defined(MK21DA5))
	#define K21DA5_SERIES
	/* CMSIS-style register definitions */
	#include "MK21DA5.h"
	/* CPU specific feature definitions */
	#include "MK21DA5_features.h"
#elif (defined(CPU_MK21FN1M0VLQ12) || defined(CPU_MK21FN1M0VMC12) || defined(CPU_MK21FN1M0VMD12) || \
	defined(CPU_MK21FX512VLQ12) || defined(CPU_MK21FX512VMC12) || defined(CPU_MK21FX512VMD12) || defined(MK21F12))
	#define K21F12_SERIES
	/* CMSIS-style register definitions */
	#include "MK21F12.h"
	/* CPU specific feature definitions */
	#include "MK21F12_features.h"
#elif (defined(CPU_MK21FN1M0AVLQ12) || defined(CPU_MK21FN1M0AVMC12) || defined(CPU_MK21FN1M0AVMD12) || \
	defined(CPU_MK21FX512AVLQ12) || defined(CPU_MK21FX512AVMC12) || defined(CPU_MK21FX512AVMD12) || defined(MK21FA12))
	#define K21FA12_SERIES
	/* CMSIS-style register definitions */
	#include "MK21FA12.h"
	/* CPU specific feature definitions */
	#include "MK21FA12_features.h"
#elif (defined(CPU_MK22DN512VLH5) || defined(CPU_MK22DN512VLK5) || defined(CPU_MK22DN512VMC5) || \
	defined(CPU_MK22DX128VLF5) || defined(CPU_MK22DX128VLH5) || defined(CPU_MK22DX128VLK5) || \
	defined(CPU_MK22DX128VMC5) || defined(CPU_MK22DX256VLF5) || defined(CPU_MK22DX256VLH5) || \
	defined(CPU_MK22DX256VLK5) || defined(CPU_MK22DX256VMC5) || defined(MK22D5))
	#define K22D5_SERIES
	/* CMSIS-style register definitions */
	#include "MK22D5.h"
	/* CPU specific feature definitions */
	#include "MK22D5_features.h"
#elif (defined(CPU_MK22FN1M0VLH12) || defined(CPU_MK22FN1M0VLK12) || defined(CPU_MK22FN1M0VLL12) || \
	defined(CPU_MK22FN1M0VLQ12) || defined(CPU_MK22FN1M0VMC12) || defined(CPU_MK22FN1M0VMD12) || \
	defined(CPU_MK22FX512VLH12) || defined(CPU_MK22FX512VLK12) || defined(CPU_MK22FX512VLL12) || \
	defined(CPU_MK22FX512VLQ12) || defined(CPU_MK22FX512VMC12) || defined(CPU_MK22FX512VMD12) || defined(MK22F12))
	#define K22F12_SERIES
	/* CMSIS-style register definitions */
	#include "MK22F12.h"
	/* CPU specific feature definitions */
	#include "MK22F12_features.h"
#elif (defined(CPU_MK22FN128VDC10) || defined(CPU_MK22FN128VLH10) || defined(CPU_MK22FN128VLL10) || \
	defined(CPU_MK22FN128VMP10) || defined(MK22F12810))
	#define K22F12810_SERIES
	/* CMSIS-style register definitions */
	#include "MK22F12810.h"
	/* CPU specific feature definitions */
	#include "MK22F12810_features.h"
#elif (defined(CPU_MK22FN128CAH12) || defined(CPU_MK22FN256CAH12) || defined(CPU_MK22FN256VDC12) || \
    defined(CPU_MK22FN256VLH12) || defined(CPU_MK22FN256VLL12) || defined(CPU_MK22FN256VMP12) || defined(MK22F25612))
	#define K22F25612_SERIES
	/* CMSIS-style register definitions */
	#include "MK22F25612.h"
	/* CPU specific feature definitions */
	#include "MK22F25612_features.h"
#elif (defined(CPU_MK22FN512CAP12) || defined(CPU_MK22FN512VDC12) || defined(CPU_MK22FN512VFX12) || \
	defined(CPU_MK22FN512VLH12) || defined(CPU_MK22FN512VLL12) || defined(CPU_MK22FN512VMP12) || defined(MK22F51212))
	#define K22F51212_SERIES
	/* CMSIS-style register definitions */
	#include "MK22F51212.h"
	/* CPU specific feature definitions */
	#include "MK22F51212_features.h"
#elif (defined(CPU_MK22FN1M0AVLH12) || defined(CPU_MK22FN1M0AVLK12) || defined(CPU_MK22FN1M0AVLL12) || \
	defined(CPU_MK22FN1M0AVLQ12) || defined(CPU_MK22FN1M0AVMC12) || defined(CPU_MK22FN1M0AVMD12) || \
	defined(CPU_MK22FX512AVLH12) || defined(CPU_MK22FX512AVLK12) || defined(CPU_MK22FX512AVLL12) || \
	defined(CPU_MK22FX512AVLQ12) || defined(CPU_MK22FX512AVMC12) || defined(CPU_MK22FX512AVMD12) || defined(MK22FA12))
	#define K22FA12_SERIES
	/* CMSIS-style register definitions */
	#include "MK22FA12.h"
	/* CPU specific feature definitions */
	#include "MK22FA12_features.h"
#elif (defined(CPU_MK24FN1M0CAJ12) || defined(CPU_MK24FN1M0VDC12) || defined(CPU_MK24FN1M0VLL12) || \
	defined(CPU_MK24FN1M0VLQ12) || defined(MK24F12))
	#define K24F12_SERIES
	/* CMSIS-style register definitions */
	#include "MK24F12.h"
	/* CPU specific feature definitions */
	#include "MK24F12_features.h"
#elif (defined(CPU_MK24FN256VDC12) || defined(MK24F25612))
	#define K24F25612_SERIES
	/* CMSIS-style register definitions */
	#include "MK24F25612.h"
	/* CPU specific feature definitions */
	#include "MK24F25612_features.h"
#elif (defined(CPU_MK26FN2M0CAC18) || defined(CPU_MK26FN2M0VLQ18) || defined(CPU_MK26FN2M0VMD18) || \
	defined(CPU_MK26FN2M0VMI18) || defined(MK26F18))
	#define K26F18_SERIES
	/* CMSIS-style register definitions */
	#include "MK26F18.h"
	/* CPU specific feature definitions */
	#include "MK26F18_features.h"
#elif (defined(CPU_MK27FN2M0VMI15) || defined(MK27F15))
	#define K27F15_SERIES
	/* CMSIS-style register definitions */
	#include "MK27F15.h"
	/* CPU specific feature definitions */
	#include "MK27F15_features.h"
#elif (defined(CPU_MK27FN2M0AVMI15) || defined(MK27FA15))
	#define K27FA15_SERIES
	/* CMSIS-style register definitions */
	#include "MK27FA15.h"
	/* CPU specific feature definitions */
	#include "MK27FA15_features.h"
#elif (defined(CPU_MK28FN2M0CAU15R) || defined(CPU_MK28FN2M0VMI15) || defined(MK28F15))
	#define K28F15_SERIES
	/* CMSIS-style register definitions */
	#include "MK28F15.h"
	/* CPU specific feature definitions */
	#include "MK28F15_features.h"
#elif (defined(CPU_MK28FN2M0ACAU15R) || defined(CPU_MK28FN2M0AVMI15) || defined(MK28FA15))
	#define K28FA15_SERIES
	/* CMSIS-style register definitions */
	#include "MK28FA15.h"
	/* CPU specific feature definitions */
	#include "MK28FA15_features.h"
#elif (defined(CPU_MK30DN512VLK10) || defined(CPU_MK30DN512VLL10) || defined(CPU_MK30DN512VLQ10) || \
	defined(CPU_MK30DN512VMC10) || defined(CPU_MK30DN512VMD10) || defined(CPU_MK30DX128VLQ10) || \
	defined(CPU_MK30DX128VMD10) || defined(CPU_MK30DX256VLQ10) || defined(CPU_MK30DX256VMD10) || defined(MK30D10))
	#define K30D10_SERIES
	/* CMSIS-style register definitions */
	#include "MK30D10.h"
	/* CPU specific feature definitions */
	#include "MK30D10_features.h"
#elif (defined(CPU_MK40DN512VLK10) || defined(CPU_MK40DN512VLL10) || defined(CPU_MK40DN512VLQ10) || \
	defined(CPU_MK40DN512VMC10) || defined(CPU_MK40DN512VMD10) || defined(CPU_MK40DX128VLQ10) || \
	defined(CPU_MK40DX128VMD10) || defined(CPU_MK40DX256VLQ10) || defined(CPU_MK40DX256VMD10) || defined(MK40D10))
	#define K40D10_SERIES
	/* CMSIS-style register definitions */
	#include "MK40D10.h"
	/* CPU specific feature definitions */
	#include "MK40D10_features.h"
#elif (defined(CPU_MK50DN512CLL10) || defined(CPU_MK50DN512CLQ10) || defined(CPU_MK50DN512CMC10) || \
	defined(CPU_MK50DN512CMD10) || defined(CPU_MK50DX256CLK10) || defined(CPU_MK50DX256CLL10) || \
	defined(CPU_MK50DX256CMC10) || defined(CPU_MK50DX256CMD10))
	#define K50D10_SERIES
	/* CMSIS-style register definitions */
	#include "MK50D10.h"
	/* CPU specific feature definitions */
	#include "MK50D10_features.h"
#elif (defined(CPU_MK51DN256CLQ10) || defined(CPU_MK51DN256CMD10) || defined(CPU_MK51DN512CLL10) || \
	defined(CPU_MK51DN512CLQ10) || defined(CPU_MK51DN512CMC10) || defined(CPU_MK51DN512CMD10) || \
	defined(CPU_MK51DX256CLK10) || defined(CPU_MK51DX256CLL10) || defined(CPU_MK51DX256CMC10))
	#define K51D10_SERIES
	/* CMSIS-style register definitions */
	#include "MK51D10.h"
	/* CPU specific feature definitions */
	#include "MK51D10_features.h"
#elif (defined(CPU_MK52DN512CLQ10) || defined(CPU_MK52DN512CMD10))
	#define K52D10_SERIES
	/* CMSIS-style register definitions */
	#include "MK52D10.h"
	/* CPU specific feature definitions */
	#include "MK52D10_features.h"
#elif (defined(CPU_MK53DN512CLQ10) || defined(CPU_MK53DN512CMD10) || defined(CPU_MK53DX256CLQ10) || \
	defined(CPU_MK53DX256CMD10))
	#define K53D10_SERIES
	/* CMSIS-style register definitions */
	#include "MK53D10.h"
	/* CPU specific feature definitions */
	#include "MK53D10_features.h"
#elif (defined(CPU_MK60DN256VLL10) || defined(CPU_MK60DN256VLQ10) || defined(CPU_MK60DN256VMC10) || \
	defined(CPU_MK60DN256VMD10) || defined(CPU_MK60DN512VLL10) || defined(CPU_MK60DN512VLQ10) || \
	defined(CPU_MK60DN512VMC10) || defined(CPU_MK60DN512VMD10) || defined(CPU_MK60DX256VLL10) || \
	defined(CPU_MK60DX256VLQ10) || defined(CPU_MK60DX256VMC10) || defined(CPU_MK60DX256VMD10) || defined(MK60D10))
	#define K60D10_SERIES
	/* CMSIS-style register definitions */
	#include "MK60D10.h"
	/* CPU specific feature definitions */
	#include "MK60D10_features.h"
#elif (defined(CPU_MK63FN1M0VLQ12) || defined(CPU_MK63FN1M0VMD12))
	#define K63F12_SERIES
	/* CMSIS-style register definitions */
	#include "MK63F12.h"
	/* CPU specific feature definitions */
	#include "MK63F12_features.h"
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

#elif (defined(CPU_MKV10Z16VFM7) || defined(CPU_MKV10Z16VLC7) || defined(CPU_MKV10Z16VLF7) || \
	defined(CPU_MKV10Z32VFM7) || defined(CPU_MKV10Z32VLC7) || defined(CPU_MKV10Z32VLF7) || defined(MKV11Z7))
	#define KV10Z7_SERIES
	/* CMSIS-style register definitions */
	#include "MKV10Z7.h"
	/* CPU specific feature definitions */
	#include "MKV10Z7_features.h"
#if (defined(CPU_MKV10Z128VFM7) || defined(CPU_MKV10Z128VLC7) || defined(CPU_MKV10Z128VLF7) || \
	defined(CPU_MKV10Z128VLH7) || defined(CPU_MKV10Z64VFM7) || defined(CPU_MKV10Z64VLC7) || \
	defined(CPU_MKV10Z64VLF7) || defined(CPU_MKV10Z64VLH7) || defined(MKV10Z128))
	#define KV10Z1287_SERIES
	/* CMSIS-style register definitions */
	#include "MKV10Z1287.h"
	/* CPU specific feature definitions */
	#include "MKV10Z1287_features.h"
#elif (defined(CPU_MKV11Z128VFM7) || defined(CPU_MKV11Z128VLC7) || defined(CPU_MKV11Z128VLF7) || \
	defined(CPU_MKV11Z128VLH7) || defined(CPU_MKV11Z64VFM7) || defined(CPU_MKV11Z64VLC7) || \
	defined(CPU_MKV11Z64VLF7) || defined(CPU_MKV11Z64VLH7) || defined(MKV11Z7))
	#define KV11Z7_SERIES
	/* CMSIS-style register definitions */
	#include "MKV11Z7.h"
	/* CPU specific feature definitions */
	#include "MKV11Z7_features.h"
#elif (defined(CPU_MKV30F128VFM10) || defined(CPU_MKV30F128VLF10) || defined(CPU_MKV30F128VLH10) || \
	defined(CPU_MKV30F64VFM10) || defined(CPU_MKV30F64VLF10) || defined(CPU_MKV30F64VLH10) || defined(MKV30F12810)))
	#define KV30F12810_SERIES
	/* CMSIS-style register definitions */
	#include "MKV30F12810.h"
	/* CPU specific feature definitions */
	#include "MKV30F12810_features.h"
#elif (defined(CPU_MKV31F128VLH10) || defined(CPU_MKV31F128VLL10)) || defined(MKV31F12810))
	#define KV31F12810_SERIES
	/* CMSIS-style register definitions */
	#include "MKV31F12810.h"
	/* CPU specific feature definitions */
	#include "MKV31F12810_features.h"
#elif (defined(CPU_MKV31F256VLH12) || defined(CPU_MKV31F256VLL12)) || defined(MKV31F25612))
	#define KV31F25612_SERIES
	/* CMSIS-style register definitions */
	#include "MKV31F25612.h"
	/* CPU specific feature definitions */
	#include "MKV31F25612_features.h"
#elif (defined(CPU_MKV31F512VLH12) || defined(CPU_MKV31F512VLL12)) || defined(MKV31F51212))
	#define KV31F51212_SERIES
	/* CMSIS-style register definitions */
	#include "MKV31F51212.h"
	/* CPU specific feature definitions */
	#include "MKV31F51212_features.h"
#elif (defined(CPU_MKV42F128VLF16) || defined(CPU_MKV42F128VLH16) || defined(CPU_MKV42F128VLL16) || \
	defined(CPU_MKV42F256VLH16) || defined(CPU_MKV42F256VLL16) || defined(CPU_MKV42F64VLF16) || \
	defined(CPU_MKV42F64VLH16) || defined(MKV42F16))
	#define KV42F16_SERIES
	/* CMSIS-style register definitions */
	#include "MKV42F16.h"
	/* CPU specific feature definitions */
	#include "MKV42F16_features.h"
#elif (defined(CPU_MKV44F128VLF16) || defined(CPU_MKV44F128VLH16) || defined(CPU_MKV44F128VLL16) || \
	defined(CPU_MKV44F256VLH16) || defined(CPU_MKV44F256VLL16) || defined(CPU_MKV44F64VLF16) || \
	defined(CPU_MKV44F64VLH16) || defined(MKV44F16))
	#define KV44F16_SERIES
	/* CMSIS-style register definitions */
	#include "MKV44F16.h"
	/* CPU specific feature definitions */
	#include "MKV44F16_features.h"
#elif (defined(CPU_MKV46F128VLH16) || defined(CPU_MKV46F128VLL16) || defined(CPU_MKV46F256VLH16) || \
	defined(CPU_MKV46F256VLL16) || defined(MKV46F16))
	#define KV46F16_SERIES
	/* CMSIS-style register definitions */
	#include "MKV46F16.h"
	/* CPU specific feature definitions */
	#include "MKV46F16_features.h"
#if (defined(CPU_MKV56F1M0VLL24) || defined(CPU_MKV56F1M0VLQ24) || defined(CPU_MKV56F1M0VMD24) || \
	defined(CPU_MKV56F512VLL24) || defined(CPU_MKV56F512VLQ24) || defined(CPU_MKV56F512VMD24) || defined(MKV56F24))
	#define KV56F24_SERIES
	/* CMSIS-style register definitions */
	#include "MKV56F24.h"
	/* CPU specific feature definitions */
	#include "MKV56F24_features.h"
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
