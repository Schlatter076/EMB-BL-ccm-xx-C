/*******************************************************************************
  * File    :  USART.h
  * Author  :  kensky
  * Version :
  * Date    :  2020-9-17
  * Brief   :
*******************************************************************************/
#ifndef __USART_H_KENSKY_2020_9_17
#define __USART_H_KENSKY_2020_9_17

/**** Includes ****************************************************************/
#include "./USART_Init.h"
#include "./USART_SendBuf.h"
#include "./USART_SendByte.h"
#include "./USART_GetByte.h"
#include "./USART_RegHandle.h"

/**** Defines *****************************************************************/
#define __USART_RECV_is_PENDING(U)      __USART_DDL_RECV_is_PENDING((U))
#define __USART_RECV_not_PENDING(U)     __USART_DDL_RECV_not_PENDING((U))

#endif // __USART_H_KENSKY_2020_9_17
