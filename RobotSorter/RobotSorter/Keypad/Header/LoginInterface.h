/*
 * LoginInterface.h
 *
 * Created: 18-05-2020 11:07:09
 *  Author: MIKKELJENSEN
 */ 
#include "KeyPad.h"

#ifndef LOGININTERFACE_H_
#define LOGININTERFACE_H_

class LoginInterface
{
	public:
	LoginInterface();
	char getstateOfMachine();
	
	
	bool checkLogin();
	
	private:
	
	void setstateOfMachine(char);
	
	KeyPad keypad;
	
	uint8_t passWord[4];
	
	char stateOfMachine;
	
	
};

#endif /* LOGININTERFACE_H_ */