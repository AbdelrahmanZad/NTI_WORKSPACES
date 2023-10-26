/*
 * main.c
*
 *  Created on: Oct 25, 2023
 *      Author: Asus
 */

#include "stdio.h"
#include "login_check.h"
#include "util/delay.h"
#include "Keypad.h"
#include "LCD.h"


int main() {

	int i = 0, ID[4], password[4], ID_retVal, PASS_retVal;
	// initialize Data Base //
	initializeDatabase();

	/*************** to check ****************/
	while (1) {

		H_LCD_void_sendString("enter ID: ");
		_delay_ms(50);
		for (i = 0; i < 4; i++) {
			// get the number from KEYPAD and display on LCD //
			ID[i] = KEYPAD_getPressedKey();
			H_LCD_void_sendIntNum(ID[i]);
			// wait a while //
			_delay_ms(50);
		}
		// clear LCD //
		H_LCD_void_clearScreen();
		_delay_ms(50);
		H_LCD_void_sendString("enter password: ");
		_delay_ms(50);
		for (i = 0; i < 4; i++) {
			// get the number from KEYPAD and display on LCD //
			password[i] = KEYPAD_getPressedKey();
			H_LCD_void_sendIntNum(password[i]);
			// wait a while //
			_delay_ms(50);
		}
		// clear LCD //
		H_LCD_void_clearScreen();
		_delay_ms(50);

		// pass the array to check ID function
		ID_retVal = ID_check(ID);
		PASS_retVal = PASSWORD_check(password);

		if (ID_retVal == 1 && PASS_retVal == 1) {
			H_LCD_void_sendString("welcome Ahmed");
			_delay_ms(50);
		} else if (ID_retVal == 2 && PASS_retVal == 2) {
			H_LCD_void_sendString("welcome Sara");
			_delay_ms(50);
		} else {
			H_LCD_void_sendString("wrong ID or Password");
			_delay_ms(50);
		}
		H_LCD_void_clearScreen();
		_delay_ms(50);
	}
	return 0;
}

