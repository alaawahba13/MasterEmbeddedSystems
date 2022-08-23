#include <stdio.h>
#include <stdlib.h>

int main()
{   char c;
    printf("Enter an alphabet: ");
    scanf("%c", &c);
    if(c == 'i' || c== 'o' || c == 'e' || c == 'a'|| c== 'u' ||c == 'I' || c== 'O' || c == 'E' || c == 'A'|| c== 'U' )
        printf("%c is a vowel",c);
    else
        printf("%d is a consonat",c);
    return 0;
}
