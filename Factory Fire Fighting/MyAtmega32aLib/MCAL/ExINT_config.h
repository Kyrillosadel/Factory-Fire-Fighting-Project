/*
 * ExINT_config.h
 *
 * Created: 4/30/2022 10:55:15 PM
 *  Author: the samoray
 */ 


#ifndef EXINT_CONFIG_H_
#define EXINT_CONFIG_H_



/*
//----Signal Mode----
*/
#define IRQ_AT_RISING_EADGE    0
#define IRQ_AT_FALLING_EADGE   1
#define IRQ_AT_LOW_LEVEL       2
#define IRQ_AT_LOGICAL_CHANGE  3

/*
//----INTERRUPT PINS NAME----
*/
#define DIO_INT0  0
#define DIO_INT1  1
#define DIO_INT2  2

#endif /* EXINT_CONFIG_H_ */