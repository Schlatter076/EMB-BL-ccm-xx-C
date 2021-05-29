////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "tracer_types.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2015-4-30
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_RVTRACER_TRACER_TYPES_H_KENSKY_2015__
#define __LIBS_RVTRACER_TRACER_TYPES_H_KENSKY_2015__

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
#include "./tracer_cfg.h"

#if (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)
/**** Global Data Types *******************************************************/
typedef enum
{
  _tracer_uninit = 0,
  _tracer_inited = 1,
} tracer_status_e;

typedef enum
{
  _tracer_usart  = 1,
  _tracer_spi    = 2,
} tracer_type_e;

typedef unsigned char uchar;

typedef enum
{
  _tracer_Locked      = 0x00, // 0x00
  _tracer_free        = 0x01, // 0x01, which means it is stored in the stack, or else, the node is used by a list
  _tracer_TxPending   = 0x02, // 0x02
  _tracer_AckPending  = 0x03, // 0x03
  _tracer_TxDone      = 0x06, // 0x06

  _tracer_Rxing       = 0x07, // 0x06

  _tracer_Recved      = 0xff, // 0xff // todo, conflict with __RULE_BUF_ACK_WAITING
}PACKED tracerStatus_e; // make sure the rvBufStatus_e is compatible with this struct
__KS_STATIC_ASSERT(0x01 == sizeof(tracerStatus_e));

typedef struct
{
  tracerStatus_e  status;
  uchar           len;
  uchar           buf[__TRACER_DMABUF_SIZE];
} tracerBuf_t;
__KS_STATIC_ASSERT(__TRACER_DMABUF_SIZE+0x02 == sizeof(tracerBuf_t));

typedef struct
{
  ksStroage_e       storage;
  uchar             index;
  tracer_status_e   status;
  tracer_type_e     type;     // choose between spi or uart
  union
  {
    void*           pPeriph;  // choose between spi or uart
    ksUSART_t*      pUsart;   // choose uart
    ksSPI_t*        pSPI;     // choose spi
  };
  Queue             *Q;
  tracerBuf_t       txBuf;
  tracerBuf_t       rxBuf;
} ksTracer_t;

#endif // (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_RVTRACER_TRACER_TYPES_H_KENSKY_2015__
