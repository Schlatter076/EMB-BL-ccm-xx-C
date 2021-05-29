/*******************************************************************************
  * File    :  NVIC_Spec.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-29
  * Brief   :  
*******************************************************************************/
#ifndef __NVIC_SPEC_H_KENSKY_2020_9_29
#define __NVIC_SPEC_H_KENSKY_2020_9_29

/**** Includes ****************************************************************/
#include <0A_ISR/ISR_Spec.h>

/**** Defines *****************************************************************/
#define     _NVIC_VECT_TAB_RAM              (0)
#define     _NVIC_VECT_TAB_FLASH            (1)

/**** Global Data Types *******************************************************/
typedef enum
{ // tested for ARM CM3 & CM0, CM0plus
  _ISER =   0x00,
  _ICER =   0x01,
  _ISPR =   0x02,
  _ICPR =   0x03,
  _IABR =   0x04, // not available in CM0
  _IPR  =   0x06,
  _STIR =   0x1C, // not available in CM0
} ksNvicReg_e;

typedef enum
{
  _NVIC_DIS = 0x00,
  _NVIC_EN  = 0x01,
  _NVIC_ERR = 0xFF,
} ksNvicStatus_e;

typedef struct
{
  ksISR_t isr;
  ksU32   preprio;
  ksU32   subprio;
} ksNVIC_t; // todo : not applicable for now

#endif // __NVIC_SPEC_H_KENSKY_2020_9_29
