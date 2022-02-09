/*
* Timer0.c
*
* Created: 12/17/2021 1:14:57 PM
*  Author: karim
*/


#include "Timer2.h"

uint16 _Prescaler_ = 0;

void Timer2_Start(Timer2_Prescaler prescaler)
{
	switch(prescaler)
	{
		case PreS_0_:
		break;
		case PreS_1_:
		_Prescaler_ = 1;
		CLR_BIT(TCCR2, CS22);CLR_BIT(TCCR2, CS21);SET_BIT(TCCR2, CS20);
		break;
		case PreS_8_:
		_Prescaler_ = 8;
		CLR_BIT(TCCR2, CS22);SET_BIT(TCCR2, CS21);CLR_BIT(TCCR2, CS20);
		break;
		case PreS_64_:
		_Prescaler_ = 64;
		CLR_BIT(TCCR2, CS22);SET_BIT(TCCR2, CS21);SET_BIT(TCCR2, CS20);
		break;
		case PreS_256_:
		_Prescaler_ = 256;
		SET_BIT(TCCR2, CS22);CLR_BIT(TCCR2, CS21);CLR_BIT(TCCR2, CS20);
		break;
		case PreS_1024_:
		_Prescaler_ = 1024;
		SET_BIT(TCCR2, CS22);CLR_BIT(TCCR2, CS21);SET_BIT(TCCR2, CS20);
		break;
		
	}
}
void Timer2_Stop(void)
{
	CLR_BIT(TCCR2, CS22);CLR_BIT(TCCR2, CS21);CLR_BIT(TCCR2, CS20);
}

/*
void Timer2_WithoutInterrupt_Initialization(Timer2_Mode mode, Timer2_Pin_Mode pin)
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
*/

//Global Variables
uint32_t Timer2_OVF = 0;
uint32_t Timer2_CTC = 0;
uint32_t Timer2_Init_Value = 0;

void Timer2_WithInterrupt_Initialization(Timer2_Mode mode, Timer2_Pin_Mode pin)
{
	cli();//Close global interrupt
	switch(mode)//Chose Mode
	{
		case Normal_Mode_:
		CLR_BIT(TCCR2, WGM21);CLR_BIT(TCCR2, WGM20);
		SET_BIT(TIMSK, TOIE2);//Open OVF interrupt
		break;
		case CTC_Mode_:
		SET_BIT(TCCR2, WGM21);CLR_BIT(TCCR2, WGM20);
		SET_BIT(TIMSK, OCIE2);//Open CTC Interrupt
		break;
		case PWM_PhaseCorrect_:
		break;
		case PWM_Fast_:
		break;
	}
	switch(pin)//Output pin mode
	{
		case Pin_disconnected_:
		CLR_BIT(TCCR2, COM21);CLR_BIT(TCCR2, COM20);
		break;
		case Pin_Toggle_:
		CLR_BIT(TCCR2, COM21);SET_BIT(TCCR2, COM20);
		break;
		case Pin_Clear_:
		SET_BIT(TCCR2, COM21);CLR_BIT(TCCR2, COM20);
		break;
		case Pin_Set_:
		SET_BIT(TCCR2, COM21);SET_BIT(TCCR2, COM20);
		break;
	}
	sei();//Enable global interrupt
}
void Timer2_WithInterrupt_SetDelay(Timer2_Mode mode, uint32_t delay, uint8_t top)
{
	if(mode == Normal_Mode_)
	{
		uint8_t Tick = ( 1 * _Prescaler_) / Frequency;
		uint32_t count = (delay * Microsecond) / Tick;
		Timer2_OVF = count / Bits;
		Timer2_OVF ++;
		Timer2_Init_Value = Bits - (count % Bits);
		return;
	}
	else if(mode == CTC_Mode_)
	{
		OCR2 = top;
		uint8_t Tick = ( 1 * _Prescaler_) / Frequency;
		uint32_t count = (delay * Microsecond) / Tick;
		Timer2_CTC = count / OCR0;
		Timer2_CTC ++;
		return;
	}
}


/*
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
*/