/*
 * Queue.h
 *
 *  Created on: 30 Aug 2023
 *      Author: Alaa Wahba
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Data_Structure.h"
#define element_type  	Student_t

typedef struct{
	char First_Name[20];
	char Last_Name[20];
	int ID;
	float GPA;
	int course[10];
}Student_t;

typedef struct{
   u32 MAX_SIZE ;
   u32 count;
   element_type *base;
   element_type *head;
   element_type *tail;
}Queue_t;

ret_status Queue_init(Queue_t *my_Queue);
ret_status Queue_enqueue(Queue_t *my_Queue, element_type *data);
ret_status Queue_dequeue(Queue_t *my_Queue, element_type *data);
ret_status Queue_isFull(Queue_t *my_Queue);
ret_status Queue_isEmpty(Queue_t *my_Queue);

void addStudentFile(Queue_t *my_Queue);
void addStudentManually(Queue_t *my_Queue);
void find_byID(Queue_t *my_Queue);
void find_byName(Queue_t *my_Queue);
void find_byCourse(Queue_t *my_Queue);
void getTotalNumber(Queue_t *my_Queue);
void DeleteStudent(Queue_t *my_Queue);
void UpdateStudent(Queue_t *my_Queue);
void printAll(Queue_t *my_Queue);

ret_status checkID(Queue_t *my_Queue, int ID);

#endif /* QUEUE_H_ */
