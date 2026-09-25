#include <stdio.h>

int main() {
    // continue: skip the rest and go to the next iteration
    // break: exit the loop
    int i = 0;
    while (1) {
        i++;
        if (i > 10)
            break;
        if (i % 2 == 0)
            continue;
        printf("%d ", i); // prints only the odd numbers from 1 to 9
    }
    printf("\n");
    return 0;
}
