/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work Strings ex3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);
	char str[50], reverse[50];
	int len;
	printf("Enter the string: ");
	gets(str);
	len = strlen(str);
	for (int i = 0; i < len; i++) {
		reverse[i] = str[len - i-1];
	}
	printf("Reverse string is = %s", reverse);
	return 0;
}
