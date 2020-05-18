/*
 * KeyPad.cpp
 *
 * Created: 26-03-2020 09:05:06
 *  Author: MIKKELJENSEN
 */ 

/*
 *	1_0 = PF3	ROW 1
 *	1_1 = PF4	ROW 2
 *	1_2 = PF2	ROW 3
 *	1_3 = PF5	ROW 4
 *	1_4 = PF1	COLOUMN 1
 *	1_5 = PF6	COLOUMN 2
 *	1_6 = PF0	COLOUMN 3
 *	1_7 = PF7	COLOUMN 4
 
 *	PF0 = COLOUMN 3
 *	PF1 = COLOUMN 1
 *	PF2 = ROW 3
 *	PF3 = ROW 1
 *	PF4 = ROW 2
 *	PF5 = ROW 4
 *	PF6 = COLOUMN 2
 *	PF7 = COLOUMN 4
 
 
 
 */

#include <stdlib.h>
#include <avr/io.h>
#include "KeyPad.h"

/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

 KeyPad::KeyPad()
{
}

char KeyPad::readKeyboard(){
	
	uint8_t read_byte = 0; // Bytes to contain pressed char
	DDRK = 0b11110000; // Configure for Columns to be output and row to be input
	PORTK = 0b11110000; // Set Columns output to be high!
	
	vTaskDelay(8/portTICK_RATE_MS);	// Delays for allowing Pins to switch state from input to output and reverse
	
	
	while( (PINK & 0b00001111) == 0 )	// Wait for key pressed
	{	
	}
	
	read_byte = (PINK & 0b00001111); // Get row of pressed key
	
	DDRK = 0b00001111; // Switch Columns to be input and row to be output
	PORTK = 0b00001111; // Set Row outputs to be high!
	
	vTaskDelay(8/portTICK_RATE_MS);
	
	//PORTA = 0;
	//DDRA = 0;
	char pressed_key = findKey(read_byte | (PINK & 0b11110000));
	
	// Wait for no key pressed anymore
	
	while((PINK & 0b11110000) != 0)
	{
	}
	
	return pressed_key;
}

char KeyPad::findKey(uint8_t pin_press)
{
	switch(pin_press) {
		
		case 0b01000010  :
			return '1';
		case 0b01001000  :
			return '2';
		case 0b01000001  :
			return '3';
		case 0b01000100  :
			return 'A';
			
		case 0b10000010  :
			return '4';
		case 0b10001000  :
			return '5';
		case 0b10000001  :
			return '6';
		case 0b10000100  :
			return 'B';
			
		case 0b00100010  :
			return '7';
		case 0b00101000  :
			return '8';
		case 0b00100001  :
			return '9';
		case 0b00100100  :
			return 'C';
			
		case 0b00010010  :
			return '*';
		case 0b00011000  :
			return '0';
		case 0b00010001  :
			return '#';
		case 0b00010100  :
			return 'D';
			
		
		// you can have any number of case statements.
		default : //Optional
			return 'E';
	}
}