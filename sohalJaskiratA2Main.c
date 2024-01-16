#include "sohalJaskiratA2.h"

int main(int argc, char *argv[]){

    int i;
    int numWords = 0;
    int numSentences = 0;
    int taskNum;
    int whichWord;
    int numWordsReturned;
    char *oldStringT2;
    char *newStringT2;
    char *desiredSuffix;
    char *newStringT4;
    char **data = NULL;

    char * fileContents = readFile(argv[1]);

    if(fileContents == NULL){

        printf("Error in reading the file.\n");

    }
    printf("File contents are : \n%s\n\n",fileContents);
    free(fileContents);

    do{
        printf("To test function 2, enter 2 : \n");
        printf("To test function 3, enter 3 : \n");
        printf("To test function 4, enter 4 : \n");
        printf("To test function 5, enter 5 : \n");
        printf("To test function 6, enter 6 : \n\n");
        printf("Enter a value : ");
        scanf("%d", &taskNum);
        printf("\n");

        switch(taskNum){

            case 2:

                fileContents = readFile(argv[1]);
                dejaVu (fileContents, &numWords, &numSentences);
                printf("Number of words are : %d\n", numWords);
                printf("Number of sentences are : %d\n\n", numSentences);
                numWords=0;
                numSentences=0;
                free(fileContents);
                break;

            case 3: 
            

                oldStringT2 = malloc(sizeof(char)* MAX_STR);
                newStringT2 = malloc(sizeof(char)* MAX_STR);
                printf("Enter a string : ");
                scanf("%s", oldStringT2);
                newStringT2 = goBig (oldStringT2);
                printf("New string is : %s\n\n",newStringT2);
                free(oldStringT2);
                free(newStringT2);

                break;

            case 4:  
                
                fileContents = readFile(argv[1]);
                data = goAway (fileContents, &numWordsReturned);
                printf("Number of words are : %d\n",numWordsReturned);
                printf("Data is : \n");
                for(i=0;i < numWordsReturned;i++){
                    printf("%s\n",data[i]);
                    free(data[i]);
                }
                free(data);
                free(fileContents);
                break;

            case 5:
    
                fileContents = readFile(argv[1]);
                newStringT4 = malloc(sizeof(char)* MAX_STR);
                newStringT4 = breathless(fileContents);
                printf("File contents after removing all punctuations are : \n");
                printf("%s\n\n", newStringT4);
                free(newStringT4);
                free(fileContents);
                break;

    
            case 6: 

                fileContents = readFile(argv[1]);
                desiredSuffix = malloc(sizeof(char) * MAX_STR);
                printf("Enter a number :");
                scanf("%d",&whichWord);
                printf("Enter the desired suffix : ");
                scanf("%s", desiredSuffix);
                printf("The new words are : \n");
                tail(fileContents,whichWord,desiredSuffix);
                free(desiredSuffix);
                free(fileContents);
                break;

        }

            
    }while(taskNum>=2 && taskNum<=6);


    return 0;

}
