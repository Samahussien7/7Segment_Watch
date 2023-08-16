/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: ProBook G7
 */
#include "../HAL/7segment/7_segment_init.h"
#include "../MCAL/DIO/DIO.h"
#include <util/delay.h>

void void_minutes();

void main() {


	HSSD_voidInit(0);
	HSSD_voidInit(1);
	HSSD_voidInit(2);
	HSSD_voidInit(3);
	u8 L_hourIterations;
	u8 L_first_digit, L_second_digit;

	while(1){
		for(L_hourIterations=1;L_hourIterations<=24;L_hourIterations++)
		{
			if(L_hourIterations==24)
					{
						HSSD_voidDisplayNumber(PORTA,0);
						HSSD_voidDisplayNumber(PORTB,0);
					}
			void_minutes();
			if(L_hourIterations<10) {HSSD_voidDisplayNumber(PORTA,L_hourIterations);}

			else
			{
				  L_first_digit = L_hourIterations / 10;
				  L_second_digit = L_hourIterations % 10;

				  HSSD_voidDisplayNumber(PORTB,L_first_digit);
				  HSSD_voidDisplayNumber(PORTA,L_second_digit);
			}
		}
	}
}

void void_minutes()
{
	u8 L_secIterations;
	u8 L_minIterations;
	u8 L_first_digit, L_second_digit;
	for(L_minIterations=1;L_minIterations<=60;L_minIterations++){
		if(L_minIterations==60)
		{
			HSSD_voidDisplayNumber(PORTC,0);
			HSSD_voidDisplayNumber(PORTD,0);
			break;
		}
		for(L_secIterations=0;L_secIterations<60;L_secIterations++)
		{
			_delay_ms(900);   //the delay is 900 less than 1000ms -->1 sec considering the hardware delay and instructions delay
		}

		if(L_minIterations<10) {HSSD_voidDisplayNumber(PORTD,L_minIterations)}
		else
		{
			  L_first_digit = L_minIterations / 10;
			  L_second_digit = L_minIterations % 10;

			  HSSD_voidDisplayNumber(PORTC,L_first_digit);
			  HSSD_voidDisplayNumber(PORTD,L_second_digit);


		}
	}
}
