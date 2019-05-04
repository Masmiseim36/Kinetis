// Copyright (c) 2010-2014 Rowley Associates Limited.
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
#define MK20FX512xxx12 39
#define MK20FN1M0xxx12 40
#define MK21DX128xxx5 41
#define MK21DX256xxx5 42
#define MK21DN512xxx5 43
#define MK21FX512xxx12 44
#define MK21FN1M0xxx12 45
#define MK22DX128xxx5 46
#define MK22DX256xxx5 47
#define MK22DN512xxx5 48
#define MK22FN128xxx10 49
#define MK22FN256xxx12 50
#define MK22FN512xxx12 51
#define MK22FX512xxx12 52
#define MK22FN1M0xxx12 53
#define MK24FN1M0xxx12 54
#define MK30DX64xxx7 55
#define MK30DX128xxx7 56
#define MK30DX256xxx7 57
#define MK30DX128Zxxx10 58
#define MK30DX256Zxxx10 59
#define MK30DN512Zxxx10 60
#define MK30DX128xxx10 61
#define MK30DX256xxx10 62
#define MK30DN512xxx10 63
#define MK40DX64xxx7 64
#define MK40DX128xxx7 65
#define MK40DX256xxx7 66
#define MK40DX128Zxxx10 67
#define MK40DX256Zxxx10 68
#define MK40DN512Zxxx10 69
#define MK40DX128xxx10 70
#define MK40DX256xxx10 71
#define MK40DN512xxx10 72
#define MK50DX128xxx7 73
#define MK50DX256xxx7 74
#define MK50DX256xxx10 75
#define MK50DN512xxx10 76
#define MK50DX256Zxxx10 77
#define MK50DN512Zxxx10 78
#define MK51DX128xxx7 79
#define MK51DX256xxx7 80
#define MK51DX256xxx10 81
#define MK51DN512xxx10 82
#define MK51DX256Zxxx10 83
#define MK51DN512Zxxx10 84
#define MK52DN512xxx10 85
#define MK52DN512Zxxx10 86
#define MK53DX256xxx10 87
#define MK53DN512xxx10 88
#define MK53DX256Zxxx10 89
#define MK53DN512Zxxx10 90
#define MK60DN256xxx10 91
#define MK60DX256xxx10 92
#define MK60DN512xxx10 93
#define MK60DN256Zxxx10 94
#define MK60DX256Zxxx10 95
#define MK60DN512Zxxx10 96
#define MK60FX512xxx12 97
#define MK60FN1M0xxx12 98
#define MK60FX512xxx15 99
#define MK60FN1M0xxx15 100
#define MK61FX512xxx12 101
#define MK61FN1M0xxx12 102
#define MK61FX512xxx15 103
#define MK61FN1M0xxx15 104
#define MK63FN1M0xxx12 105
#define MK64FX512xxx12 106
#define MK64FN1M0xxx12 107
#define MK70FX512xxx12 108
#define MK70FN1M0xxx12 109
#define MK70FX512xxx15 110
#define MK70FN1M0xxx15 111
#define MKE02Z16xxx2 112
#define MKE02Z32xxx2 113
#define MKE02Z64xxx2 114
#define MKE02Z16xxx4 115
#define MKE02Z32xxx4 116
#define MKE02Z64xxx4 117
#define MKE04Z8xxx4 118
#define MKE04Z64xxx4 119
#define MKE04Z128xxx4 120
#define MKE06Z64xxx4 121
#define MKE06Z128xxx4 122
#define SKEAZN16xxx2 123
#define SKEAZN32xxx2 124
#define SKEAZN64xxx2 125
#define SKEAZN8xxx4 126
#define SKEAZ64xxx4 127
#define SKEAZ128xxx4 128
#define MKL02Z8xxx4 129
#define MKL02Z16xxx4 130
#define MKL02Z32xxx4 131
#define MKL03Z8xxx4 132
#define MKL03Z16xxx4 133
#define MKL03Z32xxx4 134
#define MKL04Z8xxx4 135
#define MKL04Z16xxx4 136
#define MKL04Z32xxx4 137
#define MKL05Z8xxx4 138
#define MKL05Z16xxx4 139
#define MKL05Z32xxx4 140
#define MKL14Z32xxx4 141
#define MKL14Z64xxx4 142
#define MKL15Z32xxx4 143
#define MKL15Z64xxx4 144
#define MKL15Z128xxx4 145
#define MKL16Z32xxx4 146
#define MKL16Z64xxx4 147
#define MKL16Z128xxx4 148
#define MKL16Z256xxx4 149
#define MKL24Z32xxx4 150
#define MKL24Z64xxx4 151
#define MKL25Z32xxx4 152
#define MKL25Z64xxx4 153
#define MKL25Z128xxx4 154
#define MKL26Z32xxx4 155
#define MKL26Z64xxx4 156
#define MKL26Z128xxx4 157
#define MKL26Z256xxx4 158
#define MKL34Z64xxx4 159
#define MKL36Z64xxx4 160
#define MKL36Z128xxx4 161
#define MKL36Z256xxx4 162
#define MKL46Z128xxx4 163
#define MKL46Z256xxx4 164
#define MKM14Z64xxx5 165
#define MKM14Z128xxx5 166
#define MKM33Z64xxx5 167
#define MKM33Z128xxx5 168
#define MKM34Z128xxx5 169
#define MKV10Z16xxx7 170
#define MKV10Z32xxx7 171
#define MKV31F128xxx10 172
#define MKV31F256xxx12 173
#define MKV31F512xxx12 174
#define MKW01Z128xxx 175
#define MKW21D256xxx5 176
#define MKW21D512xxx5 177
#define MKW22D512xxx5 178
#define MKW24D512xxx5 179

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

#elif (__TARGET_PROCESSOR == MK20FX512xxx12 )
#include          <CMSIS/MK20F12.h>

#elif (__TARGET_PROCESSOR == MK20FN1M0xxx12 )
#include          <CMSIS/MK20F12.h>

#elif (__TARGET_PROCESSOR == MK21DX128xxx5 )
#include          <CMSIS/MK21D5.h>

#elif (__TARGET_PROCESSOR == MK21DX256xxx5 )
#include          <CMSIS/MK21D5.h>

#elif (__TARGET_PROCESSOR == MK21DN512xxx5 )
#include          <CMSIS/MK21D5.h>

#elif (__TARGET_PROCESSOR == MK21FX512xxx12 )
#include          <CMSIS/MK21F12.h>

#elif (__TARGET_PROCESSOR == MK21FN1M0xxx12 )
#include          <CMSIS/MK21F12.h>

#elif (__TARGET_PROCESSOR == MK22DX128xxx5 )
#include          <CMSIS/MK22D5.h>

#elif (__TARGET_PROCESSOR == MK22DX256xxx5 )
#include          <CMSIS/MK22D5.h>

#elif (__TARGET_PROCESSOR == MK22DN512xxx5 )
#include          <CMSIS/MK22D5.h>

#elif (__TARGET_PROCESSOR == MK22FN128xxx10 )
#include          <CMSIS/MK22F12810.h>

#elif (__TARGET_PROCESSOR == MK22FN256xxx12 )
#include          <CMSIS/MK22F25612.h>

#elif (__TARGET_PROCESSOR == MK22FN512xxx12 )
#include          <CMSIS/MK22F51212.h>

#elif (__TARGET_PROCESSOR == MK22FX512xxx12 )
#include          <CMSIS/MK22F12.h>

#elif (__TARGET_PROCESSOR == MK22FN1M0xxx12 )
#include          <CMSIS/MK22F12.h>

#elif (__TARGET_PROCESSOR == MK24FN1M0xxx12 )
#include          <CMSIS/MK24F12.h>

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

#elif (__TARGET_PROCESSOR == MK63FN1M0xxx12 )
#include          <CMSIS/MK63F12.h>

#elif (__TARGET_PROCESSOR == MK64FX512xxx12 )
#include          <CMSIS/MK64F12.h>

#elif (__TARGET_PROCESSOR == MK64FN1M0xxx12 )
#include          <CMSIS/MK64F12.h>

#elif (__TARGET_PROCESSOR == MK70FX512xxx12 )
#include          <CMSIS/MK70F12.h>

#elif (__TARGET_PROCESSOR == MK70FN1M0xxx12 )
#include          <CMSIS/MK70F12.h>

#elif (__TARGET_PROCESSOR == MK70FX512xxx15 )
#include          <CMSIS/MK70F15.h>

#elif (__TARGET_PROCESSOR == MK70FN1M0xxx15 )
#include          <CMSIS/MK70F15.h>

#elif (__TARGET_PROCESSOR == MKE02Z16xxx2 )
#include          <CMSIS/MKE02Z2.h>

#elif (__TARGET_PROCESSOR == MKE02Z32xxx2 )
#include          <CMSIS/MKE02Z2.h>

#elif (__TARGET_PROCESSOR == MKE02Z64xxx2 )
#include          <CMSIS/MKE02Z2.h>

#elif (__TARGET_PROCESSOR == MKE02Z16xxx4 )
#include          <CMSIS/MKE02Z4.h>

#elif (__TARGET_PROCESSOR == MKE02Z32xxx4 )
#include          <CMSIS/MKE02Z4.h>

#elif (__TARGET_PROCESSOR == MKE02Z64xxx4 )
#include          <CMSIS/MKE02Z4.h>

#elif (__TARGET_PROCESSOR == MKE04Z8xxx4 )
#include          <CMSIS/MKE04Z4.h>

#elif (__TARGET_PROCESSOR == MKE04Z64xxx4 )
#include          <CMSIS/MKE04Z4.h>

#elif (__TARGET_PROCESSOR == MKE04Z128xxx4 )
#include          <CMSIS/MKE04Z1284.h>

#elif (__TARGET_PROCESSOR == MKE06Z64xxx4 )
#include          <CMSIS/MKE06Z4.h>

#elif (__TARGET_PROCESSOR == MKE06Z128xxx4 )
#include          <CMSIS/MKE06Z4.h>

#elif (__TARGET_PROCESSOR == SKEAZN16xxx2 )
#include          <CMSIS/SKEAZN642.h>

#elif (__TARGET_PROCESSOR == SKEAZN32xxx2 )
#include          <CMSIS/SKEAZN642.h>

#elif (__TARGET_PROCESSOR == SKEAZN64xxx2 )
#include          <CMSIS/SKEAZN642.h>

#elif (__TARGET_PROCESSOR == SKEAZN8xxx4 )
#include          <CMSIS/SKEAZN84.h>

#elif (__TARGET_PROCESSOR == SKEAZ64xxx4 )
#include          <CMSIS/SKEAZ1284.h>

#elif (__TARGET_PROCESSOR == SKEAZ128xxx4 )
#include          <CMSIS/SKEAZ1284.h>

#elif (__TARGET_PROCESSOR == MKL02Z8xxx4 )
#include          <CMSIS/MKL02Z4.h>

#elif (__TARGET_PROCESSOR == MKL02Z16xxx4 )
#include          <CMSIS/MKL02Z4.h>

#elif (__TARGET_PROCESSOR == MKL02Z32xxx4 )
#include          <CMSIS/MKL02Z4.h>

#elif (__TARGET_PROCESSOR == MKL03Z8xxx4 )
#include          <CMSIS/MKL03Z4.h>

#elif (__TARGET_PROCESSOR == MKL03Z16xxx4 )
#include          <CMSIS/MKL03Z4.h>

#elif (__TARGET_PROCESSOR == MKL03Z32xxx4 )
#include          <CMSIS/MKL03Z4.h>

#elif (__TARGET_PROCESSOR == MKL04Z8xxx4 )
#include          <CMSIS/MKL04Z4.h>

#elif (__TARGET_PROCESSOR == MKL04Z16xxx4 )
#include          <CMSIS/MKL04Z4.h>

#elif (__TARGET_PROCESSOR == MKL04Z32xxx4 )
#include          <CMSIS/MKL04Z4.h>

#elif (__TARGET_PROCESSOR == MKL05Z8xxx4 )
#include          <CMSIS/MKL05Z4.h>

#elif (__TARGET_PROCESSOR == MKL05Z16xxx4 )
#include          <CMSIS/MKL05Z4.h>

#elif (__TARGET_PROCESSOR == MKL05Z32xxx4 )
#include          <CMSIS/MKL05Z4.h>

#elif (__TARGET_PROCESSOR == MKL14Z32xxx4 )
#include          <CMSIS/MKL14Z4.h>

#elif (__TARGET_PROCESSOR == MKL14Z64xxx4 )
#include          <CMSIS/MKL14Z4.h>

#elif (__TARGET_PROCESSOR == MKL15Z32xxx4 )
#include          <CMSIS/MKL15Z4.h>

#elif (__TARGET_PROCESSOR == MKL15Z64xxx4 )
#include          <CMSIS/MKL15Z4.h>

#elif (__TARGET_PROCESSOR == MKL15Z128xxx4 )
#include          <CMSIS/MKL15Z4.h>

#elif (__TARGET_PROCESSOR == MKL16Z32xxx4 )
#include          <CMSIS/MKL16Z4.h>

#elif (__TARGET_PROCESSOR == MKL16Z64xxx4 )
#include          <CMSIS/MKL16Z4.h>

#elif (__TARGET_PROCESSOR == MKL16Z128xxx4 )
#include          <CMSIS/MKL16Z4.h>

#elif (__TARGET_PROCESSOR == MKL16Z256xxx4 )
#include          <CMSIS/MKL16Z4.h>

#elif (__TARGET_PROCESSOR == MKL24Z32xxx4 )
#include          <CMSIS/MKL24Z4.h>

#elif (__TARGET_PROCESSOR == MKL24Z64xxx4 )
#include          <CMSIS/MKL24Z4.h>

#elif (__TARGET_PROCESSOR == MKL25Z32xxx4 )
#include          <CMSIS/MKL25Z4.h>

#elif (__TARGET_PROCESSOR == MKL25Z64xxx4 )
#include          <CMSIS/MKL25Z4.h>

#elif (__TARGET_PROCESSOR == MKL25Z128xxx4 )
#include          <CMSIS/MKL25Z4.h>

#elif (__TARGET_PROCESSOR == MKL26Z32xxx4 )
#include          <CMSIS/MKL26Z4.h>

#elif (__TARGET_PROCESSOR == MKL26Z64xxx4 )
#include          <CMSIS/MKL26Z4.h>

#elif (__TARGET_PROCESSOR == MKL26Z128xxx4 )
#include          <CMSIS/MKL26Z4.h>

#elif (__TARGET_PROCESSOR == MKL26Z256xxx4 )
#include          <CMSIS/MKL26Z4.h>

#elif (__TARGET_PROCESSOR == MKL34Z64xxx4 )
#include          <CMSIS/MKL34Z4.h>

#elif (__TARGET_PROCESSOR == MKL36Z64xxx4 )
#include          <CMSIS/MKL36Z4.h>

#elif (__TARGET_PROCESSOR == MKL36Z128xxx4 )
#include          <CMSIS/MKL36Z4.h>

#elif (__TARGET_PROCESSOR == MKL36Z256xxx4 )
#include          <CMSIS/MKL36Z4.h>

#elif (__TARGET_PROCESSOR == MKL46Z128xxx4 )
#include          <CMSIS/MKL46Z4.h>

#elif (__TARGET_PROCESSOR == MKL46Z256xxx4 )
#include          <CMSIS/MKL46Z4.h>

#elif (__TARGET_PROCESSOR == MKM14Z64xxx5 )
#include          <CMSIS/MKM14Z5.h>

#elif (__TARGET_PROCESSOR == MKM14Z128xxx5 )
#include          <CMSIS/MKM14Z5.h>

#elif (__TARGET_PROCESSOR == MKM33Z64xxx5 )
#include          <CMSIS/MKM33Z5.h>

#elif (__TARGET_PROCESSOR == MKM33Z128xxx5 )
#include          <CMSIS/MKM33Z5.h>

#elif (__TARGET_PROCESSOR == MKM34Z128xxx5 )
#include          <CMSIS/MKM34Z5.h>

#elif (__TARGET_PROCESSOR == MKV10Z16xxx7 )
#include          <CMSIS/MKV10Z7.h>

#elif (__TARGET_PROCESSOR == MKV10Z32xxx7 )
#include          <CMSIS/MKV10Z7.h>

#elif (__TARGET_PROCESSOR == MKV31F128xxx10 )
#include          <CMSIS/MKV31F12810.h>

#elif (__TARGET_PROCESSOR == MKV31F256xxx12 )
#include          <CMSIS/MKV31F25612.h>

#elif (__TARGET_PROCESSOR == MKV31F512xxx12 )
#include          <CMSIS/MKV31F51212.h>

#elif (__TARGET_PROCESSOR == MKW01Z128xxx )
#include          <CMSIS/MKW01Z4.h>

#elif (__TARGET_PROCESSOR == MKW21D256xxx5 )
#include          <CMSIS/MKW21D5.h>

#elif (__TARGET_PROCESSOR == MKW21D512xxx5 )
#include          <CMSIS/MKW21D5.h>

#elif (__TARGET_PROCESSOR == MKW22D512xxx5 )
#include          <CMSIS/MKW22D5.h>

#elif (__TARGET_PROCESSOR == MKW24D512xxx5 )
#include          <CMSIS/MKW24D5.h>

#else
#error bad __TARGET_PROCESSOR
#endif

#endif
