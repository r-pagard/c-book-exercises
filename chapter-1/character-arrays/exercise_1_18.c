#include <stdio.h>

#define MAXLINE 100 // maximum input line length
#define IN 0	// inside a word
#define OUT 1	// outside a word


int getLine(char string[], int lim);
void proccessLine(char to[], char from[]);


int main() {
    int len;	// current line length
    char line[MAXLINE];	// current input line
    char result[MAXLINE];	// cleaned-up version of the input line

    while( (len = getLine(line, MAXLINE)) > 0) {
        proccessLine(result, line);
        if(result[0] != '\0') printf("%s\n", result);   // only print non-empty lines
    }


    /*  Write a program to remove trailing blanks and tabs from each line of input,
        and to delete entirely blank lines.
    */

    return 0;
}


int getLine(char string[], int lim) {
	/*	The functions, reads a line of input from the user and stores it in the `string` array,
	 *	up to a given limit which is provide by the function.
	 *
	 *	@param string[]: The array where the input line will be stores
	 *	@param lim: The maximum number of characters to read
	*/

    int character, length;

	// read characters one by one and stores them in the array
    for(length = 0; length < lim-1 && (character = getchar()) != EOF && character != '\n'; ++length) string[length] = character;
	// if the loop exits because of newline, it means a full line was read, then the `\n` character stores in the array
    if(character == '\n') {
        string[length] = character;
        ++length;
    }
    string[length] = '\0';	// making the string is a valid C string with null-terminated
    return length;	// return the length of the string
}

void proccessLine(char to[], char from[]) {
    int i = 0, j = 0;
    int state = OUT;

    int end = 0;    // index to track the last meaningful character in the line
    while(from[end] != '\0') end++; // find the string length
    end--;  // move back from `\0` to the last actual character in the string

    // move `end` backward to skip trailing spaces, tabs, or newlines
    while(end >= 0 && (from[end] == ' ' || from[end] == '\t' || from[end] == '\n') ) end--;

    while(i <= end)
    {
        // check if the character is space or tab
        if(from[i] == ' ' || from[i] == '\t') {
            if(state == OUT) {  // if we're outside a word(consecutive spaces)
                to[j++] = ' ';  // keep only one space
                state = IN; // mark that we've added a space and are now inside a word
            }
        } else {    // otherwise, if the character is NOT space or tab
            to[j++] = from[i];  // copy the character from `from` to `to`
            state = OUT;    // reset state since we've copied a non-space charcter
        }
        i++;
    }

    to[j] = '\0';   // null-terminate the cleaned-up string
}
