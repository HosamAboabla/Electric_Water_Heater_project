/*
 * Timer2.h
 *
 * Created: 12/17/2021 1:14:49 PM
 *  Author: karim
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include "Timer2_Configuration.h"

void Timer2_Start(Timer2_Prescaler prescaler);
void Timer2_Stop(void);
//Timer Blocking mode
void Timer2_WithoutInterrupt_Initialization(Timer2_Mode mode, Timer2_Pin_Mode pin);
void Timer2_WithoutInterrupt_SetDelay(Timer2_Mode mode, uint32_t delay, uint8_t top);
//Timer Non-Blocking mode
void Timer2_WithInterrupt_Initialization(Timer2_Mode mode, Timer2_Pin_Mode pin);
void Timer2_WithInterrupt_SetDelay(Timer2_Mode mode, uint32_t delay, uint8_t top);
//Timer Fast PWM
void Timer2_Fast_PWM_Initialization(PWM_Mode_ mode);
void Timer2_Fast_PWM_SetDuty(PWM_Mode_ mode, uint8_t dutycyle);
//Timer Phase Correct PWM
void Timer2_PhaseCorrect_PWM_Initialization(PWM_Mode_ mode);
void Timer2_PhaseCorrect_PWM_SetDuty(PWM_Mode_ mode, uint8_t dutycyle);

#endif /* TIMER2_H_ */