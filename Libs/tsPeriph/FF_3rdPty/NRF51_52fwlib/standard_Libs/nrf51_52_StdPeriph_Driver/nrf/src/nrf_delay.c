/* Copyright (c) 2012 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */
/**** Includes ****************************************************************/
#include <stdio.h> 
#include "../inc/nrf_delay.h"

/***** Function Definitions ***************************************************/
/*lint --e{438} "Variable not used" */
////////////////////////////////////////////////////////////////////////////////
/// @fn     : nrf_delay_ms
/// @param  : number_of_ms : how many mili seconds
/// @return : description of return value.
/// @brief  : Brief description of the function.
/// @author : kensky
/// @date   : 2016-1-5
/// @pre    : add precondition here if needed.
/// @note   : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
void nrf_delay_ms(uint32_t volatile number_of_ms)
{
  while (number_of_ms != 0)
  {
    number_of_ms--;
    nrf_delay_us(999);
  }
}
