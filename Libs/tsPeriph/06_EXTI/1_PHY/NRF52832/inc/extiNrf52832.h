////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "extiNrf52832.h"
/// * Author  : yangken
/// * Version :
/// * Date    : Mar 1, 2017
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_RVPERIPH_06_EXTI_1_PHY_NRF52832_INC_EXTINRF52832_H_YANGKEN_2017__
#define __LIBS_RVPERIPH_06_EXTI_1_PHY_NRF52832_INC_EXTINRF52832_H_YANGKEN_2017__

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
#include "../../Common/inc/EXTI_Common.h"

#if (__MCU_TYPE == _MCU_IS_NRF52832)

#include "../../../../FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h"

/***** Function Prototypes ****************************************************/
void  nrf52832ExtiDeInit  (void);
ksS32 nrf52832ExtiInit    (ksEXTI_t *exti);
void  nrf52832ExtiBindIO  (const ksGPIO_t *IO);

#endif

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_RVPERIPH_06_EXTI_1_PHY_NRF52832_INC_EXTINRF52832_H_YANGKEN_2017__
