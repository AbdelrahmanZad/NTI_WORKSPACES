/*
 * GPIO_Driver.c
 *
 *  Created on: Oct 20, 2023
 *      Author: BODO
 */
#include "GPIO_Driver.h"



void DIO_voidSetPinDirection(prephieral_t *Copy_usint8_tPortId, u8 Copy_usint8_tPinId, u8 Copy_usint8_tDirection)
{


	switch(Copy_usint8_tPinId)
	{
	case 0:
		Copy_usint8_tPortId->Direction.bit_access.bit_0= Copy_usint8_tDirection;
		break;
	case 1:
		Copy_usint8_tPortId->Direction.bit_access.bit_1=Copy_usint8_tDirection;
		break;
	case 2:
			Copy_usint8_tPortId->Direction.bit_access.bit_2=Copy_usint8_tDirection;
			break;
	case 3:
			Copy_usint8_tPortId->Direction.bit_access.bit_3=Copy_usint8_tDirection;
			break;
	case 4:
			Copy_usint8_tPortId->Direction.bit_access.bit_4=Copy_usint8_tDirection;
			break;
	case 5:
			Copy_usint8_tPortId->Direction.bit_access.bit_5=Copy_usint8_tDirection;
			break;
	case 6:
			Copy_usint8_tPortId->Direction.bit_access.bit_6=Copy_usint8_tDirection;
			break;
	case 7:
			Copy_usint8_tPortId->Direction.bit_access.bit_7=Copy_usint8_tDirection;
			break;
	default:
		break;

	}


}
void DIO_voidSetPinValue(prephieral_t *Copy_usint8_tPortId, u8 Copy_usint8_tPinId, u8 Copy_usint8_tValue)
{
	switch(Copy_usint8_tPinId)
	{
	case 0:
			Copy_usint8_tPortId->output.bit_access.bit_0= Copy_usint8_tValue;
			break;
		case 1:
			Copy_usint8_tPortId->output.bit_access.bit_1=Copy_usint8_tValue;
			break;
		case 2:
				Copy_usint8_tPortId->output.bit_access.bit_2=Copy_usint8_tValue;
				break;
		case 3:
				Copy_usint8_tPortId->output.bit_access.bit_3=Copy_usint8_tValue;
				break;
		case 4:
				Copy_usint8_tPortId->output.bit_access.bit_4=Copy_usint8_tValue;
				break;
		case 5:
				Copy_usint8_tPortId->output.bit_access.bit_5=Copy_usint8_tValue;
				break;
		case 6:
				Copy_usint8_tPortId->output.bit_access.bit_6=Copy_usint8_tValue;
				break;
		case 7:
				Copy_usint8_tPortId->output.bit_access.bit_7=Copy_usint8_tValue;
				break;
		default:
			break;
	}

}
u8 DIO_voidGetPinValue(prephieral_t *Copy_usint8_tPortId, u8 Copy_usint8_tPinId)
{
	u8 value=0;
	switch(Copy_usint8_tPinId)
	{
	case 0:
		value=Copy_usint8_tPortId->Input.bit_access.bit_0;
		break;
	case 1:
		value=Copy_usint8_tPortId->Input.bit_access.bit_1;
		break;
	case 2:
		value=Copy_usint8_tPortId->Input.bit_access.bit_2;
		break;
	case 3:
		value=Copy_usint8_tPortId->Input.bit_access.bit_3;
		break;
	case 4:
		value=Copy_usint8_tPortId->Input.bit_access.bit_4;
		break;
	case 5:
		value=Copy_usint8_tPortId->Input.bit_access.bit_5;
		break;
	case 6:
		value=Copy_usint8_tPortId->Input.bit_access.bit_6;
		break;
	case 7:
		value=Copy_usint8_tPortId->Input.bit_access.bit_7;
		break;
	}

	return value;
}
void DIO_voidSetPortDirection(prephieral_t *Copy_usint8_tPortId, u8 Copy_ugDirection)
{
	Copy_usint8_tPortId->Direction.All_bits=Copy_ugDirection;

}
void DIO_voidSetPortValue(prephieral_t *Copy_usint8_tPortId, u8 Copy_usint8_tValue)
{
	Copy_usint8_tPortId->output.All_bits=Copy_usint8_tValue;

}
u8 DIO_voidGetportValue(prephieral_t *Copy_usint8_tPortId)
{
	u8 value = Copy_usint8_tPortId->Input.All_bits;


	return value;
}
