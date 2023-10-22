/*
 * Sevseg.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Abdelrahman Zad
 */


#include "GPIO_Driver.h"
#include "Sevseg.h"

void Sevseg_Init() {

	// Initialize the port and pins for the 7-segment display
	DIO_voidSetPinDirection(PORTB,0,1); // Configure all pins as outputs
	DIO_voidSetPinDirection(PORTB,1,1);
	DIO_voidSetPinDirection(PORTB,2,1);
	DIO_voidSetPinDirection(PORTB,4,1);

	//Configure PORTA,PIN3 to make it output to enable the right number
	DIO_voidSetPinDirection(PORTA,3,1); //Configure PORTA,PIN3 to make it output to enable the right number

	//Configure the 4 bins of comm1,2,3,4 initially by zero
	DIO_voidSetPinValue(PORTA,2,LOGIC_LOW);
	DIO_voidSetPinValue(PORTA,3,LOGIC_LOW);
	DIO_voidSetPinValue(PORTB,5,LOGIC_LOW);
	DIO_voidSetPinValue(PORTB,6,LOGIC_LOW);
}

void Sevseg_num(u8 num) {

	if (num < 0 || num > 9)
	{

	}

	else
	{
		switch (num)
		{
		case 0 :
			DIO_voidSetPinValue(PORTB,0,LOGIC_LOW);  //assign the values according to decoder table
			DIO_voidSetPinValue(PORTB,1,LOGIC_LOW);
			DIO_voidSetPinValue(PORTB,2,LOGIC_LOW);
			DIO_voidSetPinValue(PORTB,4,LOGIC_LOW);
			break;
		case 1 :
			DIO_voidSetPinValue(PORTB,0,LOGIC_HIGH);  //assign the values according to decoder table
			DIO_voidSetPinValue(PORTB,1,LOGIC_LOW);
			DIO_voidSetPinValue(PORTB,2,LOGIC_LOW);
			DIO_voidSetPinValue(PORTB,4,LOGIC_LOW);
			break;
		case 2 :
			DIO_voidSetPinValue(PORTB,0,LOGIC_LOW);  //assign the values according to decoder table
			DIO_voidSetPinValue(PORTB,1,LOGIC_HIGH);
			DIO_voidSetPinValue(PORTB,2,LOGIC_LOW);
			DIO_voidSetPinValue(PORTB,4,LOGIC_LOW);
			break;
		case 3 :
			DIO_voidSetPinValue(PORTB,0,LOGIC_HIGH);  //assign the values according to decoder table
			DIO_voidSetPinValue(PORTB,1,LOGIC_HIGH);
			DIO_voidSetPinValue(PORTB,2,LOGIC_LOW);
			DIO_voidSetPinValue(PORTB,4,LOGIC_LOW);
			break;
		case 4 :
			DIO_voidSetPinValue(PORTB,0,LOGIC_LOW);  //assign the values according to decoder table
			DIO_voidSetPinValue(PORTB,1,LOGIC_LOW);
			DIO_voidSetPinValue(PORTB,2,LOGIC_HIGH);
			DIO_voidSetPinValue(PORTB,4,LOGIC_LOW);
			break;
		case 5 :
			DIO_voidSetPinValue(PORTB,0,LOGIC_HIGH);  //assign the values according to decoder table
			DIO_voidSetPinValue(PORTB,1,LOGIC_LOW);
			DIO_voidSetPinValue(PORTB,2,LOGIC_HIGH);
			DIO_voidSetPinValue(PORTB,4,LOGIC_LOW);
			break;

		case 6 :
			DIO_voidSetPinValue(PORTB,0,LOGIC_LOW);  //assign the values according to decoder table
			DIO_voidSetPinValue(PORTB,1,LOGIC_HIGH);
			DIO_voidSetPinValue(PORTB,2,LOGIC_HIGH);
			DIO_voidSetPinValue(PORTB,4,LOGIC_LOW);
			break;

		case 7 :
			DIO_voidSetPinValue(PORTB,0,LOGIC_HIGH);  //assign the values according to decoder table
			DIO_voidSetPinValue(PORTB,1,LOGIC_HIGH);
			DIO_voidSetPinValue(PORTB,2,LOGIC_HIGH);
			DIO_voidSetPinValue(PORTB,4,LOGIC_LOW);
			break;
		case 8 :
			DIO_voidSetPinValue(PORTB,0,LOGIC_LOW);  //assign the values according to decoder table
			DIO_voidSetPinValue(PORTB,1,LOGIC_LOW);
			DIO_voidSetPinValue(PORTB,2,LOGIC_LOW);
			DIO_voidSetPinValue(PORTB,4,LOGIC_HIGH);
			break;
		case 9 :
			DIO_voidSetPinValue(PORTB,0,LOGIC_HIGH);  //assign the values according to decoder table
			DIO_voidSetPinValue(PORTB,1,LOGIC_HIGH);
			DIO_voidSetPinValue(PORTB,2,LOGIC_LOW);
			DIO_voidSetPinValue(PORTB,4,LOGIC_LOW);
			break;

			default:
			break;
		}
	}

}


