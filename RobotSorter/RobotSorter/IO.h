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

/* xxxx */

#endif /* IO_H_ */