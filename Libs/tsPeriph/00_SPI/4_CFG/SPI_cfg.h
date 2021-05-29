/*******************************************************************************
  * File    :  SPI_cfg.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-14
  * Brief   :  
*******************************************************************************/
#ifndef __SPI_CFG_H_KENSKY_2012_9_14
#define __SPI_CFG_H_KENSKY_2012_9_14

/**** Includes ****************************************************************/
#include    <stdint.h>
#include    "../SPI_Spec.h"

#if !(defined __MCU_TYPE)
#error "please define the __MCU_TYPE first!"
#endif

/**** Includes ****************************************************************/
#if   (__MCU_TYPE == _MCU_IS_STM32L0x)
#include "../../FF_3rdPty/STM32L0fwlib/stm32l0xx_expansion.h"
#elif (__MCU_TYPE == _MCU_IS_STM32F10x)
#include "../../FF_3rdPty/STM32F1fwlib/stm32f10x_expansion.h"
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#include "../../FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h"
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#include "../../FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#include "../../FF_3rdPty/EFM32xxfwlib/efm32YYxxx_expansion.h"
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#include "../../FF_3rdPty/EFR32xGfwlib/EFR32yGxxx_expansion.h"
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#include "../../FF_3rdPty/STM32F0fwlib/stm32f0xx_expansion.h"
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#include "../../FF_3rdPty/HSDC32L1xxfwlib/hdsc32L1xx_expansion.h"
#else
#error "please specify the MCU type"
#endif // __MCU_TYPE

/**** Defines *****************************************************************/

#endif // __SPI_CFG_H_KENSKY_2012_9_14
