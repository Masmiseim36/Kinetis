// Copyright (c) 2010, 2011, 2012, 2013 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#ifndef __Kinetis_H__
#define __Kinetis_H__

#define MK10DN32xxx5 1
#define MK10DX32xxx5 2
#define MK10DN64xxx5 3
#define MK10DX64xxx5 4
#define MK10DN128xxx5 5
#define MK10DX128xxx5 6
#define MK10DX64xxx7 7
#define MK10DX128xxx7 8
#define MK10DX256xxx7 9
#define MK10DX128Zxxx10 10
#define MK10DX256Zxxx10 11
#define MK10DN512Zxxx10 12
#define MK10DX128xxx10 13
#define MK10DX256xxx10 14
#define MK10DN512xxx10 15
#define MK10FX512xxx12 16
#define MK10FN1M0xxx12 17
#define MK11DX128xxx5 18
#define MK11DX256xxx5 19
#define MK11DN512xxx5 20
#define MK12DX128xxx5 21
#define MK12DX256xxx5 22
#define MK12DN512xxx5 23
#define MK20DN32xxx5 24
#define MK20DX32xxx5 25
#define MK20DN64xxx5 26
#define MK20DX64xxx5 27
#define MK20DN128xxx5 28
#define MK20DX128xxx5 29
#define MK20DX64xxx7 30
#define MK20DX128xxx7 31
#define MK20DX256xxx7 32
#define MK20DX128Zxxx10 33
#define MK20DX256Zxxx10 34
#define MK20DN512Zxxx10 35
#define MK20DX128xxx10 36
#define MK20DX256xxx10 37
#define MK20DN512xxx10 38
#define MK21DX128xxx5 39
#define MK21DX256xxx5 40
#define MK21DN512xxx5 41
#define MK22DX128xxx5 42
#define MK22DX256xxx5 43
#define MK22DN512xxx5 44
#define MK30DX64xxx7 45
#define MK30DX128xxx7 46
#define MK30DX256xxx7 47
#define MK30DX128Zxxx10 48
#define MK30DX256Zxxx10 49
#define MK30DN512Zxxx10 50
#define MK30DX128xxx10 51
#define MK30DX256xxx10 52
#define MK30DN512xxx10 53
#define MK40DX64xxx7 54
#define MK40DX128xxx7 55
#define MK40DX256xxx7 56
#define MK40DX128Zxxx10 57
#define MK40DX256Zxxx10 58
#define MK40DN512Zxxx10 59
#define MK40DX128xxx10 60
#define MK40DX256xxx10 61
#define MK40DN512xxx10 62
#define MK50DX128xxx7 63
#define MK50DX256xxx7 64
#define MK50DX256xxx10 65
#define MK50DN512xxx10 66
#define MK50DX256Zxxx10 67
#define MK50DN512Zxxx10 68
#define MK51DX128xxx7 69
#define MK51DX256xxx7 70
#define MK51DX256xxx10 71
#define MK51DN512xxx10 72
#define MK51DX256Zxxx10 73
#define MK51DN512Zxxx10 74
#define MK52DN512xxx10 75
#define MK52DN512Zxxx10 76
#define MK53DX256xxx10 77
#define MK53DN512xxx10 78
#define MK53DX256Zxxx10 79
#define MK53DN512Zxxx10 80
#define MK60DN256xxx10 81
#define MK60DX256xxx10 82
#define MK60DN512xxx10 83
#define MK60DN256Zxxx10 84
#define MK60DX256Zxxx10 85
#define MK60DN512Zxxx10 86
#define MK60FX512xxx12 87
#define MK60FN1M0xxx12 88
#define MK60FX512xxx15 89
#define MK60FN1M0xxx15 90
#define MK61FX512xxx12 91
#define MK61FN1M0xxx12 92
#define MK61FX512xxx15 93
#define MK61FN1M0xxx15 94
#define MK70FX512xxx12 95
#define MK70FN1M0xxx12 96
#define MK70FX512xxx15 97
#define MK70FN1M0xxx15 98
#define MKE02Z16Vxx2 99
#define MKE02Z32Vxx2 100
#define MKE02Z64Vxx2 101
#define MKE04Z8Vxx4 102
#define MKL02Z8Vxx4 103
#define MKL02Z16Vxx4 104
#define MKL02Z32Vxx4 105
#define MKL04Z8Vxx4 106
#define MKL04Z16Vxx4 107
#define MKL04Z32Vxx4 108
#define MKL05Z8Vxx4 109
#define MKL05Z16Vxx4 110
#define MKL05Z32Vxx4 111
#define MKL14Z32Vxx4 112
#define MKL14Z64Vxx4 113
#define MKL15Z32Vxx4 114
#define MKL15Z64Vxx4 115
#define MKL15Z128Vxx4 116
#define MKL15Z256Vxx4 117
#define MKL24Z32Vxx4 118
#define MKL24Z64Vxx4 119
#define MKL24Z128Vxx4 120
#define MKL25Z32Vxx4 121
#define MKL25Z64Vxx4 122
#define MKL25Z128Vxx4 123
#define MKL25Z256Vxx4 124
#define MKL34Z64Vxx4 125
#define MKL34Z128Vxx4 126
#define MKL34Z256Vxx4 127
#define MKL46Z128Vxx4 128
#define MKL46Z256Vxx4 129
#define MKM14Z64Cxx5 130
#define MKM14Z128Cxx5 131
#define MKM33Z64Cxx5 132
#define MKM33Z128Cxx5 133
#define MKM34Z128Cxx5 134

#if (__TARGET_PROCESSOR == MK10DN32xxx5 )
#include          <CMSIS/MK10D5.h>

#elif (__TARGET_PROCESSOR == MK10DX32xxx5 )
#include          <CMSIS/MK10D5.h>

#elif (__TARGET_PROCESSOR == MK10DN64xxx5 )
#include          <CMSIS/MK10D5.h>

#elif (__TARGET_PROCESSOR == MK10DX64xxx5 )
#include          <CMSIS/MK10D5.h>

#elif (__TARGET_PROCESSOR == MK10DN128xxx5 )
#include          <CMSIS/MK10D5.h>

#elif (__TARGET_PROCESSOR == MK10DX128xxx5 )
#include          <CMSIS/MK10D5.h>

#elif (__TARGET_PROCESSOR == MK10DX64xxx7 )
#include          <CMSIS/MK10D7.h>

#elif (__TARGET_PROCESSOR == MK10DX128xxx7 )
#include          <CMSIS/MK10D7.h>

#elif (__TARGET_PROCESSOR == MK10DX256xxx7 )
#include          <CMSIS/MK10D7.h>

#elif (__TARGET_PROCESSOR == MK10DX128Zxxx10 )
#include          <CMSIS/MK10DZ10.h>

#elif (__TARGET_PROCESSOR == MK10DX256Zxxx10 )
#include          <CMSIS/MK10DZ10.h>

#elif (__TARGET_PROCESSOR == MK10DN512Zxxx10 )
#include          <CMSIS/MK10DZ10.h>

#elif (__TARGET_PROCESSOR == MK10DX128xxx10 )
#include          <CMSIS/MK10D10.h>

#elif (__TARGET_PROCESSOR == MK10DX256xxx10 )
#include          <CMSIS/MK10D10.h>

#elif (__TARGET_PROCESSOR == MK10DN512xxx10 )
#include          <CMSIS/MK10D10.h>

#elif (__TARGET_PROCESSOR == MK10FX512xxx12 )
#include          <CMSIS/MK10F12.h>

#elif (__TARGET_PROCESSOR == MK10FN1M0xxx12 )
#include          <CMSIS/MK10F12.h>

#elif (__TARGET_PROCESSOR == MK11DX128xxx5 )
#include          <CMSIS/MK11D5.h>

#elif (__TARGET_PROCESSOR == MK11DX256xxx5 )
#include          <CMSIS/MK11D5.h>

#elif (__TARGET_PROCESSOR == MK11DN512xxx5 )
#include          <CMSIS/MK11D5.h>

#elif (__TARGET_PROCESSOR == MK12DX128xxx5 )
#include          <CMSIS/MK12D5.h>

#elif (__TARGET_PROCESSOR == MK12DX256xxx5 )
#include          <CMSIS/MK12D5.h>

#elif (__TARGET_PROCESSOR == MK12DN512xxx5 )
#include          <CMSIS/MK12D5.h>

#elif (__TARGET_PROCESSOR == MK20DN32xxx5 )
#include          <CMSIS/MK20D5.h>

#elif (__TARGET_PROCESSOR == MK20DX32xxx5 )
#include          <CMSIS/MK20D5.h>

#elif (__TARGET_PROCESSOR == MK20DN64xxx5 )
#include          <CMSIS/MK20D5.h>

#elif (__TARGET_PROCESSOR == MK20DX64xxx5 )
#include          <CMSIS/MK20D5.h>

#elif (__TARGET_PROCESSOR == MK20DN128xxx5 )
#include          <CMSIS/MK20D5.h>

#elif (__TARGET_PROCESSOR == MK20DX128xxx5 )
#include          <CMSIS/MK20D5.h>

#elif (__TARGET_PROCESSOR == MK20DX64xxx7 )
#include          <CMSIS/MK20D7.h>

#elif (__TARGET_PROCESSOR == MK20DX128xxx7 )
#include          <CMSIS/MK20D7.h>

#elif (__TARGET_PROCESSOR == MK20DX256xxx7 )
#include          <CMSIS/MK20D7.h>

#elif (__TARGET_PROCESSOR == MK20DX128Zxxx10 )
#include          <CMSIS/MK20DZ10.h>

#elif (__TARGET_PROCESSOR == MK20DX256Zxxx10 )
#include          <CMSIS/MK20DZ10.h>

#elif (__TARGET_PROCESSOR == MK20DN512Zxxx10 )
#include          <CMSIS/MK20DZ10.h>

#elif (__TARGET_PROCESSOR == MK20DX128xxx10 )
#include          <CMSIS/MK20D10.h>

#elif (__TARGET_PROCESSOR == MK20DX256xxx10 )
#include          <CMSIS/MK20D10.h>

#elif (__TARGET_PROCESSOR == MK20DN512xxx10 )
#include          <CMSIS/MK20D10.h>

#elif (__TARGET_PROCESSOR == MK21DX128xxx5 )
#include          <CMSIS/MK21D5.h>

#elif (__TARGET_PROCESSOR == MK21DX256xxx5 )
#include          <CMSIS/MK21D5.h>

#elif (__TARGET_PROCESSOR == MK21DN512xxx5 )
#include          <CMSIS/MK21D5.h>

#elif (__TARGET_PROCESSOR == MK22DX128xxx5 )
#include          <CMSIS/MK22D5.h>

#elif (__TARGET_PROCESSOR == MK22DX256xxx5 )
#include          <CMSIS/MK22D5.h>

#elif (__TARGET_PROCESSOR == MK22DN512xxx5 )
#include          <CMSIS/MK22D5.h>

#elif (__TARGET_PROCESSOR == MK30DX64xxx7 )
#include          <CMSIS/MK30D7.h>

#elif (__TARGET_PROCESSOR == MK30DX128xxx7 )
#include          <CMSIS/MK30D7.h>

#elif (__TARGET_PROCESSOR == MK30DX256xxx7 )
#include          <CMSIS/MK30D7.h>

#elif (__TARGET_PROCESSOR == MK30DX128Zxxx10 )
#include          <CMSIS/MK30DZ10.h>

#elif (__TARGET_PROCESSOR == MK30DX256Zxxx10 )
#include          <CMSIS/MK30DZ10.h>

#elif (__TARGET_PROCESSOR == MK30DN512Zxxx10 )
#include          <CMSIS/MK30DZ10.h>

#elif (__TARGET_PROCESSOR == MK30DX128xxx10 )
#include          <CMSIS/MK30D10.h>

#elif (__TARGET_PROCESSOR == MK30DX256xxx10 )
#include          <CMSIS/MK30D10.h>

#elif (__TARGET_PROCESSOR == MK30DN512xxx10 )
#include          <CMSIS/MK30D10.h>

#elif (__TARGET_PROCESSOR == MK40DX64xxx7 )
#include          <CMSIS/MK40D7.h>

#elif (__TARGET_PROCESSOR == MK40DX128xxx7 )
#include          <CMSIS/MK40D7.h>

#elif (__TARGET_PROCESSOR == MK40DX256xxx7 )
#include          <CMSIS/MK40D7.h>

#elif (__TARGET_PROCESSOR == MK40DX128Zxxx10 )
#include          <CMSIS/MK40DZ10.h>

#elif (__TARGET_PROCESSOR == MK40DX256Zxxx10 )
#include          <CMSIS/MK40DZ10.h>

#elif (__TARGET_PROCESSOR == MK40DN512Zxxx10 )
#include          <CMSIS/MK40DZ10.h>

#elif (__TARGET_PROCESSOR == MK40DX128xxx10 )
#include          <CMSIS/MK40D10.h>

#elif (__TARGET_PROCESSOR == MK40DX256xxx10 )
#include          <CMSIS/MK40D10.h>

#elif (__TARGET_PROCESSOR == MK40DN512xxx10 )
#include          <CMSIS/MK40D10.h>

#elif (__TARGET_PROCESSOR == MK50DX128xxx7 )
#include          <CMSIS/MK50D7.h>

#elif (__TARGET_PROCESSOR == MK50DX256xxx7 )
#include          <CMSIS/MK50D7.h>

#elif (__TARGET_PROCESSOR == MK50DX256xxx10 )
#include          <CMSIS/MK50D10.h>

#elif (__TARGET_PROCESSOR == MK50DN512xxx10 )
#include          <CMSIS/MK50D10.h>

#elif (__TARGET_PROCESSOR == MK50DX256Zxxx10 )
#include          <CMSIS/MK50DZ10.h>

#elif (__TARGET_PROCESSOR == MK50DN512Zxxx10 )
#include          <CMSIS/MK50DZ10.h>

#elif (__TARGET_PROCESSOR == MK51DX128xxx7 )
#include          <CMSIS/MK51D7.h>

#elif (__TARGET_PROCESSOR == MK51DX256xxx7 )
#include          <CMSIS/MK51D7.h>

#elif (__TARGET_PROCESSOR == MK51DX256xxx10 )
#include          <CMSIS/MK51D10.h>

#elif (__TARGET_PROCESSOR == MK51DN512xxx10 )
#include          <CMSIS/MK51D10.h>

#elif (__TARGET_PROCESSOR == MK51DX256Zxxx10 )
#include          <CMSIS/MK51DZ10.h>

#elif (__TARGET_PROCESSOR == MK51DN512Zxxx10 )
#include          <CMSIS/MK51DZ10.h>

#elif (__TARGET_PROCESSOR == MK52DN512xxx10 )
#include          <CMSIS/MK52D10.h>

#elif (__TARGET_PROCESSOR == MK52DN512Zxxx10 )
#include          <CMSIS/MK52DZ10.h>

#elif (__TARGET_PROCESSOR == MK53DX256xxx10 )
#include          <CMSIS/MK53D10.h>

#elif (__TARGET_PROCESSOR == MK53DN512xxx10 )
#include          <CMSIS/MK53D10.h>

#elif (__TARGET_PROCESSOR == MK53DX256Zxxx10 )
#include          <CMSIS/MK53DZ10.h>

#elif (__TARGET_PROCESSOR == MK53DN512Zxxx10 )
#include          <CMSIS/MK53DZ10.h>

#elif (__TARGET_PROCESSOR == MK60DN256xxx10 )
#include          <CMSIS/MK60D10.h>

#elif (__TARGET_PROCESSOR == MK60DX256xxx10 )
#include          <CMSIS/MK60D10.h>

#elif (__TARGET_PROCESSOR == MK60DN512xxx10 )
#include          <CMSIS/MK60D10.h>

#elif (__TARGET_PROCESSOR == MK60DN256Zxxx10 )
#include          <CMSIS/MK60DZ10.h>

#elif (__TARGET_PROCESSOR == MK60DX256Zxxx10 )
#include          <CMSIS/MK60DZ10.h>

#elif (__TARGET_PROCESSOR == MK60DN512Zxxx10 )
#include          <CMSIS/MK60DZ10.h>

#elif (__TARGET_PROCESSOR == MK60FX512xxx12 )
#include          <CMSIS/MK60F12.h>

#elif (__TARGET_PROCESSOR == MK60FN1M0xxx12 )
#include          <CMSIS/MK60F12.h>

#elif (__TARGET_PROCESSOR == MK60FX512xxx15 )
#include          <CMSIS/MK60F15.h>

#elif (__TARGET_PROCESSOR == MK60FN1M0xxx15 )
#include          <CMSIS/MK60F15.h>

#elif (__TARGET_PROCESSOR == MK61FX512xxx12 )
#include          <CMSIS/MK61F12.h>

#elif (__TARGET_PROCESSOR == MK61FN1M0xxx12 )
#include          <CMSIS/MK61F12.h>

#elif (__TARGET_PROCESSOR == MK61FX512xxx15 )
#include          <CMSIS/MK61F15.h>

#elif (__TARGET_PROCESSOR == MK61FN1M0xxx15 )
#include          <CMSIS/MK61F15.h>

#elif (__TARGET_PROCESSOR == MK70FX512xxx12 )
#include          <CMSIS/MK70F12.h>

#elif (__TARGET_PROCESSOR == MK70FN1M0xxx12 )
#include          <CMSIS/MK70F12.h>

#elif (__TARGET_PROCESSOR == MK70FX512xxx15 )
#include          <CMSIS/MK70F15.h>

#elif (__TARGET_PROCESSOR == MK70FN1M0xxx15 )
#include          <CMSIS/MK70F15.h>

#elif (__TARGET_PROCESSOR == MKE02Z16Vxx2 )
#include          <CMSIS/MKE02Z2.h>

#elif (__TARGET_PROCESSOR == MKE02Z32Vxx2 )
#include          <CMSIS/MKE02Z2.h>

#elif (__TARGET_PROCESSOR == MKE02Z64Vxx2 )
#include          <CMSIS/MKE02Z2.h>

#elif (__TARGET_PROCESSOR == MKE04Z8Vxx4 )
#include          <CMSIS/MKE04Z4.h>

#elif (__TARGET_PROCESSOR == MKL02Z8Vxx4 )
#include          <CMSIS/MKL02Z4.h>

#elif (__TARGET_PROCESSOR == MKL02Z16Vxx4 )
#include          <CMSIS/MKL02Z4.h>

#elif (__TARGET_PROCESSOR == MKL02Z32Vxx4 )
#include          <CMSIS/MKL02Z4.h>

#elif (__TARGET_PROCESSOR == MKL04Z8Vxx4 )
#include          <CMSIS/MKL04Z4.h>

#elif (__TARGET_PROCESSOR == MKL04Z16Vxx4 )
#include          <CMSIS/MKL04Z4.h>

#elif (__TARGET_PROCESSOR == MKL04Z32Vxx4 )
#include          <CMSIS/MKL04Z4.h>

#elif (__TARGET_PROCESSOR == MKL05Z8Vxx4 )
#include          <CMSIS/MKL05Z4.h>

#elif (__TARGET_PROCESSOR == MKL05Z16Vxx4 )
#include          <CMSIS/MKL05Z4.h>

#elif (__TARGET_PROCESSOR == MKL05Z32Vxx4 )
#include          <CMSIS/MKL05Z4.h>

#elif (__TARGET_PROCESSOR == MKL14Z32Vxx4 )
#include          <CMSIS/MKL14Z4.h>

#elif (__TARGET_PROCESSOR == MKL14Z64Vxx4 )
#include          <CMSIS/MKL14Z4.h>

#elif (__TARGET_PROCESSOR == MKL15Z32Vxx4 )
#include          <CMSIS/MKL15Z4.h>

#elif (__TARGET_PROCESSOR == MKL15Z64Vxx4 )
#include          <CMSIS/MKL15Z4.h>

#elif (__TARGET_PROCESSOR == MKL15Z128Vxx4 )
#include          <CMSIS/MKL15Z4.h>

#elif (__TARGET_PROCESSOR == MKL15Z256Vxx4 )
#include          <CMSIS/MKL15Z4.h>

#elif (__TARGET_PROCESSOR == MKL24Z32Vxx4 )
#include          <CMSIS/MKL24Z4.h>

#elif (__TARGET_PROCESSOR == MKL24Z64Vxx4 )
#include          <CMSIS/MKL24Z4.h>

#elif (__TARGET_PROCESSOR == MKL24Z128Vxx4 )
#include          <CMSIS/MKL24Z4.h>

#elif (__TARGET_PROCESSOR == MKL25Z32Vxx4 )
#include          <CMSIS/MKL25Z4.h>

#elif (__TARGET_PROCESSOR == MKL25Z64Vxx4 )
#include          <CMSIS/MKL25Z4.h>

#elif (__TARGET_PROCESSOR == MKL25Z128Vxx4 )
#include          <CMSIS/MKL25Z4.h>

#elif (__TARGET_PROCESSOR == MKL25Z256Vxx4 )
#include          <CMSIS/MKL25Z4.h>

#elif (__TARGET_PROCESSOR == MKL34Z64Vxx4 )
#include          <CMSIS/MKL34Z4.h>

#elif (__TARGET_PROCESSOR == MKL34Z128Vxx4 )
#include          <CMSIS/MKL34Z4.h>

#elif (__TARGET_PROCESSOR == MKL34Z256Vxx4 )
#include          <CMSIS/MKL34Z4.h>

#elif (__TARGET_PROCESSOR == MKL46Z128Vxx4 )
#include          <CMSIS/MKL46Z4.h>

#elif (__TARGET_PROCESSOR == MKL46Z256Vxx4 )
#include          <CMSIS/MKL46Z4.h>

#elif (__TARGET_PROCESSOR == MKM14Z64Cxx5 )
#include          <CMSIS/MKM14Z5.h>

#elif (__TARGET_PROCESSOR == MKM14Z128Cxx5 )
#include          <CMSIS/MKM14Z5.h>

#elif (__TARGET_PROCESSOR == MKM33Z64Cxx5 )
#include          <CMSIS/MKM33Z5.h>

#elif (__TARGET_PROCESSOR == MKM33Z128Cxx5 )
#include          <CMSIS/MKM33Z5.h>

#elif (__TARGET_PROCESSOR == MKM34Z128Cxx5 )
#include          <CMSIS/MKM34Z5.h>

#else
#error bad __TARGET_PROCESSOR
#endif

#endif
