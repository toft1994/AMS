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
	
	void clearScreen(void);
	uint8_t checkButtons(void);
	void presentButtonsOnDisplay(void);
	
	private:
	
	TouchDriver TouchDriv;
	ButtonClass blueBnt;
	ButtonClass greenBnt;
	
};




#endif /* TOUCHSCREEN_H_ */