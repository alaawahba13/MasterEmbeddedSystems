/*
 ============================================================================
 Name        : Unit2.c
 Author      : Alaa Wahba
 Version     :
 Copyright   : Your copyright notice
 Description : Home work 3 ex1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
     float arr1[2][2],arr2[2][2], sum[2][2];
     printf("Enter the elements of the 1st matrix: \n");
     for(int i=0; i<2 ; i++){
    	 for(int j=0 ; j<2 ;j++){
    		 printf("Enter a%d%d : ", i+1,j+1);
    		 scanf("%f", &arr1[i][j]);

    	 }
     }
     printf("Enter the elements of the 2nd matrix: \n");
     for(int i=0; i<2 ; i++){
    	 for(int j=0 ; j<2 ;j++){
    		 printf("Enter b%d%d : ", i+1,j+1);
    		 scanf("%f", &arr2[i][j]);

    	 }
     }
     for(int i=0; i<2 ; i++)
        	 for(int j=0 ; j<2 ;j++)
        		 sum[i][j] = arr1[i][j] + arr2[i][j];

     printf("Sum of Matrix: \n");
     for(int i=0; i<2 ; i++){
            	 for(int j=0 ; j<2 ;j++){
                  printf("%0.1f  ", sum[i][j]);

     }
            	 printf("\n");
     }
	    return 0;
}
