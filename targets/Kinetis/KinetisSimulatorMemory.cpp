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

#define MCG_SC_OFFSET (MCG_BASE+0x8)
#define MCG_MC_OFFSET (MCG_BASE+0x18)

class KinetisLitePeripheralMemory : public LittleMemoryRegion
{
public:
  KinetisLitePeripheralMemory() : LittleMemoryRegion(0x100000) { }
  void reset()
    {     
      pokeByte(MCG_C1_OFFSET, 0x40);
      pokeByte(MCG_C2_OFFSET, 0x01);
      pokeByte(MCG_S_OFFSET, 0x04);
      pokeByte(MCG_SC_OFFSET, 0x00);
      pokeByte(MCG_MC_OFFSET, 0x00);       
    } 
  void pokeByte(unsigned address, unsigned value)
    {
      LittleMemoryRegion::pokeByte(address, value);
      if (address == MCG_C1_OFFSET)
        {
          pokeByte(MCG_S_OFFSET, value);
        }
    }  
};


#define ICS_BASE (0x64000)
#define ICS_C1_OFFSET (MCG_BASE+0x0)
#define ICS_C2_OFFSET (MCG_BASE+0x1)
#define ICS_C3_OFFSET (MCG_BASE+0x2)
#define ICS_C4_OFFSET (MCG_BASE+0x3)
#define ICS_S_OFFSET (MCG_BASE+0x4)

class KinetisEPeripheralMemory : public LittleMemoryRegion
{
public:
  KinetisEPeripheralMemory() : LittleMemoryRegion(0x100000) { }
  void reset()
    {     
      pokeByte(ICS_C1_OFFSET, 0x04);
      pokeByte(ICS_C2_OFFSET, 0x20);
      pokeByte(ICS_C3_OFFSET, 0x00);
      pokeByte(ICS_C4_OFFSET, 0x00);
      pokeByte(ICS_S_OFFSET, 0x10);        
    } 
  void pokeByte(unsigned address, unsigned value)
    {
      LittleMemoryRegion::pokeByte(address, value);
      if (address == ICS_C1_OFFSET)
        {
          switch ((value>>6) & 0x3)
            {
              case 0:
              case 3:
                if (value & (1<<2))
                  pokeByte(ICS_S_OFFSET, 1<<6|1<<4);
                else
                  pokeByte(ICS_S_OFFSET, 1<<6);
                break;
              case 1:
                pokeByte(ICS_S_OFFSET, 1<<2);
                break;
              case 2:
                pokeByte(ICS_S_OFFSET, 2<<2);
                break;
            }
        }
    }  
};

KinetisSimulatorMemoryImpl::KinetisSimulatorMemoryImpl() :
  pflash(0), dflash(0), flexram(0), sram(0), peripherals(0), scs(0), itcm(0)
{
}

KinetisSimulatorMemoryImpl::~KinetisSimulatorMemoryImpl()
{
  if (pflash)
    delete pflash;
  if (dflash)
    delete dflash;
  if (flexram)
    delete flexram;
  if (sram)
    delete sram;
  if (peripherals)
    delete peripherals;
  if (scs)
    delete scs;
  if (itcm)
    delete itcm;
}

bool 
KinetisSimulatorMemoryImpl::setSpecification(bool le, unsigned argc, const char *argv[])
{
  if (argc != 6)
    return false;  
  l_series = (strstr(argv[0], "MKL") == argv[0]) || (strstr(argv[0], "MKE") == argv[0]) || (strstr(argv[0], "MKM") == argv[0]) || (strstr(argv[0], "MKV10") == argv[0]) || (strstr(argv[0], "MKV11") == argv[0]) || (strstr(argv[0], "MKW0") == argv[0]) || (strstr(argv[0], "SKEA") == argv[0]) || (strstr(argv[0], "MWPR1516") == argv[0]);
  kv5_series = (strstr(argv[0], "MKV5") == argv[0]);
  pflash = new LittleMemoryRegion(strtoul(argv[1],0,0));
  pflash->clear(0xff);  
  dflash = new LittleMemoryRegion(strtoul(argv[2],0,0));
  dflash->clear(0xff);  
  flexram = new LittleMemoryRegion(strtoul(argv[3],0,0));
  sram = new LittleMemoryRegion(strtoul(argv[4],0,0));   
  unsigned sramsplit = strtoul(argv[5],0,0);
  if (strstr(argv[0], "MKE") || strstr(argv[0], "SKEA") || strstr(argv[0], "MWPR1516"))
    peripherals = new KinetisEPeripheralMemory();
  else if (strstr(argv[0], "MKL13") || strstr(argv[0], "MKL17Z32") || strstr(argv[0], "MKL17Z64") || strstr(argv[0], "MKL27Z32") || strstr(argv[0], "MKL27Z64") || strstr(argv[0], "MKL33Z32") || strstr(argv[0], "MKL33Z64"))
    peripherals = new KinetisLitePeripheralMemory();
  else
    peripherals = new KinetisPeripheralMemory();
  scs = new LittleMemoryRegion(0x1000);
  if (kv5_series)
    {
      sram_start = 0x20000000;
      sram_end = 0x20000000+sram->size();
      itcm = new LittleMemoryRegion(0x10000);
    }
  else
    {
      sram_start = 0x20000000-(sram->size()/sramsplit);
      sram_end = 0x20000000+(sram->size()/sramsplit)*(sramsplit-1);
    }
  return true;
}

void 
KinetisSimulatorMemoryImpl::reset()
{
  sram->clear(0xcd);
  flexram->clear(0xcd);
  peripherals->reset();
  scs->clear(0x0);
}

void 
KinetisSimulatorMemoryImpl::eraseAll()
{
  pflash->clear(0xff);
  dflash->clear(0xff);
}

MemoryRegion *
KinetisSimulatorMemoryImpl::findMemoryRegion(unsigned address, unsigned size, unsigned &offset)
{
  MemoryRegion *m = 0;  
  if (kv5_series && (address >= 0x10000000) && (address < (0x10000000+pflash->size())))
    {
      m = pflash;
      offset = address-0x10000000;
    }
  else if (kv5_series && (address < 0x10000))
    {
      m = itcm;
      offset = address;
    }
  else if (address < pflash->size())
    {
      m = pflash;
      offset = address;
    }
  else if (!l_series && (address >= (0x10000000-(dflash->size()/4)) && address < (0x10000000+dflash->size()/4*3)))
    {
      m = dflash;
      offset = address-(0x10000000-(dflash->size()/4));
    }
  else if (!l_series && (address >= (0x14000000-(flexram->size()/4)) && address < (0x10000000+flexram->size()/4*3)))
    {
      m = flexram;
      offset = address-(0x14000000-(flexram->size()/4));
    }
  else if (address >= sram_start && address < sram_end)
    {
      m = sram;
      offset = address-sram_start;
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
