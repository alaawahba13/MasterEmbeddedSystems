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

void main() {
	// Define PINS 5,6,7 in portD as Output
	SET(DDRD, 5);
	SET(DDRD, 6);
	SET(DDRD, 7);

	while (1) {
		for (int i = 5; i <= 7; i++) {
			SET(PORTD, i);
			delay_ms(1000);
		}
		for (int i = 7; i >= 5; i--) {
			CLEAR(PORTD, i);
			delay_ms(1000);
		}
	}

}
