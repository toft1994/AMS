/*
* M1.h
*
* Created: 28-03-2020 22:07:08
* Author: jespe
*/


#ifndef __M1_H__
#define __M1_H__

#include "Motor.h"

class M1 : public Motor
{
	//functions
	public:
	M1(Timer1 * tmr);
	~M1();
	void TurnMotor();
	M1( const M1 &c );
	M1& operator=( const M1 &c );
	
	/* These functions are needed for some reason - Otherwise inheratence wont work */
	void * operator new(size_t n)
	{
		void * const p = malloc(n);
		return p;
	}

	void operator delete(void * p)
	{
		if ( p != NULL )
		{
			free(p);
		}
	}
	protected:
	private:

}; //M1

#endif //__M1_H__
