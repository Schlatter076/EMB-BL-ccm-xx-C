////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "DMA_PHY.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __DMA_PHY_H_KENSKY_2020_6_23
#define __DMA_PHY_H_KENSKY_2020_6_23

/**** Includes ****************************************************************/
#include <11_DMA/4_CFG/DMA_cfg.h>

#if 	(defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_STM32F10x)
#include "../../STM32_F10x/inc/stm32f10xDma.h"
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#include "../../STM32F4xx/inc/stm32f4xxDma.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)

#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#include "../../FSKLxxZyyy/inc/FSKLxxZyyyDma.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#include "../../STM32L0xx/inc/DMA_STM32L0xx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#include "../../EFM32TGxx/inc/DMA_EFM32TGxx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32ZGxxx)
#include "../../STM32L0xx/inc/DMA_STM32L0xx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
#include "../../STM32L0xx/inc/DMA_STM32L0xx.h"
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#include "../../EFR32yGxx/inc/LDMA_EFR32yGxx.h"
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

#endif // __DMA_PHY_H_KENSKY_2020_6_23
