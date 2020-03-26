/*
 * Timer1.h
 *
 * Created: 12-03-2020 11:42:47
 *  Author: jespe
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include <stdint.h>

class timer1
{
	public:
	timer1();
	void setDutyCycleComA(float dutyCycle);
	void setDutyCycleComB(float dutyCycle);
	void setDutyCycleComC(float dutyCycle);
		
	private:
};

#endif /* TIMER1_H_ */