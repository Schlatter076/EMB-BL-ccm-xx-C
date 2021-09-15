////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "main.c"
/// * Author  : Ffh
/// * Version :
/// * Date    : 2021年2月28日
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
#include "../../BSPs/BSP.h"
#include <Tracer.h>
#include "../../main/inc/tm30.test.adc.h"
#include "../../callbacks/inc/tsTracerRxCallBacks.h"
#include "../../main/inc/bissell.test.timer.h"
#include "../../main/inc/sensor.sample.type.h"
#include "../../main/inc/nrf52832.flash.h"

#define   _STABLED_THRESHOLD   5
#define   _FRONT_SLOPE         3.32f
#define   _FRONR_FACTOR        5
#define   _BACK_FACTOR         5
#define   _BACK_SLOPE          4.0f
#define   _MIN_TRIGGER_F       50
#define   _MIN_DIFF_F          50
#define   _GEAR_MIDDLE         730

#define   __PIN_TO_PC           0x12
#define   __PIN_FROM_PC         0x14
#define   __PIN_TO_ADB          0x0E
#define   __PIN_FROM_ADB        0x10
#define   __PIN_FROM_WM         0x05

#define   _THOR_NORMAL          0x00
#define   _THOR_WANMO           0x01

#define   __THOR_MODE           _THOR_NORMAL // */ _THOR_WANMO

// 3296 for 4#
#if   (__THOR_MODE == _THOR_NORMAL)
#define   __AIDEBAO_PKT_LEN     31
#elif (__THOR_MODE == _THOR_WANMO)
#define   __DIVIDOR_RESISTOR    32960 // ohm
#define   __SUPPLY_VOLTAGE      3280  // mv
#define   __REF_VOLTAGE         /* 3600 // */ 3000  // mv
#define   __WANMO_PKT_LEN       8 // */ 9
#endif

static ksU32 lv_aiDeBaoCntr = 0x00;

/**
 * @fn aiDeBaoRcvdDataHandler
 */
static void aiDeBaoRcvdDataHandler(ksTracer_t *pTracer, ksU08 *pByte)
{
  uchar rcvdByte = *pByte;
  tracerBuf_t *pRxBuf = &uTracer[__UTRACER_IDX_1].rxBuf;

  pRxBuf->buf[pRxBuf->len++] = rcvdByte;

  if (lv_aiDeBaoCntr == __AIDEBAO_PKT_LEN)
  {
    pRxBuf->status = _tracer_Recved;
  }
  else if (lv_aiDeBaoCntr > __AIDEBAO_PKT_LEN)
  {
    lv_aiDeBaoCntr = 0x00;
    deInitUtracerRxBuf();
  }
}

/**
 * @fn aiDeBaoReturnRecvISR
 */
static void aiDeBaoReturnRecvISR(void)
{
  ksUSART_t *pUart = uTracer[__UTRACER_IDX_1].pUsart;

  if (__USART_RECV_is_PENDING(pUart))
  {
    ksU08 rcvdByte = ksUsartGetByte(pUart);
    tracerStatus_e status = uTracer[__UTRACER_IDX_1].rxBuf.status;

    switch (status)
    {
    case _tracer_free:
    { // the 1st byte
      switch (lv_aiDeBaoCntr)
      {
      case 0x00:
      {
        if (0x01 != rcvdByte)
        {
          lv_aiDeBaoCntr = 0x00;
          deInitUtracerRxBuf();
          goto __EXIT_aiDeBaoReturnRecvISR;
        }
      }
        break;

      case 0x01:
      {
        if (0x03 != rcvdByte)
        {
          lv_aiDeBaoCntr = 0x00;
          deInitUtracerRxBuf();
          goto __EXIT_aiDeBaoReturnRecvISR;
        }
      }
        break;

      case 0x02:
      {
        if (0x1a == rcvdByte)
        {
          uTracer[__UTRACER_IDX_1].rxBuf.status = _tracer_Locked;
        }
        else
        {
          lv_aiDeBaoCntr = 0x00;
          deInitUtracerRxBuf();
          goto __EXIT_aiDeBaoReturnRecvISR;
        }
      }
        break;

      default:
        break;
      }
    }
      break;

    case _tracer_Locked:
    {
      asm("nop");
    }
      break;

    default:
      goto __EXIT_aiDeBaoReturnRecvISR;
    }

    ++lv_aiDeBaoCntr;
    aiDeBaoRcvdDataHandler(&uTracer[__UTRACER_IDX_1], &rcvdByte);

    __EXIT_aiDeBaoReturnRecvISR: ksUsartClrITFlag(pUart, pUart->RX_isr.flag);

    NRF_UART0->EVENTS_ERROR = 0x00;
  }
}

/**
 * @fn    uTracerRemapUart
 * @param pin
 */
static void uTracerRemapUart(ksU32 pin)
{
  switch (pin)
  {
  case __PIN_TO_ADB:
  {
    NRF_UART0->PSELTXD = pin;
    NRF_UART0->PSELRXD = __PIN_FROM_ADB;
    NRF_UART0->BAUDRATE = 2576384; // 9600

    NRF52832_ISR_IntVectSet(UARTE0_UART0_IRQn, aiDeBaoReturnRecvISR);
  }
    break;

  case __PIN_TO_PC:
  {
    NRF_UART0->PSELTXD = pin;
    NRF_UART0->PSELRXD = __PIN_FROM_PC;
    NRF_UART0->BAUDRATE = 2576384; // 9600

    NRF52832_ISR_IntVectSet(UARTE0_UART0_IRQn, aiDeBaoReturnRecvISR);
  }
    break;

#if (__THOR_MODE == _THOR_WANMO)
    case __PIN_FROM_WM :
    {
      NRF_UART0->PSELRXD  = __PIN_FROM_WM;
      NRF_UART0->BAUDRATE = /* 2576384; // */ 30642176; // 115200

      NRF52832_ISR_IntVectSet(UARTE0_UART0_IRQn, wmGetAdcRecvISR);
    }
    break;
#endif

  default:
    break;
  }

  ksDelayMsByLoop(10);
}

void modifyLEDStatus(float gf1, ksU16 k1, float gf2, ksU16 k2)
{
  ksU32 abs_Force = 0;
  static ksU32 abs_ForcePre = 0;
  if ((gf1 >= _MIN_TRIGGER_F && gf1 <= _GEAR_MIDDLE && gf2 <= _GEAR_MIDDLE) || (gf2 >= _MIN_TRIGGER_F && gf2 <= _GEAR_MIDDLE && gf1 <= _GEAR_MIDDLE))
  {
    if (gf1 > gf2)
    {
      abs_Force = gf1 - gf2;
      if (gf1 > _MIN_TRIGGER_F && k1 <= _STABLED_THRESHOLD && abs_Force > _MIN_DIFF_F)
      {
        LEDs_On(&gv_ledPeriph[1]);
        LEDs_Off(&gv_ledPeriph[6]);
      }
      else
      {
        LEDs_Off(&gv_ledPeriph[1]);
        if (duty > 0)
        {
          duty--;
        }
      }
    }
    else
    {
      abs_Force = gf2 - gf1;
      if (gf2 > _MIN_TRIGGER_F && k2 <= _STABLED_THRESHOLD && abs_Force > _MIN_DIFF_F)
      {
        LEDs_On(&gv_ledPeriph[6]);
        LEDs_Off(&gv_ledPeriph[1]);
      }
      else
      {
        LEDs_Off(&gv_ledPeriph[6]);
        if (duty > 0)
        {
          duty--;
        }
      }
    }
    if (abs_Force > abs_ForcePre && duty < 20)
    {

      duty++;
    }
    else if (duty > 0)
    {
      //duty--;
    }
    abs_ForcePre = abs_Force;
  }
  else
  {
    duty = 0;
    abs_ForcePre = 0;
    LEDs_Off(&gv_ledPeriph[1]);
    LEDs_Off(&gv_ledPeriph[6]);
  }
  //duty = abs_Force % 20;

  //*/
}

void bissell_timer0_callback(void)
{
  static ksU32 cnt = 0;
  cnt++;
  if (cnt % 20 < duty)
  {
    LEDs_On(&gv_ledPeriph[0]);
  }
  else
  {
    LEDs_Off(&gv_ledPeriph[0]);
  }
  TIMx_ClrFlag(&blTimer, NRF_TIMER_CC_CHANNEL0);
}

ksU32 admBuf[10];
ksU32 midAdm = 0;
ksU32 midAdmOld = 0;
/**
 * @fn main
 * @return
 */
int main()
{
  ksU32 calVal = 0;
  mcuBSPInit(aiDeBaoReturnRecvISR);
  bissell_timer_Init(&blTimer, 800, bissell_timer0_callback);
  Init_sample();
  tm30AdcTestInit(&gv_tm30TestAdc, _ISR_ADC_DONE, tm30AdcTestCallBack);

  uTracer[__UTRACER_IDX_1].pUsart->gpio[_KS_USART_IO_TXD].Pin.pinNum = (ksGPIO_PIN_e) __PIN_TO_PC;
  ksGpioInit(&uTracer[__UTRACER_IDX_1].pUsart->gpio[_KS_USART_IO_TXD]);

  uTracer[__UTRACER_IDX_1].pUsart->gpio[_KS_USART_IO_RXD].Pin.pinNum = (ksGPIO_PIN_e) __PIN_FROM_PC;
  ksGpioInit(&uTracer[__UTRACER_IDX_1].pUsart->gpio[_KS_USART_IO_RXD]);

  uTracerRemapUart(__PIN_TO_PC);
  __uTRACER_PRINTF(__TRACER_OUT, true, "\n*********************************************\n");
  __uTRACER_PRINTF(__TRACER_OUT, true, "**********This is bissell program************\n");
  __uTRACER_PRINTF(__TRACER_OUT, true, "*********************************************\n");


  while (true)
  {
    for(int i = 0; i < 10; i++)
    {
      tm30AdcDoSampleing(&gv_tm30TestAdc);
      caculateVoutAndResistor(&sensorSamples[0], gv_tm30TestAdc.adcBuf[0], 5, 800);
      caculateVoutAndResistor(&sensorSamples[1], gv_tm30TestAdc.adcBuf[1], 5, 800);
      admBuf[i] = sensorSamples[0].admVal;
      ksDelayMsByLoop(1);
    }

    //midAdm = GetMedianNum(admBuf, 10);
    midAdm = GetWidthNum(GetMedianNum(admBuf, 10), &midAdmOld, 10);
    if(_tracer_Recved == uTracer[__UTRACER_IDX_1].rxBuf.status)
    {
      if(uTracer[__UTRACER_IDX_1].rxBuf.buf[0x03] == 0x76)
      {
        writeCalVal((ksU32)((uTracer[__UTRACER_IDX_1].rxBuf.buf[0x04] << 8) | uTracer[__UTRACER_IDX_1].rxBuf.buf[0x05]));
        deInitUtracerRxBuf();
      }
    }
    calVal = readCalVal();

    __uTRACER_PRINTF(__TRACER_OUT, true, "%d, %d, %d, %d, %d, %d, %d\n", //format
        sensorSamples[0].filteredADC,  //
        sensorSamples[0].resistorVal,  //
        // sensorSamples[0].admVal,  //
        midAdm,  //
        sensorSamples[1].filteredADC,  //
        sensorSamples[1].resistorVal,  //
        sensorSamples[1].admVal,  //
        calVal); // in 100%

    //ksDelayMsByLoop(10);
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

