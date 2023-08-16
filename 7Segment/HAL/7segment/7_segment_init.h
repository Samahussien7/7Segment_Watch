/*
 * 7_segment_init.h
 *
 *  Created on: Aug 13, 2023
 *      Author: ProBook G7
 */

#ifndef HAL_7SEGMENT_7_SEGMENT_INIT_H_
#define HAL_7SEGMENT_7_SEGMENT_INIT_H_

#include"../../LIB/std_types.h"

#define Cathode 1
#define Anode   2

#define SSD_Type	Cathode


/*
  //Table for common cathode

Digit	A	B	C	D	E	F	G
0		1	1	1	1	1	1	0
1		0	1	1	0	0	0	0
2		1	1	0	1	1	0	1
3		1	1	1	1	0	0	1
4		0	1	1	0	0	1	1
5		1	0	1	1	0	1	1
6		1	0	1	1	1	1	1
7		1	1	1	0	0	0	0
8		1	1	1	1	1	1	1
9		1	1	1	1	0	1	1
A		1	1	1	0	1	1	1
b		0	0	1	1	1	1	1
C		1	0	0	1	1	1	0
d		0	1	1	1	1	0	1
E		1	0	0	1	1	1	1
F		1	0	0	0	1	1	1

 */

 // macros to define numbers in English
 //avoid problem if user entered HSSD_voidDisplayNumber(zero) writing in English

#define zero	0
#define one		1
#define two		2
#define three	3
#define four	4
#define five	5
#define six		6
#define seven	7
#define eight	8
#define nine	9


void HSSD_voidInit(u8 A_u8SSD_PORT);
void HSSD_voidDisplayNumber(u8 A_u8SSD_PORT, u8 A_u8Number);
void HSSD_voidTurnOff(u8 A_u8SSD_PORT);
void HSSD_voidCountUp(u8 A_u8SSD_PORT ,u8 A_u8Number);
void HSSD_voidCountdown(u8 A_u8SSD_PORT,u8 A_u8Number);


#endif /* HAL_7SEGMENT_7_SEGMENT_INIT_H_ */
