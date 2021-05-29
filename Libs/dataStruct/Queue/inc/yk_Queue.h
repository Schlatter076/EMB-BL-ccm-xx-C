/*******************************************************************************
  * File    :  yk_Queue.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-10
  * Brief   :  
*******************************************************************************/
#ifndef __YK_QUEUE_H_KENSKY_2012_9_10
#define __YK_QUEUE_H_KENSKY_2012_9_10

/**** Includes ****************************************************************/
#include "./yk_cycQueue.h"

/**** Defines *****************************************************************/
#define     __DS_Q_Init(q, buf, uds, qs)        ksCycQueueCreatebySize((q), (buf), (uds), (qs))
#define     __DS_Q_Destroy(q, qs)               st(ksCycQueueDestroy((q), (qs));)
#define     __DS_Q_Clear(q)                     st(ksCycQueueClear((q));)
#define     __DS_Q_is_Empty(q)                  ksCycQueueIsEmpty((q))
#define     __DS_Q_is_Full(q)                   ksCycQueueIsFull((q))
#define     __DS_Q_WR(q, pData, uds)            ksCycQueuePutData((q), (pData),(uds))
#define     __DS_Q_RD(q, pBuf, uds)             ksCycQueuePopData((q), (pBuf), (uds))
#define     __DS_Q_POP(q)                       st(ksCycQueueMoveToNext((q));) // POP one data unit without using it
#define     __DS_Q_PEEK(q, pBuf, uds)           ksCycQueuePeekData((q), (pBuf), (uds))
#define     __DS_Q_SEND(q,ch,dt,len,rt)         ksCycQueueSend((q),(ch),(dt),(len),(rt))
#define     __DS_Q_GET_HEAD(q)                  ksQ_GetHead((q))

/**** Global Data Types *******************************************************/
typedef     cycQ_t      Queue;

/***** Function Prototypes ****************************************************/

#endif // __YK_QUEUE_H_KENSKY_2012_9_10
