/*
 * main.h
 *
 *  Created on: Jan 26, 2023
 *      Author: Alaa Wahba
 */

#ifndef INC_MAIN_H_
#define INC_MAIN_H_

#include "GPIO.h"
#include "STM32_F103x6.h"
#include "LCD.h"
#include "Keypad.h"
#include "EXTI.h"

#define ZERO	 0x01
#define ONE 	 0x79
#define TWO		 0x24
#define THREE 	 0x30
#define FOUR 	 0x4C
#define FIVE     0x12
#define SIX		 0x02
#define SEVEN 	 0x19
#define EIGHT	 0x00
#define NINE	 0x10

void delay_ms(uint32 time);

#endif /* INC_MAIN_H_ */
