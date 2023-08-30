#ifndef STACK_H
#define STACK_H


#include "Data_Structure.h"


typedef struct{
   u32 MAX_SIZE ;
   u8 *head; // stack pointer that is the array index
   u32 count;
}Stack;

ret_status LIFO_init(Stack *my_stack);
ret_status LIFO_push(Stack *my_stack, u32 data);
ret_status LIFO_pop(Stack *my_stack, u32 *data);
ret_status LIFO_top(Stack *my_stack, u32 *data);
void print_stack(Stack *my_stack);
u32 LIFO_getSize(Stack *my_stack);
ret_status Stack_isFull(Stack *my_stack);
ret_status Stack_isEmpty(Stack *my_stack);

#endif
