/*
* M3.h
*
* Created: 28-03-2020 22:07:08
* Author: jespe
*/


#ifndef __M3_H__
#define __M3_H__

#include "Motor.h"

class M3 : public Motor
{
	//functions
	public:
	M3( Timer1 * tmr );
	~M3();
	
	/**
	*    Turns motor a given amount until the desired position is achieved.
	*	  Note that this function needs to run multiple times to work as intended.
	*    @param void Nothing
	*    @return void Nothing
	*/
	void TurnMotor();
		
	protected:
	private:

}; //M3

#endif //__M3_H__
