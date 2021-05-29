/*******************************************************************************
  * File    :  NVIC.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-29
  * Brief   :  
*******************************************************************************/
#ifndef __NVIC_H_KENSKY_2020_9_29
#define __NVIC_H_KENSKY_2020_9_29

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/NVIC_DDL.h"

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksNvicIsOn
/// @param      : IRQn :
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.

////////////////////////////////////////////////////////////////////////////////
ksNvicStatus_e ksNvicIsOn(ksIsrChn IRQn);

/*******************************************************************************
*  Func_Name: ksNvicVectblConfig
*  Paras    : vect_location : _NVIC_VECT_TAB_RAM || _NVIC_VECT_TAB_FLASH
*  Returns  : 0 for OK, -1 for mismatched argument
*  Brief    : set the vector table  base location at RAM or Flash
*  Build on :
*  Note     :
*******************************************************************************/
int ksNvicVectblConfig(unsigned char vect_location);

/*******************************************************************************
*  Func_Name: ksNvicPrioGrpCfg
*  Paras    : Priority_Group :
*  Returns  : none
*  Brief    : set NVIC Priority group
*  Build on :
*  Note     :
*******************************************************************************/
void ksNvicPrioGrpCfg(ksU32 Priority_Group);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksNvicGpioConfig
/// @param      : p_arg     description of param
///               @arg  Pin_Num
///               @arg  PrePriority
///               @arg  SubPriority
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.

////////////////////////////////////////////////////////////////////////////////
ksS08  ksNvicGpioConfig(ksU08 Pin_Num,
                        ksU08 PrePriority,
                        ksU08 SubPriority);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksNvicEnable
/// @param      : IRQn : the irq channel
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.

////////////////////////////////////////////////////////////////////////////////
#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
void ksNvicEnable(ksIsrChn IRQn);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksNvicSwReset
/// @param      : p_arg
/// @return     : description of return value.
/// @brief      : generate a software system reset
/// @author     : kensky
/// @date       : 2014-2-27
/// @pre        : add precondition here if needed.
/// @note       : tested ok for STM32L
////////////////////////////////////////////////////////////////////////////////
#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
void ksNvicSwReset();

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksNvicDisable
/// @param      : IRQn : the irq channnel
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.

////////////////////////////////////////////////////////////////////////////////
#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
void ksNvicDisable(ksIsrChn IRQn);

void ksNvicClear (ksIsrChn IRQn);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksNvicInit
/// @param      : p_arg     description of param
///               @arg  IRQn
///               @arg  PrePriority
///               @arg  SubPriority
///               @arg  NVIC_State
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.

////////////////////////////////////////////////////////////////////////////////
void ksNvicInit(ksIsrChn       IRQn,
                 ksU08         PrePriority,
                 ksU08         SubPriority,
                 ksNvicStatus_e NVIC_State);

#endif // __NVIC_H_KENSKY_2020_9_29
