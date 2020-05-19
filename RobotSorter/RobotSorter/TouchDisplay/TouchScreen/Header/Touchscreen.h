/*
 * Touchscreen.h
 *
 * Created: 14-05-2020 10:01:17
 *  Author: MIKKELJENSEN
 */ 

#include "ButtonClass.h"
#include "TouchDriver.h"


#ifndef TOUCHSCREEN_H_
#define TOUCHSCREEN_H_

class Touchscreen
{
	
	public:
	Touchscreen();
	~Touchscreen();
	
	/**
	*    Will clear the screen of the display 
	*    @param Void, Nothing
	*    @return void, Nothing
	*/
	void clearScreen(void);
	
	/**
	*    Will check if any buttons has been pressed on the display.
	*    @param Void, Nothing
	*    @return uint8_t, Return value of what buttons has been pressed
	*/
	uint8_t checkButtons(void);
	
	/**
	*    Will present the buttons on the display
	*    @param Void, Nothing
	*    @return void, Nothing
	*/
	void presentButtonsOnDisplay(void);
	
	private:
	
	/**
	*    TouchDriver Object
	*/
	TouchDriver TouchDriv;
	/**
	*    Blue ButtonClass Object
	*/
	ButtonClass blueBnt;
	/**
	*    Green ButtonClass Object
	*/
	ButtonClass greenBnt;
	
};

#endif /* TOUCHSCREEN_H_ */