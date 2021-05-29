/*******************************************************************************
  * File    :  tracer_usart.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-20
  * Brief   :  
*******************************************************************************/
#ifndef __TRACER_USART_H_KENSKY_2012_9_20
#define __TRACER_USART_H_kensky_2012_9_20

/**** Includes ****************************************************************/
#include "../tracer_types.h"

#if (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)

#if (__uTRACER_CNT >= 1)

#if   (__MCU_TYPE == _MCU_IS_STM32L1x)
#define     __TRACER_IO_SPEED_N_1             (is_10MHz)    // for stm32l1x; (is_50MHz) // for stm32f10x
#elif (__MCU_TYPE == _MCU_IS_STM32F10x)
#define     __uTRACER_IO_SPEED_N_1            (is_50MHz)    // for stm32l1x; (is_50MHz) // for stm32f10x
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#define     __uTRACER_IO_SPEED_N_1            (is_10MHz)    // for stm32l1x; (is_50MHz) // for stm32f10x
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#define     __uTRACER_IO_SPEED_N_1            (is_10MHz)    // for efm32TGxx, meaningless
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#define     __uTRACER_IO_SPEED_N_1            (is_10MHz)    // for efm32TGxx, meaningless
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#define     __uTRACER_IO_SPEED_N_1            (is_10MHz)    // for efm32TGxx, meaningless
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#define     __uTRACER_IO_SPEED_N_1            (is_10MHz)    // for efm32TGxx, meaningless
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#define     __uTRACER_IO_SPEED_N_1            (is_10MHz)    // for efm32TGxx, meaningless
#endif

#if   (__uTRACER_ISR_MODE_1 == _TRACER_ISR_NODMA)

#if   ((__MCU_TYPE == _MCU_IS_EFM32Gxxx)  || \
       (__MCU_TYPE == _MCU_IS_EFM32TGxxx) || \
       (__MCU_TYPE == _MCU_IS_EFM32ZGxxx))
#define     __uTRACER_RCVISR_FLAG_1           (USART_IF_RXDATAV)
#elif ((__MCU_TYPE == _MCU_IS_STM32L1x)  || \
       (__MCU_TYPE == _MCU_IS_STM32F10x) || \
       (__MCU_TYPE == _MCU_IS_STM32f0xx) || \
       (__MCU_TYPE == _MCU_IS_STM32L0x))
#define     __uTRACER_RCVISR_FLAG_1           (USART_IT_RXNE)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#define     __uTRACER_RCVISR_FLAG_1           (NRF_UART0_BASE + 0x108)  // (NRF_UART0->EVENTS_RXDRDY)
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#define     __uTRACER_RCVISR_FLAG_1           (NRF_UART0_BASE + 0x108)  // (NRF_UART0->EVENTS_RXDRDY)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#define     __uTRACER_RCVISR_FLAG_1           (USART_IF_RXDATAV)

#else
#endif // __MCU_TYPE

#elif (__uTRACER_ISR_MODE_1 == _TRACER_ISR_DMA)

#if   ((__MCU_TYPE == _MCU_IS_EFM32Gxxx)  || \
       (__MCU_TYPE == _MCU_IS_EFM32TGxxx) || \
       (__MCU_TYPE == _MCU_IS_EFM32ZGxxx))
#define     __uTRACER_RCVISR_FLAG_1           (USART_IT_IDLE)
#elif ((__MCU_TYPE == _MCU_IS_STM32L1x)  || \
       (__MCU_TYPE == _MCU_IS_STM32F10x) || \
       (__MCU_TYPE == _MCU_IS_STM32f0xx) || \
       (__MCU_TYPE == _MCU_IS_STM32L0x))
#define     __uTRACER_RCVISR_FLAG_1           (USART_IT_IDLE)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#define     __uTRACER_RCVISR_FLAG_1           /* (NRF_UART0->EVENTS_RXDRDY) // */ (NRF_UART0_BASE + 0x108) // constant
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#define     __uTRACER_RCVISR_FLAG_1           (NRF_UARTE0_BASE + 0x108)  // (NRF_UARTE0->EVENTS_ENDRX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#define     __uTRACER_RCVISR_FLAG_1           (USART_IF_RXDATAV)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#define     __uTRACER_RCVISR_FLAG_1           (LPUART_STAT_RDRF_MASK)
#else
#endif // __MCU_TYPE

#endif // __uTRACER_ISR_MODE_1

#if   ((__MCU_TYPE == _MCU_IS_EFM32Gxxx)  || \
       (__MCU_TYPE == _MCU_IS_EFM32TGxxx) || \
       (__MCU_TYPE == _MCU_IS_EFM32ZGxxx))
#define     __uTRACER_TXISR_FLAG_1            (USART_IF_TXC)
#elif ((__MCU_TYPE == _MCU_IS_STM32L1x)  || \
       (__MCU_TYPE == _MCU_IS_STM32F10x) || \
       (__MCU_TYPE == _MCU_IS_STM32f0xx) || \
       (__MCU_TYPE == _MCU_IS_STM32L0x))
#define     __uTRACER_TXISR_FLAG_1            (USART_IT_TC)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#define     __uTRACER_TXISR_FLAG_1            /* (NRF_UART0->EVENTS_TXDRDY) // */ (NRF_UART0_BASE + 0x11C) // constant
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#define     __uTRACER_TXISR_FLAG_1            (NRF_UARTE0_BASE + 0x11C)  // (NRF_UARTE0->EVENTS_ENDTX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#define     __uTRACER_TXISR_FLAG_1            (USART_IF_TXC)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#define     __uTRACER_TXISR_FLAG_1            (LPUART_STAT_TC_MASK)  // TODO ??
#else
#endif // __MCU_TYPE

#endif // __uTRACER_CNT >= 1

#if ((__USART_TRACER == _TRACER_ON))
#include "./tracerPeri.h"

#if (__uTRACER_CNT >= 1)
extern ksTracer_t uTracer[__uTRACER_CNT];
#endif // (__uTRACER_CNT >= 1)

/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: Tracer_USART_Receive_Data
*  Paras    : None
*  Returns  : None
*  Brief    : this routine will be called by an ISR
*  Build on :
*  Note     : in the tracer, we will only use _TRACER_Console to receive data
*             from other terminals. by default, the tracer console always uses
*             tracer0
*******************************************************************************/
void Tracer_USART_Receive_Data(ksTracer_t *tracer, uchar *pData);

#endif // ((__USART_TRACER == _TRACER_ON))

#endif // (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)

#endif // __TRACER_USART_H_KENSKY_2012_9_20
