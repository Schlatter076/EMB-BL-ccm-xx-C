////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "Protection_PHY.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __PROTECTION_PHY_H_KEN_2020_9_25
#define __PROTECTION_PHY_H_KEN_2020_9_25

/**** Includes ****************************************************************/
#include <FD_Protection/4_CFG/Protection_cfg.h>

#if 	(defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_STM32F10x)
#include "../../STM32_F10x/inc/Protection_STM32F10x.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#include "../../STM32L1xx/inc/ProtectionSTM32L1xx.h"
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#include "../../FSKLxxZyyy/inc/Protection_FSKLxxZyyy.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)

#include  "../../STM32L0xx/inc/ProtectionSTM32L0xx.h"

#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#include "../../EFM32TGxx/inc/protectionEFM32TGxx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)

#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#include  "../../NRF51822/inc/Protection_NRF51822.h"
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#include  "../../NRF52832/inc/Protection_NRF52832.h"
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
  #include  "../../STM32_F10x/inc/Protection_STM32F10x_Init.h" // Todo
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

#endif // __PROTECTION_PHY_H_KEN_2020_9_25
