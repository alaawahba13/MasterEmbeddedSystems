/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work Strings ex1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);
	int n, insert, location;
	int arr[30];
	printf("Enter no of elemets: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Enter the element to be inserted: ");
	scanf("%d", &insert);
	printf("Enter the location: ");
	scanf("%d", &location);
	for (int i = n; i >= location; i--) {
         arr[i] = arr[i-1];
	}
	n++;
	arr[location-1] = insert;
	for (int i = 0; i < n ; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
