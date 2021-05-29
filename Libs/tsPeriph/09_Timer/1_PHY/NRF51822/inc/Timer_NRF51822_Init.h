////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "Timer_NRF51822_Init.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-1-24
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_09_TIMER_1_PHY_NRF51822_INC_TIMER_NRF51822_INIT_H_kensky_2020__
#define __LIBS_KSPERIPH_09_TIMER_1_PHY_NRF51822_INC_TIMER_NRF51822_INIT_H_kensky_2020__

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
#include <09_Timer/4_CFG/Timer_cfg.h>

#if ((__MCU_TYPE == _MCU_IS_NRF51822) || (__MCU_TYPE == _MCU_IS_NRF52832))

/**** Includes ****************************************************************/
#include <FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h>

/**** Defines *****************************************************************/
#define __NRF51822_TIM(TIMx)              (((NRF_TIMER_Type *)(TIMx)->addrBase))

//--- pending and flag of NRF51822 timer events ---//
#define __NRF51_TIM_CC0_FLAG              (0x00)  // always set as ARR
#define __NRF51_TIM_ARR_FLAG              (0x00)  // always set as ARR
#define __NRF51_TIM_CC1_FLAG              (0x01)  // normal CC function
#define __NRF51_TIM_CC2_FLAG              (0x02)  // normal CC function
#define __NRF51_TIM_CC3_FLAG              (0x03)  // always set as counter cpature

#define __NRF51_TIM_CC0_IRQ               (1<<16)
#define __NRF51_TIM_ARR_IRQ               (1<<16)
#define __NRF51_TIM_CC1_IRQ               (1<<17)
#define __NRF51_TIM_CC2_IRQ               (1<<18)
#define __NRF51_TIM_CC3_IRQ               (1<<19)

//--- the following macros are some most frequently used CMDs ---//
#define TIMx_EN(TIMx)                     st(__NRF51822_TIM(TIMx)->TASKS_START    = 0x01ul;)
#define TIMx_DIS(TIMx)                    st(__NRF51822_TIM(TIMx)->TASKS_STOP     = 0x01ul;)
#define TIMx_PWROFF(TIMx)                 st(__NRF51822_TIM(TIMx)->TASKS_SHUTDOWN = 0x01ul;)
#define TIMx_CntClr(TIMx)                 st(__NRF51822_TIM(TIMx)->TASKS_CLEAR    = 0x01ul;)
#define TIMx_CntGet(TIMx)                 (__NRF51822_TIM(TIMx)->TASKS_CAPTURE[__NRF51_TIM_CC3_FLAG] = 0x01, __NRF51822_TIM(TIMx)->CC[__NRF51_TIM_CC3_FLAG])

#define TIMx_IS_Pending(TIMx, Pending)    (__NRF51822_TIM(TIMx)->EVENTS_COMPARE[(Pending)])
#define TIMx_IS_CLR(TIMx, Pending)        !TIMx_IS_Pending((TIMx), (Pending))
#define TIMx_ClrPending(TIMx, Pending)    st(__NRF51822_TIM(TIMx)->EVENTS_COMPARE[(Pending)] = 0x00;)
#define TIMx_ClrFlag(TIMx, Flag)          TIMx_ClrPending((TIMx), (Flag))
#define TIMx_IrqON(TIMx, Irq)             st(__NRF51822_TIM(TIMx)->INTENSET |= (Irq);)
#define TIMx_IrqOFF(TIMx, Irq)            st(__NRF51822_TIM(TIMx)->INTENCLR |= (Irq);)
#define TIMx_IRQ_IS_ON(TIMx, Irq)         (__NRF51822_TIM(TIMx)->INTENSET & (Irq))
#define TIMx_GET_ARR(TIMx, buf)           (*buf = __NRF51822_TIM(TIMx)->CC[__NRF51_TIM_CC0_FLAG])
#define TIMx_SET_ARR(TIMx, val)           (__NRF51822_TIM(TIMx)->CC[__NRF51_TIM_CC0_FLAG] = val)

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// @fn         : nrf51822TimGetChn
/// @param      : TIMx the instance of the timer
/// @return     : description of return value.
/// @brief      : get the timer channel based on bus definition
/// @author     : kensky
/// @date       : 2014-10-23
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void nrf51822TimGetChn (ksTIM_t *pTimer)
{
  switch (pTimer->bus)
  {
    case is_tim00 :
    case is_tim01 :
    case is_tim02 :
    {
      pTimer->addrBase  = (ksAddr_t)TIM0 + (pTimer->bus-is_tim00)*((ksAddr_t)TIM1-(ksAddr_t)TIM0);
    }
    break;

#if   (__MCU_TYPE == _MCU_IS_NRF52832)
    case is_tim03 :
    case is_tim04 :
    {
      pTimer->addrBase  = (ksAddr_t)TIM3 + (pTimer->bus-is_tim03)*((ksAddr_t)TIM4-(ksAddr_t)TIM3);
      pTimer->addrBase  = (ksAddr_t)TIM3;
    }
    break;
#endif

    default :
      __KS_FORCE_ASSERT(__ASSERT_NOT_HAPPEN);
  }
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : nrf51822TimGetIRQn
/// @param      : TIMx the instance of the timer
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2020-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE ksIsrChn nrf51822TimGetIRQn(ksTIM_t *pTimer)
{
  switch (pTimer->bus)
  {
    case is_tim00 :
      pTimer->GE_isr.id  =
      pTimer->UP_isr.id  = TIMER0_IRQn;
    break;

    case is_tim01 :
      pTimer->GE_isr.id  =
      pTimer->UP_isr.id  = TIMER1_IRQn;
    break;

    case is_tim02 :
      pTimer->GE_isr.id  =
      pTimer->UP_isr.id  = TIMER2_IRQn;
    break;

    default :
      __KS_FORCE_ASSERT(__ASSERT_NOT_HAPPEN);
  }

  return pTimer->GE_isr.id ;
}

ksRet_t nrf51822TimGetInfo            (ksTIM_t  *pTimer);
/*******************************************************************************
*                              efm32TGxxTimClkSw()
* Description : This function config the RCC of TIMx.
* Argument(s) : TIMx_perigh_id : __STM32F1x_PERIPH_ID_TIMx, where x can be 1 to 17 to
*                                select the TIMx peripheral.
*               RCC_Status      :   RCC_Enable  : Turn on RCC
*                                   RCC_Disable : Turn off RCC
* Return(s)   : 0: failure； 1: success
* Caller(s)   : Any Routine.
* Note(s)     : Not Tested
*******************************************************************************/
void    nrf51822TimerClkSw            (ksTIM_t *pTimer, ksTIM_State_e TIM_State);
ksRet_t nrf51822TimerInit             (ksTIM_t  *pTimer);

ksRet_t nrf51822TimerIntervalInitNew  (ksTIM_t  *pTimer,
                                       ksU32    tickPerCycle,
                                       ksU32    tickPerSec);

ksRet_t nrf51822TimerUnitIntervalInit (ksTIM_t  *pTimer,
                                       ksU32    tickPerInterval,
                                       ksU32    tickPerSec);

#endif // (defined __MCU_TYPE)        && \
          (defined _MCU_IS_NRF51822) && \
          (__MCU_TYPE == _MCU_IS_NRF51822)

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_09_TIMER_1_PHY_NRF51822_INC_TIMER_NRF51822_INIT_H_kensky_2020__
