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
#elif (defined(CPU_MK10DN32VLF5)  || defined(CPU_MK10DX32VLF5)  || defined(CPU_MK10DN32VFT5) || \
	   defined(CPU_MK10DX32VFT5)  || defined(CPU_MK10DN32VLH5)  || defined(CPU_MK10DX32VLH5) || \
	   defined(CPU_MK10DN64VLF5)  || defined(CPU_MK10DX64VLF5)  || defined(CPU_MK10DN64VFT5) || \
	   defined(CPU_MK10DX64VFT5)  || defined(CPU_MK10DN64VLH5)  || defined(CPU_MK10DX64VLH5) || \
	   defined(CPU_MK10DN128VLF5) || defined(CPU_MK10DX128VLF5) || defined(CPU_MK10DN128VFT5) || defined(CPU_MK10DX128VFT5) || \
	   defined(CPU_MK10DN128VLH5) || defined(CPU_MK10DX128VLH5) || defined(CPU_MK10DN32VMP5)  || defined(CPU_MK10DX32VMP5)  || \
	   defined(CPU_MK10DN64VMP5)  || defined(CPU_MK10DX64VMP5)  || defined(CPU_MK10DN128VMP5) || defined(CPU_MK10DX128VMP5) || \
	   defined(CPU_MK10DN32VFM5)  || defined(CPU_MK10DX32VFM5)  || defined(CPU_MK10DN64VFM5)  || \
	   defined(CPU_MK10DX64VFM5)  || defined(CPU_MK10DN128VFM5) || defined(CPU_MK10DX128VFM5))
	#define K10D5_SERIES
	/* CMSIS-style register definitions */
	#include "MK10D5.h"
	/* CPU specific feature definitions */
	//#include "MK10D5_features.h" // not supported by this device family
#elif (defined(CPU_MK10DX64VLK7) || defined(CPU_MK10DX128VLK7) || defined(CPU_MK10DX256VLK7) || defined(CPU_MK10DX128VLL7) || \
	  defined(CPU_MK10DX256VLL7) || defined(CPU_MK10DX64VMC7)  || defined(CPU_MK10DX128VMC7) || defined(CPU_MK10DX256VMC7) || \
	  defined(CPU_MK10DX64VLH7)  || defined(CPU_MK10DX128VLH7) || defined(CPU_MK10DX256VLH7))
	#define K10D7_SERIES
	/* CMSIS-style register definitions */
	#include "MK10D7.h"
	/* CPU specific feature definitions */
	//#include "MK10D7_features.h" // not supported by this device family
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
	defined(CPU_MK60DX256VLQ10) || defined(CPU_MK60DX256VMC10) || defined(CPU_MK60DX256VMD10))
	#define K60D10_SERIES
	/* CMSIS-style register definitions */
	#include "MK60D10.h"
	/* CPU specific feature definitions */
	#include "MK60D10_features.h"
#elif (defined(CPU_MK60DN512ZVLL10) || defined(CPU_MK60DX256ZVLL10) || defined(CPU_MK60DN256ZVLL10) || \
	   defined(CPU_MK60DN512ZVLQ10) || defined(CPU_MK60DN256ZVLQ10) || defined(CPU_MK60DX256ZVLQ10) || \
	   defined(CPU_MK60DN512ZVMC10) || defined(CPU_MK60DN256ZVMC10) || defined(CPU_MK60DX256ZVMC10) || \
	   defined(CPU_MK60DN512ZVMD10) || defined(CPU_MK60DX256ZVMD10) || defined(CPU_MK60DN256ZVMD10))
	#define K60DZ10_SERIES
	/* CMSIS-style register definitions */
	#include "MK60DZ10.h"
	/* CPU specific feature definitions */
//	#include "MK60DZ10_features.h" // Not available for this device
#elif (defined(CPU_MK60FX512VLQ12) || defined(CPU_MK60FN1M0VLQ12) || defined(CPU_MK60FX512VMD12) || defined(CPU_MK60FN1M0VMD12))
	#define K60F12_SERIES
	/* CMSIS-style register definitions */
	#include "MK60F12.h"
	/* CPU specific feature definitions */
//	#include "MK60F12_features.h" // Not available for this device
#elif (defined(CPU_MK60FX512VLQ15) || defined(CPU_MK60FN1M0VLQ15) || defined(CPU_MK60FX512VMD15) || defined(CPU_MK60FN1M0VMD15))
	#define K60F15_SERIES
	/* CMSIS-style register definitions */
	#include "MK60F15.h"
	/* CPU specific feature definitions */
//	#include "MK60F15_features.h" // Not available for this device
#elif (defined(CPU_MK61FX512VMJ12) || defined(CPU_MK61FN1M0VMJ12) || defined(CPU_MK61FN1M0CAA12) || \
	   defined(CPU_MK61FX512VMD12) || defined(CPU_MK61FN1M0VMD12))
	#define K61F12_SERIES
	/* CMSIS-style register definitions */
	#include "MK61F12.h"
	/* CPU specific feature definitions */
//	#include "MK61F12_features.h" // Not available for this device
#elif (defined(CPU_MK61FX512VMJ15) || defined(CPU_MK61FN1M0VMJ15) || defined(CPU_MK61FX512VMD15) || defined(CPU_MK61FN1M0VMD15))
	#define K61F15_SERIES
	/* CMSIS-style register definitions */
	#include "MK61F15.h"
	/* CPU specific feature definitions */
//	#include "MK61F15_features.h" // Not available for this device
#elif (defined(CPU_MK63FN1M0VLQ12) || defined(CPU_MK63FN1M0VMD12))
	#define K63F12_SERIES
	/* CMSIS-style register definitions */
	#include "MK63F12.h"
	/* CPU specific feature definitions */
	#include "MK63F12_features.h"
#elif (defined(CPU_MK64FN1M0CAJ12) || defined(CPU_MK64FN1M0VDC12) || defined(CPU_MK64FN1M0VLL12) || \
	defined(CPU_MK64FN1M0VLQ12) || defined(CPU_MK64FN1M0VMD12) || defined(CPU_MK64FX512VDC12) || \
	defined(CPU_MK64FX512VLL12) || defined(CPU_MK64FX512VLQ12) || defined(CPU_MK64FX512VMD12))
	#define K64F12_SERIES
	/* CMSIS-style register definitions */
	#include "MK64F12.h"
	/* CPU specific feature definitions */
	#include "MK64F12_features.h"
#elif (defined(CPU_MK65FN2M0CAC18) || defined(CPU_MK65FX1M0CAC18) || defined(CPU_MK65FN2M0VMI18) || defined(CPU_MK65FX1M0VMI18))
	#define K65F18_SERIES
	/* CMSIS-style register definitions */
	#include "MK65F18.h"
	/* CPU specific feature definitions */
	#include "MK65F18_features.h"
#elif (defined(CPU_MK66FN2M0VLQ18) || defined(CPU_MK66FN2M0VMD18) || defined(CPU_MK66FX1M0VLQ18) || defined(CPU_MK66FX1M0VMD18))
	#define K66F18_SERIES
	/* CMSIS-style register definitions */
	#include "MK66F18.h"
	/* CPU specific feature definitions */
	#include "MK66F18_features.h"
#elif (defined(CPU_MK70FX512VMJ12) || defined(CPU_MK70FN1M0VMJ12))
	#define K70F12_SERIES
	/* CMSIS-style register definitions */
	#include "MK70F12.h"
	/* CPU specific feature definitions */
//	#include "MK70F12_features.h" // Not available for this device
#elif (defined(CPU_MK70FX512VMJ15) || defined(CPU_MK70FN1M0VMJ15)
	#define K70F15_SERIES
	/* CMSIS-style register definitions */
	#include "MK70F15.h"
	/* CPU specific feature definitions */
//	#include "MK70F15_features.h" // Not available for this device
#elif (defined(CPU_MK80FN256CAx15) || defined(CPU_MK80FN256VDC15) || defined(CPU_MK80FN256VLL15) || defined(CPU_MK80FN256VLQ15))
	#define K80F25615_SERIES
	/* CMSIS-style register definitions */
	#include "MK80F25615.h"
	/* CPU specific feature definitions */
	#include "MK80F25615_features.h"
#elif (defined(CPU_MK82FN256CAx15) || defined(CPU_MK82FN256VDC15) || defined(CPU_MK82FN256VLL15) || defined(CPU_MK82FN256VLQ15))
	#define K82F25615_SERIES
	/* CMSIS-style register definitions */
	#include "MK82F25615.h"
	/* CPU specific feature definitions */
	#include "MK82F25615_features.h"

#elif (defined(CPU_MKE02Z16VFM4) || defined(CPU_MKE02Z16VLC4) || defined(CPU_MKE02Z16VLD4) || \
	defined(CPU_MKE02Z32VFM4) || defined(CPU_MKE02Z32VLC4) || defined(CPU_MKE02Z32VLD4) || \
	defined(CPU_MKE02Z32VLH4) || defined(CPU_MKE02Z32VQH4) || defined(CPU_MKE02Z64VFM4) || \
	defined(CPU_MKE02Z64VLC4) || defined(CPU_MKE02Z64VLD4) || defined(CPU_MKE02Z64VLH4) || \
	defined(CPU_MKE02Z64VQH4) || defined(MKE02Z4))
	#define KE02Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKE02Z4.h"
	/* CPU specific feature definitions */
	#include "MKE02Z4_features.h"
#elif (defined(CPU_MKE04Z8VFK4) || defined(CPU_MKE04Z8VTG4) || defined(CPU_MKE04Z8VWJ4) || defined(MKE04Z4))
	#define KE04Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKE04Z4.h"
	/* CPU specific feature definitions */
	#include "MKE04Z4_features.h"
#elif (defined(CPU_MKE04Z128VLD4) || defined(CPU_MKE04Z128VLH4) || defined(CPU_MKE04Z128VLK4) || \
	defined(CPU_MKE04Z128VQH4) || defined(CPU_MKE04Z64VLD4) || defined(CPU_MKE04Z64VLH4) || \
	defined(CPU_MKE04Z64VLK4) || defined(CPU_MKE04Z64VQH4) || defined(MKE04Z1284))
	#define KE04Z1284_SERIES
	/* CMSIS-style register definitions */
	#include "MKE04Z1284.h"
	/* CPU specific feature definitions */
	#include "MKE04Z1284_features.h"
#elif (defined(CPU_MKE06Z128VLD4) || defined(CPU_MKE06Z128VLH4) || defined(CPU_MKE06Z128VLK4) || \
	defined(CPU_MKE06Z128VQH4) || defined(CPU_MKE06Z64VLD4) || defined(CPU_MKE06Z64VLH4) || \
	defined(CPU_MKE06Z64VLK4) || defined(CPU_MKE06Z64VQH4) || defined(MKE06Z4))
	#define KE06Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKE06Z4.h"
	/* CPU specific feature definitions */
	#include "MKE06Z4_features.h"
#elif (defined(CPU_MKE14F256VLH16) || defined(CPU_MKE14F256VLL16) || defined(CPU_MKE14F512VLH16) || \
	defined(CPU_MKE14F512VLL16) || defined(MKE14F16))
	#define KE14F16_SERIES
	/* CMSIS-style register definitions */
	#include "MKE14F16.h"
	/* CPU specific feature definitions */
	#include "MKE14F16_features.h"
#elif (defined(CPU_MKE14Z32VLD4) || defined(CPU_MKE14Z32VLF4) || defined(CPU_MKE14Z64VLD4) || \
	defined(CPU_MKE14Z64VLF4) || defined(MKE14Z4))
	#define KE14Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKE14Z4.h"
	/* CPU specific feature definitions */
	#include "MKE14Z4_features.h"
#elif (defined(CPU_MKE14Z128VLH7) || defined(CPU_MKE14Z128VLL7) || defined(CPU_MKE14Z256VLH7) || \
	defined(CPU_MKE14Z256VLL7) || defined(MKE14Z7))
	#define KE14Z7_SERIES
	/* CMSIS-style register definitions */
	#include "MKE14Z7.h"
	/* CPU specific feature definitions */
	#include "MKE14Z7_features.h"
#elif (defined(CPU_MKE15Z32VLD4) || defined(CPU_MKE15Z32VLF4) || defined(CPU_MKE15Z64VLD4) || \
	defined(CPU_MKE15Z64VLF4) || defined(MKE15Z4))
	#define KE15Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKE15Z4.h"
	/* CPU specific feature definitions */
	#include "MKE15Z4_features.h"
#elif (defined(CPU_MKE15Z128VLH7) || defined(CPU_MKE15Z128VLL7) || defined(CPU_MKE15Z256VLH7) || \
	defined(CPU_MKE15Z256VLL7) || defined(MKE15Z7))
	#define KE15Z7_SERIES
	/* CMSIS-style register definitions */
	#include "MKE15Z7.h"
	/* CPU specific feature definitions */
	#include "MKE15Z7_features.h"
#elif (defined(CPU_MKE16F256VLH16) || defined(CPU_MKE16F256VLL16) || defined(CPU_MKE16F512VLH16) || \
	defined(CPU_MKE16F512VLL16) || defined(MKE16F16))
	#define KE16F16_SERIES
	/* CMSIS-style register definitions */
	#include "MKE16F16.h"
	/* CPU specific feature definitions */
	#include "MKE16F16_features.h"
#elif (defined(CPU_MKE16Z32VLD4) || defined(CPU_MKE16Z32VLF4) || defined(CPU_MKE16Z64VLD4) || \
	defined(CPU_MKE16Z64VLF4) || defined(MKE16Z4))
	#define KE16Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKE16Z4.h"
	/* CPU specific feature definitions */
	#include "MKE16Z4_features.h"
#elif (defined(CPU_MKE18F256VLH16) || defined(CPU_MKE18F256VLL16) || defined(CPU_MKE18F512VLH16) || \
	defined(CPU_MKE18F512VLL16) || defined(MKE18F16))
	#define KE18F16_SERIES
	/* CMSIS-style register definitions */
	#include "MKE18F16.h"
	/* CPU specific feature definitions */
	#include "MKE18F16_features.h"

#elif (defined(CPU_MKL02Z16VFG4) || defined(CPU_MKL02Z16VFK4) || defined(CPU_MKL02Z16VFM4) || \
	defined(CPU_MKL02Z32CAF4) || defined(CPU_MKL02Z32VFG4) || defined(CPU_MKL02Z32VFK4) || \
	defined(CPU_MKL02Z32VFM4) || defined(CPU_MKL02Z8VFG4))
	#define KL02Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL02Z4.h"
	/* CPU specific feature definitions */
	#include "MKL02Z4_features.h"
#elif (defined(CPU_MKL03Z16VFG4) || defined(CPU_MKL03Z16VFK4) || defined(CPU_MKL03Z32CAF4) || \
	defined(CPU_MKL03Z32VFG4) || defined(CPU_MKL03Z32VFK4) || defined(CPU_MKL03Z8VFG4) || \
	defined(CPU_MKL03Z8VFK4))
	#define KL03Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL03Z4.h"
	/* CPU specific feature definitions */
	#include "MKL03Z4_features.h"
#elif (defined(CPU_MKL04Z8VFK4) || defined(CPU_MKL04Z8VLC4) || defined(CPU_MKL04Z8VFM4) || \
	defined(CPU_MKL04Z16VFK4) || defined(CPU_MKL04Z16VLC4) || defined(CPU_MKL04Z16VFM4) || defined(CPU_MKL04Z16VLF4) || \
	defined(CPU_MKL04Z32VFK4) || defined(CPU_MKL04Z32VLC4) || defined(CPU_MKL04Z32VFM4) || defined(CPU_MKL04Z32VLF4))
	#define KL04Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL04Z4.h"
	/* CPU specific feature definitions */
//	#include "MKL04Z4_features.h"
#elif (defined(CPU_MKL05Z8VFK4) || defined(CPU_MKL05Z8VLC4) || defined(CPU_MKL05Z8VFM4) || \
	defined(CPU_MKL05Z16VFK4) || defined(CPU_MKL05Z16VLC4) || defined(CPU_MKL05Z16VFM4) || defined(CPU_MKL05Z16VLF4) || \
	defined(CPU_MKL05Z32VFK4) || defined(CPU_MKL05Z32VLC4) || defined(CPU_MKL05Z32VFM4) || defined(CPU_MKL05Z32VLF4))
	#define KL05Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL05Z5.h"
	/* CPU specific feature definitions */
//	#include "MKL05Z5_features.h"
#elif (defined(CPU_MKL13Z32VFM4) || defined(CPU_MKL13Z32VFT4) || defined(CPU_MKL13Z32VLH4) || \
	defined(CPU_MKL13Z32VLK4) || defined(CPU_MKL13Z32VMP4) || defined(CPU_MKL13Z64VFM4) || \
	defined(CPU_MKL13Z64VFT4) || defined(CPU_MKL13Z64VLH4) || defined(CPU_MKL13Z64VLK4) || \
	defined(CPU_MKL13Z64VMP4))
	#define KL13Z644_SERIES
	/* CMSIS-style register definitions */
	#include "MKL13Z644.h"
	/* CPU specific feature definitions */
	#include "MKL13Z644_features.h"
#elif (defined(CPU_MKL14Z32VFM4) || defined(CPU_MKL14Z32VFT4) || defined(CPU_MKL14Z32VLH4) || \
	defined(CPU_MKL14Z32VLK4) || defined(CPU_MKL14Z64VFM4) || defined(CPU_MKL14Z64VFT4) || \
	defined(CPU_MKL14Z64VLH4) || defined(CPU_MKL14Z64VLK4) || defined(MKL14Z4))
	#define KL14Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL14Z4.h"
	/* CPU specific feature definitions */
	#include "MKL14Z4_features.h"
#elif (defined(CPU_MKL15Z128CAD4) || defined(CPU_MKL15Z128VFM4) || defined(CPU_MKL15Z128VFT4) || \
	defined(CPU_MKL15Z128VLH4) || defined(CPU_MKL15Z128VLK4) || defined(CPU_MKL15Z32VFM4) || \
	defined(CPU_MKL15Z32VFT4) || defined(CPU_MKL15Z32VLH4) || defined(CPU_MKL15Z32VLK4) || \
	defined(CPU_MKL15Z64VFM4) || defined(CPU_MKL15Z64VFT4) || defined(CPU_MKL15Z64VLH4) || \
	defined(CPU_MKL15Z64VLK4))
	#define KL15Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL15Z4.h"
	/* CPU specific feature definitions */
	#include "MKL15Z4_features.h"
#elif (defined(CPU_MKL16Z128VFM4) || defined(CPU_MKL16Z128VFT4) || defined(CPU_MKL16Z128VLH4) || \
	defined(CPU_MKL16Z256VLH4) || defined(CPU_MKL16Z256VMP4) || defined(CPU_MKL16Z32VFM4) || \
	defined(CPU_MKL16Z32VFT4) || defined(CPU_MKL16Z32VLH4) || defined(CPU_MKL16Z64VFM4) || \
	defined(CPU_MKL16Z64VFT4) || defined(CPU_MKL16Z64VLH4))
	#define KL16Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL16Z4.h"
	/* CPU specific feature definitions */
	#include "MKL16Z4_features.h"
#elif (defined(CPU_MKL17Z128VFM4) || defined(CPU_MKL17Z128VFT4) || defined(CPU_MKL17Z128VLH4) || \
	defined(CPU_MKL17Z128VMP4) || defined(CPU_MKL17Z256VFM4) || defined(CPU_MKL17Z256VFT4) || \
	defined(CPU_MKL17Z256VLH4) || defined(CPU_MKL17Z256VMP4))
	#define KL17Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL17Z4.h"
	/* CPU specific feature definitions */
	#include "MKL17Z4_features.h"
#elif (defined(CPU_MKL17Z32VDA4) || defined(CPU_MKL17Z32VFM4) || defined(CPU_MKL17Z32VFT4) || \
	defined(CPU_MKL17Z32VLH4) || defined(CPU_MKL17Z32VMP4) || defined(CPU_MKL17Z64VDA4) || \
	defined(CPU_MKL17Z64VFM4) || defined(CPU_MKL17Z64VFT4) || defined(CPU_MKL17Z64VLH4) || \
	defined(CPU_MKL17Z64VMP4))
	#define KL17Z644_SERIES
	/* CMSIS-style register definitions */
	#include "MKL17Z644.h"
	/* CPU specific feature definitions */
	#include "MKL17Z644_features.h"
#elif (defined(CPU_MKL24Z32VFM4) || defined(CPU_MKL24Z32VFT4) || defined(CPU_MKL24Z32VLH4) || \
	defined(CPU_MKL24Z32VLK4) || defined(CPU_MKL24Z64VFM4) || defined(CPU_MKL24Z64VFT4) || \
	defined(CPU_MKL24Z64VLH4) || defined(CPU_MKL24Z64VLK4) || defined(MKL24Z4))
	#define KL24Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL24Z4.h"
	/* CPU specific feature definitions */
	#include "MKL24Z4_features.h"
#elif (defined(CPU_MKL25Z128VFM4) || defined(CPU_MKL25Z128VFT4) || defined(CPU_MKL25Z128VLH4) || \
	defined(CPU_MKL25Z128VLK4) || defined(CPU_MKL25Z32VFM4) || defined(CPU_MKL25Z32VFT4) || \
	defined(CPU_MKL25Z32VLH4) || defined(CPU_MKL25Z32VLK4) || defined(CPU_MKL25Z64VFM4) || \
	defined(CPU_MKL25Z64VFT4) || defined(CPU_MKL25Z64VLH4) || defined(CPU_MKL25Z64VLK4) || defined(MKL25Z4))
	#define KL25Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL25Z4.h"
	/* CPU specific feature definitions */
	#include "MKL25Z4_features.h"
#elif (defined(CPU_MKL26Z128CAL4) || defined(CPU_MKL26Z128VFM4) || defined(CPU_MKL26Z128VFT4) || \
	defined(CPU_MKL26Z128VLH4) || defined(CPU_MKL26Z128VLL4) || defined(CPU_MKL26Z128VMC4) || \
	defined(CPU_MKL26Z256VLH4) || defined(CPU_MKL26Z256VLL4) || defined(CPU_MKL26Z256VMC4) || \
	defined(CPU_MKL26Z256VMP4) || defined(CPU_MKL26Z32VFM4) || defined(CPU_MKL26Z32VFT4) || \
	defined(CPU_MKL26Z32VLH4) || defined(CPU_MKL26Z64VFM4) || defined(CPU_MKL26Z64VFT4) || \
	defined(CPU_MKL26Z64VLH4) || defined(MKL26Z4))
	#define KL26Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL26Z4.h"
	/* CPU specific feature definitions */
	#include "MKL26Z4_features.h"
#elif (defined(CPU_MKL27Z32VDA4) || defined(CPU_MKL27Z32VFM4) || defined(CPU_MKL27Z32VFT4) || \
	defined(CPU_MKL27Z32VLH4) || defined(CPU_MKL27Z32VMP4) || defined(CPU_MKL27Z64VDA4) || \
	defined(CPU_MKL27Z64VFM4) || defined(CPU_MKL27Z64VFT4) || defined(CPU_MKL27Z64VLH4) || \
	defined(CPU_MKL27Z64VMP4) || defined(MKL27Z644))
	#define KL27Z644_SERIES
	/* CMSIS-style register definitions */
	#include "MKL27Z644.h"
	/* CPU specific feature definitions */
	#include "MKL27Z644_features.h"
#elif (defined(CPU_MKL27Z128VFM4) || defined(CPU_MKL27Z128VFT4) || defined(CPU_MKL27Z128VLH4) || \
	defined(CPU_MKL27Z128VMP4) || defined(CPU_MKL27Z256VFM4) || defined(CPU_MKL27Z256VFT4) || \
	defined(CPU_MKL27Z256VLH4) || defined(CPU_MKL27Z256VMP4) || defined(MKL27Z4))
	#define KL27Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL27Z4.h"
	/* CPU specific feature definitions */
	#include "MKL27Z4_features.h"
#elif (defined(CPU_MKL28Z512VDC7) || defined(CPU_MKL28Z512VLL7) || defined(MKL28Z7))
	#define KL28Z7_SERIES
	/* CMSIS-style register definitions */
	#include "MKL28Z7.h"
	/* CPU specific feature definitions */
	#include "MKL28Z7_features.h"
#elif (defined(CPU_MKL33Z128VLH4) || defined(CPU_MKL33Z128VMP4) || defined(CPU_MKL33Z256VLH4) || \
	defined(CPU_MKL33Z256VMP4) || defined(MKL33Z4))
	#define KL33Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL33Z4.h"
	/* CPU specific feature definitions */
	#include "MKL33Z4_features.h"
#elif (defined(CPU_MKL33Z32VFT4) || defined(CPU_MKL33Z32VLH4) || defined(CPU_MKL33Z32VLK4) || \
	defined(CPU_MKL33Z32VMP4) || defined(CPU_MKL33Z64VFT4) || defined(CPU_MKL33Z64VLH4) || \
	defined(CPU_MKL33Z64VLK4) || defined(CPU_MKL33Z64VMP4) || defined(MKL33Z644))
	#define KL33Z644_SERIES
	/* CMSIS-style register definitions */
	#include "MKL33Z644.h"
	/* CPU specific feature definitions */
	#include "MKL33Z644_features.h"
#elif (defined(CPU_MKL34Z64VLH4) || defined(CPU_MKL34Z64VLL4) || defined(MKL34Z4))
	#define KL34Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL34Z4.h"
	/* CPU specific feature definitions */
	#include "MKL34Z4_features.h"
#elif (defined(CPU_MKL36Z128VLH4) || defined(CPU_MKL36Z128VLL4) || defined(CPU_MKL36Z128VMC4) || \
	defined(CPU_MKL36Z256VLH4) || defined(CPU_MKL36Z256VLL4) || defined(CPU_MKL36Z256VMC4) || \
	defined(CPU_MKL36Z256VMP4) || defined(CPU_MKL36Z64VLH4) || defined(CPU_MKL36Z64VLL4) || defined(MKL36Z4))
	#define KL36Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL36Z4.h"
	/* CPU specific feature definitions */
	#include "MKL36Z4_features.h"
#elif (defined(CPU_MKL43Z128VLH4) || defined(CPU_MKL43Z128VMP4) || defined(CPU_MKL43Z256VLH4) || \
	defined(CPU_MKL43Z256VMP4) || defined(MKL43Z4))
	#define KL43Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL43Z4.h"
	/* CPU specific feature definitions */
	#include "MKL43Z4_features.h"
#elif (defined(CPU_MKL46Z128VLH4) || defined(CPU_MKL46Z128VLL4) || defined(CPU_MKL46Z128VMC4) || \
	defined(CPU_MKL46Z256VLH4) || defined(CPU_MKL46Z256VLL4) || defined(CPU_MKL46Z256VMC4) || \
	defined(CPU_MKL46Z256VMP4) || defined(MKL46Z4))
	#define KL46Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKL46Z4.h"
	/* CPU specific feature definitions */
	#include "MKL46Z4_features.h"
#elif (defined(CPU_MKL81Z128VLH7) || defined(CPU_MKL81Z128VLK7) || defined(CPU_MKL81Z128VLL7) || \
	defined(CPU_MKL81Z128VMC7) || defined(CPU_MKL81Z128VMP7) || defined(MKL81Z7))
	#define KL81Z7_SERIES
	/* CMSIS-style register definitions */
	#include "MKL81Z7.h"
	/* CPU specific feature definitions */
	#include "MKL81Z7_features.h"
#elif (defined(CPU_MKL82Z128VLH7) || defined(CPU_MKL82Z128VLK7) || defined(CPU_MKL82Z128VLL7) || \
	defined(CPU_MKL82Z128VMC7) || defined(CPU_MKL82Z128VMP7) || defined(MKL82Z7))
	#define KL82Z7_SERIES
	/* CMSIS-style register definitions */
	#include "MKL82Z7.h"
	/* CPU specific feature definitions */
	#include "MKL82Z7_features.h"

#elif (defined(CPU_MKM34Z256VLL7) || defined(CPU_MKM34Z256VLQ7))
	#define KM34Z7_SERIES
	/* CMSIS-style register definitions */
	#include "MKM34Z7.h"
	/* CPU specific feature definitions */
	#include "MKM34Z7_features.h"
#elif (defined(CPU_MKM35Z256VLL7) || defined(CPU_MKM35Z256VLL7R) || defined(CPU_MKM35Z256VLQ7) || \
	defined(CPU_MKM35Z256VLQ7R) || defined(CPU_MKM35Z512VLL7) || defined(CPU_MKM35Z512VLL7R) || \
	defined(CPU_MKM35Z512VLQ7) || defined(CPU_MKM35Z512VLQ7R))
	#define KM35Z7_SERIES
	/* CMSIS-style register definitions */
	#include "MKM35Z7.h"
	/* CPU specific feature definitions */
	#include "MKM35Z7_features.h"
#elif (defined(CPU_MKS20FN128VFT12) || defined(CPU_MKS20FN128VLH12) || defined(CPU_MKS20FN128VLL12) || \
	defined(CPU_MKS20FN256VFT12) || defined(CPU_MKS20FN256VLH12) || defined(CPU_MKS20FN256VLL12))
	#define KS20F12_SERIES
	/* CMSIS-style register definitions */
	#include "MKS20F12.h"
	/* CPU specific feature definitions */
	#include "MKS20F12_features.h"
#elif (defined(CPU_MKS22FN128VFT12) || defined(CPU_MKS22FN128VLH12) || defined(CPU_MKS22FN128VLL12) || \
	defined(CPU_MKS22FN256VFT12) || defined(CPU_MKS22FN256VLH12) || defined(CPU_MKS22FN256VLL12))
	#define KS22F12_SERIES
	/* CMSIS-style register definitions */
	#include "MKS22F12.h"
	/* CPU specific feature definitions */
	#include "MKS22F12_features.h"
#elif (defined(CPU_MKV10Z16VFM7) || defined(CPU_MKV10Z16VLC7) || defined(CPU_MKV10Z16VLF7) || \
	defined(CPU_MKV10Z32VFM7) || defined(CPU_MKV10Z32VLC7) || defined(CPU_MKV10Z32VLF7) || defined(MKV11Z7))
	#define KV10Z7_SERIES
	/* CMSIS-style register definitions */
	#include "MKV10Z7.h"
	/* CPU specific feature definitions */
	#include "MKV10Z7_features.h"
#elif (defined(CPU_MKV10Z128VFM7) || defined(CPU_MKV10Z128VLC7) || defined(CPU_MKV10Z128VLF7) || \
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
	defined(CPU_MKV30F64VFM10) || defined(CPU_MKV30F64VLF10) || defined(CPU_MKV30F64VLH10) || defined(MKV30F12810))
	#define KV30F12810_SERIES
	/* CMSIS-style register definitions */
	#include "MKV30F12810.h"
	/* CPU specific feature definitions */
	#include "MKV30F12810_features.h"
#elif (defined(CPU_MKV31F128VLH10) || defined(CPU_MKV31F128VLL10) || defined(MKV31F12810))
	#define KV31F12810_SERIES
	/* CMSIS-style register definitions */
	#include "MKV31F12810.h"
	/* CPU specific feature definitions */
	#include "MKV31F12810_features.h"
#elif (defined(CPU_MKV31F256VLH12) || defined(CPU_MKV31F256VLL12) || defined(MKV31F25612))
	#define KV31F25612_SERIES
	/* CMSIS-style register definitions */
	#include "MKV31F25612.h"
	/* CPU specific feature definitions */
	#include "MKV31F25612_features.h"
#elif (defined(CPU_MKV31F512VLH12) || defined(CPU_MKV31F512VLL12) || defined(MKV31F51212))
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
#elif (defined(CPU_MKV56F1M0VLL24) || defined(CPU_MKV56F1M0VLQ24) || defined(CPU_MKV56F1M0VMD24) || \
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

#elif (defined(CPU_MKW21D256VHA5) || defined(CPU_MKW21D512VHA5) || defined(MKW21D5))
	#define KW21D5_SERIES
	/* CMSIS-style register definitions */
	#include "MKW21D5.h"
	/* CPU specific feature definitions */
	#include "MKW21D5_features.h"
#elif (defined(CPU_MKW21Z256VHT4) || defined(CPU_MKW21Z512VHT4) || defined (MKW21Z4))
	#define KW21Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKW21Z4.h"
	/* CPU specific feature definitions */
	#include "MKW21Z4_features.h"
#elif (defined(CPU_MKW22D512VHA5) || defined(MKW22D5))
	#define KW22D5_SERIES
	/* CMSIS-style register definitions */
	#include "MKW22D5.h"
	/* CPU specific feature definitions */
	#include "MKW22D5_features.h"
#elif (defined(CPU_MKW24D512VHA5) || defined(MKW24D5))
	#define KW24D5_SERIES
	/* CMSIS-style register definitions */
	#include "MKW24D5.h"
	/* CPU specific feature definitions */
	#include "MKW24D5_features.h"
#elif (defined(CPU_MKW31Z256VHT4) || defined(CPU_MKW31Z512CAT4) || defined(CPU_MKW31Z512VHT4) || defined(MKW31Z4))
	#define KW31Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKW31Z4.h"
	/* CPU specific feature definitions */
	#include "MKW31Z4_features.h"
#elif (defined(CPU_MKW34A512VFT4))
	#define KW34A4_SERIES
	/* CMSIS-style register definitions */
	#include "MKW34A4.h"
	/* CPU specific feature definitions */
	#include "MKW34A4_features.h"
#elif (defined(CPU_MKW35A512VFP4) || defined(CPU_MKW35A512VFT4) || defined(MKW35A4))
	#define KW35A4_SERIES
	/* CMSIS-style register definitions */
	#include "MKW35A4.h"
	/* CPU specific feature definitions */
	#include "MKW35A4_features.h"
#elif (defined(CPU_MKW35Z512VHT4) || defined(MKW35Z4))
	#define KW35Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKW35Z4.h"
	/* CPU specific feature definitions */
	#include "MKW35Z4_features.h"
#elif (defined(CPU_MKW36A512VFP4) || defined(CPU_MKW36A512VFT4) || defined(CPU_MKW36A512VHT4) || defined(MKW36A4))
	#define KW36A4_SERIES
	/* CMSIS-style register definitions */
	#include "MKW36A4.h"
	/* CPU specific feature definitions */
	#include "MKW36A4_features.h"
#elif (defined(CPU_MKW36Z512VFP4) || defined(CPU_MKW36Z512VHT4) || defined(MKW36Z4))
	#define KW36Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKW36Z4.h"
	/* CPU specific feature definitions */
	#include "MKW36Z4_features.h"
#elif (defined(CPU_MKW37A512VFT4))
	#define KW37A4_SERIES
	/* CMSIS-style register definitions */
	#include "MKW37A4.h"
	/* CPU specific feature definitions */
	#include "MKW37A4_features.h"
#elif (defined(CPU_MKW37Z512VFT4))
	#define KW37Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKW37Z4.h"
	/* CPU specific feature definitions */
	#include "MKW37Z4_features.h"
#elif (defined(CPU_MKW38A512VFT4))
	#define KW38A4_SERIES
	/* CMSIS-style register definitions */
	#include "MKW38A4.h"
	/* CPU specific feature definitions */
	#include "MKW38A4_features.h"
#elif (defined(CPU_MKW38Z512VFT4))
	#define KW38Z4_SERIES
	/* CMSIS-style register definitions */
	#include "MKW38Z4.h"
	/* CPU specific feature definitions */
	#include "MKW38Z4_features.h"
#elif (defined(CPU_MKW39A512VFT4))
	#define KW39A4_SERIES
	/* CMSIS-style register definitions */
	#include "MKW39A4.h"
	/* CPU specific feature definitions */
	#include "MKW39A4_features.h"
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
