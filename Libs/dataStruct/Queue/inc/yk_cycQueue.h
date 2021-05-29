/*******************************************************************************
  * File    :  yk_cycQueue.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-20
  * Brief   :  FIFO, cicular queue
*******************************************************************************/
#ifndef __YKQUEUE_H_KENSKY_2012_9_20
#define __YKQUEUE_H_KENSKY_2012_9_20

/**** Includes ****************************************************************/
#include    "../../DS_cfg.h"
#include    "./yk_Queue_Spec.h"

/**** Global Data Types *******************************************************/
/*******************************************************************************
*  Type_Name : cycQ_t
*  Elements  : base         : pointer to the buffer of the queue(not the queue)
*              qsize        : the size of the queue buffer
*              head         : the head position of the queue buffer
*              tail         : the tail position of the queue buffer
*              used         : the buffer used
*              userDataSize : the size of the user data type
*  Brief     :
*******************************************************************************/
typedef struct
{
  void  *base;
  dsU32 qsize;
  dsU32 head;
  dsU32 tail;
  dsU32 used;
  dsU08 locked;
  dsU32 userDataSize;
} cycQ_t;

/***** Function Prototypes ****************************************************/
int ksCycQueueInit(cycQ_t *q, dsU32 userDataSize, dsU32 Qsize, void *buffer);

/*******************************************************************************
*  Func_Name: ksCycQueueCreatebySize
*  Paras    : userDataSize  : the size of the user data type
*             Qsize         : the size of the queue buffer
*             strategy      : malloc strategy
*  Returns  : if successful, return the pointer of the queue, or else, return NULL
*  Brief    : Create a cyclic queue according to the userDataSize & Qsize
*  Build on :
*  Note     :
*******************************************************************************/
cycQ_t* ksCycQueueCreatebySize(cycQ_t *q, void *pBuf, dsU32 userDataSize, dsU32 Qsize);

/*******************************************************************************
*  Func_Name: ksCycQueueDestroy
*  Paras    : q     : pointer to the queue
*             Qsize : the size of the queue buffer
*  Returns  : _DS_SUCCESSFUL for ok, _DS_ERROR for error
*  Brief    : Destroy a queue
*  Build on :
*  Note     :
*******************************************************************************/
int ksCycQueueDestroy(cycQ_t *q, dsU32 Qsize);

/*******************************************************************************
*  Func_Name: ksCycQueueClear
*  Paras    : q : pointer to the queue
*  Returns  : _DS_SUCCESSFUL for ok
*  Brief    : Clear everything in a queue, and make it empty again
*  Build on :
*  Note     : ??
*******************************************************************************/
int ksCycQueueClear  (cycQ_t * q);

/*******************************************************************************
*  Func_Name: Queue_is_Empty
*  Paras    : q : pointer to the queue
*  Returns  : 1 for Q is empty, 0 for Q is not empty
*  Brief    : Check if the Queue is empty
*  Build on :
*  Note     :
*******************************************************************************/
#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
__STATIC_INLINE int ksCycQueueIsEmpty (cycQ_t *q)
{
  return ((NULL == q) ?  0 : (0 == q->used));
}

/*******************************************************************************
*  Func_Name: ksCycQueueIsFull
*  Paras    : q : pointer to the queue
*  Returns  : 0 for Q is not full, 1 for Q is full
*  Brief    : Check if the Queue is full
*  Build on :
*  Note     :
*******************************************************************************/
__STATIC_INLINE dsU08 ksCycQueueIsFull (cycQ_t *q)
{
  return ((NULL == q) ? 0 : !!(q->used >= q->qsize));
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksCycQueueMoveToNext
/// @param      : q :the instance of the queue
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-4-26
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
/// @deprecated : add deprecated reason.
////////////////////////////////////////////////////////////////////////////////
void  ksCycQueueMoveToNext(cycQ_t *q);

/*******************************************************************************
*  Func_Name: ksCycQueuePutData
*  Paras    : q     : pointer to the queue
*  Returns  : data  : pointer to the user data
*  Brief    : write data into the queue buffer
*  Build on :
*  Note     :
*******************************************************************************/
int   ksCycQueuePutData (cycQ_t *q, const void *pData, dsU32 dataSize);

/*******************************************************************************
*  Func_Name: ksCycQueuePeekData
*  Paras    : q : pointer to the queue
*             data : user buf, which is used to sotre the data fetch from the
*             queue
*  Returns  : _DS_SUCCESSFUL for ok, _DS_ERROR for error
*  Brief    : fetch and remove the head element in the queue
*  Build on :
*  Note     :
*******************************************************************************/
int   ksCycQueuePeekData(cycQ_t *q, void *pRdBuf, dsU32 dataSize);

/*******************************************************************************
*  Func_Name: ksCycQueuePopData
*  Paras    : q : pointer to the queue
*             data : user buf, which is used to store the data fetch from the
*             queue
*  Returns  : _DS_SUCCESSFUL for ok, _DS_ERROR for error
*  Brief    : fetch and remove the head element in the queue
*  Build on :
*  Note     :
*******************************************************************************/
int   ksCycQueuePopData(cycQ_t *q, void *pRdBuf, dsU32 dataSize);
void* ksQ_GetHead (cycQ_t *q);
void* ksQ_GetTail (cycQ_t *q);

/*******************************************************************************
*  Func_Name: ksCycQueueSend
*  Paras    : q             : pointer to the queue
*             chn           :  some routine may have this argument to specify
*             which channel is used to send the data
*             len           : how many data should be transmitted
*             datatype      : the type of the data
*             send_routine  : call backs to send the data in q buffer
*  Returns  : _DS_SUCCESSFUL for OK, _DS_ERROR for error
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
int   ksCycQueueSend(cycQ_t      *q,        dsU08   chn,
                     data_type_e datatype,  dsU32    len,
                     pQsend      send_routine);

#endif // __YKQUEUE_H_KENSKY_2012_9_20
