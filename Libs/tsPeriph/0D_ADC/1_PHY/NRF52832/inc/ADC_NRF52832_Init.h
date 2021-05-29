/*******************************************************************************
  * File    :  ADC_NRF52832_Init.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-10-9
  * Brief   :  
*******************************************************************************/
#ifndef __ADC_NRF52832_INIT_H_KENSKY_2020_10_9
#define __ADC_NRF52832_INIT_H_KENSKY_2020_10_9

/**** Includes ****************************************************************/
#include "../../../4_CFG/ADC_cfg.h"

#if (defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_NRF52832)

#include    "../../../../04_GPIO/GPIO_Driver.h"

#define __NRF52832_RDY_INDEX          (0x00)
#define __NRF52832_DONE_INDEX         (0x01)
#define __NRF52832_CAL_INDEX          (0x02)
#define __NRF52832_BEGIN_INDEX        (0x03)
#define __NRF52832_STOP_INDEX         (0x04)
#define __NRF52832_BUF_INDEX          (0x05)

#define __NRF52832_BEGIN_FLAG         (0x0100u)
#define __NRF52832_BUF_FLAG           (0x0104u)
#define __NRF52832_DONE_FLAG          (0x0108u)
#define __NRF52832_RDY_FLAG           (0x010Cu)
#define __NRF52832_CAL_FLAG           (0x0110u)
#define __NRF52832_STOP_FLAG          (0x0114u)

#define __NRF52832_ADC_CHN_NBR        (0x08)

/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: nrf52832AdcGet_CHn
*  Paras    : ADC
*  Returns  : ADC1..3 or NULL
*  Brief    : According to ADC, find which ADC is about to be used!
*  Build on :
*  Note     :
*******************************************************************************/
void  nrf52832AdcGetChn   (ksADC_t *pADC);

/*******************************************************************************
*  Func_Name: nrf52832AdcDeInit
*  Paras    : SPI
*  Returns  : _KS_SPI_SUCCESSFUL or _SPI_MISMATCH
*  Brief    : DeInitialize the SPI based on its bus. only effective to hSPI.
*  Build on :
*  Note     :
*******************************************************************************/
void  nrf52832AdcDeInit   (ksADC_t *pADC);

/*******************************************************************************
*  Func_Name: nrf52832AdcInit
*  Paras    : ADC       :
*             ADC_IN_IO :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     : this routine is just for test!
*******************************************************************************/
ksRet_t  nrf52832AdcInit  (ksADC_t *pADC);

/*******************************************************************************
*  Func_Name: nrf52832_SPI_CLK
*  Paras    : SPI   :
*             state :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
void  nrf52832AdcCLK      (ksADC_t *pADC, ksADC_State_e newState);

/*******************************************************************************
*  Func_Name: nrf52832Adcswitch
*  Paras    : SPI   :
*             state :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
void  nrf52832AdcSwitch   (ksADC_t *pADC, ksADC_State_e newState);

/*******************************************************************************
*  Func_Name: nrf52832Adcread
*  Paras    : ADC       :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     : this routine is just for test!
*******************************************************************************/
int   nrf52832AdcRead     (ksADC_t *pADC);

/**
 * nrf52832AdcCalibrate
 * @param pADC
 */
void  nrf52832AdcCalibrate(ksADC_t *pADC);

/**
 * nrf52832AdcBufferConfig
 * @param pADC
 * @param bufAddr
 * @param bufSize
 */
void nrf52832AdcBufferConfig (ksADC_t *pADC, ksAddr_t bufAddr, ksU32 bufSize);

#endif // (defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_NRF52832)

#endif // __ADC_NRF52832_INIT_H_KENSKY_2020_10_9
