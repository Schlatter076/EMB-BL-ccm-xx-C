////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "tm30.test.adc.c"
/// * Author  : kensky
/// * Version :
/// * Date    : Oct 27, 2020
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////

//*****************************************************************************
#ifdef  __cplusplus
//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//extern "C"
//{
#endif // __cplusplus

/**** Includes ****************************************************************/
#include	"../inc/tm30.test.adc.h"


tm30AdcTest_t gv_tm30TestAdc =
{
  .adcMin = 4096,
  .adcMax = 0x00,
  .adcSem = 0x00,
  .adc    =
  {
    .storage      = ksRAM,
    .info         =
    {
      .bus        = ADC_bus00,
      .addrBase   = 0x00,
    },

    .chnCntr      = __TM30_ADC_TEST_SENSOR_CNTR,
    .params       =
    {
      .mode       = ADC_Mode_Single,
      .chn        =
      {
        {ADC_Ch02, ADC_ChNo},  // 0x00, 0x02 are tested
        {ADC_Ch03, ADC_ChNo},
        {ADC_ChNo, ADC_ChNo},
        {ADC_ChNo, ADC_ChNo},
      },
      .group      = ADC_GRP_No,
      .conversion = ADC_Scan_single,
      .dataAlign  = ADC_ALIGN_No,
      .sampleTime = /* ADC_Sample_005_micro, // */ ADC_Sample_010_micro,
      .resolution = ADC_12_bits, // */ ADC_10_bits,
      .prescaler  = RCC_DIV_by_002,
      .vref       = ADC_Vref_Internal,  // 0.6V
      .gain       = /* ADC_Gain_1_3,       // */ ADC_Gain_1_6, // 0.6 * 6 == 3.6V | 0.6 * 3 = 1.8V
    },

#if (0)
    .ioAin        =
    {
        {
            {
                .periphID  = 0,
                .addrBase  = 0,
                .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
                .PORTn     = io_Port_0,
                .Pin       =
                {
                    .pinNum  = io_Pin_31,
                    .Mode    = io_Mode_AIN,
                    .Speed   = io_NoSpeed,
                },
            },

            {
                .periphID  = 0,
                .addrBase  = 0,
                .isr       = {_ksISR_CHN_NULL, 0, 0, 0, 0},
                .PORTn     = io_Port_No,
                .Pin       =
                {
                    .pinNum  = io_Pin_No,
                    .Mode    = io_Mode_AIN,
                    .Speed   = io_NoSpeed,
                },
            },
        },
    },
#endif

    .isr          =
    {
      .adc_isr[_ISR_ADC_READY] =
      {
       .id        = 0,
       .handler   = NULL,
       .flag      = 0,
       .IT        = 0,
       .preprio   = 0,
       .subprio   = 0,
      },

      .adc_isr[_ISR_ADC_BUFFER_FUL] =
      {
        .id       = 0,
        .handler  = NULL,
        .flag     = 0,
        .IT       = 0,
        .preprio  = 0,
        .subprio  = 0,
      },
    },
  },
};

/*!
 * @fn tm30AdcTestCallBack
 */
void tm30AdcTestCallBack (void)
{
  if (0x00 != NRF_SAADC->EVENTS_DONE)
  {
    ++gv_tm30TestAdc.adcSem;

    NRF_SAADC->EVENTS_DONE = 0x00;
  }
}
/*!
 * @fn    tm30AdcTestInit
 * @param pADC
 * @param event
 * @param handrailADC_Callback
 * @return
 */
ksRet_t tm30AdcTestInit (tm30AdcTest_t  *pTestAdc,
                         ksU32          event,
                         pISR           tm30AdcTestCB)

{
  __KS_RUNTIME_ASSERT(NULL != pTestAdc, __ASSERT_NULL);

  pTestAdc->adcSem  = 0x00;
  pTestAdc->adcMax  = 0x00;
  pTestAdc->adcMin  = 4096;
  pTestAdc->state   = adcTestOff;
  pTestAdc->errCode = 0x00;

  pTestAdc->adc.isr.adc_isr[event].id     = ksAdcGetIRQn(&pTestAdc->adc, event);
  pTestAdc->adc.isr.adc_isr[event].handler= tm30AdcTestCB;
  ksAdcInit(&pTestAdc->adc);

  if (NULL != tm30AdcTestCB)
  {
    ksIsrIntVectSet(&pTestAdc->adc.isr.adc_isr[event]);
    ksNvicInit(pTestAdc->adc.isr.adc_isr[event].id,
               pTestAdc->adc.isr.adc_isr[event].preprio,
               pTestAdc->adc.isr.adc_isr[event].subprio,
               _NVIC_EN);
  }

  ksAdcBufferConfig(&pTestAdc->adc, (ksAddr_t)pTestAdc->adcBuf, sizeof(pTestAdc->adcBuf) / sizeof(pTestAdc->adcBuf[0]));
  ksAdcCalibrate(&pTestAdc->adc);
  ksAdcBufferConfig(&pTestAdc->adc, (ksAddr_t)pTestAdc->adcBuf, sizeof(pTestAdc->adcBuf) / sizeof(pTestAdc->adcBuf[0]));

  return __DEV_EOK;
}

/**
 * @fn tm30AdcDoSampleing
 */
void tm30AdcDoSampleing (tm30AdcTest_t  *pTestADC)
{
  ksAdcStart(&pTestADC->adc);
  ksAdcSample(&pTestADC->adc);

  while(pTestADC->adcSem < __TM30_ADC_TEST_SENSOR_CNTR)
  {
    asm("nop"); // sleep
  }
  ksAdcStop(&pTestADC->adc);
  pTestADC->adcSem = 0x00;
}

/**
 * @fn    tm30AdcTestLoop
 * @param pPwmTest
 */
void tm30AdcTestLoop (tm30AdcTest_t  *pTestADC)
{
  if (adcTestOff == pTestADC->state)
  {
    ksVU32 adcCntr = 0;
    ksVS16 adcVal = 0;

    pTestADC->adcMin = 4096;
    pTestADC->adcMax = 0;

    do
    {
      tm30AdcDoSampleing(pTestADC);

      adcVal = pTestADC->adcBuf[0x00];

      if (pTestADC->adcMax < adcVal)
      {
        pTestADC->adcMax = adcVal;
      }

      if (pTestADC->adcMin > adcVal)
      {
        pTestADC->adcMin = adcVal;
      }
    }while(++adcCntr < 1024);

    pTestADC->ampMax  = pTestADC->adcMax * 360/ 4096;
    pTestADC->ampMin  = pTestADC->adcMin * 360/ 4096;
    pTestADC->state   = adcTestDone;

    NRF_SAADC->CH[0].PSELP = 0;
    NRF_SAADC->CH[0].PSELN = 0;
    nrf52832AdcSwitch(&gv_tm30TestAdc.adc, ADC_Disable);

    nrf_gpio_cfg_default(gv_tm30TestAdc.adc.ioAin[0][__AIN_SINGLE].Pin.pinNum);
  }
}

/**
 * @fn    tm30AdcTestAnalyze
 * @param pTestADC
 */
void tm30AdcTestAnalyze (tm30AdcTest_t  *pTestADC)
{
  if (adcTestDone == pTestADC->state)
  {
    pTestADC->errCode = 0x00;

    if ((pTestADC->ampMin > __TM30_ADC_AMPMIN_LIMIT_Upper) || (pTestADC->ampMin < __TM30_ADC_AMPMIN_LIMIT_Lower))
    {
      pTestADC->errCode |= 0x01;
    }

    if ((pTestADC->ampMax > __TM30_ADC_AMPMAX_LIMIT_Upper) || (pTestADC->ampMax < __TM30_ADC_AMPMAX_LIMIT_Lower))
    {
      pTestADC->errCode |= 0x02;
    }
  }
}

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
//}
#endif // __cplusplus
