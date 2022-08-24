 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Version     :
 Copyright   : Your copyright notice
 Description : Home work 2 ex5
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	 char c;
	     printf("Enter a character: ");
	     fflush(stdout);
	     scanf("%c", &c);
	      if((c >= 'a' && c<= 'z') ||(c>= 'A' && c<= 'Z' ) )
	        printf("%c is an alphabet.", c);
	      else
	        printf("%c is not an alphabet.", c);
	    return 0;
}
