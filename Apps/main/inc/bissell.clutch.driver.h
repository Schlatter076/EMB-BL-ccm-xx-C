/*
 * bissell.clutch.driver.h
 *
 *  Created on: Oct 8, 2021
 *      Author: loyer
 */

#ifndef APPS_MAIN_INC_BISSELL_CLUTCH_DRIVER_H_
#define APPS_MAIN_INC_BISSELL_CLUTCH_DRIVER_H_


/***** Include ****************************************************************/
#include  "projCfg.h"
#include  <ksPeriph.h>
#include  <Tracer.h>

/***** Defines ****************************************************************/
#define  MOTOR_RELAY1_PORT     (io_Port_0)
#define  MOTOR_RELAY1_Pin      (io_Pin_08)
#define  MOTOR_RELAY1_SPEED    (is_10MHz)
#define  MOTOR_RELAY1_MODE     (io_Mode_OOP)
#define  __RELAY_1_HIGH        __KS_IO_SET_HIGH(&io_relay1)
#define  __RELAY_1_LOW         __KS_IO_SET_LOW(&io_relay1)

#define  MOTOR_RELAY2_PORT     (io_Port_0)
#define  MOTOR_RELAY2_Pin      (io_Pin_09)
#define  MOTOR_RELAY2_SPEED    (is_10MHz)
#define  MOTOR_RELAY2_MODE     (io_Mode_OOP)
#define  __RELAY_2_HIGH        __KS_IO_SET_HIGH(&io_relay2)
#define  __RELAY_2_LOW         __KS_IO_SET_LOW(&io_relay2)



extern ksGPIO_t io_relay1;
extern ksGPIO_t io_relay2;


/******************************************************************************/
void Init_Clutch_Driver(void);


#endif /* APPS_MAIN_INC_BISSELL_CLUTCH_DRIVER_H_ */
