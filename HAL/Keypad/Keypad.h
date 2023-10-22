/*
 * Keypad.h
 *
 *  Created on: Oct 21, 2023
 *      Author: ASUS
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Types.h"

/* Keypad Port Configurations */
#define KEYPAD_ROW_PORT_ID                PORTC
#define KEYPAD_FIRST_ROW_PIN_ID           5

#define KEYPAD_COL_PORT_ID                PORTD
#define KEYPAD_FIRST_COL_PIN_ID           7

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED           LOGIC_HIGH


/*
 * Description :
 * Get the Keypad pressed button
 */
u8 KEYPAD_getPressedKey(void);


#endif /* KEYPAD_H_ */
