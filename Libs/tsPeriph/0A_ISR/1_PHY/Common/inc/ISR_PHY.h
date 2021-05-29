/*******************************************************************************
  * File    :  ISR_PHY.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-25
  * Brief   :  
*******************************************************************************/
#ifndef __ISR_PHY_H_KENSKY_2020_9_25
#define __ISR_PHY_H_KENSKY_2020_9_25

/**** Includes ****************************************************************/
#include    "../../../4_CFG/ISR_cfg.h"

#if 	(defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_STM32F10x)
#include "../../STM32_F10x/inc/ISR_STM32F10x.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#include "../../STM32L1xx/inc/ISR_STM32Lx.h"
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#include "../../FSKLxxZyyy/inc/ISR_FSKLxxZyyy.h"
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#include "../../STM32F0xx/inc/isrSTM32F0xx.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#include "../../STM32L0xx/inc/ISR_STM32L0xx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#include "../../EFM32TGxxx/inc/ISR_EFM32TGxxx.h"
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#include "../../EFR32BGxxx/inc/ISR_EFR32BGxxx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
#include "../../EFM32Gxxx/inc/ISR_EFM32Gxxx.h"
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#include "../../NRF51822/inc/ISR_NRF51822.h"
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#include "../../NRF52832/inc/ISR_NRF52832.h"
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#include "../../CC1310/inc/ISR_CC1310.h"
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#include "../../STM32F4xx/inc/isrSTM32F4xx.h"
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

#endif // __ISR_PHY_H_KENSKY_2020_9_25
