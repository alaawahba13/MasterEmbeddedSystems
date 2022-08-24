/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Version     :
 Copyright   : Your copyright notice
 Description : Homework 1 ex3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num1, num2;
	    printf("Enter two intgers: ");
	    fflush(stdout);
	    scanf("%d", &num1);
	    scanf("%d", &num2);
	    printf("Sum: %d",num1+num2 );
	    return 0;
}
