/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Version     :
 Copyright   : Your copyright notice
 Description : Homework ex5
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	      char c;
	    printf("Enter a character: ");
	    fflush(stdout);
	    scanf("%c", &c);
	    printf("ASCII value of %c = %d", c, c);
	    return 0;
}
