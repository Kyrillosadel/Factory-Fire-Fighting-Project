#define F_CPU 16000000UL						// AVR FREQUENCY 16MHz
#include <util/delay.h>
#include "HAL/LCD_interface.h"
#include "MCAL/DIO_interface.h"

#include "MCAL/ADC_interface.h"
#include "Application/Temp_interface.h"

int main ()
{

	DIO_SetPinDir(DIO_PORTC , PIN2, OUTPUT_PIN); // MACHINE 1 LED SET
	DIO_SetPinDir(DIO_PORTC , PIN7, OUTPUT_PIN); // MACHINE 2 LED SET
	DIO_SetPinDir(DIO_PORTD , PIN0, OUTPUT_PIN); // MACHINE 3 LED SET
	DIO_SetPinDir(DIO_PORTD , PIN1, OUTPUT_PIN); // BUZZER SET
	DIO_SetPinDir(DIO_PORTC , PIN0, OUTPUT_PIN); // MOTOR SET
	
	LCD_init();									 // LCD SETUP
	KeyPad_init();								 // KEYPAD SETUP
	ADC_INIT();									// ADC POT SETUP

	while(1)
	{
		reading_init();							// MAIN APP
	}
	
}


