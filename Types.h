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

#ifndef TURE
#define TURE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif


/* Non-Volatile Data Types */
typedef 	signed char 						s8;
typedef 	unsigned char 						u8;

typedef 	signed short int 					s16;
typedef 	unsigned short int 					u16;

typedef 	signed int 							s32;
typedef 	unsigned int 						u32;

typedef 	signed long long int 				s64;
typedef 	unsigned long long int 				u64;


/* Volatile Data Types */
typedef 	volatile signed char 				vsint8_t;
typedef 	volatile unsigned char 				vusint8_t;

typedef 	volatile signed short int 			vsint16_t;
typedef 	volatile unsigned short int 		vusint16_t;

typedef 	volatile signed int 				vsint32_t;
typedef 	volatile unsigned int 				vusint32_t;

typedef 	volatile signed long long int 		vsint64_t;
typedef 	volatile unsigned long long int 	vusint64_t;





#endif /* TYPES_H_ */
