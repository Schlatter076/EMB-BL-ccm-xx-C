////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "LPWR_Spec.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LPWR_SPEC_H_KENSKY_2013_3_27
#define __LPWR_SPEC_H_KENSKY_2013_3_27

/**** Includes ****************************************************************/
#include "../ksPeriphSpec.h"

/**** Global Data Types *******************************************************/
#pragma pack(1)
typedef enum
{
  ykWkupByIrq   = 0x01,
  ykWkupByEvt   = 0x02,
} ksWkupMode_e;
#pragma pack()

typedef struct
{
  ksWkupMode_e wkupMode;
} ksLowPwr_t;

#endif // __LPWR_SPEC_H_KENSKY_2013_3_27
