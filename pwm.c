/*
 * Timer0.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Abdulla Nagy
 */
#include "pwm.h"
#include "gpio.h"
#include "common_macros.h"
#include <avr/io.h>

/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed by updating the value
 * in The Compare Register
 */
void PWM_Timer0_Init(unsigned char duty_cycle)
{
	uint8 targetTicks = (uint8)(((uint16)(duty_cycle * 255))/100) ;

	TCNT0 = 0; //Set Timer Initial value

	OCR0  = targetTicks; // Set Compare Value

	DDRB  = DDRB | (1<<PB3); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}


