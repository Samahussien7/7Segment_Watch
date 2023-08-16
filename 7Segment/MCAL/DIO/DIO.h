/*
 * DIO.h
 *
 *  Created on: Aug 12, 2023
 *      Author: ProBook G7
 */

#ifndef DIO_H_
#define DIO_H_

//Ports

#define PORTA 		0
#define PORTB 		1
#define PORTC 		2
#define PORTD 		3

//I/O
#define INPUT		0
#define OUTPUT		1

//PINS

#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7

//values
#define LOW			0
#define HIGH 		1



void MDIO_voidSetPinValue(u8 A_PortNum, u8 A_PinNum, u8 A_PinVal);

void MDIO_voidSetPinDirection(u8 A_PortNum, u8 A_PinNum, u8 A_PinDirection);

u8 MDIO_U8GetPinValue(u8 A_PortNum, u8 A_PinNum);


void MDIO_voidSetPortValue(u8 A_PortNum,  u8 A_PortVal);

void MDIO_voidSetPortDirection(u8 A_PortNum, u8 A_PortDirection);



#endif /* DIO_H_ */
