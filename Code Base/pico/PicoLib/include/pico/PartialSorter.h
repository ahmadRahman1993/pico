#ifndef __PICO_PARTIALSORTER_H__
#define __PICO_PARTIALSORTER_H__

#include <pico/picoCPUConfig.h>
#include <pico/picoGPUConfig.h>

namespace pico
{
  class PartialSorter
  {
    public:
      PartialSorter();
      virtual ~PartialSorter();

      virtual bool canExecuteOnGPU() const = 0;
      virtual bool canExecuteOnCPU() const = 0;
      virtual void init() = 0;
      virtual void finalize() = 0;
      virtual void executeOnGPUAsync(picoGPUConfig * const picoGPUConfig) = 0;
      virtual void executeOnCPUAsync(picoCPUConfig * const picoCPUConfig) = 0;
  };
}

#endif
