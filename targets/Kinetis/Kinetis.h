// Copyright (c) 2010-2014 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#ifndef __Kinetis_H__
#define __Kinetis_H__

#define MK02FN64xxx10 1
#define MK02FN128xxx10 2
#define MK10DN32xxx5 3
#define MK10DX32xxx5 4
#define MK10DN64xxx5 5
#define MK10DX64xxx5 6
#define MK10DN128xxx5 7
#define MK10DX128xxx5 8
#define MK10DX64xxx7 9
#define MK10DX128xxx7 10
#define MK10DX256xxx7 11
#define MK10DX128Zxxx10 12
#define MK10DX256Zxxx10 13
#define MK10DN512Zxxx10 14
#define MK10DX128xxx10 15
#define MK10DX256xxx10 16
#define MK10DN512xxx10 17
#define MK10FX512xxx12 18
#define MK10FN1M0xxx12 19
#define MK11DX128xxx5 20
#define MK11DX256xxx5 21
#define MK11DN512xxx5 22
#define MK11DX128Axxx5 23
#define MK11DX256Axxx5 24
#define MK11DN512Axxx5 25
#define MK12DX128xxx5 26
#define MK12DX256xxx5 27
#define MK12DN512xxx5 28
#define MK20DN32xxx5 29
#define MK20DX32xxx5 30
#define MK20DN64xxx5 31
#define MK20DX64xxx5 32
#define MK20DN128xxx5 33
#define MK20DX128xxx5 34
#define MK20DX64xxx7 35
#define MK20DX128xxx7 36
#define MK20DX256xxx7 37
#define MK20DX128Zxxx10 38
#define MK20DX256Zxxx10 39
#define MK20DN512Zxxx10 40
#define MK20DX128xxx10 41
#define MK20DX256xxx10 42
#define MK20DN512xxx10 43
#define MK20FX512xxx12 44
#define MK20FN1M0xxx12 45
#define MK21DX128xxx5 46
#define MK21DX256xxx5 47
#define MK21DN512xxx5 48
#define MK21DX128Axxx5 49
#define MK21DX256Axxx5 50
#define MK21DN512Axxx5 51
#define MK21FX512xxx12 52
#define MK21FN1M0xxx12 53
#define MK22DX128xxx5 54
#define MK22DX256xxx5 55
#define MK22DN512xxx5 56
#define MK22FN128xxx10 57
#define MK22FN256xxx12 58
#define MK22FN512xxx12 59
#define MK22FX512xxx12 60
#define MK22FN1M0xxx12 61
#define MK24FN256xxx12 62
#define MK24FN1M0xxx12 63
#define MK30DX64xxx7 64
#define MK30DX128xxx7 65
#define MK30DX256xxx7 66
#define MK30DX128Zxxx10 67
#define MK30DX256Zxxx10 68
#define MK30DN512Zxxx10 69
#define MK30DX128xxx10 70
#define MK30DX256xxx10 71
#define MK30DN512xxx10 72
#define MK40DX64xxx7 73
#define MK40DX128xxx7 74
#define MK40DX256xxx7 75
#define MK40DX128Zxxx10 76
#define MK40DX256Zxxx10 77
#define MK40DN512Zxxx10 78
#define MK40DX128xxx10 79
#define MK40DX256xxx10 80
#define MK40DN512xxx10 81
#define MK50DX128xxx7 82
#define MK50DX256xxx7 83
#define MK50DX256xxx10 84
#define MK50DN512xxx10 85
#define MK50DX256Zxxx10 86
#define MK50DN512Zxxx10 87
#define MK51DX128xxx7 88
#define MK51DX256xxx7 89
#define MK51DX256xxx10 90
#define MK51DN512xxx10 91
#define MK51DX256Zxxx10 92
#define MK51DN512Zxxx10 93
#define MK52DN512xxx10 94
#define MK52DN512Zxxx10 95
#define MK53DX256xxx10 96
#define MK53DN512xxx10 97
#define MK53DX256Zxxx10 98
#define MK53DN512Zxxx10 99
#define MK60DN256xxx10 100
#define MK60DX256xxx10 101
#define MK60DN512xxx10 102
#define MK60DN256Zxxx10 103
#define MK60DX256Zxxx10 104
#define MK60DN512Zxxx10 105
#define MK60FX512xxx12 106
#define MK60FN1M0xxx12 107
#define MK60FX512xxx15 108
#define MK60FN1M0xxx15 109
#define MK61FX512xxx12 110
#define MK61FN1M0xxx12 111
#define MK61FX512xxx15 112
#define MK61FN1M0xxx15 113
#define MK63FN1M0xxx12 114
#define MK64FX512xxx12 115
#define MK64FN1M0xxx12 116
#define MK70FX512xxx12 117
#define MK70FN1M0xxx12 118
#define MK70FX512xxx15 119
#define MK70FN1M0xxx15 120
#define MKE02Z16xxx2 121
#define MKE02Z32xxx2 122
#define MKE02Z64xxx2 123
#define MKE02Z16xxx4 124
#define MKE02Z32xxx4 125
#define MKE02Z64xxx4 126
#define MKE04Z8xxx4 127
#define MKE04Z64xxx4 128
#define MKE04Z128xxx4 129
#define MKE06Z64xxx4 130
#define MKE06Z128xxx4 131
#define SKEAZN16xxx2 132
#define SKEAZN32xxx2 133
#define SKEAZN64xxx2 134
#define SKEAZN8xxx4 135
#define SKEAZ64xxx4 136
#define SKEAZ128xxx4 137
#define MKL02Z8xxx4 138
#define MKL02Z16xxx4 139
#define MKL02Z32xxx4 140
#define MKL03Z8xxx4 141
#define MKL03Z16xxx4 142
#define MKL03Z32xxx4 143
#define MKL04Z8xxx4 144
#define MKL04Z16xxx4 145
#define MKL04Z32xxx4 146
#define MKL05Z8xxx4 147
#define MKL05Z16xxx4 148
#define MKL05Z32xxx4 149
#define MKL14Z32xxx4 150
#define MKL14Z64xxx4 151
#define MKL15Z32xxx4 152
#define MKL15Z64xxx4 153
#define MKL15Z128xxx4 154
#define MKL16Z32xxx4 155
#define MKL16Z64xxx4 156
#define MKL16Z128xxx4 157
#define MKL16Z256xxx4 158
#define MKL17Z128xxx4 159
#define MKL17Z256xxx4 160
#define MKL24Z32xxx4 161
#define MKL24Z64xxx4 162
#define MKL25Z32xxx4 163
#define MKL25Z64xxx4 164
#define MKL25Z128xxx4 165
#define MKL26Z32xxx4 166
#define MKL26Z64xxx4 167
#define MKL26Z128xxx4 168
#define MKL26Z256xxx4 169
#define MKL27Z128xxx4 170
#define MKL27Z256xxx4 171
#define MKL33Z128xxx4 172
#define MKL33Z256xxx4 173
#define MKL34Z64xxx4 174
#define MKL36Z64xxx4 175
#define MKL36Z128xxx4 176
#define MKL36Z256xxx4 177
#define MKL43Z64xxx4 178
#define MKL43Z128xxx4 179
#define MKL43Z256xxx4 180
#define MKL46Z128xxx4 181
#define MKL46Z256xxx4 182
#define MKM14Z64xxx5 183
#define MKM14Z128xxx5 184
#define MKM33Z64xxx5 185
#define MKM33Z128xxx5 186
#define MKM34Z128xxx5 187
#define MKV10Z16xxx7 188
#define MKV10Z32xxx7 189
#define MKV30F64xxx10 190
#define MKV30F128xxx10 191
#define MKV31F128xxx10 192
#define MKV31F256xxx12 193
#define MKV31F512xxx12 194
#define MKV40F64xxx15 195
#define MKV40F128xxx15 196
#define MKV40F256xxx15 197
#define MKV43F64xxx15 198
#define MKV43F128xxx15 199
#define MKV44F64xxx15 200
#define MKV44F128xxx15 201
#define MKV45F128xxx15 202
#define MKV45F256xxx15 203
#define MKV46F128xxx15 204
#define MKV46F256xxx15 205
#define MKW01Z128xxx 206
#define MKW21D256xxx5 207
#define MKW21D512xxx5 208
#define MKW22D512xxx5 209
#define MKW24D512xxx5 210
#define MWPR1516 211

#if (__TARGET_PROCESSOR == MK02FN64xxx10 )
#include          <CMSIS/MK02F12810.h>

#elif (__TARGET_PROCESSOR == MK02FN128xxx10 )
#include          <CMSIS/MK02F12810.h>

#elif (__TARGET_PROCESSOR == MK10DN32xxx5 )
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

#elif (__TARGET_PROCESSOR == MK11DX128Axxx5 )
#include          <CMSIS/MK11DA5.h>

#elif (__TARGET_PROCESSOR == MK11DX256Axxx5 )
#include          <CMSIS/MK11DA5.h>

#elif (__TARGET_PROCESSOR == MK11DN512Axxx5 )
#include          <CMSIS/MK11DA5.h>

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

#elif (__TARGET_PROCESSOR == MK21DX128Axxx5 )
#include          <CMSIS/MK21DA5.h>

#elif (__TARGET_PROCESSOR == MK21DX256Axxx5 )
#include          <CMSIS/MK21DA5.h>

#elif (__TARGET_PROCESSOR == MK21DN512Axxx5 )
#include          <CMSIS/MK21DA5.h>

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

#elif (__TARGET_PROCESSOR == MK24FN256xxx12 )
#include          <CMSIS/MK24F25612.h>

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

#elif (__TARGET_PROCESSOR == MKL17Z128xxx4 )
#include          <CMSIS/MKL17Z4.h>

#elif (__TARGET_PROCESSOR == MKL17Z256xxx4 )
#include          <CMSIS/MKL17Z4.h>

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

#elif (__TARGET_PROCESSOR == MKL27Z128xxx4 )
#include          <CMSIS/MKL27Z4.h>

#elif (__TARGET_PROCESSOR == MKL27Z256xxx4 )
#include          <CMSIS/MKL27Z4.h>

#elif (__TARGET_PROCESSOR == MKL33Z128xxx4 )
#include          <CMSIS/MKL33Z4.h>

#elif (__TARGET_PROCESSOR == MKL33Z256xxx4 )
#include          <CMSIS/MKL33Z4.h>

#elif (__TARGET_PROCESSOR == MKL34Z64xxx4 )
#include          <CMSIS/MKL34Z4.h>

#elif (__TARGET_PROCESSOR == MKL36Z64xxx4 )
#include          <CMSIS/MKL36Z4.h>

#elif (__TARGET_PROCESSOR == MKL36Z128xxx4 )
#include          <CMSIS/MKL36Z4.h>

#elif (__TARGET_PROCESSOR == MKL36Z256xxx4 )
#include          <CMSIS/MKL36Z4.h>

#elif (__TARGET_PROCESSOR == MKL43Z64xxx4 )
#include          <CMSIS/MKL43Z4.h>

#elif (__TARGET_PROCESSOR == MKL43Z128xxx4 )
#include          <CMSIS/MKL43Z4.h>

#elif (__TARGET_PROCESSOR == MKL43Z256xxx4 )
#include          <CMSIS/MKL43Z4.h>

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

#elif (__TARGET_PROCESSOR == MKV30F64xxx10 )
#include          <CMSIS/MKV30F12810.h>

#elif (__TARGET_PROCESSOR == MKV30F128xxx10 )
#include          <CMSIS/MKV30F12810.h>

#elif (__TARGET_PROCESSOR == MKV31F128xxx10 )
#include          <CMSIS/MKV31F12810.h>

#elif (__TARGET_PROCESSOR == MKV31F256xxx12 )
#include          <CMSIS/MKV31F25612.h>

#elif (__TARGET_PROCESSOR == MKV31F512xxx12 )
#include          <CMSIS/MKV31F51212.h>

#elif (__TARGET_PROCESSOR == MKV40F64xxx15 )
#include          <CMSIS/MKV40F15.h>

#elif (__TARGET_PROCESSOR == MKV40F128xxx15 )
#include          <CMSIS/MKV40F15.h>

#elif (__TARGET_PROCESSOR == MKV40F256xxx15 )
#include          <CMSIS/MKV40F15.h>

#elif (__TARGET_PROCESSOR == MKV43F64xxx15 )
#include          <CMSIS/MKV43F15.h>

#elif (__TARGET_PROCESSOR == MKV43F128xxx15 )
#include          <CMSIS/MKV43F15.h>

#elif (__TARGET_PROCESSOR == MKV44F64xxx15 )
#include          <CMSIS/MKV44F15.h>

#elif (__TARGET_PROCESSOR == MKV44F128xxx15 )
#include          <CMSIS/MKV44F15.h>

#elif (__TARGET_PROCESSOR == MKV45F128xxx15 )
#include          <CMSIS/MKV45F15.h>

#elif (__TARGET_PROCESSOR == MKV45F256xxx15 )
#include          <CMSIS/MKV45F15.h>

#elif (__TARGET_PROCESSOR == MKV46F128xxx15 )
#include          <CMSIS/MKV46F15.h>

#elif (__TARGET_PROCESSOR == MKV46F256xxx15 )
#include          <CMSIS/MKV46F15.h>

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

#elif (__TARGET_PROCESSOR == MWPR1516 )
#include          <CMSIS/MWPR1516.h>

#else
#error bad __TARGET_PROCESSOR
#endif

#endif
