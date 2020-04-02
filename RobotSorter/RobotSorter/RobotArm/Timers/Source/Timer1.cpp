/*
 * Timer1.cpp
 *
 * Created: 12-03-2020 11:44:02
 *  Author: jespe
 */ 

#include "Timer1.h"
#include <avr/io.h>

Timer1::Timer1()
{
	// Set B5 to output
	DDRB = DDRB | ( 1 << 5 ) | ( 1 << 6 ) | ( 1 << 7 );
	
	// Set timer to run in PWM, Phase Correct mode with 50 Hz freq. 
	TCCR1A = ( 1 << COM1A1 ) | ( 1 << COM1B1 ) | ( 1 << COM1C1 ) | ( 0 << WGM10 ) | ( 0 << WGM11 );
	TCCR1B = ( 1 << WGM13 ) | ( 0 << CS10 )  | ( 1 << CS12 );
	TCCR1C = 0;
	ICR1 = 622;
	
	OCR1A = 0;
	OCR1B = 0;
	OCR1C = 0;
}

void Timer1::setDutyCycleComA( float dutyCycle )
{
	volatile float percent = ICR1/100;
	OCR1A = (uint8_t)percent*dutyCycle;
}

void Timer1::setDutyCycleComB( float dutyCycle )
{
	volatile float percent = ICR1/100;
	OCR1B = (uint8_t)percent*dutyCycle;
}

void Timer1::setDutyCycleComC( float dutyCycle )
{
	volatile float percent = ICR1/100;
	OCR1C = (uint8_t)percent*dutyCycle;
}