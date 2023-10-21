/*
 * Sevseg.h
 *
 *  Created on: Oct 21, 2023
 *      Author: ASUS
 */

#ifndef SEVSEG_H_
#define SEVSEG_H_

#include "Types.h"

// Define the pin connections for the BCD inputs and 7-segment display commons
void Sevseg_Init();
void Sevseg_num(u8 num);


#endif /* SEVSEG_H_ */
