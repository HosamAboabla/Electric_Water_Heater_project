/*
* TWI.c
*
* Created: 1/8/2022 9:49:29 AM
*  Author: karim
*/


#include "TWI.h"


//Define mode master or slave
void TWI_Master_Initialization(TWI_Mode mode)
{
	
	TWBR = 0xC0; //Prescaler /*0 0 0 0 1 1 0 0*/
	SET_BIT(TWCR, TWEN);//Enable Two wire interface
	/*
	if(mode == TWI_Master)
	{

	}
	else if(mode == TWI_Slave)
	{
	TWI_Slave_Initialization(mode, 1);
	}
	*/
}
void TWI_Slave_Initialization(TWI_Mode mode, uint8_t slavenumber)
{
	TWAR = (0x01 << 1);//Disable General Call and set address by 1
	switch(slavenumber)
	{
		case 1:
		//TWAR = (0x01 << 1);//Disable General Call and set address by 1
		break;
		/*
		.
		.
		.
		.
		*/
		case 127:
		//TWAR = (0xFF << 1);//Disable General Call and set address by 127
		break;
		default:
		break;
	}
	SET_BIT(TWCR, TWEA);//Enable Two wire interface acknowledgment enable
	SET_BIT(TWCR, TWEN);//Enable Two wire interface
	/*
	if(mode == TWI_Master)
	{
	TWI_Master_Initialization(TWI_Master);
	}
	else if(mode == TWI_Slave)
	{
	TWAR = (0x01 << 1);//Disable General Call and set address by 1
	switch(slavenumber)
	{
	case 1:
	//TWAR = (0x01 << 1);//Disable General Call and set address by 1
	break;
	.
	.
	.
	.
	case 127:
	//TWAR = (0xFF << 1);//Disable General Call and set address by 127
	break;
	default:
	break;
	}
	SET_BIT(TWCR, TWEA);//Enable Two wire interface acknowledgment enable
	SET_BIT(TWCR, TWEN);//Enable Two wire interface
	}
	*/
}
//Start of frame by sending (Start or Repeated Start) Condition
void TWI_Start_Condition(void)
{
	//SET_BIT(TWCR, TWSTA);//Enable start condition bit
	//SET_BIT(TWCR, TWINT);//Re-initialize flag
	TWCR |= (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while(GET_BIT(TWCR, TWINT) != 0);//Wait for flag to raise again
	while((TWSR & 0xF8) != START_ACK);//Check on status
}
void TWI_Repeated_Start_Condition(void)
{
	TWCR |= (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while(GET_BIT(TWCR, TWINT) != 0);//Wait for flag to raise again
	while((TWSR & 0xF8) != REP_START_ACK);//Check on status
}
//SLave Address + Write/Read
void TWI_Slave_Write_Data(uint8_t address)
{
	TWDR = (1<< address) | (0x00);
	TWCR |= (1 << TWINT) | (1 << TWEN); 
	while(GET_BIT(TWCR, TWINT) != 0);//Wait for flag to raise again
	while((TWSR & 0xF8) != SLAVE_ADD_RCVD_WR_REQ);//Check on status
}
void TWI_Slave_Read_Data(uint8_t address)
{
	TWDR = (1<< address) | (0x01);
	TWCR |= (1 << TWINT) | (1 << TWEN);
	while(GET_BIT(TWCR, TWINT) != 0);//Wait for flag to raise again
	while((TWSR & 0xF8) != SLAVE_ADD_RCVD_RD_REQ);//Check on status
}
//Data + Write/read
void TWI_Transmit_Data(uint8_t data)
{
	TWDR = data;
	TWCR |= (1 << TWINT) | (1 << TWEN);
	while(GET_BIT(TWCR, TWINT) != 0);//Wait for flag to raise again
	while((TWSR & 0xF8) != WR_BYTE_ACK);//Check on status
}
uint8_t TWI_Receive_Data(void)
{
	uint8_t data;
	TWCR |= (1 << TWINT) | (1 << TWEN);
	while(GET_BIT(TWCR, TWINT) != 0);//Wait for flag to raise again
	while((TWSR & 0xF8) != RD_BYTE_ACK);//Check on status
	data = TWDR;
	return data;
}
//Stop condition
void TWI_Stop_Condition(void)
{
	TWCR |= (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
	while(GET_BIT(TWCR, TWINT) != 0);//Wait for flag to raise again
	while((TWSR & 0xF8) != Stop_ACK);//Check on status
}