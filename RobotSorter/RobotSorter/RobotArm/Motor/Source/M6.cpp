/* 
* M6.cpp
*
* Created: 26-03-2020 23:57:16
* Author: jespe
*/

#include "M6.h"

M6::M6( Timer3* tmr )
{
	/* Store timer pointer */
	tmr3Ptr_ = tmr;
	
	/* This value is number of percent to add or subtract pr degree. */
	percentPrDeg = 0.07936507936507;
	
	/* This value is the lowest duty cycle percentage needed to make motor turn. */
	startpercent_ = 2.5;
	
	/* This value is the delay on motor. A lower value makes motors go faster and higher value makes motors go slower. Value is in MS */
	delay_ = 1;
	
	/* This value is the maximum number of degrees the motor can turn */
	maxDegrees_ = 63;
	
	/* Set motor to default startup value */
	SetDegrees( 0 );
	tmr3Ptr_->setDutyCycleComC( percent_ );
	oldPercent_ = percent_;
}

M6::~M6()
{
}

void M6::TurnMotor()
{
	if ( percent_ > oldPercent_ + PERCENT_PR_TICK )
	{
		oldPercent_ += 0.0625;
		tmr3Ptr_->setDutyCycleComC( oldPercent_ );
		vTaskDelay( delay_ / portTICK_RATE_MS );
	}
	else if ( percent_ < oldPercent_ )
	{
		oldPercent_ -= 0.0625;
		tmr3Ptr_->setDutyCycleComC( oldPercent_ );
		vTaskDelay( delay_ / portTICK_RATE_MS );
	}
}
