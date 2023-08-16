/*
 * DIO.c
 *
 *  Created on: Aug 12, 2023
 *      Author: ProBook G7
 */
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"
#include "DIO.h"


#define DIO_PORTA_REG		*((volatile u8 *)0X3B)
#define DIO_DDRA_REG		*((volatile u8 *)0X3A)
#define DIO_PINA_REG		*((volatile u8 *)0X39)

#define DIO_PORTB_REG		*((volatile u8 *)0X38)
#define DIO_DDRB_REG		*((volatile u8 *)0X37)
#define DIO_PINB_REG		*((volatile u8 *)0X36)

#define DIO_PORTC_REG		*((volatile u8 *)0X35)
#define DIO_DDRC_REG		*((volatile u8 *)0X34)
#define DIO_PINC_REG		*((volatile u8 *)0X33)

#define DIO_PORTD_REG		*((volatile u8 *)0X32)
#define DIO_DDRD_REG		*((volatile u8 *)0X31)
#define DIO_PIND_REG		*((volatile u8 *)0X30)



void MDIO_voidSetPinValue(u8 A_u8PortNum, u8 A_u8PinNum, u8 A_u8PinVal)
{
	if((A_u8PortNum<=PORTD)&&(A_u8PinNum<=PIN7)&&(A_u8PinNum<=HIGH))
	{
		switch (A_u8PortNum)
		{
			case PORTA:
				switch (A_u8PinVal)
				{
					case INPUT:clr_bit(DIO_PORTA_REG, A_u8PinNum); break;
					case OUTPUT:set_bit(DIO_PORTA_REG, A_u8PinNum); break;
				}
				break;
			case PORTB:
				switch (A_u8PinVal)
				{
					case INPUT:clr_bit(DIO_PORTB_REG, A_u8PinNum); break;
					case OUTPUT:set_bit(DIO_PORTB_REG, A_u8PinNum); break;
				}
				break;
			case PORTC:
				switch (A_u8PinVal)
				{
					case INPUT:clr_bit(DIO_PORTC_REG, A_u8PinNum); break;
					case OUTPUT:set_bit(DIO_PORTC_REG, A_u8PinNum); break;
				}
				break;
			case PORTD:
				switch (A_u8PinVal)
				{
					case INPUT:clr_bit(DIO_PORTD_REG, A_u8PinNum); break;
					case OUTPUT:set_bit(DIO_PORTD_REG, A_u8PinNum); break;
				}
				break;
		}
	}
}

void MDIO_voidSetPinDirection(u8 A_u8PortNum, u8 A_u8PinNum, u8 A_u8PinDirection)
{
	if((A_u8PortNum<=PORTD)&&(A_u8PinNum<=PIN7)&&(A_u8PinDirection<=OUTPUT))
	{
		switch (A_u8PortNum)
			{
				case PORTA:
					switch (A_u8PinDirection)
					{
						case INPUT:clr_bit(DIO_DDRA_REG, A_u8PinNum); break;
						case OUTPUT:set_bit(DIO_DDRA_REG, A_u8PinNum); break;
					}
					break;
				case PORTB:
					switch (A_u8PinDirection)
					{
						case INPUT:clr_bit(DIO_DDRB_REG, A_u8PinNum); break;
						case OUTPUT:set_bit(DIO_DDRB_REG, A_u8PinNum); break;
					}
					break;
				case PORTC:
					switch (A_u8PinDirection)
					{
						case INPUT:clr_bit(DIO_DDRC_REG, A_u8PinNum); break;
						case OUTPUT:set_bit(DIO_DDRC_REG, A_u8PinNum); break;
					}
					break;
				case PORTD:
					switch (A_u8PinDirection)
					{
						case INPUT:clr_bit(DIO_DDRD_REG, A_u8PinNum); break;
						case OUTPUT:set_bit(DIO_DDRD_REG, A_u8PinNum); break;
					}
					break;
			}
	}

}

u8 MDIO_U8GetPinValue(u8 A_u8PortNum, u8 A_u8PinNum)
{
	u8 L_u8PinValue=2;
	if((A_u8PortNum<=PORTD)&&(A_u8PinNum<=PIN7))
	{
		switch(A_u8PortNum)
		{
			case PORTA:
						L_u8PinValue=get_bit(DIO_PINA_REG, A_u8PinNum); break;
			case PORTB:
						L_u8PinValue=get_bit(DIO_PINB_REG, A_u8PinNum); break;
			case PORTC:
						L_u8PinValue=get_bit(DIO_PINC_REG, A_u8PinNum); break;
			case PORTD:
						L_u8PinValue=get_bit(DIO_PIND_REG, A_u8PinNum); break;
		}
	}
	return L_u8PinValue;

}

void MDIO_voidSetPortValue(u8 A_u8PortNum,  u8 A_u8PortVal)
{
	if(A_u8PortNum<=PORTD)
	{
		switch(A_u8PortNum)
		{
			case PORTA:
				DIO_PORTA_REG=A_u8PortVal; break;
			case PORTB:
				DIO_PORTB_REG=A_u8PortVal; break;
			case PORTC:
				DIO_PORTC_REG=A_u8PortVal; break;
			case PORTD:
				DIO_PORTD_REG=A_u8PortVal; break;
		}
	}
}

void MDIO_voidSetPortDirection(u8 A_u8PortNum, u8 A_u8PortDirection)
{
	if(A_u8PortNum<=PORTD)
	{
		switch(A_u8PortNum)
		{
			case PORTA:
				DIO_DDRA_REG=A_u8PortDirection; break;
			case PORTB:
				DIO_DDRB_REG=A_u8PortDirection; break;
			case PORTC:
				DIO_DDRC_REG=A_u8PortDirection; break;
			case PORTD:
				DIO_DDRD_REG=A_u8PortDirection; break;
		}
	}
}



