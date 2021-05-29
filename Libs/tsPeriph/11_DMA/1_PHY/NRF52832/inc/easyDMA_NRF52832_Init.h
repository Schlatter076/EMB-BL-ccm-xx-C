////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "LDMA_EFR32yGxx_Init.h"
/// * Author  : yangken
/// * Version :
/// * Date    : Oct 6, 2016
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_11_DMA_1_PHY_NRF52832_INC_EASYDMA_NRF52832_INIT_H_YANGKEN_2016__
#define __LIBS_KSPERIPH_11_DMA_1_PHY_NRF52832_INC_EASYDMA_NRF52832_INIT_H_YANGKEN_2016__

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
#include "../../../4_CFG/DMA_cfg.h"

#if  (defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_NRF52832)
#include "../../../../FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h"

/**** Defines *****************************************************************/
#define     __NRF52832_DMA_IT_GI_OS            (0)
#define     __NRF52832_DMA_IT_TC_OS            (1)
#define     __NRF52832_DMA_IT_HT_OS            (2)
#define     __NRF52832_DMA_IT_TE_OS            (3)

#endif //(__MCU_TYPE == _MCU_IS_NRF52832)

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_11_DMA_1_PHY_NRF52832_INC_EASYDMA_NRF52832_INIT_H_YANGKEN_2016__
