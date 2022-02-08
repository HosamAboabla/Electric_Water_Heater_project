/*
 * Timer0_Address.h
 *
 * Created: 12/17/2021 1:14:17 PM
 *  Author: karim
 */ 


#ifndef TIMER0_ADDRESS_H_
#define TIMER0_ADDRESS_H_

//All address will be found in register summary

#define TCCR0 (*(volatile uint8_t*) 0x53)
#define TCNT0 (*(volatile uint8_t*) 0x52)
#define TIMSK (*(volatile uint8_t*) 0x59)
#define TIFR  (*(volatile uint8_t*) 0x58)
#define OCR0  (*(volatile uint8_t*) 0x5C)



#endif /* TIMER0_ADDRESS_H_ */