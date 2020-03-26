/*
 * RobotArm.h
 *
 * Created: 12-03-2020 11:42:32
 *  Author: jespe
 */ 

#include "../Header/Timer1.h"
#include "../Header/Timer3.h"

#ifndef ROBOTARM_H_
#define ROBOTARM_H_

class Robotarm
{
	public:
	Robotarm();
	void grabBlock();
	void moveBlockToZoneOne();
	static void startMotorImpl( void *pvParameters );
	void MotorSpeedController();
	
	private:
	timer1 tmr1_;
	timer3 tmr3_;
	float M1_Percent;
	float M1_OldPercent;
	float M2_Percent;
	float M2_OldPercent;
	float M3_Percent;
	float M3_OldPercent;
	float M4_Percent;
	float M4_OldPercent;
	float M5_Percent;
	float M5_OldPercent;
	float M6_Percent;
	float M6_OldPercent;
};

#endif /* ROBOTARM_H_ */