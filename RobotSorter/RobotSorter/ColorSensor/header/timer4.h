/*
 * timer1.h
 *
 * Created: 27-02-2020 10:45:41
 *  Author: jespe
 */ 

#include <stdint.h>

#ifndef TIMER4_H_
#define TIMER4_H_

class timer4
{
	public:
	timer4();
	
	/**
	*    Reads the period of the PWM signal from sensor and returns it.
	*    @param void 
	*    @return uint16_t	period of PWM signal
	*/
	uint16_t getPeriod( void );
	
	private:
};

#endif /* TIMER4_H_ */