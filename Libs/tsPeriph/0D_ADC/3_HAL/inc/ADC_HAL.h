/*******************************************************************************
  * File    :  ADC_HAL.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-10-9
  * Brief   :  
*******************************************************************************/
#ifndef __ADC_HAL_H_KENSKY_2012_10_9
#define __ADC_HAL_H_KENSKY_2012_10_9

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/ADC_DDL.h"

/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: ykADC_Init
*  Paras    : ADC       :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     : this routine is just for test!
*******************************************************************************/
void ksAdcInit          (ksADC_t *pADC);

/*******************************************************************************
*  Func_Name: ykADC_read
*  Paras    : ADC       :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     : this routine is just for test!
*******************************************************************************/
int ksAdcRead           (ksADC_t *pADC);

/*******************************************************************************
*  Func_Name: ykADC_switch
*  Paras    : ADC   :
*             state :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
void ksAdcSwitch        (ksADC_t *pADC, ksADC_State_e state);

ksIsrChn ksAdcGetIRQn   (ksADC_t *pADC, ksU08 irqSrc);

/**
 * ksAdcBufferConfig
 * @param pADC
 * @param bufAddr
 * @param bufSize
 */
void ksAdcBufferConfig  (ksADC_t *pADC, ksAddr_t bufAddr, ksU32 bufSize);

/**
 * ksAdcCalibrate
 * @param pADC
 */
void ksAdcCalibrate     (ksADC_t *pADC);

/**
 * ksAdcStart
 * @param pADC
 */
void ksAdcStart         (ksADC_t *pADC);

/**
 * ksAdcSample
 * @param pADC
 */
void ksAdcSample        (ksADC_t *pADC);

/**
 * ksAdcStop
 * @param pADC
 */
void ksAdcStop          (ksADC_t *pADC);

#endif // __ADC_HAL_H_KENSKY_2012_10_9
