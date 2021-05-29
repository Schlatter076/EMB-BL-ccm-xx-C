////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "archCM3.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2014-12-31
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_FC_ARCH_INC_ARCHCM3_H_KENSKY_2014__
#define __LIBS_KSPERIPH_FC_ARCH_INC_ARCHCM3_H_KENSKY_2014__

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
typedef     unsigned char       ksU08;
typedef     unsigned short      ksU16;
typedef     unsigned long       ksU32;
typedef     unsigned long long  ksU64;

typedef     volatile ksU08      ksVU08;
typedef     volatile ksU16      ksVU16;
typedef     volatile ksU32      ksVU32;
typedef     volatile ksU64      ksVU64;

typedef     signed char         ksS08;
typedef     signed short        ksS16;
typedef     signed long         ksS32;
typedef     signed long long    ksS64;

typedef     volatile ksS08      ksVS08;
typedef     volatile ksS16      ksVS16;
typedef     volatile ksS32      ksVS32;
typedef     volatile ksS64      ksVS64;

typedef     char                ksChar;
typedef     ksU32               ksPtrSize;
typedef     ksU32               ksAddr_t;
typedef     ksU32               ksUintFast_t;

typedef     ksS32               ksRet_t;

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_FC_ARCH_INC_ARCHCM3_H_KENSKY_2014__
