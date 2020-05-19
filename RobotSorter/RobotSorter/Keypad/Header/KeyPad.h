/*
 * KeyPad.h
 *
 * Created: 26-03-2020 09:05:15
 *  Author: MIKKELJENSEN
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

class KeyPad
{
	public:
	KeyPad();
	~KeyPad();
	/**
	*    Reads the key pressed on the keyboard. This function is blocking
	*	 And will first return when no key is pressed again
	*    @param void Nothing
	*    @return char, character pressed on keypad 
	*/
	char readKeyboard(void);
	
	private:
	/**
	*    Finds the characters pressed on keyboard from the 2 bit set in param
	*    @param uint8_t The byte with 2 bits set corresponding to row and column pressed
	*    @return char, character corresponding to the param byte
	*/
	char findKey(uint8_t);
	
};



#endif /* KEYPAD_H_ */