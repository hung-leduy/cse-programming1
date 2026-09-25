#include <stdio.h>

// Small program for practicing debugging in VS Code (set a breakpoint in the loop)
int main() {
    int a[5] = {5, 3, 8, 1, 9};
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += a[i]; // <-- set a breakpoint here and inspect i, sum, a[i]
    }
    printf("sum = %d\n", sum);
    return 0;
}
