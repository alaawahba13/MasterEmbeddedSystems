/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 6 ex1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	setbuf(stdout, NULL);
	int m = 29;
	int *ptr = &m, *ab = NULL;
	printf("Address of m is 0x%p\nValue of m : %d\n\n", ptr, *ptr);
	ab = &m;
	printf("Address of pointer ab is 0x%p\nContent of pointer ab : %d\n\n", ab,
			*ab);
	m = 34;
	printf("Address of pointer ab is 0x%p\nContent of pointer ab : %d\n\n", ab,
			*ab);
	*ab = 7;
	printf("Address of m is 0x%p\nValue of m : %d\n\n", &m,m);
	return 0;
}

