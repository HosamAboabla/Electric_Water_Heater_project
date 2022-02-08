/*
 * LED1.c
 *
 * Created: 11/27/2021 1:16:03 PM
 *  Author: karim
 */ 
#include "LED1.h"

void LED1_Initialization(void)
{
	SET_BIT(LED1_DDR, LED1);
}
void LED1_ON(void)
{
	SET_BIT(LED1_PORT, LED1);
}
void LED1_OFF(void)
{
	CLR_BIT(LED1_PORT, LED1);
}
void LED1_TGL(void)
{
	TGL_BIT(LED1_PORT, LED1);
}