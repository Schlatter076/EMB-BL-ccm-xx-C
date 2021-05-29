////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "Protection_NRF52832.h"
/// * Author  : yangken
/// * Version :
/// * Date    : Apr 16, 2017
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_FD_PROTECTION_1_PHY_NRF52832_INC_PROTECTION_NRF52832_H_YANGKEN_2017__
#define __LIBS_KSPERIPH_FD_PROTECTION_1_PHY_NRF52832_INC_PROTECTION_NRF52832_H_YANGKEN_2017__

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
#include "Protection_NRF52832_Init.h"

#if (__MCU_TYPE == _MCU_IS_NRF52832)

ksS32 nrf52832SwdDisable (void);

#endif // __MCU_TYPE

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_FD_PROTECTION_1_PHY_NRF52832_INC_PROTECTION_NRF52832_H_YANGKEN_2017__
