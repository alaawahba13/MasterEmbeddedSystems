/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Description : Home work 5 ex5
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct Distance
{
    int feet;
    float inch;
} d1, d2, sumOfDistances;


int main()
{   setbuf(stdout, NULL);
printf("Enter information for 1st distance\n");
    printf("Enter feet: ");
    scanf("%d", &d1.feet);
    printf("Enter inch: ");
    scanf("%f", &d1.inch);
    printf("\nEnter information for 2nd distance\n");
    printf("Enter feet: ");
    scanf("%d", &d2.feet);
    printf("Enter inch: ");
    scanf("%f", &d2.inch);
    sumOfDistances.feet = d1.feet+d2.feet;
    sumOfDistances.inch = d1.inch+d2.inch;
    if (sumOfDistances.inch>12.0)
    {
        sumOfDistances.inch = sumOfDistances.inch-12.0;
        ++sumOfDistances.feet;
    }

    printf("\nSum of distances = %d\'-%.1f\"",sumOfDistances.feet, sumOfDistances.inch);
    return 0;
}


