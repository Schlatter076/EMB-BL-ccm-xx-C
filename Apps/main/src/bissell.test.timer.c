/*
 * bissell.test.timer.c
 *
 *  Created on: Jun 8, 2021
 *      Author: loyer
 */

#include "../../main/inc/bissell.test.timer.h"

ksU16 duty = 0;
ksTIM_t blTimer =
{
	.bus = is_tim00,
	.periphID = 0x00000000,
	.addrBase = 0x00000000,
	.width = is_16_bits, /* 0-16bit 1-8bit 2-24bit 3-32bit */
	.UP_isr =
	{
		.id = (ksS32)(0x00),
		.handler = NULL, /* interrupt handler */
		.flag = 0x00,
		.IT = 0x00,
		.preprio = 0x03,
		.subprio = 0x00
	},
	.GE_isr =
	{
		.id = (ksS32)(0x00),
		.handler = NULL, /* interrupt handler */
		.flag = 0x00,
		.IT = 0x00,
		.preprio = 0x00,
		.subprio = 0x00
	},
	.params =
	{
		.Prescaler = 0,
		.Mode = is_UP,
		.Period = 16000,
		.ClkDiv = is_DIV01,
		.RepetitionCounter = 0x00,
		.count2x = 0x00,
		.isOneShot = 0x00
	},
	.status = timer_state_running,
	.locked = ksFree,
};

void bissell_timer_Init(ksTIM_t *pTestTimer, ksU32 us_per, pISR callback_hal)
{

  /* init timer config */
  pTestTimer->freq = 16000000;
  pTestTimer->UP_isr.id = ksTimerGetIRQn(pTestTimer,NRF_TIMER_EVENT_COMPARE0);
  //pTestTimer->UP_isr.id = TIMER1_IRQn;
  pTestTimer->UP_isr.handler = callback_hal;

  static int errRet = 0;

  errRet = ksTimerInit(pTestTimer);
  ksTimerIntervalInit(pTestTimer, us_per);//unit:us

  /* init timer callback */
  if(NULL != callback_hal)
  {
    ksIsrIntVectSet(&pTestTimer->UP_isr);
    ksNvicInit(pTestTimer->UP_isr.id,
              pTestTimer->UP_isr.preprio,
              pTestTimer->UP_isr.subprio,
              _NVIC_EN);
  }

  ksTimerSwitch(pTestTimer, timer_state_running);

  /*Enable time irq*/
  {
    __Enable_TIMn_Irq(pTestTimer,(1<<16));
  }
}



