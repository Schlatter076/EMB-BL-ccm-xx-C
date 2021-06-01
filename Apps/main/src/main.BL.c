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

static const ksU08 lc_cmdGetForce[] =
{ 0x01, 0x03, 0x00, 0x00, 0x00, 0x0D, 0x84, 0x0F, };

static float lv_forceInGF = 0.1f;
// 18 -> PC; 14 -> AiDeBao; 05 <- WM

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
#define   __DIVIDOR_RESISTOR    32940 // ohm
#define   __SUPPLY_VOLTAGE      3286  // mv
#define   __REF_VOLTAGE         /* 3600 // */ 3560  // mv
#define   __AIDEBAO_PKT_LEN     31
#elif (__THOR_MODE == _THOR_WANMO)
#define   __DIVIDOR_RESISTOR    32960 // ohm
#define   __SUPPLY_VOLTAGE      3280  // mv
#define   __REF_VOLTAGE         /* 3600 // */ 3000  // mv
#define   __WANMO_PKT_LEN       8 // */ 9
#endif

static ksU32 lv_aiDeBaoCntr = 0x00;
static ksU32 lv_wmUartCntr = 0x00;

static ksS32 lv_filteredADC = 0x00;
static ksS32 lv_Vout = 0x00;
static ksS32 lv_resistorVal = 0x00;
static ksS32 lv_resistorValPrev = 0x00;

static ksS32 lv_bl_filteredADC = 0x00;
static ksS32 lv_bl_Vout = 0x00;
static ksS32 lv_bl_resistorVal = 0x00;
static ksS32 lv_bl_resistorValPrev = 0x00;

#if (__THOR_MODE == _THOR_WANMO)
/**
 *
 * @param pTracer
 * @param pByte
 */
static void wmUardDataHandler (ksTracer_t *pTracer, ksU08 *pByte)
{
  uchar        rcvdByte  = *pByte;
  tracerBuf_t  *pRxBuf   = &uTracer[__UTRACER_IDX_1].rxBuf;

  pRxBuf->buf[pRxBuf->len++] = rcvdByte;

  if (lv_wmUartCntr == __WANMO_PKT_LEN)
  {
    pRxBuf->status = _tracer_Recved;
  }
  else if (lv_wmUartCntr > __WANMO_PKT_LEN)
  {
    lv_wmUartCntr = 0x00;
    deInitUtracerRxBuf();
  }
}

static void wmGetAdcRecvISR (void)
{
  ksUSART_t *pUart = uTracer[__UTRACER_IDX_1].pUsart;

  if(__USART_RECV_is_PENDING(pUart))
  {
    ksU08           rcvdByte  = ksUsartGetByte(pUart);
    tracerStatus_e  status    = uTracer[__UTRACER_IDX_1].rxBuf.status;
    // 52 A1 08 00 C1 56 78 00
    switch (status)
    {
      case _tracer_free :
      {
        switch (lv_wmUartCntr)
        {
          case 0x00 :
          {
            if ((0x52 != rcvdByte) && (0x42 != rcvdByte))
            {
              lv_wmUartCntr = 0x00;
              deInitUtracerRxBuf();
              goto __EXIT_wmUartReturnRecvISR;
            }
          }
          break;

          case 0x01 :
          {
            if (0xA1 != rcvdByte)
            {
              lv_wmUartCntr = 0x00;
              deInitUtracerRxBuf();
              goto __EXIT_wmUartReturnRecvISR;
            }
          }
          break;

          case 0x02 :
          {
             if (0x08 != rcvdByte)
             {
              lv_wmUartCntr = 0x00;
              deInitUtracerRxBuf();
              goto __EXIT_wmUartReturnRecvISR;
             }
          }
          break;
        }
      }
      break;

      default :
        goto __EXIT_wmUartReturnRecvISR;
    }
    ++lv_wmUartCntr;
    wmUardDataHandler(&uTracer[__UTRACER_IDX_1], &rcvdByte);

__EXIT_wmUartReturnRecvISR :
    ksUsartClrITFlag(pUart, pUart->RX_isr.flag);
    NRF_UART0->EVENTS_ERROR = 0x00;
  }
}
#endif

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

		__EXIT_aiDeBaoReturnRecvISR: ksUsartClrITFlag(pUart,
				pUart->RX_isr.flag);

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

ksU32 lv_THOR_KineState;
ksU32 lv_BL_KineState;
ksU32 lv_THOR_qActiveHead;
ksU32 lv_BL_qActiveHead;
ksU32 lv_THOR_qActiveTail;
ksU32 lv_BL_qActiveTail;
ksU32 lv_THOR_qActiveUsed;
ksU32 lv_BL_qActiveUsed;
ksU32 lv_THOR_qActiveBuf[0x05];
ksU32 lv_BL_qActiveBuf[0x05];

/**
 * @fn    thorDeInitKineStateQ
 * @brief De-Initialize the queue used to buffer delta baseline
 */
static void thorDeInitKineStateQ(void)
{
	lv_THOR_qActiveUsed = 0x00;
	lv_THOR_qActiveHead = 0x00;
	lv_THOR_qActiveTail = 0x00;
	lv_THOR_KineState = 0x00;

	lv_BL_qActiveUsed = 0x00;
	lv_BL_qActiveHead = 0x00;
	lv_BL_qActiveTail = 0x00;
	lv_BL_KineState = 0x00;

	for (int i = 0; i < 0x05; ++i)
	{
		lv_THOR_qActiveBuf[i] = 0x00;
		lv_BL_qActiveBuf[i] = 0x00;
	}
}

/**
 * @fn    thorGetAbsVal
 * @param valA
 * @param valB
 * @return
 */
static ksU32 thorGetAbsVal(ksS32 valA, ksS32 valB)
{
	ksS32 delta = 0x00;

	if (valA >= valB)
	{
		delta = valA - valB;
	}
	else
	{
		delta = valB - valA;
	}

	ksU32 absVal = 0x00;
	absVal = delta;

	return absVal;
}

/**
 * @fn      ts210xBufferKinestate
 * @param
 * @brief   update the base value of the sensor's admittance by weighedMAFilter
 * @note    the algorithym is executed only when the sensor is in FREE state
 */
static void thorBufferKinestate(void)
{
	ksU32 deltaAbs = 0x00;
	deltaAbs = thorGetAbsVal(lv_resistorValPrev, lv_resistorVal);

#if   (__ANTI_NOISE_STRATEGY >= __ANTI_NOISE_LEVEL_4)
	deltaAbs >>= 0x03;
#elif (__ANTI_NOISE_STRATEGY >= __ANTI_NOISE_LEVEL_3)
  deltaAbs >>= 0x02;
#elif (__ANTI_NOISE_STRATEGY >= __ANTI_NOISE_LEVEL_2)
  deltaAbs >>= 0x01;
#endif

#if (__ANTI_NOISE_STRATEGY != __ANTI_NOISE_LEVEL_0)
  deltaAbs -= !!deltaAbs;
#else

#endif

	if (0x05 == lv_THOR_qActiveUsed)
	{ // the Q is full
		lv_THOR_KineState -= lv_THOR_qActiveBuf[lv_THOR_qActiveHead];
		++lv_THOR_qActiveHead;
		lv_THOR_qActiveHead %= 0x05; // pop Data from Head
		--lv_THOR_qActiveUsed;
	}

	lv_THOR_qActiveBuf[lv_THOR_qActiveTail] = deltaAbs;     // put Data at Tail
	++lv_THOR_qActiveTail;
	lv_THOR_qActiveTail %= 0x05;
	++lv_THOR_qActiveUsed;

	lv_THOR_KineState += deltaAbs; // less than 255
}

static void bissellBufferKinestate(void)
{
	ksU32 deltaAbs = 0x00;
	deltaAbs = thorGetAbsVal(lv_bl_resistorValPrev, lv_bl_resistorVal);

#if   (__ANTI_NOISE_STRATEGY >= __ANTI_NOISE_LEVEL_4)
	deltaAbs >>= 0x03;
#elif (__ANTI_NOISE_STRATEGY >= __ANTI_NOISE_LEVEL_3)
  deltaAbs >>= 0x02;
#elif (__ANTI_NOISE_STRATEGY >= __ANTI_NOISE_LEVEL_2)
  deltaAbs >>= 0x01;
#endif

#if (__ANTI_NOISE_STRATEGY != __ANTI_NOISE_LEVEL_0)
  deltaAbs -= !!deltaAbs;
#else

#endif

	if (0x05 == lv_BL_qActiveUsed)
	{ // the Q is full
		lv_BL_KineState -= lv_BL_qActiveBuf[lv_BL_qActiveHead];
		++lv_BL_qActiveHead;
		lv_BL_qActiveHead %= 0x05; // pop Data from Head
		--lv_BL_qActiveUsed;
	}

	lv_BL_qActiveBuf[lv_BL_qActiveTail] = deltaAbs;     // put Data at Tail
	++lv_BL_qActiveTail;
	lv_BL_qActiveTail %= 0x05;
	++lv_BL_qActiveUsed;

	lv_BL_KineState += deltaAbs; // less than 255
}

/**
 * @fn main
 * @return
 */
int main()
{
	unsigned int k1 = 0, k2 = 0;
	mcuBSPInit(aiDeBaoReturnRecvISR);

	uTracer[__UTRACER_IDX_1].pUsart->gpio[_KS_USART_IO_TXD].Pin.pinNum =
			(ksGPIO_PIN_e) __PIN_TO_PC;
	ksGpioInit(&uTracer[__UTRACER_IDX_1].pUsart->gpio[_KS_USART_IO_TXD]);

	uTracer[__UTRACER_IDX_1].pUsart->gpio[_KS_USART_IO_RXD].Pin.pinNum =
			(ksGPIO_PIN_e) __PIN_FROM_PC;
	ksGpioInit(&uTracer[__UTRACER_IDX_1].pUsart->gpio[_KS_USART_IO_RXD]);

#if (__THOR_MODE == _THOR_WANMO)
  uTracer[__UTRACER_IDX_1].pUsart->gpio[_KS_USART_IO_RXD].Pin.pinNum = (ksGPIO_PIN_e)__PIN_FROM_WM;
  ksGpioInit(&uTracer[__UTRACER_IDX_1].pUsart->gpio[_KS_USART_IO_RXD]);
#endif

#if (__THOR_MODE == _THOR_NORMAL)
	tm30AdcTestInit(&gv_tm30TestAdc,
	_ISR_ADC_DONE, // _ISR_ADC_BUFFER_FUL,
			tm30AdcTestCallBack);
#endif

	uTracerRemapUart(__PIN_TO_PC);
	__uTRACER_PRINTF(__TRACER_OUT, true,
			"\n*********************************************\n");
	__uTRACER_PRINTF(__TRACER_OUT, true,
			"***********The thor is running***************\n");
	__uTRACER_PRINTF(__TRACER_OUT, true,
			"*********************************************\n");

	lv_filteredADC = 0x00;
	lv_bl_filteredADC = 0x00;
	thorDeInitKineStateQ();
	while (true)
	{
		/*
		 uTracerRemapUart(__PIN_TO_ADB);
		 do
		 { // receive forve value from aidebao
		 __uTRACER_SEND_BUF(__TRACER_OUT,  &lc_cmdGetForce, sizeof(lc_cmdGetForce));
		 ksDelayMsByLoop(200);
		 } while(true && (_tracer_Recved != uTracer[__UTRACER_IDX_1].rxBuf.status));

		 ksU32 *pForceInteger =
		 (ksU32*) &uTracer[__UTRACER_IDX_1].rxBuf.buf[0x03];
		 *pForceInteger = ks_htonl(*pForceInteger);

		 float *pForceFloat = (float*) &uTracer[__UTRACER_IDX_1].rxBuf.buf[0x03];

		 lv_forceInGF = *pForceFloat;
		 lv_forceInGF *= -1000.0f;

		 lv_aiDeBaoCntr = 0x00;
		 deInitUtracerRxBuf();
		 //*/

#if   (__THOR_MODE == _THOR_NORMAL)

		tm30AdcDoSampleing(&gv_tm30TestAdc);

		/*
		 __uTRACER_PRINTF(__TRACER_OUT, true, "%d, %d, %d, %d, %d, %d, %d, %d\n",
		 gv_tm30TestAdc.adcBuf[0],
		 gv_tm30TestAdc.adcBuf[1],
		 gv_tm30TestAdc.adcBuf[2],
		 gv_tm30TestAdc.adcBuf[3],
		 gv_tm30TestAdc.adcBuf[4],
		 gv_tm30TestAdc.adcBuf[5],
		 gv_tm30TestAdc.adcBuf[6],
		 gv_tm30TestAdc.adcBuf[7]);

		 //*/

		// calculation
		lv_filteredADC = rcFilter(gv_tm30TestAdc.adcBuf[0], lv_filteredADC, 5);
		lv_Vout = lv_filteredADC * __REF_VOLTAGE / 4096;

		lv_resistorValPrev = lv_resistorVal;
		lv_resistorVal = (__SUPPLY_VOLTAGE - lv_Vout) * __DIVIDOR_RESISTOR
				/ lv_Vout;

		tm30AdcDoSampleing(&gv_tm30TestAdc);

		lv_bl_filteredADC = rcFilter(gv_tm30TestAdc.adcBuf[0],
				lv_bl_filteredADC, 5);
		lv_bl_Vout = lv_bl_filteredADC * __REF_VOLTAGE / 4096;

		lv_bl_resistorValPrev = lv_bl_resistorVal;
		lv_bl_resistorVal = (__SUPPLY_VOLTAGE - lv_bl_Vout) * __DIVIDOR_RESISTOR
				/ lv_bl_Vout;

#elif (__THOR_MODE == _THOR_WANMO)
    deInitUtracerRxBuf();
    uTracerRemapUart(__PIN_FROM_WM);
    while(_tracer_Recved != uTracer[__UTRACER_IDX_1].rxBuf.status);

    ksU16 adcVal = 0x00;
    adcVal  = uTracer[__UTRACER_IDX_1].rxBuf.buf[0x04];
    adcVal += uTracer[__UTRACER_IDX_1].rxBuf.buf[0x03] << 0x08;

   ksS16 adcValSigned = (ksS16)adcVal;

    // TODO
    lv_filteredADC      = rcFilter(adcValSigned, lv_filteredADC, 5);
    lv_Vout             = lv_filteredADC * __REF_VOLTAGE / 32768;

    lv_resistorValPrev  = lv_resistorVal;
    lv_resistorVal      = (__SUPPLY_VOLTAGE -  lv_Vout) * __DIVIDOR_RESISTOR /  lv_Vout;

    lv_wmUartCntr = 0x00;
    deInitUtracerRxBuf();

    uTracerRemapUart(__PIN_TO_ADB);
#endif

		thorBufferKinestate();
		bissellBufferKinestate();

		if (lv_resistorVal == 0)
		{
			lv_resistorVal = 1;
		}
		if (lv_bl_resistorVal == 0)
		{
			lv_bl_resistorVal = 1;
		}

		ksS32 gfInt = (ksS32) (lv_forceInGF * 10);
		ksS32 gfDecimal = gfInt % 10;
		if (gfDecimal < 0)
		{
			gfDecimal = -1 * gfDecimal;
		}

		k1 = lv_THOR_KineState * 100 / lv_resistorVal;
		k2 = lv_BL_KineState * 100 / lv_bl_resistorVal;
		uTracerRemapUart(__PIN_TO_PC);
		__uTRACER_PRINTF(__TRACER_OUT, true, "%7d, %4d, %3d, %7d, %4d, %3d\n",
				lv_resistorVal, // resisor
				lv_Vout,// Vout
				k1,// in 100%
				lv_bl_resistorVal,// resisor
				lv_bl_Vout,// Vout
				k2);// in 100%

		//*/
		if (lv_Vout > 200 || lv_bl_Vout > 200)
		{
			LEDs_On(&gv_ledPeriph[0]); //马达启动
			if (lv_Vout > lv_bl_Vout)
			{
				if (lv_Vout > 200 && k1 <= 1 && (lv_Vout - lv_bl_Vout) > 60)
				{
					LEDs_On(&gv_ledPeriph[1]);
					LEDs_Off(&gv_ledPeriph[6]);
				}
				else
				{
					LEDs_Off(&gv_ledPeriph[1]);
				}
			}
			else
			{
				if (lv_bl_Vout > 200 && k2 <= 1 && (lv_bl_Vout - lv_Vout) > 60)
				{
					LEDs_On(&gv_ledPeriph[6]);
					LEDs_Off(&gv_ledPeriph[1]);
				}
				else
				{
					LEDs_Off(&gv_ledPeriph[6]);
				}
			}
		}
		else
		{
			LEDs_Off(&gv_ledPeriph[0]);
			LEDs_Off(&gv_ledPeriph[1]);
			LEDs_Off(&gv_ledPeriph[6]);
		}
		ksDelayMsByLoop(100);
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

