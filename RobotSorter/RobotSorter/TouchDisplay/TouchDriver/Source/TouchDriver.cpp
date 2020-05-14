/*
 * TouchDriver.cpp
 *
 * Created: 30-04-2020 08:59:34
 *  Author: MIKKELJENSEN
 */ 
#define F_CPU 16000000
#include <avr/interrupt.h>
#include <avr/io.h>

#include "IO.h"
#include "TouchDriver.h"

/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

volatile uint8_t eIntHappend = 255;

/************************************************************************/
/* PIN LAYOUT                                                           */
/* PH3 = CLK															*/
/* PE3 = CS																*/
/* PG5 = DIN															*/
/* PE5 = DOUT															*/
/* PE4 = IRQ (Not Used)													*/
/************************************************************************/

TouchDriver::TouchDriver()
{
	initTouchDriver();
}


void TouchDriver::initTouchDriver()
{
	/************************************************************************/
	/* BIT 7		= S (Start Byte)                                        */
	/* BIT 6-4		= A2-A0 (Channel Select Bits)							*/
	/* BIT 3		= MODE (12bit/8bit Conversion Select Bit)				*/
	/* BIT 2		= SER/DFR (Single-Ended/Differentials Ref Select Bit)	*/
	/* BIT 1-0		= PD1/PD0 (Power-Down Mode Select Bits)					*/
	/************************************************************************/
	/************************************************************************/
	/* A2-A0:																*/
	/* (A2 = 0, A1 = 0, A0 = 1)		= Y-position                            */
	/* (A2 = 1, A1 = 0, A0 = 1)		= X-position							*/
	/* MODE							= 12bit = High							*/
	/* SER/DFR						= Differential = Low					*/
	/* PD1/PD0						= Device always powered = 11			*/
	/************************************************************************/
	
	dinXByte = 0b10011100;
	dinYByte = 0b11011100;
	
	DDRH |= BIT4;
	DDRE |= BIT4;
	DDRG |= BIT6;
	
	// Enable Interrupt
	EICRB = 00000010;
	EIMSK |= 0b00010000;
	
	sei();
	
}

ISR (INT4_vect)
{
	eIntHappend = 0;
}

void TouchDriver::getCoordinates(uint8_t *x_ptr, uint8_t *y_ptr)
{	
	while(eIntHappend != 0);
	
	*x_ptr = readTouch('X');
	*y_ptr = readTouch('Y');
	
	vTaskDelay( 50 / portTICK_RATE_MS );
	eIntHappend = 255;
	
}



uint8_t TouchDriver::readTouch(char coord)
{
	uint8_t delayTime = 8;
	uint8_t dinByte = 0;
	
	if (coord == 'X')
	{
		dinByte = dinXByte;
		
	}else if (coord == 'Y')
	{
		dinByte = dinYByte;
	}
	else{
		return 255;
	}
	
	// ChipSelect Set to 0	
	CS_PORT &= ~CS_PIN;
	vTaskDelay( delayTime / portTICK_RATE_MS );
	uint8_t result = 0;
	
	// DIN byte and pulse DCLK for Read X
	for (int i = 7; i >= 0; i--)
	{
		vTaskDelay( delayTime / portTICK_RATE_MS );
		
		DIN_PORT |= (((dinByte >> i)  & 0x01) << 5);
				
		CLK_PORT |= CLK_PIN;
		vTaskDelay( delayTime / portTICK_RATE_MS );		
		
		CLK_PORT &= ~CLK_PIN;
		DIN_PORT &= ~BIT6;
	}
			
	// Systematically read DOUT
	
	for (int i = 7; i >= 0; i--)
	{
		vTaskDelay( delayTime / portTICK_RATE_MS );
		
		CLK_PORT |= CLK_PIN;
		vTaskDelay( delayTime / portTICK_RATE_MS );
		
		CLK_PORT &= ~CLK_PIN;
		//_delay_us(1); IS THIS NEEDED MIKKEL?
		
		bool temp = (PINE & (1U << 5));
		
		// Check this
		result |= (temp << i);
	}
	
	for (int i = 7; i >= 0; i--)
	{
		vTaskDelay( delayTime / portTICK_RATE_MS );		CLK_PORT |= CLK_PIN;
		CLK_PORT &= ~CLK_PIN;
		// Check this
	}
	
	CS_PORT |= CS_PIN;
		
	return ~result;
} 