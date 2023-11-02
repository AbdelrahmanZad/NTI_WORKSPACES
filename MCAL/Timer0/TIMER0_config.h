/*
 * TIMER0_config.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Asus
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#include "TIMER0_private.h"
/*
    timer_OFF, // timer is off //
	no_prescaler,
	FCPU_8,
	FCPU_64,
	FCPU_256,
	FCPU_1024,
	EXT_FALLING,
	EXT_RISING

*/

// Choose from the above //
#define TIMER0_PRESCALER FCPU_1024


#define SYSTEM_CLOCK_SOURCE  16000000

/*
	Normal_OVF_mode,
	PWM_Phase_Correct,
	CTC,
	Fast_PWM,
*/

// choose one of the above //
#define Op_mode Normal_OVF_mode




/*
	OC0_disconnected
	Toggle_OC0_on_compare_match
	Clear_OC0_on_compare_match  -- THIS IS INVERTED FASTPWM
	Set_OC0_on_compare_match   -- THIS IS NON-INVERTED FASTPWM
*/
// choose one of the above //
#define TIMER0_OC0_MODE OC0_disconnected


/*
 * choosing one of two interrupt modes to enable or disable
 */
#define OVERFLOW_INTERRUPT 1
#define OC_INTERRUPT 0



#endif /* TIMER0_CONFIG_H_ */
