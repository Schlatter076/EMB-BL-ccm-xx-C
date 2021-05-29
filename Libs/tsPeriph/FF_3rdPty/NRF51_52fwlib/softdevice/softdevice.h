////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "sofrdevice_110.h"
/// * Author  : yangken
/// * Version :
/// * Date    : 2016-7-8
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_FF_3RDPTY_NRF51_52FWLIB_STANDARD_LIBS_SOFTDEVICE_V110_SOFRDEVICE_110_H_yangken_2016__
#define __LIBS_KSPERIPH_FF_3RDPTY_NRF51_52FWLIB_STANDARD_LIBS_SOFTDEVICE_V110_SOFRDEVICE_110_H_yangken_2016__

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

#if   defined(S110)
#include "./v110/inc/ble.h"
#include "./v110/inc/ble_err.h"
#include "./v110/inc/ble_hci.h"
#include "./v110/inc/nrf_error_sdm.h"
#include "./v110/inc/nrf_error_soc.h"
#include "./v110/inc/nrf_mbr.h"
#include "./v110/inc/nrf_sd_def.h"
#include "./v110/inc/nrf_sdm.h"
#include "./v110/inc/softdevice_assert.h"
#elif defined(S132)
#include "./s132/headers/ble.h"
#include "./s132/headers/ble_err.h"
#include "./s132/headers/ble_hci.h"
#include "./s132/headers/nrf_error_sdm.h"
#include "./s132/headers/nrf_error_soc.h"
#include "./s132/headers/nrf_mbr.h"
#include "./s132/headers/nrf_sd_def.h"
#include "./s132/headers/nrf_sdm.h"
#endif // S110

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_FF_3RDPTY_NRF51_52FWLIB_STANDARD_LIBS_SOFTDEVICE_V110_SOFRDEVICE_110_H_yangken_2016__
