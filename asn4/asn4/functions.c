/* CS2211a 2020 */
/* Assignment 04 */
/* ziqin shang */
/* 250890594 */
/* zshang3 */
/* NOV 14 2020 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 15
char * createStr() {
    printf("Enter a word to search\n");
    char buf[MAX];
    fgets(buf, MAX, stdin);
    char *pos;
    if ((pos=strchr(buf, '\n')) != NULL)
        *pos = '\0';
    char *search_word = buf;
    return search_word;
}
