/*
 * ButtonClass.h
 *
 * Created: 14-05-2020 10:25:19
 *  Author: MIKKELJENSEN
 */ 


#ifndef BUTTONCLASS_H_
#define BUTTONCLASS_H_

class ButtonClass
{
	
	public:
	ButtonClass()
	{
		startX = 0;
		startY = 0;
		height = 0;
		width = 0;
		colorRed = 0;
		colorBlue = 0;
		colorGreen = 0;
		endX = 0;
		endY = 0;
	}
	
	ButtonClass(uint8_t StartX, uint8_t StartY, uint16_t EndX, uint8_t EndY, uint8_t ColorRed, uint8_t ColorBlue, uint8_t ColorGreen)
	{
		startX = StartX;
		startY = StartY;
		endX = EndX;
		endY = EndY;
		width = EndX-StartX;
		height = EndY-StartY;
		colorRed = ColorRed;
		colorBlue = ColorBlue;
		colorGreen = ColorGreen;
	}
	
	uint8_t startX;
	uint8_t startY;
	uint8_t height;
	uint8_t width;
	uint8_t colorRed;
	uint8_t colorBlue;
	uint8_t colorGreen;
	uint16_t endX;
	uint8_t endY;
		
};



#endif /* BUTTONCLASS_H_ */