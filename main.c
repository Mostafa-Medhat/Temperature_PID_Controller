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


#define PID_KP  0.1f
#define PID_KI  0.01f
#define PID_KD  0.0f

#define PID_LIM_MIN -10.0f
#define PID_LIM_MAX  10.0f

#define PID_LIM_MIN_INT -5.0f
#define PID_LIM_MAX_INT  5.0f


int main(void)
{
	SREG  |= (1<<7);           // Enable global interrupts in MC.

	SPI_initMaster();
	TC72_Init(CONTINUOUS_MODE);
	LCD_init();

	PIDController pid =
	{
	PID_KP, PID_KI, PID_KD,
	PID_LIM_MIN, PID_LIM_MAX,
	PID_LIM_MIN_INT, PID_LIM_MAX_INT
	};

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

