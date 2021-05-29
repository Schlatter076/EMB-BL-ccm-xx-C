////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "Protection_NRF51822.h"
/// * Author  : yangken
/// * Version :
/// * Date    : 2016-6-14
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_FD_PROTECTION_1_PHY_NRF51822_INC_PROTECTION_NRF51822_H_YANGKEN_2016__
#define __LIBS_KSPERIPH_FD_PROTECTION_1_PHY_NRF51822_INC_PROTECTION_NRF51822_H_YANGKEN_2016__

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
#include "./Protection_NRF51822_Init.h"

#if (__MCU_TYPE == _MCU_IS_NRF51822)

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : __NRF51822GetUuid128
/// @param      : uuid : inout parameter to store the retrieved uuid
/// @return     : ksUUID128_u uuid.
/// @brief      : get the uuid of STM32F10x in 128 bits
/// @author     : kensky
/// @date       : 2014-3-14
/// @pre        : add precondition here if needed.
/// @note       : the uuid of stm32f10x is actually 96bit,
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE
void __NRF51822GetUuid128 (ksUUID128_u *uuid)
{
  uuid->id32[0] = *(ksU32*)(M__UUID_ADDR_0);
  uuid->id32[1] = *(ksU32*)(M__UUID_ADDR_1);
  uuid->id32[2] = *(ksU32*)(M__UUID_ADDR_0);
  uuid->id32[3] = *(ksU32*)(M__UUID_ADDR_1);
}

void  nrf51822NvmProtect   (ksU32 regionSize);
ksS32 nrf51822SwdDisable   (void);
void  nrf51822SwdRestore   (void);

#endif // __MCU_TYPE

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_FD_PROTECTION_1_PHY_NRF51822_INC_PROTECTION_NRF51822_H_YANGKEN_2016__
