/*
 * RobotArm.h
 *
 * Created: 12-03-2020 11:42:32
 *  Author: jespe
 */ 

#include "Motor.h"

/* Timers used for PWM */
#include "Timer1.h"
#include "Timer5.h"

#ifndef ROBOTARM_H_
#define ROBOTARM_H_

class Robotarm
{
	public:
	Robotarm();
	
	/**
	*    Picks up item from standard position.
	*    @param void Nothing
	*    @return void Nothing
	*/
	void grabBlock();
	
	/**
	*    Moves item to zone one. 
	*	 Note: This function should be called after \ref grabBlock.
	*    @param void Nothing
	*    @return void Nothing
	*/
	void moveBlockToZoneOne();
	
	/**
	*    Moves item to zone two. 
	*	 Note: This function should be called after \ref grabBlock.
	*    @param void Nothing
	*    @return void Nothing
	*/
	void moveBlockToZoneTwo();
	
	/**
	*    Moves item to zone three. 
	*	 Note: This function should be called after \ref grabBlock.
	*    @param void Nothing
	*    @return void Nothing
	*/
	void moveBlockToZoneThree();
	
	/**
	*    Moves item to zone four. 
	*	 Note: This function should be called after \ref grabBlock.
	*    @param void Nothing
	*    @return void Nothing
	*/
	void moveBlockToZoneFour();
	
	/**
	*    Moves item to zone five. 
	*	 Note: This function should be called after \ref grabBlock.
	*    @param void Nothing
	*    @return void Nothing
	*/
	void moveBlockToZoneFive();
	
	/**
	*    Moves item to zone six. 
	*	 Note: This function should be called after \ref grabBlock.
	*    @param void Nothing
	*    @return void Nothing
	*/
	void moveBlockToZoneSix();

	private:
	static void startMotorImpl( void *pvParameters );
	void ArmDownReleaseItem();
	inline void MotorSpeedController();
	
	/**
	* Instance of Timer1 used to control PWM signals in \ref M1, \ref M2 and \ref M3.
	*/
	Timer1 tmr1_;
	
	/**
	* Instance of Timer5 used to control PWM signals in \ref M4, \ref M5 and \ref M6.
	*/
	Timer5 tmr3_;
	
	/** 
	* Array of motors used to easily loop though \ref TurnMotor. 
	*/
	Motor* motors_[6U];
};

#endif /* ROBOTARM_H_ */