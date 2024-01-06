/*
 * APP.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Abdulla Nagy
 */

#include "adc.h"
#include "lcd.h"
#include"lm35_sensor.h"
#include"DC_motor.h"


int main (void){

	uint8 temp;

	ADC_configType ADC_configurations = {Internal_2_56v,F_CPU_8}; //Select ADC with internal reference voltage 2.56 volt and prescaler F_CPU/8
	ADC_init(&ADC_configurations); //send the address of the ADC configurations to the ADC_Init Function
	DCMotor_Init(); //DC_Motor Initialization
	LCD_init(); // LCD initialization
	LCD_displayString("FAN IS     ");
	LCD_moveCursor(1,0);
	LCD_displayString("TEMP =    C");


	while(1){

		temp = LM35_getTemperature();//Get the Temperature Value from the sensor

		if(temp>=100){

			LCD_moveCursor(1,7);
		    LCD_intgerToString(temp);//Display The Value of Temperature Sensor

		             }
	    else{

	    	LCD_moveCursor(1,7);
		    LCD_intgerToString(temp);//Display The Value of Temperature Sensor
		    LCD_displayCharacter(' ');

	        }


if (temp<30){

	        LCD_moveCursor(0,8);
	        LCD_displayString("OFF"); //Display The DC_Motor State
	        DCMotor_Rotate(CW,0); //TurnOFF DC_Motor

           }


else if((temp>=30)&&(temp<60)){

		    LCD_moveCursor(0,8);
		    LCD_displayString("ON 25%"); //Display The DC_Motor State
		    LCD_displayCharacter(' ');
		    DCMotor_Rotate(CW,25); //The DC_Motor rotate clockwise with 25% of its Maximuum Speed

                              }
else if((temp>=60)&&(temp<90)){

	        LCD_moveCursor(0,8);
			LCD_displayString("ON 50%");//Display The DC_Motor State
			LCD_displayCharacter(' ');
			DCMotor_Rotate(CW,50); //The DC_Motor rotate clockwise with 50% of its Maximuum Speed

                               }
else if((temp>=90)&&(temp<120)){

	        LCD_moveCursor(0,8);
			LCD_displayString("ON 75%");//Display The DC_Motor State
			LCD_displayCharacter(' ');
			DCMotor_Rotate(CW,75); //The DC_Motor rotate clockwise with 75% of its Maximuum Speed

                               }
else if((temp>=120)){

	        LCD_moveCursor(0,8);
			LCD_displayString("ON 100%");//Display The DC_Motor State
			DCMotor_Rotate(CW,100);//The DC_Motor rotate clockwise with 100% of its Maximuum Speed

                     }

	         }
                 }
