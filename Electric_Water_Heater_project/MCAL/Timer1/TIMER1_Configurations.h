/*
 * TIMER1_Configurations.h
 *
 * Created: 1/15/2022 10:48:18 PM
 *  Author: hosam
 */ 


#ifndef TIMER1_CONFIGURATIONS_H_
#define TIMER1_CONFIGURATIONS_H_

#include "CONFIGURATION.h"



#define CPU_FREQUENCY 16
#define BITS 65536
#define milli 1000

typedef enum
{
	TIMER1_Normal = 0,
	TIMER1_PWM_Phase_Correct_8,
	TIMER1_PWM_Phase_Correct_9,
	TIMER1_PWM_Phase_Correct_10,
	TIMER1_CTC_OCR,
	TIMER1_FAST_PWM_8,
	TIMER1_FAST_PWM_9,
	TIMER1_FAST_PWM_10,
	TIMER1_Phase_Correct_Frequencey_Correct_ICR,
	TIMER1_Phase_Correct_Frequencey_Correct_OCR,
	TIMER1_CTC_Mode_1,
	TIMER1_PWM_Fast_ICR,
	TIMER1_PWM_Fast_OCR
}TIMER1_Mode;

typedef enum
{
	TIMER1_PIN_Disconnected = 0,
	TIMER1_PIN_Toggle,
	TIMER1_PIN_Clear,
	TIMER1_PIN_Set
}TIMER1_Pin_Mode;


typedef enum
{
	TIMER1_Prescaler_0 = 0,
	TIMER1_Prescaler_1,
	TIMER1_Prescaler_8,
	TIMER1_Prescaler_64,
	TIMER1_Prescaler_256,
	TIMER1_Prescaler_1024
}TIMER1_Prescaler;


typedef enum
{
	TIMER1_Channel_A = 0,
	TIMER1_Channel_B
}TIMER1_Channel;

#endif /* TIMER1_CONFIGURATIONS_H_ */