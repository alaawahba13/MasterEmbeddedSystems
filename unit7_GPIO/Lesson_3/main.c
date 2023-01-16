/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Alaa Wahba
 * @brief          : Controlling leds using STM32 bluepill board.
 ******************************************************************************
 ******************************************************************************
 */

#include "STM32_F103x6.h"
#include "GPIO.h"
#include "BIT_MATH.h"


void clock_init() {
	RCC_GPIOA_CLK_EN();
RCC_GPIOB_CLK_EN();
}

void Main_GPIO_init() {
	GPIO_PinConfig_t pinConfig;
	pinConfig.MODE = MODE_INPUT_FLO;
	pinConfig.Pin_Number = PIN_1;
	GPIO_init(GPIOA, &pinConfig);

	pinConfig.MODE = MODE_INPUT_FLO;
	pinConfig.Pin_Number = PIN_13;
	GPIO_init(GPIOA, &pinConfig);

	pinConfig.MODE = MODE_OUTPUT_PP;
	pinConfig.Pin_Number = PIN_1;
	pinConfig.Output_Speed = SPEED_10M;
    GPIO_init(GPIOB, &pinConfig);

	pinConfig.MODE = MODE_OUTPUT_OD;
	pinConfig.Pin_Number = PIN_13;
	pinConfig.Output_Speed = SPEED_10M;
	 GPIO_init(GPIOB, &pinConfig);


}

void wait_ms(uint32 time) {
	for (uint32 i = 0; i < time; i++)
		for (uint32 j = 0; j < 255; j++)
			;

}
int main(void) {
	clock_init();
	Main_GPIO_init();
	while (1) {
		if (GPIO_ReadPin(GPIOA, PIN_1) ==0) {
			GPIO_TogglePin(GPIOB, PIN_1);
			while (GPIO_ReadPin(GPIOA, PIN_1) ==0);

		}
		if (GPIO_ReadPin(GPIOA, PIN_13) ==1) {
		GPIO_TogglePin(GPIOB, PIN_13);

		}
		wait_ms(10);
	}
}
