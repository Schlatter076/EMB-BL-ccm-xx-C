////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "SPI_RegHandle.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2015-5-1
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_RVPERIPH_00_SPI_3_HAL_INC_SPI_REGHANDLE_H_KENSKY_2015__
#define __LIBS_RVPERIPH_00_SPI_3_HAL_INC_SPI_REGHANDLE_H_KENSKY_2015__

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
#include "../../2_DDL/inc/SPI_DDL.h"

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// @fn         : ykSpiClrITfalg
/// @param      : SPIx    :
/// @param      : isrFlag :
/// @return     : description of return value.
/// @brief      : clear the interrupt pending bits
/// @author     : kensky
/// @date       : 2014-11-26
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
void ykSpiClrITfalg (ksSPI_t *SPIx, ksU32 isrFlag);

////////////////////////////////////////////////////////////////////////////////
/// @fn         : ykSpiGetITfalg
/// @param      : SPIx    :
/// @param      : isrFlag :
/// @return     : description of return value.
/// @brief      : get the interrupt pending bits
/// @author     : kensky
/// @date       : 2014-11-27
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
ksU08 ykSpiGetITfalg (ksSPI_t *SPIx, ksU32 isrFlag);

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_RVPERIPH_00_SPI_3_HAL_INC_SPI_REGHANDLE_H_KENSKY_2015__
