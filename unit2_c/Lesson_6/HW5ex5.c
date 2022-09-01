/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 5 ex5
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14
#define area(r) r*r*PI
int main()
{   setbuf(stdout, NULL);
   int radius;
   printf("Enter radius: ");
   scanf("%d",  &radius);
   printf("The area = %0.2f", area(radius));
    return 0;
}


