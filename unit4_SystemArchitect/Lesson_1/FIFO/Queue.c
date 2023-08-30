/*
 * Queue.c
 *
 *  Created on: 30 Aug 2023
 *      Author: Alaa Wahba
 */
#include "Queue.h"
ret_status Queue_init(Queue_t *my_Queue) {
	ret_status ret;
	if (my_Queue->base == NULL) { //pointer to array base
		ret = NOK;
	} else {
		my_Queue->count = 0;
		my_Queue->tail = my_Queue->base;
		my_Queue->head = my_Queue->base;
		ret = OK;
	}
	return ret;
}
ret_status Queue_enqueue(Queue_t *my_Queue, u32 data) {
	ret_status ret = NOK;
	if (my_Queue == NULL || Queue_isFull(my_Queue) == FULL) {
		printf("Failed to enqueue\n");
		ret = NOK;
	} else {
		*(my_Queue->head) = data;
		my_Queue->count++;
		printf("Value enqueued %d\n", data);
		if (my_Queue->head
				== (my_Queue->base + ((my_Queue->MAX_SIZE - 1) * sizeof(u8))))
			my_Queue->head = my_Queue->base;
		else
			my_Queue->head++;

		ret = OK;

	}
	return ret;
}
ret_status Queue_dequeue(Queue_t *my_Queue, u32 *data) {
	ret_status ret = NOK;
	if (my_Queue == NULL || Queue_isEmpty(my_Queue) == EMPTY) {
		printf("Failed to dequeue\n");
		ret = NOK;
	} else {
		*data = *(my_Queue->tail);
		if (my_Queue->tail
				== (my_Queue->base + ((my_Queue->MAX_SIZE - 1) * sizeof(u8))))
			my_Queue->tail = my_Queue->base;
		else
			my_Queue->tail++;

		my_Queue->count--;
		printf("Value dequeued is %i\n", *data);
		ret = OK;
	}
	return ret;
}
void print_Queue(Queue_t *my_Queue) {
	if (my_Queue == NULL || Queue_isEmpty(my_Queue) == EMPTY) {
		printf("EMPTY QUEUE\n");
	} else {
		u8 *ptr;
		ptr = my_Queue->tail;
		printf("Queue values : ");
		for (u32 i = 0; i < my_Queue->count; i++) {
			printf("%d ", *(ptr));
			if (ptr== (my_Queue->base + ((my_Queue->MAX_SIZE - 1) * sizeof(u8))))
				ptr = my_Queue->base;
			else
				ptr++;

		}
		printf("\n");

	}
}
u32 Queue_getSize(Queue_t *my_Queue) {
	u32 size = 0;
	if (my_Queue == NULL) {
		printf("Error\n");
	} else {
		size = my_Queue->count;
	}
	return size;
}
ret_status Queue_isFull(Queue_t *my_Queue) {
	if (my_Queue->count == my_Queue->MAX_SIZE) {
		return FULL;
	} else {
		return N_FULL;
	}
}
ret_status Queue_isEmpty(Queue_t *my_Queue) {
	if (my_Queue->count == 0) {
		return EMPTY;
	} else {
		return N_EMPTY;
	}
}
