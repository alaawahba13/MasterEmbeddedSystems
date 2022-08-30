/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work Strings ex1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);
	char str[50], c= ' ';
	int count = 0;
	printf("Enter a string: ");
	gets(str);
	printf("Enter a character to find the frequency: ");
	scanf("%c", &c);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == c)
			count++;
	}
	printf("Frequency of %c = %d", c, count);
	return 0;
}
