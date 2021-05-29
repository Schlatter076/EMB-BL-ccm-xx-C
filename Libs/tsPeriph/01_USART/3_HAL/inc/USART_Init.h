/*******************************************************************************
  * File    :  USART_Init.h
  * Author  :  kensky
  * Version :
  * Date    :  2020-9-7
  * Brief   :
*******************************************************************************/
#ifndef __USART_INIT_H_KENSKY_2020_9_7
#define __USART_INIT_H_KENSKY_2020_9_7

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/USART_DDL.h"

/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: ksUsartInit
*  Paras    : USART
*  Returns  : USART Status
*  Brief    : Initialize the USART Interfaces
*  Build on :
*  Note     :
*******************************************************************************/
ksS32 ksUsartInit     (ksUSART_t *pUsart);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ykUsartGetIsrId
/// @param      : USART
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-6-23
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.

////////////////////////////////////////////////////////////////////////////////
void ksUsartGetIsrId  (ksUSART_t *pUsart);

/**
 * @fn ksUsartSwitch
 * @param pUsart    : the instance of ksUSART
 * @param isEnabled : whether the instance is enabled or not
 */
void ksUsartSwitch    (ksUSART_t *pUsart, bool isEnabled);

/**
 * @fn ksUsartStart
 * @param pUsart
 */
void ksUsartStart     (ksUSART_t *pUsart);

/**
 * @fn ksUsartStop
 * @param pUsart
 */
void ksUsartStop      (ksUSART_t *pUsart);

#endif // __USART_INIT_H_KENSKY_2020_9_7
