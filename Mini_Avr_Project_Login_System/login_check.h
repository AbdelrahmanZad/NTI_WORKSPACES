/*
 * login_check.h
*
 *  Created on: Oct 25, 2023
 *      Author: Asus
 */

#ifndef LOGIN_CHECK_H_
#define LOGIN_CHECK_H_
#include "Types.h"

typedef struct
{
	u8  person_NAME[20];
	u16 person_ID;
	u16 person_PASSWORD;
}Data_t;

/**************** prototypes **********************/
void initializeDatabase(void);
u8 ID_check(int* pID);
u8 PASSWORD_check(int* pPASSWORD);

#endif /* LOGIN_CHECK_H_ */
