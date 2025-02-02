#include <stdio.h>


int main() {
    /*  Write a program to print a histogram of the lengths of words in its input. It is
        easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
    */

    int character;
    int length_number[10];
    int length = 0;

    while( (character = getchar() ) != EOF) {
        // increment the length for each character until a space or newline is encountered
        if(character != ' ' && character != '\n') ++length;
        // if the character is a space, tab, or newline, record the word length
        if(character == ' '  || character == '\t' || character == '\n') {
            ++length_number[length];    // increment the count for words of this length
            length = 0; // reset length for the next word
        }
    }
    for(int i = 0; i < 10; ++i) {
        printf("[%d]: ", i);
        for(int j = 0; j < length_number[i]; ++j) printf("*");
        printf("\n");
    }
    printf("\n");

    return 0;
}
