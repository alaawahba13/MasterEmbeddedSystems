/*
 * main.c     MASTER
 *
 *  Created on: 18 Jan 2023
 *      Author: Alaa Wahba
 */

#include "SPI.h"
#include "DIO.h"
#include "LCD.h"
uint8 x, data = 'A' , recieve_data;

int main(void) {
		SPI_Init();
		lcd_init();
		lcd_send_String("MASTER");
		while(1){
			recieve_data = SPI_SendRecieveData(data);
			data++;
			if(data == 'Z' +1)
				data = 'A';
			lcd_GOTO_XY(1, 0);
			lcd_display_number(recieve_data);
			lcd_GOTO_XY(0, 9);
			lcd_display_number(x);
			_delay_ms(2000);
			x++;
			if(x==10)
				x= 0;

		}

}

