/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 3 ex2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int n;
	float sum = 0;
	printf("Enter the number of data: ");
	scanf("%d", &n);
	float arr[n];
	for (int i = 0; i <n; i++) {
		printf("%d. Enter number : ", i+1);
		scanf("%f", &arr[i]);
	}
	for(int i=0; i<n ;i++){
		sum += arr[i];
	}
     printf("Average = %0.2f", sum/n);
	return 0;
}
