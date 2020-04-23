/*
 * Timer3.h
 *
 * Created: 19-03-2020 19:34:40
 *  Author: jespe
 */ 


#ifndef TIMER3_H_
#define TIMER3_H_

#include <stdint.h>

class Timer5
{
	public:
	Timer5();
	
	/**
	*    Sets the duty Timer 5 and outputs the PWM signal to the OC4A pin. 
	*    @param float dutyCycle
	*    @return void Nothing
	*/
	void setDutyCycleComA(float dutyCycle);
	
	/**
	*    Sets the duty Timer 5 and outputs the PWM signal to the OC4B pin. 
	*    @param float dutyCycle
	*    @return void Nothing
	*/
	void setDutyCycleComB(float dutyCycle);
	
	/**
	*    Sets the duty Timer 5 and outputs the PWM signal to the OC4C pin. 
	*    @param float dutyCycle
	*    @return void Nothing
	*/
	void setDutyCycleComC(float dutyCycle);
	
	private:
};

#endif /* TIMER3_H_ */