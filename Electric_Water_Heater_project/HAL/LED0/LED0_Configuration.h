/*
 * LED0_Configuration.h
 *
 * Created: 11/27/2021 1:13:32 PM
 *  Author: karim
 */ 


#ifndef LED0_CONFIGURATION_H_
#define LED0_CONFIGURATION_H_

#include "DIO.h"


#define LED0_PORT   DIO_PORTC
#define LED0        DIO_PIN2

#define LED0_OUT    DIO_OUTPUT

#define LED0_OFFF   DIO_LOW
#define LED0_ONN    DIO_HIGH

#endif /* LED0_CONFIGURATION_H_ */