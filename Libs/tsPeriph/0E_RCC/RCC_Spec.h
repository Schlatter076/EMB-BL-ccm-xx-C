////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "RCC_Spec.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __RCC_SPEC_H_KENSKY_2020_3_26
#define __RCC_SPEC_H_KENSKY_2020_3_26

/**** Includes ****************************************************************/
#include "../ksPeriphSpec.h"

/**** Defines *****************************************************************/
#define     _RCC_ERROR                      (0x00)
#define     _RCC_SUCESS                     (0x01)

#define     _RCC_TIMTEOUT_VAL               (0x0001FFFFu)

/**** Global Data Types *******************************************************/
typedef enum
{
  RCC_NO_Clock      = 0,
  RCC_DIV_by_001    = 1,
  RCC_DIV_by_1_5    = 150, // todo the only solution here!!!
  RCC_DIV_by_002    = 2,
  RCC_DIV_by_003    = 3,
  RCC_DIV_by_004    = 4,
  RCC_DIV_by_005    = 5,
  RCC_DIV_by_006    = 6,
  RCC_DIV_by_007    = 7,
  RCC_DIV_by_008    = 8,
  RCC_DIV_by_009    = 9,
  RCC_DIV_by_010    = 10,
  RCC_DIV_by_011    = 11,
  RCC_DIV_by_012    = 12,
  RCC_DIV_by_013    = 13,
  RCC_DIV_by_014    = 14,
  RCC_DIV_by_015    = 15,
  RCC_DIV_by_016    = 16,
  RCC_DIV_by_032    = 32,
  RCC_DIV_by_064    = 64,
  RCC_DIV_by_128    = 128,
  RCC_DIV_by_256    = 256,
  RCC_DIV_by_512    = 512,
} ksRCC_PreScale_e;

typedef struct
{
  ksRCC_PreScale_e  AHB_Prescaler;
  ksRCC_PreScale_e  APB1_Prescaler;
  ksRCC_PreScale_e  APB2_Prescaler;
  ksRCC_PreScale_e  ADC_Prescaler;
  ksRCC_PreScale_e  USB_Prescaler;
  ksRCC_PreScale_e  MCO_Prescaler;
} ksRCC_PreScale_t;

typedef struct
{
  ksU32 SYS_CLK;
  ksU32 Peri1_CLK;
  ksU32 Peri2_CLK;
} ksRCC_CLK_t;

typedef enum
{
  RCC_Disable   = 0,
  RCC_Enable    = 1,
  GET_Clock     = 2
} ksRCC_CMD_e;

#endif // __RCC_SPEC_H_KENSKY_2020_3_26
