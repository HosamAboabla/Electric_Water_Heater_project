/*
 * Interrupt_Addres.h
 *
 * Created: 12/10/2021 1:37:16 PM
 *  Author: karim
 */ 


#ifndef INTERRUPT_ADDRES_H_
#define INTERRUPT_ADDRES_H_

#define SREG   (*(volatile uint8_t*) 0x5F)
#define GICR   (*(volatile uint8_t*) 0x5B)
#define GIFR   (*(volatile uint8_t*) 0x5A)
#define MCUSR  (*(volatile uint8_t*) 0x55)
#define MCUCSR (*(volatile uint8_t*) 0x54)


#endif /* INTERRUPT_ADDRES_H_ */