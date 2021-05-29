////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "softdevice.h"
/// * Author  : yangken
/// * Version :
/// * Date    : 2016-7-8
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_FF_3RDPTY_NRF51_52FWLIB_STANDARD_LIBS_SOFTDEVICE_SOFTDEVICE_H_YANGKEN_2016__
#define __LIBS_KSPERIPH_FF_3RDPTY_NRF51_52FWLIB_STANDARD_LIBS_SOFTDEVICE_SOFTDEVICE_H_YANGKEN_2016__

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
#include <projCfg.h>

#ifdef SOFTDEVICE_PRESENT

#include "./softdevice.h"
// #include "./common/inc/softdevice_handler.h"
#endif // SOFTDEVICE_PRESENT

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_FF_3RDPTY_NRF51_52FWLIB_STANDARD_LIBS_SOFTDEVICE_SOFTDEVICE_H_YANGKEN_2016__
