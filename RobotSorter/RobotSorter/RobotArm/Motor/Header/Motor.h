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
	*    @param void Nothing
	*    @return void Nothing
	*/
	virtual void TurnMotor() = 0;
	
	/**
	*    Converts degrees to percent and sets percent. When percent is set \ref TurnMotor 
	*	 can be used to turn motor at a specific speed set by \ref delay. C
	*	 Note that this function needs to run multiple times to work as intended.
	*    @param uint8_t	degrees to turn
	*    @return void Nothing
	*/
	virtual void SetDegrees( uint8_t degrees )
	{
		if ( maxDegrees_ >= degrees )
		{
			percent_ = percentPrDeg * degrees + startpercent_;
		}
	}
	
protected:
	/**
	* Pointer to an instance of Timer1. Used to control PWM signals.
	*/
	Timer1* tmr1Ptr_;
	
	/**
	* Pointer to an instance of Timer5. Used to control PWM signals.
	*/
	Timer5* tmr3Ptr_;
	
	/**
	* Number of percent that is needed to turn motor one degree.
	*/
	float percentPrDeg;
	
	/**
	* The current duty cycle percent the motor is set to.
	*/
	float percent_;
	
	/**
	* The duty cycle percent the motor is set to one tick ago. 
	*/
	float oldPercent_;
	
	/**
	* Lowest duty cycle percent at which the motor will turn.
	*/
	float startpercent_;
	
	/**
	* Max turn radius for the motor in degrees.
	*/
	uint8_t maxDegrees_;
	
	/** 
	* Time in ms that the motor will be delayed.
	*/
	uint16_t delay_;

}; //Motor

#endif //__MOTOR_H__
