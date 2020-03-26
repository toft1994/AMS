/*
 * Timer3.cpp
 *
 * Created: 19-03-2020 19:34:58
 *  Author: jespe
 */ 

#include "../Header/Timer3.h"
#include <avr/io.h>

timer3::timer3()
{
	// Set B5 to output
	DDRE = DDRE | ( 1 << 3 ) | ( 1 << 4 ) | ( 1 << 5 );
	
	// Set timer to run in PWM, Phase Correct mode with 50 Hz freq.
	TCCR3A = ( 1 << COM3A1 ) | ( 1 << COM3B1 ) | ( 1 << COM3C1 ) | ( 0 << WGM30 ) | ( 0 << WGM31 );
	TCCR3B = ( 1 << WGM33 ) | ( 0 << CS30 )  | ( 1 << CS32 );
	TCCR3C = 0;
	ICR3 = 622;
	
	OCR3A = 0;
	OCR3B = 0;
	OCR3C = 0;
}

void timer3::setDutyCycleComA( float dutyCycle )
{
	volatile float percent = ICR3/100;
	OCR3A = (uint8_t)percent*dutyCycle;
}

void timer3::setDutyCycleComB( float dutyCycle )
{
	volatile float percent = ICR3/100;
	OCR3B = (uint8_t)percent*dutyCycle;
}

void timer3::setDutyCycleComC( float dutyCycle )
{
	volatile float percent = ICR3/100;
	OCR3C = (uint8_t)percent*dutyCycle;
}