#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int sum(int a, int b) { return a + b; }

int main() {
    int (*func)(int, int); // pointer to a function taking (int, int) and returning int

    func = max; // a function name is the function's address
    printf("max(3, 7) = %d\n", func(3, 7));
    func = min;
    printf("min(3, 7) = %d\n", func(3, 7));
    func = &sum; // writing &sum also works
    printf("sum(3, 7) = %d\n", (*func)(3, 7));

    // Array of function pointers
    int (*ops[])(int, int) = {max, min, sum};
    const char *names[] = {"max", "min", "sum"};
    for (int i = 0; i < 3; i++)
        printf("%s(10, 4) = %d\n", names[i], ops[i](10, 4));
    return 0;
}
