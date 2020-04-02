/*
 * RobotSorter.cpp
 *
 * Created: 27-02-2020 09:09:45
 * Author : jespe
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "ColorSensor.h"
#include "RobotArm/RobotArm.h"

/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

extern "C" void __cxa_pure_virtual() { while (1); }
	
ColorSensor csensor = ColorSensor( hundredPercent );

void FirstTask( void *pvParameters )
{
	Robotarm* armptr = (Robotarm*) pvParameters;	 

	csensor.setBackgroundBasis();
	csensor.addCalibrateColor( 0U );
	csensor.addCalibrateColor( 1U );
	//csensor.addCalibrateColor( 2U );
		 
	while(1)
	{		
		uint8_t color = 1U;//csensor.getColor();
		switch ( color )
		{
			case 1U:
				armptr->grabBlock();
				vTaskDelay( 5000 / portTICK_RATE_MS );
				armptr->moveBlockToZoneOne();
				vTaskDelay( 5000 / portTICK_RATE_MS );
				break;
				
			case 2U: 
				armptr->grabBlock();
				vTaskDelay( 5000 / portTICK_RATE_MS );
				armptr->moveBlockToZoneTwo();
				vTaskDelay( 5000 / portTICK_RATE_MS );
				break;
				
			case 3U:
				armptr->grabBlock();
				vTaskDelay( 5000 / portTICK_RATE_MS );
				armptr->moveBlockToZoneThree();
				vTaskDelay( 5000 / portTICK_RATE_MS );
				break;
				
			case 255U:
				break;
				
		}
	}
}

int main(void)
{
	Robotarm arm = Robotarm();

	xTaskCreate(FirstTask,  ( signed char * ) "Task", configMINIMAL_STACK_SIZE, &arm, tskIDLE_PRIORITY, NULL);
	vTaskStartScheduler();

	while (1)
	{
	}
	//InitUART( UART0, 9600, 8, 'N' );
	//ColorSensor cs = ColorSensor( hundredPercent );
	//cs.setBackgroundBasis();
	//cs.setBackgroundBasis();
	//cs.addCalibrateColor( 0U );
	//cs.addCalibrateColor( 1U );
	//cs.addCalibrateColor( 2U );
	//cs.addCalibrateColor( 3U );
//
    ///* Replace with your application code */
    //while (1) 
    //{
		//uint8_t readColor = cs.getColor();
		//
		//if (readColor == 0U)
		//{
			//SendString(UART0, "Color is green!");
			//SendChar(UART0, '\r');
			//SendChar(UART0, '\n');
		//}
		//else if (readColor == 1U)
		//{
			//SendString(UART0, "Color is blue!");
			//SendChar(UART0, '\r');
			//SendChar(UART0, '\n');
		//}
		//else if (readColor == 2U)
		//{
			//SendString(UART0, "Color is red!");
			//SendChar(UART0, '\r');
			//SendChar(UART0, '\n');
		//}
		//else if (readColor == 3U)
		//{
			//SendString(UART0, "Color is orange!");
			//SendChar(UART0, '\r');
			//SendChar(UART0, '\n');
		//}
//
		//_delay_ms(100);
    //}
}


