/*
 * nrf52832.flash.h
 *
 *  Created on: Sep 15, 2021
 *      Author: loyer
 */

#ifndef APPS_MAIN_INC_NRF52832_FLASH_H_
#define APPS_MAIN_INC_NRF52832_FLASH_H_

#include <projCfg.h>
#include <ksPeriph.h>
#include <FF_3rdPty/NRF51_52fwlib/standard_Libs/nrf51_52_StdPeriph_Driver/nrf/inc/nrf_nvmc.h>

#define CAL_ADDR   0x0007F000



void writeCalVal(ksU32 val);
ksU32 readCalVal(void);

#endif /* APPS_MAIN_INC_NRF52832_FLASH_H_ */
