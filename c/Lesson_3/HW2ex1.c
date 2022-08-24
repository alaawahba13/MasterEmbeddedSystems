/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Version     :
 Copyright   : Your copyright notice
 Description : Home work 2 ex1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num;
	    printf("Enter integer you want to check : ");
	    fflush(stdout);
	    scanf("%d", &num);
	    if(num %2 == 0 )
	        printf("%d is even.", num);
	    else
	        printf("%d is odd.",num);
	    return 0;
}
