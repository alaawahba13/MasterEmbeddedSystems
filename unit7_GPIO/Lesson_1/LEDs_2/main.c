/*
 * main.c
 *
 *  Created on: 11 Jan 2023
 *      Author: Alaa Wahba
 */

#include "Registers.h"
#include "BIT_MATH.h"

void delay_ms(int time) {
	for (uint32 i = 0; i < time; i++)
		for (uint32 j = 0; j < 255; j++);
}

int main() {
	// Define PINS 5,6,7 in portD as Output
	SET(DDRD, 5);
	SET(DDRD, 6);
	SET(DDRD, 7);
	// configure pin 0 port D as input with no pull up resistor
	CLEAR(DDRD, 0);
	CLEAR(PORTD,0);
	uint8 count = 5;
	while (1) {
		if(GET(PIND, 0) == 1){
			SET(PORTD, count);
			count ++;
			while((GET(PIND, 0) == 1));
		}

	}
return 0;
}
