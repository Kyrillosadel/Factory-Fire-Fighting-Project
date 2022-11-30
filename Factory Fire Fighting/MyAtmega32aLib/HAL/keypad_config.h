/*
 * keypad_config.h
 *
 * Created: 4/1/2022 8:28:20 PM
 *  Author: the samoray
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define F_CPU 16000000UL
#include <avr/delay.h> 
#include "../Utilities/BITMATH.h"
#include "../Utilities/STD.h"
#include "../MCAL/DIO_interface.h"


#define KP_COL_PORT  PORTB
#define KP_COL_DDR   DDRB

#define  KP_Col0_PIN  PIN4
#define  KP_Col1_PIN  PIN5
#define  KP_Col2_PIN  PIN6
#define  KP_Col3_PIN  PIN7


#define KP_ROW_PORT  PORTC
#define KP_Row_DDR   DDRC
#define KP_Row_PINR  PINC


#define  KP_Row0_PIN  PIN3
#define  KP_Row1_PIN  PIN4
#define  KP_Row2_PIN  PIN5
#define  KP_Row3_PIN  PIN6






#endif /* KEYPAD_CONFIG_H_ */