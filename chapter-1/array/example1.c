#include <stdio.h>


int main() {
	/*	write a program to count the number of occurrences of each digit, of white space
		characters (blank, tab, newline), and of all other characters. This is artificial, but it permits us
		to illustrate several aspects of C in one program.

		example:
			- input: The C Programming Language. 011 369 2
			- output:
				Digits: 1 2 1 1 0 0 1 0 0 1
				White Spaces: 8		Others: 24
			- exaplanation about output's Digit: let me explain it by the example, 
			  when I wrote `011`, I used `1` two times and then the first input of the array(1) update to `2`.
	*/

	int character;
	int white_space_number, others_number;
	int digit_number[10];

	white_space_number = others_number = 0;
	for(int i = 0; i < 10; ++i) digit_number[i] = 0;	// fill all the indexes of the array with 0
	while( (character = getchar()) != EOF) {
		if(character >= '0' && character <= '9') ++digit_number[character - '0'];	// map digit character to integer index
		else if(character == ' ' || character == '\t' || character == '\n') ++white_space_number;
		else ++others_number;
	}

	printf("Digits: ");
	for(int i = 0; i < 10; ++i) printf("%d ", digit_number[i]);	// print indexes of the array
	printf("\n");
	printf("White Spaces: %d\t\tOthers: %d\n", white_space_number, others_number);

	return 0;
}
