/*******************************************************************************
  * File    :  DataStruct.h
  * Author  :  kensky
  * Version :
  * Date    :  2020-9-10
  * Brief   :
*******************************************************************************/
#ifndef __DATASTRUCT_H_KENSKY_2020_9_10
#define __DATASTRUCT_H_KENSKY_2020_9_10

/**** Includes ****************************************************************/
#include    "./DS_cfg.h"

#if (defined __QUEUE_MODULE) && (__QUEUE_MODULE == _DS_MODULE_is_ON)
#include    "./Queue/inc/yk_Queue.h"
#include 		"./ksFifo/inc/ksFifo.h"
#endif

#if (defined __STRING_MODULE) && (__STRING_MODULE == _DS_MODULE_is_ON)
#include    "./string/inc/u_str_fun.h"
#endif

#if (defined __STACK_MODULE) && (__STACK_MODULE == _DS_MODULE_is_ON)
#include    "./Stack/inc/yk_Stack.h"
#endif

#if (defined __LLST_MODULE) && (__LLST_MODULE == _DS_MODULE_is_ON)
#include    "./LnkList/inc/Du_Linked_List.h"
#include    "./ksList/inc/ksDuLinkedList.h"
#endif

#include    "./ksHash/inc/ksHashMap.h"

#if (defined __MEMPOOL_MODULE) && (__MEMPOOL_MODULE == _DS_MODULE_is_ON)
#include    "./mem_pool/inc/ykMemPool.h"
#endif

#include    "./misc/inc/miscellaneous.h"

/**** algorithm ***************************************************************/
#include    "./algorithm/inc/ksMD5.h"
#include    "./algorithm/inc/sha256.h"
#include    "./algorithm/inc/crc16.h"
#include    "./algorithm/inc/crc32.h"

#include    "algorithm/miniLZO/inc/minilzo.h"
#include    "algorithm/inc/cubicSmoothFilter.h"
#include    "algorithm/inc/algSearch.h"
#include    "algorithm/inc/algFilter.h"

#endif // __DATASTRUCT_H_KENSKY_2020_9_10
