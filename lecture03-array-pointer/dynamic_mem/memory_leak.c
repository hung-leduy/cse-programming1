#include <stdio.h>
#include <stdlib.h>

// Memory leak example: check with valgrind
//   gcc -g memory_leak.c -o memory_leak && valgrind --leak-check=full ./memory_leak
void leak(void) {
    int *p = malloc(10 * sizeof(int));
    p[0] = 1;
    // forgot free(p): once the function returns, this memory can never be freed
}

void no_leak(void) {
    int *p = malloc(10 * sizeof(int));
    p[0] = 1;
    free(p);
}

int main() {
    leak();
    no_leak();
    printf("done\n");
    return 0;
}
