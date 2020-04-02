/* 
* Motor.h
*
* Created: 28-03-2020 22:04:31
* Author: jespe
*/


#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

/* Timer include */
#include "Timer1.h"
#include "Timer3.h"

/* How many percent to move pr. tick. Lower value will make motors turn slower. */
#define PERCENT_PR_TICK 0.0625

class Motor
{
//functions
public:
	virtual ~Motor() {};
	virtual void TurnMotor() = 0;
	virtual void SetDegrees( uint8_t degrees )
	{
		percent_ = percentPrDeg * degrees + startpercent_;
	}
	
protected:
	Timer1* tmr1Ptr_;
	Timer3* tmr3Ptr_;
	float percentPrDeg;
	float percent_;
	float oldPercent_;
	float startpercent_;
	uint16_t delay_;

}; //Motor

#endif //__MOTOR_H__
