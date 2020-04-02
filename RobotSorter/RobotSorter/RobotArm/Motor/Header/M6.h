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
	M6( Timer3 * tmr );
	~M6();
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

}; //M6

#endif //__M6_H__
