#include <stdio.h>

int main() {
    int scores[5] = {10, 20, 30, 40, 50};
    int *p_scores = scores; // an array name is a pointer to its first element

    printf("scores     = %p\n", (void *)scores);
    printf("&scores[0] = %p\n", (void *)&scores[0]);

    // Pointers can be subscripted just like arrays
    printf("p_scores[2] = %d, *(p_scores + 2) = %d\n", p_scores[2], *(p_scores + 2));

    // An array name is a "constant" pointer: it cannot be reassigned
    // scores = p_scores;  // compile error
    // scores++;           // compile error
    p_scores++; // but a pointer variable can
    printf("*p_scores = %d\n", *p_scores); // 20
    return 0;
}
