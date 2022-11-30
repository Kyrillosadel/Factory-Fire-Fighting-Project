#define F_CPU 16000000UL
#include <util/delay.h>
#include "STD.h"
#include "MCAL/Timer_interface.h"
#include "HAL/LCD_interface.h"
#include <avr/interrupt.h>



Uint8 NO_OVF=0,HOUR=12,MIN=51,SEC=5;

int main ()

{
	SET_BIT(DDRA,3);
	Timer0_INIT();
	LCD_init();
	Timer0_Start();
	
	/*to write it only one time at the start of the code */
	LCD_GoTo(0,0);
	LCD_WriteSTRING("Hour");
	LCD_WriteCHAR(':');
	LCD_WriteSTRING("Min");
	LCD_WriteCHAR(':');
	LCD_WriteSTRING("Sec");
	
	

	while(1)
	{
		
		LCD_GoTo(1,0);
		LCD_WriteSTRING(" ");
		LCD_WriteNUM(HOUR);
		LCD_WriteSTRING(" : ");
		LCD_WriteNUM(MIN);
		LCD_WriteSTRING(" : ");
		LCD_WriteNUM(SEC);
		

		

		if(SEC==60){
			SEC=0;
			MIN++;
			
			
		}
		
		if(MIN==60){
			
			MIN=0;
			HOUR++;
			

		}
		
		if(HOUR==24){
			HOUR=0;
			
		}
		

	}
}


ISR(TIMER0_OVF_vect){
	
	
	NO_OVF++;
	
	if (NO_OVF==61)
	{
		SEC++;
		SET_BIT(PORTA,3);
		NO_OVF=0;
	}
	if (NO_OVF==2) CLEAR_BIT(PORTA,3);

	TIMSK= (1<<TOV0); //CLEAR timer OverFlow interrupt Flag
	
}


