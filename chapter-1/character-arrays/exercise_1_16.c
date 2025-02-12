#include <stdio.h>

#define MAXLINE 1000    /* maximum input line length */


int getLine(char string[], int lim);
void copyString(char to[], char from[]);


int main() {
	int len;	// current line length
	int max;	// maximum length seen so far
	char line[MAXLINE];	// current input line
	char longest[MAXLINE];	// longest line saved here

	max = 0;
    while( (len = getLine(line, MAXLINE)) > 0) {
		if(len > max) {
			max = len;
			copyString(longest, line);	// store the longest line found
		}
	}

	if(max > 0) printf("Longest line (%d chars): %s", max, longest);

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


void copyString(char to[], char from[]) {
	/*	The function copies the contents of one string into another */

	int i = 0;	// use for copying characters

	// copies each character from `from` to `to` until it reaches the null-terminator
	while( (to[i] = from[i]) != '\0' ) ++i;
}
