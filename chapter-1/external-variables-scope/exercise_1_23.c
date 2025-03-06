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
	int position, buffer_length;

	char lines[MAXLINECHAR];
	char cleaned_output[MAXTEMPLEN];

	position = 0;
	buffer_length = 0;
	while( (character = getchar()) != EOF )
	{
		// Read characters into `lines` until newline and EOF
		do {
			// Store characters in the array and increment position
			lines[position] = character;
			position++;
			buffer_length++;
		}
		while( character != '\n' && (character = getchar()) != EOF );

		// If newline is encountered, store it in the array
		if(character == '\n') {
			lines[position] = character;
			position++;
		}
		lines[position] = '\0';	// Null-terminate the string
	}

	// Process the buffer to remove comments
	int i = 0, j = 0;
	while(lines[i] != '\0')
	{
		if(lines[i] == '/' && lines[i + 1] == '/') {
			// Skip the rest of the line
			while(lines[i] != '\n' && lines[i] != '\0') i++;
		} else {
			// Copy the character to the cleaned_output buffer
			cleaned_output[j] = lines[i];
			j++;
		}

		if(lines[i] != '\0') i++;
	}
	cleaned_output[j] = '\0'; // Null-terminate the cleaned_output buffer

	// Print the processed buffer content
    printf("\nThe Buffer without comments: \n");
    printf("\n%s\n", cleaned_output);
}
