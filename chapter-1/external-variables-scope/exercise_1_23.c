#include <stdio.h>


#define MAXLINECHAR 50


void comment_remover(void);


int main() {
	comment_remover();


    /*  Write a program to remove all comments from a C program. Don't forget to
        handle quoted strings and character constants properly. C comments don't nest.
    */

    return 0;
}


void comment_remover(void) {
	int character;
	int position = 0;
	char char_line[MAXLINECHAR];

	while( (character = getchar()) != EOF )
	{
		do {
			char_line[position] = character;
			position++;
		}
		while( character != '\n' && (character = getchar()) != EOF );
	}

	printf("The Buffer: %s", char_line);
}
