/*
 * main.c
 *
 *  Created on: 27 Aug 2023
 *      Author: Alaa Wahba
 */

#include <stdio.h>
#include <stdlib.h>
#include "Linked_list.h"

int main() {
	Node_t *ListHead = NULL;
	int UserChoice = 0;
	int ListLength = 0;
	setbuf(stdout, NULL);

	while (1) {
		printf("\n");
		printf("===============================\n");
		printf("-> 1) Add Student \n");
		printf("-> 2) Delete Student \n");
		printf("-> 3) View All Students \n");
		printf("-> 4) Delete All \n");
		printf("-> 5) Quit from application \n");
		printf("===============================\n");

		printf("\n");
		printf("UserChoice : ");
		scanf("%i", &UserChoice);

		switch (UserChoice) {
		case 1:
			AddStudent();
			break;
		case 2:
			deleteStudentID();
			break;
		case 3:
			printAllNodes();
			break;
		case 4:
			deleteAllStudents();
			break;
		case 5:
			printf("Quit from application \n");
			exit(1);
			break;
		default:
			printf("User Choice out of range !!\n");
			break;
		}

	}
	return 0;
}
