/*******************************************************************************
  * File    :  EXTI_Common.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-17
  * Brief   :  
*******************************************************************************/
#ifndef __EXTI_COMMON_H_KENSKY_2012_9_17
#define __EXTI_COMMON_H_KENSKY_2012_9_17

/**** Includes ****************************************************************/
#include    "../../../4_CFG/EXTI_cfg.h"
#include    <stdint.h>

/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: Init_the_EXTI_Structure
*  Paras    : EXTI_Struct   :
*             PinNun        :
*             Mode          :
*             Trigger       :
*             State         :
*  Returns  : always _EXTI_SUCCESSFUL
*  Brief    : fill parameter in the the EXTI_Struct, the struct can then be used
*             by other routine.
*  Build on :
*  Note     :
*******************************************************************************/
ksS32 extiStrucInit(ksEXTI_t         *EXTI_Struct,
                    ksU32            PinNuM,
                    ksEXTI_Mode_e    Mode,
                    ksEXTI_Trigger_e Trigger,
                    ksEXTI_State_e   State,
                    ksU32            channel);

#endif // __EXTI_COMMON_H_KENSKY_2012_9_17
