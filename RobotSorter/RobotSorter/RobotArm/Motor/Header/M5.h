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
	M5( Timer3 * tmr );
	~M5();
	virtual void TurnMotor();
	
	/* These functions are needed for some reason - Otherwise inheratence wont work */
	void * operator new( size_t n )
	{
		void * const p = malloc( n );
		return p;
	}

	void operator delete( void * p ) // or delete(void *, std::size_t)
	{
		free( p );
	}
	protected:
	private:

}; //M5

#endif //__M5_H__
