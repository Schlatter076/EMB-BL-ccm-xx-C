/*******************************************************************************
  * File    :  yk_memPool_cfg.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-10
  * Brief   :  memPool configuration
*******************************************************************************/
#ifndef __YK_MEMPOOL_CFG_H_KENSKY_2012_9_10
#define __YK_MEMPOOL_CFG_H_KENSKY_2012_9_10

/**** Includes ****************************************************************/
#include "./ykMemPoolSpec.h"

/**** Defines *****************************************************************/
/*******************************************************************************
*  Macro_Name : __MEM_POOL_OPTIMAL_SIMPLE_USE
*  Paras	  : _NOTSET_ORIGINAL_BLKSIZE ：the routine will autimatically record
*                   the original block size, it's very safe while use a little
*                   extra memory(sizeof(void*) for each allocation).
*               SET_ORIGINAL_BLKSIZE     ：developer should manuaaly defines the
*                   original block size, and if there is anything wrong, the
*                   memory behavior would be unpredictable, it's not recommended
*  Brief      : define the routine behavior concerning the block size recording
*               there is no double memory consumption when __MEM_POOL_DEBUG and
*               __MEM_POOL_OPTIMAL_SIMPLE_USE are both on
*******************************************************************************/
#define     __MEM_POOL_OPTIMAL_SIMPLE_USE       (_SET_ORIGINAL_BLKSIZE)

/*******************************************************************************
*  Macro_Name : __MEM_POOL_DEBUG
*  Paras	  : _MEMPOOL_DBG_ON：debug mode is on, while a little bit of extra
*                   memory is used (sizeof(void*) for each allocation).
*               _MEMPOOL_DBG_OFF：debug mode is off
*               other valuse also shut the debug mode off
*  Brief      : whether to turn on the debug mode of the mem pool, it is
*               suggestted that we use this mode when developing, while shut it
*               off when releasing the program
*               there is no double memory consumption when __MEM_POOL_DEBUG and
*               __MEM_POOL_OPTIMAL_SIMPLE_USE are both on
*******************************************************************************/
#define     __MEM_POOL_DEBUG                    (_MEMPOOL_DBG_OFF)

/*******************************************************************************
*  Macro_Name : __MEM_POOL_DEFAULT_POOL_SIZE
*  Paras	  : positive integers
*  Brief      : the increment that the mem pool being enlarged, pool size base unit
*******************************************************************************/
#define     __MEM_POOL_DEFAULT_POOL_SIZE        (512ul)

/*******************************************************************************
*  Macro_Name : __MEM_POOL_DEFAULT_ALIGN_SIZE
*  Paras      :
*  Brief      : default width of the alignment
*******************************************************************************/
#define     __MEM_POOL_DEFAULT_ALIGN_SIZE       (sizeof(int))

/*******************************************************************************
*  Macro_Name : __mem_pool_alloc
*  Paras      :
*  Brief      : what the malloc routine will be used?
*******************************************************************************/
#include <stdlib.h>
#define     __mem_pool_alloc(size)              malloc(size)

/*******************************************************************************
*  Macro_Name : __mem_pool_free
*  Paras      :
*  Brief      : what the frre woutine will be used?
*  Note       : basically, the mempool is not designed to be freed under any
*               circumstance
*******************************************************************************/
#define     __mem_pool_free(pbuf)               do{if(pbuf)free(pbuf);}while(0)

#endif // __YK_MEMPOOL_CFG_H_KENSKY_2012_9_10
