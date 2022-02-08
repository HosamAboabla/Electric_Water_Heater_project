/*
* Timer0_Configuration.h
*
* Created: 12/17/2021 1:14:37 PM
*  Author: karim
*/


#ifndef TIMER0_CONFIGURATION_H_
#define TIMER0_CONFIGURATION_H_

#include "Configuration.h"

#define Frequency    16
#define Microsecond  1000
#define Bits         256

//#include "Timer0_Address.h"
//Data type for mode
typedef enum
{
	Normal_Mode = 0,
	PWM_PhaseCorrect = 1,
	CTC_Mode = 2,
	PWM_Fast = 3
}Timer0_Mode;
//Data type for pin mode
typedef enum
{
	Pin_disconnected = 0,
	Pin_Toggle = 1,
	Pin_Clear = 2,
	Pin_Set = 3
}Timer0_Pin_Mode;
//Data type for pre-scaler
typedef enum
{
	PreS_0 = 0,
	PreS_1 = 1,
	PreS_8 = 2,
	PreS_64 = 3,
	PreS_256 = 4,
	PreS_1024 = 5
}Timer0_Prescaler;
//Data type for PWM Mode
typedef enum
{
	Non_Inverting= 0,
	Inverting
}PWM_Mode;

#endif /* TIMER0_CONFIGURATION_H_ */