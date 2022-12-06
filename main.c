/*
 * main.c
 *
 *      Author: Mostafa Medhat
 */

#include "gpio.h"
#include "poller.h"
#include "PollingDataClient.h"
#include "lcd.h"
#include "spi.h"
#include "util/delay.h"


int main(void)
{
	unsigned char temperature = 0;
	SPI_initMaster();

	GPIO_writePin(PORTB_ID, PIN4_ID, LOGIC_HIGH);
	SPI_sendReceiveByte(0x80);
	SPI_sendReceiveByte(0x04);
	GPIO_writePin(PORTB_ID, PIN4_ID, LOGIC_LOW);

//	_delay_ms(200);

	LCD_init();
	SetPollingTime(500);
	while(1)
	{
		LCD_clearScreen();



		GPIO_writePin(PORTB_ID, PIN4_ID, LOGIC_HIGH);
		SPI_sendReceiveByte(0x02);
		temperature = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
		GPIO_writePin(PORTB_ID, PIN4_ID, LOGIC_LOW);
		LCD_intgerToString(temperature);
		_delay_ms(500);

	}

}

