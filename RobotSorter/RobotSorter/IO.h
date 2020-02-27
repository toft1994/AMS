/*
 * IO.h
 *
 * Created: 27-02-2020 09:27:08
 *  Author: jespe
 */ 


#ifndef IO_H_
#define IO_H_

/* Bit positions */
#define BIT1 = (1U << 0U)
#define BIT2 = (1U << 1U)
#define BIT3 = (1U << 2U)
#define BIT4 = (1U << 3U)
#define BIT5 = (1U << 4U)
#define BIT6 = (1U << 5U)
#define BIT7 = (1U << 6U)
#define BIT8 = (1U << 7U)

/* Colorsensor */
#define COLORSENSOR_S0_PIN = BIT1
#define COLORSENSOR_S1_PIN = BIT1
#define COLORSENSOR_S2_PIN = BIT1
#define COLORSENSOR_S3_PIN = BIT1
#define COLORSENSOR_OUT_PIN = BIT1

#define COLORSENSOR_S0_PORT = PORTA
#define COLORSENSOR_S1_PORT = PORTA
#define COLORSENSOR_S2_PORT = PORTA
#define COLORSENSOR_S3_PORT = PORTA
#define COLORSENSOR_OUT_PORT = PORTA


/* Matrix KeyPad */
#define KEYPAD_PIN_0 = BIT1
#define KEYPAD_PIN_1 = BIT2
#define KEYPAD_PIN_2 = BIT3
#define KEYPAD_PIN_3 = BIT4
#define KEYPAD_PIN_4 = BIT5
#define KEYPAD_PIN_5 = BIT6
#define KEYPAD_PIN_6 = BIT7
#define KEYPAD_PIN_7 = BIT8

#define KEYPAD_PORT_0 = PORTA
#define KEYPAD_PORT_1 = PORTB
#define KEYPAD_PORT_2 = PORTB
#define KEYPAD_PORT_3 = PORTB
#define KEYPAD_PORT_4 = PORTB
#define KEYPAD_PORT_5 = PORTB
#define KEYPAD_PORT_6 = PORTB
#define KEYPAD_PORT_7 = PORTB

/* xxxx */

#endif /* IO_H_ */