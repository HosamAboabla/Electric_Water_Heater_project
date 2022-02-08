/*
 * SEVSEG.h
 *
 * Created: 12/3/2021 1:16:32 PM
 *  Author: karim
 */ 


#ifndef SEVSEG_H_
#define SEVSEG_H_

#include "SEVSEG_Configuration.h"

void SEVSEG_Initialization(void);
void SEVSEG_Enable1(void);
void SEVSEG_Disable1(void);
void SEVSEG_Enable2(void);
void SEVSEG_Disable2(void);
void SEVSEG_Dot_Enable(void);
void SEVSEG_Dot_Disable(void);
void SEVSEG_Display(uint8_t number);

#endif /* SEVSEG_H_ */