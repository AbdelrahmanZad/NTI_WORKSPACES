/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Bodo
 */

#include <stdio.h>
#include "GPIO_Driver.h"
#include <avr/delay.h>

int main() {

		DIO_voidSetPinDirection(PORTA,6,1);
	while (1) {

		DIO_voidSetPinValue(PORTA, 6, 1);
		_delay_ms(500);
		DIO_voidSetPinValue(PORTA, 6, 0);
		_delay_ms(500);
	}

	return 0;
}
