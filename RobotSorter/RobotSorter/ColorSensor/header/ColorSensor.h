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

typedef enum FrequencyScaling
{
	powerDown,
	twoPercent,
	twentyPercent,
	hundredPercent,	
};

typedef enum Filter
{
	noFilter,
	redFilter,
	greenFilter,
	blueFilter,
};

class ColorSensor
{
//variables
public:
protected:
private:
	timer4 frequency_;
	Color _colors[10];
	Color _backgroundBasis;
	
//functions
public:
	ColorSensor( FrequencyScaling scaling );
	~ColorSensor();
	uint8_t getColor( void );
	void addCalibrateColor( uint8_t colorIndex );
	void setBackgroundBasis( void );
protected:
private:
	void setFilter( Filter filter );
	void setFrequencyscaling( FrequencyScaling scaling );
};

#endif /* COLORSENSOR_H_ */