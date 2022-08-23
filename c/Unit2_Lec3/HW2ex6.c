#include <stdio.h>
#include <stdlib.h>

int main()
{   int n, sum=0;
    printf("Enter an integer: ");
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++){
        sum += i;
    }
     printf("sum = %d", sum);
    return 0;
}
