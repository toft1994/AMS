/*
 * RobotArmTestMain.h
 *
 * Created: 09-05-2020 13:47:13
 *  Author: jespe
 */ 

#include "RobotArm.h"

void RobotarmTestMain( void* armPtr )
{
	Robotarm* arm = ( Robotarm* ) armPtr;
	
	while (1)
	{
		arm->grabBlock();
		vTaskDelay( 500 / portTICK_RATE_MS );
		arm->moveBlockToZoneOne();
		vTaskDelay( 500 / portTICK_RATE_MS );
	}
}