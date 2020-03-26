/* 
* Color.cpp
*
* Created: 12-03-2020 22:27:47
* Author: jespe
*/


#include "../header/Color.h"
#include <string.h>

// default constructor
Color::Color()
{
}

// default destructor
Color::~Color()
{
}

uint32_t Color::getRedPwm( void )
{
	return _redPwm;
}

uint32_t Color::getBluePwm( void )
{
	return _bluePwm;
}

uint32_t Color::getGreenPwm( void )
{
	return _greenPwm;
}

uint8_t Color::getColorIndex( void )
{
	return _colorIndex;
}

void Color::setRedPwm( uint32_t redPwm )
{
	_redPwm = redPwm;
}

void Color::setBluePwm( uint32_t bluePwm )
{
	_bluePwm = bluePwm;
}

void Color::setGreenPwm( uint32_t greenPwm )
{
	_greenPwm = greenPwm;
}

void Color::setColorIndex( uint8_t index )
{
	_colorIndex = index;
}