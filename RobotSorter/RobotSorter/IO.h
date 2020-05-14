/*
 * IO.h
 *
 * Created: 27-02-2020 09:27:08
 *  Author: jespe
 */ 

#include <avr/io.h>

#ifndef IO_H_
#define IO_H_

/* Bit positions */
#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7

/* Colorsensor */
#define COLORSENSOR_S0_PIN BIT7
#define COLORSENSOR_S1_PIN BIT6
#define COLORSENSOR_S2_PIN BIT5
#define COLORSENSOR_S3_PIN BIT4
#define COLORSENSOR_OUT_PIN BIT0

#define COLORSENSOR_S0_PORT PORTK
#define COLORSENSOR_S1_PORT PORTK
#define COLORSENSOR_S2_PORT PORTK
#define COLORSENSOR_S3_PORT PORTK
#define COLORSENSOR_OUT_PORT PORTL

/* RobotArm */
#define ROBOTARM_M1_OUT_PIN BIT5
#define ROBOTARM_M2_OUT_PIN BIT6
#define ROBOTARM_M3_OUT_PIN BIT7
#define ROBOTARM_M4_OUT_PIN BIT3
#define ROBOTARM_M5_OUT_PIN BIT4
#define ROBOTARM_M6_OUT_PIN BIT5

#define ROBOTARM_M1_OUT_PORT DDRB
#define ROBOTARM_M2_OUT_PORT DDRB
#define ROBOTARM_M3_OUT_PORT DDRB
#define ROBOTARM_M4_OUT_PORT DDRL
#define ROBOTARM_M5_OUT_PORT DDRL
#define ROBOTARM_M6_OUT_PORT DDRL

/* Matrix KeyPad */
#define KEYPAD_PIN_0 BIT0
#define KEYPAD_PIN_1 BIT1
#define KEYPAD_PIN_2 BIT2
#define KEYPAD_PIN_3 BIT3
#define KEYPAD_PIN_4 BIT4
#define KEYPAD_PIN_5 BIT5
#define KEYPAD_PIN_6 BIT6
#define KEYPAD_PIN_7 BIT7

#define KEYPAD_PORT_0 PORTA
#define KEYPAD_PORT_1 PORTB
#define KEYPAD_PORT_2 PORTB
#define KEYPAD_PORT_3 PORTB
#define KEYPAD_PORT_4 PORTB
#define KEYPAD_PORT_5 PORTB
#define KEYPAD_PORT_6 PORTB
#define KEYPAD_PORT_7 PORTB

/* Screen Touch part */
#define CLK_PORT PORTH
#define CS_PORT PORTE
#define DIN_PORT PORTG
#define DOUT_PORT PORTE
#define IRQ_PORT PORTE

#define CLK_PIN	BIT4
#define CS_PIN BIT4
#define DIN_PIN BIT6
#define DOUT_PIN BIT6
#define IRQ_PIN BIT5

/* Screen Display part */
// Data port definitions:
#define DATA_PORT_HIGH PORTA
#define DATA_PORT_LOW  PORTC

// Control port definitions:
#define WR_PORT PORTG
#define WR_BIT 2
#define DC_PORT PORTD
#define DC_BIT  7  //"DC" signal is at the shield called RS
#define CS_PORT_Dispay PORTG
#define CS_BIT  1
#define RST_PORT PORTG
#define RST_BIT 0

/* xxxx */

#endif /* IO_H_ */