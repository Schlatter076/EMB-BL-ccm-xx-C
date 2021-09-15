/*
 * sensor.sample.type.c
 *
 *  Created on: Jun 23, 2021
 *      Author: loyer
 */
#include "../inc/sensor.sample.type.h"


SensorSample_t sensorSamples[__SAMPLE_CNTR];

void Init_sample(void)
{
	for(int i = 0; i < __SAMPLE_CNTR; i++)
	{
		DeInitSample(&sensorSamples[i]);
	}
}
/**
 * @fn    thorGetAbsVal
 * @param valA
 * @param valB
 * @return
 */
ksU32 GetAbsVal(ksS32 valA, ksS32 valB)
{
	ksS32 delta = 0x00;

	if (valA >= valB)
	{
		delta = valA - valB;
	}
	else
	{
		delta = valB - valA;
	}

	ksU32 absVal = 0x00;
	absVal = delta;

	return absVal;
}

/**
 * @fn    DeInitKineStateQ
 * @brief De-Initialize the queue used to buffer delta baseline
 */
void DeInitSample(SensorSample_t *sample)
{
	sample->qActiveUsed = 0x00;
	sample->qActiveHead = 0x00;
	sample->qActiveTail = 0x00;
	sample->KineState = 0x00;

	for (int i = 0; i < 0x05; ++i)
	{
		sample->qActiveBuf[i] = 0x00;
	}
	sample->K = 0;
	sample->Vout = 0;
	sample->filteredADC = 0;
	sample->gf = 0.0f;
	sample->gF_Decimal = 0;
	sample->gF_Int = 0;
	sample->resistorVal = 0;
	sample->resistorValPrev = 0;
	sample->admVal = 0;
}

/**
 * @fn      BufferKinestate
 * @param
 * @brief   update the base value of the sensor's admittance by weighedMAFilter
 * @note    the algorithym is executed only when the sensor is in FREE state
 */
static void BufferKinestate(SensorSample_t *sample)
{
	ksU32 deltaAbs = 0x00;
	deltaAbs = GetAbsVal(sample->resistorValPrev, sample->resistorVal);

#if   (__ANTI_NOISE_STRATEGY >= __ANTI_NOISE_LEVEL_4)
	deltaAbs >>= 0x03;
#elif (__ANTI_NOISE_STRATEGY >= __ANTI_NOISE_LEVEL_3)
  deltaAbs >>= 0x02;
#elif (__ANTI_NOISE_STRATEGY >= __ANTI_NOISE_LEVEL_2)
  deltaAbs >>= 0x01;
#endif

#if (__ANTI_NOISE_STRATEGY != __ANTI_NOISE_LEVEL_0)
  deltaAbs -= !!deltaAbs;
#else

#endif

	if (0x05 == sample->qActiveUsed)
	{ // the Q is full
		sample->KineState -= sample->qActiveBuf[sample->qActiveHead]; //minus the first value of term,Is the value 4 cycles ago
		++sample->qActiveHead;
		sample->qActiveHead %= 0x05; // pop Data from Head
		--sample->qActiveUsed;
	}

	sample->qActiveBuf[sample->qActiveTail] = deltaAbs;     // put Data at Tail
	++sample->qActiveTail;
	sample->qActiveTail %= 0x05;
	++sample->qActiveUsed;

	sample->KineState += deltaAbs; // less than 255
}
/**
 * @fn       根据斜率和电阻值计算压力
 * @slope    斜率
 * @resistor 电阻值
 */
float getForceBySlopeAndResistor(float slope, ksS32 resistor)
{
	if (resistor == 1)
		return 0.0f;
	float admittance = 100000000.0f / resistor;
	float force = admittance / slope;
	//float force = admittance;
	//float force = (admittance + 727777) / 180.04;
	if (force < 0)
		force = 0.0f;
	return force;
}
/**
 * @fn           将浮点数切分成整数部分和小数部分
 * @origin       待切分浮点数
 * @intPart      整数部分
 * @decimalPart  小数部分
 */
void splitFloatWithDot(float origin, ksS32 *intPart, ksS32 *decimalPart)
{
	*intPart = (ksS32) (origin * 10);
	*decimalPart = *intPart % 10;
	if (*decimalPart < 0)
	{
		*decimalPart *= -1;
	}
}
/**
 * @fn
 */
void caculateVoutAndResistor(SensorSample_t *sample, ksS16 adcVal, ksS32 factor, ksU16 k_times)
{
	sample->filteredADC = rcFilter(adcVal, sample->filteredADC, factor);
	sample->filteredADC = rcFilter(sample->filteredADC, sample->filteredADC,
			factor);
	sample->Vout = sample->filteredADC * __REF_VOLTAGE / 4096;

	//TODO:repair adc variable signed bug
	if (sample->Vout <= 0)
	{
		sample->Vout = 1;
	}

	sample->resistorValPrev = sample->resistorVal;
	sample->resistorVal = (__SUPPLY_VOLTAGE - sample->Vout) * __DIVIDOR_RESISTOR
			/ sample->Vout;


	sample->admVal = 100000000 / sample->resistorVal;
	if ((sample->resistorVal <= 0) || (sample->resistorVal >= 10000000))
	{
		sample->resistorVal = 1;
		sample->admVal = 0;
	}

	BufferKinestate(sample);
	sample->K = sample->KineState * k_times / sample->resistorVal;
}
