////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "LPWR_NRF52832.h"
/// * Author  : yangken
/// * Version :
/// * Date    : Feb 23, 2017
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_0F_LPWR_1_PHY_NRF52832_INC_LPWR_NRF52832_H_YANGKEN_2017__
#define __LIBS_KSPERIPH_0F_LPWR_1_PHY_NRF52832_INC_LPWR_NRF52832_H_YANGKEN_2017__

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
#include "./LPWR_NRF52832_Init.h"

#if ((defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_NRF52832))

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

#endif // __LIBS_KSPERIPH_0F_LPWR_1_PHY_NRF52832_INC_LPWR_NRF52832_H_YANGKEN_2017__
