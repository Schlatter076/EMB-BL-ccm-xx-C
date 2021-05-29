/*******************************************************************************
  * File    :  GPIO_DDL.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-16
  * Brief   :  
*******************************************************************************/
#ifndef __GPIO_DDL_H_KENSKY_2020_9_16
#define __GPIO_DDL_H_KENSKY_2020_9_16

/**** Includes ****************************************************************/
#include "../../1_PHY/Common/inc/GPIO_Common.h"

#if 	(__MCU_TYPE == _MCU_IS_STM32F10x)
#include "../../1_PHY/STM32_F10x/inc/GPIO_STM32F10x.h"

/**** Defines *****************************************************************/
#define     __set_IO_High(IO)           __set_STM32_IO_HIGH(IO)
#define     __set_IO_LOW(IO)            __set_STM32_IO_LOW(IO)
#define     __IO_is_LOW(IO)             __STM32_IO_is_LOW(IO)
#define     __IO_is_HIGH(IO)            __STM32_IO_is_HIGH(IO)

#define     __GPIO_DeINIT(IO)           st(stm32f10x_GPIO_DeInit((IO));)
#define     __GPIO_INIT(IO, para)       st(stm32f10x_GPIO_Init((IO),(para));)
#define     __GPIO_Switch(IO, state)    st(stm32f10x_switch_GPIO((IO), state);)

#define     __GPIO_SAVE_CR(IO)          stm32f10x_GPIO_save_CR((IO))
#define     __GPIO_RESTORE_CR(IO,CR)    st(stm32f10x_GPIO_restore_CR((IO),(CR));)

#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#include "../../1_PHY/STM32L1xx/inc/GPIO_STM32L1xx.h"

/**** Defines *****************************************************************/
#define     __set_IO_High(IO)           __set_STM32_IO_HIGH(IO)
#define     __set_IO_LOW(IO)            __set_STM32_IO_LOW(IO)
#define     __IO_is_LOW(IO)             __STM32_IO_is_LOW(IO)
#define     __IO_is_HIGH(IO)            __STM32_IO_is_HIGH(IO)

#define     __GPIO_DeINIT(IO)           st(stm32Lx_GPIO_DeInit((IO));)
#define     __GPIO_INIT(IO, para)       st(stm32Lx_GPIO_Init((IO),(para));)
#define     __GPIO_Switch(IO, state)    st(stm32Lx_switch_GPIO((IO), state);)

#define     __GPIO_SAVE_CR(IO)          stm32Lx_GPIO_save_CR((IO))
#define     __GPIO_RESTORE_CR(IO,CR)    st(stm32Lx_GPIO_restore_CR((IO),(CR));)

#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)

#include "../../1_PHY/STM32L0xx/inc/GPIO_STM32L0xx.h"

/**** Defines *****************************************************************/
#define     __set_IO_High(IO)           __set_STM32_IO_HIGH(IO)
#define     __set_IO_LOW(IO)            __set_STM32_IO_LOW(IO)
#define     __IO_is_LOW(IO)             __STM32_IO_is_LOW(IO)
#define     __IO_is_HIGH(IO)            __STM32_IO_is_HIGH(IO)

#define     __GPIO_DeINIT(IO)           st(stm32L0xGpioDeInit((IO));)
#define     __GPIO_INIT(IO, para)       st(stm32L0xGpioInit((IO),(para));)
#define     __GPIO_Switch(IO, state)    st(stm32L0xGpioSwitch((IO), state);)

#define     __GPIO_SAVE_CR(IO)          stm32Lx_GPIO_save_CR((IO))
#define     __GPIO_RESTORE_CR(IO,CR)    st(stm32Lx_GPIO_restore_CR((IO),(CR));)

#elif ((__MCU_TYPE == _MCU_IS_EFM32TGxxx) || (__MCU_TYPE == _MCU_IS_EFM32Gxxx))
#include "../../1_PHY/EFM32TGxx/inc/GPIO_EFM32TGxx.h"
/**** Defines *****************************************************************/
#define     __set_IO_High(IO)           __set_EFM32_IO_HIGH(IO)
#define     __set_IO_LOW(IO)            __set_EFM32_IO_LOW(IO)
#define     __IO_is_LOW(IO)             __EFM32_IO_is_LOW(IO)
#define     __IO_is_HIGH(IO)            __EFM32_IO_is_HIGH(IO)

#define     __GPIO_DeINIT(IO)           st(efm32TGxxGpioDeInit((IO));)
#define     __GPIO_INIT(IO, para)       st(efm32TGxxGpioInit((IO),(para));)
#define     __GPIO_Switch(IO, state)    st(efm32TGxxGpioSwitch((IO), state);)

#define     __GPIO_SAVE_CR(IO)          efm32TGxx_GPIO_save_CR((IO))
//#define     __GPIO_RESTORE_CR(IO,CR)    st(efm32TGxx_GPIO_restore_CR((IO),(CR));)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#include "../../1_PHY/EFR32yGxx/inc/GPIO_EFR32yGxx.H"
/**** Defines *****************************************************************/
#define     __set_IO_High(IO)           __set_EFR32_IO_HIGH(IO)
#define     __set_IO_LOW(IO)            __set_EFR32_IO_LOW(IO)
#define     __IO_is_LOW(IO)             __EFR32_IO_is_LOW(IO)
#define     __IO_is_HIGH(IO)            __EFR32_IO_is_HIGH(IO)

#define     __GPIO_DeINIT(IO)           st(efr32yGxxGpioDeInit((IO));)
#define     __GPIO_INIT(IO, para)       st(efr32yGxxGpioInit((IO),(para));)
#define     __GPIO_Switch(IO, state)    st(efr32yGxxGpioSwitch((IO), state);)

#define     __GPIO_SAVE_CR(IO)          efm32TGxx_GPIO_save_CR((IO))
//#define     __GPIO_RESTORE_CR(IO,CR)    st(efm32TGxx_GPIO_restore_CR((IO),(CR));)

#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#include "../../1_PHY/NRF52832/inc/GPIO_NRF52832.h"

#define     __set_IO_High(IO)           __set_NRF_IO_HIGH(IO)
#define     __set_IO_LOW(IO)            __set_NRF_IO_LOW(IO)
#define     __IO_is_LOW(IO)             __NRF_IO_is_LOW(IO)
#define     __IO_is_HIGH(IO)            __NRF_IO_is_HIGH(IO)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#include "../../1_PHY/NRF51822/inc/GPIO_NRF51822.h"

#define     __set_IO_High(IO)           __set_NRF_IO_HIGH(IO)
#define     __set_IO_LOW(IO)            __set_NRF_IO_LOW(IO)

#define     __set_IO_OUTPUT(IO)         __set_NRF_IO_OUTPUT(IO)
#define     __set_IO_INPUT(IO)          __set_NRF_IO_INPUT(IO)

#define     __IO_is_LOW(IO)             __NRF_IO_is_LOW(IO)
#define     __IO_is_HIGH(IO)            __NRF_IO_is_HIGH(IO)

#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#include "../../1_PHY/STM32F4xx/inc/gpioSTM32F4xx.h"

/**** Defines *****************************************************************/
#define     __set_IO_High(IO)           __set_STM32_IO_HIGH(IO)
#define     __set_IO_LOW(IO)            __set_STM32_IO_LOW(IO)
#define     __set_IO(IO, cmd)           __set_STM32_IO(IO, cmd)
#define     __IO_is_LOW(IO)             __STM32_IO_is_LOW(IO)
#define     __IO_is_HIGH(IO)            __STM32_IO_is_HIGH(IO)

#define     __GPIO_DeINIT(IO)           st(stm32F4xxGpioDeInit((IO));)
#define     __GPIO_INIT(IO, para)       st(stm32F4xxGpioInit((IO),(para));)
#define     __GPIO_Switch(IO, state)    st(stm32F4xxGpioSwitch((IO), (state));)

#define     __GPIO_SAVE_CR(IO)          stm32Lx_GPIO_save_CR((IO))
#define     __GPIO_RESTORE_CR(IO,CR)    st(stm32Lx_GPIO_restore_CR((IO),(CR));)

#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#include "../../1_PHY/FSKLxxZyyy/inc/GPIO_FSKLxxZyyy.h"

/**** Defines *****************************************************************/
#define     __set_IO_High(IO)           __set_FSKL_IO_HIGH(IO)
#define     __set_IO_LOW(IO)            __set_FSKL_IO_LOW(IO)
#define     __set_IO(IO, cmd)           __set_FSKL_IO(IO, cmd)
#define     __IO_is_LOW(IO)             __FSKL_IO_is_LOW(IO)
#define     __IO_is_HIGH(IO)            __FSKL_IO_is_HIGH(IO)

//#define     __GPIO_DeINIT(IO)           st(stm32F4xxGpioDeInit((IO));)
//#define     __GPIO_INIT(IO, para)       st(stm32F4xxGpioInit((IO),(para));)
//#define     __GPIO_Switch(IO, state)    st(stm32F4xxGpioSwitch((IO), (state));)

#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

#endif // __GPIO_DDL_H_KENSKY_2020_9_16
