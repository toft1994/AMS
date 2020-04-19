/* 
* M1.cpp
*
* Created: 26-03-2020 23:57:16
* Author: jespe
*/

#include "M1.h"

M1::M1( Timer1* tmr )
{
	/* Store timer pointer */
	tmr1Ptr_ = tmr;
	
	/* This value is number of percent to add or subtract pr degree. */
	percentPrDeg = 0.0555555555555556;
	
	/* This value is the lowest duty cycle percentage needed to make motor turn. */
	startpercent_ = 2.5;
	
	/* This value is the delay on motor. A lower value makes motors go faster and higher value makes motors go slower. */
	delay_ = 10;
	
	/* This value is the maximum number of degrees the motor can turn */
	maxDegrees_ = 180;
	
	/* Set motor to default startup value */
	SetDegrees( 90 );
	tmr1Ptr_->setDutyCycleComA( percent_ );
	oldPercent_ = percent_;
} 

M1::~M1()
{
}

void M1::TurnMotor()
{
	if ( percent_ > oldPercent_ + PERCENT_PR_TICK )
	{
		oldPercent_ += PERCENT_PR_TICK;
		tmr1Ptr_->setDutyCycleComA( oldPercent_ );
		vTaskDelay( delay_ / portTICK_RATE_MS );
	}
	else if ( percent_ < oldPercent_ )
	{
		oldPercent_ -= PERCENT_PR_TICK;
		tmr1Ptr_->setDutyCycleComA( oldPercent_ );
		vTaskDelay( delay_ / portTICK_RATE_MS );
	}
}
