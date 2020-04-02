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

Robotarm::Robotarm() : tmr1_(), tmr3_(), motor1_( &tmr1_ ), motor2_( &tmr1_ ), motor3_( &tmr1_ ), motor4_( &tmr3_ ), motor5_( &tmr3_ ), motor6_( &tmr3_ )
{
	DDRB = DDRB | ( 1 << 4 );
	//PORTB =  ( 1 << 4 );
	motors_[0] = &motor1_;
	motors_[1] = &motor2_;
	motors_[2] = &motor3_;
	motors_[3] = &motor4_;
	motors_[4] = &motor5_;
	motors_[5] = &motor6_;
	
	xTaskCreate(this->startMotorImpl,  ( signed char * ) "Motors", configMINIMAL_STACK_SIZE, this, 1U, NULL);
}

void Robotarm::grabBlock()
{
	motor4_.SetDegrees(40);
	motor5_.SetDegrees(90);
	motor1_.SetDegrees(0);
	vTaskDelay( 1500 / portTICK_RATE_MS );
	motor2_.SetDegrees(35);
	motor3_.SetDegrees(63);
	vTaskDelay( 1500 / portTICK_RATE_MS );
	motor6_.SetDegrees(65);
	vTaskDelay( 250 / portTICK_RATE_MS );
	motor2_.SetDegrees(70);
	motor3_.SetDegrees(70);
	motor4_.SetDegrees(70);
}

void Robotarm::moveBlockToZoneOne()
{
	motor1_.SetDegrees(90);
	ArmDownReleaseItem();
}

void Robotarm::moveBlockToZoneTwo()
{
	motor1_.SetDegrees(135);
	ArmDownReleaseItem();
}

void Robotarm::moveBlockToZoneThree()
{
	motor1_.SetDegrees(180);
	ArmDownReleaseItem();
}

void Robotarm::startMotorImpl( void *_this )
{
	Robotarm* ptr = (Robotarm*) _this;
	ptr->MotorSpeedController();
}

void Robotarm::MotorSpeedController()
{
	while(1)
	{
		for ( uint8_t i = 0U; i < 6U; i++ )
		{
			motors_[i]->TurnMotor();
		}
	}
}

void Robotarm::ArmDownReleaseItem()
{
	vTaskDelay( 1500 / portTICK_RATE_MS );
	motor2_.SetDegrees(35);
	motor3_.SetDegrees(40);
	vTaskDelay( 1500 / portTICK_RATE_MS );
	motor6_.SetDegrees(0);
	vTaskDelay( 250 / portTICK_RATE_MS );
	motor2_.SetDegrees(90);
	motor3_.SetDegrees(90);
	motor4_.SetDegrees(90);
	vTaskDelay( 250 / portTICK_RATE_MS );
}