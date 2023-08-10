/*
 * main.c
 *
 *  Created on: 18 Jan 2023
 *      Author: Alaa Wahba
 */

#include "Atmega32/inc/ADC.h"
#include "Atmega32/inc/GI.h"
#include "HAL/LCD_Driver/LCD.h"
#include <stdio.h>
#include <string.h>

void ADC_fun() {
}

int main(void) {
	GI_Enable();
	lcd_init();
	//uint32 Temp;
	uint64 percentage;
	uint16 val,size;
	ADC_pinConfig_t ADC_pinConfig = { VCC_5, RIGHT, PRESCALAR_64, DISABLE,SINGLE_CONVERSION, NULL };
	ADC_init(&ADC_pinConfig);
	lcd_GOTO_XY(0, 0);
	lcd_send_String("Percent is: ");

	while (1) {
		val = ADC_Read(ADC3);
			//	lcd_display_number(val);
		//		lcd_send_String("  ");
	//	Temp = (((uint32) val) * 500) / 1024;
		percentage = ((uint64)val *100) /1024;
	//	lcd_GOTO_XY(1, 8);
		lcd_GOTO_XY(0,13);
		lcd_display_number(percentage);
	//	lcd_send_String("  ");
		// 16 >> 100
		//?? >> percentage
		size = (16*percentage)/100;
		lcd_GOTO_XY(1, 0);
		for(int i=0 ; i<size ;i++){
			lcd_Send_Char(0xff);
		}
	}

	return 0;
}

