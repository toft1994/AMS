/*
* M6.h
*
* Created: 28-03-2020 22:07:08
* Author: jespe
*/


#ifndef __M6_H__
#define __M6_H__

#include "Motor.h"

class M6 : public Motor
{
	//functions
	public:
	M6( Timer5 * tmr );
	~M6();
	
	/**
	*    Turns motor a given amount until the desired position is achieved.
	*	  Note that this function needs to run multiple times to work as intended.
	*    @param void
	*    @return void
	*/
	void TurnMotor();
	
	protected:
	private:

}; //M6

#endif //__M6_H__
