/*
 * Linked_List.h
 *
 *  Created on: 30 Aug 2023
 *      Author:  Alaa Wahba
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Student_t{
	int ID;
	int Grade;
	char name[20];
}Student_t;


typedef struct Node_t {
	Student_t NodeData;
	struct Node_t *NodePtr;
}Node_t;


void AddStudent();
void getStudentData(Student_t *Student);
void deleteStudentID();
void deleteAllStudents();
void printAllNodes();

void getNthNode(int NodePosition);
void getNthNodeFromEnd(int NodePosition);
void getMiddle();
int getLength();




#endif /* LINKED_LIST_H_ */
