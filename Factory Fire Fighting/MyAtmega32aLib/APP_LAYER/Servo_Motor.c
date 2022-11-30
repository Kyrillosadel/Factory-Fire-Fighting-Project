
#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include "BITMATH.h"
#include "STD.h"
#include "MCAL/DIO_interface.h"
#include "MCAL/Timer_private.h"




void Timer1_Fast_PWM_Init()
{
	TCNT1 = 0;
	
	ICR1 = 4999 ;			  // TOP = (F_CPU/(64*50))-1


	TCCR1A = (1<<WGM11) | (1<<COM1A1);

	TCCR1B = (1<<WGM12) | (1<<WGM13)  | (1<<CS11) | (1<<CS10) ;
}





int main ()
{
	SET_BIT(DDRA,3);
	DDRD |= (1<<5);	/* Make OC1A pin as output */

	Timer1_Fast_PWM_Init();

	Uint16 i ;
	while(1)
	 	{
	//
	// 		  OCR1A =125;
	// 		  	TCNT1 = 0;
	//
	// 		  _delay_ms(720);
	// 		 OCR1A =250;
	// 		 	TCNT1 = 0;
	//
	// 		 _delay_ms(720);
	// 		 OCR1A =375;
	// 		 	TCNT1 = 0;
	//
	// 		  _delay_ms(720);
	// 		  OCR1A =500;
	// 		  	TCNT1 = 0;
	//
	// 		  _delay_ms(720);
	// 		  OCR1A =625;
	// 		  	TCNT1 = 0;
	//
	// 		  _delay_ms(720);

	for (i=124;i<625;i+=42)	  //each 42 count = 15 deg
	{
				  OCR1A =i;
			  _delay_ms(420);

	}








	
}
}