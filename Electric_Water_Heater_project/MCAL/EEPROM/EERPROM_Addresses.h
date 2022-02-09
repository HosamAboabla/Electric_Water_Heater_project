/*
 * EERPROM_Addresses.h
 *
 * Created: 2/9/2022 10:21:21 PM
 *  Author: hosam
 */ 


#ifndef EERPROM_ADDRESSES_H_
#define EERPROM_ADDRESSES_H_


#define (*(volatile uint8_t* ) 0x) EEDR
#define (*(volatile uint8_t* ) 0x) EECR
#define (*(volatile uint16_t* ) 0x) EEAR


#endif /* EERPROM_ADDRESSES_H_ */