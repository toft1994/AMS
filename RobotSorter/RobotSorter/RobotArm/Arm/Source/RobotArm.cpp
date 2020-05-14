/*
 * RobotArm.cpp
 *
 * Created: 12-03-2020 11:44:59
 *  Author: jespe
 */ 

#include <avr/io.h>
#include "RobotArm.h"

/* Robotarm motors */
#include "M1.h"
#include "M2.h"
#include "M3.h"
#include "M4.h"
#include "M5.h"
#include "M6.h"

/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

Robotarm::Robotarm() : tmr1_(), tmr3_()
{
	/* Create all motor objects */
	motors_[0] = new M1( &tmr1_ );
	motors_[1] = new M2( &tmr1_ );
	motors_[2] = new M3( &tmr1_ );
	motors_[3] = new M4( &tmr3_ );
	motors_[4] = new M5( &tmr3_ );
	motors_[5] = new M6( &tmr3_ );
	
	/* Create task to control motors */
	xTaskCreate(this->startMotorImpl,  ( signed char * ) "Motors", configMAIN_STACK_SIZE, this, tskIDLE_PRIORITY, NULL);
}

void Robotarm::grabBlock()
{
	motors_[3]->SetDegrees(40);
	motors_[4]->SetDegrees(90);
	motors_[0]->SetDegrees(0);
	vTaskDelay( 1500 / portTICK_RATE_MS );
	motors_[1]->SetDegrees(35);
	motors_[2]->SetDegrees(63);
	vTaskDelay( 1500 / portTICK_RATE_MS );
	motors_[5]->SetDegrees(63);
	vTaskDelay( 250 / portTICK_RATE_MS );
	motors_[1]->SetDegrees(70);
	motors_[2]->SetDegrees(70);
	motors_[3]->SetDegrees(70);
}

void Robotarm::moveBlockToZoneOne()
{
	motors_[0]->SetDegrees(40);
	ArmDownReleaseItem();
}

void Robotarm::moveBlockToZoneTwo()
{
	motors_[0]->SetDegrees(68);
	ArmDownReleaseItem();
}

void Robotarm::moveBlockToZoneThree()
{
	motors_[0]->SetDegrees(96);
	ArmDownReleaseItem();
}

void Robotarm::moveBlockToZoneFour()
{
	motors_[0]->SetDegrees(124);
	ArmDownReleaseItem();
}

void Robotarm::moveBlockToZoneFive()
{
	motors_[0]->SetDegrees(152);
	ArmDownReleaseItem();
}

void Robotarm::moveBlockToZoneSix()
{
	motors_[0]->SetDegrees(180);
	ArmDownReleaseItem();
}


void Robotarm::ArmDownReleaseItem()
{
	vTaskDelay( 1500 / portTICK_RATE_MS );
	motors_[1]->SetDegrees(35);
	motors_[2]->SetDegrees(40);
	vTaskDelay( 1500 / portTICK_RATE_MS );
	motors_[5]->SetDegrees(0);
	vTaskDelay( 250 / portTICK_RATE_MS );
	motors_[1]->SetDegrees(90);
	motors_[2]->SetDegrees(90);
	motors_[3]->SetDegrees(90);
	vTaskDelay( 250 / portTICK_RATE_MS );
}

void Robotarm::startMotorImpl( void *_this )
{
	/* Run \ref MotorSpeedController */
	Robotarm* ptr = (Robotarm*) _this;
	ptr->MotorSpeedController(); // This function should never return!
}

void Robotarm::MotorSpeedController()
{
	while(1)
	{
		/* Move all motors one step. */
		for ( uint8_t i = 0U; i < 6U; i++ )
		{
			motors_[i]->TurnMotor();
		}
	}
}