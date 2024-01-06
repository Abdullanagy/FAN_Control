/*
 * adc.h
 *
 *  Created on: Jan 6, 2024
 *      Author: Abdulla Nagy
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"

#define ADC_MAXIMUM_VALUE 1024
#define ADC_REF_VOLT_VALUE 2.56

typedef enum {
	AREF_internal_VREF_turnedoff,AVCC_With_external_capacitor_atAREF,Reserved,Internal_2_56v
}ADC_ReferenceVoltage;
typedef enum {
	F_CPU_20,F_CPU_21,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

typedef struct {
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_configType;

void ADC_init(const ADC_configType *config_ptr);
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
