/*
* SEVSEG.c
*
* Created: 12/3/2021 1:16:40 PM
*  Author: karim
*/

#include "SEVSEG.h"

void SEVSEG_Initialization(void)//Define direction for all pins
{
	//Initialize control pins
	DIO_SetPinDirection(SEVSEG_CTRL_PORT, SEVSEG_PIN_EN1, SEVSEG_OUT);
	DIO_SetPinDirection(SEVSEG_CTRL_PORT, SEVSEG_PIN_EN2, SEVSEG_OUT);
	//Initialize data pins
	DIO_SetPinDirection(SEVSEG_DATA_PORT, SEVSEG_PIN_A, SEVSEG_OUT);
	DIO_SetPinDirection(SEVSEG_DATA_PORT, SEVSEG_PIN_B, SEVSEG_OUT);
	DIO_SetPinDirection(SEVSEG_DATA_PORT, SEVSEG_PIN_C, SEVSEG_OUT);
	DIO_SetPinDirection(SEVSEG_DATA_PORT, SEVSEG_PIN_D, SEVSEG_OUT);
	//Initialize dot pin
	DIO_SetPinDirection(SEVSEG_CTRL_PORT, SEVSEG_PIN_DOT, SEVSEG_OUT);
}
void SEVSEG_Enable1(void)//Enable first seven segment
{
	DIO_SetPinValue(SEVSEG_CTRL_PORT, SEVSEG_PIN_EN1, SEVSEG_HIGH);
}
void SEVSEG_Disable1(void)//Disable first seven segment
{
	DIO_SetPinValue(SEVSEG_CTRL_PORT, SEVSEG_PIN_EN1, SEVSEG_LOW);
}
void SEVSEG_Enable2(void)//Enable second seven segment
{
	DIO_SetPinValue(SEVSEG_CTRL_PORT, SEVSEG_PIN_EN2, SEVSEG_HIGH);
}
void SEVSEG_Disable2(void)//Disable second seven segment
{
	DIO_SetPinValue(SEVSEG_CTRL_PORT, SEVSEG_PIN_EN2, SEVSEG_LOW);
}
void SEVSEG_Dot_Enable(void)//Enable dot
{
	DIO_SetPinValue(SEVSEG_CTRL_PORT, SEVSEG_PIN_DOT, SEVSEG_HIGH);
}
void SEVSEG_Dot_Disable(void)//Disable dot
{
	DIO_SetPinValue(SEVSEG_CTRL_PORT, SEVSEG_PIN_DOT, SEVSEG_LOW);
}
void SEVSEG_Display(uint8_t number)
{
	uint8_t num1 = number%10;
	uint8_t num2 = number/10;
	PORTA = (num1 << 4);
	SEVSEG_Enable1();
	SEVSEG_Disable2();
	_delay_ms(1);
	PORTA = (num2 << 4);
	SEVSEG_Disable1();
	SEVSEG_Enable2();

}