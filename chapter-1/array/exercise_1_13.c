#include <stdio.h>


int main() {
	/*	Write a program to print a histogram of the lengths of words in its input. It is
		easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
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

	printf("Letters: ");
	for(int i = 0; i < 26; ++i) printf("%d ", letters_number[i]);	// print letters_number indexes
	printf("\n");

	return 0;
}
