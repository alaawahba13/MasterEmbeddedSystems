/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Version     :
 Copyright   : Your copyright notice
 Description : Home work 2 ex8
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char operatorr;
    float num1,num2, result =0;
    printf("Enter operator either + or - or * or divide: ");
    fflush(stdout);
    scanf("%c", &operatorr);
    printf("Enter two operands: ");
    fflush(stdout);
    scanf("%f %f", &num1, &num2);
    switch(operatorr){
    case '+':
        result = num1+num2;
        break;
    case '-':
        result = num1-num2;
        break;
    case '*':
        result = num1*num2;
        break;
    case '/':
        result = num1/num2;
        break;
    }
        printf("%f %c %f  = %f" , num1 , operatorr, num2 , result);
	    return 0;
}
