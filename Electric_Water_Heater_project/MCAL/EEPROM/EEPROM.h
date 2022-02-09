/*
 * EEPROM.h
 *
 * Created: 2/9/2022 10:21:10 PM
 *  Author: hosam
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "EEPROM_Configurations.h"

void EEPROM_Write(uint16_t address , uint8_t data);
uint8_t EEPROM_Read(uint16_t adderss);


#endif /* EEPROM_H_ */