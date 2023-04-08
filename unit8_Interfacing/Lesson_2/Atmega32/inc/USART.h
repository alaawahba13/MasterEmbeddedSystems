/*
 * USART.h
 *
 *  Created on: 13 Feb 2023
 *      Author: Alaa Wahba
 */

#ifndef ATMEGA32_INC_USART_H_
#define ATMEGA32_INC_USART_H_
//-----------------------------
//Includes
//-----------------------------
#include "Atmega32.h"
#include "BIT_MATH.h"


/*
* ===============================================
* APIs Supported by "MCAL DIO DRIVER"
* ===============================================
*/

void USART_init(void);
void USART_send(uint8 data);
uint8 USART_recieve();

void USART_sendString(uint8 *str);
void USART_sendNumber(uint32 data);


char* USART_recieveString();
uint32 USART_recieveNumber();





#endif /* ATMEGA32_INC_USART_H_ */
