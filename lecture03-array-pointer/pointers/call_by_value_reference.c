#include <stdio.h>

// Call by value: the function gets a COPY and cannot change the original
void swap_by_value(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// Call by reference (via a pointer): can change the original
void swap_by_reference(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int x = 1, y = 2;
    swap_by_value(x, y);
    printf("by value:     x = %d, y = %d\n", x, y); // 1, 2
    swap_by_reference(&x, &y);
    printf("by reference: x = %d, y = %d\n", x, y); // 2, 1
    return 0;
}
