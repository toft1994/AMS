/*
 * KeyPad.cpp
 *
 * Created: 26-03-2020 09:05:06
 *  Author: MIKKELJENSEN
 */ 
#define F_CPU 16000000

#include <stdlib.h>
#include <util/delay.h>
#include <avr/io.h>
#include "KeyPad.h"
#include "uart.h"


KeyPad::KeyPad()
{
	InitUART(9600, 8, 'N');
}

char KeyPad::readKeyboard(){
	
	uint8_t read_byte = 0; // Bytes to contain pressed char
	DDRA = 0b11110000; // Configure for Columns to be output and row to be input
	PORTA = 0b11110000; // Set Columns output to be high!
	
	_delay_ms(4);	// Delays for allowing Pins to switch state from input to output and reverse
	
	while( (PINA & 0b00001111) == 0 )	// Wait for key pressed
	{	
	}
	
	read_byte = (PINA & 0b00001111); // Get row of pressed key
	
	DDRA = 0b00001111; // Switch Columns to be input and row to be output
	PORTA = 0b00001111; // Set Row outputs to be high!
	
	_delay_ms(4);
	
	//PORTA = 0;
	//DDRA = 0;
	
	return findKey(read_byte | (PINA & 0b11110000)); // read_byte 
}

char KeyPad::findKey(uint8_t pin_press)
{
	switch(pin_press) {
		
		case 0b00010001  :
			return '1';
		case 0b00100001  :
			return '2';
		case 0b01000001  :
			return '3';
		case 0b10000001  :
			return 'A';
			
		case 0b00010010  :
			return '4';
		case 0b00100010  :
			return '5';
		case 0b01000010  :
			return '6';
		case 0b10000010  :
			return 'B';
			
		case 0b00010100  :
			return '7';
		case 0b00100100  :
			return '8';
		case 0b01000100  :
			return '9';
		case 0b10000100  :
			return 'C';
			
		case 0b00011000  :
			return '*';
		case 0b00101000  :
			return '0';
		case 0b01001000  :
			return '#';
		case 0b10001000  :
			return 'D';
			
		
		// you can have any number of case statements.
		default : //Optional
			return 'E';
	}
}

