#include <stdio.h>


#define TABSIZE 4

void entab(void);


int main() {
    entab();


    /*  Write a program entab that replaces strings of blanks by the minimum
        number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
        When either a tab or a single blank would suffice to reach a tab stop, which should be given
        preference?
    */

    return 0;
}


void entab(void) {
    int character;
    int num_space = 0, num_tab = 0;
    int position;   // tracks the current column position in the line

    for(position = 1; (character = getchar()) != EOF; ++position)
    {
        // collect consecutive spaces to determine the minumum number of tabs and spaces needed
        if(character ==  ' ') {
            // if the current position is NOT a tab stop, count it as a space
            if( (position % TABSIZE) != 0 ) ++num_space;
            // if the current position is a tab stop, convert collected spaces into a tab
            else {
                num_space = 0;
                ++num_tab;
            }
        } else {
            // print collected tabs first
            for(; num_tab > 0; --num_tab) putchar('\t');
            // if a tab character is encountered in the input, reset space count
            if(character == '\t') num_space = 0;
            else {
                // print remaining spaces (if any)
                for(; num_space > 0; --num_space) putchar(' ');
            }

            // print the actual non-space character
            putchar(character);

            // reset position counter if a newline is encountered
            if(character == '\n') position = 0;
            // adjust position correctly when encountering a tab
            else if(character == '\t') position = position + (TABSIZE - (position - 1) % TABSIZE) - 1;
        }
    }
}
