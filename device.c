/*
 * device.c
 *
 *      Author: Mostafa Medhat
 */
#include "device.h"
#include "spi.h"

unsigned char data;

unsigned char Get_Data(void)
{
	SPI_sendReceiveByte(0x80);
	data = SPI_sendReceiveByte(0x02);
	return data;
}
