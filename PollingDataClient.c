/*
 * PollDataClient.c
 *
 *      Author: Mostafa
 */
#include "PollingDataClient.h"
#include "lcd.h"
#include "PID.h"

void Handle_data(unsigned char data)
{
	LCD_moveCursor(0, 0);
	LCD_intgerToString(data);
	PIDController_Update(pid, SET_POINT, data);
}
