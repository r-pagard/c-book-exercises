#include <stdio.h>


int main() {
	/* Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank. */

	int character;

	while( (character = getchar()) != EOF) {
		if(character == ' ') {	// find the first whitespace
			while( (character = getchar()) == ' ' );	// through on characters until the last whitespace
			if(character == '\t') {
				while( (character = getchar()) == '\t' );
				printf("");
			}
			if(character == ' ') {
				while( (character = getchar()) == ' ' );
				printf("");
			}
			putchar(' ');	// print a blank(whitespace)
		}
		if(character == '\t') {	// find the first tab
			while( ((character = getchar()) == '\t') );	// through on characters until the last tab and whitespace
			if(character == ' ') {
				while( (character = getchar()) == ' ' );
				printf("");
			}
			putchar(' ');	// print a blank(whitespace)
		}

		putchar(character);	// print the input
	}

	return 0;
}

