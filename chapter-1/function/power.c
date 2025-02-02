#include <stdio.h>


int power(int base, int n);


int main() {
    // prints the power of `2` and `-3` for values of `i` from `0` to `9`
    printf("Exponent\tExponentiation of 2\tExponentiation of -3\n");
    for(int i = 0; i < 10; ++i) printf("%d\t\t %d \t\t\t %d\n", i, power(2, i), power(-3, i));

    return 0;
}

int power(int base, int n) {
    /*  computes the power of a number (base ^ n) using iteration

        @param base: the base number
        @param n: the exponent

        example:
            - input: base = 2,    n = 5
            - proccess: 1*2: 2,     2*2: 4,     4*2: 8,     8*2: 16,    16*2: 32
            - output: 32
    */
    
    int p = 1;  // initialize power result to 1
    for(int i = 1; i <= n; ++i) p = p * base;   // multiply base iteratively
    return p;
}
