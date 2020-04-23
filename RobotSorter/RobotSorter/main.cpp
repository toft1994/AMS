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
	SendString("Moving on 3 \n\r");
	
	//csensor.addCalibrateColor( 2U );
	//
	//while( read != 'o' )
	//{
		//read = ReadChar();
	//}
	//read = '0';	
	//SendString("Moving on 4 \n\r");
	//
	//csensor.addCalibrateColor( 3U );
	//
	//while( read != 'o' )
	//{
		//read = ReadChar();
	//}
	//read = '0';
	//SendString("Moving on 5 \n\r");
	//
	//csensor.addCalibrateColor( 4U );
	//
	//while( read != 'o' )
	//{
		//read = ReadChar();
	//}
	//read = '0';
	//SendString("Moving on 6 \n\r");
	//
	//csensor.addCalibrateColor( 5U );
	//
	while( read != 'o' )
	{
		read = ReadChar();
	}
	read = '0';
	SendString("Moving on 7 \n\r");
		 
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
				//SendString("White color\r\n");
				//vTaskDelay( 5000 / portTICK_RATE_MS );
				break;
				
			case 1U: 
				arm->grabBlock();
				vTaskDelay( 5000 / portTICK_RATE_MS );
				arm->moveBlockToZoneTwo();
				vTaskDelay( 5000 / portTICK_RATE_MS );
				//SendString("Red color\r\n");
				//vTaskDelay( 5000 / portTICK_RATE_MS );
				break;
				
			//case 2U:
				////arm.grabBlock();
				////vTaskDelay( 5000 / portTICK_RATE_MS );
				////arm.moveBlockToZoneThree();
				////vTaskDelay( 5000 / portTICK_RATE_MS );
				//SendString("Blue color\r\n");
				//vTaskDelay( 5000 / portTICK_RATE_MS );
				//break;
				//
			//case 3U:
				//SendString("Green color\r\n");
				//vTaskDelay( 5000 / portTICK_RATE_MS );
				//break;
				//
			//case 4U:
				//SendString("Yellow color\r\n");
				//vTaskDelay( 5000 / portTICK_RATE_MS );
				//break;
				//
			//case 5U:
				//SendString("Orange color\r\n");
				//vTaskDelay( 5000 / portTICK_RATE_MS );
				//break;
				
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
	//char read = '0';
	//InitUART( 9600, 8, 'N' );
	//ColorSensor cs = ColorSensor( twentyPercent );
	//while( read != 'o' )
	//{
		//read = ReadChar();
	//}
	//read = '0';
	//SendString("Moving on \n\r");
	//cs.addCalibrateColor( 0U );
		//while( read != 'o' )
		//{
			//read = ReadChar();
		//}
		//read = '0';
		//SendString("Moving on \n\r");
	//cs.addCalibrateColor( 1U );
//
    ///* Replace with your application code */
    //while (1) 
    //{
		//SendString("ReadingColor\n\r");
		//uint8_t readColor = cs.getColor();
		//
		//if (readColor == 0U)
		//{
			//SendString("Color is green!");
			//SendChar( '\r');
			//SendChar('\n');
		//}
		//else if (readColor == 1U)
		//{
			//SendString("Color is blue!");
			//SendChar('\r');
			//SendChar('\n');
		//}
		//
		//_delay_ms(1000);
    //}
}


