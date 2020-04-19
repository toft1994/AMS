/*
* M1.h
*
* Created: 28-03-2020 22:07:08
* Author: jespe
*/


#ifndef __M1_H__
#define __M1_H__

#include "Motor.h"

class M1 : public Motor
{
	//functions
	public:
	M1(Timer1 * tmr);
	~M1();
	
	/**
	*    Turns motor a given amount until the desired position is achieved.
	*	 Note that this function should be run from a task along with all the other motors
	*	 and it needs to run multiple times to work as intended.
	*    @param void
	*    @return void
	*/
	void TurnMotor();
	
	protected:
	private:

}; //M1

#endif //__M1_H__
