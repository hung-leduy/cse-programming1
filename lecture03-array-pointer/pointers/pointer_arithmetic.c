#include <stdio.h>
#include <stdlib.h>

void print(int *a, int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int *base = calloc(5, sizeof(int)); // 5 ints, initialized to 0
    int *p_scores = base;

    // Moving a pointer: p + 1 advances by sizeof(int) bytes
    printf("p_scores     = %p\n", (void *)p_scores);
    printf("p_scores + 3 = %p\n", (void *)(p_scores + 3));

    *(p_scores) = 3;     // base[0] = 3
    *(++p_scores) = 1;   // increment p first, then assign: base[1] = 1
    *(p_scores + 3) = 2; // base[1 + 3] = base[4] = 2
    print(base, 5);      // 3 1 0 0 2

    // Quiz: *(p_scores++) = 7 assigns to the CURRENT position, then increments p
    p_scores = base;
    *(p_scores++) = 7; // base[0] = 7, then p points to base[1]
    print(base, 5);    // 7 1 0 0 2
    printf("*p_scores = %d\n", *p_scores); // 1

    free(base); // free via the original pointer, not the shifted p_scores
    return 0;
}
