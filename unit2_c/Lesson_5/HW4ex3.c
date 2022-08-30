/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 4 ex3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverseSentence() ;
int main(void) {
	setbuf(stdout, NULL);
	     printf("Enter a sentence: ");
	     reverseSentence();

}


void reverseSentence() {
    char c;
    scanf("%c", &c);
    if (c != '\n') {
        reverseSentence();
        printf("%c", c);
    }
}
