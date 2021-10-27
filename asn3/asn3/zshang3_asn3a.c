/* CS2211a 2020 */
/* Assignment 03 */
/* ziqin shang*/
/*250890594*/
/* zshang3 */
/* OCT 19 2020 */

#include <stdio.h>
int main(){
    int array[] = { 12,63,44,89,3,55,73,27,37,18,1,2,3,4,5 };
    printf("size of array:");
    printf("%d ", sizeof(array));
    printf("\n");
    printf("length of array:");
    int size =sizeof(array)/sizeof(int);
    printf("%d ", size);
     printf("\n");
    //part 1
    printf("PART1\n");
    for(int i=0; i<size; i++)
    {
        printf("%d ",array[i]);
    }
    //part 2
    printf("\nPART2\n");
    for(int i=size-1; i>=0; i--)
    {
        printf("%d ",array[i]);
    }
    //part 3
    printf("\nPART3\n");
    int smallestvalue=100;
    int smallestindex;
    for (int i=0; i<size; i++) {
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
    for (int i=0; i<size; i++){
        printf("%d ",array[i]);
        totalvalue = totalvalue + array[i];
        if(i==size-1){
            printf("equals");
            printf("%d ", totalvalue);
            break;
        }
        printf("+");
    }
    //part 5
    printf("\nPART5\n");
    int array2[size];
    for (int i=0; i <size; i++){
        array2[size-1-i] = array[i];
    }
    printf("The original array:\n");
    for(int i=0; i<size; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\nnew(reversed) array\n");
    for(int i=0; i<size; i++)
    {
        printf("%d ",array2[i]);
    }
    //part 6
    printf("\nPART6\n");
    printf("The original array:\n");
    for(int i=0; i<size; i++)
    {
        printf("%d ",array[i]);
    }
    int buffer = array[0];
    array[0] = array[size-1];
    array [size-1] = buffer;
    printf("\nThe modified array:\n");
    for(int i=0; i<size; i++)
    {
        printf("%d ",array[i]);
    }
    //part 7
    printf("\nPART7\n");
    printf("The original array:\n");
    for(int i=0; i<size; i++)
    {
        printf("%d ",array[i]);
    }
    int i, j, temp;
    for (i = 0; i < size; ++i)
    {
    for (j = i + 1; j < size; ++j)
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
    for(int i=0; i<size; i++)
    {
        printf("%d ",array[i]);
    }
        return 0;
}

