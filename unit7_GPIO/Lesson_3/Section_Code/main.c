/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Alaa Wahba
 * @brief          : LCD & Keypad driver for STM32 MCU
 ******************************************************************************
 ******************************************************************************
 */

#include "main.h"

void clock_init() {
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}

void Main_GPIO_init() {
	uint32 PINS[7] = { PIN_9, PIN_10, PIN_11, PIN_12, PIN_13, PIN_14, PIN_15 };
	GPIO_PinConfig_t pinConfig;
	for (uint32 i; i < 7; i++) {
		pinConfig.MODE = MODE_OUTPUT_PP;
		pinConfig.Output_Speed = SPEED_10M;
		pinConfig.Pin_Number = PINS[i];
		GPIO_init(GPIOB, &pinConfig);
	}

}

int main(void) {
	clock_init();
	Main_GPIO_init();
	lcd_init();


	lcd_send_String("Hi ALAA");
	delay_ms(50);
	lcd_Clear_Screen();
	uint8 key = 'A';

	uint8 LCD_num[11] =
			{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	uint8 seg_num[11] = { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
	NINE, ZERO };

	for (uint32 i; i < 11; i++) {
		lcd_Send_Char(LCD_num[i]);
		GPIO_WritePort(GPIOB, seg_num[i] << 9);
		delay_ms(50);
	}
	Keypad_init();
	lcd_Clear_Screen();
	lcd_send_String("KEYPAD IS READY");
	delay_ms(50);
	lcd_Clear_Screen();

	while (1) {
		key = Keypad_Get_Key();
		switch (key) {
		case 'A':
			break;
		case '?':
			lcd_Clear_Screen();
			break;
		default:
			lcd_Send_Char(key);
			break;
		}
	}
}
