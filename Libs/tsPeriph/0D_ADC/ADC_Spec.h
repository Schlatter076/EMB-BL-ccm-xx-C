/*******************************************************************************
  * File    :  ADC_Spec.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-10-9
  * Brief   :  
*******************************************************************************/
#ifndef __ADC_SPEC_H_KENSKY_2020_10_9
#define __ADC_SPEC_H_KENSKY_2020_10_9

/**** Includes ****************************************************************/
#include <04_GPIO/GPIO_Spec.h>
#include <0E_RCC/RCC_Spec.h>

/**** Defines *****************************************************************/
#define   __AIN_SINGLE              (0x00)
#define   __AIN_DIFFERENTIAL_P      (0x00)
#define   __AIN_DIFFERENTIAL_N      (0x01)
#define   __AIN_IO_NBR              (__AIN_DIFFERENTIAL_N + 1)


#if   (__MCU_TYPE == _MCU_IS_NRF52832)
#define   _ISR_ADC_READY            (0x00ul)  // data is ready
#define   _ISR_ADC_DONE             (0x01ul)  // conversion is done
#define   _ISR_ADC_CALIBRATED       (0x02ul)  // adc is calibrated
#define   _ISR_ADC_STARTED          (0x03ul)  // adc is ready
#define   _ISR_ADC_STOPPED          (0x04ul)  // adc is stopped
#define   _ISR_ADC_BUFFER_FUL       (0x05ul)  // adc buffer is full
#define   _ISR_ADC_MAX              (_ISR_ADC_BUFFER_FUL)

#define   _ADC_CHN_NBR              (0x08)
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#define   _ISR_ADC_READY            (0x00ul)  // data is ready
#define   _ISR_ADC_DONE             (0x01ul)  // conversion is done
#define   _ISR_ADC_MAX              (_ISR_ADC_DONE + 0x01)

#define   _ADC_CHN_NBR              (0x08)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#define   _ADC_CHN_NBR              (0x08)
#elif (__MCU_TYPE == _MCU_IS_STM32F10x)
#define   _ADC_CHN_NBR              (0x08) // TODO
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#define   _ISR_ADC_CALIBRATED       (0x02ul)  // adc is calibrated
#define   _ADC_CHN_NBR              (0x08) // TODO
#else
#warning "not implemented!"
#endif

#if ((__MCU_TYPE == _MCU_IS_NRF51822) || (__MCU_TYPE == _MCU_IS_NRF52832))
#define     _IS_ISR_ADC_SRC(src)    ((src) <= _ISR_ADC_MAX)
#define     _ISR_ADC_CNT            (_ISR_ADC_MAX + 1)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#define     _ISR_ADC_MAX            (1)
#define     _ISR_ADC_CNT            (_ISR_ADC_MAX + 1)
#elif (__MCU_TYPE == _MCU_IS_STM32F10x)  // TODO
#define     _ISR_ADC_MAX            (1)
#define     _ISR_ADC_CNT            (_ISR_ADC_MAX + 1)
#else
#define     _IS_ISR_AC_SRC(src)     ((src) <= _ISR_ADC_MAX)
#define     _ISR_ADC_CNT            (_ISR_ADC_CALIBRATED + 1)
#endif

/**** Global Data Types *******************************************************/
typedef enum
{
  ADC_busNo,
  ADC_bus00,
  ADC_bus01,
  ADC_bus02,
  ADC_bus03,
  ADC_bus04,
  ADC_bus05,
} ksADC_Bus_e;

typedef enum
{
  ADC_ChNo  = 0x00,
  ADC_Ch00  = 0x01,
  ADC_Ch01  = 0x02,
  ADC_Ch02  = 0x03,
  ADC_Ch03  = 0x04,
  ADC_Ch04  = 0x05,
  ADC_Ch05  = 0x06,
  ADC_Ch06  = 0x07,
  ADC_Ch07  = 0x08,
  ADC_Ch08  = 0x09,
  ADC_VDD   = 0x09, // for nrf52832
  ADC_Ch09  = 0x0A,
  ADC_Ch10  = 0x0B,
  ADC_Ch11  = 0x0C,
  ADC_Ch12  = 0x0D,
  ADC_Ch13  = 0x0E,
  ADC_Ch14  = 0x0F,
  ADC_Ch15  = 0x10,
  ADC_Ch16  = 0x11,
  ADC_Ch17  = 0x12,
  ADC_Ch18  = 0x13,
} ksADC_Channel_e;

typedef enum
{
  ADC_Mode_No,
  ADC_Mode_Single,  // for single-end
  ADC_Mode_Diff,    // for differential
} ksADC_Mode_e;

typedef enum
{
  ADC_Conv_No         = 0x00,
  ADC_Conv_Single     = 0x01,
  ADC_Conv_Continuous = 0x02,
  ADC_Scan_single     = 0x03,
  ADC_Scan_Continuous = 0x04,
} ksADC_ConvMode_e;

typedef enum
{
  ADC_GRP_No        = 0x00,
  ADC_GRP_Regular   = 0x01,
  ADC_GRP_Injected  = 0x02,
} ksADC_Group_e;

typedef enum
{
  ADC_ALIGN_No,
  ADC_ALIGN_Right,
  ADC_ALIGN_Left,
} ksADC_DataAlgin_e;

typedef enum
{
  ADC_Disable   = 0,
  ADC_Enable    = !ADC_Disable
} ksADC_State_e;

typedef enum
{ // also known as acquisiton time
  ADC_Sample_001_0cycle = 0x00,
  ADC_Sample_003_micro  = 0x00, // for nrf52832
  ADC_Sample_001_5cycle = 0x01,
  ADC_Sample_005_micro  = 0x01, // for nrf52832
  ADC_Sample_007_5cycle = 0x02,
  ADC_Sample_010_micro  = 0x02, // for nrf52832
  ADC_Sample_013_5cycle = 0x03,
  ADC_Sample_015_micro  = 0x03, // for nrf52832
  ADC_Sample_028_5cycle = 0x04,
  ADC_Sample_020_micro  = 0x04, // for nrf52832
  ADC_Sample_041_5cycle = 0x05,
  ADC_Sample_040_micro  = 0x05, // for nrf52832
  ADC_Sample_055_5cycle = 0x06,
  ADC_Sample_071_5cycle = 0x07,
  ADC_Sample_239_5cycle = 0x08,
} ksADC_SampleTime_e;

typedef enum
{
  ADC_06_bits = 0x00,
  ADC_07_bits,
  ADC_08_bits,
  ADC_09_bits,
  ADC_10_bits,
  ADC_11_bits,
  ADC_12_bits,
  ADC_13_bits,
  ADC_14_bits,
  ADC_15_bits,
  ADC_16_bits,
  ADC_17_bits,
  ADC_18_bits,
  ADC_19_bits,
  ADC_20_bits,
} ksADC_Resolution_e;

typedef enum
{ // can not be modified
  ADC_Vref_Internal   = 0x00,
  ADC_Vref_VDD        = 0x01,
} ksADC_Vref_e;

typedef enum
{
  ADC_Gain_1_8        = 0x00,
  ADC_Gain_1_7        = 0x01,
  ADC_Gain_1_6        = 0x02,
  ADC_Gain_1_5        = 0x03,
  ADC_Gain_1_4        = 0x04,
  ADC_Gain_1_3        = 0x05,
  ADC_Gain_1_2        = 0x06,
  ADC_Gain_1_1        = 0x07,
  ADC_Gain_2_1        = 0x08,
  ADC_Gain_4_1        = 0x09,
} ksADC_Gain_e;

typedef struct
{
  ksADC_Mode_e        mode;
  ksADC_Channel_e     chn[_ADC_CHN_NBR][__AIN_IO_NBR];
  ksADC_Group_e       group;
  ksADC_ConvMode_e    conversion;
  ksADC_DataAlgin_e   dataAlign;
  ksADC_SampleTime_e  sampleTime;
  ksADC_Resolution_e  resolution;
  ksRCC_PreScale_e    prescaler;
  ksADC_Vref_e        vref;
  ksADC_Gain_e        gain;
} ksADC_Params_t;

typedef struct
{
  ksADC_Bus_e         bus;
  ksAddr_t            addrBase;
} ksADC_Info_t;

typedef struct
{
  ksISR_t             adc_isr[_ISR_ADC_CNT];
} ksADC_isr_t;


typedef struct
{
  ksStroage_e         storage;
  ksADC_Info_t        info;
  ksADC_Params_t      params;
  ksU32               chnCntr;
  ksGPIO_t            ioAin[_ADC_CHN_NBR][__AIN_IO_NBR];
  ksADC_isr_t         isr;
} ksADC_t;

#endif // __ADC_SPEC_H_KENSKY_2020_10_9
