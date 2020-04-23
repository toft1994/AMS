/*
 * timer1.h
 *
 * Created: 27-02-2020 10:45:41
 *  Author: jespe
 */ 

#include <stdint.h>

#ifndef TIMER4_H_
#define TIMER4_H_

class Timer4
{
	public:
	Timer4();
	
	/**
	*    Reads the period of the PWM signal from sensor and returns it.
	*    @param void Nothing
	*    @return uint16_t period of PWM signal
	*/
	uint16_t getPeriod( void );
	
	private:
};

#endif /* TIMER4_H_ */