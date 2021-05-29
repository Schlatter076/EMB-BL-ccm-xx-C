////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "miscellaneous.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __MISCELLANEOUS_H_KENSKY_2012_12_15
#define __MISCELLANEOUS_H_KENSKY_2012_12_15

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
#include "../../arch/rvArch.h"
#include <DS_Spec.h>

/***** Function Prototypes ****************************************************/
dsU32   uint32_mask_set         (dsU32 value,  dsU32 mask,  dsU32 set);
void    uint32_mask_set_pointer (dsU32 *value, dsU32 mask,  dsU32 set);
dsU32   uint32_mask_set_shift   (dsU32 value,  dsU32 shift, dsU32 mask, dsU32 set);
dsS08   getExponentof2          (dsU32 m);
dsS32   uint32_comp             (dsU32 v1,     dsU32 v2);
dsS32   uint64_comp             (dsU32 v1_l,   dsU32 v1_h,  dsU32 v2_l, dsU32 v2_h);
void    uint64_add              (dsU32 *v1_l,  dsU32 *v1_h, dsU32 v2_l, dsU32 v2_h);

                                 #ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __MISCELLANEOUS_H_KENSKY_2012_12_15
