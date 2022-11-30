/*
 * main.c
 * Created: 3/26/2022 7:57:17 PM
 *  Author: EN.Eslam
 */ 

#include "MCAL/DIO_private.h"
#include "BIT_MATH.h"
#include "STD.h"
#define F_CPU 16000000UL
#include <avr/delay.h>




 void _7seg_init(void);

int main(void)
{
_7seg_init();
KeyPad_init();


SET_BIT(PORTB,PIN1);//EN2 output pin


SINT8 value=0,KEY;

while(1){
	
// 	value=KeyPad_GetKey();
// 	if( value!=0)
// 	DIO_PORTA = ((value-'0')<<4)|(DIO_PORTA & 0x0F);

	KEY=KeyPad_GetKey();
		
			
		if(KEY=='A') {value++;_delay_ms(150);}
			
		if(KEY=='B') {value--;_delay_ms(150);}
			if(value>99) value=99;
			else if (value<0) value=0;

	
		SET_BIT(PORTB,PIN2);//EN1 output pin
	
		PORTA = ((value/10)<<4)|(PORTA & 0x0F);
		_delay_ms(10);
		
		CLEAR_BIT(PORTB,PIN2);//EN1 output pin
	
		SET_BIT(PORTB,PIN1);//EN2 output pin
	
		PORTA = ((value %10)<<4)|(PORTA & 0x0F);
	   _delay_ms(10);
	
		CLEAR_BIT(PORTB,PIN1);//EN2 output pin
	
		
	
}


}

 void _7seg_init(void){
	 
	 SET_BIT(DIO_DDRA,PIN4);//output pin
	 SET_BIT(DIO_DDRA,PIN5);//output pin
	 SET_BIT(DIO_DDRA,PIN6);//output pin
	 SET_BIT(DIO_DDRA,PIN7);//output pin
	 //enable pins EN1 and EN2
	 SET_BIT(DIO_DDRB,PIN1);//EN1 output pin
	 SET_BIT(DIO_DDRB,PIN2);//EN2 output pin
 
 }