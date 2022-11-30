/*
EXT_Interrupt Quize 

Implement a C code to toggle between leds (LED0,LED1,LED2)
 through extranal interrupt of INT0 pin

HINT :
a pulled down push button2 connected on INT0 pin (PD6) 
*/


#define  F_CPU 16000000UL
#include <util/delay.h>
#include "BITMATH.h"
#include "STD.h"
#include "MCAL/DIO_private.h"
#include <avr/interrupt.h>
#include "MCAL/ExINT_interface.h"


#define LED0_PORT  PORTC
#define LED1_PORT  PORTC
#define LED2_PORT  PORTD

#define LED0  2
#define LED1  7
#define LED2  3

volatile Uint8 count;
int main ()
{
	ExINT_SetUp(INT0,IRQ_AT_RISING_EADGE);	/* initialize INT0 to fire interrupt with raising eadge  */

	  

	SET_BIT(DDRC,LED0); // LED0 direction is OUTPUT
	SET_BIT(DDRC,LED1); // LED1 direction is OUTPUT
	SET_BIT(DDRD,LED2); // LED2 direction is OUTPUT
	
	while(1)
	{
	   
	

		
		
	}
}

ISR(INT0_vect){
 General_Int_Disable();
count++;

   if (count==1){
	   SET_BIT(LED0_PORT,LED0);
	   CLEAR_BIT(LED1_PORT,LED1);
	   CLEAR_BIT(LED2_PORT,LED2);
   }
   else if (count==2){
	   CLEAR_BIT(LED0_PORT,LED0);
	   SET_BIT(LED1_PORT,LED1);
	   CLEAR_BIT(LED2_PORT,LED2);
   }
   else if (count==3){
	   CLEAR_BIT(LED0_PORT,LED0);
	   CLEAR_BIT(LED1_PORT,LED1);
	   SET_BIT(LED2_PORT,LED2);
	   count=0;
   }

   _delay_ms(30);

   General_Int_Enable();

}



