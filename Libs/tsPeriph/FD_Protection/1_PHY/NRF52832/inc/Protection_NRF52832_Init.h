////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "Protection_NRF52832_Init.h"
/// * Author  : yangken
/// * Version :
/// * Date    : Apr 16, 2017
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_FD_PROTECTION_1_PHY_NRF52832_INC_PROTECTION_NRF52832_INIT_H_YANGKEN_2017__
#define __LIBS_KSPERIPH_FD_PROTECTION_1_PHY_NRF52832_INC_PROTECTION_NRF52832_INIT_H_YANGKEN_2017__

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
#include "../../../4_CFG/Protection_cfg.h"

#if (__MCU_TYPE == _MCU_IS_NRF52832)
#include "../../../../FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h"

/**** Defines *****************************************************************/
// todo : not tested
#define     M__UUID_WIDTH         (64)    // bits
#define     M__USER_OPB_ADDR      ((ksU32*)0x1FFFF800ul)
#define     M__USER_OPB_SIZE      (16ul)  // bytes
// little endian
#define     M__UUID_ADDR_0        ((ksU32*)0x10000060ul)
#define     M__UUID_ADDR_1        ((ksU32*)0x10000064ul)

#define     M__OPB_ADDR           ((ksU32*)0x1FFFF800ul)

#endif // __MCU_TYPE

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_FD_PROTECTION_1_PHY_NRF52832_INC_PROTECTION_NRF52832_INIT_H_YANGKEN_2017__
