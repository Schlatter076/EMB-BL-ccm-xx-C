////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "tracerUsart.stm32f4xx.h"
/// * Author  : yangken
/// * Version :
/// * Date    : Dec 11, 2019
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSTRACER_ARCH_INC_TRACERUSART_STM32F4XX_H_YANGKEN_2019__
#define __LIBS_KSTRACER_ARCH_INC_TRACERUSART_STM32F4XX_H_YANGKEN_2019__

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
#include "../../tracer_types.h"

#if ((__USART_TRACER == _TRACER_ON))
#include "../../inc/tracerPeri.h"

#if (__uTRACER_CNT >= 1)
extern ksTracer_t uTracer[__uTRACER_CNT];
#endif // (__uTRACER_CNT >= 1)

#endif // ((__USART_TRACER == _TRACER_ON))

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSTRACER_ARCH_INC_TRACERUSART_STM32F4XX_H_YANGKEN_2019__
