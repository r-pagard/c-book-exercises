#include <stdio.h>


void temperature_conversion_table(int lower, int upper, int step);
int temperature_conversion(int fahr);

int main() {
	int fahrenheit, celsius;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;

	temperature_conversion_table(lower, upper, step);
	printf("\n");

	fahrenheit = 100;
	celsius = temperature_conversion(fahrenheit);
	printf("Fahrenheit(F): %d, Celsius(C): %d\n", fahrenheit, celsius);


	/*	Exercise explanation: Rewrite the temperature conversion program of Section 1.2
	 *	to use a function for conversion.
	*/

    return 0;
}

void temperature_conversion_table(int lower, int upper, int step) {
	/*	Prints a temperature conversion table from Fahrenheit to Celsius
		Formula: C = (5/9) * (F - 32)

		@param lower: The starting Fahrenheit temperature
		@param upper: The ending Fahrenheit temperatur
		@param step: The increment between temperatures in the table

		The function does not return values; it prints a table instead
	*/

	int fahr, celsius;

	fahr = lower;
	while(fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}

int temperature_conversion(int fahr) {
	/*	Temperature Conversion Formula

		Celsius (C) = (5/9) * (Fahrenheit (F) - 32)

		Explanation:
			- Fahrenheit and Celcius are two different temperature scales
			- 32°F is the freezing point of water, which is 0°C
			- 212°F is the boiling point of water, which is 100°C
			- The ratio between the two scales is 5/9
	*/

	return 5 * (fahr - 32) / 9;
}
