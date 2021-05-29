////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "rvArch.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __RVARCH_H_KENSKY_2014
#define __RVARCH_H_KENSKY_2014

//*****************************************************************************
#ifdef  __cplusplus
//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
extern "C"
{
#endif // __cplusplus

/**** Includes ****************************************************************/

/**** Global Data Types *******************************************************/
#if (__MCU_ADDR_SPACE == _MCU_IS_32_BITS)

typedef     unsigned char       dsU08;
typedef     unsigned short      dsU16;
typedef     unsigned int        dsU32;
typedef     unsigned long long  dsU64;

typedef     signed   char       dsS08;
typedef     signed   short      dsS16;
typedef     signed   int        dsS32;
typedef     signed   long long  dsS64;

typedef     char                dsChar;

typedef     dsU32               dsPtrSize;
typedef     dsU32               dsAddr_t;
typedef     dsU32               dsUintFast_t;

#elif (__MCU_ADDR_SPACE == _MCU_IS_64_BITS)

typedef     unsigned char       dsU08;
typedef     unsigned short      dsU16;
typedef     unsigned int        dsU32;
typedef     unsigned long long  dsU64;

typedef     signed   char       dsS08;
typedef     signed   short      dsS16;
typedef     signed   int        dsS32;
typedef     signed   long long  dsS64;

typedef     char                dsChar;

typedef     dsU64               dsPtrSize;
typedef     dsU64               dsAddr_t;
typedef     dsU64               dsUintFast_t;

#else
#endif

typedef union
{
  dsU08 ui08[sizeof(dsU32)/sizeof(dsU08)];
  dsU16 ui16[sizeof(dsU32)/sizeof(dsU16)];
  dsU32 ui32;
  dsU32 uAll;

  dsS08 si08[sizeof(dsS32)/sizeof(dsS08)];
  dsS16 si16[sizeof(dsS32)/sizeof(dsS16)];
  dsS32 si32;
  dsS32 sAll;
} dsInt_u;

typedef   dsS32   ksStackSize_t; // make sure it's signed type
typedef   dsS32   ksDlistSize_t;
typedef   dsS32   ksHashSize_t;
typedef   dsU32   ksFifoSize_t;

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __RVARCH_H_KENSKY_2014
