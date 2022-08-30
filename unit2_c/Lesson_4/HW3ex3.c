/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 3 ex3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int rows, cols;
	printf("Enter rows and columns of matrix : ");
	scanf("%d%d", &rows, &cols);
	int arr[rows][cols];
	printf("Enter elements of the matrix: \n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("Enter a%d%d : ", i + 1, j + 1);
			scanf("%d", &arr[i][j]);
		}
	}
	printf("Entered Matrix : \n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("Transpose Matrix : \n");
		for (int i = 0; i < cols; i++) {
			for (int j = 0; j < rows; j++) {
				printf("%d ", arr[j][i]);
			}
			printf("\n");
		}
	return 0;
}
