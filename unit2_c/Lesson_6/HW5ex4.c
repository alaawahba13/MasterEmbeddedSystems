/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 5 ex4
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
 struct student{
	 char name[30];
	  int roll;
	  float grade;
 };


int main()
{   setbuf(stdout, NULL);
   struct student students[2];
   printf("Enter information of students\n");
   for(int i=0 ; i<2 ; i++){
	   printf("For roll: ");
	   scanf("%d", &students[i].roll);
	   printf("Enter Name: ");
	   scanf("%s", &students[i].name);
	   	printf("Enter grade: ");
	    scanf("%f", &students[i].grade);
   }
   printf("Displaying information of students:\n");

   for(int i=0 ; i<2 ; i++){
  	   printf("Information for roll number %d\n ", students[i].roll );
  	   printf("Name: %s\n", students[i].name);
  	   	printf("grade: %f\n",students[i].grade);
     }

    return 0;
}


