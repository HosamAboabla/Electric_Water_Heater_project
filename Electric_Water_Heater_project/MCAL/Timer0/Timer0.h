/*
 * Timer0.h
 *
 * Created: 12/17/2021 1:14:49 PM
 *  Author: karim
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "Timer0_Configuration.h"

void Timer0_Start(Timer0_Prescaler prescaler);
void Timer0_Stop(void);
//Timer Blocking mode
void Timer0_WithoutInterrupt_Initialization(Timer0_Mode mode, Timer0_Pin_Mode pin);
void Timer0_WithoutInterrupt_SetDelay(Timer0_Mode mode, uint32_t delay, uint8_t top);
//Timer Non-Blocking mode
void Timer0_WithInterrupt_Initialization(Timer0_Mode mode, Timer0_Pin_Mode pin);
void Timer0_WithInterrupt_SetDelay(Timer0_Mode mode, uint32_t delay, uint8_t top);
//Timer Fast PWM
void Timer0_Fast_PWM_Initialization(PWM_Mode mode);
void Timer0_Fast_PWM_SetDuty(PWM_Mode mode, uint8_t dutycyle);
//Timer Phase Correct PWM
void Timer0_PhaseCorrect_PWM_Initialization(PWM_Mode mode);
void Timer0_PhaseCorrect_PWM_SetDuty(PWM_Mode mode, uint8_t dutycyle);

#endif /* TIMER0_H_ */