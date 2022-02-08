/*
* TWI_Configuration.h
*
* Created: 1/8/2022 9:49:13 AM
*  Author: karim
*/


#ifndef TWI_CONFIGURATION_H_
#define TWI_CONFIGURATION_H_

#include "Configuration.h"
#include "TWI_Address.h"

typedef enum
{
	TWI_Slave = 0,
	TWI_Master = 1
}TWI_Mode;

#define	START_ACK             0X08 //Start has been transmitted
#define REP_START_ACK         0x10 //Repeated start has been transmitted
#define SLAVE_ADD_WR_ACK      0x18 //Master transmit (Slave address + write request) received ACK
#define SLAVE_ADD_RD_ACK      0x40 //Master transmit (Slave address + read request) received ACK
#define WR_BYTE_ACK           0x28 //Master transmit (Data) received ACK
#define RD_BYTE_ACK           0x50 //Master received data with ACK
#define RD_BYTE_NACK          0x58 //Master received data with no ACK
#define SLAVE_ADD_RCVD_WR_REQ 0x60 //Slave address received with read request
#define SLAVE_ADD_RCVD_RD_REQ 0xA8 //Slave address received with write request
#define SLAVE_DATA_RECEIVED   0x80 //Read byte request received
#define SLAVE_DATA_TRANSMIT   0xC0 //Write byte request received 
#define Stop_ACK              0xA0 //Stop condition has been transmitted

//Master write to slave
/*
Write schedule here
*/
//Master read from slave
/*
Write schedule here
*/
//Slave read from master
/*
Write schedule here
*/
//Slave write on master
/*
Write schedule here
*/

#endif /* TWI_CONFIGURATION_H_ */