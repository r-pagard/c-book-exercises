#include <stdio.h>


int main() {
	/* Print Fahenheit-Celsius table
	 * For fahr = 0, 20, ..., 300; floating-point version
	 * This program convers temperatures from Fahrenheit to Celsius
	 * and prints the results in a table format.
	*/

	float fahr, celsius;
	float lower, upper, step;

	lower = 0;	// Lower limit of temperature scale
	upper = 300;	// Uppper limit
	step = 20;	// Step size for increments

	fahr = lower;
	while(fahr <= upper) {
		/* Converts the Fahrenheit difference into Celsius.
		 * Formula: (5.0 / 9.0) * (Fahrenheit - 32.0).
		 * The formula converts the Fahrenheit temperature to Celsius by adjusting
		 * the Fahrenheit temperature relative to freezing (32F) and scaling the difference
		 * by the ratio of the temperature scales.
		 */
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	return 0;
}
