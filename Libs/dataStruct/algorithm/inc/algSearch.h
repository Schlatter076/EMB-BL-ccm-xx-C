////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "algSearch.h"
/// * Author  : kensky
/// * Version :
/// * Date    : Jun 1, 2020
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_DATASTRUCT_ALGORITHM_INC_ALGSEARCH_H_KENSKY_2020__
#define __LIBS_DATASTRUCT_ALGORITHM_INC_ALGSEARCH_H_KENSKY_2020__

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
#include "../../DS_cfg.h"

dsS32 ksBinaryInRangeU32 (const dsS32 * const pArray, dsU32 arraySize, dsS32 key);

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_DATASTRUCT_ALGORITHM_INC_ALGSEARCH_H_KENSKY_2020__
