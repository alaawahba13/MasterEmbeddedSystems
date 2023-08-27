/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
*/
#include "Platform_types.h"
#include <stdlib.h>

#define SYSCTL_base 0x400FE000
#define GPIO_base 0x40025000
#define SYSCTL_RCGC2_R (*(volatile unsigned long *) (SYSCTL_base  +0x108))
#define GPIO_PORTF_DIR_R (*(volatile unsigned long *) (GPIO_base  +0x400))
#define GPIO_PORTF_DEN_R (*(volatile unsigned long *) (GPIO_base  +0x51C))
#define GPIO_PORTF_DATA_R (*(volatile unsigned long *) (GPIO_base  +0x3FC))

void* _sbrk(int incr){
	static unsigned char* heap_ptr = NULL;
	unsigned char* prev_heap_ptr = NULL;
	extern unsigned int _E_bss;
	extern unsigned int _E_heap;
	
	if(heap_ptr == NULL)
		heap_ptr = (unsigned char*)&_E_bss;
	prev_heap_ptr = heap_ptr;
	
	if((heap_ptr + incr) > (unsigned char*)(& _E_heap))
		return (void*) (NULL);
	
	heap_ptr += incr;
	return (void*)prev_heap_ptr;
}



int main(void)
{
	SYSCTL_RCGC2_R = 0x20;
	int *p = (int*) malloc(4);
	volatile unsigned long delay = 0;
	for(delay=0;delay<200;delay++);
		GPIO_PORTF_DIR_R |= (1<<3) ;
	GPIO_PORTF_DEN_R |= (1<<3) ;
	while(1){
		GPIO_PORTF_DATA_R |=(1<<3);
		for( delay=0;delay<5000;delay++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for( delay=0;delay<5000;delay++);
	}
	return 0;
}
