////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "nrf51822UsartTxU08.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2016-1-20
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_01_USART_1_PHY_NRF51822_INC_NRF51822USARTTXU08_H_KENSKY_2016__
#define __LIBS_KSPERIPH_01_USART_1_PHY_NRF51822_INC_NRF51822USARTTXU08_H_KENSKY_2016__

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

#if ((__MCU_TYPE ==  _MCU_IS_NRF51822) || (__MCU_TYPE ==  _MCU_IS_NRF52832))
/**** Includes ****************************************************************/
#include "../../../../FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h"

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// @fn         : nrf51822UsartTxU08
/// @param      : USART :
/// @param      : Byte  :
/// @return     : description of return value.
/// @brief      : sent a byte through the USART interface
/// @author     : kensky
/// @date       : 2014-11-27
/// @pre        : add precondition here if needed.
/// @note       : tested
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void nrf51822UsartTxU08 (ksUSART_t *USART, uint16_t Byte)
{
  // tested befor : __KS_RUNTIME_ASSERT(USART->addrBase == (ksAddr_t)NRF_UART0, __ASSERT_NULL);

  NRF_UART0->EVENTS_TXDRDY  = 0x00;
  NRF_UART0->TXD            = (Byte & 0xFF); /* Transmit Data */
  while(!NRF_UART0->EVENTS_TXDRDY);
}

#endif // (__MCU_TYPE ==  _MCU_IS_NRF51822)

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_01_USART_1_PHY_NRF51822_INC_NRF51822USARTTXU08_H_KENSKY_2016__
