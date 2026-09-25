#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate a single variable
    int *p = malloc(sizeof(int));
    *p = 42;
    printf("*p = %d\n", *p);
    free(p);

    // Allocate an int[100] array
    int *p_scores = malloc(100 * sizeof(int));
    if (p_scores == NULL) { // always check the result of malloc
        printf("Out of memory\n");
        return 1;
    }
    p_scores[0] = 13;  // subscripted just like a regular array
    p_scores[99] = 42;
    printf("%d %d\n", p_scores[0], p_scores[99]);
    free(p_scores);    // free -> avoid a memory leak
    p_scores = NULL;   // avoid a dangling pointer
    return 0;
}
