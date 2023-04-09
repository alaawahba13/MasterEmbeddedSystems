/*
 * SPI.h
 *
 *  Created on: 22 Feb 2023
 *      Author: Alaa Wahba
 */

#ifndef ATMEGA32_INC_SPI_H_
#define ATMEGA32_INC_SPI_H_

#include "DIO.h"
#include "Atmega32.h"
#include "BIT_MATH.h"

#define SPI_PORT			PORT_B
#define MOSI 				PIN_5
#define MISO 				PIN_6
#define SCLK 				PIN_7
#define SS	 				PIN_4

void SPI_MasterInit();
uint8 SPI_MaterSendData(uint8 Data);
uint8 SPI_SlaveRecieveData(uint8 Data);
void SPI_SlaveInit();



#endif /* ATMEGA32_INC_SPI_H_ */
