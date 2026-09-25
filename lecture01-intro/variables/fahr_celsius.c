#include <stdio.h>

// Print a Fahrenheit -> Celsius table (K&R, section 1.2)
int main() {
    int fahr, celsius; // variable declarations

    fahr = 0;
    while (fahr <= 300) {
        celsius = 5 * (fahr - 32) / 9; // integer division
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + 20;
    }
    return 0;
}
