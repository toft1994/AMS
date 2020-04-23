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
public:
	Color();
	~Color();
	
	/**
	*    Reads the value of the red period attribute and returns it. 
	*    @param void Nothing
	*    @return uint16_t value of _redPeriod
	*/
	uint16_t getRedPeriod( void );
	
	/**
	*    Reads the value of the blue Period attribute and returns it.
	*    @param void Nothing
	*    @return uint16_t value of _bluePeriod
	*/
	uint16_t getBluePeriod( void );
	
	/**
	*    Reads the value of the green Period attribute and returns it.
	*    @param void Nothing
	*    @return uint16_t value of _greenPeriod
	*/
	uint16_t getGreenPeriod( void );
	
	/**
	*    Reads the value of the white Period attribute and returns it.
	*    @param void Nothing
	*    @return uint16_t value of _greenPeriod
	*/
	uint16_t getWhitePeriod( void );
	
	/**
	*    Reads the value of the index attribute and returns it.
	*    @param void Nothing
	*    @return uint8_t value of _index
	*/
	uint8_t getColorIndex( void );
	
	/**
	*    Sets the value of the red Period attribute.
	*    @param uint16_t redPeriod
	*    @return void Nothing
	*/
	void setRedPeriod( uint16_t redPeriod );
	
	/**
	*    Sets the value of the blue Period attribute.
	*    @param uint16_t bluePeriod
	*    @return void 
	*/
	void setBluePeriod( uint16_t bluePeriod );
	
	/**
	*    Sets the value of the red Period attribute.
	*    @param uint16_t greenPeriod
	*    @return void
	*/
	void setGreenPeriod( uint16_t greenPeriod );
	
	/**
	*    Sets the value of the white Period attribute.
	*    @param uint16_t whitePeriod
	*    @return void
	*/
	void setWhitePeriod( uint16_t whitePeriod );
	
	/**
	*    Moves item to zone one. 
	*	 Note: This function should be called after \ref grabBlock.
	*    @param uint8_t index
	*    @return void
	*/
	void setColorIndex( uint8_t index );

private:
	/**
	* Value of red period to store.
	*/
	uint16_t _redPeriod;
	
	/**
	* Value of blue period to store.
	*/
	uint16_t _bluePeriod;
	
	/**
	* Value of green period to store.
	*/
	uint16_t _greenPeriod;
	
	/**
	* Value of white period to store.
	*/
	uint16_t _whitePeriod;
	
	/**
	* Value of colorIndex to store.
	*/
	uint8_t _colorIndex;

}; //Color

#endif //__COLOR_H__
