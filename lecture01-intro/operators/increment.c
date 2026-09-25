#include <stdio.h>

int main() {
    int i = 42;
    i++;
    printf("i = %d\n", i); // 43

    // i++ : use the value first, then increment
    i = 42;
    int j = (i++ + 10);
    printf("j = %d, i = %d\n", j, i); // j = 52, i = 43

    // ++i : increment first, then use the value
    i = 42;
    j = (++i + 10);
    printf("j = %d, i = %d\n", j, i); // j = 53, i = 43

    // Same for i-- and --i
    i = 42;
    printf("i-- = %d, ", i--);
    printf("i = %d\n", i); // 41
    return 0;
}
