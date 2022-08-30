#include <stdio.h>
#include <stdlib.h>

int main()
{   float a,b,c;
     printf("Enter three numbers : ");
     scanf("%f %f %f ", &a, &b,&c);
     if(a<b)  // assume a is the largest
        a =b;
    if( a< c)
        a=c;
     printf("The largest number %f", a );
    return 0;
}
