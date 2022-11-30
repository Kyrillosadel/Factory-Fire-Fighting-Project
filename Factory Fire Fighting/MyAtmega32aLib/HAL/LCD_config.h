/*
 * LCD_CFG.h
 *
 * Created: 6/7/2021 11:59:10 AM
 *  Author: EN.ESLAM EID
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "../MCAL/DIO_interface.h"




#define LCD_CMD_PORT                 DIO_PORTB
#define RS_PIN                       PIN1
#define RW_PIN                       PIN2
#define E_PIN                        PIN3


#define LCD_DATA_PORT                DIO_PORTA
#define LCD_PIN4                     PIN4
#define LCD_PIN5                     PIN5
#define LCD_PIN6                     PIN6
#define LCD_PIN7                     PIN7

#endif /* LCD_CFG_H_ */