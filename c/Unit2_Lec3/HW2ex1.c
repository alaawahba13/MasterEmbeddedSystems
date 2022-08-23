#include <stdio.h>
#include <stdlib.h>

int main()
{   int num;
    printf("Enter integer you want to check : ");
    scanf("%d", &num);
    if(num %2 == 0 )
        printf("%d is even.", num);
    else
        printf("%d is odd.",num);
    return 0;
}
