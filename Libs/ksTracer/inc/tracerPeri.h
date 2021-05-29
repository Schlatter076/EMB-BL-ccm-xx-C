////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "tracerPeri.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __TRACERPERI_H_KENSKY_2013_6_27
#define __TRACERPERI_H_KENSKY_2013_6_27

/**** Includes ****************************************************************/
#include "../tracer_cfg.h"

#if (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)

/**** Defines *****************************************************************/
#if (__USART_TRACER ==_TRACER_ON) // only valid for usart
#define   __TRACER_CTS_SET_BUSY(N)      st(__KS_IO_SET_HIGH(&(uTracer[(N)].pUsart)->gpio[_KS_USART_IO_CTS]);)
#define   __TRACER_CTS_SET_FREE(N)      st(__KS_IO_SET_LOW(&(uTracer[(N)].pUsart)->gpio[_KS_USART_IO_CTS]);)
#define   __TRACER_RTS_IS_BUSY(N)       (__KS_IO_IS_HIGH(&(uTracer[(N)].pUsart)->gpio[_KS_USART_IO_RTS]))
#define   __TRACER_RTS_IS_FREE(N)       (__KS_IO_IS_LOW(&(uTracer[(N)].pUsart)->gpio[_KS_USART_IO_RTS]))
#endif // (__USART_TRACER ==_TRACER_ON)

/**** Global Data Types *******************************************************/

/**** Global Variables ********************************************************/
#else
/**** Defines *****************************************************************/
#define   __TRACER_CTS_SET_BUSY(N)
#define   __TRACER_CTS_SET_FREE(N)
#define   __TRACER_RTS_IS_BUSY(N)
#define   __TRACER_RTS_IS_FREE(N)
#endif // (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)
#endif // __TRACERPERI_H_KENSKY_2013_6_27
