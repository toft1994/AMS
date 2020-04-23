/*
* M5.h
*
* Created: 28-03-2020 22:07:08
* Author: jespe
*/


#ifndef __M5_H__
#define __M5_H__

#include "Motor.h"

class M5 : public Motor
{
	//functions
	public:
	M5( Timer5 * tmr );
	~M5();
	
	/**
	*    Turns motor a given amount until the desired position is achieved.
	*	  Note that this function needs to run multiple times to work as intended.
	*    @param void Nothing
	*    @return void Nothing
	*/
	void TurnMotor();
	
	protected:
	private:

}; //M5

#endif //__M5_H__
