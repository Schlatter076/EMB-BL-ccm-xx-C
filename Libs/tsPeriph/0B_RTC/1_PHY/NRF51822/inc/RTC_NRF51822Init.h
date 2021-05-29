////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "RTC_NRF51822Init.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2016-1-14
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_0B_RTC_1_PHY_NRF51822_INC_RTC_NRF51822INIT_H_KENSKY_2016__
#define __LIBS_KSPERIPH_0B_RTC_1_PHY_NRF51822_INC_RTC_NRF51822INIT_H_KENSKY_2016__

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
#include    "../../../4_CFG/RTC_cfg.h"

#if ((__MCU_TYPE == _MCU_IS_NRF51822) || (__MCU_TYPE == _MCU_IS_NRF52832))

/**** Includes ****************************************************************/
#include "../../../../FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h"

/**** Defines *****************************************************************/
#define __NRF51822_RTC(rtc)           (((NRF_RTC_Type *)(rtc)->addrBase))

#define __NRF51822_ARR_INDEX          (0x00)
#define __NRF51822_CC0_INDEX          (0x00)
#define __NRF51822_CC1_INDEX          (0x01)
#define __NRF51822_CC2_INDEX          (0x02)
#define __NRF51822_CC3_INDEX          (0x03)

#define __NRF51822_TICK_FLAG          (0x0100u)
#define __NRF51822_OVR_FLAG           (0x0104u)
#define __NRF51822_ARR_FLAG           (0x0140u)
#define __NRF51822_CC0_FLAG           (0x0140u)
#define __NRF51822_CC1_FLAG           (0x0144u)
#define __NRF51822_CC2_FLAG           (0x0148u)
#define __NRF51822_CC3_FLAG           (0x014Cu)

/***** Function Prototypes ****************************************************/
ksRet_t nrf51822RtcInit (ksRTC_t *pRTC);

#endif // ((defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_NRF51822))

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_0B_RTC_1_PHY_NRF51822_INC_RTC_NRF51822INIT_H_KENSKY_2016__
