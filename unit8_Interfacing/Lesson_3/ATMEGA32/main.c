/*
 * main.c
 *
 *  Created on: 18 Jan 2023
 *      Author: Alaa Wahba
 */

#include "USART.h"
#include "LCD.h"
int main(void){
	lcd_init();
	USART_init();
	uint8 str[100]; 
	uint8 y,x=0;

	//lcd_send_String("Hi ");
	//uint32 x;
	//USART_send('A');
	//USART_sendNumber(300);
	//USART_sendNumber(55);
	//USART_sendNumber(8);
	USART_send_string_Asynch("I'M PIZZA");
	while (1) {
		lcd_GOTO_XY(1, 0);
	//	x = USART_recieveNumber();
	//	lcd_display_number(x);

	//	if(USART_recievePeriodicData(&y))
	//		lcd_send_String(&y);
		USART_recieveString(str);
		lcd_send_String(str);

		lcd_GOTO_XY(0, 0);
	//	lcd_display_Real_number(x);
		x++;
		if(x==10){
			x=0;
		}
		_delay_ms(200);

	}


	return 0;
}

