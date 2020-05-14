/************************************************************
  File name: "TFTdriver.c"

  Driver for "ITDB02 320 x 240 TFT display module, Version 2"
  mounted at "ITDB02 Arduino Mega2560 Shield".
  Display controller = ILI 9341.
  
  Max. uC clock frequency = 16 MHz (Tclk = 62,5 ns)

  Connections:
  DB15-DB8:   PORT A
  DB7-DB0:    PORT C

  RESETx:     PORT G, bit 0
  CSx:        PORT G, bit 1
  WRx:        PORT G, bit 2
  RS (=D/Cx): PORT D, bit 7

  Henning Hargaard, February 14, 2019
************************************************************/  
#include <avr/io.h> 
#include <avr/cpufunc.h>

#include "TFTdriver.h"
#include "IO.h"

/* RTOS include */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

// LOCAL FUNCTIONS /////////////////////////////////////////////////////////////

// ILI 9341 data sheet, page 238
void WriteCommand(unsigned int command)
{
	// Set DC port to command
	DC_PORT &= ~(1 << DC_BIT);
	
	// Set chip select to high - Then wait min 15 ns for chip select setup.
	CS_PORT_Dispay &= ~(1 << CS_BIT);	
	_NOP();
	
	// Set databus
	DATA_PORT_HIGH = command >> 8U;
	DATA_PORT_LOW = command;
	
	//Set WR port to 0 to start transmission - wait 15 nano sec - Set WR port to 1 to end transmission. 
	WR_PORT &= ~(1 << WR_BIT);
	_NOP();
	WR_PORT |= (1 << WR_BIT);
	_NOP();
	
	// Set chip select to low
	CS_PORT_Dispay |= (1 << CS_BIT);
}

// ILI 9341 data sheet, page 238
void WriteData(unsigned int data)
{
	// Set DC port to data
	DC_PORT |= (1 << DC_BIT);
	
	// Set chip select to high - Then wait min 15 ns for chip select setup. 
	CS_PORT_Dispay &= ~(1 << CS_BIT);
	_NOP();
		
	// Set databus
	DATA_PORT_HIGH = data >> 8U;
	DATA_PORT_LOW = data;
	
	//Set WR port to 0 to start transmission - wait 15 nano sec - Set WR port to 1 to end transmission.
	WR_PORT &= ~(1 << WR_BIT);
	_NOP();
	WR_PORT |= (1 << WR_BIT);
	_NOP();
	
	// Set chip select to low
	CS_PORT_Dispay |= (1 << CS_BIT);
}

// PUBLIC FUNCTIONS ////////////////////////////////////////////////////////////

// Initializes (resets) the display
void DisplayInit()
{
	// Control pins are outputs
	DDRG |= 0b00000111;
	DDRD |= 0b10000000;
	
	// Data pins are outputs
	DDRA = 0xFF;
	DDRC = 0xFF;
	
	// All control pins high;
	PORTG |= 0b00000111;
	PORTD |= 0b10000000;
	
	// Pull reset pin - Wait min 10 uS
	RST_PORT &= ~(1 << RST_BIT);
	vTaskDelay( 500 / portTICK_RATE_MS );
	RST_PORT |= (1 << RST_BIT);
	
	// Wait for display to be rdy
	vTaskDelay( 500 / portTICK_RATE_MS );
	
	// Set pixel interface and memoryaccesscontrol
	InterfacePixelFormat(0b00000101);
	MemoryAccessControl(0b00001000);
	
	// Call sleepout and display on.
	SleepOut();
	DisplayOn();
}

void DisplayOff()
{
	// Send command DisplayOff which is 0x28 in HEX.
	WriteCommand(0x28);
}

void DisplayOn()
{
	// Send command DisplayOn which is 0x29 in HEX.
	WriteCommand(0x29);
}

void SleepOut()
{
	// Send command SleepOut which is 0x11 in HEX. 
	WriteCommand(0x11);
}

void MemoryAccessControl(unsigned char parameter)
{
	WriteCommand(0x36);
	WriteData(parameter);
}

void InterfacePixelFormat(unsigned char parameter)
{
	WriteCommand(0x3A);
	WriteData(parameter);
}

void MemoryWrite()
{
	WriteCommand(0x2C);
}

// Red 0-31, Green 0-63, Blue 0-31
void WritePixel(unsigned char Red, unsigned char Green, unsigned char Blue)
{
	uint16_t toSend = (Red << 11U) | (Green << 5U) | (Blue);
	WriteData(toSend);
}

// Set Column Address (0-239), Start > End
void SetColumnAddress(unsigned int Start, unsigned int End)
{
	if (Start < End)
	{
		WriteCommand(0x2A);
		WriteData(Start >> 8U);
		WriteData(Start);
		WriteData(End >> 8U);
		WriteData(End);
	}
}

// Set Page Address (0-319), Start > End
void SetPageAddress(unsigned int Start, unsigned int End)
{
	if (Start < End)
	{
		WriteCommand(0x2B);
		WriteData(Start >> 8U);
		WriteData(Start);
		WriteData(End >> 8U);
		WriteData(End);
	}
}

// Fills rectangle with specified color
// (StartX,StartY) = Upper left corner. X horizontal (0-319) , Y vertical (0-239).
// Height (1-240) is vertical. Width (1-320) is horizontal.
// R-G-B = 5-6-5 bits.
void FillRectangle(unsigned int StartX, unsigned int StartY, unsigned int Width, unsigned int Height, unsigned char Blue, unsigned char Green, unsigned char Red)
{
	SetPageAddress(StartX,StartX+Width-1);
	SetColumnAddress(StartY,StartY+Height-1);
	MemoryWrite();
	
	for (uint32_t counter = 0; counter < (uint32_t)Width*Height; counter++)
	{
		WritePixel(Red,Green,Blue);
	}
	SleepOut();
}


void printLetter(unsigned int StartX, unsigned int StartY, unsigned char* letterptr)
{
	SetPageAddress(StartX, StartX + letterptr[0]-1);
	SetColumnAddress(StartY, StartY + letterptr[1]-1);
	MemoryWrite();

	uint8_t pixelCounter = 8U;
	uint8_t letterIndex = 3U;
	
	for (uint8_t counter1 = 0; counter1 < letterptr[1]; counter1++ )
	{
		for (uint8_t counter2 = 0; counter2 < letterptr[0]; counter2++ )
		{
			uint8_t letter = letterptr[letterIndex];
				
			if (letter && (1 << pixelCounter))
			{
				WritePixel(0,0,0);
			}
			else
			{
				WritePixel(31,63,31);
			}
			
			if (pixelCounter == 1U)
			{
				pixelCounter = 8U;
				letterIndex++;
			}
			else
			{
				pixelCounter--;
			}
		}
		if (pixelCounter != 8U)
		{
			letterIndex++;
		}
		pixelCounter = 8U;
	}
}

//void printLetter(unsigned int StartX, unsigned int StartY, unsigned char asd)
//{
	//SetPageAddress(StartX, StartX + Bmp214[0]-1);
	//SetColumnAddress(StartY, StartY + Bmp214[1]-1);
	//MemoryWrite();
//
	//uint8_t pixelCounter = 8U;
	//uint8_t letterIndex = 3U;
	//
	//uint8_t countValue = Bmp214[0]*Bmp214[1];
	//
	//for (uint16_t counter = 0; counter < (uint16_t)countValue; counter++)
	//{
		//uint8_t letter = Bmp214[letterIndex];
		//uint8_t bitset = letter & (1 << pixelCounter);
		//if (bitset > 1)
		//{
			//WritePixel(0,0,0);
		//}
		//else
		//{
			//WritePixel(31,63,31);
		//}
		//
		//if(pixelCounter == 1U)
		//{
			//letterIndex++;
			//pixelCounter = 8U;
		//}
		//else
		//{
			//pixelCounter--;
		//}
	//}
//}