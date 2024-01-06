/*
 * DC_motor.h
 *
 *  Created on: Jan 6, 2024
 *      Author: Abdulla Nagy
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include"std_types.h"
typedef enum{
	stop,CW,ACW
}DCMotor_state;
DCMotor_state state;

void DCMotor_Init(void);

void DCMotor_Rotate( DCMotor_state state ,uint8 speed);

#endif /* DC_MOTOR_H_ */
