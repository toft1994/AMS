/*
 * Touchscreen.cpp
 *
 * Created: 14-05-2020 10:00:47
 *  Author: MIKKELJENSEN
 */ 
#include <avr/io.h>


#include "Touchscreen.h"
#include "TouchDriver.h"
#include "TFTdriver.h"
#include "ButtonClass.h"
#include "uart.h"


Touchscreen::Touchscreen()
{
	TouchDriv = TouchDriver();
	
	blueBnt = ButtonClass(20, 70, 120, 170, 29, 234, 2);
	greenBnt = ButtonClass(200, 70, 300, 170, 44, 2, 234);
	
	DisplayInit();
}


uint8_t Touchscreen::checkButtons(void)
{
	uint8_t x = 0;
	uint8_t y = 0;
	
	TouchDriv.getCoordinates(&x, &y);
	SendString("X value: ");
	SendInteger(x);
	SendString("y value: ");
	SendInteger(y);
	SendString("\r\n");
	if (x > blueBnt.startX/1.33 && x < blueBnt.endX/1.33 && y > blueBnt.startY && y < blueBnt.endY)
	{
		return 1;
	}
	else if (x > greenBnt.startX/1.33 && x < greenBnt.endX/1.33 && y > greenBnt.startY && y < greenBnt.endY)
	{
		return 2;
	}
	else
	{
		return 0;
	}
	
}

void Touchscreen::clearScreen(void)
{
	// Full Screen White
	FillRectangle(0,0,320,240,255,255,255);
}

void Touchscreen::presentButtonsOnDisplay(void)
{
	
	// Button One
	FillRectangle(blueBnt.startX, blueBnt.startY, blueBnt.width, blueBnt.height, blueBnt.colorRed, blueBnt.colorGreen, blueBnt.colorBlue);

	// Button Two
	FillRectangle(greenBnt.startX, greenBnt.startY, greenBnt.width, greenBnt.height, greenBnt.colorRed, greenBnt.colorGreen, greenBnt.colorBlue);
}
