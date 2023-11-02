/*
 * TIMER0.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Asus
 */

#include "Types.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"


u32 Global_u32Number_Of_Overflow = 0;
u32 Global_u32RemainingTime = 0;
TIMER0_GLOBAL_t TIM0_GLOBAL_FUN = TIMER0_NO_OPERATION;




static void (*Timer0_OVF_Fptr) (void)=NULLPTR;
static void (*Timer0_OC_Fptr) (void)=NULLPTR;


void TIMER0_init(void){

	// set the OC0 mode by masking technique
	Ptr_timer_registers->TCCR0 &= TIMER0_OC0_MODE_MASK;
	Ptr_timer_registers->TCCR0 |= (TIMER0_OC0_MODE << 4);

	// Setting Timer Mode //
#if Op_mode == Normal_OVF_mode
	{
		CLEAR_BIT((Ptr_timer_registers->TCCR0), 3);
		CLEAR_BIT(Ptr_timer_registers->TCCR0, 6);
	}

#elif Op_mode == PWM_Phase_Correct
	{
		SET_BIT(Ptr_timer_registers->TCCR0, 6);
		CLEAR_BIT(Ptr_timer_registers->TCCR0, 3);
	}
#elif Op_mode == CTC
	{
		CLEAR_BIT(Ptr_timer_registers->TCCR0, 6);
		SET_BIT(Ptr_timer_registers->TCCR0, 3);
	}

#elif Op_mode == Fast_PWM
	{
		SET_BIT(Ptr_timer_registers->TCCR0, 3);
		SET_BIT(Ptr_timer_registers->TCCR0, 6);
	}

#else
	{
#error ("wrong mode choice !")

	}

#endif
}

void TIMER0_Start(void) {

	Ptr_timer_registers->TCCR0 &= TIMER0_PRESCALER_MASK;
	Ptr_timer_registers->TCCR0 |= TIMER0_PRESCALER;


}

void TIEMR0_Stop(void){

	Ptr_timer_registers->TCCR0 &= TIMER0_PRESCALER_MASK;
	Ptr_timer_registers->TCCR0 |= timer_OFF;

}


void TIMER0_Interrupt_Enable(u8 Int_ID ){

	if (Int_ID == OC_INTERRUPT)
	{
		SET_BIT(Ptr_timer_registers->TIMSK, 1);
	}
	else if (Int_ID == OVERFLOW_INTERRUPT)
	{
		SET_BIT(Ptr_timer_registers->TIMSK, 0);
	}

}

void TIMER0_IntDis(u8 Int_ID) {

	if (Int_ID == OC_INTERRUPT)
		{
			CLEAR_BIT(Ptr_timer_registers->TIMSK, 1);
		}
		else if (Int_ID == OVERFLOW_INTERRUPT)
		{
			CLEAR_BIT(Ptr_timer_registers->TIMSK, 0);
		}


}


void TIMER0_SetDelayTimeMilliSec(u16 reqTime)
{
		TIM0_GLOBAL_FUN = TIMER0_SET_DELAY_FUNCTION;
		TIMER0_IntDis(OVERFLOW_INTERRUPT);

		u32 Local_u32Load = 0;
		u32 Timer0_CLK = 0 ;

		#if TIMER0_PRESCALER   == timer_OFF
			Timer0_CLK = 0 ;
		#elif TIMER0_PRESCALER == no_prescaler
			Timer0_CLK = SYSTEM_CLOCK_SOURCE ;
		#elif TIMER0_PRESCALER == FCPU_8
			Timer0_CLK = (SYSTEM_CLOCK_SOURCE/8) ;
		#elif TIMER0_PRESCALER == FCPU_64
			Timer0_CLK = (SYSTEM_CLOCK_SOURCE/64) ;
		#elif TIMER0_PRESCALER == FCPU_256
			Timer0_CLK = (SYSTEM_CLOCK_SOURCE/256) ;
		#elif TIMER0_PRESCALER == FCPU_1024
			Timer0_CLK = (SYSTEM_CLOCK_SOURCE/1024) ;
		#else
			#error (" Configuration error")
		#endif


		/* CALCULATIONS */
		Local_u32Load = reqTime * (Timer0_CLK / 1000) ;
		Global_u32Number_Of_Overflow = Local_u32Load / 255 ;
		Global_u32RemainingTime  = Local_u32Load % 255;
		/* Start Timer */
		TIMER0_Start();

		/* Enable Interrupt */
		TIMER0_Interrupt_Enable(OVERFLOW_INTERRUPT);

		while(TIM0_GLOBAL_FUN == TIMER0_SET_DELAY_FUNCTION);
}

void TIMER0_setFastPWM(u8 duty)
{

#if Op_mode == Fast_PWM

		u8 DutyCycle = 0;

		TIMER0_IntDis(OC_INTERRUPT);

		#if TIMER0_OC0_MODE == Set_OC0_on_compare_match   //NON-INVERTED MODE

			DutyCycle = (duty * 255)/100 ;
			Ptr_timer_registers ->OCR0 = DutyCycle ;

			/* Start Timer */
			TIEMR0_start();
			/* Enable Interrupt */
			TIMER0_Interrupt_Enable(OC_INTERRUPT);


		#elif TIMER0_OC0_MODE == Clear_OC0_on_compare_match    //INVERTED MODE

			DutyCycle = (duty * 255)/100 ;

			Ptr_timer_registers->OCR0 = 255 - DutyCycle ;
			/* Start Timer */
			TIEMR0_start();
			/* Enable Interrupt */
			TIMER0_Interrupt_Enable(OC_INTERRUPT);

		#endif
	#else
		#warning "Wrong fastPwm mode choice"
	#endif

}

void TIMER0_setphaseCorrectPWM(u8 duty)
{

#if Op_mode == PWM_Phase_Correct

		u8 DutyCycle = 0;

		TIMER0_IntDis(OC_INTERRUPT);


		#if TIMER0_OC0_MODE == Clear_OC0_on_compare_match   //NON-INVERTED MODE

				DutyCycle = (duty * 255)/100 ;
				Ptr_timer_registers ->OCR0 = DutyCycle ;

				/* Start Timer */
				TIEMR0_start();
				/* Enable Interrupt */
				TIMER0_Interrupt_Enable(OC_INTERRUPT);

		#elif TIMER0_OC0_MODE == Set_OC0_on_compare_match     //INVERTED MODE

			DutyCycle = (duty * 255)/100 ;

			Ptr_timer_registers->OCR0 = 255 - DutyCycle;
				/* Start Timer */
				TIEMR0_start();
				/* Enable Interrupt */
				TIMER0_Interrupt_Enable(OC_INTERRUPT);

		#endif
	#else
		#warning "Phase Correct PWM is Disabled"
	#endif
}


void TIMER0_OV_SetCallBack(void(*local_fptr)(void))
{
	Timer0_OVF_Fptr=local_fptr;

}
void TIMER0_OC_SetCallBack(void(*local_fptr)(void))
{
	Timer0_OC_Fptr=local_fptr;

}


TIMER0_Overflow_IRQHandler
{
		static u32 Timer_Overflow_counter = 0;
		Timer_Overflow_counter++;
		if(Timer_Overflow_counter == Global_u32Number_Of_Overflow)
		{
			Ptr_timer_registers->OCR0 = Global_u32RemainingTime;
			Timer_Overflow_counter = 0 ;
			TIM0_GLOBAL_FUN = TIMER0_NO_OPERATION ;
			if (Timer0_OVF_Fptr != NULLPTR)
			{
			            Timer0_OVF_Fptr(); // Callback function for overflow
			}
		}
	}


/* Timer/Counter0 Compare Match  ISR */
TIMER0_CompareMatch_IRQHandler{

    if (Timer0_OC_Fptr != NULLPTR)
    {
        Timer0_OC_Fptr(); // Callback function for compare match
    }
}


