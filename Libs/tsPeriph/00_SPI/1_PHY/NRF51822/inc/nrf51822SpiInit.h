////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "SPI_NRF51822_Init.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2016-3-4
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_RVPERIPH_00_SPI_1_PHY_NRF51822_INC_SPI_NRF51822_INIT_H_KENSKY_2016__
#define __LIBS_RVPERIPH_00_SPI_1_PHY_NRF51822_INC_SPI_NRF51822_INIT_H_KENSKY_2016__

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
#include <00_SPI/4_CFG/SPI_cfg.h>

#if (__MCU_TYPE == _MCU_IS_NRF51822)

/***** Function Prototypes ****************************************************/
void  nrf51822SpiGetCHn   (ksSPI_t *pSpi);
ksS32 nrf51822SpiSw       (ksSPI_t *pSpi, ksSPI_State_e state);
ksS32 nrf51822SpiClkSw    (ksSPI_t *pSpi, ksSPI_State_e state);
void  nrf51822SpiDeInit   (ksSPI_t *pSpi);
ksS32 nrf51822SpiInit     (ksSPI_t *pSpi);
void  nrf51822SpiGetIsrId (ksSPI_t *pSpi);

#endif // __MCU_TYPE

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_RVPERIPH_00_SPI_1_PHY_NRF51822_INC_SPI_NRF51822_INIT_H_KENSKY_2016__
