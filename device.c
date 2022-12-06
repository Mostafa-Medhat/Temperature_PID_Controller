/*
 * device.c
 *
 *      Author: Mostafa Medhat
 */
#include "device.h"
#include "TC72.h"
unsigned char data;

unsigned char Get_Data(void)
{
	data = TC72_ReadTemp();
	return data;
}
