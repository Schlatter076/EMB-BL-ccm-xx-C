/*******************************************************************************
  * File    :  LIB_Common.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-10-8
  * Brief   :  
*******************************************************************************/
#ifndef __LIB_COMMON_H_KENSKY_2012_10_8
#define __LIB_COMMON_H_KENSKY_2012_10_8

/**** Includes ****************************************************************/
#include "../../../4_CFG/Lib_cfg.h"
#include <0A_ISR/ISR_Driver.h>

#if 	(defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_STM32F10x)

#include "../../STM32_F10x/inc/LIB_STM32F10x.h"

#elif (__MCU_TYPE == _MCU_IS_STM32L1x)

#include "../../STM32L1xx/inc/LIB_STM32Lx.h"

#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#include "../../STM32L0xx/inc/LIB_STM32L0xx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#include "../../EFM32TGxx/inc/LIB_EFM32TGxx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
#include "../../EFM32TGxx/inc/LIB_EFM32TGxx.h"
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif ((__MCU_TYPE == _MCU_IS_NRF51822) || ((__MCU_TYPE == _MCU_IS_NRF52832)))
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

#endif // __LIB_COMMON_H_KENSKY_2012_10_8
