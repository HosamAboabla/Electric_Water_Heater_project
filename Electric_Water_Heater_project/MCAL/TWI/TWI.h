/*
 * TWI.h
 *
 * Created: 1/8/2022 9:49:20 AM
 *  Author: karim
 */ 


#ifndef TWI_H_

#include "TWI_Configuration.h"

//Define mode master or slave
void TWI_Master_Initialization(TWI_Mode mode);
void TWI_Slave_Initialization(TWI_Mode mode, uint8_t slavenumber);
//Start of frame by sending (Start or Repeated Start) Condition
void TWI_Start_Condition(void);
void TWI_Repeated_Start_Condition(void);
//SLave Address + Write/Read
void TWI_Slave_Write_Data(uint8_t address);
void TWI_Slave_Read_Data(uint8_t address);
//Data + Write/read
void TWI_Transmit_Data(uint8_t data);
uint8_t TWI_Receive_Data(void);
//Stop condition
void TWI_Stop_Condition(void);


#endif /* TWI_H_ */