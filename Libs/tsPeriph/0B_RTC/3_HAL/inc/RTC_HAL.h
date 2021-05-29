////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "RTC_HAL.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __RTC_HAL_H_KENSKY_2013_3_27
#define __RTC_HAL_H_KENSKY_2013_3_27

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/RTC_DDL.h"

/**** Defines *****************************************************************/

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : RTC_Init
/// @param      : p_arg
///               @arg  MCU_RTC
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
int ksRTCInit(ksRTC_t *MCU_RTC);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : RTC_Get_Prescaler
/// @param      : pRTC :
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
void ksRTC_GetPrescaler(ksRTC_t *pRTC);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : RTC_get_IRQn
/// @param      : p_arg     description of param
///               @arg  MCU_RTC
///               @arg  irqSrc
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-4-29
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
ksIsrChn ksRTC_GetIRQn(ksRTC_t *MCU_RTC, ksU08 irqSrc);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksRTC_SetAlarm
/// @param      : p_arg
///               @arg  alrVal
///               @arg  arg_2
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-4-29
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
void ksRTC_SetAlarm (ksRTC_t *pRTC, ksU32 alrVal);

#endif // __RTC_HAL_H_KENSKY_2013_3_27
