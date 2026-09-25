#include <stdio.h>
#include <string.h>

int main() {
    char a[50] = "Hello";
    char b[] = "World";

    printf("strlen(a) = %zu\n", strlen(a)); // length, not counting '\0'

    printf("strcmp(a, b) = %d\n", strcmp(a, b) < 0 ? -1 : 1); // < 0: a comes before b
    printf("strncmp(\"Hello\", \"Help\", 3) = %d\n", strncmp("Hello", "Help", 3)); // 0

    strcat(a, ", ");          // concatenate: a must have enough room!
    strncat(a, b, 3);         // append at most 3 characters
    printf("a = %s\n", a);    // Hello, Wor

    char c[50];
    strcpy(c, b);             // copy a string
    printf("c = %s\n", c);

    char d[4];
    strncpy(d, "abcdef", sizeof(d) - 1); // strncpy does not add '\0' when it truncates
    d[sizeof(d) - 1] = '\0';
    printf("d = %s\n", d);    // abc

    char *found = strstr(a, "llo"); // find a substring
    if (found != NULL)
        printf("\"llo\" at position %ld\n", found - a);
    return 0;
}
