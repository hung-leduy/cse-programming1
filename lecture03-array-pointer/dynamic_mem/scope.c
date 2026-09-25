#include <stdio.h>
#include <stdlib.h>

int global_counter = 0; // global variable: usable in every function

// WRONG: returns the address of a local (stack) variable, destroyed when the function returns
// int *bad_array(void) {
//     int local[3] = {1, 2, 3};
//     return local;
// }

// RIGHT: an array allocated on the heap lives until free
int *good_array(void) {
    int *heap = malloc(3 * sizeof(int));
    heap[0] = 1;
    heap[1] = 2;
    heap[2] = 3;
    return heap;
}

void increase(void) {
    int local = 0; // local variable: created anew on each call
    local++;
    global_counter++;
    printf("local = %d, global_counter = %d\n", local, global_counter);
}

int main() {
    increase();
    increase();

    {
        int x = 5; // x exists only inside this {} block
        printf("x = %d\n", x);
    }
    // printf("%d", x); // error: x is out of scope

    int *a = good_array();
    printf("%d %d %d\n", a[0], a[1], a[2]);
    free(a);
    return 0;
}
