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
#include "PID.h"
#include <avr/interrupt.h>




int main(void)
{
	SREG  |= (1<<7);           // Enable global interrupts in MC.

	SPI_initMaster();
	TC72_Init(CONTINUOUS_MODE);
	LCD_init();


	PIDController_Init(&pid);

	SetPollingTime(500);
	Timer2_Init_CTC_Mode(250);

	while(1)
	{

	}
}

ISR(TIMER2_COMP_vect)
{
	Poll();
}

