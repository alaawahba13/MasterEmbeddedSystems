/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Version     :
 Copyright   : Your copyright notice
 Description : Home work 2 ex7
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num, factorial =1;
		    printf("Enter an integer: ");
		    fflush(stdout);
		    scanf("%d", &num);
		    if(num <0 )
		        printf("Erorr!! Factorial of a negative number doesn't exist.");
		   else if(num == 0)
		        printf("Factorial = 1");
		    else {
		        for(int i=1 ; i<= num ; i++ )
		        {
		             factorial = factorial *i;
		        }
		        printf("Factorial = %d", factorial);
		    }
	    return 0;
}
