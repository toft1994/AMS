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

void Keypad( void *pvParameters )
{
	while (1)
	{
		//Keypad.Run();
	}
}

void DisplayArm( void *pvParameters )
{
	while(1)
	{
		screen.clearScreen();
		
		while ( /* Keypad.AccessGranted == */ 1 ) 
		{
			screen.presentButtonsOnDisplay();
			
			switch ( screen.checkButtons() )
			{
				case 1U:
				{
					csensor.addCalibrateColor( colorIndex );
					colorIndex++;			
					break;
				}
		
				case 2U:
				{
					arm.MoveItem( csensor.getColor() );
				}
			}
		}
	}
}

int main(void)
{
	xTaskCreate(DisplayArm,  ( signed char * ) "Display + Arm Task", configMAIN_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
	xTaskCreate(Keypad,  ( signed char * ) "Keypad Task", configMAIN_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
	vTaskStartScheduler();

	while (1)
	{
	}
}


