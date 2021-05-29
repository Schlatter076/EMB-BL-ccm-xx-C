////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "math.h"
/// * Author  : yangken
/// * Version :
/// * Date    : May 23, 2017
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_DATASTRUCT_ALGORITHM_INC_MATH_H_YANGKEN_2017__
#define __LIBS_DATASTRUCT_ALGORITHM_INC_MATH_H_YANGKEN_2017__

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
#include <stdint.h>

/***** Function Prototypes ****************************************************/
int ksGCD (int x, int y);

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_DATASTRUCT_ALGORITHM_INC_MATH_H_YANGKEN_2017__
