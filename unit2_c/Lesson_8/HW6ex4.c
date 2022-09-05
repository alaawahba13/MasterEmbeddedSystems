/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 6 ex4
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	setbuf(stdout, NULL);
	int arr[15];
	int n, *ptr = arr;
	printf("Input the number of elements to store in the array (max 15) : ");
	scanf("%d", &n);
	printf("Input 5 number of elements in the array :\n");
	for (int i = 0; i < n; i++) {
		printf("element - %d : ", i + 1);
		scanf("%d", ptr);
		ptr++;
	}
	ptr--;
	printf("The elements of array in reverse order are : \n");
	for (int i = 0; i < n; i++) {
		printf("element - %d : %d\n", i + 1, *ptr);
		ptr--;
	}
	return 0;
}

