/*
 * EXT1.h
 *
 *  Created on: Oct 22, 2023
 *      Author: ASUS
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "Types.h"


#define LOW_LEVEL			0
#define ANY_CHANGE			1
#define FALLING_EDGE		2
#define RISING_EDGE			3


#define INT2_ID 	5
#define INT0_ID		6
#define INT1_ID		7


void EXT1_Enable(u8 coby_u8_INT_ID, u8 Trigger);
void EXT1_Disable(u8 coby_u8_EXTI_ID);
void EXT1_voidsetCallback(void (*callback)(void),u8 coby_u8_INT_ID);




#endif

