/*
 * ColorSensor.h
 *
 * Created: 27-02-2020 09:23:12
 *  Author: jespe
 */ 

#include <stdint.h>
#include "timer4.h"
#include "../../IO.h"

#ifndef COLORSENSOR_H_
#define COLORSENSOR_H_

enum FrequencyScaling
{
	powerDown,
	twoPercent,
	twentyPercent,
	hundredPercent,	
};

enum color
{
	red,
	green,
	blue,
	error,
};

enum filter
{
	noFilter,
	redFilter,
	greenFilter,
	blueFilter,
};

class ColorSensor
{
	public:
	ColorSensor();
	color getColor( void );
	
	private:
	void setFilter( filter filter_ );
	void setFrequencyscaling( FrequencyScaling scaling );

	timer4 frequency_;
};

#endif /* COLORSENSOR_H_ */