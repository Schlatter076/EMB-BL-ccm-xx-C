/*******************************************************************************
  * File    :  tracer_spi.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-20
  * Brief   :  
*******************************************************************************/
#ifndef __TRACER_SPI_H_KENSKY_2012_9_20
#define __TRACER_SPI_H_KENSKY_2012_9_20

/**** Includes ****************************************************************/
#include "../tracer_types.h"

#if (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)

#if (__SPI_TRACER == _TRACER_ON)
#include "./tracerPeri.h"

#if (__sTRACER_CNT >= 1)
/**** Defines *****************************************************************/
#define     __sTRACER_FLWCNTL               (_TRACER_OFF)

/**** Global Variables ********************************************************/
extern ksTracer_t sTracer[__sTRACER_CNT];

#endif // (__sTRACER_CNT >= 1)

#endif

#endif // (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)
#endif // __TRACER_SPI_H_KENSKY_2012_9_20
