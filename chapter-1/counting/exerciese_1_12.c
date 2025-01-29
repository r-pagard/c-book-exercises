#include <stdio.h>

#define IN 0	// inside a word
#define OUT 1	// outside a word


int main() {
	/*	Write a program that prints its input one word per line. */

	int character;
	int state = OUT;

	while( (character = getchar()) != EOF ) {
		// check if a character is any of these spaces, update `state` to OUT means ouside a word, recognize a word
		if(character == ' ' || character == '\t' || character == '\n') state = OUT;
		if(state == OUT) {	// if we're outside a word
			state = IN;	// update `state` to IN
			putchar('\n');	// print a new line for put next word in the new line
			
			// when we're ouside a word, it means we've passed a word, and in this case, we put the next word to the new line
		}
		putchar(character);
	}

	return 0;
}
