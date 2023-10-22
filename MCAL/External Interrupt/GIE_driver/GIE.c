/*
 * GIE.c
 *
 *  Created on: Oct 22, 2023
 *      Author: ASUS
 */


#include "GIE_private.h"
#include "GIE.h"
#include "GIE_config.h"


void GIE_ENABLE()
{
	asm("SEI");

}


void GIE_DISABLE()
{
	asm("CLI");

}


