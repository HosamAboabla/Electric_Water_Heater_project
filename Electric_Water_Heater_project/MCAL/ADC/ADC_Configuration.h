/*
* ADC_Configuration.h
*
* Created: 12/11/2021 1:18:26 PM
*  Author: karim
*/


#ifndef ADC_CONFIGURATION_H_
#define ADC_CONFIGURATION_H_

#include "Configuration.h"
#include "ADC_Address.h"

typedef enum
{
	ADC0 = 0,
	ADC1 = 1,
	ADC2 = 2,
	ADC3 = 3,
	ADC4 = 4,
	ADC5 = 5,
	ADC6 = 6,
	ADC7 = 7
}ADC_Chanel;

#define FREE_RUNNING_MODE 0

#define ADC_Mode FREE_RUNNING_MODE

#endif /* ADC_CONFIGURATION_H_ */