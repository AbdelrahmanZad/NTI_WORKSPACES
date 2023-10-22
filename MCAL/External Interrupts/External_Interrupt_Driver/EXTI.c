/*
 * EXT.c
 *
 *  Created on: Oct 22, 2023
 *      Author: ASUS
 */
// EXT1.c

#include "EXTI_priv.h"
#include "EXTI_config.h"
#include "EXTI.h"
#include "Types.h"

Register *EXT_I = EXTI;		     //ASSIGNING APOINTER TO STRUCTURE TO POINT AT EVERY REGISTER OF EXTI REGISTERS
void (*Callback[3])(void);       //ARRAY OF 3 POINTERS TO (CALL BACK) FUNCTION -- AS A GLOBAL VAROABLE


void EXT1_Enable(u8 coby_u8_INT_ID, u8 Trigger) {

	if (coby_u8_INT_ID == INT0_ID)
	{

	        SET_BIT(EXT_I->GICR, INT0_ID);

	        if (Trigger == ANY_CHANGE)
	        {
	            SET_BIT(EXT_I->MCUCR,0);        //ISC00 = 1
	            CLEAR_BIT(EXT_I->MCUCR,1);		//ISC01 = 0

	        }
	        else if (Trigger == FALLING_EDGE)
	        {
	            SET_BIT(EXT_I->MCUCR,1);		//ISC00 = 0
	            CLEAR_BIT(EXT_I->MCUCR,0);		//ISC01 = 1
	        }
	        else if (Trigger == RISING_EDGE)
	        {
	            SET_BIT(EXT_I->MCUCR, 1);		//ISC00 = 1
	            SET_BIT(EXT_I->MCUCR, 0);		//ISC01 = 1
	        }
	        else
	        {
				//do nothing if the input is wrong
	        }
	    }

	else if (coby_u8_INT_ID == INT1_ID)
	{

	        SET_BIT(EXT_I->GICR, INT1_ID);

	        if (Trigger == ANY_CHANGE)
	        {
	            SET_BIT(EXT_I->MCUCR, 2);		//ISC10 = 1
	            CLEAR_BIT(EXT_I->MCUCR, 3);		//ISC11 = 1
	        }
	        else if (Trigger == FALLING_EDGE)
	        {
	            SET_BIT(EXT_I->MCUCR, 3);		//ISC10 = 0
	            CLEAR_BIT(EXT_I->MCUCR, 2);		//ISC11 = 1
	        }
	        else if (Trigger == RISING_EDGE)
	        {
	            SET_BIT(EXT_I->MCUCR, 2);		//ISC10 = 1
	            SET_BIT(EXT_I->MCUCR, 3);		//ISC11 = 1
	        }
	        else
	       	{
	       		//do nothing if the input is wrong
	       	}

	    }

	else if (coby_u8_INT_ID == INT2_ID)
	{
	        SET_BIT(EXT_I->GICR, INT2_ID);

	        if (Trigger == FALLING_EDGE)
	        {
	            CLEAR_BIT(EXT_I->MCUCSR, 6);  //ISC2 =0
	        }
	        else if (Trigger == RISING_EDGE)
	        {
	            SET_BIT(EXT_I->MCUCSR, 6);    //ISC2 = 1
	        }
	    }
	}

void EXT1_Disable(u8 coby_u8_EXTI_ID) {

	    if (coby_u8_EXTI_ID == INT0_ID)
	    {
	        CLEAR_BIT(EXT_I->GICR, INT0_ID);
	    }

	    else if (coby_u8_EXTI_ID == INT1_ID)
	    {
	        CLEAR_BIT(EXT_I->GICR, INT1_ID);
	    }

	    else if (coby_u8_EXTI_ID == INT2_ID)
	    {
	        CLEAR_BIT(EXT_I->GICR, INT2_ID);
	    }

	    else
	    {
	        // do nothing
	    }


}


void EXT1_voidsetCallback(void (*callback)(void),u8 coby_u8_INT_ID) {

	if (coby_u8_INT_ID == INT0_ID)
	{
		Callback[0] = callback;
	}
	else if (coby_u8_INT_ID == INT1_ID)
	{
		Callback[1] = callback;
	}
	else if (coby_u8_INT_ID == INT2_ID)
	{
		Callback[2] = callback;
	}
	else
	{
	    // do nothing
	}


}

EXTI0_IRQHandler         //handler for int0
{
	Callback[0]();

}


EXTI1_IRQHandler		//handler for int1
{
	Callback[1]();
}
/*********  INT 2 *********/
EXTI2_IRQHandler		//handler for int 2
{
	Callback[2]();

}


