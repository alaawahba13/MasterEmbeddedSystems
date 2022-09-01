/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 5 ex1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct student
{
    char name[50];
    int roll;
    float marks;
} s;


int main(void) {
	    setbuf(stdout, NULL);
	    printf("Enter information of students:\n");
	    printf("Enter name: ");
	    scanf("%s", s.name);
	    printf("Enter roll number: ");
	    scanf("%d", &s.roll);
	    printf("Enter marks: ");
	    scanf("%f", &s.marks);
	    printf("Displaying Information:\n");
	    printf("Name: ");
	    puts(s.name);
	    printf("Roll number: %d\n",s.roll);

	    printf("Marks: %.1f\n", s.marks);
       	return 0;
}

