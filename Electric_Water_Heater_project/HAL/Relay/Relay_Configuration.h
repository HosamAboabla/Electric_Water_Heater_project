/*
 * Relay_Configuration.h
 *
 * Created: 12/4/2021 10:03:58 AM
 *  Author: karim
 */ 


#ifndef RELAY_CONFIGURATION_H_
#define RELAY_CONFIGURATION_H_


#include "DIO.h"

#define RELAY_PORT DIO_PORTA
#define RELAY_PIN  DIO_PIN2

#define RELAY_OUT  DIO_OUTPUT

#define RELAY_LOW  DIO_LOW
#define RELAY_HIGH DIO_HIGH


#endif /* RELAY_CONFIGURATION_H_ */