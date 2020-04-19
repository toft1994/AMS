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
	*    @param void
	*    @return void
	*/
	void grabBlock();
	
	/**
	*    Moves item to zone one. 
	*	 Note: This function should be called after \ref grabBlock.
	*    @param void
	*    @return void
	*/
	void moveBlockToZoneOne();
	
	/**
	*    Moves item to zone two. 
	*	 Note: This function should be called after \ref grabBlock.
	*    @param void
	*    @return void
	*/
	void moveBlockToZoneTwo();
	
	/**
	*    Moves item to zone three. 
	*	 Note: This function should be called after \ref grabBlock.
	*    @param void
	*    @return void
	*/
	void moveBlockToZoneThree();

	private:
	static void startMotorImpl( void *pvParameters );
	void ArmDownReleaseItem();
	inline void MotorSpeedController();
	
	Timer1 tmr1_;
	Timer5 tmr3_;
	Motor* motors_[6U];
};

#endif /* ROBOTARM_H_ */