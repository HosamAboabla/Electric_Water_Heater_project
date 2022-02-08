/*
* Timer0.c
*
* Created: 12/17/2021 1:14:57 PM
*  Author: karim
*/


#include "Timer0.h"

uint16 _Prescaler = 0;

void Timer0_Start(Timer0_Prescaler prescaler)
{
	switch(prescaler)
	{
		case PreS_0:
		break;
		case PreS_1:
		_Prescaler = 1;
		CLR_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);
		break;
		case PreS_8:
		_Prescaler = 8;
		CLR_BIT(TCCR0, CS02);SET_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
		break;
		case PreS_64:
		_Prescaler = 64;
		CLR_BIT(TCCR0, CS02);SET_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);
		break;
		case PreS_256:
		_Prescaler = 256;
		SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
		break;
		case PreS_1024:
		_Prescaler = 1024;
		SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);
		break;
		
	}
}
void Timer0_Stop(void)
{
	CLR_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
}

void Timer0_WithoutInterrupt_Initialization(Timer0_Mode mode, Timer0_Pin_Mode pin)
{
	cli();//Close global interrupt
	switch(mode)//Chose Mode
	{
		case Normal_Mode:
		CLR_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
		CLR_BIT(TIMSK, TOIE0);//Close OVF interrupt
		break;
		case CTC_Mode:
		SET_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
		CLR_BIT(TIMSK, OCIE0);//Close CTC Interrupt
		break;
		case PWM_PhaseCorrect:
		break;
		case PWM_Fast:
		break;
	}
	switch(pin)//Output pin mode
	{
		case Pin_disconnected:
		CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
		break;
		case Pin_Toggle:
		CLR_BIT(TCCR0, COM01);SET_BIT(TCCR0, COM00);
		break;
		case Pin_Clear:
		SET_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
		break;
		case Pin_Set:
		SET_BIT(TCCR0, COM01);SET_BIT(TCCR0, COM00);
		break;
	}
}
void Timer0_WithoutInterrupt_SetDelay(Timer0_Mode mode, uint32_t delay, uint8_t top)
{
	if(mode == Normal_Mode)
	{
		uint32_t counter = 0;
		uint8_t Tick = (1 * _Prescaler) / Frequency;
		uint32_t Count = (delay * Microsecond) / Tick;
		uint32_t OVF = Count / Bits;
		OVF ++;
		uint8_t Initial_value = Bits - (Count % Bits);
		TCNT0 = Initial_value;//Initial value of first overflow
		while(counter != OVF)//Polling Mode(Blocking Delay)
		{
			while(GET_BIT(TIFR, TOV0) != 1);//Wait until raise flag
			SET_BIT(TIFR, TOV0);//Clear flag
			counter++;//Increment counter
		}
	}
	else if (mode == CTC_Mode)
	{
		OCR0 = top;
		uint32_t counter = 0;
		uint8_t Tick = (1 * _Prescaler) / Frequency;
		uint32_t Count = (delay * Microsecond) / Tick;
		uint32_t CTC = Count / OCR0;
		CTC ++;
		while(counter != CTC)//Polling Mode(Blocking Delay)
		{
			while(GET_BIT(TIFR, OCF0) != 1);//Wait until raise flag
			SET_BIT(TIFR, OCF0);//Clear flag
			counter++;//Increment counter
		}
	}
}

//Global Variables
uint32_t Number_OVF = 0;
uint32_t Number_CTC = 0;
uint32_t Init_Value = 0;

void Timer0_WithInterrupt_Initialization(Timer0_Mode mode, Timer0_Pin_Mode pin)
{
	cli();//Close global interrupt
	switch(mode)//Chose Mode
	{
		case Normal_Mode:
		CLR_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
		SET_BIT(TIMSK, TOIE0);//Open OVF interrupt
		break;
		case CTC_Mode:
		SET_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
		SET_BIT(TIMSK, OCIE0);//Open CTC Interrupt
		break;
		case PWM_PhaseCorrect:
		break;
		case PWM_Fast:
		break;
	}
	switch(pin)//Output pin mode
	{
		case Pin_disconnected:
		CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
		break;
		case Pin_Toggle:
		CLR_BIT(TCCR0, COM01);SET_BIT(TCCR0, COM00);
		break;
		case Pin_Clear:
		SET_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
		break;
		case Pin_Set:
		SET_BIT(TCCR0, COM01);SET_BIT(TCCR0, COM00);
		break;
	}
	sei();//Enable global interrupt
}
void Timer0_WithInterrupt_SetDelay(Timer0_Mode mode, uint32_t delay, uint8_t top)
{
	if(mode == Normal_Mode)
	{
		uint8_t Tick = ( 1 * _Prescaler) / Frequency;
		uint32_t count = (delay * Microsecond) / Tick;
		Number_OVF = count / Bits;
		Number_OVF ++;
		Init_Value = Bits - (count % Bits);
		return;
	}
	else if(mode == CTC_Mode)
	{
		OCR0 = top;
		uint8_t Tick = ( 1 * _Prescaler) / Frequency;
		uint32_t count = (delay * Microsecond) / Tick;
		Number_CTC = count / OCR0;
		Number_CTC ++;
		return;
	}
}



void Timer0_Fast_PWM_Initialization(PWM_Mode mode)
{
	//Define direction of OC0 pin as output
	SET_BIT(DDRB, PB3);
	//Choose Fast PWM mode
	SET_BIT(TCCR0, WGM01);SET_BIT(TCCR0, WGM00);
	//Define pre-scaler(Fosc/256)
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
	//Choose mode
	switch(mode)
	{
		case Non_Inverting:
		SET_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
		break;
		case Inverting:
		SET_BIT(TCCR0, COM01);SET_BIT(TCCR0, COM00);
		break;
	}
}
void Timer0_Fast_PWM_SetDuty(PWM_Mode mode, uint8_t dutycyle)
{
	switch(mode)
	{
		case Non_Inverting:
		OCR0 = ((Bits * dutycyle) / 100) - 1;
		break;
		case Inverting:
		OCR0 = (Bits - 1) - (((Bits * dutycyle) / 100) - 1);
		break;
	}
}



void Timer0_PhaseCorrect_PWM_Initialization(PWM_Mode mode)
{
	//Define direction of OC0 pin as output
	SET_BIT(DDRB, PB3);
	//Choose Fast PWM mode
	CLR_BIT(TCCR0, WGM01);SET_BIT(TCCR0, WGM00);
	//Define pre-scaler(Fosc/256)
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
	//Choose mode
	switch(mode)
	{
		case Non_Inverting:
		SET_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
		break;
		case Inverting:
		SET_BIT(TCCR0, COM01);SET_BIT(TCCR0, COM00);
		break;
	}
}
void Timer0_PhaseCorrect_PWM_SetDuty(PWM_Mode mode, uint8_t dutycyle)
{
	switch(mode)
	{
		case Non_Inverting:
		OCR0 = ((Bits * dutycyle) / 100) - 1;
		break;
		case Inverting:
		OCR0 = (Bits - 1) - (((Bits * dutycyle) / 100) - 1);
		break;
	}
}
