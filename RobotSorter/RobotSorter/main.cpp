/*
 * RobotSorter.cpp
 *
 * Created: 27-02-2020 09:09:45
 * Author : jespe
 */ 
//#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "ColorSensor/header/ColorSensor.h"
#include "RobotArm/Header/RobotArm.h"

/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

void FirstTask( void *pvParameters )
{
			Robotarm* ptr = (Robotarm*) pvParameters;
		ptr->grabBlock();
	while(1)
	{
		ptr->grabBlock();
	 	vTaskDelay( 5000 / portTICK_RATE_MS );
		ptr->moveBlockToZoneOne();
	 	vTaskDelay( 5000 / portTICK_RATE_MS );
	}
}

int main(void)
{
	Robotarm arm = Robotarm();
	
	volatile uint8_t test = xTaskCreate(FirstTask,  ( signed char * ) "Task", configMINIMAL_STACK_SIZE, &arm, tskIDLE_PRIORITY, NULL);
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


