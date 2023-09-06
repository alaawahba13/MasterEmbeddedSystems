/*
 * main.c
 *
 *  Created on: 1 Sept 2023
 *      Author: Alaa Wahba
 */

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main() {
	int UserChoice = 0;
	element_type buff[50];
	setbuf(stdout, NULL);
	Queue_t my_Queue;
	my_Queue.MAX_SIZE = 50;
	my_Queue.base = buff;
	int ret = Queue_init(&my_Queue);
	if (ret == OK) {
		printf("Welcome to student Management System\n");

		while (1) {
			printf("\n");
			printf("===============================\n");
			printf("-> 1)  Add Student Details Manually \n");
			printf("-> 2)  Add Student Details From file \n");
			printf("-> 3)  Find a Student Details by ID \n");
			printf("-> 4)  Find a Student Details by First Name  \n");
			printf("-> 5)  Find Student Details by Course \n");
			printf("-> 6)  Find Total Number of Students\n");
			printf("-> 7)  Delete a student record\n");
			printf("-> 8)  Update a student record\n");
			printf("-> 9)  Show All Student Details\n");
			printf("-> 10) Quit from application \n");
			printf("===============================\n");
			printf("\n");
			printf("UserChoice : ");
			scanf("%i", &UserChoice);
			printf("\n");

			switch (UserChoice) {
			case 1:
				addStudentManually(&my_Queue);
				break;
			case 2:
				addStudentFile(&my_Queue);
				break;
			case 3:
				find_byID(&my_Queue);
				break;
			case 4:
				find_byName(&my_Queue);
				break;
			case 5:
				find_byCourse(&my_Queue);
				break;
			case 6:
				getTotalNumber(&my_Queue);
				break;
			case 7:
				DeleteStudent(&my_Queue);
				break;
			case 8:
				UpdateStudent(&my_Queue);
				break;
			case 9:
				printAll(&my_Queue);
				break;
			case 10:
				printf("Quit from application \n");
				exit(1);
				break;
			default:
				printf("User Choice out of range !!\n");
				break;
			}

		}
	}
	return 0;
}
