/*
 * ColorSensorTestMain.h
 *
 * Created: 09-05-2020 13:08:31
 *  Author: jespe
 */ 

#include "uart.h"
#include "ColorSensor.h"

void ColorSensorTestMain()
{
	// Setup UART and colorsensor
	InitUART( 9600, 8, 'N' );
	ColorSensor csensor = ColorSensor( twentyPercent );
	
	// Wait until 
	for (uint8_t i = 0; i < 2; i++)
	{
		char read = '0';
		SendString("To continue place color infront of sensor and press 'o'");
		while( read != 'o' )
		{
			read = ReadChar();
		}
		csensor.addCalibrateColor(i);
		SendString("\r\nAdding color number ");
		SendInteger(i+1);
		SendString(" out of 6\r\n");
	}
	
	while(1)
	{
		// Read color and write 
		uint8_t color = csensor.getColor();
		switch ( color )
		{
			case 0U:
			SendString("Color index 1\r\n");
			vTaskDelay( 200 / portTICK_RATE_MS );
			break;
			
			case 1U:
			SendString("Color index 2\r\n");
			vTaskDelay( 200 / portTICK_RATE_MS );
			break;
			
			case 2U:
			SendString("Color index 3\r\n");
			vTaskDelay( 200 / portTICK_RATE_MS );
			break;
			
			case 3U:
			SendString("Color index 4\r\n");
			vTaskDelay( 200 / portTICK_RATE_MS );
			break;
			
			case 4U:
			SendString("Color index 5\r\n");
			vTaskDelay( 200 / portTICK_RATE_MS );
			break;
			
			case 5U:
			SendString("Color index 6\r\n");
			vTaskDelay( 200 / portTICK_RATE_MS );
			break;
		}
		vTaskDelay( 200 / portTICK_RATE_MS );
	}
}