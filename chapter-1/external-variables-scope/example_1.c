#include <stdio.h>

#define MAXLINE 1000    // maximum input line size

// global variables (external variables)
int max;    // maximum length seen so far
char line[MAXLINE];  // current input line
char longest[MAXLINE];  // longest line saved here


int getLine(void);
void copyString(void);


int main() {
    int len;    // length of the current line
    extern int max; // tracks the maximum length encountered
    extern char longest[];  // the longest line

    max = 0;
    while( (len = getLine()) > 0 ) {
        if(len > max) {
            max = len;
            copyString();   // store the longest line found so far
        }
    }

    if(max > 0) printf("%s", longest);  // print the longest line if one exists

    return 0;
}


int getLine(void) {
    /*  Reads a line of input from the user and stores it in the `line` array.

        character: The current input character being processed.
        length: Counter for the number of characters read.
        line: The array that stores the current input line; it resets(null-terminated) on each call.
	*/

    int character, length;
    extern char line[];

    // read characters one by one and stores them in the array
    for(length = 0; length < MAXLINE - 1 && (character = getchar()) != EOF && character != '\n'; ++length) line[length] = character;

    // if a newline is encountered, store it in the array
    if(character == '\n') {
        line[length] = character;
        ++length;
    }
    line[length] = '\0';    // null-terminate the string
    return length;  // return the length of the string
}

void copyString(void) {
    /*  Copies the contents of `line` into `lingest`. 
        This function is used to store the longest line encountered so far.
    */

    int i = 0;  // index for copying characters
    extern char line[], longest[];  // `line` will be copied into `lingest`

    // copy each character from `line` to `longest` until the null terminator is reached
    while( (longest[i] = line[i]) != '\0' ) ++i;
}
