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




u8 KEYPAD_getPressedKey (void)
{
	u8 col,row;

	// Configure all keypad pins as Input Pins
	DIO_voidSetPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID, PIN_INPUT);
	DIO_voidSetPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID-1, PIN_INPUT);
	DIO_voidSetPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID-2, PIN_INPUT);
	DIO_voidSetPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID-3, PIN_INPUT);

	DIO_voidSetPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID, PIN_INPUT);
	DIO_voidSetPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID-1, PIN_INPUT);
	DIO_voidSetPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID-2, PIN_INPUT);
	DIO_voidSetPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID-4, PIN_INPUT);

	while(1)
	{
		for(row=0 ; row<4 ; row++) /* loop for rows */
		{
			/*
			 * Each time setup the direction for all keypad port as input pins,
			 * except this row will be output pin
			 */
			DIO_voidSetPinDirection(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+row,PIN_OUTPUT);

			/* Set/Clear the row output pin */
			DIO_voidSetPinValue(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID+row, KEYPAD_BUTTON_PRESSED);

			for(col=0 ; col<4 ; col++) /* loop for columns */
			{
				/* Check if the switch is pressed in this column */
				if(DIO_voidGetPinValue(KEYPAD_COL_PORT_ID,KEYPAD_FIRST_COL_PIN_ID+col) == KEYPAD_BUTTON_PRESSED)
				{
					return ((row*KEYPAD_NUM_COLS)+col+1);
				}
			}
			DIO_voidSetPinDirection(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+row,PIN_INPUT);
		}
	}
}



