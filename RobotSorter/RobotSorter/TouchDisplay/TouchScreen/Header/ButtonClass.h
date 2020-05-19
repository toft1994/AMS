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
	// Default Constructor
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
	
	/**
	*    Constructor for Button class with will contain values for where button should be presented
	*    @param uint8_t Start X Coordinate
	*	 @param	uint8_t Start Y Coordinate
	*	 @param	uint16_t End X Coordinate
	*	 @param	uint8_t End Y Coordinate
	*	 @param	uint8_t Color Code for Red
	*	 @param	uint8_t Color Code for Blue
	*	 @param	uint8_t Color Code for Green
	*    @return ButtonClass, Object
	*/
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
	
	~ButtonClass()
	{	
	}
	
	/**
	*    Start X Position for the button on the screen
	*/
	uint8_t startX;
	
	/**
	*    Start Y Position for the button on the screen
	*/
	uint8_t startY;
	
	/**
	*    Height of the button. Calculated by startY and endY
	*/
	uint8_t height;
	
	/**
	*    Width of the button. Calculated by startX and endX
	*/
	uint8_t width;
	
	/**
	*    Color code for the red color (RGB)
	*/
	uint8_t colorRed;
	
	/**
	*    Color code for the blue color (RGB)
	*/
	uint8_t colorBlue;
	
	/**
	*    Color code for the green color (RGB)
	*/
	uint8_t colorGreen;
	
	/**
	*    End X Position for the button on the screen
	*/
	uint16_t endX;
	
	/**
	*    End Y Position for the button on the screen
	*/
	uint8_t endY;
		
};



#endif /* BUTTONCLASS_H_ */