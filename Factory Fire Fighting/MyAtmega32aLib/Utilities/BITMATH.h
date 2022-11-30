/*
* BITMATH.h
*
* Created: 3/25/2022 5:18:32 PM
*  Author: the samoray
*/


#ifndef BITMATH_H_
#define BITMATH_H_


#define SET_BIT(REG,BIT_NUM)   ( REG |= (1<<BIT_NUM))

#define CLEAR_BIT(REG,BIT_NUM)  ( REG &=(~(1<<BIT_NUM)))

#define TOGGLE_BIT(REG,BIT_NUM) ( REG ^= (1<<BIT_NUM))

#define IS_HIGH(REG,BIT_NUM)    (REG & (1<<BIT_NUM))

#define IS_LOW(REG,BIT_NUM)  (!(REG & (1<<BIT_NUM)))

#define GET_BIT(REG,BIT_NUM)     ((REG>>BIT_NUM)&1)

#define WRITE_BIT(REG,BIT_NUM,OP)     (  (REG & (~(1<<BIT_NUM))) | (OP<<BIT_NUM) )


#define SET_H_PORT_H_DATA_NIBBLE(PORT,DATA)     (PORT=((DATA & 0xF0)|(PORT & 0x0F)))
#define SET_H_PORT_L_DATA_NIBBLE(PORT,DATA)     (PORT=((DATA <<4)|(PORT & 0x0F)))
#define SET_L_PORT_H_DATA_NIBBLE(PORT,DATA)     (PORT=((DATA>>4)|(PORT & 0xF0)))
#define SET_L_PORT_L_DATA_NIBBLE(PORT,DATA)     (PORT=((DATA & 0x0F)|(PORT & 0xF0)))


#endif /* BITMATH_H_ */