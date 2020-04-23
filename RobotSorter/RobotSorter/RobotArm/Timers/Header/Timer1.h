/*
 * Timer1.h
 *
 * Created: 12-03-2020 11:42:47
 *  Author: jespe
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include <stdint.h>

class Timer1
{
	public:
	Timer1();
	
	/**
	*    Sets the duty Timer 1 and outputs the PWM signal to the OC4A pin. 
	*    @param float dutyCycle
	*    @return void Nothing
	*/
	void setDutyCycleComA(float dutyCycle);
	
	/**
	*    Sets the duty Timer 1 and outputs the PWM signal to the OC4B pin. 
	*    @param float dutyCycle
	*    @return void Nothing
	*/
	void setDutyCycleComB(float dutyCycle);
	
	/**
	*    Sets the duty Timer 1 and outputs the PWM signal to the OC4C pin. 
	*    @param float dutyCycle
	*    @return void Nothing
	*/
	void setDutyCycleComC(float dutyCycle);
		
	private:
};

#endif /* TIMER1_H_ */