////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "nrf51_52_expansion.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2016-1-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_FF_3RDPTY_NRF51_52FWLIB_NRF51_52_EXPANSION_H_KENSKY_2016__
#define __LIBS_KSPERIPH_FF_3RDPTY_NRF51_52FWLIB_NRF51_52_EXPANSION_H_KENSKY_2016__

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
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf/inc/ble_flash.h"
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf/inc/nrf_adc.h"
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf/inc/nrf_saadc.h"
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf_drv/inc/nrf_drv_gpiote.h"
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf_drv/inc/nrf_drv_clock.h"
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf_drv/inc/nrf_drv_ppi.h"
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf_drv/inc/nrf_drv_spi.h"
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf_drv/inc/nrf_drv_rtc.h"
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf_drv/inc/nrf_drv_rng.h"
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf/inc/nrf_delay.h"
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf/inc/nrf_nvmc.h"
#if defined (UART_PRESENT)
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf/inc/nrf_uart.h"
#endif
#if defined (UARTE_PRESENT)
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf/inc/nrf_uarte.h"
#endif

#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf_drv/inc/nrf_drv_saadc.h"
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/drivers/twi_master/inc/twi_master.h"

#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/nrf/inc/nrf51_52_it.h"

#include  "./libraries/bsp/inc/bsp.h"
#include  "./libraries/timer/inc/app_timer.h"
#include  "./libraries/log/inc/nrf_log.h"
#include  "./libraries/log/inc/nrf_log_ctrl.h"
#include  "./libraries/pwr_mgmt/nrf_pwr_mgmt.h"

#include  "./pca10040.h"

#if   (defined(NRF52))
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/config/nRF52/inc/system_nrf52.h"
#elif (defined(NRF51))
#include  "./standard_Libs/nrf51_52_StdPeriph_Driver/config/nRF51/inc/system_nrf51.h"
#endif


#ifdef SOFTDEVICE_PRESENT
#include  "./softdevice/softdeviceApi.h"
#include  "./softdevice/common/inc/nrf_sdh.h"
#include  "./softdevice/common/inc/nrf_sdh_ble.h"
#include  "./components/ble/common/ble_advdata.h"
#include  "./components/ble/common/ble_conn_params.h"
#include  "./components/ble/ble_services/ble_lbs/ble_lbs.h"
#include  "./components/ble/ble_services/ble_dis/ble_dis.h"
#include  "./components/ble/ble_services/ble_nus/ble_nus.h"
#include  "./components/ble/ble_advertising/ble_advertising.h"
#include  "./components/ble/nrf_ble_gatt/nrf_ble_gatt.h"
#include  "./components/ble/nrf_ble_qwr/nrf_ble_qwr.h"
#endif // SOFTDEVICE_PRESENT

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_FF_3RDPTY_NRF51_52FWLIB_NRF51_52_EXPANSION_H_KENSKY_2016__
