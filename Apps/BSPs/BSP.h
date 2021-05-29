/*******************************************************************************
  * File    :  BSP.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-10-4
  * Brief   :  
*******************************************************************************/
#ifndef __BSP_H_KEN_YANG_2012_10_4
#define __BSP_H_KEN_YANG_2012_10_4

/**** Includes ****************************************************************/
#include <projCfg.h>

#ifndef __MCU_TYPE
#error MCU Type is not defined , please check!
#endif

#if     (__MCU_TYPE == _MCU_IS_STM32f10x)
#include "./01_PHY/STM32/inc/STM32_BSP.h"
#elif   (__MCU_TYPE == _MCU_IS_STM32L1x)
#include "./01_PHY/STM32/inc/STM32_BSP.h"
#elif   (__MCU_TYPE == _MCU_IS_STM32l0xx)
#include "./01_PHY/STM32/inc/STM32_BSP.h"
#elif   (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#include "01_PHY/EFM32TGxx/inc/EFM32TGxxBsp.h"
#elif   (__MCU_TYPE == _MCU_IS_NRF51822)
#include "01_PHY/NRF51822/inc/NRF51822_BSP.h"
#elif   (__MCU_TYPE == _MCU_IS_NRF52832)
#include "01_PHY/NRF52832/inc/NRF52832_BSP.h"
#elif   (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#include "01_PHY/EFR32yGxx/inc/EFR32yGxx_BSP.h"
#else
#endif // (defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_STM32f10x)

#endif // __BSP_H_KEN_YANG_2012_10_4
