#include <stdio.h>

int main() {
    int a = 17, b = 5;
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b); // integer division: 3
    printf("a %% b = %d\n", a % b); // remainder (modulus): 2

    double x = 17.0, y = 5.0;
    printf("x / y = %f\n", x / y); // floating-point division: 3.4
    // x % y -> compile error: operator % does not work on float/double
    return 0;
}
