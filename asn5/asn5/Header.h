/* CS2211a 2020 */
/* Assignment 05 */
/* ziqin shang */
/* 250890594 */
/* zshang3 */
/* NOV 25 2020 */


#ifndef Header_h
#define Header_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct words
{
    char *content;
    int totalnum;
    int position;
    struct wordnodes *next;
} wordnodes;

typedef struct sentences
{
    struct wordnodes *content;
    int numofwords;
    int position;
    struct sentences *next;
} sentencenodes;

typedef struct
{
    sentencenodes *head;
    int count;
} control_list;

char *usrinput(void);

control_list* createList(void);
void insertList (control_list* list, sentencenodes* itemPtr);
//bool insertList (control_list* list, sentencenodes* itemPtr);
//bool insertList (control_list* list, void* itemPtr);
//traverse the entire linked list and print elements
void printwordlist(sentencenodes *sentence);
//insert word to the end of linked list
void insertword(char *content,int charlen, int position, sentencenodes *sentence);

sentencenodes *createsentence(int position);

void printsentencelist(control_list *list);

void searchword(char *word,sentencenodes *sentence);

void searchlist(control_list *list);

void deletenode(control_list *list, int key);
#endif /* Header_h */
