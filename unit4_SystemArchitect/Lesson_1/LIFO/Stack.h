#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include "Platform_types.h"

#define true 1
#define false 0

typedef struct{
   u32 MAX_SIZE ;
   u8 *head; // stack pointer that is the array index
   u32 count;
}Stack;

typedef enum{
  NOK,
  OK,
  FULL,
  N_FULL,
  EMPTY,
  N_EMPTY
}LIFO_status;

LIFO_status LIFO_init(Stack *my_stack);
LIFO_status LIFO_push(Stack *my_stack, u32 data);
LIFO_status LIFO_pop(Stack *my_stack, u32 *data);
LIFO_status LIFO_top(Stack *my_stack, u32 *data);
void print_stack(Stack *my_stack);
u32 LIFO_getSize(Stack *my_stack);
LIFO_status isFull(Stack *my_stack);
LIFO_status isEmpty(Stack *my_stack);

#endif
