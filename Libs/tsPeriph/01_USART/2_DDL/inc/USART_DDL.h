/*******************************************************************************
  * File    :  USART_DDL.h
  * Author  :  kensky
  * Version :
  * Date    :  2020-9-7
  * Brief   :
*******************************************************************************/
#ifndef __USART_DDL_H_KENSKY_2012_9_7
#define __USART_DDL_H_KENSKY_2012_9_7

/**** Includes ****************************************************************/
#include    "./USART_DDL_Buf.h"
#include    "./USART_DDL_GetByte.h"
#include    "./USART_DDL_ISR.h"
#include    "./USART_DDL_SendByte.h"
#include    "./USART_DDL_GetByte.h"
#include    <stdbool.h>

#if   (__MCU_TYPE == _MCU_IS_STM32F10x)
#include "../../1_PHY/STM32_F10x/inc/USART_STM32F10x.h"

/**** Defines *****************************************************************/
#define __USART_DDL_RECV_is_PENDING(U)      __STM32F10X_USART_RECV_is_PENDING(((USART_TypeDef *)((U)->addrBase )))
#define __USART_DDL_RECV_not_PENDING(U)     __STM32F10X_USART_RECV_not_PENDING(((USART_TypeDef *)((U)->addrBase )))

#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#include "../../1_PHY/STM32F4xx/inc/usartSTM32F4xx.h"

/**** Defines *****************************************************************/
#define __USART_DDL_RECV_is_PENDING(U)      __STM32F4XX_USART_RECV_is_PENDING(((USART_TypeDef *)((U)->addrBase )))
#define __USART_DDL_RECV_not_PENDING(U)     __STM32F4XX_USART_RECV_not_PENDING(((USART_TypeDef *)((U)->addrBase )))

#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#include "../../1_PHY/STM32L1xx/inc/USART_STM32L1x.h"

/**** Defines *****************************************************************/
#define __USART_DDL_RECV_is_PENDING(U)      __STM32L1X_USART_RECV_is_PENDING(((USART_TypeDef *)((U)->addrBase )))
#define __USART_DDL_RECV_not_PENDING(U)     __STM32L1X_USART_RECV_not_PENDING(((USART_TypeDef *)((U)->addrBase )))

#elif (__MCU_TYPE ==  _MCU_IS_FSKLxxZ4)
#include "../../1_PHY/FSKLxxZyyy/inc/FSKLxxZyyyUsart.h"
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#include "../../1_PHY/STM32L0xx/inc/stm32L0Usart.h"

/**** Defines *****************************************************************/
#define __USART_DDL_RECV_is_PENDING(U)      __STM32L0X_USART_RECV_is_PENDING(((USART_TypeDef *)((U)->addrBase )))
#define __USART_DDL_RECV_not_PENDING(U)     __STM32L0X_USART_RECV_not_PENDING(((USART_TypeDef *)((U)->addrBase )))

#elif ((__MCU_TYPE == _MCU_IS_EFM32TGxxx) || \
       (__MCU_TYPE == _MCU_IS_EFM32ZGxxx) || \
       (__MCU_TYPE == _MCU_IS_EFM32Gxxx))
#include "../../1_PHY/EFM32XGYYY/inc/efm32xGyyyUsart.h"

/**** Defines *****************************************************************/
#define __USART_DDL_RECV_is_PENDING(U)      __EFM32_USART_RECV_is_PENDING(((USART_TypeDef *)((U)->addrBase)))
#define __USART_DDL_RECV_not_PENDING(U)     __EFM32_USART_RECV_not_PENDING(((USART_TypeDef *)((U)->addrBase)))

#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#include "../../1_PHY/NRF51822/inc/nrf51822Usart.h"

/**** Defines *****************************************************************/
#define __USART_DDL_RECV_is_PENDING(U)      (NRF_UART0->EVENTS_RXDRDY)
#define __USART_DDL_RECV_not_PENDING(U)     (!__USART_DDL_RECV_is_PENDING(U))

#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#include "../../1_PHY/NRF51822/inc/nrf51822Usart.h"

/**** Defines *****************************************************************/
#define __USART_DDL_RECV_is_PENDING(U)      (NRF_UART0->EVENTS_RXDRDY)
#define __USART_DDL_RECV_not_PENDING(U)     (!__USART_DDL_RECV_is_PENDING(U))

#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#include "../../1_PHY/EFR32xGyy/inc/efr32xGyyyUsart.h"

/**** Defines *****************************************************************/
#define __USART_DDL_RECV_is_PENDING(U)      __EFR32xGyyy_USART_RECV_is_PENDING(((emUSART_t *)((U)->addrBase)))
#define __USART_DDL_RECV_not_PENDING(U)     __EFR32xGyyy_USART_RECV_not_PENDING(((emUSART_t *)((U)->addrBase)))

#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

#endif // __USART_DDL_H_KENSKY_2012_9_7
