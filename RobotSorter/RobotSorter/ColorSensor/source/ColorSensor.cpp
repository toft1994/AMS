/*
 * ColorSensor.cpp
 *
 * Created: 27-02-2020 09:23:26
 *  Author: jespe
 */ 

#include "../header/ColorSensor.h"
#include "../header/timer4.h"
#include <avr/io.h>

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
	//color result = error;
	
	volatile uint32_t redpwm = 0U;
	volatile uint32_t bluepwm = 0U;
	volatile uint32_t greenpwm = 0U;

	setFilter( redFilter );
	redpwm = frequency_.getPwm() - _backgroundBasis.getRedPwm();

	setFilter( blueFilter );
	bluepwm = frequency_.getPwm() - _backgroundBasis.getBluePwm();  

	setFilter( greenFilter );
	greenpwm = frequency_.getPwm() - _backgroundBasis.getGreenPwm();
	
	for ( uint8_t index = 0U; index < 10; index++)
	{
		uint32_t storedRed = _colors[index].getRedPwm();
		uint32_t storedBlue = _colors[index].getBluePwm();
		uint32_t storedGreen = _colors[index].getGreenPwm();		
		
		if ( storedRed + 5000 > redpwm && storedRed - 5000 < redpwm )
		{
			if ( storedBlue + 5000 > bluepwm && storedBlue - 5000 < bluepwm )
			{
				if ( storedGreen + 5000 > greenpwm && storedGreen - 5000 < greenpwm )
				{
					return index;
					break;
				}
			}
		}
	}

	return 255;
}

void ColorSensor::setBackgroundBasis( void )
{
	setFilter(redFilter);
	_backgroundBasis.setRedPwm( frequency_.getPwm() - 3000U );
	
	setFilter(blueFilter);
	_backgroundBasis.setBluePwm( frequency_.getPwm() - 3000U );
	
	setFilter(greenFilter);
	_backgroundBasis.setGreenPwm( frequency_.getPwm() - 3000U );
}

void ColorSensor::addCalibrateColor( uint8_t colorIndex )
{
	if ( colorIndex < 10U )
	{
		// Set all colors
		setFilter( redFilter );
		_colors[colorIndex].setRedPwm( frequency_.getPwm() - _backgroundBasis.getRedPwm() );

		setFilter( blueFilter );
		_colors[colorIndex].setBluePwm( frequency_.getPwm() - _backgroundBasis.getBluePwm() );
		
		setFilter( greenFilter );
		_colors[colorIndex].setGreenPwm( frequency_.getPwm() - _backgroundBasis.getGreenPwm() );
		
		// Set index
		_colors[colorIndex].setColorIndex(colorIndex);
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