#include <stdio.h>

int main() {
    char variable = 'a'; // 97

    float value1 = variable / 5;          // 19.0: integer division first, then converted to float
    float value2 = (float)variable / 5;   // 19.4: cast before dividing
    printf("value1 = %f, value2 = %f\n", value1, value2);

    // Truncation when assigning a floating-point value to an integer
    double pi = 3.14159;
    int truncated = pi; // 3
    printf("truncated = %d\n", truncated);

    // Overflow when assigning a large value to a smaller type
    int big = 300;
    char small = big; // only the low 8 bits are kept
    printf("small = %d\n", small);
    return 0;
}
