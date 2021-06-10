/*
 * bissell.test.timer.h
 *
 *  Created on: Jun 8, 2021
 *      Author: loyer
 */

#ifndef APPS_MAIN_INC_BISSELL_TEST_TIMER_H_
#define APPS_MAIN_INC_BISSELL_TEST_TIMER_H_

/***** Include ****************************************************************/
#include <projCfg.h>
#include <ksPeriph.h>
#include <FF_3rdPty/NRF51_52fwlib/standard_Libs/nrf51_52_StdPeriph_Driver/nrfx/inc/nrfx_timer.h>
#include <FF_3rdPty/NRF51_52fwlib/standard_Libs/nrf51_52_StdPeriph_Driver/nrf/inc/nrf_timer.h>
#include "09_Timer/3_HAL/inc/Timer.h"

extern ksTIM_t blTimer;
void bissell_timer_Init(ksTIM_t *pTestTimer, ksU32 us_per, pISR callback_hal);
extern ksU16 duty;
#endif /* APPS_MAIN_INC_BISSELL_TEST_TIMER_H_ */
