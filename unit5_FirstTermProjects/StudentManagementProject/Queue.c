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
ret_status Queue_enqueue(Queue_t *my_Queue, element_type *data) {
	ret_status ret = NOK;
	if (my_Queue == NULL || Queue_isFull(my_Queue) == FULL) {
		ret = NOK;
	} else {
		*(my_Queue->head) = *data;
		my_Queue->count++;
		if (my_Queue->head
				== (my_Queue->base
						+ ((my_Queue->MAX_SIZE - 1) * sizeof(element_type))))
			my_Queue->head = my_Queue->base;
		else
			my_Queue->head++;

		ret = OK;

	}
	return ret;
}
ret_status Queue_dequeue(Queue_t *my_Queue, element_type *data) {
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
		ret = OK;
	}
	return ret;
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

void addStudentFile(Queue_t *my_Queue) {
	FILE *fptr;
	char ch[500];
	fptr = fopen("Names.txt", "r");
	if (fptr == NULL) {
		printf("The file dose not exist");
	} else {
		while (fgets(ch, 500, fptr) != NULL) {
			Student_t student;
			fscanf(fptr, "%s %s %d %f %d %d %d %d %d", student.First_Name,
					student.Last_Name, &student.ID, &student.GPA,
					&student.course[0], &student.course[1], &student.course[2],
					&student.course[3], &student.course[4]);

			ret_status retID = checkID(my_Queue, student.ID);
			if (retID == NOK) {
				printf("[ERROR] Student ID Already Taken\n");
			} else {
				ret_status ret = Queue_enqueue(my_Queue, &student);
				if (ret == NOK)
					printf("[ERROR] Unable to add Student\n");
				else
					printf("[INFO] Student added Successfully\n");
			}
		}
		fclose(fptr);
	}
}
void addStudentManually(Queue_t *my_Queue) {
	Student_t student;
	printf("Enter Student ID: ");
	scanf("%d", &(student.ID));
	printf("Enter Student GPA: ");
	scanf("%f", &student.GPA);
	printf("Enter Student First Name: ");
	fflush(stdin);
	gets(student.First_Name);
	printf("Enter Student Last Name: ");
	fflush(stdin);
	gets(student.Last_Name);
	printf("Enter The ID of each course: \n");

	for (int i = 0; i < 5; i++) {
		printf("Course %d ID : ", i + 1);
		scanf("%d", &student.course[i]);
	}
	ret_status retID = checkID(my_Queue, student.ID);
	if (retID == NOK) {
		printf("[ERROR] Student ID Already Taken\n");
		return;
	}

	ret_status ret = Queue_enqueue(my_Queue, &student);
	if (ret == NOK)
		printf("[ERROR] Unable to add Student\n");
	else
		printf("[INFO] Student added Successfully\n");

}

ret_status checkID(Queue_t *my_Queue, int ID) {
	ret_status ret = OK;
	Student_t *ptr;
	ptr = my_Queue->tail;

	for (u32 i = 0; i < my_Queue->count; i++) {
		if (ptr->ID == ID) {
			ret = NOK;
		}

		if (ptr
				== (my_Queue->base
						+ ((my_Queue->MAX_SIZE - 1) * sizeof(element_type))))
			ptr = my_Queue->base;
		else
			ptr++;
	}
	return ret;

}
void find_byID(Queue_t *my_Queue) {
	int ID = 0;
	printf("Enter Student ID : ");
	scanf("%d", &ID);

	Student_t *ptr;
	ptr = my_Queue->tail;

	for (u32 i = 0; i < my_Queue->count; i++) {
		if (ptr->ID == ID) {

			printf("Student Name is %s %s \n", ptr->First_Name, ptr->Last_Name);
			printf("Student ID is %d \n", ptr->ID);
			printf("Student GPA is %0.2f \n", ptr->GPA);
			for (int i = 0; i < 5; i++) {
				printf("The Course ID is %d \n", ptr->course[i]);
			}
			printf("===============================\n");
			return;
		}

		if (ptr
				== (my_Queue->base
						+ ((my_Queue->MAX_SIZE - 1) * sizeof(element_type))))
			ptr = my_Queue->base;
		else
			ptr++;
	}
	printf("ID Not Found\n");

}
void find_byName(Queue_t *my_Queue) {
	char name[20];
	printf("Enter Student First Name : ");
	fflush(stdin);
	gets(name);
	Student_t *ptr;
	ptr = my_Queue->tail;
	for (u32 i = 0; i < my_Queue->count; i++) {
		if (!strcasecmp(ptr->First_Name, name)) {
			printf("Student Full Name is %s %s \n", ptr->First_Name,
					ptr->Last_Name);
			printf("Student ID is %d \n", ptr->ID);
			printf("Student GPA is %0.2f \n", ptr->GPA);
			printf("The Course ID is %d \n", ptr->course[0]);
			printf("The Course ID is %d \n", ptr->course[1]);
			for (int i = 0; i < 5; i++) {
				printf("The Course ID is %d \n", ptr->course[i]);
			}
			printf("===============================\n");
			return;
		}

		if (ptr
				== (my_Queue->base
						+ ((my_Queue->MAX_SIZE - 1) * sizeof(element_type))))
			ptr = my_Queue->base;
		else
			ptr++;
	}
	printf("Name Not Found\n");

}
void find_byCourse(Queue_t *my_Queue) {
	int Course_ID = 0;
	printf("Enter Course ID : ");
	scanf("%d", &Course_ID);
	Student_t *ptr;
	ptr = my_Queue->tail;
	for (u32 i = 0; i < my_Queue->count; i++) {
		for (int j = 0; j < 5; j++) {
			if (ptr->course[j] == Course_ID) {
				printf("Student Name is %s %s \n", ptr->First_Name,
						ptr->Last_Name);
				printf("Student ID is %d \n", ptr->ID);
				printf("Student GPA is %0.2f \n", ptr->GPA);
				for (int i = 0; i < 5; i++) {
					printf("The Course ID is %d \n", ptr->course[i]);
				}
				printf("===============================\n");
				break;
			}

		}
		if (ptr
				== (my_Queue->base
						+ ((my_Queue->MAX_SIZE - 1) * sizeof(element_type))))
			ptr = my_Queue->base;
		else
			ptr++;

	}

}
void getTotalNumber(Queue_t *my_Queue) {
	printf("[INFO] Total Number of students is %d \n", my_Queue->count);
	printf("[INFO] You Can Add Up to 50 students \n");
	printf("[INFO] You Can Add Up to %d students more \n",
			50 - my_Queue->count);
}
void DeleteStudent(Queue_t *my_Queue) {
	int ID = 0, i = 0;
	printf("Enter Student ID : ");
	scanf("%d", &ID);

	Student_t *ptr;
	ptr = my_Queue->base;

	for (i = 0; i < my_Queue->count; i++) {
		if (ptr->ID == ID) {
			break;
		}
		ptr++;
	}
	if (i < my_Queue->count) {
		for (int j = 0; j < my_Queue->count; j++, i++) {
			my_Queue->base[i] = my_Queue->base[i + 1];
		}
		my_Queue->head--;
		my_Queue->count--;
	} else
		printf("ID Not Found\n");
}
void UpdateStudent(Queue_t *my_Queue) {
	int ID = 0, field;
	printf("Enter Student ID : ");
	scanf("%d", &ID);
	Student_t *ptr;
	ptr = my_Queue->tail;
	for (u32 i = 0; i < my_Queue->count; i++) {
		if (ptr->ID == ID) {
			printf(
					"Enter The field to update:\n1.Student Name\n2.GPA\n3.ID\n4.Course Number\n");
			scanf("%d", &field);
			switch (field) {
			case 1:
				printf("Enter Student First Name: ");
				fflush(stdin);
				gets(ptr->First_Name);
				printf("Enter Student Last Name: ");
				fflush(stdin);
				gets(ptr->Last_Name);
				break;
			case 2:
				printf("Enter Student GPA: ");
				scanf("%f", &ptr->GPA);
				break;
			case 3:
				printf("Enter Student ID: ");
				scanf("%d", &(ptr->ID));
				break;
			case 4:
				printf("Enter The ID of each course: \n");

				for (int i = 0; i < 5; i++) {
					printf("Course %d ID : ", i + 1);
					scanf("%d", &ptr->course[i]);
				}
				break;
			}
			return;
		}

		if (ptr
				== (my_Queue->base
						+ ((my_Queue->MAX_SIZE - 1) * sizeof(element_type))))
			ptr = my_Queue->base;
		else
			ptr++;
	}
	printf("ID Not Found\n");
}
void printAll(Queue_t *my_Queue) {
	if (my_Queue == NULL || Queue_isEmpty(my_Queue) == EMPTY) {
		printf("EMPTY QUEUE\n");
	} else {
		Student_t *ptr;
		ptr = my_Queue->tail;
		printf("===============================\n");
		printf("Students Info : \n\n");
		for (u32 i = 0; i < my_Queue->count; i++) {
			printf("Student Name is %s %s \n", ptr->First_Name, ptr->Last_Name);
			printf("Student ID is %d \n", ptr->ID);
			printf("Student GPA is %0.2f \n", ptr->GPA);
			for (int i = 0; i < 5; i++) {
				printf("The Course ID is %d \n", ptr->course[i]);
			}
			printf("===============================\n");

			if (ptr
					== (my_Queue->base
							+ ((my_Queue->MAX_SIZE - 1) * sizeof(element_type))))
				ptr = my_Queue->base;
			else
				ptr++;

		}
		printf("\n");

	}

}
