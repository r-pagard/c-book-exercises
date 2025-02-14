#include <stdio.h>

#define MAXLINE 100 // maximum input line length


int getLine(char string[], int lim);
void reverseLine(char to[], char from[]);


int main() {
    int len;	// current line length
    char line[MAXLINE];	// current input line
    char result[MAXLINE];	// cleaned-up version of the input line

    while( (len = getLine(line, MAXLINE)) > 0) {
        reverseLine(result, line);
        printf("%s\n", result);   // only print non-empty lines
    }


    /*  Write a function reverse(s) that reverses the character string s. Use it to
        write a program that reverses its input a line at a time.
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

void reverseLine(char to[], char from[]) {
    int first = 0;  // points to the beginning of the string
    int end = 0;    // will be used to find the last character of the string

    while(from[end] != '\0') end++; // find the length of the string
    end--;  // move to the last actual character

    // check if there's a new line at the end, then ignore it while reversing
    int has_new_line = (from[end] == '\n') ? 1 : 0;
    if(has_new_line) end--;

    while(first < end) {
        char temp = from[first];    // store the first character of the string
        from[first] = from[end];    // replace the first character with the last character of the string
        from[end] = temp;   // put `temp` (previous first character) at the end of the string

        first++;
        end--;
    }

    int i = 0;
    while(from[i] != '\0') {    // copy the reversed string to `to`
        to[i] = from[i];
        i++;
    }

    // if there was a newline, add it at the end of the reversed string
    if(has_new_line) {
        to[i] = '\n';
        i++;
    }

    to[i] = '\0';   // null-terminate the string
}
