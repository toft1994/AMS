/*
 * TouchDriver.h
 *
 * Created: 30-04-2020 08:59:52
 *  Author: MIKKELJENSEN
 */ 


#ifndef TOUCHDRIVER_H_
#define TOUCHDRIVER_H_

class TouchDriver
{
	
	public:
	TouchDriver();
	~TouchDriver();
	
	/**
	*    Get the coordinates pressed on the touch display 
	*    @param uint8_t* x coordinate uint8_t* y coordinate
	*    @return void, uses call by reference to param 
	*/
	void getCoordinates(uint8_t *x_ptr, uint8_t *y_ptr);
	
	/**
	*    Will read the x or y coordinate on touch display.  
	*    @param char, X or Y. if different will return 255.
	*    @return uint8_t, byte containing the row and column pressed
	*/
	uint8_t readTouch(char);
	
	private:
	/**
	*    Will initiate all the ports and variables needed
	*    @param void, nothing
	*    @return void, nothing
	*/
	void initTouchDriver();
	
	/**
	*    DIN byte for getting X Coordinate
	*/
	uint8_t dinXByte;
	/**
	*    DIN byte for getting Y Coordinate
	*/
	uint8_t dinYByte;
	
};

#endif /* TOUCHDRIVER_H_ */