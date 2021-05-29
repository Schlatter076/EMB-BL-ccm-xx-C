/*******************************************************************************
  * File    :  Timer_cfg.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-17
  * Brief   :  
*******************************************************************************/
#ifndef __TIMER_CFG_H_KENSKY_2012_9_17
#define __TIMER_CFG_H_KENSKY_2012_9_17

/**** Includes ****************************************************************/
#include    <09_Timer/Timer_Spec.h>

#ifndef __MCU_TYPE
#error please define the MCU_TYPE
#endif

#if (__MCU_TYPE != _MCU_IS_ESP8266)
#include    <0E_RCC/RCC_Driver.h>
#endif // (__MCU_TYPE != _MCU_IS_ESP8266)

#endif // __TIMER_CFG_H_KENSKY_2012_9_17
