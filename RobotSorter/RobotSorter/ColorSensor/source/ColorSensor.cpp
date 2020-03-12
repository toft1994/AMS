/*
 * ColorSensor.cpp
 *
 * Created: 27-02-2020 09:23:26
 *  Author: jespe
 */ 

#include "../header/ColorSensor.h"
#include <avr/io.h>

ColorSensor::ColorSensor()
{
	DDRC = 0xFF;
	DDRD = 0x00;
	frequency_ = timer4();

	setFilter( noFilter );
	setFrequencyscaling( twentyPercent );
}

color ColorSensor::getColor()
{
	color result = error;
	
	volatile uint16_t redpwm = 0U;
	volatile uint16_t bluepwm = 0U;
	volatile uint16_t greenpwm = 0U;

	setFilter( redFilter );
	redpwm = frequency_.getPwm();

	setFilter( blueFilter );
	bluepwm = frequency_.getPwm();

	setFilter( greenFilter );
	greenpwm = frequency_.getPwm();

	if ( redpwm > bluepwm && redpwm > greenpwm )
	{
		result = red;
	}
	else if ( bluepwm > redpwm && redpwm > greenpwm )
	{
		result = blue;
	}
	else if ( greenpwm > bluepwm && greenpwm > redpwm )
	{
		result = green;
	}

	return result;
}

void ColorSensor::setFilter( filter filter_ )
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