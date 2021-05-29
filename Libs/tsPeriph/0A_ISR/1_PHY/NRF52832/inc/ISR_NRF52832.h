////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "ISR_NRF52832.h"
/// * Author  : yangken
/// * Version :
/// * Date    : 2016-6-1
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_0A_ISR_1_PHY_NRF52832_INC_ISR_NRF52832_H_YANGKEN_2016__
#define __LIBS_KSPERIPH_0A_ISR_1_PHY_NRF52832_INC_ISR_NRF52832_H_YANGKEN_2016__

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
#include  "ISR_NRF52832_Init.h"

#if (__MCU_TYPE == _MCU_IS_NRF52832)

/***** DEFINES ****************************************************************/
#define     __NRF52832_Global_IRQ_ON()      st(asm volatile ("cpsie i");)
#define     __NRF52832_Global_IRQ_OFF()     st(asm volatile ("cpsid i");)
#define     __NRF52832_EN_CRITICAL(sr)      st(sr = __get_PRIMASK();\
                                               __NRF52832_Global_IRQ_OFF();)
#define     __NRF52832_EXIT_CRITICAL(sr)    st(__set_PRIMASK(sr);)

/***** PERIPH DEFINES *********************************************************/

/***** GLOBAL VARIABLES *******************************************************/

/***** MACRO'S ****************************************************************/

/***** FUNCTION PROTOTYPES ****************************************************/
void    NRF52832_ISR_Init                     (void);
void    NRF52832_ISRClr                       (ksIsrChn  int_id);
void    NRF52832_ISR_IntVectSet               (ksIsrChn  int_id,  pISR isr);

/***** INTERRUPT SERVICES *****************************************************/
__WEAK  void    yk_Spurious_ISR               (void);

__WEAK  void    Reset_Handler                 (void);
__WEAK  void    NMI_Handler                   (void);
__WEAK  void    HardFault_Handler             (void);
__WEAK  void    MemoryManagement_Handler      (void);
__WEAK  void    BusFault_Handler              (void);
__WEAK  void    UsageFault_Handler            (void);
__WEAK  void    SVC_Handler                   (void);
__WEAK  void    DebugMon_Handler              (void);
__WEAK  void    PendSV_Handler                (void);
__WEAK  void    SysTick_Handler               (void);

__WEAK  void    POWER_CLOCK_IRQHandler        (void);
__WEAK  void    RADIO_IRQHandler              (void);
__WEAK  void    UARTE0_UART0_IRQHandler       (void);
__WEAK  void    SPIMS0_TWI0_IRQHandler        (void);
__WEAK  void    SPIMS1_TWI1_IRQHandler        (void);
__WEAK  void    NFCT_IRQHandler               (void);
__WEAK  void    GPIOTE_IRQHandler             (void);
__WEAK  void    SAADC_IRQHandler              (void);
__WEAK  void    TIMER0_IRQHandler             (void);
__WEAK  void    TIMER1_IRQHandler             (void);
__WEAK  void    TIMER2_IRQHandler             (void);
__WEAK  void    RTC0_IRQHandler               (void);
__WEAK  void    TEMP_IRQHandler               (void);
__WEAK  void    RNG_IRQHandler                (void);
__WEAK  void    ECB_IRQHandler                (void);
__WEAK  void    CCM_AAR_IRQHandler            (void);
__WEAK  void    WDT_IRQHandler                (void);
__WEAK  void    RTC1_IRQHandler               (void);
__WEAK  void    QDEC_IRQHandler               (void);
__WEAK  void    COMP_LPCOMP_IRQHandler        (void);
__WEAK  void    SWI0_EGU0_IRQHandler          (void);
__WEAK  void    SWI1_EGU1_IRQHandler          (void);
__WEAK  void    SWI2_EGU2_IRQHandler          (void);
__WEAK  void    SWI3_EGU3_IRQHandler          (void);
__WEAK  void    SWI4_EGU4_IRQHandler          (void);
__WEAK  void    SWI5_EGU5_IRQHandler          (void);

__WEAK  void    TIMER3_IRQHandler             (void);
__WEAK  void    TIMER4_IRQHandler             (void);
__WEAK  void    PWM0_IRQHandler               (void);
__WEAK  void    PDM_IRQHandler                (void);
__WEAK  void    MWU_IRQHandler                (void);
__WEAK  void    PWM1_IRQHandler               (void);
__WEAK  void    PWM2_IRQHandler               (void);
__WEAK  void    SPI2_IRQHandler               (void);
__WEAK  void    RTC2_IRQHandler               (void);
__WEAK  void    I2S_IRQHandler                (void);
__WEAK  void    FPU_IRQHandler                (void);

#define  NRF52832_INT_SRC_NBR                 (39)
#endif // _MCU_IS_NRF51822

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_0A_ISR_1_PHY_NRF52832_INC_ISR_NRF52832_H_yangken_2016__
