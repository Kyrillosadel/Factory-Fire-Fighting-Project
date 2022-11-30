/*
 * I2C.c
 *
 * Created: 6/2/2021 8:31:59 PM
 *  Author: Ali
 */ 


#include "I2C.h"


void I2C_Init_Master(void)
{
	/*Init SCL 400KHz  / TWBR =   0x0C */
	/*Init SCL 100KHz  / TWBR =   0x28 */
	TWBR = 0x0C ;
	CLR_BIT(TWSR , 0);
	CLR_BIT(TWSR , 1);
	
	
	/*enable I2c*/
	SET_BIT(TWCR , 6);
	/*enable I2c*/
	SET_BIT(TWCR , 2);
#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include "BITMATH.h"
#include "STD.h"
#include "HAL/EEPROM.h"
#include "MCAL/DIO_interface.h"
#include "HAL/LCD_interface.h"

Uint8 CH=0 ;
Uint8 Rxname[17]  ;
Uint8 Txname[17]  ;


int main ()
{
	LCD_init();
	EEPROM_INIT();
	Uint8 i=0;
	LCD_GoTo(0,0);
	EEPROM_WriteString(1,0,"ESLAM EID");
	LCD_WriteSTRING(Txname);

	while(1){
		
		EEPROM_ReadMultiByte(1,i,Rxname,13);
		LCD_WriteSTRING(Rxname);
		_delay_ms(50);
		i++;
		
		if (CH =='\0')
		{	   i=0;
			LCD_Clear();

		}

		


	}
}
}

void I2C_Init_Slave(void)
{
	TWAR |= (0x01 << 1);
	
   /*enable I2c*/
   SET_BIT(TWCR , 2);
}

void I2C_Start_Cond(void)
{
	/*generate Start Cond*/
	SET_BIT(TWCR , 5);
	
	/*enable I2c*/
	/*Trigger Flag / Clear Flag*/
	TWCR |= 0X84 ;
	
	/*Monitor Flag*/
	while(GET_BIT(TWCR , 7) == 0);
	
	/*Check Operation Status*/
	while((TWSR &0XF8) != START_ACK);
	
}

void I2C_RpeatedStart(void)
{
	/*generate Repeated Start Cond*/
	SET_BIT(TWCR , 5);
	
	/*enable I2c*/
	/*Trigger Flag / Clear Flag*/
	TWCR = 0X84 ;
	
	/*Monitor Flag*/
	while(GET_BIT(TWCR , 7) == 0);
	
	/*Check Operation Status*/
	while((TWSR &0XF8) != REP_START_ACK);
}

void I2C_Send_SlaveAddress_Write_Operation(uint8 addr)
{
	/*Send Slave Addr with Write Operation*/
	TWDR = (addr << 1);
	
	/*enable I2c*/
	/*Trigger Flag / Clear Flag*/
	TWCR = 0X84 ;
	
	/*Monitor Flag*/
	while(GET_BIT(TWCR , 7) == 0);
	
	/*Check Operation Status*/
	while((TWSR &0XF8) != SLAVE_ADD_AND_WR_ACK);
}

void I2C_Send_SlaveAddress_Read_Operation(uint8 addr)
{
	/*Send Slave Addr with Read Operation*/
	TWDR = (addr << 1) | (0x01) ;
	
	/*enable I2c*/
	/*Trigger Flag / Clear Flag*/
	TWCR = 0X84 ;
	
	/*Monitor Flag*/
	while(GET_BIT(TWCR , 7) == 0);
	
	/*Check Operation Status*/
	while((TWSR &0XF8) != SLAVE_ADD_AND_RD_ACK);
}

void I2C_WriteByte(uint8 data)
{
	
	/*Send Data Operation*/
	TWDR = data;
	
	/*enable I2c*/
	/*Trigger Flag / Clear Flag*/
	TWCR = 0X84 ;
	
	/*Monitor Flag*/
	while(GET_BIT(TWCR , 7) == 0);
	
	/*Check Operation Status*/
	while((TWSR &0XF8) != WR_BYTE_ACK);
}

uint8 I2C_ReadByte(void)
{
		/*enable I2c*/
		/*Trigger Flag / Clear Flag*/
		TWCR |= 0X84 ;
		
		/*Monitor Flag*/
		while(GET_BIT(TWCR , 7) == 0);
		
		/*Check Operation Status*/
		//while((TWSR &0XF8) != RD_BYTE_WITH_ACK);
		
		return TWDR ;
}

void I2C_StopCond(void)
{
		/*Stop Condition*/
	//	SET_BIT(TWCR , 4);
		
		/*enable I2c*/
		/*Trigger Flag / Clear Flag*/
		TWCR |= 0X94 ;
		
	   /*Monitor Flag*/
	//while(GET_BIT(TWCR , 7) == 0);
}