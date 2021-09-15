/*
 * nrf52832.flash.c
 *
 *  Created on: Sep 15, 2021
 *      Author: loyer
 */
#include "../../main/inc/nrf52832.flash.h"

/**
 *
 */
void writeCalVal(ksU32 val)
{
  nrf_nvmc_page_erase(CAL_ADDR);
  nrf_nvmc_write_word(CAL_ADDR, val);
}

/**
 *
 */
ksU32 readCalVal(void)
{
  return *(ksU32 *)CAL_ADDR;
}

