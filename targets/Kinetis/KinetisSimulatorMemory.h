#ifndef __LM3SSimulatorMemory
#define __LMS3SimulatorMemory

#include "ARMSimulatorMemoryImplementation.h"

class LM3SSimulatorMemoryImpl : public ARMSimulatorMemoryImplementation
{
public:
  LM3SSimulatorMemoryImpl();
  ~LM3SSimulatorMemoryImpl();
  bool setSpecification(bool le, unsigned argc, const char *argv[]);
  void reset();  
  void eraseAll();  
  MemoryRegion *findMemoryRegion(unsigned address, unsigned size, unsigned &offset);
private:
  MemoryRegion *flash, *sram, *peripherals, *scs;  
};

#endif
