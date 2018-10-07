#ifndef __PICO_INTINTSORTER_H__
#define __PICO_INTINTSORTER_H__

#include <pico/Sorter.h>
#include <pico/picoCPUConfig.h>
#include <pico/picoGPUConfig.h>

namespace pico
{
  class IntIntSorter : public Sorter
  {
    public:
      IntIntSorter();
      virtual ~IntIntSorter();

      virtual bool canExecuteOnGPU() const;
      virtual bool canExecuteOnCPU() const;
      virtual void init();
      virtual void finalize();
      virtual void executeOnGPUAsync(void * const keys, void * const vals, const int numKeys, int & numUniqueKeys, int ** keyOffsets, int ** valOffsets, int ** numVals);
      virtual void executeOnCPUAsync(void * const keys, void * const vals, const int numKeys, int & numUniqueKeys, int ** keyOffsets, int ** valOffsets, int ** numVals);
  };
}

#endif
