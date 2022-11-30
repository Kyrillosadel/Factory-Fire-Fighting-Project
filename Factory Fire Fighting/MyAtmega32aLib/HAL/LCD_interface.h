/*
 * LCD.h
 *
 * Created: 6/7/2021 11:58:56 AM
 *  Author: EN.ESLAM EID
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_config.h"
#include "LCD_private.h"



void LCD_init(void);
void LCD_WriteCMD(Uint8 cmd);
void LCD_WriteCHAR(Uint8 chr);


void LCD_Clear(void);
void LCD_GoTo(Uint8 ROW, Uint8 COL);


void LCD_WriteSTRING(const Uint8 * STR);

void LCD_WriteINTEGER(Sint32 num);
void LCD_WriteFLOAT(double num,Uint8 Percision);
void LCD_WriteNUM(Sint64 NUM);
void LCD_AddCustomCHAR(Uint8 loc, Uint8 *arr);
//void LCD_ModifyDDRAM_CHAR(Uint8 loc, Uint8 *arr);



#endif /* LCD_H_ */