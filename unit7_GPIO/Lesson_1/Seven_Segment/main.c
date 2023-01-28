/*
 * main.c
 *
 *  Created on: 28 Jan 2023
 *      Author: Alaa Wahba
 */

#include "avr/io.h"
#include "util/delay.h"
#include "BIT_MATH.h"
int main(void) {

	DDRC = 0xff;
	while (1) {
		for (char i = 0; i < 10; i++) {  // for left 7 segment
			for (char j = 0; j < 10; j++) {   // for right 7 segment
				/*
				 * i = 0
				 *  0000 0000
				 *  0000 1011
				 *  PORTC =  0000  1011   means zero for 7 segment & ON for 1st & OFF for 2nd
				 */
				PORTC = (0b1011) | (i << 4);
				_delay_ms(50);
				PORTC = (0b0111) | (j << 4);
				_delay_ms(5000);


			}
		}

	}

	return 0;
}
