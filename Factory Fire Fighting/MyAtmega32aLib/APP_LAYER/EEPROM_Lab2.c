#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include "BITMATH.h"
#include "STD.h"
#include "HAL/EEPROM.h"
#include "MCAL/DIO_interface.h"
#include "HAL/LCD_interface.h"

Uint8 *Rxname;

int main ()
{
	LCD_init();
	EEPROM_INIT();
	Uint8 i=0;
	LCD_GoTo(0,0);
	EEPROM_WriteString(1,0,"HELLO ESLAM EID");
	Rxname=EEPROM_ReadString(1,0);
	LCD_WriteSTRING(Rxname);
	while(1){
		
		LCD_WriteCMD(Shift_Entire_Display_Left);
		_delay_ms(150);


    }

}