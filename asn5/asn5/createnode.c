/* CS2211a 2020 */
/* Assignment 05 */
/* ziqin shang */
/* 250890594 */
/* zshang3 */
/* NOV 25 2020 */
#include "Header.h"
#include <stdio.h>
#define MAX 15
// control list is just pointing at the first sentence object instead of a entire list of sentence???

void printsentencelist(control_list *list)
{
    if(NULL == list)
    {
       printf("The sentence linked list is empty!\n\n");
       return;
    }
    printf("sentence linked list items: \n");
    sentencenodes *tmpsentence = list->head;
    while(NULL != tmpsentence)
    {
        printwordlist(tmpsentence);
       tmpsentence = tmpsentence->next;
    }
}

void printwordlist(sentencenodes *sentence)
{
    if(NULL == sentence)
    {
       printf("The linked list is empty!\n\n");
       return;
    }
    printf("linked list items: ");
    //loop through list
    wordnodes *tmpnode = sentence->content;
    while(NULL != tmpnode)
    {
    //display each node
       printf("%s, ", tmpnode->content);
       //go to next node
       tmpnode = tmpnode->next;
    }
    printf("\n\n");
}

sentencenodes *createsentence(int position)
{
    sentencenodes *sentence = malloc(sizeof(sentence));
    sentence->position = position;
    return sentence;
}

void insertword(char *content,int charlen, int position, sentencenodes *sentence)
{
    //1.allocate node
    wordnodes *newnode;
    newnode =(wordnodes*)malloc(sizeof(content)+sizeof(int)+sizeof(int)+sizeof(sentence->content));
    wordnodes *lastnode = sentence->content;
    //2. put in the data
    newnode->content = content;
    newnode->position = position;
    newnode->totalnum = charlen;
    //3. this node is gonna be the last node, so let newnode->next = NULL
    newnode->next = NULL;
    //4. If the linked list is empty, then make the newnode as head
    if (sentence->content == NULL)
    {
       sentence->content = newnode;
       return;
    }
    //5.else, traverse till the last node
    while (lastnode->next != NULL)
           lastnode = lastnode->next;
    //6. change the next of last node
    lastnode->next = newnode;
}

control_list* createList(void)
{
    control_list * list;
    list= (control_list*) malloc (sizeof (list));
        if (list)
        {
            list->head = NULL;
            list->count = 0;
        }
    return list;
}

void insertList (control_list* list, sentencenodes* itemPtr)
{
//    sentencenodes* newPtr;
//    newPtr =(sentencenodes*)malloc(sizeof(sentencenodes));
//    newPtr = itemPtr;
//    newPtr->next = list->head;
//    (list->count)++;
//    list->head = newPtr;
//    return;
    
    sentencenodes* newPtr;
    newPtr =(sentencenodes*)malloc(sizeof(sentencenodes));
    sentencenodes *last = list->head;
    newPtr = itemPtr;
    newPtr->next = NULL;
    if(list->head == NULL){
        list->head = newPtr;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    (list->count)++;
    last->next = newPtr;
    return;

}

void searchword(char *word,sentencenodes *sentence)
{
    int wordposition;
    wordnodes *tmpnode = sentence->content;
    while(NULL != tmpnode)
    {
        if(strcmp(word,tmpnode->content) == 0)
        {
            wordposition = tmpnode->position;
            //plus one for both sentence position and word position for readability
            printf( "word found in line: %d and position : %d\n", sentence->position+1, wordposition+1 );
        }
       //go to next node
       tmpnode = tmpnode->next;
    }

}

void searchlist(control_list *list){
    while(1){
    //ask user to input a word for search
    printf("Enter a word to search\n");
    char buf[MAX];//initialize a user input array
    fgets(buf, MAX, stdin);//actual code for input
        //getting rid of newline character
    char *pos;
        //loop break point, when user entered \n
        if(*buf == '\n') break;
    if ((pos=strchr(buf, '\n')) != NULL)
        *pos = '\0';
        //put buffer into search_word
    char *search_word = buf;
        //search it
        sentencenodes *tmpsentence = list->head;
        while (tmpsentence != NULL)
        {
            searchword(search_word, tmpsentence);
            tmpsentence = tmpsentence->next;
        }
    }
}

void deletenode(control_list *list, int key){
    sentencenodes *tmpnode = list->head, *prev;
    if (tmpnode != NULL && tmpnode->position == key)
      {
          list->head = tmpnode->next;   // Changed head
          free(tmpnode);               // free old head
          return;
      }
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (tmpnode != NULL && tmpnode->position != key)
    {
        prev = tmpnode;
        tmpnode = tmpnode->next;
    }
  
    // If key was not present in linked list
    if (tmpnode == NULL) return;
  
    // Unlink the node from linked list
    prev->next = tmpnode->next;
    list->count--;
    free(tmpnode);  // Free memory
}
