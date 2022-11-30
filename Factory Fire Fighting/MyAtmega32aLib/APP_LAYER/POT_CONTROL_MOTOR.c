/*
   by : EN ESLAM EID
*/
#define F_CPU 16000000UL

#define __DELAY_BACKWARD_COMPATIBLE__

#include <util/delay.h>
#include "BITMATH.h"
#include "STD.h"

#include "MCAL/DIO_interface.h"
#include "MCAL/Timer_private.h"
#include "MCAL/ADC_interface.h"
#include "HAL/LCD_interface.h"


#define MOTOR_1        0
#define MOTOR_2        1
#define CLOCK_WISE      0
#define ANTI_CLOCK_WISE 1

void SET_MOTOR_DIR(Uint8 MOTOR_NUM,Uint8 DIR){
	
	switch(MOTOR_NUM){
		
		case MOTOR_1:
		
		switch(DIR){
			
			case CLOCK_WISE:
			SET_BIT(PORTC,3);
			CLEAR_BIT(PORTC,4);

			
			break;
			case ANTI_CLOCK_WISE:
			
			SET_BIT(PORTC,4);
			CLEAR_BIT(PORTC,3);
			break;
			
		}
		
		
		break;
		
		case MOTOR_2 :
		
		switch(DIR){
			
			case CLOCK_WISE:
			SET_BIT(PORTC,5);
			CLEAR_BIT(PORTC,6);

			
			break;
			case ANTI_CLOCK_WISE:
			
			SET_BIT(PORTC,6);
			CLEAR_BIT(PORTC,5);
			break;
			
		}
		break;
		
	}
	
}


void MOTOR_INIT(){
	
	SET_BIT(DDRC,3);
	SET_BIT(DDRC,4);

	SET_BIT(DDRC,5);
	SET_BIT(DDRC,6);
	
	SET_BIT(DDRD,4);
	SET_BIT(DDRD,5);
	
	
}


void Timer1_Fast_PWM_Init( ){

	TCCR1A = (1<<WGM11) | (1<<COM1A1);

	TCCR1B = (1<<WGM12) | (1<<WGM13)  |  (1<<CS10) ;	 // pre-scaler =1
	ICR1 = 100;	/* Set TOP that produce 5KHZ */
}


void SET_MOTOR_SPEED( Uint16 SPEED)
{
	TCNT1 = 0;		   /* Set timer1 initial count to zero */
	
	if(SPEED>100) SPEED=100;
	OCR1A = SPEED; /* Set the compare value */


}





int main ()
{
	LCD_init();
	ADC_INIT();
	Timer1_Fast_PWM_Init();
	MOTOR_INIT();
	Uint16 speed;

	while(1)
	{
		speed=ADC_Read(ADC1)/10;
		SET_MOTOR_DIR(MOTOR_2,CLOCK_WISE);
		SET_MOTOR_SPEED(speed);
		LCD_GoTo(0,0);
		LCD_WriteNUM(speed);
		_delay_ms(500);
		
	}
}



#include "HAL/EEPROM.h"
#define F_CPU 16000000UL

#define __DELAY_BACKWARD_COMPATIBLE__

#include <util/delay.h>
#include "BITMATH.h"
#include "STD.h"
#include "MCAL/DIO_interface.h"
#include "HAL/LCD_interface.h"


int main(void)
{
	LCD_init();
	EEPROM_INIT();
	
	EEPROM_WriteByte(0,'S');
		LCD_WriteCHAR('1');

	EEPROM_WriteByte(1,'A');
			LCD_WriteCHAR('2');

	EEPROM_WriteByte(2,'H');
			LCD_WriteCHAR('3');

	EEPROM_WriteByte(3,'R');
				LCD_WriteCHAR('4');

	
	Uint16 i=0;
	Uint8 ch;
	while (1)
	{
	LCD_GoTo(0,0);
	//ch=EEPROM_ReadByte(i);
	LCD_WriteCHAR('s');
	_delay_ms(500);
	
	i++;
			
		
		
	}

	
}


