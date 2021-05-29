/*******************************************************************************
  * File    :  USART_SendByte.h
  * Author  :  kensky
  * Version :
  * Date    :  2020-9-16
  * Brief   :
*******************************************************************************/
#ifndef __USART_SENDBYTE_H_KENSKY_2012_9_16
#define __USART_SENDBYTE_H_KENSKY_2012_9_16

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/USART_DDL.h"

/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: ksUsartSendU08
*  Paras    : USARTn :
*             byte   :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
void ksUsartSendU08(ksUSART_t *pUsart, uint16_t Byte);

#endif // __USART_SENDBYTE_H_KENSKY_2012_9_16
