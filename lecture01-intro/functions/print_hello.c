#include <stdio.h>

// Definition of print_hello: takes a string, returns an int
int print_hello(const char *name) {
    printf("hello, %s\n", name);
    return 0;
}

// A function with no parameters and no return value
void print_line(void) {
    printf("------------\n");
}

int main() {
    // A function can be called many times -> code reuse
    print_hello("world");
    print_line();
    print_hello("student");
    print_hello("teacher");
    return 0;
}
