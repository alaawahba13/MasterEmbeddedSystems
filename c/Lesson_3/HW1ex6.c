/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Version     :
 Copyright   : Your copyright notice
 Description : Home work1 ex6
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a,b, temp;
	    printf("Enter value of a ");
	    fflush(stdout);
	    scanf("%f", &a);
	     printf("Enter value of b ");
	     fflush(stdout);
	    scanf("%f", &b);
	    temp = b;
	    b =a;
	    a = temp;
	    printf("After swapping, value of a : %0.2f\n", a);
	      printf("After swapping, value of b : %0.2f\n", b);
	    return 0;
}
