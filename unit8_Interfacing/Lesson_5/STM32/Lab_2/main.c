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

#define MASTER_MODE
//#define SLAVE_MODE
uint16 pTxBuffer;

unsigned char ch;
void clock_init() {
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}
void SPI_IRQ_Callback(struct  IRQ_source_t irq_Src) {
#ifdef SLAVE_MODE
	if(irq_Src.RXNE){
		pTxBuffer =0xf;
		SPI_RXTX(SPI1, &pTxBuffer, Pollingdisable);
		USART_Send(USART1, &pTxBuffer, Enable);
	}
#endif


}


void UART_IRQ_Callback() {
#ifdef MASTER_MODE
	USART_Recieve(USART1, &pTxBuffer, Disable);
	USART_Send(USART1, &pTxBuffer, Enable);
	//Enable ss
	GPIO_WritePin(GPIOA, PIN_4,PIN_LOW );
	SPI_RXTX(SPI1, &pTxBuffer, Pollingenable);
	GPIO_WritePin(GPIOA, PIN_4, PIN_HIGH);
#endif
}

void wait_ms(uint32 time) {
	for (uint32 i = 0; i < time; i++)
		for (uint32 j = 0; j < 255; j++)
			;

}

int main(void) {
	clock_init();

	GPIO_PinConfig_t GPIO_pinConfig;
// UART_init
    	USART_pinConfig_t USART_pinConfig;
		USART_pinConfig.BaudRate = USART_BaudRate_115200;
		USART_pinConfig.Parity = USART_Parity_None;
		USART_pinConfig.DataLength = USART_DataLength8;
		USART_pinConfig.StopBits = USART_StopBits_1;
		USART_pinConfig.FlowControl = USART_FlowControl_NONE;
		USART_pinConfig.USART_Mode =USART_TXRXEN;
		USART_pinConfig.P_CallBack_Fun =UART_IRQ_Callback;
		USART_pinConfig.IRQ_Enable = USART_RXIEN;

	USART_init(&USART_pinConfig, USART1);
	USART_SetPins(USART1);
// SPI init
	SPI_PinConfig_t SPI_pinConfig;
	SPI_pinConfig.Commuincation_Mode = SPI_Direction_2Lines_RXTX;
	SPI_pinConfig.Data_Size = SPI_Data8;
	SPI_pinConfig.Frame_Format = SPI_Frame_MSB;
	SPI_pinConfig.BaudRate = SPI_BaudRate_8;
	SPI_pinConfig.CLK_Polarity = SPI_CLK_Polarity_1;
	SPI_pinConfig.CLK_Phase = SPI_CLK_Phase_2nd;

#ifdef MASTER_MODE
	SPI_pinConfig.SPI_Mode = SPI_Mode_Master;
	SPI_pinConfig.NSS =  SPI_NSS_Soft_NSSInternalSoft_set;
	SPI_pinConfig.IRQ_Enable = SPI_IRQ_EN_None;
	SPI_pinConfig.P_CallBackFun = NULL;


	// Configure SS pin
	GPIO_pinConfig.MODE = MODE_OUTPUT_PP;
	GPIO_pinConfig.Output_Speed = SPEED_10M;
	GPIO_pinConfig.Pin_Number = PIN_4;
	GPIO_init(GPIOA, &GPIO_pinConfig);
	// write high as idle case
	GPIO_WritePin(GPIOA, PIN_4, PIN_HIGH);
#endif

#ifdef SLAVE_MODE
	SPI_pinConfig.SPI_Mode = SPI_Mode_Slave;
	SPI_pinConfig.NSS = SPI_NSS_Hard_Slave;
	SPI_pinConfig.IRQ_Enable = SPI_IRQ_EN_RXNEIE;
	SPI_pinConfig.P_CallBackFun = SPI_IRQ_Callback;
#endif

	SPI_init(&SPI_pinConfig, SPI1);
	SPI_GPIO_SetPins(SPI1);

	while (1) {

	}

}

