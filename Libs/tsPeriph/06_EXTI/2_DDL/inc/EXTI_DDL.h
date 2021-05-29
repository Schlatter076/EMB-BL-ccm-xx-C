/*******************************************************************************
  * File    :  EXTI_DDL.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-17
  * Brief   :  
*******************************************************************************/
#ifndef __EXTI_DDL_H_KENSKY_2020_9_17
#define __EXTI_DDL_H_KENSKY_2020_9_17

/**** Includes ****************************************************************/
#include "../../1_PHY/Common/inc/EXTI_Common.h"

#if   (__MCU_TYPE == _MCU_IS_STM32F10x)
#include "../../1_PHY/STM32_F10x/inc/EXTI_STM32F10x.h"

/**** Defines *****************************************************************/
#define     __EXTI_DeINIT()             st(stm32f10xExtiDeInit();)
#define     __EXTI_INIT(para)           st(stm32f10xExtiInit(para);)
#define     __EXTI_SW_Irq(n)            st(stm32f10x_generate_EXTI_SWIrq(n);)
#define     __EXTI_GET_FlagStatus(n)    st(get_stm32f10x_FlagStatus(n);)
#define     __EXTI_CLR_FLAG(n)          st(stm32f10x_Clr_Flag(n);)
#define     __EXTI_GET_ITStatus(n)      st(get_stm32f10x_IT_Status(n);)
#define     __EXTI_CLR_Pending(n)       st(stm32f10x_clr_IT_Pending(n);)
#define     __EXTI_BIND(IO)             st(stm32f10x_bind_IO_N_EXTI((IO));)

#define     __EXTI_EN_IRQ(n)            __EXTI_IRQ_ON(n)
#define     __EXTI_DIS_IRQ(n)           __EXTI_IRQ_OFF(n)
#define     __EXTI_IRQ_is_ON(n)         __EXTI_IRQ_IS_ON(n)
#define     __EXTI_IRQ_is_OFF(n)        __EXTI_IRQ_IS_OFF(n)
#define     __EXTI_EN_EVT(n)            __EXTI_EVT_ON(n)
#define     __EXTI_DIS_EVT(n)           __EXTI_EVT_OFF(n)
#define     __EXTI_EVT_is_ON(n)         __EXTI_EVT_IS_ON(n)
#define     __EXTI_EVT_is_OFF(n)        __EXTI_EVT_IS_OFF(n)
#define     __EXTI_is_Pending(n)        __EXTI_IS_PENDING(n)

#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#include "../../1_PHY/STM32F4xx/inc/extiSTM32F4xx.h"
/**** Defines *****************************************************************/
#define     __EXTI_DeINIT()             st(stm32f4xxExtiDeInit();)
#define     __EXTI_INIT(para)           st(stm32f4xxExtiInit(para);)
#define     __EXTI_SW_Irq(n)            st(stm32f4xxGenerateExtiSWIrq(n);)
#define     __EXTI_GET_FlagStatus(n)    st(getStm32f4xxFlagStatus(n);)
#define     __EXTI_CLR_FLAG(n)          st(stm32f4xxClrFlag(n);)
#define     __EXTI_GET_ITStatus(n)      st(getStm32f4xxItStatus(n);)
#define     __EXTI_CLR_Pending(n)       st(stm32f4xxClrItPending(n);)
#define     __EXTI_BIND(IO)             st(stm32f4xxBindIo_Exti((IO));)

#define     __EXTI_EN_IRQ(n)            __EXTI_IRQ_ON(n)
#define     __EXTI_DIS_IRQ(n)           __EXTI_IRQ_OFF(n)
#define     __EXTI_IRQ_is_ON(n)         __EXTI_IRQ_IS_ON(n)
#define     __EXTI_IRQ_is_OFF(n)        __EXTI_IRQ_IS_OFF(n)
#define     __EXTI_EN_EVT(n)            __EXTI_EVT_ON(n)
#define     __EXTI_DIS_EVT(n)           __EXTI_EVT_OFF(n)
#define     __EXTI_EVT_is_ON(n)         __EXTI_EVT_IS_ON(n)
#define     __EXTI_EVT_is_OFF(n)        __EXTI_EVT_IS_OFF(n)
#define     __EXTI_is_Pending(n)        __EXTI_IS_PENDING(n)

#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#include "../../1_PHY/STM32L1xx/inc/EXTI_STM32L1x.h"

/**** Defines *****************************************************************/
#define     __EXTI_EN_IRQ(n)            __EXTI_IRQ_ON(n)
#define     __EXTI_DIS_IRQ(n)           __EXTI_IRQ_OFF(n)
#define     __EXTI_IRQ_is_ON(n)         __EXTI_IRQ_IS_ON(n)
#define     __EXTI_IRQ_is_OFF(n)        __EXTI_IRQ_IS_OFF(n)
#define     __EXTI_EN_EVT(n)            __EXTI_EVT_ON(n)
#define     __EXTI_DIS_EVT(n)           __EXTI_EVT_OFF(n)
#define     __EXTI_EVT_is_ON(n)         __EXTI_EVT_IS_ON(n)
#define     __EXTI_EVT_is_OFF(n)        __EXTI_EVT_IS_OFF(n)
#define     __EXTI_is_Pending(n)        __EXTI_IS_PENDING(n)

#define     __EXTI_DeINIT()             st(stm32l1xExtiDeInit();)
#define     __EXTI_INIT(para)           st(stm32l1xExtiInit(para);)
#define     __EXTI_SW_Irq(n)            st(stm32l1xExtiGenSWIrq(n);)
#define     __get_EXTI_FlagStatus(n)    st(stm32l1xGetExtiFlag(n);)
#define     __EXTI_CLR_FLAG(n)          st(stm32l1xExtiClrFlag(n);)
#define     __get_EXTI_ITStatus(n)      st(stm32l1xExtiGetItStatus(n);)
#define     __EXTI_CLR_Pending(n)       st(stm32l1xExtiClrItPending(n);)
#define     __EXTI_BIND(IO)             st(stm32l1xExtiBindIO((IO));)

#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#include "../../1_PHY/STM32L0xx/inc/EXTI_STM32L0xx.h"
/**** Defines *****************************************************************/
#define     __EXTI_EN_IRQ(n)            __EXTI_IRQ_ON(n)
#define     __EXTI_DIS_IRQ(n)           __EXTI_IRQ_OFF(n)
#define     __EXTI_IRQ_is_ON(n)         __EXTI_IRQ_IS_ON(n)
#define     __EXTI_IRQ_is_OFF(n)        __EXTI_IRQ_IS_OFF(n)
#define     __EXTI_EN_EVT(n)            __EXTI_EVT_ON(n)
#define     __EXTI_DIS_EVT(n)           __EXTI_EVT_OFF(n)
#define     __EXTI_EVT_is_ON(n)         __EXTI_EVT_IS_ON(n)
#define     __EXTI_EVT_is_OFF(n)        __EXTI_EVT_IS_OFF(n)
#define     __EXTI_is_Pending(n)        __EXTI_IS_PENDING(n)

#define     __EXTI_DeINIT()             st(stm32l0xExtiDeInit();)
#define     __EXTI_INIT(para)           st(stm32l0xExtiInit(para);)
#define     __EXTI_SW_Irq(n)            st(stm32l0xExtiGenSWIrq(n);)
#define     __get_EXTI_FlagStatus(n)    st(stm32l0xGetExtiFlag(n);)
#define     __EXTI_CLR_FLAG(n)          st(stm32l0xExtiClrFlag(n);)
#define     __get_EXTI_ITStatus(n)      st(stm32l0xExtiGetItStatus(n);)
#define     __EXTI_CLR_Pending(n)       st(stm32l0xExtiClrItPending(n);)
#define     __EXTI_BIND(IO)             st(stm32l0xExtiBindIO((IO));)
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx) || (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
#include "../../1_PHY/EFM32TGxx/inc/EXTI_EFM32TGxx.h"
#define     __EXTI_DeINIT()             st(efm32TGxxExtiDeInit();)
#define     __EXTI_INIT(para)           st(efm32TGxxExtiInit(para);)
#define     __EXTI_GET_FlagStatus(n)    st(efm32TGxxGetExtiFlag(n);)
#define     __EXTI_CLR_FLAG(n)          st(efm32TGxxExtiClrFlag(n);)
#define     __EXTI_GET_ITStatus(n)      st(efm32TGxxExtiGetItStatus(n);)
#define     __EXTI_CLR_Pending(n)       st(efm32TGxxExtiClrItPending(n);)
#define     __EXTI_BIND(IO)             st(efm32TGxxExtiBindIO((IO));)

#define     __EXTI_EN_IRQ(n)            __EXTI_IRQ_ON(n)
#define     __EXTI_DIS_IRQ(n)           __EXTI_IRQ_OFF(n)
#define     __EXTI_IRQ_is_ON(n)         __EXTI_IRQ_IS_ON(n)
#define     __EXTI_IRQ_is_OFF(n)        __EXTI_IRQ_IS_OFF(n)
#define     __EXTI_EN_EVT(n)            __EXTI_EVT_ON(n)
#define     __EXTI_DIS_EVT(n)           __EXTI_EVT_OFF(n)
#define     __EXTI_EVT_is_ON(n)         __EXTI_EVT_IS_ON(n)
#define     __EXTI_EVT_is_OFF(n)        __EXTI_EVT_IS_OFF(n)
#define     __EXTI_is_Pending(n)        __EXTI_IS_PENDING(n)
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#include "../../1_PHY/NRF51822/inc/extiNrf51822.h"

#define     __EXTI_DeINIT()             st(nrf51822ExtiDeInit();)
#define     __EXTI_INIT(para)           st(nrf51822ExtiInit(para);)
#define     __EXTI_BIND(IO)             st(nrf51822ExtiBindIO((IO));)

#define     __EXTI_EN_IRQ(n)            st(NRF_GPIOTE->INTENSET |= 1<<(n);)
#define     __EXTI_DIS_IRQ(n)           st(NRF_GPIOTE->INTENCLR |= 1<<(n);)

#define     __EXTI_IRQ_is_ON(n)         (NRF_GPIOTE->INTENSET & (1<<(n)))
#define     __EXTI_IRQ_is_OFF(n)        (!__EXTI_IRQ_is_ON(n))

#define     __EXTI_CLR_Pending(n)       st(NRF_GPIOTE->EVENTS_IN[(n)] = 0x00;)
#define     __EXTI_is_Pending(n)        (NRF_GPIOTE->EVENTS_IN[(n)] == 0x01)

#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#include "../../1_PHY/NRF52832/inc/extiNrf52832.h"

#define     __EXTI_DeINIT()             st(nrf52832ExtiDeInit();)
#define     __EXTI_INIT(para)           st(nrf52832ExtiInit(para);)
#define     __EXTI_BIND(IO)             st(nrf52832ExtiBindIO((IO));)

#define     __EXTI_EN_IRQ(n)            st(NRF_GPIOTE->INTENSET |= 1<<(n);)
#define     __EXTI_DIS_IRQ(n)           st(NRF_GPIOTE->INTENCLR |= 1<<(n);)

#define     __EXTI_IRQ_is_ON(n)         (NRF_GPIOTE->INTENSET & (1<<(n)))
#define     __EXTI_IRQ_is_OFF(n)        (!__EXTI_IRQ_is_ON(n))

#define     __EXTI_CLR_Pending(n)       st(NRF_GPIOTE->EVENTS_IN[(n)] = 0x00;)
#define     __EXTI_is_Pending(n)        (NRF_GPIOTE->EVENTS_IN[(n)] == 0x01)

#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#include "../../1_PHY/EFR32yGxx/inc/EXTI_EFR32yGxx.h"
#define     __EXTI_DeINIT()             st(efr32yGxxExtiDeInit();)
#define     __EXTI_INIT(para)           st(efr32yGxxExtiInit(para);)
#define     __EXTI_GET_FlagStatus(n)    st(efr32yGxxGetExtiFlag(n);)
#define     __EXTI_CLR_FLAG(n)          st(efr32yGxxExtiClrFlag(n);)
#define     __EXTI_GET_ITStatus(n)      st(efr32yGxxExtiGetItStatus(n);)
#define     __EXTI_CLR_Pending(n)       st(efr32yGxxExtiClrItPending(n);)
#define     __EXTI_BIND(IO)             st(efr32yGxxExtiBindIO((IO));)

#define     __EXTI_EN_IRQ(n)            __EXTI_IRQ_ON(n)
#define     __EXTI_DIS_IRQ(n)           __EXTI_IRQ_OFF(n)
#define     __EXTI_IRQ_is_ON(n)         __EXTI_IRQ_IS_ON(n)
#define     __EXTI_IRQ_is_OFF(n)        __EXTI_IRQ_IS_OFF(n)
#define     __EXTI_EN_EVT(n)            __EXTI_EVT_ON(n)
#define     __EXTI_DIS_EVT(n)           __EXTI_EVT_OFF(n)
#define     __EXTI_EVT_is_ON(n)         __EXTI_EVT_IS_ON(n)
#define     __EXTI_EVT_is_OFF(n)        __EXTI_EVT_IS_OFF(n)
#define     __EXTI_is_Pending(n)        __EXTI_IS_PENDING(n)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

#endif // __EXTI_DDL_H_KENSKY_2020_9_17
