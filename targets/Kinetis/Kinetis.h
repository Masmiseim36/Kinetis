/*****************************************************************************
 * Copyright (c) 2010, 2011 Rowley Associates Limited.                       *
 *                                                                           *
 * This file may be distributed under the terms of the License Agreement     *
 * provided with this software.                                              *
 *                                                                           *
 * THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE   *
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. *
 *****************************************************************************/

#define MK10N512VMD100 0x10A512
#define MK10X256VMD100 0x10A512//0x10B256
#define MK20N512VMD100 0x20A512
#define MK20X256VMD100 0x20A512//0x20B256
#define MK30N512VMD100 0x30A512
#define MK30X256VMD100 0x30A512//0x30B256
#define MK40N512VMD100 0x40A512
#define MK40X256VMD100 0x40A512//0x40B256
#define MK60N512VMD100 0x60A512
#define MK60X256VMD100 0x60B256

#if __TARGET_PROCESSOR==MK10N512VMD100
#include "CMSIS/MK10N512MD100.h"
#elif __TARGET_PROCESSOR==MK10X256VMD100
#include "CMSIS/MK10X256MD100.h"
#elif __TARGET_PROCESSOR==MK20N512VMD100
#include "CMSIS/MK20N512MD100.h"
#elif __TARGET_PROCESSOR==MK20X256VMD100
#include "CMSIS/MK20X256MD100.h"
#elif __TARGET_PROCESSOR==MK30N512VMD100
#include "CMSIS/MK30N512MD100.h"
#elif __TARGET_PROCESSOR==MK30X256VMD100
#include "CMSIS/MK30N256MD100.h"
#elif __TARGET_PROCESSOR==MK40N512VMD100
#include "CMSIS/MK40N512MD100.h"
#elif __TARGET_PROCESSOR==MK40X256VMD100
#include "CMSIS/MK40X256MD100.h"
#elif __TARGET_PROCESSOR==MK60N512VMD100
#include "CMSIS/MK60N512MD100.h"
#elif __TARGET_PROCESSOR==MK60X256VMD100
#include "CMSIS/MK60X256MD100.h"
#else
#error __TARGET_PROCESSOR
#endif
