////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "RTC_NRF51822.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2016-1-14
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_0B_RTC_1_PHY_NRF51822_INC_RTC_NRF51822_H_KENSKY_2016__
#define __LIBS_KSPERIPH_0B_RTC_1_PHY_NRF51822_INC_RTC_NRF51822_H_KENSKY_2016__

//*****************************************************************************
#ifdef  __cplusplus
//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
extern "C"
{
#endif // __cplusplus

/**** Includes ****************************************************************/
#include "./RTC_NRF51822Init.h"

#if ((__MCU_TYPE == _MCU_IS_NRF51822) || (__MCU_TYPE == _MCU_IS_NRF52832))

/**** Defines *****************************************************************/
#define __NRF51822_RTC_Clr_Reg(rtc, reg, flg)       st(;)
#define __NRF51822_RTC_SYNCHRONIZED(rtc)            st(;)
#define __NRF51822_RTC_CLR_SYNCHROIZED(rtc)         st(;)

#define __NRF51822_RTC_Enable(rtc)                  st(__NRF51822_RTC(rtc)->TASKS_START = 0x01;)
#define __NRF51822_RTC_Disable(rtc)                 st(__NRF51822_RTC(rtc)->TASKS_STOP  = 0x01;)

// make sure to manipulate one flag at a time
#define __NRF51822_RTC_PENDING_is_SET(rtc, p)       (*(ksU32 *)((rtc)->addrBase + (p)))
#define __NRF51822_RTC_PENDING_is_CLR(rtc, p)       !__NRF51822_RTC_PENDING_is_CLR((rtc), (p))
#define __NRF51822_RTC_CLR_PENDING(rtc, p)          st(*(ksU32 *)((rtc)->addrBase + (p)) = 0x00;)
#define __NRF51822_RTC_SET_PENDING(rtc, p)          st(*(ksU32 *)((rtc)->addrBase + (p)) = 0x01;)

#define __NRF51822_RTC_EnIrq(rtc, irq)              st(__NRF51822_RTC(rtc)->INTENSET |= (irq);)
#define __NRF51822_RTC_DisIrq(rtc, irq)             st(__NRF51822_RTC(rtc)->INTENCLR |= (irq);)
#define __NRF51822_RTC_GET_CNT(rtc)                 (__NRF51822_RTC(rtc)->COUNTER)
#define __NRF51822_RTC_CLR_CNT(rtc)                 st(__NRF51822_RTC(rtc)->TASKS_CLEAR = 0x01;)
#define __NRF51822_RTC_SET_CNT(rtc, n)              st(while(1);) // the RTC.Counter of NRF51822 is read only

// RTC of NRF51822 has no auto-reload function, we will use CC0 with inteerupt to replace it
#define __NRF51822_RTC_SET_ARR(rtc, arr)            st(__NRF51822_RTC(rtc)->CC[__NRF51822_ARR_INDEX] = (arr);)
#define __NRF51822_RTC_GET_ARR(rtc, pARR)           st(*(pARR) = __NRF51822_RTC(rtc)->CC[__NRF51822_ARR_INDEX];)

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : NRF51822RTCgetIRQn
/// @param      : MCU_RTC : the instance of the RTC
/// @param      : irqSrc  : INTERRUPT SOURCE
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-4-29
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE IRQn_Type NRF51822RTCgetIRQn(ksRTC_t *pRTC, ksU08 irqSrc)
{
  __KS_RUNTIME_ASSERT(_IS_ISR_RTC_SRC(irqSrc), __ASSERT_LIMIT);

  return (pRTC->bus == __KS_TIMER_RTC0) ? RTC0_IRQn : RTC1_IRQn;
}

#endif // ((defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_NRF51822))

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_0B_RTC_1_PHY_NRF51822_INC_RTC_NRF51822_H_KENSKY_2016__
