/*
 * ColorSensor.h
 *
 * Created: 27-02-2020 09:23:12
 *  Author: jespe
 */ 

#include <stdint.h>
#include "timer4.h"
#include "IO.h"
#include "Color.h"

#ifndef COLORSENSOR_H_
#define COLORSENSOR_H_

enum FrequencyScaling
{
	powerDown,
	twoPercent,
	twentyPercent,
	hundredPercent,	
};

enum Filter
{
	noFilter,
	redFilter,
	greenFilter,
	blueFilter,
};

class ColorSensor
{

	public:
	ColorSensor( FrequencyScaling scaling );
	~ColorSensor();
	
	/**
	*    Reads color of object placed in front of color sensor and returns
	*	 the specific color index.
	*    @param void Nothing
	*    @return uint8_t index of color. 
	*/
	uint8_t getColor( void );
	
	/**
	*    Adds color of object placed in front of color sensor to list of 
	*	 known colors. If the object is placed in front of color sensor again
	*	 and \ref getColor is called the color index will be returned. 
	*    @param uint8_t	Specific index for color
	*    @return void Nothing
	*/	
	void addCalibrateColor( uint8_t colorIndex );
	
	private:
	void setFilter( Filter filter );
	void setFrequencyscaling( FrequencyScaling scaling );
	
	/**
	* Instance of \ref Timer4 used to capture the period of the
	* duty cycle from the color sensor. 
	*/
	Timer4 frequency_;
	
	/**
	* Array of \ref Color instances to store colors read from sensor. 
	* These values will be used to check if the read color is the 
	* same as the stored color
	*/
	Color _colors[10];
};

#endif /* COLORSENSOR_H_ */