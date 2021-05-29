////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "Protection_DDL.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __PROTECTION_DDL_H_KEN_2020_9_25
#define __PROTECTION_DDL_H_KEN_2020_9_25

/**** Includes ****************************************************************/
#include "../../1_PHY/Common/inc/Protection_PHY.h"

#ifndef __MCU_TYPE
#error "please specify yhe MCU type in the 1st place"
#endif

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _rvMcuDDLGetUUID
/// @param      : pIdRet : inout parameter to retrieve the uuid in 128 bits
/// @return     : ksUUID128_u pIdRet.
/// @brief      : get the uuid of STM32L in 128 bit
/// @author     : kensky
/// @date       : 2014-3-14
/// @pre        : add precondition here if needed.
/// @note       : the uuid of stm32l is actually 96bit
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void _rvMcuDDLGetUUID(ksUUID128_u *pIdRet)
{
#if 	(__MCU_TYPE == _MCU_IS_STM32L1x)
  __stm32L1xxGetUuid(pIdRet);
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
  __EFM32YYxxGetUuid128(pIdRet);
#elif (__MCU_TYPE == _MCU_IS_STM32F10x)
  __stm32F1xxGetUuid128(pIdRet);
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
  __stm32L0xxGetUuid (pIdRet);
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
  __NRF51822GetUuid128(pIdRet);
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
  FSKLxxZyyyGetUuid128(pIdRet);
#endif

  int pos;

  for (pos=0; pos<8; ++pos)
  { // swap for the 1st time
#if 0
    swap                   = pIdRet->id08[pos];
    pIdRet->id08[pos]      = pIdRet->id08[15-pos];
    pIdRet->id08[15-pos]   = swap;
#else
    pIdRet->id08[pos]     ^= pIdRet->id08[15-pos];
    pIdRet->id08[15-pos]  ^= pIdRet->id08[pos];
    pIdRet->id08[pos]     ^= pIdRet->id08[15-pos];
#endif
  }

  for (pos=0; pos<8; ++pos)
  { // swap for the 2nd time
    int j = pos<<1;

#if 0
    swap               = pIdRet->id08[j];
    pIdRet->id08[j]    = pIdRet->id08[j+1];
    pIdRet->id08[j+1]  = swap;
#else
    pIdRet->id08[j]   ^= pIdRet->id08[j+1];
    pIdRet->id08[j+1] ^= pIdRet->id08[j];
    pIdRet->id08[j]   ^= pIdRet->id08[j+1];

#endif
  }

  for (pos=0; pos<8; ++pos)
  { // swap for the 3rd time
#if 0
    swap                 = pIdRet->id08[pos];
    pIdRet->id08[pos]    = pIdRet->id08[pos+8];
    pIdRet->id08[pos+8]  = swap;
#else
    pIdRet->id08[pos]   ^= pIdRet->id08[pos+8];
    pIdRet->id08[pos+8] ^= pIdRet->id08[pos];
    pIdRet->id08[pos]   ^= pIdRet->id08[pos+8];
#endif
  }
}

#endif // __PROTECTION_DDL_H_KEN_2020_9_25
