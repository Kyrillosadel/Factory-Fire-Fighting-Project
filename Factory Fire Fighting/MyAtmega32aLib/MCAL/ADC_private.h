/*
 * ADC_private.h
 *
 * Created: 5/27/2022 4:44:18 PM
 *  Author: TEAM B
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include "../Utilities/STD.h"
   	#define SREG   (*(volatile Uint8 *) (0x5F))

	   #define ADC0              0
	   #define ADC1              1
	   #define ADC2              2
	   #define ADC3              3
	   #define ADC4              4
	   #define ADC5              5
	   #define ADC6              6
	   #define ADC7              7

   #define  ADMUX (*( (volatile Uint8 *) 0x27))

   #define  REFS1		7   //VOLTAGE REFRENCE SELECT     ----  AVCC SELECTED
   #define  REFS0		6
   #define  ADLAR		5  //LEFT OR RIGHT
   #define  MUX4		4
   #define  MUX3	    3
   #define  MUX2	   	2
   #define  MUX1		1
   #define  MUX0		0

   #define  ADCSRA  (*((volatile Uint8 *)0x26))    // FREE RUNNING SELECTION

   
   #define  ADEN		7
   #define  ADSC		6
   #define  ADATE		5
   #define  ADIF		4
   #define  ADIE	    3
   #define  ADPS2	   	2
   #define  ADPS1		1
   #define  ADPS0		0

   #define  ADCH       (*((volatile Uint8 *)0x25))
   #define  ADCL       (*((volatile Uint8 *)0x24))
   #define  ADC_REG  	(*((volatile Uint16 *)0x24))
   

   #define  SFIOR (*((volatile Uint16 *)0x50))
   
   #define  ADTS2 7
   #define  ADTS1 6
   #define  ADTS0 5



#endif /* ADC_PRIVATE_H_ */