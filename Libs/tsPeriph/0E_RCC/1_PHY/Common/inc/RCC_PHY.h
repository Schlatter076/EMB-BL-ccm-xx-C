////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "RCC_PHY.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __RCC_PHY_H_KENSKY_2013_3_26
#define __RCC_PHY_H_KENSKY_2013_3_26

/**** Includes ****************************************************************/
#include "../../../4_CFG/RCC_cfg.h"

#if (defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_STM32F10x)
#include "../../STM32_F10x/inc/RCC_STM32F10x.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#include "../../STM32L1xx/inc/RCC_STM32Lx.h"
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#include "../../stm32L0xx/inc/RCC_STM32L0xx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#include "../../EFM32TGxxx/inc/RCC_EFM32TGxx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
//#include "../../EFM32TGxxx/inc/RCC_EFM32TGxx.h"
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#include "../../NRF51822/inc/RCC_NRF51822.h"
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#include "../../NRF51822/inc/RCC_NRF51822.h"
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#include "../../tiCC1310/inc/RCC_CC1310.h"
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#include "../../EFR32BG1Pxx/inc/RCC_EFR32yGxx.h"
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

#endif // __RCC_PHY_H_KENSKY_2013_3_26
