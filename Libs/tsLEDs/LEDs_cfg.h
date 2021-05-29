#ifndef     __LEDS_CFG_H_YK20120413
#define     __LEDS_CFG_H_YK20120413

/**** Includes ****************************************************************/
#include <projCfg.h>
#include <LEDs_Spec.h>

#if (defined __LEDs_MODULE) && (_MODULE_ON == __LEDs_MODULE)

#include <ksPeriph.h>

#if (defined __PROJ_CONFIGURATION) &&(__PROJ_CONFIGURATION != _GLOBAL_CONFIGURED)

/**** Includes ****************************************************************/

/***** Macros *****************************************************************/
#ifndef _uuidCheck
#define     _uuidCheck()  // override the global uuid checking routine
#endif

/***** User Configurable Part *************************************************/
#define     __LEDS_CNT              (10) // Support 10 LEDs at most

/***** LEDs GPIO Configuration ************************************************/
#if (__LEDS_CNT > 0)
#define     __LED_1_PORT            (io_Port_0)
#define     __LED_1_PIN             (io_Pin_00)
#define     __LED_1_DRIVE_MODE      (__LED_HIGH_DRIVE)
#endif // (__LEDS_CNT > 0)

#if (__LEDS_CNT > 1)
#define     __LED_2_PORT           (io_Port_0)
#define     __LED_2_PIN            (io_Pin_00)
#define     __LED_2_DRIVE_MODE     (__LED_HIGH_DRIVE)
#endif // (__LEDS_CNT > 1)

#if (__LEDS_CNT > 2)
#define     __LED_3_PORT            (io_Port_0)
#define     __LED_3_PIN             (io_Pin_00)
#define     __LED_3_DRIVE_MODE      (__LED_HIGH_DRIVE)
#endif // (__LEDS_CNT > 2)

#if (__LEDS_CNT > 3)
#define     __LED_4_PORT            (io_Port_0)
#define     __LED_4_PIN             (io_Pin_00)
#define     __LED_4_DRIVE_MODE      (__LED_HIGH_DRIVE)
#endif // (__LEDS_CNT > 3)

#if (__LEDS_CNT > 4)
#define     __LED_5_PORT            (io_Port_0)
#define     __LED_5_PIN             (io_Pin_00)
#define     __LED_5_DRIVE_MODE      (__LED_HIGH_DRIVE)
#endif // (__LEDS_CNT > 4)

#if (__LEDS_CNT > 5)
#define     __LED_6_PORT            (io_Port_0)
#define     __LED_6_PIN             (io_Pin_00)
#define     __LED_6_DRIVE_MODE      (__LED_HIGH_DRIVE)
#endif // (__LEDS_CNT > 5)

#if (__LEDS_CNT > 6)
#define     __LED_7_PORT            (io_Port_0)
#define     __LED_7_PIN             (io_Pin_00)
#define     __LED_7_DRIVE_MODE      (__LED_HIGH_DRIVE)
#endif // (__LEDS_CNT > 6)

#if (__LEDS_CNT > 7)
#define     __LED_8_PORT            (io_Port_0)
#define     __LED_8_PIN             (io_Pin_00)
#define     __LED_8_DRIVE_MODE      (__LED_HIGH_DRIVE)
#endif // (__LEDS_CNT > 7)

#if (__LEDS_CNT > 8)
#define     __LED_9_PORT            (io_Port_0)
#define     __LED_9_PIN             (io_Pin_00)
#define     __LED_9_DRIVE_MODE      (__LED_HIGH_DRIVE)
#endif // (__LEDS_CNT > 8)

#if (__LEDS_CNT > 9)
#define     __LED_10_PORT           (io_Port_0)
#define     __LED_10_PIN            (io_Pin_00)
#define     __LED_10_DRIVE_MODE     (__LED_HIGH_DRIVE)
#endif // (__LEDS_CNT > 9)

#endif      // _USE_GLOBAL_PROJECT_CONFIGURATION
#endif // (defined __LEDs_MODULE) && (_MODULE_ON == __LEDs_MODULE)
#endif      // __LEDS_CFG_H_YK20120413
