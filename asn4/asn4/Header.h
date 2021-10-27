/* CS2211a 2020 */
/* Assignment 04 */
/* ziqin shang */
/* 250890594 */
/* zshang3 */
/* NOV 14 2020 */
#ifndef Header_h
#define Header_h
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//function for user input, can be found in inputfunction.c
char *usrinput(){
    char *input;
    size_t bufsize = 100;
    size_t characters;
    input = (char *)malloc(bufsize * sizeof(char));
    printf("Enter a string: ");
    characters = getline(&input,&bufsize,stdin);
//    printf("%zu characters were read.\n",characters);
//    printf("You typed: '%s'\n",input);
    return input;
}
//structure for words
typedef struct words{
    char *start;
    int totalnum;
    int position;
} words;
//word create helper function
words createword(char *content,int charlen, int position)
{
    words word;
    word.start = content;
    word.totalnum = charlen;
    word.position = position;
    return word;
}
//print word helper function
void printword(words word){
    printf("%s",word.start);
}
//structure for sentences
typedef struct sentences{
    struct words *start;
    int numofwords;
    int position;
} sentences;
//sentence create helper function
sentences createsentence(words *allwords,int numofwords, int position)
{
    sentences sentence;
    sentence.start = allwords;
    sentence.numofwords=numofwords;
    sentence.position=position;
    return sentence;
}
//print sentence helper function
void printsentence(sentences sentence){
    for(int i=0;i<sentence.numofwords;i++){
        printword(*(sentence.start+i));
        printf(" ");
    }
}
//print every words helper function
void printsentenceV2(sentences sentence){
    for(int i=0;i<sentence.numofwords;i++){
        printword(*(sentence.start+i));
        printf("\n");
    }
}
//search word helper function
void searchword(char *word,sentences sentence){
    int wordposition;
    for(int i=0; i<sentence.numofwords;i++){
        //using strcmp() here, returns 0 if they are the same
        if(strcmp(word,(sentence.start+i)->start) == 0){
            //take the location of that word
            wordposition=(sentence.start+i)->position;
            //plus one for both sentence position and word position for readability
            printf( "word found in line: %d and position : %d\n", sentence.position+1, wordposition+1 );
        }
    }
}
//useless
char * createStr();
#endif /* Header_h */
