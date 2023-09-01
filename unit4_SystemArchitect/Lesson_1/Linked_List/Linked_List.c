/*
 * Linked_List.c
 *
 *  Created on: 30 Aug 2023
 *      Author: Alaa Wahba
 */

#include "Linked_list.h"
struct Node_t *gpHead = NULL;

void AddStudent() {
	Node_t *temp = NULL;
	Node_t *LastNode = NULL;
	temp = (Node_t*) malloc(sizeof(Node_t));
	getStudentData(&temp->NodeData);
	temp->NodePtr = NULL;

	if (gpHead == NULL) { //list is empty

		gpHead = temp;
	} else {
		// list not empty
		LastNode = gpHead;
		while (LastNode->NodePtr != NULL) {
			LastNode = LastNode->NodePtr;
		}
		LastNode->NodePtr = temp;
	}

}
void getStudentData(Student_t *Student) {
	printf("Enter Student ID: ");
	scanf("%d", &Student->ID);
	printf("Enter Student Grade: ");
	scanf("%d", &Student->Grade);
	printf("Enter Student Name: ");
	fflush(stdin);
	gets(Student->name);
}
void deleteStudentID() {
	Node_t *StudentDelete = gpHead;
	Node_t *StudentBefore = NULL;
	int ID = 0;
	printf("Enter Student ID : ");
	scanf("%d", &ID);
	while (StudentDelete) {
		if (StudentDelete->NodeData.ID == ID) {
			if (!StudentBefore)
				gpHead = StudentDelete->NodePtr;
			else
				StudentBefore->NodePtr = StudentDelete->NodePtr;
			printf("Student Removed Succesfully\n");
			free(StudentDelete);
			return;
		}
		StudentBefore = StudentDelete;
		StudentDelete = StudentDelete->NodePtr;

	}
	printf("ID not found\n");

}

void deleteAllStudents() {
	Node_t *Current_Student = gpHead, *Remove_Student = gpHead;
	if (!Current_Student) {
		printf("List Is Already Empty !!\n");
		return;
	}
	gpHead = NULL;
	while (Current_Student) {
		Current_Student = Current_Student->NodePtr;
		free(Remove_Student);
		Remove_Student = Current_Student;
	}
	printf("List Deleted\n");
}
void printAllNodes() {
	Node_t *temp = gpHead;

	if (gpHead == NULL) {
		printf("List is empty");
	} else {
		while (temp) {
			printf("Student ID: %d \n", temp->NodeData.ID);
			printf("Student Name: %s \n", temp->NodeData.name);
			printf("Student Grade: %d \n", temp->NodeData.Grade);
			printf("==============================\n");
			temp = temp->NodePtr;
		}

	}

}

void getNthNode(int NodePosition) {
	Node_t *First = NULL;
	int listPosition = 0;

	if (NodePosition < getLength(gpHead)) {
		First = gpHead;
		while (listPosition < NodePosition) {
			listPosition++;
			First = First->NodePtr;
		}
		printf("Student info at postion %d\n", NodePosition);
		printf("Student ID: %d \n", First->NodeData.ID);
		printf("Student Name: %s \n", First->NodeData.name);
		printf("Student Grade: %d \n", First->NodeData.Grade);
		printf("==============================\n");

	} else {
		printf("Node position doesn't exist");
	}
}
void getNthNodeFromEnd(int index) {
	int length = getLength();
	getNthNode(length-index);
}
void getMiddle(){
	int length = getLength();
	int middle =0;
	if(length %2 != 0)
		middle = (length+1)/2;
	else{
		middle = (length /2) +1;
	}
	getNthNode(middle-1);

}
int getLength() {
	Node_t *temp = gpHead;
	int listLength = 0;
	while (temp != NULL) {
		listLength++;
		temp = temp->NodePtr;
	}
	return listLength;
}




