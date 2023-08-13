/*
 * main.c
 *
 *  Created on: 18 Jan 2023
 *      Author: Alaa Wahba
 */

#include "Atmega32/inc/USART.h"
#include "Atmega32/inc/GI.h"
#include "HAL/LCD_Driver/LCD.h"

#include <stdio.h>
#include <string.h>

int main(void){
	lcd_init();
	USART_init();
	GI_Enable();


	uint32 x;
	uint8 y;
	//USART_send('A');
	//USART_sendNumber(300);
	//lcd_Send_Char(USART_recieve());
	//USART_sendString("x");
	//	USART_recieveString(str);
	//lcd_send_String(str);

	//x = USART_recieveNumber();
	//lcd_display_number(x);

//USART_send_string_Asynch("I'M PIZZA");
	USART_send_string_Asynch("HELLO ALAA");

	while (1) {

		lcd_GOTO_XY(1, 0);


	if(USART_recievePeriodicData(&y))
			lcd_send_String(&y);
		//USART_recieveString(str);
		//lcd_send_String(str);

		lcd_GOTO_XY(0, 0);
		lcd_display_Real_number(x);
		x++;
		if(x==10){
			x=0;
		}
		_delay_ms(200);


	}


	return 0;
}
