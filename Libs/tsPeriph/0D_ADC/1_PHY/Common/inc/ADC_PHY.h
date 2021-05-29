/*******************************************************************************
  * File    :  ADC_PHY.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-10-9
  * Brief   :  
*******************************************************************************/
#ifndef __ADC_PHY_H_KENSKY_2020_05_29
#define __ADC_PHY_H_KENSKY_2020_05_29

/**** Includes ****************************************************************/
#include "../../../4_CFG/ADC_cfg.h"

#if   (defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_STM32F10x)
#include "../../STM32_F10x/inc/ADC_STM32F10x.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#include "../../STM32L1xx/inc/ADC_STM32Lx.h"
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#include "../../STM32F0XX/inc/ADC_STM32F0XX.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif ((__MCU_TYPE == _MCU_IS_NRF51822) || ((__MCU_TYPE == _MCU_IS_NRF52832)))
#include "../../NRF52832/inc/ADC_NRF52832.h"
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

#endif // __ADC_PHY_H_KENSKY_2020_05_29
