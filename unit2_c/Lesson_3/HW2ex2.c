/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Version     :
 Copyright   : Your copyright notice
 Description : Home work 2 ex2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	 char c;
	    printf("Enter an alphabet: ");
	    fflush(stdout);
	    scanf("%c", &c);
	    if(c == 'i' || c== 'o' || c == 'e' || c == 'a'|| c== 'u' ||c == 'I' || c== 'O' || c == 'E' || c == 'A'|| c== 'U' )
	        printf("%c is a vowel",c);
	    else
	        printf("%c is a consonat",c);
	    return 0;
}
