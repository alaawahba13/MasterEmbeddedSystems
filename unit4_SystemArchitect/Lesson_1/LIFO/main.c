/*
 * main.c
 *
 *  Created on: 27 Aug 2023
 *      Author: Alaa Wahba
 */

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Platform_types.h"

int main() {
	u8 head[5];
	u32 pop_value,stack_size=0,top_value;
	Stack my_stack = { 5, &head[0] };
	LIFO_status ret = NOK;
	ret = LIFO_init(&my_stack);

	if (ret == OK) {
		// push 5 values
		for (u32 i = 0; i < 5; i++) {
			LIFO_push(&my_stack, i);
			printf("Value pushed %d\n", i);
		}
		//pop two values
		for (u32 i = 0; i < 2; i++) {
			LIFO_pop(&my_stack,&pop_value );
		}
		 //print the top
		   LIFO_top(&my_stack, &top_value);

		//print the size
		   stack_size = LIFO_getSize(&my_stack);;
		   printf("The stack size is: %d\n",stack_size);

// print values
		print_stack(&my_stack);

	}

	return 0;
}
