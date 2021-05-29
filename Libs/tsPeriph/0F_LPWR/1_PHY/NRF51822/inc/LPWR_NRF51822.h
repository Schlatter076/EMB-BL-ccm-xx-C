////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "LPWR_NRF51822.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2016-1-16
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_0F_LPWR_1_PHY_NRF51822_INC_LPWR_NRF51822_H_KENSKY_2016__
#define __LIBS_KSPERIPH_0F_LPWR_1_PHY_NRF51822_INC_LPWR_NRF51822_H_KENSKY_2016__

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
#include "./LPWR_NRF51822_Init.h"

#if ((defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_NRF51822))

#define __MCU_STOP_TEST(sw)       st(while((sw))                        \
                                   {                                    \
                                     SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk; \
                                     __WFI();                           \
                                     asm("nop");                        \
                                   };)
#define __MCU_SLEEP_TEST(sw)      st(while((sw))                        \
                                   {                                    \
                                     SCB->SCR &=~SCB_SCR_SLEEPDEEP_Msk; \
                                     __WFI();                           \
                                     asm("nop");                        \
                                   };)

#define __MCU_RUN_TEST(sw)        st(while((sw))                        \
                                   {                                    \
                                     asm("nop");                        \
                                   };)

#endif // __MCU_TYPE

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_0F_LPWR_1_PHY_NRF51822_INC_LPWR_NRF51822_H_KENSKY_2016__
