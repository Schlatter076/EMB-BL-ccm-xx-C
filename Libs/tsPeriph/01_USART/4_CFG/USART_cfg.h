/*******************************************************************************
  * File    : "USART_Chip_cfg.h"
  * Author  : kensky
  * Version : 1.0
  * Date    : 2020-9-1
  * Brief   : This file configures the USART chip Phy layer which will determine
  *           the behavior of the module
*******************************************************************************/
#ifndef     __USART_CHIP_CFG_H_20120901YK
#define     __USART_CHIP_CFG_H_20120901YK

/**** Includes ****************************************************************/
#include <stdint.h>
#include <01_USART/USART_Spec.h>
#include <projCfg.h>

#if !defined __MCU_TYPE
#error MCU Type is not defined!
#endif

/**** Defines *****************************************************************/
/***** User Configurable Part *************************************************/
//#if (defined __PROJ_CONFIGURATION) && (__PROJ_CONFIGURATION != _GLOBAL_CONFIGURED)
#define     __USART_CNT                         1
#define     __USART_Use_Qn                      1 // all the usart should use the same type of queue
#define     __USART_DMA                         (_USART_DMA_is_OFF)
#define     __ENTER_USART_CRITICAL              st(;)
#define     __EXIT_USART_CRITICAL               st(;)
#define     __USART_Delay_MS(t)                 st(;) //please implement this delay function
#define     __USART_ISR_Registrate(id, pIsr)    st(stm32f10x_IntVectSet(id, pIsr);)
/***** GPIO Configuration ******************************************************
 * PORT 0..N, or A..?, only accept numbers, _USART_IO_UNSPECIFIED(Oxff) for none
*******************************************************************************/
#define     __USART1_N                  (1)
#define     __USART1_IO_TXD_N           (0)
#define     __USART1_IO_TXD_PinNun      (9)
#define     __USART1_TXD_ISR_id         (USART1_IRQn) //= 37
#define     __USART1_IO_RXD_N           (0)
#define     __USART1_IO_RXD_PinNun      (10)
#define     __USART1_RXD_ISR_id         ()
#define     __USART1_IO_CK_N            (_USART_IO_UNSPECIFIED) // if not use , pls. make it to be _USART_IO_UNSPECIFIED
#define     __USART1_IO_CK_PinNun       (_USART_IO_UNSPECIFIED) // if not use , pls. make it to be _USART_IO_UNSPECIFIED
#define     __USART1_IO_RTS_N           (_USART_IO_UNSPECIFIED)
#define     __USART1_IO_RTS_PinNun      (_USART_IO_UNSPECIFIED)
#define     __USART1_IO_CTS_N           (_USART_IO_UNSPECIFIED)
#define     __USART1_IO_CTS_PinNun      (_USART_IO_UNSPECIFIED)
#define     __USART1_IO_DTR_N           (_USART_IO_UNSPECIFIED)
#define     __USART1_IO_DTR_PinNun      (_USART_IO_UNSPECIFIED)
#define     __USART1_IO_DSR_N           (_USART_IO_UNSPECIFIED)
#define     __USART1_IO_DSR_PinNun      (_USART_IO_UNSPECIFIED)
#define     __USART1_IO_DCD_N           (_USART_IO_UNSPECIFIED)
#define     __USART1_IO_DCD_PinNun      (_USART_IO_UNSPECIFIED)
#define     __USART1_IO_RI_N            (_USART_IO_UNSPECIFIED)
#define     __USART1_IO_RI_PinNun       (_USART_IO_UNSPECIFIED)

/**** USART Parameters ********************************************************/
#define     __USART1_BAUD_RATE          (115200u)
#define     __USART1_WrdLen             (_YK_USART_WordLength_8b)
#define     __USART1_STP_Bits           (_YK_USART_StopBits_1)
#define     __USART1_Parity             (_YK_USART_Parity_No)
#define     __USART1_MODE               (_YK_USART_TX_MODE | _YK_USART_RX_MODE)
#define     __USART1_FlowCntl           (_YK_USART_FlowControl_SOFT)

// the following parameters won't take effect, as _YK_USART_Clk_Disable is chosen
#define     __USART1_Clock              (_YK_USART_Clk_Disable)
#define     __USART1_CPOL               (_YK_USART_CPOL_Low)
#define     __USART1_CPHA               (_YK_USART_CPHA_1Edge)
#define     __USART1_LastBit            (_YK_USART_LastBit_Disable)

/***** NVIC Configuration *****************************************************/
#define     __USART1_RXd_IRQ_PIN        (_YK_USART_IO_RXD)
#define     __USART1_TXd_IRQ_PIN        (_YK_USART_IO_TXD)
#define     __USART1_TXd_IRQn           (USART1_IRQn)
#define     __USART1_Txd_IRQ_PrioGRP    (_HAL_IRQ_PrioGRP0)
#define     __USART1_Txd_IRQ_PrePrio    (_HAL_IRQ_PrePrio0)
#define     __USART1_Txd_IRQ_SubPrio    (_HAL_IRQ_SubPrio0) // todo !!!

#endif // __USART_CHIP_CFG_H_20120901YK

