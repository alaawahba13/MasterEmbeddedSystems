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

#define GPIO_BASE 0x40010800
#define RCC_BASE 0x40021000
#define GPIOA_CRH  *((volatile uint32 * ) (GPIO_BASE + 0x04))
#define GPIOA_ODR  *((volatile uint32 * ) (GPIO_BASE + 0x0C))
#define RCC_APB2 *(volatile uint32 * )(RCC_BASE +  0x18)
#define RCC_CFGR *(volatile uint32 * )(RCC_BASE +  0x04)
#define RCC_CR *(volatile uint32 * )(RCC_BASE +  0x00)

int main(void)
{
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	RCC_APB2 |= 1<<2 ;

	RCC_CFGR |=(0b0110 << 18);
	RCC_CFGR |=(0b10 << 0);
	RCC_CFGR |=(0b10 << 2);
	RCC_CFGR |= (0b101 << 11);
	RCC_CR |= ( 1 << 24);

	RCC_CFGR &= (1 << 16);





		RCC_CFGR |= (0b100 << 8);

  while (1)
  {
	  GPIOA_ODR |= 1<<13 ;
	  for (int i = 0; i < 5000; i++); // arbitrary delay
	  GPIOA_ODR &= ~(1<<13) ;
	  for (int i = 0; i < 5000; i++); // arbitrary delay
  }
}
