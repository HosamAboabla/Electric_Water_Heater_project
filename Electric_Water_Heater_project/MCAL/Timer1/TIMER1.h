/*
 * TIMER1.h
 *
 * Created: 1/15/2022 10:47:53 PM
 *  Author: hosam
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "TIMER1_Configurations.h"

void Timer1_start(TIMER1_Prescaler prescaler);
void Timer1_stop(void);

void Timer1_without_interrupt_initialization(TIMER1_Mode mode , TIMER1_Pin_Mode pin_mode , TIMER1_Channel channel);
void Timer1_without_interrupt_setDelay(TIMER1_Mode mode , uint32_t delay , uint16_t top);

void Timer1_with_interrupt_initialization(TIMER1_Mode mode , TIMER1_Pin_Mode pin_mode , TIMER1_Channel channel);
void Timer1_with_interrupt_setDelay(TIMER1_Mode mode , uint32_t delay , uint16_t top);


#endif /* TIMER1_H_ */