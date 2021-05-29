/*******************************************************************************
  * File    :  ksPeriph
  * Author  :  kensky
  * Version :
  * Date    :  2020-9-17
  * Brief   :
*******************************************************************************/
#ifndef __RL_PERIPH_H_KENSKY_2020_9_17
#define __RL_PERIPH_H_KENSKY_2020_9_17

/**** Includes ****************************************************************/
#include    <00_SPI/SPI_Driver.h>
#include    <01_USART/USART_Driver.h>
#include    <06_EXTI/EXTI_Driver.h>
#include    <08_NVIC/NVIC_Driver.h>
#include    <09_Timer/Timer_Driver.h>
#include    <11_DMA/DMA_Driver.h>
#include    <0A_ISR/ISR_Driver.h>
#include    <0B_RTC/RTC_Driver.h>
#include    <0C_LIBs/Lib_Driver.h>
#include    <0D_ADC/ADC_Driver.h>
#include    <0E_RCC/RCC_Driver.h>
#include    <0F_LPWR/LPWR_Driver.h>
#include    <FE_Misc/Misc_Driver.h>
#include    <FD_Protection/rvProtection.h>

# if (__MCU_TYPE == _MCU_IS_HSDC32L110)
#include    <FF_3rdPty/HSDC32L1xxfwlib/hdsc32L1xx_expansion.h>
#endif

/**** Defines *****************************************************************/
#define     __KS_PERIPH_LIB_USED

#endif // __RL_PERIPH_H_KENSKY_2020_9_17
