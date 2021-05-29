#ifndef     __LEDS_PERIPH_CFG_H_YK20120414
#define     __LEDS_PERIPH_CFG_H_YK20120414

/**** Includes ****************************************************************/
#include <LEDs_cfg.h>

#if ((defined __LEDs_MODULE) && ( __LEDs_MODULE == _MODULE_ON))

/***** Data Structure Definitions *********************************************/
typedef int8_t LEDs_Status;

/***** Defines ****************************************************************/
#if 	(__MCU_TYPE == _MCU_IS_STM32L1x)
#define     __LEDS_GPIO_SPEED           (is_400Kz)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#define     __LEDS_GPIO_SPEED           /* (is_40MHz) // */ (is_400Kz)
#elif (__MCU_TYPE == _MCU_IS_STM32F10x)
#define     __LEDS_GPIO_SPEED           (is_10MHz)
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#define     __LEDS_GPIO_SPEED           (is_10MHz)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#define     __LEDS_GPIO_SPEED           (is_10MHz)
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#define     __LEDS_GPIO_SPEED           (is_10MHz)
#else
#endif

#define     __LEDS_GPIO_MODE            (io_Mode_OOP)

/***** Data Type **************************************************************/
typedef struct
{
  ksGPIO_t      io;
  ksU08         drvMode;
} ksLED_t;

/***** Global Variables *******************************************************/
extern ksLED_t gv_ledPeriph[__LEDS_CNT];

#endif // ((defined __LEDs_MODULE) && ( __LEDs_MODULE == _MODULE_ON))

#endif      // __LEDS_PERIPH_CFG_H_YK20120414
