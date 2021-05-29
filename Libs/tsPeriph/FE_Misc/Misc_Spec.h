////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "Misc_Spec.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __MISC_SPEC_H_KENSKY_2012_11_23
#define __MISC_SPEC_H_KENSKY_2012_11_23

/**** Includes ****************************************************************/
#include "../ksPeriphSpec.h"

/**** Global Data Types *******************************************************/
typedef enum
{
  numsys_02 = 0x0002,
  numsys_08 = 0x0008,
  numsys_10 = 0x000a,
  numsys_16 = 0x0010,
} numsys_e;

#define     _IS_NUMSYS_E(N)     (((N) == numsys_02) || \
                                 ((N) == numsys_08) || \
                                 ((N) == numsys_10) || \
                                 ((N) == numsys_16)    \
                                 )

#endif // __MISC_SPEC_H_KENSKY_2012_11_23
