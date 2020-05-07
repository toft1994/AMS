/*
 * timer1.cpp
 *
 * Created: 27-02-2020 10:45:54
 *  Author: jespe
 */ 

#include "Timer4.h"
#include "IO.h"
#include <avr/interrupt.h>

/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

/** 
* The previews value read from sensor. 
*/
volatile uint16_t oldValue = 0U;

/**
* Overflow counter to be able to handle duty cycles below 200 Hz.
*/
volatile uint32_t timeroverflow = 0U;

/**
* The resulting duty cycle from the sample. 
*/ 
volatile uint16_t period = 0U;

/** 
* Indicator if its the first rising edge or not. 
*/ 
volatile bool first = true;

// No scale
//volatile float tick = 0.0000000625;

// 8 scale
//volatile float tick = 0.0000005;

// 64 scale
volatile float tick = 0.000004;

// 256 scale
//volatile float tick = 0.000016;

// 1024 scale
//volatile float tick = 0.000064;

Timer4::Timer4()
{
	// Setup timer to normal mode and pre scaler to 64
	TCCR4A = 0U;
	TCCR4B = ( 1 << ICNC4 ) | ( 1 << ICES4 ) | ( 1 << CS40 ) | ( 1 << CS41 );
	TCCR4C = 0U;
	
	// Clear flags and set counter to zero
	TIFR4 = ( 1 << ICF4 ) | ( 1 << TOV4 );
	TCNT4 = 0;        

	// Enable global interrupts
    sei();
}

uint16_t Timer4::getPeriod( void )
{
	// Reset all needed values
	first = true;
	oldValue = 0U;
	period = 0U;
	timeroverflow = 0;
	
	// Enable interrupt and clear pending
	TIFR4 = ( 1 << ICF4 ) | ( 1 << TOV4 );
	TIMSK4 = ( 1 << ICIE4 ) | ( 1 << TOIE4 );	
	
	// Wait until measurement has been taken
	while ( period == 0U )
	{
		if ( timeroverflow > 10U )
		{
			// Error - Disable interrupt and clear pending
			TIMSK4 = 0U;
			TIFR4 = ( 1 << ICF4 ) | ( 1 << TOV4 );
			break;
		}
	}
	
	return period;
}

ISR(TIMER4_OVF_vect)
{
	timeroverflow++;
}

ISR(TIMER4_CAPT_vect)
{
	// Read value of timer
	uint16_t readValue = ICR4;

	if ( first == true )
	{
		timeroverflow = 0U;
		oldValue = readValue;
		first = false;
		return;
	}
	
	// Check if overflow is pending
	if ( TIFR4 & ( 1 << TOV4 ))
	{
		timeroverflow++;
	}
		
	// Disable interrupt and clear pending
	TIMSK4 = 0U;	
	TIFR4 = ( 1 << ICF4 ) | ( 1 << TOV4 );		
			
	// Calculate difference
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
	
	// Calculate period
	period = diff * tick * 1000000;
}