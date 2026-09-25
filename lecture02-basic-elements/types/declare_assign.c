#include <stdio.h>

int main() {
    // Declare variables
    int integer_var;
    char char_var;
    float float_var;

    // Assign constant values
    integer_var = 42;      // integer
    integer_var = 0x2A;    // hexadecimal = 42
    char_var = 'A';        // character constant
    float_var = 3.14f;     // floating point

    printf("%d %c %f\n", integer_var, char_var, float_var);

    // Variable names are case-sensitive and may contain _
    int count = 1, Count = 2, _count = 3;
    printf("%d %d %d\n", count, Count, _count);
    return 0;
}
