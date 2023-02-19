/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Alaa Wahba
 * @brief          : STM32 MCAL Driver.
 ******************************************************************************
 ******************************************************************************
 */

#include "main.h"
#include "USART.h"

uint8 flag =0;
uint16  pTxBuffer ;
void clock_init() {
	RCC_GPIOA_CLK_EN();
    RCC_GPIOB_CLK_EN();
    RCC_AFIO_CLK_EN();
}

void UART_IRQ_Callback (struct  UART_IRQ_Event* flag)
{

	USART_Recieve(USART1, &pTxBuffer, Enable);

	USART_Send(USART1, &pTxBuffer, Enable);
}


void wait_ms(uint32 time) {
	for (uint32 i = 0; i < time; i++)
		for (uint32 j = 0; j < 255; j++);

}


int main(void) {
	clock_init();
	lcd_init();


	USART_pinConfig_t USART_pinConfig;
	USART_pinConfig.BaudRate = USART_BaudRate_115200;
	USART_pinConfig.Parity = USART_Parity_None;
	USART_pinConfig.DataLength = USART_DataLength8;
	USART_pinConfig.StopBits = USART_StopBits_1;
	USART_pinConfig.FlowControl = USART_FlowControl_NONE;
	USART_pinConfig.USART_Mode =USART_TXRXEN;
	//USART_pinConfig.P_CallBack_Fun =NULL;
		//USART_pinConfig.IRQ_Enable = USART_NONE;
	USART_pinConfig.P_CallBack_Fun =UART_IRQ_Callback;
	USART_pinConfig.IRQ_Enable = USART_RXIEN;

	USART_init(&USART_pinConfig, USART1);
	USART_SetPins(USART1);

	while (1) {

	//	USART_Recieve(USART1, &pTxBuffer, Enable);

		//		USART_Send(USART1, &pTxBuffer, Enable);
	}

}
