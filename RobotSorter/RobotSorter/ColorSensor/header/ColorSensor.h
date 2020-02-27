/*
 * ColorSensor.h
 *
 * Created: 27-02-2020 09:23:12
 *  Author: jespe
 */ 


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
	red,
	green,
	blue,
};

class ColorSensor
{
	public:
	ColorSensor();
	color getColor( void );
	
	private:
	void setFilter( uint8_t filter );
	void setFrequencyscaling( FrequencyScaling scaling );
};

#endif /* COLORSENSOR_H_ */