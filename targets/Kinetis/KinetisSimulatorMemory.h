#ifndef __KinetisSimulatorMemory
#define __KinetisSimulatorMemory

#include "ARMSimulatorMemoryImplementation.h"

class KinetisSimulatorMemoryImpl : public ARMSimulatorMemoryImplementation
{
public:
  KinetisSimulatorMemoryImpl();
  ~KinetisSimulatorMemoryImpl();
  bool setSpecification(bool le, unsigned argc, const char *argv[]);
  void reset();  
  void eraseAll();  
  MemoryRegion *findMemoryRegion(unsigned address, unsigned size, unsigned &offset);
private:
  MemoryRegion *pflash, *dflash, *flexram, *sram, *peripherals, *scs, *itcm;
  bool l_series;
  bool kv5_series;
  unsigned sram_start, sram_end;
};

#endif
