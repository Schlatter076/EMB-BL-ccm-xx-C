/*******************************************************************************
  * File    :  GPIO_Spec.h
  * Author  :  kensky
  * Version :   
  * Date    :  2019-12-08
  * Brief   :  
*******************************************************************************/
#ifndef __GPIO_SPEC_H_KENSKY_2019_12_08
#define __GPIO_SPEC_H_KENSKY_2019_12_08

/**** Includes ****************************************************************/
#include <0A_ISR/ISR_Spec.h>

/**** Defines *****************************************************************/
/**** GPIO_Speed **************************************************************/
#define     _GPIO_SPEED_Undefined          (0x00U)
#define     _GPIO_SPEED_400KHz             (0x07u)
#define     _GPIO_SPEED_1MHz               (0x01u)
#define     _GPIO_SPEED_2MHz               (0x02u)
#define     _GPIO_SPEED_5MHz               (0x03U)
#define     _GPIO_SPEED_10MHz              (0x04U)
#define     _GPIO_SPEED_25MHz              (0x09U)
#define     _GPIO_SPEED_40MHz              (0x06U)
#define     _GPIO_SPEED_50MHz              (0x05U)
#define     _GPIO_SPEED_100MHz             (0x08U)

/**** GPIO Drive Strength *****************************************************/
#define     _GPIO_DRIVE_Undefined          (0x00U)
#define     _GPIO_DRIVE_LOWEST             (0x01U)
#define     _GPIO_DRIVE_LOW                (0x02U)
#define     _GPIO_DRIVE_STANDARD           (0x03U)
#define     _GPIO_DRIVE_HIGH               (0x04U)

/**** GPIO Alternate Function *************************************************/
#define     _GPIO_AFUNCTION_NULL           (0xFFu)

/**** GPIO MODE ***************************************************************/
#define     _GPIO_MODE_AIN                 (0x00U) // Analog Input
#define     _GPIO_MODE_FIN                 (0x01U) // Float Input
#define     _GPIO_MODE_IPU                 (0x02U) // Input pull up
#define     _GPIO_MODE_IPD                 (0x03U) // input pull down
#define     _GPIO_MODE_OPP                 (0x04U) // output pushpull
#define     _GPIO_MODE_OOD                 (0x05U) // output open drain
#define     _GPIO_MODE_AOD                 (0x06U) // analog output opendrain
#define     _GPIO_MODE_APP                 (0x07U) // analog output push pull
#define     _GPIO_MODE_DIN                 (0x08U) // digital Input
#define     _GPIO_MODE_OOS                 (0x09U) // output open source
#define     _GPIO_MODE_IPF                 (0x0AU) // digital input with pull-up or pull-down
#define     _GPIO_MODE_Undefined           (0xFFu)

/**** GPIO Ports **************************************************************/
#define     _GPIO_Port_0                   (0x00U)
#define     _GPIO_Port_A                   (0x00U)
#define     _GPIO_Port_1                   (0x01U)
#define     _GPIO_Port_B                   (0x01U)
#define     _GPIO_Port_2                   (0x02U)
#define     _GPIO_Port_C                   (0x02U)
#define     _GPIO_Port_3                   (0x03U)
#define     _GPIO_Port_D                   (0x03U)
#define     _GPIO_Port_4                   (0x04U)
#define     _GPIO_Port_E                   (0x04U)
#define     _GPIO_Port_5                   (0x05U)
#define     _GPIO_Port_F                   (0x05U)
#define     _GPIO_Port_6                   (0x06U)
#define     _GPIO_Port_G                   (0x06U)
#define     _GPIO_Port_7                   (0x07U)
#define     _GPIO_Port_H                   (0x07U)
#define     _GPIO_Port_8                   (0x08U)
#define     _GPIO_Port_I                   (0x08U)
#define     _GPIO_Port_9                   (0x09U)
#define     _GPIO_Port_J                   (0x09U)
#define     _GPIO_Port_10                  (0x0AU)
#define     _GPIO_Port_K                   (0x0AU)
#define     _GPIO_NoPort                   (0xFFu)

/**** GPIO Pins ***************************************************************/
#define     _GPIO_Pin_0                    ((ksU16)0x0001)  // Pin 0 selected
#define     _GPIO_Pin_1                    ((ksU16)0x0002)  // Pin 1 selected
#define     _GPIO_Pin_2                    ((ksU16)0x0004)  // Pin 2 selected
#define     _GPIO_Pin_3                    ((ksU16)0x0008)  // Pin 3 selected
#define     _GPIO_Pin_4                    ((ksU16)0x0010)  // Pin 4 selected
#define     _GPIO_Pin_5                    ((ksU16)0x0020)  // Pin 5 selected
#define     _GPIO_Pin_6                    ((ksU16)0x0040)  // Pin 6 selected
#define     _GPIO_Pin_7                    ((ksU16)0x0080)  // Pin 7 selected
#define     _GPIO_Pin_8                    ((ksU16)0x0100)  // Pin 8 selected
#define     _GPIO_Pin_9                    ((ksU16)0x0200)  // Pin 9 selected
#define     _GPIO_Pin_10                   ((ksU16)0x0400)  // Pin 10 selected
#define     _GPIO_Pin_11                   ((ksU16)0x0800)  // Pin 11 selected
#define     _GPIO_Pin_12                   ((ksU16)0x1000)  // Pin 12 selected
#define     _GPIO_Pin_13                   ((ksU16)0x2000)  // Pin 13 selected
#define     _GPIO_Pin_14                   ((ksU16)0x4000)  // Pin 14 selected
#define     _GPIO_Pin_15                   ((ksU16)0x8000)  // Pin 15 selected
#define     _GPIO_Pin_Low_All              ((ksU16)0x00FF)  // All Low 8 pins selected
#define     _GPIO_Pin_High_All             ((ksU16)0xFF00)  // All High 8 pins selected
#define     _GPIO_Pin_All                  ((ksU16)0xFFFF)  // All pins selected

#define     _GPIO_PinNum_00                (0x00U)
#define     _GPIO_PinNum_01                (0x01U)
#define     _GPIO_PinNum_02                (0x02U)
#define     _GPIO_PinNum_03                (0x03U)
#define     _GPIO_PinNum_04                (0x04U)
#define     _GPIO_PinNum_05                (0x05U)
#define     _GPIO_PinNum_06                (0x06U)
#define     _GPIO_PinNum_07                (0x07U)
#define     _GPIO_PinNum_08                (0x08U)
#define     _GPIO_PinNum_09                (0x09U)
#define     _GPIO_PinNum_10                (0x0Au)
#define     _GPIO_PinNum_11                (0x0Bu)
#define     _GPIO_PinNum_12                (0x0Cu)
#define     _GPIO_PinNum_13                (0x0Du)
#define     _GPIO_PinNum_14                (0x0Eu)
#define     _GPIO_PinNum_15                (0x0Fu)
#if ((__MCU_TYPE == _MCU_IS_NRF51822) || \
     (__MCU_TYPE == _MCU_IS_NRF52832) || \
     (__MCU_TYPE == _MCU_IS_FSKLxxZ4))
#define     _GPIO_PinNum_16                (0x10U)
#define     _GPIO_PinNum_17                (0x11U)
#define     _GPIO_PinNum_18                (0x12U)
#define     _GPIO_PinNum_19                (0x13U)
#define     _GPIO_PinNum_20                (0x14U)
#define     _GPIO_PinNum_21                (0x15U)
#define     _GPIO_PinNum_22                (0x16U)
#define     _GPIO_PinNum_23                (0x17U)
#define     _GPIO_PinNum_24                (0x18U)
#define     _GPIO_PinNum_25                (0x19U)
#define     _GPIO_PinNum_26                (0x1Au)
#define     _GPIO_PinNum_27                (0x1Bu)
#define     _GPIO_PinNum_28                (0x1Cu)
#define     _GPIO_PinNum_29                (0x1Du)
#define     _GPIO_PinNum_30                (0x1Eu)
#define     _GPIO_PinNum_31                (0x1Fu)
#endif // (__MCU_TYPE == _MCU_IS_NRF51822)

/**** Global Data Types *******************************************************/
typedef enum
{
  IO_Disable    = 0,
  IO_Enable     = !IO_Disable,
} ksGPIO_State_e;

typedef enum
{
  io_Port_0   = _GPIO_Port_0,
  io_Port_A   = _GPIO_Port_0,
  io_Port_1   = _GPIO_Port_1,
  io_Port_B   = _GPIO_Port_1,
  io_Port_2   = _GPIO_Port_2,
  io_Port_C   = _GPIO_Port_2,
  io_Port_3   = _GPIO_Port_3,
  io_Port_D   = _GPIO_Port_3,
  io_Port_4   = _GPIO_Port_4,
  io_Port_E   = _GPIO_Port_4,
  io_Port_5   = _GPIO_Port_5,
  io_Port_F   = _GPIO_Port_5,
  io_Port_6   = _GPIO_Port_6,
  io_Port_G   = _GPIO_Port_6,
  io_Port_7   = _GPIO_Port_7,
  io_Port_H   = _GPIO_Port_7,
  io_Port_8   = _GPIO_Port_8,
  io_Port_I   = _GPIO_Port_8,
  io_Port_9   = _GPIO_Port_9,
  io_Port_J   = _GPIO_Port_9,
  io_Port_10  = _GPIO_Port_10,
  io_Port_K   = _GPIO_Port_10,
  io_Port_No  = _GPIO_NoPort,
} ksGPIO_PORT_e;

typedef enum
{
  io_Pin_00  = _GPIO_PinNum_00,
  io_Pin_01  = _GPIO_PinNum_01,
  io_Pin_02  = _GPIO_PinNum_02,
  io_Pin_03  = _GPIO_PinNum_03,
  io_Pin_04  = _GPIO_PinNum_04,
  io_Pin_05  = _GPIO_PinNum_05,
  io_Pin_06  = _GPIO_PinNum_06,
  io_Pin_07  = _GPIO_PinNum_07,
  io_Pin_08  = _GPIO_PinNum_08,
  io_Pin_09  = _GPIO_PinNum_09,
  io_Pin_10  = _GPIO_PinNum_10,
  io_Pin_11  = _GPIO_PinNum_11,
  io_Pin_12  = _GPIO_PinNum_12,
  io_Pin_13  = _GPIO_PinNum_13,
  io_Pin_14  = _GPIO_PinNum_14,
  io_Pin_15  = _GPIO_PinNum_15,
#if ((__MCU_TYPE == _MCU_IS_NRF51822) || \
     (__MCU_TYPE == _MCU_IS_NRF52832) || \
     (__MCU_TYPE == _MCU_IS_FSKLxxZ4))
  io_Pin_16  = _GPIO_PinNum_16,
  io_Pin_17  = _GPIO_PinNum_17,
  io_Pin_18  = _GPIO_PinNum_18,
  io_Pin_19  = _GPIO_PinNum_19,
  io_Pin_20  = _GPIO_PinNum_20,
  io_Pin_21  = _GPIO_PinNum_21,
  io_Pin_22  = _GPIO_PinNum_22,
  io_Pin_23  = _GPIO_PinNum_23,
  io_Pin_24  = _GPIO_PinNum_24,
  io_Pin_25  = _GPIO_PinNum_25,
  io_Pin_26  = _GPIO_PinNum_26,
  io_Pin_27  = _GPIO_PinNum_27,
  io_Pin_28  = _GPIO_PinNum_28,
  io_Pin_29  = _GPIO_PinNum_29,
  io_Pin_30  = _GPIO_PinNum_30,
  io_Pin_31  = _GPIO_PinNum_31,
  io_Pin_All = 0x0000ffff,
#else
  io_Pin_All = 0x000000ff,
#endif // (__MCU_TYPE == _MCU_IS_NRF51822)
  io_Pin_No  = 0xffffffff,
} ksGPIO_PIN_e;

typedef enum
{
  io_NoSpeed  =   _GPIO_SPEED_Undefined ,
  is_400Kz    =   _GPIO_SPEED_400KHz ,
  is_01MHz    =   _GPIO_SPEED_1MHz ,
  is_02MHz    =   _GPIO_SPEED_2MHz ,
  is_05MHz    =   _GPIO_SPEED_5MHz ,
  is_10MHz    =   _GPIO_SPEED_10MHz ,
  is_25MHz    =   _GPIO_SPEED_25MHz ,
  is_40MHz    =   _GPIO_SPEED_40MHz ,
  is_50MHz    =   _GPIO_SPEED_50MHz ,
  is_100MHz   =   _GPIO_SPEED_100MHz ,
} ksGPIO_Speed_e;

typedef enum
{
  is__no_drv  =   _GPIO_DRIVE_Undefined ,
  is_min_drv  =   _GPIO_DRIVE_LOWEST , // minimum
  is_low_drv  =   _GPIO_DRIVE_LOW ,
  is_nor_drv  =   _GPIO_DRIVE_STANDARD ,
  is_max_drv  =   _GPIO_DRIVE_HIGH ,
} ksGPIO_Drive_e;

typedef enum
{
  io_Mode_AIN = _GPIO_MODE_AIN , // analog input A.K.A. input without filter
  io_Mode_FIN = _GPIO_MODE_FIN , // float, also HiZ
  io_Mode_IPU = _GPIO_MODE_IPU , // input pull-up
  io_Mode_IPD = _GPIO_MODE_IPD , // input pull-down
  io_Mode_OOP = _GPIO_MODE_OPP , // pushpull output
  io_Mode_OOD = _GPIO_MODE_OOD , // output opendrain
  io_Mode_AOD = _GPIO_MODE_AOD , // analog open drain output
  io_Mode_APP = _GPIO_MODE_APP , // alternate function

  io_Mode_HIZ = _GPIO_MODE_FIN , // the same as io_Mode_FIN
  io_Mode_DIN = _GPIO_MODE_DIN , // input with filter
  io_Mode_IPF = _GPIO_MODE_IPF , // input with filter and pull resistor
  io_Mode_OOS = _GPIO_MODE_OOS , // open source output
  io_Mode_No  = _GPIO_MODE_Undefined,
} ksGPIO_Mode_e;

typedef enum
{
  IO_is_Low   = 0x00,
  IO_is_High  = 0x01,
  IO_is_HiZ   = 0x02, // todo : not tested, useless for now
} ksGPIO_Status_e;

typedef ksU32     ksGpioAF;
typedef ksU32     ksGpioFilter; // 0 : filter off; 1 : filter on

typedef struct
{
  ksGPIO_PIN_e    pinNum;
  ksGPIO_Mode_e   Mode;
  ksGPIO_Speed_e  Speed;
  ksGpioAF        ioAFunc;
  ksGpioFilter    filter;
  ksGPIO_Drive_e  drive;
} ksGPIO_Pin_t;

typedef enum __IO_Press_State
{
  ioReleased  = 0x00,
  ioPressed   = 0x01,
  ioSpressed  = 0x02,
  ioLpressed  = 0x03,
} ksGpioPressed_e;

typedef struct
{
#if 	(__MCU_TYPE == _MCU_IS_STM32F10x)
  ksU32 CRL;
  ksU32 CRH;
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
  ksU32 MODER;
  ksU32 SPEDR;    // for output
  ksU32 TYPER;    // for output
  ksU32 PUPDR;
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
  ksU32 MODER;    // GPIO port mode register,
  ksU32 SPEDR;    // GPIO port output speed register,
  ksU32 TYPER;    // GPIO port output type register,
  ksU32 PUPDR;    // GPIO port pull-up/pull-down register,
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
  ksU32 MODER;    // todo :: it's wrong!!
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
  ksU32 MODER;    // GPIO port mode register,
  ksU32 SPEDR;    // GPIO port output speed register,
  ksU32 TYPER;    // GPIO port output type register,
  ksU32 PUPDR;    // GPIO port pull-up/pull-down register,
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
  ksU32 MODEL;    // GPIO port mode register,
  ksU32 MODEH;    // GPIO port mode register,
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx) // todo
  ksU32 MODEL;    // GPIO port mode register,
  ksU32 MODEH;    // GPIO port mode register,
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
  ksU32 MODEL;    // GPIO port mode register,
  ksU32 MODEH;    // GPIO port mode register,
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
  ksU32 CNF;      // todo : GPIO port mode register,
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
  ksU32 CNF;      // todo : GPIO port mode register,
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
  ksU32 todoxx; // todo ??
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
  ksU32 MODER;    // GPIO port mode register,
  ksU32 SPEDR;    // GPIO port output speed register,
  ksU32 TYPER;    // GPIO port output type register,
  ksU32 PUPDR;    // GPIO port pull-up/pull-down register,
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
  ksU32 MODER;    // TODO : GPIO port mode register,
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
  ksU32 MODER;    // TODO : GPIO port mode register,
#else
#error please specify the MCU TYPE!
#endif
} ksGPIO_CTRLReg_t;

typedef struct
{
  ksStroage_e     storage;
  ksU32           periphID;
  ksAddr_t        addrBase;
  ksISR_t         isr;
  ksGPIO_PORT_e   PORTn;
  ksGPIO_Pin_t    Pin;
  ksGPIO_Status_e status;
  ksGpioPressed_e pressed;
  void            *pSpecial; // special definition for some IC
#if (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
  // ksFsklPort_t *pFsklPort; // exapmle
#endif
} ksGPIO_t;

#endif // __GPIO_SPEC_H_KENSKY_2019_12_08
