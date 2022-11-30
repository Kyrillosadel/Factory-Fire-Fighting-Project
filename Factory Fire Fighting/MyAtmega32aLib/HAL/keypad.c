/*
 * keypad.c
 *
 * Created: 4/1/2022 8:26:46 PM
 *  Author: the samoray
 */ 

#include "keypad.h"


Uint8 KEY[4][4]=
{
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'o','0','=','+'}
	
};


void KeyPad_init(void){
	
	/* ALL PINs OF cols IS OUTPUT*/
	    SET_BIT(KP_COL_DDR,KP_Col0_PIN);
		SET_BIT(KP_COL_DDR,KP_Col1_PIN);
		SET_BIT(KP_COL_DDR,KP_Col2_PIN);
		SET_BIT(KP_COL_DDR,KP_Col3_PIN);
		
	/* all pins of col is HIGH */	
		 SET_BIT(KP_COL_PORT,KP_Col0_PIN);
		 SET_BIT(KP_COL_PORT,KP_Col1_PIN);
		 SET_BIT(KP_COL_PORT,KP_Col2_PIN);
		 SET_BIT(KP_COL_PORT,KP_Col3_PIN);
		 
		 /* SEt all row pins input*/
		 
		 CLEAR_BIT(KP_Row_DDR,KP_Row0_PIN);
		 CLEAR_BIT(KP_Row_DDR,KP_Row1_PIN);
		 CLEAR_BIT(KP_Row_DDR,KP_Row2_PIN);
		 CLEAR_BIT(KP_Row_DDR,KP_Row3_PIN);
		 
		 /* SET ALL row pins to PULLUP*/
		 
	     SET_BIT(KP_ROW_PORT,KP_Row0_PIN);
	     SET_BIT(KP_ROW_PORT,KP_Row1_PIN);
	     SET_BIT(KP_ROW_PORT,KP_Row2_PIN);
	     SET_BIT(KP_ROW_PORT,KP_Row3_PIN);

}

Uint8 KeyPad_GetKey(void)
{
	
	Uint8 VAL=0;
	
	for(int i=0;i<=3;i++)
	{
		CLEAR_BIT(KP_COL_PORT,(KP_Col0_PIN+i));
			
		for (int j=0;j<=3;j++)
		{
			if(IS_LOW(KP_Row_PINR,(j+KP_Row0_PIN))){
				_delay_ms(25);
				if(IS_LOW(KP_Row_PINR,(j+KP_Row0_PIN))){
					
					VAL= KEY[j][i];
				}
				}
			
		}
		
		SET_BIT(KP_COL_PORT,(KP_Col0_PIN+i));
	}
	
	return VAL;

	
}