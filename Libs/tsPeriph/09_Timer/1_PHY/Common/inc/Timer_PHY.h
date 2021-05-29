/*******************************************************************************
  * File    :  Timer_PHY.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-24
  * Brief   :  
*******************************************************************************/
#ifndef __TIMER_PHY_H_KENSKY_2020_9_24
#define __TIMER_PHY_H_KENSKY_2020_9_24

/**** Includes ****************************************************************/
#include    <stdlib.h>
#include    "../../../4_CFG/Timer_cfg.h"

#if   (__MCU_TYPE == _MCU_IS_STM32F10x)
#include "../../STM32_F10x/inc/Timer_STM32F10x.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#include "../../STM32L1xx/inc/Timer_STM32L1x.h"

#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)

#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#include "../../STM32L0xx/inc/Timer_STM32L0xx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#include "../../EFM32TGxx/inc/Timer_EFM32TGxx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
#include "../../EFM32TGxx/inc/Timer_EFM32TGxx.h"
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#include "../../NRF51822/inc/Timer_NRF51822.h"
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#include "../../NRF51822/inc/Timer_NRF51822.h"
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#include "../../EFR32yGxx/inc/Timer_EFR32yGxx.h"
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// @fn         : Init_ykTIM_Struct
/// @param      : p_arg
///               @arg  TIM_Struct        ::
///               @arg  Prescaler         ::
///               @arg  Mode              ::
///               @arg  Period            ::
///               @arg  ClkDiv            ::
///               @arg  RepetitionCounter ::
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-11-13
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
void Init_ykTIM_Struct (ksTIM_para_t  *TIM_Struct,
                        ksU32         Prescaler,
                        ksU16         Mode,
                        ksU32         Period,
                        ksU16         ClkDiv,
                        ksU08         RepetitionCounter);

#endif // __TIMER_PHY_H_KENSKY_2020_9_24
