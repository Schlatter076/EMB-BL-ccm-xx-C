/*******************************************************************************
  * File    :  Timer.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-17
  * Brief   :  
*******************************************************************************/
#ifndef __TIMER_H_KENSKY_2020_9_17
#define __TIMER_H_KENSKY_2020_9_17

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/Timer_DDL.h"

/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: ksTimerIntervalInit
*  Paras    : TIM           :
*             _us_per_Cycle :
*  Returns  : Status
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
ksS32 ksTimerIntervalInit (ksTIM_t *pTimer,  ksU32 _us_per_Cycle);

/*******************************************************************************
*  Func_Name: ksTimerInit
*  Paras    : TIM
*  Returns  :
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
ksS32 ksTimerInit         (ksTIM_t *pTimer);

/*******************************************************************************
*  Func_Name: ksTimerGetInfo
*  Paras    : TIM       :
*             Timer_Freq: TIMx的时钟频率（并非其工作分频频率），单位为Hz
*  Returns  : Timer Status
*  Brief    : 通过TIMx_periph_id获取TIMx的基本信息，主要包含TIMx编号和TIMx的时钟分频信息
*  Build on :
*  Note     :
*******************************************************************************/
ksS32 ksTimerGetInfo      (ksTIM_t *pTimer);

/*******************************************************************************
*                            ksTimerClkSw()
* Description : This function configs the RCC of TIMx.
* Argument(s) : pTimer    : the instance of the timer to be handled
*               isEnabled : the new state of the timer
*                           TIM_Disbale  : Turn on the timer
*                           TIM_Enable   : Turn off the timer
* Return(s)   : 0: Fail； 1: Success
* Caller(s)   : Any Routine.
* Note(s)     : Not Tested
*******************************************************************************/
__STATIC_INLINE void ksTimerClkSw(ksTIM_t *pTimer, ksTIM_State_e newState)
{
#if 	(__MCU_TYPE == _MCU_IS_STM32F10x)
  stm32f10x_TIM_Clk(pTimer, newState);
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
  stm32l1xTimClkSw(pTimer, newState);
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
  stm32l0xTimClkSw(pTimer, newState);
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
  efm32TGxxTimClkSw(pTimer, newState);
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
  efm32TGxxTimClkSw(pTimer, newState);
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)

#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif ((__MCU_TYPE == _MCU_IS_NRF51822) || ((__MCU_TYPE == _MCU_IS_NRF52832)))
  nrf51822TimerClkSw(pTimer, newState);
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif
}

ksIsrChn ksTimerGetIRQn(ksTIM_t *pTimer, ksU32 IRQ_Flag);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksTimerAlarmSet
/// @param      : TIM
///               @arg  TIM
///               @arg  us
/// @return     : description of return value.
/// @brief      : make the timer initiate an alarm every us period
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : after this setting, the timer is running in a mode that each
///               tick represents n times of us

////////////////////////////////////////////////////////////////////////////////
ksS32 ksTimerAlarmSet (ksTIM_t *pTimer, ksU32 us);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksTimerAlarmSetUnit
/// @param      : p_arg
///               @arg  TIM
///               @arg  us
/// @return     : description of return value.
/// @brief      : make the timer initiate an alarm every us period
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : after this setting, the timer is running in a mode that each
///               tick represents n times of us

////////////////////////////////////////////////////////////////////////////////
ksS32 ksTimerAlarmSetUnit (ksTIM_t  *pTimer, ksU64 expectedTicks, ksU64 ticksPerSec);


////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksTimerSwitch
/// @param      : pTimer   : the timer instance
/// @param      : newState :
/// @return     : NONE
/// @brief      : switch the working status of the timer.
/// @author     : kensky
/// @date       : 2020-4-26
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.////////////////////////
void ksTimerSwitch (ksTIM_t *pTimer, ksTIM_status_e newState);


#endif // __TIMER_H_KENSKY_2020_9_17
