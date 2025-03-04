#include <stdio.h>


#define MAXTEMPLEN 50
#define MAXLINECHAR 1000


void comment_remover(void);


int main() {
	comment_remover();


    /* Write a program to remove all comments from a C program.
       Don't forget to handle quoted strings and character constants properly.
       C comments don't nest.
    */

    return 0;
}


void comment_remover(void) {
	int character;
	int position = 0;
	char lines[MAXLINECHAR];
	char temp[MAXTEMPLEN];

	while( (character = getchar()) != EOF )
	{
		// Read characters into `lines` until newline and EOF
		do {
			// Store characters in the array and increment position
			lines[position] = character;
			position++;
		}
		while( character != '\n' && (character = getchar()) != EOF );

		// If newline is encountered, store it in the array
		if(character == '\n') {
			lines[position] = character;
			position++;
		}
		lines[position] = '\0';	// Null-terminate the string
	}

	// print the buffer content
	printf("\nThe Buffer: \n");
	printf("\n%s\n", lines);
}
