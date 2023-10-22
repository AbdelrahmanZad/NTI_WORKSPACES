/*
 * EXT1_priv.h
 *
 *  Created on: Oct 22, 2023
 *      Author: ASUS
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

#include "Types.h"


typedef struct
{
	u8 MCUCSR;
	u8 MCUCR;
	u8 PASS[4];
	u8 GIFR;
	u8 GICR;

}Register;


#define EXTI (volatile Register*)(0x54)  //to define the base address of external interrupt

#define EXTI0_IRQHandler        \
	void __vector_1(void) __attribute__ ((signal)); \
	void __vector_1(void)

#define EXTI1_IRQHandler        \
	void __vector_2(void) __attribute__ ((signal)); \
	void __vector_2(void)

#define EXTI2_IRQHandler        \
	void __vector_3(void) __attribute__ ((signal)); \
	void __vector_3(void)





#endif /* EXTI_PRIV_H_ */
