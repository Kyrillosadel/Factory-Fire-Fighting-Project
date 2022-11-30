/*
 * ExINT_private.h
 *
 * Created: 4/30/2022 10:54:59 PM
 *  Author: the samoray
 */ 


#ifndef EXINT_PRIVATE_H_
#define EXINT_PRIVATE_H_
#include "../Utilities/STD.h"
#include "DIO_private.h"
#include "../Utilities/BITMATH.h"


#define SREG   (*((volatile Uint8 *) (0x5F)))
#define GICR   (*((volatile Uint8 *) (0x5B)))
#define GIFR   (*((volatile Uint8 *) (0x5A)))
#define MCUCR  (*((volatile Uint8 *) (0x55)))
#define MCUCSR (*((volatile Uint8 *) (0x54)))


/*
-----SREG bit-------
*/
#define IBIT  7

/*
-----MCUCR BITS-----
*/
#define  ISC00  0
#define  ISC01  1

#define  ISC10  2
#define  ISC11  3

/*-------MCUCSR bit----*/
#define ISC2  6

/*-----GICR-------*/

#define INT0_E  6
#define INT1_E  7
#define INT2_E  5

#define INT2    5
#define INT0    6
#define INT1    7
/*-----GIFR-------*/

#define INTF0  6
#define INTF1  7
#define INTF2  5



#endif /* EXINT_PRIVATE_H_ */