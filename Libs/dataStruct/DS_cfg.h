/*******************************************************************************
  * File    :  DS_cfg.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-9
  * Brief   :  
*******************************************************************************/
#ifndef __DS_CFG_H_KENSKY_2020_9_9
#define __DS_CFG_H_KENSKY_2020_9_9

/**** Includes ****************************************************************/
#include <DS_Spec.h>
#include <projCfg.h>
#include "./retVal/inc/u_return_value.h"
#include "./arch/rvArch.h"
// #include "./arch/stdarg.h"

#if !defined(__MCU_ADDR_SPACE) || !defined(_MCU_IS_32_BITS) || !defined(_MCU_IS_64_BITS)
#error "MACROS UNDEFINED"
#endif

#include "./retVal/inc/kserrno.h"

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

#ifndef _uuidCheck
#define     _uuidCheck()  // override the global uuid checking routine
#endif

/**** DS Module Switch ********************************************************/
#define     __QUEUE_MODULE      (_DS_MODULE_is_ON)
#define     __STACK_MODULE      (_DS_MODULE_is_OFF)
#define     __LLST_MODULE       (_DS_MODULE_is_ON)
#define     __MEMPOOL_MODULE    (_DS_MODULE_is_ON)
#define     __STRING_MODULE     (_DS_MODULE_is_OFF)

#if __MEMPOOL_MODULE == _DS_MODULE_is_ON
#include    "./mem_pool/inc/ykMemPool.h"
#endif

/**** Defines *****************************************************************/
#define     __DS_Malloc(n)      POOLMALLOC((n))  // which malloc should be used
#define     __DS_Free(p, n)     POOLFREE(p,n)    // which free should be used

#ifndef NULL
  #define NULL  0
#endif /* NULL */

/**** Global Data Types *******************************************************/

/**** Queue Module Configurations *********************************************/

#ifdef  __cplusplus
//******************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//******************************************************************************
}
#endif // __cplusplus

#endif // __DS_CFG_H_KENSKY_2020_9_9
