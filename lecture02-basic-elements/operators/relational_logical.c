#include <stdio.h>

int main() {
    int a = 5, b = 10;

    // Relational operators: result is 1 (true) or 0 (false)
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("a >  b: %d\n", a > b);
    printf("a <  b: %d\n", a < b);
    printf("a >= b: %d\n", a >= b);
    printf("a <= b: %d\n", a <= b);

    // Logical operators
    printf("!(a < b): %d\n", !(a < b));
    printf("a < b && b < 20: %d\n", a < b && b < 20);
    printf("a > b || b < 20: %d\n", a > b || b < 20);

    // In C, any nonzero value is considered "true"
    if (42)
        printf("42 is true\n");
    return 0;
}
