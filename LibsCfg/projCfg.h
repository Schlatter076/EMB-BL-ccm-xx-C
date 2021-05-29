/*******************************************************************************
  * File    : "Proj_cfg.h"
  * Author  : kensky
  * Version :
  * Date    : 2020-2-2
  * Brief   : There will always be such a global cfg file like this one in each
              project being developed, which can configure necessary parameters
              controlling the behaviors of the program. Though developers ,with
              much experience and knowledge about the modules, can still use
              individual cfg file in each module, it will be much more convenient
              and clear to handle those parameters here!
*******************************************************************************/
#ifndef   __PROJECT_CONFIGURATION_H_20120114YK
#define   __PROJECT_CONFIGURATION_H_20120114YK

/**** Includes ****************************************************************/
#include "./Proj_cfg/inc/projSpec.h"
#include "./Proj_cfg/inc/projRetValue.h"
#include "./Proj_cfg/inc/projCompiler.h"

extern volatile unsigned char gv_testBreakPoint;

// NRF51822, sniffer
/**** Defines *****************************************************************/
#define __UUIDx                 (0xB0E1519531002495ull)

#ifdef __UUID
// #define __PID_LST_BYTE_GLOBAL   (0x23)
#define __UUID0                 (__UUID)
#define __UUID1                 (0x91198E9928445F81ull)
#endif // __UUID

#define __ADDR_FREE_MEM         (0x20003400)

/**** MCU Interface ***********************************************************/
#define __MCU_TYPE              (_MCU_IS_NRF52832)

#if 	(__MCU_TYPE == _MCU_IS_STM32L0xx)
#define __MCU_CLKSRC            /* __RCC_HSID1_NPLL_STM32L0 // __RCC_HSID1_NPLL_LSE_STM32L0 // */ /* __RCC_2_10MHZ_MSI_LSE_STM32L0 // */ __RCC_4_20MHZ_LSE_STM32L0
#elif (__MCU_TYPE == _MCU_IS_STM32L0xx)
#define __MCU_SYSCLK            __RCC_72MHZ_HSE25_PLL_CL
#define __MCU_FREQ              (72000000ul)
#define HSE_VALUE               (25000000ul)
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#define __MCU_CLKSRC            __RCC_HSI14_LSE_EFM32TGxx
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#define __MCU_FREQ              (40000000ul)
#define HSE_VALUE               (40000000ul)
#define __MCU_CLKSRC            __RCC_HSED1_NPLL_EFR32yGxx
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#define __MCU_FREQ              (16000000ul)
#define HSE_VALUE               (16000000ul)
// __MCU_CLKSRC : not necessary
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#define __MCU_FREQ              (64000000ul)
#define HSE_VALUE               (32000000ul)
// __MCU_CLKSRC : not necessary
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#define __MCU_FREQ              (64000000ul)
#define HSE_VALUE               (32000000ul)
#else
#error "please specify the mcu type"
#endif

#define __MCU_ADDR_SPACE        (_MCU_IS_32_BITS)
#define __MCU_LPWR_STRATEGY     (_MCU_LPWR_STOP)

#define ICACHE_FLASH_ATTR
#define ICACHE_RODATA_ATTR

#define __EN_RAM_EXECUTIONx

/**** module switch ***********************************************************/
/*******************************************************************************
 *                      Global configuration SW
 *  If the MACRO below has been defined, the current configuration file will
 *  override all other configuration files in each module separately.
 *  So, developer can make global configuration just in the same location, which
 *  will considerably make configuration easier and clearer.
*******************************************************************************/
#define __PROJ_CONFIGURATION    (_GLOBAL_CONFIGURED)
#define __RLEASE_MODE           (_MODULE_OFF) // */ (_MODULE_ON)
#define __KS_PERIPH_MODULE      /* (_MODULE_OFF)  // */ (_MODULE_ON)
#define __TRACER_MODULE         /* (_MODULE_OFF) // */ (_MODULE_ON)
#define __LEDs_MODULE           /* (_MODULE_OFF)  // */ (_MODULE_ON)
#define __SWD_MODULE            /* (_MODULE_OFF) // */ (_MODULE_ON)

#if (defined __PROJ_CONFIGURATION) && (__PROJ_CONFIGURATION == _GLOBAL_CONFIGURED)

/**** RL Periph Module ********************************************************/
#if (defined __KS_PERIPH_MODULE) && (_MODULE_ON == __KS_PERIPH_MODULE)

#define __USE_YK_ASSERT
#define USE_DEFAULT_YK_ASSERT   // use the assert in the ksPeriph
#define __MCU_ENDIAN                  (_MCU_is_LITTLE_ENDIAN)

#endif

/**** STM32FWLib **************************************************************/
#if (defined __KS_PERIPH_MODULE) && (_MODULE_ON == __KS_PERIPH_MODULE)

#define USE_STDPERIPH_DRIVER
#define USE_FULL_ASSERT
#define USE_FULL_FILENAMEx
#define NDEBUG
#define USE_EXTERNAL_PROJECT_IT_Hx // whether to use the nrf51_52_it.c in fwlib
#define __CORTEX_IRQ_PrioGRP           (NVIC_PriorityGroup_0)

#if   (__MCU_TYPE == _MCU_IS_NRF52832)
#define NRF52

#ifndef NRFX_IRQ_HANDLER_ENABLED
#define NRFX_IRQ_HANDLER_ENABLED        (0) // */ (1)
#endif

#define CLOCK_ENABLED                           (1)
#define CLOCK_CONFIG_XTAL_FREQ                  NRF_CLOCK_XTALFREQ_Default // 16 MHZ xtal

#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#define NRF51
#define CLOCK_ENABLED                           (1)

#define CLOCK_CONFIG_XTAL_FREQ                  CLOCK_XTALFREQ_XTALFREQ_16MHz // 16 MHZ xtal
#define CLOCK_CONFIG_LF_SRC                     CLOCK_LFCLKSRC_SRC_Xtal       // 32768 xtal

#define GPIOTE_ENABLED                          (0)
#define TIMER0_ENABLED                          (0)
#define TIMER1_ENABLED                          (0)
#define TIMER2_ENABLED                          (0)
#define TIMER3_ENABLED                          (0)
#define TIMER4_ENABLED                          (0)
#define RTC0_ENABLED                            (0)
#define RTC1_ENABLED                            (1)
#define RNG_ENABLED                             (0)
#define PWM0_ENABLED                            (0)
#define PWM1_ENABLED                            (0)
#define PWM2_ENABLED                            (0)
#define SPI0_ENABLED                            (0)
#define SPI1_ENABLED                            (0)
#define SPI2_ENABLED                            (0)
#define SPIS0_ENABLED                           (0)
#define SPIS1_ENABLED                           (0)
#define SPIS2_ENABLED                           (0)
#define UART0_ENABLED                           (1)
#define TWI0_ENABLED                            (0)
#define TWI1_ENABLED                            (0)
#define TWIS0_ENABLED                           (0)
#define TWIS1_ENABLED                           (0)
#define QDEC_ENABLED                            (0)
#define SAADC_ENABLED                           (0)
#define PDM_ENABLED                             (0)
#define LPCOMP_ENABLED                          (0)
#define WDT_ENABLED                             (0)
#define I2S_ENABLED                             (0)

#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#if (defined USE_FULL_ASSERT)
#define DEBUG_EFMx
#endif
#define EFR32BG1P232F256GM32
// #define EFR32BG1P232F256GJ43

#elif (__MCU_TYPE == _MCU_IS_NRF52832)

#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#define DEBUG
#define FRDM_KL17Z
#define CPU_MKL17Z64VFM4
#define FREEDOM   // TODO : platform
#define _MKL17Z4  // TODO : MCU
#else
#error "unsupportted"
#endif // 1

#endif

/***** LEDs Module ************************************************************/
#if (defined __LEDs_MODULE) && (_MODULE_ON == __LEDs_MODULE)
#include <LEDs_Spec.h>

  #define     __LEDS_CNT              (0x07) // Support 10 LEDs at most

/***** LEDs GPIO Configuration ************************************************/
 #if (__LEDS_CNT > 0)
  #define     __LED_IO_OK_EXCITE      (0x00)
  #define     __LED_1_PORT            (io_Port_0)
  #define     __LED_1_PIN             (io_Pin_26)
  #define     __LED_1_DRIVE_MODE      (__LED_LOW_DRIVE)
 #endif // (__LEDS_CNT > 0)

 #if (__LEDS_CNT > 1)
  #define     __LED_IO_ERR_EXCITE     (0x01)
  #define     __LED_2_PORT            (io_Port_0)
  #define     __LED_2_PIN             (io_Pin_25)
  #define     __LED_2_DRIVE_MODE      (__LED_LOW_DRIVE)
 #endif // (__LEDS_CNT > 1)

#if (__LEDS_CNT > 2)
  #define     __LED_IO_OK_RMS_E       (0x02)
  #define     __LED_3_PORT            (io_Port_0)
  #define     __LED_3_PIN             (io_Pin_18)
  #define     __LED_3_DRIVE_MODE      (__LED_LOW_DRIVE)
#endif // (__LEDS_CNT > 2)

#if (__LEDS_CNT > 3)
  #define     __LED_IO_ERR_RMS_E      (0x03)
  #define     __LED_4_PORT            (io_Port_0)
  #define     __LED_4_PIN             (io_Pin_20)
  #define     __LED_4_DRIVE_MODE      (__LED_LOW_DRIVE)
#endif // (__LEDS_CNT > 3)

#if (__LEDS_CNT > 4)
  #define     __LED_IO_OK_RMS_L       (0x04)
  #define     __LED_5_PORT            (io_Port_0)
  #define     __LED_5_PIN             (io_Pin_11)
  #define     __LED_5_DRIVE_MODE      (__LED_LOW_DRIVE)
#endif // (__LEDS_CNT > 4)

#if (__LEDS_CNT > 5)
  #define     __LED_IO_ERR_RMS_L      (0x05)
  #define     __LED_6_PORT            (io_Port_0)
  #define     __LED_6_PIN             (io_Pin_12)
  #define     __LED_6_DRIVE_MODE      (__LED_LOW_DRIVE)
#endif // (__LEDS_CNT > 5)

#if (__LEDS_CNT > 6)
  #define     __LED_IO_OK_I2C         (0x06)
  #define     __LED_7_PORT            (io_Port_0)
  #define     __LED_7_PIN             (io_Pin_10)
  #define     __LED_7_DRIVE_MODE      (__LED_LOW_DRIVE)
#endif // (__LEDS_CNT > 6)

#if (__LEDS_CNT > 7)
  #define     __LED_8_PORT        (io_Port_1)
  #define     __LED_8_PIN         (io_Pin_11)
  #define     __LED_8_DRIVE_MODE  (__LED_HIGH_DRIVE)
#endif // (__LEDS_CNT > 7)

#if (__LEDS_CNT > 8)
  #define     __LED_9_PORT        (io_Port_1)
  #define     __LED_9_PIN         (io_Pin_11)
  #define     __LED_9_DRIVE_MODE  (__LED_HIGH_DRIVE)
#endif // (__LEDS_CNT > 8)

#if (__LEDS_CNT > 9)
  #define     __LED_10_PORT       (io_Port_1)
  #define     __LED_10_PIN        (io_Pin_11)
  #define     __LED_10_DRIVE_MODE (__LED_HIGH_DRIVE)
#endif // (__LEDS_CNT > 9)
#endif

/************************* Tracer_Debugger_Module ******************************/
#if (defined __TRACER_MODULE) && (__TRACER_MODULE == _MODULE_ON)
#include <tracer_spec.h>

#ifndef __MCU_TYPE
#define     __MCU_TYPE                        (_MCU_IS_NRF51822)
#endif

#define     __USART_TRACER                    (_TRACER_ON)
#define     __SPI_TRACER                      (_TRACER_OFF)

#define     __TRACER_BUF_SIZE                 (20)
#define     __TRACER_CONSOLE_SIZE             (50)
#define     __TRACER_PRINTF_STATUS            (_TRACER_ON)
#define     __TRACER_PRINTFBUF_SIZE           (256)
#define     __TRACER_DMABUF_SIZE              (256)
#define     __TRACER_CONSOLE                  (_TRACER_0)
#define     __TRACER_OUT                      (__TRACER_CONSOLE)

/**** Debugger IO Configuration ***********************************************/
#if (__USART_TRACER ==_TRACER_ON)
#define     __uTRACER_CNT                     (0x01)
#else
#define     __uTRACER_CNT                     (0x00)
#endif
#if (__SPI_TRACER ==_TRACER_ON)
#define     __sTRACER_CNT                     (0x01)
#else
#define     __sTRACER_CNT                     (0x00)
#endif

#if (__uTRACER_CNT >= 1)
#define     __UTRACER_IDX_1                   (0x00)

#define     __uTRACER_BDR_1                   (115200)  // */ (9600)      // Baud Rate
#define     __uTRACER_BUS_1                   (is_usart1)     // choose the channel
#define     __uTRACER_FLWCNTL                 (_TRACER_OFF)

#define     __uTRACER_ISR_MODE_1              (_TRACER_ISR_DMA) // */ (_TRACER_ISR_NODMA)

#if (__uTRACER_ISR_MODE_1 == _TRACER_ISR_DMA)
#define     __uTRACER_RX_DMA_CHANNEL          (DMA_Chan_1)
#define     __uTRACER_TX_DMA_CHANNEL          (DMA_Chan_0)
#endif // _TRACER_ISR_DMA

#define     __uTRACER_RX_PREPRIO_1            (0)
#define     __uTRACER_RX_SUBPRIO_1            (0)
#define     __uTRACER_TX_PREPRIO_1            (1) // for DMA
#define     __uTRACER_TX_SUBPRIO_1            (1) // for DMA

#if 	(__TRACER_FLWCNTL == _TRACER_ON) // note : used for upper API
// en? am I available? :: 0 free; 1 : busy
#define     __uTRACER_CTS_PORT_N_1            (io_Port_0)
#define     __uTRACER_CTS_PIN_N_1             (io_Pin_11)
#define     __uTRACER_CTS_MODE_1              (io_Mode_OOD)
// hi baby, I am coming
#define     __uTRACER_RTS_PORT_N_1            (io_Port_0)
#define     __uTRACER_RTS_PIN_N_1             (io_Pin_12)
#define     __uTRACER_RTS_MODE_1              (io_Mode_FIN)
#endif // (__TRACER_FLWCNTL == _TRACER_ON)

#define     __uTRACER_TX_PORT_N_1             (io_Port_A)     // TXD || MOSI
#define     __uTRACER_TX_PIN_N_1              (io_Pin_18)     // */ (io_Pin_14) // TXD || MOSI
#if   ((__MCU_TYPE == _MCU_IS_EFM32TGxxx) || \
       (__MCU_TYPE == _MCU_IS_EFM32ZGxxx) || \
       (__MCU_TYPE == _MCU_IS_EFM32Gxxx))
#define     __uTRACER_TX_MODE_1               (io_Mode_OOP)   // TXD || MOSI
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#define     __uTRACER_TX_MODE_1               (io_Mode_OOP)   // TXD || MOSI
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#define     __uTRACER_TX_MODE_1               (io_Mode_APP)   // TXD || MOSI
#define     __uTRACER_TX_AFIO_1               (kPORT_MuxAlt3)
#else
#define     __uTRACER_TX_MODE_1               (io_Mode_APP)   // TXD || MOSI
#endif

#define     __uTRACER_RX_PORT_N_1             (io_Port_A)     // RXD || MISO
#define     __uTRACER_RX_PIN_N_1              (io_Pin_20)     // */ (io_Pin_16) // RXD || MISO
#define     __uTRACER_RX_MODE_1               (io_Mode_FIN)   // RXD || MISO

#define     __uTRACER_SCK_PORT_N_1            (io_Port_No)    // for spi use
#define     __uTRACER_SCK_PIN_N_1             (io_Pin_No)     // for spi use
#define     __uTRACER_SCK_MODE_1              (io_Mode_No)    // for spi use
// hi baby, I am coming
#define     __uTRACER_RTS_PORT_N_1            (io_Port_No)    // MCU RTS
#define     __uTRACER_RTS_PIN_N_1             (io_Pin_No)     // MCU RTS
#define     __uTRACER_RTS_MODE_1              (io_Mode_No)    // MCU RTS
// en? am I available? :: 0 free; 1 : busy
#define     __uTRACER_CTS_PORT_N_1            (io_Port_No)    // MCU CTS
#define     __uTRACER_CTS_PIN_N_1             (io_Pin_No)     // MCU CTS
#define     __uTRACER_CTS_MODE_1              (io_Mode_No)    // MCU CTS

#define     __uTRACER_DTR_PORT_N_1            (io_Port_No)    // MCU DTR
#define     __uTRACER_DTR_PIN_N_1             (io_Pin_No)     // MCU DTR
#define     __uTRACER_DTR_MODE_1              (io_Mode_No)    // MCU DTR

#define     __uTRACER_DSR_PORT_N_1            (io_Port_No)    // MCU DTR
#define     __uTRACER_DSR_PIN_N_1             (io_Pin_No)     // MCU DTR
#define     __uTRACER_DSR_MODE_1              (io_Mode_No)    // MCU DTR

#define     __uTRACER_DCD_PORT_N_1            (io_Port_No)    // MCU DCD
#define     __uTRACER_DCD_PIN_N_1             (io_Pin_No)     // MCU DCD
#define     __uTRACER_DCD_MODE_1              (io_Mode_No)    // MCU DCD

#define     __uTRACER_RI_PORT_N_1             (io_Port_No)    // MCU RI
#define     __uTRACER_RI_PIN_N_1              (io_Pin_No)     // MCU RI
#define     __uTRACER_RI_MODE_1               (io_Mode_No)    // MCU RI

#define     __uTRACER_CS_PORT_N_1             (io_Port_No)    // for spi use
#define     __uTRACER_CS_PIN_N_1              (io_Pin_No)     // for spi use
#define     __uTRACER_CS_MODE_1               (io_Mode_No)    // for spi use

#endif // (__uTRACER_CNT >= 1)

#endif // (defined __TRACER_MODULE) && (__TRACER_MODULE == _MODULE_ON)

#endif // defined _USE_GLOBAL_PROJECT_CONFIGURATION

/**** Includes ****************************************************************/
#include "./Proj_cfg/inc/projAssert.h"

#endif // __PROJECT_CONFIGURATION_H_20120114YK
