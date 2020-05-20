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
	 stateOfMachine = 'L';
 }
 
 LoginInterface::~LoginInterface()
 {
 }
 
 void LoginInterface::checkLogin()
 {
	 uint8_t userPressed = 0;
	 volatile uint8_t userPass[4];
	 
	 while(userPressed < 4)
	 {
		 char buf = keypad.readKeyboard();
		 
		 // If star is pressed.. Reset Keys pressed
		 if (buf == 42)
		 {
			 userPressed = 0;
		 }else
		 {
			 // Put key pressed into array
			 userPass[userPressed] = buf;
			 userPressed++; 
		 }
	 }
	 
	 bool all_okay = true;
	 // Check each of the entries in array if they match password
	 for (uint8_t i = 0; i < 4; i++)
	 {
		 if (userPass[i] != passWord[i])
		 {
			 setstateOfMachine('L');
			 all_okay = false;
		 }
	 }
	 // If state is locked unlock it
	 // If state is unlocked lock it
	 
	 if (all_okay)
	 {
		 if (getstateOfMachine() == 'L')
		 {
			 setstateOfMachine('U');
		 }else
		 {
			 setstateOfMachine('L');
		 }
	 }
 }
 
 
 // Set and get Method for stateOfMachine
 char LoginInterface::getstateOfMachine()
 {
	 return stateOfMachine;
 }
 
 void LoginInterface::setstateOfMachine(char state)
 {
	 
	 switch(state){
		 case 'U':
			stateOfMachine = 'U';
			break;
		 case 'L':
			stateOfMachine = 'L';
			break;
		 default:
			stateOfMachine = 'L';
			break;
	 }
 }