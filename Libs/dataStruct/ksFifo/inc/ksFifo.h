////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "ksFifo.h"
/// * Author  : kensky
/// * Version :
/// * Date    : Feb 6, 2014
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __KSFIFO_H_KENSKY_2014
#define __KSFIFO_H_KENSKY_2014

//******************************************************************************
#ifdef  __cplusplus
//******************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
extern "C"
{
#endif // __cplusplus

/**** Includes ****************************************************************/
#include "../../ksBase/inc/ksLog2.h"

/**** Global Data Types *******************************************************/
typedef struct __ksQueue
{
  void          *base;  // the base address of the buffer holding data, type ignored
  ksFifoSize_t	head;		// head(in)  : data is added at offset (in % size)
  ksFifoSize_t	tail;		// tail(out) : data is extracted from off. (out % size)
  ksFifoSize_t	eSize;	// element size in bytes
  ksFifoSize_t  qSize;	// how many elements can be stored into the queue
  ksFifoSize_t  used; 	// how many elements are being used
	dsU08	        locked; // reserved for synchronization
} ksQ_t;

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksQInitByMalloc
/// @param      : pQ    : the queue
/// @param      : eQty  : how many elements
/// @param      : esize : element size in bytes
/// @return     : SUCCESS || EINVAL || ENOMEN
/// @brief      : init the queue buffer by malloc
/// @author     : kensky
/// @date       : Feb 6, 2014
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
int ksQInitByMalloc(ksQ_t *pQ, dsU32 eQty, size_t eSize);

int ksQInit(ksQ_t *q, dsU32 userDataSize, dsU32 Qsize, void *buffer);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksQDestroy
/// @param      : p_arg
///               @arg  pQ : the queue
/// @return     : SUCCESS || EFAULT
/// @brief      : destroy the queue and retrieve the mem allocated
/// @author     : kensky
/// @date       : Feb 6, 2014
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
int ksQDestroy(ksQ_t *pQ);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksQClear
/// @param      : p_arg
///               @arg  pQ	: the queue
/// @return     : EFAULE or SUCCESS.
/// @brief      : clear the queue without destroying it
/// @author     : kensky
/// @date       : Feb 6, 2014
/// @pre        : add precondition here if needed.
/// @note       : clear the queue without destroying it
////////////////////////////////////////////////////////////////////////////////
int ksQClear(ksQ_t *pQ);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksQisEmpty
/// @param      : p_arg
///               @arg  pQ
/// @return     : false or true
/// @brief      : check if the queue is empty or not
/// @author     : kensky
/// @date       : Feb 6, 2014
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE int ICACHE_FLASH_ATTR ksQisEmpty(ksQ_t *pQ)
{
  return ((NULL == pQ) ? 0 : (0 == pQ->used));
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksQisFull
/// @param      : p_arg
///               @arg  pQ
/// @return     : false or true
/// @brief      : check is the queue is full or not
/// @author     : kensky
/// @date       : Feb 6, 2014
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE int ICACHE_FLASH_ATTR ksQisFull(ksQ_t *pQ)
{
  return ((NULL == pQ) ? 0 : (pQ->used >= pQ->qSize));
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksQMoveToNext
/// @param      : p_arg
///               @arg  pQ
/// @return     : EFAULT || SUCCESS
/// @brief      : move the tail indexer by one, which means one data is being
///								extracted from the queue, and the memory is freed
/// @author     : kensky
/// @date       : Feb 6, 2014
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
int ksQMoveToNext(ksQ_t *pQ);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksQPutData
/// @param      : p_arg
///               @arg  pQ			: the queue
///               @arg  pData		: pointer to the data to be written into
///               @arg  dataSize: how many bytes long the data, should no exceed
///                               the sizeof value of the element
/// @return     : SUCCESS || EBUSY || EFAULT
/// @brief      : put one element into the queue. the data may not have the full
///								length of the element, but should no be greater than that.
/// @author     : kensky
/// @date       : Feb 6, 2014
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
int ksQPutData(ksQ_t *pQ, const void *pData, dsU32 dataSize);

void* ICACHE_FLASH_ATTR ksQPeekPtr(ksQ_t *pQ);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksQPeek
/// @param      : p_arg
///               @arg  pQ			: the queue
///               @arg  pBuf		: bue to get the data read out
///               @arg  dataSize: data length
/// @return     : EFAULT || SUCCESS
/// @brief      : read some or full part of the element, without remove it from
///								the queue
/// @author     : kensky
/// @date       : Feb 6, 2014
/// @pre        : add precondition here if needed.
/// @note       : you can even read just one byte of the data
////////////////////////////////////////////////////////////////////////////////
int ksQPeek(ksQ_t *pQ, void *pBuf, dsU32 dataSize);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksQgetData
/// @param      : p_arg
///               @arg  pQ			: the queue
///               @arg  pBuf		: buffer to get the data read out
///               @arg  dataSize: data length
/// @return     : description of return value.
/// @brief      : read some or full part of the element, and remove it from
///								the queue
/// @author     : kensky
/// @date       : Feb 6, 2014
/// @pre        : add precondition here if needed.
/// @note       : you can even read just one byte of the data
////////////////////////////////////////////////////////////////////////////////
int ksQgetData(ksQ_t *pQ, void *pBuf, dsU32 dataSize);

#ifdef  __cplusplus
//******************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//******************************************************************************
}
#endif // __cplusplus

#endif // __KSFIFO_H_KENSKY_2014
