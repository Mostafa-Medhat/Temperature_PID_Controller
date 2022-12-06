/*
 * device.c
 *
 *      Author: Mostafa Medhat
 */
#include "device.h"
#include "spi.h"
#include "gpio.h"

unsigned char data;

unsigned char Get_Data(void)
{
	GPIO_writePin(PORTB_ID, PIN4_ID, LOGIC_HIGH);
	SPI_sendReceiveByte(0x02);
	data = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
	GPIO_writePin(PORTB_ID, PIN4_ID, LOGIC_LOW);
	return data;
}
