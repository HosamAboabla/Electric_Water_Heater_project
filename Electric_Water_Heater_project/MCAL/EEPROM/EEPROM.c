/*
 * EEPROM.c
 *
 * Created: 2/9/2022 10:21:04 PM
 *  Author: hosam
 */ 


#include "EEPROM.h"

void EEPROM_Write(uint16_t address , uint8_t data)
{
	// Wait for completion of previous write 
	while(EECR & (1<<EEWE));
	/* Set up address and data registers */
	EEAR = address;
	EEDR = data;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start EEPROM write by setting EEWE */
	EECR |= (1<<EEWE);
}

uint8_t EEPROM_Read(uint16_t adderss)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address register */
	EEAR = adderss;
	/* Start EEPROM read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}