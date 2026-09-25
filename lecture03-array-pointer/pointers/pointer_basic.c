#include <stdio.h>

int main() {
    // Declare pointers
    int *int_pointer;
    float *float_pointer;
    char *char_pointer;
    void *pointer;      // generic pointer
    int_pointer = NULL; // null pointer
    float_pointer = NULL;
    char_pointer = NULL;
    pointer = NULL;
    printf("%p %p %p %p\n", (void *)int_pointer, (void *)float_pointer, (void *)char_pointer, pointer);

    int x = 10;
    int_pointer = &x; // referencing: take the address of x
    printf("address of x = %p\n", (void *)int_pointer);
    printf("*int_pointer  = %d\n", *int_pointer); // dereferencing

    *int_pointer = 20; // change x through the pointer
    printf("x = %d\n", x);
    return 0;
}
