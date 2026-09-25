#include <stdio.h>

int main() {
    // Character array: holds up to 49 characters + the terminating '\0'
    char str[50] = "Hello, World!";
    str[0] = 'h'; // may be modified

    // Pointer to a string literal: must NOT be modified
    const char *literal = "Hello, World!";
    // literal[0] = 'h'; // error / undefined behavior

    printf("%s\n%s\n", str, literal);

    // A string always ends with '\0'
    char s[] = "abc"; // equivalent to {'a', 'b', 'c', '\0'}
    printf("sizeof(s) = %zu\n", sizeof(s)); // 4
    for (int i = 0; s[i] != '\0'; i++)
        printf("s[%d] = '%c' (%d)\n", i, s[i], s[i]);
    return 0;
}
