/*
 * Timer4.cpp
 *
 * Created: 19-03-2020 20:21:37
 *  Author: jespe
 */ 

#include "../Header/Timer4.h"
#include <avr/io.h>

timer4::timer4()
{
	// Setup timer to normal mode and pre scaler to 1
	TCCR4A = ( 1 << COM4A1 ) | ( 1 << COM4C1 ) | ( 0 << WGM40 ) | ( 0 << WGM41 );
	TCCR4B = ( 1 << ICNC4 ) | ( 1 << ICES4 ) | ( 1 << CS41 ) | ( 1 << WGM33 );
	TCCR4C = 0U;
	ICR4 = 39999;
	
	// Clear flags and set counter to zero
	TIFR4 = ( 0 << ICF4 ) | ( 0 << TOV4 );
	TCNT4 = 0;

	DDRB = 0xff;
	// Dan maske på basis af parameteren (led_nr)
	uint8_t mask = 0b00000001 << 6;
	// Tænd den aktuelle lysdiode (de andre ændres ikke)
	PORTB = mask;
	OCR3A = 0;

	// Enable global interrupts
	sei();
}

void timer4::setDutyCycle( float dutyCycle )
{
	volatile float percent = ICR1/100;
	OCR1A = (uint8_t)percent*dutyCycle;
}