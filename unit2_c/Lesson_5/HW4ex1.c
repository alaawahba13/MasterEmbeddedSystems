/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 4 ex1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

_Bool isPrime(int num );
int main(void) {
	int num1, num2;
	setbuf(stdout, NULL);
    printf("Enter two numbers : ");
    scanf("%d", &num1);
    scanf("%d", &num2);
    printf("Prime numbers between %d and %d are ", num1, num2);
    for(int i = num1 ; i<=num2 ;i++){
    		if(isPrime(i)){
    			printf("%d ", i );
    		}
    	}
   	return 0;
}

_Bool isPrime(int num ){
	  for(int i = 2 ; i<num ;i ++){
		  if(num % i ==0 )
			  return false;
	  }
	return true;
}
