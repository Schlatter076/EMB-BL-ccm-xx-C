////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "Protection_Spec.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __PROTECTION_SPEC_H_KEN_2013_9_25
#define __PROTECTION_SPEC_H_KEN_2013_9_25

/**** Includes ****************************************************************/
#include "../ksPeriphSpec.h"

/**** Global Data Types *******************************************************/
typedef union
{
  ksU64   id64[2];
  ksU32   id32[4];
  ksU16   id16[8];
  ksU08   id08[16];
} ksUUID128_u;

#endif // __PROTECTION_SPEC_H_KEN_2013_9_25
