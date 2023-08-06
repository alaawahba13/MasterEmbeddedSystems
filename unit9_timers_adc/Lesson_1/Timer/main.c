/*
 * main.c
 *
 *  Created on: 18 Jan 2023
 *      Author: Alaa Wahba
 */

#include "Atmega32/inc/Timer.h"
#include "Atmega32/inc/DIO.h"


#include <stdio.h>
#include <string.h>

void CTC_CallBack(){
	PORTA = ~PORTA;
}

int main(void) {
	SET(SREG,7);
	TIMER0_PinConfig_t pinConfig = {FAST_PWM,CLK_8,OCIE_DISABLE,TOIE_ENABLE,PWM_INVERTING};
	DIO_initPort(PORT_A, PORT_OUTPUT);
	DIO_initPin(PIN_3, PORT_B, OUTPUT);
	Timer0_SetCompareValue(0xFF);
	//Timer0_SetCountValue(192);
   Timer0_CallBack_Overflow(&CTC_CallBack);
	Timer0_init(&pinConfig);

	while (1) {
		for(int i =0 ; i<255 ;i ++){
			Timer0_SetCompareValue(i);
			_delay_ms(100);
		}
		for(int i =255 ; i >=0 ; i--){
				Timer0_SetCompareValue(i);
				_delay_ms(100);
			}

	}

	return 0;
}


