/*
* Interrupt.c
*
* Created: 12/10/2021 1:37:49 PM
*  Author: karim
*/


#include "Interrupt.h"

/*
Search inside data sheet starting from page. 64
*/

void Interrupt_Initialization(Interrupt_Signal_Pin pin)
{
	//Define Direction as input
	CLR_BIT(DDRD, PD2);
	CLR_BIT(DDRD, PD3);
	CLR_BIT(DDRD, PB2);
	//Enable Global interrupt (Apartment Door)
	//===============================================================
	#if Global_INTERRUPT_STATUS == GLOBAL_EN
	sei();
	//SET_BIT(SREG, 7);
	#elif Global_INTERRUPT_STATUS == GLOBAL_DS
	cli();
	//CLR_BIT(SREG, 7);
	#else
	#warning This is invalid choice
	#endif
	//==============================================================
	if(pin == INT0_Signal)
	{
		//Enable Peripheral interrupt (Room Door)
		SET_BIT(GICR, INT0);
		#if Interrupt_SENSE == LOW_SIGNAL
		CLR_BIT(MCUCR, ISC01);CLR_BIT(MCUCR, ISC00);
		#elif Interrupt_SENSE == HIGH_SIGNAL
		CLR_BIT(MCUCR, ISC01);SET_BIT(MCUCR, ISC00);
		#elif Interrupt_SENSE == Falling_SIGNAL
		SET_BIT(MCUCR, ISC01);CLR_BIT(MCUCR, ISC00);
		#elif Interrupt_SENSE == RISING_SIGNAL
		SET_BIT(MCUCR, ISC01);SET_BIT(MCUCR, ISC00);
		#else
		#warning This is invalid
		#endif
	}
	else if(pin == INT1_Signal)
	{
		//Enable Peripheral interrupt (Room Door)
		SET_BIT(GICR, INT1);
		#if Interrupt_SENSE == LOW_SIGNAL
		CLR_BIT(MCUCR, ISC11);CLR_BIT(MCUCR, ISC10);
		#elif Interrupt_SENSE == HIGH_SIGNAL
		CLR_BIT(MCUCR, ISC11);SET_BIT(MCUCR, ISC10);
		#elif Interrupt_SENSE == Falling_SIGNAL
		SET_BIT(MCUCR, ISC11);CLR_BIT(MCUCR, ISC10);
		#elif Interrupt_SENSE == RISING_SIGNAL
		SET_BIT(MCUCR, ISC11);SET_BIT(MCUCR, ISC10);
		#else
		#warning This is invalid
		#endif
	}
	else if(pin == INT2_Signal)
	{
		//Enable Peripheral interrupt (Room Door)
		SET_BIT(GICR, INT2);
		#if Interrupt_SENSE == Falling_SIGNAL
		CLR_BIT(MCUCSR, ISC2);
		#elif Interrupt_SENSE == RISING_SIGNAL
		SET_BIT(MCUCSR, ISC2);
		#else
		#warning This is invalid
		#endif
	}
	else
	{
		//#warning This is invalid
	}
}
