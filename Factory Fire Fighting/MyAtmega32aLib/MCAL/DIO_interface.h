





/*
 * DIO.h
 *
 * Created: 5/26/2021 12:44:58 PM
 *  Author: TEAM B
  */


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_private.h"
#include "DIO_config.h"
#include "../Utilities/STD.h"
#include "../Utilities/BITMATH.h"

#define OFF 0
#define ON  1

typedef enum {DIO_PORTA,
			  DIO_PORTB,
			  DIO_PORTC,
			  DIO_PORTD} PORT_TYPE;

typedef enum {PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7} PIN_TYPE;

typedef enum {LOW_PIN,
			  HIGH_PIN} STATE_TYPE;

typedef enum {INPUT_PIN,OUTPUT_PIN} DIR_TYPE;	
	
typedef enum {Data_H_To_Port_H,
			  Data_L_To_Port_H, 
	          Data_H_To_Port_L,
			  Data_L_To_Port_L} NIPPLE_TYPE;

	
	

void DIO_SetPinDir(PORT_TYPE , PIN_TYPE , DIR_TYPE );

void DIO_SetPinVal(PORT_TYPE , PIN_TYPE , STATE_TYPE);

void DIO_TogglePin(PORT_TYPE , PIN_TYPE);

STATE_TYPE DIO_GetPinVal(PORT_TYPE,PIN_TYPE);

void DIO_SetPullup(PORT_TYPE , PIN_TYPE );


void DIO_SetPortNibble(PORT_TYPE , Uint8 Data,NIPPLE_TYPE );



#endif 