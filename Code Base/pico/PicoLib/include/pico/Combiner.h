#ifndef __PICO_COMBINER_H__
#define __PICO_COMBINER_H__

#include <cudacpp/Stream.h>

namespace pico
{
  class Combiner
  {
    protected:
    public:
      Combiner();
      virtual ~Combiner();

      virtual bool canExecuteOnGPU() const = 0;
      virtual bool canExecuteOnCPU() const = 0;
      virtual void init() = 0;
      virtual void finalize() = 0;
      virtual int  getMemoryRequirementsOnGPU() const = 0;
      virtual void executeOnGPUAsync(void * const gpuKeys,
                                     void * const gpuValues,
                                     const int numKeys,
                                     const int singleKeySize,
                                     const int singleValSize,
                                     int * const gpuNumOutputKeys,
                                     cudacpp::Stream * const stream) = 0;
      virtual void executeOnGPUAsync(void * const gpuKeys,
                                     void * const gpuValues,
                                     int * const gpuKeyOffsets,
                                     int * const gpuValOffsets,
                                     int * const gpuNumOutputKeys,
                                     cudacpp::Stream * const stream) = 0;
      // TODO: figure out good CPU execution declarations.
      // virtual void executeOnCPUAsync(pico::Chunk * const chunk, picoCPUConfig & picoCPUConfig) = 0;
  };
}

#endif
