/*
 * timer1.h
 *
 * Created: 27-02-2020 10:45:41
 *  Author: jespe
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

class timer1
{
	public:
	timer1();
	uint16_t getPwm( void );
	
	private:
	//void setFilter( uint8_t filter );
	//void setFrequencyscaling( FrequencyScaling scaling );
};


#endif /* TIMER1_H_ */