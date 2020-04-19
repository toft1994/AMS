/*
 * ColorSensor.cpp
 *
 * Created: 27-02-2020 09:23:26
 *  Author: jespe
 */ 

#include "ColorSensor.h"
#include "timer4.h"
#include <avr/io.h>

#include "uart.h"

/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

// default constructor
ColorSensor::ColorSensor( FrequencyScaling scaling )
{
	DDRC = 0xFF;
	DDRD = 0x00;
	frequency_ = timer4();

	setFilter( noFilter );
	setFrequencyscaling( scaling );
}

// default destructor
ColorSensor::~ColorSensor()
{	
}

uint8_t ColorSensor::getColor()
{
	setFilter( redFilter );
	uint16_t redPeriod = frequency_.getPeriod();

	setFilter( blueFilter );
	uint16_t bluePeriod = frequency_.getPeriod();  

	setFilter( greenFilter );
	uint16_t greenPeriod = frequency_.getPeriod();
	
	setFilter( noFilter );
	uint16_t whitePeriod = frequency_.getPeriod();
	
	//SendString("RedPeriod: ");
	//SendInteger((int)redPeriod);
	//SendString("\n\r\n\r");
	//
	//SendString("BluePeriod: ");
	//SendInteger((int)bluePeriod);
	//SendString("\n\r\n\r");
	//
	//SendString("GreenPeriod: ");
	//SendInteger((int)greenPeriod);
	//SendString("\n\r\n\r");
	//
	//SendString("NoFilter: ");
	//SendInteger((int)whitePeriod);
	//SendString("\n\r\n\r");
	
	for ( uint8_t index = 0U; index < 10; index++)
	{
		uint16_t storedRed = _colors[index].getRedPeriod();
		uint16_t storedBlue = _colors[index].getBluePeriod();
		uint16_t storedGreen = _colors[index].getGreenPeriod();		
		uint16_t storedWhite = _colors[index].getWhitePeriod();
		
		if ( storedRed + 20 > redPeriod && storedRed - 20 < redPeriod )
		{
			if ( storedBlue + 20 > bluePeriod && storedBlue - 20 < bluePeriod )
			{
				if ( storedGreen + 20 > greenPeriod && storedGreen - 20 < greenPeriod )
				{
					if ( storedWhite + 100 > whitePeriod && storedWhite - 100 < whitePeriod )
					{
						return index;
						break;
					}
				}
			}
		}
	}

	return 255;
}

void ColorSensor::addCalibrateColor( uint8_t colorIndex )
{
	if ( colorIndex < 10U )
	{
		uint16_t period = 0;
		
		// Set all colors
		setFilter( redFilter );
		while( period == 0 )
		{
			period = frequency_.getPeriod();
		}
		_colors[colorIndex].setRedPeriod( period );
		period = 0;

		setFilter( blueFilter );
		while( period == 0 )
		{
			period = frequency_.getPeriod();
		}
		_colors[colorIndex].setBluePeriod( period );
		period = 0;
		
		setFilter( greenFilter );
		while( period == 0 )
		{
			period = frequency_.getPeriod();
		}
		_colors[colorIndex].setGreenPeriod( period );
		
		setFilter( noFilter );
		while( period == 0 )
		{
			period = frequency_.getPeriod();
		}
		_colors[colorIndex].setWhitePeriod( period );
		
		// Set index
		_colors[colorIndex].setColorIndex(colorIndex);
		
		//SendString("RedPeriod: ");
		//SendInteger((int)_colors[colorIndex].getRedPeriod());
		//SendString("\n\r\n\r");
		//
		//SendString("BluePeriod: ");
		//SendInteger((int)_colors[colorIndex].getBluePeriod());
		//SendString("\n\r\n\r");
		//
		//SendString("GreenPeriod: ");
		//SendInteger((int)_colors[colorIndex].getGreenPeriod());
		//SendString("\n\r\n\r");
		//
		//SendString("NoFilter: ");
		//SendInteger((int)_colors[colorIndex].getWhitePeriod());
		//SendString("\n\r\n\r");
	}
	else
	{
		/* Cant add more colors. Increase size of array. */
	}
}

void ColorSensor::setFilter( Filter filter_ )
{
	switch ( filter_ )
	{
	case redFilter:
		COLORSENSOR_S2_PORT &= ~( COLORSENSOR_S2_PIN );
		COLORSENSOR_S3_PORT &= ~( COLORSENSOR_S3_PIN );
		break;

	case blueFilter:
		COLORSENSOR_S2_PORT &= ~( COLORSENSOR_S2_PIN );
		COLORSENSOR_S3_PORT |= COLORSENSOR_S3_PIN;
		break;

	case greenFilter:
		COLORSENSOR_S2_PORT |= COLORSENSOR_S2_PIN;
		COLORSENSOR_S3_PORT |= COLORSENSOR_S3_PIN;
		break;

	case noFilter:
		COLORSENSOR_S2_PORT |= COLORSENSOR_S2_PIN;
		COLORSENSOR_S3_PORT &= ~( COLORSENSOR_S3_PIN );
		break;
	default:
		/* Do nothing! */
		break;
	}	
}

void ColorSensor::setFrequencyscaling( FrequencyScaling scaling )
{
	switch (scaling)
	{
	case powerDown:
		COLORSENSOR_S0_PORT &= ~( COLORSENSOR_S0_PIN );
		COLORSENSOR_S1_PORT &= ~( COLORSENSOR_S1_PIN );
		break;

	case twoPercent:
		COLORSENSOR_S0_PORT &= ~( COLORSENSOR_S0_PIN );
		COLORSENSOR_S1_PORT |= COLORSENSOR_S1_PIN;
		break;

	case twentyPercent:
		COLORSENSOR_S0_PORT |= COLORSENSOR_S0_PIN;
		COLORSENSOR_S1_PORT &= ~( COLORSENSOR_S1_PIN );
		break;

	case hundredPercent:
		COLORSENSOR_S0_PORT |= COLORSENSOR_S0_PIN;
		COLORSENSOR_S1_PORT |= COLORSENSOR_S1_PIN;
		break;
	default:
		/* Do nothing! */
		break;
	}
}