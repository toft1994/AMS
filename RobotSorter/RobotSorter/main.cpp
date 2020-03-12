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
#include "ColorSensor/header/ColorSensor.h"
#include "uart.h"

int main(void)
{
	InitUART(UART0,9600,8,'N');
	ColorSensor cs = ColorSensor();

    /* Replace with your application code */
    while (1) 
    {
		color readColor = cs.getColor();
		
		if (readColor == green)
		{
			SendString(UART0, "Color is green!");
			SendChar(UART0, '\r');
			SendChar(UART0, '\n');
		}
		else if (readColor == blue)
		{
			SendString(UART0, "Color is blue!");
			SendChar(UART0, '\r');
			SendChar(UART0, '\n');
		}
		else if (readColor == red)
		{
			SendString(UART0, "Color is red!");
			SendChar(UART0, '\r');
			SendChar(UART0, '\n');
		}

		_delay_ms(100);
    }
}

