#ifndef __PICOCPUCONFIG_H__
#define __PICOCPUCONFIG_H__

typedef struct _picoCPUConfig
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
} picoCPUConfig;

#endif
