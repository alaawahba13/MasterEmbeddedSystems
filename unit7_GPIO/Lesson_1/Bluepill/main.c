/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Alaa Wahba
 * @brief          : Controlling leds using STM32 bluepill board.
 ******************************************************************************
 ******************************************************************************
 */

#include "Platform_types.h"
#include "BIT_MATH.h"

#define GPIOA_BASE 0x40010800
#define GPIOA_CRL 		*(volatile uint32 *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH 		*(volatile uint32 *)(GPIOA_BASE + 0x04)
#define GPIOA_IDR 		*(volatile uint32 *)(GPIOA_BASE + 0x08)

#define GPIOB_BASE 0x40010C00
#define GPIOB_CRL 		 *(volatile uint32 *)(GPIOB_BASE + 0x00)
#define GPIOB_CRH		 *(volatile uint32 *)(GPIOB_BASE + 0x04)
#define GPIOB_ODR 		 *(volatile uint32 *)(GPIOB_BASE + 0x0C)

#define RCC_BASE 0x40021000
#define RCC_ABP2   *(volatile uint32 *)(RCC_BASE + 0x18)

void clock_init(){
	SET_BIT(RCC_ABP2,2);
	SET_BIT(RCC_ABP2,3);
}

void GPIO_init(){
	GPIOA_CRL =0;
	GPIOA_CRH=0;
	GPIOB_CRL=0;
	GPIOB_CRH=0;
	//PortA pin 1 as floating input
	GPIOA_CRL &= ~(0b11 <<4);
	GPIOA_CRL |= (0b01<< 6);
	// portA pin 13 as floating input
	GPIOA_CRH &= ~(0b11 <<20);
	GPIOA_CRH |= (0b01<<22);
	//PortB pin 1 as output push pull
	GPIOB_CRL |= (0b01 <<4 );
	GPIOB_CRL &= ~(0b11 << 6);
	//PortB pin 13 as output push pull
	GPIOB_CRH |= (0b01 <<20 );
	GPIOB_CRH &= ~(0b11 << 22);

}
void wait_ms(uint32 time){
	for(uint32 i = 0 ; i <time ; i++)
		for(uint32 j =0 ; j <255 ; j++);

}
int main(void)
{
   clock_init();
   GPIO_init();

   while(1){
	   if(GET_BIT(GPIOA_IDR,1) ==0)
	   {
		   TOG_BIT(GPIOB_ODR,1);
		   while(GET_BIT(GPIOA_IDR,1) == 0);
	   }
	   if(GET_BIT(GPIOA_IDR,13) ==1)
	   {
	   		   TOG_BIT(GPIOB_ODR,13);

	   }
	   wait_ms(1);
   }
}
