/*
* DIO.h
*
* Created: 11/27/2021 1:12:47 PM
*  Author: karim
*/


#ifndef DIO_H_
#define DIO_H_

//#include "DIO_Address.h"
#include "DIO_Configurations.h"

//Prototypes for functions for pin only
void DIO_SetPinDirection (Port port, Pin pin, State state);
void DIO_SetPinValue (Port port, Pin pin, Status status);
void DIO_TogglePinValue (Port port, Pin pin);
uint8_t DIO_ReadPinValue (Port port, Pin pin);
void DIO_SetPinPullUp (Port port, Pin pin);
//Prototypes for function for port
void DIO_SetPortDirection(Port port, State state);
void DIO_SetPortValue (Port port, Status status);
void DIO_TogglePortValue (Port port);
uint8_t DIO_ReadPortValue(Port port);
void DIO_SetPortPullUp (Port port);
//From future
void ViewBit_Format1(Port port, Pin pin, Status* status);
boolean ViewBit_Format2(Port port, Pin pin, Status* status);

#endif /* DIO_H_ */