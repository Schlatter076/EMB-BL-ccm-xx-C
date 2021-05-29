////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "LPWR_HAL.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LPWR_HAL_H_KENSKY_2013_3_27
#define __LPWR_HAL_H_KENSKY_2013_3_27

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/LPWR_DDL.h"

/**** Defines *****************************************************************/
#if  ((__MCU_TYPE == _MCU_IS_STM32F10x)  || \
     (__MCU_TYPE == _MCU_IS_STM32L1x)   || \
     (__MCU_TYPE == _MCU_IS_STN32F0xx)  || \
     (__MCU_TYPE == _MCU_IS_STM32L0x)  || \
     (__MCU_TYPE == _MCU_IS_EFM32TGxxx) || \
     (__MCU_TYPE == _MCU_IS_EFM32Gxxx)  || \
     (__MCU_TYPE == _MCU_IS_NRF51822)   || \
     (__MCU_TYPE == _MCU_IS_NRF52832)   || \
     (__MCU_TYPE == _MCU_IS_TI_CC13XX)  || \
     (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx))
#define   __PWR_WHEN_SLEEP(sw)        while((sw)) \
                                      {\
                                         SCB->SCR &= (uint32_t)~((uint32_t)SCB_SCR_SLEEPDEEP_Msk); \
                                         __WFI(); \
                                      }
#define   __PWR_WHEN_STOP(sw)        while((sw)) \
                                      {\
                                         SCB->SCR |= ((uint32_t)SCB_SCR_SLEEPDEEP_Msk); \
                                         __WFI(); \
                                      }
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error "not supported for now!"
#endif

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksMcuSleep
/// @param      : NONE
/// @return     : NONE
/// @brief      : the mcu will sleep here
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
void ksMcuSleep(void);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksMcuStandby
/// @param      : NONE
/// @return     : NONE
/// @brief      : the mcu will standby here
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
void ksMcuStandby(void);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksMcuStop
/// @param      : NONE
/// @return     : NONE
/// @brief      : the mcu wiil stop here
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
void ksMcuStop(void);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksMcuLpwrInitGpio
/// @param      : none
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-6-16
/// @pre        : add precondition here if needed.
/// @note       : it's tested for STM32L151C8, pay attention to PB7

////////////////////////////////////////////////////////////////////////////////
void ksMcuLpwrInitGpio(void);

#endif // __LPWR_HAL_H_KENSKY_2013_3_27
