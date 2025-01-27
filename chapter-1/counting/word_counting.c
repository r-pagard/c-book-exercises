#include <stdio.h>

#define IN 0	// inside a word
#define OUT 1	// outside a word

int main() {
	/*	count lines, words, and characters in input.

	 	The fourth in our series of useful programs counts lines, words, and characters, with the loose
		definition that a word is any sequence of characters that does not contain a blank, tab or
		newline. This is a bare-bones version of the UNIX program wc.
	*/

	int character;
	int line_number, word_number, character_number;
	int state = OUT;
	line_number = word_number = character_number = 0;

	while( (character = getchar()) != EOF) {
		++character_number;

		if(character == '\n') ++line_number;	// if see a new line, increase line number
		// check if a character is any of these spaces, update `state` to OUT means outside a word
		if(character == ' ' || character == '\t' || character == '\n') state = OUT;
		if(state == OUT) {	// if we're outside a word
			state = IN;	// update `state` to IN
			++word_number;	// increase word number
			// when we're outside a word, it means we've passed a word, and in this case, we increment the word number
		}
	}
	
	printf("Number Of Lines: %d\tNumber Of Words: %d\tNumber Of Characters: %d\n", line_number, word_number, character_number);

	return 0;
}
