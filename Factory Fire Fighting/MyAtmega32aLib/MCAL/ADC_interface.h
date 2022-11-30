/*
* ADC.h
*
* Created: 5/27/2022 2:58:55 PM
*  Author: TEAM B
*/


#ifndef ADC_H_
#define ADC_H_

#include "DIO_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_INIT();
Uint16 ADC_Read(Uint8 ADC_CHANNEL);


#endif /* ADC_H_ */