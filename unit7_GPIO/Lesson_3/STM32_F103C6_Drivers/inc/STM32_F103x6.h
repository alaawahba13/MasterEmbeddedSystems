/*
 * STM32_F103xx.h
 *
 *  Created on: Jan 15, 2023
 *      Author: Alaa Wahba
 */

#ifndef INC_STM32_F103X6_H_
#define INC_STM32_F103X6_H_

//-----------------------------
//Includes
#include <stdio.h>
#include <Platform_types.h>

//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_Memory_BASE													0x08000000
#define SYSTEM_Memory_BASE													0x1FFFF000
#define SRAM_BASE 															0x20000000
#define Periphrals_BASE 													0x40000000
#define CORTEX_M3_Internal_Periphrals_BASE 									0xE0000000
//-----------------------------
//Base addresses for ABP2 Peripherals
//-----------------------------
//GPIO

// A,B fully included in LQFP48 Package
#define GPIOA_BASE															0x40010800
#define GPIOB_BASE															0x40010C00
// C,D partially included in LQFP48 Package
#define GPIOC_BASE 															0x40011000
#define GPIOD_BASE 															0x40011400
// E not included in LQFP48 Package
#define GPIOE_BASE 															0x40011800
//EXTI
#define EXTI_BASE 															0x40010400
//AFIO
#define AFIO_BASE 															0x40010000

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
//RCC
#define RCC_BASE 														   0x40021000UL

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32 CRL;
	volatile uint32 CRH;
	volatile uint32 IDR;
	volatile uint32 ODR;
	volatile uint32 BSRR;
	volatile uint32 BRR;
	volatile uint32 LCKR;

}GPIO_Registers_t;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32 CR;
	volatile uint32 CFGR;
	volatile uint32 CIR;
	volatile uint32 APB2RSTR;
	volatile uint32 APB1RSTR;
	volatile uint32 AHBENR;
	volatile uint32 ABP2ENR;
	volatile uint32 ABP1ENR;
	volatile uint32 BDCR ;
	volatile uint32 CSR;
}RCC_Registers_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32 IMR;
	volatile uint32 EMR;
	volatile uint32 RTSR;
	volatile uint32 FTSR;
	volatile uint32 SWIER;
	volatile uint32 PR;

}EXTI_Registers_t;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:  AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32 EVCR;
	volatile uint32 MAPR;
	volatile uint32 EXTICR1;
	volatile uint32 EXTICR2;
	volatile uint32 EXTICR3;
	volatile uint32 EXTICR4;
	volatile uint32 Resverved;
	volatile uint32 MAPR2;
}AFIO_Registers_t;


//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA 				((GPIO_Registers_t * )(GPIOA_BASE))
#define GPIOB 				((GPIO_Registers_t * )(GPIOB_BASE))
#define GPIOC 				((GPIO_Registers_t * )(GPIOC_BASE))
#define GPIOD 				((GPIO_Registers_t * )(GPIOD_BASE))
#define GPIOE 				((GPIO_Registers_t * )(GPIOE_BASE))

#define RCC 				((RCC_Registers_t  * )RCC_BASE)

#define EXTI 				((EXTI_Registers_t * )(EXTI_BASE))

#define AFIO 				((AFIO_Registers_t * )(AFIO_BASE))
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()   (RCC->ABP2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN()   (RCC->ABP2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN()   (RCC->ABP2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN()   (RCC->ABP2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN()   (RCC->ABP2ENR |= (1<<6))

#define RCC_AFIO_CLK_EN   (RCC->ABP2ENR |= (1<<0))

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*



#endif /* INC_STM32_F103X6_H_ */
