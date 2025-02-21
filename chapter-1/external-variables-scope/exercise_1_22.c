#include <stdio.h>


#define LIMIT 20
#define MAXCHAR 100
#define TABSIZE 4

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
    int position = 0;   // Tracks the current column position in the line
    char character_group[MAXCHAR];  // Buffer to store the input ine (up to MAXCHAR)

    //  Read input character by character until EOF is reached
    while( (character = getchar()) != EOF )
    {
        // Read characters into `character_group` until LIMIT or newline
        do {
            if(character == '\t') {
                // Handle tab characters by converting them to spaces
                int spaces_to_next_tab = TABSIZE - (position % TABSIZE);
                for(int i = 0; i < spaces_to_next_tab && position < LIMIT; ++i) character_group[position++] = ' ';
            } else {
                // Store the character in the buffer
                character_group[position++] = character;
            }
        } while(position < LIMIT && (character = getchar()) != EOF && character != '\n');

        // If the last character is a newline, store it
        if(character == '\n') character_group[position++] = character;

        // Add null-terminated to make it a valid C string
        character_group[position] = '\0';

        // Print the stored characters (line)
        printf("%s\n", character_group);

        // Reset the buffer for the next line
        character_group[0] = '\0';
        position = 0;
    }
}
