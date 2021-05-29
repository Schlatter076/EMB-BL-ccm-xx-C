/*******************************************************************************
  * File    :  NVIC_cfg.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-29
  * Brief   :  
*******************************************************************************/
#ifndef __NVIC_CFG_H_KENSKY_2012_9_29
#define __NVIC_CFG_H_KENSKY_2012_9_29

/**** Includes ****************************************************************/
#include    <stdint.h>
#include    "../NVIC_Spec.h"

#if (__MCU_TYPE != _MCU_IS_ESP8266)
#include    "../../0A_ISR/ISR_Driver.h"
#endif // (__MCU_TYPE != _MCU_IS_ESP8266)

#endif // __NVIC_CFG_H_kensky_2020-9-29
