/*******************************************************************************
*                           LEDs Driver header
* Filename      : LEDs_Driver.h
* Version       : V1.00
* Programmer(s) : yangkun1978@sina.com
* Date          : 2011-10-06
* IDE           : IAR_EWARM6.10
* Remarks       : this edition can only handle single key pressed event, those 
*                 combo key situations are simply  abandoned
*******************************************************************************/
#ifndef  __LEDS_DRIVERS_H_20200413YK
#define  __LEDS_DRIVERS_H_20200413YK

/**** Includes ****************************************************************/
#include "./inc/LEDs_Periph_cfg.h"

#if (defined __LEDs_MODULE) && (_MODULE_ON == __LEDs_MODULE)
/**** Defines *****************************************************************/
#define     M__LED_TOGGLE(ledNb)            st(LEDs_Toggle(&gv_ledPeriph[ledNb]);)
#define     M__LED_TurnOn(ledNb)            st(LEDs_On(&gv_ledPeriph[ledNb]);)
#define     M__LED_TurnOff(ledNb)           st(LEDs_Off(&gv_ledPeriph[ledNb]);)
#define     M__LED_Set(ledNb, isTurnOn)     st(if (isTurnOn) {LEDs_On(&gv_ledPeriph[ledNb]);} else {LEDs_Off(&gv_ledPeriph[ledNb]);})
#define     M__LED_IsOn(ledNb)              (ledIsOn(&gv_ledPeriph[ledNb]))
#define     M__LED_IsOff(ledNb)             (!M__LED_IsOn(ledNb))

/***** Global Variables *******************************************************/

/***** Routine Prototype ******************************************************/
/*******************************************************************************
* Function Name  : void LEDs_Init
* Description    : Initialize the GPIOs used by LEDs
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void LEDs_Init(void);

/*******************************************************************************
* Function Name  : void LEDs_Toggle
* Description    : Toggle the working status of LEDs
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void LEDs_Toggle(ksLED_t *LED);

/*******************************************************************************
* Function Name  : void LEDs_On
* Description    : turn on the LED
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void LEDs_On(ksLED_t *LED);

/*******************************************************************************
* Function Name  : void LEDs_Off
* Description    : turn off the LED
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void LEDs_Off(ksLED_t *LED);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ledIsOn
/// @param      : p_arg
///               @arg  LED
/// @return     : description of return value.
/// @brief      : check if the led is on or off
/// @author     : kensky
/// @date       : 2014-7-10
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
int ledIsOn(ksLED_t *LED);

#endif // (defined __LEDs_MODULE) && (_MODULE_ON == __LEDs_MODULE)

#endif // __LEDS_DRIVERS_H_20200413YK
