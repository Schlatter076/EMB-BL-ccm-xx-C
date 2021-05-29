////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "ISR_NRF52832_Init.h"
/// * Author  : yangken
/// * Version :
/// * Date    : 2016-6-1
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_0A_ISR_1_PHY_NRF52832_INC_ISR_NRF52832_INIT_H_YANGKEN_2016__
#define __LIBS_KSPERIPH_0A_ISR_1_PHY_NRF52832_INC_ISR_NRF52832_INIT_H_YANGKEN_2016__

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
#include    "../../../4_CFG/ISR_cfg.h"

#if (__MCU_TYPE == _MCU_IS_NRF52832)
#include "../../../../FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h"

#endif // _MCU_IS_NRF51822

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_0A_ISR_1_PHY_NRF52832_INC_ISR_NRF52832_INIT_H_YANGKEN_2016__
