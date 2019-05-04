// Copyright (c) 2010 Rowley Associates Limited.
//
// This file may be distributed under the terms of the License Agreement
// provided with this software.
//
// THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <string.h>
#include <stdlib.h>
#include "KinetisSimulatorMemory.h"

#define MCG_BASE (0x64000)
#define MCG_C1_OFFSET (MCG_BASE+0x0)
#define MCG_C2_OFFSET (MCG_BASE+0x1)
#define MCG_C3_OFFSET (MCG_BASE+0x2)
#define MCG_C4_OFFSET (MCG_BASE+0x3)
#define MCG_C5_OFFSET (MCG_BASE+0x4)
#define MCG_C6_OFFSET (MCG_BASE+0x5)
#define MCG_S_OFFSET (MCG_BASE+0x6)
#define MCG_ATC_OFFSET (MCG_BASE+0x8)
#define MCG_ATCVH_OFFSET (MCG_BASE+0xA)
#define MCG_ATCVL_OFFSET (MCG_BASE+0xB)

class KinetisPeripheralMemory : public LittleMemoryRegion
{
public:
  KinetisPeripheralMemory() : LittleMemoryRegion(0x100000) { }
  void reset()
    {     
      pokeByte(MCG_C1_OFFSET, 0x04);
      pokeByte(MCG_C2_OFFSET, 0x00);
      pokeByte(MCG_C3_OFFSET, 0x00);
      pokeByte(MCG_C4_OFFSET, 0x00);
      pokeByte(MCG_C5_OFFSET, 0x00);
      pokeByte(MCG_C6_OFFSET, 0x00);
      pokeByte(MCG_S_OFFSET, 0x10);
      pokeByte(MCG_ATC_OFFSET, 0x00);
      pokeByte(MCG_ATCVH_OFFSET, 0x00);
      pokeByte(MCG_ATCVL_OFFSET, 0x00);
    } 
  void pokeByte(unsigned address, unsigned value)
    {
      LittleMemoryRegion::pokeByte(address, value);
      if (address == MCG_C1_OFFSET)
        {
          if (value == 0x6) // CLKS=0,FRDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0
            pokeByte(MCG_S_OFFSET, 1<<4); // set IREFST
          else if ((value & 0xc0) == 0x80) // CLKS=External reference clock
            pokeByte(MCG_S_OFFSET, (peekByte(MCG_S_OFFSET) & ~(1<<4|2<<2)) | (2<<2)); // clear IREFST and set CLKST
          else if ((value & 0xc0) == 0x40) // CLKS=Internal reference clock
            pokeByte(MCG_S_OFFSET, (peekByte(MCG_S_OFFSET) & ~(2<<2)) | (1<<4) | (1<<2)); // set IREFST and set CLKST
          else if ((value & 0xc0) == 0x0) // CLKS=FLL or PLL
            pokeByte(MCG_S_OFFSET, (peekByte(MCG_S_OFFSET) | (3<<2))); // set CLKST
        }
      else if (address == MCG_C2_OFFSET)
        {
          if (value & (1<<2)) // EREFS
            pokeByte(MCG_S_OFFSET, peekByte(MCG_S_OFFSET) | (1<<1)); // set OSCINIT
        }
      else if (address == MCG_C6_OFFSET)
        {
          if (value & (1<<6)) // PLLS
            pokeByte(MCG_S_OFFSET, peekByte(MCG_S_OFFSET) | (1<<5) | (1<<6)); // set PLLST and LOCK
        }
    }
};

KinetisSimulatorMemoryImpl::KinetisSimulatorMemoryImpl() :
  flash(0), sram(0)
{
}

KinetisSimulatorMemoryImpl::~KinetisSimulatorMemoryImpl()
{
  if (flash)
    delete flash;
  if (sram)
    delete sram;
  if (peripherals)
    delete peripherals;
  if (scs)
    delete scs;
}

bool 
KinetisSimulatorMemoryImpl::setSpecification(bool le, unsigned argc, const char *argv[])
{
  if (argc != 5)
    return false;
  unsigned flashSize = strtoul(argv[1],0,0);
  unsigned sramSize = strtoul(argv[4],0,0);
  flash = new LittleMemoryRegion(flashSize);
  flash->clear(0xff);  
  sram = new LittleMemoryRegion(sramSize);   
  peripherals = new KinetisPeripheralMemory();
  scs = new LittleMemoryRegion(0x1000);
  return true;
}

void 
KinetisSimulatorMemoryImpl::reset()
{
  sram->clear(0xcd);
  peripherals->reset();
  scs->clear(0x0);
}

void 
KinetisSimulatorMemoryImpl::eraseAll()
{
  flash->clear(0xff);
}

MemoryRegion *
KinetisSimulatorMemoryImpl::findMemoryRegion(unsigned address, unsigned size, unsigned &offset)
{
  MemoryRegion *m = 0;  
  if (address < flash->size())
    {
      m = flash;
      offset = address;
    }
  else if (address >= (0x20000000-(sram->size()/2)) && address < (0x20000000+sram->size()/2))
    {
      m = sram;
      offset = address-(0x20000000-(sram->size()/2));
    }
  else if (address >= 0x40000000 && address < 0x40100000)
    {
      m = peripherals;
      offset = address-0x40000000;
    }
  else if (address >= 0xE000E000 && address < 0xE000F000)
    {
      m = scs;
      offset = address-0xE000E000;
    }
  if (!m) 
    return 0;
  if ((offset + size) <= m->size())
    return m;
  else
    return 0;
}

#ifdef WIN32

#define WIN32_LEAN_AND_MEAN	
#include <windows.h>

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

#define EXPORT __declspec( dllexport )

#else

#define EXPORT

#endif

extern "C" EXPORT void *AllocateARMSimulatorMemoryInterface(void);
extern "C" EXPORT void ReleaseARMSimulatorMemoryInterface(void *ptr);

void *AllocateARMSimulatorMemoryInterface(void)
{
  return new KinetisSimulatorMemoryImpl();
}

void ReleaseARMSimulatorMemoryInterface(void *ptr)
{
  delete ptr;
}
