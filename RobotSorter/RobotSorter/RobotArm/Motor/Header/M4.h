/*
* M4.h
*
* Created: 28-03-2020 22:07:08
* Author: jespe
*/


#ifndef __M4_H__
#define __M4_H__

#include "Motor.h"

class M4 : public Motor
{
	public:
	M4( Timer5 * tmr );
	~M4();

	/**
	*    Turns motor a given amount until the desired position is achieved.
	*	  Note that this function needs to run multiple times to work as intended.
	*    @param void Nothing
	*    @return void Nothing
	*/
	void TurnMotor();
	
	protected:
	private:

}; //M4

#endif //__M4_H__
