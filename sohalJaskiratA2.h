#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 200
#define MAX_STR 40

/*
Function 1 : 
This function takes a filename of a text file as input, opens and reads the contents of the
file and returns the contents as a string (char *).
*/
char * readFile (char * filename);


/*
Function 2 : 
This function takes a string as input, and outputs the number of words and number of
sentences in it.
*/
void dejaVu (char * aString, int * numWords, int * numSentences);


/*
Function 3 :
This function takes a string as its only parameter. It prompts the user to enter exactly n
valid positive integers, where n is the length of aString. Entering a 0 or negative is
considered invalid. The function then creates a new string that consists of the letters in
aString (in the same order) – each letter repeated by the number of times indicated by
the user for that corresponding position.
*/
char * goBig (char * aString);

/*
Function 4 :
This function takes a string aString, splits it into n words, stores the words in a
dynamic 2D array and returns it. The function also outputs the total number of words
stored in the given input aString.
*/
char ** goAway (char * aString, int * numWordsReturned);

/*
Function 5 :
This function takes a string aString, finds all punctuations in the given string and
removes them from aString. The function returns the string with punctuation removed.
*/
char * breathless (char * aString);

/*
Function 6 :
This function takes a string as a parameter, finds the word given in position whichWord
and prints n number of words on the standard output, where n is the length of the word
at position whichWord. Each word printed on the screen starts with a letter in the word at
position whichWord and is suffixed by desiredSuffix.
*/
void tail (char * aString, int whichWord, char * desiredSuffix);
