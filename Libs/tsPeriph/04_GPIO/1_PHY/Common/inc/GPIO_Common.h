/*******************************************************************************
  * File    :  GPIO_Common.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-17
  * Brief   :  
*******************************************************************************/
#ifndef __GPIO_COMMON_H_KENSKY_2020_9_17
#define __GPIO_COMMON_H_KENSKY_2020_9_17

/**** Includes ****************************************************************/
#include    <04_GPIO/4_CFG/GPIO_cfg.h>
#include    <stdint.h>
#include    <stdlib.h>

/**** Defines *****************************************************************/

/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: Init_the_GPIO_Structure
*  Paras    :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
void Init_the_GPIO_Structure (ksGPIO_Pin_t    *Pin_Struct,
                              ksU16           PinNum,
                              ksGPIO_Mode_e   Mode,
                              ksGPIO_Speed_e  Speed);

#endif // __GPIO_COMMON_H_KENSKY_2020_9_17
