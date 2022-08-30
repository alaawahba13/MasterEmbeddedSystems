/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 4 ex4
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  pow(int base, int power);
int main(void) {
	setbuf(stdout, NULL);
	int base,power;
     printf("Enter base number: ");
     scanf("%d", &base);
     printf("Enter power number (positive integer): ");
     scanf("%d", &power);
     printf("%d^%d = %d", base, power, pow(base,power));
   	return 0;
}

int  pow(int base, int power){
	  if(power == 0 )
		  return 1;
	return base* pow(base,power-1);
}


