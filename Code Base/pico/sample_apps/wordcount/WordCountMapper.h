#ifndef __WORDCOUNTMAPPER_H__
#define __WORDCOUNTMAPPER_H__

#include <pico/Mapper.h>

#include <string>

void wordCountMapperExecute(const float * const gpuCenters,
                         const int numCenters,
                         const int numDims,
                         void * const gpuMemoryForChunk,
                         const int numElems,
                         picoGPUConfig & picoGPUConfig,
                         cudaStream_t & stream);

class WordCountMapper : public pico::Mapper
{
  protected:
    int numUniqueWords;
    bool mappedOneAlready;
    std::string dataDir;
    void * gpuG;
  public:
    WordCountMapper(const char * const pDataDir, const int numUniqueWords);
    virtual ~WordCountMapper();

    virtual pico::EmitConfiguration getEmitConfiguration(pico::Chunk * const chunk) const;
    virtual bool canExecuteOnGPU() const;
    virtual bool canExecuteOnCPU() const;
    virtual void init();
    virtual void finalize();
    virtual void executeOnGPUAsync(pico::Chunk * const chunk, picoGPUConfig & picoGPUConfig, void * const gpuMemoryForChunk,
                                   cudacpp::Stream * kernelStream, cudacpp::Stream * memcpyStream);
    virtual void executeOnCPUAsync(pico::Chunk * const chunk, picoCPUConfig & picoCPUConfig);
};

#endif
