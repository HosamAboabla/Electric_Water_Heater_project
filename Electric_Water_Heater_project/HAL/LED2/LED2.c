/*
 * LED2.c
 *
 * Created: 11/27/2021 1:16:10 PM
 *  Author: karim
 */ 
#include "LED2.h"

void LED2_Initialization(void)
{
	SET_BIT(LED2_DDR, LED2);
}
void LED2_ON(void)
{
	SET_BIT(LED2_PORT, LED2);
}
void LED2_OFF(void)
{
	CLR_BIT(LED2_PORT, LED2);
}
void LED2_TGL(void)
{
	TGL_BIT(LED2_PORT, LED2);
}