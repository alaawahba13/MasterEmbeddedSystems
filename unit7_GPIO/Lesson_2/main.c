/*
 * main.c
 *
 *  Created on: 17 Jan 2023
 *      Author: Alaa Wahba
 */

#include "LCD.h"
#include "Keypad.h"

int main(void){
	lcd_init();
	Keypad_init();
	char key='X';
	while(1){
		key = Keypad_Get_Key();
		switch(key){
		case 'A':
			break;
		case '?':
			lcd_Clear_Screen();
			break;
		default:
			lcd_Send_Char(key);
			break;
		}
	}

	return 0;
}


