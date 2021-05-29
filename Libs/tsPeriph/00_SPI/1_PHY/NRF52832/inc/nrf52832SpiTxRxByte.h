////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "nrf52832SpiTxRxByte.h"
/// * Author  : yangken
/// * Version :
/// * Date    : Feb 28, 2017
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_RVPERIPH_00_SPI_1_PHY_NRF52832_INC_NRF52832SPITXRXBYTE_H_YANGKEN_2017__
#define __LIBS_RVPERIPH_00_SPI_1_PHY_NRF52832_INC_NRF52832SPITXRXBYTE_H_YANGKEN_2017__

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

/**** Defines *****************************************************************/
#if   (__MCU_TYPE == _MCU_IS_NRF51822)
#define     __SPI_RDY_TO_SEND(spi)      while((spi)->EVENTS_READY)
#define     __SPI_RDY_TO_READ(spi)      while(!(spi)->EVENTS_READY)
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#define     __SPI_RDY_TO_SEND(spi)      while((spi)->EVENTS_READY)
#define     __SPI_RDY_TO_READ(spi)      while(!(spi)->EVENTS_READY)
#endif

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : nrf52832SpiTxByte
/// @param      : pSpi : the spi object
/// @param      : Byte : byte to be transferred
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
void nrf52832SpiTxByte (const ksSPI_t *pSpi, ksU08 Byte);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : nrf52832SpiRxByte
/// @param      : pSpi : the spi object
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
ksU08 nrf52832SpiRxByte(const ksSPI_t *pSpi);

////////////////////////////////////////////////////////////////////////////////
/// @fn     : nrf52832SpiTxRxByte
/// @param  : pSpi : the spi object
/// @param  : Byte : the byte to be transferred
/// @return : the byte retrieved
/// @brief  : Brief description of the function.
/// @author : Kensky
/// @date   : Oct 5, 2016
/// @pre    : add precondition here if needed.
/// @note   : v1.0 MSB first
////////////////////////////////////////////////////////////////////////////////
ksU08 nrf52832SpiTxRxByte (const ksSPI_t *pSpi, ksU08 Byte);

/*******************************************************************************
*  Func_Name: nrf52832SpiTxRxBytes
*  Paras    : SPI        ：SPI Info
*             pBytes     ： data sent thru SPI(8bits)
*             size       ： how many bytes
*  Returns  : Byte       ：data get from SPI (8bits)
*  Brief    : send and get data thru SPI bus
*  Build on : 24/03/12
*  Note(s)  : v1.0 MSB first
*******************************************************************************/
void nrf52832SpiTxRxBytes (const
                            ksSPI_t *pSpi,
                            const
                            ksU08   *pTxBytes,
                            ksU08   *pRxBytes,
                            ksU32   size);

/*******************************************************************************
*  Func_Name: nrf52832SpiTxBytes
*  Paras    : SPI        ：SPI Info
*             pBytes     ： data sent thru SPI(8bits)
*             size       ： how many bytes
*  Returns  : Byte       ：data get from SPI (8bits)
*  Brief    : send and get data thru SPI bus
*  Build on : 24/03/12
*  Note(s)  : v1.0 MSB first
*******************************************************************************/
void nrf52832SpiTxBytes (const
                         ksSPI_t *pSpi,
                         const
                         ksU08   *pTxBytes,
                         ksU32   txSize);

/*******************************************************************************
*  Func_Name: nrf52832SpiRxBytes
*  Paras    : SPI        ：SPI Info
*             pBytes     ： data sent thru SPI(8bits)
*             size       ： how many bytes
*  Returns  : Byte       ：data get from SPI (8bits)
*  Brief    : send and get data thru SPI bus
*  Build on : 24/03/12
*  Note(s)  : v1.0 MSB first
*******************************************************************************/
void nrf52832SpiRxBytes (const
                         ksSPI_t *pSpi,
                         ksU08   *pRxBytes,
                         ksU32   rxSize);

#endif

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_RVPERIPH_00_SPI_1_PHY_NRF52832_INC_NRF52832SPITXRXBYTE_H_YANGKEN_2017__
