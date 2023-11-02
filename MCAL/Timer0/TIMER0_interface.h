/*
 * TIMER0_interfacec.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Asus
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


#include "TIMER0_private.h"
#include "TIMER0_config.h"
//========================================//

typedef enum{
	TIMER0_SET_DELAY_FUNCTION,
	TIMER0_NO_OPERATION = 2
}TIMER0_GLOBAL_t;

/**************** PROTOTYPES **************/
void TIMER0_init(void);
void TIMER0_Start(void);
void TIMER0_Stop();
void TIMER0_Interrupt_Enable(u8 Int_ID );
void TIMER0_Interrupt_Disable(u8 Int_ID );
void TIMER0_OC_SetCallBack(void(*local_fptr)(void));
void TIMER0_OV_SetCallBack(void(*local_fptr)(void));
u8 TIMER0_getcounts(void);
void TIMER0_SetDelayTimeMilliSec(u16 ReqTime);





#endif /* TIMER0_INTERFACE_H_ */
