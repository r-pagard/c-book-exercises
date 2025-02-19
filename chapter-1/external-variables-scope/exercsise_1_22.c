#include <stdio.h>


#define LIMIT 20
#define MAXCHAR 100

void fold(void);


int main() {
    fold();


    /*  Write a program to ``fold'' long input lines into two or more shorter lines after
        the last non-blank character that occurs before the n-th column of input. Make sure your
        program does something intelligent with very long lines, and if there are no blanks or tabs
        before the specified column.
    */
    
    
    return 0;
}


void fold(void) {
    int character;
    int position;   // tracks the current column position in the line

    char character_group[MAXCHAR];  // buffer to store the input ine (up to MAXCHAR)

    // read characters one by one and stores them in the array
    for(position = 0; position < LIMIT && (character = getchar()) != EOF; ++position) character_group[position] = character;

    // if the last character is a newline, store it and increment position
    if(character == '\n') {
        character_group[position] = character;
        ++position;
    }

    // add null-terminated to make it a valid C string
    character_group[position] = '\0';

    // print the stored characters (line)
    printf("%s\n", character_group);

    // reset the buffer for the next line
    character_group[0] = '\0';
    position = 0;
}
