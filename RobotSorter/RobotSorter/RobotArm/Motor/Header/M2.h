/*
* M2.h
*
* Created: 28-03-2020 22:07:08
* Author: jespe
*/


#ifndef __M2_H__
#define __M2_H__

#include "Motor.h"

class M2 : public Motor
{
	//functions
	public:
	M2( Timer1 * tmr );
	~M2();
	
	/**
	*    Turns motor a given amount until the desired position is achieved.
	*	  Note that this function needs to run multiple times to work as intended.
	*    @param void Nothing
	*    @return void Nothing
	*/
	void TurnMotor();
	
	protected:
	private:

}; //M2

#endif //__M2_H__
