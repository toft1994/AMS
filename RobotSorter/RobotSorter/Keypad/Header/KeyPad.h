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
	char readKeyboard(void);
	
	private:
	char findKey(uint8_t);
	
};



#endif /* KEYPAD_H_ */