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

}; //M3

#endif //__M3_H__
