#ifndef __PICO_PICOGPUBLOCKFUNCTIONS_H__
#define __PICO_PICOGPUBLOCKFUNCTIONS_H__

#include <pico/picoGPUFunctions.h>

template <typename Key, typename Value>
__device__ void picoBlockEmitKeyValRegister(const int outputNumber, const Key & key, const Value & value)
{
}

template <typename Key, typename Value>
__device__ void picoBlockEmitKeyValShared(const int outputNumber, const Key & key, const Value & value)
{
}

template <typename Key, typename Value>
__device__ void picoBlockEmitKeyValGlobal(const int outputNumber, const Key & key, const Value & value)
{
}

#endif
