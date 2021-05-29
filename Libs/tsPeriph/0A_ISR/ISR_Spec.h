/*******************************************************************************
  * File    :  ISR_Spec.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-20
  * Brief   :  
*******************************************************************************/
#ifndef __ISR_SPEC_H_KENSKY_2020_9_20
#define __ISR_SPEC_H_KENSKY_2020_9_20

/**** Includes ****************************************************************/
#include "../ksPeriphSpec.h"

/**** Defines *****************************************************************/
#define     _ksVECT_IS_OFF              (0)
#define     _ksVECT_IS_ON               (1)
#define     _ksISR_CHN_NULL             (-0xffff)

#define     _ISR_MSG_SVC                ("SVC FAULT")
#define     _ISR_MSG_SPURIOUS           ("SPURIOUS ISR")
#define     _ISR_MSG_FAULT              ("FAULT ERR")
#define     _ISR_MSG_NMI                ("NMI ERR")

/**** Global Data Types *******************************************************/
typedef     void(* pISR)(void); // function pointer for ISR routine

typedef     ksS32     ksIsrChn;

typedef struct
{
  ksIsrChn  id;
  pISR      handler;
  ksU32     flag; // flag may be different with IT
  ksU32     IT;   // flag may be different with IT
  ksU32     preprio;
  ksU32     subprio;
} ksISR_t;

typedef  union
{
  pISR  Fnct;
  void  *Ptr;
} ISR_VECT_ELEM_u;

#endif // __ISR_SPEC_H_KENSKY_2020_9_20
