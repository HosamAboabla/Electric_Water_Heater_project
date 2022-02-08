/*
 * ADC.h
 *
 * Created: 12/11/2021 1:18:34 PM
 *  Author: karim
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "ADC_Configuration.h"

void ADC_Initialization(ADC_Chanel chanel);

uint16_t ADC_Read(void);


#endif /* ADC_H_ */