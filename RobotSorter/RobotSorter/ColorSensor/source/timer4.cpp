/*
 * timer1.cpp
 *
 * Created: 27-02-2020 10:45:54
 *  Author: jespe
 */ 

#include "../header/timer4.h"
#include "../../IO.h"
#include <avr/interrupt.h>

volatile unsigned long oldValue = 0U;
volatile unsigned long timeroverflow = 0U;
volatile float freq = 0U;
volatile bool first = true;

// No scale
volatile float tick = 0.0000000625;

// 8 scale
//volatile float tick = 0.0000005;

// 64 scale
//volatile float tick = 0.000004;

// 256 scale
//volatile float tick = 0.000016;

// 1024 scale
//volatile float tick = 0.000064;

timer4::timer4()
{
	// Setup timer to normal mode and pre scaler to 1
	TCCR4A = 0U;
	TCCR4B = ( 1 << ICNC4 ) | ( 1 << ICES4 ) | ( 1 << CS40 );
	TCCR4C = 0U;
	
	// Clear flags and set counter to zero
	TIFR4 = ( 0 << ICF4 ) | ( 0 << TOV4 );
	TCNT4 = 0;        

	// Enable global interrupts
    sei();
}

float timer4::getPwm( void )
{
	// Reset all needed values
	first = true;
	oldValue = 0U;
	freq = 0U;
	
	// Enable interrupt and clear pending
	TIFR4 = ( 0 << ICF4 ) | ( 0 << TOV4 );	
	TIMSK4 = ( 1 << ICIE4 ) | ( 1 << TOIE4 );	
	
	// Wait until measurement has been taken
	while ( freq == 0 )
	{}
	
	return freq;
}

ISR(TIMER4_OVF_vect)
{
	timeroverflow++;
}

ISR(TIMER4_CAPT_vect, ISR_BLOCK)
{
	uint16_t readValue = ICR4;

	if ( first == true )
	{
		timeroverflow = 0U;
		oldValue = readValue;
		first = false;
		TIFR4 = 1;
		return;
	}
	
	// Disable interrupt and clear pending
	TIMSK4 = 0U;	
	TIFR4 = 0U;		
			
	uint32_t diff = 0U;

	if ( readValue < oldValue )
	{
		if ( timeroverflow != 0 )
		{
			timeroverflow--;
		}
		diff = ( 0xFFFF - oldValue ) + readValue;
	}
	else
	{
		diff = readValue - oldValue;
	}
	
	// Add timeroverflow to total diff
	diff += timeroverflow << 16U;
	
	// Calculate frequency
	freq = 1 / ( (float)diff * tick );
	
	// Reset timeroverflow and old value
	timeroverflow = 0U;
	oldValue = 0U;
}