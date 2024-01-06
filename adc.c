/*
 * adc.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Abdulla Nagy
 */

#include "avr/io.h"
#include "adc.h"
#include"common_macros.h"

void ADC_init(const ADC_configType *config_ptr){

	/* ADMUX Register Bits Description:
		 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
		 * ADLAR   = 0 right adjusted
		 */


		/* ADCSRA Register Bits Description:
		 * ADEN    = 1 Enable ADC
		 * ADIE    = 0 Disable ADC Interrupt
		 * ADATE   = 0 Disable Auto Trigger
		 * ADC_Clock = F_CPU/8 = 1Mhz/8 = 125Khz*/




ADMUX =ADMUX | (config_ptr->ref_volt<<6);
ADCSRA=(1<<ADEN);
ADCSRA=(ADCSRA&0xF8)|(config_ptr->prescaler);

}

uint16 ADC_readChannel(uint8 channel_num ){

	channel_num &=0x07;     /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0;    /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX=ADMUX|channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC);    /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));/* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF);/* Clear ADIF by write '1' to it :) */
	return ADC;/* Read the digital value from the data register */



}
