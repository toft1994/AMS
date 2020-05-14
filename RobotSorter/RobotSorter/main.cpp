/*
 * RobotSorter.cpp
 *
 * Created: 27-02-2020 09:09:45
 * Author : jespe
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "ColorSensor.h"
#include "RobotArm.h"
#include "Touchscreen.h"
#include "KeyPad.h"

#include "uart.h"

/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

/* This file is needed to be able to use new and delete operators */
#include "CPlusPlusSpecific.h"

/* Create all needed objects */
Robotarm arm = Robotarm();
ColorSensor csensor = ColorSensor( twentyPercent );
Touchscreen screen = Touchscreen();

uint8_t colorIndex = 0;

void Sort( uint8_t color )
{
	switch ( color )
	{
		case 0U:
		arm.grabBlock();
		vTaskDelay( 500 / portTICK_RATE_MS ); // This might not be needed!!! it can be added in Robotarm!!!! we will seeee later
		arm.moveBlockToZoneOne();
		vTaskDelay( 500 / portTICK_RATE_MS );
		break;
		
		case 1U:
		arm.grabBlock();
		vTaskDelay( 500 / portTICK_RATE_MS );
		arm.moveBlockToZoneTwo();
		vTaskDelay( 500 / portTICK_RATE_MS );
		break;
		
		case 2U:
		arm.grabBlock();
		vTaskDelay( 500 / portTICK_RATE_MS );
		arm.moveBlockToZoneThree();
		vTaskDelay( 500 / portTICK_RATE_MS );
		break;
		
		case 3U:
		arm.grabBlock();
		vTaskDelay( 500 / portTICK_RATE_MS );
		arm.moveBlockToZoneFour();
		vTaskDelay( 500 / portTICK_RATE_MS );
		break;
		
		case 4U:
		arm.grabBlock();
		vTaskDelay( 500 / portTICK_RATE_MS );
		arm.moveBlockToZoneFive();
		vTaskDelay( 500 / portTICK_RATE_MS );
		break;
		
		case 5U:
		arm.grabBlock();
		vTaskDelay( 500 / portTICK_RATE_MS );
		arm.moveBlockToZoneSix();
		vTaskDelay( 500 / portTICK_RATE_MS );
		break;
		
		default:
		break;
	}
}

void MainTask( void *pvParameters )
{
	while(1)
	{
		screen.clearScreen();
		
		while (1); // while(keypad.checkPasswordEntered() == 0);
					
		screen.presentButtonsOnDisplay();
		
		// We need somehting to break from this state again! Input from keypad
	
		switch ( screen.checkButtons() )
		{
			case 1U:
			{
				csensor.addCalibrateColor(colorIndex);
				colorIndex++;			
				break;
			}
		
			case 2U:
			{
				Sort( csensor.getColor() );
			}
		}
	}
}

int main(void)
{
	xTaskCreate(MainTask,  ( signed char * ) "Task", configMAIN_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
	vTaskStartScheduler();

	while (1)
	{
	}
}


