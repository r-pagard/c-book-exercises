#include <stdio.h>

#define IN 0	// inside a word
#define OUT 1	// outside a word


int main() {
    /*  Write a program to print a histogram of the lengths of words in its input. It is
        easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
    */

    int character;
    int length_number[10];
    int length = 0;
    int state = OUT;

    while( (character = getchar() ) != EOF) {
        if(character != ' ' && character != '\n') ++length;
        if(character == ' '  || character == '\t' || character == '\n') {
            ++length_number[length];
            length = 0;
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