////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "extiNrf51822.h"
/// * Author  : yangken
/// * Version :
/// * Date    : Mar 1, 2017
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_RVPERIPH_06_EXTI_1_PHY_NRF51822_INC_EXTINRF51822_H_yangken_2017__
#define __LIBS_RVPERIPH_06_EXTI_1_PHY_NRF51822_INC_EXTINRF51822_H_yangken_2017__

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

#if (__MCU_TYPE == _MCU_IS_NRF51822)

/***** Function Prototypes ****************************************************/
void  nrf51822ExtiDeInit  (void);
ksS32 nrf51822ExtiInit    (ksEXTI_t *exti);
void  nrf51822ExtiBindIO  (const ksGPIO_t *IO);

#endif // __MCU_TYPE

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_RVPERIPH_06_EXTI_1_PHY_NRF51822_INC_EXTINRF51822_H_yangken_2017__
