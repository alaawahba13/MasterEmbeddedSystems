/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Alaa Wahba
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "Platform_types.h"
#include <stdlib.h>
#include <stdio.h>
// GPIO
#define GPIO_BASE 0x40010800
#define GPIOA_CRH  *((volatile uint32 * ) (GPIO_BASE + 0x04))
#define GPIOA_ODR  *((volatile uint32 * ) (GPIO_BASE + 0x0C))
#define GPIOA_CRL  *((volatile uint32 * ) (GPIO_BASE + 0x00))
//RCC
#define RCC_BASE 0x40021000
#define RCC_APB2 *(volatile uint32 * )(RCC_BASE +  0x18)
#define RCC_CFGR *(volatile uint32 * )(RCC_BASE +  0x04)
#define RCC_CR *(volatile uint32 * )(RCC_BASE +  0x00)
//External interrupt
#define EXTI 0x40010400
#define EXTI_IMR *(volatile uint32 *)(EXTI + 0X00)
#define EXTI_RTSR *(volatile uint32 *)(EXTI + 0X08)
#define EXTI_PR *(volatile uint32 *)(EXTI + 0X14)
//AFIO
#define AFIO_BASE 0x40010000
#define AFIO_EXTICR1 *(volatile uint32 *)(AFIO_BASE + 0X08)
//NVIC
#define NVIC_ISE0 *(volatile uint32 *)(0xE000E100)

void clock_init(){
	RCC_APB2 |= 1<<2 ;
	RCC_APB2 |= 1<<0 ;

}
void GPIO_init(){
	GPIOA_CRH &= 0xFF0FFFFF;
		GPIOA_CRH |= 0x00200000;
		GPIOA_CRL |= (1<<2);
}

void EXTI0_IRQHandler(){

		  GPIOA_ODR ^= 1<<13 ;
		  // clear pending register
		  EXTI_PR |= (1<<0);


}
int main(void)
{
	clock_init();
	 GPIO_init();
	AFIO_EXTICR1 = 0;
	//MASK register
	EXTI_IMR |= (1<<0);
	// enable rising edge register
	EXTI_RTSR |= (1<<0);
	//Set bit 6 to one
	NVIC_ISE0 |= (1<<6);
	while(1);


}
