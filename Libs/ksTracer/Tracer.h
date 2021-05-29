/*******************************************************************************
  * File     "Tracer.h"
  * Author   yangkun1978@sina.com
  * Version  V1.1.1
  * Date     07/28/2019
  * Brief    Tracer module interface
*******************************************************************************/
#ifndef __TRACER_H_20190110YK
#define __TRACER_H_20190110YK

/**** Includes ****************************************************************/
#include    <DataStruct.h>
#include    "./inc/tracer_str.h"
#include    "./inc/tracerConsole.h"
#include    <stdarg.h> // variable argument header files

/**** Defines *****************************************************************/
#if (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)
#define     __TRACER_INIT(n)                    st(tracerInit(n);)
#define     __TRACER_SendStr(t, s, d, l)        st(tracerTranceiveBuf((t), (s), (d), (l));)
#define     __TRACER_SEND_BUF(t,B,L)            st(tracerTranceiveBuf((t),(B),NULL,(L));)
#define     __TRACER_TXRX_BUF(N,TB,RB,L)        st(tracerTranceiveBuf((N),(TB),(RB),(L));)
#define     __TRACER_SEND_U08(N, D)
#define     __TRACER_SEND_U16(N, D)
#define     __TRACER_SEND_U32(N, D)

#if (defined __TRACER_PRINTF_STATUS) && (__TRACER_PRINTF_STATUS == _TRACER_ON)
#define     __TRACER_PRINTF(t, fm,...)          st(tracerPrintf((t), fm, ##__VA_ARGS__);)
#define     __TRACER_PRINTFBUF(l, b, f, ...)    st(l += tracerPrintfBuf((b),(f), ##__VA_ARGS__);)

#if (__uTRACER_CNT >= 0x01)
#define     __uTRACER_PRINTF(N, dispSw, fm,...) st(if (dispSw){tracerPrintf((&uTracer[(N)]), fm, ##__VA_ARGS__);})
#define     __uTRACER_SEND_STR(N, str, len)     __TRACER_SendStr((&uTracer[(N)]), (str), NULL, (len))
#define     __uTRACER_SEND_BUF(N, B, L)         __TRACER_SEND_BUF((&uTracer[(N)]), B, L)
#else
#define     __uTRACER_PRINTF(N, dispSw, fm,...)
#define     __uTRACER_SEND_STR(N, str, len)
#endif // (__uTRACER_CNT >= 0x01)

#else
#define     __TRACER_PRINTF(n,fm,...)
#define     __uTRACER_PRINTF(N, dispSw, fm,...)
#endif

#else

#define     __TRACER_INIT(n)
#define     __TRACER_SendStr(t, s, d, l)
#define     __TRACER_SEND_BUF(t,B,L)
#define     __TRACER_TXRX_BUF(N,TB,RB,L)
#define     __TRACER_SEND_U08(N, D)
#define     __TRACER_SEND_U16(N, D)
#define     __TRACER_SEND_U32(N, D)

#define     __TRACER_PRINTF(n,fm,...)
#define     __TRACER_PRINTFBUF(l, b, f, ...)

#define     __uTRACER_PRINTF(N, dispSw, fm,...)
#define     __uTRACER_SEND_STR(N, str, len)
#define     __uTRACER_SEND_BUF(N, B, L)

#define     __TRACER_OUT                (0) // meaningless, but it must be an integer
#define     __TRACER_CONSOLE            (0) // meaningless, but it must be an integer
#endif

#if (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)

/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: tracerInit
*  Paras    : Tracer_N: which tracer should be initialized!
*  Returns  : tracer error messages, 0 for success
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
ksS32 tracerInit  (ksTracer_t *tracer);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : tracerWaitUnlock
/// @param      : tracerNb
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-3-20
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
void tracerWaitUnlock(ksTracer_t *pTracer);

#if (__TRACER_FLWCNTL == _TRACER_ON)
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : tracerWaitFlowControl
/// @param      : p_arg
///               @arg  tracerNb
/// @return     : _TRACER_ETIMEOUT || _TRACER_EOK
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-3-20
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
ksS32 tracerWaitFlowControl(uchar tracerNb);
#endif  // (__TRACER_FLWCNTL == _TRACER_ON)

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : tracerTranceiveStr
/// @param      : p_arg
///               @arg  Tracer_N  - which tracer
///               @arg  src       - the source buffer
///               @arg  des       - the destination buffer
///               @arg  len       - how many bytes
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-9-4
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
ksS32 tracerTranceiveStr(ksTracer_t *pTracer, const void *src, uchar *des, ksU32 len);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : tracerTranceiveBuf
/// @param      : p_arg
///               @arg  Tracer_N
///               @arg  pBuf
///               @arg  len
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-7-10
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
/// @deprecated : add deprecated reason.
////////////////////////////////////////////////////////////////////////////////
ksS32 tracerTranceiveBuf (ksTracer_t  *pTracer,
                          const void  *pSrc,
                          uchar       *pDes,
                          ksU32       len);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : tracerPrintfBuf
/// @param      : @arg  Tracer_N  :: which tracer is being used
///               @arg  pFormat   :: format arguments
///               @arg  pvArg     :: the pointer to a variable argument
/// @return     : description of return value.
/// @brief      : print formatted byte stream to the destination buffer
/// @author     : kensky
/// @date       : 2014-3-17
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
ksS32 tracerPrintfBuf (char *vsnBuf, const char  *pFormat, ...);

#if (defined __TRACER_PRINTF_STATUS) && (__TRACER_PRINTF_STATUS == _TRACER_ON)
/*******************************************************************************
*  Func_Name: tracerPrintf
*  Paras    : Tracer_N  :
*             pFormat   : the format
*  Returns  : len > 0 : successful, len <0 fail
*  Brief    : This function will print a formatted string on tracer
*  Build on :
*  Note     : this routine will use some extra memory for a static buffer, in
*             the configuration file, developers can cancel this routine to save
*             memory.
*******************************************************************************/
ksS32 tracerPrintf (ksTracer_t *pTracer, const char *pFormat, ...);
#endif

/*******************************************************************************
*  Func_Name: tracerReceiveISR
*  Paras    : None
*  Returns  : None
*  Brief    : this is an ISR
*  Build on :
*  Note     : in the tracer, we will only use _TRACER_Console to receive data
*             from other terminals. by default, the tracer console always uses
*             tracer0
*******************************************************************************/
void tracerReceiveISR(void);
#endif // (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)

#endif // __TRACER_H_20190110YK
