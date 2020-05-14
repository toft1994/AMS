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
		
	void getCoordinates(uint8_t *x_ptr, uint8_t *y_ptr);
	uint8_t readTouch(char);
	
	
	private:
	void initTouchDriver();
		
	uint8_t dinXByte;
	uint8_t dinYByte;
	
};






#endif /* TOUCHDRIVER_H_ */