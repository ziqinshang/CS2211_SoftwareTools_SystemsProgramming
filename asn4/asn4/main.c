/* CS2211a 2020 */
/* Assignment 04 */
/* ziqin shang */
/* 250890594 */
/* zshang3 */
/* NOV 14 2020 */
#include "Header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 15
int main() {
    //initalize the sentence array at the beginning of code
    //beacuse the memory of this structre will keep growing during the runtime
    sentences *sentence_array = NULL;
    //initalize a pointer-to-char array with a maximum size of 100
//    char *input;
//        size_t bufsize = 100;
//        size_t characters;
//        input = (char *)malloc(bufsize * sizeof(char));
//        printf("Enter a string: ");
//        characters = getline(&input,&bufsize,stdin);
//
    char *input;
    input = usrinput();
    //sentence index, showing how many sentences there is
    int sentenceindex=0;
    while (*(input)!= ' ') //if the user input is not a spacekey
    {
        if(sentenceindex != 0){ //if this is not the first time user inputted
            input = usrinput(); //re-prompt user to input a new line
        }
    char *p = input;
    //make sure to re-initalize *thisword to NULL
    //because if you dont you will end up putting the first sentence you entered
    //into the subsequent sentences
    words *thisword=NULL;
    char *tmpword;// a temporary char array to store upcoming word
    int wordindex=0; //word index, indicating the location of words in a sentence
    int word_size = 0; //word size, the totalsize allocated for the words in a sentence
        //using strtok() here, this is gonna skip all the space key entered
        //efficient and easy, this for loop will stop iterate when there is no more words left
        for (p = strtok (input, " "); p; p = strtok (NULL, " "))
        {
            tmpword = p;
            size_t length=strlen(tmpword);
//            printf( " %s", tmpword );
//            printf( " Size: %lu", length );
//            printf( " Location: %d\n", wordindex );
            word_size += sizeof(tmpword)+sizeof(int)+sizeof(int);//word size is size of char array plus two ints
            //allocating memory for the word array
            thisword = (words*) realloc(thisword, word_size);
            //createing word structure
            *(thisword+wordindex) = createword(tmpword, length, wordindex);
            wordindex++; // plus plus wordindex when we are done
        }
        //display the total memory allocated by words dynamic array
    printf("memory allocated for the words: '%d'\n",word_size);
    sentences onesentence; //initalize a temp sentence
    int sentencesize; //the memory required by a sentence structure
    sentencesize += word_size + sizeof(int) + sizeof(int); //self-explaintory
    onesentence=createsentence(thisword, wordindex, sentenceindex); //create sentence structure
    sentence_array = (sentences*) realloc(sentence_array, sentencesize);//allocating memory for the sentence array
    (*(sentence_array+sentenceindex))=onesentence;//store temp sentence into the sentence array
        //display the total memory allocated by sentences dynamic array
     printf("memory allocated in total: '%d'\n",sentencesize);
    //printsentence(*(sentence_array+sentenceindex));
    sentenceindex++;//plus plus sentenceindex when we are done
    }
    //print every words inputted
    for(int i = 0; i<sentenceindex;i++){
        printsentenceV2(*(sentence_array+i));
    }
    //print every sentences inputted
    for(int i = 0; i<sentenceindex;i++){
        printsentence(*(sentence_array+i));
    }
    //an infinite loop, sorry i am too tired for this at this point
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
        for(int i = 0; i<sentenceindex;i++)
        {
        searchword(search_word, *(sentence_array+i));
        }
    }
}
