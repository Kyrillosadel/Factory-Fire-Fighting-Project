/*
* Temp.c
*
* Created: 7/13/2022 6:10:18 PM
*  Author: TEAM B
*/
#include "Temp_interface.h"
#include "../MCAL/DIO_interface.h"
#include "../MCAL/ADC_interface.h"
#include "../HAL/LCD_interface.h"
#define F_CPU 16000000UL         // AVR FREQUENCY 16MHz
#include <util/delay.h>



Uint8 PASS_ERROR=0 ;           //FLAG
void password(void)
{
	Uint8 CHECK[4];
	Uint8 Key;
	Uint8 i;
	
	for (i=0;i<4;i++)             //PASSWORD LOOP FOR 4 CHARACTERS
	{
		Key=KeyPad_GetKey();      //Wait FOR User to enter key
		_delay_ms(50);
		
		while(Key==0)			//IF NO KEY Wait Until KEY not equal NUll
		{
			Key= KeyPad_GetKey();
			_delay_ms(50);
		};
		
		CHECK[i]=Key;           //FILL User Password Into Array
		_delay_ms(50);
		LCD_WriteCHAR(Key);		//Write PASSWORD  ON LCD
		
	}							// END OF PASSWORD LOOP

	if((CHECK[0]=='1') && (CHECK[1]=='2') && (CHECK[2]=='3') && (CHECK[3] =='4') )  //PASSWORD ----> 1234
	
	{// IF PASSWORD CORRECT
		
		LCD_Clear();
		LCD_WriteSTRING("Correct Pass");
		_delay_ms(300);
		LCD_Clear();
		Key=KeyPad_GetKey();
		_delay_ms(50);
		LCD_WriteCHAR(Key);
		DIO_SetPinVal(DIO_PORTD,PIN1,LOW_PIN);			//Buzzer OFF
		DIO_SetPinVal(DIO_PORTC,PIN0,LOW_PIN);			//MOTOR OFF
		PASS_ERROR=0;
	}
	
	if(CHECK[0]!='1' || CHECK[1]!='2' || CHECK[2]!='3' || CHECK[3]!='4'){
		DIO_SetPinVal(DIO_PORTD,PIN1,HIGH_PIN);
		DIO_SetPinVal(DIO_PORTC,PIN0,HIGH_PIN);
		_delay_ms(200);
		LCD_Clear();
		LCD_GoTo(1,3);
		LCD_WriteSTRING("Try Again");
		_delay_ms(500);
		LCD_Clear();
		
		LCD_WriteSTRING("ENTER PASS");
		PASS_ERROR =1;
	}

	
	
	
}

void reading_init(void) //MAIN APP
{
	float a;  //READ FROM ADC
	float c;  // CASTING FROM 0-1024 TO 0-100
	Uint16 b; //TEMPERATURE
	a=ADC_Read(ADC1);
	c=((a/1023)*100);
	b=(Uint16)c;
	LCD_GoTo(0,0);
	LCD_WriteSTRING("Temperature ");
	
	if(b<30 && PASS_ERROR==0)					//Normal Mode
	{
		
		LCD_GoTo(1,0);
		LCD_WriteSTRING("MODE:Normal");
		LCD_GoTo(0,0);
		LCD_WriteSTRING("Temperature ");
		LCD_WriteNUM(b);						 //TEMP FROM POT
		DIO_SetPinVal(DIO_PORTC,PIN2,HIGH_PIN);  //MACHINE LED 1  ((C2))
		DIO_SetPinVal(DIO_PORTC,PIN7,HIGH_PIN);  //MACHINE LED 2  ((C7))
		DIO_SetPinVal(DIO_PORTD,PIN0,HIGH_PIN);  //MACHINE LED 3  ((D0))
		
		_delay_ms(300);
		LCD_Clear();
	}
	else if (b>=30 && b<70 && PASS_ERROR==0)
	{
		
		LCD_GoTo(0,0);
		LCD_WriteSTRING("Temperature ");
		LCD_WriteNUM(b);
		DIO_SetPinVal(DIO_PORTC,PIN2,LOW_PIN); //MACHINE LED 1  ((C2))
		DIO_SetPinVal(DIO_PORTC,PIN7,LOW_PIN); //MACHINE LED 2  ((C7))
		DIO_SetPinVal(DIO_PORTD,PIN0,LOW_PIN); //MACHINE LED 3  ((D0))
		_delay_ms(300);
		LCD_Clear();
	}
	
	else if(b>=70 && b<=85 && PASS_ERROR==0)   //HOT Mode
	{
		
		LCD_GoTo(0,0);
		LCD_WriteSTRING("Temperature ");
		LCD_WriteNUM(b);
		LCD_GoTo(1,0);
		LCD_WriteSTRING("MODE:Hot");
		DIO_SetPinVal(DIO_PORTD,PIN1,HIGH_PIN);  // BUZZER ON  ((A3))
		_delay_ms(500);							//  BUZZER Toggle
		DIO_SetPinVal(DIO_PORTD,PIN1,LOW_PIN);  // BUZZER OFF  ((A3))
		LCD_Clear();
	}
	else if (b>85 && b<95 && PASS_ERROR==0)    //OUT OF RANGE
	{
		
		LCD_GoTo(0,0);
		LCD_WriteSTRING("Temperature ");
		LCD_WriteNUM(b);
		_delay_ms(300);
		DIO_SetPinVal(DIO_PORTD,PIN1,LOW_PIN);  //NO BUZZER
		LCD_Clear();
	}
	else if(b>=95 || PASS_ERROR==1)            //FIRE MODE 
	{
		
		LCD_GoTo(0,0);
		LCD_WriteSTRING("Temperature ");
		LCD_WriteNUM(b);
		LCD_GoTo(1,0);
		LCD_WriteSTRING("MODE:Fire");
		_delay_ms(500);
		DIO_SetPinVal(DIO_PORTD,PIN1,HIGH_PIN);  //BUZZER ON
		DIO_SetPinVal(DIO_PORTC,PIN0,HIGH_PIN);	 //MOTOR ON
		LCD_Clear();
		_delay_ms(300);
		LCD_WriteSTRING("ENTER PASS ");
		password();
	}
	
}
