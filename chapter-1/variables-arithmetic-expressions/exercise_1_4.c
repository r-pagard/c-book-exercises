#include <stdio.h>


int main() {
	int celsius;
	int lower = 0, upper = 100, step = 10;

	printf("Celsius\t\tFahrenheit\n");
	printf("-------\t\t----------\n");

	celsius = lower;
	while(celsius <= upper) {
		float fahrenheit = (9.0 / 5.0) * celsius + 32;
		printf("  %d\t\t %6.1f\n", celsius, fahrenheit);

		celsius += step;
	}

	return 0;
}
