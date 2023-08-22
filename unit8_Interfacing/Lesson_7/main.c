/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Alaa Wahba
 * @brief          : SPI DRIVER.
 ******************************************************************************
 ******************************************************************************
 */

#include "main.h"
#include "USART.h"
#include "SPI.h"
#include "I2C.h"
#include "EEPROM.h"

void clock_init() {
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}

void wait_ms(uint32 time) {
	for (uint32 i = 0; i < time; i++)
		for (uint32 j = 0; j < 255; j++)
			;

}

int main(void) {
	clock_init();
	EEPROM_init();
//Test case 1
	uint8 ch1[] = { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7 };
	uint8 ch2[7] = { 0 };

	EEPROM_Write(ch1, 7, 0xAF);
	EEPROM_Read(ch2, 7, 0xAF);
	//Test case 2

	ch1[0] = 0xA;
	ch1[1] = 0xB;
	ch1[2] = 0xC;
	ch1[3] = 0xD;

	EEPROM_Write(ch1, 4, 0x0FFF);
	EEPROM_Read(ch2, 4, 0x0FFF);

	while (1) {

	}

}

