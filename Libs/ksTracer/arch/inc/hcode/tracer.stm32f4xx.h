////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "tracer.stm32f4xx.h"
/// * Author  : yangken
/// * Version :
/// * Date    : Dec 9, 2019
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSTRACER_ARCH_INC_HCODE_TRACER_STM32F4XX_H_YANGKEN_2019__
#define __LIBS_KSTRACER_ARCH_INC_HCODE_TRACER_STM32F4XX_H_YANGKEN_2019__

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
#include <tracer_cfg.h>
// #include 

/**** Definess ****************************************************************/
#if   (__MCU_TYPE == _MCU_IS_STM32F4xx)
#define   __TRACER_IT_RXNE                (USART_IT_RXNE)
#define   __uTRACER_IO_SPEED_N_1          (is_50MHz)
#endif // __MCU_TYPE

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSTRACER_ARCH_INC_HCODE_TRACER_STM32F4XX_H_YANGKEN_2019__
