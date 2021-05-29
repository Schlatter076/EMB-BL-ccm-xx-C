/*******************************************************************************
  * File    :  ADC_STM32F10x.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-10-9
  * Brief   :  
*******************************************************************************/
#ifndef __ADC_NRF52832_H_KENSKY_2020_10_9
#define __ADC_NRF52832_H_KENSKY_2020_10_9

/**** Includes ****************************************************************/
#include <0D_ADC/1_PHY/NRF52832/inc/ADC_NRF52832_Init.h>

#if (defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_NRF52832)


/**** Inline Function Defintions **********************************************/
__STATIC_INLINE IRQn_Type NRF51822AdcGetIRQn(ksADC_t *pADC, ksU08 irqSrc)
{
  __KS_RUNTIME_ASSERT(_IS_ISR_ADC_SRC(irqSrc), __ASSERT_LIMIT);

  return SAADC_IRQn;
}

#endif // (defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_NRF52832)

#endif // __ADC_NRF52832_H_KENSKY_2020_10_9
