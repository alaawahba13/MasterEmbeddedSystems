/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work Strings ex2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);
	char str[50];
	int count = 0;
	printf("Enter the string: ");
	gets(str);
	for (int i = 0; str[i] !='\0'; i++) {
			count++;
	}
	printf("Length of string = %d", count);
	return 0;
}
