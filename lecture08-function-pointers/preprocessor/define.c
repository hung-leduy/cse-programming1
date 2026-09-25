#include <stdio.h>

// Define constants
#define MAX_CHAR 100
#define PI 3.14159

// Define macros: ALWAYS put parentheses around parameters and the whole expression
#define AREA_BAD(l, b) (l * b)
#define AREA(l, b) ((l) * (b))
#define SQUARE(x) ((x) * (x))

int main() {
    char array[MAX_CHAR];
    snprintf(array, MAX_CHAR, "PI = %.5f", PI);
    printf("%s\n", array);

    printf("AREA(2, 3)         = %d\n", AREA(2, 3));
    // Macros are plain text substitution: AREA_BAD(1 + 1, 3) -> (1 + 1 * 3) = 4 (wrong!)
    printf("AREA_BAD(1 + 1, 3) = %d\n", AREA_BAD(1 + 1, 3));
    printf("AREA(1 + 1, 3)     = %d\n", AREA(1 + 1, 3)); // 6
    printf("SQUARE(4)          = %d\n", SQUARE(4));
    return 0;
}
