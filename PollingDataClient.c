/*
 * PollDataClient.c
 *
 *      Author: Mostafa
 */
#include "PollingDataClient.h"
#include "lcd.h"
#include "PID.h"
#include "pwm.h"

void Handle_data(signed char data)
{
	LCD_moveCursor(0, 0);
	if(data < 0)
	{
		LCD_displayCharacter('-');
		LCD_intgerToString(-data);
		if(data>-10)
		{
			LCD_displayCharacter(' ');
		}
	}
	else if(data >=0)
	{
		LCD_intgerToString(data);
		if(data<10)
		{
			LCD_displayCharacter(' ');
		}
		if(data<100)
		{
			LCD_displayCharacter(' ');
		}
	}
	float feedbackSignal = PIDController_Update(&pid, SET_POINT, data);
	if(feedbackSignal < 0)
	{
		feedbackSignal = -feedbackSignal;
	}
	uint8 duty_cycle= (uint8)((feedbackSignal/100.0)*255);
	PWM_Timer0_Start(duty_cycle);

}
