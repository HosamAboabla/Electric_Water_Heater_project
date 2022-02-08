/*
 * Bit_Math.h
 *
 * Created: 11/27/2021 12:17:49 PM
 *  Author: karim
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG, BIT) REG |= (1<<BIT)
#define CLR_BIT(REG, BIT) REG &=~(1<<BIT)
#define TGL_BIT(REG, BIT) REG ^= (1<<BIT)
#define GET_BIT(REG, BIT) ((REG>>BIT)&0X01)

#endif /* BIT_MATH_H_ */