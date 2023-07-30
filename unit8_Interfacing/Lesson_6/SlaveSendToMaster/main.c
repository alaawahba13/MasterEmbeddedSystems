/*
 * main.c
 *
 *  Created on: 18 Jan 2023
 *      Author: Alaa Wahba
 */


#include "Atmega32/inc/I2C.h"
#include "Atmega32/inc/DIO.h"

#define Slave_Address 			(uint8)(0b11010000)
int main(void){
#ifdef MASTER_Mode
	DIO_initPort(PORTA, PORT_OUTPUT);

	I2C_init(0x48);
#endif
#ifdef SLAVE_Mode
	uint8 Data = 0;
	I2C_setAddress(Slave_Address);
#endif

	while(1){
#ifdef MASTER_Mode
		_delay_ms(500);
		I2C_Start();
		I2C_Write(Slave_Address+1);  //SLA +W(0)
		PORTA= I2C_Read();
		I2C_Stop();
#endif
#ifdef SLAVE_Mode
		I2C_Read();
		I2C_Write(Data++);
#endif

	}


	return 0;
}


