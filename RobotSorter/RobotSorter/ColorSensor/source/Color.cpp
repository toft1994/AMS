/* 
* Color.cpp
*
* Created: 12-03-2020 22:27:47
* Author: jespe
*/


#include "Color.h"
#include <string.h>

// default constructor
Color::Color()
{
}

// default destructor
Color::~Color()
{
}

uint16_t Color::getRedPeriod( void )
{
	return _redPeriod;
}

uint16_t Color::getBluePeriod( void )
{
	return _bluePeriod;
}

uint16_t Color::getGreenPeriod( void )
{
	return _greenPeriod;
}

uint16_t Color::getWhitePeriod( void )
{
	return _whitePeriod;
}

uint8_t Color::getColorIndex( void )
{
	return _colorIndex;
}

void Color::setRedPeriod( uint16_t redPeriod )
{
	_redPeriod = redPeriod;
}

void Color::setBluePeriod( uint16_t bluePeriod )
{
	_bluePeriod = bluePeriod;
}

void Color::setGreenPeriod( uint16_t greenPeriod )
{
	_greenPeriod = greenPeriod;
}

void Color::setWhitePeriod( uint16_t whitePeriod )
{
	_whitePeriod = whitePeriod;
}

void Color::setColorIndex( uint8_t index )
{
	_colorIndex = index;
}