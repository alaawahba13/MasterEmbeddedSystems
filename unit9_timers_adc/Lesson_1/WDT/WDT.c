/*
 * main.c
 *
 *  Created on: 18 Jan 2023
 *      Author: Alaa Wahba
 */

#include "Atmega32/inc/WDT.h"
#include "Atmega32/inc/DIO.h"


#include <stdio.h>
#include <string.h>



int main(void) {

	DIO_initPin(PIN_6, PORT_D, OUTPUT);

	while (1) {
		WDT_Enable(WDT_2100_ms);
		DIO_Toggle(PIN_6, PORT_D);
		_delay_ms(100);
		WDT_Disable();

	}

	return 0;
}


