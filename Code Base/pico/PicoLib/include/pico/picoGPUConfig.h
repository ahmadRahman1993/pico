#ifndef __PICOGPUCONFIG_H__
#define __PICOGPUCONFIG_H__

typedef struct _picoGPUConfig
{
  void * keySpace;
  void * valueSpace;
  union
  {
    struct
    {
      int keyOffset;
      int valueOffset;
    } atomic;
    struct
    {
      int * totalKeySize;
      int * totalValueSize;
      int * keyOffset;
      int * valueOffset;
    } thread, block;
    struct
    {
      int numThreads;
      int emitsPerThread;
    } grid;
  } emitInfo;
} picoGPUConfig;

#endif
