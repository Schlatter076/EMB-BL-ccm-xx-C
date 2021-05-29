////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "nrf52832SpiInit.h"
/// * Author  : yangken
/// * Version :
/// * Date    : Feb 28, 2017
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_RVPERIPH_00_SPI_1_PHY_NRF52832_INC_NRF52832SPIINIT_H_YANGKEN_2017__
#define __LIBS_RVPERIPH_00_SPI_1_PHY_NRF52832_INC_NRF52832SPIINIT_H_YANGKEN_2017__

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

#if (__MCU_TYPE == _MCU_IS_NRF52832)

/***** Function Prototypes ****************************************************/
void  nrf52832SpiGetCHn   (ksSPI_t *pSpi);
ksS32 nrf52832SpiSw       (ksSPI_t *pSpi, ksSPI_State_e state);
ksS32 nrf52832SpiClkSw    (ksSPI_t *pSpi, ksSPI_State_e state);
void  nrf52832SpiDeInit   (ksSPI_t *pSpi);
ksS32 nrf52832SpiInit     (ksSPI_t *pSpi);
void  nrf52832SpiGetIsrId (ksSPI_t *pSpi);

#endif

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_RVPERIPH_00_SPI_1_PHY_NRF52832_INC_NRF52832SPIINIT_H_yangken_2017__
