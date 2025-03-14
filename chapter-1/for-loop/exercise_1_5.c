#include <stdio.h>


int main() {
	float fahrenheit, celsius;
	float lower = 0, upper = 300, step = 20;

	printf("Fahrenheit\tCelsius\n");
	printf("----------\t-------\n");

	for(fahrenheit = upper; fahrenheit >= lower; fahrenheit -= step) {
		celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
		printf("   %3.0f\t\t%6.1f\n", fahrenheit, celsius);
	}


	/* Modify the temperature conversion program to print the table in reverse order,
	 * That is, from 300 degrees to 0.
	 */

	return 0;
}
