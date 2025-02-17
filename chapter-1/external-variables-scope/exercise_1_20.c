#include <stdio.h>


int tab_size = 4;   // number of spaces per tab stop
int position = 0;   // keeps track of the current column position

void detab(void);


int main() {

    detab();


    /*  Write a program detab that replaces tabs in the input with the proper number
        of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
        Should n be a variable or a symbolic parameter?
    */

    return 0;
}

void detab(void) {
    /*  Replaces tab characters in the input with the appropriate number of spaces.

        The function reads characters from standard input and processes them one by one.

        - If a character is a tab(\t), it's replaces with enough spaces to reach the next tab stop.
        - If it's any other characters, it's print it as is.
        - The `position` variable keeps track of the current column position to correctly calculate tab stops.
        - If a newline(\n) is encountered, `position` resets to 0.
    */
    
    int character;
    extern int position;

    while( (character = getchar()) != EOF )
    {
        if(character == '\t') { // if character is a tab
            int spaces = tab_size - (position % tab_size);  // calculate spaces needed to align to the next tab stop
            for(int i = 0; i < spaces; i++) {
                putchar(' ');   // print spaces instead of tab
                position++;
            }
        } else {    // if character isn not a tab
            putchar(character); // print the character
            position++;

            // reset position when a newline is encountered
            if(character == '\n') position = 0;
        }
    }
}
