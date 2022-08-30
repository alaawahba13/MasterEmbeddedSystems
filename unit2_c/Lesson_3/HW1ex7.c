/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Version     :
 Copyright   : Your copyright notice
 Description : Home work 1 ex7
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a,b ;
	    printf("Enter value of a ");
	    fflush(stdout);
	    scanf("%f", &a);
	     printf("Enter value of b ");
	     fflush(stdout);
	    scanf("%f", &b);
	    b=a+b;
	    a = b-a;
	    b= b-a;
	    printf("After swapping, value of a : %0.2f\n", a);
	      printf("After swapping, value of b : %0.2f\n", b);
	    return 0;
}
