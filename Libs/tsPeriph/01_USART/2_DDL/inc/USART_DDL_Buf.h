/*******************************************************************************
  * File    :  USART_DDL_Buf.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-22
  * Brief   :  
*******************************************************************************/
#ifndef __USART_DDL_BUF_H_KENSKY_2012_9_22
#define __USART_DDL_BUF_H_KENSKY_2012_9_22

/**** Includes ****************************************************************/
#include "../../1_PHY/Common/inc/USART_PHY.h"

/**** Defines *****************************************************************/
#define     __LOCK_UBUF(buf)                st(buf.bufLocked = 1;)
#define     __UNLOCK_UBUF(buf)              st(buf.bufLocked = 0;)
#define     __UBUF_is_LOCK(buf)             (buf.bufLocked == 1)
#define     __UBUF_is_FULL(Q, Qn, Qt)       (_DS_is_EMPTY == Queue_is_Full((Q), (Qn), (Qt)))
#define     __UBUF_is_EMPTY(Q, Qn, Qt)      (_DS_is_EMPTY == Queue_is_Empty((Q), (Qn), (Qt)))
#define     __USART_QUEUE                   Queue1
#define     __USART_ElementType             __Q1_ITEM

/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: USART_DDL_WR_Buf
*  Paras    : pBuf      : pointer to usart buffer, the type should be matched
*                         with the data.
*             pData     : pointer to data to be written into the buffer (>=9 bits)
*  Returns  :
*  Brief    :
*  Build on :
*  Note     : USART_WR_into_Buf only cares whether the buffer is full or not.
*             when usart_Buf->freeBuf == 0, the buffer is used up, the routine
*             should wait send action to recover some more buffer.
*******************************************************************************/
__STATIC_INLINE void USART_DDL_WR_Buf(uint16_t *pBuf, uint16_t *pData)
{
  *pBuf = *pData;
}

/*******************************************************************************
*  Func_Name: USART_DDL_RD_Buf
*  Paras    : pBuf      : pointer to usart buffer, the type shoule be matched
*                         with the data.
*             pData     : pointer to data to be written into the buffer (>=9 bits)
*  Returns  :
*  Brief    :
*  Build on :
*  Note     : USART_WR_into_Buf only cares whether the buffer is full or not.
*             when usart_Buf->freeBuf == 0, the buffer is used up, the routine
*             should wait send action to recover some more buffer.
*******************************************************************************/
__STATIC_INLINE void USART_DDL_RD_Buf(uint16_t *pBuf, uint16_t *pData)
{
  *pData = *pBuf;
}

/*******************************************************************************
*  Func_Name: USART_Send_Buf
*  Paras    : USARTn    : 1,2,3,4,5.. for different architecture
*             pBuf      : pointer to usart buffer, the type shoule be matched
*                         with the data.
*  Returns  :
*  Brief    :
*  Build on :
*  Note     : USART_WR_into_Buf only cares whether the buffer is full or not.
*             when usart_Buf.freeBuf == 0, the buffer is used up, the routine
*             should wait send action to recover some more buffer.
*******************************************************************************/
void USART_Send_Buf(ksUSART_t *USART, uint16_t *pBuf);
/**** Global Data Types *******************************************************/

/**** Global Variables ********************************************************/

#endif // __USART_DDL_BUF_H_KENSKY_2012_9_22
