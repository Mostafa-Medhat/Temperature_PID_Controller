/*
 * TC72.c
 *
 *  Created on: Dec 7, 2022
 *      Author: RYZEN
 */

#include "TC72.h"
#include "gpio.h"
#include "spi.h"

void TC72_Init(unsigned char  mode)
{
	GPIO_writePin(PORTB_ID, PIN4_ID, LOGIC_HIGH);	//Enable Chip(slave) select
	SPI_sendReceiveByte(0x80);						// Write Control Address
	SPI_sendReceiveByte(mode);						// Mode: Continuous or One-shot
	GPIO_writePin(PORTB_ID, PIN4_ID, LOGIC_LOW);	//Disable slave select
}

signed char TC72_ReadTemp(void)
{
	unsigned char data;
	GPIO_writePin(PORTB_ID, PIN4_ID, LOGIC_HIGH);	//Enable Chip Select
	SPI_sendReceiveByte(0x02);						//Send MSB Address
	data = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);	//Read Temperature
	GPIO_writePin(PORTB_ID, PIN4_ID, LOGIC_LOW);	//Disable Chip Select
	return data;
}
