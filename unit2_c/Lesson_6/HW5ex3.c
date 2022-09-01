/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 5 ex3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
 struct complex
{
    float real;
    float imag;
}complex;

struct complex add(struct complex n1, struct complex n2);

int main()
{   setbuf(stdout, NULL);
    struct complex n1, n2, temp;
    printf("For 1st complex number \n");
    printf("Enter real and imaginary respectively:\n");
    scanf("%f %f", &n1.real, &n1.imag);
    printf("\nFor 2nd complex number \n");
    printf("Enter real and imaginary respectively:\n");
    scanf("%f %f", &n2.real, &n2.imag);
    temp = add(n1, n2);
    printf("Sum = %.1f + %.1fi", temp.real, temp.imag);

    return 0;
}

struct complex add(struct complex n1,struct complex n2)
{
	struct complex temp;

      temp.real = n1.real + n2.real;
      temp.imag = n1.imag + n2.imag;

      return(temp);
}
