/*
 * ExINT_prog.h
 *
 * Created: 4/30/2022 10:55:45 PM
 *  Author:  TEAM B
 */ 




#include "ExINT_interface.h"


void General_Int_Enable(void){
		SET_BIT(SREG,IBIT);//GIE=1
}
void General_Int_Disable(void){
	CLEAR_BIT(SREG,IBIT);//GIE=0
}
void CLOSE_INT0(void){	CLEAR_BIT(GICR,INT0_E);}
 
void CLOSE_INT1(void){	CLEAR_BIT(GICR,INT1_E);}

void CLOSE_INT2(void){	CLEAR_BIT(GICR,INT2_E);}



void ExINT_SetUp(Uint8 INT_PIN,Uint8 signal_Mode){ 

	switch (INT_PIN){
		
		case INT0:
		CLEAR_BIT(DDRD,2);//SET INT0 INPUT PIN 
		SET_BIT(GICR,INT0_E);//Enable INT0 
		switch(signal_Mode){
			case IRQ_AT_RISING_EADGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
//MCUCR=IRQ_AT_RISING_EADGE;
			break;

			case IRQ_AT_FALLING_EADGE:

			CLEAR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);

			break;

			case IRQ_AT_LOW_LEVEL :
			CLEAR_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;

			case IRQ_AT_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;

		}
		break;

		case INT1:
		
				CLEAR_BIT(DDRD,3);//SET INT0 INPUT PIN

				SET_BIT(GICR,INT1_E);//Enable INT0

		switch(signal_Mode){
			case IRQ_AT_RISING_EADGE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
//MCUCR=IRQ_AT_RISING_EADGE<<2;
			break;

			case IRQ_AT_FALLING_EADGE:

			CLEAR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);

			break;

			case IRQ_AT_LOW_LEVEL :
			CLEAR_BIT(MCUCR,ISC10);
			CLEAR_BIT(MCUCR,ISC11);
			break;

			case IRQ_AT_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC10);
			CLEAR_BIT(MCUCR,ISC11);
			break;

		}
		break;


		case INT2:
				CLEAR_BIT(DDRB,2);//SET INT0 INPUT PIN
		     	SET_BIT(GICR,INT2_E);//Enable INT2
		switch(signal_Mode){
			case IRQ_AT_RISING_EADGE:
			SET_BIT(MCUCSR,ISC2);
			break;
			case IRQ_AT_FALLING_EADGE:
			CLEAR_BIT(MCUCSR,ISC2);
			break;
		}
		break;



	}
	
	
	    General_Int_Enable();

}


