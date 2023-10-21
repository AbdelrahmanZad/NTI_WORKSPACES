/*
 * Types.h
 *
 *  Created on: Oct 19, 2023
 *      Author: ASUS
 */

#ifndef TYPES_H_
#define TYPES_H_

/* Boolean Data Type */
typedef _Bool boolean;

#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

#define NULL_PTR    ((void*)0)



/* Non-Volatile Data Types */
typedef 	signed char 						s8;
typedef 	unsigned char 						u8;

typedef 	signed short int 					s16;
typedef 	unsigned short int 					u16;

typedef 	signed int 							s32;
typedef 	unsigned int 						u32;

typedef 	signed long long int 				s64;
typedef 	unsigned long long int 				u64;




#endif /* TYPES_H_ */
