#include "../inc/LEDs_Periph_cfg.h"

#if ((defined __LEDs_MODULE) && ( __LEDs_MODULE == _MODULE_ON))

#ifndef __LEDS_GPIO_SPEED
#define __LEDS_GPIO_SPEED     (io_NoSpeed)
#endif // __LEDS_GPIO_SPEED

#if (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
ksFsklPort_t gv_ledPort[__LEDS_CNT] =
{
#if (__LEDS_CNT > 0)
  {
    .pFPort = NULL, // auto-complete
    .pPort  = NULL, // auto-complete
  },
#endif // (__LEDS_CNT > 0)

#if (__LEDS_CNT > 1)
  {
    .pFPort = NULL, // auto-complete
    .pPort  = NULL, // auto-complete
  },
#endif // (__LEDS_CNT > 0)

#if (__LEDS_CNT > 2)
  {
    .pFPort = NULL, // auto-complete
    .pPort  = NULL, // auto-complete
  },
#endif // (__LEDS_CNT > 0)

};
#endif

ksLED_t gv_ledPeriph[__LEDS_CNT] =
{
#if (__LEDS_CNT > 0)
 {
  .io =
  {
   .periphID  = 0,
   .addrBase  = 0,
   .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
   .PORTn     = __LED_1_PORT,
   .Pin       =
   {
    .pinNum   = __LED_1_PIN,
    .Mode     = __LEDS_GPIO_MODE,
    .Speed    = __LEDS_GPIO_SPEED,
#if (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
    .ioAFunc  = kPORT_MuxAsGpio,
#endif // __MCU_TYPE
   },
#if (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
   .pSpecial  = (void *)&gv_ledPort[0x00],
#else
  .pSpecial  = NULL,
#endif // (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
  },
  .drvMode =  __LED_1_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 0)

#if (__LEDS_CNT > 1)
 {
  .io =
  {
   .periphID  = 0,
   .addrBase  = 0,
   .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
   .PORTn     = __LED_2_PORT,
   .Pin       =
   {
    .pinNum   = __LED_2_PIN,
    .Mode     = __LEDS_GPIO_MODE,
    .Speed    = __LEDS_GPIO_SPEED,
#if (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
    .ioAFunc  = kPORT_MuxAsGpio,
#endif // __MCU_TYPE
   },
#if (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
   .pSpecial  = (void *)&gv_ledPort[0x01],
#endif // (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
  },
  .drvMode =  __LED_2_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 1)

#if (__LEDS_CNT > 2)
 {
  .io =
  {
   .periphID  = 0,
   .addrBase  = 0,
   .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
   .PORTn     = __LED_3_PORT,
   .Pin       =
   {
    .pinNum   = __LED_3_PIN,
    .Mode     = __LEDS_GPIO_MODE,
    .Speed    = __LEDS_GPIO_SPEED,
#if (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
    .ioAFunc  = kPORT_MuxAsGpio,
#endif // __MCU_TYPE
   },
#if (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
   .pSpecial  = (void *)&gv_ledPort[0x02],
#else
  .pSpecial   = NULL,
#endif // (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
  },
  .drvMode    = __LED_3_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 2)

#if (__LEDS_CNT > 3)
 {
  .io =
  {
   .periphID  = 0,
   .addrBase  = 0,
   .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
   .PORTn     = __LED_4_PORT,
   .Pin       =
   {
    .pinNum  = __LED_4_PIN,
    .Mode     = __LEDS_GPIO_MODE,
    .Speed    = __LEDS_GPIO_SPEED,
   },
  },
  .drvMode =  __LED_4_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 3)

#if (__LEDS_CNT > 4)
 {
   .io =
   {
     .periphID  = 0,
     .addrBase  = 0,
     .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
     .PORTn     = __LED_5_PORT,
     .Pin       =
     {
      .pinNum  = __LED_5_PIN,
      .Mode     = __LEDS_GPIO_MODE,
      .Speed    = __LEDS_GPIO_SPEED,
     },
   },
   .drvMode =  __LED_5_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 4)

#if (__LEDS_CNT > 5)
 {
   .io =
   {
     .periphID  = 0,
     .addrBase  = 0,
     .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
     .PORTn     = __LED_6_PORT,
     .Pin       =
     {
      .pinNum  = __LED_6_PIN,
      .Mode     = __LEDS_GPIO_MODE,
      .Speed    = __LEDS_GPIO_SPEED,
     },
    },
    .drvMode =  __LED_6_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 5)

#if (__LEDS_CNT > 6)
 {
   .io =
   {
     .periphID  = 0,
     .addrBase  = 0,
     .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
     .PORTn     = __LED_7_PORT,
     .Pin       =
     {
      .pinNum  = __LED_7_PIN,
      .Mode     = __LEDS_GPIO_MODE,
      .Speed    = __LEDS_GPIO_SPEED,
     },
    },
    .drvMode =  __LED_7_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 6)

#if (__LEDS_CNT > 7)
 {
   .io =
   {
     .periphID  = 0,
     .addrBase  = 0,
     .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
     .PORTn     = __LED_8_PORT,
     .Pin       =
     {
      .pinNum   = __LED_8_PIN,
      .Mode     = __LEDS_GPIO_MODE,
      .Speed    = __LEDS_GPIO_SPEED,
     },
    },
    .drvMode =  __LED_8_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 7)

#if (__LEDS_CNT > 8)
 {
   .io =
   {
     .periphID  = 0,
     .addrBase  = 0,
     .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
     .PORTn     = __LED_9_PORT,
     .Pin       =
     {
      .pinNum   = __LED_9_PIN,
      .Mode     = __LEDS_GPIO_MODE,
      .Speed    = __LEDS_GPIO_SPEED,
     },
    },
    .drvMode =  __LED_9_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 8)

#if (__LEDS_CNT > 9)
 {
   .io =
   {
    .periphID  = 0,
    .addrBase  = 0,
    .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
    .PORTn     = __LED_10_PORT,
    .Pin       =
    {
     .pinNum   = __LED_10_PIN,
     .Mode     = __LEDS_GPIO_MODE,
     .Speed    = __LEDS_GPIO_SPEED,
    },
   },
   .drvMode =  __LED_10_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 9)

#if (__LEDS_CNT > 10)
 {
   .io =
   {
     .periphID  = 0,
     .addrBase  = 0,
     .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
     .PORTn     = __LED_11_PORT,
     .Pin       =
     {
      .pinNum   = __LED_11_PIN,
      .Mode     = __LEDS_GPIO_MODE,
      .Speed    = __LEDS_GPIO_SPEED,
     },
    },
    .drvMode =  __LED_11_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 10)

#if (__LEDS_CNT > 11)
 {
    .io =
    {
     .periphID  = 0,
     .addrBase  = 0,
     .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
     .PORTn     = __LED_12_PORT,
     .Pin       =
     {
      .pinNum   = __LED_12_PIN,
      .Mode     = __LEDS_GPIO_MODE,
      .Speed    = __LEDS_GPIO_SPEED,
     },
    },
    .drvMode =  __LED_12_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 11)

#if (__LEDS_CNT > 12)
 {
   .io =
    {
     .periphID  = 0,
     .addrBase  = 0,
     .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
     .PORTn     = __LED_13_PORT,
     .Pin       =
     {
      .pinNum   = __LED_13_PIN,
      .Mode     = __LEDS_GPIO_MODE,
      .Speed    = __LEDS_GPIO_SPEED,
     },
    },
    .drvMode =  __LED_13_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 12)

#if (__LEDS_CNT > 13)
 {
   .io =
    {
     .periphID  = 0,
     .addrBase  = 0,
     .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
     .PORTn     = __LED_14_PORT,
     .Pin       =
     {
      .pinNum   = __LED_14_PIN,
      .Mode     = __LEDS_GPIO_MODE,
      .Speed    = __LEDS_GPIO_SPEED,
     },
    },
    .drvMode =  __LED_14_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 13)

#if (__LEDS_CNT > 14)
 {
   .io =
    {
     .periphID  = 0,
     .addrBase  = 0,
     .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
     .PORTn     = __LED_15_PORT,
     .Pin       =
     {
      .pinNum   = __LED_15_PIN,
      .Mode     = __LEDS_GPIO_MODE,
      .Speed    = __LEDS_GPIO_SPEED,
     },
    },
    .drvMode    =  __LED_15_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 14)

#if (__LEDS_CNT > 15)
 {
   .io =
    {
      .periphID  = 0,
      .addrBase  = 0,
      .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
      .PORTn     = __LED_16_PORT,
      .Pin       =
      {
        .pinNum  = __LED_16_PIN,
        .Mode    = __LEDS_GPIO_MODE,
        .Speed   = __LEDS_GPIO_SPEED,
      },
    },
    .drvMode     =  __LED_16_DRIVE_MODE,
 },
#endif // (__LEDS_CNT > 15)

#if (__LEDS_CNT > 16)
#error the driver currently only supports maximally 10 LEDs, Please check __LEDS_CNT!
#endif
};

#endif // ((defined __LEDs_MODULE) && ( __LEDs_MODULE == _MODULE_ON))
