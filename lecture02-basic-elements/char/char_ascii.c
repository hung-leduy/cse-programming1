#include <stdio.h>

int main() {
    char variable = 'a';
    int value = variable; // 97: converted automatically using the ASCII table
    printf("'%c' = %d\n", variable, value);

    // Print part of the ASCII table
    for (char c = 'A'; c <= 'Z'; c++)
        printf("%c=%d ", c, c);
    printf("\n");

    // Convert lowercase -> uppercase using arithmetic
    char lower = 'g';
    char upper = lower - 'a' + 'A';
    printf("%c -> %c\n", lower, upper);
    return 0;
}
