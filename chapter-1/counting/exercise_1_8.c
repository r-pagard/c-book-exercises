#include <stdio.h>


int main() {
    /* Write a program to count blanks, tabs, and newlines. */
    int character;
    int blank_quantity, tab_quantity, new_line_quantity;

    blank_quantity = tab_quantity = new_line_quantity = 0;
    while( (character = getchar()) != EOF ) {
        if(character == ' ') ++blank_quantity;  // check if character is blank, increase blank quantity
        if(character == '\t') ++tab_quantity;   // check if character is tab, increase tab quantity
        if(character == '\n') ++new_line_quantity;  // check if character is new line, increase new line quantity
    }

    printf("Blanks: %d\tTabs: %d\t\tNew Line: %d\n", blank_quantity, tab_quantity, new_line_quantity);

    return 0;
}
