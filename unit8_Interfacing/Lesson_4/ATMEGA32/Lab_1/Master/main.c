/*
 * main.c     MASTER
 *
 *  Created on: 18 Jan 2023
 *      Author: Alaa Wahba
 */

#include "SPI.h"
#include "DIO.h"
#include "util/delay.h"
int main(void) {
	uint8 ch =0;
	DIO_initPort(PORT_A, PORT_OUTPUT);
	SPI_MasterInit();
	for (ch = 0; ch <= 255; ch++) {
		_delay_ms(1000);
		DIO_WritePort(PORT_A, SPI_MaterSendData(ch));
	}

	
}
