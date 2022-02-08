/*
 * TIMER1.c
 *
 * Created: 1/15/2022 10:47:45 PM
 *  Author: hosam
 */ 


#include "TIMER1.h"


uint16_t Timer1_global_prescaler = 0;

void Timer1_start(TIMER1_Prescaler prescaler)
{
	switch(prescaler)
	{
		case TIMER1_Prescaler_0:
			CLEAR_BIT(TCCR1B , CS12); CLEAR_BIT(TCCR1B , CS11); CLEAR_BIT(TCCR1B , CS10);
			Timer1_global_prescaler = 0;
			break;
			
		case TIMER1_Prescaler_1:
			CLEAR_BIT(TCCR1B , CS12); CLEAR_BIT(TCCR1B , CS11); SET_BIT(TCCR1B , CS10);
			Timer1_global_prescaler = 1;
			break;
			
		case TIMER1_Prescaler_8:
			CLEAR_BIT(TCCR1B , CS12); SET_BIT(TCCR1B , CS11); CLEAR_BIT(TCCR1B , CS10);
			Timer1_global_prescaler = 8;
			break;
			
		case TIMER1_Prescaler_64:
			CLEAR_BIT(TCCR1B , CS12); SET_BIT(TCCR1B , CS11); SET_BIT(TCCR1B , CS10);
			Timer1_global_prescaler = 64;
			break;
			
		case TIMER1_Prescaler_256:
			SET_BIT(TCCR1B , CS12); CLEAR_BIT(TCCR1B , CS11); CLEAR_BIT(TCCR1B , CS10);
			Timer1_global_prescaler = 256;
			break;
			
		case TIMER1_Prescaler_1024:
			SET_BIT(TCCR1B , CS12); CLEAR_BIT(TCCR1B , CS11); SET_BIT(TCCR1B , CS10);
			Timer1_global_prescaler = 1024;
			break;
	
	}
}
void Timer1_stop(void)
{
	CLEAR_BIT(TCCR1B , CS12); CLEAR_BIT(TCCR1B , CS11); CLEAR_BIT(TCCR1B , CS10);
	Timer1_global_prescaler = 0;
}

void Timer1_without_interrupt_initialization(TIMER1_Mode mode , TIMER1_Pin_Mode pin_mode , TIMER1_Channel channel)
{
	cli();
	CLEAR_BIT(TIMSK , TOIE1);
	switch(mode)
	{
		case TIMER1_Normal:
			CLEAR_BIT(TCCR1B , WGM13); CLEAR_BIT(TCCR1B , WGM12); CLEAR_BIT(TCCR1A , WGM11); CLEAR_BIT(TCCR1A , WGM10); 
			break;
		case TIMER1_CTC_OCR:
			CLEAR_BIT(TCCR1B , WGM13); SET_BIT(TCCR1B , WGM12); CLEAR_BIT(TCCR1B , WGM11); CLEAR_BIT(TCCR1B , WGM10);
			break;
		
		default:
			break;
	}
	
	// non pwm
	switch(channel)
	{
		case TIMER1_Channel_A:
			switch(pin_mode)
			{
				case TIMER1_PIN_Disconnected:
					CLEAR_BIT(TCCR1A , COM1A1); CLEAR_BIT(TCCR1A , COM1A0);
					break;
				case TIMER1_PIN_Toggle:
					CLEAR_BIT(TCCR1A , COM1A1); SET_BIT(TCCR1A , COM1A0);
					break;
				case TIMER1_PIN_Clear:
					SET_BIT(TCCR1A , COM1A1); CLEAR_BIT(TCCR1A , COM1A0);
					break;
				case TIMER1_PIN_Set:
					SET_BIT(TCCR1A , COM1A1); SET_BIT(TCCR1A , COM1A0);
					break;
			}
		
			break;
		case TIMER1_Channel_B:
			switch(pin_mode)
			{
				case TIMER1_PIN_Disconnected:
					CLEAR_BIT(TCCR1A , COM1B1); CLEAR_BIT(TCCR1A , COM1B0);
					break;
				case TIMER1_PIN_Toggle:
					CLEAR_BIT(TCCR1A , COM1B1); SET_BIT(TCCR1A , COM1B0);
					break;
				case TIMER1_PIN_Clear:
					SET_BIT(TCCR1A , COM1B1); CLEAR_BIT(TCCR1A , COM1B0);
					break;
				case TIMER1_PIN_Set:
					SET_BIT(TCCR1A , COM1B1); SET_BIT(TCCR1A , COM1B0);
					break;
			}
			break;
	}
	
}


void Timer1_without_interrupt_setDelay(TIMER1_Mode mode , uint32_t delay , uint16_t top)
{
	if(mode == TIMER1_Normal)
	{
		uint16_t tick = (Timer1_global_prescaler) / CPU_FREQUENCY;
		uint32_t count = (delay * milli) / tick;
		uint16_t ovf = count / BITS;
		ovf++;
		uint16_t initial_value = BITS - (count % BITS);
		uint32_t my_counter = 0;
		TCNT1 = initial_value;
		while(my_counter < ovf)
		{
			while(GET_BIT(TIFR , TOV1) != 1);
			my_counter++;
			SET_BIT(TIFR , TOV1); // Clear flag
		}
	}
}



void Timer1_with_interrupt_initialization(TIMER1_Mode mode , TIMER1_Pin_Mode pin_mode , TIMER1_Channel channel)
{
	cli();
	switch(mode)
	{
		case TIMER1_Normal:
			CLEAR_BIT(TCCR1B , WGM13); CLEAR_BIT(TCCR1B , WGM12); CLEAR_BIT(TCCR1A , WGM11); CLEAR_BIT(TCCR1A , WGM10);
			SET_BIT(TIMSK , TOIE1);
			break;
		case TIMER1_CTC_OCR:
			CLEAR_BIT(TCCR1B , WGM13); SET_BIT(TCCR1B , WGM12); CLEAR_BIT(TCCR1B , WGM11); CLEAR_BIT(TCCR1B , WGM10);
			// SET_BIT(TIMSK , TOIE1);
			break;
		
		default:
			break;
	}
	
	// non pwm
	switch(channel)
	{
		case TIMER1_Channel_A:
			switch(pin_mode)
			{
				case TIMER1_PIN_Disconnected:
					CLEAR_BIT(TCCR1A , COM1A1); CLEAR_BIT(TCCR1A , COM1A0);
					break;
				case TIMER1_PIN_Toggle:
					CLEAR_BIT(TCCR1A , COM1A1); SET_BIT(TCCR1A , COM1A0);
					break;
				case TIMER1_PIN_Clear:
					SET_BIT(TCCR1A , COM1A1); CLEAR_BIT(TCCR1A , COM1A0);
					break;
				case TIMER1_PIN_Set:
					SET_BIT(TCCR1A , COM1A1); SET_BIT(TCCR1A , COM1A0);
					break;
			}
			
			break;
		case TIMER1_Channel_B:
			switch(pin_mode)
			{
				case TIMER1_PIN_Disconnected:
				CLEAR_BIT(TCCR1A , COM1B1); CLEAR_BIT(TCCR1A , COM1B0);
				break;
				case TIMER1_PIN_Toggle:
				CLEAR_BIT(TCCR1A , COM1B1); SET_BIT(TCCR1A , COM1B0);
				break;
				case TIMER1_PIN_Clear:
				SET_BIT(TCCR1A , COM1B1); CLEAR_BIT(TCCR1A , COM1B0);
				break;
				case TIMER1_PIN_Set:
				SET_BIT(TCCR1A , COM1B1); SET_BIT(TCCR1A , COM1B0);
				break;
			}
			break;
	}
	sei();
}

uint16_t TIMER1_OVF ;
void Timer1_with_interrupt_setDelay(TIMER1_Mode mode , uint32_t delay , uint16_t top)
{
	if(mode == TIMER1_Normal)
	{
		uint16_t tick = (Timer1_global_prescaler) / CPU_FREQUENCY;
		uint32_t count = (delay * milli) / tick;
		uint16_t TIMER1_OVF = count / BITS;
		TIMER1_OVF++;
		uint16_t initial_value = BITS - (count % BITS);
		uint32_t my_counter = 0;
		TCNT1 = initial_value;

	}
}