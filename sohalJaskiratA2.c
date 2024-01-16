#include "sohalJaskiratA2.h"

/*
Function 1 : 
This function takes a filename of a text file as input, opens and reads the contents of the
file and returns the contents as a string (char *).
*/
char * readFile (char * filename){

    int fileSize;
    FILE * fptr = fopen(filename,"r");
    
    if (fptr == NULL) {
        return NULL;
    }

    fseek(fptr, 0, SEEK_END);//Using fseek to reach end of the file.
    fileSize = ftell(fptr);//Using ftell to get the size of file.
    rewind(fptr);//Using rewind to get the file pointer back to the top of the file.
    char * fileContents = malloc(fileSize +1);//Allocating memory to store contents of file
    fread(fileContents, sizeof(char), fileSize, fptr);//Read the contents of the file.
    fclose(fptr);//Closed file
    fileContents[fileSize] = '\0';
    return fileContents;
  
}



/*
Function 2 : 
This function takes a string as input, and outputs the number of words and number of
sentences in it.
*/
void dejaVu (char * aString, int * numWords, int * numSentences){

    int i;
    int extraSpace = 0;
    int extraSentence = 0;

    for (i = 0; i < strlen(aString); i++) {

        if (aString[i] == ' '|| aString[i]=='\n') {
            if (!extraSpace) {//If one space was counted, extraSpace will be set to 1.
                (*numWords)++;
                extraSpace = 1;//This will prevent next space to be counted as another word.
            }
        }
        else if (aString[i] == '.'||aString[i] == '?'||aString[i] == '!'||aString[i] == ';' || aString[i] == ':') {//Since colon, and semicolon are not used m
            if(!extraSentence){//This will prevent counting any symbol twice.

                (*numSentences)++;
                extraSentence=1;
            }
            extraSpace = 0;
        }
        else {
            extraSpace = 0;
            extraSentence=0;
        }
    }
    if (aString[strlen(aString) - 1] != ' ') {//Checking if last character is space.
        (*numWords)++;
    }
}





/*
Function 3 :
This function takes a string as its only parameter. It prompts the user to enter exactly n
valid positive integers, where n is the length of aString. Entering a 0 or negative is
considered invalid. The function then creates a new string that consists of the letters in
aString (in the same order) – each letter repeated by the number of times indicated by
the user for that corresponding position.
*/
char * goBig (char * aString){

    
    int i,j;
    int k=0;
    int len=strlen(aString);
    int count[len];
    char *stringReturn;
    char arr[len][5];

    stringReturn = malloc(sizeof(char) * MAX_STR);
    printf("Enter exactly n, valid positive integers, separated by spaces, where n is the length of aString : ");
    for(i=0;i<strlen(aString);i++){
        scanf("%d",&count[i]);//stored numbers in array.
    }
    for(i=0;i<strlen(aString);i++){
        for(j=0;j<count[i];j++){
            arr[i][j] = aString[i];//Using 2d array to make desired changes.
            stringReturn[k++] = arr[i][j];
        }
    }

    return stringReturn;

}



/*
Function 4 :
This function takes a string aString, splits it into n words, stores the words in a
dynamic 2D array and returns it. The function also outputs the total number of words
stored in the given input aString.
*/
char ** goAway (char * aString, int * numWordsReturned){

    int wordCount = 0;
    char **data = NULL;//declared a 2d array
    char *wordSplit = strtok(aString, " ");//using strtok to tokenize the words of file.
    while(wordSplit != NULL){

        wordCount++;//counts number of words
        data = realloc(data, wordCount * sizeof(char *));
        data[wordCount -1]= malloc((strlen(wordSplit) +1) * sizeof(char));//dynamically allocating the memory
        strcpy(data[wordCount-1],wordSplit);
        wordSplit = strtok(NULL, " ");

    }

    * numWordsReturned = wordCount;
    return data;

}





/*
Function 5 :
This function takes a string aString, finds all punctuations in the given string and
removes them from aString. The function returns the string with punctuation removed.
*/

char * breathless (char * aString){

    int i;
    int j=0;
    int len = strlen(aString);
    char *stringReturn;
    stringReturn = malloc(sizeof(char) * len);
    
    for(i=0;i<len;i++){

        if(aString[i] == '.' || aString[i] == '?' || aString[i] == '!'|| aString[i] == ';' || aString[i] == ':'){
            continue;//If we get punctuations we will continue.
        }
        else{
            stringReturn[j++]= aString[i];//All words except punctuations will get stored in stringReturn.
        }
    }
    stringReturn[j]= '\0';
    return stringReturn;

}



/*
Function 6 :
This function takes a string as a parameter, finds the word given in position whichWord
and prints n number of words on the standard output, where n is the length of the word
at position whichWord. Each word printed on the screen starts with a letter in the word at
position whichWord and is suffixed by desiredSuffix.
*/
void tail (char * aString, int whichWord, char * desiredSuffix){

    int i = 0;
    int count = 0;
    int wordLength = 0;
    int len = strlen(aString);
    

    
    while (count < whichWord - 1 && i < len) {
        if (aString[i] == ' ') {// We need to count the words until we reach the desired word.
            count++;
        }
        i++;
    }

    if (i >= len) {//If end of string , return
        return;
    }

    while (aString[i + wordLength] != ' ' && i + wordLength < len) {
        wordLength++;// We need to find the length of the word we want to tail
    }

    for (int j = 0; j < wordLength; j++) {//print each word with desired suffix
        putchar(aString[i+j]);
        printf("%s\n", desiredSuffix);
    }
}
