#ifndef __PICO_PICOGPUTHREADFUNCTIONS_H__
#define __PICO_PICOGPUTHREADFUNCTIONS_H__

#include <pico/picoGPUFunctions.h>

template <typename Key, typename Value>
__device__ void picoThreadEmitKeyValRegister(const int outputNumber, const Key & key, const Value & value)
{
}

template <typename Key, typename Value>
__device__ void picoThreadEmitKeyValShared(const int outputNumber, const Key * const keyDataForBlock, const Value * const valueDataForBlock)
{
}

template <typename Key, typename Value>
__device__ void picoThreadEmitKeyValGlobal(const int outputNumber, const Key * const keyDataForBlock, const Value * const valueDataForBlock)
{
}

#endif
