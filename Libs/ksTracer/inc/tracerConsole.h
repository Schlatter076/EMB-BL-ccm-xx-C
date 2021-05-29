/*******************************************************************************
  * File    :  thread_tracer_console.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-10-2
  * Brief   :  
*******************************************************************************/
#ifndef __THREAD_TRACER_CONSOLE_H_KENSKY_2012_10_2
#define __THREAD_TRACER_CONSOLE_H_KENSKY_2012_10_2

/**** Includes ****************************************************************/
#include "./tracer_usart.h"
#include "./tracer_spi.h"

/**** Defines *****************************************************************/
#if (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)

/**** Global Variables ********************************************************/

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : tracerDMARdyToRecv
/// @param      : tracer
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-7-13
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
void tracerDMARdyToRecv (ksTracer_t *tracer);
void tracerConsoleInit  (ksTracer_t *tracer, pISR tracerRxCB);

#endif // (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)

#endif // __THREAD_TRACER_CONSOLE_H_KENSKY_2012_10_2
