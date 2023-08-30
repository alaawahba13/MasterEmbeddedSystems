/*
 * Queue.h
 *
 *  Created on: 30 Aug 2023
 *      Author: Alaa Wahba
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Data_Structure.h"

typedef struct{
   u32 MAX_SIZE ;
   u32 count;
   u8 *base;
   u8 *head;
   u8 *tail;
}Queue_t;

ret_status Queue_init(Queue_t *my_Queue);
ret_status Queue_enqueue(Queue_t *my_Queue, u32 data);
ret_status Queue_dequeue(Queue_t *my_Queue, u32 *data);
void print_Queue(Queue_t *my_Queue);
u32 Queue_getSize(Queue_t *my_Queue);
ret_status Queue_isFull(Queue_t *my_Queue);
ret_status Queue_isEmpty(Queue_t *my_Queue);

#endif /* QUEUE_H_ */
