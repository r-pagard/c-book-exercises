#include <stdio.h>


int main() {
	/*	Write a program to print a histogram of the frequencies of different characters
		in its input.
	*/

	int character;
	int letters_number[26];	// store frequesncies of each letter

	for(int i = 0; i < 26; ++i) letters_number[i] = 0;	// initialize all indexes to 0
	while( (character = getchar()) != EOF) {
		/*	check if the character is valid(for both uppercase and lowercase), then
			convert character to index and increment letters_number
		*/
		if(character >= 'a' && character <= 'y') ++letters_number[character - 'a'];
		if(character >= 'A' && character <= 'Y') ++letters_number[character - 'A'];
	}

	for(int i = 0; i < 26; ++i) {
		if(letters_number[i] > 0) {	// only letters that appeared in the input
			printf("[%c]: ", 'a' + i);	// convert index to character
			for(int j = 0; j < letters_number[i]; ++j) printf("*");
			printf("\n");
		}
	}
	printf("\n");

	return 0;
}
