////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "DMA_DDL.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __DMA_DDL_H_KENSKY_2013_6_23
#define __DMA_DDL_H_KENSKY_2013_6_23

/**** Includes ****************************************************************/
#include "../../1_PHY/Common/inc/DMA_PHY.h"

#if 	(__MCU_TYPE == _MCU_IS_STM32F10x)
#define     __KS_DMA_IT_GI_OS             (__STM32F10X_DMA_IT_GI_OS)
#define     __KS_DMA_IT_TC_OS             (__STM32F10X_DMA_IT_TC_OS)
#define     __KS_DMA_IT_HT_OS             (__STM32F10X_DMA_IT_HT_OS)
#define     __KS_DMA_IT_TE_OS             (__STM32F10X_DMA_IT_TE_OS)
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#define     __KS_DMA_IT_GI_OSx            (__STM32F10X_DMA_IT_GI_OS)
#define     __KS_DMA_IT_TC_OSx            (__STM32F10X_DMA_IT_TC_OS)
#define     __KS_DMA_IT_HT_OSx            (__STM32F10X_DMA_IT_HT_OS)
#define     __KS_DMA_IT_TE_OSx            (__STM32F10X_DMA_IT_TE_OS)
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#define     __KS_DMA_IT_GI_OSx            (__STM32F10X_DMA_IT_GI_OS)
#define     __KS_DMA_IT_TC_OSx            (__STM32F10X_DMA_IT_TC_OS)
#define     __KS_DMA_IT_HT_OSx            (__STM32F10X_DMA_IT_HT_OS)
#define     __KS_DMA_IT_TE_OSx            (__STM32F10X_DMA_IT_TE_OS)
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#define     __KS_DMA_IT_GI_OS             (__STM32F4XX_DMA_IT_GI_OS)
#define     __KS_DMA_IT_FE_OS             (__STM32F4XX_DMA_IT_FE_OS)
#define     __KS_DMA_IT_DM_OS             (__STM32F4XX_DMA_IT_DM_OS)
#define     __KS_DMA_IT_TE_OS             (__STM32F4XX_DMA_IT_TE_OS)
#define     __KS_DMA_IT_HT_OS             (__STM32F4XX_DMA_IT_HT_OS)
#define     __KS_DMA_IT_TC_OS             (__STM32F4XX_DMA_IT_TC_OS)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#define     __KS_DMA_IT_GI_OS             (__STM32L0X_DMA_IT_GI_OS)
#define     __KS_DMA_IT_TC_OS             (__STM32L0X_DMA_IT_TC_OS)
#define     __KS_DMA_IT_HT_OS             (__STM32L0X_DMA_IT_HT_OS)
#define     __KS_DMA_IT_TE_OS             (__STM32L0X_DMA_IT_TE_OS)
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
//#define     __KS_DMA_IT_GI_OS            (__STM32L0X_DMA_IT_GI_OS)
//#define     __KS_DMA_IT_TC_OS            (__STM32L0X_DMA_IT_TC_OS)
//#define     __KS_DMA_IT_HT_OS            (__STM32L0X_DMA_IT_HT_OS)
//#define     __KS_DMA_IT_TE_OS            (__STM32L0X_DMA_IT_TE_OS)
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
//#define     __KS_DMA_IT_GI_OS            (__STM32L0X_DMA_IT_GI_OS)
//#define     __KS_DMA_IT_TC_OS            (__STM32L0X_DMA_IT_TC_OS)
//#define     __KS_DMA_IT_HT_OS            (__STM32L0X_DMA_IT_HT_OS)
//#define     __KS_DMA_IT_TE_OS            (__STM32L0X_DMA_IT_TE_OS)
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif ((__MCU_TYPE == _MCU_IS_NRF51822) || ((__MCU_TYPE == _MCU_IS_NRF52832)))
#define     __KS_DMA_IT_GI_OSx             (__STM32L0X_DMA_IT_GI_OS)
#define     __KS_DMA_IT_TC_OSx             (__STM32L0X_DMA_IT_TC_OS)
#define     __KS_DMA_IT_HT_OSx             (__STM32L0X_DMA_IT_HT_OS)
#define     __KS_DMA_IT_TE_OSx             (__STM32L0X_DMA_IT_TE_OS)
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
// todo
#define     __KS_DMA_IT_GI_OS             (__STM32L0X_DMA_IT_GI_OS)
#define     __KS_DMA_IT_TC_OS             (__STM32L0X_DMA_IT_TC_OS)
#define     __KS_DMA_IT_HT_OS             (__STM32L0X_DMA_IT_HT_OS)
#define     __KS_DMA_IT_TE_OS             (__STM32L0X_DMA_IT_TE_OS)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#define     __KS_DMA_IT_GI_OS             (__STM32L0X_DMA_IT_GI_OS)
#define     __KS_DMA_IT_TC_OS             (__STM32L0X_DMA_IT_TC_OS)
#define     __KS_DMA_IT_HT_OS             (__STM32L0X_DMA_IT_HT_OS)
#define     __KS_DMA_IT_TE_OS             (__STM32L0X_DMA_IT_TE_OS)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error please specify the MCU Type!

#endif

#endif // __DMA_DDL_H_kensky_2013-6-23
