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

}; //M2

#endif //__M2_H__
