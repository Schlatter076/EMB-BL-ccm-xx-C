////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "LPWR_PHY.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2019-12-11
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LPWR_PHY_H_KENSKY_2019_12_11
#define __LPWR_PHY_H_KENSKY_2019_12_11

/**** Includes ****************************************************************/
#include "../../../4_CFG/LPWR_cfg.h"

#if 	(defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_STM32F10x)
#include "../../STM32_F10x/inc/LPWR_STM32F10x.h"
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#include "../../STM32F4xx/inc/lpwrSTM32F4xx.h"
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#include "../../STM32L0xx/inc/LPWR_STM32L0yyx.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#include "../../STM32L1xx/inc/LPWR_STM32L1x.h"
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#include "../../FSKLxxZyyy/inc/LPWR_FSKLxxZyyy.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#include "../../EFM32TGxx/inc/LPWR_EFM32TGxx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
#include "../../EFM32TGxx/inc/LPWR_EFM32TGxx.h"
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#include "../../EFR32yGxx/inc/LPWR_EFR32yGxx.h"
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#include "../../NRF51822/inc/LPWR_NRF51822.h"
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#include "../../NRF52832/inc/LPWR_NRF52832.h"
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

#endif // __LPWR_PHY_H_KENSKY_2019_12_11
