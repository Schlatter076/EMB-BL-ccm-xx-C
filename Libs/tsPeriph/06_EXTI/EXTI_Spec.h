/*******************************************************************************
  * File    :  EXTI_Spec.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-17
  * Brief   :  
*******************************************************************************/
#ifndef __EXTI_SPEC_H_KENSKY_2012_9_17
#define __EXTI_SPEC_H_KENSKY_2012_9_17

/**** Includes ****************************************************************/
#include "../04_GPIO/GPIO_Spec.h"

/**** Defines *****************************************************************/
#define     _EXTI_Pin_0             (0x00u)
#define     _EXTI_Pin_1             (0x01u)
#define     _EXTI_Pin_2             (0x02u)
#define     _EXTI_Pin_3             (0x03u)
#define     _EXTI_Pin_4             (0x04u)
#define     _EXTI_Pin_5             (0x05u)
#define     _EXTI_Pin_6             (0x06u)
#define     _EXTI_Pin_7             (0x07u)
#define     _EXTI_Pin_8             (0x08u)
#define     _EXTI_Pin_9             (0x09u)
#define     _EXTI_Pin_10            (0x0au)
#define     _EXTI_Pin_11            (0x0bu)
#define     _EXTI_Pin_12            (0x0cu)
#define     _EXTI_Pin_13            (0x0du)
#define     _EXTI_Pin_14            (0x0eu)
#define     _EXTI_Pin_15            (0x0fu)
#define     _EXTI_Pin_16            (0x10u)
#define     _EXTI_Pin_17            (0x11u)
#define     _EXTI_Pin_18            (0x12u)
#define     _EXTI_Pin_19            (0x13u)
#define     _EXTI_Pin_20            (0x14u)
#define     _EXTI_Pin_21            (0x15u)
#define     _EXTI_Pin_22            (0x16u)
#define     _EXTI_Pin_23            (0x17u)

#define     _EXTI_SUCCESSFUL        ((int32_t)(0x00))
#define     _EXTI_MISMATCH          ((int32_t)(-1))

/**** Global Data Types *******************************************************/
typedef enum
{
  EXTI_En   = 1,
  EXTI_Dis  = !EXTI_En,
} ksEXTI_State_e;

typedef enum
{
  exti_irq   = 0,
  exti_event = 1,
} ksEXTI_Mode_e;

typedef enum
{
  exti_Rising      = 0x01, //0,
  exti_Falling     = 0x02, //1,
  exti_LevelShift  = 0x03, //2,
  exti_noneTrigger = 0xFF, //3,
} ksEXTI_Trigger_e;

typedef struct
{
  ksGPIO_PORT_e     port;
  ksU32             PinNum;
  ksEXTI_Mode_e     Mode;
  ksEXTI_Trigger_e  Trigger;
  ksEXTI_State_e    State;
  ksU32             channel; // used by NRF51822 or NRF52832
} ksEXTI_t;

#endif // __EXTI_SPEC_H_KENSKY_2012_9_17
