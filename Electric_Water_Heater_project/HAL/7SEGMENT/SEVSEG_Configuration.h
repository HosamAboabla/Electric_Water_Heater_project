/*
 * SEVSEG_Configuration.h
 *
 * Created: 12/3/2021 1:16:23 PM
 *  Author: karim
 */ 


#ifndef SEVSEG_CONFIGURATION_H_
#define SEVSEG_CONFIGURATION_H_

#include "DIO.h"

#define SEVSEG_DATA_PORT DIO_PORTA
#define SEVSEG_CTRL_PORT DIO_PORTB

#define SEVSEG_OUT   DIO_OUTPUT

#define  SEVSEG_LOW  DIO_LOW
#define  SEVSEG_HIGH DIO_HIGH
//Data pins
#define SEVSEG_PIN_A DIO_PIN4
#define SEVSEG_PIN_B DIO_PIN5
#define SEVSEG_PIN_C DIO_PIN6
#define SEVSEG_PIN_D DIO_PIN7
//Control pins
#define SEVSEG_PIN_EN1 DIO_PIN1
#define SEVSEG_PIN_EN2 DIO_PIN2
#define SEVSEG_PIN_DOT DIO_PIN3

#endif /* SEVSEG_CONFIGURATION_H_ */