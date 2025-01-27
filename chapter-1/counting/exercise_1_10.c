#include <stdio.h>


int main() {
	/*	Write a program to copy its input to its output, replacing each tab by \t, each
		backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an
		unambiguous way.
	*/

	int character;

	while( (character = getchar()) != EOF ) {
		if(character == '\t') {
			putchar('\\');
			putchar('t');
			continue;	// get next character
		}
		if(character == '\b') {
			putchar('\\');
			putchar('b');
			continue;
		}
		if(character == '\\') {
			putchar('\\');
			putchar('\\');
			continue;
		}

		putchar(character);
	}

	return 0;
}

