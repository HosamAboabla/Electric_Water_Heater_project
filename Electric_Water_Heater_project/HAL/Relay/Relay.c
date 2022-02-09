/*
 * Relay.c
 *
 * Created: 12/4/2021 10:04:21 AM
 *  Author: karim
 */ 

#include "Relay.h"


void Relay_Initialization(void)
{
	DIO_SetPinDirection(RELAY_PORT, RELAY_PIN, RELAY_OUT);
}
void Relay_ON(void)
{
	DIO_SetPinValue(RELAY_PORT, RELAY_PIN, RELAY_HIGH);
}
void Relay_OFF(void)
{
	DIO_SetPinValue(RELAY_PORT, RELAY_PIN, RELAY_LOW);
}
void Relay_Toggle(void)
{
	DIO_TogglePinValue(RELAY_PORT, RELAY_PIN);
}