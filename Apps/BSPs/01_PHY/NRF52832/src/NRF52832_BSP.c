////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "NRF53822_BSP.c"
/// * Author  : yangken
/// * Version :
/// * Date    : 2016-6-1
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
#include	"../inc/NRF52832_BSP.h"

#if ((0) || (__MCU_TYPE == _MCU_IS_NRF52832))

#if (defined __TRACER_MODULE) && (__TRACER_MODULE == _MODULE_ON)
#include <Tracer.h>
#include "../../../../callbacks/inc/tsTracerRxCallBacks.h"

/***** Function Definitions ***************************************************/
////////////////////////////////////////////////////////////////////////////////
/// * Func_Name: bspTracerInit
/// * Paras    : none
/// * Returns  : none
/// * Brief    : initialize the tracer module
/// * Author   : kensky
/// * Build on : 2020-11-6
/// * Note     : static
////////////////////////////////////////////////////////////////////////////////
static void bspTracerInit(pISR tracerRxCB)
{
  _uuidCheck();

#if 0
  unsigned char i;
//  for (i=0; i<__TRACER_CNT; ++i) { tracer_init(i); }
#else

#if (__USART_TRACER == _TRACER_ON)
  tracerInit(&uTracer[__UTRACER_IDX_1]);
  tracerConsoleInit(&uTracer[__UTRACER_IDX_1], tracerRxCB);
#elif (__SPI_TRACER == _TRACER_ON) && (defined __RULE_USE_HCI_INTERFACE)
  tracerInit(&sTracer[0]);

  while(0)
  {
    __WFI();
    asm("nop");
    // ksMcuStop(); // 3.2mA, why??
  }

  tracerConsoleInit(&sTracer[0], __sTracer_RCVD_IRQ_ROUTINE);

#if (__MCU_TYPE == _MCU_IS_NRF51822)
  NRF_SPIS1->TASKS_RELEASE  = 0x01;
  NRF_SPIS1->INTENSET      |= 1<<0x01; // enable SPIS1 END irq
#endif // (__MCU_TYPE == _MCU_IS_NRF51822)

#endif
#endif
}

#endif // (__TRACER_MODULE == _MODULE_ON)

#if (defined __IR_MODULE) && (__IR_MODULE == _MODULE_ON)
#include <irStudyDriver.h>
#endif // (__IR_MODULE == _MODULE_ON)

#if (defined __sFLASH_MODULE) && (__sFLASH_MODULE == _MODULE_ON)
#include <sFlash_Driver.h>

/*******************************************************************************
*                          BSP_sFlash_Flash_Init()
* Description : Initializes sFlash_Flash
* Argument(s) : none.
* Return(s)   : none.
* Caller(s)   : BSP_Init().
* Note(s)     : none.
*******************************************************************************/
void BSP_sFlash_Init()
{
  __uTRACER_PRINTF(_TRACER_0, "Initializing the serial flash.\n\r", 0);

  for (int sFLASH_index = 0; sFLASH_index < __sFLASH_CNT; ++sFLASH_index)
  {
#if (_sFLASH_INTERFACE ==_HSPI__FLASH)
    {
      while(_sFLASH_SPI_SUCCESS != sFlash_Init(&(sFLASH_Periph[sFLASH_index]), _sFLASH_Dis));
    }
#else
    {
      while(_sFLASH_SPI_SUCCESS != sFlash_Init(&(sFLASH_Periph[sFLASH_index]), _sFLASH_En));
    }
#endif

#if ((defined __RELEASE_MODE)         && \
     (__RELEASE_MODE == _MODULE_OFF)  && \
     0)
    volatile uint32_t Data_tmp;

    Data_tmp = sFlash_SPI_U32_RD(&sFLASH_Periph[sFLASH_index], 0x00);
    Data_tmp = sFlash_SPI_U16_RD(&sFLASH_Periph[sFLASH_index], 0x00);
    Data_tmp = sFlash_SPI_U16_RD(&sFLASH_Periph[sFLASH_index], 0x02);
    Data_tmp = sFlash_SPI_U08_RD(&sFLASH_Periph[sFLASH_index], 0x00);
    Data_tmp = sFlash_SPI_U08_RD(&sFLASH_Periph[sFLASH_index], 0x01);
    Data_tmp = sFlash_SPI_U08_RD(&sFLASH_Periph[sFLASH_index], 0x02);
    Data_tmp = sFlash_SPI_U08_RD(&sFLASH_Periph[sFLASH_index], 0x03);

    while(_sFLASH_SPI_SUCCESS != sFlash_SPI_Erase((&sFLASH_Periph[sFLASH_index]), 0, __sFLASH_SECTOR_ERASE));

    Data_tmp = sFlash_SPI_U32_RD(&sFLASH_Periph[sFLASH_index], 0x00);
    Data_tmp = sFlash_SPI_U16_RD(&sFLASH_Periph[sFLASH_index], 0x00);
    Data_tmp = sFlash_SPI_U16_RD(&sFLASH_Periph[sFLASH_index], 0x02);
    Data_tmp = sFlash_SPI_U08_RD(&sFLASH_Periph[sFLASH_index], 0x00);
    Data_tmp = sFlash_SPI_U08_RD(&sFLASH_Periph[sFLASH_index], 0x01);
    Data_tmp = sFlash_SPI_U08_RD(&sFLASH_Periph[sFLASH_index], 0x02);
    Data_tmp = sFlash_SPI_U08_RD(&sFLASH_Periph[sFLASH_index], 0x03);

     sFlash_SPI_U32_WR(&sFLASH_Periph[sFLASH_index], 0x01234567, 0x00);
#endif
  }

#if 0
  sFlash_Para_Erase(0x00, __sFLASH_SECTOR_ERASE);

  sFlash_ParaWR_16(0x0123,0x00);
  sFlash_ParaWR_16(0x4567,0x02);
  sFlash_ParaWR_16(0x89ab,0x04);
  sFlash_ParaWR_08(0x04,0x06);
  sFlash_ParaWR_16(0x1234,0x07);
  sFlash_ParaWR_16(0x4321,0x09);
  Data_tmp = sFlash_ParaRD_08(0x00);
  Data_tmp = sFlash_ParaRD_16(0x00);
  Data_tmp = sFlash_ParaRD_16(0x06);
  Data_tmp = sFlash_ParaRD_08(0x04);
  Data_tmp = sFlash_ParaRD_08(0x05);
  Data_tmp = sFlash_ParaRD_16(0x04);
  Data_tmp = sFlash_ParaRD_08(0x07);
  Data_tmp = sFlash_ParaRD_08(0x08);
  Data_tmp = sFlash_ParaRD_16(0x07);

  sFlash_ParaWR_16(0x1234,0x50);
  Data_tmp = sFlash_ParaRD_16(0x50);

  Data_tmp = sFlash_ParaRD_32(0X00);
  Data_tmp = sFlash_ParaRD_32(0X10);
  sFlash_ParaWR_32(0x11111111, 0x12);
  sFlash_ParaWR_32(0x22222222, 0x22);
  sFlash_ParaWR_32(0x76543210, 0x32);

  Data_tmp = sFlash_ParaRD_32(0X12);
  Data_tmp = sFlash_ParaRD_32(0X22);
  Data_tmp = sFlash_ParaRD_32(0X32);

//  Toggle_sFlash_QUAD_FSTRD_Mode( _sFLASH_CONTINUOUS_FSTRD); // todo bbfb
#endif

#if 0
  Data_tmp = 0;

  Data_tmp = sFlash_ParaRD_16(0);
  Data_tmp = sFlash_ParaRD_16(65623);
  Data_tmp = sFlash_ParaRD_08(65625);
  Data_tmp = sFlash_ParaRD_32(65626);
  Data_tmp = sFlash_ParaRD_32(65640);
  Data_tmp = sFlash_ParaRD_16(87043);
  Data_tmp = sFlash_ParaRD_32(237568);
  Data_tmp = sFlash_ParaRD_32(237596);


#endif

#if 0
  uint8_t   arrayBuf08[100];
  uint16_t  arrayBuf16[100];
  uint32_t  arrayBuf32[100];
//  for(uint8_t i=0; i<__sFLASH_CNT; ++i)
//  {
//    sFlash_SPI_Erase(&sFLASH_Periph[i],  8, __sFLASH_SECTOR_ERASE);
//  }
  sFLASH_Array_FSTRD(65536, arrayBuf08, 20, _RD_DATA_08);
//  sFLASH_Array_FSTRD(65536, arrayBuf16, 20, _RD_DATA_16); // something wrong!!
//  sFLASH_Array_FSTRD(65536, arrayBuf32, 20, _RD_DATA_32);

#endif // 0
#if (_LEARN_IR_DATA == _WORKING_STATUS)
  sFlash_U32_Read(0, Data_tmp, 0x00);
  sFlash_U32_Read(0, Data_tmp, 0x05);
  sFlash_U32_Write(0, 0x1234aaaa, 0x05);
  sFlash_U32_Read(0, Data_tmp, 0x05);
  sFlash_Erase_Chip(0);
  sFlash_U32_Read(0, Data_tmp, 0x05);
#endif
  __uTRACER_PRINTF(_TRACER_0, "Serial flash initialized.\n\r", 0);
}

#endif // (__sFLASH_MODULE == _MODULE_ON)

#if (defined __uCOS_MODULE) && (__uCOS_MODULE == _MODULE_ON)

#endif // (__uCOS_MODULE == _MODULE_ON)

#if (defined __RTT_MODULE) && (__RTT_MODULE == _MODULE_ON)

#endif

#if (defined __SMPL120_MODULE) && (__SMPL120_MODULE == _MODULE_ON)

#endif // (__SMPL120_MODULE == _MODULE_ON)

#if (defined __KEYPADS_MODULE) && (__KEYPADS_MODULE == _MODULE_ON)
#include <Key_Driver.h>
#endif // (__KEYPADS_MODULE == _MODULE_ON)

#if (defined __LEDs_MODULE) && (__LEDs_MODULE == _MODULE_ON)
#include <LEDs_Driver.h>
#endif // (__LEDs_MODULE == _MODULE_ON)

#if (defined __LWIP_MODULE) && (__LWIP_MODULE == _MODULE_ON)

#endif

#if (defined __SMS_MODULE) && (__SMS_MODULE == _MODULE_ON)
#include    <SMS_Module.h>
#endif

/***** LOCAL DEFINES **********************************************************/

/***** EXTERNAL GLOBAL VARIABLES **********************************************/
////////////////////////////////////////////////////////////////////////////////
/// @fn     : nrf_sTracerSenseIsr
/// @param  : none
/// @return : none
/// @brief  : this routine is called when sTracer's CS pin is pulled low. to
///           save the power, we will disable the SPI usually, only when CSn is
///           pulled low, we will re-enable the SPI functionality. in this
///           routine, we shall pull up a sychronizing pin to tell the peer that
///           the SPI is ready
/// @author : Kensky
/// @date   : 2016-3-6
/// @pre    : add precondition here if needed.
/// @note   : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
void nrf_sTracerSenseIsr ()
{
#if 1
  NRF_GPIOTE->EVENTS_PORT = 0x00;
#else
  if (NRF_GPIOTE->EVENTS_PORT)
  {
    NRF_GPIOTE->EVENTS_PORT = 0x00;
  }
  else
  {
    asm("nop");
  }
#endif
}

/*******************************************************************************
*                                  STM32_BSPInit()
* Description : Initialize the STM32 board Peripherals
* Argument(s) : none.
* Return(s)   : none.
* Caller(s)   : This the main standard entry point.
* Note(s)     : none.
*******************************************************************************/
void mcuBSPInit(pISR tracerRxCB)
{
  SystemInit();

  nrf_delay_ms(300);

/**** project initialization **************************************************/
  projInit();

/**** Low Power configurations ************************************************/
  ksMcuLpwrInitGpio();

#if 1
   SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

   // NRF_POWER->DCDCEN       = 0x00; // disable DC/DC converter (by default)
   NRF_POWER->DCDCEN          = 0x01; // enable DC/DC converter (not by default)
#if 0
   NRF_POWER->TASKS_CONSTLAT  = 0x01; // choose between TASKS_CONSTLAT and TASKS_LOWPWR
#else
   NRF_POWER->TASKS_LOWPWR    = 0x01;
#endif
#endif

#if 0
   // PWR->CR     |= 0X03<<11;    // VOS 11 range 3
   // PWR->CR     |= 0X01<<9;     // ULP 1 Vref int off
   // PWR->CR     |= 0X01<<10;    // FWU 1 Vref int STARTUP is ignored
   // PWR->CR     &= ~(0X01<<4);  // PVD 0 Disabled
   FLASH->ACR  |= (0X01<<3);   // SLEEP_PD FLASH in PWRDN mode when sleep

   if((FLASH_OB_GetBOR() & 0x0F) != OB_BOR_OFF)
   {
     FLASH_OB_Unlock();
     /* Clears the FLASH pending flags */
     FLASH_ClearFlag(FLASH_FLAG_EOP     |
                     FLASH_FLAG_WRPERR  |
                     FLASH_FLAG_PGAERR  |
                     FLASH_FLAG_SIZERR  |
                     FLASH_FLAG_OPTVERR);
     FLASH_OB_BORConfig(OB_BOR_OFF);
     FLASH_OB_Lock();
     FLASH_OB_Launch();
   }

#endif

   ksNvicVectblConfig(_NVIC_VECT_TAB_FLASH);
   ksNvicPrioGrpCfg(__CORTEX_IRQ_PrioGRP);

#if (defined __KS_PERIPH_MODULE) && (__KS_PERIPH_MODULE == _MODULE_ON)

// TODO : not tested
#if ((1) && (defined __RELEASE_MODE) && (__RELEASE_MODE == __MODULE_OFF))
  NRF_MPU->DISABLEINDEBUG = 0x01;
  NRF_UICR->RBPCONF       = 0xFFFF;
#else
  NRF_UICR->RBPCONF       = 0x00;
  NRF_MPU->DISABLEINDEBUG = 0x00; // enable protection mechanism for NVM during debug mode
#endif // (__REALSE_MODE == __MODULE_OFF)

  ksIsrInit();

  __MCU_STOP_TEST(0);

#if 	(__MCU_TYPE == _MCU_IS_STM32f10x)
  stm32f10x_SYSCLCK_Configurate(__MCU_CLKSRC);   // 2.30 MA for 8Mhz
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE );
  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
  //  GPIO_PinRemapConfig(GPIO_Remap_PD01, ENABLE); // We will use HSE, the PD01 should not be remapped
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)

#if (__RADIO_MODULE == _MODULE_ON) && (__SMPL120_MODULE == __MODULE_OFF)
#if ((0)  ||                             \
     ((__RELEASE_MODE   == _MODULE_ON) && \
      (__RULE_DEV_TYPE == _RULE_WOR_DEV)))  // low power
  if (rfChipPeriph.pwrIO.PORTn != io_Port_No)
  {// for STM32L default sysclk, j = 6 means 3 seconds
    volatile unsigned int i, j;
    for(i=0, j=0; j<=__RULE_STARTUP_DELAY; ++i)
    {
      if (i >= 0xffff)
      {
        i = 0;
        ++j;
      }
    }
  }
#endif
#endif // (__RADIO_MODULE == _MODULE_ON) && (__SMPL120_MODULE == __MODULE_OFF)

  stm32l1xRCCSysClkConfig(__MCU_CLKSRC);  // 2.30 MA for 8Mhz
  RCC_ClocksTypeDef MCU_Clk;
  RCC_GetClocksFreq(&MCU_Clk);
  gv_mcuFreq = MCU_Clk.HCLK_Frequency;    // can not be accurate, just estimated value

  if (gv_mcuFreq <= (rvU64)4200000)
  {
    PWR_VoltageScalingConfig(PWR_VoltageScaling_Range3);
  }
  else if (gv_mcuFreq <= (rvU64)1600000)
  {
    PWR_VoltageScalingConfig(PWR_VoltageScaling_Range2);
  }
  else
  {
    PWR_VoltageScalingConfig(PWR_VoltageScaling_Range1);
  }

  /*
   * ?.?? mA for 8MHz HSE and 8MHz freq,
   * not tested;
   * 1.68 mA for 8MHz HSE and 4MHz freq,
   * the circuit can provide such a power;
   * 1.22 mA for 8MHz HSE and 2MHz freq,
   * the circuit can provide such a power;
   */
#elif (__MCU_TYPE == _MCU_IS_STM32l0xx)
  stm32l0xRCCSysClkConfig(__MCU_CLKSRC);  // 2.30 MA for 8Mhz

  // __HAL_FLASH_POWER_DOWN_ENABLE(); // 230 uA

  RCC_ClocksTypeDef MCU_Clk;
  RCC_GetClocksFreq(&MCU_Clk);
  gv_mcuFreq = MCU_Clk.HCLK_Frequency;    // can not be accurate, just estimated value

  if (gv_mcuFreq <= (rvU64)4200000)
  {
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
    RCC->CFGR &= ~(1<<15); // choose MSI as wake-up from stop mode
  }
  else if (gv_mcuFreq < (rvU64)16000000)
  {
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  }
  else
  {
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
    RCC->CFGR |= 1<<15; // choose HSI16 as wake-up from stop mode
  }

#elif (__MCU_TYPE == _MCU_IS_NRF51822)
  nrf_drv_clock_init();

#if (__RULE_NWK_WAKEUP > 0x00)
  // to save power, the hfclk will be turned on in applications
  gv_mcuFreq = 16000000;
  nrf_lfclk_start();
#if (0) // for test
  while(!nrf_drv_clock_lfclk_is_running());
  nrf_clock_event_clear(NRF_CLOCK_EVENT_LFCLKSTARTED);
  __KS_RUNTIME_ASSERT(NRF_CLOCK->LFCLKSRC == CLOCK_LFCLKSRC_SRC_Xtal, __ASSERT_VALUE);
#endif
#else
  nrf_hfclk_start();
  while(!nrf_drv_clock_hfclk_is_running());
  nrf_clock_event_clear(NRF_CLOCK_EVENT_HFCLKSTARTED);

  gv_mcuFreq = 16000000 << (NRF_CLOCK_XTALFREQ_32MHz == nrf_clock_xtalfreq_get());
  __KS_RUNTIME_ASSERT(gv_mcuFreq == __MCU_FREQ, __ASSERT_VALUE);

  nrf_hfclk_stop();
#endif // __RULE_NWK_WAKEUP

#elif (__MCU_TYPE == _MCU_IS_NRF52832)
  nrf_drv_clock_init();

#if (__RULE_NWK_WAKEUP > 0x00)
  // to save power, the hfclk will be turned on in applications
  gv_mcuFreq = 16000000;
  nrf_lfclk_start();

#if (0) // for test
  while(!nrf_drv_clock_lfclk_is_running());
  nrf_clock_event_clear(NRF_CLOCK_EVENT_LFCLKSTARTED);
  __KS_RUNTIME_ASSERT(NRF_CLOCK->LFCLKSRC == CLOCK_LFCLKSRC_SRC_Xtal, __ASSERT_VALUE);
#endif
#else
  nrfx_clock_hfclk_start();
  while(!nrf_drv_clock_hfclk_is_running());
  nrf_clock_event_clear(NRF_CLOCK_EVENT_HFCLKSTARTED);

  ksSetSysFreq(64000000ULL);
#endif // __RULE_NWK_WAKEUP

  nrfx_clock_lfclk_start();

#endif  // (__MCU_TYPE == _MCU_IS_STM32l0xx))

  __MCU_STOP_TEST(0);

/**** KeyPad Module ***********************************************************/
#if (defined __KEYPADS_MODULE) && (__KEYPADS_MODULE == _MODULE_ON)
  KeyPads_Init();
#endif // (__KEYPADS_MODULE == _MODULE_ON)

/**** LEDs Module *************************************************************/
#if (defined __LEDs_MODULE) && (__LEDs_MODULE == _MODULE_ON)
#if (__LEDS_CNT >= 1)
  LEDs_Init();
#endif // (__LEDS_CNT >= 1)
#endif // (__LEDs_MODULE == _MODULE_ON)

/**** __RADIO_MODULE *********************************************************/
#if (1) && (__RADIO_MODULE == _MODULE_ON) && (__SMPL120_MODULE == __MODULE_OFF)

/***** if smpl is on, the init should be done in smpl module ******************/
  if (_RADIO_SUCCESSFUL != radioInit((rfPeriph_t*)&radioPeriph, __RADIO_TRx_IRQ_ROUTINE))
  {
    __KS_FORCE_ASSERT(__ASSERT_NOT_HAPPEN);
  }

  __MCU_STOP_TEST(0);

#endif // (__RADIO_MODULE == _MODULE_ON)

#endif // (__KS_PERIPH_MODULE == _MODULE_ON)

/**** Tracer Module ***********************************************************/
#if (defined __TRACER_MODULE) && (__TRACER_MODULE == _MODULE_ON)
  bspTracerInit(tracerRxCB);

  __MCU_STOP_TEST(0);

#ifdef __RULE_USE_HCI_INTERFACE
  // ksGPIO_t sTracerIrqPin   = {};

  volatile ksU32 pinCfg = GPIOA->PIN_CNF[__sTRACER_CS_PIN_N_1];

  pinCfg |= 0x03<<16;
  pinCfg &=~0x02;
  GPIOA->PIN_CNF[__sTRACER_CS_PIN_N_1] = pinCfg;

  // ksGpioInit(&sTracerIrqPin);

/**** configure the GPIOTE of master SPI sense ********************************/
  ksISR_t lv_gpioeIrq = {.id = GPIOTE_IRQn, .handler = nrf_sTracerSenseIsr, };
  ksIsrIntVectSet(&lv_gpioeIrq);

  NRF52832_NVIC_Init(GPIOTE_IRQn, 0x00, 0x00, _NVIC_EN); // todo : priority
#if (__MCU_TYPE == _MCU_IS_NRF51822)
  NRF_GPIOTE->POWER       = 0x01;
#endif
  NRF_GPIOTE->INTENSET   |= (ksU32)(0x01<<31); // enable PORT EVENT irq
#endif

  __MCU_STOP_TEST(0);

#if (__uTRACER_CNT >= 0x01)
  NRF_UART0->TASKS_STARTTX = 0x01;
  NRF_UART0->TASKS_STARTRX = 0x01;

#ifndef   __IR_HID_INFO_STATUS
#define __IR_HID_INFO_STATUS          (true)
#endif

  __uTRACER_PRINTF(__TRACER_OUT, __IR_HID_INFO_STATUS, "\r\n");
  __uTRACER_PRINTF(__TRACER_OUT, __IR_HID_INFO_STATUS, "the MCU sysClk is %d Hz \r\n", ksGetSysFreq());

  // to save the power (MCU sleep will not turn off the peripherals)
  // ksUsartSwitch((uTracer[__UTRACER_IDX_1].pUsart), disableUsart);
#else

#endif
#endif // (defined __TRACER_MODULE) && (__TRACER_MODULE == _MODULE_ON)

/**** Delay Module ************************************************************/
#if (defined __DELAY_MODULE) && (__DELAY_MODULE == _MODULE_ON)
  _DELAY_INIT();

#endif // (__DELAY_MODULE == _MODULE_ON)

#if (defined __SMS_MODULE) && (__SMS_MODULE == _MODULE_ON)

  ykSMS_Init();
  ykSMS_PWR_Toggle(sms_on);
  __SMS_SEND_CMD(__SMS_ECHO);
  _DELAY_MS(1000);
  __SMS_SEND_CMD(__SMS_INIT);
  _DELAY_MS(1000);
  ykSMS_PWR_Toggle(sms_off);

#endif

/**** sFlash Module ***********************************************************/
#if (defined __sFLASH_MODULE) && (__sFLASH_MODULE == _MODULE_ON)

#if (_BOARD_STATUS == _BOARD_WITH_W25Q)

    BSP_sFlash_Init();
#endif

#endif // (__sFLASH_MODULE == _MODULE_ON)

/**** IR Module ***************************************************************/
#if (defined __IR_MODULE) && (__IR_MODULE == _MODULE_ON)

irZIP.pzTbl = (uint32_t*)((uint32_t)__P_IrLevel + __Capture_Len*2 + 4);
irZIP.pzBuf = (uint8_t*)((uint32_t)__P_IrLevel + __Capture_Len*2 + 4 + 20*4);

#if (defined __IR_TRASMIT_STATUS)         && \
    (_IR_OUT  ==  __IR_TRASMIT_STATUS)    || \
    (_IR_In_N_Out  ==  __IR_TRASMIT_STATUS)
    irInitTransmitter();
#endif

#if (defined __IR_TRASMIT_STATUS)         && \
    (_IR_IN  ==  __IR_TRASMIT_STATUS)    || \
    (_IR_In_N_Out  ==  __IR_TRASMIT_STATUS)
    irCaptureInit();
#endif

#endif // (defined __IR_MODULE) && (__IR_MODULE == _MODULE_ON)

/**** uCOS Module***********************************************/
#if (defined __uCOS_MODULE) && (__uCOS_MODULE == _MODULE_ON)

#endif // (__uCOS_MODULE == _MODULE_ON)

/**** SMPL120 Module **********************************************************/
#if (defined __SMPL120_MODULE) && (__SMPL120_MODULE == _MODULE_ON)
//    gdl_SMPL_Init();
#endif // (__SMPL120_MODULE == _MODULE_ON)

/**** LWIP Module **********************************************************/
#if (defined __LWIP_MODULE) && (__LWIP_MODULE == _MODULE_ON)

#endif // (__LWIP_MODULE == _MODULE_ON)

/**** E2ROM Module ************************************************************/
#if (defined __E2ROM_MODULE) && (_MODULE_ON == __E2ROM_MODULE)

    for (unsigned char i=0; i<__E2ROM_CNT; ++i)
    {
      E2ROM_Init(&e2rom_periph[i]);
      __E2ROM_WP_DIS(&e2rom_periph[i]);
#if 0
      unsigned char     I2C_byte[10]  = {0,1,2,3,4,5,6,7,8,9};
      unsigned char     I2C2_byte[10] = {0xff, 0xff, 0xff, 0xff, 0xff,
                                         0xff, 0xff, 0xff, 0xff, 0xff};
      unsigned char     tmp;
      unsigned short    tmp16;

      E2ROM_WR_nU08(&e2rom_periph[i], 256+0x00, I2C_byte, 10);
      E2ROM_WR_U16(&e2rom_periph[i], 256+0x00, 0X1234);
      E2ROM_RD_U16(&e2rom_periph[i], 256+0x00, &tmp16);
      E2ROM_RD_U08(&e2rom_periph[i], 256+0x02, &tmp);
      E2ROM_RD_U08(&e2rom_periph[i], 256+0x03, &tmp);
      E2ROM_RD_U08(&e2rom_periph[i], 256+0x04, &tmp);
      E2ROM_RD_U08(&e2rom_periph[i], 256+0x05, &tmp);
      E2ROM_WR_U08(&e2rom_periph[i], 256+0x01, 0X12);
      E2ROM_RD_U08(&e2rom_periph[i], 256+0x01, &tmp);

      E2ROM_WR_nU08(&e2rom_periph[i], 256+0x00, I2C2_byte, 10);
      E2ROM_RD_U08(&e2rom_periph[i], 256+0x00, &tmp);
      E2ROM_RD_U08(&e2rom_periph[i], 256+0x01, &tmp);
      E2ROM_RD_U08(&e2rom_periph[i], 256+0x02, &tmp);
      E2ROM_RD_U08(&e2rom_periph[i], 256+0x03, &tmp);
      E2ROM_WR_U16(&e2rom_periph[i], 256+0x00, 0X1234);
      E2ROM_RD_U08(&e2rom_periph[i], 256+0x00, &tmp);
      E2ROM_RD_U08(&e2rom_periph[i], 256+0x01, &tmp);
#endif //0
      __E2ROM_WP_EN(&e2rom_periph[i]);
    }
    __uTRACER_PRINTF(__TRACER_CONSOLE, "AT24C0x inited!\r\n");

#endif // (defined __KS_PERIPH_MODULE) && (_MODULE_ON == __KS_PERIPH_MODULE)

/**** RT Thread Module ********************************************************/
#if (defined __RTT_MODULE) && (__RTT_MODULE == _MODULE_ON)
    RCC_ClocksTypeDef RCC_Clocks;

    RCC_GetClocksFreq(&RCC_Clocks);
    SysTick_Config( RCC_Clocks.HCLK_Frequency / RT_TICK_PER_SECOND );
#endif

#if (__MEMS_MODULE == _MODULE_ON)
    LIS3DH_Init(&gvMemsPeriph, __MEMS_IRQ_ROUTINE);
#endif // (__MEMS_MODULE == _MODULE_ON)

}

#endif // (__MCU_TYPE == _MCU_IS_NRF52832)

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
//}
#endif // __cplusplus
