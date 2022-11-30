/*
* DIO.c
*
* Created: 5/26/2021 12:45:12 PM
*  Author: TEAM B
*/
#include "DIO_interface.h"

void DIO_SetPinDir(PORT_TYPE port, PIN_TYPE pin, DIR_TYPE dir)
{
	switch (dir)
	{
		case INPUT_PIN:
		
		switch (port)
		{
			case DIO_PORTA:
			CLEAR_BIT( DDRA, pin);
			break;
			case DIO_PORTB:
			CLEAR_BIT( DDRB, pin);
			break;
			case DIO_PORTC:
			CLEAR_BIT( DDRC, pin);
			break;
			case DIO_PORTD:
			CLEAR_BIT( DDRD, pin);
			break;
			default:   //MISRA C rules
			break;
		}
		
		break;
		case OUTPUT_PIN:
		
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT( DDRA, pin);
			break;
			case DIO_PORTB:
			SET_BIT( DDRB, pin);
			break;
			case DIO_PORTC:
			SET_BIT( DDRC, pin);
			break;
			case DIO_PORTD:
			SET_BIT( DDRD, pin);
			break;
			default:   //MISRA C rules
			break;
		}
		
		break;
		
	}
}

void DIO_SetPinVal(PORT_TYPE port, PIN_TYPE pin, STATE_TYPE val) {
	switch (val)
	{
		case LOW_PIN:
		
		switch (port)
		{
			case DIO_PORTA:
			CLEAR_BIT(PORTA, pin);
			break;
			case DIO_PORTB:
			CLEAR_BIT(PORTB, pin);
			break;
			case DIO_PORTC:
			CLEAR_BIT(PORTC, pin);
			break;
			case DIO_PORTD:
			CLEAR_BIT(PORTD, pin);
			break;
			default:   //MISRA C rules
			break;
		} break;
		
		case HIGH_PIN:
		
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT(PORTA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(PORTB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC, pin);
			break;
			case DIO_PORTD:
			SET_BIT (PORTD, pin);
			break;
			default:   //MISRA C rules
			break;
		}break;
		
		
	}
}

STATE_TYPE DIO_GetPinVal(PORT_TYPE port, PIN_TYPE pin)
{
	switch (port)
	{
		case DIO_PORTA:
		return GET_BIT(PINA, pin);
		break;
		case DIO_PORTB:
		return GET_BIT(PINB, pin);
		break;
		case DIO_PORTC:
		return GET_BIT(PINC, pin);
		break;
		case DIO_PORTD:
		return GET_BIT(PIND, pin);
		break;
		default:   //MISRA C rules
		break;
	}
	
}

void DIO_SetPullup(PORT_TYPE port, PIN_TYPE pin)
{
	DIO_SetPinDir(port, pin, INPUT_PIN);
	switch (port)
	{
		case DIO_PORTA:
		SET_BIT(PORTA, pin);
		break;
		case DIO_PORTB:
		SET_BIT(PORTB, pin);
		break;
		case DIO_PORTC:
		SET_BIT(PORTC, pin);
		break;
		case DIO_PORTD:
		SET_BIT(PORTD, pin);
		break;
		default:   //MISRA C rules
		break;
	}
	
}

void DIO_SetPortNibble(PORT_TYPE port, Uint8 Data,NIPPLE_TYPE np)
{
	switch (port)
	{
		case DIO_PORTA:
		switch (np)
		{
			case Data_H_To_Port_H:
			SET_H_PORT_H_DATA_NIBBLE(PORTA,Data);
			break;
			case Data_H_To_Port_L:
			SET_L_PORT_H_DATA_NIBBLE(PORTA,Data);
			break;
			case Data_L_To_Port_H:
			SET_H_PORT_L_DATA_NIBBLE(PORTA,Data);
			break;
			case Data_L_To_Port_L:
			SET_L_PORT_L_DATA_NIBBLE(PORTA,Data);
			break;
		}
		break;
		case DIO_PORTB:
		switch (np)
		{
			case Data_H_To_Port_H:
			SET_H_PORT_H_DATA_NIBBLE(PORTB,Data);
			break;
			case Data_H_To_Port_L:
			SET_L_PORT_H_DATA_NIBBLE(PORTB,Data);
			break;
			case Data_L_To_Port_H:
			SET_H_PORT_L_DATA_NIBBLE(PORTB,Data);
			break;
			case Data_L_To_Port_L:
			SET_L_PORT_L_DATA_NIBBLE(PORTB,Data);
			break;
		}
		break;
		case DIO_PORTC:
		switch (np)
		{
			case Data_H_To_Port_H:
			SET_H_PORT_H_DATA_NIBBLE(PORTC,Data);
			break;
			case Data_H_To_Port_L:
			SET_L_PORT_H_DATA_NIBBLE(PORTC,Data);
			break;
			case Data_L_To_Port_H:
			SET_H_PORT_L_DATA_NIBBLE(PORTC,Data);
			break;
			case Data_L_To_Port_L:
			SET_L_PORT_L_DATA_NIBBLE(PORTC,Data);
			break;
		}
		break;
		case DIO_PORTD:
		switch (np)
		{
			case Data_H_To_Port_H:
			SET_H_PORT_H_DATA_NIBBLE(PORTD,Data);
			break;
			case Data_H_To_Port_L:
			SET_L_PORT_H_DATA_NIBBLE(PORTD,Data);
			break;
			case Data_L_To_Port_H:
			SET_H_PORT_L_DATA_NIBBLE(PORTD,Data);
			break;
			case Data_L_To_Port_L:
			SET_L_PORT_L_DATA_NIBBLE(PORTD,Data);
			break;
		}
		break;
	}
	
}
