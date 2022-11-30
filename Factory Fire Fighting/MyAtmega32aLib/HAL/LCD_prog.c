/*
* LCD.c
*
* Created: 6/7/2021 11:58:33 AM
*  Author: EN.ESLAM EID
*/
#include "LCD_interface.h"
#define  F_CPU 16000000UL
#include <util/delay.h>


void LCD_init(void)
{
	_delay_ms(16);
	/*Set direction of command pins (RS, RW, E)*/
	DIO_SetPinDir(LCD_CMD_PORT, RS_PIN, OUTPUT_PIN);
	DIO_SetPinDir(LCD_CMD_PORT, RW_PIN, OUTPUT_PIN);
	DIO_SetPinDir(LCD_CMD_PORT,  E_PIN, OUTPUT_PIN);
	/*Set direction of data pins*/
	DIO_SetPinDir(LCD_DATA_PORT, LCD_PIN4, OUTPUT_PIN);
	DIO_SetPinDir(LCD_DATA_PORT, LCD_PIN5, OUTPUT_PIN);
	DIO_SetPinDir(LCD_DATA_PORT, LCD_PIN6, OUTPUT_PIN);
	DIO_SetPinDir(LCD_DATA_PORT, LCD_PIN7, OUTPUT_PIN);
	/*choose 4-bit mode*/
	LCD_WriteCMD(0x33);//function set 1
	_delay_ms(1);
	LCD_WriteCMD(0x32);//function set 2
	_delay_ms(1);
	LCD_WriteCMD( LCD_4Bit_Mode_2_Line_5X8);
	/*The number of display lines and character font
	can not be changed after this point*/
	LCD_WriteCMD(CMD_Display_ON_Cursor_Blink_OFF);
	_delay_ms(1);
	LCD_WriteCMD(CMD_Clear_Display);
	_delay_ms(2);
	LCD_WriteCMD(CMD_Shift_Cursor_Right_Per_Read_Write);
	_delay_ms(1);
	LCD_WriteCMD(CMD_Return_Home);
	_delay_ms(2);
}
void LCD_WriteCMD(Uint8 cmd)
{
	

	DIO_SetPinVal(LCD_CMD_PORT, RS_PIN, LOW_PIN);
	DIO_SetPinVal(LCD_CMD_PORT, RW_PIN, LOW_PIN);
	DIO_SetPinVal(LCD_CMD_PORT,  E_PIN, LOW_PIN);
	
	_delay_ms(1);
	
DIO_SetPinVal(LCD_CMD_PORT, E_PIN, HIGH_PIN);
DIO_SetPortNibble(LCD_DATA_PORT,cmd,Data_H_To_Port_H);
DIO_SetPinVal(LCD_CMD_PORT, E_PIN, LOW_PIN);
	_delay_ms(1);
	

DIO_SetPinVal(LCD_CMD_PORT, E_PIN, HIGH_PIN);

DIO_SetPortNibble(LCD_DATA_PORT,cmd,Data_L_To_Port_H);
	
DIO_SetPinVal(LCD_CMD_PORT, E_PIN, LOW_PIN);
	_delay_ms(1);
}
void LCD_WriteCHAR(Uint8 CHR)
{

    DIO_SetPinVal(LCD_CMD_PORT, RS_PIN, HIGH_PIN);
	DIO_SetPinVal(LCD_CMD_PORT, RW_PIN, LOW_PIN);
	DIO_SetPinVal(LCD_CMD_PORT, E_PIN, LOW_PIN);

	_delay_ms(1);
/*
	SET_BIT(LCD_CMD_PORT,E_PIN);		
	LCD_DATA_PORT=((CHR & 0xF0)|(LCD_DATA_PORT & 0x0F));
	CLEAR_BIT(LCD_CMD_PORT,E_PIN);*/
	
  DIO_SetPinVal(LCD_CMD_PORT, E_PIN, HIGH_PIN);	
	DIO_SetPortNibble(LCD_DATA_PORT,CHR,Data_H_To_Port_H);
	DIO_SetPinVal(LCD_CMD_PORT, E_PIN, LOW_PIN);

	_delay_ms(1);
/*
	
	SET_BIT(LCD_CMD_PORT,E_PIN);
	LCD_DATA_PORT=((CHR <<4)|(LCD_DATA_PORT & 0x0F));
	CLEAR_BIT(LCD_CMD_PORT,E_PIN);
*/
	
	DIO_SetPinVal(LCD_CMD_PORT, E_PIN, HIGH_PIN);
	DIO_SetPortNibble(LCD_DATA_PORT,CHR,Data_L_To_Port_H);
	DIO_SetPinVal(LCD_CMD_PORT, E_PIN, LOW_PIN);
	
	_delay_ms(1);
}

void LCD_WriteSTRING(const Uint8* STR)
{
	Uint8 index = 0;
	while (STR[index] != '\0')
	{
		LCD_WriteCHAR(STR[index]);
		index++;
	}
}

void LCD_AddCustomCHAR(Uint8 CGRAM_Address, Uint8 *NewCharArray)
{
	Uint8 index;
	LCD_WriteCMD(CGRAM_CMD_OFFSET | (CGRAM_Address << 3));
	//note that AC dec/increased by 1 each R/W to DD/CGRAM
	for (index = 0; index < 8; index++)
	{
		LCD_WriteCHAR(NewCharArray[index]);
	}
}


void LCD_GoTo(Uint8 ROW, Uint8 COL)
{
	Uint8 Address[2] = {LCD_Line1_1stAddress, LCD_Line2_1stAddress};
	LCD_WriteCMD(Address[ROW] + COL);
}

void LCD_Clear(void)
{
	LCD_WriteCMD(CMD_Clear_Display);
}


void LCD_WriteNUM(Sint64 NUM){
	Uint64 Multiplier=1;
	
	if(NUM == 0){	LCD_WriteCHAR('0'); 	}
	
	else
	{
		if(NUM < 0) {	LCD_WriteCHAR('-');
				 NUM *= -1;		 }
		
		if(NUM > 0){
			
			while( (Sint64)(NUM/Multiplier) != 0){	Multiplier*=10;	}

			do
			{
				Multiplier/=10;
				LCD_WriteCHAR( NUM/Multiplier +'0');
				NUM %=Multiplier;
			}
			while(Multiplier != 1 );
			
			
		}
		
		
		
		
		
		
	}
	
	



}

void LCD_WriteFLOAT(double num,Uint8 Percision)
{
	Uint64 val,i;
	val = (Uint64) num;
	LCD_WriteNUM(val);
	LCD_WriteCHAR('.');
	num -= val;
	for (i = 0; i < Percision; i++)
	{
		num *=10;
		val = (int)num;
		LCD_WriteCHAR(val+'0');
		num -=val;
	}
}

