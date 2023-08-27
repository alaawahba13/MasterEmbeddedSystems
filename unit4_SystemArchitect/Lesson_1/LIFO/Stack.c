#include "Stack.h"

/** @brief intialize the stack pointer
 * @param  my_stack
 * @return value to indicate if it's intialized
 */

LIFO_status LIFO_init(Stack *my_stack) {
	LIFO_status ret;
	if (my_stack->head == NULL) {
		ret = NOK;
	} else {
		// stack counter indicates empty stack
		my_stack->count = -1;
		ret = OK;
	}
	return ret;

}
LIFO_status isEmpty(Stack *my_stack){
	if (my_stack->count ==  -1) {
			return EMPTY;
		} else {
			return N_EMPTY;
		}
}
LIFO_status isFull(Stack *my_stack) {
	if (my_stack->count == my_stack->MAX_SIZE - 1) {
		return FULL;
	} else {
		return N_FULL;
	}
}

LIFO_status LIFO_push(Stack *my_stack, u32 data) {
	LIFO_status ret = NOK;
	if (my_stack == NULL || isFull(my_stack) == FULL) {
		printf("Failed to push");
		ret = NOK;
	} else {
		*(my_stack->head) = data;
		my_stack->head++;
		my_stack->count++;
		ret = OK;

	}
	return ret;
}

LIFO_status LIFO_pop(Stack *my_stack, u32 *data) {
	LIFO_status ret = NOK;
	if (my_stack == NULL || isEmpty(my_stack) == EMPTY) {
		printf("Failed to pop");
		ret = NOK;
	} else {
		my_stack->head--;
		*data = *(my_stack->head);
		my_stack->count--;
		printf("Value popped is %i\n", *data);
		ret = OK;
	}
	return ret;
}
LIFO_status LIFO_top(Stack *my_stack, u32 *data) {
	LIFO_status ret = NOK;
	if (my_stack == NULL || isFull(my_stack) == EMPTY) {
		printf("No top found");
		ret = NOK;
	} else {
		my_stack->head--;
		*data = *(my_stack->head);
		my_stack->head++;

		printf("Top Value is %i\n", *data);
		ret = OK;
	}
	return ret;
}
void print_stack(Stack *my_stack) {
	if (my_stack == NULL || isFull(my_stack) == EMPTY) {
		printf("EMPTY STACK");
	} else {
		u8 *ptr;
		ptr= my_stack->head;
		printf("Stack values : ");
		for (u32 i = 0 ; i <= my_stack->count ; i++) {
			printf("%d ", *(--ptr));
		}

	}
}
u32 LIFO_getSize(Stack *my_stack) {
	u32 size = 0;
	if (my_stack == NULL) {
		printf("Error");
	} else {
		size = my_stack->count + 1;
	}
	return size;
}
