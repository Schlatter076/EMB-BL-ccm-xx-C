/*******************************************************************************
  * File    :  RTC_spec.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-10-4
  * Brief   :  
*******************************************************************************/
#ifndef __RTC_SPEC_H_KENSKY_2012_10_4
#define __RTC_SPEC_H_KENSKY_2012_10_4

/**** Includes ****************************************************************/
#include <09_Timer/Timer_Spec.h>

/**** Defines *****************************************************************/
#if   (__MCU_TYPE == _MCU_IS_STM32F10x)
#define     _ISR_RTC_SEC            (0x00u) // second interrupt, occurring when CNTR++
#define     _ISR_RTC_ALR            (0x01u) // ALARM
#define     _ISR_RTC_ALA            (0x01u) // ALARM A, FOR STM32
#define     _ISR_RTC_COMP0          (0x01u) // FOR EFM32, NRF51822
#define     _ISR_RTC_ALB            (0x02u) // ALARM B, FOR STM32
#define     _ISR_RTC_COMP1          (0x02u) // FOR EFM32, NRF51822
#define     _ISR_RTC_OW_            (0x02u) // OVERFLOW
#define     _ISR_RTC_ARR            (_ISR_RTC_ALR) // auto reload
#define     _ISR_RTC_MAX            (_ISR_RTC_OW_)
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
// todo : not applicable for STM32F0xx
#define     _ISR_RTC_SEC            (0x00u) // second interrupt, occurring when CNTR++
#define     _ISR_RTC_ALR            (0x01u) // ALARM
#define     _ISR_RTC_ALA            (0x01u) // ALARM A, FOR STM32
#define     _ISR_RTC_COMP0          (0x01u) // FOR EFM32, NRF51822
#define     _ISR_RTC_ALB            (0x02u) // ALARM B, FOR STM32
#define     _ISR_RTC_COMP1          (0x02u) // FOR EFM32, NRF51822
#define     _ISR_RTC_OW_            (0x02u) // OVERFLOW
#define     _ISR_RTC_ARR            (_ISR_RTC_ALR) // auto reload
#define     _ISR_RTC_MAX            (_ISR_RTC_OW_)
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#define     _ISR_RTC_SEC             (0x00u)
#define     _ISR_RTC_ALR             (0x01u)
#define     _ISR_RTC_OW_             (0x02u)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#define     _ISR_RTC_ALR            (0x00u) // ALARM
#define     _ISR_RTC_ALA            (0x00u) // ALARM A, FOR STM32
#define     _ISR_RTC_PRECNT_CCV     (0x00u)
#define     _ISR_RTC_COMP0          (0x00u) // FOR EFM32, NRF51822
#define     _ISR_RTC_ALB            (0x01u) // ALARM B, FOR STM32
#define     _ISR_RTC_COMP1          (0x01u) // FOR EFM32, NRF51822
#define     _ISR_RTC_CNT_CCV        (0x01u)
#define     _ISR_RTC_COMP2          (0x02u) // FOR EFR32
#define     _ISR_RTC_OW_            (0x03u) // OVERFLOW
#define     _ISR_RTC_SEC            (0x00u) // second interrupt, occurring when CNTR++
#define     _ISR_RTC_ARR            (_ISR_RTC_COMP1) // auto reload
#define     _ISR_RTC_MAX            (_ISR_RTC_OW_)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#define     _ISR_RTC_SEC            (0x00u) // second interrupt, occurring when CNTR++
#define     _ISR_RTC_ALR            (0x01u) // ALARM
#define     _ISR_RTC_ALA            (0x01u) // ALARM A, FOR STM32
#define     _ISR_RTC_COMP0          (0x01u) // FOR EFM32, NRF51822
#define     _ISR_RTC_ALB            (0x02u) // ALARM B, FOR STM32
#define     _ISR_RTC_COMP1          (0x02u) // FOR EFM32, NRF51822
#define     _ISR_RTC_OW_            (0x03u) // OVERFLOW
#define     _ISR_RTC_ARR            (_ISR_RTC_ALR) // auto reload
#define     _ISR_RTC_MAX            (_ISR_RTC_OW_)
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#define     _ISR_RTC_SEC            (0x00u) // second interrupt, occurring when CNTR++
#define     _ISR_RTC_ALR            (0x01u) // ALARM
#define     _ISR_RTC_ALA            (0x01u) // ALARM A, FOR STM32
#define     _ISR_RTC_COMP0          (0x01u) // FOR EFM32, NRF51822
#define     _ISR_RTC_ALB            (0x02u) // ALARM B, FOR STM32
#define     _ISR_RTC_COMP1          (0x02u) // FOR EFM32, NRF51822
#define     _ISR_RTC_OW_            (0x03u) // OVERFLOW
#define     _ISR_RTC_COMP2          (0x04u) // FOR NRF51822
#define     _ISR_RTC_COMP3          (0x05u) // FOR NRF51822
#define     _ISR_RTC_TICK           (0x06u) // FOR NRF51822
#define     _ISR_RTC_ARR            (_ISR_RTC_ALR) // auto reload
#define     _ISR_RTC_MAX            (_ISR_RTC_TICK)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#define     _ISR_RTC_SEC            (0x00u) // second interrupt, occurring when CNTR++
#define     _ISR_RTC_ALR            (0x01u) // ALARM
#define     _ISR_RTC_OW_            (0x03u) // OVERFLOW
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#define     _ISR_RTC_SEC            (0x00u) // second interrupt, occurring when CNTR++
#define     _ISR_RTC_ALR            (0x01u) // ALARM
#define     _ISR_RTC_OW_            (0x03u) // OVERFLOW
#else
#define     _ISR_RTC_OW_            (0x03u) // OVERFLOW
#endif

#if ((__MCU_TYPE == _MCU_IS_NRF51822) || (__MCU_TYPE == _MCU_IS_NRF52832))
#define     _IS_ISR_RTC_SRC(src)    ((src) <= _ISR_RTC_MAX)
#define     _ISR_RTC_CNT            (_ISR_RTC_MAX + 1)
#else
#define     _IS_ISR_RTC_SRC(src)    ((src) <= _ISR_RTC_MAX)
#define     _ISR_RTC_CNT            (_ISR_RTC_OW_+1)
#endif

typedef enum
{
  rtc_src_none__    = 0x00,
  rtc_src_is_LSE    = 0x01, // low speed external osc, AKA 32768 OSC
  rtc_src_is_LSI    = 0x02, // low speed internal osc, AKA internal low speed RC
  rtc_src_is_HSE    = 0x03, // high speed external osc
  rtc_src_is_ULO    = 0x04, // ultra low speed osc
  rtc_src_is_SYN    = 0x05, // 32,768 kHz synthesized from HFCLOCK (NRF51822)
} ksRTC_SRC_e;

typedef enum
{
  rtcIrqSrc_is_Sec = _ISR_RTC_SEC, // second
  rtcIrqSrc_is_Alr = _ISR_RTC_ALR, // Alarm
  rtcIrqSrc_is_Ofw = _ISR_RTC_OW_, // OverFlow
} ksRTC_IrqSec_e;

typedef enum
{
  rtc_is_UpCounting = 0x00,
  rtc_is_DnCounting = 0x01,
} ksRTC_Dir_e;

typedef enum
{
  rtc_lowpwr_mode   = 0x00, // for STM32
  rtc_normal_mode   = 0x01,
  rtc_dbgrun_mode   = 0x02, // for EFM32
} ksRTC_Mode_e;

typedef struct
{
  ksISR_t      rtc_isr[_ISR_RTC_CNT];
} ksRTC_isr_t;

typedef struct
{
  ksU32        freq;      // RTCCLK
  ksRTC_Dir_e  direction; // up-counting or down-counting
  union
  { // the actual prescaler is the following value + 1
    ksU32      prescaler;
    struct
    { // in STM32L1/0, the prescaler is divided into 2 parts to minimize the power consumption
#if (__MCU_ENDIAN == _MCU_is_LITTLE_ENDIAN)
      ksU16    spre;      // synchronous prescaler
      ksU16    apre;      // asynchronous prescaler
#else
      ksU16    apre;      // asynchronous prescaler
      ksU16    spre;      // synchronous prescaler
#endif
    };
  };
  ksRTC_SRC_e  src;       // RTC source
  ksU08        shdwBP;    // if the shadow registers are bypassed?(for STM32L)
  ksU32        top;       // top value of the counter :: ARR value
  ksU32        cmp;       // top value of the counter :: ARR value
} ksRTC_para_t;

typedef struct
{
  ksTIM_bus_e       bus;        // no conflict with
  ksU32             periphID;   // unnecessary for stm3210x
  volatile ksAddr_t addrBase;   // this addr is used to transform to specific TIMn registers
  ksRTC_Mode_e      runningMode;
  ksTIM_width_e     width;
  ksRTC_isr_t       isr;
  ksRTC_para_t      para;
  ksU08             locked;     // for synchronization
} ksRTC_t;

#endif // __RTC_SPEC_H_KENSKY_2012_10_4
