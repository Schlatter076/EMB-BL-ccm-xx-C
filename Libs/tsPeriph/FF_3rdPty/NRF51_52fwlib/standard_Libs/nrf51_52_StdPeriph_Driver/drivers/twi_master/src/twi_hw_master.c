/**
 * Copyright (c) 2009 - 2019, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include "../inc/twi_master.h"
#include "../../../nrf/inc/nrf_delay.h"
#include "../../../nrf/inc/nrf_gpio.h"

/* Max cycles approximately to wait on RXDREADY and TXDREADY event,
 * This is optimized way instead of using timers, this is not power aware. */
#define MAX_TIMEOUT_LOOPS (20000UL) /**< MAX while loops to wait for RXD/TXD event */

/**
 * @fn      twi_master_timeout
 * @param   timeout
 * @brief   Recover the peripheral as indicated by PAN 56:
 *          "TWI: TWI module lock-up." found at
 *          Product Anomaly Notification document found at
 *          https://www.nordicsemi.com/eng/Products/Bluetooth-R-low-energy/nRF51822/#Downloads
 * @return  true : nothing wrong; false timeout or something wrong
 */
static bool twi_master_timeout (uint32_t timeout)
{
  if ((timeout == 0) || (NRF_TWI1->EVENTS_ERROR != 0))
  {
    NRF_TWI1->EVENTS_ERROR = 0;
    NRF_TWI1->ENABLE       = TWI_ENABLE_ENABLE_Disabled << TWI_ENABLE_ENABLE_Pos;
#if defined(NRF51)
    NRF_TWI1->POWER        = 0;
#endif
    nrf_delay_us(5);
#if defined(NRF51)
    NRF_TWI1->POWER        = 1;
#endif
    NRF_TWI1->ENABLE       = TWI_ENABLE_ENABLE_Enabled << TWI_ENABLE_ENABLE_Pos;

    (void)twi_master_init();

    return false;
  }

  return true;
}

/**
 * @fn      twi_master_issue_stopcondition
 * @return  always true, for now
 */
bool twi_master_issue_stopcondition(void)
{
  NRF_TWI1->EVENTS_STOPPED = 0;
  NRF_TWI1->TASKS_STOP     = 1;
  /* Wait until stop sequence is sent */
  while (NRF_TWI1->EVENTS_STOPPED == 0);

  return true;
}

/**
 * @fn    twi_master_issue_startcondition
 * @brief dummy interface
 * @return
 */
bool twi_master_issue_startcondition(void)
{
  return true;
}

/**
 * @fn    twi_master_write
 * @param data
 * @param data_length
 * @param issue_stop_condition
 * @return
 */
uint32_t twi_master_write(uint8_t *pData, uint8_t dataLen, bool issue_stop_condition)
{
  if (dataLen > 0)
  {
    NRF_TWI1->TXD           = *pData++;
    NRF_TWI1->TASKS_STARTTX = 0x01uL;

    /** @snippet [TWI HW master write] */
    uint32_t timeout = MAX_TIMEOUT_LOOPS; /* max loops to wait for EVENTS_TXDSENT event*/

    while(dataLen > 0)
    {
      while ((NRF_TWI1->EVENTS_TXDSENT == 0) &&
             (NRF_TWI1->EVENTS_ERROR   == 0) &&
             (--timeout));

      if ((timeout == 0) || (NRF_TWI1->EVENTS_ERROR != 0))
      {
        return twi_master_timeout(timeout); // TODO : what will we do when problem occurs
      }
      timeout = MAX_TIMEOUT_LOOPS; /* max loops to wait for EVENTS_TXDSENT event*/

      NRF_TWI1->EVENTS_TXDSENT = 0x00uL;

      if (--dataLen > 0)
      {
        NRF_TWI1->TXD = *pData++;
      }
    }
    /** @snippet [TWI HW master write] */

    if (issue_stop_condition)
    {
      twi_master_issue_stopcondition();
    }
  }

  return (dataLen == 0);
}

/** @brief Function for read by twi_master.
 */
uint32_t twi_master_read(uint8_t *pData, uint8_t dataLen, bool issue_stop_condition)
{
  uint32_t retLen  = 0x00uL, timeout = 0x00uL;
  bool     isConcatenated  = false;

  if (dataLen > 0)
  {
    if ((uint32_t)&NRF_TWI1->TASKS_SUSPEND == NRF_PPI->CH[0].TEP)
    {
      isConcatenated = true;
    }

    if ((1 == dataLen) && (issue_stop_condition))
    {
      NRF_PPI->CH[0].TEP = (uint32_t)&NRF_TWI1->TASKS_STOP;
    }
    else
    {
      NRF_PPI->CH[0].TEP = (uint32_t)&NRF_TWI1->TASKS_SUSPEND;
    }

    if (false == isConcatenated)
    {
      NRF_PPI->CHENSET          = PPI_CHENSET_CH0_Msk;
      NRF_TWI1->EVENTS_RXDREADY = 0;
      NRF_TWI1->TASKS_STARTRX   = 1;
    }
    else
    {
      timeout = MAX_TIMEOUT_LOOPS; /* max loops to wait for RXDREADY event*/
      while ((NRF_TWI1->EVENTS_SUSPENDED == 0) &&
             (NRF_TWI1->EVENTS_ERROR     == 0) &&
             (--timeout));
      isConcatenated = false; // clear

      if (false == twi_master_timeout(timeout))
      {
        return false;
      }

      NRF_TWI1->TASKS_RESUME = 1;
    }
    
    /** @snippet [TWI HW master read] */
    do
    {
      timeout = MAX_TIMEOUT_LOOPS;
      while ((NRF_TWI1->EVENTS_RXDREADY == 0) &&
             (NRF_TWI1->EVENTS_ERROR    == 0) &&
             (--timeout));

      NRF_TWI1->EVENTS_RXDREADY = 0;

      if ((timeout == 0) || (NRF_TWI1->EVENTS_ERROR != 0))
      {
        return twi_master_timeout(timeout);
      }

      *pData++ = NRF_TWI1->RXD;
      ++retLen;

      if (dataLen > 0x01uL)
      {
        if ((0x02uL == dataLen) && (issue_stop_condition))
        {
          NRF_PPI->CH[0].TEP = (uint32_t)&NRF_TWI1->TASKS_STOP;
        }

        // Recover the peripheral as indicated by PAN 56: "TWI: TWI module lock-up." found at
        // Product Anomaly Notification document found at
        // https://www.nordicsemi.com/eng/Products/Bluetooth-R-low-energy/nRF51822/#Downloads
        // nrf_delay_us(5);
        NRF_TWI1->TASKS_RESUME = 1;
      }
    } while(--dataLen);
    /** @snippet [TWI HW master read] */

    if (issue_stop_condition)
    { /* Wait until stop sequence is sent */
      if (NRF_PPI->CH[0].TEP == (uint32_t)&NRF_TWI1->TASKS_STOP)
      {
        NRF_TWI1->EVENTS_STOPPED   = 0x00uL;

        timeout = MAX_TIMEOUT_LOOPS;
        while (--timeout && (NRF_TWI1->EVENTS_STOPPED == 0));

        NRF_TWI1->EVENTS_STOPPED   = 0x00uL;
        NRF_TWI1->EVENTS_SUSPENDED = 0x00uL;
      }

      NRF_PPI->CHENCLR           = PPI_CHENCLR_CH0_Msk;
    }
    NRF_TWI1->EVENTS_BB          = 0x00uL;
  }

  return retLen;
}


/**
 * @brief Function for detecting stuck slaves (SDA = 0 and SCL = 1) and tries to clear the bus.
 *
 * @return
 * @retval false Bus is stuck.
 * @retval true Bus is clear.
 */
bool twi_master_clear_bus(void)
{
  uint32_t twi_state;
  bool     bus_clear;
  uint32_t clk_pin_config;
  uint32_t data_pin_config;

  // Save and disable TWI hardware so software can take control over the pins.
  twi_state        = NRF_TWI1->ENABLE;
  NRF_TWI1->ENABLE = TWI_ENABLE_ENABLE_Disabled << TWI_ENABLE_ENABLE_Pos;

  clk_pin_config = NRF_GPIO->PIN_CNF[TWI_MASTER_CONFIG_CLOCK_PIN_NUMBER];
  
  NRF_GPIO->PIN_CNF[TWI_MASTER_CONFIG_CLOCK_PIN_NUMBER] =      \
      (GPIO_PIN_CNF_SENSE_Disabled  << GPIO_PIN_CNF_SENSE_Pos)  | \
      (GPIO_PIN_CNF_DRIVE_S0D1      << GPIO_PIN_CNF_DRIVE_Pos)  | \
      (GPIO_PIN_CNF_PULL_Pullup     << GPIO_PIN_CNF_PULL_Pos)   | \
      (GPIO_PIN_CNF_INPUT_Connect   << GPIO_PIN_CNF_INPUT_Pos)  | \
      (GPIO_PIN_CNF_DIR_Output      << GPIO_PIN_CNF_DIR_Pos);

  data_pin_config = NRF_GPIO->PIN_CNF[TWI_MASTER_CONFIG_DATA_PIN_NUMBER];
  
  NRF_GPIO->PIN_CNF[TWI_MASTER_CONFIG_DATA_PIN_NUMBER] =       \
      (GPIO_PIN_CNF_SENSE_Disabled  << GPIO_PIN_CNF_SENSE_Pos)  | \
      (GPIO_PIN_CNF_DRIVE_S0D1      << GPIO_PIN_CNF_DRIVE_Pos)  | \
      (GPIO_PIN_CNF_PULL_Pullup     << GPIO_PIN_CNF_PULL_Pos)   | \
      (GPIO_PIN_CNF_INPUT_Connect   << GPIO_PIN_CNF_INPUT_Pos)  | \
      (GPIO_PIN_CNF_DIR_Output      << GPIO_PIN_CNF_DIR_Pos);

  TWI_SDA_HIGH();
  TWI_SCL_HIGH();
  TWI_DELAY();

  if ((TWI_SDA_READ() == 1) && (TWI_SCL_READ() == 1))
  {
    bus_clear = true;
  }
  else
  {
    bus_clear = false;

    // Clock max 18 pulses worst case scenario(9 for master to send the rest of command and 9
    // for slave to respond) to SCL line and wait for SDA come high.
    for (uint_fast8_t i=18; i--;)
    {
      TWI_SCL_LOW();
      TWI_DELAY();
      TWI_SCL_HIGH();
      TWI_DELAY();

      if (TWI_SDA_READ() == 1)
      {
        bus_clear = true;
        break;
      }
    }
  }

  NRF_GPIO->PIN_CNF[TWI_MASTER_CONFIG_CLOCK_PIN_NUMBER] = clk_pin_config;
  NRF_GPIO->PIN_CNF[TWI_MASTER_CONFIG_DATA_PIN_NUMBER]  = data_pin_config;

  NRF_TWI1->ENABLE = twi_state;

  return bus_clear;
}


/** @brief Function for initializing the twi_master.
 */
bool twi_master_init(void)
{
  /* To secure correct signal levels on the pins used by the TWI
       master when the system is in OFF mode, and when the TWI master is
       disabled, these pins must be configured in the GPIO peripheral.
   */
  NRF_GPIO->PIN_CNF[TWI_MASTER_CONFIG_CLOCK_PIN_NUMBER] =     \
      (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos) | \
      (GPIO_PIN_CNF_DRIVE_S0D1     << GPIO_PIN_CNF_DRIVE_Pos) | \
      (GPIO_PIN_CNF_PULL_Pullup    << GPIO_PIN_CNF_PULL_Pos)  | \
      (GPIO_PIN_CNF_INPUT_Connect  << GPIO_PIN_CNF_INPUT_Pos) | \
      (GPIO_PIN_CNF_DIR_Input      << GPIO_PIN_CNF_DIR_Pos);

  NRF_GPIO->PIN_CNF[TWI_MASTER_CONFIG_DATA_PIN_NUMBER] =      \
      (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos) | \
      (GPIO_PIN_CNF_DRIVE_S0D1     << GPIO_PIN_CNF_DRIVE_Pos) | \
      (GPIO_PIN_CNF_PULL_Pullup    << GPIO_PIN_CNF_PULL_Pos)  | \
      (GPIO_PIN_CNF_INPUT_Connect  << GPIO_PIN_CNF_INPUT_Pos) | \
      (GPIO_PIN_CNF_DIR_Input      << GPIO_PIN_CNF_DIR_Pos);

  NRF_TWI1->EVENTS_RXDREADY = 0;
  NRF_TWI1->EVENTS_TXDSENT  = 0;
  NRF_TWI1->PSELSCL         = TWI_MASTER_CONFIG_CLOCK_PIN_NUMBER;
  NRF_TWI1->PSELSDA         = TWI_MASTER_CONFIG_DATA_PIN_NUMBER;
  // NRF_TWI1->FREQUENCY    = TWI_FREQUENCY_FREQUENCY_K100 << TWI_FREQUENCY_FREQUENCY_Pos;
  NRF_TWI1->FREQUENCY       = TWI_FREQUENCY_FREQUENCY_K250 << TWI_FREQUENCY_FREQUENCY_Pos;
  NRF_PPI->CH[0].EEP        = (uint32_t)&NRF_TWI1->EVENTS_BB;
  NRF_PPI->CH[0].TEP        = (uint32_t)&NRF_TWI1->TASKS_STOP; //TASKS_SUSPEND;
  NRF_PPI->CHENCLR          = PPI_CHENCLR_CH0_Msk;
  NRF_TWI1->ENABLE          = TWI_ENABLE_ENABLE_Enabled << TWI_ENABLE_ENABLE_Pos;

  return twi_master_clear_bus();
}

/** @brief  Function for transfer by twi_master.
 */
bool twi_master_transfer(uint8_t address, uint8_t *pData, uint8_t dataLen, bool issue_stop_condition)
{
  bool transfer_succeeded = false;

  if (dataLen > 0 && twi_master_clear_bus())
  {
    NRF_TWI1->ADDRESS = (address >> 1);

    if ((address & TWI_READ_BIT))
    {
      transfer_succeeded = twi_master_read(pData, dataLen, issue_stop_condition);
    }
    else
    {
      transfer_succeeded = twi_master_write(pData, dataLen, issue_stop_condition);
    }
  }

  return transfer_succeeded;
}

/*lint --flb "Leave library region" */
