/*
 * GPIO_Driver.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Abdelrahman Zad
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_


#define PORTA (volatile prephieral_t*)0x39
#define PORTB (volatile prephieral_t*)0x36
#define PORTC (volatile prephieral_t*)0x33
#define PORTD (volatile prephieral_t*)0x30


#include "Types.h"

typedef union
{
	unsigned char All_bits;
	struct
	{
		unsigned char bit_0:1;
		unsigned char bit_1:1;
		unsigned char bit_2:1;
		unsigned char bit_3:1;
		unsigned char bit_4:1;
		unsigned char bit_5:1;
		unsigned char bit_6:1;
		unsigned char bit_7:1;
	}bit_access;
}access_register_t;

typedef struct
{
	access_register_t Input;
	access_register_t Direction;
	access_register_t output;

}prephieral_t;


void DIO_voidSetPinDirection(prephieral_t *Copy_usint8_tPortId, u8 Copy_usint8_tPinId, u8 Copy_usint8_tDirection);
void DIO_voidSetPinValue(prephieral_t *Copy_usint8_tPortId, u8 Copy_usint8_tPinId, u8 Copy_usint8_tValue);
u8 DIO_voidGetPinValue(prephieral_t *Copy_usint8_tPortId, u8 Copy_usint8_tPinId);
void DIO_voidSetPortDirection(prephieral_t *Copy_usint8_tPortId, u8 Copy_ugDirection);
void DIO_voidSetPortValue(prephieral_t *Copy_usint8_tPortId, u8 Copy_usint8_tValue);
u8 DIO_voidGetportValue(prephieral_t *Copy_usint8_tPortId);

#endif /* GPIO_DRIVER_H_ */
