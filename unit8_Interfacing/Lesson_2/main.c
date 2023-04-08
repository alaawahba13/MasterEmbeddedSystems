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
	char* str;

	lcd_GOTO_XY(0, 0);
	lcd_send_String("Hi ");
	uint32 x;
	//USART_send('A');
	USART_sendNumber(300);
	USART_sendNumber(55);
	USART_sendNumber(8);
	//USART_sendString("I'M PIZZA");

	while (1) {
	//	lcd_GOTO_XY(1, 0);
	//	x = USART_recieveNumber();
	//	lcd_display_number(x);
	//	str= USART_recieveString();
	//	lcd_send_String(str);

	}


	return 0;
}
