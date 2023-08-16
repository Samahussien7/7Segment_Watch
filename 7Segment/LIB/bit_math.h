/*
 * bit_math.h
 *
 *  Created on: Aug 12, 2023
 *      Author: ProBook G7
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define set_bit(reg,bitnum)    reg|=1<<bitnum
#define clr_bit(reg,bitnum)    reg&=~(1<<bitnum)
#define toggle_bit(reg,bitnum) reg^=1<<bitnum
#define get_bit(reg,bitnum)    (reg>>bitnum)&0x01
#define set_byte(reg,val)      (reg=val)


#endif /* BIT_MATH_H_ */
