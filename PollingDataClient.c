/*
 * PollDataClient.c
 *
 *      Author: Mostafa
 */
#include "PollingDataClient.h"
#include "lcd.h"

void Handle_data(unsigned char data)
{
	LCD_clearScreen();
	LCD_intgerToString(data);
}
