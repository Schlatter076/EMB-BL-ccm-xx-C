////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "tm30.test.adc.h"
/// * Author  : kensky
/// * Version :
/// * Date    : Oct 27, 2020
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __APPS_MAIN_INC_TM30_TEST_ADC_H_KENSKY_2020__
#define __APPS_MAIN_INC_TM30_TEST_ADC_H_KENSKY_2020__

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
#include  <ksPeriph.h>

#define   __TM30_ADC_TEST_SENSOR_CNTR         (0x01)
#define   __TM30_ADC_AMPMAX_LIMIT_Upper       (325)
#define   __TM30_ADC_AMPMAX_LIMIT_Lower       /* (305) // */ (300)
#define   __TM30_ADC_AMPMIN_LIMIT_Upper       (25)
#define   __TM30_ADC_AMPMIN_LIMIT_Lower       (5)

typedef enum
{
  adcTestOff   = 0x00,
  adcTestDone  = 0x01,
} tm30AdcTest_e;

typedef struct
{
  ksADC_t       adc;
  ksS16         adcBuf[8];
  ksU32         adcSem;
  ksS16         adcMin;
  ksS16         adcMax;
  ksU32         ampMax;
  ksU32         ampMin;
  ksU32         errCode;
  tm30AdcTest_e state;
} tm30AdcTest_t;

extern tm30AdcTest_t  gv_tm30TestAdc;

void    tm30AdcTestCallBack   (void);
void    tm30AdcDoSampleing    (tm30AdcTest_t  *pTestADC);
ksRet_t tm30AdcTestInit       (tm30AdcTest_t  *pTestAdc,
                               ksU32          event,
                               pISR           tm30AdcTestCB);
void    tm30AdcTestLoop       (tm30AdcTest_t  *pTestADC);
void    tm30AdcTestAnalyze    (tm30AdcTest_t  *pTestADC);

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __APPS_MAIN_INC_TM30_TEST_ADC_H_KENSKY_2020__
