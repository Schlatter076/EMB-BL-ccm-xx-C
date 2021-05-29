////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "LDMA_EFR32yGxx.h"
/// * Author  : yangken
/// * Version :
/// * Date    : Oct 6, 2016
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_11_DMA_1_PHY_NRF52832_INC_EASYDMA_NRF52832_H_YANGKEN_2016__
#define __LIBS_KSPERIPH_11_DMA_1_PHY_NRF52832_INC_EASYDMA_NRF52832_H_YANGKEN_2016__

//*****************************************************************************
#ifdef  __cplusplus
//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
extern "C"
{
#endif // __cplusplus

/**** Includes ****************************************************************/
#include <11_DMA/1_PHY/NRF52832/inc/easyDMA_NRF52832_Init.h>

#if  (defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_NRF52832)

/***** Function Prototypes ****************************************************/
void  nrf52832DmaClkSw     (ksDMA_t *pDMA, ksState_e state);
ksS32 nrf52832DmaInit      (ksDMA_t *pDMA);
void  nrf52832DmaNvicInit  (ksDMA_t *pDMA, ksState_e  state);

#endif //(__MCU_TYPE == _MCU_IS_NRF52832)

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_11_DMA_1_PHY_NRF52832_INC_EASYDMA_NRF52832_H_YANGKEN_2016__
