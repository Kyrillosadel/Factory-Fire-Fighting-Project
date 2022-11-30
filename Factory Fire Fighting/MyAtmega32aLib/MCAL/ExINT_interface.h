/*
 * ExINT_interface.h
 *
 * Created: 4/30/2022 10:55:32 PM
 *  Author: the samoray
 */ 


#ifndef EXINT_INTERFACE_H_
#define EXINT_INTERFACE_H_

#include "ExINT_private.h"
#include "ExINT_config.h"
#include <avr/interrupt.h>
/*
//----Signal Mode----
 1) IRQ_AT_RISING_EADGE    
 2) IRQ_AT_FALLING_EADGE   
 3) IRQ_AT_LOW_LEVEL       
 4) IRQ_AT_LOGICAL_CHANGE  
*/

#include "../Utilities/BITMATH.h"

void ExINT_SetUp(Uint8 INT_PIN,Uint8 signal_Mode);
void General_Int_Enable(void);
void General_Int_Disable(void);

void CLOSE_INT0(void);
void CLOSE_INT1(void);
void CLOSE_INT2(void);



#endif /* EXINT_INTERFACE_H_ */