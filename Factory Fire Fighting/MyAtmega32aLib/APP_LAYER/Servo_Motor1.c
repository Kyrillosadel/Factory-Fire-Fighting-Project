
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
	
	ICR1 = 2499 ;			  // TOP = (F_CPU/(64*50))-1


	TCCR1A = (1<<WGM11) | (1<<COM1A1);

	TCCR1B = (1<<WGM12) | (1<<WGM13)  | (1<<CS11) | (1<<CS10) ;
}





int main ()
{
	SET_BIT(DDRA,3);
	DDRD |= (1<<5);	/* Make OC1A pin as output */

	Timer1_Fast_PWM_Init();

	Uint8 i ;
	while(1)
	{
		for(i=124;i<251;i++){
		OCR1A =i; 
		_delay_ms(10);
		 }
		for(i=250;i>=124;i--){
		OCR1A =i;
		_delay_ms(10); }
		
	}
}






/*



#define F_CPU 16000000UL
#include <util/delay.h>
#include "BITMATH.h"
#include "STD.h"
#include "MCAL/DIO_interface.h"
#define FULL_WAVE_STEPS 4

int main()
{
	Uint8 motor_steps[FULL_WAVE_STEPS] = {12,6,3,9};
	Uint8 count = 0;
	DDRC |= 0x0F; //configure first 4 pins in PORTC as output pins
	
	while(1)
	{	 		
		// move the motor to the next step
		PORTC = (motor_steps[count] & 0x0F) | (PORTC & 0xF0);
		count++;
		if(count == FULL_WAVE_STEPS)
		{
			//start from the beginning after finish the full motor rotation.
			count = 0;
		}
		
		
		
	}
}



*/