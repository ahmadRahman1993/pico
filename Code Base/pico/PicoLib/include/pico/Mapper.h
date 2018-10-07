#ifndef __PICO_MAPPER_H__
#define __PICO_MAPPER_H__

#include <pico/EmitConfiguration.h>
#include <pico/picoCPUConfig.h>
#include <pico/picoGPUConfig.h>
#include <cudacpp/Stream.h>

namespace pico
{
  class Chunk;

  class Mapper
  {
    public:
      Mapper();
      virtual ~Mapper();

      virtual EmitConfiguration getEmitConfiguration(pico::Chunk * const chunk) const = 0;
      virtual bool canExecuteOnGPU() const = 0;
      virtual bool canExecuteOnCPU() const = 0;
      virtual void init() = 0;
      virtual void finalize() = 0;
      virtual void executeOnGPUAsync(pico::Chunk * const chunk, picoGPUConfig & picoGPUConfig, void * const gpuMemoryForChunk,
                                     cudacpp::Stream * kernelStream, cudacpp::Stream * memcpyStream) = 0;
      virtual void executeOnCPUAsync(pico::Chunk * const chunk, picoCPUConfig & picoCPUConfig) = 0;
  };
}

#endif
