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
#include "Timer5.h"

/* How many percent to move pr. tick. Lower value will make motors turn slower. */
#define PERCENT_PR_TICK 0.0625

class Motor
{
//functions
public:
	virtual ~Motor() {};

	/**
	*    Turns motor a given amount until the desired position is achieved.
	*	  Note that this function needs to run multiple times to work as intended.
	*    @param void
	*    @return void
	*/
	virtual void TurnMotor() = 0;
	
	/**
	*    Converts degrees to percent and sets percent. When percent is set \ref TurnMotor 
	*	 can be used to turn motor at a specific speed set by \ref delay. C
	*	 Note that this function needs to run multiple times to work as intended.
	*    @param uint8_t		sdegrees to turn
	*    @return void
	*/
	virtual void SetDegrees( uint8_t degrees )
	{
		if ( maxDegrees_ >= degrees )
		{
			percent_ = percentPrDeg * degrees + startpercent_;
		}
	}
	
protected:
	/* Needed timers for motors */
	Timer1* tmr1Ptr_;
	Timer5* tmr3Ptr_;
	
	/* Attributes needed to calculate degree to duty cycle */
	float percentPrDeg;
	float percent_;
	float oldPercent_;
	float startpercent_;
	uint8_t maxDegrees_;
	
	/* Speed delay */
	uint16_t delay_;

}; //Motor

#endif //__MOTOR_H__
