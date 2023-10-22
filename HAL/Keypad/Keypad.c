/*
 * Keypad.c
 *
 *  Created on: Oct 21, 2023
 *      Author: ASUS
 */
 /******************************************************************************/

#include "Keypad.h"
#include "gpio.h"
#include "types.h"



void KEYPAD_init() {

	// Configure all keypad pins as Input Pins
		DIO_voidSetPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID,PIN_INPUT);
		DIO_voidSetPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID-1,PIN_INPUT);
		DIO_voidSetPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID-2,PIN_INPUT);
		DIO_voidSetPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID-3,PIN_INPUT);

		DIO_voidSetPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID,PIN_OUTPUT);
		DIO_voidSetPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID-1,PIN_OUTPUT);
		DIO_voidSetPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID-2,PIN_OUTPUT);
		DIO_voidSetPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID-4,PIN_OUTPUT);


		// MAKE THE COLOUMS OUTPUT IS HIGH  INITIALLY
		DIO_voidSetPinValue (KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID,LOGIC_HIGH);
		DIO_voidSetPinValue (KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID-1,LOGIC_HIGH);
		DIO_voidSetPinValue (KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID-2,LOGIC_HIGH);
		DIO_voidSetPinValue (KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID-4,LOGIC_HIGH);

		// Make ROWS BY DEFAULT AS A PULL-UP
		DIO_voidSetPinValue (KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID,LOGIC_HIGH);
		DIO_voidSetPinValue (KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID-1,LOGIC_HIGH);
		DIO_voidSetPinValue (KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID-2,LOGIC_HIGH);
		DIO_voidSetPinValue (KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID-4,LOGIC_HIGH);



}

u8 KEYPAD_getPressedKey(void)
{
		u8 r, c, key_value = 0xFF;
		u8 row[4] = {5, 4, 3, 2}, col[4] = {3,5,6,7};

		for (c = 0; c < 4; c++) {

			DIO_voidSetPinValue(PORTD, col[c], LOGIC_LOW);

			for (r = 0; r < 4; r++) {

				if (DIO_voidGetPinValue(PORTC, row[r]) == 0) {
																	// Key is pressed
					key_value = ((r*4)+c+1);
																	// Debouncing delay
					while (DIO_voidGetPinValue(PORTC, row[r]) == 0);
				}
			}
			// Set the column back to HIGH for the next iteration
			DIO_voidSetPinValue(PORTD, col[c], LOGIC_HIGH);
		}

		return key_value;


}
