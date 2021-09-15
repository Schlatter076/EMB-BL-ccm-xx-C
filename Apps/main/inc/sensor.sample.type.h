/*
 * sensor.sample.type.h
 *
 *  Created on: Jun 23, 2021
 *      Author: loyer
 */

#ifndef APPS_MAIN_INC_SENSOR_SAMPLE_TYPE_H_
#define APPS_MAIN_INC_SENSOR_SAMPLE_TYPE_H_

/***** Include ****************************************************************/
#include  "projCfg.h"
#include  <ksPeriph.h>
#include  <Tracer.h>

/***** Defines ****************************************************************/
#define   __DIVIDOR_RESISTOR    32940 // ohm
#define   __SUPPLY_VOLTAGE      3286  // mv
#define   __REF_VOLTAGE         /* 3600 // */ 3560  // mv
#define   __SAMPLE_CNTR         2
/******************************************************************************/

/***** Data type **************************************************************/
typedef struct
{
	ksS32   filteredADC;
	ksS32   Vout;
	ksS32   resistorVal;
	ksS32   resistorValPrev;
	ksU32   admVal;
	ksU32   KineState;
	ksU32   qActiveHead;
	ksU32   qActiveTail;
	ksU32   qActiveUsed;
	ksU32   qActiveBuf[0x05];
	ksU16   K;
	float   gf;
	ksS32   gF_Int;
	ksS32   gF_Decimal;
}SensorSample_t;

extern SensorSample_t sensorSamples[__SAMPLE_CNTR];

/******************************************************************************/
ksU32 GetAbsVal(ksS32 valA, ksS32 valB);
void DeInitSample(SensorSample_t *sample);
float getForceBySlopeAndResistor(float slope, ksS32 resistor);
void splitFloatWithDot(float origin, ksS32 *intPart, ksS32 *decimalPart);
void caculateVoutAndResistor(SensorSample_t *sample, ksS16 adcVal, ksS32 factor, ksU16 k_times);
void Init_sample(void);
ksU32 GetMedianNum(ksU32 *bArray, int iFilterLen);
ksU32 GetWidthNum(ksU32 newVal, ksU32 *oldVal, ksU08 width);

#endif /* APPS_MAIN_INC_SENSOR_SAMPLE_TYPE_H_ */
