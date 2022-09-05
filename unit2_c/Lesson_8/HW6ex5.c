/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 6 ex5
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct employee {
	char name[5];
	int ID;

};

int main() {
	setbuf(stdout, NULL);
	struct employee emp1 = { "Alex", 1005 };
	struct employee emp2 = { "Alaa", 2001 };
	struct employee *arr[2] = {&emp1 , &emp2};
	struct employee **ptr = arr;

	printf("Employee Name : %s\nEmployee ID : %d", (**ptr).name , (**ptr).ID);
	return 0;
}

