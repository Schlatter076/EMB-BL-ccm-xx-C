/*******************************************************************************
  * File    :  EXTI.h
  * Author  :  kensky
  * Version :   
  * Date    :  2019-9-17
  * Brief   :  
*******************************************************************************/
#ifndef __EXTI_H_KENSKY_2019_9_17
#define __EXTI_H_KENSKY_2019_9_17

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/EXTI_DDL.h"

/***** Function Prototypes ****************************************************/
void extiBindWithGpio(ksGPIO_t         *IO,
                      pISR             ISR,
                      ksEXTI_Mode_e    Mode,
                      ksEXTI_Trigger_e Trigger,
                      ksU32            PrePrio,
                      ksU32            SubPrio,
                      ksEXTI_State_e   State,
                      ksU32            channel);

/*******************************************************************************
*                               EXTI_get_IRQn()
* Description : get the EXTI IRQ Chn by PinNuM
* Argument(s) : PinNum        :  Pin  0..15
* Return(s)   : IRQChannel.
* Caller(s)   : Any Routine.
* Note(s)     : not tested yet
*******************************************************************************/
ksIsrChn EXTI_get_IRQn(unsigned char ExtiPinN);

#endif // __EXTI_H_KENSKY_2019_9_17
