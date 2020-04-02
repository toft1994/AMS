/*
 * RobotArm.cpp
 *
 * Created: 12-03-2020 11:44:59
 *  Author: jespe
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "../Header/RobotArm.h"
#define F_CPU 16000000

/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

const uint16_t xDelay = 10 / portTICK_RATE_MS;

Robotarm::Robotarm()
{
	DDRB = DDRB | ( 1 << 4 );
	//PORTB =  ( 1 << 4 );
	
	tmr1_ = timer1();
	tmr3_ = timer3();
	
 	tmr1_.setDutyCycleComA(6);
	M1_Percent = 6;
	M1_OldPercent = 6;

 	tmr1_.setDutyCycleComB(7);
	M2_Percent = 7;
	M2_OldPercent = 7;
	
	tmr1_.setDutyCycleComC(6);
	M3_Percent = 6;
	M3_OldPercent = 6;
	
	tmr3_.setDutyCycleComA(6);
	M4_Percent = 6;
	M4_OldPercent = 6;
	
	tmr3_.setDutyCycleComB(3);
	M5_Percent = 3;
	M5_OldPercent = 3;
	
	tmr3_.setDutyCycleComC(3);
	M6_Percent = 3;
	M6_OldPercent = 3;
	
	volatile uint8_t returnval = xTaskCreate(this->startMotorImpl,  ( signed char * ) "Motors", configMINIMAL_STACK_SIZE, this, tskIDLE_PRIORITY, NULL);
}

void Robotarm::grabBlock()
{
	M5_Percent = 7.7;
	M1_Percent = 2.5;
	vTaskDelay( 1500 / portTICK_RATE_MS );
	M2_Percent = 5.2; 
	M3_Percent = 5.0;
	vTaskDelay( 1500 / portTICK_RATE_MS );
	M6_Percent = 7.3;
}

void Robotarm::moveBlockToZoneOne()
{
	M1_Percent = 2.5;
	M2_Percent = 7; 
	M3_Percent = 6;
	M4_Percent = 6;
	vTaskDelay( 3000 / portTICK_RATE_MS );
	M2_Percent = 5.2;
	M3_Percent = 5.0;
	vTaskDelay( 1500 / portTICK_RATE_MS );
	M6_Percent = 2.5;
	vTaskDelay( 1500 / portTICK_RATE_MS );	
	M2_Percent = 7; 
	M3_Percent = 6;
	M4_Percent = 6;
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
		{
			if ( M1_Percent > M1_OldPercent )
			{
				M1_OldPercent += 0.0625 ;
				tmr1_.setDutyCycleComA( M1_OldPercent );
				vTaskDelay( xDelay );
			}
			else if ( M1_Percent < M1_OldPercent )
			{
				M1_OldPercent -= 0.0625;
				tmr1_.setDutyCycleComA( M1_OldPercent );
			 	vTaskDelay( xDelay );
			}
			
			if ( M2_Percent > M2_OldPercent )
			{
				M2_OldPercent += 0.0625;
				tmr1_.setDutyCycleComB( M2_OldPercent );
				vTaskDelay( xDelay );
			}
			else if ( M2_Percent < M2_OldPercent )
			{
				M2_OldPercent -= 0.0625;
				tmr1_.setDutyCycleComB( M2_OldPercent );
				vTaskDelay( xDelay );
			}
			
			if ( M3_Percent > M3_OldPercent )
			{
				M3_OldPercent += 0.0625;
				tmr1_.setDutyCycleComC( M3_OldPercent );
				vTaskDelay( xDelay );
			}
			else if ( M3_Percent < M3_OldPercent )
			{
				M3_OldPercent -= 0.0625;
				tmr1_.setDutyCycleComC( M3_OldPercent );
				vTaskDelay( xDelay );
			}
			
			if ( M4_Percent > M4_OldPercent )
			{
				M4_OldPercent += 0.0625;
				tmr3_.setDutyCycleComA( M4_OldPercent );
				vTaskDelay( xDelay );
			}
			else if ( M4_Percent < M4_OldPercent )
			{
				M4_OldPercent -= 0.0625;
				tmr1_.setDutyCycleComA( M4_OldPercent );
				vTaskDelay( xDelay );
			}
			
			if ( M5_Percent > M5_OldPercent )
			{
				M5_OldPercent += 0.0625;
				tmr3_.setDutyCycleComB( M5_OldPercent );
				vTaskDelay( xDelay );
			}
			else if ( M5_Percent < M5_OldPercent )
			{
				M5_OldPercent -= 0.0625;
				tmr3_.setDutyCycleComB( M5_OldPercent );
				vTaskDelay( xDelay );
			}
			
			if ( M6_Percent > M6_OldPercent )
			{
				M6_OldPercent += 0.0625;
				tmr3_.setDutyCycleComC( M6_OldPercent );
				vTaskDelay( xDelay );
			}
			else if ( M6_Percent < M6_OldPercent )
			{
				M6_OldPercent -= 0.0625;
				tmr3_.setDutyCycleComC( M6_OldPercent );
				vTaskDelay( xDelay );
			}
		}
	}
}