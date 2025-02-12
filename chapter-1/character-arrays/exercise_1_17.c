#include <stdio.h>

#define MAXLINE 100

int getLine(char string[], int lim);


int main() {
    int length; // stores the length of the current input line
    char line[MAXLINE]; // stores the current input line

    while( (length = getLine(line, MAXLINE)) > 0 ) {
        if(length - 1 >= 80) {  // check if the line length is greater than or equal to 80 characters
            printf("Line (%d chars): %s", length - 1, line);    // print the line of its length is 80 characters or more
        }
    }


    /*  Exercise explanation: Write a program to print all input lines that are longer than 80 characters. */

    return 0;
} 

int getLine(char string[], int lim) {
    int character, length;

    // read characters one by one and stores in the array
    for(length = 0; length < lim-1 && (character = getchar()) != EOF && character != '\n'; ++length ) string[length] = character;
    // if the loop exits due to newline, store the newline character in the array
    if(character == '\n') {
        string[length] = character;
        ++length;
    }

    string[length] = '\0';  // null-terminate the string to make it a valid C string

    return length;
}
