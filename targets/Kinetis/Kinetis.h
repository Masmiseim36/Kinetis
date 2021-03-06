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
#define MK21FX512Axxx12 54
#define MK21FN1M0Axxx12 55
#define MK22DX128xxx5 56
#define MK22DX256xxx5 57
#define MK22DN512xxx5 58
#define MK22FN128xxx10 59
#define MK22FN256xxx12 60
#define MK22FN512xxx12 61
#define MK22FX512xxx12 62
#define MK22FN1M0xxx12 63
#define MK24FN256xxx12 64
#define MK24FN1M0xxx12 65
#define MK26FN2M0xxx18 66
#define MK27FN2M0xxx15 67
#define MK28FN2M0xxx15 68
#define MK30DX64xxx7 69
#define MK30DX128xxx7 70
#define MK30DX256xxx7 71
#define MK30DX128Zxxx10 72
#define MK30DX256Zxxx10 73
#define MK30DN512Zxxx10 74
#define MK30DX128xxx10 75
#define MK30DX256xxx10 76
#define MK30DN512xxx10 77
#define MK40DX64xxx7 78
#define MK40DX128xxx7 79
#define MK40DX256xxx7 80
#define MK40DX128Zxxx10 81
#define MK40DX256Zxxx10 82
#define MK40DN512Zxxx10 83
#define MK40DX128xxx10 84
#define MK40DX256xxx10 85
#define MK40DN512xxx10 86
#define MK50DX128xxx7 87
#define MK50DX256xxx7 88
#define MK50DX256xxx10 89
#define MK50DN512xxx10 90
#define MK50DX256Zxxx10 91
#define MK50DN512Zxxx10 92
#define MK51DX128xxx7 93
#define MK51DX256xxx7 94
#define MK51DX256xxx10 95
#define MK51DN512xxx10 96
#define MK51DX256Zxxx10 97
#define MK51DN512Zxxx10 98
#define MK52DN512xxx10 99
#define MK52DN512Zxxx10 100
#define MK53DX256xxx10 101
#define MK53DN512xxx10 102
#define MK53DX256Zxxx10 103
#define MK53DN512Zxxx10 104
#define MK60DN256xxx10 105
#define MK60DX256xxx10 106
#define MK60DN512xxx10 107
#define MK60DN256Zxxx10 108
#define MK60DX256Zxxx10 109
#define MK60DN512Zxxx10 110
#define MK60FX512xxx12 111
#define MK60FN1M0xxx12 112
#define MK60FX512xxx15 113
#define MK60FN1M0xxx15 114
#define MK61FX512xxx12 115
#define MK61FN1M0xxx12 116
#define MK61FX512xxx15 117
#define MK61FN1M0xxx15 118
#define MK63FN1M0xxx12 119
#define MK64FX512xxx12 120
#define MK64FN1M0xxx12 121
#define MK65FX1M0xxx18 122
#define MK65FN2M0xxx18 123
#define MK66FX1M0xxx18 124
#define MK66FN2M0xxx18 125
#define MK70FX512xxx12 126
#define MK70FN1M0xxx12 127
#define MK70FX512xxx15 128
#define MK70FN1M0xxx15 129
#define MK80FN256xxx15 130
#define MK82FN256xxx15 131
#define MKE02Z16xxx2 132
#define MKE02Z32xxx2 133
#define MKE02Z64xxx2 134
#define MKE02Z16xxx4 135
#define MKE02Z32xxx4 136
#define MKE02Z64xxx4 137
#define MKE04Z8xxx4 138
#define MKE04Z64xxx4 139
#define MKE04Z128xxx4 140
#define MKE06Z64xxx4 141
#define MKE06Z128xxx4 142
#define MKE14Z32xxx4 143
#define MKE14Z64xxx4 144
#define MKE15Z32xxx4 145
#define MKE15Z64xxx4 146
#define MKE16Z32xxx4 147
#define MKE16Z64xxx4 148
#define MKE14Z128xxx7 149
#define MKE14Z256xxx7 150
#define MKE15Z128xxx7 151
#define MKE15Z256xxx7 152
#define MKE14F256xxx16 153
#define MKE14F512xxx16 154
#define MKE16F256xxx16 155
#define MKE16F512xxx16 156
#define MKE18F256xxx16 157
#define MKE18F512xxx16 158
#define SKEAZN16xxx2 159
#define SKEAZN32xxx2 160
#define SKEAZN64xxx2 161
#define SKEAZN8xxx4 162
#define SKEAZ64xxx4 163
#define SKEAZ128xxx4 164
#define MKL02Z8xxx4 165
#define MKL02Z16xxx4 166
#define MKL02Z32xxx4 167
#define MKL03Z8xxx4 168
#define MKL03Z16xxx4 169
#define MKL03Z32xxx4 170
#define MKL04Z8xxx4 171
#define MKL04Z16xxx4 172
#define MKL04Z32xxx4 173
#define MKL05Z8xxx4 174
#define MKL05Z16xxx4 175
#define MKL05Z32xxx4 176
#define MKL13Z32xxx4 177
#define MKL13Z64xxx4 178
#define MKL14Z32xxx4 179
#define MKL14Z64xxx4 180
#define MKL15Z32xxx4 181
#define MKL15Z64xxx4 182
#define MKL15Z128xxx4 183
#define MKL16Z32xxx4 184
#define MKL16Z64xxx4 185
#define MKL16Z128xxx4 186
#define MKL16Z256xxx4 187
#define MKL17Z32xxx4 188
#define MKL17Z64xxx4 189
#define MKL17Z128xxx4 190
#define MKL17Z256xxx4 191
#define MKL24Z32xxx4 192
#define MKL24Z64xxx4 193
#define MKL25Z32xxx4 194
#define MKL25Z64xxx4 195
#define MKL25Z128xxx4 196
#define MKL26Z32xxx4 197
#define MKL26Z64xxx4 198
#define MKL26Z128xxx4 199
#define MKL26Z256xxx4 200
#define MKL27Z32xxx4 201
#define MKL27Z64xxx4 202
#define MKL27Z128xxx4 203
#define MKL27Z256xxx4 204
#define MKL28Z512xxx7 205
#define MKL33Z32xxx4 206
#define MKL33Z64xxx4 207
#define MKL33Z128xxx4 208
#define MKL33Z256xxx4 209
#define MKL34Z64xxx4 210
#define MKL36Z64xxx4 211
#define MKL36Z128xxx4 212
#define MKL36Z256xxx4 213
#define MKL43Z64xxx4 214
#define MKL43Z128xxx4 215
#define MKL43Z256xxx4 216
#define MKL46Z128xxx4 217
#define MKL46Z256xxx4 218
#define MKL82Z128xxx7 219
#define MKM14Z64xxx5 220
#define MKM14Z128xxx5 221
#define MKM14Z64Axxx5 222
#define MKM14Z128Axxx5 223
#define MKM33Z64xxx5 224
#define MKM33Z128xxx5 225
#define MKM33Z64Axxx5 226
#define MKM33Z128Axxx5 227
#define MKM34Z128xxx5 228
#define MKM34Z128Axxx5 229
#define MKM34Z256xxx7 230
#define MKS22FN128xxx12 231
#define MKS22FN256xxx12 232
#define MKV10Z16xxx7 233
#define MKV10Z32xxx7 234
#define MKV10Z64xxx7 235
#define MKV10Z128xxx7 236
#define MKV11Z64xxx7 237
#define MKV11Z128xxx7 238
#define MKV30F64xxx10 239
#define MKV30F128xxx10 240
#define MKV31F128xxx10 241
#define MKV31F256xxx12 242
#define MKV31F512xxx12 243
#define MKV42F64xxx16 244
#define MKV42F128xxx16 245
#define MKV42F256xxx16 246
#define MKV44F64xxx16 247
#define MKV44F128xxx16 248
#define MKV44F256xxx16 249
#define MKV46F128xxx16 250
#define MKV46F256xxx16 251
#define MKV56F512xxx24 252
#define MKV56F1M0xxx24 253
#define MKV58F512xxx24 254
#define MKV58F1M0xxx24 255
#define MKW01Z128xxx4 256
#define MKW21D256xxx5 257
#define MKW21D512xxx5 258
#define MKW22D512xxx5 259
#define MKW24D512xxx5 260
#define MKW20Z160xxx4 261
#define MKW21Z256xxx4 262
#define MKW21Z512xxx4 263
#define MKW30Z160xxx4 264
#define MKW31Z256xxx4 265
#define MKW31Z512xxx4 266
#define MKW40Z160xxx4 267
#define MKW41Z256xxx4 268
#define MKW41Z512xxx4 269
#define MKW35A512xxx4 270
#define MKW35Z512xxx4 271
#define MKW36A512xxx4 272
#define MKW36Z512xxx4 273
#define MWPR1516 274

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

#elif (__TARGET_PROCESSOR == MK21FX512Axxx12 )
#include          <CMSIS/MK21FA12.h>

#elif (__TARGET_PROCESSOR == MK21FN1M0Axxx12 )
#include          <CMSIS/MK21FA12.h>

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

#elif (__TARGET_PROCESSOR == MK26FN2M0xxx18 )
#include          <CMSIS/MK26F18.h>

#elif (__TARGET_PROCESSOR == MK27FN2M0xxx15 )
#include          <CMSIS/MK27F15.h>

#elif (__TARGET_PROCESSOR == MK28FN2M0xxx15 )
#include          <CMSIS/MK28F15.h>

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

#elif (__TARGET_PROCESSOR == MK65FX1M0xxx18 )
#include          <CMSIS/MK65F18.h>

#elif (__TARGET_PROCESSOR == MK65FN2M0xxx18 )
#include          <CMSIS/MK65F18.h>

#elif (__TARGET_PROCESSOR == MK66FX1M0xxx18 )
#include          <CMSIS/MK66F18.h>

#elif (__TARGET_PROCESSOR == MK66FN2M0xxx18 )
#include          <CMSIS/MK66F18.h>

#elif (__TARGET_PROCESSOR == MK70FX512xxx12 )
#include          <CMSIS/MK70F12.h>

#elif (__TARGET_PROCESSOR == MK70FN1M0xxx12 )
#include          <CMSIS/MK70F12.h>

#elif (__TARGET_PROCESSOR == MK70FX512xxx15 )
#include          <CMSIS/MK70F15.h>

#elif (__TARGET_PROCESSOR == MK70FN1M0xxx15 )
#include          <CMSIS/MK70F15.h>

#elif (__TARGET_PROCESSOR == MK80FN256xxx15 )
#include          <CMSIS/MK80F25615.h>

#elif (__TARGET_PROCESSOR == MK82FN256xxx15 )
#include          <CMSIS/MK82F25615.h>

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
#include          <CMSIS/MKE04Z1284.h>

#elif (__TARGET_PROCESSOR == MKE04Z128xxx4 )
#include          <CMSIS/MKE04Z1284.h>

#elif (__TARGET_PROCESSOR == MKE06Z64xxx4 )
#include          <CMSIS/MKE06Z4.h>

#elif (__TARGET_PROCESSOR == MKE06Z128xxx4 )
#include          <CMSIS/MKE06Z4.h>

#elif (__TARGET_PROCESSOR == MKE14Z32xxx4 )
#include          <CMSIS/MKE14Z4.h>

#elif (__TARGET_PROCESSOR == MKE14Z64xxx4 )
#include          <CMSIS/MKE14Z4.h>

#elif (__TARGET_PROCESSOR == MKE15Z32xxx4 )
#include          <CMSIS/MKE15Z4.h>

#elif (__TARGET_PROCESSOR == MKE15Z64xxx4 )
#include          <CMSIS/MKE15Z4.h>

#elif (__TARGET_PROCESSOR == MKE16Z32xxx4 )
#include          <CMSIS/MKE16Z4.h>

#elif (__TARGET_PROCESSOR == MKE16Z64xxx4 )
#include          <CMSIS/MKE16Z4.h>

#elif (__TARGET_PROCESSOR == MKE14Z128xxx7 )
#include          <CMSIS/MKE14Z7.h>

#elif (__TARGET_PROCESSOR == MKE14Z256xxx7 )
#include          <CMSIS/MKE14Z7.h>

#elif (__TARGET_PROCESSOR == MKE15Z128xxx7 )
#include          <CMSIS/MKE15Z7.h>

#elif (__TARGET_PROCESSOR == MKE15Z256xxx7 )
#include          <CMSIS/MKE15Z7.h>

#elif (__TARGET_PROCESSOR == MKE14F256xxx16 )
#include          <CMSIS/MKE14F16.h>

#elif (__TARGET_PROCESSOR == MKE14F512xxx16 )
#include          <CMSIS/MKE14F16.h>

#elif (__TARGET_PROCESSOR == MKE16F256xxx16 )
#include          <CMSIS/MKE16F16.h>

#elif (__TARGET_PROCESSOR == MKE16F512xxx16 )
#include          <CMSIS/MKE16F16.h>

#elif (__TARGET_PROCESSOR == MKE18F256xxx16 )
#include          <CMSIS/MKE18F16.h>

#elif (__TARGET_PROCESSOR == MKE18F512xxx16 )
#include          <CMSIS/MKE18F16.h>

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

#elif (__TARGET_PROCESSOR == MKL13Z32xxx4 )
#include          <CMSIS/MKL13Z644.h>

#elif (__TARGET_PROCESSOR == MKL13Z64xxx4 )
#include          <CMSIS/MKL13Z644.h>

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

#elif (__TARGET_PROCESSOR == MKL17Z32xxx4 )
#include          <CMSIS/MKL17Z644.h>

#elif (__TARGET_PROCESSOR == MKL17Z64xxx4 )
#include          <CMSIS/MKL17Z644.h>

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

#elif (__TARGET_PROCESSOR == MKL27Z32xxx4 )
#include          <CMSIS/MKL27Z644.h>

#elif (__TARGET_PROCESSOR == MKL27Z64xxx4 )
#include          <CMSIS/MKL27Z644.h>

#elif (__TARGET_PROCESSOR == MKL27Z128xxx4 )
#include          <CMSIS/MKL27Z4.h>

#elif (__TARGET_PROCESSOR == MKL27Z256xxx4 )
#include          <CMSIS/MKL27Z4.h>

#elif (__TARGET_PROCESSOR == MKL28Z512xxx7 )
#include          <CMSIS/MKL28Z7.h>

#elif (__TARGET_PROCESSOR == MKL33Z32xxx4 )
#include          <CMSIS/MKL33Z644.h>

#elif (__TARGET_PROCESSOR == MKL33Z64xxx4 )
#include          <CMSIS/MKL33Z644.h>

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

#elif (__TARGET_PROCESSOR == MKL82Z128xxx7 )
#include          <CMSIS/MKL82Z7.h>

#elif (__TARGET_PROCESSOR == MKM14Z64xxx5 )
#include          <CMSIS/MKM14Z5.h>

#elif (__TARGET_PROCESSOR == MKM14Z128xxx5 )
#include          <CMSIS/MKM14Z5.h>

#elif (__TARGET_PROCESSOR == MKM14Z64Axxx5 )
#include          <CMSIS/MKM14ZA5.h>

#elif (__TARGET_PROCESSOR == MKM14Z128Axxx5 )
#include          <CMSIS/MKM14ZA5.h>

#elif (__TARGET_PROCESSOR == MKM33Z64xxx5 )
#include          <CMSIS/MKM33Z5.h>

#elif (__TARGET_PROCESSOR == MKM33Z128xxx5 )
#include          <CMSIS/MKM33Z5.h>

#elif (__TARGET_PROCESSOR == MKM33Z64Axxx5 )
#include          <CMSIS/MKM33ZA5.h>

#elif (__TARGET_PROCESSOR == MKM33Z128Axxx5 )
#include          <CMSIS/MKM33ZA5.h>

#elif (__TARGET_PROCESSOR == MKM34Z128xxx5 )
#include          <CMSIS/MKM34Z5.h>

#elif (__TARGET_PROCESSOR == MKM34Z128Axxx5 )
#include          <CMSIS/MKM34ZA5.h>

#elif (__TARGET_PROCESSOR == MKM34Z256xxx7 )
#include          <CMSIS/MKM34Z7.h>

#elif (__TARGET_PROCESSOR == MKS22FN128xxx12 )
#include          <CMSIS/MKS22F25612.h>

#elif (__TARGET_PROCESSOR == MKS22FN256xxx12 )
#include          <CMSIS/MKS22F25612.h>

#elif (__TARGET_PROCESSOR == MKV10Z16xxx7 )
#include          <CMSIS/MKV10Z7.h>

#elif (__TARGET_PROCESSOR == MKV10Z32xxx7 )
#include          <CMSIS/MKV10Z7.h>

#elif (__TARGET_PROCESSOR == MKV10Z64xxx7 )
#include          <CMSIS/MKV10Z7.h>

#elif (__TARGET_PROCESSOR == MKV10Z128xxx7 )
#include          <CMSIS/MKV10Z7.h>

#elif (__TARGET_PROCESSOR == MKV11Z64xxx7 )
#include          <CMSIS/MKV11Z7.h>

#elif (__TARGET_PROCESSOR == MKV11Z128xxx7 )
#include          <CMSIS/MKV11Z7.h>

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

#elif (__TARGET_PROCESSOR == MKV42F64xxx16 )
#include          <CMSIS/MKV42F16.h>

#elif (__TARGET_PROCESSOR == MKV42F128xxx16 )
#include          <CMSIS/MKV42F16.h>

#elif (__TARGET_PROCESSOR == MKV42F256xxx16 )
#include          <CMSIS/MKV42F16.h>

#elif (__TARGET_PROCESSOR == MKV44F64xxx16 )
#include          <CMSIS/MKV44F16.h>

#elif (__TARGET_PROCESSOR == MKV44F128xxx16 )
#include          <CMSIS/MKV44F16.h>

#elif (__TARGET_PROCESSOR == MKV44F256xxx16 )
#include          <CMSIS/MKV44F16.h>

#elif (__TARGET_PROCESSOR == MKV46F128xxx16 )
#include          <CMSIS/MKV46F16.h>

#elif (__TARGET_PROCESSOR == MKV46F256xxx16 )
#include          <CMSIS/MKV46F16.h>

#elif (__TARGET_PROCESSOR == MKV56F512xxx24 )
#include          <CMSIS/MKV56F24.h>

#elif (__TARGET_PROCESSOR == MKV56F1M0xxx24 )
#include          <CMSIS/MKV56F24.h>

#elif (__TARGET_PROCESSOR == MKV58F512xxx24 )
#include          <CMSIS/MKV58F24.h>

#elif (__TARGET_PROCESSOR == MKV58F1M0xxx24 )
#include          <CMSIS/MKV58F24.h>

#elif (__TARGET_PROCESSOR == MKW01Z128xxx4 )
#include          <CMSIS/MKW01Z4.h>

#elif (__TARGET_PROCESSOR == MKW21D256xxx5 )
#include          <CMSIS/MKW21D5.h>

#elif (__TARGET_PROCESSOR == MKW21D512xxx5 )
#include          <CMSIS/MKW21D5.h>

#elif (__TARGET_PROCESSOR == MKW22D512xxx5 )
#include          <CMSIS/MKW22D5.h>

#elif (__TARGET_PROCESSOR == MKW24D512xxx5 )
#include          <CMSIS/MKW24D5.h>

#elif (__TARGET_PROCESSOR == MKW20Z160xxx4 )
#include          <CMSIS/MKW20Z4.h>

#elif (__TARGET_PROCESSOR == MKW21Z256xxx4 )
#include          <CMSIS/MKW21Z4.h>

#elif (__TARGET_PROCESSOR == MKW21Z512xxx4 )
#include          <CMSIS/MKW21Z4.h>

#elif (__TARGET_PROCESSOR == MKW30Z160xxx4 )
#include          <CMSIS/MKW30Z4.h>

#elif (__TARGET_PROCESSOR == MKW31Z256xxx4 )
#include          <CMSIS/MKW31Z4.h>

#elif (__TARGET_PROCESSOR == MKW31Z512xxx4 )
#include          <CMSIS/MKW31Z4.h>

#elif (__TARGET_PROCESSOR == MKW40Z160xxx4 )
#include          <CMSIS/MKW40Z4.h>

#elif (__TARGET_PROCESSOR == MKW41Z256xxx4 )
#include          <CMSIS/MKW41Z4.h>

#elif (__TARGET_PROCESSOR == MKW41Z512xxx4 )
#include          <CMSIS/MKW41Z4.h>

#elif (__TARGET_PROCESSOR == MKW35A512xxx4 )
#include          <CMSIS/MKW35A4.h>

#elif (__TARGET_PROCESSOR == MKW35Z512xxx4 )
#include          <CMSIS/MKW35Z4.h>

#elif (__TARGET_PROCESSOR == MKW36A512xxx4 )
#include          <CMSIS/MKW36A4.h>

#elif (__TARGET_PROCESSOR == MKW36Z512xxx4 )
#include          <CMSIS/MKW36Z4.h>

#elif (__TARGET_PROCESSOR == MWPR1516 )
#include          <CMSIS/MWPR1516.h>

#else
#error bad __TARGET_PROCESSOR
#endif

#endif
