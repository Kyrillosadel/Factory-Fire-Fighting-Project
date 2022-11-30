
/***********************************************************
 * ADC session Quiz:
 * Develop a C-code to Get ADC read through PotentioMeter 
 * And Display The Output on The LCD ?
 *
 ******************* 
 *Req:
 * 		1-code must be Fully Commented      
 * 		2-code must be Optmized As Much As Possible!				
 ***********************************************************/




#define F_CPU 16000000UL
#include <util/delay.h>
#include "BITMATH.h"
#include "STD.h"
#include "MCAL/ADC_interface.h"
#include "HAL/LCD_interface.h"


int main()
{
	ADC_INIT(); //initialize ADC with RESELUTION=8BIT  
	LCD_init(); //initialize LCD with 4BIT-MODE Parallel Communication 
	
	float POT_READ; // Variable To HOLD ANALOG READ FROM POT
	
	while(1)
	{	 		
		POT_READ = ADC_Read(ADC1); //START CONVERSION FROM CHANNEL 1  
		LCD_Clear();  //CLEAR LCD
		LCD_GoTo(0,0); //ReDisplay on first line first Coloumn 
		LCD_WriteFLOAT(POT_READ,1);//write on LCD With Precision(1) 
		LCD_WriteSTRING(" VOLT"); // write the Unit OF Data entered 
		_delay_ms(500); // just Delay to be able to watch the displayed Data  
		
	}
}
