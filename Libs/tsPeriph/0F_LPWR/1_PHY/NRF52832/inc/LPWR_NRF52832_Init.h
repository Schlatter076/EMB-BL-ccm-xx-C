////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "LPWR_NRF52832_Init.h"
/// * Author  : yangken
/// * Version :
/// * Date    : Feb 23, 2017
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_0F_LPWR_1_PHY_NRF52832_INC_LPWR_NRF52832_INIT_H_YANGKEN_2017__
#define __LIBS_KSPERIPH_0F_LPWR_1_PHY_NRF52832_INC_LPWR_NRF52832_INIT_H_YANGKEN_2017__

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
#include "../../../4_CFG/LPWR_cfg.h"

#if ((defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_NRF52832))

/**** Includes ****************************************************************/
#include "../../../../FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h"

/***** Function Prototypes ****************************************************/
void nrf52832LpwrInitGpio (void);
void nrf52832Standby      (void);
void nrf52832Stop         (ksU32 regulator, ksU08 mode);
void nrf52832Sleep        (void);

#endif

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_0F_LPWR_1_PHY_NRF52832_INC_LPWR_NRF52832_INIT_H_YANGKEN_2017__
