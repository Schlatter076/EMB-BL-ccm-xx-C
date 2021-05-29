////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "smooth_5_3_filert.h"
/// * Author  : kensky
/// * Version :
/// * Date    : Jun 1, 2020
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_DATASTRUCT_ALGORITHM_INC_SMOOTH_5_3_FILERT_H_KENSKY_2020__
#define __LIBS_DATASTRUCT_ALGORITHM_INC_SMOOTH_5_3_FILERT_H_KENSKY_2020__

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

/***
 * cubicSmooth5
 * @param in  : data to be smoothed
 * @param out : the data filtered
 * @param N   : the size of the data
 */
void cubicSmooth5 (double in[], double out[], int N);

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_DATASTRUCT_ALGORITHM_INC_SMOOTH_5_3_FILERT_H_KENSKY_2020__
