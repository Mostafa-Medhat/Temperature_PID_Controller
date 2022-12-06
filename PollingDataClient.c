/*
 * PollDataClient.c
 *
 *      Author: Mostafa
 */
#include "PollingDataClient.h"
#include "lcd.h"

void Handle_data(float data)
{
	LCD_intgerToString(data);
}
