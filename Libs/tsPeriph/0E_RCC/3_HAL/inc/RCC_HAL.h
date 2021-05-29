////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "RCC_HAL.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __RCC_HAL_H_KENSKY_2013_3_26
#define __RCC_HAL_H_KENSKY_2013_3_26

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/RCC_DDL.h"

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : kskRccConfigAHB
/// @param      : p_arg     description of param
///               @arg  AHB_CLK
///               @arg  arg_2
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
void kskRccConfigAHB(ksU32 AHB_CLK);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksRccGetPrescaler
/// @param      : p_arg     description of param
///               @arg  MCU_Prescaler
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
void ksRccGetPrescaler(ksRCC_PreScale_t *MCU_Prescaler);

#endif // __RCC_HAL_H_KENSKY_2013_3_26
