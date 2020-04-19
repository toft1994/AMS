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
	uint16_t _redPeriod;
	uint16_t _bluePeriod;
	uint16_t _greenPeriod;
	uint16_t _whitePeriod;
	uint8_t _colorIndex;
//functions
public:
	Color();
	~Color();
	
	/**
	*    Reads the value of the red period attribute and returns it. 
	*    @param void
	*    @return uint16_t value of _redPeriod
	*/
	uint16_t getRedPeriod( void );
	
	/**
	*    Reads the value of the blue Period attribute and returns it.
	*    @param void
	*    @return uint16_t value of _bluePeriod
	*/
	uint16_t getBluePeriod( void );
	
	/**
	*    Reads the value of the green Period attribute and returns it.
	*    @param void
	*    @return uint16_t value of _greenPeriod
	*/
	uint16_t getGreenPeriod( void );
	
	/**
	*    Reads the value of the white Period attribute and returns it.
	*    @param void
	*    @return uint16_t value of _greenPeriod
	*/
	uint16_t getWhitePeriod( void );
	
	/**
	*    Reads the value of the index attribute and returns it.
	*    @param void
	*    @return uint8_t value of _index
	*/
	uint8_t getColorIndex( void );
	
	/**
	*    Sets the value of the red Period attribute.
	*    @param uint16_t
	*    @return void
	*/
	void setRedPeriod( uint16_t redPeriod );
	
	/**
	*    Sets the value of the blue Period attribute.
	*    @param void
	*    @return void
	*/
	void setBluePeriod( uint16_t bluePeriod );
	
	/**
	*    Sets the value of the red Period attribute.
	*    @param void
	*    @return void
	*/
	void setGreenPeriod( uint16_t greenPeriod );
	
	/**
	*    Sets the value of the white Period attribute.
	*    @param void
	*    @return void
	*/
	void setWhitePeriod( uint16_t whitePeriod );
	
	/**
	*    Moves item to zone one. 
	*	 Note: This function should be called after \ref grabBlock.
	*    @param void
	*    @return void
	*/
	void setColorIndex( uint8_t index );

protected:
private:

}; //Color

#endif //__COLOR_H__
