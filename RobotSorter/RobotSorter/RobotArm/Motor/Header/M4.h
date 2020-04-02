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
	//functions
	public:
	M4( Timer3 * tmr );
	~M4();
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

}; //M4

#endif //__M4_H__
