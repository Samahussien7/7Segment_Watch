/*
 * 7_segmenty.c
 *
 *  Created on: Aug 13, 2023
 *      Author: ProBook G7
 */
#include<util/delay.h>
#include"../../LIB/std_types.h"
#include"../../LIB/bit_math.h"
#include"../../MCAL/DIO/DIO.h"
#include"7_segment_init.h"


static const u8 G_u8SSD_Num[10]= {
		0b00111111 , //0
		0b00000110 , //1
		0b01011011 , //2
		0b01001111 , //3
		0b01100110 , //4
		0b01101101 , //5
		0b01111101 , //6
		0b00000111 , //7
		0b01111111 , //8
		0b01101111   //9
};

void HSSD_voidInit(u8 A_u8SSD_PORT)
{

	MDIO_voidSetPortDirection(A_u8SSD_PORT,0xff);
}

 void HSSD_voidDisplayNumber(u8 A_u8SSD_PORT, u8 A_u8Number)
{
	if((A_u8Number <=9) &&(A_u8Number >=0))
	{
		#if SSD_Type==1
		MDIO_voidSetPortValue(A_u8SSD_PORT, G_u8SSD_Num[A_u8Number]);
		#elif SSD_Type==2
		MDIO_voidSetPortValue(A_u8SSD_PORT, ~G_u8SSD_Num[A_u8Number]);
		#endif
	}
}


void HSSD_voidTurnOff(u8 A_u8SSD_PORT)
{

	#if SSD_Type==1
		MDIO_voidSetPortValue(A_u8SSD_PORT, 0x00);
	#elif SSD_Type==2
		MDIO_voidSetPortValue(A_u8SSD_PORT, 0xff);
	#endif

}


void HSSD_voidCountUp(u8 A_u8SSD_PORT ,u8 A_u8Number)
{
	for(u8 counter=A_u8Number ; counter<=9; counter++)
	{
		HSSD_voidDisplayNumber(A_u8SSD_PORT,counter);
		_delay_ms(1000);
	}

}

void HSSD_voidCountdown(u8 A_u8SSD_PORT,u8 A_u8Number)
{
	for(u8 counter=A_u8Number ; counter>=0 ; counter--)
	{
		HSSD_voidDisplayNumber(A_u8SSD_PORT,counter);
		_delay_ms(1000);
	}

}
