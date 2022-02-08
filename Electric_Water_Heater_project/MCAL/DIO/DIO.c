/*
* DIO.c
*
* Created: 11/27/2021 1:12:55 PM
*  Author: karim
*/
//Include library
#include "DIO.h"
//Prototypes for functions for pin only
void DIO_SetPinDirection (Port port, Pin pin, State state)
{
	switch (state)
	{
		case DIO_INPUT:
		switch (port)
		{
			case DIO_PORTA:
			CLR_BIT(DDRA, pin);
			break;
			case DIO_PORTB:
			CLR_BIT(DDRB, pin);
			break;
			case DIO_PORTC:
			CLR_BIT(DDRC, pin);
			break;
			case DIO_PORTD:
			CLR_BIT(DDRD, pin);
			break;
		}
		break;
		case DIO_OUTPUT:
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT(DDRA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(DDRB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(DDRC, pin);
			break;
			case DIO_PORTD:
			SET_BIT(DDRD, pin);
			break;
		}
		break;
	}
}
//If pin is defined as output
void DIO_SetPinValue (Port port, Pin pin, Status status)
{
	switch (status)
	{
		case DIO_LOW:
		switch (port)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA, pin);
			break;
			case DIO_PORTB:
			CLR_BIT(PORTB, pin);
			break;
			case DIO_PORTC:
			CLR_BIT(PORTC, pin);
			break;
			case DIO_PORTD:
			CLR_BIT(PORTD, pin);
			break;
		}
		break;
		case DIO_HIGH:
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT(PORTA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(PORTB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC, pin);
			break;
			case DIO_PORTD:
			SET_BIT(PORTD, pin);
			break;
		}
		break;
	}
}
void DIO_TogglePinValue (Port port, Pin pin)
{
	switch (port)
	{
		case DIO_PORTA:
		TGL_BIT(PORTA, pin);
		break;
		case DIO_PORTB:
		TGL_BIT(PORTB, pin);
		break;
		case DIO_PORTC:
		TGL_BIT(PORTC, pin);
		break;
		case DIO_PORTD:
		TGL_BIT(PORTD, pin);
		break;
	}
}
//If pin is defined as input
uint8_t DIO_ReadPinValue (Port port, Pin pin)
{
	uint8_t reading = 0;
	_delay_ms(10);
	switch (port)
	{
		case DIO_PORTA:
		reading = GET_BIT(PINA, pin);
		break;
		case DIO_PORTB:
		reading = GET_BIT(PINB, pin);
		break;
		case DIO_PORTC:
		reading = GET_BIT(PINC, pin);
		break;
		case DIO_PORTD:
		reading = GET_BIT(PIND, pin);
		break;
	}
	return reading;
}
void DIO_SetPinPullUp (Port port, Pin pin)
{
	switch (port)
	{
		case DIO_PORTA:
		SET_BIT(PORTA, pin);
		break;
		case DIO_PORTB:
		SET_BIT(PORTB, pin);
		break;
		case DIO_PORTC:
		SET_BIT(PORTC, pin);
		break;
		case DIO_PORTD:
		SET_BIT(PORTD, pin);
		break;
	}
}
//===================================================================
//Prototypes for function for port
void DIO_SetPortDirection(Port port, State state)
{
	switch(state)
	{
		case DIO_INPUT:
		switch (port)
		{
			case DIO_PORTA:
			DDRA = 0x00;
			break;
			case DIO_PORTB:
			DDRB = 0x00;
			break;
			case DIO_PORTC:
			DDRC = 0x00;
			break;
			case DIO_PORTD:
			DDRD = 0x00;
			break;
		}
		break;
		case DIO_OUTPUT:
		switch (port)
		{
			case DIO_PORTA:
			DDRA = 0xFF;
			break;
			case DIO_PORTB:
			DDRB = 0xFF;
			break;
			case DIO_PORTC:
			DDRC = 0xFF;
			break;
			case DIO_PORTD:
			DDRD = 0xFF;
			break;
		}
		break;
	}
}
//If pin is defined as output
void DIO_SetPortValue (Port port, Status status)
{
	switch(status)
	{
		case DIO_LOW:
		switch (port)
		{
			case DIO_PORTA:
			PORTA = 0x00;
			break;
			case DIO_PORTB:
			PORTB = 0x00;
			break;
			case DIO_PORTC:
			PORTC = 0x00;
			break;
			case DIO_PORTD:
			PORTD = 0x00;
			break;
		}
		break;
		case DIO_HIGH:
		switch (port)
		{
			case DIO_PORTA:
			PORTA = 0xFF;
			break;
			case DIO_PORTB:
			PORTB = 0xFF;
			break;
			case DIO_PORTC:
			PORTC = 0xFF;
			case DIO_PORTD:
			PORTD = 0xFF;
			break;
		}
		break;
	}
}
void DIO_TogglePortValue (Port port)
{
	switch (port)
	{
		case DIO_PORTA:
		PORTA ^= 0xFF;
		break;
		case DIO_PORTB:
		PORTB ^= 0xFF;
		break;
		case DIO_PORTC:
		PORTC ^= 0xFF;
		case DIO_PORTD:
		PORTD ^= 0xFF;
		break;
	}
}
//If pin is defined as input
uint8_t DIO_ReadPortValue(Port port)
{
	uint8_t reading = 0x00;
	switch (port)
	{
		case DIO_PORTA:
		reading = PINA;
		break;
		case DIO_PORTB:
		reading = PINB;
		break;
		case DIO_PORTC:
		reading = PINC;
		break;
		case DIO_PORTD:
		reading = PIND;
		break;
	}
	return reading;
}
void DIO_SetPortPullUp (Port port)
{
	switch (port)
	{
		case DIO_PORTA:
		PORTA = 0xFF;
		break;
		case DIO_PORTB:
		PORTB = 0xFF;
		break;
		case DIO_PORTC:
		PORTC = 0xFF;
		case DIO_PORTD:
		PORTD = 0xFF;
		break;
	}
}
//===================================================================
//From future
void ViewBit_Format1(Port port, Pin pin, Status* status)//Read Bit
{
	switch(port)
	{
		case DIO_PORTA:
		*status = GET_BIT(PINA, pin);
		break;
		case DIO_PORTB:
		*status = GET_BIT(PINB, pin);
		break;
		case DIO_PORTC:
		*status = GET_BIT(PINC, pin);
		break;
		case DIO_PORTD:
		*status = GET_BIT(PIND, pin);
		break;
	}
}
boolean ViewBit_Format2(Port port, Pin pin, Status* status)//Read Bit
{
	switch(port)
	{
		case DIO_PORTA:
		*status = GET_BIT(PINA, pin);
		return TRUE;
		break;
		case DIO_PORTB:
		*status = GET_BIT(PINB, pin);
		return TRUE;
		break;
		case DIO_PORTC:
		*status = GET_BIT(PINC, pin);
		return TRUE;
		break;
		case DIO_PORTD:
		*status = GET_BIT(PIND, pin);
		return TRUE;
		break;
	}
	return FALSE;//There is no reading
}