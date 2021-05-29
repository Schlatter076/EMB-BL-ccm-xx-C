////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "nrf51822Spi.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2016-3-4
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_RVPERIPH_00_SPI_1_PHY_NRF51822_INC_NRF51822SPI_H_KENSKY_2016__
#define __LIBS_RVPERIPH_00_SPI_1_PHY_NRF51822_INC_NRF51822SPI_H_KENSKY_2016__

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
#include "./nrf51822SpiInit.h"

#if (__MCU_TYPE == _MCU_IS_NRF51822)

#include "nrf51822SpiIsr.h"
#include "nrf51822SpiTxRxByte.h"

#endif // __MCU_TYPE

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_RVPERIPH_00_SPI_1_PHY_NRF51822_INC_NRF51822SPI_H_KENSKY_2016__
