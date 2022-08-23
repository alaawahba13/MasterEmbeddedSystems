#include <stdio.h>
#include <stdlib.h>

int main()
{
    char operatorr;
    float num1,num2, result =0;
    printf("Enter operator either + or - or * or divide: ");
    scanf("%c", &operatorr);
    printf("Enter two operands: ");
    scanf("%f %f", &num1, &num2);
    if(operatorr == '+')
        result = num1+num2;
    else if(operatorr == '-')
        result = num1-num2;
    else if(operatorr == '*')
        result = num1*num2;
    else if(operatorr == '/')
        result = num1/num2;
        printf("%f %c %f  = %f" , num1 , operatorr, num2 , result);
    return 0;
}
