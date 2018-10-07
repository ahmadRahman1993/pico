#ifndef __PICO_PICOGPUATOMICFUNCTIONS_H__
#define __PICO_PICOGPUATOMICFUNCTIONS_H__

#include <pico/picoGPUFunctions.h>

template <typename Key, typename Value>
__device__ void picoAtomicEmitKeyValRegister(const int outputNumber, const Key & key, const Value & value)
{
}

template <typename Key, typename Value>
__device__ void picoAtomicEmitKeyValShared(const int outputNumber, const Key * const keyDataForBlock, const Value * const valueDataForBlock)
{
}

template <typename Key, typename Value>
__device__ void picoAtomicEmitKeyValGlobal(const int outputNumber, const Key * const keyDataForBlock, const Value * const valueDataForBlock)
{
}

#endif
