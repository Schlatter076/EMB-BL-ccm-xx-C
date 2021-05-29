/*******************************************************************************
  * File    :  ISR.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-25
  * Brief   :  
*******************************************************************************/
#ifndef __ISR_H_KENSKY_2020_9_25
#define __ISR_H_KENSKY_2020_9_25

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/ISR_DDL.h"

/**** Defines *****************************************************************/
#if 	(defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_STM32F10x)

#define     __ksGLOBAL_IRQ_ON()           st(__STM32F10X_Global_IRQ_ON();)
#define     __ksGLOBAL_IRQ_OFF()          st(__STM32F10X_Global_IRQ_OFF();)
#define     __KS_ENTER_CRITICAL(sr)       st(__STM32F10X_EN_CRITICAL(sr);)
#define     __KS_EXIT_CRITICAL(sr)        st(__STM32F10X_EXIT_CRITICAL(sr);)

#elif (__MCU_TYPE == _MCU_IS_STM32L1x)

#define     __ksGLOBAL_IRQ_ON()           st(__STM32LX_Global_IRQ_ON();)
#define     __ksGLOBAL_IRQ_OFF()          st(__STM32LX_Global_IRQ_OFF();)
#define     __KS_ENTER_CRITICAL(sr)       st(__STM32LX_EN_CRITICAL(sr);)
#define     __KS_EXIT_CRITICAL(sr)        st(__STM32LX_EXIT_CRITICAL(sr);)

#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)

#define     __ksGLOBAL_IRQ_ON()           st(__STM32F4xx_Global_IRQ_ON();)
#define     __ksGLOBAL_IRQ_OFF()          st(__STM32F4xx_Global_IRQ_OFF();)
#define     __KS_ENTER_CRITICAL(sr)       st(__STM32F4xx_EN_CRITICAL(sr);)
#define     __KS_EXIT_CRITICAL(sr)        st(__STM32F4xx_EXIT_CRITICAL(sr);)

#elif (__MCU_TYPE == _MCU_IS_STM32L0x)

#define     __ksGLOBAL_IRQ_ON()           st(__STM32L0X_Global_IRQ_ON();)
#define     __ksGLOBAL_IRQ_OFF()          st(__STM32L0X_Global_IRQ_OFF();)
#define     __KS_ENTER_CRITICAL(sr)       st(__STM32L0X_EN_CRITICAL(sr);)
#define     __KS_EXIT_CRITICAL(sr)        st(__STM32L0X_EXIT_CRITICAL(sr);)

#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)

#define     __ksGLOBAL_IRQ_ON()           st(__EFM32TGxx_Global_IRQ_ON();)
#define     __ksGLOBAL_IRQ_OFF()          st(__EFM32TGxx_Global_IRQ_OFF();)
#define     __KS_ENTER_CRITICAL(sr)       st(__EFM32TGxx_EN_CRITICAL(sr);)
#define     __KS_EXIT_CRITICAL(sr)        st(__EFM32TGxx_EXIT_CRITICAL(sr);)

#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)

#define     __ksGLOBAL_IRQ_ON()           st(__EFM32Gxx_Global_IRQ_ON();)
#define     __ksGLOBAL_IRQ_OFF()          st(__EFM32Gxx_Global_IRQ_OFF();)
#define     __KS_ENTER_CRITICAL(sr)       st(__EFM32Gxx_EN_CRITICAL(sr);)
#define     __KS_EXIT_CRITICAL(sr)        st(__EFM32Gxx_EXIT_CRITICAL(sr);)

#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#define     __ksGLOBAL_IRQ_ON()           st(__NRF51822_Global_IRQ_ON();)
#define     __ksGLOBAL_IRQ_OFF()          st(__NRF51822_Global_IRQ_OFF();)
#define     __KS_ENTER_CRITICAL(sr)       st(__NRF51822_EN_CRITICAL(sr);)
#define     __KS_EXIT_CRITICAL(sr)        st(__NRF51822_EXIT_CRITICAL(sr);)
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#define     __ksGLOBAL_IRQ_ON()           st(__NRF52832_Global_IRQ_ON();)
#define     __ksGLOBAL_IRQ_OFF()          st(__NRF52832_Global_IRQ_OFF();)
#define     __KS_ENTER_CRITICAL(sr)       st(__NRF52832_EN_CRITICAL(sr);)
#define     __KS_EXIT_CRITICAL(sr)        st(__NRF52832_EXIT_CRITICAL(sr);)
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)

#define     __ksGLOBAL_IRQ_ON()           st(__TICC1310_Global_IRQ_ON();)
#define     __ksGLOBAL_IRQ_OFF()          st(__TICC1310_Global_IRQ_OFF();)
#define     __KS_ENTER_CRITICAL(sr)       st(__TICC1310_EN_CRITICAL(sr);)
#define     __KS_EXIT_CRITICAL(sr)        st(__TICC1310_EXIT_CRITICAL(sr);)

#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)

#define     __ksGLOBAL_IRQ_ON()           st(__EFR32yGxx_Global_IRQ_ON();)
#define     __ksGLOBAL_IRQ_OFF()          st(__EFR32yGxx_Global_IRQ_OFF();)
#define     __KS_ENTER_CRITICAL(sr)       st(__EFR32yGxx_EN_CRITICAL(sr);)
#define     __KS_EXIT_CRITICAL(sr)        st(__EFR32yGxx_EXIT_CRITICAL(sr);)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#define     __ksGLOBAL_IRQ_ON()           st(__FSKLxxZyyy_Global_IRQ_ON();)
#define     __ksGLOBAL_IRQ_OFF()          st(__FSKLxxZyyy_Global_IRQ_OFF();)
#define     __KS_ENTER_CRITICAL(sr)       st(__FSKLxxZyyy_EN_CRITICAL(sr);)
#define     __KS_EXIT_CRITICAL(sr)        st(__FSKLxxZyyy_EXIT_CRITICAL(sr);)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: ksIsrInit
*  Paras    :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
void  ksIsrInit (void);

/*******************************************************************************
*  Func_Name: ksIsrIntVectSet
*  Paras    : int_id    :
*             isr       :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
void  ksIsrIntVectSet (const ksISR_t *pIrq);

#endif // __ISR_H_KENSKY_2020_9_25
