/*
 * TIMER0_private.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Asus
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#include "Types.h"

typedef struct
{
	vusint8_t TCNT0;
	vusint8_t TCCR0;
	u8 reserved[4];
	vusint8_t TIFR;
	vusint8_t TIMSK;
	u8 reserve[2];
	vusint8_t OCR0;

}TIMER0_Registers;

#define Ptr_timer_registers ((volatile TIMER0_Registers*)0x52)

//TIMER0_Registers *Ptr_timer_registers = Timer0_Base_Address;


//Prescalers Select

#define timer_OFF   	0
#define no_prescaler 	1
#define FCPU_8 			2
#define FCPU_64 		3
#define FCPU_256 		4
#define FCPU_1024 		5
#define EXT_FALLING 	6
#define EXT_RISING 		7



// Operation_mode select

#define Normal_OVF_mode 0
#define PWM_Phase_Correct 1
#define CTC 2
#define Fast_PWM 3


// OC0_modes select

#define OC0_disconnected	 		 0
#define Toggle_OC0_on_compare_match	 1
#define Clear_OC0_on_compare_match	 2
#define Set_OC0_on_compare_match	 3



#define NULLPTR ((void*)0)


#define TIMER0_PRESCALER_MASK   0b11111000
#define TIMER0_OC0_MODE_MASK    0b11001111



#  define ISR_NOBLOCK    __attribute__((interrupt))
#  define ISR_NAKED      __attribute__((naked))

/* Timer/Counter0 Compare Match ISR */

#define TIMER0_CompareMatch_IRQHandler            \
	void __vector_10(void) __attribute__ ((signal)); \
	void __vector_10(void)
/*************************************************************/
/* Timer/Counter0 Overflow ISR */

#define TIMER0_Overflow_IRQHandler            \
	void __vector_11(void) __attribute__ ((signal)); \
	void __vector_11(void)

#endif
