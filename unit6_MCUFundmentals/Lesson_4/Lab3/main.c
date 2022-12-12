/*
 * main.c
 *
 *  Created on: Dec 6, 2022
 *      Author: Alaa
 */
#include "Platform_types.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#define F_CPU 8000000UL

#define IO_BASE 0x20

#define PORTD      *(volatile uint8 *) (IO_BASE + 0x12)
#define DDRD        *(volatile uint8*)(IO_BASE + 0x11)
// MCU CONTROL REGISTER
#define MCUCR *((volatile uint8 *)( IO_BASE+ 0x35))

//MCU CONTROL AND STATUS REGISTER
#define MCUCSR *((volatile uint8 *)(IO_BASE +0x34))

// General interrupt control register
#define GICR *((volatile uint8 *)(IO_BASE + 0x3B))


int main() {
	//set pins as OUPUT
	SET_BIT(DDRD, 5);
	SET_BIT(DDRD, 6);
	SET_BIT(DDRD, 7);
	// Any logical change for ISC0
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	// rising edge for ISC1
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	//falling edge for ISC2
	CLR_BIT(MCUCSR,6);
	//Enable INT0, INT1, INT2 pins
	SET_BIT(GICR, 5);
	SET_BIT(GICR, 6);
	SET_BIT(GICR, 7);
	sei();
	while(1){

		CLR_BIT(PORTD, 5);
		CLR_BIT(PORTD, 6);
		CLR_BIT(PORTD, 7);
	}


}

 ISR(INT0_vect){
	 SET_BIT(PORTD,5);
	 _delay_ms(1000);
 }
 ISR(INT1_vect){
	 SET_BIT(PORTD,6);
	 _delay_ms(1000);
 }
 ISR(INT2_vect){
	 SET_BIT(PORTD,7);
	 _delay_ms(1000);

 }
