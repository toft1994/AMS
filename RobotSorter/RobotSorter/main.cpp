/*
 * RobotSorter.cpp
 *
 * Created: 27-02-2020 09:09:45
 * Author : jespe
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "ColorSensor.h"
#include "RobotArm.h"

#include "uart.h"

/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

/* This file is needed to be able to use new and delete operators */
#include "CPlusPlusSpecific.h"

void FirstTask( void *pvParameters )
{
	InitUART( 9600, 8, 'N' );

	SendString("I JUST FUCKIN RESTARTED!!\n\r\n\r");
	Robotarm* arm = ( Robotarm* ) pvParameters;
	ColorSensor csensor = ColorSensor( twentyPercent );
	char read = '0';
	
	while( read != 'o' )
	{
		read = ReadChar();
	}
	read = '0';	
	SendString("Moving on 1 \n\r");
	
	csensor.addCalibrateColor( 0U );
	
	while( read != 'o' )
	{
		read = ReadChar();
	}
	read = '0';
	SendString("Moving on 2 \n\r");
		
	csensor.addCalibrateColor( 1U );
	
	while( read != 'o' )
	{
		read = ReadChar();
	}
	read = '0';
	SendString("Starting to read\n\r");
			 
	while(1)
	{		
		uint8_t color = csensor.getColor();
		switch ( color )
		{
			case 0U:
				arm->grabBlock();
				vTaskDelay( 5000 / portTICK_RATE_MS );
				arm->moveBlockToZoneOne();
				vTaskDelay( 5000 / portTICK_RATE_MS );
				break;
				
			case 1U: 
				arm->grabBlock();
				vTaskDelay( 5000 / portTICK_RATE_MS );
				arm->moveBlockToZoneTwo();
				vTaskDelay( 5000 / portTICK_RATE_MS );
				break;
		}
		vTaskDelay(100/portTICK_RATE_MS);
	}
}

int main(void)
{
	Robotarm arm = Robotarm();
	xTaskCreate(FirstTask,  ( signed char * ) "Task", configMAIN_STACK_SIZE, &arm, tskIDLE_PRIORITY, NULL);
	vTaskStartScheduler();

	while (1)
	{
	}
}


