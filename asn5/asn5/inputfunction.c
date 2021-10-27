/* CS2211a 2020 */
/* Assignment 05 */
/* ziqin shang */
/* 250890594 */
/* zshang3 */
/* NOV 25 2020 */
#include "Header.h"
#include <stdio.h>

//function for user input, can be found in inputfunction.c
char *usrinput(void){
    char *input;
    size_t bufsize = 100;
    size_t characters;
    input = (char *)malloc(bufsize * sizeof(char));
    printf("Enter a string: ");
    characters = getline(&input,&bufsize,stdin);
    input[strlen(input)-1]=0;
    return input;
}
