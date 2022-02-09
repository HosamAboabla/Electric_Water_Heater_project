/*
* Timer0_Configuration.h
*
* Created: 12/17/2021 1:14:37 PM
*  Author: karim
*/


#ifndef TIMER2_CONFIGURATION_H_
#define TIMER2_CONFIGURATION_H_

#include "Configuration.h"

#define Frequency    16
#define Microsecond  1000
#define Bits         256

//#include "Timer2_Address.h"
//Data type for mode
typedef enum
{
	Normal_Mode_ = 0,
	PWM_PhaseCorrect_ = 1,
	CTC_Mode_ = 2,
	PWM_Fast_ = 3
}Timer2_Mode;
//Data type for pin mode
typedef enum
{
	Pin_disconnected_ = 0,
	Pin_Toggle_ = 1,
	Pin_Clear_ = 2,
	Pin_Set_ = 3
}Timer2_Pin_Mode;
//Data type for pre-scaler
typedef enum
{
	PreS_0_ = 0,
	PreS_1_ = 1,
	PreS_8_ = 2,
	PreS_64_ = 3,
	PreS_256_ = 4,
	PreS_1024_ = 5
}Timer2_Prescaler;
//Data type for PWM Mode
typedef enum
{
	Non_Inverting_= 0,
	Inverting_
}PWM_Mode_;

#endif /* TIMER2_CONFIGURATION_H_ */