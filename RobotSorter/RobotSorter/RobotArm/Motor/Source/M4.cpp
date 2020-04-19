/* 
* M4.cpp
*
* Created: 26-03-2020 23:57:16
* Author: jespe
*/

#include "M4.h"

M4::M4( Timer3* tmr )
{
	/* Store timer pointer */
	tmr3Ptr_ = tmr;
	
	/* This value is number of percent to add or subtract pr degree. */
	percentPrDeg = 0.0555555555555556;
	
	/* This value is the lowest duty cycle percentage needed to make motor turn. */
	startpercent_ = 2.5;
		
	/* This value is the delay on motor. A lower value makes motors go faster and higher value makes motors go slower. Value is in MS */
	delay_ = 5;
	
	/* This value is the maximum number of degrees the motor can turn */
	maxDegrees_ = 180;
	
	/* Set motor to default startup value */
	SetDegrees( 90 );
	tmr3Ptr_->setDutyCycleComA( percent_ );
	oldPercent_ = percent_;
}

M4::~M4()
{
} 

void M4::TurnMotor()
{
	if ( percent_ > oldPercent_ + PERCENT_PR_TICK )
	{
		oldPercent_ += PERCENT_PR_TICK;
		tmr3Ptr_->setDutyCycleComA( oldPercent_ );
		vTaskDelay( 10 / portTICK_RATE_MS );
	}
	else if ( percent_ < oldPercent_ )
	{
		oldPercent_ -= PERCENT_PR_TICK;
		tmr3Ptr_->setDutyCycleComA( oldPercent_ );
		vTaskDelay( 10 / portTICK_RATE_MS );
	}
}
