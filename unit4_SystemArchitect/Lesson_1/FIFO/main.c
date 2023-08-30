/*
 * main.c
 *
 *  Created on: 27 Aug 2023
 *      Author: Alaa Wahba
 */

#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"


int main() {
	u8 head[5] ;
	u32 dequeue_value,Q_size=0;
	Queue_t my_queue;
	my_queue.MAX_SIZE = 5;
	my_queue.base = &head;
	ret_status ret = NOK;
	ret = Queue_init(&my_queue);

	if (ret == OK) {
		printf("Queue init Done\n");
		// push 5 values

		for (u32 i = 0; i < 7; i++) {
			Queue_enqueue(&my_queue, i);
		}

		// print values
			print_Queue(&my_queue);

		//pop two values
		for (u32 i = 0; i < 2; i++) {
			Queue_dequeue(&my_queue, &dequeue_value);
		}

		Queue_enqueue(&my_queue, 6);
		Queue_enqueue(&my_queue, 7);


		// print values
		   print_Queue(&my_queue);

	}

	return 0;
}
