////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "NRF53822_BSP.h"
/// * Author  : yangken
/// * Version :
/// * Date    : 2016-6-1
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __APP_BSPS_01_PHY_NRF53822_INC_NRF53822_BSP_H_YANGKEN_2016__
#define __APP_BSPS_01_PHY_NRF53822_INC_NRF53822_BSP_H_YANGKEN_2016__

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
#include    <projCfg.h>

#ifndef __MCU_TYPE
#error MCU Type is not defined , please check!
#endif

#if (__MCU_TYPE == _MCU_IS_NRF52832)

#if (__uCOS_MODULE == _MODULE_ON)
  #include   "uCOS290_Driver.h"
#endif // (__uCOS_MODULE == _MODULE_ON)

#if (defined __RTT_MODULE) && (__RTT_MODULE == _MODULE_ON)
#include <rt_module.h>
#endif // (defined __RTT_MODULE) && (__RTT_MODULE == _MODULE_ON)

#if (defined __DELAY_MODULE ) &&(__DELAY_MODULE == _MODULE_ON)
#include    <delay.h>
#endif // (__DELAY_MODULE == _MODULE_ON)

#if (defined __KS_PERIPH_MODULE) && (__KS_PERIPH_MODULE == _MODULE_ON)
#include <ksPeriph.h>
#endif // (__KS_PERIPH_MODULE == _MODULE_ON)

#if (defined __RADIO_MODULE) && (__RADIO_MODULE == _MODULE_ON)
#include <rfChip.h>
#endif // (__TICC110x_MODULE == _MODULE_ON)

#if (__IR_MODULE == _MODULE_ON)

#endif // (__IR_MODULE == _MODULE_ON)

#if (__SPI_DEBUGGER_MODULE == _MODULE_ON)

#endif // (__SPI_DEBUGGER_MODULE == _MODULE_ON)

#if (__sFLASH_MODULE == _MODULE_ON)
#include <sFlash_Driver.h>
#endif // (__sFLASH_MODULE == _MODULE_ON)

#if (__TICCXXXx_MODULE == _MODULE_ON)
#include    <TI_CCXXXx_Driver.h>
#endif // (__TICC110x_MODULE == _MODULE_ON)

#if (__SMPL120_MODULE == _MODULE_ON)
//#include    "SMPL_Driver.h" // TODO
#endif // (__SMPL120_MODULE == _MODULE_ON)

#if (__KEYPADS_MODULE == _MODULE_ON)
#include    <Key_Driver.h>
#endif // (__KEYPADS_MODULE == _MODULE_ON)

#if (__LEDs_MODULE == _MODULE_ON)
#include    <LEDs_Driver.h>
#endif // (__LEDs_MODULE == _MODULE_ON)

#if (__MEMS_MODULE == _MODULE_ON)
#include <ksMems.h>
#endif // (__MEMS_MODULE == _MODULE_ON)

#if (__LWIP_MODULE == _MODULE_ON)

#endif

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// @fn     : mcuBSPInit
/// @param  : none
/// @return : description of return value.
/// @brief  : Brief description of the function.
/// @author : Kensky
/// @date   : 2016-1-8
/// @pre    : add precondition here if needed.
/// @note   : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
void mcuBSPInit (pISR tracerRxCB);

#endif // (__MCU_TYPE == _MCU_IS_NRF52832)

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __APP_BSPS_01_PHY_NRF53822_INC_NRF53822_BSP_H_yangken_2016__
