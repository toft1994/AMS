/* 
* M3.cpp
*
* Created: 26-03-2020 23:57:16
* Author: jespe
*/

#include "M3.h"

M3::M3( Timer1* tmr )
{
	/* Store timer pointer */
	tmr1Ptr_ = tmr;
		
	/* This value is number of percent to add or subtract pr degree. */
	percentPrDeg = 0.0555555555555556;
	
	/* This value is the lowest duty cycle percentage needed to make motor turn. */
	startpercent_ = 2.5;

	/* This value is the delay on motor. A lower value makes motors go faster and higher value makes motors go slower. Value is in MS */
	delay_ = 7;
	
	/* Set motor to default startup value */
	SetDegrees(90);
	tmr1Ptr_->setDutyCycleComC( percent_ );
	oldPercent_ = percent_;	
}

M3::~M3()
{
}

void M3::TurnMotor()
{
	if ( percent_ > oldPercent_ + PERCENT_PR_TICK )
	{
		oldPercent_ += PERCENT_PR_TICK;
		tmr1Ptr_->setDutyCycleComC( oldPercent_ );
		vTaskDelay( delay_ / portTICK_RATE_MS );
	}
	else if ( percent_ < oldPercent_ )
	{
		oldPercent_ -= PERCENT_PR_TICK;
		tmr1Ptr_->setDutyCycleComC( oldPercent_ );
		vTaskDelay( delay_ / portTICK_RATE_MS );
	}
}
