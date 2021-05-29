/*******************************************************************************
  * File    :  USART_DDL_SendByte.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-22
  * Brief   :  
*******************************************************************************/
#ifndef __USART_DDL_SENDBYTE_H_KENSKY_2012_9_22
#define __USART_DDL_SENDBYTE_H_KENSKY_2012_9_22

/**** Includes ****************************************************************/
#include "../../1_PHY/Common/inc/USART_PHY.h"

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : USART_DDL_SentByte
/// @param      : pUsart
/// @param      : byte
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-9-29
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
int USART_DDL_SentByte(ksUSART_t *pUsart, uint16_t byte);

#endif // __USART_DDL_SENDBYTE_H_KENSKY_2012_9_22
