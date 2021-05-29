////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "nrf52832Spi.h"
/// * Author  : yangken
/// * Version :
/// * Date    : Feb 28, 2017
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_RVPERIPH_00_SPI_1_PHY_NRF52832_INC_NRF52832SPI_H_yangken_2017__
#define __LIBS_RVPERIPH_00_SPI_1_PHY_NRF52832_INC_NRF52832SPI_H_yangken_2017__

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
#include "./nrf52832SpiInit.h"

#if (__MCU_TYPE == _MCU_IS_NRF52832)

#include "nrf52832SpiIsr.h"
#include "nrf52832SpiTxRxByte.h"

#endif

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_RVPERIPH_00_SPI_1_PHY_NRF52832_INC_NRF52832SPI_H_yangken_2017__
