/*******************************************************************************
  * File    :  NVIC_PHY.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-29
  * Brief   :  
*******************************************************************************/
#ifndef __NVIC_PHY_H_KENSKY_2012_9_29
#define __NVIC_PHY_H_KENSKY_2012_9_29

/**** Includes ****************************************************************/
#include    "../../../4_CFG/NVIC_cfg.h"

#if 	(defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_STM32F10x)
#include "../../STM32_F10x/inc/NVIC_STM32F10x.h"
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#include "../../STM32F4xx/inc/nvicSTM32F4xx.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#include "../../STM32L0xx/inc/NVIC_STM32L0xx.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#include "../../STM32L1xx/inc/NVIC_STM32Lx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#include "../../EFM32TGxx/inc/NVIC_EFM32TGxx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
#include "../../EFM32TGxx/inc/NVIC_EFM32TGxx.h"
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#include "../../NRF51822/inc/NVIC_NRF51822.h"
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#include "../../NRF52832/inc/NVIC_NRF52832.h"
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#include "../../CC1310/inc/NVIC_tiCC1310.h"
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#include "../../EFR32yGxx/inc/NVIC_EFR32yGxx.h"
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

#endif // __NVIC_PHY_H_KENSKY_2012_9_29
