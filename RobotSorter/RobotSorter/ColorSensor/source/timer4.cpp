/*
 * timer1.cpp
 *
 * Created: 27-02-2020 10:45:54
 *  Author: jespe
 */ 

#include "timer4.h"
#include "IO.h"
#include <avr/interrupt.h>

volatile uint32_t oldValue = 0U;
volatile uint32_t timeroverflow = 0U;
volatile uint16_t period = 0U;
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

#include "uart.h"
/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"
uint16_t timer4::getPeriod( void )
{
	// Reset all needed values
	first = true;
	oldValue = 0U;
	period = 0U;
	timeroverflow = 0;
	
	// Enable interrupt and clear pending
	TIFR4 = ( 0 << ICF4 ) | ( 0 << TOV4 );	
	TIMSK4 = ( 1 << ICIE4 ) | ( 0 << TOIE4 );	
	
	// Wait until measurement has been taken
	uint8_t timeout = 0U;
	while ( period == 0U )
	{
		if ( timeout > 5U )
		{
			// Disable interrupt and clear pending
			TIMSK4 = 0U;
			TIFR4 = 0U;
			break;
		}
		
		// Delay for timeout
		vTaskDelay( 1 / portTICK_RATE_MS );

		// Increment timeout
		timeout++;
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
		
	// Disable interrupt and clear pending
	TIMSK4 = 0U;	
	TIFR4 = 0U;		
			
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