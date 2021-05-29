////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "tsTracerRxCallBacks.h"
/// * Author  : kensky
/// * Version :
/// * Date    : Apr 15, 2020
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __APPS_CALLBACKS_INC_TSTRACERRXCALLBACKS_H_KENSKY_2020__
#define __APPS_CALLBACKS_INC_TSTRACERRXCALLBACKS_H_KENSKY_2020__

//*****************************************************************************
#ifdef  __cplusplus
//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
extern "C"
{
#endif // __cplusplus

/**** Includes ****************************************************************/
#include <Tracer.h>

void deInitUtracerRxBuf (void);

/*******************************************************************************
*  Func_Name: tm30TestTracerRecvISR
*  Paras    : None
*  Returns  : None
*  Brief    : this is an ISR
*  Build on :
*  Note     : in the tracer, we will only use lConsoleNum to receive data
*             from other terminals. by default, the tracer console always uses
*             tracer0
*******************************************************************************/
void tm30TestTracerRecvISR (void);

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __APPS_CALLBACKS_INC_TSTRACERRXCALLBACKS_H_KENSKY_2020__
