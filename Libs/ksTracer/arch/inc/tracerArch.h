////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "tracerArch.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2015-3-3
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_TRACER_ARCH_INC_TRACERARCH_H_KENSKY_2015__
#define __LIBS_TRACER_ARCH_INC_TRACERARCH_H_KENSKY_2015__

//*****************************************************************************
#ifdef  __cplusplus
//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
extern "C"
{
#endif // __cplusplus

/**** Includes ****************************************************************/
#include "../../tracer_cfg.h"

/**** Defines *****************************************************************/
#if   ((__MCU_TYPE == _MCU_IS_EFM32Gxxx)  || \
       (__MCU_TYPE == _MCU_IS_EFM32TGxxx) || \
       (__MCU_TYPE == _MCU_IS_EFM32ZGxxx))
#define   __TRACER_IT_RXNE        (USART_IT_RXNE)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#define   __TRACER_IT_RXNE        (USART_IT_RXNE)
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#define   __TRACER_IT_RXNE        (USART_IT_RXNE)
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#define   __TRACER_IT_RXNE        (USART_IT_RXNE)
#elif (__MCU_TYPE == _MCU_IS_STM32F10x)
#define   __TRACER_IT_RXNE        (USART_IT_RXNE)
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#include "hcode/tracer.stm32f4xx.h"
#else
#endif


#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_TRACER_ARCH_INC_TRACERARCH_H_KENSKY_2015__
