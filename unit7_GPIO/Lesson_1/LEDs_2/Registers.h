/*
 * Registers.h
 *
 *  Created on: 11 Jan 2023
 *      Author: Alaa Wahba
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "Platform_types.h"
#define vuint8_t volatile uint8

// PORT A
#define PORTA *((vuint8_t *) 0x3B)
#define DDRA *((vuint8_t *) 0x3A)
#define PINA *((vuint8_t *) 0x39)

//PORT B
#define PORTB *((vuint8_t *) 0x38)
#define DDRB *((vuint8_t *) 0x37)
#define PINB *((vuint8_t *) 0x36)

//PORT C
#define PORTC *((vuint8_t *) 0x35)
#define DDRC *((vuint8_t *) 0x34)
#define PINC *((vuint8_t *) 0x33)

//PORT D
#define PORTD *((vuint8_t *) 0x32)
#define DDRD *((vuint8_t *) 0x31)
#define PIND *((vuint8_t *) 0x30)

#endif /* REGISTERS_H_ */
