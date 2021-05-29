////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "LPWR_NRF51822_Init.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2016-1-16
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_0F_LPWR_1_PHY_NRF51822_INC_LPWR_NRF51822_INIT_H_KENSKY_2016__
#define __LIBS_KSPERIPH_0F_LPWR_1_PHY_NRF51822_INC_LPWR_NRF51822_INIT_H_KENSKY_2016__

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

#if ((defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_NRF51822))

/**** Includes ****************************************************************/
#include "../../../../FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h"

/***** Function Prototypes ****************************************************/
void nrf51822LpwrInitGpio (void);
void nrf51822Standby      (void);
void nrf51822Stop         (ksU32 regulator, ksU08 mode);
void nrf51822Sleep        (void);

#endif // ((defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_NRF51822))

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_0F_LPWR_1_PHY_NRF51822_INC_LPWR_NRF51822_INIT_H_KENSKY_2016__
