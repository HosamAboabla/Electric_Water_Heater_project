/*
 * TIMER1_Addresses.h
 *
 * Created: 1/15/2022 10:48:05 PM
 *  Author: hosam
 */ 


#ifndef TIMER1_ADDRESSES_H_
#define TIMER1_ADDRESSES_H_

#define TIFR (*(volatile uint8_t*) 0x58)
#define TIMSK (*(volatile uint8_t*) 0x59)

#define TCCR1A (*(volatile uint8_t*) 0x4F)
#define TCNT1 (*(volatile uint16_t*) 0x4C)
#define OCR1A (*(volatile uint16_t*) 0x4A)
#define OCR1B (*(volatile uint16_t*) 0x48)
#define ICR1 (*(volatile uint16_t*) 0x46)




#endif /* TIMER1_ADDRESSES_H_ */