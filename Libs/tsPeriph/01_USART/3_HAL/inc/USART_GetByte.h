/*******************************************************************************
  * File    :  USART_GetByte.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-27
  * Brief   :  
*******************************************************************************/
#ifndef __USART_GETBYTE_H_KENSKY_2012_9_27
#define __USART_GETBYTE_H_KENSKY_2012_9_27

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/USART_DDL.h"

/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: ksUsartGetByte
*  Paras    : USART
*  Returns  : Data Received
*  Brief    : get a byte from the usart
*  Build on :
*  Note     :
*******************************************************************************/
ksU16 ksUsartGetByte(const ksUSART_t *pUSART);

#endif // __USART_GETBYTE_H_KENSKY_2012_9_27
