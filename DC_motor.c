/*
 * DC_motor.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Abdulla Nagy
 */


#include"avr/io.h"
#include"DC_motor.h"
#include"gpio.h"
#include "pwm.h"
void DCMotor_Init(void){

		/* configure pin PD4 and PD5 as output pins */
		DDRD |= 0x30;

		/* Motor is stop at the beginning */
		PORTD &=~(1<<PD4);
		PORTD &=~(1<<PD5);

}

void DCMotor_Rotate(DCMotor_state state ,uint8 speed){



		PWM_Timer0_Init(speed);

		/* check state  */
				if(state==CW)
				{
					// Rotate the motor --> clock wise
					PORTD &= (~(1<<PD4));
					PORTD |= (1<<PD5);
				}


				else if(state==ACW)
				{
					// Rotate the motor --> anti-clock wise
					PORTD |= (1<<PD4);
					PORTD &= (~(1<<PD5));
				}


				else if(state==stop)
				{
					// Stop the motor
					PORTD &= (~(1<<PD4));
					PORTD &= (~(1<<PD5));
				}


}
