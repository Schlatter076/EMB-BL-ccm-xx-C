/*******************************************************************************
  * File     "tracer_cfg.h"
  * Author   yangkun1978@sina.com
  * Version  V1.0.1
  * Date     12/08/2019
  * Brief    SPI_Debugger configurations，please use Tracer.h as the interface
*******************************************************************************/
#ifndef _TARCER_CFG_H_20191208_YK
#define _TARCER_CFG_H_20191208_YK

/**** Includes ****************************************************************/
#include <projCfg.h>
#include "./tracer_spec.h"

#if (defined __KS_PERIPH_MODULE) && (__KS_PERIPH_MODULE == _MODULE_ON)
#include    <ksPeriph.h>
#include    <DataStruct.h>
#endif

#ifndef _uuidCheck
#define     _uuidCheck()  // override the global uuid checking routine
#endif

__KS_STATIC_ASSERT(0 == _TRACER_UNLOCKED);
__KS_STATIC_ASSERT(0 == _TRACER_ISR_DMA);

#if (__TRACER_MODULE == _MODULE_ON)
__KS_STATIC_ASSERT(__TRACER_DMABUF_SIZE >= __TRACER_PRINTFBUF_SIZE);
#endif

#if (defined __PROJ_CONFIGURATION) && \
    (defined _GLOBAL_CONFIGURED) && \
    (__PROJ_CONFIGURATION  != _GLOBAL_CONFIGURED)

/************************* Debugger_Configuration *****************************/
/**** MCU Interface ***********************************************************/
#ifndef __MCU_TYPE
#define     __MCU_TYPE              (_MCU_IS_STM32F10x)
#endif
#define     __TRACER_TYPE           (_USART_TRACER)
#define     __TRACER_CNT            (1)
#define     __TRACER_BUF_TYPE       char // Do not add brackets here!
#define     __TRACER_BUF_SIZE       (1)
#define     __TRACER_PRINTF_STATUS  (_TRACER_ON)
#define     __TRACER_PRINTFBUF_SIZE (128)

/**** Debugger IO Configuration ***********************************************/
#if (__TRACER_CNT >= 1)
#define     __TRACER_IO_SPEED       (is_50MHz)

#define     __TRACER_RX_PORT_N_1    (io_Port_0)     // RXD || MISO
#define     __TRACER_RX_PIN_N_1     (io_Pin_10)     // RXD || MISO
#define     __TRACER_RX_MODE_1      (io_Mode_AIN)        // RXD || MISO

#define     __TRACER_TX_PORT_N_1    (io_Port_0)     // TXD || MOSI
#define     __TRACER_TX_PIN_N_1     (io_Pin_09)     // TXD || MOSI
#define     __TRACER_TX_MODE_1      (io_Mode_APP)        // TXD || MOSI

#define     __TRACER_SCK_PORT_N_1   (no_Port)       // for spi use
#define     __TRACER_SCK_PIN_N_1    (no_Pin)        // for spi use
#define     __TRACER_SCK_MODE_1     (no_mode)       // for spi use

#define     __TRACER_CS_PORT_N_1    (no_Port)       // for spi use
#define     __TRACER_CS_PIN_N_1     (no_Pin)        // for spi use
#define     __TRACER_CS_MODE_1      (no_mode)       // for spi use
#endif // (__TRACER_CNT >= 1)

#endif // (__PROJ_CONFIGURATION  != _GLOBAL_CONFIGURED)

#ifndef   __USART_TRACER
#define   __USART_TRACER           (_TRACER_OFF)
#endif

#ifndef   __SPI_TRACER
#define   __SPI_TRACER             (_TRACER_OFF)
#endif

#define     __TRACER_CNT           (__uTRACER_CNT + __sTRACER_CNT)

//#ifndef __uTRACER_IO_SPEED_N_1
//#define   __uTRACER_IO_SPEED_N_1          (is_50MHz)    // for stm32l1x; (is_50MHz) // for stm32f10x
//#endif // __uTRACER_IO_SPEED_N_1

#endif //_TARCER_CFG_H_20191208_YK
