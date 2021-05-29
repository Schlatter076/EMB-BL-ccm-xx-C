////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "RTC_PHY.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __RTC_PHY_H_KENSKY_2013_3_27
#define __RTC_PHY_H_KENSKY_2013_3_27

/**** Includes ****************************************************************/
#include    "../../../4_CFG/RTC_cfg.h"

#if   (defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_STM32F10x)
#include "../../STM32_F10x/inc/RTC_STM32F10x.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#include "../../STM32L1xx/inc/RTC_STM32L1xx.h"c
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#include "../../STM32L0xx/inc/RTC_STM32L0xx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#include "../../EFM32xGyyy/inc/RTC_EFM32xGyyy.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
#include "../../EFM32xGyyy/inc/RTC_EFM32xGyyy.h"
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif ((__MCU_TYPE == _MCU_IS_NRF51822) || ((__MCU_TYPE == _MCU_IS_NRF52832)))
#include "../../NRF51822/inc/RTC_NRF51822.h"
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#include "../../EFR32yGxx/inc/RTC_EFR32yGxx.h"
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

#if   (__MCU_TYPE == _MCU_IS_STM32F10x)
#define __RTC_is_SYNCHRONIZED           __STM32F10X_RTC_SYNCHRONIZED
#define __RTC_CLR_SYNCHROIZED()         st(__STM32F10X_RTC_CLR_SYNCHROIZED();)
#define __RTC_Enable(rtc)               st(__STM32F10X_RTC_Enable();)
#define __RTC_Disable(rtc)              st(__STM32F10X_RTC_Disable();)
#define __RTC_EnIrq(src)                st(__STM32F10X_RTC_EnIrq(src);)
#define __RTC_DisIrq(src)               st(__STM32F10X_RTC_DisIrq(src);)

#define __RTC_PENDING_IS_CLR(rtc, p)    __STM32F10X_RTC_PENDING_is_CLR((rtc), (p))
#define __RTC_PENDING_IS_SET(rtc, p)    __STM32F10X_RTC_PENDING_is_SET((rtc), (p))
#define __RTC_CLR_PENDING(rtc, p)       __STM32F10X_RTC_CLR_PENDING((rtc), (p))
#define __RTC_SET_PENDING(rtc, p)       __STM32F10X_RTC_SET_PENDING((rtc), (p))

#define __RTC_SET_ARR(rtc, arr)        __EFM32xGyyy_RTC_SET_ARR((rtc), (arr))
#define __RTC_GET_ARR(rtc, pARR)       __EFM32xGyyy_RTC_GET_ARR((rtc), (pARR))

#define __RTC_SET_CNT(rtc, CNT)        st(__STM32F10X_RTC_SET_CNT((rtc), (CNT));)
#define __RTC_GET_CNT(rtc)             __STM32F10X_RTC_GET_CNT(rtc)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#define __RTC_is_SYNCHRONIZED(rtc)      __STM32L0X_RTC_SYNCHRONIZED(rtc)
#define __RTC_CLR_SYNCHROIZED(rtc)      st(__STM32L0X_RTC_CLR_SYNCHROIZED(rtc);)
#define __RTC_Enable(rtc)               st(__STM32L0X_RTC_Enable(rtc);)
#define __RTC_Disable(rtc)              st(__STM32L0X_RTC_Disable(rtc);)
#define __RTC_EnIrq(src)                st(__STM32L0X_RTC_EnIrq(src);)
#define __RTC_DisIrq(src)               st(__STM32L0X_RTC_DisIrq(src);)
#define __RTC_PENDING_IS_CLR(rtc, p)    __STM32L0X_RTC_PENDING_is_CLR(rtc, p)
#define __RTC_PENDING_IS_SET(rtc, p)    __STM32L0X_RTC_PENDING_is_SET(rtc, p)
#define __RTC_CLR_PENDING(rtc, p)       __STM32L0X_RTC_CLR_PENDING(rtc, p)
#define __RTC_SET_PENDING(rtc, p)       __STM32L0X_RTC_SET_PENDING(rtc, p)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#define __RTC_is_SYNCHRONIZED(rtc)      __EFR32yGxx_RTC_SYNCHRONIZED(rtc)
#define __RTC_CLR_SYNCHROIZED(rtc)      __EFR32yGxx_RTC_CLR_SYNCHROIZED(rtc)
#define __RTC_Enable(rtc)               __EFR32yGxx_RTC_Enable(rtc)
#define __RTC_Disable(rtc)              __EFR32yGxx_RTC_Disable(rtc)
#define __RTC_EnIrq(rtc, src)           __EFR32yGxx_RTC_EnIrq(rtc, src)
#define __RTC_DisIrq(rtc, src)          __EFR32yGxx_RTC_DisIrq(rtc, src)
#define __RTC_PENDING_IS_CLR(rtc, p)    __EFR32yGxx_RTC_PENDING_is_CLR(rtc, p)
#define __RTC_PENDING_IS_SET(rtc, p)    __EFR32yGxx_RTC_PENDING_is_SET(rtc, p)
#define __RTC_CLR_PENDING(rtc, p)       __EFR32yGxx_RTC_CLR_PENDING(rtc, p)
#define __RTC_SET_PENDING(rtc, p)       __EFR32yGxx_RTC_SET_PENDING(rtc, p)

#define __RTC_SET_ARR(rtc, arr)         __EFR32yGxx_RTC_SET_ARR((rtc), (arr))
#define __RTC_GET_ARR(rtc, pARR)        __EFR32yGxx_RTC_GET_ARR((rtc), (pARR))

#define __RTC_SET_CNT(rtc, CNT)         __EFR32yGxx_RTC_SET_CNT((rtc), (CNT))
#define __RTC_GET_CNT(rtc)              __EFR32yGxx_RTC_GET_CNT(rtc)
#define __RTC_CLR_CNT(rtc)              st(__RTC_SET_CNT((rtc), 0x00);)

#elif ((__MCU_TYPE == _MCU_IS_EFM32ZGxxx) || \
       (__MCU_TYPE == _MCU_IS_EFM32TGxxx))
#define __RTC_is_SYNCHRONIZED(rtc)      __EFM32xGyyy_RTC_SYNCHRONIZED(rtc)
#define __RTC_CLR_SYNCHROIZED(rtc)      __EFM32xGyyy_RTC_CLR_SYNCHROIZED(rtc)
#define __RTC_Enable(rtc)               __EFM32xGyyy_RTC_Enable(rtc)
#define __RTC_Disable(rtc)              __EFM32xGyyy_RTC_Disable(rtc)
#define __RTC_EnIrq(rtc, src)           __EFM32xGyyy_RTC_EnIrq(src)
#define __RTC_DisIrq(rtc, src)          __EFM32xGyyy_RTC_DisIrq(src)
#define __RTC_PENDING_IS_CLR(rtc, p)    __EFM32xGyyy_RTC_PENDING_is_CLR(rtc, p)
#define __RTC_PENDING_IS_SET(rtc, p)    __EFM32xGyyy_RTC_PENDING_is_SET(rtc, p)
#define __RTC_CLR_PENDING(rtc, p)       __EFM32xGyyy_RTC_CLR_PENDING(rtc, p)
#define __RTC_SET_PENDING(rtc, p)       __EFM32xGyyy_RTC_SET_PENDING(rtc, p)

#define __RTC_SET_ARR(rtc, arr)        __EFM32xGyyy_RTC_SET_ARR((rtc), (arr))
#define __RTC_GET_ARR(rtc, pARR)       __EFM32xGyyy_RTC_GET_ARR((rtc), (pARR))

#define __RTC_SET_CNT(rtc, CNT)        __EFM32xGyyy_RTC_SET_CNT((rtc), (CNT))
#define __RTC_GET_CNT(rtc)             __EFM32xGyyy_RTC_GET_CNT(rtc)

#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif ((__MCU_TYPE == _MCU_IS_NRF51822) || (__MCU_TYPE == _MCU_IS_NRF52832))
#define __RTC_is_SYNCHRONIZED(rtc)      __NRF51822_RTC_SYNCHRONIZED(rtc)
#define __RTC_CLR_SYNCHROIZED(rtc)      __NRF51822_RTC_CLR_SYNCHROIZED(rtc)
#define __RTC_Enable(rtc)               __NRF51822_RTC_Enable(rtc)
#define __RTC_Disable(rtc)              __NRF51822_RTC_Disable(rtc)
#define __RTC_EnIrq(rtc, src)           __NRF51822_RTC_EnIrq(rtc, src)
#define __RTC_DisIrq(rtc, src)          __NRF51822_RTC_DisIrq(rtc, src)
#define __RTC_PENDING_IS_CLR(rtc, p)    __NRF51822_RTC_PENDING_is_CLR(rtc, p)
#define __RTC_PENDING_IS_SET(rtc, p)    __NRF51822_RTC_PENDING_is_SET(rtc, p)
#define __RTC_CLR_PENDING(rtc, p)       __NRF51822_RTC_CLR_PENDING(rtc, p)
#define __RTC_SET_PENDING(rtc, p)       __NRF51822_RTC_SET_PENDING(rtc, p)

// RTC of NRF51822 has no auto-reload function, we will use CC0 to replace it
#define __RTC_SET_ARR(rtc, arr)         __NRF51822_RTC_SET_ARR((rtc), (arr))
#define __RTC_GET_ARR(rtc, pARR)        __NRF51822_RTC_GET_ARR((rtc), (pARR))

// RTC of NRF51822 is read only
// #define __RTC_SET_CNT(rtc, CNT)
#define __RTC_GET_CNT(rtc)              __NRF51822_RTC_GET_CNT(rtc)
#define __RTC_CLR_CNT(rtc)              st(__NRF51822_RTC_CLR_CNT(rtc);)

#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#else
#endif

#endif // __RTC_PHY_H_KENSKY_2013_3_27
