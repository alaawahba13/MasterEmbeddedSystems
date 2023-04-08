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
/*DIO_initPin(PIN_5, PORT_D, OUTPUT);
	DIO_initPin(PIN_6, PORT_D, OUTPUT);
	DIO_initPin(PIN_7, PORT_D, OUTPUT);
	while (1) {
			for (int i = 5; i <= 7; i++) {
				DIO_WritePin(i, PORT_D, HIGH);
				_delay_ms(1000);
			}
			for (int i = 7; i >= 5; i--) {
				DIO_WritePin(i, PORT_D, LOW);
				_delay_ms(1000);
			}
		}*/
