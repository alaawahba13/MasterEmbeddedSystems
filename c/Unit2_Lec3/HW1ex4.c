#include <stdio.h>
#include <stdlib.h>

int main()
{   float num1, num2;
    printf("Enter two numbers: ");
    scanf("%f", &num1);
       scanf("%f", &num2);
    printf("Product: %0.6f",num1*num2 );
    return 0;
}
