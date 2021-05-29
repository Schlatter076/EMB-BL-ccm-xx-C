/*******************************************************************************
  * File    :  GPIO.h
  * Author  :  kensky
  * Version :   
  * Date    :  2019-9-16
  * Brief   :  
*******************************************************************************/
#ifndef __GPIO_H_KENSKY_2019_9_16
#define __GPIO_H_KENSKY_2019_9_16

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/GPIO_DDL.h"

/**** Defines *****************************************************************/
#define     _KS_IO_HIGH                 (0x01ul)
#define     _KS_IO_LOW                  (0x00ul)

#define     __KS_IO_SET_HIGH(IO)        __set_IO_High(IO)
#define     __KS_IO_SET_LOW(IO)         __set_IO_LOW(IO)

#define     __KS_IO_SET_OUTPUT(IO)      __set_IO_OUTPUT(IO)
#define     __KS_IO_SET_INPUR(IO)       __set_IO_INPUT(IO)

#define     __KS_IO_SET(IO, cmd)        __set_IO(IO, cmd)
#define     __KS_IO_IS_LOW(IO)          __IO_is_LOW(IO)
#define     __KS_IO_IS_HIGH(IO)         __IO_is_HIGH(IO)

/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: ksGpioSwitch
*  Paras    : PORTn   :
*             IOstate : IO_Enable, IO_Disable
*  Returns  : GPIO Status
*  Brief    : switch the GPIO
*  Build on :
*  Note     :
*******************************************************************************/
ksRet_t ksGpioSwitch   (ksGPIO_t *IO, ksGPIO_State_e IOstate);

////////////////////////////////////////////////////////////////////////////////
/// @fn     : ksGpioInit
/// @param  : IO : the GPIO
/// @return : description of return value.
/// @brief  : Initialize the GPIO
/// @author : Kensky
/// @date   : Oct 5, 2019
/// @pre    : add precondition here if needed.
/// @note   : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
void    ksGpioInit     (ksGPIO_t *IO);

////////////////////////////////////////////////////////////////////////////////
/// * Func_Name: ksGpioDeInit
/// * Paras    : IO
/// * Returns  :
/// * Brief    :
/// * Author   : kensky
/// * Build on : 2019-1-4
/// * Note     :
////////////////////////////////////////////////////////////////////////////////
void    ksGpioDeInit   (ksGPIO_t *IO);

#endif // __GPIO_H_KENSKY_2019_9_16
