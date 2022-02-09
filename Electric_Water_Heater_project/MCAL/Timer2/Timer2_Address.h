/*
 * Timer2_Address.h
 *
 * Created: 12/17/2021 1:14:17 PM
 *  Author: karim
 */ 


#ifndef TIMER2_ADDRESS_H_
#define TIMER2_ADDRESS_H_

//All address will be found in register summary

#define TCCR2 (*(volatile uint8_t*) 0x45)
#define TCNT2 (*(volatile uint8_t*) 0x44)
#define TIMSK (*(volatile uint8_t*) 0x59)
#define TIFR  (*(volatile uint8_t*) 0x58)
#define OCR2  (*(volatile uint8_t*) 0x43)



#endif /* TIMER2_ADDRESS_H_ */