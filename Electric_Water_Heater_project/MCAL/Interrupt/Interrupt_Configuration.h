/*
* Interrupt_Configuration.h
*
* Created: 12/10/2021 1:37:30 PM
*  Author: karim
*/


#ifndef INTERRUPT_CONFIGURATION_H_
#define INTERRUPT_CONFIGURATION_H_

#include "Configuration.h"
//#include "Interrupt_Addres.h"

#define GLOBAL_DS 0
#define GLOBAL_EN 1

#define  LOW_SIGNAL      0
#define  HIGH_SIGNAL     1
#define  Falling_SIGNAL  2
#define  RISING_SIGNAL   3

#define Interrupt_SENSE           RISING_SIGNAL
#define Global_INTERRUPT_STATUS   GLOBAL_EN

typedef enum
{
	INT0_Signal = 0,
	INT1_Signal = 1,
	INT2_Signal = 2
}Interrupt_Signal_Pin;

#endif /* INTERRUPT_CONFIGURATION_H_ */