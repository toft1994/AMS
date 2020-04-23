/*
 * ColorSensor.cpp
 *
 * Created: 27-02-2020 09:23:26
 *  Author: jespe
 */ 

#include "ColorSensor.h"
#include "timer4.h"
#include <avr/io.h>

/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

// default constructor
ColorSensor::ColorSensor( FrequencyScaling scaling )
{
	// DE HER SKAL ÆNDRES!!!
	// Set ports to the right values.
	DDRC = 0xFF;
	DDRD = 0x00;
	frequency_ = Timer4();

	// Set default filter and scaling
	setFilter( noFilter );
	setFrequencyscaling( scaling );
}

// default destructor
ColorSensor::~ColorSensor()
{	
}

uint8_t ColorSensor::getColor()
{
	// Get period values from all filters
	setFilter( redFilter );
	uint16_t redPeriod = frequency_.getPeriod();

	setFilter( blueFilter );
	uint16_t bluePeriod = frequency_.getPeriod();  

	setFilter( greenFilter );
	uint16_t greenPeriod = frequency_.getPeriod();
	
	// Check all stored colors against read values	
	for ( uint8_t index = 0U; index < 10; index++)
	{
		//uint16_t storedRed = _colors[index].getRedPeriod();
		//uint16_t storedBlue = _colors[index].getBluePeriod();
		//uint16_t storedGreen = _colors[index].getGreenPeriod();		
		
		if ( _colors[index].getRedPeriod() + 10 > redPeriod && _colors[index].getRedPeriod() - 10 < redPeriod )
		{
			if ( _colors[index].getBluePeriod() + 10 > bluePeriod && _colors[index].getBluePeriod() - 10 < bluePeriod )
			{
				if ( _colors[index].getGreenPeriod() + 10 > greenPeriod && _colors[index].getGreenPeriod() - 10 < greenPeriod )
				{
					return index;
				}
			}
		}
	}
	
	// Return default value
	return 255;
}

void ColorSensor::addCalibrateColor( uint8_t colorIndex )
{
	if ( colorIndex < 10U )
	{	
		// Set all colors
		setFilter( redFilter );
		_colors[colorIndex].setRedPeriod( frequency_.getPeriod() );

		setFilter( blueFilter );
		_colors[colorIndex].setBluePeriod( frequency_.getPeriod() );
		
		setFilter( greenFilter );
		_colors[colorIndex].setGreenPeriod( frequency_.getPeriod() );
				
		// Set index
		_colors[colorIndex].setColorIndex( colorIndex );
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