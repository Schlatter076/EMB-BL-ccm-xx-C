////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "algFilter.h"
/// * Author  : kensky
/// * Version :
/// * Date    : Jun 1, 2020
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_DATASTRUCT_ALGORITHM_INC_ALGFILTER_H_KENSKY_2020__
#define __LIBS_DATASTRUCT_ALGORITHM_INC_ALGFILTER_H_KENSKY_2020__

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
#include  "../../Queue/inc/yk_cycQueue.h"

dsU32 weighedMaFilter (cycQ_t *pFilterQ, dsU32 *pSum, dsU32 newData);
dsS32 rcFilter        (dsS32 newData, dsS32 filtered, dsU32 factor);

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_DATASTRUCT_ALGORITHM_INC_ALGFILTER_H_KENSKY_2020__
