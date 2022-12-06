/*
 * PollDataClient.c
 *
 *      Author: Mostafa
 */
#include "PollingDataClient.h"
#include "lcd.h"

void Handle_data(unsigned char data)
{
	LCD_moveCursor(0, 0);
	LCD_intgerToString(data);
}
