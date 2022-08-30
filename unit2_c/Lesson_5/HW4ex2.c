/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 4 ex2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int factorial(int num);
int main(void) {
	int num;
	setbuf(stdout, NULL);
    printf("Enter a positive integer : ");
    scanf("%d", &num);

    printf("factorial of %d = %d", num, factorial(num));

   	return 0;
}

int factorial(int num){
	  if(num==1 || num==0){
		  return 1;
	  }
	return (num *factorial(num-1));

}

