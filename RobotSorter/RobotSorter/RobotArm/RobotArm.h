/*
 * RobotArm.h
 *
 * Created: 12-03-2020 11:42:32
 *  Author: jespe
 */ 

#include "Motor.h"

/* Timers used for PWM */
#include "Timer1.h"
#include "Timer3.h"

/* Robotarm motors */
#include "M1.h"
#include "M2.h"
#include "M3.h"
#include "M4.h"
#include "M5.h"
#include "M6.h"

#ifndef ROBOTARM_H_
#define ROBOTARM_H_

class Robotarm
{
	public:
	Robotarm();
	void grabBlock();
	void moveBlockToZoneOne();
	void moveBlockToZoneTwo();
	void moveBlockToZoneThree();
	static void startMotorImpl( void *pvParameters );
	
	private:
	void ArmDownReleaseItem();
	void MotorSpeedController();
	
	Timer1 tmr1_;
	Timer3 tmr3_;
	
	M1 motor1_;
	M2 motor2_;
	M3 motor3_;
	M4 motor4_;
	M5 motor5_;
	M6 motor6_;
	Motor* motors_[6U];
};

#endif /* ROBOTARM_H_ */