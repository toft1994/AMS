/*
 * Timer5.cpp
 *
 * Created: 19-03-2020 19:34:58
 *  Author: jespe
 */ 

#include "Timer5.h"
#include <avr/io.h>

Timer5::Timer5()
{
	// Set B5 to output
	DDRL = DDRL | ( 1 << 3 ) | ( 1 << 4 ) | ( 1 << 5 );
	
	// Set timer to run in PWM, Phase Correct mode with 50 Hz freq.
	TCCR5A = ( 1 << COM3A1 ) | ( 1 << COM3B1 ) | ( 1 << COM3C1 ) | ( 0 << WGM30 ) | ( 0 << WGM31 );
	TCCR5B = ( 1 << WGM33 ) | ( 0 << CS30 )  | ( 1 << CS32 );
	TCCR5C = 0;
	ICR5 = 622;
	
	OCR5A = 0;
	OCR5B = 0;
	OCR5C = 0;
}

void Timer5::setDutyCycleComA( float dutyCycle )
{
	float percent = ICR5/100;
	OCR5A = (uint8_t)percent*dutyCycle;
}

void Timer5::setDutyCycleComB( float dutyCycle )
{
	float percent = ICR5/100;
	OCR5B = (uint8_t)percent*dutyCycle;
}

void Timer5::setDutyCycleComC( float dutyCycle )
{
	float percent = ICR5/100;
	OCR5C = (uint8_t)percent*dutyCycle;
}