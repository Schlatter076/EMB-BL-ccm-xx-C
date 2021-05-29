////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "tsTracerRxCallBacks.c"
/// * Author  : kensky
/// * Version :
/// * Date    : Apr 15, 2020
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////

//*****************************************************************************
#ifdef  __cplusplus
//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//extern "C"
//{
#endif // __cplusplus

/**** Includes ****************************************************************/
#include	"../inc/tsTracerRxCallBacks.h"

#if (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)

#define         __TM30_DATA_BEGINMARK      ('[')
#define         __TM30_DATA_ENDMARK        (']')
#define         __TM30_DATA_LENGTH         (0x10UL)

#define         __TM30_TS_HEADER_CMD       (0x54u)

static ksU32    lv_isrCntr = 0x00;
static ksU32    lv_pktLen  = 0x00;

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : tm30TestTracerHandleRecvedData
/// @param      : tracer  : which tracer
/// @param      : buf     :
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2020-5-10
/// @pre        : add precondition here if needed.
/// @note       : data format is 54 03 12 34 56
////////////////////////////////////////////////////////////////////////////////
static void tm30TestTracerHandleRecvedData(ksTracer_t *pTracer, ksU08 *pByte)
{
  uchar        rcvdByte  = *pByte;
  tracerBuf_t  *pRxBuf   = &uTracer[__UTRACER_IDX_1].rxBuf;

  pRxBuf->buf[pRxBuf->len++] = rcvdByte;

  if (lv_isrCntr == 0x02)
  {
    lv_pktLen = rcvdByte + 0x02; // magic & len
  }

  if (lv_isrCntr == lv_pktLen)
  {
    pRxBuf->status = _tracer_Recved;
  }
  else if ((lv_isrCntr > lv_pktLen) && (0 != lv_pktLen))
  {
    deInitUtracerRxBuf();
  }
}

/**
 * deInitUtracerRxBuf
 */
void deInitUtracerRxBuf (void)
{
  uTracer[__UTRACER_IDX_1].rxBuf.len    = 0x00;
  uTracer[__UTRACER_IDX_1].rxBuf.status = _tracer_free;
  lv_isrCntr  = 0x00;
  lv_pktLen   = 0x00;
}

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
void tm30TestTracerRecvISR (void) // byte by byte
{
  ksUSART_t *pUart = uTracer[__UTRACER_IDX_1].pUsart;

  if(__USART_RECV_is_PENDING(pUart))
  {
    ksU08           rcvdByte  = ksUsartGetByte(pUart);
    tracerStatus_e  status    = uTracer[__UTRACER_IDX_1].rxBuf.status;

    switch (status)
    {
      case _tracer_free :
      { // the 1st byte
        if ((__TM30_TS_HEADER_CMD == rcvdByte) && (0x00 == lv_isrCntr))
        {
          uTracer[__UTRACER_IDX_1].rxBuf.status  = _tracer_Locked;
        }
        else
        {
          goto __EXIT_tm30_uTracerRecvISR;
        }
      }
      break;

      case _tracer_Locked :
      {
        asm("nop");
      }
      break;

      default :
        goto __EXIT_tm30_uTracerRecvISR;
    }

    ++lv_isrCntr;
    tm30TestTracerHandleRecvedData(&uTracer[__UTRACER_IDX_1], &rcvdByte);

__EXIT_tm30_uTracerRecvISR :

    ksUsartClrITFlag(pUart, pUart->RX_isr.flag);

    NRF_UART0->EVENTS_ERROR = 0x00;
  }
}

#endif // (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
//}
#endif // __cplusplus
