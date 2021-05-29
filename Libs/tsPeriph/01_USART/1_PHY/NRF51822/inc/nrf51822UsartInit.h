////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "nrf51822UsartInit.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2016-1-20
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_01_USART_1_PHY_NRF51822_INC_NRF51822USARTINIT_H_KENSKY_2016__
#define __LIBS_KSPERIPH_01_USART_1_PHY_NRF51822_INC_NRF51822USARTINIT_H_KENSKY_2016__

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
#include    <01_USART/4_CFG/USART_cfg.h>
#include    <04_GPIO/GPIO_Driver.h>

#if ((__MCU_TYPE ==  _MCU_IS_NRF51822) ||  (__MCU_TYPE ==  _MCU_IS_NRF52832))
/**** Includes ****************************************************************/
#include "../../../../FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h"

/***** Function Prototypes ****************************************************/
ksS32   nrf51822UsartSwitch     (ksUSART_t *USARTx, ksUSART_State_e isEnable);
ksS32   nrf52832UarteSwitch     (ksUSART_t *USARTx, ksUSART_State_e isEnable);
void    nrf51822UsartGetChn     (ksUSART_t *USARTx);
void    nrf51822UsartDeInit     (ksUSART_t *USARTx);
ksS32   nrf51822UsartInit       (ksUSART_t *USARTx);
void    nrf51822UsartGetIsrId   (ksUSART_t *USARTx);

#endif // (__MCU_TYPE ==  _MCU_IS_NRF51822)

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_01_USART_1_PHY_NRF51822_INC_NRF51822USARTINIT_H_KENSKY_2016__
