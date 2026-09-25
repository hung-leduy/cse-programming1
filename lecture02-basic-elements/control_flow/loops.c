#include <stdio.h>

int main() {
    // for
    for (int i = 0; i < 5; i++)
        printf("for: %d\n", i);

    // while: the condition is tested first
    int j = 0;
    while (j < 3) {
        printf("while: %d\n", j);
        j++;
    }

    // do-while: the loop body runs at least once
    int k = 10;
    do {
        printf("do-while: %d\n", k);
        k++;
    } while (k < 3);
    return 0;
}
