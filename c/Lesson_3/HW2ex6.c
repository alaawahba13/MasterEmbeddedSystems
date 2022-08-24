/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Version     :
 Copyright   : Your copyright notice
 Description : Home work 2 ex6
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	 int n, sum=0;
	    printf("Enter an integer: ");
	    fflush(stdout);
	    scanf("%d", &n);
	    for(int i=1 ; i<=n ; i++){
	        sum += i;
	    }
	     printf("sum = %d", sum);
	    return 0;
}
