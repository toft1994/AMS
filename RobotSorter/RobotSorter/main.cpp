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
#include "LoginInterface.h"

/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

/* This file is needed to be able to use new and delete operators */
#include "CPlusPlusSpecific.h"

/* Create shared objects */
LoginInterface Login = LoginInterface();

uint8_t colorIndex = 0;

void LoginKeyPad( void *pvParameters )
{
	while (1)
	{
		Login.checkLogin();
	}
}

void DisplayArm( void *pvParameters )
{
	Robotarm* armPtr = (Robotarm*) pvParameters;
	ColorSensor csensor = ColorSensor( twentyPercent );
	Touchscreen screen = Touchscreen();
	
	while(1)
	{
		screen.clearScreen();
			
		while ( Login.getstateOfMachine() == 'U' )
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
					uint8_t temp_color = csensor.getColor();
					if (temp_color != 255)
					{
						armPtr->MoveItem( temp_color );
					}
					else
					{
						screen.flashRedOnDisplay();
						vTaskDelay( 1000 / portTICK_RATE_MS );
						screen.clearScreen();
						screen.presentButtonsOnDisplay();
					}
					break;
				}
				
				default:
				break;
			}
		}
	}
}

int main(void)
{		
	Robotarm arm = Robotarm();
	xTaskCreate(LoginKeyPad,  ( signed char * ) "Keypad Task", configMAIN_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
	xTaskCreate(DisplayArm,  ( signed char * ) "Display + Arm Task", configMAIN_STACK_SIZE, &arm, tskIDLE_PRIORITY, NULL);
	vTaskStartScheduler();

	while (1)
	{
	}
}