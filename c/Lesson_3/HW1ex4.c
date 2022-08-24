/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	  float num1, num2;
	    printf("Enter two numbers: ");
	    fflush(stdout);
	    scanf("%f", &num1);
	       scanf("%f", &num2);
	    printf("Product: %0.6f",num1*num2 );
	    return 0;
}
