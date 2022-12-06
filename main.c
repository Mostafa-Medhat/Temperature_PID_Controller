/*
 * main.c
 *
 *      Author: Mostafa Medhat
 */

#include "poller.h"
#include "PollingDataClient.h"
#include "lcd.h"
#include "spi.h"
#include "TC72.h"
#include "TimerCompareMode.h"
#include "util/delay.h"

int main(void)
{
	SPI_initMaster();
	TC72_Init(CONTINUOUS_MODE);
	LCD_init();
	SetPollingTime(500);
	Timer2_Init_CTC_Mode(250);
	while(1)
	{
		Poll();
		_delay_ms(500);
	}
}


