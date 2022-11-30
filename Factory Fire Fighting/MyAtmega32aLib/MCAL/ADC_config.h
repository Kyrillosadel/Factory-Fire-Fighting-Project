/*
* ADC_CNFG.h
*
* Created: 5/27/2022 2:59:34 PM
*  Author: TEAM B
*/


#ifndef ADC_CNFG_H_
#define ADC_CNFG_H_
/*-------------------------------*/
/*	VOLTAGE_REFERENCE:			 */
/*			AREF				 */
/*			AVCC				 */
/*			Internal_2_56V		 */
/*-------------------------------*/

#define AREF           0
#define AVCC           1
#define Internal_2_56V 2

#define  FREE_RUNNING              0
#define ANALOG_COMPARATOR	       1
#define EXTERNAL_INTERRUPT_REQUEST 2
#define Timer0_Compare_Match	   3
#define Timer0_Overflow			   4
#define Timer_Compare_Match_B	   5
#define Timer1_Overflow			   6
#define Timer1_Capture_Event	   7


#define  VOLTAGE_REFERENCE 	   AVCC
#define  AUTO_TRIGGER_MODE     FREE_RUNNING


#endif /* ADC_CNFG_H_ */