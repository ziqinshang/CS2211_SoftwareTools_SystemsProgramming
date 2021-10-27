//
//  main.c
//  CS2211asn2
//
//  Created by David Shang on 2020-10-18.
//  Copyright © 2020 David Shang. All rights reserved.
//

#include <stdio.h>
int main(){
    int array[] = { 12,63,44,89,3,55,73,27,37,18 };
    //part 1
    printf("PART1\n");
    for(int i=0; i<10; i++)
    {
        printf("%d ",array[i]);
    }
    //part 2
    printf("\nPART2\n");
    for(int i=9; i>=0; i--)
    {
        printf("%d ",array[i]);
    }
    //part 3
    printf("\nPART3\n");
    int smallestvalue=100;
    int smallestindex;
    for (int i=0; i<10; i++) {
        if(smallestvalue>array[i]){
            smallestvalue = array[i];
            smallestindex = i;
        }
    }
    printf("The smallest value stored in the array is:\nvalue:");
    printf("%d ",smallestvalue);
    printf("with the position of ");
    printf("%d ",smallestindex+1);
    //part 4
    printf("\nPART4\n");
    int totalvalue = 0;
    for (int i=0; i<10; i++){
        printf("%d ",array[i]);
        totalvalue = totalvalue + array[i];
        if(i==9){
            printf("equals");
            printf("%d ", totalvalue);
            break;
        }
        printf("+");
    }
    //part 5
    printf("\nPART5\n");
    int array2[10];
    for (int i=0; i <10; i++){
        array2[9-i] = array[i];
    }
    printf("The original array:\n");
    for(int i=0; i<10; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\nnew(reversed) array\n");
    for(int i=0; i<10; i++)
    {
        printf("%d ",array2[i]);
    }
    //part 6
    printf("\nPART6\n");
    printf("The original array:\n");
    for(int i=0; i<10; i++)
    {
        printf("%d ",array[i]);
    }
    int buffer = array[0];
    array[0] = array[9];
    array [9] = buffer;
    printf("\nThe modified array:\n");
    for(int i=0; i<10; i++)
    {
        printf("%d ",array[i]);
    }
    //part 7
    printf("\nPART7\n");
    printf("The original array:\n");
    for(int i=0; i<10; i++)
    {
        printf("%d ",array[i]);
    }
    int i, j, temp;
    for (i = 0; i < 10; ++i)
    {
    for (j = i + 1; j < 10; ++j)
    {
        if (array[i] > array[j])
        {
        temp =  array[i];
        array[i] = array[j];
        array[j] = temp;
        }
    }
    }
    printf("\nThe modified array:\n");
    for(int i=0; i<10; i++)
    {
        printf("%d ",array[i]);
    }
        return 0;
}
