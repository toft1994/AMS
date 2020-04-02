/* 
* Color.h
*
* Created: 12-03-2020 22:27:47
* Author: jespe
*/


#ifndef __COLOR_H__
#define __COLOR_H__

#include <stdint.h>

class Color
{
//variables
public:
protected:
private:
	uint32_t _redPwm;
	uint32_t _bluePwm;
	uint32_t _greenPwm;
	uint8_t _colorIndex;
//functions
public:
	Color();
	~Color();
	uint32_t getRedPwm( void );
	uint32_t getBluePwm( void );
	uint32_t getGreenPwm( void );
	uint8_t getColorIndex( void );
	
	void setRedPwm( uint32_t );
	void setBluePwm( uint32_t );
	void setGreenPwm( uint32_t );
	void setColorIndex( uint8_t );

protected:
private:

}; //Color

#endif //__COLOR_H__
