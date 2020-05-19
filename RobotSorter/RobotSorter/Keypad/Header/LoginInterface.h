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
	~LoginInterface();
	/**
	*    Returns value of stateOfMachine
	*    @param void Nothing
	*    @return char, char L or U whether machine is locked or unlocked
	*/
	char getstateOfMachine();
	
	/**
	*    Will wait for 4 keys pressed and check them against passWord, if correct set stateOfMachine to U, if not to L
	*	 Will also switch Unlocked to Lock if state is already unlocked
	*    @param void Nothing
	*    @return void Nothing
	*/
	void checkLogin();
	
	
	private:
	KeyPad keypad;
	
	/**
	*    Set Method for stateOfMachine Variable 
	*    @param char to set stateOfMachine
	*    @return void Nothing
	*/
	void setstateOfMachine(char);
	
	/**
	*    Array containing the passWord 
	*/
	uint8_t passWord[4];
	
	/**
	*    char containing whether machine is Locked or Unlocked
	*/
	char stateOfMachine;
	
};

#endif /* LOGININTERFACE_H_ */