/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 6 ex3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	setbuf(stdout, NULL);
	char input[30];
	printf("Pointer : Print a string in reverse order : \n------------------------------------------------\n");
	printf("Input a string :");
	gets(input);
	char *ptr = &input[strlen(input) -1 ];
	printf("Reverse of the string is : ");
	for(int i =0 ; i <strlen(input) ; i++){
		printf("%c", *ptr);
		ptr--;
	}


	return 0;
}

