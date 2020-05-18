/*
 * LoginInterface.cpp
 *
 * Created: 18-05-2020 11:06:55
 *  Author: MIKKELJENSEN
 */ 
#include <stdlib.h>
#include <avr/io.h>
#include "KeyPad.h"
#include "LoginInterface.h"

 LoginInterface::LoginInterface()
 {
	 keypad = KeyPad();
	 // ASCII Used since static declaration is not supported before STD c++ 11
	 passWord[0] = 49; // 1
	 passWord[1] = 52; // 4
	 passWord[2] = 55; // 7
	 passWord[3] = 50; // 2
	 
 }
 
 bool LoginInterface::checkLogin()
 {
	 uint8_t userPressed = 0;
	 uint8_t userPass[4];
	 
	 while(userPressed < 4)
	 {
		 char buf = keypad.readKeyboard();
		 
		 if (buf == 42)
		 {
			 userPressed = 0;
		 }else
		 {
			 userPass[userPressed] = buf;
			 userPressed++; 
		 }
	 }
	 
	 for (uint8_t i = 0; i < 4; i++)
	 {
		 if (userPass[i] != passWord[i])
		 {
			 setstateOfMachine('L');
		 }
	 }
	 if (getstateOfMachine() == 'L')
	 {
		 setstateOfMachine('U');
	 }else
	 {
		 setstateOfMachine('L');	
	 }
 }
 
 char LoginInterface::getstateOfMachine()
 {
	 return stateOfMachine;
 }
 
 void LoginInterface::setstateOfMachine(char state)
 {
	 stateOfMachine = state;
 }