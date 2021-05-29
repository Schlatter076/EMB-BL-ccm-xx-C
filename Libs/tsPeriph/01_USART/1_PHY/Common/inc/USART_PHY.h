/*******************************************************************************
  * File    :  USART_PHY.h
  * Author  :  kensky
  * Version :   
  * Date    :  2019-9-22
  * Brief   :  
*******************************************************************************/
#ifndef __USART_PHY_H_KENSKY_2019_9_22
#define __USART_PHY_H_KENSKY_2019_9_22

/**** Includes ****************************************************************/
#include    <01_USART/4_CFG/USART_cfg.h>

#if !defined __MCU_TYPE
#error MCU Type is not defined!
#endif

#if   (__MCU_TYPE ==  _MCU_IS_STM32F10x)
#include "../../STM32_F10x/inc/USART_STM32F10x.h"
#elif (__MCU_TYPE ==  _MCU_IS_STM32L1x)
#include "../../STM32L1xx/inc/USART_STM32L1x.h"
#elif (__MCU_TYPE ==  _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#include "../../STM32F4xx/inc/usartSTM32F4xx.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#elif ((__MCU_TYPE == _MCU_IS_EFM32TGxxx) || \
       (__MCU_TYPE == _MCU_IS_EFM32Gxxx)  || \
       (__MCU_TYPE == _MCU_IS_EFM32ZGxxx))
#include "../../EFM32XGYYY/inc/efm32xGyyyUsart.h"
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#include "../../NRF51822/inc/nrf51822Usart.h"
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#include "../../NRF51822/inc/nrf51822Usart.h"
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#include "../../EFR32xGyy/inc/efr32xGyyyUsart.h"
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted
#endif

#endif // __USART_PHY_H_KENSKY_2019_9_22
