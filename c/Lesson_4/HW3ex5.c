/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 3 ex5
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int n, search;
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);

	}
	printf("Enter the element to be searched : ");
	scanf("%d", &search);
	for(int i=0 ;i <n ;i++){
		if(arr[i] == search){
			printf("Number found at the location = %d", i+1);
		}
	}
	return 0;
}
