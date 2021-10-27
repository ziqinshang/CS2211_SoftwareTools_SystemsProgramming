/* CS2211a 2020 */
/* Assignment 05 */
/* ziqin shang */
/* 250890594 */
/* zshang3 */
/* NOV 25 2020 */
#include "Header.h"
#define MAX 15
int main()
{
    char *input;
    input = usrinput();
    int sentenceindex = 0;
    control_list *list;
    list = createList();
    while (*(input)!= ' ') //if the user input is not a spacekey
    {
        if(sentenceindex != 0)
        { //if this is not the first time user inputted
            input = usrinput(); //re-prompt user to input a new line
        }
    
    sentencenodes *tmpsentence = createsentence(sentenceindex);
    char *p = input;
    char *tmpword;// a temporary char array to store upcoming word
    int wordindex=0; //word index, indicating the location of words in a sentence
    int word_size = 0; //word size, the totalsize allocated for the words in a sentence
        for (p = strtok (input, " "); p; p = strtok (NULL, " "))
        {
            tmpword = p;
            size_t length=strlen(tmpword);
            insertword(tmpword, length, wordindex, tmpsentence);
            wordindex++; // plus plus wordindex when we are done
        }
    tmpsentence->numofwords = wordindex;
    printwordlist(tmpsentence);
    insertList(list, tmpsentence);
    sentenceindex++;
    //printsentencelist(list);
    }
    printsentencelist(list);
    searchlist(list);
    int tmpindex;
    printf("Enter a sentence index to delete\n");
    scanf("%d", &tmpindex);
    deletenode(list, tmpindex);
    printsentencelist(list);
    free(input);
    free(list);
//    while(1){
//    //ask user to input a word for search
//    printf("Enter a word to search\n");
//    char buf[MAX];//initialize a user input array
//    fgets(buf, MAX, stdin);//actual code for input
//        //getting rid of newline character
//    char *pos;
//        //loop break point, when user entered \n
//        if(*buf == '\n') break;
//    if ((pos=strchr(buf, '\n')) != NULL)
//        *pos = '\0';
//        //put buffer into search_word
//    char *search_word = buf;
//        //search it
//        sentencenodes *tmpsentence = list->head;
//        while (tmpsentence != NULL)
//        {
//            searchword(search_word, tmpsentence);
//            tmpsentence = tmpsentence->next;
//        }
//    }
}
