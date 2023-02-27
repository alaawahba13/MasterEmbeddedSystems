/*
 * main.c     MASTER
 *
 *  Created on: 18 Jan 2023
 *      Author: Alaa Wahba
 */

#include "SPI.h"
#include "DIO.h"
#include "util/delay.h"

void execute(uint8 cmd, uint8 data){
	DIO_WritePin(SS, SPI_PORT, LOW);
	SPI_MaterSendData(cmd);
	SPI_MaterSendData(data);
	DIO_WritePin(SS, SPI_PORT, HIGH);
}

int main(void) {
	uint8 counter=0;
		SPI_MasterInit();
		execute(0x09,0xFF); //Decode mode B for digits 7-0
		execute(0x0A, 0x0F); // Max intensity
		execute(0x0C,0x01); // shut down > >Normal operation
		execute(0x0B, 0x07);	//Scans all digits
		while(1){

			for(uint8 i =1 ;i<9 ;i++){
				execute(i,counter++);
				_delay_ms(500);
			}
		}

}
