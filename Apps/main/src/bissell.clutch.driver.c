/*
 * bissell.clutch.driver.c
 *
 *  Created on: Oct 8, 2021
 *      Author: loyer
 */
#include "../inc/bissell.clutch.driver.h"


ksGPIO_t io_relay1 =
{
   .periphID = 0,
   .addrBase  = 0,
   .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
   .PORTn     = MOTOR_RELAY1_PORT,
   .Pin =
   {
     .pinNum   = MOTOR_RELAY1_Pin,
     .Mode     = MOTOR_RELAY1_MODE,
     .Speed    = MOTOR_RELAY1_SPEED,
   },
   .pSpecial  = NULL,
};

ksGPIO_t io_relay2 =
{
   .periphID = 0,
   .addrBase  = 0,
   .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
   .PORTn     = MOTOR_RELAY2_PORT,
   .Pin =
   {
     .pinNum   = MOTOR_RELAY2_Pin,
     .Mode     = MOTOR_RELAY2_MODE,
     .Speed    = MOTOR_RELAY2_SPEED,
   },
   .pSpecial  = NULL,
};




void Init_Clutch_Driver(void)
{
  ksGpioInit(&io_relay1);
  ksGpioInit(&io_relay2);

  ksGpioSwitch(&io_relay1, IO_Enable);
  ksGpioSwitch(&io_relay2, IO_Enable);

  __RELAY_1_LOW;

  __RELAY_2_LOW;

}
