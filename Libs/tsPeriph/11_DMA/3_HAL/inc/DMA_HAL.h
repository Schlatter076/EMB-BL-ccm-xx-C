////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "DMA_HAL.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __DMA_HAL_H_KENSKY_2019_6_23
#define __DMA_HAL_H_KENSKY_2019_6_23

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/DMA_DDL.h"

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// @fn         : ksDMAInit
/// @param      : pDMA
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2019-11-27
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE ksRet_t ksDMAInit(ksDMA_t *pDMA)
{
#if   (__MCU_TYPE ==  _MCU_IS_STM32F10x)
  return stm32f10xDmaInit(pDMA);
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
  while(1);
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
  return stm32f4xxDmaInit(pDMA);
#elif (__MCU_TYPE ==  _MCU_IS_STM32L0x)
  return dmaSTM32L0xInit(pDMA);
#elif (__MCU_TYPE ==  _MCU_IS_STM32L1x)
  return __DEV_TODO;
#elif (__MCU_TYPE ==  _MCU_IS_EFM32TGxxx)
  return efm32TGxxDmaInit(pDMA);
#elif (__MCU_TYPE ==  _MCU_IS_EFM32Gxxx)
  return __DEV_TODO;
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif (__MCU_TYPE ==  _MCU_IS_FSKLxxZ4)
  return FSKLxxZyyyDmaInit(pDMA);
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
  return __DEV_TODO;
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
  return __DEV_TODO;
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
  return efr32yGxxDmaInit(pDMA);
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
  return __DEV_TODO;
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
  return __DEV_TODO;
#else
#error unsupportted!
#endif
}

/**
 * @fn ksDMAClkSwitch
 * @param pDMA
 * @param newState
 */
__STATIC_INLINE void ksDMAClkSwitch(ksDMA_t *pDMA, ksState_e newState)
{
#if   (__MCU_TYPE ==  _MCU_IS_STM32F10x)
  while(1);
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
  stm32f4xxDmaClkSwitch(pDMA, newState);
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
  FSKLxxZyyyDmaClkSwitch(pDMA, newState);
#endif
}

/**
 *
 * @param pDMA
 * @param dmaItFlag
 * @return
 */
__STATIC_INLINE ksU32 ksDmaGetItStatus(ksDMA_t *pDMA, ksU32 dmaItFlag)
{
#if   (__MCU_TYPE ==  _MCU_IS_STM32F10x)
  return __DEV_TODO;
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
  return stm32f4xxDmaGetItStatus(pDMA, dmaItFlag);
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
  return 0x00;
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
  return __DEV_TODO;
#else
  return 0x00;
#endif
}

__STATIC_INLINE void ksDmaClrItPending(ksDMA_t *pDMA, ksU32 dmaItFlag)
{
#if   (__MCU_TYPE ==  _MCU_IS_STM32F10x)
  while(1);
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
  stm32f4xxDmaClearITPendingBit(pDMA, dmaItFlag);
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
  while(1);
#endif
}
#endif // __DMA_HAL_H_KENSKY_2019_6_23
