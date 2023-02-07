/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Alaa Wahba
 * @brief          : Controlling leds using STM32 bluepill board.
 ******************************************************************************
 ******************************************************************************
 */

#include "main.h"

uint8 flag =0;

void clock_init() {
	RCC_GPIOA_CLK_EN();
    RCC_GPIOB_CLK_EN();
    RCC_AFIO_CLK_EN();
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
		for (uint32 j = 0; j < 255; j++);

}

void EXTI9_CALLBACK(void){
	lcd_send_String("EXT9 IS TRIGGERED _|-");
	flag =0;
	wait_ms(1000);
}
int main(void) {
	clock_init();
     	GPIO_PinConfig_t GPIO_pinConfig;
     	GPIO_pinConfig.MODE = MODE_INPUT_FLO;
     	GPIO_pinConfig.Pin_Number = PIN_9;
		GPIO_init(GPIOB, &GPIO_pinConfig);
	lcd_init();
	lcd_Clear_Screen();

	EXTI_PinConfig_t EXTI_pinConfig;
	EXTI_pinConfig.pinMapping = EXTI9PB9;
	EXTI_pinConfig.triggerEdge = EXTI_Rising_edge;
	EXTI_pinConfig.IRQ_Enable = EXTI_IRQ_Enabled;
	EXTI_pinConfig.P_Fun = EXTI9_CALLBACK;
	EXTI_init(&EXTI_pinConfig);
	while (1) {
		if(flag ==0)
			{lcd_Clear_Screen();
		flag =1;
	}
	}
}
