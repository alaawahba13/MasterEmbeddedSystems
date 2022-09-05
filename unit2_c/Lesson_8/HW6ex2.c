/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 6 ex1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	setbuf(stdout, NULL);
	char alphabets[27];
	char *ptr = alphabets;
	for(int i =0 ; i<26 ; i++){
      alphabets[i] = 'A' + i;
	}
	for(int i =0 ; i< 26 ; i++)
  printf("%c ", *(ptr +i));
	return 0;
}

