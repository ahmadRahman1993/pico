#ifndef __PICO_FIXEDSIZEMAPREDUCEJOB_H__
#define __PICO_FIXEDSIZEMAPREDUCEJOB_H__

#include <pico/EmitConfiguration.h>
#include <pico/picoGPUConfig.h>
#include <pico/MapReduceJob.h>
#include <cudacpp/Stream.h>
#include <oscpp/Thread.h>
#include <oscpp/Timer.h>
#include <vector>

namespace pico
{
  class Chunk;
  class EmitConfiguration;
  class FixedSizeMapReduceJob : public MapReduceJob
  {
    protected:
      std::vector<Chunk * > chunks;
      void * keys;
      void * vals;
      int keySize, keySpace;
      int valSize, valSpace;
      int numUniqueKeys;
      int * keyOffsets;
      int * valOffsets;
      int * numVals;

      cudacpp::Stream * kernelStream, * memcpyStream;

      // variables for both map and reduce
      void * cpuKeys, * cpuVals, * gpuKeys, * gpuVals;
      int maxStaticMem, maxKeySpace, maxValSpace, numBuffers;
      std::vector<EmitConfiguration> emitConfigs;

      // map variables
      void * gpuStaticMems;
      int * cpuKeyOffsets, * cpuValOffsets, * gpuKeyOffsets, * gpuValOffsets;
      int * cpuKeyCounts, * cpuValCounts, * gpuKeyCounts, * gpuValCounts;
      bool accumMap;
      bool syncPartSends;
      std::vector<void * > savedKeys, savedVals;
      std::vector<int> keyAndValCount;
      std::vector<oscpp::AsyncIORequest * > sendReqs;

      // reduce variables
      std::vector<picoGPUConfig> configs;
      std::vector<int> keyCount;
      bool accumReduce;
      int maxInputKeySpace, maxInputValSpace, maxInputValOffsetSpace, maxInputNumValsSpace;
      void * gpuInputKeys, * gpuInputVals;
      int  * gpuInputValOffsets, * gpuInputValCounts;

      // timing variables
      oscpp::Timer fullMapTimer, fullReduceTimer, fullTimer;
      oscpp::Timer mapPostTimer, mapFreeTimer;
      oscpp::Timer mapTimer;
      oscpp::Timer sortTimer;
      oscpp::Timer reduceTimer;
      oscpp::Timer totalTimer;

      virtual void determineMaximumSpaceRequirements();
      virtual void allocateMapVariables();
      virtual void freeMapVariables();
      virtual void mapChunkExecute(const unsigned int chunkIndex,
                                   picoGPUConfig & config,
                                   void * const memPool);
      virtual void mapChunkMemcpy(const unsigned int chunkIndex,
                                  const void * const gpuKeySpace,
                                  const void * const gpuValueSpace);
      virtual void mapChunkPartition(const unsigned int chunkIndex,
                                     void * const memPool,
                                     picoGPUConfig & config);
      virtual void queueChunk(const unsigned int chunkIndex);
      virtual void saveChunk(const unsigned int chunkIndex);
      virtual void combine();
      virtual void enqueueAllChunks();

      virtual picoGPUConfig & getReduceConfig(const int index);
      virtual void allocateReduceVariables();
      virtual void freeReduceVariables();
      virtual void getReduceRunParameters();
      virtual void copyReduceInput(const int index, const int keysSoFar);
      virtual void executeReduce(const int index);
      virtual void copyReduceOutput(const int index, const int keysSoFar);
      virtual void enqueueReductions();

      virtual void map();
      virtual void sort();
      virtual void reduce();
      virtual void collectTimings();
    public:
      FixedSizeMapReduceJob(int & argc,
                            char **& argv,
                            const bool accumulateMapResults     = false,
                            const bool accumulateReduceResults  = false,
                            const bool syncOnPartitionSends     = true);
      ~FixedSizeMapReduceJob();

      virtual void addInput(pico::Chunk * chunk);
      virtual void execute();
  };
}

#endif
