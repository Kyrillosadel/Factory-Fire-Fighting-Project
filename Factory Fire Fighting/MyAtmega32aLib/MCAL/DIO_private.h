/*
 * DIO_private.h
 *
 * Created: 4/8/2022 2:02:58 PM
 *  Author: TEAM B
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
#include "../Utilities/STD.h"
														
	#define PIND            (*((volatile Uint8 *)  (0X30)))
	#define DDRD			(*((volatile Uint8 *)  (0X31)))
	#define PORTD			(*((volatile Uint8 *)  (0X32)))
 
    #define PINC			(*((volatile Uint8 *)  (0X33)))
	#define DDRC			(*((volatile Uint8 *)  (0X34)))
	#define PORTC			(*((volatile Uint8 *)  (0X35)))
	
    #define PINB			(*((volatile Uint8 *)  (0X36)))
	#define DDRB			(*((volatile Uint8 *)  (0X37)))
	#define PORTB			(*((volatile Uint8 *)  (0X38)))
	
	#define PINA			(*((volatile Uint8 *) (0X39)))
	#define DDRA			(*((volatile Uint8 *) (0X3A)))
	#define PORTA			(*((volatile Uint8 *) (0X3B)))



#endif /* DIO_PRIVATE_H_ */